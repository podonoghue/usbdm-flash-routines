## ###################################################################
##
##     Copyright Freescale Semiconductor, Inc. 2011
##
##     Processor : MC56F84452
##
##     Abstract  :
##
##     This file is used by the linker. It describes files to be linked,
##     memory ranges, stack size, etc. For detailed description about linker
##     command files see CodeWarrior documentation.
##
## ###################################################################

MEMORY {
        
        ## Program Memory space 
     	.p_interruptsboot_ROM (RX)  : ORIGIN = 0x000000, LENGTH = 0x000004 # reserved for boot location
     	.p_interrupts_ROM     (RX)  : ORIGIN = 0x000004, LENGTH = 0x000200 # reserved for interrupt vectoring
#     	.p_reserved_IFR       (RX)  : ORIGIN = 0x000200, LENGTH = 0x000008 # 16 bytes reserved for IFR
     	.p_flash_ROM          (RX)  : ORIGIN = 0x000208, LENGTH = 0x00BDF8 # primary location for code to be run - to 0x0bfff
#     	.p_external           (RX)  : ORIGIN = 0x020000, LENGTH = 0x040000 # 256k words not used in this device
#     	.p_ram_RAM_code       (RX)  : ORIGIN = 0x060200, LENGTH = 0x000E00 # (alias of 0000 for data RAM space)
#     	.p_ram_RAM_data       (RX)  : ORIGIN = 0x061000, LENGTH = 0x001000 # (alias of 1000 for data RAM space)

#     	.p_unused1            (RX)  : ORIGIN = 0x064000, LENGTH = 0x004000 # unused address space
     	.p_boot_ROM           (RX)  : ORIGIN = 0x068000, LENGTH = 0x004000 # secondary program/data flash
#     	.p_unused2            (RX)  : ORIGIN = 0x06C000, LENGTH = 0x194000 # unused address space out to 0x1fffff (end of 21 bit program address space)
 

    	.p_flash_ROM_data     (RX)  : ORIGIN = 0x000000, LENGTH = 0x002000    # internal xRAM data mirror
                                                                       		  # for pROM-to-xRAM copy

		## Data Memory space 
    	#.x_internal_RAM_code   (RW)  : ORIGIN = 0x000000, LENGTH = 0x001000 # alias of 60000 for program space
    	.x_internal_RAM_data   (RW)  : ORIGIN = 0x000000, LENGTH = 0x002000 # alias of 60000 for program space
#    	.reserved_1            (RW)  : ORIGIN = 0x004000, LENGTH = 0x004000 # unused
#    	.x_boot_ROM            (RW)  : ORIGIN = 0x008000, LENGTH = 0x004000 # secondary (boot) program/data flash 
    	.x_platform            (RW)  : ORIGIN = 0x00C000, LENGTH = 0x002000 # on-platform peripheral address space
    	.x_peripherals         (RW)  : ORIGIN = 0x00E000, LENGTH = 0x002000 # off-platform perihperal address space
#    	.reserved_2            (RW)  : ORIGIN = 0x010000, LENGTH = 0x00E000
    	.x_EEE                 (RW)  : ORIGIN = 0x01E000, LENGTH = 0x000400 # max used is 1k 
    	.x_EEE_reserved        (RW)  : ORIGIN = 0x01E400, LENGTH = 0x001C00 # total ammount address space reserved for EEE is 8k
#   	.x_interrupts_ROM      (RW)  : ORIGIN = 0x020000, LENGTH = 0x000200 # reserved for interrupts
#    	.x_reserved_IFR        (RW)  : ORIGIN = 0x020200, LENGTH = 0x000008 # reserved for IFR
#    	.x_flash_ROM           (RW)  : ORIGIN = 0x020208, LENGTH = 0x00BDF8 # primary location for code to be run - to 0x2bfff
#    	.x_external            (RW)  : ORIGIN = 0x040000, LENGTH = 0x040000 # 256k words not used in this device
    	.x_EOnCE               (RW)  : ORIGIN = 0xFFFF00, LENGTH = 0x000100 # debugger and other uses at end of memory space (24 bit)

}

