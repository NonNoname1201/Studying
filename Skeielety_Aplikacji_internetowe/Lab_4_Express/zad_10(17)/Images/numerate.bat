@echo off
setlocal EnableDelayedExpansion
set i=0
for %%a in (*) do (
    if "%%~nxa" neq "%~nx0" (
        set /a i+=1
        ren "%%a" "!i!.png"
    )
)