[Rainmeter]
OnCloseAction=[!EnableMouseAction * "MouseOverAction|MouseLeaveAction" "Droptop\Other\SettingsMenu\SettingsMenu1"][!EnableMouseAction * "MouseOverAction|MouseLeaveAction" "Droptop\Other\SettingsMenu\SettingsMenu2"][!EnableMouseAction * "MouseOverAction|MouseLeaveAction" "Droptop\Other\SettingsMenu\SettingsMenu3"][!EnableMouseAction * "MouseOverAction|MouseLeaveAction" "Droptop\Other\SettingsMenu\SettingsMenu4"][!EnableMouseAction * "MouseOverAction|MouseLeaveAction" "Droptop\DropdownBar\Other\ContextBox"][!SetVariableGroup AnimationOFF 1 "SettingsMenu"][!UpdateGroup SettingsMenu]
Update=100

[Variables]
DropdownItemPadding1=#DropdownNoIconPadding#

DropdownBGCorner=0

;---------------------------

[MeasureMouseX]
Measure=Plugin
Plugin=MouseXY
Dimension=X
IfAboveValue=(#CURRENTCONFIGX#+#CURRENTCONFIGWIDTH#)
IfAboveAction=["#@#Scripts\DroptopAHK.#AHKType#" "EscapeKey"][!DisableMeasureGroup XY][!UpdateMeasureGroup XY]
IfBelowValue=(#CURRENTCONFIGX#)
IfBelowAction=["#@#Scripts\DroptopAHK.#AHKType#" "EscapeKey"][!DisableMeasureGroup XY][!UpdateMeasureGroup XY]
DynamicVariables=1
Disabled=1
Group=XY

[MeasureMouseY]
Measure=Plugin
Plugin=MouseXY
Dimension=Y
IfAboveValue=(#CURRENTCONFIGY#+#CURRENTCONFIGHEIGHT#)
IfAboveAction=["#@#Scripts\DroptopAHK.#AHKType#" "EscapeKey"][!DisableMeasureGroup XY][!UpdateMeasureGroup XY]
IfBelowValue=(#CURRENTCONFIGY#)
IfBelowAction=["#@#Scripts\DroptopAHK.#AHKType#" "EscapeKey"][!DisableMeasureGroup XY][!UpdateMeasureGroup XY]
DynamicVariables=1
Disabled=1
Group=XY

;---------------------------

[MeasureRegistry]
Measure=Registry
RegHKey=HKEY_CURRENT_USER
RegKey=Control Panel\Desktop\WindowMetrics
RegValue=AppliedDPI
UpdateDivider=-1

[InputTextFontSize]
Measure=Calc
Formula=(((10*#DroptopSize#)-((((10*#DroptopSize#)*(((ROUND(([MeasureRegistry]/100)/0.25)))*0.25))-(10*#DroptopSize#))/2))-(((10*#DroptopSize#)-((((10*#DroptopSize#)*(((ROUND(([MeasureRegistry]/100)/0.25)))*0.25))-(10*#DroptopSize#))/2))%1))
DynamicVariables=1

;---------------------------

[1]
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor "0,0,0,255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor "0,0,0,155"][!UpdateMeter #CURRENTSECTION#][!Redraw]

[LocationText]
InlineSetting2=
StringAlign=LeftCenter
Meter=String
MeterStyle=InfoStyle
FontFace=#UniversalFont#
FontWeight=
FontSize=(10*#DroptopSize#)
SolidColor=255,255,255
FontColor=0,0,0,185
Text=#WeatherLocation#
MouseOverAction=[]
MouseLeaveAction=[]
LeftMouseUpAction=[!EnableMeasureGroup XY][!UpdateMeasureGroup XY][!SetVariableGroup AnimationOFF 0 "SettingsMenu"][!UpdateGroup SettingsMenu][!CommandMeasure 1InputField "ExecuteBatch 1"]
X=(1+#DropdownStrokeWidth#)
W=(#DropdownMenuWidth#-(#DropdownStrokeWidth#*2)-#DropdownNoIconPadding#+1)
Y=((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#)
Padding=#DropdownNoIconPadding#,0,0,0
Hidden=1
Group=1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | Items 

[2]
Text=""
MouseOverAction=[]
MouseLeaveAction=[]

[3]
FontColor=#DropdownFontColor1#,128
MouseOverAction=[]
MouseLeaveAction=[]
Y=(#DropdownItemHeight#*(#NumberOfItems#-1)+((#DropdownIconYoffset#+(#DropdownItemHeight#/2))-((#DropdownIconYoffset#+(#DropdownItemHeight#/2))%1)+#DropdownItemYOffset#))
Hidden=0

[4]
Hidden=1

[1InputField]
Measure=Plugin
Plugin=InputText.dll
FontFace=#UniversalFont#
StringAlign=Left
FontSize=[InputTextFontSize]
AntiAlias=1
W=([LocationText:W]-(24*#DroptopSize#))
H=(#DropdownItemHeight#*0.75)
X=(([1:X]+#DropdownNoIconPadding#)+(1*#DroptopSize#))
Y=([LocationText:Y]+(#DropdownItemHeight#*0.25)-((0.5*#DroptopSize#)*#DroptopSize#))
FocusDismiss=0
Command1=[!SetVariable WeatherLocation "$UserInput$"][!UpdateMeasure CheckInputChange]
DefaultValue="#WeatherLocation#"
DynamicVariables=1

[CheckInputChange]
Measure=String
String=#WeatherLocation#
OnChangeAction=[!SetOption LocationText Text "#SettingsWeather3#"][!WriteKeyValue Variables WeatherLocation "#WeatherLocation#" "#@#GlobalVar\UserSettings.inc"][!ActivateConfig "Droptop\Other\BackgroundProcesses\Tasks" "WeatherParser.ini"][!UpdateMeter LocationText][!Redraw]
DynamicVariables=1