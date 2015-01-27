  
   


; sample code



; this __romCopy copies pROM to xRAM


; we use unsigned long moves for setup of addresses and size
; otherwise the values will be sign-extended



; define which loop routine to assemble -- software or hardware loop
; see alternative routine below


; hardware loop is DSP56800E stationery default __romCopy routine:

    DEFINE  useHardwareLoop   ''   ; define which copy routine to assemble



	section utility
	
	XREF	F_pROM_to_xRAM
	XREF	F_Ldata_size
	XREF	F_Ldata_ROM_addr
	XREF    F_Ldata_RAM_addr


	org	p:

	
	GLOBAL F__romCopy

	SUBROUTINE "F__romCopy",F__romCopy,F__romCopyEND-F__romCopy


F__romCopy:



; optional check for pROM-xRAM copy request
; DSP56800 Stationery LCFs sets variable F_rom_to_ram
; comment this test out if target's LCF is always set for pROM-xRAM 

    move.w  #F_pROM_to_xRAM,x0      ; optional check
    tst.w   x0
	beq     end_romCopy             ; if no pROM-to-xRAM, then exit
    nop	






; if useHardwareLoop is defined, assemble this code

    IF  @DEF('useHardwareLoop')
    
    

; Stationery default routine
; 56800E LC register doesn't have 8191 element limitation of 56800
; so we can use hardware loop here



; pROM-to-xRAM hardware loop

    move.l  #>>F_Ldata_size,r2      ; count
    move.l  #>>F_Ldata_ROM_addr,r3  ; src address  -- ROM data start
    move.l  #>>F_Ldata_RAM_addr,r1  ; dest address -- RAM data start    
    nop
    
    do      r2,>>end_romCopy        ; copy for r2 times
    move.w  p:(r3)+,x0              ; fetch p value at address r3
    nop
    nop
    nop
    move.w  x0,x:(r1)+              ; stash value at x address r1   




    ELSE    ; assemble the following code
    
    



; pROM-to-xRAM software loop	
	
    move.l  #>>F_Ldata_size,y0      ; count
;   tst.w   y0                      ; optional zero count test
;   beq     end_romCopy             ; if zero count, then exit

      
    move.l  #>>F_Ldata_ROM_addr,r3  ; src address  -- pROM data start
    move.l  #>>F_Ldata_RAM_addr,r1  ; dest address -- xRAM data start
    nop

loop_rom2ram:      
    move.w  p:(r3)+,x0              ; fetch value at address r3
    nop
    nop
    nop
    move.w  x0,x:(r1)+              ; stash value at address r1
    
    dec.l   y0					    ; decrement count and test
    bne     loop_rom2ram            ; if not zero, continue loop   
	
	
	
    ENDIF
    	
    
end_romCopy:                      
	rts 

F__romCopyEND:

	endsec
	end
	
	
	