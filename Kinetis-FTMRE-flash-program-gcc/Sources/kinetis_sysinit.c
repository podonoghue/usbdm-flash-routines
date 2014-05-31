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
  tIsrFunc __fun[3];
} tVectorTable;

extern void isr_default(void);
extern uint32_t gFlashProgramHeader[];

tVectorTable __vector_table = { /* Interrupt vector table */
 gFlashProgramHeader,                                      // 
  {
   (tIsrFunc)isr_default,                                  //
   (tIsrFunc)isr_default,                                  // NMI
   (tIsrFunc)isr_default,                                  // Hard fault
   }
};
