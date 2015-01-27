@echo on
cls
rem ***  Paths to various things

set FLASH_DIR=.\FLASH
set FILE_LIST=56F8006 56F8014 56F8023 56F825X 56F8323

mkdir "%FLASH_DIR%"
for %%f in (%FILE_LIST%) do copy "MC%%f\DSC-%%f-flash-prog.elf.p.S"  "%FLASH_DIR%"

pause