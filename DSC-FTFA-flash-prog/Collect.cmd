@echo on
cls
rem ***  Paths to various things

set FLASH_DIR=.\FLASH
set FILE_LIST=56F844XX

mkdir "%FLASH_DIR%"
for %%f in (%FILE_LIST%) do copy "MC%%f\DSC-%%f-flash-prog.elf.p.S"  "%FLASH_DIR%"

pause