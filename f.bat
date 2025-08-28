@echo off
echo Building
mingw32-make
cd build
if %errorlevel% equ 0 (
    echo Build Succeeded!
    lppo.exe
) else (
    echo Build Failed!
)
