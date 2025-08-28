@echo off
setlocal enabledelayedexpansion

set INCLUDE_DIR=E:\main\plsc\mingw32\include
set LIB_DIR=E:\main\plsc\mingw32\lib

:: Create folders if they don't exist
if not exist obj mkdir obj
if not exist build mkdir build

:: Compile all .cpp files in src\
for %%f in (src\*.cpp) do (
    echo Compiling %%f...
    set filename=%%~nf
    g++.exe -Wall -g -std=c++20 -I"%INCLUDE_DIR%" -c "%%f" -o "obj\!filename!.o"
)

:: Link all object files
set OBJS=
for %%f in (obj\*.o) do (
    set OBJS=!OBJS! %%f
)

echo Linking...
g++.exe -L%LIB_DIR% -o build\SDL3Game.exe %OBJS% -lmingw32 -lSDL3_image -lSDL3 %LIB_DIR%\libSDL3.a

echo Done!
pause
