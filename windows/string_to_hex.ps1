function ConvertTo-Hex {
    [CmdletBinding()]
    Param(
        [Parameter(
            Position=0,
            Mandatory=$true,
            ValueFromPipeline=$true,
            ValueFromPipelineByPropertyName=$true
        )]
        [string]$InputObject
    )

    $hex = [char[]]$InputObject |
           ForEach-Object { '{0:x2}' -f [int]$_ }

    if ($hex -ne $null) {
        return (-join $hex)
    }
}

function GetGuids {
    # finding the GUID to set screen brightness

    $result = powercfg -q
    $result = $result -split "`r`n"

    #write-host $result[0]
    $arr_guid_aff = @()
    For ($i=0; $i -lt $result.length; $i++) {
        #write-host "result i= "$result[$i]
        if($result[$i] -match "GUID du mode de gestion de l'alimentation"){
            $primary_GUID = $result[$i]
        }elseif($result[$i] -match "GUID du sous-groupe" -and $result[$i] -match "Affichage"){
            $sub_group_GUID = $result[$i]
        }elseif($result[$i] -match " de l'affichage"){
            $arr_guid_aff += $result[$i]
        }
    }
    $guid_aff = $arr_guid_aff[0]

    # split the primary GUID

    $primary_GUID = $primary_GUID -split(": ")
    $primary_GUID = $primary_GUID[1]
    $primary_GUID = $primary_GUID -split(" ")
    $primary_GUID = $primary_GUID[0]

    #split the subgroup

    $sub_group_GUID = $sub_group_GUID -split(": ")
    $sub_group_GUID = $sub_group_GUID[1]
    $sub_group_GUID = $sub_group_GUID -split(" ")
    $sub_group_GUID = $sub_group_GUID[0]

    # split the screen guid
    $guid_aff = $guid_aff -split(": ")
    $guid_aff = $guid_aff[1]
    $guid_aff = $guid_aff -split(" ")
    $guid_aff = $guid_aff[0]

    return $primary_GUID, $sub_group_GUID,$guid_aff
}

$ar1 = @("0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f")
$ar2 = @("0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111")

#########################################################################################################################
# read the file to translate to hex
$test = Get-Content -Raw .\test.txt
#########################################################################################################################

$hex_old = ($test | ConvertTo-Hex)

For ($i=0; $i -le 15; $i++) {
    $hex_new = $hex_old -replace $ar1[$i], $ar2[$i]
    $hex_old = $hex_new
    }

For ($i=0; $i -lt $hex_old.length; $i++) {
    $GUIDs = GetGuids
    if($hex_old[$i] -eq "0"){
        powercfg -SetDcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 1
        powercfg -SetAcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 1
        powercfg -S $GUIDs[0]
        write-host "0"
        start-sleep -seconds 1
    }else {
        powercfg -SetDcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 100
        powercfg -SetAcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 100
        powercfg -S $GUIDs[0]
        write-host "1"
        start-sleep -seconds 1
    }
}

$GUIDs = GetGuids
powercfg -SetDcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 50
powercfg -SetAcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 50
powercfg -S $GUIDs[0]