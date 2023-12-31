[Rainmeter]
OnRefreshAction=[]

[Metadata]
Name=Droptop Four
Author=Cariboudjan / Thomas Sven Whittaker
Information=The frogurt is also cursed
License=Creative Commons Attribution-Non-Commercial-Share Alike 3.0

[Variables]
SettingsMenuNumber=1.6.1

16=1
32=2

;----------------------------------
LuaLoc=#@#Scripts\Lua\DropScroll.lua
;----------------------------------
NumberOfItems=5

MaxItem=5

ScrollTracker=5
AboveTotal=1

1Match=1
2Match=2
3Match=3
4Match=4
5Match=5

MeasureAppName1=1
MeasureAppName2=2
MeasureAppName3=3
MeasureAppName4=4
MeasureAppName5=5

[ScrollCheck]
Measure=Calc
IfCondition=AnalyzeTotal = #ScrollTracker#
IfTrueAction=[!SetOptionGroup Items MouseScrollDownAction """[]"""]
IfFalseAction=[!SetOptionGroup Items MouseScrollDownAction ""]
IfCondition2=#ScrollTracker# = #MaxItem#
IfTrueAction2=[!SetOptionGroup Items MouseScrollUpAction """[]"""]
IfFalseAction2=[!SetOptionGroup Items MouseScrollUpAction ""]
DynamicVariables=1

;----------------------------------------------------
; Styles
;----------------------------------------------------

