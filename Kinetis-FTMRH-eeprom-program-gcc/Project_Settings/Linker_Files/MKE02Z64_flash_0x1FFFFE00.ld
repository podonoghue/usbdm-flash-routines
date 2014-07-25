/*
 Minimal Linker file for RAM image
 */

/* Entry Point */
ENTRY(asm_testApp)

MEMORY {
   /* Optimized for 2K RAM */
   m_flashProg (RX) : ORIGIN = 0x1FFFFE00, LENGTH = 0x800 /* 2K RAM (.5K lower)+(1.5K upper) */
}

SECTIONS {
   STACKSIZE = 200;

   .flashProg : {
      . = ALIGN (4*4);   /* Alignment allows for 32 entries => 16 interrupts */
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
