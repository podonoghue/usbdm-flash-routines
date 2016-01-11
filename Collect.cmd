@echo off
cls

set DEST_DIR=%~dp0\GeneratedFiles

set FILE_LIST=
set FILE_LIST=%FILE_LIST% BootLoopK20 BootLoopKL25
set FILE_LIST=%FILE_LIST% ColdfireV1+default-flash-program ColdfireV1-default-flash-program ColdfireV2-default-flash-program
set FILE_LIST=%FILE_LIST% DSC-FTFA-flash-prog DSC-FTFL-flash-prog DSC-xxxx-flash-prog
set FILE_LIST=%FILE_LIST% HCS08-default-flash-program HCS08-PAxx-flash-program HCS08-PTxx-flash-program
set FILE_LIST=%FILE_LIST% Kinetis-default-flash-program Kinetis-FTFE-flash-program-gcc Kinetis-FTFL-flash-program-gcc
set FILE_LIST=%FILE_LIST% Kinetis-FTMRE-flash-program-gcc Kinetis-FTMRH-eeprom-program-gcc Kinetis-FTMRH-flash-program-gcc
set FILE_LIST=%FILE_LIST% Kinetis-MK-FTFA-flash-program-gcc Kinetis-MKL-FTFA-flash-program-gcc Kinetis-MKM-FTFA-flash-program-gcc
set FILE_LIST=%FILE_LIST% Kinetis-MKV10-FTFA-flash-program-gcc
set FILE_LIST=%FILE_LIST% S12Z-FTMRZ-flash-program STM32F100xx-default-flash-program

rem echo %FILE_LIST%

rmdir /s /q "%DEST_DIR%"/*
mkdir "%DEST_DIR%"

for %%f in (%FILE_LIST%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.s19 %DEST_DIR% 
for %%f in (%FILE_LIST%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.sx  %DEST_DIR% 
for %%f in (%FILE_LIST%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.hex %DEST_DIR% 
for %%f in (%FILE_LIST%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.p.s %DEST_DIR% 
rem copy /y "%~dp0\%%f\*.s19"  "%DEST_DIR%"

pause