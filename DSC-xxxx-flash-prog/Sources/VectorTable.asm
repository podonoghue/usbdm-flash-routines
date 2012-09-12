;==========================================================================================
;  Relocated Vector Table (P)
;
FLASH_ERR_TRAP equ 7 ; USBDM error number for TRAP

   section vector_table
   org   p:

   global   FRelocatedVectorTable
   global   FflashProgramHeader
   global   Fasm_entry
   global   FstackStart
   global   FsetErrorCode
   
   ; Provided by linker cmd file
   global   INTC_VBA_VALUE       ; VBA register value to relocate vector table
   global   INTC_VBA             ; Address of VBA register
   
   SUBROUTINE "FRelocatedVectorTable",FRelocatedVectorTable,FRelocatedVectorTableEND-FRelocatedVectorTable

FRelocatedVectorTable:
;  Interrupt               ; Description                              Pri   VBA+  #
;=============================================================================================
   ;dw FflashProgramHeader ; Address of info table - done by linker
    jmp >abort             ; COP Reset Overlay - not used
    jmp >abort             ; Illegal Instruction                       3    0x04  2
    jmp >abort             ; SW Interrupt 3                            3    0x06  3
    jmp >abort             ; Hardware Stack Overflow                   3    0x08  4
    jmp >abort             ; Misaligned Data Access                    3    0x0A  5
 
;========================================================================================
FRelocatedVectorTableEND:


   SUBROUTINE "Fasm_entry",Fasm_entry,Fasm_entryEND-Fasm_entry

Fasm_entry:
   ; Relocate vector table to pRAM
   move.l   #INTC_VBA_VALUE,R0            ; Point at relocated vector table
   move.w   R0,x:>INTC_VBA                ; Relocate Vector table
   
   ; Set up stack
   move.l   #>>FstackStart,r0             ; Import SP address from linker
   tfra     r0,sp
 
   ; Debug only
   ;jsr      >FtestApp  ; For debug

   ; Jump to main C code
   jmp     >Fentry   
   
abort:
   move.w  #FLASH_ERR_TRAP,A1
   jmp     >FsetErrorCode
      
Fasm_entryEND:
      
   endsec   
   end
