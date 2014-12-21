/*
 Minimal Linker file for RAM image
 */

/* Entry Point */
ENTRY(asm_testApp)

MEMORY {
   /* Optimized for 2K RAM */
/*   m_flashProg (RX) : ORIGIN = 0x1FFFFE00, LENGTH = 0x0438 /* 2K RAM (0.5K)+(1.5K) */
   m_flashProg (RX) : ORIGIN = 0x1FFFFF00, LENGTH = 0x0320   /* 1K RAM (0.25K)+(0.75K) */
}

SECTIONS {
   STACKSIZE = 50;

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
