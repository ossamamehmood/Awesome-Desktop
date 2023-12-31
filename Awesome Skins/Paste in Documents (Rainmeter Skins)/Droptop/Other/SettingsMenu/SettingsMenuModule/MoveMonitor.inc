[Rainmeter]

[Variables]

NextX=(#Xnum#+1)
PrevX=(#Xnum#-1)

NextStretch=(#StretchNum#+1)

LinkA0=
LinkB0=[ms-settings:display]

LinkA1=
LinkB1=[ms-settings:display]

[2]
Y=(#DividerSpace#*2)R
Group=2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Group2

[2Icon]
Y=(#DividerSpace#*2)R
Group=2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Group2 | ItemIcon

[3]
Group=3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Group2

[3Icon]
Group=3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Group2 | ItemIcon

[4]
Y=(#DividerSpace#*2)R
Group=4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Group2

[4Icon]
Y=(#DividerSpace#*2)R
Group=4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Group2 | ItemIcon

[Divider1]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*1)+(#DropdownItemHeight#*1)-(#DividerHeight#/2))

[Divider2]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*3)+(#DropdownItemHeight#*3)-(#DividerHeight#/2))

[5]
Group=5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Group1

[5Icon]
Group=5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Group1 | ItemIcon

;-----------------------------------

[SetMouseActions]
Measure=Calc
IfCondition=#AlwaysShowSkin#=1
IfTrueAction=[!ShowMeter HiddenOverlay][!DisableMouseActionGroup "LeftMouseDownAction|MouseOverAction|MouseLeaveAction" Group2][!SetOptionGroup Group2 FontColor "#*DropdownFontColor1*#,75"][!SetOptionGroup Group2 ImageAlpha 75][!UpdateMeterGroup Group2][!Redraw]
IfCondition2=#StretchNum#=0
IfTrueAction2=[!DisableMouseActionGroup "LeftMouseDownAction|MouseOverAction|MouseLeaveAction" Group1][!SetOptionGroup Group1 FontColor "#*DropdownFontColor1*#,75"][!SetOptionGroup Group1 ImageAlpha 75][!UpdateMeterGroup Group1][!Redraw]
IfCondition3=(#SCREENAREAWIDTH@1# <> #SCREENAREAWIDTH@2#) || (#SCREENAREAWIDTH@1# <> #SCREENAREAWIDTH@3#)
IfTrueAction3=[!ShowMeter HiddenOverlay2][!DisableMouseActionGroup "LeftMouseDownAction|MouseOverAction|MouseLeaveAction" Group2][!SetOptionGroup Group2 FontColor "#*DropdownFontColor1*#,75"][!SetOptionGroup Group2 ImageAlpha 75][!UpdateMeterGroup Group2][!Redraw]

[OverlayStyle]
X=1
Y=(((#DropdownIconYoffset#+(#DropdownItemHeight#*1))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)*1)
W=#DropdownMenuWidth#
H=((#DropdownItemHeight#*4)+(#DividerSpace#*4))
LeftMouseDownAction=[!Hide "Droptop\Other\Misc\Tooltip"][!DeactivateConfig "Droptop\Other\Misc\Tooltip"]
RightMouseDownAction=[!Hide "Droptop\Other\Misc\Tooltip"][!DeactivateConfig "Droptop\Other\Misc\Tooltip"]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Shape "Rectangle 0,0,40,40,16 | Fill Color 255,255,255,5 | Stroke Color 255,255,255,15 | StrokeWidth 2"][!UpdateMeter #CURRENTSECTION#][!Redraw][!DeactivateConfig "Droptop\Other\Misc\Tooltip"]
DynamicVariables=1

[HiddenOverlay]
Meter=Image
MeterStyle=OverlayStyle
MouseOverAction=[!WriteKeyValue Variables TooltipTitle "#*Context1Item3TooltipTitleA*#" "#SKINSPATH#Droptop\Other\Misc\Tooltip\Tooltip2.ini"][!WriteKeyValue Variables TooltipText """#*Context1Item3TooltipContentA*#""" "#SKINSPATH#Droptop\Other\Misc\Tooltip\Tooltip2.ini"][!ActivateConfig "Droptop\Other\Misc\Tooltip" "Tooltip2.ini"][!Move ([#CURRENTCONFIGX]+(#CURRENTCONFIGWIDTH#/2)) ([#CURRENTCONFIGY]+(#CURRENTCONFIGHEIGHT#/2)) "Droptop\Other\Misc\Tooltip"][!Show "Droptop\Other\Misc\Tooltip"]
Hidden=1

[HiddenOverlay2]
Meter=Image
MeterStyle=OverlayStyle
MouseOverAction=[!WriteKeyValue Variables TooltipTitle "#*Context1Item3TooltipTitleB*#" "#SKINSPATH#Droptop\Other\Misc\Tooltip\Tooltip2.ini"][!WriteKeyValue Variables TooltipText """#*Context1Item3TooltipContentB*#""" "#SKINSPATH#Droptop\Other\Misc\Tooltip\Tooltip2.ini"][!ActivateConfig "Droptop\Other\Misc\Tooltip" "Tooltip2.ini"][!Move ([#CURRENTCONFIGX]+(#CURRENTCONFIGWIDTH#/2)) (#SettingsMenuYpos#+(#CURRENTCONFIGHEIGHT#/2)) "Droptop\Other\Misc\Tooltip"][!Show "Droptop\Other\Misc\Tooltip"]
Hidden=1