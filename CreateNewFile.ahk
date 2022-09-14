#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
; #Warn  ; Enable warnings to assist with detecting common errors.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

USER_NAME = "Taylor Hancock"
NUM_STARS = 20

::.createNewCPP::
Sleep, 50 ; wait for .createNewCPP to delete itself

WinGet, WindowID ; get active window for...later

InputBox, fileName, File Name Input, Please input your desired file name:
;fileName := %fileName%.cpp ; turn fileName into a .cpp

WinActivate, ahk_id WindowID ; move back to active window

createNewFile(fileName)

WinActivate, ahk_id WindowID ; ensure return to active

Sleep, 200 ; wait for window to open

createHeader(fileName)
return

createNewFile(fileName) {
    Send, ^n ; creates new file
    Send, ^s ; saves new file
    WinWait, Save As ; wait until save window opens
    Send, %fileName% ; prints fileName
    Send, {Enter} ; saves
}

createHeader(fileName) {
    FormatTime, CurrentTime,, MMM dd, yyyy
    Send, / ; sends slash to start comment
    Loop %NUM_STARS% { ; prints NUM_STARS stars for the line edges
        Send, *
    }
    Send, {Enter} * File:    %fileName% ; creates File line
    Send, {Enter} * Author:  %USER_NAME% ; creates Author line
    Send, {Enter} * Purpose:{Space} ; creates Purpose line to fill
    Send, {Enter} * Version: 1.0 %CurrentTime% ; creates version 1.0 with current time
    Send, {Enter} * Resources:{Space}{Enter}{Space} ; creates blank Resources line to be filled
    Loop %NUM_STARS% { ; prints NUM_STARS stars for the line edges
        Send, *
    }
    Send, / ; sends slash to end comment
}

