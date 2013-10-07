MEMORY 
{
   .pRAM  (RX)  : ORIGIN = 0x04F800, LENGTH = 0x000800
   .xRAM  (RW)  : ORIGIN = 0x000000, LENGTH = 0x001000
}

KEEP_SECTION{ vector_table.text}
KEEP_SECTION{ reset_vector.text}

SECTIONS 
{
    STACKSIZE = 40;

    INTC_VBA        = 0xF1AA;                      # Address of Vector Base Address register
    INTC_VBA_OFFSET = 128;                         # Offset for VBA register value (8-bit)
    INTC_VBA_VALUE  = ADDR(.pRAM)/INTC_VBA_OFFSET; # Value for VBA

    .pCode :
    {
        . = ALIGN(1<<INTC_VBA_OFFSET);
        FloadAddress = .;
        
        WRITEW(FflashProgramHeader);          # Start of relocated vector table
        * (vector_table.text)                 # Rest of vector table
        
        OBJECT (FflashProgramHeader, main.c)
        * (.text)		
    } > .pRAM

    .xData :
    {
#       . = .+ SIZEOF(.pCode)/2;  # Space for overlayed code
        . = ALIGN(2);
        FstackStart = .+1;
        . = .+STACKSIZE;          # Stack space
        . = ALIGN(2);
        FflashData = .;	          # Flash data start
        * (.const.data) 
    } > .xRAM 
}

