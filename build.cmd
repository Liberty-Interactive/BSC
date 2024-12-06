@echo off
mkdir build
cd build
rem we use cmake!!
cmake ..
cmake --build .
rem mmm... copy..
rem xcopy /Y /E /I "..\res" "Debug"
cd Debug
BSC.exe
pause
cd ..
cd ..
cls