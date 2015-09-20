/*
 *    kinetis_sysinit.c - Default init routines for
 *                     		Kinetis ARM systems
 *    Copyright © 2010 Freescale semiConductor Inc. All Rights Reserved.
 */

#include "kinetis_sysinit.h"
#include "derivative.h"

typedef void (*const tIsrFunc)(void);
typedef struct {
  uint32_t * __ptr;
  tIsrFunc __fun[6];
} tVectorTable;

extern void isr_default(void);
extern uint32_t __stacktop[];
extern uint32_t gFlashProgramHeader[];

tVectorTable __vector_table = { /* Interrupt vector table */
 gFlashProgramHeader,                                      
  {
   (tIsrFunc)isr_default,                                  /* 1  (0x00000004) reset       */
   (tIsrFunc)isr_default,                                  /* 2  (0x00000008) NMI         */
   (tIsrFunc)isr_default,                                  /* 3  (0x0000000C) Hard fault  */
   (tIsrFunc)isr_default,                                  /* 4  (0x00000010) MMU         */
   (tIsrFunc)isr_default,                                  /* 5  (0x00000014) Bus fault   */
   (tIsrFunc)isr_default,                                  /* 6  (0x00000018) Usage fault */
   }
};
