$themename=$args[0]
$themeauthor=$args[1]
$fontname=$args[2]
$skinspath=$args[3]

cd "$skinspath"
New-Item -ItemType "directory" -Path ".\Droptop Folders\Other files\@Rmskins\Droptop Themes"
Remove-Item -Path ".\Droptop Folders\Other files\@Rmskins\Droptop Themes\$themename - $themeauthor (Droptop Theme).rmskin" -Recurse
Remove-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\@Rmskins\*.rmskin" -Recurse
Remove-Item -Path ".\Droptop\@Resources\Scripts\AppBuilder\@Rmskins\*.zip" -Recurse
Copy-Item ".\Droptop\@Resources\Themes\99.inc" -Destination ".\Droptop\@Resources\Scripts\AppBuilder\ThemeTemplate\Skins\Droptop\@Resources\Themes" -Recurse
Copy-Item ".\Droptop\@Resources\Themes\99Settings.inc" -Destination ".\Droptop\@Resources\Scripts\AppBuilder\ThemeTemplate\Skins\Droptop\@Resources\Themes" -Recurse
Copy-Item ".\Droptop\@Resources\Fonts\$fontname.tff" -Destination ".\Droptop\@Resources\Scripts\AppBuilder\ThemeTemplate\Skins\Droptop\@Resources\Fonts" -Recurse
Copy-Item ".\Droptop\@Resources\Fonts\$fontname.otf" -Destination ".\Droptop\@Resources\Scripts\AppBuilder\ThemeTemplate\Skins\Droptop\@Resources\Fonts" -Recurse
cd .\Droptop\@Resources\Scripts\AppBuilder
.\MakeRmSkin.ps1 -Skin ThemeTemplate
cd "$skinspath"
Move-Item -Path '.\Droptop\@Resources\Scripts\AppBuilder\@Rmskins\ThemeTemplate.rmskin' -Destination ".\Droptop Folders\Other files\@Rmskins\Droptop Themes\$themename - $themeauthor (Droptop Theme).rmskin"
cd .\Droptop\@Resources\Scripts\AppBuilder
Remove-Item -Path ".\ThemeTemplate\Skins\Droptop\@Resources\Themes\*" -Recurse
Remove-Item -Path ".\@Rmskins\*.zip" -Recurse
cd "$skinspath"
Invoke-Item '.\Droptop Folders\Other files\@Rmskins\Droptop Themes'