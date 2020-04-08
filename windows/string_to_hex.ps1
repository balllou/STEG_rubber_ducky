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

$ar1 = @("0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f")
$ar2 = @("0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111")

# read the file to translate to hex
$test = Get-Content -Raw .\test.txt

$hex = ($test | ConvertTo-Hex)

#write-output $hex
#write-output $0

$hex -replace "0", $0

$hex_old = $hex

For ($i=0; $i -le 15; $i++) {
    $hex_new = $hex_old -replace $ar1[$i], $ar2[$i]
    $hex_old = $hex_new
    }

write-output $hex_old.length
write-output $hex_old
For ($i=0; $i -lt $hex_old.length; $i++) {

    write-output "hex_old i= "$hex_old[$i]

    if($hex_old[$i] -eq "0"){
        write-output "it's a 0"
    }else {
        write-output "a 1"
    }
}