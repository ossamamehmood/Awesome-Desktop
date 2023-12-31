[Variables]

; --------------------------
; Menu options

TopBarBlur=1
TopBarHideGradient=1
TopBarHideHomeShape=1
TopBarHLSkew=0

DropdownMenuBlur=1
DropdownArrowStyle=1

;---

IconStyle=1

NewDesktopStyle=#IconStyle#
ActionStyle=#IconStyle#
SearchStyle=#IconStyle#
TimeStyle=#IconStyle#
MailStyle=#IconStyle#
AlarmStyle=#IconStyle#
VolumeStyle=#IconStyle#
WeatherStyle=#IconStyle#
WifiStyle=#IconStyle#
BatteryStyle=#IconStyle#
DownloadsStyle=#IconStyle#
RecentStyle=#IconStyle#
NotesStyle=#IconStyle#
CopyStyle=#IconStyle#
ExchangeStyle=#IconStyle#
LanguageStyle=#IconStyle#
AppDrawerStyle=#IconStyle#
AssistantStyle=#IconStyle#

DropdownSliderStyle=2

;-------------------------
; Colors

SetColorByWallpaperOFF=0

TopBarBGColor1=21,21,21
TopBarBGColor2=21,21,21
TopBarBGColor3=21,21,21
TopBarFontColor1=255,255,255
TopBarFontColor2=255,255,255
; TopBarHLColor1=133,133,133
TopBarHLColor1=255,255,255
TopBarAssistantIconTint1=255,255,255
TopBarAssistantIconTint2=255,255,255
TopBarHomeIconColor=255,255,255
TopBarIconGreyscale=0
TopBarBorderTopColor=25,25,25,(92*(#TopBarOpacity1#/255))
TopBarBorderBottomColor=0,0,0,(43*(#TopBarOpacity1#/255))

DropdownBGColor1=21,21,21
DropdownFontColor1=255,255,255
DropdownFontColor2=255,255,255
; DropdownItemHL=133,133,133
DropdownItemHL=255,255,255
DropdownIconTint=255,255,255
DropdownIconGreyscale=0
DropdownSliderColor=#DropdownItemHL#

BatteryChargingColor=47,207,91
BatteryDyingColor=233,86,70

;-------------------------
; Opacities

TopBarOpacity1=195
TopBarGradientOpacity1=76.5
TopBarHLOpacity1=55
TopBarHLOpacity2=85
TopBarHLOpacity2Offset=0
TopBarTitleOpacity=255

DropdownMenuOpacity1=195
DropdownHLOpacity1=55
DropdownHLOpacity2=85
DropdownHLOpacity2Offset=0
DropdownItemOpacity=255

HighlightShapeOpacity=200
HighlightShapeOpacityDivisor1A=6
HighlightShapeOpacityDivisor1B=6
HighlightShapeOpacityDivisor2A=6
HighlightShapeOpacityDivisor2B=8
HighlightFontOpacity1=255

BlurTypeNum=1
TopBarBlurType=[#BlurType[#BlurTypeNum]]

;---

TopBarShadow=0
DropdownMenuShadow=0

TopBarFontShadow=1
TopBarFontShadowBlur=2.5

DropdownFontShadow=0
DropdownFontShadowBlur=2.5

;-------------------------
; Font options

FontYposOffset=0
FontSizeOffset=0
IconSizeOffset=0
TitleSpaOffset=0

FontName0=Segoe UI

FontName1=#DefaultFont#
TopBarFontName=[#FontName[#AltFont[#LanguageNum]]]

TopBarTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*TopBarFontShadowBlur*] | 0,0,0,185
DropdownTextShadow100=Shadow | 0 | (1*#DroptopSize#) | [#*DropdownFontShadowBlur*] | 0,0,0,100

;---

FontWeight=400
ApplicationFontWeight=600

TopBarTitleCase=None
DegreeSymbol=°
PercentSymbol=%
MusicSymbol=#NotificationPlaying#
MailSymbol=#NotificationMail#

TopBarCharacterSpacing=0 | 0
DropdownCharacterSpacing=0 | 0

TopBarAntiAlias=1
DropdownAntiAlias=#TopBarAntiAlias#

;-------------------------
; Shapes & backgrounds

TopBarCornerMinMax0=0
TopBarCornerMinMax1=5
DropdownCornerMinMax0=0
DropdownCornerMinMax1=8
HighlightCornerMinMax0=0
HighlightCornerMinMax1=5
TopBarRoundCorners=0
DropdownRoundCorners=1
TopBarCorner=([#TopBarCornerMinMax[#TopBarRoundCorners]]*#DroptopSize#)
TopGradientCorner=#TopBarCorner#
DropdownBGCorner=[#DropdownCornerMinMax[#DropdownRoundCorners]]
TopBarHighlightCorner=(#TopBarCornerMinMax1#*#DroptopSize#)
DropdownHighlightCorner=(#DropdownBGCorner#*0.83)

CurrentDayStrokeWidth=(2*#DroptopSize#)

TopBarStrokeWidth=(0*#DroptopSize#)
DropdownStrokeWidth=1

TopBarStrokeColor=#DropdownFontColor1#
DropdownStrokeColor=0,0,0,#DropdownStrokeOpacity#

TopBarStrokeOpacity=0
DropdownStrokeOpacity=105

HLSelectedShapeNum=1

TopBarHotCornerStrokeWidth=#TopBarStrokeWidth#
BLANK=195

;-------------------------
