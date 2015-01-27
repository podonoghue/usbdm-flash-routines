MEMORY 
{
   .pRAM  (RX)  : ORIGIN = 0x008000, LENGTH = 0x000800 # pRAM Overlaid 
   .xRAM  (RW)  : ORIGIN = 0x000000, LENGTH = 0x000C00 # xRAM Overlaid
}

KEEP_SECTION{ vector_table.text}
KEEP_SECTION{ reset_vector.text}

SECTIONS 
{
    STACKSIZE = 40;

    INTC_VBA        = 0xF0E7;                      # Address of Vector Base Address register
    INTC_VBA_OFFSET = 64;                          # Offset for VBA register value (7-bit)
    INTC_VBA_VALUE  = ADDR(.pRAM)/INTC_VBA_OFFSET; # Value for VBA

    .pCode :
    {
        . = ALIGN(1<<INTC_VBA_OFFSET);
        FloadAddress = .;
        
        WRITEW(FflashProgramHeader);          # Start of relocated vector table
        * (vector_table.text)                 # Rest of vector table
        
        OBJECT (FflashProgramHeader, main_c.obj)
        * (.text)		
    } > .pRAM

    .xData :
    {
        . = .+ SIZEOF(.pCode)/2;  # Space for overlayed code
        . = ALIGN(2);
        FstackStart = .+1;
        . = .+STACKSIZE;          # Stack space
        . = ALIGN(2);
        FflashData = .;	          # Flash data start
        * (.const.data) 
    } > .xRAM 
}

