[Variables]

AltFont1=0
AltFont2=0
AltFont3=0
AltFont4=0
AltFont5=0
AltFont6=0
AltFont7=0
AltFont8=0
AltFont9=0
AltFont10=0
AltFont11=0
AltFont12=0
AltFont13=0
AltFont14=0
AltFont15=0
AltFont16=0
AltFont17=0
AltFont18=0
AltFont19=0
AltFont20=0

;-------------------------

TopBarFontSize=(((11*#DroptopSize#)-((11*#DroptopSize#)%1))+(#FontSizeOffset#*#DroptopSize#))
TopBarContentXOffset=((8*#DroptopSize#)-((8*#DroptopSize#)%1))
TopBarTitlePadding="((8*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),((0*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1)),((8*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),0"
TopBarTextYOffset=((0*#DroptopSize#)+(#FontYposOffset#*#DroptopSize#))
TopBarSysIconYOffset=(0*#DroptopSize#)
TopBarSysIconTextOffset=((29*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarSysBatteryIconOffset=(3*#DroptopSize#)
TopBarSysBatteryTextOffset=(8*#DroptopSize#)
TopBarSysTextYPadding=((0*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1))
TopBarSysTextWPadding=(6*#DroptopSize#)
TopBarSysAppWPadding=(0*#DroptopSize#)
TopBarBorderTopH=0
TopBarBorderBottomH=(1*#DroptopSize#)
TopBarHLOffsetY=(0*#DroptopSize#)
TopBarHLOffsetH=(0*#DroptopSize#)
TopBarSkew=(-20*#TopBarHLSkew#)
TopBarIconHOffset=((0*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarCutout=(0*#DroptopSize#)
TopBarGradientCutout=#TopBarCutout#

;-------------------------

DropdownMenuWidth=((275*#DroptopSize#)-((275*#DroptopSize#)%1))
DropdownItemHeight=((25*#DroptopSize#)-((25*#DroptopSize#)%1))
DropdownItemFontSize=(((11*#DroptopSize#)-((11*#DroptopSize#)%1))+(#FontSizeOffset#*#DroptopSize#))
DropdownMenuYOffset=(0*#DroptopSize#)
DropdownMenuShapeOffsetH=(0*#DroptopSize#)
DropdownIconPadding=((#DropdownItemHeight#-#IconH#)/2)
DropdownIconXoffset=(7*#DroptopSize#)
DropdownIconYoffset=((0*#DroptopSize#)-((0*#DroptopSize#)%1))
DropdownItemYOffset=((6*#DroptopSize#)-((6*#DroptopSize#)%1))
DropdownItemPadding1=(31*#DroptopSize#)
DropdownItemPadding2=(20*#DroptopSize#)
DropdownItemPaddingY=((0+#FontYposOffset#)*#DroptopSize#)
DropdownTopBottomSpacing=(#DropdownIconYoffset#+#DropdownItemYOffset#+1)
DropdownSubMenuWidth=(170*#DroptopSize#)
DropdownContextMenuYOffset=(0*#DroptopSize#)
DropdownNoIconPadding=(6*#DroptopSize#)
DropdownSysMenuOffset=(2*#DroptopSize#)
DropdownSysAppContentXOffset=(0*#DroptopSize#)
DropdownArrowHighlightW=((21*#DroptopSize#)-((21*#DroptopSize#)%1))
DropdownArrowXOffset=(-1*#DroptopSize#)+(#DropdownMenuCutout#%1)
DropdownArrowXOffsetTray=(-1*#DroptopSize#)
DropdownArrowXOffsetRTL=(0*#DroptopSize#)
DropdownScrollButtonYOffset=(1*#DroptopSize#)
DropdownMenuFlatTop=1
DropdownSubMenuXOffset=(6*#DroptopSize#)
DropdownMenuCutout=(0*#DroptopSize#)
DropdownHLOffsetX=((0*#DroptopSize#)-((0*#DroptopSize#)%1))
DropdownMenuLandingHeight=(17*#DroptopSize#)
DropdownBottomButtonOffset=((1*#DroptopSize#)-((1*#DroptopSize#)%1))

;-------------------------
; Colors

ChamLum1=0
ChamLum2=0
ChamLumA=0,0,0
ChamLumB=255,255,255

ChamBG1=51,30,212
ChamBG2=51,15,200
ChamBG3=49,11,159
ChamFG1=255,150,255
ChamFG2=255,255,255

TopBarSolidColor=0

DropdownStringEffect=None
DropdownFontEffectColor=0,0,0

LockSetColorByWallpaperOFF=0

LockReverseDarkLightTopBar=0
LockReverseDarkLightDropdownMenu=0

;---
; ColorMode/Charging/BatteryLow
BatteryFillColor000=[#*TopBarFontColor1*]
BatteryFillColor001=[#*TopBarFontColor1*]
BatteryFillColor010=[#*TopBarFontColor1*]
BatteryFillColor011=[#*TopBarFontColor1*]

BatteryFillColor100=[#*TopBarFontColor1*]
BatteryFillColor101=#BatteryDyingColor#
BatteryFillColor110=#BatteryChargingColor#
BatteryFillColor111=#BatteryDyingColor#

;---

BatteryFillColor000B=[#*TopBarFontColor2*]
BatteryFillColor001B=[#*TopBarFontColor2*]
BatteryFillColor010B=[#*TopBarFontColor2*]
BatteryFillColor011B=[#*TopBarFontColor2*]

BatteryFillColor100B=[#*TopBarFontColor2*]
BatteryFillColor101B=#BatteryDyingColor#
BatteryFillColor110B=#BatteryChargingColor#
BatteryFillColor111B=#BatteryDyingColor#

;-------------------------
; Opacities

BatteryFillOpacity=355

;-------------------------
; Shapes & backgrounds

DividerX=(#DropdownStrokeWidth#+1)
DividerSpace=(#DropdownIconYoffset#+#DropdownItemYOffset#)
DividerHeight=(1*#DroptopSize#)

DividerShape=Rectangle (#DividerX#+1),0,(#DropdownMenuWidth#-(#DividerX#*2)),#DividerHeight#,(0*#DroptopSize#) | Fill Color #DropdownFontColor1#,40 | StrokeWidth 0

HomeShape=Rectangle #TopBarContentXOffset#,(#TopBarHLOffsetH#+#TopBarHLOffsetY#),[Home:W],(#TopHeight#-(#TopBarCutout#*2)),#TopBarHighlightCorner# | StrokeWidth 0 | Stroke Color #TopBarBGColor1# | Skew #TopBarSkew#,0 | Extend HomeFillColor#TopBarHideHomeShape#

FlatTopShape=Rectangle #DropdownMenuCutout#,0,((#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2))*#DropdownMenuFlatTop#),((#DropdownBGCorner#+2)*#DropdownMenuFlatTop#),0 | Fill Color 255,55,55 | StrokeWidth 0

;-------------------------
; Chameleon settings

ChamTopBarBGColor1=[ChamLumA]
ChamTopBarBGColor2=[ChamLumA]
ChamTopBarBGColor3=[ChamLumA]
ChamDropdownBGColor1=[ChamLumA]
ChamFolderHL=65,109,217
ChamTopBarHL=65,109,217
ChamDropdownFontColor1=[ChamLumB]
ChamDropdownFontColor2=255,255,255
ChamTopBarFontColor1=[ChamLumB]
ChamTopBarFontColor2=255,255,255
ChamDropdownStrokeColor=0,0,0,#DropdownStrokeOpacity#
ChamTopBarStrokeColor=[ChamFG2]
ChamTopBarHomeIconColor=[ChamLumB]
ChamTopBarAssistantIconTint1=255,255,255
ChamTopBarAssistantIconTint2=255,255,255
ChamBatteryFillColor=[ChamLumB]
ChamLightOffset=255
ChamDarkOffset=0
ChamLumThreshold=0.5

;-------------------------

