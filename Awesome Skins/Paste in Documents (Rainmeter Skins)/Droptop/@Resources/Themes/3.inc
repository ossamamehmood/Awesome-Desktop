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

TopBarFontSize=((11*#DroptopSize#)+(#FontSizeOffset#*#DroptopSize#))
TopBarContentXOffset=((12*#DroptopSize#)-((12*#DroptopSize#)%1))
TopBarTitlePadding="((10*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),((0.5*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1)),((10*#DroptopSize#)+(#TitleSpaOffset#*#DroptopSize#)),0"
TopBarTextYOffset=((0*#DroptopSize#)+(#FontYposOffset#*#DroptopSize#))
TopBarSysIconYOffset=(0*#DroptopSize#)
TopBarSysIconTextOffset=((28*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarSysBatteryIconOffset=(2*#DroptopSize#)
TopBarSysBatteryTextOffset=(8*#DroptopSize#)
TopBarSysTextYPadding=((0.5*#DroptopSize#)*(([#AltFont[#LanguageNum]]-1)*-1))
TopBarSysTextWPadding=(6*#DroptopSize#)
TopBarSysAppWPadding=(2*#DroptopSize#)
TopBarBorderTopH=0
TopBarBorderBottomH=0
TopBarHLOffsetY=(0*#DroptopSize#)
TopBarHLOffsetH=(0*#DroptopSize#)
TopBarSkew=(-20*#TopBarHLSkew#)
TopBarIconHOffset=((-1*#DroptopSize#)+(#IconSizeOffset#*#DroptopSize#))
TopBarCutout=(0*#DroptopSize#)
TopBarGradientCutout=#TopBarCutout#

;-------------------------

DropdownMenuWidth=((275*#DroptopSize#)-((275*#DroptopSize#)%1))
DropdownItemHeight=((28*#DroptopSize#)-((28*#DroptopSize#)%1))
DropdownItemFontSize=((11*#DroptopSize#)+(#FontSizeOffset#*#DroptopSize#))
DropdownMenuYOffset=(0*#DroptopSize#)
DropdownMenuShapeOffsetH=(0*#DroptopSize#)
DropdownIconPadding=((#DropdownItemHeight#-#IconH#)/2)
DropdownIconXoffset=(10*#DroptopSize#)
DropdownIconYoffset=((2*#DroptopSize#)-((2*#DroptopSize#)%1))
DropdownItemYOffset=((5*#DroptopSize#)-((5*#DroptopSize#)%1))
DropdownItemPadding1=(36*#DroptopSize#)
DropdownItemPadding2=(30*#DroptopSize#)
DropdownItemPaddingY=((1+#FontYposOffset#)*#DroptopSize#)
DropdownTopBottomSpacing=(#DropdownIconYoffset#+#DropdownItemYOffset#+1)
DropdownSubMenuWidth=(185*#DroptopSize#)
DropdownContextMenuYOffset=(3*#DroptopSize#)
DropdownNoIconPadding=(12*#DroptopSize#)
DropdownSysMenuOffset=(2*#DroptopSize#)
DropdownSysAppContentXOffset=(0*#DroptopSize#)
DropdownArrowHighlightW=((23*#DroptopSize#)-((23*#DroptopSize#)%1))
DropdownArrowXOffset=(0*#DroptopSize#)+(#DropdownMenuCutout#%1)
DropdownArrowXOffsetTray=(-1*#DroptopSize#)
DropdownArrowXOffsetRTL=(0*#DroptopSize#)
DropdownScrollButtonYOffset=(0*#DroptopSize#)
DropdownMenuFlatTop=0
DropdownSubMenuXOffset=(6*#DroptopSize#)
DropdownMenuCutout=1
DropdownHLOffsetX=((5*#DroptopSize#)-((5*#DroptopSize#)%1))
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
ChamFG1=255,151,255
ChamFG2=255,255,255

TopBarSolidColor=1

LockSetColorByWallpaperOFF=0

LockReverseDarkLightTopBar=1
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

DividerX=((8*#DroptopSize#)+1)
DividerSpace=(#DropdownIconYoffset#+#DropdownItemYOffset#)
DividerHeight=(1*#DroptopSize#)

DividerShape=Rectangle (#DividerX#+1),0,(#DropdownMenuWidth#-(#DividerX#*2)),#DividerHeight#,(0*#DroptopSize#) | Fill Color #DropdownFontColor1#,40 | StrokeWidth 0

HomeShape=Rectangle #TopBarContentXOffset#,(#TopBarHLOffsetH#+#TopBarHLOffsetY#),[Home:W],(#TopHeight#-(#TopBarCutout#*2)),#TopBarHighlightCorner# | StrokeWidth 0 | Stroke Color #TopBarBGColor1# | Skew #TopBarSkew#,0 | Extend HomeFillColor#TopBarHideHomeShape#

FlatTopShape=Rectangle #DropdownMenuCutout#,0,((#DropdownMenuWidth#+2-(#DropdownMenuCutout#*2))*#DropdownMenuFlatTop#),((#DropdownBGCorner#+2)*#DropdownMenuFlatTop#),0 | Fill Color 255,55,55 | StrokeWidth 0

;-------------------------
; Chameleon settings

ChamTopBarBGColor1=[ChamBG1]
ChamTopBarBGColor2=[ChamBG1]
ChamTopBarBGColor3=[ChamBG3]
ChamDropdownBGColor1=[ChamLumA]
ChamFolderHL=0,125,255
ChamTopBarHL=[ChamLumB]
ChamDropdownFontColor1=[ChamLumB]
ChamDropdownFontColor2=255,255,255
ChamTopBarFontColor1=[ChamLumB]
ChamTopBarFontColor2=[ChamLumB]
ChamDropdownStrokeColor=0,0,0,#DropdownStrokeOpacity#
ChamTopBarStrokeColor=[ChamFG2]
ChamTopBarHomeIconColor=[ChamLumB]
ChamTopBarAssistantIconTint1=255,255,255
ChamTopBarAssistantIconTint2=255,255,255
ChamBatteryFillColor=[ChamLumB]
ChamLightOffset=255
ChamDarkOffset=0
ChamLumThreshold=0.6

;-------------------------
