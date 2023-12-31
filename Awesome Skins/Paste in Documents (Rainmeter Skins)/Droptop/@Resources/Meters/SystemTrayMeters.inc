[Rainmeter]
MouseActionCursor=Arrow
OnFocusAction=[!SetVariable Focused 1 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure CompareFocused "Droptop\Other\BackgroundProcesses"]
OnUnfocusAction=[!SetVariable Focused 0 "Droptop\Other\BackgroundProcesses"][!UpdateMeasure MeasureIsFullScreen "Droptop\Other\BackgroundProcesses"]
RightMouseDownAction=[]
SkinWidth=(#DropdownMenuWidth#+#SysAppMenuXOffset#+#SysAppMenuWOffset#+2)
; Blur=#DropdownMenuBlur#

DefaultKeepOnScreen=1

[Variables]
MenuBlur=#DropdownMenuBlur#

;-----------------------------------
Padding0=(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),#DropdownItemPaddingY#,#DropdownItemPadding2#,(#DropdownItemPaddingY#*-1)
Padding1=#DropdownItemPadding2#,#DropdownItemPaddingY#,(#HideIcons#=1?#DropdownNoIconPadding#:#DropdownItemPadding1#),(#DropdownItemPaddingY#*-1)
;---
Padding0B=#DropdownItemPadding1#,#DropdownItemPaddingY#,#DropdownItemPadding2#,(#DropdownItemPaddingY#*-1)
Padding1B=(#DropdownItemPadding1#*2),#DropdownItemPaddingY#,#DropdownNoIconPadding#,(#DropdownItemPaddingY#*-1)
;-----------------------------------

[BlurBehind]
Measure=Plugin
Plugin=FrostedGlass
BlurEnabled=#DropdownMenuBlur#
Type=[#BlurType[#BlurTypeNum]]
Border=[#Shadows[#DropdownMenuShadow]]
Corner=[#BlurCorner[#DropdownRoundCorners]]

[MeasureActionTimer1]
Measure=Plugin
Plugin=ActionTimer
Group=Animation
ActionList1=Wait #FolderMouseOverTime#|StopBlock1|FolderMouseOver|StopBlock0
FolderMouseOver=
StopBlock1=[!SetVariable StopBlock 1][!UpdateMeterGroup Items]
StopBlock0=[!SetVariable StopBlock 0][!UpdateMeterGroup Items]
DynamicVariables=1
IgnoreWarnings=1
Disabled=1

;----------------------------------------------------
; Styles
;----------------------------------------------------

[InfoStyle]
StringAlign=#TextDirection#Center
FontColor=#DropdownFontColor1#,#DropdownItemOpacity#
FontFace=[#FontName[#AltFont[#LanguageNum]]]
FontSize=#DropdownItemFontSize#
InlineSetting=CharacterSpacing | #DropdownCharacterSpacing#
InlineSetting2=[#DropdownTextShadow[#DropdownFontShadow][#ChamLum1]]
StringEffect=#DropdownStringEffect#
FontEffectColor=#DropdownFontEffectColor#
X=(1+(#DropdownMenuWidth#*#RTLText#)+#SysAppMenuXOffset#)
Y=R
W=(#DropdownMenuWidth#+#SysAppMenuWOffset#-#DropdownItemPadding2#-#DropdownItemPadding1#+(#DropdownItemPadding1#*#HideIcons#))
H=#DropdownItemHeight#
Text="%1"
FontWeight=#FontWeight#
Padding=[#Padding[#RTLText]]
AntiAlias=#DropdownAntiAlias#
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor2*#,(#*HighlightFontOpacity1*#-(#*HighlightFontOpacity1*#*#HideIcons#))"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#Arrow][!Redraw]
MouseLeaveAction=[!HideMeter HighlightBackground][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor1*#,(#*DropdownItemOpacity*#-(#*DropdownItemOpacity*#*#HideIcons#))"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#Arrow][!Redraw]
Hidden=(#NumberOfItems# >= #CURRENTSECTION# ? 0 : 1)
DynamicVariables=1
ClipString=1
Group=Items

[FolderStyle]
MouseOverAction=[!SetVariable CurrentSubFolder #CURRENTSECTION#][!SetOption MeasureActionTimer#AnimationOFF# FolderMouseOver """[!WriteKeyValue Variables FolderNumber #CURRENTSECTION# "#CURRENTPATH#Folder\Config\FolderConfig.inc"][#OpenFolder][PlayStop][!ShowMeter HighlightSelected][!SetVariable HighlightSelectedY [#CURRENTSECTION#:Y]][!Hide "#CURRENTCONFIG#\Folder"][!DeactivateConfig "#CURRENTCONFIG#\Folder"][!ActivateConfig "#CURRENTCONFIG#\Folder" "Folder#CURRENTSECTION#.ini"][!Move ([#CURRENTCONFIGX]-#DropdownSubMenuWidth#-#DropdownSubMenuXOffset#+#SysAppMenuXOffset#+1) ([#CURRENTCONFIGY]+[#CURRENTSECTION#:Y]-#DropdownTopBottomSpacing#) "#CURRENTCONFIG#\Folder"][!#Show# "#CURRENTCONFIG#\Folder"][!UpdateMeter HighlightSelected][!Redraw]"""][!UpdateMeasure MeasureActionTimer#AnimationOFF#][!CommandMeasure MeasureActionTimer#AnimationOFF# "Execute 1"]   [!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION# FontEffectColor "#*DropdownFontColor2*#"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor2*#,#*HighlightFontOpacity1*#"][!ShowMeterGroup Highlight][!UpdateMeterGroup Highlight][!UpdateMeter #CURRENTSECTION#][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#Arrow][!Redraw]
MouseLeaveAction=[!CommandMeasure MeasureActionTimer#AnimationOFF# "[#Stop[#StopBlock]] 1"][!HideMeter HighlightBackground][!SetOption #CURRENTSECTION# FontColor "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Icon ImageTint "#*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Arrow StrokeColor "Stroke Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!SetOption #CURRENTSECTION#Arrow FillColor "Fill Color #*DropdownFontColor1*#,#*DropdownItemOpacity*#"][!UpdateMeter #CURRENTSECTION#][!UpdateMeter #CURRENTSECTION#Icon][!UpdateMeter #CURRENTSECTION#Arrow][!Redraw]
UpdateDivider=1

@IncludeArrowStyle=#SKINSPATH#Droptop\@Resources\Meters\ArrowStyle\ArrowStyle#DropdownArrowStyle#.ini

[IconStyle]
X=(#DropdownIconXoffset#+((#DropdownMenuWidth#-#DropdownIconXoffset#-#IconW#-#DropdownHLOffsetX#-(#DropdownIconPadding#*2))*#RTLText#)+#SysAppMenuXOffset#)
Y=R
W=#IconW#
H=#IconH#
ImageTint=#DropdownFontColor1#,(#DropdownItemOpacity#-(#DropdownItemOpacity#*#HideIcons#))
Greyscale=#DropdownIconGreyscale#
Padding=#DropdownIconPadding#,#DropdownIconPadding#,#DropdownIconPadding#,(#DropdownIconPadding#+(#DropdownIconPadding#%1))
DynamicVariables=1
; Group=Items

[BackgroundStyle]
LeftMouseUpAction=[]

;----------------------------------------------------
; Background Meters
;----------------------------------------------------

[Background]
Meter=Shape
MeterStyle=BackgroundStyle
Shape=Rectangle #DropdownMenuCutout#,(#DropdownMenuShapeOffsetH#+#DropdownMenuCutout#),(#DropdownMenuWidth#+#SysAppMenuWOffset#+2-(#DropdownMenuCutout#*2)),(#DropdownItemHeight#*#NumberOfItems#+((#DropdownIconYoffset#+#DropdownItemYOffset#)*2)+(((#DividerSpace#*2)+#DividerHeight#)*#NumberOfDividers#)-#DropdownMenuCutout#),#DropdownBGCorner# | Fill Color #DropdownBGColor1#,(#DropdownMenuOpacity1#<1?1:#DropdownMenuOpacity1#) | StrokeWidth #DropdownStrokeWidth# | Stroke Color #DropdownStrokeColor#
Shape2=#FlatTopShape#
Shape3=Combine Shape | Union Shape2
X=#SysAppMenuXOffset#
DynamicVariables=1

;----------------------------------------------------
; Item Highlight

[HighlightBackground]
Meter=Shape
Shape=Rectangle (#DropdownMenuCutout#+#DropdownHLOffsetX#),[#CurrentSubFolder#:Y],(#DropdownMenuWidth#+#SysAppMenuWOffset#-(#DropdownMenuCutout#*2)+((#DropdownMenuWidth#-(#DropdownMenuCutout#*2))%1)-(#DropdownHLOffsetX#*2)),#DropdownItemHeight#,#DropdownHighlightCorner# | Fill Color #DropdownItemHL#,(#HighlightShapeOpacity#/#HighlightShapeOpacityDivisor1B#) | StrokeWidth 0
X=(1+#SysAppMenuXOffset#)
Group=Highlight | HL
DynamicVariables=1
Hidden=1

[HighlightSelected]
Meter=Shape
Shape=Rectangle [#HLSelectedShapeB[#HLSelectedShapeNum]]
ShapeOption=[#HLSelectedOptionB[#HLSelectedShapeNum]]
X=(1+#SysAppMenuXOffset#)
Y=#HighlightSelectedY#
Group=HighlightSelected
DynamicVariables=1
Hidden=1

[1Icon]
Meter=Image

[2Icon]
Meter=Image

[3Icon]
Meter=Image

[4Icon]
Meter=Image

[5Icon]
Meter=Image

[6Icon]
Meter=Image

[7Icon]
Meter=Image

[8Icon]
Meter=Image

[9Icon]
Meter=Image

[10Icon]
Meter=Image

; ;----------------------

[1Arrow]
Meter=Shape
Y=[1Icon:Y]

[2Arrow]
Meter=Shape

[3Arrow]
Meter=Shape

[4Arrow]
Meter=Shape

[5Arrow]
Meter=Shape

[6Arrow]
Meter=Shape

[7Arrow]
Meter=Shape

[8Arrow]
Meter=Shape

[9Arrow]
Meter=Shape

[10Arrow]
Meter=Shape
