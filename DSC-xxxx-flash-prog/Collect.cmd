@echo off
cls
rem ***  Paths to various things

set DEST_DIR=%~dp0\RAM
set FILE_LIST=56F8006 56F8014 56F8023 56F825X 56F8323

rmdir /s /q "%DEST_DIR%"
mkdir "%DEST_DIR%"

for %%f in (%FILE_LIST%) do copy "%~dp0\MC%%f\DSC-%%f-flash-prog.elf.p.S"  "%DEST_DIR%"

pause