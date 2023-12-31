[Rainmeter]

; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;

[LoadActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 50 | ExportVars | Start0 | Wait 750 | Start1 | Wait 1000 | ClickOn | Start2

[Variables]
Sec.L=(500*#Scale#)
Sec.boxW=(100)
Sec.SaveLocation="#@#GlobalVar\UserSettings.inc"

WeatherLocation=e.g. "Hong Kong", "Toronto, Ontario"

WeatherLocation.Password=0

GmailUsername=username@gmail.com
GmailPassword=password

GmailUsername.Password=0
GmailPassword.Password=1

MetricSymbol0=[\xe906]
MetricSymbol1=[\xe901]

MetricColor0=255,255,255,185
MetricColor1=56,250,138

MediaPlayer1String=1
MediaPlayer2String=2
MediaPlayer3String=3
MediaPlayer4String=4
MediaPlayer5String=5
MediaPlayer6String=6
MediaPlayer7String=7
MediaPlayer8String=8
MediaPlayer9String=9
MediaPlayer10String=10
MediaPlayer11String=11
MediaPlayer12String=12

MediaPlayerNum1=1
MediaPlayerType1=0

MediaPlayerNum2=6
MediaPlayerType2=1

MediaPlayerNum3=6
MediaPlayerType3=1

MediaPlayerNum4=2
MediaPlayerType4=0

MediaPlayerNum5=6
MediaPlayerType5=1

MediaPlayerNum6=6
MediaPlayerType6=1

MediaPlayerNum7=6
MediaPlayerType7=1

MediaPlayerNum8=6
MediaPlayerType8=1

MediaPlayerNum9=6
MediaPlayerType9=1

MediaPlayerNum10=3
MediaPlayerType10=0

MediaPlayerNum11=4
MediaPlayerType11=0

MediaPlayerNum12=7
MediaPlayerType12=0

ExecuteAnimation0=[!CommandMeasure LoadActions "Execute 2"]
ExecuteAnimation1=[!WriteKeyvalue Variables Page (#Page#+1)][!Refresh]


[LoadActions]
Measure=Plugin
Plugin=ActionTimer
ActionList1=Wait 50 | ExportVars | Start0

[PSRM]
Measure=Plugin
Plugin=PowershellRM
ScriptFile=#@#Scripts\Powershell\FetchVars.ps1
FetchStringCount=9
Fetch1=StartP#Page#Title1|000
Fetch2=StartP#Page#Notes1|Text.1
Fetch3=StartP#Page#Title2|Subtitle.1
Fetch4=StartP#Page#Size1|Size1
Fetch5=StartP#Page#Size2|Size2
Fetch6=StartP#Page#Size3|Size3
Fetch9=SayContinue|ButtonText

[Tween:M]
Measure=Script
ScriptFile=#@#Scripts\Lua\Tween\Main.lua
Tween0=Single | Variable | TweenNode1 | 0 | 1 | 500
Tween1=Single | Variable | TweenNode2 | 0 | 1 | 1000
Tween2=Single | Variable | TweenNode3 | 0 | 1 | 1000
Tween3=Single | Variable | TweenNode4 | 0 | 1 | 1000
Tween4=Single | Variable | TweenNode5 | 0 | 1 | 1000
Tween5=Single | Variable | TweenNode6 | 0 | 1 | 500
Optional1=Easing OutExpo
Optional2=Easing OutExpo | Group All
Optional3=Easing OutExpo | Group All
Optional4=Easing OutExpo | Group All
Optional5=Easing InOutSine | Group All
TweenGroup=Tweenable
UpdateDivider=1

[Box:S]
FillColor=StrokeWidth (2*#Scale#) | Fill Color 43,43,43 | Stroke Color 55,55,55
X=(#Sec.L#+100*#Scale#)
Group=InputBox
Container=Container
DynamicVariables=1

[mBox:S]
X=(#Sec.P#/2)R
Y=r
Container=Container
Shape=Rectangle 0,0,(#Sec.boxW#),(#Sec.boxW#),(5) | StrokeWidth 0 | Scale #Scale#,#Scale# | Fill Color 43,43,43

[mImage:S]
X=r
Y=r
W=((#Sec.boxW#-20)*#Scale#)
H=((#Sec.boxW#-20)*#Scale#)
Padding=(10*#Scale#),(10*#Scale#),(10*#Scale#),(10*#Scale#)
Container=Container
PreserveAspectRatio=1
ImageName=#@#Images\mPlayerIcons\#CURRENTSECTION#.png

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[BackArrow]
Meter=String
MeterStyle=BackArrow:S

[Shape]
Meter=Shape
X=((#SCREENAREAWIDTH#/2-#Sec.W#/2))
Y=((#SCREENAREAHEIGHT#/2-#Sec.H#/2))
Shape=Rectangle 0,0,(+#Sec.W#),(28+(#Sec.H#-28)),(10*#Scale#) | StrokeWidth (2*#Scale#) | Stroke Color 34,34,34 | Fill Color 31,31,31

[Container]
Meter=Shape
X=((#SCREENAREAWIDTH#/2-#Sec.W#/2))
Y=((#SCREENAREAHEIGHT#/2-#Sec.H#/2))
Shape=Rectangle 0,0,(+#Sec.W#),(28+(#Sec.H#-28)),(10*#Scale#) | StrokeWidth (2*#Scale#) | Stroke Color 34,34,34 | Fill Color 31,31,31,(#TWeenNode1#*255)
Group=Tweenable
DynamicVariables=1

[BackgroundImage]
Meter=String
StringAlign=RightCenter
MeterStyle=Image:BG
Text=[\xe903]

[Title]
Meter=String
Text=droptop four
X=(#SCREENAREAWIDTH#/2)
Y=(#SCREENAREAHEIGHT#/2-#SEc.H#/2+#Sec.p#)
FontSize=(22*#Scale#)
StringAlign=Center
Container=
InlineSetting=CharacterSpacing | 1 | 0
FontColor=43B553
MeterStyle=String:S

; --------------------------------- Section 1 -------------------------------- ;

[000]
Meter=String
X=(#Sec.P#)
Y=(107*#Scale#)
Text=Choose a home button
FontSize=(25*#Scale#)
DynamicVariables=1
Group=Tweenable
MeterStyle=String:S | Header:S

[Text.1]
Meter=String
FontSize=(17*#Scale#)
X=r
Y=(80*#Scale#-#Sec.P#/2)r
W=(450*#Scale#)
H=(65*#Scale#)
Text=Upgrade to the supporter version#CRLF#to unlock 300 home button icons
MeterStyle=String:S | Text:S

[HomeIconStyle]
ImageTint=255,255,255,155
X=R
Y=r
W=(78*#Scale#)
H=(52*#Scale#)
LeftMouseDownAction=[!WriteKeyValue Variables HomeRow #CURRENTSECTION# "#@#GlobalVar\UserSettings.inc"][!SetVariable HomeRow #CURRENTSECTION#][!SetOptionGroup HomeIcons ImageTint "255,255,255,155"][!SetOption #CURRENTSECTION# ImageTint "56,250,138"][!EnableMouseActionGroup "MouseOverAction|MouseLeaveAction" HomeIcons][!DisableMouseAction #CURRENTSECTION# "MouseOverAction|MouseLeaveAction"][!UpdateMeasure *][!UpdateMeter *][!Redraw]
MouseOverAction=[!SetOption #CURRENTSECTION# ImageTint "255,255,255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# ImageTint "255,255,255,155"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Group=Content | Section3 | HomeIcons
Container=Container

[0]
Meter=Image
MeterStyle=HomeIconStyle
ImageName=#@#TopImages\Home\32\Column0\Home#CURRENTSECTION#.png
X=(#Sec.P#-(20*#Scale#))
Y=(90*#Scale#-#Sec.P#/2)r

[1]
Meter=Image
MeterStyle=HomeIconStyle
ImageName=#@#TopImages\Home\32\Column0\Home#CURRENTSECTION#.png

[2]
Meter=Image
MeterStyle=HomeIconStyle
ImageName=#@#TopImages\Home\32\Column0\Home#CURRENTSECTION#.png

[3]
Meter=Image
MeterStyle=HomeIconStyle
ImageName=#@#TopImages\Home\32\Column0\Home#CURRENTSECTION#.png

[4]
Meter=Image
MeterStyle=HomeIconStyle
ImageName=#@#TopImages\Home\32\Column0\Home#CURRENTSECTION#.png

[5]
Meter=Image
MeterStyle=HomeIconStyle
ImageName=#@#TopImages\Home\32\Column0\Home#CURRENTSECTION#.png

[6]
Meter=Image
MeterStyle=HomeIconStyle
ImageName=#@#TopImages\Home\32\Column0\Home#CURRENTSECTION#.png
X=(#Sec.P#-(20*#Scale#))
Y=(20*#Scale#)R

[MoreIcons]
Meter=Image
ImageName=#@#Images\Setup\HomeIcons.png
ImageTint=255,255,255,45
; SolidColor=255,55,55
X=(#Sec.P#-(4*#Scale#))
Y=(10*#Scale#)r
W=(428*#Scale#)
PreserveAspectRatio=1
Group=Content | Section3
Container=Container

; --------------------------------- Section 2 -------------------------------- ;

[Subtitle.1]
Meter=String
X=(#Sec.L#+100*#Scale#)
Y=(120*#Scale#)
W=(330*#Scale#)
Text=Choose a size for the dropdown bar
ClipString=2
DynamicVariables=1
MeterStyle=String:S | Header2:S

[Size.StringStyle]
X=(#Sec.L#+100*#Scale#)
Y=55r
W=425
FontColor=255,255,255,185
FontFace=Product Sans
MouseOverAction=[!SetOption #CURRENTSECTION# FontColor "255,255,255"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FontColor "255,255,255,185"][!UpdateMeter #CURRENTSECTION#][!Redraw]
Container=Container
Group=SizeOptions

[Size1]
Meter=String
MeterStyle=String:S | Header2:S | Size.StringStyle
X=r
Y=(13*#Scale#)R
H=60
FontSize=20
Text=Small
LeftMouseDownAction=[!WriteKeyValue Variables DroptopSize 1 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconSize Small "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables TopIconSize Medium "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables TopIconWH 32 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconW 16 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconH 16 "#@#GlobalVar\UserSettings.inc"][!SetOptionGroup SizeOptions FontColor "255,255,255,185"][!SetOption #CURRENTSECTION# FontColor "56,250,138"][!SetOptionGroup SizeOptions ImageTint "255,255,255"][!SetOptionGroup Size1 ImageTint "56,250,138"][!SetOptionGroup SizeOptions Stroke "Stroke Color 255,255,255,15 | StrokeWidth 2"][!SetOption #CURRENTSECTION#Shape Stroke "Stroke Color 56,250,138 | StrokeWidth 2"][!EnableMouseActionGroup "MouseOverAction|MouseLeaveAction" SizeOptions][!DisableMouseAction #CURRENTSECTION# "MouseOverAction|MouseLeaveAction"][!UpdateMeterGroup SizeOptions][!Redraw]

[Size1.Image]
Meter=Image
ImageName=#@#Images\Setup\Bar1.png
X=r
Y=38r
PreserveAspectRatio=1
Group=SizeOptions | Size1
Container=Container

[Size1.Icon]
Meter=Image
ImageName=#@#TopImages\Home\32\Column0\Home#HomeRow#.png
X=8r
Y=1r
H=26
DynamicVariables=1
Container=Container
Group=SizeOptions | Size1

;---------------------

[Size2]
Meter=String
MeterStyle=String:S | Header2:S | Size.StringStyle
FontSize=30
H=80
Text=Medium
LeftMouseDownAction=[!WriteKeyValue Variables DroptopSize 1.6 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconSize Medium "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables TopIconSize Medium "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables TopIconWH 32 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconW 32 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconH 32 "#@#GlobalVar\UserSettings.inc"][!SetOptionGroup SizeOptions FontColor "255,255,255,185"][!SetOption #CURRENTSECTION# FontColor "56,250,138"][!SetOptionGroup SizeOptions ImageTint "255,255,255"][!SetOptionGroup Size2 ImageTint "56,250,138"][!SetOptionGroup SizeOptions Stroke "Stroke Color 255,255,255,15 | StrokeWidth 2"][!SetOption #CURRENTSECTION#Shape Stroke "Stroke Color 56,250,138 | StrokeWidth 2"][!EnableMouseActionGroup "MouseOverAction|MouseLeaveAction" SizeOptions][!DisableMouseAction #CURRENTSECTION# "MouseOverAction|MouseLeaveAction"][!UpdateMeterGroup SizeOptions][!Redraw]

[Size2.Image]
Meter=Image
ImageName=#@#Images\Setup\Bar2.png
X=r
Y=50r
Group=SizeOptions | Size2
Container=Container

[Size2.Icon]
Meter=Image
ImageName=#@#TopImages\Home\32\Column0\Home#HomeRow#.png
X=12r
Y=1r
H=41
DynamicVariables=1
Container=Container
Group=SizeOptions | Size2

;---------------------

[Size3]
Meter=String
MeterStyle=String:S | Header2:S | Size.StringStyle
FontSize=40
Text=Large
LeftMouseDownAction=[!WriteKeyValue Variables DroptopSize 2 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconSize Medium "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables TopIconSize Medium "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables TopIconWH 32 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconW 32 "#@#GlobalVar\UserSettings.inc"][!WriteKeyValue Variables IconH 32 "#@#GlobalVar\UserSettings.inc"][!SetOptionGroup SizeOptions FontColor "255,255,255,185"][!SetOption #CURRENTSECTION# FontColor "56,250,138"][!SetOptionGroup SizeOptions ImageTint "255,255,255"][!SetOptionGroup Size3 ImageTint "56,250,138"][!SetOptionGroup SizeOptions Stroke "Stroke Color 255,255,255,15 | StrokeWidth 2"][!SetOption #CURRENTSECTION#Shape Stroke "Stroke Color 56,250,138 | StrokeWidth 2"][!EnableMouseActionGroup "MouseOverAction|MouseLeaveAction" SizeOptions][!DisableMouseAction #CURRENTSECTION# "MouseOverAction|MouseLeaveAction"][!UpdateMeterGroup SizeOptions][!Redraw]
H=120

[Size3.Image]
Meter=Image
ImageName=#@#Images\Setup\Bar3.png
X=r
Y=65r
Group=SizeOptions | Size3
Container=Container

[Size3.Icon]
Meter=Image
ImageName=#@#TopImages\Home\32\Column0\Home#HomeRow#.png
X=16r
Y=2r
H=52
DynamicVariables=1
Container=Container
Group=SizeOptions | Size3

[SizeLimitShape]
Meter=Shape
Shape=Rectangle (+#Sec.W#-(120*#Scale#)),0,(128*#Scale#),(28+(#Sec.H#-28)) | StrokeWidth 0 | Fill LinearGradient FillColor
FillColor=0 | 31,31,31,255 ; 0.4 | 31,31,31,0 ; 1.0
Container=Container

; ---------------------------------- Button ---------------------------------- ;

[Button]
Meter=Shape
X=(#Sec.W#-(180*#Scale#+#Sec.P#)*#TweenNode3#)
Y=(#SEc.H#-#Sec.P#-40*#Scale#)
Shape=Rectangle 0,0,(180*#Scale#),(40*#Scale#),(20*#Scale#) | StrokeWidth 0 | Extend FillColor
FillColor=Fill Color 39,174,96,(255*#TweenNode3#)
MouseOverAction=[!SetOption #CURRENTSECTION# FillColor "Fill Color 56,250,138"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# FillColor "Fill Color 39,174,96"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[#ExecuteAnimation[#NoAnimationNum]]
Group=Button | Tweenable
DynamicVariables=1
Container=Container

[ButtonText]
Meter=String
X=(180/2*#Scale#)r
Y=(21*#Scale#)r
FontSize=(15*#Scale#)
StringAlign=CenterCenter
Text=Continue
FontColor=255,255,255,(255*#TweenNode3#)
InlineSetting=Shadow | 0 | 1 | 2 | 0,0,0,175
Group=Button | Tweenable
DynamicVariables=1
MeterStyle=String:S