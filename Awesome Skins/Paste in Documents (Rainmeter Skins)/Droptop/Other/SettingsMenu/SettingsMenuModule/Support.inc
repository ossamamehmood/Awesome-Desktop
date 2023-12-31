[Rainmeter]

[Variables]

SupportText0=#SettingsUpdateText4#
SupportText1=#SettingsSupport5#

SupportIcon0=thumbsup
SupportIcon1=cloud

SupportAction0=["https://gumroad.com/l/droptop"]#CloseSettingsMenu#
SupportAction1=[!SetOption 5 Text "#SettingsUpdateText1#"][!DisableMouseAction 5 "LeftMouseDownAction"][!EnableMeasureGroup Update][!UpdateMeasureGroup Update][!UpdateMeter 5][!Redraw]

[SkinVersionMini]
Measure=Calc
Formula=((#SkinVersionMini#+1)>99?0:(#SkinVersionMini#+1))

[SkinVersionTime]
Measure=Time
Format="%m%d.%H%M"
DynamicVariables=1

[CheckUpdate]
Measure=WebParser
Url=https://blacksquare88.wixsite.com/droptop4
RegExp=(?siU)Current version: (.*)</span>
UpdateRate=1500
Group=Update
Disabled=1
FinishAction=[!EnableMeasure CompareVersions][!UpdateMeasure CompareVersions]
OnRegExpErrorAction=[!SetOption 5 Text "#SettingsUpdateText2#"][!UpdateMeter 5][!Redraw]
OnErrorAction=

[NewVersionNum]
Measure=WebParser
Url=[CheckUpdate]
StringIndex=1
Substitute="":"0"
Group=Update
Disabled=1

[CompareVersions]
Measure=Calc
Formula=[NewVersionNum]
IfAboveValue=#SkinVersion#
IfAboveAction=[!EnableMouseAction 5 "LeftMouseDownAction"][!SetOption 5 Text "#SettingsUpdateText3#"][!SetOption 5 LeftMouseDownAction """["https://blacksquare88.wixsite.com/droptop4/download"]#CloseSettingsMenu#"""][!UpdateMeter 5][!Redraw]
IfEqualValue=#SkinVersion#
IfEqualAction=[!DisableMouseAction 5 "LeftMouseDownAction"][!SetOption 5 Text "#SettingsUpdateText2#"][!UpdateMeter 5][!Redraw]
IfBelowValue=#SkinVersion#
IfBelowAction=[!DisableMouseAction 5 "LeftMouseDownAction"][!SetOption 5 Text "#SettingsUpdateText2#"][!UpdateMeter 5][!Redraw]
DynamicVariables=1
Disabled=1

[5]
Y=(#DividerSpace#*2)R

[5Icon]
Y=(#DividerSpace#*2)R

[7]
RightMouseDoubleClickAction=[!SetClip "#SkinVersion#.[SkinVersionMini]"][!WriteKeyValue Variables FolderLoc5 "[\x0025]USERPROFILE[\x0025]" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables DownloadsLoc "[\x0025]USERPROFILE[\x0025]\Downloads" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables USER "[\x0025]USERNAME[\x0025]" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables SkinVersionMini "[SkinVersionMini]" "#@#GlobalVar\Control.inc"][!WriteKeyValue Variables SkinVersionTime "[SkinVersionTime]" "#@#GlobalVar\Control.inc"][!WriteKeyValue Variables SupporterVersion "#SkinVersion#" "#SKINSPATH#Droptop\Other\Welcome\99.inc"][!WriteKeyValue Variables SkinVersion "#SkinVersion#" "#SKINSPATH#Droptop\Other\Welcome\100.inc"][!WriteKeyValue Variables SkinVersionMini "[SkinVersionMini]" "#SKINSPATH#Droptop\Other\Welcome\100.inc"][!WriteKeyValue rmskin Version "#SkinVersion#.[SkinVersionMini]" "#SKINSPATH#Redistributables\Basic-Version\RMSKIN.ini"][!WriteKeyValue rmskin Version "#SkinVersion#.[SkinVersionMini]" "#SKINSPATH#Redistributables\Supporter-Version\RMSKIN.ini"][!WriteKeyValue rmskin Version "#SkinVersion#.[SkinVersionMini]" "#SKINSPATH#Redistributables\Update\RMSKIN.ini"]["#@#Scripts\Other\CompileDroptop.bat" "#SKINSPATH#]

[8]
Y=(#DividerSpace#*2)R

[8Icon]
Y=(#DividerSpace#*2)R

[Divider1]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*1)+(#DropdownItemHeight#*4)-(#DividerHeight#/2))

[Divider2]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*3)+(#DropdownItemHeight#*7)-(#DividerHeight#/2))