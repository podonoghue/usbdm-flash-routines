@echo off
cls
rem ***  Paths to various things

set DEST_DIR=%~dp0\RAM
set FILE_LIST=Default-0x80 Default-0xB0 Small-0x80

rmdir /s /q "%DEST_DIR%"
mkdir "%DEST_DIR%"

for %%f in (%FILE_LIST%) do copy /y "%~dp0\%%f\*.s19"  "%DEST_DIR%"

pause