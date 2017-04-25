/*
  FILE    : kinetis_sysinit.h
  PURPOSE : system initialization header for Kinetis ARM architecture
  LANGUAGE: C
  Copyright © 2010 Freescale semiConductor Inc. All Rights Reserved.
*/
#ifndef KINETIS_SYSINIT_H
#define KINETIS_SYSINIT_H

#ifdef __cplusplus
extern "C" {
#endif

/*
** ===================================================================
**     Method      :  isr_default
**
**     Description :
**         The default ISR.
** ===================================================================
*/
void isr_default(void);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef KINETIS_SYSINIT_H */
