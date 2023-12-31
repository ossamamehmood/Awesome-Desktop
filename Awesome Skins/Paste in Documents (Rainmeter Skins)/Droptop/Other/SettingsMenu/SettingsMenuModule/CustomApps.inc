[Rainmeter]

[Variables]
16=1
32=2

MeasureAppName1=1
MeasureAppName2=2
MeasureAppName3=3
MeasureAppName4=4
MeasureAppName5=5

;----------------------------------------------------

[MeasureAppName1]
Measure=String
String=[#CustomAppID[##CURRENTSECTION#]]
Substitute="_":" ","-":" - "
DynamicVariables=1

[MeasureAppName2]
Measure=String
String=[#CustomAppID[##CURRENTSECTION#]]
Substitute="_":" ","-":" - "
DynamicVariables=1

[MeasureAppName3]
Measure=String
String=[#CustomAppID[##CURRENTSECTION#]]
Substitute="_":" ","-":" - "
DynamicVariables=1

[MeasureAppName4]
Measure=String
String=[#CustomAppID[##CURRENTSECTION#]]
Substitute="_":" ","-":" - "
DynamicVariables=1

[MeasureAppName5]
Measure=String
String=[#CustomAppID[##CURRENTSECTION#]]
Substitute="_":" ","-":" - "
DynamicVariables=1

;----------------------------------------------------

[CustomAppIconStyle]
ImageCrop=-16,-16,32,32,5
ImageName=#SKINSPATH#Droptop Community Apps\Apps\[#CustomAppID[##CURRENTSECTION#]]\Button\Medium\Button.png
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+1+(#DropdownItemHeight#*([##CURRENTSECTION#]-1)))
W=#IconW#
H=#IconH#

[1Icon]
MeterStyle=IconStyle | CustomAppIconStyle
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+1)

[2Icon]
MeterStyle=IconStyle | CustomAppIconStyle

[3Icon]
MeterStyle=IconStyle | CustomAppIconStyle

[4Icon]
MeterStyle=IconStyle | CustomAppIconStyle

[5Icon]
MeterStyle=IconStyle | CustomAppIconStyle

[Divider1]
Y=(#DropdownIconYoffset#+#DropdownItemYOffset#+(#DividerSpace#*1)+(#DropdownItemHeight#*5)-(#DividerHeight#/2))

[6]
Y=(#DividerSpace#*2)R

[6Icon]
Y=(#DividerSpace#*2)R
