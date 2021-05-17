/*
 *    kinetis_sysinit.c - Default init routines for
 *                     		Kinetis ARM systems
 *    Copyright (C) 2010 Freescale semiConductor Inc. All Rights Reserved.
 */

#include "stdint.h"
#include "kinetis_sysinit.h"

typedef void (*const tIsrFunc)(void);
typedef struct {
  uint32_t * __ptr;
  tIsrFunc __fun[3];
} tVectorTable;

extern void isr_default(void);
extern uint32_t gFlashProgramHeader[];

tVectorTable __vector_table = { /* Interrupt vector table */
 gFlashProgramHeader,                                      
  {
   (tIsrFunc)isr_default,                                  /* 1  (0x00000004) reset       */
   (tIsrFunc)isr_default,                                  /* 2  (0x00000008) NMI         */
   (tIsrFunc)isr_default,                                  /* 3  (0x0000000C) Hard fault  */
   }
};