[InfoStyle]
; MeasureName=mIndex#CURRENTSECTION#Name
MeasureName=MeasureAppName#CURRENTSECTION#
FontColor=#DropdownFontColor1#,#DropdownItemOpacity#
FontFace=[#FontName[#AltFont[#LanguageNum]]]
FontSize=#DropdownItemFontSize#
X=(1+(#DropdownMenuWidth#*#RTLText#))
Y=R
H=#DropdownItemHeight#
AntiAlias=#DropdownAntiAlias#
LeftMouseDownAction=#OptionChanged#[!WriteKeyValue Variables HideAppCustomApp#SettingsMenuIndex# 0 "#@#GlobalVar\FolderSettings.inc"][!WriteKeyValue Variables CustomAppID#SettingsMenuIndex# "[&mIndex[#CURRENTSECTION]Name]" "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables CustomAppPosition #SettingsMenuIndex# "#SKINSPATH#Droptop Community Apps\Apps\[&mIndex[#CURRENTSECTION]Name]\Config\MainConfig.inc"][!WriteKeyValue Variables [&mIndex[#CURRENTSECTION]Name] #SettingsMenuIndex# "#@#GlobalVar\UserSettings.inc"][!RefreshGroup SM2]
RightMouseDownAction=[!CommandMeasure mIndex#CURRENTSECTION#Name "ContextMenu"][!DeactivateConfigGroup Tray][!SetVariable ActiveTray 0 "Droptop\DropdownBar"][!HideMeter HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup SysTray "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]
MiddleMouseDownAction=[!CommandMeasure mIndex#CURRENTSECTION#Name "Open"][!SetVariable ActiveTray 0 "Droptop\DropdownBar"][!Hide "#CURRENTCONFIG#"][!HideMeterGroup HighlightSelected "Droptop\DropdownBar"][!UpdateMeterGroup SysTray "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"][!DeactivateConfig]
MouseScrollUpAction=[!SetVariable ScrollTracker (#ScrollTracker#<=#MaxItem#?#MaxItem#:(#ScrollTracker#-#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-#MaxItem#)][!CommandMeasure mPath "PageUp"][!UpdateMeasure *][!UpdateMeter *][!Redraw]
MouseScrollDownAction=[!SetVariable ScrollTracker (#ScrollTracker#>=[AnalyzeTotal]?[AnalyzeTotal]:(#ScrollTracker#+#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!CommandMeasure mPath "PageDown"][!UpdateMeasure *][!UpdateMeter *][!Redraw]
DynamicVariables=1
UpdateDivider=-1
ClipString=1
Hidden=1
; Group=Items

[IconStyle]
MeasureName=mIndex[##CURRENTSECTION#]Name
ImageName=#SKINSPATH#Droptop Community Apps\Apps\%1\Button\Medium\Button.png
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#))
Y=R
W=#IconW#
H=#IconH#
PreserveAspectRatio=1
ImageCrop=-16,-16,32,32,5
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
UpdateDivider=-1
Hidden=1

;----------------------------------------------------
; Measures
;----------------------------------------------------

[mPath]
Measure=Plugin
Plugin=FileView
Path="#SKINSPATH#Droptop Community Apps\Apps\"
ShowDotDot=0
SortType=Name
SortAscending=1
SortDateType=
ShowFile=0
ShowFolder=1
ShowSystem=0
ShowHidden=0
HideExtensions=0
;WildCardSearch="**"
;Recursive=0
Count=#MaxItem#
FinishAction=[!UpdateMeterGroup Items][!Redraw]

;----------------------------------------------------

[FolderCount]
Measure=Plugin
Plugin=FolderInfo
Folder="[mPath]"
InfoType=FolderCount
IncludeHiddenFiles=0
IncludeSubFolders=0
IncludeSystemFiles=1
DynamicVariables=1

[AnalyzeTotal]
Measure=Calc
Formula=FolderCount
IfCondition=(#CURRENTSECTION# > #NumberOfItems#) && (#NumberOfItems# < #MaxItem#)
IfTrueAction=[!WriteKeyValue Variables NumberOfItems ([#CURRENTSECTION#]=0?1:[#CURRENTSECTION#]) "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenuModule\CustomAppSelect.inc"][!Refresh]
IfCondition2=#CURRENTSECTION# > #MaxItem#
IfTrueAction2=[!WriteKeyValue Variables AboveTotal 1 "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenuModule\CustomAppSelect.inc"][!WriteKeyValue Variables NumberOfItems #MaxItem# "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenuModule\CustomAppSelect.inc"][!SetVariable AboveTotal 1][!SetVariable NumberOfItems #MaxItem#][!ShowMeterGroup #MaxItem#][!EnableMeasureGroup Scrollbar][!ShowMeterGroup Scrollbar][!UpdateMeasure *][!UpdateMeter *][!Redraw]
IfFalseAction2=[!WriteKeyValue Variables AboveTotal 0 "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenuModule\CustomAppSelect.inc"][!WriteKeyValue Variables NumberOfItems ([#CURRENTSECTION#]=0?1:[#CURRENTSECTION#]) "#SKINSPATH#Droptop\Other\SettingsMenu\SettingsMenuModule\CustomAppSelect.inc"][!SetVariable AboveTotal 1][!SetVariable NumberOfItems ([#CURRENTSECTION#]=0?1:[#CURRENTSECTION#])][!ShowMeterGroup [#CURRENTSECTION#]]

[AnalyzeTotal]
Measure=Calc
Formula=FolderCount
IfCondition=FolderCount > #MaxItem#
IfTrueAction=[!EnableMeasureGroup Scrollbar][!ShowMeterGroup Scrollbar]
IfFalseAction=[!DisableMeasureGroup Scrollbar][!HideMeterGroup Scrollbar]
DynamicVariables=1

;----------------------------------------------------
; Background Meters
;----------------------------------------------------

[Background]
Shape=Rectangle #DropdownMenuCutout#,#DropdownMenuCutout#,(#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*#NumberOfItems#+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(#DropdownMenuLandingHeight#)-(#DropdownMenuCutout#*2)),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#

;----------------------------------------------------
; Index 1

[mIndex1Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=1
Substitute=" ":""

;----------------------------------------------------
; Index 2

[mIndex2Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=2
Substitute=" ":""

;----------------------------------------------------
; Index 3

[mIndex3Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=3
Substitute=" ":""

;----------------------------------------------------
; Index 4

[mIndex4Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=4
Substitute=" ":""

;----------------------------------------------------
; Index 5

[mIndex5Name]
Measure=Plugin
Plugin=FileView
Path=[mPath]
Type=FileName
Index=5
Substitute=" ":""

;----------------------------------------------------

[MeasureAppName1]
Measure=String
String=[&mIndex[##CURRENTSECTION#]Name]
Substitute="_":" ","-":" - "
DynamicVariables=1

[MeasureAppName2]
Measure=String
String=[&mIndex[##CURRENTSECTION#]Name]
Substitute="_":" ","-":" - "
DynamicVariables=1

[MeasureAppName3]
Measure=String
String=[&mIndex[##CURRENTSECTION#]Name]
Substitute="_":" ","-":" - "
DynamicVariables=1

[MeasureAppName4]
Measure=String
String=[&mIndex[##CURRENTSECTION#]Name]
Substitute="_":" ","-":" - "
DynamicVariables=1

[MeasureAppName5]
Measure=String
String=[&mIndex[##CURRENTSECTION#]Name]
Substitute="_":" ","-":" - "
DynamicVariables=1

;----------------------------------------------------

[1Match]
Measure=String
String="[&mIndex[##CURRENTSECTION#]Name]"
IfMatch=[#CustomAppID1]|[#CustomAppID2]|[#CustomAppID3]|[#CustomAppID4]|[#CustomAppID5]
IfMatchAction=[!DisableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor "#*DropdownFontColor1*#,75"][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha 75][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
IfNotMatchAction=[!EnableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor ""][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha "255"][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
DynamicVariables=1

[2Match]
Measure=String
String="[&mIndex[##CURRENTSECTION#]Name]"
IfMatch=[#CustomAppID1]|[#CustomAppID2]|[#CustomAppID3]|[#CustomAppID4]|[#CustomAppID5]
IfMatchAction=[!DisableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor "#*DropdownFontColor1*#,75"][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha 75][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
IfNotMatchAction=[!EnableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor ""][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha "255"][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
DynamicVariables=1

[3Match]
Measure=String
String="[&mIndex[##CURRENTSECTION#]Name]"
IfMatch=[#CustomAppID1]|[#CustomAppID2]|[#CustomAppID3]|[#CustomAppID4]|[#CustomAppID5]
IfMatchAction=[!DisableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor "#*DropdownFontColor1*#,75"][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha 75][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
IfNotMatchAction=[!EnableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor ""][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha "255"][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
DynamicVariables=1

[4Match]
Measure=String
String="[&mIndex[##CURRENTSECTION#]Name]"
IfMatch=[#CustomAppID1]|[#CustomAppID2]|[#CustomAppID3]|[#CustomAppID4]|[#CustomAppID5]
IfMatchAction=[!DisableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor "#*DropdownFontColor1*#,75"][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha 75][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
IfNotMatchAction=[!EnableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor ""][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha "255"][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
DynamicVariables=1

[5Match]
Measure=String
String="[&mIndex[##CURRENTSECTION#]Name]"
IfMatch=[#CustomAppID1]|[#CustomAppID2]|[#CustomAppID3]|[#CustomAppID4]|[#CustomAppID5]
IfMatchAction=[!DisableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor "#*DropdownFontColor1*#,75"][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha 75][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
IfNotMatchAction=[!EnableMouseAction [##CURRENTSECTION#] "LeftMouseDownAction|MouseOverAction|MouseLeaveAction"][!SetOption [##CURRENTSECTION#] FontColor ""][!SetOption [##CURRENTSECTION#]Icon ImageTint "#*DropdownFontColor1*#"][!SetOption [##CURRENTSECTION#]Icon ImageAlpha "255"][!UpdateMeter [##CURRENTSECTION#]][!Redraw]
DynamicVariables=1

;----------------------------------------------------
; Scrollbar
;----------------------------------------------------

[ScrollbarTop]
Meter=Image
X=3
Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#-1)
UpdateDivider=-1

[Size]
Measure=Calc
Formula=((#DropdownItemHeight#*#MaxItem#)-#DropdownIconYoffset#)
UpdateDivider=-1
Group=Scrollbar

[ScrollH]
Measure=Calc
Formula=Size * (#MaxItem# / (AnalyzeTotal = 0 ? 1 : AnalyzeTotal))
Group=Scrollbar
Disabled=1

[ScrollbarScript]
Measure=Script
ScriptFile=#LuaLoc#
UpdateDivider=-1

[CurrentPos]
Meter=Shape
Shape=Rectangle 0,0,(3*#DroptopSize#),([ScrollH]<1?1:[ScrollH]),2 | Fill Color #DropdownFontColor1#,155 | StrokeWidth 0 | StrokeColor #DropdownBGColor1#,55
X=(#DropdownMenuWidth#-(3*#DroptopSize#)-(#DropdownStrokeWidth#/2))
Y=(#DropdownIconYoffset#-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+1)
DynamicVariables=1
Group=ScrollBar | Items
Hidden=1

;-------------------------------------------

[OpenFolder]
Meter=Image
ImageName=#@#Icons\Fixed\Medium\dot.png
ImageTint=#DropdownFontColor1#,#DropdownItemOpacity#
ImageAlpha=55
X=(8*#DroptopSize#)
Y=(#DropdownIconYoffset#+(#DropdownItemHeight#*#NumberOfItems#)-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#+#DropdownBottomButtonOffset#)
H=(16*#DroptopSize#)
LeftMouseDownAction=[!SetVariable ActiveTray 0 "Droptop\DropdownBar"][!Hide "Droptop\Other\SystemTray\Home"][!HideGroup Tray][!UpdateMeterGroup SysTray "Droptop\DropdownBar"][!Redraw "Droptop\DropdownBar"]["[mPath]"]
MouseOverAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\open.png"][!SetOption #CURRENTSECTION# ImageAlpha #DropdownItemOpacity#][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageName "#@#Icons\Fixed\Medium\dot.png"][!SetOption #CURRENTSECTION# ImageAlpha 55][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
UpdateDivider=-1

[DownArrow]
Meter=Shape
Shape=Rectangle (-5*#DroptopSize#),(-1*#DroptopSize#),(21*#DroptopSize#),(21*#DroptopSize#),0 | Fill Color 0,0,0,0 | StrokeWidth 0
Shape2=Rectangle 0,(-1*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45 | Extend Look
Shape3=Rectangle 0,(-3*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45
Shape4=Combine Shape2 | Exclude Shape3
Look=Fill Color #DropdownFontColor1#,(#ScrollTracker#>=[AnalyzeTotal]?0:(#DropdownItemOpacity#/3))
LeftMouseDownAction=[!SetVariable ScrollTracker (#ScrollTracker#>=[AnalyzeTotal]?[AnalyzeTotal]:(#ScrollTracker#+#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(#MaxItem#)][!CommandMeasure mPath "PageDown"][!UpdateMeasure *][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#>=[AnalyzeTotal]?0:#DropdownItemOpacity#)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#>=[AnalyzeTotal]?0:(#DropdownItemOpacity#/3))"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#DropdownMenuWidth#-(25*#DroptopSize#))
Y=r
DynamicVariables=1

[UpArrow]
Meter=Shape
Shape=Rectangle (-5*#DroptopSize#),(-1*#DroptopSize#),(21*#DroptopSize#),(21*#DroptopSize#),0 | Fill Color 0,0,0,0 | StrokeWidth 0
Shape2=Rectangle 0,(6*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45 | Extend Look
Shape3=Rectangle 0,(8*#DroptopSize#),(11*#DroptopSize#),(11*#DroptopSize#),0 | StrokeWidth 0 | Rotate 45
Shape4=Combine Shape2 | Exclude Shape3
Look=Fill Color #DropdownFontColor1#,(#ScrollTracker#<=#MaxItem#?0:(#DropdownItemOpacity#/3))
LeftMouseDownAction=[!SetVariable ScrollTracker (#ScrollTracker#<=#MaxItem#?#MaxItem#:(#ScrollTracker#-#MaxItem#))][!CommandMeasure ScrollbarScript UpdateCurrentPos(-#MaxItem#)][!CommandMeasure mPath "PageUp"][!UpdateMeasure *][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#<=#MaxItem#?0:#DropdownItemOpacity#)"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Look "Fill Color #*DropdownFontColor1*#,(#*ScrollTracker*#<=#MaxItem#?0:(#DropdownItemOpacity#/3))"][!UpdateMeter #CURRENTSECTION#][!Redraw]
X=(#DropdownMenuWidth#-(45*#DroptopSize#))
Y=r
DynamicVariables=1
