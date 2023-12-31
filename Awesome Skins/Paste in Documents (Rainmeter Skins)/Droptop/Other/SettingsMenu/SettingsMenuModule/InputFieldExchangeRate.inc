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

[CheckCurrency1Change]
Measure=String
String=#ExchangeCurrency1#
OnChangeAction=#OptionChanged#[!WriteKeyValue Variables ExchangeCurrency1 [#CURRENTSECTION#] "#@#GlobalVar\UserSettings.inc"][!SetOption 1 Text #ExchangeCurrency1#][!UpdateMeter 1][!Redraw]
DynamicVariables=1

[CheckCurrency2Change]
Measure=String
String=#ExchangeCurrency2#
OnChangeAction=#OptionChanged#[!WriteKeyValue Variables ExchangeCurrency2 [#CURRENTSECTION#] "#@#GlobalVar\UserSettings.inc"][!SetOption 2 Text #ExchangeCurrency2#][!UpdateMeter 2][!Redraw]
DynamicVariables=1
Group=Password

[1]
InlineSetting2=
StringAlign=LeftCenter
FontSize=(10*#DroptopSize#)
FontFace=#UniversalFont#
FontWeight=
SolidColor=255,255,255
FontColor=0,0,0,185
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor "0,0,0,255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor "0,0,0,185"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!EnableMeasureGroup XY][!UpdateMeasureGroup XY][!SetVariableGroup AnimationOFF 0 "SettingsMenu"][!UpdateGroup SettingsMenu][!CommandMeasure #CURRENTSECTION#InputField "ExecuteBatch 1"]
X=(1+#DropdownStrokeWidth#)
W=(#DropdownMenuWidth#-(#DropdownStrokeWidth#*2)-#DropdownNoIconPadding#+1)
Padding=#DropdownNoIconPadding#,0,0,0

[2]
InlineSetting2=
StringAlign=LeftCenter
FontSize=(10*#DroptopSize#)
FontFace=#UniversalFont#
FontWeight=
SolidColor=255,255,255
FontColor=0,0,0,185
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor "0,0,0,255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor "0,0,0,185"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!EnableMeasureGroup XY][!UpdateMeasureGroup XY][!SetVariableGroup AnimationOFF 0 "SettingsMenu"][!UpdateGroup SettingsMenu][!CommandMeasure #CURRENTSECTION#InputField "ExecuteBatch 1"]
X=(1+#DropdownStrokeWidth#)
W=(#DropdownMenuWidth#-(#DropdownStrokeWidth#*2)-#DropdownNoIconPadding#+1)
Padding=#DropdownNoIconPadding#,0,0,0
Y=1R

[3]
FontColor=#DropdownFontColor1#,128
MouseOverAction=[]
MouseLeaveAction=[]
DynamicVariables=1
Hidden=0

[4]
Hidden=1

[1InputField]
Measure=Plugin
Measure=Plugin
Plugin=InputText.dll
FontFace=#UniversalFont#
StringAlign=Left
FontSize=[InputTextFontSize]
AntiAlias=1
W=([1:W]-(24*#DroptopSize#))
H=(#DropdownItemHeight#*0.75)
X=(([1:X]+#DropdownNoIconPadding#)+(1*#DroptopSize#))
Y=([1:Y]+(#DropdownItemHeight#*0.25)-((0.5*#DroptopSize#)*#DroptopSize#))
FocusDismiss=0
Command1=[!SetVariable ExchangeCurrency1 "$UserInput$"][!CommandMeasure 2InputField "ExecuteBatch 1"][!UpdateMeasure CheckCurrency1Change]
DefaultValue="#ExchangeCurrency1#"
DynamicVariables=1

[2InputField]
Measure=Plugin
Plugin=InputText.dll
FontFace=#UniversalFont#
StringAlign=Left
FontSize=[InputTextFontSize]
AntiAlias=1
W=([2:W]-(24*#DroptopSize#))
H=(#DropdownItemHeight#*0.75)
X=(([1:X]+#DropdownNoIconPadding#)+(1*#DroptopSize#))
Y=([2:Y]+(#DropdownItemHeight#*0.25)-((0.5*#DroptopSize#)*#DroptopSize#))
FocusDismiss=0
Command1=[!SetVariable ExchangeCurrency2 "$UserInput$"][!UpdateMeasure CheckCurrency2Change][!ActivateConfig "Droptop\Other\BackgroundProcesses\Tasks" "ExchangeRates.ini"]
DefaultValue="#ExchangeCurrency2#"
DynamicVariables=1