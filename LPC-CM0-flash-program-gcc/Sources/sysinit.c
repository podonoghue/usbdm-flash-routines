/*
 *    kinetis_sysinit.c - Default init routines for
 *                     		Kinetis ARM systems
 *    Copyright © 2010 Freescale semiConductor Inc. All Rights Reserved.
 */

#include <stdint.h>
#include "sysinit.h"

typedef void (*const tIsrFunc)(void);

typedef struct {
  uint32_t * __ptr;
//  tIsrFunc __fun[6];
} tVectorTable;

extern void isr_default(void);
extern uint32_t __stacktop[];
extern uint32_t gFlashProgramHeader[];

// LPC devices do not support relocates vector table while programming flash
__attribute__ ((section(".interrupt_vectors")))
tVectorTable __vector_table = { /* Interrupt vector table */
 gFlashProgramHeader,                                      /* 0  (0x00000000) (prior: -) */
};
