[Variables]
UserAppSubstitutions="^(.*)\.(.*)$":"\1","^(.*)Rainmeter(.*)$":"#*LastFocusedApp*#","Droptop ":"","#*SavedAppTitleA*#":"#*SavedAppTitleB*#","(?is)Explorer":"#*AppMenu*#","":"#*LastFocusedApp*#","mspaint":"Paint","SearchUI":"#*LastFocusedApp*#","msedge":"Edge","ShellExperienceHost":"#*LastFocusedApp*#","ApplicationFrameHost":"[*MeasureActiveTitle*]","LogiOverlay":"#*LastFocusedApp*#","StartMenuExperienceHost":"#*LastFocusedApp*#","PMA":"#*LastFocusedApp*#","Droptop Rainmeter":"#*LastFocusedApp*#","LockApp":"#*LastFocusedApp*#","MusNotificationUx":"#*LastFocusedApp*#","ListWindows":"#*LastFocusedApp*#","ScreenClippingHost":"#*LastFocusedApp*#","steamwebhelper":"Steam","AutoHotkey":"#*LastFocusedApp*#","SearchApp":"#*LastFocusedApp*#","(?is)SearchUI":"#*LastFocusedApp*#","GoogleDriveSync":"#*LastFocusedApp*#","(?is)Nexus":"#*LastFocusedApp*#","(?is)PowerLauncher":"#*LastFocusedApp*#","WINWORD":"Word","EXCEL":"Excel","POWERPNT":"PowerPoint","OUTLOOK":"Outlook","ONENOTE":"OneNote","(?is)Notepad":"Notepad","soffice":"OpenOffice","(?is)iTunes":"[\x200B]iTunes","([_].*$)":"","^(.{18})(.{19,})":"\1"

; ----------------------------------------------------
; Information on how to add your own application name substititions can be found in the Droptop FAQ here:
; https://blacksquare88.wixsite.com/droptop4/faq
; ----------------------------------------------------

ThemeNum=4

DroptopSize=0.8

GmailUsername=Unassigned
GmailPassword=Password

FolderTitle1=#FolderName1#
FolderTitle2=#FolderName2#
FolderTitle3=#FolderName3#
FolderTitle4=#FolderName4#
FolderTitle5=#FolderName5#
FolderTitle6=Ossama Mehmood
FolderTitle7=#FolderName7#
FolderTitle8=#FolderName8#
FolderTitle9=#FolderName9#
FolderTitle10=#FolderName10#
FolderTitle11=#FolderName11#
FolderTitle12=#FolderName12#

; #SKINSPATH# = C:\Users\%USERNAME%\Documents\Rainmeter\Skins\
; %USERPROFILE% = C:\Users\%USERNAME%

FolderLoc1=#SKINSPATH#Droptop Folders\PinnedApps
FolderLoc2=#SKINSPATH#Droptop Folders\Games
FolderLoc3=#SKINSPATH#Droptop Folders\Bookmarks
FolderLoc4=#SKINSPATH#Droptop Folders\Control
FolderLoc5=%USERPROFILE%
FolderLoc6=#SKINSPATH#Droptop Folders\CustomFolder1
FolderLoc7=#SKINSPATH#Droptop Folders\CustomFolder2
FolderLoc8=#SKINSPATH#Droptop Folders\CustomFolder3
FolderLoc9=#SKINSPATH#Droptop Folders\CustomFolder4
FolderLoc10=#SKINSPATH#Droptop Folders\CustomFolder5
FolderLoc11=#SKINSPATH#Droptop Folders\CustomFolder6
FolderLoc12=#SKINSPATH#Droptop Folders\CustomFolder7

DownloadsLoc=%USERPROFILE%\Downloads
RecentLoc=%USERPROFILE%\AppData\Roaming\Microsoft\Windows\Recent

Note1=#NotesItem1#
Note2=#NotesItem2#
Note3=#NotesItem3#
Note4=#NotesItem4#
Note5=#NotesItem5#

; Options --------------------
LanguageNum=1
RTLText=0
;----------
WeatherLocation=Washington DC

