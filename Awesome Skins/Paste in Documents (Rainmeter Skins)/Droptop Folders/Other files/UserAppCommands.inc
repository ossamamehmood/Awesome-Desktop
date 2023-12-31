[Variables]
; Define up to 5 actions per application. By selecting the "Create app commands..." button, 
; a template to create commands for your app has been added to your clipboard. Paste it at the bottom of this document.

; See the sample below for a reference on how to configure your commands. 

; Actions use AutoHotkey script. For information on how to create AutoHotkey commands, 
; go here: https://www.autohotkey.com/docs/Hotkeys.htm

; ^ = Control
; + = Shift
; ! = Alt
; # = Windows key
; {Tab} {Esc} {Enter} {Backspace} {F1} {F2} {F3} {Up} {Down} {Left} {Right} {Space}

; When finished, save this document and refresh Rainmeter to view your changes.



;Example
;---------------------------------------
;Replace "APPLICATIONNAME" with the name of the application you are creating commands for
;Set APPLICATIONNAME.exe.CommandCount= to the number of commands you have created

APPLICATIONNAME.exe.CommandCount=5

;Name the command and then set its keyboard shortcut action
APPLICATIONNAME.exe.CommandName01=New tab
APPLICATIONNAME.exe.CommandAction01=^t

;Example: "^+t" means Control+Shift+T
APPLICATIONNAME.exe.CommandName02=Reopen closed tab
APPLICATIONNAME.exe.CommandAction02=^+t

APPLICATIONNAME.exe.CommandName03=New Incognito window
APPLICATIONNAME.exe.CommandAction03=^+n

APPLICATIONNAME.exe.CommandName04=Downloads
APPLICATIONNAME.exe.CommandAction04=^j

APPLICATIONNAME.exe.CommandName05=History
APPLICATIONNAME.exe.CommandAction05=^h
;---------------------------------------