KEEP_SECTION { interrupt_vectorsboot.text }
KEEP_SECTION { interrupt_vectors.text }

SECTIONS {

        .interrupt_vectorsboot :
        {
          F_vector_addr = .;
          # interrupt vectors boot area
          * (interrupt_vectorsboot.text)
        } > .p_interruptsboot_ROM

        .interrupt_vectors :
        {
          # interrupt vectors
          * (interrupt_vectors.text)
        } > .p_interrupts_ROM

        .ApplicationCode :
        {

              F_Pcode_start_addr = .;

              # .text sections
              * (.text)
              
              * (rtlib.text)
              * (startup.text)
              * (interrupt_routines.text)
              * (fp_engine.text)
              * (ll_engine.text)
              * (user.text)
              * (.data.pmem)

              F_Pcode_end_addr = .;

              # save address where for the data start in pROM
              . = ALIGN(2);
              __pROM_data_start = .;

        } >.p_flash_ROM

        # AT sets the download address
        # the download stashes the data just after the program code
        # as determined by our saved pROM data start variable

        .data_in_p_flash_ROM : AT(__pROM_data_start)
        {
              # the data sections flashed to pROM
              # save data start so we can copy data later to xRAM

              __xRAM_data_start = .;

              # .data sections
              * (.const.data.char)  # used if "Emit Separate Char Data Section" enabled
              * (.const.data)

              * (fp_state.data)
              * (rtlib.data)
              * (.data.char)        # used if "Emit Separate Char Data Section" enabled
              * (.data)
	    
		
		

              # save data end and calculate data block size
              . = ALIGN(2);
              __xRAM_data_end = .;
              __data_size = __xRAM_data_end - __xRAM_data_start;

        } > .p_flash_ROM_data    # this section is designated as p-memory
                                 # with X flag in the memory map
                                 # the start address and length map to
                                 # actual internal xRAM

        .ApplicationData :
        {
              # save space for the pROM data copy
              

              . =  __data_size + .;

              # .bss sections
              * (rtlib.bss.lo)
              * (rtlib.bss)
              . = ALIGN(4);
              F_Xbss_start_addr = .;
              _START_BSS = .;
              * (.bss.char)         # used if "Emit Separate Char Data Section" enabled
              * (.bss)
              . = ALIGN(2);         # used to ensure proper functionality of the zeroBSS hardware loop utility
              _END_BSS   = .;
              F_Xbss_length = _END_BSS - _START_BSS;

              /* Setup the HEAP address */
              . = ALIGN(4);
              _HEAP_ADDR = .;
              _HEAP_SIZE = 0x00000100;
              _HEAP_END = _HEAP_ADDR + _HEAP_SIZE;
              . = _HEAP_END;

              /* SETUP the STACK address */
              _min_stack_size = 0x00000200;
              _stack_addr = _HEAP_END;
              _stack_end  = _stack_addr + _min_stack_size;
              . = _stack_end;

              /* EXPORT HEAP and STACK runtime to libraries */
              F_heap_addr   = _HEAP_ADDR;
              F_heap_end    = _HEAP_END;
              F_Lstack_addr = _HEAP_END;
              F_StackAddr = _HEAP_END;
              F_StackEndAddr = _stack_end - 1;

              # runtime code __init_sections uses these globals:

              F_Ldata_size     = __data_size;
              F_Ldata_RAM_addr = __xRAM_data_start;
              F_Ldata_ROM_addr = __pROM_data_start;

              F_xROM_to_xRAM   = 0x0000;
              F_pROM_to_xRAM   = 0x0001;

              F_start_bss   = _START_BSS;
              F_end_bss     = _END_BSS;

              __DATA_END=.;

        } > .x_internal_RAM_data

}
