/*
 *    kinetis_sysinit.c - Default init routines for
 *                     		Kinetis ARM systems
 *    Copyright © 2010 Freescale semiConductor Inc. All Rights Reserved.
 */
#include <stdint.h>

typedef void (*const tIsrFunc)(void);

typedef struct {
  uint32_t * __ptr;
  tIsrFunc __fun[7];
} tVectorTable;

extern void isr_default(void);
extern uint32_t __stacktop[];
extern uint32_t gFlashProgramHeader[];

#pragma define_section vectortable ".vectortable" far_abs R
static __declspec(vectortable) tVectorTable __vect_table = { /* Interrupt vector table */
  gFlashProgramHeader,                                      /* 0  (0x00000000) (prior: -) */
  {
   (tIsrFunc)isr_default,                                  /* 1  (0x00000004) (prior: -) */
   (tIsrFunc)isr_default,                                  /* 2  (0x00000008) (prior: -2) */
   (tIsrFunc)isr_default,                                  /* 3  (0x0000000C) (prior: -1) */
   (tIsrFunc)isr_default,                                  /* 4  (0x00000010) (prior: -) */
   (tIsrFunc)isr_default,                                  /* 5  (0x00000014) (prior: -) */
   (tIsrFunc)isr_default,                                  /* 6  (0x00000018) (prior: -) */
   (tIsrFunc)isr_default,                                  /* 7  (0x0000001C) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 8  (0x00000020) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 9  (0x00000024) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 10 (0x00000028) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 11 (0x0000002C) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 12 (0x00000030) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 13 (0x00000034) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 14 (0x00000038) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 15 (0x0000003C) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 16 (0x00000040) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 17 (0x00000044) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 18 (0x00000048) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 19 (0x0000004C) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 20 (0x00000050) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 21 (0x00000054) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 22 (0x00000058) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 23 (0x0000005C) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 24 (0x00000060) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 25 (0x00000064) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 26 (0x00000068) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 27 (0x0000006C) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 28 (0x00000070) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 29 (0x00000074) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 30 (0x00000078) (prior: -) */
//   (tIsrFunc)isr_default,                                  /* 31 (0x0000007C) (prior: -) */
   }
};
