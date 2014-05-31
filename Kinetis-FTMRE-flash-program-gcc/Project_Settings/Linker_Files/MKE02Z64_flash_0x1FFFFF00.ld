/*
 Minimal Linker file for RAM image
 */

/* Entry Point */
ENTRY(asm_testApp)

MEMORY {
   /* Optimized for 2K RAM */
   m_flashProg (RX) : ORIGIN = 0x1FFFFF00, LENGTH = 0x400 /* 1K RAM (.25K lower)+(.75K upper) */
}

SECTIONS {
   STACKSIZE = 56;

   .flashProg : {
      . = ALIGN (4*4);   /* Alignment allows for 4 entries => 4 interrupts */
      __loadAddress = .;
      KEEP(*(.data.__vector_table));
      . = . + STACKSIZE;
      . = ALIGN(4);
      __stacktop = .;

      . = ALIGN (4);
      * (.data.*)
      * (.text.*)
      * (.rodata.*)
      . = ALIGN (4);
   } > m_flashProg
}
