[Rainmeter]
OnRefreshAction=[!Zpos 1][!KeepOnScreen 1][!Draggable 0][!WriteKeyValue Variables TopBarWidth #WORKAREAWIDTH# "#@#GlobalVar\Control.inc"][!DeactivateConfig "Droptop\DropdownBar"][!DeactivateConfig "Droptop\Other\BackgroundProcesses"]

[Variables]
@IncludeUserSettings=#@#GlobalVar\UserSettings.inc

[LoadActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 150 | Start0 | Wait 1500 | Start1 | Wait 750 | Start2 | ClickOn

[PSRM]
Measure=Plugin
Plugin=PowershellRM
DynamicVariables=1
ScriptFile=#@#Scripts\Powershell\Func.ps1

[RunCommand.Restart]
Measure=Plugin
Plugin=RunCommand
Parameter=taskkill /f /im "Rainmeter.exe" & start "" "#PROGRAMPATH#Rainmeter.exe"
State=Hide
OutputType=ANSI
OutputFile=

[Start]
Measure=Calc
IfCondition=#FirstLoad#=1
IfTrueAction=[!WriteKeyValue Variables Page 1][!Delay 2000][!Refresh]
IfFalseAction=[!Delay 1000][!CommandMeasure PSRM "MakeShortcut"][!WriteKeyValue Variables FirstLoad 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables Page 1][!CommandMeasure MeasureCreateFolders "Run"]

[MeasureOSVersion]
Measure=Plugin
Plugin=SysInfo
SysInfoType=OS_VERSION
Substitute=".*Windows 10.*":"1",".*Windows 11.*":"2"
RegExpSubstitute=1
IfMatch=1
IfMatchAction=[!WriteKeyValue Variables OSVERSION 10 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables Win10Apps 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables DropdownRoundCorners 0 "#@#Themes\1Settings.inc"][!WriteKeyValue Variables DropdownRoundCorners 0 "#@#Themes\2Settings.inc"][!WriteKeyValue Variables DropdownMenuShadow 1 "#@#Themes\1Settings.inc"][!WriteKeyValue Variables DropdownMenuShadow 1 "#@#Themes\2Settings.inc"]
IfMatch2=2
IfMatchAction2=[!WriteKeyValue Variables OSVERSION 11 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables Win10Apps 0 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables DropdownRoundCorners 1 "#@#Themes\1Settings.inc"][!WriteKeyValue Variables DropdownRoundCorners 1 "#@#Themes\2Settings.inc"][!WriteKeyValue Variables DropdownMenuShadow 0 "#@#Themes\1Settings.inc"][!WriteKeyValue Variables DropdownMenuShadow 0 "#@#Themes\2Settings.inc"]

[MeasureCreateFolders]
Measure=Plugin
Plugin=RunCommand
Parameter=reg add "HKEY_CURRENT_USER\SOFTWARE\Microsoft\Windows NT\CurrentVersion\AppCompatFlags\Layers" /v "#PROGRAMPATH#Rainmeter.exe" /t "REG_SZ" /d "~ HIGHDPIAWARE" /f & "Wscript.exe" "#SKINSPATH#Droptop\@Resources\Scripts\IconsColor1.vbs" "#SKINSPATH#" & xcopy /a /y /i /f "%PROGRAMDATA%\Microsoft\Windows\Start Menu\Programs" "#SKINSPATH#Droptop Folders\PinnedApps" & xcopy /s /y /i /f "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Steam" "#SKINSPATH#Droptop Folders\Games"
State=Hide
OutputType=ANSI
OutputFile=
; FinishAction=["#SKINSPATH#Droptop\@Resources\Scripts\RestartRainmeter.bat" "#PROGRAMPATH#]
FinishAction=[!CommandMeasure RunCommand.Restart "Run"]

[Container]
Meter=String
