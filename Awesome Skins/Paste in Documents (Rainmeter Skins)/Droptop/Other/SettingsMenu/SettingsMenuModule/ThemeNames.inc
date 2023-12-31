[Rainmeter]

[Variables]
@Include99Settings=#@#Themes\99Settings.inc
@IncludeNumSettings=#@#Themes\#ThemeNum#Settings.inc

[MeasureSupporter]
Measure=Calc
IfCondition=#Supporter#=0
IfTrueAction=[!SetOptionGroup SupporterThemes ImageName "#@#Icons\Fixed\#IconSize#\lock.png"][!Redraw]

[InfoStyle]
MiddleMouseUpAction=["#@#Themes\#CURRENTSECTION#Settings.inc"]#CloseSettingsMenu#

[CustomThemeName]
Measure=String
String=#CustomThemeName#
Substitute="My Custom Theme":"#ThemeName99#"

; [Divider1]
; Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*1)+(#DropdownItemHeight#*22)-(#DividerHeight#/2))

; [23]
; Y=(#DividerSpace#*2)R

; [23Icon]
; Y=(#DividerSpace#*2)R

; [23Arrow]
; Y=(#DividerSpace#*2)R