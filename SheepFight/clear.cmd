@ECHO OFF
ECHO Delete unnecessary files!

ECHO Delete folder .vs
rmdir /S /Q proj.win32\.vs

ECHO Delete folder proj.win32\Debug.win32
rmdir /S /Q proj.win32\Debug.win32

ECHO Delete file proj.win32\SheepFight.VC.db
del proj.win32\SheepFight.VC.db

ECHO Done

