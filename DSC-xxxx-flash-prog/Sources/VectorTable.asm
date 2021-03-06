;==========================================================================================
;  Relocated Vector Table (P)
;
FLASH_ERR_TRAP equ 7 ; USBDM error number for TRAP

; OMR mode bits

NL_MODE        EQU      $8000
CM_MODE        EQU      $0100
XP_MODE        EQU      $0080
R_MODE         EQU      $0020
SA_MODE        EQU      $0010

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
   
; setup the OMR with the values required by C

   bfset #NL_MODE,omr              ; ensure NL=1  (enables nested DO loops)
   nop
   nop
                                    ; ensure CM=0  (optional for C)
                                    ; ensure XP=0 to enable harvard architecture
                                    ; ensure R=0  (required for C)
                                    ; ensure SA=0 (required for C)
   bfclr #(CM_MODE|XP_MODE|R_MODE|SA_MODE),omr   

   move.w   #-1,x0
   moveu.w  x0,m01                  ; set the m register to linear addressing
            
   moveu.w  hws,la                  ; clear the hardware stack
   moveu.w  hws,la
   nop
   nop
   
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
