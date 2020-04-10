#include <Keyboard.h>

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
const int ledPin = 13;

const String file_to_light = ""\
"function ConvertTo-Hex {\n"\
"    [CmdletBinding()]\n"\
"    Param(\n"\
"        [Parameter(\n"\
"            Position=0,\n"\
"            Mandatory=$true,\n"\
"            ValueFromPipeline=$true,\n"\
"            ValueFromPipelineByPropertyName=$true\n"\
"        )]\n"\
"        [string]$InputObject\n"\
"    )\n"\
"\n"\
"    $hex = [char[]]$InputObject |\n"\
"           ForEach-Object { '{0:x2}' -f [int]$_ }\n"\
"\n"\
"    if ($hex -ne $null) {\n"\
"        return (-join $hex)\n"\
"    }\n"\
"}\n"\
"\n"\
"function GetGuids {\n"\
"    # finding the GUID to set screen brightness\n"\
"\n"\
"    $result = powercfg -q\n"\
"    $result = $result -split \"`r`n\"\n"\
"\n"\
"    #write-host $result[0]\n"\
"    $arr_guid_aff = @()\n"\
"    For ($i=0; $i -lt $result.length; $i++) {\n"\
"        #write-host \"result i= \"$result[$i]\n"\
"        if($result[$i] -match \"GUID du mode de gestion de l'alimentation\"){\n"\
"            $primary_GUID = $result[$i]\n"\
"        }elseif($result[$i] -match \"GUID du sous-groupe\" -and $result[$i] -match \"Affichage\"){\n"\
"            $sub_group_GUID = $result[$i]\n"\
"        }elseif($result[$i] -match \" de l'affichage\"){\n"\
"            $arr_guid_aff += $result[$i]\n"\
"        }\n"\
"    }\n"\
"    $guid_aff = $arr_guid_aff[0]\n"\
"\n"\
"    # split the primary GUID\n"\
"\n"\
"    $primary_GUID = $primary_GUID -split(\": \")\n"\
"    $primary_GUID = $primary_GUID[1]\n"\
"    $primary_GUID = $primary_GUID -split(\" \")\n"\
"    $primary_GUID = $primary_GUID[0]\n"\
"\n"\
"    #split the subgroup\n"\
"\n"\
"    $sub_group_GUID = $sub_group_GUID -split(\": \")\n"\
"    $sub_group_GUID = $sub_group_GUID[1]\n"\
"    $sub_group_GUID = $sub_group_GUID -split(\" \")\n"\
"    $sub_group_GUID = $sub_group_GUID[0]\n"\
"\n"\
"    # split the screen guid\n"\
"    $guid_aff = $guid_aff -split(\": \")\n"\
"    $guid_aff = $guid_aff[1]\n"\
"    $guid_aff = $guid_aff -split(\" \")\n"\
"    $guid_aff = $guid_aff[0]\n"\
"\n"\
"    return $primary_GUID, $sub_group_GUID,$guid_aff\n"\
"}\n"\
"\n"\
"$ar1 = @(\"0\",\"1\",\"2\",\"3\",\"4\",\"5\",\"6\",\"7\",\"8\",\"9\",\"a\",\"b\",\"c\",\"d\",\"e\",\"f\")\n"\
"$ar2 = @(\"0000\",\"0001\",\"0010\",\"0011\",\"0100\",\"0101\",\"0110\",\"0111\",\"1000\",\"1001\",\"1010\",\"1011\",\"1100\",\"1101\",\"1110\",\"1111\")\n"\
"\n"\
"#########################################################################################################################\n"\
"# read the file to translate to hex\n"\
"#$test = Get-Content -Raw .\test.txt\n"\
"$test = \"aabbcc\""\
"#########################################################################################################################\n"\
"\n"\
"$hex_old = ($test | ConvertTo-Hex)\n"\
"\n"\
"For ($i=0; $i -le 15; $i++) {\n"\
"    $hex_new = $hex_old -replace $ar1[$i], $ar2[$i]\n"\
"    $hex_old = $hex_new\n"\
"    }\n"\
"\n"\
"For ($i=0; $i -lt $hex_old.length; $i++) {\n"\
"    $GUIDs = GetGuids\n"\
"    if($hex_old[$i] -eq \"0\"){\n"\
"        powercfg -SetDcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 1\n"\
"        powercfg -SetAcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 1\n"\
"        powercfg -S $GUIDs[0]\n"\
"        start-sleep -seconds 1\n"\
"    }else {\n"\
"        powercfg -SetDcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 100\n"\
"        powercfg -SetAcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 100\n"\
"        powercfg -S $GUIDs[0]\n"\
"        start-sleep -seconds 1\n"\
"    }\n"\
"}\n"\
"\n"\
"$GUIDs = GetGuids\n"\
"powercfg -SetDcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 50\n"\
"powercfg -SetAcValueIndex $GUIDs[0] $GUIDs[1] $GUIDs[2] 50\n"\
"powercfg -S $GUIDs[0]";
