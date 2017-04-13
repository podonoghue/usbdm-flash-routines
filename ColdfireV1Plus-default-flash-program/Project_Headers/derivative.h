/*
 * Note: This file is recreated by the project wizard whenever the MCU is
 *       changed and should not be edited by hand
 */

/* Include the derivative-specific header file */
#include <mcf51ac256a.h>

#define _Stop asm ( mov3q #4,d0; bclr.b d0,SOPT; stop #0x2000; )
  /*!< Macro to enter stop modes, STOPE bit in SOPT register must be set prior to executing this macro */

#define _Wait asm ( mov3q #4,d0; bset.b d0,SOPT; nop; stop #0x2000; )
  /*!< Macro to enter wait mode */


