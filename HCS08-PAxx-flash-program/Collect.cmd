@echo off
cls
rem ***  Paths to various things

set DEST_DIR=%~dp0\RAM
set FILE_LIST=Default-eeprom-0x40 Default-flash-0x40

rmdir /s /q "%DEST_DIR%"
mkdir "%DEST_DIR%"

for %%f in (%FILE_LIST%) do copy /y "%~dp0\%%f\*.s19"  "%DEST_DIR%"

pause