WeatherUnits0=e
WeatherUnits1=m
UnitsMetric=1
;----------
AHKNum=0
AppSwitcherNum=1

HomeColumn=0
HomeRow=0

HomeColorNum=0
CustomHomeButton=0

ShowFadeNum=1
HideFadeNum=1

HideIcons=0
HideSubIcons=0

HideProgramsApp=0

MiddleClickNum=2
MiddleClickBehavior=Open

MenuBlur=1

AutohideDelayNum=2
AutohideSpeedNum=3

EnableDragDrop=1

DisableLeftHotCorner=0
DisableRightHotCorner=0

LeftHotCornerActionNum=2
RightHotCornerActionNum=1

;----------
HideLanding=0
;----------
HideIPAddress=0
;----------
ShowBatteryText=1
BatteryColorMode=0
BacklightSmoothNum=0
;----------
SearchModeNum=0
;----------
DPIOverride=1
DPIRescaleOFF=0
;----------
AutoMuteTime=300
AutoMuteON=0

AlwaysShowSongTitleOFF=0

HideAlbumCircle=0
HideExtraButtonsVolume=1
;----------
MailNum=0
HideMailCount=1
HideGmailPreviews=0
;----------
AlarmNum=1
AlarmHour=12
AlarmMinute=30
AlarmOFF=1

AlarmSunday=1
AlarmMonday=1
AlarmTuesday=1
AlarmWednesday=1
AlarmThursday=1
AlarmFriday=1
AlarmSaturday=1
;----------
TimeFormatTypeNum=2
CenterTimeFormatTypeNum=1
TimeLeadingZeroNum=1
Time24HourNum=1

CalendarNum=1
CalendarEvents=1

HideTimeCenter=1
StartMonday=0
;----------
PlayerNum=1
PlayerTypeNum=0

SkipSecondsNum=2
VolumeSliderSteps=5
;----------
IPAddress=N/A
;----------
ExchangeCurrency1=USD
ExchangeCurrency2=EUR

ExchangeNum=1
;----------
RecentFileFilter=
;----------
USER=ossamamehmood
;----------
ReverseDarkLight=0
;----------

Xpos=0
Xnum=0
Xval=(#PSCREENAREAWIDTH#*#Xnum#)

Ypos=0
Ynum=0
Yval=(#PSCREENAREAHEIGHT#*#Ynum#)

StretchNum=0

BarDragX=0
BarDragY=0

BarXposOffsetNum=0

BarXposOffset=0
BarYposOffset=0
BarLengthOffset=(-#BarXposOffset#*2)

TopReservationOffset=0

VallistartIntegration=0

; ----------------------------------------------------
; ADVISORY: It is not recommended to change any of the settings below.
; Changing any of the below values may have irrevesible effects on Droptop's function.
; ----------------------------------------------------

TopHeight=(([#TopHeight[#ThemeNum]]*#DroptopSize#)-(([#TopHeight[#ThemeNum]]*#DroptopSize#)%1))
CropHeight=#TopHeight#

AlwaysShowSkin=1
AutohideTopBar=0

TopIconSize=Medium
TopIconWH=32

IconSize=Small
IconW=16
IconH=16

DPIRescaleValue=1

ZposBehavior=1
PopupInFullscreen=0

FirstLoad=1

OSVERSION=5
Win10Apps=1

UniversalFont=SF Pro Display

CustomAppID1=JaxCore
CustomAppID2=Quick_Settings-Cariboudjan
CustomAppID3=Recycle_Bin-Phanlock
CustomAppID4=Daily_Quotes-Bunz
CustomAppID5=Sample_App-Cariboudjan

JaxCore=1
Quick_Settings-Cariboudjan=2
Sample_App-Cariboudjan=5

; ----------------------------------------------------

CustomAppSlots=Below
Disks-Phanlock=1
Recycle_Bin-Phanlock=3
Daily_Quotes-Bunz=4
Location-notAperson=1
System_Monitor-Yaron=2
SystemMonitor-Yaron=2
Media_Control-Yaron=2
Color_Mode_Toggle-Cariboudjan=1
Thumbtack-Cariboudjan=1
Stocks-Cariboudjan=1
