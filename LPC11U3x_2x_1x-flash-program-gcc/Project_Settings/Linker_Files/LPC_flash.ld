/* 
 * Linker-rom.ld 
 *
 * Memory map for devices without SRAM_U allocation for bit-band/bme
 */
 
/* ---- <<< Use Configuration Wizard in Context Menu >>> ---- */

MEMORY
{
/*
 *  <o>  RAM addres
 *  <o1> RAM size 
 */
  ram   (rwx) : ORIGIN = 0x10000000, LENGTH = 0x2000
};

/*
 *  <o>  Stack Size
 *  <i>  Need space for IAP routines 128 bytes + code needs
 */
__stack_size = 256;
 
OUTPUT_FORMAT ("elf32-littlearm", "elf32-bigarm", "elf32-littlearm")
SEARCH_DIR(.)

ENTRY(entry)

SECTIONS
{
   .text :
   {
      __loadAddress = .;
      
      /* Vector table - Must be at start of RAM */
      __VECTOR_TABLE = .;
      KEEP(*(.interrupt_vectors))
      
      /* Make sure we pulled in at least a reset vector.  */
      ASSERT (. != __VECTOR_TABLE, "No reset vector found");
      __VECTOR_TABLE_END = .;
      
      KEEP(*(.text))           /* .text sections (code) */
      KEEP(*(.text.*))         /* .text.* sections (code) */
      KEEP(*(.rodata))         /* .rodata.* sections (constants, strings, etc.) */
      KEEP(*(.rodata.*))       /* .rodata.* sections (constants, strings, etc.) */
      KEEP(*(.data))           /* .rodata.* sections (constants, strings, etc.) */
      KEEP(*(.data.*))         /* .rodata.* sections (constants, strings, etc.) */
      
      . = . + __stack_size;
    } > ram
   __stacktop = .;

   __exidx_end = .;

   __etext = .;    /* define a global symbol at end of code */
   __DATA_ROM = .; /* Symbol is used by startup for data initialization */

  /*
   RAM Memory map
  +----------------------+ __loadAddress  
  | RAM vector table     |
  |                      |
  +----------------------+ __data_start__
  | DATA                 |
  |                      |
  +----------------------+ __bss_end__ = __HeapBase
  | Stack                |
  | (__stack_size__)     | 
  +----------------------+ __StackTop
  
  */
}
