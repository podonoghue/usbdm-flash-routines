


# ----------------------------------------------------

# Freescale sample code

# linker command file for DSP56800E Simulator
# for Large Data Model (LDM)


# ----------------------------------------------------

    
# see end of file for additional notes




# CodeWarrior preference settings:
#
#   M56800E Processor:
#     Small Program Model: OFF
#        Large Data Model: ON
#
#   M56800E Assembler:
#        Default Data Memory Model: 24-bit
#     Default Program Memory Model: 19-bit




# 56800E memory map for LDM

MEMORY 
{
	.p_interrupts_RAM   (RWX) : ORIGIN = 0x0,      LENGTH = 0x82
    .p_RAM              (RWX) : ORIGIN = 0x0082,   LENGTH = 0xFF3E
    .x_RAM              (RW)  : ORIGIN = 0x0001,   LENGTH = 0xFF7F
    .x_sim_reserved     (RWX) : ORIGIN = 0xFF80,   LENGTH = 0x0080
    .x_RAM2             (RWX) : ORIGIN = 0x10000,  LENGTH = 0x0000   
}




# we ensure the interrupt vector section is not deadstripped here
# the label "interrupt_vectors" comes from file 56800_vector.asm

KEEP_SECTION{ interrupt_vectors.text }



SECTIONS 
{
    .interrupt_code :
    {
        * (interrupt_vectors.text)  
       
    } > .p_interrupts_RAM
    
    
    
    .application_code :
    {
        # .text sections
        
        * (.text)
        
        * (rtlib.text)
        * (fp_engine.text)
        * (user.text)    
    } > .p_RAM



    .data :
    {    
        # .data sections
        
        * (.const.data.char)   # used if "Emit Separate Char Data Section" enabled
        * (.const.data)
        * (fp_state.data)
        * (rtlib.data)
        * (.data.char)         # used if "Emit Separate Char Data Section" enabled
        * (.data)
	    
		
		
        
        
        # .bss sections
        
        * (rtlib.bss.lo)
        * (rtlib.bss)
        . = ALIGN(1);
        _START_BSS = .;
        * (.bss.char)          # used if "Emit Separate Char Data Section" enabled
        * (.bss)
        _END_BSS   = .;



        # setup the heap address 
        
        . = ALIGN(4);
        _HEAP_ADDR = .;
        _HEAP_SIZE = 0x100;
        _HEAP_END = _HEAP_ADDR + _HEAP_SIZE; 
        . = _HEAP_END;



        # setup the stack address 
        
        _min_stack_size = 0x200;
        _stack_addr = _HEAP_END;
        _stack_end  = _stack_addr + _min_stack_size;
        . = _stack_end;
        
        
        # export heap and stack runtime to libraries 
            
        F_heap_addr   = _HEAP_ADDR;
        F_heap_end    = _HEAP_END;
        F_Lstack_addr = _HEAP_END;
        F_start_bss   = _START_BSS;
        F_end_bss     = _END_BSS;
    } > .x_RAM    
}





# -------------------------------------------------------
# additional notes:


# about the reserved sections:

# p_interrupts_RAM -- reserved in internal pRAM
# memory space reserved for interrupt vectors
# interrupt vectors must start at address zero
# interrupt vector space size is 0x82



# about LCF conventions:

# program memory (p memory)
# (RWX) read/write/execute for pRAM
# (RX) read/execute for flashed pROM

# data memory (X memory)
# (RW) read/write for xRAM
# (R)  read for data flashed xROM or reserved x memory

# LENGTH = next start address - previous
# LENGTH = 0x0000 means use all remaing memory


# revision history
# 011226 R1.0  c.m. first version
# 020220 R1.1  a.h. updates
# 020308 R1.1  a.h. 56838E
# 021101 R2.0  a.h. R2.0 prep
# 021204 R2.01 a.h. bss align by 1




