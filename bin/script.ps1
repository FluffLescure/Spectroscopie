$ErrorActionPreference = "Stop"
$ErrorView = 'CategoryView'

$path1 = $args[0]
$path2 = $args[1]

Try {
    $content1 = Get-Content -Path $path1 
} Catch {
    $path1 = 0
    while($path1 -eq 0) {
        $counter = 1
        Get-ChildItem -Name -Include *.csv | ForEach-Object {Write-Host "[$counter] " -ForeGroundColor Green -NoNewLine; Write-Host "$_"; $counter++}
        $files = Get-ChildItem -Name -Include *.csv
        Write-Host ""
        Write-Host "Choose the original list :"
        $choice = Read-Host
        $path1 = $files[$choice - 1]
        Try{
            $content1 = Get-Content -Path $path1
        }
        Catch{
             Write-Host "Error : $path1 not found"
             $path1 = 0
        }
        Clear-Host
    }
}


    

Try {
    $content2 = Get-Content -Path $path2 
} Catch {
    $path2 = 0
    while($path2 -eq 0) {
        $counter = 1
        Get-ChildItem -Name -Include *.csv | ForEach-Object {Write-Host "[$counter] " -ForeGroundColor Green -NoNewLine; Write-Host "$_"; $counter++}
        $files = Get-ChildItem -Name -Include *.csv
        Write-Host ""
        Write-Host "Choose the updated Sigraph list :"
        $choice = Read-Host
        $path2 = $files[$choice - 1]
        Try{
            $content2 = Get-Content -Path $path2
        }
        Catch{
             Write-Host "Error : $path2 not found"
             $path2 = 0
        }
        Clear-Host
    }
}



$t_exact1 = $content1.Length/85 #time constant 140
$t_rounded1 = [math]::round($t_exact1.ToString().replace(",","."),2)

$t_exact2 = $content2.Length/91 #time constant 175
$t_rounded2 = [math]::round($t_exact2.ToString().replace(",","."),2)


while ($mod_desc -ne "Y" -and $mod_desc -ne "n") {
    Write-Host "Do you want to change conflicting descriptions automatically? (Y/n)"
    $mod_desc = Read-Host
}

while ($mod_kks -ne "Y" -and $mod_kks -ne "n") {
    Write-Host "Do you want to change conflicting KKS automatically? (Y/n)"
    $mod_kks = Read-Host
}

Clear-Host
Write-Host "Estimated $t_rounded1 seconds to completion"

foreach ($line1 in $content1) {
    $parts1 = $line1.Split(";")
    $temp_parts1 = $parts1[4].Trim()
    $flag = 0

    

    foreach ($line2 in $content2) {
        $parts2 = $line2.Split(";")
        $temp_parts2 = $parts2[31].Trim()
         

        # Same DESC and KKS
        if ($flag -eq 0 -and $parts1[1] -eq $parts2[1] -and $temp_parts2.Contains($temp_parts1)) {
	        $part = $parts1 -join ";"
            $maintained = $maintained + "`n" + $part
            $flag = 1
        } 

        # Same DESC diff KKS
        elseif ($flag -eq 0 -and ($temp_parts2.Contains($temp_parts1) -or $temp_parts1.Contains($temp_parts2)) -and $parts1[3] -eq $parts2[3]) {
            if ($parts1[1] -ne $parts2[1]){
                if($mod_kks -eq "Y") {
                    $parts1[1] = $parts2[1]
                    $parts1[2] = $parts2[2]
                    $parts1[3] = $parts2[3]
                }
                $part = $parts1 -join ";"
                $KKS_changed = $KKS_changed + "`n" + $part
                $flag = 1
            }
        } 
         
        # Same KKS diff DESC
        elseif ($flag -eq 0 -and $parts1[1] -eq $parts2[1] -and !$temp_parts2.Contains($temp_parts1)) {
            if ($mod_desc -eq "Y"){
                $parts1[4] = $parts2[31]
            }
            $part = $parts1 -join ";"
            $DESC_changed = $DESC_changed + "`n" + $part
            $flag = 1
        }
    }

    
    $i = $i + 1
    $percent = [math]::Round($i / $content1.Length * 100)
 
    Write-Progress -Activity "Checking for changes" -Status "$percent% Complete" -PercentComplete $percent

    # Old elements
    if($flag -eq 0){
        $part = $parts1 -join ";"
        $deleted = $deleted + "`n" + $part
    }
}


Clear-Host
Write-Host "Estimated $t_rounded2 seconds to completion"

$i = 0 

foreach ($line2 in $content2) {
    $parts2 = $line2.Split(";")
    $temp_parts2 = $parts2[31].Trim()
    $flag = 0

    foreach ($line1 in $content1) {
        $parts1 = $line1.Split(";")
        $temp_parts1 = $parts1[4].Trim() 

        if ($flag -eq 0 -and $parts1[1] -eq $parts2[1] -and $temp_parts2.Contains($temp_parts1)) {
            $flag = 1
        } 

        elseif ($flag -eq 0 -and ($temp_parts2.Contains($temp_parts1) -or $temp_parts1.Contains($temp_parts2)) -and $parts1[3] -eq $parts2[3]) {
            if ($parts1[1] -ne $parts2[1]){
                $flag = 1
            }
        } 

        elseif ($flag -eq 0 -and $parts1[1] -eq $parts2[1] -and !$temp_parts2.Contains($temp_parts1)) {
            $flag = 1
        }
    }

    $i = $i + 1
    $percent = [math]::Round($i / $content2.Length * 100)
 
    Write-Progress -Activity "Checking for new elements" -Status "$percent% Complete" -PercentComplete $percent

    # New elements
    if($flag -eq 0 -and $parts2[10].Trim() -ne "comm" -and !($parts2[3] -like "ZB*" -or $parts2[3] -like "ZQ*")){
        $part = $parts2 -join ";"
        $new = $new + "`n" + $part
    }
}

$maintained | Set-Content -Path .\maintained.csv
Write-Host "Created maintained.csv"

"`nKKS Changed`n" | Set-Content -Path .\changed.csv
$KKS_changed | Add-Content -Path .\changed.csv 
"`nDESC Changed`n" | Add-Content -Path .\changed.csv
$DESC_changed | Add-Content -Path .\changed.csv 
Write-Host "Created changed.csv"

"`nDeleted`n" | Add-Content -Path .\changed.csv
$deleted | Add-Content -Path .\changed.csv
Write-Host "Added deleted elements"

$new | Set-Content -Path ".\New Elements.csv"
Write-Host "Created New Elements.csv"
