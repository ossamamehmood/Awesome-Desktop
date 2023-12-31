$appname=$args[0]
$appauthor=$args[1]
$newappname=$args[2]
$skinspath=$args[3]
$exclude = @('*.rmskin','*.md')

cd "$skinspath"
New-Item -ItemType "directory" -Path ".\Droptop Folders\Other files\@Rmskins\Droptop Apps"
Remove-Item -Path ".\Droptop Folders\Other files\@Rmskins\Droptop Apps\$newappname - $appauthor (Droptop App).rmskin" -Recurse
Remove-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\@Rmskins\*.rmskin" -Recurse
Remove-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\@Rmskins\*.zip" -Recurse
Copy-Item -Path ".\Droptop Community Apps\Apps\$appname" -Destination ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Skins\Droptop Community Apps\Apps\" -Recurse -Exclude $exclude
Copy-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Skins\Droptop Community Apps\Apps\$appname\Plugins\32bit\*" -Destination ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Plugins\32bit\" -Recurse
Copy-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Skins\Droptop Community Apps\Apps\$appname\Plugins\64bit\*" -Destination ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Plugins\64bit\" -Recurse
Copy-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Skins\Droptop Community Apps\Apps\$appname\Images\RMSKIN.bmp" -Destination ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\" -Recurse
cd .\Droptop\@Resources\Scripts\AppBuilder
.\MakeRmSkin.ps1 -Skin AppTemplate
cd "$skinspath"
Move-Item -Path '.\Droptop\@Resources\Scripts\AppBuilder\@Rmskins\AppTemplate.rmskin' -Destination ".\Droptop Folders\Other files\@Rmskins\Droptop Apps\$newappname - $appauthor (Droptop App).rmskin"
Remove-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Skins\Droptop Community Apps\Apps\*" -Recurse
Remove-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Plugins\32bit\*" -Recurse
Remove-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\AppTemplate\Plugins\64bit\*" -Recurse
Remove-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\@Rmskins\*.zip" -Recurse
Invoke-Item ".\Droptop Folders\Other files\@Rmskins\Droptop Apps"