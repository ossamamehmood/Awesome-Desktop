[Rainmeter]

[Variables]
DropdownItemPadding1=#DropdownNoIconPadding#

[MeasureSupporter]
Measure=Calc
IfCondition=#Supporter#=0
IfTrueAction=[!SetOptionGroup SupporterFolders FontColor "#*DropdownFontColor1*#,75"][!DisableMouseActionGroup "MouseOverAction|MouseLeaveAction|LeftMouseDownAction" SupporterFolders][!SetOptionGroup SupporterFolders FillColor "Fill Color 0,0,0,0"][!UpdateMeterGroup SupportFolders][!Redraw]

[IconStyle]
ImageName=