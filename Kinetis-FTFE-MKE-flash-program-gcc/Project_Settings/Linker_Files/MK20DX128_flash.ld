/*
 Minimal Linker file for RAM image
 */

/* Entry Point */
ENTRY(asm_testApp)

MEMORY {
   /* Optimized for 2K RAM */
   m_flashProg (RX) : ORIGIN = 0x20000000, LENGTH = 0x1000
}

SECTIONS {
   STACKSIZE = 200;

   .flashProg : {
      . = ALIGN (4*32);   /* Alignment allows for 32 entries => 16 interrupts */
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
