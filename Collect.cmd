@echo off
cls

set DEST_DIR=%~dp0\GeneratedFiles
set DEST_DIR_ARM=%DEST_DIR%\ARM
set DEST_DIR_HCS08=%DEST_DIR%\HCS08
set DEST_DIR_DSC=%DEST_DIR%\DSC
set DEST_DIR_CFV1=%DEST_DIR%\CFV1
set DEST_DIR_CFVx=%DEST_DIR%\CFVx
set DEST_DIR_S12Z=%DEST_DIR%\S12Z

rem
rem ARM devices
rem
if not exist %DEST_DIR_ARM% mkdir %DEST_DIR_ARM%

set FILE_LIST_ARM=
set FILE_LIST_ARM=%FILE_LIST_ARM% BootLoopK20 BootLoopKL25
set FILE_LIST_ARM=%FILE_LIST_ARM% Kinetis-FTFL-MK-flash-program-gcc
set FILE_LIST_ARM=%FILE_LIST_ARM% Kinetis-FTFE-MK-flash-program-gcc Kinetis-FTFE-MKE-flash-program-gcc Kinetis-FTFE-MKE18-flash-program-gcc
set FILE_LIST_ARM=%FILE_LIST_ARM% Kinetis-FTMRE-flash-program-gcc
set FILE_LIST_ARM=%FILE_LIST_ARM% Kinetis-FTMRH-eeprom-program-gcc Kinetis-FTMRH-flash-program-gcc
set FILE_LIST_ARM=%FILE_LIST_ARM% Kinetis-FTFA-MK-flash-program-gcc Kinetis-FTFA-MKL-flash-program-gcc Kinetis-FTFA-MKM-flash-program-gcc
set FILE_LIST_ARM=%FILE_LIST_ARM% Kinetis-FTFA-MKV10-flash-program-gcc
set FILE_LIST_ARM=%FILE_LIST_ARM% STM32F100xx-default-flash-program

echo %FILE_LIST_ARM%
for %%f in (%FILE_LIST_ARM%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.hex %DEST_DIR_ARM% 

set FILE_LIST_ARM=LPC-CM0-flash-program-gcc LPC-CM3-flash-program-gcc

echo %FILE_LIST_ARM%
for %%f in (%FILE_LIST_ARM%) do if exist %~dp0\%%f\Release copy %~dp0\%%f\Release\*.hex %DEST_DIR_ARM% 

rem
rem HCS08 devices
rem
if not exist %DEST_DIR_HCS08% mkdir %DEST_DIR_HCS08%

set FILE_LIST_HCS08=
set FILE_LIST_HCS08=%FILE_LIST_HCS08% HCS08-PTxx-flash-program

echo %FILE_LIST_HCS08%
for %%f in (%FILE_LIST_HCS08%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.s19 %DEST_DIR_HCS08% 

set FILE_LIST_HCS08=
set FILE_LIST_HCS08=%FILE_LIST_HCS08% HCS08-default-flash-program\Small-0x80 HCS08-default-flash-program\Default-0x80 HCS08-default-flash-program\Default-0xB0 
set FILE_LIST_HCS08=%FILE_LIST_HCS08% HCS08-PAxx-flash-program\Default-eeprom-0x40 HCS08-PAxx-flash-program\Default-flash-0x40

echo %FILE_LIST_HCS08%
for %%f in (%FILE_LIST_HCS08%) do copy %~dp0\%%f\*.abs.s19 %DEST_DIR_HCS08% 

rem
rem DSC devices
rem
if not exist %DEST_DIR_DSC% mkdir %DEST_DIR_DSC%

set FILE_LIST_DSC=
set FILE_LIST_DSC=%FILE_LIST_DSC% DSC-FTFA-flash-prog DSC-FTFL-flash-prog DSC-xxxx-flash-prog

echo %FILE_LIST_DSC%
for %%f in (%FILE_LIST_DSC%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.p.S %DEST_DIR_DSC% 

set FILE_LIST_DSC=
set FILE_LIST_DSC=%FILE_LIST_DSC% DSC-xxxx-flash-prog\MC56F825X DSC-xxxx-flash-prog\MC56F8006 DSC-xxxx-flash-prog\MC56F8014
set FILE_LIST_DSC=%FILE_LIST_DSC% DSC-xxxx-flash-prog\MC56F8023 DSC-xxxx-flash-prog\MC56F8323
echo %FILE_LIST_DSC%
for %%f in (%FILE_LIST_DSC%) do copy %~dp0\%%f\*.elf.p.S %DEST_DIR_DSC% 

rem
rem CFV1 devices
rem
if not exist %DEST_DIR_CFV1% mkdir %DEST_DIR_CFV1%

set FILE_LIST_CFV1=
set FILE_LIST_CFV1=%FILE_LIST_CFV1% ColdfireV1Plus-default-flash-program ColdfireV1-default-flash-program

echo %FILE_LIST_CFV1%
for %%f in (%FILE_LIST_CFV1%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.S19 %DEST_DIR_CFV1% 

rem
rem CFVx devices
rem
if not exist %DEST_DIR_CFVx% mkdir %DEST_DIR_CFVx%

set FILE_LIST_CFVx=
set FILE_LIST_CFVx=%FILE_LIST_CFVx% ColdfireV2-default-flash-program

echo %FILE_LIST_CFVx%
for %%f in (%FILE_LIST_CFVx%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.S19 %DEST_DIR_CFVx% 

rem
rem STM devices
rem
if not exist %DEST_DIR_S12Z% mkdir %DEST_DIR_S12Z%

set FILE_LIST_S12Z=
set FILE_LIST_S12Z=%FILE_LIST_S12Z% S12Z-FTMRZ-flash-program

echo %FILE_LIST_S12Z%
for %%f in (%FILE_LIST_S12Z%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.sx  %DEST_DIR_S12Z% 

pause
exit







exit
echo %FILE_LIST%

rmdir /s /q "%DEST_DIR%"/*
mkdir "%DEST_DIR%"

for %%f in (%FILE_LIST%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.s19 %DEST_DIR% 
for %%f in (%FILE_LIST%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.sx  %DEST_DIR% 
for %%f in (%FILE_LIST%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.hex %DEST_DIR% 
for %%f in (%FILE_LIST%) do if exist %~dp0\%%f\RAM copy %~dp0\%%f\RAM\*.p.s %DEST_DIR% 
rem copy /y "%~dp0\%%f\*.s19"  "%DEST_DIR%"



pause