/* Based on CPU DB MC9S08PT60_64, version 3.00.006 (RegistersPrg V2.33) */
/*
** ###################################################################
**     Filename  : mc9s08pt60.h
**     Processor : MC9S08PT60VLH
**     FileFormat: V2.33
**     DataSheet : MC9S08PT60RM Rev. 3 Draft A, 12/2011
**     Compiler  : CodeWarrior compiler
**     Date/Time : 2/2/2012, 4:52 PM
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2012 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 12.1.2012, V3.00.0:
**              - Registers updated according to the new reference manual revision - Rev. 3 Draft A 12/2011
**              - TSI: Added CURSW bit into TSI_CS0 register. 
**              - SPI: Removed DL and ML registers of SPI0. Removed individual bits of Match Registers.
**              - PORT: Changed the bitnames of PORT_IOFLT0/1/2 registers; from FIL<port_name> to FLT<port_name>. Removed PTAPE4 bit.
**              - SYS: Added UUID7/8 registers.
**
**     File-Format-Revisions:
**      - 15.09.2010, V2.33 :
**               - Empty union is not generated for data overlapping registers, cause there is no bit access
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S08PT60_H
#define _MC9S08PT60_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(WDOG_CNT = 0xA602U, WDOG_CNT = 0xB480U)
#endif
#endif /* __RESET_WATCHDOG */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vnvm               39U
#define VectorNumber_Vkbi1              38U
#define VectorNumber_Vkbi0              37U
#define VectorNumber_Vtsi               36U
#define VectorNumber_Vrtc               35U
#define VectorNumber_Viic               34U
#define VectorNumber_Vspi1              33U
#define VectorNumber_Vspi0              32U
#define VectorNumber_Vsci2tx            31U
#define VectorNumber_Vsci2rx            30U
#define VectorNumber_Vsci2err           29U
#define VectorNumber_Vsci1tx            28U
#define VectorNumber_Vsci1rx            27U
#define VectorNumber_Vsci1err           26U
#define VectorNumber_Vsci0tx            25U
#define VectorNumber_Vsci0rx            24U
#define VectorNumber_Vsci0err           23U
#define VectorNumber_Vadc               22U
#define VectorNumber_Vacmp              21U
#define VectorNumber_Vmtim1             20U
#define VectorNumber_Vmtim0             19U
#define VectorNumber_Vftm0ovf           18U
#define VectorNumber_Vftm0ch1           17U
#define VectorNumber_Vftm0ch0           16U
#define VectorNumber_Vftm1ovf           15U
#define VectorNumber_Vftm1ch1           14U
#define VectorNumber_Vftm1ch0           13U
#define VectorNumber_Vftm2ovf           12U
#define VectorNumber_Vftm2ch5           11U
#define VectorNumber_Vftm2ch4           10U
#define VectorNumber_Vftm2ch3           9U
#define VectorNumber_Vftm2ch2           8U
#define VectorNumber_Vftm2ch1           7U
#define VectorNumber_Vftm2ch0           6U
#define VectorNumber_Vftm2flt           5U
#define VectorNumber_Vclk               4U
#define VectorNumber_Vlvw               3U
#define VectorNumber_Virq_wdog          2U
#define VectorNumber_Vswi               1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define Vnvm                            0xFFB0U
#define Vkbi1                           0xFFB2U
#define Vkbi0                           0xFFB4U
#define Vtsi                            0xFFB6U
#define Vrtc                            0xFFB8U
#define Viic                            0xFFBAU
#define Vspi1                           0xFFBCU
#define Vspi0                           0xFFBEU
#define Vsci2tx                         0xFFC0U
#define Vsci2rx                         0xFFC2U
#define Vsci2err                        0xFFC4U
#define Vsci1tx                         0xFFC6U
#define Vsci1rx                         0xFFC8U
#define Vsci1err                        0xFFCAU
#define Vsci0tx                         0xFFCCU
#define Vsci0rx                         0xFFCEU
#define Vsci0err                        0xFFD0U
#define Vadc                            0xFFD2U
#define Vacmp                           0xFFD4U
#define Vmtim1                          0xFFD6U
#define Vmtim0                          0xFFD8U
#define Vftm0ovf                        0xFFDAU
#define Vftm0ch1                        0xFFDCU
#define Vftm0ch0                        0xFFDEU
#define Vftm1ovf                        0xFFE0U
#define Vftm1ch1                        0xFFE2U
#define Vftm1ch0                        0xFFE4U
#define Vftm2ovf                        0xFFE6U
#define Vftm2ch5                        0xFFE8U
#define Vftm2ch4                        0xFFEAU
#define Vftm2ch3                        0xFFECU
#define Vftm2ch2                        0xFFEEU
#define Vftm2ch1                        0xFFF0U
#define Vftm2ch0                        0xFFF2U
#define Vftm2flt                        0xFFF4U
#define Vclk                            0xFFF6U
#define Vlvw                            0xFFF8U
#define Virq_wdog                       0xFFFAU
#define Vswi                            0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PORT_PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1; 
    byte PTAD1       :1; 
    byte PTAD2       :1; 
    byte PTAD3       :1; 
    byte PTAD4       :1; 
    byte PTAD5       :1; 
    byte PTAD6       :1; 
    byte PTAD7       :1; 
  } Bits;
} PORT_PTADSTR;
extern volatile PORT_PTADSTR _PORT_PTAD @0x00000000;
#define PORT_PTAD                       _PORT_PTAD.Byte
#define PORT_PTAD_PTAD0                 _PORT_PTAD.Bits.PTAD0
#define PORT_PTAD_PTAD1                 _PORT_PTAD.Bits.PTAD1
#define PORT_PTAD_PTAD2                 _PORT_PTAD.Bits.PTAD2
#define PORT_PTAD_PTAD3                 _PORT_PTAD.Bits.PTAD3
#define PORT_PTAD_PTAD4                 _PORT_PTAD.Bits.PTAD4
#define PORT_PTAD_PTAD5                 _PORT_PTAD.Bits.PTAD5
#define PORT_PTAD_PTAD6                 _PORT_PTAD.Bits.PTAD6
#define PORT_PTAD_PTAD7                 _PORT_PTAD.Bits.PTAD7

#define PORT_PTAD_PTAD0_MASK            1U
#define PORT_PTAD_PTAD1_MASK            2U
#define PORT_PTAD_PTAD2_MASK            4U
#define PORT_PTAD_PTAD3_MASK            8U
#define PORT_PTAD_PTAD4_MASK            16U
#define PORT_PTAD_PTAD5_MASK            32U
#define PORT_PTAD_PTAD6_MASK            64U
#define PORT_PTAD_PTAD7_MASK            128U


/*** PORT_PTBD - Port B Data Register; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1; 
    byte PTBD1       :1; 
    byte PTBD2       :1; 
    byte PTBD3       :1; 
    byte PTBD4       :1; 
    byte PTBD5       :1; 
    byte PTBD6       :1; 
    byte PTBD7       :1; 
  } Bits;
} PORT_PTBDSTR;
extern volatile PORT_PTBDSTR _PORT_PTBD @0x00000001;
#define PORT_PTBD                       _PORT_PTBD.Byte
#define PORT_PTBD_PTBD0                 _PORT_PTBD.Bits.PTBD0
#define PORT_PTBD_PTBD1                 _PORT_PTBD.Bits.PTBD1
#define PORT_PTBD_PTBD2                 _PORT_PTBD.Bits.PTBD2
#define PORT_PTBD_PTBD3                 _PORT_PTBD.Bits.PTBD3
#define PORT_PTBD_PTBD4                 _PORT_PTBD.Bits.PTBD4
#define PORT_PTBD_PTBD5                 _PORT_PTBD.Bits.PTBD5
#define PORT_PTBD_PTBD6                 _PORT_PTBD.Bits.PTBD6
#define PORT_PTBD_PTBD7                 _PORT_PTBD.Bits.PTBD7

#define PORT_PTBD_PTBD0_MASK            1U
#define PORT_PTBD_PTBD1_MASK            2U
#define PORT_PTBD_PTBD2_MASK            4U
#define PORT_PTBD_PTBD3_MASK            8U
#define PORT_PTBD_PTBD4_MASK            16U
#define PORT_PTBD_PTBD5_MASK            32U
#define PORT_PTBD_PTBD6_MASK            64U
#define PORT_PTBD_PTBD7_MASK            128U


/*** PORT_PTCD - Port C Data Register; 0x00000002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1; 
    byte PTCD1       :1; 
    byte PTCD2       :1; 
    byte PTCD3       :1; 
    byte PTCD4       :1; 
    byte PTCD5       :1; 
    byte PTCD6       :1; 
    byte PTCD7       :1; 
  } Bits;
} PORT_PTCDSTR;
extern volatile PORT_PTCDSTR _PORT_PTCD @0x00000002;
#define PORT_PTCD                       _PORT_PTCD.Byte
#define PORT_PTCD_PTCD0                 _PORT_PTCD.Bits.PTCD0
#define PORT_PTCD_PTCD1                 _PORT_PTCD.Bits.PTCD1
#define PORT_PTCD_PTCD2                 _PORT_PTCD.Bits.PTCD2
#define PORT_PTCD_PTCD3                 _PORT_PTCD.Bits.PTCD3
#define PORT_PTCD_PTCD4                 _PORT_PTCD.Bits.PTCD4
#define PORT_PTCD_PTCD5                 _PORT_PTCD.Bits.PTCD5
#define PORT_PTCD_PTCD6                 _PORT_PTCD.Bits.PTCD6
#define PORT_PTCD_PTCD7                 _PORT_PTCD.Bits.PTCD7

#define PORT_PTCD_PTCD0_MASK            1U
#define PORT_PTCD_PTCD1_MASK            2U
#define PORT_PTCD_PTCD2_MASK            4U
#define PORT_PTCD_PTCD3_MASK            8U
#define PORT_PTCD_PTCD4_MASK            16U
#define PORT_PTCD_PTCD5_MASK            32U
#define PORT_PTCD_PTCD6_MASK            64U
#define PORT_PTCD_PTCD7_MASK            128U


/*** PORT_PTDD - Port D Data Register; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDD0       :1; 
    byte PTDD1       :1; 
    byte PTDD2       :1; 
    byte PTDD3       :1; 
    byte PTDD4       :1; 
    byte PTDD5       :1; 
    byte PTDD6       :1; 
    byte PTDD7       :1; 
  } Bits;
} PORT_PTDDSTR;
extern volatile PORT_PTDDSTR _PORT_PTDD @0x00000003;
#define PORT_PTDD                       _PORT_PTDD.Byte
#define PORT_PTDD_PTDD0                 _PORT_PTDD.Bits.PTDD0
#define PORT_PTDD_PTDD1                 _PORT_PTDD.Bits.PTDD1
#define PORT_PTDD_PTDD2                 _PORT_PTDD.Bits.PTDD2
#define PORT_PTDD_PTDD3                 _PORT_PTDD.Bits.PTDD3
#define PORT_PTDD_PTDD4                 _PORT_PTDD.Bits.PTDD4
#define PORT_PTDD_PTDD5                 _PORT_PTDD.Bits.PTDD5
#define PORT_PTDD_PTDD6                 _PORT_PTDD.Bits.PTDD6
#define PORT_PTDD_PTDD7                 _PORT_PTDD.Bits.PTDD7

#define PORT_PTDD_PTDD0_MASK            1U
#define PORT_PTDD_PTDD1_MASK            2U
#define PORT_PTDD_PTDD2_MASK            4U
#define PORT_PTDD_PTDD3_MASK            8U
#define PORT_PTDD_PTDD4_MASK            16U
#define PORT_PTDD_PTDD5_MASK            32U
#define PORT_PTDD_PTDD6_MASK            64U
#define PORT_PTDD_PTDD7_MASK            128U


/*** PORT_PTED - Port E Data Register; 0x00000004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTED0       :1; 
    byte PTED1       :1; 
    byte PTED2       :1; 
    byte PTED3       :1; 
    byte PTED4       :1; 
    byte PTED5       :1; 
    byte PTED6       :1; 
    byte PTED7       :1; 
  } Bits;
} PORT_PTEDSTR;
extern volatile PORT_PTEDSTR _PORT_PTED @0x00000004;
#define PORT_PTED                       _PORT_PTED.Byte
#define PORT_PTED_PTED0                 _PORT_PTED.Bits.PTED0
#define PORT_PTED_PTED1                 _PORT_PTED.Bits.PTED1
#define PORT_PTED_PTED2                 _PORT_PTED.Bits.PTED2
#define PORT_PTED_PTED3                 _PORT_PTED.Bits.PTED3
#define PORT_PTED_PTED4                 _PORT_PTED.Bits.PTED4
#define PORT_PTED_PTED5                 _PORT_PTED.Bits.PTED5
#define PORT_PTED_PTED6                 _PORT_PTED.Bits.PTED6
#define PORT_PTED_PTED7                 _PORT_PTED.Bits.PTED7

#define PORT_PTED_PTED0_MASK            1U
#define PORT_PTED_PTED1_MASK            2U
#define PORT_PTED_PTED2_MASK            4U
#define PORT_PTED_PTED3_MASK            8U
#define PORT_PTED_PTED4_MASK            16U
#define PORT_PTED_PTED5_MASK            32U
#define PORT_PTED_PTED6_MASK            64U
#define PORT_PTED_PTED7_MASK            128U


/*** PORT_PTFD - Port F Data Register; 0x00000005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFD0       :1; 
    byte PTFD1       :1; 
    byte PTFD2       :1; 
    byte PTFD3       :1; 
    byte PTFD4       :1; 
    byte PTFD5       :1; 
    byte PTFD6       :1; 
    byte PTFD7       :1; 
  } Bits;
} PORT_PTFDSTR;
extern volatile PORT_PTFDSTR _PORT_PTFD @0x00000005;
#define PORT_PTFD                       _PORT_PTFD.Byte
#define PORT_PTFD_PTFD0                 _PORT_PTFD.Bits.PTFD0
#define PORT_PTFD_PTFD1                 _PORT_PTFD.Bits.PTFD1
#define PORT_PTFD_PTFD2                 _PORT_PTFD.Bits.PTFD2
#define PORT_PTFD_PTFD3                 _PORT_PTFD.Bits.PTFD3
#define PORT_PTFD_PTFD4                 _PORT_PTFD.Bits.PTFD4
#define PORT_PTFD_PTFD5                 _PORT_PTFD.Bits.PTFD5
#define PORT_PTFD_PTFD6                 _PORT_PTFD.Bits.PTFD6
#define PORT_PTFD_PTFD7                 _PORT_PTFD.Bits.PTFD7

#define PORT_PTFD_PTFD0_MASK            1U
#define PORT_PTFD_PTFD1_MASK            2U
#define PORT_PTFD_PTFD2_MASK            4U
#define PORT_PTFD_PTFD3_MASK            8U
#define PORT_PTFD_PTFD4_MASK            16U
#define PORT_PTFD_PTFD5_MASK            32U
#define PORT_PTFD_PTFD6_MASK            64U
#define PORT_PTFD_PTFD7_MASK            128U


/*** PORT_PTGD - Port G Data Register; 0x00000006 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGD0       :1; 
    byte PTGD1       :1; 
    byte PTGD2       :1; 
    byte PTGD3       :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGD :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PORT_PTGDSTR;
extern volatile PORT_PTGDSTR _PORT_PTGD @0x00000006;
#define PORT_PTGD                       _PORT_PTGD.Byte
#define PORT_PTGD_PTGD0                 _PORT_PTGD.Bits.PTGD0
#define PORT_PTGD_PTGD1                 _PORT_PTGD.Bits.PTGD1
#define PORT_PTGD_PTGD2                 _PORT_PTGD.Bits.PTGD2
#define PORT_PTGD_PTGD3                 _PORT_PTGD.Bits.PTGD3
#define PORT_PTGD_PTGD                  _PORT_PTGD.MergedBits.grpPTGD

#define PORT_PTGD_PTGD0_MASK            1U
#define PORT_PTGD_PTGD1_MASK            2U
#define PORT_PTGD_PTGD2_MASK            4U
#define PORT_PTGD_PTGD3_MASK            8U
#define PORT_PTGD_PTGD_MASK             15U
#define PORT_PTGD_PTGD_BITNUM           0U


/*** PORT_PTHD - Port H Data Register; 0x00000007 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHD0       :1;                                       /* Port H Data Register Bit 0 */
    byte PTHD1       :1;                                       /* Port H Data Register Bit 1 */
    byte PTHD2       :1;                                       /* Port H Data Register Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTHD6       :1;                                       /* Port H Data Register Bit 6 */
    byte PTHD7       :1;                                       /* Port H Data Register Bit 7 */
  } Bits;
  struct {
    byte grpPTHD :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTHD_6 :2;
  } MergedBits;
} PORT_PTHDSTR;
extern volatile PORT_PTHDSTR _PORT_PTHD @0x00000007;
#define PORT_PTHD                       _PORT_PTHD.Byte
#define PORT_PTHD_PTHD0                 _PORT_PTHD.Bits.PTHD0
#define PORT_PTHD_PTHD1                 _PORT_PTHD.Bits.PTHD1
#define PORT_PTHD_PTHD2                 _PORT_PTHD.Bits.PTHD2
#define PORT_PTHD_PTHD6                 _PORT_PTHD.Bits.PTHD6
#define PORT_PTHD_PTHD7                 _PORT_PTHD.Bits.PTHD7
#define PORT_PTHD_PTHD                  _PORT_PTHD.MergedBits.grpPTHD
#define PORT_PTHD_PTHD_6                _PORT_PTHD.MergedBits.grpPTHD_6

#define PORT_PTHD_PTHD0_MASK            1U
#define PORT_PTHD_PTHD1_MASK            2U
#define PORT_PTHD_PTHD2_MASK            4U
#define PORT_PTHD_PTHD6_MASK            64U
#define PORT_PTHD_PTHD7_MASK            128U
#define PORT_PTHD_PTHD_MASK             7U
#define PORT_PTHD_PTHD_BITNUM           0U
#define PORT_PTHD_PTHD_6_MASK           192U
#define PORT_PTHD_PTHD_6_BITNUM         6U


/*** TSI_CS0 - TSI Control and Status Register 0; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte SWTS        :1;                                       /* SWTS */
    byte CURSW       :1;                                       /* CURSW */
    byte EOSF        :1;                                       /* EOSF */
    byte SCNIP       :1;                                       /* SCNIP */
    byte STM         :1;                                       /* STM */
    byte STPE        :1;                                       /* STPE */
    byte TSIIEN      :1;                                       /* TSIIEN */
    byte TSIEN       :1;                                       /* TSIEN */
  } Bits;
} TSI_CS0STR;
extern volatile TSI_CS0STR _TSI_CS0 @0x00000008;
#define TSI_CS0                         _TSI_CS0.Byte
#define TSI_CS0_SWTS                    _TSI_CS0.Bits.SWTS
#define TSI_CS0_CURSW                   _TSI_CS0.Bits.CURSW
#define TSI_CS0_EOSF                    _TSI_CS0.Bits.EOSF
#define TSI_CS0_SCNIP                   _TSI_CS0.Bits.SCNIP
#define TSI_CS0_STM                     _TSI_CS0.Bits.STM
#define TSI_CS0_STPE                    _TSI_CS0.Bits.STPE
#define TSI_CS0_TSIIEN                  _TSI_CS0.Bits.TSIIEN
#define TSI_CS0_TSIEN                   _TSI_CS0.Bits.TSIEN
/* TSI_CS_ARR: Access 4 TSI_CSx registers in an array */
#define TSI_CS_ARR                      ((volatile byte * __far) &TSI_CS0)

#define TSI_CS0_SWTS_MASK               1U
#define TSI_CS0_CURSW_MASK              2U
#define TSI_CS0_EOSF_MASK               4U
#define TSI_CS0_SCNIP_MASK              8U
#define TSI_CS0_STM_MASK                16U
#define TSI_CS0_STPE_MASK               32U
#define TSI_CS0_TSIIEN_MASK             64U
#define TSI_CS0_TSIEN_MASK              128U


/*** TSI_CS1 - TSI Control and Status Register 1; 0x00000009 ***/
typedef union {
  byte Byte;
  struct {
    byte NSCN0       :1;                                       /* NSCN, bit 0 */
    byte NSCN1       :1;                                       /* NSCN, bit 1 */
    byte NSCN2       :1;                                       /* NSCN, bit 2 */
    byte NSCN3       :1;                                       /* NSCN, bit 3 */
    byte NSCN4       :1;                                       /* NSCN, bit 4 */
    byte PS0         :1;                                       /* PS, bit 0 */
    byte PS1         :1;                                       /* PS, bit 1 */
    byte PS2         :1;                                       /* PS, bit 2 */
  } Bits;
  struct {
    byte grpNSCN :5;
    byte grpPS   :3;
  } MergedBits;
} TSI_CS1STR;
extern volatile TSI_CS1STR _TSI_CS1 @0x00000009;
#define TSI_CS1                         _TSI_CS1.Byte
#define TSI_CS1_NSCN0                   _TSI_CS1.Bits.NSCN0
#define TSI_CS1_NSCN1                   _TSI_CS1.Bits.NSCN1
#define TSI_CS1_NSCN2                   _TSI_CS1.Bits.NSCN2
#define TSI_CS1_NSCN3                   _TSI_CS1.Bits.NSCN3
#define TSI_CS1_NSCN4                   _TSI_CS1.Bits.NSCN4
#define TSI_CS1_PS0                     _TSI_CS1.Bits.PS0
#define TSI_CS1_PS1                     _TSI_CS1.Bits.PS1
#define TSI_CS1_PS2                     _TSI_CS1.Bits.PS2
#define TSI_CS1_NSCN                    _TSI_CS1.MergedBits.grpNSCN
#define TSI_CS1_PS                      _TSI_CS1.MergedBits.grpPS

#define TSI_CS1_NSCN0_MASK              1U
#define TSI_CS1_NSCN1_MASK              2U
#define TSI_CS1_NSCN2_MASK              4U
#define TSI_CS1_NSCN3_MASK              8U
#define TSI_CS1_NSCN4_MASK              16U
#define TSI_CS1_PS0_MASK                32U
#define TSI_CS1_PS1_MASK                64U
#define TSI_CS1_PS2_MASK                128U
#define TSI_CS1_NSCN_MASK               31U
#define TSI_CS1_NSCN_BITNUM             0U
#define TSI_CS1_PS_MASK                 224U
#define TSI_CS1_PS_BITNUM               5U


/*** TSI_CS2 - TSI Control and Status Register 2; 0x0000000A ***/
typedef union {
  byte Byte;
  struct {
    byte EXTCHRG0    :1;                                       /* EXTCHRG, bit 0 */
    byte EXTCHRG1    :1;                                       /* EXTCHRG, bit 1 */
    byte EXTCHRG2    :1;                                       /* EXTCHRG, bit 2 */
    byte DVOLT0      :1;                                       /* DVOLT, bit 0 */
    byte DVOLT1      :1;                                       /* DVOLT, bit 1 */
    byte REFCHRG0    :1;                                       /* REFCHRG, bit 0 */
    byte REFCHRG1    :1;                                       /* REFCHRG, bit 1 */
    byte REFCHRG2    :1;                                       /* REFCHRG, bit 2 */
  } Bits;
  struct {
    byte grpEXTCHRG :3;
    byte grpDVOLT :2;
    byte grpREFCHRG :3;
  } MergedBits;
} TSI_CS2STR;
extern volatile TSI_CS2STR _TSI_CS2 @0x0000000A;
#define TSI_CS2                         _TSI_CS2.Byte
#define TSI_CS2_EXTCHRG0                _TSI_CS2.Bits.EXTCHRG0
#define TSI_CS2_EXTCHRG1                _TSI_CS2.Bits.EXTCHRG1
#define TSI_CS2_EXTCHRG2                _TSI_CS2.Bits.EXTCHRG2
#define TSI_CS2_DVOLT0                  _TSI_CS2.Bits.DVOLT0
#define TSI_CS2_DVOLT1                  _TSI_CS2.Bits.DVOLT1
#define TSI_CS2_REFCHRG0                _TSI_CS2.Bits.REFCHRG0
#define TSI_CS2_REFCHRG1                _TSI_CS2.Bits.REFCHRG1
#define TSI_CS2_REFCHRG2                _TSI_CS2.Bits.REFCHRG2
#define TSI_CS2_EXTCHRG                 _TSI_CS2.MergedBits.grpEXTCHRG
#define TSI_CS2_DVOLT                   _TSI_CS2.MergedBits.grpDVOLT
#define TSI_CS2_REFCHRG                 _TSI_CS2.MergedBits.grpREFCHRG

#define TSI_CS2_EXTCHRG0_MASK           1U
#define TSI_CS2_EXTCHRG1_MASK           2U
#define TSI_CS2_EXTCHRG2_MASK           4U
#define TSI_CS2_DVOLT0_MASK             8U
#define TSI_CS2_DVOLT1_MASK             16U
#define TSI_CS2_REFCHRG0_MASK           32U
#define TSI_CS2_REFCHRG1_MASK           64U
#define TSI_CS2_REFCHRG2_MASK           128U
#define TSI_CS2_EXTCHRG_MASK            7U
#define TSI_CS2_EXTCHRG_BITNUM          0U
#define TSI_CS2_DVOLT_MASK              24U
#define TSI_CS2_DVOLT_BITNUM            3U
#define TSI_CS2_REFCHRG_MASK            224U
#define TSI_CS2_REFCHRG_BITNUM          5U


/*** TSI_CS3 - TSI Control and Status Register 3; 0x0000000B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TSICH0      :1;                                       /* TSICH, bit 0 */
    byte TSICH1      :1;                                       /* TSICH, bit 1 */
    byte TSICH2      :1;                                       /* TSICH, bit 2 */
    byte TSICH3      :1;                                       /* TSICH, bit 3 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTSICH :4;
  } MergedBits;
} TSI_CS3STR;
extern volatile TSI_CS3STR _TSI_CS3 @0x0000000B;
#define TSI_CS3                         _TSI_CS3.Byte
#define TSI_CS3_TSICH0                  _TSI_CS3.Bits.TSICH0
#define TSI_CS3_TSICH1                  _TSI_CS3.Bits.TSICH1
#define TSI_CS3_TSICH2                  _TSI_CS3.Bits.TSICH2
#define TSI_CS3_TSICH3                  _TSI_CS3.Bits.TSICH3
#define TSI_CS3_TSICH                   _TSI_CS3.MergedBits.grpTSICH

#define TSI_CS3_TSICH0_MASK             16U
#define TSI_CS3_TSICH1_MASK             32U
#define TSI_CS3_TSICH2_MASK             64U
#define TSI_CS3_TSICH3_MASK             128U
#define TSI_CS3_TSICH_MASK              240U
#define TSI_CS3_TSICH_BITNUM            4U


/*** TSI_PEN0 - TSI Pin Enable Register 0; 0x0000000C ***/
typedef union {
  byte Byte;
  struct {
    byte PEN0        :1;                                       /* PEN0 */
    byte PEN1        :1;                                       /* PEN1 */
    byte PEN2        :1;                                       /* PEN2 */
    byte PEN3        :1;                                       /* PEN3 */
    byte PEN4        :1;                                       /* PEN4 */
    byte PEN5        :1;                                       /* PEN5 */
    byte PEN6        :1;                                       /* PEN6 */
    byte PEN7        :1;                                       /* PEN7 */
  } Bits;
} TSI_PEN0STR;
extern volatile TSI_PEN0STR _TSI_PEN0 @0x0000000C;
#define TSI_PEN0                        _TSI_PEN0.Byte
#define TSI_PEN0_PEN0                   _TSI_PEN0.Bits.PEN0
#define TSI_PEN0_PEN1                   _TSI_PEN0.Bits.PEN1
#define TSI_PEN0_PEN2                   _TSI_PEN0.Bits.PEN2
#define TSI_PEN0_PEN3                   _TSI_PEN0.Bits.PEN3
#define TSI_PEN0_PEN4                   _TSI_PEN0.Bits.PEN4
#define TSI_PEN0_PEN5                   _TSI_PEN0.Bits.PEN5
#define TSI_PEN0_PEN6                   _TSI_PEN0.Bits.PEN6
#define TSI_PEN0_PEN7                   _TSI_PEN0.Bits.PEN7
/* TSI_PEN_ARR: Access 2 TSI_PENx registers in an array */
#define TSI_PEN_ARR                     ((volatile byte * __far) &TSI_PEN0)

#define TSI_PEN0_PEN0_MASK              1U
#define TSI_PEN0_PEN1_MASK              2U
#define TSI_PEN0_PEN2_MASK              4U
#define TSI_PEN0_PEN3_MASK              8U
#define TSI_PEN0_PEN4_MASK              16U
#define TSI_PEN0_PEN5_MASK              32U
#define TSI_PEN0_PEN6_MASK              64U
#define TSI_PEN0_PEN7_MASK              128U


/*** TSI_PEN1 - TSI Pin Enable Register 1; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte PEN8        :1;                                       /* PEN8 */
    byte PEN9        :1;                                       /* PEN9 */
    byte PEN10       :1;                                       /* PEN10 */
    byte PEN11       :1;                                       /* PEN11 */
    byte PEN12       :1;                                       /* PEN12 */
    byte PEN13       :1;                                       /* PEN13 */
    byte PEN14       :1;                                       /* PEN14 */
    byte PEN15       :1;                                       /* PEN15 */
  } Bits;
} TSI_PEN1STR;
extern volatile TSI_PEN1STR _TSI_PEN1 @0x0000000D;
#define TSI_PEN1                        _TSI_PEN1.Byte
#define TSI_PEN1_PEN8                   _TSI_PEN1.Bits.PEN8
#define TSI_PEN1_PEN9                   _TSI_PEN1.Bits.PEN9
#define TSI_PEN1_PEN10                  _TSI_PEN1.Bits.PEN10
#define TSI_PEN1_PEN11                  _TSI_PEN1.Bits.PEN11
#define TSI_PEN1_PEN12                  _TSI_PEN1.Bits.PEN12
#define TSI_PEN1_PEN13                  _TSI_PEN1.Bits.PEN13
#define TSI_PEN1_PEN14                  _TSI_PEN1.Bits.PEN14
#define TSI_PEN1_PEN15                  _TSI_PEN1.Bits.PEN15

#define TSI_PEN1_PEN8_MASK              1U
#define TSI_PEN1_PEN9_MASK              2U
#define TSI_PEN1_PEN10_MASK             4U
#define TSI_PEN1_PEN11_MASK             8U
#define TSI_PEN1_PEN12_MASK             16U
#define TSI_PEN1_PEN13_MASK             32U
#define TSI_PEN1_PEN14_MASK             64U
#define TSI_PEN1_PEN15_MASK             128U


/*** TSI_CNT - TSI Counter Register; 0x0000000E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TSI_CNTH - TSI Counter Register: High; 0x0000000E ***/
    union {
      byte Byte;
      struct {
        byte CNTH0       :1;                                       /* CNTH, bit 0 */
        byte CNTH1       :1;                                       /* CNTH, bit 1 */
        byte CNTH2       :1;                                       /* CNTH, bit 2 */
        byte CNTH3       :1;                                       /* CNTH, bit 3 */
        byte CNTH4       :1;                                       /* CNTH, bit 4 */
        byte CNTH5       :1;                                       /* CNTH, bit 5 */
        byte CNTH6       :1;                                       /* CNTH, bit 6 */
        byte CNTH7       :1;                                       /* CNTH, bit 7 */
      } Bits;
    } TSI_CNTHSTR;
    #define TSI_CNTH                    _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Byte
    #define TSI_CNTH_CNTH0              _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Bits.CNTH0
    #define TSI_CNTH_CNTH1              _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Bits.CNTH1
    #define TSI_CNTH_CNTH2              _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Bits.CNTH2
    #define TSI_CNTH_CNTH3              _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Bits.CNTH3
    #define TSI_CNTH_CNTH4              _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Bits.CNTH4
    #define TSI_CNTH_CNTH5              _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Bits.CNTH5
    #define TSI_CNTH_CNTH6              _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Bits.CNTH6
    #define TSI_CNTH_CNTH7              _TSI_CNT.Overlap_STR.TSI_CNTHSTR.Bits.CNTH7
    
    #define TSI_CNTH_CNTH0_MASK         1U
    #define TSI_CNTH_CNTH1_MASK         2U
    #define TSI_CNTH_CNTH2_MASK         4U
    #define TSI_CNTH_CNTH3_MASK         8U
    #define TSI_CNTH_CNTH4_MASK         16U
    #define TSI_CNTH_CNTH5_MASK         32U
    #define TSI_CNTH_CNTH6_MASK         64U
    #define TSI_CNTH_CNTH7_MASK         128U
    

    /*** TSI_CNTL - TSI Counter Register: Low; 0x0000000F ***/
    union {
      byte Byte;
      struct {
        byte CNTL0       :1;                                       /* CNTL, bit 0 */
        byte CNTL1       :1;                                       /* CNTL, bit 1 */
        byte CNTL2       :1;                                       /* CNTL, bit 2 */
        byte CNTL3       :1;                                       /* CNTL, bit 3 */
        byte CNTL4       :1;                                       /* CNTL, bit 4 */
        byte CNTL5       :1;                                       /* CNTL, bit 5 */
        byte CNTL6       :1;                                       /* CNTL, bit 6 */
        byte CNTL7       :1;                                       /* CNTL, bit 7 */
      } Bits;
    } TSI_CNTLSTR;
    #define TSI_CNTL                    _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Byte
    #define TSI_CNTL_CNTL0              _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Bits.CNTL0
    #define TSI_CNTL_CNTL1              _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Bits.CNTL1
    #define TSI_CNTL_CNTL2              _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Bits.CNTL2
    #define TSI_CNTL_CNTL3              _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Bits.CNTL3
    #define TSI_CNTL_CNTL4              _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Bits.CNTL4
    #define TSI_CNTL_CNTL5              _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Bits.CNTL5
    #define TSI_CNTL_CNTL6              _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Bits.CNTL6
    #define TSI_CNTL_CNTL7              _TSI_CNT.Overlap_STR.TSI_CNTLSTR.Bits.CNTL7
    
    #define TSI_CNTL_CNTL0_MASK         1U
    #define TSI_CNTL_CNTL1_MASK         2U
    #define TSI_CNTL_CNTL2_MASK         4U
    #define TSI_CNTL_CNTL3_MASK         8U
    #define TSI_CNTL_CNTL4_MASK         16U
    #define TSI_CNTL_CNTL5_MASK         32U
    #define TSI_CNTL_CNTL6_MASK         64U
    #define TSI_CNTL_CNTL7_MASK         128U
    
  } Overlap_STR;

} TSI_CNTSTR;
extern volatile TSI_CNTSTR _TSI_CNT @0x0000000E;
#define TSI_CNT                         _TSI_CNT.Word


/*** ADC_SC1 - Status and Control Register 1; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCH0       :1;                                       /* Input Channel Select, bit 0 */
    byte ADCH1       :1;                                       /* Input Channel Select, bit 1 */
    byte ADCH2       :1;                                       /* Input Channel Select, bit 2 */
    byte ADCH3       :1;                                       /* Input Channel Select, bit 3 */
    byte ADCH4       :1;                                       /* Input Channel Select, bit 4 */
    byte ADCO        :1;                                       /* Continuous Conversion Enable */
    byte AIEN        :1;                                       /* Interrupt Enable */
    byte COCO        :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADC_SC1STR;
extern volatile ADC_SC1STR _ADC_SC1 @0x00000010;
#define ADC_SC1                         _ADC_SC1.Byte
#define ADC_SC1_ADCH0                   _ADC_SC1.Bits.ADCH0
#define ADC_SC1_ADCH1                   _ADC_SC1.Bits.ADCH1
#define ADC_SC1_ADCH2                   _ADC_SC1.Bits.ADCH2
#define ADC_SC1_ADCH3                   _ADC_SC1.Bits.ADCH3
#define ADC_SC1_ADCH4                   _ADC_SC1.Bits.ADCH4
#define ADC_SC1_ADCO                    _ADC_SC1.Bits.ADCO
#define ADC_SC1_AIEN                    _ADC_SC1.Bits.AIEN
#define ADC_SC1_COCO                    _ADC_SC1.Bits.COCO
#define ADC_SC1_ADCH                    _ADC_SC1.MergedBits.grpADCH

#define ADC_SC1_ADCH0_MASK              1U
#define ADC_SC1_ADCH1_MASK              2U
#define ADC_SC1_ADCH2_MASK              4U
#define ADC_SC1_ADCH3_MASK              8U
#define ADC_SC1_ADCH4_MASK              16U
#define ADC_SC1_ADCO_MASK               32U
#define ADC_SC1_AIEN_MASK               64U
#define ADC_SC1_COCO_MASK               128U
#define ADC_SC1_ADCH_MASK               31U
#define ADC_SC1_ADCH_BITNUM             0U


/*** ADC_SC2 - Status and Control Register 2; 0x00000011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FFULL       :1;                                       /* Result FIFO full */
    byte FEMPTY      :1;                                       /* Result FIFO empty */
    byte ACFGT       :1;                                       /* Compare Function Greater Than Enable */
    byte ACFE        :1;                                       /* Compare Function Enable */
    byte ADTRG       :1;                                       /* Conversion Trigger Select */
    byte ADACT       :1;                                       /* Conversion Active */
  } Bits;
} ADC_SC2STR;
extern volatile ADC_SC2STR _ADC_SC2 @0x00000011;
#define ADC_SC2                         _ADC_SC2.Byte
#define ADC_SC2_FFULL                   _ADC_SC2.Bits.FFULL
#define ADC_SC2_FEMPTY                  _ADC_SC2.Bits.FEMPTY
#define ADC_SC2_ACFGT                   _ADC_SC2.Bits.ACFGT
#define ADC_SC2_ACFE                    _ADC_SC2.Bits.ACFE
#define ADC_SC2_ADTRG                   _ADC_SC2.Bits.ADTRG
#define ADC_SC2_ADACT                   _ADC_SC2.Bits.ADACT

#define ADC_SC2_FFULL_MASK              4U
#define ADC_SC2_FEMPTY_MASK             8U
#define ADC_SC2_ACFGT_MASK              16U
#define ADC_SC2_ACFE_MASK               32U
#define ADC_SC2_ADTRG_MASK              64U
#define ADC_SC2_ADACT_MASK              128U


/*** ADC_SC3 - Status and Control Register 3; 0x00000012 ***/
typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       /* Input Clock Select, bit 0 */
    byte ADICLK1     :1;                                       /* Input Clock Select, bit 1 */
    byte MODE0       :1;                                       /* Conversion Mode Selection, bit 0 */
    byte MODE1       :1;                                       /* Conversion Mode Selection, bit 1 */
    byte ADLSMP      :1;                                       /* Long Sample Time Configuration */
    byte ADIV0       :1;                                       /* Clock Divide Select, bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select, bit 1 */
    byte ADLPC       :1;                                       /* Low-Power Configuration */
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADC_SC3STR;
extern volatile ADC_SC3STR _ADC_SC3 @0x00000012;
#define ADC_SC3                         _ADC_SC3.Byte
#define ADC_SC3_ADICLK0                 _ADC_SC3.Bits.ADICLK0
#define ADC_SC3_ADICLK1                 _ADC_SC3.Bits.ADICLK1
#define ADC_SC3_MODE0                   _ADC_SC3.Bits.MODE0
#define ADC_SC3_MODE1                   _ADC_SC3.Bits.MODE1
#define ADC_SC3_ADLSMP                  _ADC_SC3.Bits.ADLSMP
#define ADC_SC3_ADIV0                   _ADC_SC3.Bits.ADIV0
#define ADC_SC3_ADIV1                   _ADC_SC3.Bits.ADIV1
#define ADC_SC3_ADLPC                   _ADC_SC3.Bits.ADLPC
#define ADC_SC3_ADICLK                  _ADC_SC3.MergedBits.grpADICLK
#define ADC_SC3_MODE                    _ADC_SC3.MergedBits.grpMODE
#define ADC_SC3_ADIV                    _ADC_SC3.MergedBits.grpADIV

#define ADC_SC3_ADICLK0_MASK            1U
#define ADC_SC3_ADICLK1_MASK            2U
#define ADC_SC3_MODE0_MASK              4U
#define ADC_SC3_MODE1_MASK              8U
#define ADC_SC3_ADLSMP_MASK             16U
#define ADC_SC3_ADIV0_MASK              32U
#define ADC_SC3_ADIV1_MASK              64U
#define ADC_SC3_ADLPC_MASK              128U
#define ADC_SC3_ADICLK_MASK             3U
#define ADC_SC3_ADICLK_BITNUM           0U
#define ADC_SC3_MODE_MASK               12U
#define ADC_SC3_MODE_BITNUM             2U
#define ADC_SC3_ADIV_MASK               96U
#define ADC_SC3_ADIV_BITNUM             5U


/*** ADC_SC4 - Status and Control Register 4; 0x00000013 ***/
typedef union {
  byte Byte;
  struct {
    byte AFDEP0      :1;                                       /* FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared, the FIFO is disabled. When AFDEP is set to nonzero, the FIFO function is enabled and the depth is indicated by the AFDEP bits. The ADCH in ADCSC1 and ADCRH:ADCRL must be accessed by FIFO mode when FIFO function is enabled. ADC starts conversion when the analog channel FIFO is upon the level indicated by AFDEP bits. The COCO bit is set when the set of conversions are completed and the result FIFO is upon the level indicated by AFDEP bits, bit 0 */
    byte AFDEP1      :1;                                       /* FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared, the FIFO is disabled. When AFDEP is set to nonzero, the FIFO function is enabled and the depth is indicated by the AFDEP bits. The ADCH in ADCSC1 and ADCRH:ADCRL must be accessed by FIFO mode when FIFO function is enabled. ADC starts conversion when the analog channel FIFO is upon the level indicated by AFDEP bits. The COCO bit is set when the set of conversions are completed and the result FIFO is upon the level indicated by AFDEP bits, bit 1 */
    byte AFDEP2      :1;                                       /* FIFO Depth enables the FIFO function and sets the depth of FIFO. When AFDEP is cleared, the FIFO is disabled. When AFDEP is set to nonzero, the FIFO function is enabled and the depth is indicated by the AFDEP bits. The ADCH in ADCSC1 and ADCRH:ADCRL must be accessed by FIFO mode when FIFO function is enabled. ADC starts conversion when the analog channel FIFO is upon the level indicated by AFDEP bits. The COCO bit is set when the set of conversions are completed and the result FIFO is upon the level indicated by AFDEP bits, bit 2 */
    byte             :1; 
    byte             :1; 
    byte ACFSEL      :1;                                       /* Compare function select OR/AND when the FIFO function is enabled (AFDEP > 0) .When this bit is cleared, ADC will OR all of compare triggers and set COCO after at least one of compare trigger occurs. When this bit is set, ADC will AND all of compare triggers and set COCO after all of compare tiggers occur */
    byte ASCANE      :1;                                       /* FIFO Scan Mode Enable */
    byte             :1; 
  } Bits;
  struct {
    byte grpAFDEP :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADC_SC4STR;
extern volatile ADC_SC4STR _ADC_SC4 @0x00000013;
#define ADC_SC4                         _ADC_SC4.Byte
#define ADC_SC4_AFDEP0                  _ADC_SC4.Bits.AFDEP0
#define ADC_SC4_AFDEP1                  _ADC_SC4.Bits.AFDEP1
#define ADC_SC4_AFDEP2                  _ADC_SC4.Bits.AFDEP2
#define ADC_SC4_ACFSEL                  _ADC_SC4.Bits.ACFSEL
#define ADC_SC4_ASCANE                  _ADC_SC4.Bits.ASCANE
#define ADC_SC4_AFDEP                   _ADC_SC4.MergedBits.grpAFDEP

#define ADC_SC4_AFDEP0_MASK             1U
#define ADC_SC4_AFDEP1_MASK             2U
#define ADC_SC4_AFDEP2_MASK             4U
#define ADC_SC4_ACFSEL_MASK             32U
#define ADC_SC4_ASCANE_MASK             64U
#define ADC_SC4_AFDEP_MASK              7U
#define ADC_SC4_AFDEP_BITNUM            0U


/*** ADC_R - Data Result Register; 0x00000014 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC_RH - Conversion Result High Register; 0x00000014 ***/
    union {
      byte Byte;
      struct {
        byte ADR0        :1;                                       /* Conversion Result[15:8], bit 0 */
        byte ADR1        :1;                                       /* Conversion Result[15:8], bit 1 */
        byte ADR2        :1;                                       /* Conversion Result[15:8], bit 2 */
        byte ADR3        :1;                                       /* Conversion Result[15:8], bit 3 */
        byte ADR4        :1;                                       /* Conversion Result[15:8], bit 4 */
        byte ADR5        :1;                                       /* Conversion Result[15:8], bit 5 */
        byte ADR6        :1;                                       /* Conversion Result[15:8], bit 6 */
        byte ADR7        :1;                                       /* Conversion Result[15:8], bit 7 */
      } Bits;
    } ADC_RHSTR;
    #define ADC_RH                      _ADC_R.Overlap_STR.ADC_RHSTR.Byte
    #define ADC_RH_ADR0                 _ADC_R.Overlap_STR.ADC_RHSTR.Bits.ADR0
    #define ADC_RH_ADR1                 _ADC_R.Overlap_STR.ADC_RHSTR.Bits.ADR1
    #define ADC_RH_ADR2                 _ADC_R.Overlap_STR.ADC_RHSTR.Bits.ADR2
    #define ADC_RH_ADR3                 _ADC_R.Overlap_STR.ADC_RHSTR.Bits.ADR3
    #define ADC_RH_ADR4                 _ADC_R.Overlap_STR.ADC_RHSTR.Bits.ADR4
    #define ADC_RH_ADR5                 _ADC_R.Overlap_STR.ADC_RHSTR.Bits.ADR5
    #define ADC_RH_ADR6                 _ADC_R.Overlap_STR.ADC_RHSTR.Bits.ADR6
    #define ADC_RH_ADR7                 _ADC_R.Overlap_STR.ADC_RHSTR.Bits.ADR7
    
    #define ADC_RH_ADR0_MASK            1U
    #define ADC_RH_ADR1_MASK            2U
    #define ADC_RH_ADR2_MASK            4U
    #define ADC_RH_ADR3_MASK            8U
    #define ADC_RH_ADR4_MASK            16U
    #define ADC_RH_ADR5_MASK            32U
    #define ADC_RH_ADR6_MASK            64U
    #define ADC_RH_ADR7_MASK            128U
    

    /*** ADC_RL - Conversion Result Low Register; 0x00000015 ***/
    union {
      byte Byte;
      struct {
        byte ADR0        :1;                                       /* Conversion Result[7:0], bit 0 */
        byte ADR1        :1;                                       /* Conversion Result[7:0], bit 1 */
        byte ADR2        :1;                                       /* Conversion Result[7:0], bit 2 */
        byte ADR3        :1;                                       /* Conversion Result[7:0], bit 3 */
        byte ADR4        :1;                                       /* Conversion Result[7:0], bit 4 */
        byte ADR5        :1;                                       /* Conversion Result[7:0], bit 5 */
        byte ADR6        :1;                                       /* Conversion Result[7:0], bit 6 */
        byte ADR7        :1;                                       /* Conversion Result[7:0], bit 7 */
      } Bits;
    } ADC_RLSTR;
    #define ADC_RL                      _ADC_R.Overlap_STR.ADC_RLSTR.Byte
    #define ADC_RL_ADR0                 _ADC_R.Overlap_STR.ADC_RLSTR.Bits.ADR0
    #define ADC_RL_ADR1                 _ADC_R.Overlap_STR.ADC_RLSTR.Bits.ADR1
    #define ADC_RL_ADR2                 _ADC_R.Overlap_STR.ADC_RLSTR.Bits.ADR2
    #define ADC_RL_ADR3                 _ADC_R.Overlap_STR.ADC_RLSTR.Bits.ADR3
    #define ADC_RL_ADR4                 _ADC_R.Overlap_STR.ADC_RLSTR.Bits.ADR4
    #define ADC_RL_ADR5                 _ADC_R.Overlap_STR.ADC_RLSTR.Bits.ADR5
    #define ADC_RL_ADR6                 _ADC_R.Overlap_STR.ADC_RLSTR.Bits.ADR6
    #define ADC_RL_ADR7                 _ADC_R.Overlap_STR.ADC_RLSTR.Bits.ADR7
    
    #define ADC_RL_ADR0_MASK            1U
    #define ADC_RL_ADR1_MASK            2U
    #define ADC_RL_ADR2_MASK            4U
    #define ADC_RL_ADR3_MASK            8U
    #define ADC_RL_ADR4_MASK            16U
    #define ADC_RL_ADR5_MASK            32U
    #define ADC_RL_ADR6_MASK            64U
    #define ADC_RL_ADR7_MASK            128U
    
  } Overlap_STR;

} ADC_RSTR;
extern volatile ADC_RSTR _ADC_R @0x00000014;
#define ADC_R                           _ADC_R.Word


/*** ADC_CV - Compare Value Register; 0x00000016 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC_CVH - Compare Value High Register; 0x00000016 ***/
    union {
      byte Byte;
      struct {
        byte CV0         :1;                                       /* Conversion Result[15:8], bit 0 */
        byte CV1         :1;                                       /* Conversion Result[15:8], bit 1 */
        byte CV2         :1;                                       /* Conversion Result[15:8], bit 2 */
        byte CV3         :1;                                       /* Conversion Result[15:8], bit 3 */
        byte CV4         :1;                                       /* Conversion Result[15:8], bit 4 */
        byte CV5         :1;                                       /* Conversion Result[15:8], bit 5 */
        byte CV6         :1;                                       /* Conversion Result[15:8], bit 6 */
        byte CV7         :1;                                       /* Conversion Result[15:8], bit 7 */
      } Bits;
    } ADC_CVHSTR;
    #define ADC_CVH                     _ADC_CV.Overlap_STR.ADC_CVHSTR.Byte
    #define ADC_CVH_CV0                 _ADC_CV.Overlap_STR.ADC_CVHSTR.Bits.CV0
    #define ADC_CVH_CV1                 _ADC_CV.Overlap_STR.ADC_CVHSTR.Bits.CV1
    #define ADC_CVH_CV2                 _ADC_CV.Overlap_STR.ADC_CVHSTR.Bits.CV2
    #define ADC_CVH_CV3                 _ADC_CV.Overlap_STR.ADC_CVHSTR.Bits.CV3
    #define ADC_CVH_CV4                 _ADC_CV.Overlap_STR.ADC_CVHSTR.Bits.CV4
    #define ADC_CVH_CV5                 _ADC_CV.Overlap_STR.ADC_CVHSTR.Bits.CV5
    #define ADC_CVH_CV6                 _ADC_CV.Overlap_STR.ADC_CVHSTR.Bits.CV6
    #define ADC_CVH_CV7                 _ADC_CV.Overlap_STR.ADC_CVHSTR.Bits.CV7
    
    #define ADC_CVH_CV0_MASK            1U
    #define ADC_CVH_CV1_MASK            2U
    #define ADC_CVH_CV2_MASK            4U
    #define ADC_CVH_CV3_MASK            8U
    #define ADC_CVH_CV4_MASK            16U
    #define ADC_CVH_CV5_MASK            32U
    #define ADC_CVH_CV6_MASK            64U
    #define ADC_CVH_CV7_MASK            128U
    

    /*** ADC_CVL - Compare Value Low Register; 0x00000017 ***/
    union {
      byte Byte;
      struct {
        byte CV0         :1;                                       /* Conversion Result[7:0], bit 0 */
        byte CV1         :1;                                       /* Conversion Result[7:0], bit 1 */
        byte CV2         :1;                                       /* Conversion Result[7:0], bit 2 */
        byte CV3         :1;                                       /* Conversion Result[7:0], bit 3 */
        byte CV4         :1;                                       /* Conversion Result[7:0], bit 4 */
        byte CV5         :1;                                       /* Conversion Result[7:0], bit 5 */
        byte CV6         :1;                                       /* Conversion Result[7:0], bit 6 */
        byte CV7         :1;                                       /* Conversion Result[7:0], bit 7 */
      } Bits;
    } ADC_CVLSTR;
    #define ADC_CVL                     _ADC_CV.Overlap_STR.ADC_CVLSTR.Byte
    #define ADC_CVL_CV0                 _ADC_CV.Overlap_STR.ADC_CVLSTR.Bits.CV0
    #define ADC_CVL_CV1                 _ADC_CV.Overlap_STR.ADC_CVLSTR.Bits.CV1
    #define ADC_CVL_CV2                 _ADC_CV.Overlap_STR.ADC_CVLSTR.Bits.CV2
    #define ADC_CVL_CV3                 _ADC_CV.Overlap_STR.ADC_CVLSTR.Bits.CV3
    #define ADC_CVL_CV4                 _ADC_CV.Overlap_STR.ADC_CVLSTR.Bits.CV4
    #define ADC_CVL_CV5                 _ADC_CV.Overlap_STR.ADC_CVLSTR.Bits.CV5
    #define ADC_CVL_CV6                 _ADC_CV.Overlap_STR.ADC_CVLSTR.Bits.CV6
    #define ADC_CVL_CV7                 _ADC_CV.Overlap_STR.ADC_CVLSTR.Bits.CV7
    
    #define ADC_CVL_CV0_MASK            1U
    #define ADC_CVL_CV1_MASK            2U
    #define ADC_CVL_CV2_MASK            4U
    #define ADC_CVL_CV3_MASK            8U
    #define ADC_CVL_CV4_MASK            16U
    #define ADC_CVL_CV5_MASK            32U
    #define ADC_CVL_CV6_MASK            64U
    #define ADC_CVL_CV7_MASK            128U
    
  } Overlap_STR;

} ADC_CVSTR;
extern volatile ADC_CVSTR _ADC_CV @0x00000016;
#define ADC_CV                          _ADC_CV.Word


/*** MTIM0_SC - MTIM Status and Control Register; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TSTP        :1;                                       /* MTIM Counter Stop */
    byte TRST        :1;                                       /* MTIM Counter Reset */
    byte TOIE        :1;                                       /* MTIM Overflow Interrupt Enable */
    byte TOF         :1;                                       /* MTIM Overflow Flag */
  } Bits;
} MTIM0_SCSTR;
extern volatile MTIM0_SCSTR _MTIM0_SC @0x00000018;
#define MTIM0_SC                        _MTIM0_SC.Byte
#define MTIM0_SC_TSTP                   _MTIM0_SC.Bits.TSTP
#define MTIM0_SC_TRST                   _MTIM0_SC.Bits.TRST
#define MTIM0_SC_TOIE                   _MTIM0_SC.Bits.TOIE
#define MTIM0_SC_TOF                    _MTIM0_SC.Bits.TOF

#define MTIM0_SC_TSTP_MASK              16U
#define MTIM0_SC_TRST_MASK              32U
#define MTIM0_SC_TOIE_MASK              64U
#define MTIM0_SC_TOF_MASK               128U


/*** MTIM0_CLK - MTIM Clock Configuration Register; 0x00000019 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Clock Source Prescaler, bit 0 */
    byte PS1         :1;                                       /* Clock Source Prescaler, bit 1 */
    byte PS2         :1;                                       /* Clock Source Prescaler, bit 2 */
    byte PS3         :1;                                       /* Clock Source Prescaler, bit 3 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPS   :4;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} MTIM0_CLKSTR;
extern volatile MTIM0_CLKSTR _MTIM0_CLK @0x00000019;
#define MTIM0_CLK                       _MTIM0_CLK.Byte
#define MTIM0_CLK_PS0                   _MTIM0_CLK.Bits.PS0
#define MTIM0_CLK_PS1                   _MTIM0_CLK.Bits.PS1
#define MTIM0_CLK_PS2                   _MTIM0_CLK.Bits.PS2
#define MTIM0_CLK_PS3                   _MTIM0_CLK.Bits.PS3
#define MTIM0_CLK_CLKS0                 _MTIM0_CLK.Bits.CLKS0
#define MTIM0_CLK_CLKS1                 _MTIM0_CLK.Bits.CLKS1
#define MTIM0_CLK_PS                    _MTIM0_CLK.MergedBits.grpPS
#define MTIM0_CLK_CLKS                  _MTIM0_CLK.MergedBits.grpCLKS

#define MTIM0_CLK_PS0_MASK              1U
#define MTIM0_CLK_PS1_MASK              2U
#define MTIM0_CLK_PS2_MASK              4U
#define MTIM0_CLK_PS3_MASK              8U
#define MTIM0_CLK_CLKS0_MASK            16U
#define MTIM0_CLK_CLKS1_MASK            32U
#define MTIM0_CLK_PS_MASK               15U
#define MTIM0_CLK_PS_BITNUM             0U
#define MTIM0_CLK_CLKS_MASK             48U
#define MTIM0_CLK_CLKS_BITNUM           4U


/*** MTIM0_CNT - MTIM Counter Register; 0x0000001A ***/
typedef union {
  byte Byte;
} MTIM0_CNTSTR;
extern volatile MTIM0_CNTSTR _MTIM0_CNT @0x0000001A;
#define MTIM0_CNT                       _MTIM0_CNT.Byte


/*** MTIM0_MOD - MTIM Modulo Register; 0x0000001B ***/
typedef union {
  byte Byte;
} MTIM0_MODSTR;
extern volatile MTIM0_MODSTR _MTIM0_MOD @0x0000001B;
#define MTIM0_MOD                       _MTIM0_MOD.Byte


/*** MTIM1_SC - MTIM Status and Control Register; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TSTP        :1;                                       /* MTIM Counter Stop */
    byte TRST        :1;                                       /* MTIM Counter Reset */
    byte TOIE        :1;                                       /* MTIM Overflow Interrupt Enable */
    byte TOF         :1;                                       /* MTIM Overflow Flag */
  } Bits;
} MTIM1_SCSTR;
extern volatile MTIM1_SCSTR _MTIM1_SC @0x0000001C;
#define MTIM1_SC                        _MTIM1_SC.Byte
#define MTIM1_SC_TSTP                   _MTIM1_SC.Bits.TSTP
#define MTIM1_SC_TRST                   _MTIM1_SC.Bits.TRST
#define MTIM1_SC_TOIE                   _MTIM1_SC.Bits.TOIE
#define MTIM1_SC_TOF                    _MTIM1_SC.Bits.TOF

#define MTIM1_SC_TSTP_MASK              16U
#define MTIM1_SC_TRST_MASK              32U
#define MTIM1_SC_TOIE_MASK              64U
#define MTIM1_SC_TOF_MASK               128U


/*** MTIM1_CLK - MTIM Clock Configuration Register; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Clock Source Prescaler, bit 0 */
    byte PS1         :1;                                       /* Clock Source Prescaler, bit 1 */
    byte PS2         :1;                                       /* Clock Source Prescaler, bit 2 */
    byte PS3         :1;                                       /* Clock Source Prescaler, bit 3 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPS   :4;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} MTIM1_CLKSTR;
extern volatile MTIM1_CLKSTR _MTIM1_CLK @0x0000001D;
#define MTIM1_CLK                       _MTIM1_CLK.Byte
#define MTIM1_CLK_PS0                   _MTIM1_CLK.Bits.PS0
#define MTIM1_CLK_PS1                   _MTIM1_CLK.Bits.PS1
#define MTIM1_CLK_PS2                   _MTIM1_CLK.Bits.PS2
#define MTIM1_CLK_PS3                   _MTIM1_CLK.Bits.PS3
#define MTIM1_CLK_CLKS0                 _MTIM1_CLK.Bits.CLKS0
#define MTIM1_CLK_CLKS1                 _MTIM1_CLK.Bits.CLKS1
#define MTIM1_CLK_PS                    _MTIM1_CLK.MergedBits.grpPS
#define MTIM1_CLK_CLKS                  _MTIM1_CLK.MergedBits.grpCLKS

#define MTIM1_CLK_PS0_MASK              1U
#define MTIM1_CLK_PS1_MASK              2U
#define MTIM1_CLK_PS2_MASK              4U
#define MTIM1_CLK_PS3_MASK              8U
#define MTIM1_CLK_CLKS0_MASK            16U
#define MTIM1_CLK_CLKS1_MASK            32U
#define MTIM1_CLK_PS_MASK               15U
#define MTIM1_CLK_PS_BITNUM             0U
#define MTIM1_CLK_CLKS_MASK             48U
#define MTIM1_CLK_CLKS_BITNUM           4U


/*** MTIM1_CNT - MTIM Counter Register; 0x0000001E ***/
typedef union {
  byte Byte;
} MTIM1_CNTSTR;
extern volatile MTIM1_CNTSTR _MTIM1_CNT @0x0000001E;
#define MTIM1_CNT                       _MTIM1_CNT.Byte


/*** MTIM1_MOD - MTIM Modulo Register; 0x0000001F ***/
typedef union {
  byte Byte;
} MTIM1_MODSTR;
extern volatile MTIM1_MODSTR _MTIM1_MOD @0x0000001F;
#define MTIM1_MOD                       _MTIM1_MOD.Byte


/*** FTM0_SC - Status and Control; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Factor Selection, bit 0 */
    byte PS1         :1;                                       /* Prescale Factor Selection, bit 1 */
    byte PS2         :1;                                       /* Prescale Factor Selection, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Selection, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Selection, bit 1 */
    byte CPWMS       :1;                                       /* Center-aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM0_SCSTR;
extern volatile FTM0_SCSTR _FTM0_SC @0x00000020;
#define FTM0_SC                         _FTM0_SC.Byte
#define FTM0_SC_PS0                     _FTM0_SC.Bits.PS0
#define FTM0_SC_PS1                     _FTM0_SC.Bits.PS1
#define FTM0_SC_PS2                     _FTM0_SC.Bits.PS2
#define FTM0_SC_CLKS0                   _FTM0_SC.Bits.CLKS0
#define FTM0_SC_CLKS1                   _FTM0_SC.Bits.CLKS1
#define FTM0_SC_CPWMS                   _FTM0_SC.Bits.CPWMS
#define FTM0_SC_TOIE                    _FTM0_SC.Bits.TOIE
#define FTM0_SC_TOF                     _FTM0_SC.Bits.TOF
#define FTM0_SC_PS                      _FTM0_SC.MergedBits.grpPS
#define FTM0_SC_CLKS                    _FTM0_SC.MergedBits.grpCLKS

#define FTM0_SC_PS0_MASK                1U
#define FTM0_SC_PS1_MASK                2U
#define FTM0_SC_PS2_MASK                4U
#define FTM0_SC_CLKS0_MASK              8U
#define FTM0_SC_CLKS1_MASK              16U
#define FTM0_SC_CPWMS_MASK              32U
#define FTM0_SC_TOIE_MASK               64U
#define FTM0_SC_TOF_MASK                128U
#define FTM0_SC_PS_MASK                 7U
#define FTM0_SC_PS_BITNUM               0U
#define FTM0_SC_CLKS_MASK               24U
#define FTM0_SC_CLKS_BITNUM             3U


/*** FTM0_CNT - FTM0 Timer Counter Register; 0x00000021 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM0_CNTH - Counter High; 0x00000021 ***/
    union {
      byte Byte;
    } FTM0_CNTHSTR;
    #define FTM0_CNTH                   _FTM0_CNT.Overlap_STR.FTM0_CNTHSTR.Byte
    

    /*** FTM0_CNTL - Counter Low; 0x00000022 ***/
    union {
      byte Byte;
    } FTM0_CNTLSTR;
    #define FTM0_CNTL                   _FTM0_CNT.Overlap_STR.FTM0_CNTLSTR.Byte
    
  } Overlap_STR;

} FTM0_CNTSTR;
extern volatile FTM0_CNTSTR _FTM0_CNT @0x00000021;
#define FTM0_CNT                        _FTM0_CNT.Word


/*** FTM0_MOD - FTM0 Timer Counter Modulo Register; 0x00000023 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM0_MODH - Modulo High; 0x00000023 ***/
    union {
      byte Byte;
    } FTM0_MODHSTR;
    #define FTM0_MODH                   _FTM0_MOD.Overlap_STR.FTM0_MODHSTR.Byte
    

    /*** FTM0_MODL - Modulo Low; 0x00000024 ***/
    union {
      byte Byte;
    } FTM0_MODLSTR;
    #define FTM0_MODL                   _FTM0_MOD.Overlap_STR.FTM0_MODLSTR.Byte
    
  } Overlap_STR;

} FTM0_MODSTR;
extern volatile FTM0_MODSTR _FTM0_MOD @0x00000023;
#define FTM0_MOD                        _FTM0_MOD.Word


/*** FTM0_C0SC - Channel Status and Control; 0x00000025 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM0_C0SCSTR;
extern volatile FTM0_C0SCSTR _FTM0_C0SC @0x00000025;
#define FTM0_C0SC                       _FTM0_C0SC.Byte
#define FTM0_C0SC_ELSA                  _FTM0_C0SC.Bits.ELSA
#define FTM0_C0SC_ELSB                  _FTM0_C0SC.Bits.ELSB
#define FTM0_C0SC_MSA                   _FTM0_C0SC.Bits.MSA
#define FTM0_C0SC_MSB                   _FTM0_C0SC.Bits.MSB
#define FTM0_C0SC_CHIE                  _FTM0_C0SC.Bits.CHIE
#define FTM0_C0SC_CHF                   _FTM0_C0SC.Bits.CHF
#define FTM0_C0SC_ELSx                  _FTM0_C0SC.MergedBits.grpELSx
#define FTM0_C0SC_MSx                   _FTM0_C0SC.MergedBits.grpMSx

#define FTM0_C0SC_ELSA_MASK             4U
#define FTM0_C0SC_ELSB_MASK             8U
#define FTM0_C0SC_MSA_MASK              16U
#define FTM0_C0SC_MSB_MASK              32U
#define FTM0_C0SC_CHIE_MASK             64U
#define FTM0_C0SC_CHF_MASK              128U
#define FTM0_C0SC_ELSx_MASK             12U
#define FTM0_C0SC_ELSx_BITNUM           2U
#define FTM0_C0SC_MSx_MASK              48U
#define FTM0_C0SC_MSx_BITNUM            4U


/*** FTM0_C0V - FTM0 Timer Channel 0 Value Register; 0x00000026 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM0_C0VH - Channel Value High; 0x00000026 ***/
    union {
      byte Byte;
    } FTM0_C0VHSTR;
    #define FTM0_C0VH                   _FTM0_C0V.Overlap_STR.FTM0_C0VHSTR.Byte
    

    /*** FTM0_C0VL - Channel Value Low; 0x00000027 ***/
    union {
      byte Byte;
    } FTM0_C0VLSTR;
    #define FTM0_C0VL                   _FTM0_C0V.Overlap_STR.FTM0_C0VLSTR.Byte
    
  } Overlap_STR;

} FTM0_C0VSTR;
extern volatile FTM0_C0VSTR _FTM0_C0V @0x00000026;
#define FTM0_C0V                        _FTM0_C0V.Word


/*** FTM0_C1SC - Channel Status and Control; 0x00000028 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM0_C1SCSTR;
extern volatile FTM0_C1SCSTR _FTM0_C1SC @0x00000028;
#define FTM0_C1SC                       _FTM0_C1SC.Byte
#define FTM0_C1SC_ELSA                  _FTM0_C1SC.Bits.ELSA
#define FTM0_C1SC_ELSB                  _FTM0_C1SC.Bits.ELSB
#define FTM0_C1SC_MSA                   _FTM0_C1SC.Bits.MSA
#define FTM0_C1SC_MSB                   _FTM0_C1SC.Bits.MSB
#define FTM0_C1SC_CHIE                  _FTM0_C1SC.Bits.CHIE
#define FTM0_C1SC_CHF                   _FTM0_C1SC.Bits.CHF
#define FTM0_C1SC_ELSx                  _FTM0_C1SC.MergedBits.grpELSx
#define FTM0_C1SC_MSx                   _FTM0_C1SC.MergedBits.grpMSx

#define FTM0_C1SC_ELSA_MASK             4U
#define FTM0_C1SC_ELSB_MASK             8U
#define FTM0_C1SC_MSA_MASK              16U
#define FTM0_C1SC_MSB_MASK              32U
#define FTM0_C1SC_CHIE_MASK             64U
#define FTM0_C1SC_CHF_MASK              128U
#define FTM0_C1SC_ELSx_MASK             12U
#define FTM0_C1SC_ELSx_BITNUM           2U
#define FTM0_C1SC_MSx_MASK              48U
#define FTM0_C1SC_MSx_BITNUM            4U


/*** FTM0_C1V - FTM0 Timer Channel 1 Value Register; 0x00000029 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM0_C1VH - Channel Value High; 0x00000029 ***/
    union {
      byte Byte;
    } FTM0_C1VHSTR;
    #define FTM0_C1VH                   _FTM0_C1V.Overlap_STR.FTM0_C1VHSTR.Byte
    

    /*** FTM0_C1VL - Channel Value Low; 0x0000002A ***/
    union {
      byte Byte;
    } FTM0_C1VLSTR;
    #define FTM0_C1VL                   _FTM0_C1V.Overlap_STR.FTM0_C1VLSTR.Byte
    
  } Overlap_STR;

} FTM0_C1VSTR;
extern volatile FTM0_C1VSTR _FTM0_C1V @0x00000029;
#define FTM0_C1V                        _FTM0_C1V.Word


/*** ACMP_CS - ACMP Control and Status Register; 0x0000002C ***/
typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       /* ACMP MOD, bit 0 */
    byte ACMOD1      :1;                                       /* ACMP MOD, bit 1 */
    byte ACOPE       :1;                                       /* ACMP Output Pin Enable */
    byte ACO         :1;                                       /* ACMP Output */
    byte ACIE        :1;                                       /* ACMP Interrupt Enable */
    byte ACF         :1;                                       /* ACMP Interrupt Flag Bit */
    byte HYST        :1;                                       /* Analoy Comparator Hystersis Selection */
    byte ACE         :1;                                       /* Analog Comparator Enable */
  } Bits;
  struct {
    byte grpACMOD :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMP_CSSTR;
extern volatile ACMP_CSSTR _ACMP_CS @0x0000002C;
#define ACMP_CS                         _ACMP_CS.Byte
#define ACMP_CS_ACMOD0                  _ACMP_CS.Bits.ACMOD0
#define ACMP_CS_ACMOD1                  _ACMP_CS.Bits.ACMOD1
#define ACMP_CS_ACOPE                   _ACMP_CS.Bits.ACOPE
#define ACMP_CS_ACO                     _ACMP_CS.Bits.ACO
#define ACMP_CS_ACIE                    _ACMP_CS.Bits.ACIE
#define ACMP_CS_ACF                     _ACMP_CS.Bits.ACF
#define ACMP_CS_HYST                    _ACMP_CS.Bits.HYST
#define ACMP_CS_ACE                     _ACMP_CS.Bits.ACE
#define ACMP_CS_ACMOD                   _ACMP_CS.MergedBits.grpACMOD

#define ACMP_CS_ACMOD0_MASK             1U
#define ACMP_CS_ACMOD1_MASK             2U
#define ACMP_CS_ACOPE_MASK              4U
#define ACMP_CS_ACO_MASK                8U
#define ACMP_CS_ACIE_MASK               16U
#define ACMP_CS_ACF_MASK                32U
#define ACMP_CS_HYST_MASK               64U
#define ACMP_CS_ACE_MASK                128U
#define ACMP_CS_ACMOD_MASK              3U
#define ACMP_CS_ACMOD_BITNUM            0U


/*** ACMP_C0 - ACMP Control Register 0; 0x0000002D ***/
typedef union {
  byte Byte;
  struct {
    byte ACNSEL0     :1;                                       /* ACMP Negative Input Select, bit 0 */
    byte ACNSEL1     :1;                                       /* ACMP Negative Input Select, bit 1 */
    byte             :1; 
    byte             :1; 
    byte ACPSEL0     :1;                                       /* ACMP Positive Input Select, bit 0 */
    byte ACPSEL1     :1;                                       /* ACMP Positive Input Select, bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpACNSEL :2;
    byte         :1;
    byte         :1;
    byte grpACPSEL :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMP_C0STR;
extern volatile ACMP_C0STR _ACMP_C0 @0x0000002D;
#define ACMP_C0                         _ACMP_C0.Byte
#define ACMP_C0_ACNSEL0                 _ACMP_C0.Bits.ACNSEL0
#define ACMP_C0_ACNSEL1                 _ACMP_C0.Bits.ACNSEL1
#define ACMP_C0_ACPSEL0                 _ACMP_C0.Bits.ACPSEL0
#define ACMP_C0_ACPSEL1                 _ACMP_C0.Bits.ACPSEL1
/* ACMP_C_ARR: Access 3 ACMP_Cx registers in an array */
#define ACMP_C_ARR                      ((volatile byte * __far) &ACMP_C0)
#define ACMP_C0_ACNSEL                  _ACMP_C0.MergedBits.grpACNSEL
#define ACMP_C0_ACPSEL                  _ACMP_C0.MergedBits.grpACPSEL

#define ACMP_C0_ACNSEL0_MASK            1U
#define ACMP_C0_ACNSEL1_MASK            2U
#define ACMP_C0_ACPSEL0_MASK            16U
#define ACMP_C0_ACPSEL1_MASK            32U
#define ACMP_C0_ACNSEL_MASK             3U
#define ACMP_C0_ACNSEL_BITNUM           0U
#define ACMP_C0_ACPSEL_MASK             48U
#define ACMP_C0_ACPSEL_BITNUM           4U


/*** ACMP_C1 - ACMP Control Register 1; 0x0000002E ***/
typedef union {
  byte Byte;
  struct {
    byte DACVAL0     :1;                                       /* DAC Output Level Selection, bit 0 */
    byte DACVAL1     :1;                                       /* DAC Output Level Selection, bit 1 */
    byte DACVAL2     :1;                                       /* DAC Output Level Selection, bit 2 */
    byte DACVAL3     :1;                                       /* DAC Output Level Selection, bit 3 */
    byte DACVAL4     :1;                                       /* DAC Output Level Selection, bit 4 */
    byte DACVAL5     :1;                                       /* DAC Output Level Selection, bit 5 */
    byte DACREF      :1;                                       /* DAC Reference Select */
    byte DACEN       :1;                                       /* DAC Enable */
  } Bits;
  struct {
    byte grpDACVAL :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMP_C1STR;
extern volatile ACMP_C1STR _ACMP_C1 @0x0000002E;
#define ACMP_C1                         _ACMP_C1.Byte
#define ACMP_C1_DACVAL0                 _ACMP_C1.Bits.DACVAL0
#define ACMP_C1_DACVAL1                 _ACMP_C1.Bits.DACVAL1
#define ACMP_C1_DACVAL2                 _ACMP_C1.Bits.DACVAL2
#define ACMP_C1_DACVAL3                 _ACMP_C1.Bits.DACVAL3
#define ACMP_C1_DACVAL4                 _ACMP_C1.Bits.DACVAL4
#define ACMP_C1_DACVAL5                 _ACMP_C1.Bits.DACVAL5
#define ACMP_C1_DACREF                  _ACMP_C1.Bits.DACREF
#define ACMP_C1_DACEN                   _ACMP_C1.Bits.DACEN
#define ACMP_C1_DACVAL                  _ACMP_C1.MergedBits.grpDACVAL

#define ACMP_C1_DACVAL0_MASK            1U
#define ACMP_C1_DACVAL1_MASK            2U
#define ACMP_C1_DACVAL2_MASK            4U
#define ACMP_C1_DACVAL3_MASK            8U
#define ACMP_C1_DACVAL4_MASK            16U
#define ACMP_C1_DACVAL5_MASK            32U
#define ACMP_C1_DACREF_MASK             64U
#define ACMP_C1_DACEN_MASK              128U
#define ACMP_C1_DACVAL_MASK             63U
#define ACMP_C1_DACVAL_BITNUM           0U


/*** ACMP_C2 - ACMP Control Register 2; 0x0000002F ***/
typedef union {
  byte Byte;
  struct {
    byte ACIPE0      :1; 
    byte ACIPE1      :1; 
    byte ACIPE2      :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpACIPE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ACMP_C2STR;
extern volatile ACMP_C2STR _ACMP_C2 @0x0000002F;
#define ACMP_C2                         _ACMP_C2.Byte
#define ACMP_C2_ACIPE0                  _ACMP_C2.Bits.ACIPE0
#define ACMP_C2_ACIPE1                  _ACMP_C2.Bits.ACIPE1
#define ACMP_C2_ACIPE2                  _ACMP_C2.Bits.ACIPE2
#define ACMP_C2_ACIPE                   _ACMP_C2.MergedBits.grpACIPE

#define ACMP_C2_ACIPE0_MASK             1U
#define ACMP_C2_ACIPE1_MASK             2U
#define ACMP_C2_ACIPE2_MASK             4U
#define ACMP_C2_ACIPE_MASK              7U
#define ACMP_C2_ACIPE_BITNUM            0U


/*** FTM1_SC - Status and Control; 0x00000030 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Factor Selection, bit 0 */
    byte PS1         :1;                                       /* Prescale Factor Selection, bit 1 */
    byte PS2         :1;                                       /* Prescale Factor Selection, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Selection, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Selection, bit 1 */
    byte CPWMS       :1;                                       /* Center-aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1_SCSTR;
extern volatile FTM1_SCSTR _FTM1_SC @0x00000030;
#define FTM1_SC                         _FTM1_SC.Byte
#define FTM1_SC_PS0                     _FTM1_SC.Bits.PS0
#define FTM1_SC_PS1                     _FTM1_SC.Bits.PS1
#define FTM1_SC_PS2                     _FTM1_SC.Bits.PS2
#define FTM1_SC_CLKS0                   _FTM1_SC.Bits.CLKS0
#define FTM1_SC_CLKS1                   _FTM1_SC.Bits.CLKS1
#define FTM1_SC_CPWMS                   _FTM1_SC.Bits.CPWMS
#define FTM1_SC_TOIE                    _FTM1_SC.Bits.TOIE
#define FTM1_SC_TOF                     _FTM1_SC.Bits.TOF
#define FTM1_SC_PS                      _FTM1_SC.MergedBits.grpPS
#define FTM1_SC_CLKS                    _FTM1_SC.MergedBits.grpCLKS

#define FTM1_SC_PS0_MASK                1U
#define FTM1_SC_PS1_MASK                2U
#define FTM1_SC_PS2_MASK                4U
#define FTM1_SC_CLKS0_MASK              8U
#define FTM1_SC_CLKS1_MASK              16U
#define FTM1_SC_CPWMS_MASK              32U
#define FTM1_SC_TOIE_MASK               64U
#define FTM1_SC_TOF_MASK                128U
#define FTM1_SC_PS_MASK                 7U
#define FTM1_SC_PS_BITNUM               0U
#define FTM1_SC_CLKS_MASK               24U
#define FTM1_SC_CLKS_BITNUM             3U


/*** FTM1_CNT - FTM1 Timer Counter Register; 0x00000031 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1_CNTH - Counter High; 0x00000031 ***/
    union {
      byte Byte;
    } FTM1_CNTHSTR;
    #define FTM1_CNTH                   _FTM1_CNT.Overlap_STR.FTM1_CNTHSTR.Byte
    

    /*** FTM1_CNTL - Counter Low; 0x00000032 ***/
    union {
      byte Byte;
    } FTM1_CNTLSTR;
    #define FTM1_CNTL                   _FTM1_CNT.Overlap_STR.FTM1_CNTLSTR.Byte
    
  } Overlap_STR;

} FTM1_CNTSTR;
extern volatile FTM1_CNTSTR _FTM1_CNT @0x00000031;
#define FTM1_CNT                        _FTM1_CNT.Word


/*** FTM1_MOD - FTM1 Timer Counter Modulo Register; 0x00000033 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1_MODH - Modulo High; 0x00000033 ***/
    union {
      byte Byte;
    } FTM1_MODHSTR;
    #define FTM1_MODH                   _FTM1_MOD.Overlap_STR.FTM1_MODHSTR.Byte
    

    /*** FTM1_MODL - Modulo Low; 0x00000034 ***/
    union {
      byte Byte;
    } FTM1_MODLSTR;
    #define FTM1_MODL                   _FTM1_MOD.Overlap_STR.FTM1_MODLSTR.Byte
    
  } Overlap_STR;

} FTM1_MODSTR;
extern volatile FTM1_MODSTR _FTM1_MOD @0x00000033;
#define FTM1_MOD                        _FTM1_MOD.Word


/*** FTM1_C0SC - Channel Status and Control; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1_C0SCSTR;
extern volatile FTM1_C0SCSTR _FTM1_C0SC @0x00000035;
#define FTM1_C0SC                       _FTM1_C0SC.Byte
#define FTM1_C0SC_ELSA                  _FTM1_C0SC.Bits.ELSA
#define FTM1_C0SC_ELSB                  _FTM1_C0SC.Bits.ELSB
#define FTM1_C0SC_MSA                   _FTM1_C0SC.Bits.MSA
#define FTM1_C0SC_MSB                   _FTM1_C0SC.Bits.MSB
#define FTM1_C0SC_CHIE                  _FTM1_C0SC.Bits.CHIE
#define FTM1_C0SC_CHF                   _FTM1_C0SC.Bits.CHF
#define FTM1_C0SC_ELSx                  _FTM1_C0SC.MergedBits.grpELSx
#define FTM1_C0SC_MSx                   _FTM1_C0SC.MergedBits.grpMSx

#define FTM1_C0SC_ELSA_MASK             4U
#define FTM1_C0SC_ELSB_MASK             8U
#define FTM1_C0SC_MSA_MASK              16U
#define FTM1_C0SC_MSB_MASK              32U
#define FTM1_C0SC_CHIE_MASK             64U
#define FTM1_C0SC_CHF_MASK              128U
#define FTM1_C0SC_ELSx_MASK             12U
#define FTM1_C0SC_ELSx_BITNUM           2U
#define FTM1_C0SC_MSx_MASK              48U
#define FTM1_C0SC_MSx_BITNUM            4U


/*** FTM1_C0V - FTM1 Timer Channel 0 Value Register; 0x00000036 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1_C0VH - Channel Value High; 0x00000036 ***/
    union {
      byte Byte;
    } FTM1_C0VHSTR;
    #define FTM1_C0VH                   _FTM1_C0V.Overlap_STR.FTM1_C0VHSTR.Byte
    

    /*** FTM1_C0VL - Channel Value Low; 0x00000037 ***/
    union {
      byte Byte;
    } FTM1_C0VLSTR;
    #define FTM1_C0VL                   _FTM1_C0V.Overlap_STR.FTM1_C0VLSTR.Byte
    
  } Overlap_STR;

} FTM1_C0VSTR;
extern volatile FTM1_C0VSTR _FTM1_C0V @0x00000036;
#define FTM1_C0V                        _FTM1_C0V.Word


/*** FTM1_C1SC - Channel Status and Control; 0x00000038 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1_C1SCSTR;
extern volatile FTM1_C1SCSTR _FTM1_C1SC @0x00000038;
#define FTM1_C1SC                       _FTM1_C1SC.Byte
#define FTM1_C1SC_ELSA                  _FTM1_C1SC.Bits.ELSA
#define FTM1_C1SC_ELSB                  _FTM1_C1SC.Bits.ELSB
#define FTM1_C1SC_MSA                   _FTM1_C1SC.Bits.MSA
#define FTM1_C1SC_MSB                   _FTM1_C1SC.Bits.MSB
#define FTM1_C1SC_CHIE                  _FTM1_C1SC.Bits.CHIE
#define FTM1_C1SC_CHF                   _FTM1_C1SC.Bits.CHF
#define FTM1_C1SC_ELSx                  _FTM1_C1SC.MergedBits.grpELSx
#define FTM1_C1SC_MSx                   _FTM1_C1SC.MergedBits.grpMSx

#define FTM1_C1SC_ELSA_MASK             4U
#define FTM1_C1SC_ELSB_MASK             8U
#define FTM1_C1SC_MSA_MASK              16U
#define FTM1_C1SC_MSB_MASK              32U
#define FTM1_C1SC_CHIE_MASK             64U
#define FTM1_C1SC_CHF_MASK              128U
#define FTM1_C1SC_ELSx_MASK             12U
#define FTM1_C1SC_ELSx_BITNUM           2U
#define FTM1_C1SC_MSx_MASK              48U
#define FTM1_C1SC_MSx_BITNUM            4U


/*** FTM1_C1V - FTM1 Timer Channel 1 Value Register; 0x00000039 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1_C1VH - Channel Value High; 0x00000039 ***/
    union {
      byte Byte;
    } FTM1_C1VHSTR;
    #define FTM1_C1VH                   _FTM1_C1V.Overlap_STR.FTM1_C1VHSTR.Byte
    

    /*** FTM1_C1VL - Channel Value Low; 0x0000003A ***/
    union {
      byte Byte;
    } FTM1_C1VLSTR;
    #define FTM1_C1VL                   _FTM1_C1V.Overlap_STR.FTM1_C1VLSTR.Byte
    
  } Overlap_STR;

} FTM1_C1VSTR;
extern volatile FTM1_C1VSTR _FTM1_C1V @0x00000039;
#define FTM1_C1V                        _FTM1_C1V.Word


/*** IRQ_SC - Interrupt Pin Request Status and Control Register; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       /* IRQ Detection Mode */
    byte IRQIE       :1;                                       /* IRQ Interrupt Enable */
    byte IRQACK      :1;                                       /* IRQ Acknowledge */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte IRQPE       :1;                                       /* IRQ Pin Enable */
    byte IRQEDG      :1;                                       /* Interrupt Request (IRQ) Edge Select */
    byte IRQPDD      :1;                                       /* Interrupt Request (IRQ) Pull Device Disable */
    byte             :1; 
  } Bits;
} IRQ_SCSTR;
extern volatile IRQ_SCSTR _IRQ_SC @0x0000003B;
#define IRQ_SC                          _IRQ_SC.Byte
#define IRQ_SC_IRQMOD                   _IRQ_SC.Bits.IRQMOD
#define IRQ_SC_IRQIE                    _IRQ_SC.Bits.IRQIE
#define IRQ_SC_IRQACK                   _IRQ_SC.Bits.IRQACK
#define IRQ_SC_IRQF                     _IRQ_SC.Bits.IRQF
#define IRQ_SC_IRQPE                    _IRQ_SC.Bits.IRQPE
#define IRQ_SC_IRQEDG                   _IRQ_SC.Bits.IRQEDG
#define IRQ_SC_IRQPDD                   _IRQ_SC.Bits.IRQPDD

#define IRQ_SC_IRQMOD_MASK              1U
#define IRQ_SC_IRQIE_MASK               2U
#define IRQ_SC_IRQACK_MASK              4U
#define IRQ_SC_IRQF_MASK                8U
#define IRQ_SC_IRQPE_MASK               16U
#define IRQ_SC_IRQEDG_MASK              32U
#define IRQ_SC_IRQPDD_MASK              64U


/*** KBI0_SC - KBI Status and Control Register; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte KBMOD       :1;                                       /* KBI Detection Mode */
    byte KBIE        :1;                                       /* KBI Interrupt Enable */
    byte KBACK       :1;                                       /* KBI Acknowledge */
    byte KBF         :1;                                       /* KBI Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI0_SCSTR;
extern volatile KBI0_SCSTR _KBI0_SC @0x0000003C;
#define KBI0_SC                         _KBI0_SC.Byte
#define KBI0_SC_KBMOD                   _KBI0_SC.Bits.KBMOD
#define KBI0_SC_KBIE                    _KBI0_SC.Bits.KBIE
#define KBI0_SC_KBACK                   _KBI0_SC.Bits.KBACK
#define KBI0_SC_KBF                     _KBI0_SC.Bits.KBF

#define KBI0_SC_KBMOD_MASK              1U
#define KBI0_SC_KBIE_MASK               2U
#define KBI0_SC_KBACK_MASK              4U
#define KBI0_SC_KBF_MASK                8U


/*** KBI1_SC - KBI Status and Control Register; 0x0000003D ***/
typedef union {
  byte Byte;
  struct {
    byte KBMOD       :1;                                       /* KBI Detection Mode */
    byte KBIE        :1;                                       /* KBI Interrupt Enable */
    byte KBACK       :1;                                       /* KBI Acknowledge */
    byte KBF         :1;                                       /* KBI Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI1_SCSTR;
extern volatile KBI1_SCSTR _KBI1_SC @0x0000003D;
#define KBI1_SC                         _KBI1_SC.Byte
#define KBI1_SC_KBMOD                   _KBI1_SC.Bits.KBMOD
#define KBI1_SC_KBIE                    _KBI1_SC.Bits.KBIE
#define KBI1_SC_KBACK                   _KBI1_SC.Bits.KBACK
#define KBI1_SC_KBF                     _KBI1_SC.Bits.KBF

#define KBI1_SC_KBMOD_MASK              1U
#define KBI1_SC_KBIE_MASK               2U
#define KBI1_SC_KBACK_MASK              4U
#define KBI1_SC_KBF_MASK                8U


/*** IPC_SC - IPC Status and Control Register; 0x0000003E ***/
typedef union {
  byte Byte;
  struct {
    byte IPM0        :1;                                       /* Interrupt Priority Mask, bit 0 */
    byte IPM1        :1;                                       /* Interrupt Priority Mask, bit 1 */
    byte             :1; 
    byte PULIPM      :1;                                       /* Pull IPM from IPMPS */
    byte PSF         :1;                                       /* Pseudo Stack Full */
    byte PSE         :1;                                       /* Pseudo Stack Empty */
    byte             :1; 
    byte IPCE        :1;                                       /* Interrupt Priority Controller Enable */
  } Bits;
  struct {
    byte grpIPM  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IPC_SCSTR;
extern volatile IPC_SCSTR _IPC_SC @0x0000003E;
#define IPC_SC                          _IPC_SC.Byte
#define IPC_SC_IPM0                     _IPC_SC.Bits.IPM0
#define IPC_SC_IPM1                     _IPC_SC.Bits.IPM1
#define IPC_SC_PULIPM                   _IPC_SC.Bits.PULIPM
#define IPC_SC_PSF                      _IPC_SC.Bits.PSF
#define IPC_SC_PSE                      _IPC_SC.Bits.PSE
#define IPC_SC_IPCE                     _IPC_SC.Bits.IPCE
#define IPC_SC_IPM                      _IPC_SC.MergedBits.grpIPM

#define IPC_SC_IPM0_MASK                1U
#define IPC_SC_IPM1_MASK                2U
#define IPC_SC_PULIPM_MASK              8U
#define IPC_SC_PSF_MASK                 16U
#define IPC_SC_PSE_MASK                 32U
#define IPC_SC_IPCE_MASK                128U
#define IPC_SC_IPM_MASK                 3U
#define IPC_SC_IPM_BITNUM               0U


/*** IPC_IPMPS - Interrupt Priority Mask Pseudo Stack Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte IPM00       :1;                                       /* Interrupt Priority Mask pseudo stack position 0, bit 0 */
    byte IPM01       :1;                                       /* Interrupt Priority Mask pseudo stack position 0, bit 1 */
    byte IPM10       :1;                                       /* Interrupt Priority Mask pseudo stack position 1, bit 0 */
    byte IPM11       :1;                                       /* Interrupt Priority Mask pseudo stack position 1, bit 1 */
    byte IPM20       :1;                                       /* Interrupt Priority Mask pseudo stack position 2, bit 0 */
    byte IPM21       :1;                                       /* Interrupt Priority Mask pseudo stack position 2, bit 1 */
    byte IPM30       :1;                                       /* Interrupt Priority Mask pseudo stack position 3, bit 0 */
    byte IPM31       :1;                                       /* Interrupt Priority Mask pseudo stack position 3, bit 1 */
  } Bits;
  struct {
    byte grpIPM0 :2;
    byte grpIPM1 :2;
    byte grpIPM2 :2;
    byte grpIPM3 :2;
  } MergedBits;
} IPC_IPMPSSTR;
extern volatile IPC_IPMPSSTR _IPC_IPMPS @0x0000003F;
#define IPC_IPMPS                       _IPC_IPMPS.Byte
#define IPC_IPMPS_IPM00                 _IPC_IPMPS.Bits.IPM00
#define IPC_IPMPS_IPM01                 _IPC_IPMPS.Bits.IPM01
#define IPC_IPMPS_IPM10                 _IPC_IPMPS.Bits.IPM10
#define IPC_IPMPS_IPM11                 _IPC_IPMPS.Bits.IPM11
#define IPC_IPMPS_IPM20                 _IPC_IPMPS.Bits.IPM20
#define IPC_IPMPS_IPM21                 _IPC_IPMPS.Bits.IPM21
#define IPC_IPMPS_IPM30                 _IPC_IPMPS.Bits.IPM30
#define IPC_IPMPS_IPM31                 _IPC_IPMPS.Bits.IPM31
#define IPC_IPMPS_IPM0                  _IPC_IPMPS.MergedBits.grpIPM0
#define IPC_IPMPS_IPM1                  _IPC_IPMPS.MergedBits.grpIPM1
#define IPC_IPMPS_IPM2                  _IPC_IPMPS.MergedBits.grpIPM2
#define IPC_IPMPS_IPM3                  _IPC_IPMPS.MergedBits.grpIPM3

#define IPC_IPMPS_IPM00_MASK            1U
#define IPC_IPMPS_IPM01_MASK            2U
#define IPC_IPMPS_IPM10_MASK            4U
#define IPC_IPMPS_IPM11_MASK            8U
#define IPC_IPMPS_IPM20_MASK            16U
#define IPC_IPMPS_IPM21_MASK            32U
#define IPC_IPMPS_IPM30_MASK            64U
#define IPC_IPMPS_IPM31_MASK            128U
#define IPC_IPMPS_IPM0_MASK             3U
#define IPC_IPMPS_IPM0_BITNUM           0U
#define IPC_IPMPS_IPM1_MASK             12U
#define IPC_IPMPS_IPM1_BITNUM           2U
#define IPC_IPMPS_IPM2_MASK             48U
#define IPC_IPMPS_IPM2_BITNUM           4U
#define IPC_IPMPS_IPM3_MASK             192U
#define IPC_IPMPS_IPM3_BITNUM           6U


/*** SYS_SRS - System Reset Status Register; 0x00003000 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte LOC         :1;                                       /* Internal Clock Source Module Reset */
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte WDOG        :1;                                       /* Watchdog (WDOG) */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SYS_SRSSTR;
extern volatile SYS_SRSSTR _SYS_SRS @0x00003000;
#define SYS_SRS                         _SYS_SRS.Byte
#define SYS_SRS_LVD                     _SYS_SRS.Bits.LVD
#define SYS_SRS_LOC                     _SYS_SRS.Bits.LOC
#define SYS_SRS_ILAD                    _SYS_SRS.Bits.ILAD
#define SYS_SRS_ILOP                    _SYS_SRS.Bits.ILOP
#define SYS_SRS_WDOG                    _SYS_SRS.Bits.WDOG
#define SYS_SRS_PIN                     _SYS_SRS.Bits.PIN
#define SYS_SRS_POR                     _SYS_SRS.Bits.POR

#define SYS_SRS_LVD_MASK                2U
#define SYS_SRS_LOC_MASK                4U
#define SYS_SRS_ILAD_MASK               8U
#define SYS_SRS_ILOP_MASK               16U
#define SYS_SRS_WDOG_MASK               32U
#define SYS_SRS_PIN_MASK                64U
#define SYS_SRS_POR_MASK                128U


/*** SYS_SBDFR - System Background Debug Force Reset Register; 0x00003001 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SYS_SBDFRSTR;
extern volatile SYS_SBDFRSTR _SYS_SBDFR @0x00003001;
#define SYS_SBDFR                       _SYS_SBDFR.Byte
#define SYS_SBDFR_BDFR                  _SYS_SBDFR.Bits.BDFR

#define SYS_SBDFR_BDFR_MASK             1U


/*** SYS_SDID - System Device Identification Register; 0x00003002 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SYS_SDIDH - System Device Identification Register: High; 0x00003002 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpID :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SYS_SDIDHSTR;
    #define SYS_SDIDH                   _SYS_SDID.Overlap_STR.SYS_SDIDHSTR.Byte
    #define SYS_SDIDH_ID0               _SYS_SDID.Overlap_STR.SYS_SDIDHSTR.Bits.ID0
    #define SYS_SDIDH_ID1               _SYS_SDID.Overlap_STR.SYS_SDIDHSTR.Bits.ID1
    #define SYS_SDIDH_ID2               _SYS_SDID.Overlap_STR.SYS_SDIDHSTR.Bits.ID2
    #define SYS_SDIDH_ID3               _SYS_SDID.Overlap_STR.SYS_SDIDHSTR.Bits.ID3
    #define SYS_SDIDH_ID                _SYS_SDID.Overlap_STR.SYS_SDIDHSTR.MergedBits.grpID
    
    #define SYS_SDIDH_ID0_MASK          1U
    #define SYS_SDIDH_ID1_MASK          2U
    #define SYS_SDIDH_ID2_MASK          4U
    #define SYS_SDIDH_ID3_MASK          8U
    #define SYS_SDIDH_ID_MASK           15U
    #define SYS_SDIDH_ID_BITNUM         0U
    

    /*** SYS_SDIDL - System Device Identification Register: Low; 0x00003003 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SYS_SDIDLSTR;
    #define SYS_SDIDL                   _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Byte
    #define SYS_SDIDL_ID0               _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Bits.ID0
    #define SYS_SDIDL_ID1               _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Bits.ID1
    #define SYS_SDIDL_ID2               _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Bits.ID2
    #define SYS_SDIDL_ID3               _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Bits.ID3
    #define SYS_SDIDL_ID4               _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Bits.ID4
    #define SYS_SDIDL_ID5               _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Bits.ID5
    #define SYS_SDIDL_ID6               _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Bits.ID6
    #define SYS_SDIDL_ID7               _SYS_SDID.Overlap_STR.SYS_SDIDLSTR.Bits.ID7
    
    #define SYS_SDIDL_ID0_MASK          1U
    #define SYS_SDIDL_ID1_MASK          2U
    #define SYS_SDIDL_ID2_MASK          4U
    #define SYS_SDIDL_ID3_MASK          8U
    #define SYS_SDIDL_ID4_MASK          16U
    #define SYS_SDIDL_ID5_MASK          32U
    #define SYS_SDIDL_ID6_MASK          64U
    #define SYS_SDIDL_ID7_MASK          128U
    
  } Overlap_STR;

} SYS_SDIDSTR;
extern volatile SYS_SDIDSTR _SYS_SDID @0x00003002;
#define SYS_SDID                        _SYS_SDID.Word


/*** SYS_SOPT1 - System Options Register 1; 0x00003004 ***/
typedef union {
  byte Byte;
  struct {
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte FWAKE       :1;                                       /* Fast Wakeup Enable */
    byte RSTPE       :1;                                       /* RESET Pin Enable */
    byte BKGDPE      :1;                                       /* Background Debug Mode Pin Enable */
    byte FTM2PS      :1;                                       /* FTM2 Port Pin Select */
    byte IICPS       :1;                                       /* IIC Port Pin Select */
    byte SPI0PS      :1;                                       /* SPI0 Pin Select */
    byte SCI0PS      :1;                                       /* SCI0 Pin Select */
  } Bits;
} SYS_SOPT1STR;
extern volatile SYS_SOPT1STR _SYS_SOPT1 @0x00003004;
#define SYS_SOPT1                       _SYS_SOPT1.Byte
#define SYS_SOPT1_STOPE                 _SYS_SOPT1.Bits.STOPE
#define SYS_SOPT1_FWAKE                 _SYS_SOPT1.Bits.FWAKE
#define SYS_SOPT1_RSTPE                 _SYS_SOPT1.Bits.RSTPE
#define SYS_SOPT1_BKGDPE                _SYS_SOPT1.Bits.BKGDPE
#define SYS_SOPT1_FTM2PS                _SYS_SOPT1.Bits.FTM2PS
#define SYS_SOPT1_IICPS                 _SYS_SOPT1.Bits.IICPS
#define SYS_SOPT1_SPI0PS                _SYS_SOPT1.Bits.SPI0PS
#define SYS_SOPT1_SCI0PS                _SYS_SOPT1.Bits.SCI0PS

#define SYS_SOPT1_STOPE_MASK            1U
#define SYS_SOPT1_FWAKE_MASK            2U
#define SYS_SOPT1_RSTPE_MASK            4U
#define SYS_SOPT1_BKGDPE_MASK           8U
#define SYS_SOPT1_FTM2PS_MASK           16U
#define SYS_SOPT1_IICPS_MASK            32U
#define SYS_SOPT1_SPI0PS_MASK           64U
#define SYS_SOPT1_SCI0PS_MASK           128U


/*** SYS_SOPT2 - System Options Register 2; 0x00003005 ***/
typedef union {
  byte Byte;
  struct {
    byte ADHWTS0     :1;                                       /* ADC Hardware Trigger Source, bit 0 */
    byte ADHWTS1     :1;                                       /* ADC Hardware Trigger Source, bit 1 */
    byte RTCC        :1;                                       /* Real-Time Counter Capture */
    byte ACIC        :1;                                       /* Analog Comparator to Input Capture Enable */
    byte RXDCE       :1;                                       /* SCI0 RxD Capture Select */
    byte RXDFE       :1;                                       /* SCI0 RxD Filter Select */
    byte FTMSYNC     :1;                                       /* FTM2 Synchronization Select */
    byte TXDME       :1;                                       /* SCI0 TxD Modulation Select */
  } Bits;
  struct {
    byte grpADHWTS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SYS_SOPT2STR;
extern volatile SYS_SOPT2STR _SYS_SOPT2 @0x00003005;
#define SYS_SOPT2                       _SYS_SOPT2.Byte
#define SYS_SOPT2_ADHWTS0               _SYS_SOPT2.Bits.ADHWTS0
#define SYS_SOPT2_ADHWTS1               _SYS_SOPT2.Bits.ADHWTS1
#define SYS_SOPT2_RTCC                  _SYS_SOPT2.Bits.RTCC
#define SYS_SOPT2_ACIC                  _SYS_SOPT2.Bits.ACIC
#define SYS_SOPT2_RXDCE                 _SYS_SOPT2.Bits.RXDCE
#define SYS_SOPT2_RXDFE                 _SYS_SOPT2.Bits.RXDFE
#define SYS_SOPT2_FTMSYNC               _SYS_SOPT2.Bits.FTMSYNC
#define SYS_SOPT2_TXDME                 _SYS_SOPT2.Bits.TXDME
#define SYS_SOPT2_ADHWTS                _SYS_SOPT2.MergedBits.grpADHWTS

#define SYS_SOPT2_ADHWTS0_MASK          1U
#define SYS_SOPT2_ADHWTS1_MASK          2U
#define SYS_SOPT2_RTCC_MASK             4U
#define SYS_SOPT2_ACIC_MASK             8U
#define SYS_SOPT2_RXDCE_MASK            16U
#define SYS_SOPT2_RXDFE_MASK            32U
#define SYS_SOPT2_FTMSYNC_MASK          64U
#define SYS_SOPT2_TXDME_MASK            128U
#define SYS_SOPT2_ADHWTS_MASK           3U
#define SYS_SOPT2_ADHWTS_BITNUM         0U


/*** SYS_SOPT3 - System Options Register 3; 0x00003006 ***/
typedef union {
  byte Byte;
  struct {
    byte BUSREF0     :1;                                       /* BUS Output select, bit 0 */
    byte BUSREF1     :1;                                       /* BUS Output select, bit 1 */
    byte BUSREF2     :1;                                       /* BUS Output select, bit 2 */
    byte CLKOE       :1;                                       /* CLK Output Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DLYACT      :1;                                       /* FTM2 Trigger Delay Active */
  } Bits;
  struct {
    byte grpBUSREF :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SYS_SOPT3STR;
extern volatile SYS_SOPT3STR _SYS_SOPT3 @0x00003006;
#define SYS_SOPT3                       _SYS_SOPT3.Byte
#define SYS_SOPT3_BUSREF0               _SYS_SOPT3.Bits.BUSREF0
#define SYS_SOPT3_BUSREF1               _SYS_SOPT3.Bits.BUSREF1
#define SYS_SOPT3_BUSREF2               _SYS_SOPT3.Bits.BUSREF2
#define SYS_SOPT3_CLKOE                 _SYS_SOPT3.Bits.CLKOE
#define SYS_SOPT3_DLYACT                _SYS_SOPT3.Bits.DLYACT
#define SYS_SOPT3_BUSREF                _SYS_SOPT3.MergedBits.grpBUSREF

#define SYS_SOPT3_BUSREF0_MASK          1U
#define SYS_SOPT3_BUSREF1_MASK          2U
#define SYS_SOPT3_BUSREF2_MASK          4U
#define SYS_SOPT3_CLKOE_MASK            8U
#define SYS_SOPT3_DLYACT_MASK           128U
#define SYS_SOPT3_BUSREF_MASK           7U
#define SYS_SOPT3_BUSREF_BITNUM         0U


/*** SYS_SOPT4 - System Options Register 4; 0x00003007 ***/
typedef union {
  byte Byte;
  struct {
    byte DELAY0      :1;                                       /* FTM2 Trigger Delay, bit 0 */
    byte DELAY1      :1;                                       /* FTM2 Trigger Delay, bit 1 */
    byte DELAY2      :1;                                       /* FTM2 Trigger Delay, bit 2 */
    byte DELAY3      :1;                                       /* FTM2 Trigger Delay, bit 3 */
    byte DELAY4      :1;                                       /* FTM2 Trigger Delay, bit 4 */
    byte DELAY5      :1;                                       /* FTM2 Trigger Delay, bit 5 */
    byte DELAY6      :1;                                       /* FTM2 Trigger Delay, bit 6 */
    byte DELAY7      :1;                                       /* FTM2 Trigger Delay, bit 7 */
  } Bits;
} SYS_SOPT4STR;
extern volatile SYS_SOPT4STR _SYS_SOPT4 @0x00003007;
#define SYS_SOPT4                       _SYS_SOPT4.Byte
#define SYS_SOPT4_DELAY0                _SYS_SOPT4.Bits.DELAY0
#define SYS_SOPT4_DELAY1                _SYS_SOPT4.Bits.DELAY1
#define SYS_SOPT4_DELAY2                _SYS_SOPT4.Bits.DELAY2
#define SYS_SOPT4_DELAY3                _SYS_SOPT4.Bits.DELAY3
#define SYS_SOPT4_DELAY4                _SYS_SOPT4.Bits.DELAY4
#define SYS_SOPT4_DELAY5                _SYS_SOPT4.Bits.DELAY5
#define SYS_SOPT4_DELAY6                _SYS_SOPT4.Bits.DELAY6
#define SYS_SOPT4_DELAY7                _SYS_SOPT4.Bits.DELAY7

#define SYS_SOPT4_DELAY0_MASK           1U
#define SYS_SOPT4_DELAY1_MASK           2U
#define SYS_SOPT4_DELAY2_MASK           4U
#define SYS_SOPT4_DELAY3_MASK           8U
#define SYS_SOPT4_DELAY4_MASK           16U
#define SYS_SOPT4_DELAY5_MASK           32U
#define SYS_SOPT4_DELAY6_MASK           64U
#define SYS_SOPT4_DELAY7_MASK           128U


/*** SCG_C1 - System Clock Gating Control 1 Register; 0x0000300C ***/
typedef union {
  byte Byte;
  struct {
    byte RTC         :1;                                       /* RTC Clock Gate Control */
    byte MTIM0       :1;                                       /* MTIM0 Clock Gate Control */
    byte MTIM1       :1;                                       /* MTIM1 Clock Gate Control */
    byte             :1; 
    byte             :1; 
    byte FTM0        :1;                                       /* FTM0 Clock Gate Control */
    byte FTM1        :1;                                       /* FTM1 Clock Gate Control */
    byte FTM2        :1;                                       /* FTM2 Clock Gate Control */
  } Bits;
  struct {
    byte         :1;
    byte grpMTIM :2;
    byte         :1;
    byte         :1;
    byte grpFTM  :3;
  } MergedBits;
} SCG_C1STR;
extern volatile SCG_C1STR _SCG_C1 @0x0000300C;
#define SCG_C1                          _SCG_C1.Byte
#define SCG_C1_RTC                      _SCG_C1.Bits.RTC
#define SCG_C1_MTIM0                    _SCG_C1.Bits.MTIM0
#define SCG_C1_MTIM1                    _SCG_C1.Bits.MTIM1
#define SCG_C1_FTM0                     _SCG_C1.Bits.FTM0
#define SCG_C1_FTM1                     _SCG_C1.Bits.FTM1
#define SCG_C1_FTM2                     _SCG_C1.Bits.FTM2
#define SCG_C1_MTIM                     _SCG_C1.MergedBits.grpMTIM
#define SCG_C1_FTM                      _SCG_C1.MergedBits.grpFTM

#define SCG_C1_RTC_MASK                 1U
#define SCG_C1_MTIM0_MASK               2U
#define SCG_C1_MTIM1_MASK               4U
#define SCG_C1_FTM0_MASK                32U
#define SCG_C1_FTM1_MASK                64U
#define SCG_C1_FTM2_MASK                128U
#define SCG_C1_MTIM_MASK                6U
#define SCG_C1_MTIM_BITNUM              1U
#define SCG_C1_FTM_MASK                 224U
#define SCG_C1_FTM_BITNUM               5U


/*** SCG_C2 - System Clock Gating Control 2 Register; 0x0000300D ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte CRC         :1;                                       /* CRC Clock Gate Control */
    byte IPC         :1;                                       /* IPC Clock Gate Control */
    byte NVM         :1;                                       /* NVM Clock Gate Control */
    byte DBG         :1;                                       /* DBG Clock Gate Control */
    byte             :1; 
    byte             :1; 
  } Bits;
} SCG_C2STR;
extern volatile SCG_C2STR _SCG_C2 @0x0000300D;
#define SCG_C2                          _SCG_C2.Byte
#define SCG_C2_CRC                      _SCG_C2.Bits.CRC
#define SCG_C2_IPC                      _SCG_C2.Bits.IPC
#define SCG_C2_NVM                      _SCG_C2.Bits.NVM
#define SCG_C2_DBG                      _SCG_C2.Bits.DBG

#define SCG_C2_CRC_MASK                 4U
#define SCG_C2_IPC_MASK                 8U
#define SCG_C2_NVM_MASK                 16U
#define SCG_C2_DBG_MASK                 32U


/*** SCG_C3 - System Clock Gating Control 3 Register; 0x0000300E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte IIC         :1;                                       /* IIC Clock Gate Control */
    byte SPI0        :1;                                       /* SPI0 Clock Gate Control */
    byte SPI1        :1;                                       /* SPI1 Clock Gate Control */
    byte SCI0        :1;                                       /* SCI0 Clock Gate Control */
    byte SCI1        :1;                                       /* SCI1 Clock Gate Control */
    byte SCI2        :1;                                       /* SCI2 Clock Gate Control */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpSPI  :2;
    byte grpSCI  :3;
    byte         :1;
  } MergedBits;
} SCG_C3STR;
extern volatile SCG_C3STR _SCG_C3 @0x0000300E;
#define SCG_C3                          _SCG_C3.Byte
#define SCG_C3_IIC                      _SCG_C3.Bits.IIC
#define SCG_C3_SPI0                     _SCG_C3.Bits.SPI0
#define SCG_C3_SPI1                     _SCG_C3.Bits.SPI1
#define SCG_C3_SCI0                     _SCG_C3.Bits.SCI0
#define SCG_C3_SCI1                     _SCG_C3.Bits.SCI1
#define SCG_C3_SCI2                     _SCG_C3.Bits.SCI2
#define SCG_C3_SPI                      _SCG_C3.MergedBits.grpSPI
#define SCG_C3_SCI                      _SCG_C3.MergedBits.grpSCI

#define SCG_C3_IIC_MASK                 2U
#define SCG_C3_SPI0_MASK                4U
#define SCG_C3_SPI1_MASK                8U
#define SCG_C3_SCI0_MASK                16U
#define SCG_C3_SCI1_MASK                32U
#define SCG_C3_SCI2_MASK                64U
#define SCG_C3_SPI_MASK                 12U
#define SCG_C3_SPI_BITNUM               2U
#define SCG_C3_SCI_MASK                 112U
#define SCG_C3_SCI_BITNUM               4U


/*** SCG_C4 - System Clock Gating Control 4 Register; 0x0000300F ***/
typedef union {
  byte Byte;
  struct {
    byte KBI0        :1;                                       /* KBI0 Clock Gate Control */
    byte KBI1        :1;                                       /* KBI1 Clock Gate Control */
    byte TSI         :1;                                       /* TSI Clock Gate Control */
    byte IRQ         :1;                                       /* IRQ Clock Gate Control */
    byte             :1; 
    byte ADC         :1;                                       /* ADC Clock Gate Control */
    byte             :1; 
    byte ACMP        :1;                                       /* ACMP Clock Gate Control */
  } Bits;
  struct {
    byte grpKBI  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SCG_C4STR;
extern volatile SCG_C4STR _SCG_C4 @0x0000300F;
#define SCG_C4                          _SCG_C4.Byte
#define SCG_C4_KBI0                     _SCG_C4.Bits.KBI0
#define SCG_C4_KBI1                     _SCG_C4.Bits.KBI1
#define SCG_C4_TSI                      _SCG_C4.Bits.TSI
#define SCG_C4_IRQ                      _SCG_C4.Bits.IRQ
#define SCG_C4_ADC                      _SCG_C4.Bits.ADC
#define SCG_C4_ACMP                     _SCG_C4.Bits.ACMP
#define SCG_C4_KBI                      _SCG_C4.MergedBits.grpKBI

#define SCG_C4_KBI0_MASK                1U
#define SCG_C4_KBI1_MASK                2U
#define SCG_C4_TSI_MASK                 4U
#define SCG_C4_IRQ_MASK                 8U
#define SCG_C4_ADC_MASK                 32U
#define SCG_C4_ACMP_MASK                128U
#define SCG_C4_KBI_MASK                 3U
#define SCG_C4_KBI_BITNUM               0U


/*** DBG_CAH - Debug Comparator A High Register; 0x00003010 ***/
typedef union {
  byte Byte;
} DBG_CAHSTR;
extern volatile DBG_CAHSTR _DBG_CAH @0x00003010;
#define DBG_CAH                         _DBG_CAH.Byte


/*** DBG_CAL - Debug Comparator A Low Register; 0x00003011 ***/
typedef union {
  byte Byte;
} DBG_CALSTR;
extern volatile DBG_CALSTR _DBG_CAL @0x00003011;
#define DBG_CAL                         _DBG_CAL.Byte


/*** DBG_CBH - Debug Comparator B High Register; 0x00003012 ***/
typedef union {
  byte Byte;
} DBG_CBHSTR;
extern volatile DBG_CBHSTR _DBG_CBH @0x00003012;
#define DBG_CBH                         _DBG_CBH.Byte


/*** DBG_CBL - Debug Comparator B Low Register; 0x00003013 ***/
typedef union {
  byte Byte;
} DBG_CBLSTR;
extern volatile DBG_CBLSTR _DBG_CBL @0x00003013;
#define DBG_CBL                         _DBG_CBL.Byte


/*** DBG_CCH - Debug Comparator C High Register; 0x00003014 ***/
typedef union {
  byte Byte;
} DBG_CCHSTR;
extern volatile DBG_CCHSTR _DBG_CCH @0x00003014;
#define DBG_CCH                         _DBG_CCH.Byte


/*** DBG_CCL - Debug Comparator C Low Register; 0x00003015 ***/
typedef union {
  byte Byte;
} DBG_CCLSTR;
extern volatile DBG_CCLSTR _DBG_CCL @0x00003015;
#define DBG_CCL                         _DBG_CCL.Byte


/*** DBG_FH - Debug FIFO High Register; 0x00003016 ***/
typedef union {
  byte Byte;
} DBG_FHSTR;
extern volatile DBG_FHSTR _DBG_FH @0x00003016;
#define DBG_FH                          _DBG_FH.Byte


/*** DBG_FL - Debug FIFO Low Register; 0x00003017 ***/
typedef union {
  byte Byte;
} DBG_FLSTR;
extern volatile DBG_FLSTR _DBG_FL @0x00003017;
#define DBG_FL                          _DBG_FL.Byte


/*** DBG_CAX - Debug Comparator A Extension Register; 0x00003018 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RWA         :1;                                       /* Read/Write Comparator A Value Bit */
    byte RWAEN       :1;                                       /* Read/Write Comparator A Enable Bit */
  } Bits;
} DBG_CAXSTR;
extern volatile DBG_CAXSTR _DBG_CAX @0x00003018;
#define DBG_CAX                         _DBG_CAX.Byte
#define DBG_CAX_RWA                     _DBG_CAX.Bits.RWA
#define DBG_CAX_RWAEN                   _DBG_CAX.Bits.RWAEN

#define DBG_CAX_RWA_MASK                64U
#define DBG_CAX_RWAEN_MASK              128U


/*** DBG_CBX - Debug Comparator B Extension Register; 0x00003019 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RWB         :1;                                       /* Read/Write Comparator B Value Bit */
    byte RWBEN       :1;                                       /* Read/Write Comparator B Enable Bit */
  } Bits;
} DBG_CBXSTR;
extern volatile DBG_CBXSTR _DBG_CBX @0x00003019;
#define DBG_CBX                         _DBG_CBX.Byte
#define DBG_CBX_RWB                     _DBG_CBX.Bits.RWB
#define DBG_CBX_RWBEN                   _DBG_CBX.Bits.RWBEN

#define DBG_CBX_RWB_MASK                64U
#define DBG_CBX_RWBEN_MASK              128U


/*** DBG_CCX - Debug Comparator C Extension Register; 0x0000301A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RWC         :1;                                       /* Read/Write Comparator C Value Bit */
    byte RWCEN       :1;                                       /* Read/Write Comparator C Enable Bit */
  } Bits;
} DBG_CCXSTR;
extern volatile DBG_CCXSTR _DBG_CCX @0x0000301A;
#define DBG_CCX                         _DBG_CCX.Byte
#define DBG_CCX_RWC                     _DBG_CCX.Bits.RWC
#define DBG_CCX_RWCEN                   _DBG_CCX.Bits.RWCEN

#define DBG_CCX_RWC_MASK                64U
#define DBG_CCX_RWCEN_MASK              128U


/*** DBG_FX - Debug FIFO Extended Information Register; 0x0000301B ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* Extended Address Bit 16 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PPACC       :1;                                       /* PPAGE Access Indicator Bit */
  } Bits;
} DBG_FXSTR;
extern volatile DBG_FXSTR _DBG_FX @0x0000301B;
#define DBG_FX                          _DBG_FX.Byte
#define DBG_FX_Bit16                    _DBG_FX.Bits.Bit16
#define DBG_FX_PPACC                    _DBG_FX.Bits.PPACC

#define DBG_FX_Bit16_MASK               1U
#define DBG_FX_PPACC_MASK               128U


/*** DBG_C - Debug Control Register; 0x0000301C ***/
typedef union {
  byte Byte;
  struct {
    byte LOOP1       :1;                                       /* Select LOOP1 Capture Mode */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte BRKEN       :1;                                       /* Break Enable Bit */
    byte TAG         :1;                                       /* Tag or Force Bit */
    byte ARM         :1;                                       /* Arm Bit */
    byte DBGEN       :1;                                       /* DBG Module Enable Bit */
  } Bits;
} DBG_CSTR;
extern volatile DBG_CSTR _DBG_C @0x0000301C;
#define DBG_C                           _DBG_C.Byte
#define DBG_C_LOOP1                     _DBG_C.Bits.LOOP1
#define DBG_C_BRKEN                     _DBG_C.Bits.BRKEN
#define DBG_C_TAG                       _DBG_C.Bits.TAG
#define DBG_C_ARM                       _DBG_C.Bits.ARM
#define DBG_C_DBGEN                     _DBG_C.Bits.DBGEN

#define DBG_C_LOOP1_MASK                1U
#define DBG_C_BRKEN_MASK                16U
#define DBG_C_TAG_MASK                  32U
#define DBG_C_ARM_MASK                  64U
#define DBG_C_DBGEN_MASK                128U


/*** DBG_T - Debug Trigger Register; 0x0000301D ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Trigger Mode Bits, bit 0 */
    byte TRG1        :1;                                       /* Trigger Mode Bits, bit 1 */
    byte TRG2        :1;                                       /* Trigger Mode Bits, bit 2 */
    byte TRG3        :1;                                       /* Trigger Mode Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       /* Begin/End Trigger Bit */
    byte TRGSEL      :1;                                       /* Trigger Selection Bit */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBG_TSTR;
extern volatile DBG_TSTR _DBG_T @0x0000301D;
#define DBG_T                           _DBG_T.Byte
#define DBG_T_TRG0                      _DBG_T.Bits.TRG0
#define DBG_T_TRG1                      _DBG_T.Bits.TRG1
#define DBG_T_TRG2                      _DBG_T.Bits.TRG2
#define DBG_T_TRG3                      _DBG_T.Bits.TRG3
#define DBG_T_BEGIN                     _DBG_T.Bits.BEGIN
#define DBG_T_TRGSEL                    _DBG_T.Bits.TRGSEL
#define DBG_T_TRG                       _DBG_T.MergedBits.grpTRG

#define DBG_T_TRG0_MASK                 1U
#define DBG_T_TRG1_MASK                 2U
#define DBG_T_TRG2_MASK                 4U
#define DBG_T_TRG3_MASK                 8U
#define DBG_T_BEGIN_MASK                64U
#define DBG_T_TRGSEL_MASK               128U
#define DBG_T_TRG_MASK                  15U
#define DBG_T_TRG_BITNUM                0U


/*** DBG_S - Debug Status Register; 0x0000301E ***/
typedef union {
  byte Byte;
  struct {
    byte ARMF        :1;                                       /* Arm Flag Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CF          :1;                                       /* Trigger C Match Bit */
    byte BF          :1;                                       /* Trigger B Match Bit */
    byte AF          :1;                                       /* Trigger A Match Bit */
  } Bits;
} DBG_SSTR;
extern volatile DBG_SSTR _DBG_S @0x0000301E;
#define DBG_S                           _DBG_S.Byte
#define DBG_S_ARMF                      _DBG_S.Bits.ARMF
#define DBG_S_CF                        _DBG_S.Bits.CF
#define DBG_S_BF                        _DBG_S.Bits.BF
#define DBG_S_AF                        _DBG_S.Bits.AF

#define DBG_S_ARMF_MASK                 1U
#define DBG_S_CF_MASK                   32U
#define DBG_S_BF_MASK                   64U
#define DBG_S_AF_MASK                   128U


/*** DBG_CNT - Debug Count Status Register; 0x0000301F ***/
typedef union {
  byte Byte;
  struct {
    byte CNT         :4;                                       /* FIFO Valid Count Bitss */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} DBG_CNTSTR;
extern volatile DBG_CNTSTR _DBG_CNT @0x0000301F;
#define DBG_CNT                         _DBG_CNT.Byte
#define DBG_CNT_CNT                     _DBG_CNT.Bits.CNT

#define DBG_CNT_CNT_MASK                15U
#define DBG_CNT_CNT_BITNUM              0U


/*** NVM_FCLKDIV - Flash Clock Divider Register; 0x00003020 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Clock Divider Bits, bit 0 */
    byte FDIV1       :1;                                       /* Clock Divider Bits, bit 1 */
    byte FDIV2       :1;                                       /* Clock Divider Bits, bit 2 */
    byte FDIV3       :1;                                       /* Clock Divider Bits, bit 3 */
    byte FDIV4       :1;                                       /* Clock Divider Bits, bit 4 */
    byte FDIV5       :1;                                       /* Clock Divider Bits, bit 5 */
    byte FDIVLCK     :1;                                       /* Clock Divider Locked */
    byte FDIVLD      :1;                                       /* Clock Divider Loaded */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVM_FCLKDIVSTR;
extern volatile NVM_FCLKDIVSTR _NVM_FCLKDIV @0x00003020;
#define NVM_FCLKDIV                     _NVM_FCLKDIV.Byte
#define NVM_FCLKDIV_FDIV0               _NVM_FCLKDIV.Bits.FDIV0
#define NVM_FCLKDIV_FDIV1               _NVM_FCLKDIV.Bits.FDIV1
#define NVM_FCLKDIV_FDIV2               _NVM_FCLKDIV.Bits.FDIV2
#define NVM_FCLKDIV_FDIV3               _NVM_FCLKDIV.Bits.FDIV3
#define NVM_FCLKDIV_FDIV4               _NVM_FCLKDIV.Bits.FDIV4
#define NVM_FCLKDIV_FDIV5               _NVM_FCLKDIV.Bits.FDIV5
#define NVM_FCLKDIV_FDIVLCK             _NVM_FCLKDIV.Bits.FDIVLCK
#define NVM_FCLKDIV_FDIVLD              _NVM_FCLKDIV.Bits.FDIVLD
#define NVM_FCLKDIV_FDIV                _NVM_FCLKDIV.MergedBits.grpFDIV

#define NVM_FCLKDIV_FDIV0_MASK          1U
#define NVM_FCLKDIV_FDIV1_MASK          2U
#define NVM_FCLKDIV_FDIV2_MASK          4U
#define NVM_FCLKDIV_FDIV3_MASK          8U
#define NVM_FCLKDIV_FDIV4_MASK          16U
#define NVM_FCLKDIV_FDIV5_MASK          32U
#define NVM_FCLKDIV_FDIVLCK_MASK        64U
#define NVM_FCLKDIV_FDIVLD_MASK         128U
#define NVM_FCLKDIV_FDIV_MASK           63U
#define NVM_FCLKDIV_FDIV_BITNUM         0U


/*** NVM_FSEC - Flash Security Register; 0x00003021 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1; 
    byte SEC1        :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1; 
    byte KEYEN1      :1; 
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} NVM_FSECSTR;
extern volatile NVM_FSECSTR _NVM_FSEC @0x00003021;
#define NVM_FSEC                        _NVM_FSEC.Byte
#define NVM_FSEC_SEC0                   _NVM_FSEC.Bits.SEC0
#define NVM_FSEC_SEC1                   _NVM_FSEC.Bits.SEC1
#define NVM_FSEC_KEYEN0                 _NVM_FSEC.Bits.KEYEN0
#define NVM_FSEC_KEYEN1                 _NVM_FSEC.Bits.KEYEN1
#define NVM_FSEC_SEC                    _NVM_FSEC.MergedBits.grpSEC
#define NVM_FSEC_KEYEN                  _NVM_FSEC.MergedBits.grpKEYEN

#define NVM_FSEC_SEC0_MASK              1U
#define NVM_FSEC_SEC1_MASK              2U
#define NVM_FSEC_KEYEN0_MASK            64U
#define NVM_FSEC_KEYEN1_MASK            128U
#define NVM_FSEC_SEC_MASK               3U
#define NVM_FSEC_SEC_BITNUM             0U
#define NVM_FSEC_KEYEN_MASK             192U
#define NVM_FSEC_KEYEN_BITNUM           6U


/*** NVM_FCCOBIX - Flash CCOB Index Register; 0x00003022 ***/
typedef union {
  byte Byte;
  struct {
    byte CCOBIX0     :1;                                       /* Common Command Register Index, bit 0 */
    byte CCOBIX1     :1;                                       /* Common Command Register Index, bit 1 */
    byte CCOBIX2     :1;                                       /* Common Command Register Index, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCCOBIX :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVM_FCCOBIXSTR;
extern volatile NVM_FCCOBIXSTR _NVM_FCCOBIX @0x00003022;
#define NVM_FCCOBIX                     _NVM_FCCOBIX.Byte
#define NVM_FCCOBIX_CCOBIX0             _NVM_FCCOBIX.Bits.CCOBIX0
#define NVM_FCCOBIX_CCOBIX1             _NVM_FCCOBIX.Bits.CCOBIX1
#define NVM_FCCOBIX_CCOBIX2             _NVM_FCCOBIX.Bits.CCOBIX2
#define NVM_FCCOBIX_CCOBIX              _NVM_FCCOBIX.MergedBits.grpCCOBIX

#define NVM_FCCOBIX_CCOBIX0_MASK        1U
#define NVM_FCCOBIX_CCOBIX1_MASK        2U
#define NVM_FCCOBIX_CCOBIX2_MASK        4U
#define NVM_FCCOBIX_CCOBIX_MASK         7U
#define NVM_FCCOBIX_CCOBIX_BITNUM       0U


/*** NVM_FCNFG - Flash Configuration Register; 0x00003024 ***/
typedef union {
  byte Byte;
  struct {
    byte FSFD        :1;                                       /* Force Single Bit Fault Detect */
    byte FDFD        :1;                                       /* Force Double Bit Fault Detect */
    byte             :1; 
    byte             :1; 
    byte IGNSF       :1;                                       /* Ignore Single Bit Fault */
    byte             :1; 
    byte             :1; 
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
  } Bits;
} NVM_FCNFGSTR;
extern volatile NVM_FCNFGSTR _NVM_FCNFG @0x00003024;
#define NVM_FCNFG                       _NVM_FCNFG.Byte
#define NVM_FCNFG_FSFD                  _NVM_FCNFG.Bits.FSFD
#define NVM_FCNFG_FDFD                  _NVM_FCNFG.Bits.FDFD
#define NVM_FCNFG_IGNSF                 _NVM_FCNFG.Bits.IGNSF
#define NVM_FCNFG_CCIE                  _NVM_FCNFG.Bits.CCIE

#define NVM_FCNFG_FSFD_MASK             1U
#define NVM_FCNFG_FDFD_MASK             2U
#define NVM_FCNFG_IGNSF_MASK            16U
#define NVM_FCNFG_CCIE_MASK             128U


/*** NVM_FERCNFG - Flash Error Configuration Register; 0x00003025 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIE       :1;                                       /* Single Bit Fault Detect Interrupt Enable */
    byte DFDIE       :1;                                       /* Double Bit Fault Detect Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVM_FERCNFGSTR;
extern volatile NVM_FERCNFGSTR _NVM_FERCNFG @0x00003025;
#define NVM_FERCNFG                     _NVM_FERCNFG.Byte
#define NVM_FERCNFG_SFDIE               _NVM_FERCNFG.Bits.SFDIE
#define NVM_FERCNFG_DFDIE               _NVM_FERCNFG.Bits.DFDIE

#define NVM_FERCNFG_SFDIE_MASK          1U
#define NVM_FERCNFG_DFDIE_MASK          2U


/*** NVM_FSTAT - Flash Status Register; 0x00003026 ***/
typedef union {
  byte Byte;
  struct {
    byte MGSTAT0     :1; 
    byte MGSTAT1     :1; 
    byte             :1; 
    byte MGBUSY      :1;                                       /* Memory Controller Busy Flag */
    byte FPVIOL      :1;                                       /* Flash Protection Violation Flag */
    byte ACCERR      :1;                                       /* Flash Access Error Flag */
    byte             :1; 
    byte CCIF        :1;                                       /* Command Complete Interrupt Flag */
  } Bits;
  struct {
    byte grpMGSTAT :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVM_FSTATSTR;
extern volatile NVM_FSTATSTR _NVM_FSTAT @0x00003026;
#define NVM_FSTAT                       _NVM_FSTAT.Byte
#define NVM_FSTAT_MGSTAT0               _NVM_FSTAT.Bits.MGSTAT0
#define NVM_FSTAT_MGSTAT1               _NVM_FSTAT.Bits.MGSTAT1
#define NVM_FSTAT_MGBUSY                _NVM_FSTAT.Bits.MGBUSY
#define NVM_FSTAT_FPVIOL                _NVM_FSTAT.Bits.FPVIOL
#define NVM_FSTAT_ACCERR                _NVM_FSTAT.Bits.ACCERR
#define NVM_FSTAT_CCIF                  _NVM_FSTAT.Bits.CCIF
#define NVM_FSTAT_MGSTAT                _NVM_FSTAT.MergedBits.grpMGSTAT

#define NVM_FSTAT_MGSTAT0_MASK          1U
#define NVM_FSTAT_MGSTAT1_MASK          2U
#define NVM_FSTAT_MGBUSY_MASK           8U
#define NVM_FSTAT_FPVIOL_MASK           16U
#define NVM_FSTAT_ACCERR_MASK           32U
#define NVM_FSTAT_CCIF_MASK             128U
#define NVM_FSTAT_MGSTAT_MASK           3U
#define NVM_FSTAT_MGSTAT_BITNUM         0U


/*** NVM_FERSTAT - Flash Error Status Register; 0x00003027 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIF       :1;                                       /* Single Bit Fault Detect Interrupt Flag */
    byte DFDIF       :1;                                       /* Double Bit Fault Detect Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVM_FERSTATSTR;
extern volatile NVM_FERSTATSTR _NVM_FERSTAT @0x00003027;
#define NVM_FERSTAT                     _NVM_FERSTAT.Byte
#define NVM_FERSTAT_SFDIF               _NVM_FERSTAT.Bits.SFDIF
#define NVM_FERSTAT_DFDIF               _NVM_FERSTAT.Bits.DFDIF

#define NVM_FERSTAT_SFDIF_MASK          1U
#define NVM_FERSTAT_DFDIF_MASK          2U


/*** NVM_FPROT - Flash Protection Register; 0x00003028 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1; 
    byte FPLS1       :1; 
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1; 
    byte FPHS1       :1; 
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte             :1; 
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVM_FPROTSTR;
extern volatile NVM_FPROTSTR _NVM_FPROT @0x00003028;
#define NVM_FPROT                       _NVM_FPROT.Byte
#define NVM_FPROT_FPLS0                 _NVM_FPROT.Bits.FPLS0
#define NVM_FPROT_FPLS1                 _NVM_FPROT.Bits.FPLS1
#define NVM_FPROT_FPLDIS                _NVM_FPROT.Bits.FPLDIS
#define NVM_FPROT_FPHS0                 _NVM_FPROT.Bits.FPHS0
#define NVM_FPROT_FPHS1                 _NVM_FPROT.Bits.FPHS1
#define NVM_FPROT_FPHDIS                _NVM_FPROT.Bits.FPHDIS
#define NVM_FPROT_FPOPEN                _NVM_FPROT.Bits.FPOPEN
#define NVM_FPROT_FPLS                  _NVM_FPROT.MergedBits.grpFPLS
#define NVM_FPROT_FPHS                  _NVM_FPROT.MergedBits.grpFPHS

#define NVM_FPROT_FPLS0_MASK            1U
#define NVM_FPROT_FPLS1_MASK            2U
#define NVM_FPROT_FPLDIS_MASK           4U
#define NVM_FPROT_FPHS0_MASK            8U
#define NVM_FPROT_FPHS1_MASK            16U
#define NVM_FPROT_FPHDIS_MASK           32U
#define NVM_FPROT_FPOPEN_MASK           128U
#define NVM_FPROT_FPLS_MASK             3U
#define NVM_FPROT_FPLS_BITNUM           0U
#define NVM_FPROT_FPHS_MASK             24U
#define NVM_FPROT_FPHS_BITNUM           3U


/*** NVM_EEPROT - EEPROM Protection Register; 0x00003029 ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* EEPROM Protection Size, bit 0 */
    byte DPS1        :1;                                       /* EEPROM Protection Size, bit 1 */
    byte DPS2        :1;                                       /* EEPROM Protection Size, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* EEPROM Protection Control */
  } Bits;
  struct {
    byte grpDPS  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVM_EEPROTSTR;
extern volatile NVM_EEPROTSTR _NVM_EEPROT @0x00003029;
#define NVM_EEPROT                      _NVM_EEPROT.Byte
#define NVM_EEPROT_DPS0                 _NVM_EEPROT.Bits.DPS0
#define NVM_EEPROT_DPS1                 _NVM_EEPROT.Bits.DPS1
#define NVM_EEPROT_DPS2                 _NVM_EEPROT.Bits.DPS2
#define NVM_EEPROT_DPOPEN               _NVM_EEPROT.Bits.DPOPEN
#define NVM_EEPROT_DPS                  _NVM_EEPROT.MergedBits.grpDPS

#define NVM_EEPROT_DPS0_MASK            1U
#define NVM_EEPROT_DPS1_MASK            2U
#define NVM_EEPROT_DPS2_MASK            4U
#define NVM_EEPROT_DPOPEN_MASK          128U
#define NVM_EEPROT_DPS_MASK             7U
#define NVM_EEPROT_DPS_BITNUM           0U


/*** NVM_FCCOB - Flash Common Command Object Register; 0x0000302A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** NVM_FCCOBHI - Flash Common Command Object Register:High; 0x0000302A ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Common Command Object Bit 15:8, bit 0 */
        byte CCOB1       :1;                                       /* Common Command Object Bit 15:8, bit 1 */
        byte CCOB2       :1;                                       /* Common Command Object Bit 15:8, bit 2 */
        byte CCOB3       :1;                                       /* Common Command Object Bit 15:8, bit 3 */
        byte CCOB4       :1;                                       /* Common Command Object Bit 15:8, bit 4 */
        byte CCOB5       :1;                                       /* Common Command Object Bit 15:8, bit 5 */
        byte CCOB6       :1;                                       /* Common Command Object Bit 15:8, bit 6 */
        byte CCOB7       :1;                                       /* Common Command Object Bit 15:8, bit 7 */
      } Bits;
    } NVM_FCCOBHISTR;
    #define NVM_FCCOBHI                 _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Byte
    #define NVM_FCCOBHI_CCOB0           _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Bits.CCOB0
    #define NVM_FCCOBHI_CCOB1           _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Bits.CCOB1
    #define NVM_FCCOBHI_CCOB2           _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Bits.CCOB2
    #define NVM_FCCOBHI_CCOB3           _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Bits.CCOB3
    #define NVM_FCCOBHI_CCOB4           _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Bits.CCOB4
    #define NVM_FCCOBHI_CCOB5           _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Bits.CCOB5
    #define NVM_FCCOBHI_CCOB6           _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Bits.CCOB6
    #define NVM_FCCOBHI_CCOB7           _NVM_FCCOB.Overlap_STR.NVM_FCCOBHISTR.Bits.CCOB7
    
    #define NVM_FCCOBHI_CCOB0_MASK      1U
    #define NVM_FCCOBHI_CCOB1_MASK      2U
    #define NVM_FCCOBHI_CCOB2_MASK      4U
    #define NVM_FCCOBHI_CCOB3_MASK      8U
    #define NVM_FCCOBHI_CCOB4_MASK      16U
    #define NVM_FCCOBHI_CCOB5_MASK      32U
    #define NVM_FCCOBHI_CCOB6_MASK      64U
    #define NVM_FCCOBHI_CCOB7_MASK      128U
    

    /*** NVM_FCCOBLO - Flash Common Command Object Register: Low; 0x0000302B ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Common Command Object Bit 7:0, bit 0 */
        byte CCOB1       :1;                                       /* Common Command Object Bit 7:0, bit 1 */
        byte CCOB2       :1;                                       /* Common Command Object Bit 7:0, bit 2 */
        byte CCOB3       :1;                                       /* Common Command Object Bit 7:0, bit 3 */
        byte CCOB4       :1;                                       /* Common Command Object Bit 7:0, bit 4 */
        byte CCOB5       :1;                                       /* Common Command Object Bit 7:0, bit 5 */
        byte CCOB6       :1;                                       /* Common Command Object Bit 7:0, bit 6 */
        byte CCOB7       :1;                                       /* Common Command Object Bit 7:0, bit 7 */
      } Bits;
    } NVM_FCCOBLOSTR;
    #define NVM_FCCOBLO                 _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Byte
    #define NVM_FCCOBLO_CCOB0           _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Bits.CCOB0
    #define NVM_FCCOBLO_CCOB1           _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Bits.CCOB1
    #define NVM_FCCOBLO_CCOB2           _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Bits.CCOB2
    #define NVM_FCCOBLO_CCOB3           _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Bits.CCOB3
    #define NVM_FCCOBLO_CCOB4           _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Bits.CCOB4
    #define NVM_FCCOBLO_CCOB5           _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Bits.CCOB5
    #define NVM_FCCOBLO_CCOB6           _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Bits.CCOB6
    #define NVM_FCCOBLO_CCOB7           _NVM_FCCOB.Overlap_STR.NVM_FCCOBLOSTR.Bits.CCOB7
    
    #define NVM_FCCOBLO_CCOB0_MASK      1U
    #define NVM_FCCOBLO_CCOB1_MASK      2U
    #define NVM_FCCOBLO_CCOB2_MASK      4U
    #define NVM_FCCOBLO_CCOB3_MASK      8U
    #define NVM_FCCOBLO_CCOB4_MASK      16U
    #define NVM_FCCOBLO_CCOB5_MASK      32U
    #define NVM_FCCOBLO_CCOB6_MASK      64U
    #define NVM_FCCOBLO_CCOB7_MASK      128U
    
  } Overlap_STR;

} NVM_FCCOBSTR;
extern volatile NVM_FCCOBSTR _NVM_FCCOB @0x0000302A;
#define NVM_FCCOB                       _NVM_FCCOB.Word


/*** NVM_FOPT - Flash Option Register; 0x0000302C ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bits, bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bits, bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bits, bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bits, bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bits, bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bits, bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bits, bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bits, bit 7 */
  } Bits;
} NVM_FOPTSTR;
extern volatile NVM_FOPTSTR _NVM_FOPT @0x0000302C;
#define NVM_FOPT                        _NVM_FOPT.Byte
#define NVM_FOPT_NV0                    _NVM_FOPT.Bits.NV0
#define NVM_FOPT_NV1                    _NVM_FOPT.Bits.NV1
#define NVM_FOPT_NV2                    _NVM_FOPT.Bits.NV2
#define NVM_FOPT_NV3                    _NVM_FOPT.Bits.NV3
#define NVM_FOPT_NV4                    _NVM_FOPT.Bits.NV4
#define NVM_FOPT_NV5                    _NVM_FOPT.Bits.NV5
#define NVM_FOPT_NV6                    _NVM_FOPT.Bits.NV6
#define NVM_FOPT_NV7                    _NVM_FOPT.Bits.NV7

#define NVM_FOPT_NV0_MASK               1U
#define NVM_FOPT_NV1_MASK               2U
#define NVM_FOPT_NV2_MASK               4U
#define NVM_FOPT_NV3_MASK               8U
#define NVM_FOPT_NV4_MASK               16U
#define NVM_FOPT_NV5_MASK               32U
#define NVM_FOPT_NV6_MASK               64U
#define NVM_FOPT_NV7_MASK               128U


/*** WDOG_CS1 - Watchdog Control and Status Register 1; 0x00003030 ***/
typedef union {
  byte Byte;
  struct {
    byte STOP        :1;                                       /* Stop Enable */
    byte WAIT        :1;                                       /* Wait Enable */
    byte DBG         :1;                                       /* Debug Enable */
    byte TST0        :1;                                       /* Watchdog Test, bit 0 */
    byte TST1        :1;                                       /* Watchdog Test, bit 1 */
    byte UPDATE      :1;                                       /* Allow updates */
    byte INT         :1;                                       /* Watchdog Interrupt */
    byte EN          :1;                                       /* Watchdog Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTST  :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} WDOG_CS1STR;
extern volatile WDOG_CS1STR _WDOG_CS1 @0x00003030;
#define WDOG_CS1                        _WDOG_CS1.Byte
#define WDOG_CS1_STOP                   _WDOG_CS1.Bits.STOP
#define WDOG_CS1_WAIT                   _WDOG_CS1.Bits.WAIT
#define WDOG_CS1_DBG                    _WDOG_CS1.Bits.DBG
#define WDOG_CS1_TST0                   _WDOG_CS1.Bits.TST0
#define WDOG_CS1_TST1                   _WDOG_CS1.Bits.TST1
#define WDOG_CS1_UPDATE                 _WDOG_CS1.Bits.UPDATE
#define WDOG_CS1_INT                    _WDOG_CS1.Bits.INT
#define WDOG_CS1_EN                     _WDOG_CS1.Bits.EN
#define WDOG_CS1_TST                    _WDOG_CS1.MergedBits.grpTST

#define WDOG_CS1_STOP_MASK              1U
#define WDOG_CS1_WAIT_MASK              2U
#define WDOG_CS1_DBG_MASK               4U
#define WDOG_CS1_TST0_MASK              8U
#define WDOG_CS1_TST1_MASK              16U
#define WDOG_CS1_UPDATE_MASK            32U
#define WDOG_CS1_INT_MASK               64U
#define WDOG_CS1_EN_MASK                128U
#define WDOG_CS1_TST_MASK               24U
#define WDOG_CS1_TST_BITNUM             3U


/*** WDOG_CS2 - Watchdog Control and Status Register 2; 0x00003031 ***/
typedef union {
  byte Byte;
  struct {
    byte CLK0        :1;                                       /* Watchdog Clock, bit 0 */
    byte CLK1        :1;                                       /* Watchdog Clock, bit 1 */
    byte             :1; 
    byte             :1; 
    byte PRES        :1;                                       /* Watchdog Prescalar */
    byte             :1; 
    byte FLG         :1;                                       /* Watchdog Interrupt Flag */
    byte WIN         :1;                                       /* Watchdog Window */
  } Bits;
  struct {
    byte grpCLK  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} WDOG_CS2STR;
extern volatile WDOG_CS2STR _WDOG_CS2 @0x00003031;
#define WDOG_CS2                        _WDOG_CS2.Byte
#define WDOG_CS2_CLK0                   _WDOG_CS2.Bits.CLK0
#define WDOG_CS2_CLK1                   _WDOG_CS2.Bits.CLK1
#define WDOG_CS2_PRES                   _WDOG_CS2.Bits.PRES
#define WDOG_CS2_FLG                    _WDOG_CS2.Bits.FLG
#define WDOG_CS2_WIN                    _WDOG_CS2.Bits.WIN
#define WDOG_CS2_CLK                    _WDOG_CS2.MergedBits.grpCLK

#define WDOG_CS2_CLK0_MASK              1U
#define WDOG_CS2_CLK1_MASK              2U
#define WDOG_CS2_PRES_MASK              16U
#define WDOG_CS2_FLG_MASK               64U
#define WDOG_CS2_WIN_MASK               128U
#define WDOG_CS2_CLK_MASK               3U
#define WDOG_CS2_CLK_BITNUM             0U


/*** WDOG_CNT - Watchdog Counter Register; 0x00003032 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** WDOG_CNTH - Watchdog Counter Register: High; 0x00003032 ***/
    union {
      byte Byte;
    } WDOG_CNTHSTR;
    #define WDOG_CNTH                   _WDOG_CNT.Overlap_STR.WDOG_CNTHSTR.Byte
    

    /*** WDOG_CNTL - Watchdog Counter Register: Low; 0x00003033 ***/
    union {
      byte Byte;
    } WDOG_CNTLSTR;
    #define WDOG_CNTL                   _WDOG_CNT.Overlap_STR.WDOG_CNTLSTR.Byte
    
  } Overlap_STR;

} WDOG_CNTSTR;
extern volatile WDOG_CNTSTR _WDOG_CNT @0x00003032;
#define WDOG_CNT                        _WDOG_CNT.Word


/*** WDOG_TOVAL - Watchdog Timer Register; 0x00003034 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** WDOG_TOVALH - Watchdog Timeout Value Register: High; 0x00003034 ***/
    union {
      byte Byte;
    } WDOG_TOVALHSTR;
    #define WDOG_TOVALH                 _WDOG_TOVAL.Overlap_STR.WDOG_TOVALHSTR.Byte
    

    /*** WDOG_TOVALL - Watchdog Timeout Value Register: Low; 0x00003035 ***/
    union {
      byte Byte;
    } WDOG_TOVALLSTR;
    #define WDOG_TOVALL                 _WDOG_TOVAL.Overlap_STR.WDOG_TOVALLSTR.Byte
    
  } Overlap_STR;

} WDOG_TOVALSTR;
extern volatile WDOG_TOVALSTR _WDOG_TOVAL @0x00003034;
#define WDOG_TOVAL                      _WDOG_TOVAL.Word


/*** WDOG_WIN - Watchdog Window Register; 0x00003036 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** WDOG_WINH - Watchdog Window Register: High; 0x00003036 ***/
    union {
      byte Byte;
    } WDOG_WINHSTR;
    #define WDOG_WINH                   _WDOG_WIN.Overlap_STR.WDOG_WINHSTR.Byte
    

    /*** WDOG_WINL - Watchdog Window Register: Low; 0x00003037 ***/
    union {
      byte Byte;
    } WDOG_WINLSTR;
    #define WDOG_WINL                   _WDOG_WIN.Overlap_STR.WDOG_WINLSTR.Byte
    
  } Overlap_STR;

} WDOG_WINSTR;
extern volatile WDOG_WINSTR _WDOG_WIN @0x00003036;
#define WDOG_WIN                        _WDOG_WIN.Word


/*** ICS_C1 - ICS Control Register 1; 0x00003038 ***/
typedef union {
  byte Byte;
  struct {
    byte IREFSTEN    :1;                                       /* Internal Reference Stop Enable */
    byte IRCLKEN     :1;                                       /* Internal Reference Clock Enable */
    byte IREFS       :1;                                       /* Internal Reference Select */
    byte RDIV0       :1;                                       /* Reference Divider, bit 0 */
    byte RDIV1       :1;                                       /* Reference Divider, bit 1 */
    byte RDIV2       :1;                                       /* Reference Divider, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Select, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Select, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
    byte grpCLKS :2;
  } MergedBits;
} ICS_C1STR;
extern volatile ICS_C1STR _ICS_C1 @0x00003038;
#define ICS_C1                          _ICS_C1.Byte
#define ICS_C1_IREFSTEN                 _ICS_C1.Bits.IREFSTEN
#define ICS_C1_IRCLKEN                  _ICS_C1.Bits.IRCLKEN
#define ICS_C1_IREFS                    _ICS_C1.Bits.IREFS
#define ICS_C1_RDIV0                    _ICS_C1.Bits.RDIV0
#define ICS_C1_RDIV1                    _ICS_C1.Bits.RDIV1
#define ICS_C1_RDIV2                    _ICS_C1.Bits.RDIV2
#define ICS_C1_CLKS0                    _ICS_C1.Bits.CLKS0
#define ICS_C1_CLKS1                    _ICS_C1.Bits.CLKS1
#define ICS_C1_RDIV                     _ICS_C1.MergedBits.grpRDIV
#define ICS_C1_CLKS                     _ICS_C1.MergedBits.grpCLKS

#define ICS_C1_IREFSTEN_MASK            1U
#define ICS_C1_IRCLKEN_MASK             2U
#define ICS_C1_IREFS_MASK               4U
#define ICS_C1_RDIV0_MASK               8U
#define ICS_C1_RDIV1_MASK               16U
#define ICS_C1_RDIV2_MASK               32U
#define ICS_C1_CLKS0_MASK               64U
#define ICS_C1_CLKS1_MASK               128U
#define ICS_C1_RDIV_MASK                56U
#define ICS_C1_RDIV_BITNUM              3U
#define ICS_C1_CLKS_MASK                192U
#define ICS_C1_CLKS_BITNUM              6U


/*** ICS_C2 - ICS Control Register 2; 0x00003039 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LP          :1;                                       /* Low Power Select */
    byte BDIV0       :1;                                       /* Bus Frequency Divider, bit 0 */
    byte BDIV1       :1;                                       /* Bus Frequency Divider, bit 1 */
    byte BDIV2       :1;                                       /* Bus Frequency Divider, bit 2 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :3;
  } MergedBits;
} ICS_C2STR;
extern volatile ICS_C2STR _ICS_C2 @0x00003039;
#define ICS_C2                          _ICS_C2.Byte
#define ICS_C2_LP                       _ICS_C2.Bits.LP
#define ICS_C2_BDIV0                    _ICS_C2.Bits.BDIV0
#define ICS_C2_BDIV1                    _ICS_C2.Bits.BDIV1
#define ICS_C2_BDIV2                    _ICS_C2.Bits.BDIV2
#define ICS_C2_BDIV                     _ICS_C2.MergedBits.grpBDIV

#define ICS_C2_LP_MASK                  16U
#define ICS_C2_BDIV0_MASK               32U
#define ICS_C2_BDIV1_MASK               64U
#define ICS_C2_BDIV2_MASK               128U
#define ICS_C2_BDIV_MASK                224U
#define ICS_C2_BDIV_BITNUM              5U


/*** ICS_C3 - ICS Control Register 3; 0x0000303A ***/
typedef union {
  byte Byte;
  struct {
    byte SCTRIM0     :1;                                       /* Slow Internal Reference Clock Trim Setting, bit 0 */
    byte SCTRIM1     :1;                                       /* Slow Internal Reference Clock Trim Setting, bit 1 */
    byte SCTRIM2     :1;                                       /* Slow Internal Reference Clock Trim Setting, bit 2 */
    byte SCTRIM3     :1;                                       /* Slow Internal Reference Clock Trim Setting, bit 3 */
    byte SCTRIM4     :1;                                       /* Slow Internal Reference Clock Trim Setting, bit 4 */
    byte SCTRIM5     :1;                                       /* Slow Internal Reference Clock Trim Setting, bit 5 */
    byte SCTRIM6     :1;                                       /* Slow Internal Reference Clock Trim Setting, bit 6 */
    byte SCTRIM7     :1;                                       /* Slow Internal Reference Clock Trim Setting, bit 7 */
  } Bits;
} ICS_C3STR;
extern volatile ICS_C3STR _ICS_C3 @0x0000303A;
#define ICS_C3                          _ICS_C3.Byte
#define ICS_C3_SCTRIM0                  _ICS_C3.Bits.SCTRIM0
#define ICS_C3_SCTRIM1                  _ICS_C3.Bits.SCTRIM1
#define ICS_C3_SCTRIM2                  _ICS_C3.Bits.SCTRIM2
#define ICS_C3_SCTRIM3                  _ICS_C3.Bits.SCTRIM3
#define ICS_C3_SCTRIM4                  _ICS_C3.Bits.SCTRIM4
#define ICS_C3_SCTRIM5                  _ICS_C3.Bits.SCTRIM5
#define ICS_C3_SCTRIM6                  _ICS_C3.Bits.SCTRIM6
#define ICS_C3_SCTRIM7                  _ICS_C3.Bits.SCTRIM7

#define ICS_C3_SCTRIM0_MASK             1U
#define ICS_C3_SCTRIM1_MASK             2U
#define ICS_C3_SCTRIM2_MASK             4U
#define ICS_C3_SCTRIM3_MASK             8U
#define ICS_C3_SCTRIM4_MASK             16U
#define ICS_C3_SCTRIM5_MASK             32U
#define ICS_C3_SCTRIM6_MASK             64U
#define ICS_C3_SCTRIM7_MASK             128U


/*** ICS_C4 - ICS Control Register 4; 0x0000303B ***/
typedef union {
  byte Byte;
  struct {
    byte SCFTRIM     :1;                                       /* Slow Internal Reference Clock Fine Trim */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CME         :1;                                       /* Clock Monitor Enable */
    byte             :1; 
    byte LOLIE       :1;                                       /* Loss of Lock Interrupt */
  } Bits;
} ICS_C4STR;
extern volatile ICS_C4STR _ICS_C4 @0x0000303B;
#define ICS_C4                          _ICS_C4.Byte
#define ICS_C4_SCFTRIM                  _ICS_C4.Bits.SCFTRIM
#define ICS_C4_CME                      _ICS_C4.Bits.CME
#define ICS_C4_LOLIE                    _ICS_C4.Bits.LOLIE

#define ICS_C4_SCFTRIM_MASK             1U
#define ICS_C4_CME_MASK                 32U
#define ICS_C4_LOLIE_MASK               128U


/*** ICS_S - ICS Status Register; 0x0000303C ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte CLKST0      :1;                                       /* Clock Mode Status, bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status, bit 1 */
    byte IREFST      :1;                                       /* Internal Reference Status */
    byte             :1; 
    byte LOCK        :1;                                       /* Lock Status */
    byte LOLS        :1;                                       /* Loss of Lock Status */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpCLKST :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ICS_SSTR;
extern volatile ICS_SSTR _ICS_S @0x0000303C;
#define ICS_S                           _ICS_S.Byte
#define ICS_S_CLKST0                    _ICS_S.Bits.CLKST0
#define ICS_S_CLKST1                    _ICS_S.Bits.CLKST1
#define ICS_S_IREFST                    _ICS_S.Bits.IREFST
#define ICS_S_LOCK                      _ICS_S.Bits.LOCK
#define ICS_S_LOLS                      _ICS_S.Bits.LOLS
#define ICS_S_CLKST                     _ICS_S.MergedBits.grpCLKST

#define ICS_S_CLKST0_MASK               4U
#define ICS_S_CLKST1_MASK               8U
#define ICS_S_IREFST_MASK               16U
#define ICS_S_LOCK_MASK                 64U
#define ICS_S_LOLS_MASK                 128U
#define ICS_S_CLKST_MASK                12U
#define ICS_S_CLKST_BITNUM              2U


/*** ICS_OSCSC - OSC Status and Control Register; 0x0000303E ***/
typedef union {
  byte Byte;
  struct {
    byte OSCINIT     :1;                                       /* OSC Initialization */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte             :1; 
    byte OSCOS       :1;                                       /* OSC Output Select */
    byte OSCSTEN     :1;                                       /* OSC Enable in Stop mode */
    byte             :1; 
    byte OSCEN       :1;                                       /* OSC Enable */
  } Bits;
} ICS_OSCSCSTR;
extern volatile ICS_OSCSCSTR _ICS_OSCSC @0x0000303E;
#define ICS_OSCSC                       _ICS_OSCSC.Byte
#define ICS_OSCSC_OSCINIT               _ICS_OSCSC.Bits.OSCINIT
#define ICS_OSCSC_HGO                   _ICS_OSCSC.Bits.HGO
#define ICS_OSCSC_RANGE                 _ICS_OSCSC.Bits.RANGE
#define ICS_OSCSC_OSCOS                 _ICS_OSCSC.Bits.OSCOS
#define ICS_OSCSC_OSCSTEN               _ICS_OSCSC.Bits.OSCSTEN
#define ICS_OSCSC_OSCEN                 _ICS_OSCSC.Bits.OSCEN

#define ICS_OSCSC_OSCINIT_MASK          1U
#define ICS_OSCSC_HGO_MASK              2U
#define ICS_OSCSC_RANGE_MASK            4U
#define ICS_OSCSC_OSCOS_MASK            16U
#define ICS_OSCSC_OSCSTEN_MASK          32U
#define ICS_OSCSC_OSCEN_MASK            128U


/*** PMC_SPMSC1 - System Power Management Status and Control 1 Register; 0x00003040 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte BGBDS       :1;                                       /* Bandgap Buffer Drive Select */
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning Flag */
  } Bits;
} PMC_SPMSC1STR;
extern volatile PMC_SPMSC1STR _PMC_SPMSC1 @0x00003040;
#define PMC_SPMSC1                      _PMC_SPMSC1.Byte
#define PMC_SPMSC1_BGBE                 _PMC_SPMSC1.Bits.BGBE
#define PMC_SPMSC1_BGBDS                _PMC_SPMSC1.Bits.BGBDS
#define PMC_SPMSC1_LVDE                 _PMC_SPMSC1.Bits.LVDE
#define PMC_SPMSC1_LVDSE                _PMC_SPMSC1.Bits.LVDSE
#define PMC_SPMSC1_LVDRE                _PMC_SPMSC1.Bits.LVDRE
#define PMC_SPMSC1_LVWIE                _PMC_SPMSC1.Bits.LVWIE
#define PMC_SPMSC1_LVWACK               _PMC_SPMSC1.Bits.LVWACK
#define PMC_SPMSC1_LVWF                 _PMC_SPMSC1.Bits.LVWF

#define PMC_SPMSC1_BGBE_MASK            1U
#define PMC_SPMSC1_BGBDS_MASK           2U
#define PMC_SPMSC1_LVDE_MASK            4U
#define PMC_SPMSC1_LVDSE_MASK           8U
#define PMC_SPMSC1_LVDRE_MASK           16U
#define PMC_SPMSC1_LVWIE_MASK           32U
#define PMC_SPMSC1_LVWACK_MASK          64U
#define PMC_SPMSC1_LVWF_MASK            128U


/*** PMC_SPMSC2 - System Power Management Status and Control 2 Register; 0x00003041 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LVWV0       :1;                                       /* Low-Voltage Warning Voltage Select, bit 0 */
    byte LVWV1       :1;                                       /* Low-Voltage Warning Voltage Select, bit 1 */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpLVWV :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMC_SPMSC2STR;
extern volatile PMC_SPMSC2STR _PMC_SPMSC2 @0x00003041;
#define PMC_SPMSC2                      _PMC_SPMSC2.Byte
#define PMC_SPMSC2_LVWV0                _PMC_SPMSC2.Bits.LVWV0
#define PMC_SPMSC2_LVWV1                _PMC_SPMSC2.Bits.LVWV1
#define PMC_SPMSC2_LVDV                 _PMC_SPMSC2.Bits.LVDV
#define PMC_SPMSC2_LVWV                 _PMC_SPMSC2.MergedBits.grpLVWV

#define PMC_SPMSC2_LVWV0_MASK           16U
#define PMC_SPMSC2_LVWV1_MASK           32U
#define PMC_SPMSC2_LVDV_MASK            64U
#define PMC_SPMSC2_LVWV_MASK            48U
#define PMC_SPMSC2_LVWV_BITNUM          4U


/*** SYS_ILLAH - Illegal Address Register: High; 0x0000304A ***/
typedef union {
  byte Byte;
  struct {
    byte ADDR0       :1;                                       /* High 8-bit of illegal address, bit 0 */
    byte ADDR1       :1;                                       /* High 8-bit of illegal address, bit 1 */
    byte ADDR2       :1;                                       /* High 8-bit of illegal address, bit 2 */
    byte ADDR3       :1;                                       /* High 8-bit of illegal address, bit 3 */
    byte ADDR4       :1;                                       /* High 8-bit of illegal address, bit 4 */
    byte ADDR5       :1;                                       /* High 8-bit of illegal address, bit 5 */
    byte ADDR6       :1;                                       /* High 8-bit of illegal address, bit 6 */
    byte ADDR7       :1;                                       /* High 8-bit of illegal address, bit 7 */
  } Bits;
} SYS_ILLAHSTR;
extern volatile SYS_ILLAHSTR _SYS_ILLAH @0x0000304A;
#define SYS_ILLAH                       _SYS_ILLAH.Byte
#define SYS_ILLAH_ADDR0                 _SYS_ILLAH.Bits.ADDR0
#define SYS_ILLAH_ADDR1                 _SYS_ILLAH.Bits.ADDR1
#define SYS_ILLAH_ADDR2                 _SYS_ILLAH.Bits.ADDR2
#define SYS_ILLAH_ADDR3                 _SYS_ILLAH.Bits.ADDR3
#define SYS_ILLAH_ADDR4                 _SYS_ILLAH.Bits.ADDR4
#define SYS_ILLAH_ADDR5                 _SYS_ILLAH.Bits.ADDR5
#define SYS_ILLAH_ADDR6                 _SYS_ILLAH.Bits.ADDR6
#define SYS_ILLAH_ADDR7                 _SYS_ILLAH.Bits.ADDR7

#define SYS_ILLAH_ADDR0_MASK            1U
#define SYS_ILLAH_ADDR1_MASK            2U
#define SYS_ILLAH_ADDR2_MASK            4U
#define SYS_ILLAH_ADDR3_MASK            8U
#define SYS_ILLAH_ADDR4_MASK            16U
#define SYS_ILLAH_ADDR5_MASK            32U
#define SYS_ILLAH_ADDR6_MASK            64U
#define SYS_ILLAH_ADDR7_MASK            128U


/*** SYS_ILLAL - Illegal Address Register: Low; 0x0000304B ***/
typedef union {
  byte Byte;
  struct {
    byte ADDR0       :1;                                       /* Low 8-bit of illegal address, bit 0 */
    byte ADDR1       :1;                                       /* Low 8-bit of illegal address, bit 1 */
    byte ADDR2       :1;                                       /* Low 8-bit of illegal address, bit 2 */
    byte ADDR3       :1;                                       /* Low 8-bit of illegal address, bit 3 */
    byte ADDR4       :1;                                       /* Low 8-bit of illegal address, bit 4 */
    byte ADDR5       :1;                                       /* Low 8-bit of illegal address, bit 5 */
    byte ADDR6       :1;                                       /* Low 8-bit of illegal address, bit 6 */
    byte ADDR7       :1;                                       /* Low 8-bit of illegal address, bit 7 */
  } Bits;
} SYS_ILLALSTR;
extern volatile SYS_ILLALSTR _SYS_ILLAL @0x0000304B;
#define SYS_ILLAL                       _SYS_ILLAL.Byte
#define SYS_ILLAL_ADDR0                 _SYS_ILLAL.Bits.ADDR0
#define SYS_ILLAL_ADDR1                 _SYS_ILLAL.Bits.ADDR1
#define SYS_ILLAL_ADDR2                 _SYS_ILLAL.Bits.ADDR2
#define SYS_ILLAL_ADDR3                 _SYS_ILLAL.Bits.ADDR3
#define SYS_ILLAL_ADDR4                 _SYS_ILLAL.Bits.ADDR4
#define SYS_ILLAL_ADDR5                 _SYS_ILLAL.Bits.ADDR5
#define SYS_ILLAL_ADDR6                 _SYS_ILLAL.Bits.ADDR6
#define SYS_ILLAL_ADDR7                 _SYS_ILLAL.Bits.ADDR7

#define SYS_ILLAL_ADDR0_MASK            1U
#define SYS_ILLAL_ADDR1_MASK            2U
#define SYS_ILLAL_ADDR2_MASK            4U
#define SYS_ILLAL_ADDR3_MASK            8U
#define SYS_ILLAL_ADDR4_MASK            16U
#define SYS_ILLAL_ADDR5_MASK            32U
#define SYS_ILLAL_ADDR6_MASK            64U
#define SYS_ILLAL_ADDR7_MASK            128U


/*** IPC_ILRS0 - Interrupt Level Setting Registers n; 0x00003050 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS0STR;
extern volatile IPC_ILRS0STR _IPC_ILRS0 @0x00003050;
#define IPC_ILRS0                       _IPC_ILRS0.Byte
#define IPC_ILRS0_ILRn00                _IPC_ILRS0.Bits.ILRn00
#define IPC_ILRS0_ILRn01                _IPC_ILRS0.Bits.ILRn01
#define IPC_ILRS0_ILRn10                _IPC_ILRS0.Bits.ILRn10
#define IPC_ILRS0_ILRn11                _IPC_ILRS0.Bits.ILRn11
#define IPC_ILRS0_ILRn20                _IPC_ILRS0.Bits.ILRn20
#define IPC_ILRS0_ILRn21                _IPC_ILRS0.Bits.ILRn21
#define IPC_ILRS0_ILRn30                _IPC_ILRS0.Bits.ILRn30
#define IPC_ILRS0_ILRn31                _IPC_ILRS0.Bits.ILRn31
/* IPC_ILRS_ARR: Access 10 IPC_ILRSx registers in an array */
#define IPC_ILRS_ARR                    ((volatile byte * __far) &IPC_ILRS0)
#define IPC_ILRS0_ILRn0                 _IPC_ILRS0.MergedBits.grpILRn0
#define IPC_ILRS0_ILRn1                 _IPC_ILRS0.MergedBits.grpILRn1
#define IPC_ILRS0_ILRn2                 _IPC_ILRS0.MergedBits.grpILRn2
#define IPC_ILRS0_ILRn3                 _IPC_ILRS0.MergedBits.grpILRn3

#define IPC_ILRS0_ILRn00_MASK           1U
#define IPC_ILRS0_ILRn01_MASK           2U
#define IPC_ILRS0_ILRn10_MASK           4U
#define IPC_ILRS0_ILRn11_MASK           8U
#define IPC_ILRS0_ILRn20_MASK           16U
#define IPC_ILRS0_ILRn21_MASK           32U
#define IPC_ILRS0_ILRn30_MASK           64U
#define IPC_ILRS0_ILRn31_MASK           128U
#define IPC_ILRS0_ILRn0_MASK            3U
#define IPC_ILRS0_ILRn0_BITNUM          0U
#define IPC_ILRS0_ILRn1_MASK            12U
#define IPC_ILRS0_ILRn1_BITNUM          2U
#define IPC_ILRS0_ILRn2_MASK            48U
#define IPC_ILRS0_ILRn2_BITNUM          4U
#define IPC_ILRS0_ILRn3_MASK            192U
#define IPC_ILRS0_ILRn3_BITNUM          6U


/*** IPC_ILRS1 - Interrupt Level Setting Registers n; 0x00003051 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS1STR;
extern volatile IPC_ILRS1STR _IPC_ILRS1 @0x00003051;
#define IPC_ILRS1                       _IPC_ILRS1.Byte
#define IPC_ILRS1_ILRn00                _IPC_ILRS1.Bits.ILRn00
#define IPC_ILRS1_ILRn01                _IPC_ILRS1.Bits.ILRn01
#define IPC_ILRS1_ILRn10                _IPC_ILRS1.Bits.ILRn10
#define IPC_ILRS1_ILRn11                _IPC_ILRS1.Bits.ILRn11
#define IPC_ILRS1_ILRn20                _IPC_ILRS1.Bits.ILRn20
#define IPC_ILRS1_ILRn21                _IPC_ILRS1.Bits.ILRn21
#define IPC_ILRS1_ILRn30                _IPC_ILRS1.Bits.ILRn30
#define IPC_ILRS1_ILRn31                _IPC_ILRS1.Bits.ILRn31
#define IPC_ILRS1_ILRn0                 _IPC_ILRS1.MergedBits.grpILRn0
#define IPC_ILRS1_ILRn1                 _IPC_ILRS1.MergedBits.grpILRn1
#define IPC_ILRS1_ILRn2                 _IPC_ILRS1.MergedBits.grpILRn2
#define IPC_ILRS1_ILRn3                 _IPC_ILRS1.MergedBits.grpILRn3

#define IPC_ILRS1_ILRn00_MASK           1U
#define IPC_ILRS1_ILRn01_MASK           2U
#define IPC_ILRS1_ILRn10_MASK           4U
#define IPC_ILRS1_ILRn11_MASK           8U
#define IPC_ILRS1_ILRn20_MASK           16U
#define IPC_ILRS1_ILRn21_MASK           32U
#define IPC_ILRS1_ILRn30_MASK           64U
#define IPC_ILRS1_ILRn31_MASK           128U
#define IPC_ILRS1_ILRn0_MASK            3U
#define IPC_ILRS1_ILRn0_BITNUM          0U
#define IPC_ILRS1_ILRn1_MASK            12U
#define IPC_ILRS1_ILRn1_BITNUM          2U
#define IPC_ILRS1_ILRn2_MASK            48U
#define IPC_ILRS1_ILRn2_BITNUM          4U
#define IPC_ILRS1_ILRn3_MASK            192U
#define IPC_ILRS1_ILRn3_BITNUM          6U


/*** IPC_ILRS2 - Interrupt Level Setting Registers n; 0x00003052 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS2STR;
extern volatile IPC_ILRS2STR _IPC_ILRS2 @0x00003052;
#define IPC_ILRS2                       _IPC_ILRS2.Byte
#define IPC_ILRS2_ILRn00                _IPC_ILRS2.Bits.ILRn00
#define IPC_ILRS2_ILRn01                _IPC_ILRS2.Bits.ILRn01
#define IPC_ILRS2_ILRn10                _IPC_ILRS2.Bits.ILRn10
#define IPC_ILRS2_ILRn11                _IPC_ILRS2.Bits.ILRn11
#define IPC_ILRS2_ILRn20                _IPC_ILRS2.Bits.ILRn20
#define IPC_ILRS2_ILRn21                _IPC_ILRS2.Bits.ILRn21
#define IPC_ILRS2_ILRn30                _IPC_ILRS2.Bits.ILRn30
#define IPC_ILRS2_ILRn31                _IPC_ILRS2.Bits.ILRn31
#define IPC_ILRS2_ILRn0                 _IPC_ILRS2.MergedBits.grpILRn0
#define IPC_ILRS2_ILRn1                 _IPC_ILRS2.MergedBits.grpILRn1
#define IPC_ILRS2_ILRn2                 _IPC_ILRS2.MergedBits.grpILRn2
#define IPC_ILRS2_ILRn3                 _IPC_ILRS2.MergedBits.grpILRn3

#define IPC_ILRS2_ILRn00_MASK           1U
#define IPC_ILRS2_ILRn01_MASK           2U
#define IPC_ILRS2_ILRn10_MASK           4U
#define IPC_ILRS2_ILRn11_MASK           8U
#define IPC_ILRS2_ILRn20_MASK           16U
#define IPC_ILRS2_ILRn21_MASK           32U
#define IPC_ILRS2_ILRn30_MASK           64U
#define IPC_ILRS2_ILRn31_MASK           128U
#define IPC_ILRS2_ILRn0_MASK            3U
#define IPC_ILRS2_ILRn0_BITNUM          0U
#define IPC_ILRS2_ILRn1_MASK            12U
#define IPC_ILRS2_ILRn1_BITNUM          2U
#define IPC_ILRS2_ILRn2_MASK            48U
#define IPC_ILRS2_ILRn2_BITNUM          4U
#define IPC_ILRS2_ILRn3_MASK            192U
#define IPC_ILRS2_ILRn3_BITNUM          6U


/*** IPC_ILRS3 - Interrupt Level Setting Registers n; 0x00003053 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS3STR;
extern volatile IPC_ILRS3STR _IPC_ILRS3 @0x00003053;
#define IPC_ILRS3                       _IPC_ILRS3.Byte
#define IPC_ILRS3_ILRn00                _IPC_ILRS3.Bits.ILRn00
#define IPC_ILRS3_ILRn01                _IPC_ILRS3.Bits.ILRn01
#define IPC_ILRS3_ILRn10                _IPC_ILRS3.Bits.ILRn10
#define IPC_ILRS3_ILRn11                _IPC_ILRS3.Bits.ILRn11
#define IPC_ILRS3_ILRn20                _IPC_ILRS3.Bits.ILRn20
#define IPC_ILRS3_ILRn21                _IPC_ILRS3.Bits.ILRn21
#define IPC_ILRS3_ILRn30                _IPC_ILRS3.Bits.ILRn30
#define IPC_ILRS3_ILRn31                _IPC_ILRS3.Bits.ILRn31
#define IPC_ILRS3_ILRn0                 _IPC_ILRS3.MergedBits.grpILRn0
#define IPC_ILRS3_ILRn1                 _IPC_ILRS3.MergedBits.grpILRn1
#define IPC_ILRS3_ILRn2                 _IPC_ILRS3.MergedBits.grpILRn2
#define IPC_ILRS3_ILRn3                 _IPC_ILRS3.MergedBits.grpILRn3

#define IPC_ILRS3_ILRn00_MASK           1U
#define IPC_ILRS3_ILRn01_MASK           2U
#define IPC_ILRS3_ILRn10_MASK           4U
#define IPC_ILRS3_ILRn11_MASK           8U
#define IPC_ILRS3_ILRn20_MASK           16U
#define IPC_ILRS3_ILRn21_MASK           32U
#define IPC_ILRS3_ILRn30_MASK           64U
#define IPC_ILRS3_ILRn31_MASK           128U
#define IPC_ILRS3_ILRn0_MASK            3U
#define IPC_ILRS3_ILRn0_BITNUM          0U
#define IPC_ILRS3_ILRn1_MASK            12U
#define IPC_ILRS3_ILRn1_BITNUM          2U
#define IPC_ILRS3_ILRn2_MASK            48U
#define IPC_ILRS3_ILRn2_BITNUM          4U
#define IPC_ILRS3_ILRn3_MASK            192U
#define IPC_ILRS3_ILRn3_BITNUM          6U


/*** IPC_ILRS4 - Interrupt Level Setting Registers n; 0x00003054 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS4STR;
extern volatile IPC_ILRS4STR _IPC_ILRS4 @0x00003054;
#define IPC_ILRS4                       _IPC_ILRS4.Byte
#define IPC_ILRS4_ILRn00                _IPC_ILRS4.Bits.ILRn00
#define IPC_ILRS4_ILRn01                _IPC_ILRS4.Bits.ILRn01
#define IPC_ILRS4_ILRn10                _IPC_ILRS4.Bits.ILRn10
#define IPC_ILRS4_ILRn11                _IPC_ILRS4.Bits.ILRn11
#define IPC_ILRS4_ILRn20                _IPC_ILRS4.Bits.ILRn20
#define IPC_ILRS4_ILRn21                _IPC_ILRS4.Bits.ILRn21
#define IPC_ILRS4_ILRn30                _IPC_ILRS4.Bits.ILRn30
#define IPC_ILRS4_ILRn31                _IPC_ILRS4.Bits.ILRn31
#define IPC_ILRS4_ILRn0                 _IPC_ILRS4.MergedBits.grpILRn0
#define IPC_ILRS4_ILRn1                 _IPC_ILRS4.MergedBits.grpILRn1
#define IPC_ILRS4_ILRn2                 _IPC_ILRS4.MergedBits.grpILRn2
#define IPC_ILRS4_ILRn3                 _IPC_ILRS4.MergedBits.grpILRn3

#define IPC_ILRS4_ILRn00_MASK           1U
#define IPC_ILRS4_ILRn01_MASK           2U
#define IPC_ILRS4_ILRn10_MASK           4U
#define IPC_ILRS4_ILRn11_MASK           8U
#define IPC_ILRS4_ILRn20_MASK           16U
#define IPC_ILRS4_ILRn21_MASK           32U
#define IPC_ILRS4_ILRn30_MASK           64U
#define IPC_ILRS4_ILRn31_MASK           128U
#define IPC_ILRS4_ILRn0_MASK            3U
#define IPC_ILRS4_ILRn0_BITNUM          0U
#define IPC_ILRS4_ILRn1_MASK            12U
#define IPC_ILRS4_ILRn1_BITNUM          2U
#define IPC_ILRS4_ILRn2_MASK            48U
#define IPC_ILRS4_ILRn2_BITNUM          4U
#define IPC_ILRS4_ILRn3_MASK            192U
#define IPC_ILRS4_ILRn3_BITNUM          6U


/*** IPC_ILRS5 - Interrupt Level Setting Registers n; 0x00003055 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS5STR;
extern volatile IPC_ILRS5STR _IPC_ILRS5 @0x00003055;
#define IPC_ILRS5                       _IPC_ILRS5.Byte
#define IPC_ILRS5_ILRn00                _IPC_ILRS5.Bits.ILRn00
#define IPC_ILRS5_ILRn01                _IPC_ILRS5.Bits.ILRn01
#define IPC_ILRS5_ILRn10                _IPC_ILRS5.Bits.ILRn10
#define IPC_ILRS5_ILRn11                _IPC_ILRS5.Bits.ILRn11
#define IPC_ILRS5_ILRn20                _IPC_ILRS5.Bits.ILRn20
#define IPC_ILRS5_ILRn21                _IPC_ILRS5.Bits.ILRn21
#define IPC_ILRS5_ILRn30                _IPC_ILRS5.Bits.ILRn30
#define IPC_ILRS5_ILRn31                _IPC_ILRS5.Bits.ILRn31
#define IPC_ILRS5_ILRn0                 _IPC_ILRS5.MergedBits.grpILRn0
#define IPC_ILRS5_ILRn1                 _IPC_ILRS5.MergedBits.grpILRn1
#define IPC_ILRS5_ILRn2                 _IPC_ILRS5.MergedBits.grpILRn2
#define IPC_ILRS5_ILRn3                 _IPC_ILRS5.MergedBits.grpILRn3

#define IPC_ILRS5_ILRn00_MASK           1U
#define IPC_ILRS5_ILRn01_MASK           2U
#define IPC_ILRS5_ILRn10_MASK           4U
#define IPC_ILRS5_ILRn11_MASK           8U
#define IPC_ILRS5_ILRn20_MASK           16U
#define IPC_ILRS5_ILRn21_MASK           32U
#define IPC_ILRS5_ILRn30_MASK           64U
#define IPC_ILRS5_ILRn31_MASK           128U
#define IPC_ILRS5_ILRn0_MASK            3U
#define IPC_ILRS5_ILRn0_BITNUM          0U
#define IPC_ILRS5_ILRn1_MASK            12U
#define IPC_ILRS5_ILRn1_BITNUM          2U
#define IPC_ILRS5_ILRn2_MASK            48U
#define IPC_ILRS5_ILRn2_BITNUM          4U
#define IPC_ILRS5_ILRn3_MASK            192U
#define IPC_ILRS5_ILRn3_BITNUM          6U


/*** IPC_ILRS6 - Interrupt Level Setting Registers n; 0x00003056 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS6STR;
extern volatile IPC_ILRS6STR _IPC_ILRS6 @0x00003056;
#define IPC_ILRS6                       _IPC_ILRS6.Byte
#define IPC_ILRS6_ILRn00                _IPC_ILRS6.Bits.ILRn00
#define IPC_ILRS6_ILRn01                _IPC_ILRS6.Bits.ILRn01
#define IPC_ILRS6_ILRn10                _IPC_ILRS6.Bits.ILRn10
#define IPC_ILRS6_ILRn11                _IPC_ILRS6.Bits.ILRn11
#define IPC_ILRS6_ILRn20                _IPC_ILRS6.Bits.ILRn20
#define IPC_ILRS6_ILRn21                _IPC_ILRS6.Bits.ILRn21
#define IPC_ILRS6_ILRn30                _IPC_ILRS6.Bits.ILRn30
#define IPC_ILRS6_ILRn31                _IPC_ILRS6.Bits.ILRn31
#define IPC_ILRS6_ILRn0                 _IPC_ILRS6.MergedBits.grpILRn0
#define IPC_ILRS6_ILRn1                 _IPC_ILRS6.MergedBits.grpILRn1
#define IPC_ILRS6_ILRn2                 _IPC_ILRS6.MergedBits.grpILRn2
#define IPC_ILRS6_ILRn3                 _IPC_ILRS6.MergedBits.grpILRn3

#define IPC_ILRS6_ILRn00_MASK           1U
#define IPC_ILRS6_ILRn01_MASK           2U
#define IPC_ILRS6_ILRn10_MASK           4U
#define IPC_ILRS6_ILRn11_MASK           8U
#define IPC_ILRS6_ILRn20_MASK           16U
#define IPC_ILRS6_ILRn21_MASK           32U
#define IPC_ILRS6_ILRn30_MASK           64U
#define IPC_ILRS6_ILRn31_MASK           128U
#define IPC_ILRS6_ILRn0_MASK            3U
#define IPC_ILRS6_ILRn0_BITNUM          0U
#define IPC_ILRS6_ILRn1_MASK            12U
#define IPC_ILRS6_ILRn1_BITNUM          2U
#define IPC_ILRS6_ILRn2_MASK            48U
#define IPC_ILRS6_ILRn2_BITNUM          4U
#define IPC_ILRS6_ILRn3_MASK            192U
#define IPC_ILRS6_ILRn3_BITNUM          6U


/*** IPC_ILRS7 - Interrupt Level Setting Registers n; 0x00003057 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS7STR;
extern volatile IPC_ILRS7STR _IPC_ILRS7 @0x00003057;
#define IPC_ILRS7                       _IPC_ILRS7.Byte
#define IPC_ILRS7_ILRn00                _IPC_ILRS7.Bits.ILRn00
#define IPC_ILRS7_ILRn01                _IPC_ILRS7.Bits.ILRn01
#define IPC_ILRS7_ILRn10                _IPC_ILRS7.Bits.ILRn10
#define IPC_ILRS7_ILRn11                _IPC_ILRS7.Bits.ILRn11
#define IPC_ILRS7_ILRn20                _IPC_ILRS7.Bits.ILRn20
#define IPC_ILRS7_ILRn21                _IPC_ILRS7.Bits.ILRn21
#define IPC_ILRS7_ILRn30                _IPC_ILRS7.Bits.ILRn30
#define IPC_ILRS7_ILRn31                _IPC_ILRS7.Bits.ILRn31
#define IPC_ILRS7_ILRn0                 _IPC_ILRS7.MergedBits.grpILRn0
#define IPC_ILRS7_ILRn1                 _IPC_ILRS7.MergedBits.grpILRn1
#define IPC_ILRS7_ILRn2                 _IPC_ILRS7.MergedBits.grpILRn2
#define IPC_ILRS7_ILRn3                 _IPC_ILRS7.MergedBits.grpILRn3

#define IPC_ILRS7_ILRn00_MASK           1U
#define IPC_ILRS7_ILRn01_MASK           2U
#define IPC_ILRS7_ILRn10_MASK           4U
#define IPC_ILRS7_ILRn11_MASK           8U
#define IPC_ILRS7_ILRn20_MASK           16U
#define IPC_ILRS7_ILRn21_MASK           32U
#define IPC_ILRS7_ILRn30_MASK           64U
#define IPC_ILRS7_ILRn31_MASK           128U
#define IPC_ILRS7_ILRn0_MASK            3U
#define IPC_ILRS7_ILRn0_BITNUM          0U
#define IPC_ILRS7_ILRn1_MASK            12U
#define IPC_ILRS7_ILRn1_BITNUM          2U
#define IPC_ILRS7_ILRn2_MASK            48U
#define IPC_ILRS7_ILRn2_BITNUM          4U
#define IPC_ILRS7_ILRn3_MASK            192U
#define IPC_ILRS7_ILRn3_BITNUM          6U


/*** IPC_ILRS8 - Interrupt Level Setting Registers n; 0x00003058 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS8STR;
extern volatile IPC_ILRS8STR _IPC_ILRS8 @0x00003058;
#define IPC_ILRS8                       _IPC_ILRS8.Byte
#define IPC_ILRS8_ILRn00                _IPC_ILRS8.Bits.ILRn00
#define IPC_ILRS8_ILRn01                _IPC_ILRS8.Bits.ILRn01
#define IPC_ILRS8_ILRn10                _IPC_ILRS8.Bits.ILRn10
#define IPC_ILRS8_ILRn11                _IPC_ILRS8.Bits.ILRn11
#define IPC_ILRS8_ILRn20                _IPC_ILRS8.Bits.ILRn20
#define IPC_ILRS8_ILRn21                _IPC_ILRS8.Bits.ILRn21
#define IPC_ILRS8_ILRn30                _IPC_ILRS8.Bits.ILRn30
#define IPC_ILRS8_ILRn31                _IPC_ILRS8.Bits.ILRn31
#define IPC_ILRS8_ILRn0                 _IPC_ILRS8.MergedBits.grpILRn0
#define IPC_ILRS8_ILRn1                 _IPC_ILRS8.MergedBits.grpILRn1
#define IPC_ILRS8_ILRn2                 _IPC_ILRS8.MergedBits.grpILRn2
#define IPC_ILRS8_ILRn3                 _IPC_ILRS8.MergedBits.grpILRn3

#define IPC_ILRS8_ILRn00_MASK           1U
#define IPC_ILRS8_ILRn01_MASK           2U
#define IPC_ILRS8_ILRn10_MASK           4U
#define IPC_ILRS8_ILRn11_MASK           8U
#define IPC_ILRS8_ILRn20_MASK           16U
#define IPC_ILRS8_ILRn21_MASK           32U
#define IPC_ILRS8_ILRn30_MASK           64U
#define IPC_ILRS8_ILRn31_MASK           128U
#define IPC_ILRS8_ILRn0_MASK            3U
#define IPC_ILRS8_ILRn0_BITNUM          0U
#define IPC_ILRS8_ILRn1_MASK            12U
#define IPC_ILRS8_ILRn1_BITNUM          2U
#define IPC_ILRS8_ILRn2_MASK            48U
#define IPC_ILRS8_ILRn2_BITNUM          4U
#define IPC_ILRS8_ILRn3_MASK            192U
#define IPC_ILRS8_ILRn3_BITNUM          6U


/*** IPC_ILRS9 - Interrupt Level Setting Registers n; 0x00003059 ***/
typedef union {
  byte Byte;
  struct {
    byte ILRn00      :1;                                       /* Interrupt Level Register for Source n+0, bit 0 */
    byte ILRn01      :1;                                       /* Interrupt Level Register for Source n+0, bit 1 */
    byte ILRn10      :1;                                       /* Interrupt Level Register for Source n+1, bit 0 */
    byte ILRn11      :1;                                       /* Interrupt Level Register for Source n+1, bit 1 */
    byte ILRn20      :1;                                       /* Interrupt Level Register for Source n+2, bit 0 */
    byte ILRn21      :1;                                       /* Interrupt Level Register for Source n+2, bit 1 */
    byte ILRn30      :1;                                       /* Interrupt Level Register for Source n+3, bit 0 */
    byte ILRn31      :1;                                       /* Interrupt Level Register for Source n+3, bit 1 */
  } Bits;
  struct {
    byte grpILRn0 :2;
    byte grpILRn1 :2;
    byte grpILRn2 :2;
    byte grpILRn3 :2;
  } MergedBits;
} IPC_ILRS9STR;
extern volatile IPC_ILRS9STR _IPC_ILRS9 @0x00003059;
#define IPC_ILRS9                       _IPC_ILRS9.Byte
#define IPC_ILRS9_ILRn00                _IPC_ILRS9.Bits.ILRn00
#define IPC_ILRS9_ILRn01                _IPC_ILRS9.Bits.ILRn01
#define IPC_ILRS9_ILRn10                _IPC_ILRS9.Bits.ILRn10
#define IPC_ILRS9_ILRn11                _IPC_ILRS9.Bits.ILRn11
#define IPC_ILRS9_ILRn20                _IPC_ILRS9.Bits.ILRn20
#define IPC_ILRS9_ILRn21                _IPC_ILRS9.Bits.ILRn21
#define IPC_ILRS9_ILRn30                _IPC_ILRS9.Bits.ILRn30
#define IPC_ILRS9_ILRn31                _IPC_ILRS9.Bits.ILRn31
#define IPC_ILRS9_ILRn0                 _IPC_ILRS9.MergedBits.grpILRn0
#define IPC_ILRS9_ILRn1                 _IPC_ILRS9.MergedBits.grpILRn1
#define IPC_ILRS9_ILRn2                 _IPC_ILRS9.MergedBits.grpILRn2
#define IPC_ILRS9_ILRn3                 _IPC_ILRS9.MergedBits.grpILRn3

#define IPC_ILRS9_ILRn00_MASK           1U
#define IPC_ILRS9_ILRn01_MASK           2U
#define IPC_ILRS9_ILRn10_MASK           4U
#define IPC_ILRS9_ILRn11_MASK           8U
#define IPC_ILRS9_ILRn20_MASK           16U
#define IPC_ILRS9_ILRn21_MASK           32U
#define IPC_ILRS9_ILRn30_MASK           64U
#define IPC_ILRS9_ILRn31_MASK           128U
#define IPC_ILRS9_ILRn0_MASK            3U
#define IPC_ILRS9_ILRn0_BITNUM          0U
#define IPC_ILRS9_ILRn1_MASK            12U
#define IPC_ILRS9_ILRn1_BITNUM          2U
#define IPC_ILRS9_ILRn2_MASK            48U
#define IPC_ILRS9_ILRn2_BITNUM          4U
#define IPC_ILRS9_ILRn3_MASK            192U
#define IPC_ILRS9_ILRn3_BITNUM          6U


/*** CRC_D0D1 - CRC_D0D1 register; 0x00003060 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CRC_D0 - CRC Data 0 Register; 0x00003060 ***/
    union {
      byte Byte;
      struct {
        byte DH00        :1;                                       /* CRC Data Bit 31:24, bit 0 */
        byte DH01        :1;                                       /* CRC Data Bit 31:24, bit 1 */
        byte DH02        :1;                                       /* CRC Data Bit 31:24, bit 2 */
        byte DH03        :1;                                       /* CRC Data Bit 31:24, bit 3 */
        byte DH04        :1;                                       /* CRC Data Bit 31:24, bit 4 */
        byte DH05        :1;                                       /* CRC Data Bit 31:24, bit 5 */
        byte DH06        :1;                                       /* CRC Data Bit 31:24, bit 6 */
        byte DH07        :1;                                       /* CRC Data Bit 31:24, bit 7 */
      } Bits;
    } CRC_D0STR;
    #define CRC_D0                      _CRC_D0D1.Overlap_STR.CRC_D0STR.Byte
    #define CRC_D0_DH00                 _CRC_D0D1.Overlap_STR.CRC_D0STR.Bits.DH00
    #define CRC_D0_DH01                 _CRC_D0D1.Overlap_STR.CRC_D0STR.Bits.DH01
    #define CRC_D0_DH02                 _CRC_D0D1.Overlap_STR.CRC_D0STR.Bits.DH02
    #define CRC_D0_DH03                 _CRC_D0D1.Overlap_STR.CRC_D0STR.Bits.DH03
    #define CRC_D0_DH04                 _CRC_D0D1.Overlap_STR.CRC_D0STR.Bits.DH04
    #define CRC_D0_DH05                 _CRC_D0D1.Overlap_STR.CRC_D0STR.Bits.DH05
    #define CRC_D0_DH06                 _CRC_D0D1.Overlap_STR.CRC_D0STR.Bits.DH06
    #define CRC_D0_DH07                 _CRC_D0D1.Overlap_STR.CRC_D0STR.Bits.DH07
    /* CRC_D_ARR: Access 4 CRC_Dx registers in an array */
    #define CRC_D_ARR                   ((volatile byte * __far) &CRC_D0)
    
    #define CRC_D0_DH00_MASK            1U
    #define CRC_D0_DH01_MASK            2U
    #define CRC_D0_DH02_MASK            4U
    #define CRC_D0_DH03_MASK            8U
    #define CRC_D0_DH04_MASK            16U
    #define CRC_D0_DH05_MASK            32U
    #define CRC_D0_DH06_MASK            64U
    #define CRC_D0_DH07_MASK            128U
    

    /*** CRC_D1 - CRC Data 1 Register; 0x00003061 ***/
    union {
      byte Byte;
      struct {
        byte D10         :1;                                       /* CRC Data Bit 23:16, bit 0 */
        byte D11         :1;                                       /* CRC Data Bit 23:16, bit 1 */
        byte D12         :1;                                       /* CRC Data Bit 23:16, bit 2 */
        byte D13         :1;                                       /* CRC Data Bit 23:16, bit 3 */
        byte D14         :1;                                       /* CRC Data Bit 23:16, bit 4 */
        byte D15         :1;                                       /* CRC Data Bit 23:16, bit 5 */
        byte D16         :1;                                       /* CRC Data Bit 23:16, bit 6 */
        byte D17         :1;                                       /* CRC Data Bit 23:16, bit 7 */
      } Bits;
    } CRC_D1STR;
    #define CRC_D1                      _CRC_D0D1.Overlap_STR.CRC_D1STR.Byte
    #define CRC_D1_D10                  _CRC_D0D1.Overlap_STR.CRC_D1STR.Bits.D10
    #define CRC_D1_D11                  _CRC_D0D1.Overlap_STR.CRC_D1STR.Bits.D11
    #define CRC_D1_D12                  _CRC_D0D1.Overlap_STR.CRC_D1STR.Bits.D12
    #define CRC_D1_D13                  _CRC_D0D1.Overlap_STR.CRC_D1STR.Bits.D13
    #define CRC_D1_D14                  _CRC_D0D1.Overlap_STR.CRC_D1STR.Bits.D14
    #define CRC_D1_D15                  _CRC_D0D1.Overlap_STR.CRC_D1STR.Bits.D15
    #define CRC_D1_D16                  _CRC_D0D1.Overlap_STR.CRC_D1STR.Bits.D16
    #define CRC_D1_D17                  _CRC_D0D1.Overlap_STR.CRC_D1STR.Bits.D17
    
    #define CRC_D1_D10_MASK             1U
    #define CRC_D1_D11_MASK             2U
    #define CRC_D1_D12_MASK             4U
    #define CRC_D1_D13_MASK             8U
    #define CRC_D1_D14_MASK             16U
    #define CRC_D1_D15_MASK             32U
    #define CRC_D1_D16_MASK             64U
    #define CRC_D1_D17_MASK             128U
    
  } Overlap_STR;

} CRC_D0D1STR;
extern volatile CRC_D0D1STR _CRC_D0D1 @0x00003060;
#define CRC_D0D1                        _CRC_D0D1.Word


/*** CRC_D2D3 - CRC_D2D3 register; 0x00003062 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CRC_D2 - CRC Data 2 Register; 0x00003062 ***/
    union {
      byte Byte;
      struct {
        byte D20         :1;                                       /* CRC Data Bit 15:8, bit 0 */
        byte D21         :1;                                       /* CRC Data Bit 15:8, bit 1 */
        byte D22         :1;                                       /* CRC Data Bit 15:8, bit 2 */
        byte D23         :1;                                       /* CRC Data Bit 15:8, bit 3 */
        byte D24         :1;                                       /* CRC Data Bit 15:8, bit 4 */
        byte D25         :1;                                       /* CRC Data Bit 15:8, bit 5 */
        byte D26         :1;                                       /* CRC Data Bit 15:8, bit 6 */
        byte D27         :1;                                       /* CRC Data Bit 15:8, bit 7 */
      } Bits;
    } CRC_D2STR;
    #define CRC_D2                      _CRC_D2D3.Overlap_STR.CRC_D2STR.Byte
    #define CRC_D2_D20                  _CRC_D2D3.Overlap_STR.CRC_D2STR.Bits.D20
    #define CRC_D2_D21                  _CRC_D2D3.Overlap_STR.CRC_D2STR.Bits.D21
    #define CRC_D2_D22                  _CRC_D2D3.Overlap_STR.CRC_D2STR.Bits.D22
    #define CRC_D2_D23                  _CRC_D2D3.Overlap_STR.CRC_D2STR.Bits.D23
    #define CRC_D2_D24                  _CRC_D2D3.Overlap_STR.CRC_D2STR.Bits.D24
    #define CRC_D2_D25                  _CRC_D2D3.Overlap_STR.CRC_D2STR.Bits.D25
    #define CRC_D2_D26                  _CRC_D2D3.Overlap_STR.CRC_D2STR.Bits.D26
    #define CRC_D2_D27                  _CRC_D2D3.Overlap_STR.CRC_D2STR.Bits.D27
    
    #define CRC_D2_D20_MASK             1U
    #define CRC_D2_D21_MASK             2U
    #define CRC_D2_D22_MASK             4U
    #define CRC_D2_D23_MASK             8U
    #define CRC_D2_D24_MASK             16U
    #define CRC_D2_D25_MASK             32U
    #define CRC_D2_D26_MASK             64U
    #define CRC_D2_D27_MASK             128U
    

    /*** CRC_D3 - CRC Data 3 Register; 0x00003063 ***/
    union {
      byte Byte;
      struct {
        byte D30         :1;                                       /* CRC Data Bit 7:0, bit 0 */
        byte D31         :1;                                       /* CRC Data Bit 7:0, bit 1 */
        byte D32         :1;                                       /* CRC Data Bit 7:0, bit 2 */
        byte D33         :1;                                       /* CRC Data Bit 7:0, bit 3 */
        byte D34         :1;                                       /* CRC Data Bit 7:0, bit 4 */
        byte D35         :1;                                       /* CRC Data Bit 7:0, bit 5 */
        byte D36         :1;                                       /* CRC Data Bit 7:0, bit 6 */
        byte D37         :1;                                       /* CRC Data Bit 7:0, bit 7 */
      } Bits;
    } CRC_D3STR;
    #define CRC_D3                      _CRC_D2D3.Overlap_STR.CRC_D3STR.Byte
    #define CRC_D3_D30                  _CRC_D2D3.Overlap_STR.CRC_D3STR.Bits.D30
    #define CRC_D3_D31                  _CRC_D2D3.Overlap_STR.CRC_D3STR.Bits.D31
    #define CRC_D3_D32                  _CRC_D2D3.Overlap_STR.CRC_D3STR.Bits.D32
    #define CRC_D3_D33                  _CRC_D2D3.Overlap_STR.CRC_D3STR.Bits.D33
    #define CRC_D3_D34                  _CRC_D2D3.Overlap_STR.CRC_D3STR.Bits.D34
    #define CRC_D3_D35                  _CRC_D2D3.Overlap_STR.CRC_D3STR.Bits.D35
    #define CRC_D3_D36                  _CRC_D2D3.Overlap_STR.CRC_D3STR.Bits.D36
    #define CRC_D3_D37                  _CRC_D2D3.Overlap_STR.CRC_D3STR.Bits.D37
    
    #define CRC_D3_D30_MASK             1U
    #define CRC_D3_D31_MASK             2U
    #define CRC_D3_D32_MASK             4U
    #define CRC_D3_D33_MASK             8U
    #define CRC_D3_D34_MASK             16U
    #define CRC_D3_D35_MASK             32U
    #define CRC_D3_D36_MASK             64U
    #define CRC_D3_D37_MASK             128U
    
  } Overlap_STR;

} CRC_D2D3STR;
extern volatile CRC_D2D3STR _CRC_D2D3 @0x00003062;
#define CRC_D2D3                        _CRC_D2D3.Word


/*** CRC_P0P1 - CRC_P0P1 register; 0x00003064 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CRC_P0 - CRC Polynomial 0 Register; 0x00003064 ***/
    union {
      byte Byte;
      struct {
        byte P00         :1;                                       /* CRC Polynominal Bit 31:24, bit 0 */
        byte P01         :1;                                       /* CRC Polynominal Bit 31:24, bit 1 */
        byte P02         :1;                                       /* CRC Polynominal Bit 31:24, bit 2 */
        byte P03         :1;                                       /* CRC Polynominal Bit 31:24, bit 3 */
        byte P04         :1;                                       /* CRC Polynominal Bit 31:24, bit 4 */
        byte P05         :1;                                       /* CRC Polynominal Bit 31:24, bit 5 */
        byte P06         :1;                                       /* CRC Polynominal Bit 31:24, bit 6 */
        byte P07         :1;                                       /* CRC Polynominal Bit 31:24, bit 7 */
      } Bits;
    } CRC_P0STR;
    #define CRC_P0                      _CRC_P0P1.Overlap_STR.CRC_P0STR.Byte
    #define CRC_P0_P00                  _CRC_P0P1.Overlap_STR.CRC_P0STR.Bits.P00
    #define CRC_P0_P01                  _CRC_P0P1.Overlap_STR.CRC_P0STR.Bits.P01
    #define CRC_P0_P02                  _CRC_P0P1.Overlap_STR.CRC_P0STR.Bits.P02
    #define CRC_P0_P03                  _CRC_P0P1.Overlap_STR.CRC_P0STR.Bits.P03
    #define CRC_P0_P04                  _CRC_P0P1.Overlap_STR.CRC_P0STR.Bits.P04
    #define CRC_P0_P05                  _CRC_P0P1.Overlap_STR.CRC_P0STR.Bits.P05
    #define CRC_P0_P06                  _CRC_P0P1.Overlap_STR.CRC_P0STR.Bits.P06
    #define CRC_P0_P07                  _CRC_P0P1.Overlap_STR.CRC_P0STR.Bits.P07
    /* CRC_P_ARR: Access 4 CRC_Px registers in an array */
    #define CRC_P_ARR                   ((volatile byte * __far) &CRC_P0)
    
    #define CRC_P0_P00_MASK             1U
    #define CRC_P0_P01_MASK             2U
    #define CRC_P0_P02_MASK             4U
    #define CRC_P0_P03_MASK             8U
    #define CRC_P0_P04_MASK             16U
    #define CRC_P0_P05_MASK             32U
    #define CRC_P0_P06_MASK             64U
    #define CRC_P0_P07_MASK             128U
    

    /*** CRC_P1 - CRC Polynomial 1 Register; 0x00003065 ***/
    union {
      byte Byte;
      struct {
        byte P10         :1;                                       /* CRC Polynominal Bit 23:16, bit 0 */
        byte P11         :1;                                       /* CRC Polynominal Bit 23:16, bit 1 */
        byte P12         :1;                                       /* CRC Polynominal Bit 23:16, bit 2 */
        byte P13         :1;                                       /* CRC Polynominal Bit 23:16, bit 3 */
        byte P14         :1;                                       /* CRC Polynominal Bit 23:16, bit 4 */
        byte P15         :1;                                       /* CRC Polynominal Bit 23:16, bit 5 */
        byte P16         :1;                                       /* CRC Polynominal Bit 23:16, bit 6 */
        byte P17         :1;                                       /* CRC Polynominal Bit 23:16, bit 7 */
      } Bits;
    } CRC_P1STR;
    #define CRC_P1                      _CRC_P0P1.Overlap_STR.CRC_P1STR.Byte
    #define CRC_P1_P10                  _CRC_P0P1.Overlap_STR.CRC_P1STR.Bits.P10
    #define CRC_P1_P11                  _CRC_P0P1.Overlap_STR.CRC_P1STR.Bits.P11
    #define CRC_P1_P12                  _CRC_P0P1.Overlap_STR.CRC_P1STR.Bits.P12
    #define CRC_P1_P13                  _CRC_P0P1.Overlap_STR.CRC_P1STR.Bits.P13
    #define CRC_P1_P14                  _CRC_P0P1.Overlap_STR.CRC_P1STR.Bits.P14
    #define CRC_P1_P15                  _CRC_P0P1.Overlap_STR.CRC_P1STR.Bits.P15
    #define CRC_P1_P16                  _CRC_P0P1.Overlap_STR.CRC_P1STR.Bits.P16
    #define CRC_P1_P17                  _CRC_P0P1.Overlap_STR.CRC_P1STR.Bits.P17
    
    #define CRC_P1_P10_MASK             1U
    #define CRC_P1_P11_MASK             2U
    #define CRC_P1_P12_MASK             4U
    #define CRC_P1_P13_MASK             8U
    #define CRC_P1_P14_MASK             16U
    #define CRC_P1_P15_MASK             32U
    #define CRC_P1_P16_MASK             64U
    #define CRC_P1_P17_MASK             128U
    
  } Overlap_STR;

} CRC_P0P1STR;
extern volatile CRC_P0P1STR _CRC_P0P1 @0x00003064;
#define CRC_P0P1                        _CRC_P0P1.Word


/*** CRC_P2P3 - CRC_P2P3 register; 0x00003066 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CRC_P2 - CRC Polynomial 2 Register; 0x00003066 ***/
    union {
      byte Byte;
      struct {
        byte P20         :1;                                       /* CRC Polynominal Bit 15:8, bit 0 */
        byte P21         :1;                                       /* CRC Polynominal Bit 15:8, bit 1 */
        byte P22         :1;                                       /* CRC Polynominal Bit 15:8, bit 2 */
        byte P23         :1;                                       /* CRC Polynominal Bit 15:8, bit 3 */
        byte P24         :1;                                       /* CRC Polynominal Bit 15:8, bit 4 */
        byte P25         :1;                                       /* CRC Polynominal Bit 15:8, bit 5 */
        byte P26         :1;                                       /* CRC Polynominal Bit 15:8, bit 6 */
        byte P27         :1;                                       /* CRC Polynominal Bit 15:8, bit 7 */
      } Bits;
    } CRC_P2STR;
    #define CRC_P2                      _CRC_P2P3.Overlap_STR.CRC_P2STR.Byte
    #define CRC_P2_P20                  _CRC_P2P3.Overlap_STR.CRC_P2STR.Bits.P20
    #define CRC_P2_P21                  _CRC_P2P3.Overlap_STR.CRC_P2STR.Bits.P21
    #define CRC_P2_P22                  _CRC_P2P3.Overlap_STR.CRC_P2STR.Bits.P22
    #define CRC_P2_P23                  _CRC_P2P3.Overlap_STR.CRC_P2STR.Bits.P23
    #define CRC_P2_P24                  _CRC_P2P3.Overlap_STR.CRC_P2STR.Bits.P24
    #define CRC_P2_P25                  _CRC_P2P3.Overlap_STR.CRC_P2STR.Bits.P25
    #define CRC_P2_P26                  _CRC_P2P3.Overlap_STR.CRC_P2STR.Bits.P26
    #define CRC_P2_P27                  _CRC_P2P3.Overlap_STR.CRC_P2STR.Bits.P27
    
    #define CRC_P2_P20_MASK             1U
    #define CRC_P2_P21_MASK             2U
    #define CRC_P2_P22_MASK             4U
    #define CRC_P2_P23_MASK             8U
    #define CRC_P2_P24_MASK             16U
    #define CRC_P2_P25_MASK             32U
    #define CRC_P2_P26_MASK             64U
    #define CRC_P2_P27_MASK             128U
    

    /*** CRC_P3 - CRC Polynomial 3 Register; 0x00003067 ***/
    union {
      byte Byte;
      struct {
        byte P30         :1;                                       /* CRC Polynominal Bit 7:0, bit 0 */
        byte P31         :1;                                       /* CRC Polynominal Bit 7:0, bit 1 */
        byte P32         :1;                                       /* CRC Polynominal Bit 7:0, bit 2 */
        byte P33         :1;                                       /* CRC Polynominal Bit 7:0, bit 3 */
        byte P34         :1;                                       /* CRC Polynominal Bit 7:0, bit 4 */
        byte P35         :1;                                       /* CRC Polynominal Bit 7:0, bit 5 */
        byte P36         :1;                                       /* CRC Polynominal Bit 7:0, bit 6 */
        byte P37         :1;                                       /* CRC Polynominal Bit 7:0, bit 7 */
      } Bits;
    } CRC_P3STR;
    #define CRC_P3                      _CRC_P2P3.Overlap_STR.CRC_P3STR.Byte
    #define CRC_P3_P30                  _CRC_P2P3.Overlap_STR.CRC_P3STR.Bits.P30
    #define CRC_P3_P31                  _CRC_P2P3.Overlap_STR.CRC_P3STR.Bits.P31
    #define CRC_P3_P32                  _CRC_P2P3.Overlap_STR.CRC_P3STR.Bits.P32
    #define CRC_P3_P33                  _CRC_P2P3.Overlap_STR.CRC_P3STR.Bits.P33
    #define CRC_P3_P34                  _CRC_P2P3.Overlap_STR.CRC_P3STR.Bits.P34
    #define CRC_P3_P35                  _CRC_P2P3.Overlap_STR.CRC_P3STR.Bits.P35
    #define CRC_P3_P36                  _CRC_P2P3.Overlap_STR.CRC_P3STR.Bits.P36
    #define CRC_P3_P37                  _CRC_P2P3.Overlap_STR.CRC_P3STR.Bits.P37
    
    #define CRC_P3_P30_MASK             1U
    #define CRC_P3_P31_MASK             2U
    #define CRC_P3_P32_MASK             4U
    #define CRC_P3_P33_MASK             8U
    #define CRC_P3_P34_MASK             16U
    #define CRC_P3_P35_MASK             32U
    #define CRC_P3_P36_MASK             64U
    #define CRC_P3_P37_MASK             128U
    
  } Overlap_STR;

} CRC_P2P3STR;
extern volatile CRC_P2P3STR _CRC_P2P3 @0x00003066;
#define CRC_P2P3                        _CRC_P2P3.Word


/*** CRC_CTRL - CRC Control Register; 0x00003068 ***/
typedef union {
  byte Byte;
  struct {
    byte TCRC        :1;                                       /* Width of Polynomial Generator */
    byte WAS         :1;                                       /* Write CRC data register as seed */
    byte FXOR        :1;                                       /* Complement of Read */
    byte             :1; 
    byte TOTR0       :1;                                       /* Reverse of Read, bit 0 */
    byte TOTR1       :1;                                       /* Reverse of Read, bit 1 */
    byte TOT0        :1;                                       /* Reverse of Write, bit 0 */
    byte TOT1        :1;                                       /* Reverse of Write, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTOTR :2;
    byte grpTOT  :2;
  } MergedBits;
} CRC_CTRLSTR;
extern volatile CRC_CTRLSTR _CRC_CTRL @0x00003068;
#define CRC_CTRL                        _CRC_CTRL.Byte
#define CRC_CTRL_TCRC                   _CRC_CTRL.Bits.TCRC
#define CRC_CTRL_WAS                    _CRC_CTRL.Bits.WAS
#define CRC_CTRL_FXOR                   _CRC_CTRL.Bits.FXOR
#define CRC_CTRL_TOTR0                  _CRC_CTRL.Bits.TOTR0
#define CRC_CTRL_TOTR1                  _CRC_CTRL.Bits.TOTR1
#define CRC_CTRL_TOT0                   _CRC_CTRL.Bits.TOT0
#define CRC_CTRL_TOT1                   _CRC_CTRL.Bits.TOT1
#define CRC_CTRL_TOTR                   _CRC_CTRL.MergedBits.grpTOTR
#define CRC_CTRL_TOT                    _CRC_CTRL.MergedBits.grpTOT

#define CRC_CTRL_TCRC_MASK              1U
#define CRC_CTRL_WAS_MASK               2U
#define CRC_CTRL_FXOR_MASK              4U
#define CRC_CTRL_TOTR0_MASK             16U
#define CRC_CTRL_TOTR1_MASK             32U
#define CRC_CTRL_TOT0_MASK              64U
#define CRC_CTRL_TOT1_MASK              128U
#define CRC_CTRL_TOTR_MASK              48U
#define CRC_CTRL_TOTR_BITNUM            4U
#define CRC_CTRL_TOT_MASK               192U
#define CRC_CTRL_TOT_BITNUM             6U


/*** RTC_SC1 - RTC Status and Control Register 1; 0x0000306A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RTCO        :1;                                       /* Real-Time Counter Output */
    byte             :1; 
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
} RTC_SC1STR;
extern volatile RTC_SC1STR _RTC_SC1 @0x0000306A;
#define RTC_SC1                         _RTC_SC1.Byte
#define RTC_SC1_RTCO                    _RTC_SC1.Bits.RTCO
#define RTC_SC1_RTIE                    _RTC_SC1.Bits.RTIE
#define RTC_SC1_RTIF                    _RTC_SC1.Bits.RTIF

#define RTC_SC1_RTCO_MASK               16U
#define RTC_SC1_RTIE_MASK               64U
#define RTC_SC1_RTIF_MASK               128U


/*** RTC_SC2 - RTC Status and Control Register 2; 0x0000306B ***/
typedef union {
  byte Byte;
  struct {
    byte RTCPS0      :1;                                       /* Real-Time Clock Prescaler Select, bit 0 */
    byte RTCPS1      :1;                                       /* Real-Time Clock Prescaler Select, bit 1 */
    byte RTCPS2      :1;                                       /* Real-Time Clock Prescaler Select, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RTCLKS0     :1;                                       /* Real-Time Clock Source Select, bit 0 */
    byte RTCLKS1     :1;                                       /* Real-Time Clock Source Select, bit 1 */
  } Bits;
  struct {
    byte grpRTCPS :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRTCLKS :2;
  } MergedBits;
} RTC_SC2STR;
extern volatile RTC_SC2STR _RTC_SC2 @0x0000306B;
#define RTC_SC2                         _RTC_SC2.Byte
#define RTC_SC2_RTCPS0                  _RTC_SC2.Bits.RTCPS0
#define RTC_SC2_RTCPS1                  _RTC_SC2.Bits.RTCPS1
#define RTC_SC2_RTCPS2                  _RTC_SC2.Bits.RTCPS2
#define RTC_SC2_RTCLKS0                 _RTC_SC2.Bits.RTCLKS0
#define RTC_SC2_RTCLKS1                 _RTC_SC2.Bits.RTCLKS1
#define RTC_SC2_RTCPS                   _RTC_SC2.MergedBits.grpRTCPS
#define RTC_SC2_RTCLKS                  _RTC_SC2.MergedBits.grpRTCLKS

#define RTC_SC2_RTCPS0_MASK             1U
#define RTC_SC2_RTCPS1_MASK             2U
#define RTC_SC2_RTCPS2_MASK             4U
#define RTC_SC2_RTCLKS0_MASK            64U
#define RTC_SC2_RTCLKS1_MASK            128U
#define RTC_SC2_RTCPS_MASK              7U
#define RTC_SC2_RTCPS_BITNUM            0U
#define RTC_SC2_RTCLKS_MASK             192U
#define RTC_SC2_RTCLKS_BITNUM           6U


/*** RTC_MOD - RTC Modulo Register; 0x0000306C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** RTC_MODH - RTC Modulo Register: High; 0x0000306C ***/
    union {
      byte Byte;
    } RTC_MODHSTR;
    #define RTC_MODH                    _RTC_MOD.Overlap_STR.RTC_MODHSTR.Byte
    

    /*** RTC_MODL - RTC Modulo Register: Low; 0x0000306D ***/
    union {
      byte Byte;
    } RTC_MODLSTR;
    #define RTC_MODL                    _RTC_MOD.Overlap_STR.RTC_MODLSTR.Byte
    
  } Overlap_STR;

} RTC_MODSTR;
extern volatile RTC_MODSTR _RTC_MOD @0x0000306C;
#define RTC_MOD                         _RTC_MOD.Word


/*** RTC_CNT - RTC Counter Register; 0x0000306E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** RTC_CNTH - RTC Counter Register: High; 0x0000306E ***/
    union {
      byte Byte;
    } RTC_CNTHSTR;
    #define RTC_CNTH                    _RTC_CNT.Overlap_STR.RTC_CNTHSTR.Byte
    

    /*** RTC_CNTL - RTC Counter Register: Low; 0x0000306F ***/
    union {
      byte Byte;
    } RTC_CNTLSTR;
    #define RTC_CNTL                    _RTC_CNT.Overlap_STR.RTC_CNTLSTR.Byte
    
  } Overlap_STR;

} RTC_CNTSTR;
extern volatile RTC_CNTSTR _RTC_CNT @0x0000306E;
#define RTC_CNT                         _RTC_CNT.Word


/*** I2C_A1 - I2C Address Register 1; 0x00003070 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte AD0         :1;                                       /* Address, bit 0 */
    byte AD1         :1;                                       /* Address, bit 1 */
    byte AD2         :1;                                       /* Address, bit 2 */
    byte AD3         :1;                                       /* Address, bit 3 */
    byte AD4         :1;                                       /* Address, bit 4 */
    byte AD5         :1;                                       /* Address, bit 5 */
    byte AD6         :1;                                       /* Address, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpAD   :7;
  } MergedBits;
} I2C_A1STR;
extern volatile I2C_A1STR _I2C_A1 @0x00003070;
#define I2C_A1                          _I2C_A1.Byte
#define I2C_A1_AD0                      _I2C_A1.Bits.AD0
#define I2C_A1_AD1                      _I2C_A1.Bits.AD1
#define I2C_A1_AD2                      _I2C_A1.Bits.AD2
#define I2C_A1_AD3                      _I2C_A1.Bits.AD3
#define I2C_A1_AD4                      _I2C_A1.Bits.AD4
#define I2C_A1_AD5                      _I2C_A1.Bits.AD5
#define I2C_A1_AD6                      _I2C_A1.Bits.AD6
#define I2C_A1_AD                       _I2C_A1.MergedBits.grpAD

#define I2C_A1_AD0_MASK                 2U
#define I2C_A1_AD1_MASK                 4U
#define I2C_A1_AD2_MASK                 8U
#define I2C_A1_AD3_MASK                 16U
#define I2C_A1_AD4_MASK                 32U
#define I2C_A1_AD5_MASK                 64U
#define I2C_A1_AD6_MASK                 128U
#define I2C_A1_AD_MASK                  254U
#define I2C_A1_AD_BITNUM                1U


/*** I2C_F - I2C Frequency Divider register; 0x00003071 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* Clock rate, bit 0 */
    byte ICR1        :1;                                       /* Clock rate, bit 1 */
    byte ICR2        :1;                                       /* Clock rate, bit 2 */
    byte ICR3        :1;                                       /* Clock rate, bit 3 */
    byte ICR4        :1;                                       /* Clock rate, bit 4 */
    byte ICR5        :1;                                       /* Clock rate, bit 5 */
    byte MULT0       :1;                                       /* The MULT bits define the multiplier factor mul. This factor is used along with the SCL divider to generate the I2C baud rate, bit 0 */
    byte MULT1       :1;                                       /* The MULT bits define the multiplier factor mul. This factor is used along with the SCL divider to generate the I2C baud rate, bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} I2C_FSTR;
extern volatile I2C_FSTR _I2C_F @0x00003071;
#define I2C_F                           _I2C_F.Byte
#define I2C_F_ICR0                      _I2C_F.Bits.ICR0
#define I2C_F_ICR1                      _I2C_F.Bits.ICR1
#define I2C_F_ICR2                      _I2C_F.Bits.ICR2
#define I2C_F_ICR3                      _I2C_F.Bits.ICR3
#define I2C_F_ICR4                      _I2C_F.Bits.ICR4
#define I2C_F_ICR5                      _I2C_F.Bits.ICR5
#define I2C_F_MULT0                     _I2C_F.Bits.MULT0
#define I2C_F_MULT1                     _I2C_F.Bits.MULT1
#define I2C_F_ICR                       _I2C_F.MergedBits.grpICR
#define I2C_F_MULT                      _I2C_F.MergedBits.grpMULT

#define I2C_F_ICR0_MASK                 1U
#define I2C_F_ICR1_MASK                 2U
#define I2C_F_ICR2_MASK                 4U
#define I2C_F_ICR3_MASK                 8U
#define I2C_F_ICR4_MASK                 16U
#define I2C_F_ICR5_MASK                 32U
#define I2C_F_MULT0_MASK                64U
#define I2C_F_MULT1_MASK                128U
#define I2C_F_ICR_MASK                  63U
#define I2C_F_ICR_BITNUM                0U
#define I2C_F_MULT_MASK                 192U
#define I2C_F_MULT_BITNUM               6U


/*** I2C_C1 - I2C Control Register 1; 0x00003072 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte WUEN        :1;                                       /* Wakeup enable */
    byte RSTA        :1;                                       /* Repeat START */
    byte TXAK        :1;                                       /* Transmit acknowledge enable */
    byte TX          :1;                                       /* Transmit mode select */
    byte MST         :1;                                       /* Master mode select */
    byte IICIE       :1;                                       /* I2C interrupt enable */
    byte IICEN       :1;                                       /* I2C enable */
  } Bits;
} I2C_C1STR;
extern volatile I2C_C1STR _I2C_C1 @0x00003072;
#define I2C_C1                          _I2C_C1.Byte
#define I2C_C1_WUEN                     _I2C_C1.Bits.WUEN
#define I2C_C1_RSTA                     _I2C_C1.Bits.RSTA
#define I2C_C1_TXAK                     _I2C_C1.Bits.TXAK
#define I2C_C1_TX                       _I2C_C1.Bits.TX
#define I2C_C1_MST                      _I2C_C1.Bits.MST
#define I2C_C1_IICIE                    _I2C_C1.Bits.IICIE
#define I2C_C1_IICEN                    _I2C_C1.Bits.IICEN

#define I2C_C1_WUEN_MASK                2U
#define I2C_C1_RSTA_MASK                4U
#define I2C_C1_TXAK_MASK                8U
#define I2C_C1_TX_MASK                  16U
#define I2C_C1_MST_MASK                 32U
#define I2C_C1_IICIE_MASK               64U
#define I2C_C1_IICEN_MASK               128U


/*** I2C_S - I2C Status Register; 0x00003073 ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive acknowledge */
    byte IICIF       :1;                                       /* Interrupt flag */
    byte SRW         :1;                                       /* Slave read/write */
    byte RAM         :1;                                       /* Range address match */
    byte ARBL        :1;                                       /* Arbitration lost */
    byte BUSY        :1;                                       /* Bus busy */
    byte IAAS        :1;                                       /* Addressed as a slave */
    byte TCF         :1;                                       /* Transfer complete flag */
  } Bits;
} I2C_SSTR;
extern volatile I2C_SSTR _I2C_S @0x00003073;
#define I2C_S                           _I2C_S.Byte
#define I2C_S_RXAK                      _I2C_S.Bits.RXAK
#define I2C_S_IICIF                     _I2C_S.Bits.IICIF
#define I2C_S_SRW                       _I2C_S.Bits.SRW
#define I2C_S_RAM                       _I2C_S.Bits.RAM
#define I2C_S_ARBL                      _I2C_S.Bits.ARBL
#define I2C_S_BUSY                      _I2C_S.Bits.BUSY
#define I2C_S_IAAS                      _I2C_S.Bits.IAAS
#define I2C_S_TCF                       _I2C_S.Bits.TCF

#define I2C_S_RXAK_MASK                 1U
#define I2C_S_IICIF_MASK                2U
#define I2C_S_SRW_MASK                  4U
#define I2C_S_RAM_MASK                  8U
#define I2C_S_ARBL_MASK                 16U
#define I2C_S_BUSY_MASK                 32U
#define I2C_S_IAAS_MASK                 64U
#define I2C_S_TCF_MASK                  128U


/*** I2C_D - I2C Data I/O register; 0x00003074 ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* Data, bit 0 */
    byte DATA1       :1;                                       /* Data, bit 1 */
    byte DATA2       :1;                                       /* Data, bit 2 */
    byte DATA3       :1;                                       /* Data, bit 3 */
    byte DATA4       :1;                                       /* Data, bit 4 */
    byte DATA5       :1;                                       /* Data, bit 5 */
    byte DATA6       :1;                                       /* Data, bit 6 */
    byte DATA7       :1;                                       /* Data, bit 7 */
  } Bits;
} I2C_DSTR;
extern volatile I2C_DSTR _I2C_D @0x00003074;
#define I2C_D                           _I2C_D.Byte
#define I2C_D_DATA0                     _I2C_D.Bits.DATA0
#define I2C_D_DATA1                     _I2C_D.Bits.DATA1
#define I2C_D_DATA2                     _I2C_D.Bits.DATA2
#define I2C_D_DATA3                     _I2C_D.Bits.DATA3
#define I2C_D_DATA4                     _I2C_D.Bits.DATA4
#define I2C_D_DATA5                     _I2C_D.Bits.DATA5
#define I2C_D_DATA6                     _I2C_D.Bits.DATA6
#define I2C_D_DATA7                     _I2C_D.Bits.DATA7

#define I2C_D_DATA0_MASK                1U
#define I2C_D_DATA1_MASK                2U
#define I2C_D_DATA2_MASK                4U
#define I2C_D_DATA3_MASK                8U
#define I2C_D_DATA4_MASK                16U
#define I2C_D_DATA5_MASK                32U
#define I2C_D_DATA6_MASK                64U
#define I2C_D_DATA7_MASK                128U


/*** I2C_C2 - I2C Control Register 2; 0x00003075 ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1; 
    byte AD9         :1; 
    byte AD10        :1; 
    byte RMEN        :1;                                       /* Range address matching enable */
    byte SBRC        :1;                                       /* Slave baud rate control */
    byte HDRS        :1;                                       /* High drive select */
    byte ADEXT       :1;                                       /* Address extension */
    byte GCAEN       :1;                                       /* General call address enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} I2C_C2STR;
extern volatile I2C_C2STR _I2C_C2 @0x00003075;
#define I2C_C2                          _I2C_C2.Byte
#define I2C_C2_AD8                      _I2C_C2.Bits.AD8
#define I2C_C2_AD9                      _I2C_C2.Bits.AD9
#define I2C_C2_AD10                     _I2C_C2.Bits.AD10
#define I2C_C2_RMEN                     _I2C_C2.Bits.RMEN
#define I2C_C2_SBRC                     _I2C_C2.Bits.SBRC
#define I2C_C2_HDRS                     _I2C_C2.Bits.HDRS
#define I2C_C2_ADEXT                    _I2C_C2.Bits.ADEXT
#define I2C_C2_GCAEN                    _I2C_C2.Bits.GCAEN
#define I2C_C2_AD_8                     _I2C_C2.MergedBits.grpAD_8
#define I2C_C2_AD                       I2C_C2_AD_8

#define I2C_C2_AD8_MASK                 1U
#define I2C_C2_AD9_MASK                 2U
#define I2C_C2_AD10_MASK                4U
#define I2C_C2_RMEN_MASK                8U
#define I2C_C2_SBRC_MASK                16U
#define I2C_C2_HDRS_MASK                32U
#define I2C_C2_ADEXT_MASK               64U
#define I2C_C2_GCAEN_MASK               128U
#define I2C_C2_AD_8_MASK                7U
#define I2C_C2_AD_8_BITNUM              0U


/*** I2C_FLT - I2C Programmable Input Glitch Filter register; 0x00003076 ***/
typedef union {
  byte Byte;
  struct {
    byte FLT0        :1;                                       /* I2C programmable filter factor, bit 0 */
    byte FLT1        :1;                                       /* I2C programmable filter factor, bit 1 */
    byte FLT2        :1;                                       /* I2C programmable filter factor, bit 2 */
    byte FLT3        :1;                                       /* I2C programmable filter factor, bit 3 */
    byte FLT4        :1;                                       /* I2C programmable filter factor, bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFLT  :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} I2C_FLTSTR;
extern volatile I2C_FLTSTR _I2C_FLT @0x00003076;
#define I2C_FLT                         _I2C_FLT.Byte
#define I2C_FLT_FLT0                    _I2C_FLT.Bits.FLT0
#define I2C_FLT_FLT1                    _I2C_FLT.Bits.FLT1
#define I2C_FLT_FLT2                    _I2C_FLT.Bits.FLT2
#define I2C_FLT_FLT3                    _I2C_FLT.Bits.FLT3
#define I2C_FLT_FLT4                    _I2C_FLT.Bits.FLT4
#define I2C_FLT_FLT                     _I2C_FLT.MergedBits.grpFLT

#define I2C_FLT_FLT0_MASK               1U
#define I2C_FLT_FLT1_MASK               2U
#define I2C_FLT_FLT2_MASK               4U
#define I2C_FLT_FLT3_MASK               8U
#define I2C_FLT_FLT4_MASK               16U
#define I2C_FLT_FLT_MASK                31U
#define I2C_FLT_FLT_BITNUM              0U


/*** I2C_RA - I2C Range Address register; 0x00003077 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte RAD0        :1;                                       /* Range slave address, bit 0 */
    byte RAD1        :1;                                       /* Range slave address, bit 1 */
    byte RAD2        :1;                                       /* Range slave address, bit 2 */
    byte RAD3        :1;                                       /* Range slave address, bit 3 */
    byte RAD4        :1;                                       /* Range slave address, bit 4 */
    byte RAD5        :1;                                       /* Range slave address, bit 5 */
    byte RAD6        :1;                                       /* Range slave address, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpRAD  :7;
  } MergedBits;
} I2C_RASTR;
extern volatile I2C_RASTR _I2C_RA @0x00003077;
#define I2C_RA                          _I2C_RA.Byte
#define I2C_RA_RAD0                     _I2C_RA.Bits.RAD0
#define I2C_RA_RAD1                     _I2C_RA.Bits.RAD1
#define I2C_RA_RAD2                     _I2C_RA.Bits.RAD2
#define I2C_RA_RAD3                     _I2C_RA.Bits.RAD3
#define I2C_RA_RAD4                     _I2C_RA.Bits.RAD4
#define I2C_RA_RAD5                     _I2C_RA.Bits.RAD5
#define I2C_RA_RAD6                     _I2C_RA.Bits.RAD6
#define I2C_RA_RAD                      _I2C_RA.MergedBits.grpRAD

#define I2C_RA_RAD0_MASK                2U
#define I2C_RA_RAD1_MASK                4U
#define I2C_RA_RAD2_MASK                8U
#define I2C_RA_RAD3_MASK                16U
#define I2C_RA_RAD4_MASK                32U
#define I2C_RA_RAD5_MASK                64U
#define I2C_RA_RAD6_MASK                128U
#define I2C_RA_RAD_MASK                 254U
#define I2C_RA_RAD_BITNUM               1U


/*** I2C_SMB - I2C SMBus Control and Status register; 0x00003078 ***/
typedef union {
  byte Byte;
  struct {
    byte SHTF2IE     :1;                                       /* SHTF2 interrupt enable */
    byte SHTF2       :1;                                       /* SCL high timeout flag 2 */
    byte SHTF1       :1;                                       /* SCL high timeout flag 1 */
    byte SLTF        :1;                                       /* SCL low timeout flag */
    byte TCKSEL      :1;                                       /* Timeout counter clock select */
    byte SIICAEN     :1;                                       /* Second I2C address enable */
    byte ALERTEN     :1;                                       /* SMBus alert response address enable */
    byte FACK        :1;                                       /* Fast NACK/ACK enable */
  } Bits;
} I2C_SMBSTR;
extern volatile I2C_SMBSTR _I2C_SMB @0x00003078;
#define I2C_SMB                         _I2C_SMB.Byte
#define I2C_SMB_SHTF2IE                 _I2C_SMB.Bits.SHTF2IE
#define I2C_SMB_SHTF2                   _I2C_SMB.Bits.SHTF2
#define I2C_SMB_SHTF1                   _I2C_SMB.Bits.SHTF1
#define I2C_SMB_SLTF                    _I2C_SMB.Bits.SLTF
#define I2C_SMB_TCKSEL                  _I2C_SMB.Bits.TCKSEL
#define I2C_SMB_SIICAEN                 _I2C_SMB.Bits.SIICAEN
#define I2C_SMB_ALERTEN                 _I2C_SMB.Bits.ALERTEN
#define I2C_SMB_FACK                    _I2C_SMB.Bits.FACK

#define I2C_SMB_SHTF2IE_MASK            1U
#define I2C_SMB_SHTF2_MASK              2U
#define I2C_SMB_SHTF1_MASK              4U
#define I2C_SMB_SLTF_MASK               8U
#define I2C_SMB_TCKSEL_MASK             16U
#define I2C_SMB_SIICAEN_MASK            32U
#define I2C_SMB_ALERTEN_MASK            64U
#define I2C_SMB_FACK_MASK               128U


/*** I2C_A2 - I2C Address Register 2; 0x00003079 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte SAD0        :1;                                       /* SMBus address, bit 0 */
    byte SAD1        :1;                                       /* SMBus address, bit 1 */
    byte SAD2        :1;                                       /* SMBus address, bit 2 */
    byte SAD3        :1;                                       /* SMBus address, bit 3 */
    byte SAD4        :1;                                       /* SMBus address, bit 4 */
    byte SAD5        :1;                                       /* SMBus address, bit 5 */
    byte SAD6        :1;                                       /* SMBus address, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpSAD  :7;
  } MergedBits;
} I2C_A2STR;
extern volatile I2C_A2STR _I2C_A2 @0x00003079;
#define I2C_A2                          _I2C_A2.Byte
#define I2C_A2_SAD0                     _I2C_A2.Bits.SAD0
#define I2C_A2_SAD1                     _I2C_A2.Bits.SAD1
#define I2C_A2_SAD2                     _I2C_A2.Bits.SAD2
#define I2C_A2_SAD3                     _I2C_A2.Bits.SAD3
#define I2C_A2_SAD4                     _I2C_A2.Bits.SAD4
#define I2C_A2_SAD5                     _I2C_A2.Bits.SAD5
#define I2C_A2_SAD6                     _I2C_A2.Bits.SAD6
#define I2C_A2_SAD                      _I2C_A2.MergedBits.grpSAD

#define I2C_A2_SAD0_MASK                2U
#define I2C_A2_SAD1_MASK                4U
#define I2C_A2_SAD2_MASK                8U
#define I2C_A2_SAD3_MASK                16U
#define I2C_A2_SAD4_MASK                32U
#define I2C_A2_SAD5_MASK                64U
#define I2C_A2_SAD6_MASK                128U
#define I2C_A2_SAD_MASK                 254U
#define I2C_A2_SAD_BITNUM               1U


/*** I2C_SLT - I2C SCL Low Timeout register; 0x0000307A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** I2C_SLTH - I2C SCL Low Timeout Register High; 0x0000307A ***/
    union {
      byte Byte;
      struct {
        byte SSLT0       :1;                                       /* Most significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 0 */
        byte SSLT1       :1;                                       /* Most significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 1 */
        byte SSLT2       :1;                                       /* Most significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 2 */
        byte SSLT3       :1;                                       /* Most significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 3 */
        byte SSLT4       :1;                                       /* Most significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 4 */
        byte SSLT5       :1;                                       /* Most significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 5 */
        byte SSLT6       :1;                                       /* Most significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 6 */
        byte SSLT7       :1;                                       /* Most significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 7 */
      } Bits;
    } I2C_SLTHSTR;
    #define I2C_SLTH                    _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Byte
    #define I2C_SLTH_SSLT0              _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Bits.SSLT0
    #define I2C_SLTH_SSLT1              _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Bits.SSLT1
    #define I2C_SLTH_SSLT2              _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Bits.SSLT2
    #define I2C_SLTH_SSLT3              _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Bits.SSLT3
    #define I2C_SLTH_SSLT4              _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Bits.SSLT4
    #define I2C_SLTH_SSLT5              _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Bits.SSLT5
    #define I2C_SLTH_SSLT6              _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Bits.SSLT6
    #define I2C_SLTH_SSLT7              _I2C_SLT.Overlap_STR.I2C_SLTHSTR.Bits.SSLT7
    
    #define I2C_SLTH_SSLT0_MASK         1U
    #define I2C_SLTH_SSLT1_MASK         2U
    #define I2C_SLTH_SSLT2_MASK         4U
    #define I2C_SLTH_SSLT3_MASK         8U
    #define I2C_SLTH_SSLT4_MASK         16U
    #define I2C_SLTH_SSLT5_MASK         32U
    #define I2C_SLTH_SSLT6_MASK         64U
    #define I2C_SLTH_SSLT7_MASK         128U
    

    /*** I2C_SLTL - I2C SCL Low Timeout Register Low; 0x0000307B ***/
    union {
      byte Byte;
      struct {
        byte SSLT0       :1;                                       /* Least significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 0 */
        byte SSLT1       :1;                                       /* Least significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 1 */
        byte SSLT2       :1;                                       /* Least significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 2 */
        byte SSLT3       :1;                                       /* Least significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 3 */
        byte SSLT4       :1;                                       /* Least significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 4 */
        byte SSLT5       :1;                                       /* Least significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 5 */
        byte SSLT6       :1;                                       /* Least significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 6 */
        byte SSLT7       :1;                                       /* Least significant byte of SCL low timeout value that determines the timeout period of SCL low, bit 7 */
      } Bits;
    } I2C_SLTLSTR;
    #define I2C_SLTL                    _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Byte
    #define I2C_SLTL_SSLT0              _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Bits.SSLT0
    #define I2C_SLTL_SSLT1              _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Bits.SSLT1
    #define I2C_SLTL_SSLT2              _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Bits.SSLT2
    #define I2C_SLTL_SSLT3              _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Bits.SSLT3
    #define I2C_SLTL_SSLT4              _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Bits.SSLT4
    #define I2C_SLTL_SSLT5              _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Bits.SSLT5
    #define I2C_SLTL_SSLT6              _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Bits.SSLT6
    #define I2C_SLTL_SSLT7              _I2C_SLT.Overlap_STR.I2C_SLTLSTR.Bits.SSLT7
    
    #define I2C_SLTL_SSLT0_MASK         1U
    #define I2C_SLTL_SSLT1_MASK         2U
    #define I2C_SLTL_SSLT2_MASK         4U
    #define I2C_SLTL_SSLT3_MASK         8U
    #define I2C_SLTL_SSLT4_MASK         16U
    #define I2C_SLTL_SSLT5_MASK         32U
    #define I2C_SLTL_SSLT6_MASK         64U
    #define I2C_SLTL_SSLT7_MASK         128U
    
  } Overlap_STR;

} I2C_SLTSTR;
extern volatile I2C_SLTSTR _I2C_SLT @0x0000307A;
#define I2C_SLT                         _I2C_SLT.Word


/*** KBI0_PE - KBIx Pin Enable Register; 0x0000307C ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1; 
    byte KBIPE1      :1; 
    byte KBIPE2      :1; 
    byte KBIPE3      :1; 
    byte KBIPE4      :1; 
    byte KBIPE5      :1; 
    byte KBIPE6      :1; 
    byte KBIPE7      :1; 
  } Bits;
} KBI0_PESTR;
extern volatile KBI0_PESTR _KBI0_PE @0x0000307C;
#define KBI0_PE                         _KBI0_PE.Byte
#define KBI0_PE_KBIPE0                  _KBI0_PE.Bits.KBIPE0
#define KBI0_PE_KBIPE1                  _KBI0_PE.Bits.KBIPE1
#define KBI0_PE_KBIPE2                  _KBI0_PE.Bits.KBIPE2
#define KBI0_PE_KBIPE3                  _KBI0_PE.Bits.KBIPE3
#define KBI0_PE_KBIPE4                  _KBI0_PE.Bits.KBIPE4
#define KBI0_PE_KBIPE5                  _KBI0_PE.Bits.KBIPE5
#define KBI0_PE_KBIPE6                  _KBI0_PE.Bits.KBIPE6
#define KBI0_PE_KBIPE7                  _KBI0_PE.Bits.KBIPE7

#define KBI0_PE_KBIPE0_MASK             1U
#define KBI0_PE_KBIPE1_MASK             2U
#define KBI0_PE_KBIPE2_MASK             4U
#define KBI0_PE_KBIPE3_MASK             8U
#define KBI0_PE_KBIPE4_MASK             16U
#define KBI0_PE_KBIPE5_MASK             32U
#define KBI0_PE_KBIPE6_MASK             64U
#define KBI0_PE_KBIPE7_MASK             128U


/*** KBI0_ES - KBIx Edge Select Register; 0x0000307D ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1; 
    byte KBEDG1      :1; 
    byte KBEDG2      :1; 
    byte KBEDG3      :1; 
    byte KBEDG4      :1; 
    byte KBEDG5      :1; 
    byte KBEDG6      :1; 
    byte KBEDG7      :1; 
  } Bits;
} KBI0_ESSTR;
extern volatile KBI0_ESSTR _KBI0_ES @0x0000307D;
#define KBI0_ES                         _KBI0_ES.Byte
#define KBI0_ES_KBEDG0                  _KBI0_ES.Bits.KBEDG0
#define KBI0_ES_KBEDG1                  _KBI0_ES.Bits.KBEDG1
#define KBI0_ES_KBEDG2                  _KBI0_ES.Bits.KBEDG2
#define KBI0_ES_KBEDG3                  _KBI0_ES.Bits.KBEDG3
#define KBI0_ES_KBEDG4                  _KBI0_ES.Bits.KBEDG4
#define KBI0_ES_KBEDG5                  _KBI0_ES.Bits.KBEDG5
#define KBI0_ES_KBEDG6                  _KBI0_ES.Bits.KBEDG6
#define KBI0_ES_KBEDG7                  _KBI0_ES.Bits.KBEDG7

#define KBI0_ES_KBEDG0_MASK             1U
#define KBI0_ES_KBEDG1_MASK             2U
#define KBI0_ES_KBEDG2_MASK             4U
#define KBI0_ES_KBEDG3_MASK             8U
#define KBI0_ES_KBEDG4_MASK             16U
#define KBI0_ES_KBEDG5_MASK             32U
#define KBI0_ES_KBEDG6_MASK             64U
#define KBI0_ES_KBEDG7_MASK             128U


/*** KBI1_PE - KBIx Pin Enable Register; 0x0000307E ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1; 
    byte KBIPE1      :1; 
    byte KBIPE2      :1; 
    byte KBIPE3      :1; 
    byte KBIPE4      :1; 
    byte KBIPE5      :1; 
    byte KBIPE6      :1; 
    byte KBIPE7      :1; 
  } Bits;
} KBI1_PESTR;
extern volatile KBI1_PESTR _KBI1_PE @0x0000307E;
#define KBI1_PE                         _KBI1_PE.Byte
#define KBI1_PE_KBIPE0                  _KBI1_PE.Bits.KBIPE0
#define KBI1_PE_KBIPE1                  _KBI1_PE.Bits.KBIPE1
#define KBI1_PE_KBIPE2                  _KBI1_PE.Bits.KBIPE2
#define KBI1_PE_KBIPE3                  _KBI1_PE.Bits.KBIPE3
#define KBI1_PE_KBIPE4                  _KBI1_PE.Bits.KBIPE4
#define KBI1_PE_KBIPE5                  _KBI1_PE.Bits.KBIPE5
#define KBI1_PE_KBIPE6                  _KBI1_PE.Bits.KBIPE6
#define KBI1_PE_KBIPE7                  _KBI1_PE.Bits.KBIPE7

#define KBI1_PE_KBIPE0_MASK             1U
#define KBI1_PE_KBIPE1_MASK             2U
#define KBI1_PE_KBIPE2_MASK             4U
#define KBI1_PE_KBIPE3_MASK             8U
#define KBI1_PE_KBIPE4_MASK             16U
#define KBI1_PE_KBIPE5_MASK             32U
#define KBI1_PE_KBIPE6_MASK             64U
#define KBI1_PE_KBIPE7_MASK             128U


/*** KBI1_ES - KBIx Edge Select Register; 0x0000307F ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1; 
    byte KBEDG1      :1; 
    byte KBEDG2      :1; 
    byte KBEDG3      :1; 
    byte KBEDG4      :1; 
    byte KBEDG5      :1; 
    byte KBEDG6      :1; 
    byte KBEDG7      :1; 
  } Bits;
} KBI1_ESSTR;
extern volatile KBI1_ESSTR _KBI1_ES @0x0000307F;
#define KBI1_ES                         _KBI1_ES.Byte
#define KBI1_ES_KBEDG0                  _KBI1_ES.Bits.KBEDG0
#define KBI1_ES_KBEDG1                  _KBI1_ES.Bits.KBEDG1
#define KBI1_ES_KBEDG2                  _KBI1_ES.Bits.KBEDG2
#define KBI1_ES_KBEDG3                  _KBI1_ES.Bits.KBEDG3
#define KBI1_ES_KBEDG4                  _KBI1_ES.Bits.KBEDG4
#define KBI1_ES_KBEDG5                  _KBI1_ES.Bits.KBEDG5
#define KBI1_ES_KBEDG6                  _KBI1_ES.Bits.KBEDG6
#define KBI1_ES_KBEDG7                  _KBI1_ES.Bits.KBEDG7

#define KBI1_ES_KBEDG0_MASK             1U
#define KBI1_ES_KBEDG1_MASK             2U
#define KBI1_ES_KBEDG2_MASK             4U
#define KBI1_ES_KBEDG3_MASK             8U
#define KBI1_ES_KBEDG4_MASK             16U
#define KBI1_ES_KBEDG5_MASK             32U
#define KBI1_ES_KBEDG6_MASK             64U
#define KBI1_ES_KBEDG7_MASK             128U


/*** SCI0_BD - SCI0 Baud Rate Register; 0x00003080 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI0_BDH - SCI Baud Rate Register: High; 0x00003080 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor, bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor, bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor, bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor, bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor, bit 4 */
        byte SBNS        :1;                                       /* Stop Bit Number Select */
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI0_BDHSTR;
    #define SCI0_BDH                    _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Byte
    #define SCI0_BDH_SBR0               _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Bits.SBR0
    #define SCI0_BDH_SBR1               _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Bits.SBR1
    #define SCI0_BDH_SBR2               _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Bits.SBR2
    #define SCI0_BDH_SBR3               _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Bits.SBR3
    #define SCI0_BDH_SBR4               _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Bits.SBR4
    #define SCI0_BDH_SBNS               _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Bits.SBNS
    #define SCI0_BDH_RXEDGIE            _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Bits.RXEDGIE
    #define SCI0_BDH_LBKDIE             _SCI0_BD.Overlap_STR.SCI0_BDHSTR.Bits.LBKDIE
    #define SCI0_BDH_SBR                _SCI0_BD.Overlap_STR.SCI0_BDHSTR.MergedBits.grpSBR
    
    #define SCI0_BDH_SBR0_MASK          1U
    #define SCI0_BDH_SBR1_MASK          2U
    #define SCI0_BDH_SBR2_MASK          4U
    #define SCI0_BDH_SBR3_MASK          8U
    #define SCI0_BDH_SBR4_MASK          16U
    #define SCI0_BDH_SBNS_MASK          32U
    #define SCI0_BDH_RXEDGIE_MASK       64U
    #define SCI0_BDH_LBKDIE_MASK        128U
    #define SCI0_BDH_SBR_MASK           31U
    #define SCI0_BDH_SBR_BITNUM         0U
    

    /*** SCI0_BDL - SCI Baud Rate Register: Low; 0x00003081 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor, bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor, bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor, bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor, bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor, bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor, bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor, bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor, bit 7 */
      } Bits;
    } SCI0_BDLSTR;
    #define SCI0_BDL                    _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Byte
    #define SCI0_BDL_SBR0               _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Bits.SBR0
    #define SCI0_BDL_SBR1               _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Bits.SBR1
    #define SCI0_BDL_SBR2               _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Bits.SBR2
    #define SCI0_BDL_SBR3               _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Bits.SBR3
    #define SCI0_BDL_SBR4               _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Bits.SBR4
    #define SCI0_BDL_SBR5               _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Bits.SBR5
    #define SCI0_BDL_SBR6               _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Bits.SBR6
    #define SCI0_BDL_SBR7               _SCI0_BD.Overlap_STR.SCI0_BDLSTR.Bits.SBR7
    
    #define SCI0_BDL_SBR0_MASK          1U
    #define SCI0_BDL_SBR1_MASK          2U
    #define SCI0_BDL_SBR2_MASK          4U
    #define SCI0_BDL_SBR3_MASK          8U
    #define SCI0_BDL_SBR4_MASK          16U
    #define SCI0_BDL_SBR5_MASK          32U
    #define SCI0_BDL_SBR6_MASK          64U
    #define SCI0_BDL_SBR7_MASK          128U
    
  } Overlap_STR;

} SCI0_BDSTR;
extern volatile SCI0_BDSTR _SCI0_BD @0x00003080;
#define SCI0_BD                         _SCI0_BD.Word


/*** SCI0_C1 - SCI Control Register 1; 0x00003082 ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI0_C1STR;
extern volatile SCI0_C1STR _SCI0_C1 @0x00003082;
#define SCI0_C1                         _SCI0_C1.Byte
#define SCI0_C1_PT                      _SCI0_C1.Bits.PT
#define SCI0_C1_PE                      _SCI0_C1.Bits.PE
#define SCI0_C1_ILT                     _SCI0_C1.Bits.ILT
#define SCI0_C1_WAKE                    _SCI0_C1.Bits.WAKE
#define SCI0_C1_M                       _SCI0_C1.Bits.M
#define SCI0_C1_RSRC                    _SCI0_C1.Bits.RSRC
#define SCI0_C1_SCISWAI                 _SCI0_C1.Bits.SCISWAI
#define SCI0_C1_LOOPS                   _SCI0_C1.Bits.LOOPS

#define SCI0_C1_PT_MASK                 1U
#define SCI0_C1_PE_MASK                 2U
#define SCI0_C1_ILT_MASK                4U
#define SCI0_C1_WAKE_MASK               8U
#define SCI0_C1_M_MASK                  16U
#define SCI0_C1_RSRC_MASK               32U
#define SCI0_C1_SCISWAI_MASK            64U
#define SCI0_C1_LOOPS_MASK              128U


/*** SCI0_C2 - SCI Control Register 2; 0x00003083 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable for IDLE */
    byte RIE         :1;                                       /* Receiver Interrupt Enable for RDRF */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable for TC */
    byte TIE         :1;                                       /* Transmit Interrupt Enable for TDRE */
  } Bits;
} SCI0_C2STR;
extern volatile SCI0_C2STR _SCI0_C2 @0x00003083;
#define SCI0_C2                         _SCI0_C2.Byte
#define SCI0_C2_SBK                     _SCI0_C2.Bits.SBK
#define SCI0_C2_RWU                     _SCI0_C2.Bits.RWU
#define SCI0_C2_RE                      _SCI0_C2.Bits.RE
#define SCI0_C2_TE                      _SCI0_C2.Bits.TE
#define SCI0_C2_ILIE                    _SCI0_C2.Bits.ILIE
#define SCI0_C2_RIE                     _SCI0_C2.Bits.RIE
#define SCI0_C2_TCIE                    _SCI0_C2.Bits.TCIE
#define SCI0_C2_TIE                     _SCI0_C2.Bits.TIE

#define SCI0_C2_SBK_MASK                1U
#define SCI0_C2_RWU_MASK                2U
#define SCI0_C2_RE_MASK                 4U
#define SCI0_C2_TE_MASK                 8U
#define SCI0_C2_ILIE_MASK               16U
#define SCI0_C2_RIE_MASK                32U
#define SCI0_C2_TCIE_MASK               64U
#define SCI0_C2_TIE_MASK                128U


/*** SCI0_S1 - SCI Status Register 1; 0x00003084 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI0_S1STR;
extern volatile SCI0_S1STR _SCI0_S1 @0x00003084;
#define SCI0_S1                         _SCI0_S1.Byte
#define SCI0_S1_PF                      _SCI0_S1.Bits.PF
#define SCI0_S1_FE                      _SCI0_S1.Bits.FE
#define SCI0_S1_NF                      _SCI0_S1.Bits.NF
#define SCI0_S1_OR                      _SCI0_S1.Bits.OR
#define SCI0_S1_IDLE                    _SCI0_S1.Bits.IDLE
#define SCI0_S1_RDRF                    _SCI0_S1.Bits.RDRF
#define SCI0_S1_TC                      _SCI0_S1.Bits.TC
#define SCI0_S1_TDRE                    _SCI0_S1.Bits.TDRE

#define SCI0_S1_PF_MASK                 1U
#define SCI0_S1_FE_MASK                 2U
#define SCI0_S1_NF_MASK                 4U
#define SCI0_S1_OR_MASK                 8U
#define SCI0_S1_IDLE_MASK               16U
#define SCI0_S1_RDRF_MASK               32U
#define SCI0_S1_TC_MASK                 64U
#define SCI0_S1_TDRE_MASK               128U


/*** SCI0_S2 - SCI Status Register 2; 0x00003085 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI0_S2STR;
extern volatile SCI0_S2STR _SCI0_S2 @0x00003085;
#define SCI0_S2                         _SCI0_S2.Byte
#define SCI0_S2_RAF                     _SCI0_S2.Bits.RAF
#define SCI0_S2_LBKDE                   _SCI0_S2.Bits.LBKDE
#define SCI0_S2_BRK13                   _SCI0_S2.Bits.BRK13
#define SCI0_S2_RWUID                   _SCI0_S2.Bits.RWUID
#define SCI0_S2_RXINV                   _SCI0_S2.Bits.RXINV
#define SCI0_S2_RXEDGIF                 _SCI0_S2.Bits.RXEDGIF
#define SCI0_S2_LBKDIF                  _SCI0_S2.Bits.LBKDIF

#define SCI0_S2_RAF_MASK                1U
#define SCI0_S2_LBKDE_MASK              2U
#define SCI0_S2_BRK13_MASK              4U
#define SCI0_S2_RWUID_MASK              8U
#define SCI0_S2_RXINV_MASK              16U
#define SCI0_S2_RXEDGIF_MASK            64U
#define SCI0_S2_LBKDIF_MASK             128U


/*** SCI0_C3 - SCI Control Register 3; 0x00003086 ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI0_C3STR;
extern volatile SCI0_C3STR _SCI0_C3 @0x00003086;
#define SCI0_C3                         _SCI0_C3.Byte
#define SCI0_C3_PEIE                    _SCI0_C3.Bits.PEIE
#define SCI0_C3_FEIE                    _SCI0_C3.Bits.FEIE
#define SCI0_C3_NEIE                    _SCI0_C3.Bits.NEIE
#define SCI0_C3_ORIE                    _SCI0_C3.Bits.ORIE
#define SCI0_C3_TXINV                   _SCI0_C3.Bits.TXINV
#define SCI0_C3_TXDIR                   _SCI0_C3.Bits.TXDIR
#define SCI0_C3_T8                      _SCI0_C3.Bits.T8
#define SCI0_C3_R8                      _SCI0_C3.Bits.R8

#define SCI0_C3_PEIE_MASK               1U
#define SCI0_C3_FEIE_MASK               2U
#define SCI0_C3_NEIE_MASK               4U
#define SCI0_C3_ORIE_MASK               8U
#define SCI0_C3_TXINV_MASK              16U
#define SCI0_C3_TXDIR_MASK              32U
#define SCI0_C3_T8_MASK                 64U
#define SCI0_C3_R8_MASK                 128U


/*** SCI0_D - SCI Data Register; 0x00003087 ***/
typedef union {
  byte Byte;
  struct {
    byte R0T0        :1;                                       /* Read receive data buffer 0 or write transmit data buffer 0 */
    byte R1T1        :1;                                       /* Read receive data buffer 1 or write transmit data buffer 1 */
    byte R2T2        :1;                                       /* Read receive data buffer 2 or write transmit data buffer 2 */
    byte R3T3        :1;                                       /* Read receive data buffer 3 or write transmit data buffer 3 */
    byte R4T4        :1;                                       /* Read receive data buffer 4 or write transmit data buffer 4 */
    byte R5T5        :1;                                       /* Read receive data buffer 5 or write transmit data buffer 5 */
    byte R6T6        :1;                                       /* Read receive data buffer 6 or write transmit data buffer 6 */
    byte R7T7        :1;                                       /* Read receive data buffer 7 or write transmit data buffer 7 */
  } Bits;
} SCI0_DSTR;
extern volatile SCI0_DSTR _SCI0_D @0x00003087;
#define SCI0_D                          _SCI0_D.Byte
#define SCI0_D_R0T0                     _SCI0_D.Bits.R0T0
#define SCI0_D_R1T1                     _SCI0_D.Bits.R1T1
#define SCI0_D_R2T2                     _SCI0_D.Bits.R2T2
#define SCI0_D_R3T3                     _SCI0_D.Bits.R3T3
#define SCI0_D_R4T4                     _SCI0_D.Bits.R4T4
#define SCI0_D_R5T5                     _SCI0_D.Bits.R5T5
#define SCI0_D_R6T6                     _SCI0_D.Bits.R6T6
#define SCI0_D_R7T7                     _SCI0_D.Bits.R7T7

#define SCI0_D_R0T0_MASK                1U
#define SCI0_D_R1T1_MASK                2U
#define SCI0_D_R2T2_MASK                4U
#define SCI0_D_R3T3_MASK                8U
#define SCI0_D_R4T4_MASK                16U
#define SCI0_D_R5T5_MASK                32U
#define SCI0_D_R6T6_MASK                64U
#define SCI0_D_R7T7_MASK                128U


/*** SCI1_BD - SCI1 Baud Rate Register; 0x00003088 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1_BDH - SCI Baud Rate Register: High; 0x00003088 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor, bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor, bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor, bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor, bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor, bit 4 */
        byte SBNS        :1;                                       /* Stop Bit Number Select */
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI1_BDHSTR;
    #define SCI1_BDH                    _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Byte
    #define SCI1_BDH_SBR0               _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Bits.SBR0
    #define SCI1_BDH_SBR1               _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Bits.SBR1
    #define SCI1_BDH_SBR2               _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Bits.SBR2
    #define SCI1_BDH_SBR3               _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Bits.SBR3
    #define SCI1_BDH_SBR4               _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Bits.SBR4
    #define SCI1_BDH_SBNS               _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Bits.SBNS
    #define SCI1_BDH_RXEDGIE            _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Bits.RXEDGIE
    #define SCI1_BDH_LBKDIE             _SCI1_BD.Overlap_STR.SCI1_BDHSTR.Bits.LBKDIE
    #define SCI1_BDH_SBR                _SCI1_BD.Overlap_STR.SCI1_BDHSTR.MergedBits.grpSBR
    
    #define SCI1_BDH_SBR0_MASK          1U
    #define SCI1_BDH_SBR1_MASK          2U
    #define SCI1_BDH_SBR2_MASK          4U
    #define SCI1_BDH_SBR3_MASK          8U
    #define SCI1_BDH_SBR4_MASK          16U
    #define SCI1_BDH_SBNS_MASK          32U
    #define SCI1_BDH_RXEDGIE_MASK       64U
    #define SCI1_BDH_LBKDIE_MASK        128U
    #define SCI1_BDH_SBR_MASK           31U
    #define SCI1_BDH_SBR_BITNUM         0U
    

    /*** SCI1_BDL - SCI Baud Rate Register: Low; 0x00003089 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor, bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor, bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor, bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor, bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor, bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor, bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor, bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor, bit 7 */
      } Bits;
    } SCI1_BDLSTR;
    #define SCI1_BDL                    _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Byte
    #define SCI1_BDL_SBR0               _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Bits.SBR0
    #define SCI1_BDL_SBR1               _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Bits.SBR1
    #define SCI1_BDL_SBR2               _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Bits.SBR2
    #define SCI1_BDL_SBR3               _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Bits.SBR3
    #define SCI1_BDL_SBR4               _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Bits.SBR4
    #define SCI1_BDL_SBR5               _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Bits.SBR5
    #define SCI1_BDL_SBR6               _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Bits.SBR6
    #define SCI1_BDL_SBR7               _SCI1_BD.Overlap_STR.SCI1_BDLSTR.Bits.SBR7
    
    #define SCI1_BDL_SBR0_MASK          1U
    #define SCI1_BDL_SBR1_MASK          2U
    #define SCI1_BDL_SBR2_MASK          4U
    #define SCI1_BDL_SBR3_MASK          8U
    #define SCI1_BDL_SBR4_MASK          16U
    #define SCI1_BDL_SBR5_MASK          32U
    #define SCI1_BDL_SBR6_MASK          64U
    #define SCI1_BDL_SBR7_MASK          128U
    
  } Overlap_STR;

} SCI1_BDSTR;
extern volatile SCI1_BDSTR _SCI1_BD @0x00003088;
#define SCI1_BD                         _SCI1_BD.Word


/*** SCI1_C1 - SCI Control Register 1; 0x0000308A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI1_C1STR;
extern volatile SCI1_C1STR _SCI1_C1 @0x0000308A;
#define SCI1_C1                         _SCI1_C1.Byte
#define SCI1_C1_PT                      _SCI1_C1.Bits.PT
#define SCI1_C1_PE                      _SCI1_C1.Bits.PE
#define SCI1_C1_ILT                     _SCI1_C1.Bits.ILT
#define SCI1_C1_WAKE                    _SCI1_C1.Bits.WAKE
#define SCI1_C1_M                       _SCI1_C1.Bits.M
#define SCI1_C1_RSRC                    _SCI1_C1.Bits.RSRC
#define SCI1_C1_SCISWAI                 _SCI1_C1.Bits.SCISWAI
#define SCI1_C1_LOOPS                   _SCI1_C1.Bits.LOOPS

#define SCI1_C1_PT_MASK                 1U
#define SCI1_C1_PE_MASK                 2U
#define SCI1_C1_ILT_MASK                4U
#define SCI1_C1_WAKE_MASK               8U
#define SCI1_C1_M_MASK                  16U
#define SCI1_C1_RSRC_MASK               32U
#define SCI1_C1_SCISWAI_MASK            64U
#define SCI1_C1_LOOPS_MASK              128U


/*** SCI1_C2 - SCI Control Register 2; 0x0000308B ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable for IDLE */
    byte RIE         :1;                                       /* Receiver Interrupt Enable for RDRF */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable for TC */
    byte TIE         :1;                                       /* Transmit Interrupt Enable for TDRE */
  } Bits;
} SCI1_C2STR;
extern volatile SCI1_C2STR _SCI1_C2 @0x0000308B;
#define SCI1_C2                         _SCI1_C2.Byte
#define SCI1_C2_SBK                     _SCI1_C2.Bits.SBK
#define SCI1_C2_RWU                     _SCI1_C2.Bits.RWU
#define SCI1_C2_RE                      _SCI1_C2.Bits.RE
#define SCI1_C2_TE                      _SCI1_C2.Bits.TE
#define SCI1_C2_ILIE                    _SCI1_C2.Bits.ILIE
#define SCI1_C2_RIE                     _SCI1_C2.Bits.RIE
#define SCI1_C2_TCIE                    _SCI1_C2.Bits.TCIE
#define SCI1_C2_TIE                     _SCI1_C2.Bits.TIE

#define SCI1_C2_SBK_MASK                1U
#define SCI1_C2_RWU_MASK                2U
#define SCI1_C2_RE_MASK                 4U
#define SCI1_C2_TE_MASK                 8U
#define SCI1_C2_ILIE_MASK               16U
#define SCI1_C2_RIE_MASK                32U
#define SCI1_C2_TCIE_MASK               64U
#define SCI1_C2_TIE_MASK                128U


/*** SCI1_S1 - SCI Status Register 1; 0x0000308C ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI1_S1STR;
extern volatile SCI1_S1STR _SCI1_S1 @0x0000308C;
#define SCI1_S1                         _SCI1_S1.Byte
#define SCI1_S1_PF                      _SCI1_S1.Bits.PF
#define SCI1_S1_FE                      _SCI1_S1.Bits.FE
#define SCI1_S1_NF                      _SCI1_S1.Bits.NF
#define SCI1_S1_OR                      _SCI1_S1.Bits.OR
#define SCI1_S1_IDLE                    _SCI1_S1.Bits.IDLE
#define SCI1_S1_RDRF                    _SCI1_S1.Bits.RDRF
#define SCI1_S1_TC                      _SCI1_S1.Bits.TC
#define SCI1_S1_TDRE                    _SCI1_S1.Bits.TDRE

#define SCI1_S1_PF_MASK                 1U
#define SCI1_S1_FE_MASK                 2U
#define SCI1_S1_NF_MASK                 4U
#define SCI1_S1_OR_MASK                 8U
#define SCI1_S1_IDLE_MASK               16U
#define SCI1_S1_RDRF_MASK               32U
#define SCI1_S1_TC_MASK                 64U
#define SCI1_S1_TDRE_MASK               128U


/*** SCI1_S2 - SCI Status Register 2; 0x0000308D ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI1_S2STR;
extern volatile SCI1_S2STR _SCI1_S2 @0x0000308D;
#define SCI1_S2                         _SCI1_S2.Byte
#define SCI1_S2_RAF                     _SCI1_S2.Bits.RAF
#define SCI1_S2_LBKDE                   _SCI1_S2.Bits.LBKDE
#define SCI1_S2_BRK13                   _SCI1_S2.Bits.BRK13
#define SCI1_S2_RWUID                   _SCI1_S2.Bits.RWUID
#define SCI1_S2_RXINV                   _SCI1_S2.Bits.RXINV
#define SCI1_S2_RXEDGIF                 _SCI1_S2.Bits.RXEDGIF
#define SCI1_S2_LBKDIF                  _SCI1_S2.Bits.LBKDIF

#define SCI1_S2_RAF_MASK                1U
#define SCI1_S2_LBKDE_MASK              2U
#define SCI1_S2_BRK13_MASK              4U
#define SCI1_S2_RWUID_MASK              8U
#define SCI1_S2_RXINV_MASK              16U
#define SCI1_S2_RXEDGIF_MASK            64U
#define SCI1_S2_LBKDIF_MASK             128U


/*** SCI1_C3 - SCI Control Register 3; 0x0000308E ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI1_C3STR;
extern volatile SCI1_C3STR _SCI1_C3 @0x0000308E;
#define SCI1_C3                         _SCI1_C3.Byte
#define SCI1_C3_PEIE                    _SCI1_C3.Bits.PEIE
#define SCI1_C3_FEIE                    _SCI1_C3.Bits.FEIE
#define SCI1_C3_NEIE                    _SCI1_C3.Bits.NEIE
#define SCI1_C3_ORIE                    _SCI1_C3.Bits.ORIE
#define SCI1_C3_TXINV                   _SCI1_C3.Bits.TXINV
#define SCI1_C3_TXDIR                   _SCI1_C3.Bits.TXDIR
#define SCI1_C3_T8                      _SCI1_C3.Bits.T8
#define SCI1_C3_R8                      _SCI1_C3.Bits.R8

#define SCI1_C3_PEIE_MASK               1U
#define SCI1_C3_FEIE_MASK               2U
#define SCI1_C3_NEIE_MASK               4U
#define SCI1_C3_ORIE_MASK               8U
#define SCI1_C3_TXINV_MASK              16U
#define SCI1_C3_TXDIR_MASK              32U
#define SCI1_C3_T8_MASK                 64U
#define SCI1_C3_R8_MASK                 128U


/*** SCI1_D - SCI Data Register; 0x0000308F ***/
typedef union {
  byte Byte;
  struct {
    byte R0T0        :1;                                       /* Read receive data buffer 0 or write transmit data buffer 0 */
    byte R1T1        :1;                                       /* Read receive data buffer 1 or write transmit data buffer 1 */
    byte R2T2        :1;                                       /* Read receive data buffer 2 or write transmit data buffer 2 */
    byte R3T3        :1;                                       /* Read receive data buffer 3 or write transmit data buffer 3 */
    byte R4T4        :1;                                       /* Read receive data buffer 4 or write transmit data buffer 4 */
    byte R5T5        :1;                                       /* Read receive data buffer 5 or write transmit data buffer 5 */
    byte R6T6        :1;                                       /* Read receive data buffer 6 or write transmit data buffer 6 */
    byte R7T7        :1;                                       /* Read receive data buffer 7 or write transmit data buffer 7 */
  } Bits;
} SCI1_DSTR;
extern volatile SCI1_DSTR _SCI1_D @0x0000308F;
#define SCI1_D                          _SCI1_D.Byte
#define SCI1_D_R0T0                     _SCI1_D.Bits.R0T0
#define SCI1_D_R1T1                     _SCI1_D.Bits.R1T1
#define SCI1_D_R2T2                     _SCI1_D.Bits.R2T2
#define SCI1_D_R3T3                     _SCI1_D.Bits.R3T3
#define SCI1_D_R4T4                     _SCI1_D.Bits.R4T4
#define SCI1_D_R5T5                     _SCI1_D.Bits.R5T5
#define SCI1_D_R6T6                     _SCI1_D.Bits.R6T6
#define SCI1_D_R7T7                     _SCI1_D.Bits.R7T7

#define SCI1_D_R0T0_MASK                1U
#define SCI1_D_R1T1_MASK                2U
#define SCI1_D_R2T2_MASK                4U
#define SCI1_D_R3T3_MASK                8U
#define SCI1_D_R4T4_MASK                16U
#define SCI1_D_R5T5_MASK                32U
#define SCI1_D_R6T6_MASK                64U
#define SCI1_D_R7T7_MASK                128U


/*** SCI2_BD - SCI2 Baud Rate Register; 0x00003090 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI2_BDH - SCI Baud Rate Register: High; 0x00003090 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor, bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor, bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor, bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor, bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor, bit 4 */
        byte SBNS        :1;                                       /* Stop Bit Number Select */
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI2_BDHSTR;
    #define SCI2_BDH                    _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Byte
    #define SCI2_BDH_SBR0               _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Bits.SBR0
    #define SCI2_BDH_SBR1               _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Bits.SBR1
    #define SCI2_BDH_SBR2               _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Bits.SBR2
    #define SCI2_BDH_SBR3               _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Bits.SBR3
    #define SCI2_BDH_SBR4               _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Bits.SBR4
    #define SCI2_BDH_SBNS               _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Bits.SBNS
    #define SCI2_BDH_RXEDGIE            _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Bits.RXEDGIE
    #define SCI2_BDH_LBKDIE             _SCI2_BD.Overlap_STR.SCI2_BDHSTR.Bits.LBKDIE
    #define SCI2_BDH_SBR                _SCI2_BD.Overlap_STR.SCI2_BDHSTR.MergedBits.grpSBR
    
    #define SCI2_BDH_SBR0_MASK          1U
    #define SCI2_BDH_SBR1_MASK          2U
    #define SCI2_BDH_SBR2_MASK          4U
    #define SCI2_BDH_SBR3_MASK          8U
    #define SCI2_BDH_SBR4_MASK          16U
    #define SCI2_BDH_SBNS_MASK          32U
    #define SCI2_BDH_RXEDGIE_MASK       64U
    #define SCI2_BDH_LBKDIE_MASK        128U
    #define SCI2_BDH_SBR_MASK           31U
    #define SCI2_BDH_SBR_BITNUM         0U
    

    /*** SCI2_BDL - SCI Baud Rate Register: Low; 0x00003091 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor, bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor, bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor, bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor, bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor, bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor, bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor, bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor, bit 7 */
      } Bits;
    } SCI2_BDLSTR;
    #define SCI2_BDL                    _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Byte
    #define SCI2_BDL_SBR0               _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Bits.SBR0
    #define SCI2_BDL_SBR1               _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Bits.SBR1
    #define SCI2_BDL_SBR2               _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Bits.SBR2
    #define SCI2_BDL_SBR3               _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Bits.SBR3
    #define SCI2_BDL_SBR4               _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Bits.SBR4
    #define SCI2_BDL_SBR5               _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Bits.SBR5
    #define SCI2_BDL_SBR6               _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Bits.SBR6
    #define SCI2_BDL_SBR7               _SCI2_BD.Overlap_STR.SCI2_BDLSTR.Bits.SBR7
    
    #define SCI2_BDL_SBR0_MASK          1U
    #define SCI2_BDL_SBR1_MASK          2U
    #define SCI2_BDL_SBR2_MASK          4U
    #define SCI2_BDL_SBR3_MASK          8U
    #define SCI2_BDL_SBR4_MASK          16U
    #define SCI2_BDL_SBR5_MASK          32U
    #define SCI2_BDL_SBR6_MASK          64U
    #define SCI2_BDL_SBR7_MASK          128U
    
  } Overlap_STR;

} SCI2_BDSTR;
extern volatile SCI2_BDSTR _SCI2_BD @0x00003090;
#define SCI2_BD                         _SCI2_BD.Word


/*** SCI2_C1 - SCI Control Register 1; 0x00003092 ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCI2_C1STR;
extern volatile SCI2_C1STR _SCI2_C1 @0x00003092;
#define SCI2_C1                         _SCI2_C1.Byte
#define SCI2_C1_PT                      _SCI2_C1.Bits.PT
#define SCI2_C1_PE                      _SCI2_C1.Bits.PE
#define SCI2_C1_ILT                     _SCI2_C1.Bits.ILT
#define SCI2_C1_WAKE                    _SCI2_C1.Bits.WAKE
#define SCI2_C1_M                       _SCI2_C1.Bits.M
#define SCI2_C1_RSRC                    _SCI2_C1.Bits.RSRC
#define SCI2_C1_SCISWAI                 _SCI2_C1.Bits.SCISWAI
#define SCI2_C1_LOOPS                   _SCI2_C1.Bits.LOOPS

#define SCI2_C1_PT_MASK                 1U
#define SCI2_C1_PE_MASK                 2U
#define SCI2_C1_ILT_MASK                4U
#define SCI2_C1_WAKE_MASK               8U
#define SCI2_C1_M_MASK                  16U
#define SCI2_C1_RSRC_MASK               32U
#define SCI2_C1_SCISWAI_MASK            64U
#define SCI2_C1_LOOPS_MASK              128U


/*** SCI2_C2 - SCI Control Register 2; 0x00003093 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable for IDLE */
    byte RIE         :1;                                       /* Receiver Interrupt Enable for RDRF */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable for TC */
    byte TIE         :1;                                       /* Transmit Interrupt Enable for TDRE */
  } Bits;
} SCI2_C2STR;
extern volatile SCI2_C2STR _SCI2_C2 @0x00003093;
#define SCI2_C2                         _SCI2_C2.Byte
#define SCI2_C2_SBK                     _SCI2_C2.Bits.SBK
#define SCI2_C2_RWU                     _SCI2_C2.Bits.RWU
#define SCI2_C2_RE                      _SCI2_C2.Bits.RE
#define SCI2_C2_TE                      _SCI2_C2.Bits.TE
#define SCI2_C2_ILIE                    _SCI2_C2.Bits.ILIE
#define SCI2_C2_RIE                     _SCI2_C2.Bits.RIE
#define SCI2_C2_TCIE                    _SCI2_C2.Bits.TCIE
#define SCI2_C2_TIE                     _SCI2_C2.Bits.TIE

#define SCI2_C2_SBK_MASK                1U
#define SCI2_C2_RWU_MASK                2U
#define SCI2_C2_RE_MASK                 4U
#define SCI2_C2_TE_MASK                 8U
#define SCI2_C2_ILIE_MASK               16U
#define SCI2_C2_RIE_MASK                32U
#define SCI2_C2_TCIE_MASK               64U
#define SCI2_C2_TIE_MASK                128U


/*** SCI2_S1 - SCI Status Register 1; 0x00003094 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI2_S1STR;
extern volatile SCI2_S1STR _SCI2_S1 @0x00003094;
#define SCI2_S1                         _SCI2_S1.Byte
#define SCI2_S1_PF                      _SCI2_S1.Bits.PF
#define SCI2_S1_FE                      _SCI2_S1.Bits.FE
#define SCI2_S1_NF                      _SCI2_S1.Bits.NF
#define SCI2_S1_OR                      _SCI2_S1.Bits.OR
#define SCI2_S1_IDLE                    _SCI2_S1.Bits.IDLE
#define SCI2_S1_RDRF                    _SCI2_S1.Bits.RDRF
#define SCI2_S1_TC                      _SCI2_S1.Bits.TC
#define SCI2_S1_TDRE                    _SCI2_S1.Bits.TDRE

#define SCI2_S1_PF_MASK                 1U
#define SCI2_S1_FE_MASK                 2U
#define SCI2_S1_NF_MASK                 4U
#define SCI2_S1_OR_MASK                 8U
#define SCI2_S1_IDLE_MASK               16U
#define SCI2_S1_RDRF_MASK               32U
#define SCI2_S1_TC_MASK                 64U
#define SCI2_S1_TDRE_MASK               128U


/*** SCI2_S2 - SCI Status Register 2; 0x00003095 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCI2_S2STR;
extern volatile SCI2_S2STR _SCI2_S2 @0x00003095;
#define SCI2_S2                         _SCI2_S2.Byte
#define SCI2_S2_RAF                     _SCI2_S2.Bits.RAF
#define SCI2_S2_LBKDE                   _SCI2_S2.Bits.LBKDE
#define SCI2_S2_BRK13                   _SCI2_S2.Bits.BRK13
#define SCI2_S2_RWUID                   _SCI2_S2.Bits.RWUID
#define SCI2_S2_RXINV                   _SCI2_S2.Bits.RXINV
#define SCI2_S2_RXEDGIF                 _SCI2_S2.Bits.RXEDGIF
#define SCI2_S2_LBKDIF                  _SCI2_S2.Bits.LBKDIF

#define SCI2_S2_RAF_MASK                1U
#define SCI2_S2_LBKDE_MASK              2U
#define SCI2_S2_BRK13_MASK              4U
#define SCI2_S2_RWUID_MASK              8U
#define SCI2_S2_RXINV_MASK              16U
#define SCI2_S2_RXEDGIF_MASK            64U
#define SCI2_S2_LBKDIF_MASK             128U


/*** SCI2_C3 - SCI Control Register 3; 0x00003096 ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCI2_C3STR;
extern volatile SCI2_C3STR _SCI2_C3 @0x00003096;
#define SCI2_C3                         _SCI2_C3.Byte
#define SCI2_C3_PEIE                    _SCI2_C3.Bits.PEIE
#define SCI2_C3_FEIE                    _SCI2_C3.Bits.FEIE
#define SCI2_C3_NEIE                    _SCI2_C3.Bits.NEIE
#define SCI2_C3_ORIE                    _SCI2_C3.Bits.ORIE
#define SCI2_C3_TXINV                   _SCI2_C3.Bits.TXINV
#define SCI2_C3_TXDIR                   _SCI2_C3.Bits.TXDIR
#define SCI2_C3_T8                      _SCI2_C3.Bits.T8
#define SCI2_C3_R8                      _SCI2_C3.Bits.R8

#define SCI2_C3_PEIE_MASK               1U
#define SCI2_C3_FEIE_MASK               2U
#define SCI2_C3_NEIE_MASK               4U
#define SCI2_C3_ORIE_MASK               8U
#define SCI2_C3_TXINV_MASK              16U
#define SCI2_C3_TXDIR_MASK              32U
#define SCI2_C3_T8_MASK                 64U
#define SCI2_C3_R8_MASK                 128U


/*** SCI2_D - SCI Data Register; 0x00003097 ***/
typedef union {
  byte Byte;
  struct {
    byte R0T0        :1;                                       /* Read receive data buffer 0 or write transmit data buffer 0 */
    byte R1T1        :1;                                       /* Read receive data buffer 1 or write transmit data buffer 1 */
    byte R2T2        :1;                                       /* Read receive data buffer 2 or write transmit data buffer 2 */
    byte R3T3        :1;                                       /* Read receive data buffer 3 or write transmit data buffer 3 */
    byte R4T4        :1;                                       /* Read receive data buffer 4 or write transmit data buffer 4 */
    byte R5T5        :1;                                       /* Read receive data buffer 5 or write transmit data buffer 5 */
    byte R6T6        :1;                                       /* Read receive data buffer 6 or write transmit data buffer 6 */
    byte R7T7        :1;                                       /* Read receive data buffer 7 or write transmit data buffer 7 */
  } Bits;
} SCI2_DSTR;
extern volatile SCI2_DSTR _SCI2_D @0x00003097;
#define SCI2_D                          _SCI2_D.Byte
#define SCI2_D_R0T0                     _SCI2_D.Bits.R0T0
#define SCI2_D_R1T1                     _SCI2_D.Bits.R1T1
#define SCI2_D_R2T2                     _SCI2_D.Bits.R2T2
#define SCI2_D_R3T3                     _SCI2_D.Bits.R3T3
#define SCI2_D_R4T4                     _SCI2_D.Bits.R4T4
#define SCI2_D_R5T5                     _SCI2_D.Bits.R5T5
#define SCI2_D_R6T6                     _SCI2_D.Bits.R6T6
#define SCI2_D_R7T7                     _SCI2_D.Bits.R7T7

#define SCI2_D_R0T0_MASK                1U
#define SCI2_D_R1T1_MASK                2U
#define SCI2_D_R2T2_MASK                4U
#define SCI2_D_R3T3_MASK                8U
#define SCI2_D_R4T4_MASK                16U
#define SCI2_D_R5T5_MASK                32U
#define SCI2_D_R6T6_MASK                64U
#define SCI2_D_R7T7_MASK                128U


/*** SPI0_C1 - SPI control register 1; 0x00003098 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB first (shifter direction) */
    byte SSOE        :1;                                       /* Slave select output enable */
    byte CPHA        :1;                                       /* Clock phase */
    byte CPOL        :1;                                       /* Clock polarity */
    byte MSTR        :1;                                       /* Master/slave mode select */
    byte SPTIE       :1;                                       /* SPI transmit interrupt enable */
    byte SPE         :1;                                       /* SPI system enable */
    byte SPIE        :1;                                       /* SPI interrupt enable: for SPRF and MODF (when FIFO is not supported or not enabled) or for read FIFO (when FIFO is supported and enabled) */
  } Bits;
} SPI0_C1STR;
extern volatile SPI0_C1STR _SPI0_C1 @0x00003098;
#define SPI0_C1                         _SPI0_C1.Byte
#define SPI0_C1_LSBFE                   _SPI0_C1.Bits.LSBFE
#define SPI0_C1_SSOE                    _SPI0_C1.Bits.SSOE
#define SPI0_C1_CPHA                    _SPI0_C1.Bits.CPHA
#define SPI0_C1_CPOL                    _SPI0_C1.Bits.CPOL
#define SPI0_C1_MSTR                    _SPI0_C1.Bits.MSTR
#define SPI0_C1_SPTIE                   _SPI0_C1.Bits.SPTIE
#define SPI0_C1_SPE                     _SPI0_C1.Bits.SPE
#define SPI0_C1_SPIE                    _SPI0_C1.Bits.SPIE

#define SPI0_C1_LSBFE_MASK              1U
#define SPI0_C1_SSOE_MASK               2U
#define SPI0_C1_CPHA_MASK               4U
#define SPI0_C1_CPOL_MASK               8U
#define SPI0_C1_MSTR_MASK               16U
#define SPI0_C1_SPTIE_MASK              32U
#define SPI0_C1_SPE_MASK                64U
#define SPI0_C1_SPIE_MASK               128U


/*** SPI0_C2 - SPI control register 2; 0x00003099 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI pin control 0 */
    byte SPISWAI     :1;                                       /* SPI stop in wait mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional mode output enable */
    byte MODFEN      :1;                                       /* Master mode-fault function enable */
    byte             :1; 
    byte             :1; 
    byte SPMIE       :1;                                       /* SPI match interrupt enable */
  } Bits;
} SPI0_C2STR;
extern volatile SPI0_C2STR _SPI0_C2 @0x00003099;
#define SPI0_C2                         _SPI0_C2.Byte
#define SPI0_C2_SPC0                    _SPI0_C2.Bits.SPC0
#define SPI0_C2_SPISWAI                 _SPI0_C2.Bits.SPISWAI
#define SPI0_C2_BIDIROE                 _SPI0_C2.Bits.BIDIROE
#define SPI0_C2_MODFEN                  _SPI0_C2.Bits.MODFEN
#define SPI0_C2_SPMIE                   _SPI0_C2.Bits.SPMIE

#define SPI0_C2_SPC0_MASK               1U
#define SPI0_C2_SPISWAI_MASK            2U
#define SPI0_C2_BIDIROE_MASK            8U
#define SPI0_C2_MODFEN_MASK             16U
#define SPI0_C2_SPMIE_MASK              128U


/*** SPI0_BR - SPI baud rate register; 0x0000309A ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI baud rate divisor, bit 0 */
    byte SPR1        :1;                                       /* SPI baud rate divisor, bit 1 */
    byte SPR2        :1;                                       /* SPI baud rate divisor, bit 2 */
    byte SPR3        :1;                                       /* SPI baud rate divisor, bit 3 */
    byte SPPR0       :1;                                       /* SPI baud rate prescale divisor, bit 0 */
    byte SPPR1       :1;                                       /* SPI baud rate prescale divisor, bit 1 */
    byte SPPR2       :1;                                       /* SPI baud rate prescale divisor, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :4;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI0_BRSTR;
extern volatile SPI0_BRSTR _SPI0_BR @0x0000309A;
#define SPI0_BR                         _SPI0_BR.Byte
#define SPI0_BR_SPR0                    _SPI0_BR.Bits.SPR0
#define SPI0_BR_SPR1                    _SPI0_BR.Bits.SPR1
#define SPI0_BR_SPR2                    _SPI0_BR.Bits.SPR2
#define SPI0_BR_SPR3                    _SPI0_BR.Bits.SPR3
#define SPI0_BR_SPPR0                   _SPI0_BR.Bits.SPPR0
#define SPI0_BR_SPPR1                   _SPI0_BR.Bits.SPPR1
#define SPI0_BR_SPPR2                   _SPI0_BR.Bits.SPPR2
#define SPI0_BR_SPR                     _SPI0_BR.MergedBits.grpSPR
#define SPI0_BR_SPPR                    _SPI0_BR.MergedBits.grpSPPR

#define SPI0_BR_SPR0_MASK               1U
#define SPI0_BR_SPR1_MASK               2U
#define SPI0_BR_SPR2_MASK               4U
#define SPI0_BR_SPR3_MASK               8U
#define SPI0_BR_SPPR0_MASK              16U
#define SPI0_BR_SPPR1_MASK              32U
#define SPI0_BR_SPPR2_MASK              64U
#define SPI0_BR_SPR_MASK                15U
#define SPI0_BR_SPR_BITNUM              0U
#define SPI0_BR_SPPR_MASK               112U
#define SPI0_BR_SPPR_BITNUM             4U


/*** SPI0_S - SPI status register; 0x0000309B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master mode fault flag */
    byte SPTEF       :1;                                       /* SPI transmit buffer empty flag (when FIFO is not supported or not enabled) or SPI transmit FIFO empty flag (when FIFO is supported and enabled) */
    byte SPMF        :1;                                       /* SPI match flag */
    byte SPRF        :1;                                       /* SPI read buffer full flag (when FIFO is not supported or not enabled) or SPI read FIFO FULL flag (when FIFO is supported and enabled) */
  } Bits;
} SPI0_SSTR;
extern volatile SPI0_SSTR _SPI0_S @0x0000309B;
#define SPI0_S                          _SPI0_S.Byte
#define SPI0_S_MODF                     _SPI0_S.Bits.MODF
#define SPI0_S_SPTEF                    _SPI0_S.Bits.SPTEF
#define SPI0_S_SPMF                     _SPI0_S.Bits.SPMF
#define SPI0_S_SPRF                     _SPI0_S.Bits.SPRF

#define SPI0_S_MODF_MASK                16U
#define SPI0_S_SPTEF_MASK               32U
#define SPI0_S_SPMF_MASK                64U
#define SPI0_S_SPRF_MASK                128U


/*** SPI0_D - SPI data register low; 0x0000309D ***/
typedef union {
  byte Byte;
} SPI0_DSTR;
extern volatile SPI0_DSTR _SPI0_D @0x0000309D;
#define SPI0_D                          _SPI0_D.Byte


/*** SPI0_M - SPI match register low; 0x0000309F ***/
typedef union {
  byte Byte;
} SPI0_MSTR;
extern volatile SPI0_MSTR _SPI0_M @0x0000309F;
#define SPI0_M                          _SPI0_M.Byte


/*** SPI1_C1 - SPI control register 1; 0x000030A0 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB first (shifter direction) */
    byte SSOE        :1;                                       /* Slave select output enable */
    byte CPHA        :1;                                       /* Clock phase */
    byte CPOL        :1;                                       /* Clock polarity */
    byte MSTR        :1;                                       /* Master/slave mode select */
    byte SPTIE       :1;                                       /* SPI transmit interrupt enable */
    byte SPE         :1;                                       /* SPI system enable */
    byte SPIE        :1;                                       /* SPI interrupt enable: for SPRF and MODF (when FIFO is not supported or not enabled) or for read FIFO (when FIFO is supported and enabled) */
  } Bits;
} SPI1_C1STR;
extern volatile SPI1_C1STR _SPI1_C1 @0x000030A0;
#define SPI1_C1                         _SPI1_C1.Byte
#define SPI1_C1_LSBFE                   _SPI1_C1.Bits.LSBFE
#define SPI1_C1_SSOE                    _SPI1_C1.Bits.SSOE
#define SPI1_C1_CPHA                    _SPI1_C1.Bits.CPHA
#define SPI1_C1_CPOL                    _SPI1_C1.Bits.CPOL
#define SPI1_C1_MSTR                    _SPI1_C1.Bits.MSTR
#define SPI1_C1_SPTIE                   _SPI1_C1.Bits.SPTIE
#define SPI1_C1_SPE                     _SPI1_C1.Bits.SPE
#define SPI1_C1_SPIE                    _SPI1_C1.Bits.SPIE

#define SPI1_C1_LSBFE_MASK              1U
#define SPI1_C1_SSOE_MASK               2U
#define SPI1_C1_CPHA_MASK               4U
#define SPI1_C1_CPOL_MASK               8U
#define SPI1_C1_MSTR_MASK               16U
#define SPI1_C1_SPTIE_MASK              32U
#define SPI1_C1_SPE_MASK                64U
#define SPI1_C1_SPIE_MASK               128U


/*** SPI1_C2 - SPI control register 2; 0x000030A1 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI pin control 0 */
    byte SPISWAI     :1;                                       /* SPI stop in wait mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional mode output enable */
    byte MODFEN      :1;                                       /* Master mode-fault function enable */
    byte             :1; 
    byte SPIMODE     :1;                                       /* SPI 8-bit or 16-bit mode */
    byte SPMIE       :1;                                       /* SPI match interrupt enable */
  } Bits;
} SPI1_C2STR;
extern volatile SPI1_C2STR _SPI1_C2 @0x000030A1;
#define SPI1_C2                         _SPI1_C2.Byte
#define SPI1_C2_SPC0                    _SPI1_C2.Bits.SPC0
#define SPI1_C2_SPISWAI                 _SPI1_C2.Bits.SPISWAI
#define SPI1_C2_BIDIROE                 _SPI1_C2.Bits.BIDIROE
#define SPI1_C2_MODFEN                  _SPI1_C2.Bits.MODFEN
#define SPI1_C2_SPIMODE                 _SPI1_C2.Bits.SPIMODE
#define SPI1_C2_SPMIE                   _SPI1_C2.Bits.SPMIE

#define SPI1_C2_SPC0_MASK               1U
#define SPI1_C2_SPISWAI_MASK            2U
#define SPI1_C2_BIDIROE_MASK            8U
#define SPI1_C2_MODFEN_MASK             16U
#define SPI1_C2_SPIMODE_MASK            64U
#define SPI1_C2_SPMIE_MASK              128U


/*** SPI1_BR - SPI baud rate register; 0x000030A2 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI baud rate divisor, bit 0 */
    byte SPR1        :1;                                       /* SPI baud rate divisor, bit 1 */
    byte SPR2        :1;                                       /* SPI baud rate divisor, bit 2 */
    byte SPR3        :1;                                       /* SPI baud rate divisor, bit 3 */
    byte SPPR0       :1;                                       /* SPI baud rate prescale divisor, bit 0 */
    byte SPPR1       :1;                                       /* SPI baud rate prescale divisor, bit 1 */
    byte SPPR2       :1;                                       /* SPI baud rate prescale divisor, bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :4;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI1_BRSTR;
extern volatile SPI1_BRSTR _SPI1_BR @0x000030A2;
#define SPI1_BR                         _SPI1_BR.Byte
#define SPI1_BR_SPR0                    _SPI1_BR.Bits.SPR0
#define SPI1_BR_SPR1                    _SPI1_BR.Bits.SPR1
#define SPI1_BR_SPR2                    _SPI1_BR.Bits.SPR2
#define SPI1_BR_SPR3                    _SPI1_BR.Bits.SPR3
#define SPI1_BR_SPPR0                   _SPI1_BR.Bits.SPPR0
#define SPI1_BR_SPPR1                   _SPI1_BR.Bits.SPPR1
#define SPI1_BR_SPPR2                   _SPI1_BR.Bits.SPPR2
#define SPI1_BR_SPR                     _SPI1_BR.MergedBits.grpSPR
#define SPI1_BR_SPPR                    _SPI1_BR.MergedBits.grpSPPR

#define SPI1_BR_SPR0_MASK               1U
#define SPI1_BR_SPR1_MASK               2U
#define SPI1_BR_SPR2_MASK               4U
#define SPI1_BR_SPR3_MASK               8U
#define SPI1_BR_SPPR0_MASK              16U
#define SPI1_BR_SPPR1_MASK              32U
#define SPI1_BR_SPPR2_MASK              64U
#define SPI1_BR_SPR_MASK                15U
#define SPI1_BR_SPR_BITNUM              0U
#define SPI1_BR_SPPR_MASK               112U
#define SPI1_BR_SPPR_BITNUM             4U


/*** SPI1_S - SPI status register; 0x000030A3 ***/
typedef union {
  byte Byte;
  struct {
    byte RFIFOEF     :1;                                       /* SPI read FIFO empty flag */
    byte TXFULLF     :1;                                       /* Transmit FIFO full flag */
    byte TNEAREF     :1;                                       /* Transmit FIFO nearly empty flag */
    byte RNFULLF     :1;                                       /* Receive FIFO nearly full flag */
    byte MODF        :1;                                       /* Master mode fault flag */
    byte SPTEF       :1;                                       /* SPI transmit buffer empty flag (when FIFO is not supported or not enabled) or SPI transmit FIFO empty flag (when FIFO is supported and enabled) */
    byte SPMF        :1;                                       /* SPI match flag */
    byte SPRF        :1;                                       /* SPI read buffer full flag (when FIFO is not supported or not enabled) or SPI read FIFO FULL flag (when FIFO is supported and enabled) */
  } Bits;
} SPI1_SSTR;
extern volatile SPI1_SSTR _SPI1_S @0x000030A3;
#define SPI1_S                          _SPI1_S.Byte
#define SPI1_S_RFIFOEF                  _SPI1_S.Bits.RFIFOEF
#define SPI1_S_TXFULLF                  _SPI1_S.Bits.TXFULLF
#define SPI1_S_TNEAREF                  _SPI1_S.Bits.TNEAREF
#define SPI1_S_RNFULLF                  _SPI1_S.Bits.RNFULLF
#define SPI1_S_MODF                     _SPI1_S.Bits.MODF
#define SPI1_S_SPTEF                    _SPI1_S.Bits.SPTEF
#define SPI1_S_SPMF                     _SPI1_S.Bits.SPMF
#define SPI1_S_SPRF                     _SPI1_S.Bits.SPRF

#define SPI1_S_RFIFOEF_MASK             1U
#define SPI1_S_TXFULLF_MASK             2U
#define SPI1_S_TNEAREF_MASK             4U
#define SPI1_S_RNFULLF_MASK             8U
#define SPI1_S_MODF_MASK                16U
#define SPI1_S_SPTEF_MASK               32U
#define SPI1_S_SPMF_MASK                64U
#define SPI1_S_SPRF_MASK                128U


/*** SPI1_D16 - SPI1 Data Register; 0x000030A4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI1_DH - SPI data register high; 0x000030A4 ***/
    union {
      byte Byte;
    } SPI1_DHSTR;
    #define SPI1_DH                     _SPI1_D16.Overlap_STR.SPI1_DHSTR.Byte
    

    /*** SPI1_DL - SPI data register low; 0x000030A5 ***/
    union {
      byte Byte;
    } SPI1_DLSTR;
    #define SPI1_DL                     _SPI1_D16.Overlap_STR.SPI1_DLSTR.Byte
    
  } Overlap_STR;

} SPI1_D16STR;
extern volatile SPI1_D16STR _SPI1_D16 @0x000030A4;
#define SPI1_D16                        _SPI1_D16.Word


/*** SPI1_M - SPI1 Match Register; 0x000030A6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI1_MH - SPI match register high; 0x000030A6 ***/
    union {
      byte Byte;
    } SPI1_MHSTR;
    #define SPI1_MH                     _SPI1_M.Overlap_STR.SPI1_MHSTR.Byte
    

    /*** SPI1_ML - SPI match register low; 0x000030A7 ***/
    union {
      byte Byte;
    } SPI1_MLSTR;
    #define SPI1_ML                     _SPI1_M.Overlap_STR.SPI1_MLSTR.Byte
    
  } Overlap_STR;

} SPI1_MSTR;
extern volatile SPI1_MSTR _SPI1_M @0x000030A6;
#define SPI1_M                          _SPI1_M.Word


/*** SPI1_C3 - SPI control register 3; 0x000030A8 ***/
typedef union {
  byte Byte;
  struct {
    byte FIFOMODE    :1;                                       /* FIFO mode enable */
    byte RNFULLIEN   :1;                                       /* Receive FIFO nearly full interrupt enable */
    byte TNEARIEN    :1;                                       /* Transmit FIFO nearly empty interrupt enable */
    byte INTCLR      :1;                                       /* Interrupt clearing mechanism select */
    byte RNFULLF_MARK :1;                                      /* Receive FIFO nearly full watermark */
    byte TNEAREF_MARK :1;                                      /* Transmit FIFO nearly empty watermark */
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI1_C3STR;
extern volatile SPI1_C3STR _SPI1_C3 @0x000030A8;
#define SPI1_C3                         _SPI1_C3.Byte
#define SPI1_C3_FIFOMODE                _SPI1_C3.Bits.FIFOMODE
#define SPI1_C3_RNFULLIEN               _SPI1_C3.Bits.RNFULLIEN
#define SPI1_C3_TNEARIEN                _SPI1_C3.Bits.TNEARIEN
#define SPI1_C3_INTCLR                  _SPI1_C3.Bits.INTCLR
#define SPI1_C3_RNFULLF_MARK            _SPI1_C3.Bits.RNFULLF_MARK
#define SPI1_C3_TNEAREF_MARK            _SPI1_C3.Bits.TNEAREF_MARK

#define SPI1_C3_FIFOMODE_MASK           1U
#define SPI1_C3_RNFULLIEN_MASK          2U
#define SPI1_C3_TNEARIEN_MASK           4U
#define SPI1_C3_INTCLR_MASK             8U
#define SPI1_C3_RNFULLF_MARK_MASK       16U
#define SPI1_C3_TNEAREF_MARK_MASK       32U


/*** SPI1_CI - SPI clear interrupt register; 0x000030A9 ***/
typedef union {
  byte Byte;
  struct {
    byte SPRFCI      :1;                                       /* Receive FIFO full flag clear interrupt */
    byte SPTEFCI     :1;                                       /* Transmit FIFO empty flag clear interrupt */
    byte RNFULLFCI   :1;                                       /* Receive FIFO nearly full flag clear interrupt */
    byte TNEAREFCI   :1;                                       /* Transmit FIFO nearly empty flag clear interrupt */
    byte RXFOF       :1;                                       /* Receive FIFO overflow flag */
    byte TXFOF       :1;                                       /* Transmit FIFO overflow flag */
    byte RXFERR      :1;                                       /* Receive FIFO error flag */
    byte TXFERR      :1;                                       /* Transmit FIFO error flag */
  } Bits;
} SPI1_CISTR;
extern volatile SPI1_CISTR _SPI1_CI @0x000030A9;
#define SPI1_CI                         _SPI1_CI.Byte
#define SPI1_CI_SPRFCI                  _SPI1_CI.Bits.SPRFCI
#define SPI1_CI_SPTEFCI                 _SPI1_CI.Bits.SPTEFCI
#define SPI1_CI_RNFULLFCI               _SPI1_CI.Bits.RNFULLFCI
#define SPI1_CI_TNEAREFCI               _SPI1_CI.Bits.TNEAREFCI
#define SPI1_CI_RXFOF                   _SPI1_CI.Bits.RXFOF
#define SPI1_CI_TXFOF                   _SPI1_CI.Bits.TXFOF
#define SPI1_CI_RXFERR                  _SPI1_CI.Bits.RXFERR
#define SPI1_CI_TXFERR                  _SPI1_CI.Bits.TXFERR

#define SPI1_CI_SPRFCI_MASK             1U
#define SPI1_CI_SPTEFCI_MASK            2U
#define SPI1_CI_RNFULLFCI_MASK          4U
#define SPI1_CI_TNEAREFCI_MASK          8U
#define SPI1_CI_RXFOF_MASK              16U
#define SPI1_CI_TXFOF_MASK              32U
#define SPI1_CI_RXFERR_MASK             64U
#define SPI1_CI_TXFERR_MASK             128U


/*** ADC_APCTL1 - Pin Control 1 Register; 0x000030AC ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       /* ADC Pin Control 0 */
    byte ADPC1       :1;                                       /* ADC Pin Control 1 */
    byte ADPC2       :1;                                       /* ADC Pin Control 2 */
    byte ADPC3       :1;                                       /* ADC Pin Control 3 */
    byte ADPC4       :1;                                       /* ADC Pin Control 4 */
    byte ADPC5       :1;                                       /* ADC Pin Control 5 */
    byte ADPC6       :1;                                       /* ADC Pin Control 6 */
    byte ADPC7       :1;                                       /* ADC Pin Control 7 */
  } Bits;
} ADC_APCTL1STR;
extern volatile ADC_APCTL1STR _ADC_APCTL1 @0x000030AC;
#define ADC_APCTL1                      _ADC_APCTL1.Byte
#define ADC_APCTL1_ADPC0                _ADC_APCTL1.Bits.ADPC0
#define ADC_APCTL1_ADPC1                _ADC_APCTL1.Bits.ADPC1
#define ADC_APCTL1_ADPC2                _ADC_APCTL1.Bits.ADPC2
#define ADC_APCTL1_ADPC3                _ADC_APCTL1.Bits.ADPC3
#define ADC_APCTL1_ADPC4                _ADC_APCTL1.Bits.ADPC4
#define ADC_APCTL1_ADPC5                _ADC_APCTL1.Bits.ADPC5
#define ADC_APCTL1_ADPC6                _ADC_APCTL1.Bits.ADPC6
#define ADC_APCTL1_ADPC7                _ADC_APCTL1.Bits.ADPC7

#define ADC_APCTL1_ADPC0_MASK           1U
#define ADC_APCTL1_ADPC1_MASK           2U
#define ADC_APCTL1_ADPC2_MASK           4U
#define ADC_APCTL1_ADPC3_MASK           8U
#define ADC_APCTL1_ADPC4_MASK           16U
#define ADC_APCTL1_ADPC5_MASK           32U
#define ADC_APCTL1_ADPC6_MASK           64U
#define ADC_APCTL1_ADPC7_MASK           128U


/*** ADC_APCTL2 - Pin Control 2 Register; 0x000030AD ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC8       :1;                                       /* ADC Pin Control 8 */
    byte ADPC9       :1;                                       /* ADC Pin Control 9 */
    byte ADPC10      :1;                                       /* ADC Pin Control 10 */
    byte ADPC11      :1;                                       /* ADC Pin Control 11 */
    byte ADPC12      :1;                                       /* ADC Pin Control 12 */
    byte ADPC13      :1;                                       /* ADC Pin Control 13 */
    byte ADPC14      :1;                                       /* ADC Pin Control 14 */
    byte ADPC15      :1;                                       /* ADC Pin Control 15 */
  } Bits;
} ADC_APCTL2STR;
extern volatile ADC_APCTL2STR _ADC_APCTL2 @0x000030AD;
#define ADC_APCTL2                      _ADC_APCTL2.Byte
#define ADC_APCTL2_ADPC8                _ADC_APCTL2.Bits.ADPC8
#define ADC_APCTL2_ADPC9                _ADC_APCTL2.Bits.ADPC9
#define ADC_APCTL2_ADPC10               _ADC_APCTL2.Bits.ADPC10
#define ADC_APCTL2_ADPC11               _ADC_APCTL2.Bits.ADPC11
#define ADC_APCTL2_ADPC12               _ADC_APCTL2.Bits.ADPC12
#define ADC_APCTL2_ADPC13               _ADC_APCTL2.Bits.ADPC13
#define ADC_APCTL2_ADPC14               _ADC_APCTL2.Bits.ADPC14
#define ADC_APCTL2_ADPC15               _ADC_APCTL2.Bits.ADPC15

#define ADC_APCTL2_ADPC8_MASK           1U
#define ADC_APCTL2_ADPC9_MASK           2U
#define ADC_APCTL2_ADPC10_MASK          4U
#define ADC_APCTL2_ADPC11_MASK          8U
#define ADC_APCTL2_ADPC12_MASK          16U
#define ADC_APCTL2_ADPC13_MASK          32U
#define ADC_APCTL2_ADPC14_MASK          64U
#define ADC_APCTL2_ADPC15_MASK          128U


/*** PORT_HDRVE - Port High Drive Enable Register; 0x000030AF ***/
typedef union {
  byte Byte;
  struct {
    byte PTB4        :1;                                       /* PTB4 */
    byte PTB5        :1;                                       /* PTB5 */
    byte PTD0        :1;                                       /* PTD0 */
    byte PTD1        :1;                                       /* PTD1 */
    byte PTE0        :1;                                       /* PTE0 */
    byte PTE1        :1;                                       /* PTE1 */
    byte PTH0        :1;                                       /* PTH0 */
    byte PTH1        :1;                                       /* PTH1 */
  } Bits;
  struct {
    byte grpPTB_4 :2;
    byte grpPTD  :2;
    byte grpPTE  :2;
    byte grpPTH  :2;
  } MergedBits;
} PORT_HDRVESTR;
extern volatile PORT_HDRVESTR _PORT_HDRVE @0x000030AF;
#define PORT_HDRVE                      _PORT_HDRVE.Byte
#define PORT_HDRVE_PTB4                 _PORT_HDRVE.Bits.PTB4
#define PORT_HDRVE_PTB5                 _PORT_HDRVE.Bits.PTB5
#define PORT_HDRVE_PTD0                 _PORT_HDRVE.Bits.PTD0
#define PORT_HDRVE_PTD1                 _PORT_HDRVE.Bits.PTD1
#define PORT_HDRVE_PTE0                 _PORT_HDRVE.Bits.PTE0
#define PORT_HDRVE_PTE1                 _PORT_HDRVE.Bits.PTE1
#define PORT_HDRVE_PTH0                 _PORT_HDRVE.Bits.PTH0
#define PORT_HDRVE_PTH1                 _PORT_HDRVE.Bits.PTH1
#define PORT_HDRVE_PTB_4                _PORT_HDRVE.MergedBits.grpPTB_4
#define PORT_HDRVE_PTD                  _PORT_HDRVE.MergedBits.grpPTD
#define PORT_HDRVE_PTE                  _PORT_HDRVE.MergedBits.grpPTE
#define PORT_HDRVE_PTH                  _PORT_HDRVE.MergedBits.grpPTH
#define PORT_HDRVE_PTB                  PORT_HDRVE_PTB_4

#define PORT_HDRVE_PTB4_MASK            1U
#define PORT_HDRVE_PTB5_MASK            2U
#define PORT_HDRVE_PTD0_MASK            4U
#define PORT_HDRVE_PTD1_MASK            8U
#define PORT_HDRVE_PTE0_MASK            16U
#define PORT_HDRVE_PTE1_MASK            32U
#define PORT_HDRVE_PTH0_MASK            64U
#define PORT_HDRVE_PTH1_MASK            128U
#define PORT_HDRVE_PTB_4_MASK           3U
#define PORT_HDRVE_PTB_4_BITNUM         0U
#define PORT_HDRVE_PTD_MASK             12U
#define PORT_HDRVE_PTD_BITNUM           2U
#define PORT_HDRVE_PTE_MASK             48U
#define PORT_HDRVE_PTE_BITNUM           4U
#define PORT_HDRVE_PTH_MASK             192U
#define PORT_HDRVE_PTH_BITNUM           6U


/*** PORT_PTAOE - Port A Output Enable Register; 0x000030B0 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAOE0      :1;                                       /* Output Enable for Port A Bit 0 */
    byte PTAOE1      :1;                                       /* Output Enable for Port A Bit 1 */
    byte PTAOE2      :1;                                       /* Output Enable for Port A Bit 2 */
    byte PTAOE3      :1;                                       /* Output Enable for Port A Bit 3 */
    byte PTAOE4      :1;                                       /* Output Enable for Port A Bit 4 */
    byte PTAOE5      :1;                                       /* Output Enable for Port A Bit 5 */
    byte PTAOE6      :1;                                       /* Output Enable for Port A Bit 6 */
    byte PTAOE7      :1;                                       /* Output Enable for Port A Bit 7 */
  } Bits;
} PORT_PTAOESTR;
extern volatile PORT_PTAOESTR _PORT_PTAOE @0x000030B0;
#define PORT_PTAOE                      _PORT_PTAOE.Byte
#define PORT_PTAOE_PTAOE0               _PORT_PTAOE.Bits.PTAOE0
#define PORT_PTAOE_PTAOE1               _PORT_PTAOE.Bits.PTAOE1
#define PORT_PTAOE_PTAOE2               _PORT_PTAOE.Bits.PTAOE2
#define PORT_PTAOE_PTAOE3               _PORT_PTAOE.Bits.PTAOE3
#define PORT_PTAOE_PTAOE4               _PORT_PTAOE.Bits.PTAOE4
#define PORT_PTAOE_PTAOE5               _PORT_PTAOE.Bits.PTAOE5
#define PORT_PTAOE_PTAOE6               _PORT_PTAOE.Bits.PTAOE6
#define PORT_PTAOE_PTAOE7               _PORT_PTAOE.Bits.PTAOE7

#define PORT_PTAOE_PTAOE0_MASK          1U
#define PORT_PTAOE_PTAOE1_MASK          2U
#define PORT_PTAOE_PTAOE2_MASK          4U
#define PORT_PTAOE_PTAOE3_MASK          8U
#define PORT_PTAOE_PTAOE4_MASK          16U
#define PORT_PTAOE_PTAOE5_MASK          32U
#define PORT_PTAOE_PTAOE6_MASK          64U
#define PORT_PTAOE_PTAOE7_MASK          128U


/*** PORT_PTBOE - Port B Output Enable Register; 0x000030B1 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBOE0      :1;                                       /* Output Enable for Port B Bit 0 */
    byte PTBOE1      :1;                                       /* Output Enable for Port B Bit 1 */
    byte PTBOE2      :1;                                       /* Output Enable for Port B Bit 2 */
    byte PTBOE3      :1;                                       /* Output Enable for Port B Bit 3 */
    byte PTBOE4      :1;                                       /* Output Enable for Port B Bit 4 */
    byte PTBOE5      :1;                                       /* Output Enable for Port B Bit 5 */
    byte PTBOE6      :1;                                       /* Output Enable for Port B Bit 6 */
    byte PTBOE7      :1;                                       /* Output Enable for Port B Bit 7 */
  } Bits;
} PORT_PTBOESTR;
extern volatile PORT_PTBOESTR _PORT_PTBOE @0x000030B1;
#define PORT_PTBOE                      _PORT_PTBOE.Byte
#define PORT_PTBOE_PTBOE0               _PORT_PTBOE.Bits.PTBOE0
#define PORT_PTBOE_PTBOE1               _PORT_PTBOE.Bits.PTBOE1
#define PORT_PTBOE_PTBOE2               _PORT_PTBOE.Bits.PTBOE2
#define PORT_PTBOE_PTBOE3               _PORT_PTBOE.Bits.PTBOE3
#define PORT_PTBOE_PTBOE4               _PORT_PTBOE.Bits.PTBOE4
#define PORT_PTBOE_PTBOE5               _PORT_PTBOE.Bits.PTBOE5
#define PORT_PTBOE_PTBOE6               _PORT_PTBOE.Bits.PTBOE6
#define PORT_PTBOE_PTBOE7               _PORT_PTBOE.Bits.PTBOE7

#define PORT_PTBOE_PTBOE0_MASK          1U
#define PORT_PTBOE_PTBOE1_MASK          2U
#define PORT_PTBOE_PTBOE2_MASK          4U
#define PORT_PTBOE_PTBOE3_MASK          8U
#define PORT_PTBOE_PTBOE4_MASK          16U
#define PORT_PTBOE_PTBOE5_MASK          32U
#define PORT_PTBOE_PTBOE6_MASK          64U
#define PORT_PTBOE_PTBOE7_MASK          128U


/*** PORT_PTCOE - Port C Output Enable Register; 0x000030B2 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCOE0      :1;                                       /* Output Enable for Port C Bit 0 */
    byte PTCOE1      :1;                                       /* Output Enable for Port C Bit 1 */
    byte PTCOE2      :1;                                       /* Output Enable for Port C Bit 2 */
    byte PTCOE3      :1;                                       /* Output Enable for Port C Bit 3 */
    byte PTCOE4      :1;                                       /* Output Enable for Port C Bit 4 */
    byte PTCOE5      :1;                                       /* Output Enable for Port C Bit 5 */
    byte PTCOE6      :1;                                       /* Output Enable for Port C Bit 6 */
    byte PTCOE7      :1;                                       /* Output Enable for Port C Bit 7 */
  } Bits;
} PORT_PTCOESTR;
extern volatile PORT_PTCOESTR _PORT_PTCOE @0x000030B2;
#define PORT_PTCOE                      _PORT_PTCOE.Byte
#define PORT_PTCOE_PTCOE0               _PORT_PTCOE.Bits.PTCOE0
#define PORT_PTCOE_PTCOE1               _PORT_PTCOE.Bits.PTCOE1
#define PORT_PTCOE_PTCOE2               _PORT_PTCOE.Bits.PTCOE2
#define PORT_PTCOE_PTCOE3               _PORT_PTCOE.Bits.PTCOE3
#define PORT_PTCOE_PTCOE4               _PORT_PTCOE.Bits.PTCOE4
#define PORT_PTCOE_PTCOE5               _PORT_PTCOE.Bits.PTCOE5
#define PORT_PTCOE_PTCOE6               _PORT_PTCOE.Bits.PTCOE6
#define PORT_PTCOE_PTCOE7               _PORT_PTCOE.Bits.PTCOE7

#define PORT_PTCOE_PTCOE0_MASK          1U
#define PORT_PTCOE_PTCOE1_MASK          2U
#define PORT_PTCOE_PTCOE2_MASK          4U
#define PORT_PTCOE_PTCOE3_MASK          8U
#define PORT_PTCOE_PTCOE4_MASK          16U
#define PORT_PTCOE_PTCOE5_MASK          32U
#define PORT_PTCOE_PTCOE6_MASK          64U
#define PORT_PTCOE_PTCOE7_MASK          128U


/*** PORT_PTDOE - Port D Output Enable Register; 0x000030B3 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDOE0      :1;                                       /* Output Enable for Port D Bit 0 */
    byte PTDOE1      :1;                                       /* Output Enable for Port D Bit 1 */
    byte PTDOE2      :1;                                       /* Output Enable for Port D Bit 2 */
    byte PTDOE3      :1;                                       /* Output Enable for Port D Bit 3 */
    byte PTDOE4      :1;                                       /* Output Enable for Port D Bit 4 */
    byte PTDOE5      :1;                                       /* Output Enable for Port D Bit 5 */
    byte PTDOE6      :1;                                       /* Output Enable for Port D Bit 6 */
    byte PTDOE7      :1;                                       /* Output Enable for Port D Bit 7 */
  } Bits;
} PORT_PTDOESTR;
extern volatile PORT_PTDOESTR _PORT_PTDOE @0x000030B3;
#define PORT_PTDOE                      _PORT_PTDOE.Byte
#define PORT_PTDOE_PTDOE0               _PORT_PTDOE.Bits.PTDOE0
#define PORT_PTDOE_PTDOE1               _PORT_PTDOE.Bits.PTDOE1
#define PORT_PTDOE_PTDOE2               _PORT_PTDOE.Bits.PTDOE2
#define PORT_PTDOE_PTDOE3               _PORT_PTDOE.Bits.PTDOE3
#define PORT_PTDOE_PTDOE4               _PORT_PTDOE.Bits.PTDOE4
#define PORT_PTDOE_PTDOE5               _PORT_PTDOE.Bits.PTDOE5
#define PORT_PTDOE_PTDOE6               _PORT_PTDOE.Bits.PTDOE6
#define PORT_PTDOE_PTDOE7               _PORT_PTDOE.Bits.PTDOE7

#define PORT_PTDOE_PTDOE0_MASK          1U
#define PORT_PTDOE_PTDOE1_MASK          2U
#define PORT_PTDOE_PTDOE2_MASK          4U
#define PORT_PTDOE_PTDOE3_MASK          8U
#define PORT_PTDOE_PTDOE4_MASK          16U
#define PORT_PTDOE_PTDOE5_MASK          32U
#define PORT_PTDOE_PTDOE6_MASK          64U
#define PORT_PTDOE_PTDOE7_MASK          128U


/*** PORT_PTEOE - Port E Output Enable Register; 0x000030B4 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEOE0      :1;                                       /* Output Enable for Port E Bit 0 */
    byte PTEOE1      :1;                                       /* Output Enable for Port E Bit 1 */
    byte PTEOE2      :1;                                       /* Output Enable for Port E Bit 2 */
    byte PTEOE3      :1;                                       /* Output Enable for Port E Bit 3 */
    byte PTEOE4      :1;                                       /* Output Enable for Port E Bit 4 */
    byte PTEOE5      :1;                                       /* Output Enable for Port E Bit 5 */
    byte PTEOE6      :1;                                       /* Output Enable for Port E Bit 6 */
    byte PTEOE7      :1;                                       /* Output Enable for Port E Bit 7 */
  } Bits;
} PORT_PTEOESTR;
extern volatile PORT_PTEOESTR _PORT_PTEOE @0x000030B4;
#define PORT_PTEOE                      _PORT_PTEOE.Byte
#define PORT_PTEOE_PTEOE0               _PORT_PTEOE.Bits.PTEOE0
#define PORT_PTEOE_PTEOE1               _PORT_PTEOE.Bits.PTEOE1
#define PORT_PTEOE_PTEOE2               _PORT_PTEOE.Bits.PTEOE2
#define PORT_PTEOE_PTEOE3               _PORT_PTEOE.Bits.PTEOE3
#define PORT_PTEOE_PTEOE4               _PORT_PTEOE.Bits.PTEOE4
#define PORT_PTEOE_PTEOE5               _PORT_PTEOE.Bits.PTEOE5
#define PORT_PTEOE_PTEOE6               _PORT_PTEOE.Bits.PTEOE6
#define PORT_PTEOE_PTEOE7               _PORT_PTEOE.Bits.PTEOE7

#define PORT_PTEOE_PTEOE0_MASK          1U
#define PORT_PTEOE_PTEOE1_MASK          2U
#define PORT_PTEOE_PTEOE2_MASK          4U
#define PORT_PTEOE_PTEOE3_MASK          8U
#define PORT_PTEOE_PTEOE4_MASK          16U
#define PORT_PTEOE_PTEOE5_MASK          32U
#define PORT_PTEOE_PTEOE6_MASK          64U
#define PORT_PTEOE_PTEOE7_MASK          128U


/*** PORT_PTFOE - Port F Output Enable Register; 0x000030B5 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFOE0      :1;                                       /* Output Enable for Port F Bit 0 */
    byte PTFOE1      :1;                                       /* Output Enable for Port F Bit 1 */
    byte PTFOE2      :1;                                       /* Output Enable for Port F Bit 2 */
    byte PTFOE3      :1;                                       /* Output Enable for Port F Bit 3 */
    byte PTFOE4      :1;                                       /* Output Enable for Port F Bit 4 */
    byte PTFOE5      :1;                                       /* Output Enable for Port F Bit 5 */
    byte PTFOE6      :1;                                       /* Output Enable for Port F Bit 6 */
    byte PTFOE7      :1;                                       /* Output Enable for Port F Bit 7 */
  } Bits;
} PORT_PTFOESTR;
extern volatile PORT_PTFOESTR _PORT_PTFOE @0x000030B5;
#define PORT_PTFOE                      _PORT_PTFOE.Byte
#define PORT_PTFOE_PTFOE0               _PORT_PTFOE.Bits.PTFOE0
#define PORT_PTFOE_PTFOE1               _PORT_PTFOE.Bits.PTFOE1
#define PORT_PTFOE_PTFOE2               _PORT_PTFOE.Bits.PTFOE2
#define PORT_PTFOE_PTFOE3               _PORT_PTFOE.Bits.PTFOE3
#define PORT_PTFOE_PTFOE4               _PORT_PTFOE.Bits.PTFOE4
#define PORT_PTFOE_PTFOE5               _PORT_PTFOE.Bits.PTFOE5
#define PORT_PTFOE_PTFOE6               _PORT_PTFOE.Bits.PTFOE6
#define PORT_PTFOE_PTFOE7               _PORT_PTFOE.Bits.PTFOE7

#define PORT_PTFOE_PTFOE0_MASK          1U
#define PORT_PTFOE_PTFOE1_MASK          2U
#define PORT_PTFOE_PTFOE2_MASK          4U
#define PORT_PTFOE_PTFOE3_MASK          8U
#define PORT_PTFOE_PTFOE4_MASK          16U
#define PORT_PTFOE_PTFOE5_MASK          32U
#define PORT_PTFOE_PTFOE6_MASK          64U
#define PORT_PTFOE_PTFOE7_MASK          128U


/*** PORT_PTGOE - Port G Output Enable Register; 0x000030B6 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGOE0      :1;                                       /* Output Enable for Port G Bit 0 */
    byte PTGOE1      :1;                                       /* Output Enable for Port G Bit 1 */
    byte PTGOE2      :1;                                       /* Output Enable for Port G Bit 2 */
    byte PTGOE3      :1;                                       /* Output Enable for Port G Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGOE :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PORT_PTGOESTR;
extern volatile PORT_PTGOESTR _PORT_PTGOE @0x000030B6;
#define PORT_PTGOE                      _PORT_PTGOE.Byte
#define PORT_PTGOE_PTGOE0               _PORT_PTGOE.Bits.PTGOE0
#define PORT_PTGOE_PTGOE1               _PORT_PTGOE.Bits.PTGOE1
#define PORT_PTGOE_PTGOE2               _PORT_PTGOE.Bits.PTGOE2
#define PORT_PTGOE_PTGOE3               _PORT_PTGOE.Bits.PTGOE3
#define PORT_PTGOE_PTGOE                _PORT_PTGOE.MergedBits.grpPTGOE

#define PORT_PTGOE_PTGOE0_MASK          1U
#define PORT_PTGOE_PTGOE1_MASK          2U
#define PORT_PTGOE_PTGOE2_MASK          4U
#define PORT_PTGOE_PTGOE3_MASK          8U
#define PORT_PTGOE_PTGOE_MASK           15U
#define PORT_PTGOE_PTGOE_BITNUM         0U


/*** PORT_PTHOE - Port H Output Enable Register; 0x000030B7 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHOE0      :1;                                       /* Output Enable for Port H Bit 0 */
    byte PTHOE1      :1;                                       /* Output Enable for Port H Bit 1 */
    byte PTHOE2      :1;                                       /* Output Enable for Port H Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTHOE6      :1;                                       /* Output Enable for Port H Bit 6 */
    byte PTHOE7      :1;                                       /* Output Enable for Port H Bit 7 */
  } Bits;
  struct {
    byte grpPTHOE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTHOE_6 :2;
  } MergedBits;
} PORT_PTHOESTR;
extern volatile PORT_PTHOESTR _PORT_PTHOE @0x000030B7;
#define PORT_PTHOE                      _PORT_PTHOE.Byte
#define PORT_PTHOE_PTHOE0               _PORT_PTHOE.Bits.PTHOE0
#define PORT_PTHOE_PTHOE1               _PORT_PTHOE.Bits.PTHOE1
#define PORT_PTHOE_PTHOE2               _PORT_PTHOE.Bits.PTHOE2
#define PORT_PTHOE_PTHOE6               _PORT_PTHOE.Bits.PTHOE6
#define PORT_PTHOE_PTHOE7               _PORT_PTHOE.Bits.PTHOE7
#define PORT_PTHOE_PTHOE                _PORT_PTHOE.MergedBits.grpPTHOE
#define PORT_PTHOE_PTHOE_6              _PORT_PTHOE.MergedBits.grpPTHOE_6

#define PORT_PTHOE_PTHOE0_MASK          1U
#define PORT_PTHOE_PTHOE1_MASK          2U
#define PORT_PTHOE_PTHOE2_MASK          4U
#define PORT_PTHOE_PTHOE6_MASK          64U
#define PORT_PTHOE_PTHOE7_MASK          128U
#define PORT_PTHOE_PTHOE_MASK           7U
#define PORT_PTHOE_PTHOE_BITNUM         0U
#define PORT_PTHOE_PTHOE_6_MASK         192U
#define PORT_PTHOE_PTHOE_6_BITNUM       6U


/*** PORT_PTAIE - Port A Input Enable Register; 0x000030B8 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAIE0      :1;                                       /* Input Enable for Port A Bit 0 */
    byte PTAIE1      :1;                                       /* Input Enable for Port A Bit 1 */
    byte PTAIE2      :1;                                       /* Input Enable for Port A Bit 2 */
    byte PTAIE3      :1;                                       /* Input Enable for Port A Bit 3 */
    byte             :1; 
    byte PTAIE5      :1;                                       /* Input Enable for Port A Bit 5 */
    byte PTAIE6      :1;                                       /* Input Enable for Port A Bit 6 */
    byte PTAIE7      :1;                                       /* Input Enable for Port A Bit 7 */
  } Bits;
  struct {
    byte grpPTAIE :4;
    byte         :1;
    byte grpPTAIE_5 :3;
  } MergedBits;
} PORT_PTAIESTR;
extern volatile PORT_PTAIESTR _PORT_PTAIE @0x000030B8;
#define PORT_PTAIE                      _PORT_PTAIE.Byte
#define PORT_PTAIE_PTAIE0               _PORT_PTAIE.Bits.PTAIE0
#define PORT_PTAIE_PTAIE1               _PORT_PTAIE.Bits.PTAIE1
#define PORT_PTAIE_PTAIE2               _PORT_PTAIE.Bits.PTAIE2
#define PORT_PTAIE_PTAIE3               _PORT_PTAIE.Bits.PTAIE3
#define PORT_PTAIE_PTAIE5               _PORT_PTAIE.Bits.PTAIE5
#define PORT_PTAIE_PTAIE6               _PORT_PTAIE.Bits.PTAIE6
#define PORT_PTAIE_PTAIE7               _PORT_PTAIE.Bits.PTAIE7
#define PORT_PTAIE_PTAIE                _PORT_PTAIE.MergedBits.grpPTAIE
#define PORT_PTAIE_PTAIE_5              _PORT_PTAIE.MergedBits.grpPTAIE_5

#define PORT_PTAIE_PTAIE0_MASK          1U
#define PORT_PTAIE_PTAIE1_MASK          2U
#define PORT_PTAIE_PTAIE2_MASK          4U
#define PORT_PTAIE_PTAIE3_MASK          8U
#define PORT_PTAIE_PTAIE5_MASK          32U
#define PORT_PTAIE_PTAIE6_MASK          64U
#define PORT_PTAIE_PTAIE7_MASK          128U
#define PORT_PTAIE_PTAIE_MASK           15U
#define PORT_PTAIE_PTAIE_BITNUM         0U
#define PORT_PTAIE_PTAIE_5_MASK         224U
#define PORT_PTAIE_PTAIE_5_BITNUM       5U


/*** PORT_PTBIE - Port B Input Enable Register; 0x000030B9 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBIE0      :1;                                       /* Input Enable for Port B Bit 0 */
    byte PTBIE1      :1;                                       /* Input Enable for Port B Bit 1 */
    byte PTBIE2      :1;                                       /* Input Enable for Port B Bit 2 */
    byte PTBIE3      :1;                                       /* Input Enable for Port B Bit 3 */
    byte PTBIE4      :1;                                       /* Input Enable for Port B Bit 4 */
    byte PTBIE5      :1;                                       /* Input Enable for Port B Bit 5 */
    byte PTBIE6      :1;                                       /* Input Enable for Port B Bit 6 */
    byte PTBIE7      :1;                                       /* Input Enable for Port B Bit 7 */
  } Bits;
} PORT_PTBIESTR;
extern volatile PORT_PTBIESTR _PORT_PTBIE @0x000030B9;
#define PORT_PTBIE                      _PORT_PTBIE.Byte
#define PORT_PTBIE_PTBIE0               _PORT_PTBIE.Bits.PTBIE0
#define PORT_PTBIE_PTBIE1               _PORT_PTBIE.Bits.PTBIE1
#define PORT_PTBIE_PTBIE2               _PORT_PTBIE.Bits.PTBIE2
#define PORT_PTBIE_PTBIE3               _PORT_PTBIE.Bits.PTBIE3
#define PORT_PTBIE_PTBIE4               _PORT_PTBIE.Bits.PTBIE4
#define PORT_PTBIE_PTBIE5               _PORT_PTBIE.Bits.PTBIE5
#define PORT_PTBIE_PTBIE6               _PORT_PTBIE.Bits.PTBIE6
#define PORT_PTBIE_PTBIE7               _PORT_PTBIE.Bits.PTBIE7

#define PORT_PTBIE_PTBIE0_MASK          1U
#define PORT_PTBIE_PTBIE1_MASK          2U
#define PORT_PTBIE_PTBIE2_MASK          4U
#define PORT_PTBIE_PTBIE3_MASK          8U
#define PORT_PTBIE_PTBIE4_MASK          16U
#define PORT_PTBIE_PTBIE5_MASK          32U
#define PORT_PTBIE_PTBIE6_MASK          64U
#define PORT_PTBIE_PTBIE7_MASK          128U


/*** PORT_PTCIE - Port C Input Enable Register; 0x000030BA ***/
typedef union {
  byte Byte;
  struct {
    byte PTCIE0      :1;                                       /* Input Enable for Port C Bit 0 */
    byte PTCIE1      :1;                                       /* Input Enable for Port C Bit 1 */
    byte PTCIE2      :1;                                       /* Input Enable for Port C Bit 2 */
    byte PTCIE3      :1;                                       /* Input Enable for Port C Bit 3 */
    byte PTCIE4      :1;                                       /* Input Enable for Port C Bit 4 */
    byte PTCIE5      :1;                                       /* Input Enable for Port C Bit 5 */
    byte PTCIE6      :1;                                       /* Input Enable for Port C Bit 6 */
    byte PTCIE7      :1;                                       /* Input Enable for Port C Bit 7 */
  } Bits;
} PORT_PTCIESTR;
extern volatile PORT_PTCIESTR _PORT_PTCIE @0x000030BA;
#define PORT_PTCIE                      _PORT_PTCIE.Byte
#define PORT_PTCIE_PTCIE0               _PORT_PTCIE.Bits.PTCIE0
#define PORT_PTCIE_PTCIE1               _PORT_PTCIE.Bits.PTCIE1
#define PORT_PTCIE_PTCIE2               _PORT_PTCIE.Bits.PTCIE2
#define PORT_PTCIE_PTCIE3               _PORT_PTCIE.Bits.PTCIE3
#define PORT_PTCIE_PTCIE4               _PORT_PTCIE.Bits.PTCIE4
#define PORT_PTCIE_PTCIE5               _PORT_PTCIE.Bits.PTCIE5
#define PORT_PTCIE_PTCIE6               _PORT_PTCIE.Bits.PTCIE6
#define PORT_PTCIE_PTCIE7               _PORT_PTCIE.Bits.PTCIE7

#define PORT_PTCIE_PTCIE0_MASK          1U
#define PORT_PTCIE_PTCIE1_MASK          2U
#define PORT_PTCIE_PTCIE2_MASK          4U
#define PORT_PTCIE_PTCIE3_MASK          8U
#define PORT_PTCIE_PTCIE4_MASK          16U
#define PORT_PTCIE_PTCIE5_MASK          32U
#define PORT_PTCIE_PTCIE6_MASK          64U
#define PORT_PTCIE_PTCIE7_MASK          128U


/*** PORT_PTDIE - Port D Input Enable Register; 0x000030BB ***/
typedef union {
  byte Byte;
  struct {
    byte PTDIE0      :1;                                       /* Input Enable for Port D Bit 0 */
    byte PTDIE1      :1;                                       /* Input Enable for Port D Bit 1 */
    byte PTDIE2      :1;                                       /* Input Enable for Port D Bit 2 */
    byte PTDIE3      :1;                                       /* Input Enable for Port D Bit 3 */
    byte PTDIE4      :1;                                       /* Input Enable for Port D Bit 4 */
    byte PTDIE5      :1;                                       /* Input Enable for Port D Bit 5 */
    byte PTDIE6      :1;                                       /* Input Enable for Port D Bit 6 */
    byte PTDIE7      :1;                                       /* Input Enable for Port D Bit 7 */
  } Bits;
} PORT_PTDIESTR;
extern volatile PORT_PTDIESTR _PORT_PTDIE @0x000030BB;
#define PORT_PTDIE                      _PORT_PTDIE.Byte
#define PORT_PTDIE_PTDIE0               _PORT_PTDIE.Bits.PTDIE0
#define PORT_PTDIE_PTDIE1               _PORT_PTDIE.Bits.PTDIE1
#define PORT_PTDIE_PTDIE2               _PORT_PTDIE.Bits.PTDIE2
#define PORT_PTDIE_PTDIE3               _PORT_PTDIE.Bits.PTDIE3
#define PORT_PTDIE_PTDIE4               _PORT_PTDIE.Bits.PTDIE4
#define PORT_PTDIE_PTDIE5               _PORT_PTDIE.Bits.PTDIE5
#define PORT_PTDIE_PTDIE6               _PORT_PTDIE.Bits.PTDIE6
#define PORT_PTDIE_PTDIE7               _PORT_PTDIE.Bits.PTDIE7

#define PORT_PTDIE_PTDIE0_MASK          1U
#define PORT_PTDIE_PTDIE1_MASK          2U
#define PORT_PTDIE_PTDIE2_MASK          4U
#define PORT_PTDIE_PTDIE3_MASK          8U
#define PORT_PTDIE_PTDIE4_MASK          16U
#define PORT_PTDIE_PTDIE5_MASK          32U
#define PORT_PTDIE_PTDIE6_MASK          64U
#define PORT_PTDIE_PTDIE7_MASK          128U


/*** PORT_PTEIE - Port E Input Enable Register; 0x000030BC ***/
typedef union {
  byte Byte;
  struct {
    byte PTEIE0      :1;                                       /* Input Enable for Port E Bit 0 */
    byte PTEIE1      :1;                                       /* Input Enable for Port E Bit 1 */
    byte PTEIE2      :1;                                       /* Input Enable for Port E Bit 2 */
    byte PTEIE3      :1;                                       /* Input Enable for Port E Bit 3 */
    byte PTEIE4      :1;                                       /* Input Enable for Port E Bit 4 */
    byte PTEIE5      :1;                                       /* Input Enable for Port E Bit 5 */
    byte PTEIE6      :1;                                       /* Input Enable for Port E Bit 6 */
    byte PTEIE7      :1;                                       /* Input Enable for Port E Bit 7 */
  } Bits;
} PORT_PTEIESTR;
extern volatile PORT_PTEIESTR _PORT_PTEIE @0x000030BC;
#define PORT_PTEIE                      _PORT_PTEIE.Byte
#define PORT_PTEIE_PTEIE0               _PORT_PTEIE.Bits.PTEIE0
#define PORT_PTEIE_PTEIE1               _PORT_PTEIE.Bits.PTEIE1
#define PORT_PTEIE_PTEIE2               _PORT_PTEIE.Bits.PTEIE2
#define PORT_PTEIE_PTEIE3               _PORT_PTEIE.Bits.PTEIE3
#define PORT_PTEIE_PTEIE4               _PORT_PTEIE.Bits.PTEIE4
#define PORT_PTEIE_PTEIE5               _PORT_PTEIE.Bits.PTEIE5
#define PORT_PTEIE_PTEIE6               _PORT_PTEIE.Bits.PTEIE6
#define PORT_PTEIE_PTEIE7               _PORT_PTEIE.Bits.PTEIE7

#define PORT_PTEIE_PTEIE0_MASK          1U
#define PORT_PTEIE_PTEIE1_MASK          2U
#define PORT_PTEIE_PTEIE2_MASK          4U
#define PORT_PTEIE_PTEIE3_MASK          8U
#define PORT_PTEIE_PTEIE4_MASK          16U
#define PORT_PTEIE_PTEIE5_MASK          32U
#define PORT_PTEIE_PTEIE6_MASK          64U
#define PORT_PTEIE_PTEIE7_MASK          128U


/*** PORT_PTFIE - Port F Input Enable Register; 0x000030BD ***/
typedef union {
  byte Byte;
  struct {
    byte PTFIE0      :1;                                       /* Input Enable for Port F Bit 0 */
    byte PTFIE1      :1;                                       /* Input Enable for Port F Bit 1 */
    byte PTFIE2      :1;                                       /* Input Enable for Port F Bit 2 */
    byte PTFIE3      :1;                                       /* Input Enable for Port F Bit 3 */
    byte PTFIE4      :1;                                       /* Input Enable for Port F Bit 4 */
    byte PTFIE5      :1;                                       /* Input Enable for Port F Bit 5 */
    byte PTFIE6      :1;                                       /* Input Enable for Port F Bit 6 */
    byte PTFIE7      :1;                                       /* Input Enable for Port F Bit 7 */
  } Bits;
} PORT_PTFIESTR;
extern volatile PORT_PTFIESTR _PORT_PTFIE @0x000030BD;
#define PORT_PTFIE                      _PORT_PTFIE.Byte
#define PORT_PTFIE_PTFIE0               _PORT_PTFIE.Bits.PTFIE0
#define PORT_PTFIE_PTFIE1               _PORT_PTFIE.Bits.PTFIE1
#define PORT_PTFIE_PTFIE2               _PORT_PTFIE.Bits.PTFIE2
#define PORT_PTFIE_PTFIE3               _PORT_PTFIE.Bits.PTFIE3
#define PORT_PTFIE_PTFIE4               _PORT_PTFIE.Bits.PTFIE4
#define PORT_PTFIE_PTFIE5               _PORT_PTFIE.Bits.PTFIE5
#define PORT_PTFIE_PTFIE6               _PORT_PTFIE.Bits.PTFIE6
#define PORT_PTFIE_PTFIE7               _PORT_PTFIE.Bits.PTFIE7

#define PORT_PTFIE_PTFIE0_MASK          1U
#define PORT_PTFIE_PTFIE1_MASK          2U
#define PORT_PTFIE_PTFIE2_MASK          4U
#define PORT_PTFIE_PTFIE3_MASK          8U
#define PORT_PTFIE_PTFIE4_MASK          16U
#define PORT_PTFIE_PTFIE5_MASK          32U
#define PORT_PTFIE_PTFIE6_MASK          64U
#define PORT_PTFIE_PTFIE7_MASK          128U


/*** PORT_PTGIE - Port G Input Enable Register; 0x000030BE ***/
typedef union {
  byte Byte;
  struct {
    byte PTGIE0      :1;                                       /* Input Enable for Port G Bit 0 */
    byte PTGIE1      :1;                                       /* Input Enable for Port G Bit 1 */
    byte PTGIE2      :1;                                       /* Input Enable for Port G Bit 2 */
    byte PTGIE3      :1;                                       /* Input Enable for Port G Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGIE :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PORT_PTGIESTR;
extern volatile PORT_PTGIESTR _PORT_PTGIE @0x000030BE;
#define PORT_PTGIE                      _PORT_PTGIE.Byte
#define PORT_PTGIE_PTGIE0               _PORT_PTGIE.Bits.PTGIE0
#define PORT_PTGIE_PTGIE1               _PORT_PTGIE.Bits.PTGIE1
#define PORT_PTGIE_PTGIE2               _PORT_PTGIE.Bits.PTGIE2
#define PORT_PTGIE_PTGIE3               _PORT_PTGIE.Bits.PTGIE3
#define PORT_PTGIE_PTGIE                _PORT_PTGIE.MergedBits.grpPTGIE

#define PORT_PTGIE_PTGIE0_MASK          1U
#define PORT_PTGIE_PTGIE1_MASK          2U
#define PORT_PTGIE_PTGIE2_MASK          4U
#define PORT_PTGIE_PTGIE3_MASK          8U
#define PORT_PTGIE_PTGIE_MASK           15U
#define PORT_PTGIE_PTGIE_BITNUM         0U


/*** PORT_PTHIE - Port H Input Enable Register; 0x000030BF ***/
typedef union {
  byte Byte;
  struct {
    byte PTHIE0      :1;                                       /* Input Enable for Port H Bit 0 */
    byte PTHIE1      :1;                                       /* Input Enable for Port H Bit 1 */
    byte PTHIE2      :1;                                       /* Input Enable for Port H Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTHIE6      :1;                                       /* Input Enable for Port H Bit 6 */
    byte PTHIE7      :1;                                       /* Input Enable for Port H Bit 7 */
  } Bits;
  struct {
    byte grpPTHIE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTHIE_6 :2;
  } MergedBits;
} PORT_PTHIESTR;
extern volatile PORT_PTHIESTR _PORT_PTHIE @0x000030BF;
#define PORT_PTHIE                      _PORT_PTHIE.Byte
#define PORT_PTHIE_PTHIE0               _PORT_PTHIE.Bits.PTHIE0
#define PORT_PTHIE_PTHIE1               _PORT_PTHIE.Bits.PTHIE1
#define PORT_PTHIE_PTHIE2               _PORT_PTHIE.Bits.PTHIE2
#define PORT_PTHIE_PTHIE6               _PORT_PTHIE.Bits.PTHIE6
#define PORT_PTHIE_PTHIE7               _PORT_PTHIE.Bits.PTHIE7
#define PORT_PTHIE_PTHIE                _PORT_PTHIE.MergedBits.grpPTHIE
#define PORT_PTHIE_PTHIE_6              _PORT_PTHIE.MergedBits.grpPTHIE_6

#define PORT_PTHIE_PTHIE0_MASK          1U
#define PORT_PTHIE_PTHIE1_MASK          2U
#define PORT_PTHIE_PTHIE2_MASK          4U
#define PORT_PTHIE_PTHIE6_MASK          64U
#define PORT_PTHIE_PTHIE7_MASK          128U
#define PORT_PTHIE_PTHIE_MASK           7U
#define PORT_PTHIE_PTHIE_BITNUM         0U
#define PORT_PTHIE_PTHIE_6_MASK         192U
#define PORT_PTHIE_PTHIE_6_BITNUM       6U


/*** FTM2_SC - Status and Control; 0x000030C0 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Factor Selection, bit 0 */
    byte PS1         :1;                                       /* Prescale Factor Selection, bit 1 */
    byte PS2         :1;                                       /* Prescale Factor Selection, bit 2 */
    byte CLKS0       :1;                                       /* Clock Source Selection, bit 0 */
    byte CLKS1       :1;                                       /* Clock Source Selection, bit 1 */
    byte CPWMS       :1;                                       /* Center-aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKS :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_SCSTR;
extern volatile FTM2_SCSTR _FTM2_SC @0x000030C0;
#define FTM2_SC                         _FTM2_SC.Byte
#define FTM2_SC_PS0                     _FTM2_SC.Bits.PS0
#define FTM2_SC_PS1                     _FTM2_SC.Bits.PS1
#define FTM2_SC_PS2                     _FTM2_SC.Bits.PS2
#define FTM2_SC_CLKS0                   _FTM2_SC.Bits.CLKS0
#define FTM2_SC_CLKS1                   _FTM2_SC.Bits.CLKS1
#define FTM2_SC_CPWMS                   _FTM2_SC.Bits.CPWMS
#define FTM2_SC_TOIE                    _FTM2_SC.Bits.TOIE
#define FTM2_SC_TOF                     _FTM2_SC.Bits.TOF
#define FTM2_SC_PS                      _FTM2_SC.MergedBits.grpPS
#define FTM2_SC_CLKS                    _FTM2_SC.MergedBits.grpCLKS

#define FTM2_SC_PS0_MASK                1U
#define FTM2_SC_PS1_MASK                2U
#define FTM2_SC_PS2_MASK                4U
#define FTM2_SC_CLKS0_MASK              8U
#define FTM2_SC_CLKS1_MASK              16U
#define FTM2_SC_CPWMS_MASK              32U
#define FTM2_SC_TOIE_MASK               64U
#define FTM2_SC_TOF_MASK                128U
#define FTM2_SC_PS_MASK                 7U
#define FTM2_SC_PS_BITNUM               0U
#define FTM2_SC_CLKS_MASK               24U
#define FTM2_SC_CLKS_BITNUM             3U


/*** FTM2_CNT - FTM2 Timer Counter Register; 0x000030C1 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_CNTH - Counter High; 0x000030C1 ***/
    union {
      byte Byte;
    } FTM2_CNTHSTR;
    #define FTM2_CNTH                   _FTM2_CNT.Overlap_STR.FTM2_CNTHSTR.Byte
    

    /*** FTM2_CNTL - Counter Low; 0x000030C2 ***/
    union {
      byte Byte;
    } FTM2_CNTLSTR;
    #define FTM2_CNTL                   _FTM2_CNT.Overlap_STR.FTM2_CNTLSTR.Byte
    
  } Overlap_STR;

} FTM2_CNTSTR;
extern volatile FTM2_CNTSTR _FTM2_CNT @0x000030C1;
#define FTM2_CNT                        _FTM2_CNT.Word


/*** FTM2_MOD - FTM2 Timer Counter Modulo Register; 0x000030C3 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_MODH - Modulo High; 0x000030C3 ***/
    union {
      byte Byte;
    } FTM2_MODHSTR;
    #define FTM2_MODH                   _FTM2_MOD.Overlap_STR.FTM2_MODHSTR.Byte
    

    /*** FTM2_MODL - Modulo Low; 0x000030C4 ***/
    union {
      byte Byte;
    } FTM2_MODLSTR;
    #define FTM2_MODL                   _FTM2_MOD.Overlap_STR.FTM2_MODLSTR.Byte
    
  } Overlap_STR;

} FTM2_MODSTR;
extern volatile FTM2_MODSTR _FTM2_MOD @0x000030C3;
#define FTM2_MOD                        _FTM2_MOD.Word


/*** FTM2_C0SC - Channel Status and Control; 0x000030C5 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_C0SCSTR;
extern volatile FTM2_C0SCSTR _FTM2_C0SC @0x000030C5;
#define FTM2_C0SC                       _FTM2_C0SC.Byte
#define FTM2_C0SC_ELSA                  _FTM2_C0SC.Bits.ELSA
#define FTM2_C0SC_ELSB                  _FTM2_C0SC.Bits.ELSB
#define FTM2_C0SC_MSA                   _FTM2_C0SC.Bits.MSA
#define FTM2_C0SC_MSB                   _FTM2_C0SC.Bits.MSB
#define FTM2_C0SC_CHIE                  _FTM2_C0SC.Bits.CHIE
#define FTM2_C0SC_CHF                   _FTM2_C0SC.Bits.CHF
#define FTM2_C0SC_ELSx                  _FTM2_C0SC.MergedBits.grpELSx
#define FTM2_C0SC_MSx                   _FTM2_C0SC.MergedBits.grpMSx

#define FTM2_C0SC_ELSA_MASK             4U
#define FTM2_C0SC_ELSB_MASK             8U
#define FTM2_C0SC_MSA_MASK              16U
#define FTM2_C0SC_MSB_MASK              32U
#define FTM2_C0SC_CHIE_MASK             64U
#define FTM2_C0SC_CHF_MASK              128U
#define FTM2_C0SC_ELSx_MASK             12U
#define FTM2_C0SC_ELSx_BITNUM           2U
#define FTM2_C0SC_MSx_MASK              48U
#define FTM2_C0SC_MSx_BITNUM            4U


/*** FTM2_C0V - FTM2 Timer Channel 0 Value Register; 0x000030C6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_C0VH - Channel Value High; 0x000030C6 ***/
    union {
      byte Byte;
    } FTM2_C0VHSTR;
    #define FTM2_C0VH                   _FTM2_C0V.Overlap_STR.FTM2_C0VHSTR.Byte
    

    /*** FTM2_C0VL - Channel Value Low; 0x000030C7 ***/
    union {
      byte Byte;
    } FTM2_C0VLSTR;
    #define FTM2_C0VL                   _FTM2_C0V.Overlap_STR.FTM2_C0VLSTR.Byte
    
  } Overlap_STR;

} FTM2_C0VSTR;
extern volatile FTM2_C0VSTR _FTM2_C0V @0x000030C6;
#define FTM2_C0V                        _FTM2_C0V.Word


/*** FTM2_C1SC - Channel Status and Control; 0x000030C8 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_C1SCSTR;
extern volatile FTM2_C1SCSTR _FTM2_C1SC @0x000030C8;
#define FTM2_C1SC                       _FTM2_C1SC.Byte
#define FTM2_C1SC_ELSA                  _FTM2_C1SC.Bits.ELSA
#define FTM2_C1SC_ELSB                  _FTM2_C1SC.Bits.ELSB
#define FTM2_C1SC_MSA                   _FTM2_C1SC.Bits.MSA
#define FTM2_C1SC_MSB                   _FTM2_C1SC.Bits.MSB
#define FTM2_C1SC_CHIE                  _FTM2_C1SC.Bits.CHIE
#define FTM2_C1SC_CHF                   _FTM2_C1SC.Bits.CHF
#define FTM2_C1SC_ELSx                  _FTM2_C1SC.MergedBits.grpELSx
#define FTM2_C1SC_MSx                   _FTM2_C1SC.MergedBits.grpMSx

#define FTM2_C1SC_ELSA_MASK             4U
#define FTM2_C1SC_ELSB_MASK             8U
#define FTM2_C1SC_MSA_MASK              16U
#define FTM2_C1SC_MSB_MASK              32U
#define FTM2_C1SC_CHIE_MASK             64U
#define FTM2_C1SC_CHF_MASK              128U
#define FTM2_C1SC_ELSx_MASK             12U
#define FTM2_C1SC_ELSx_BITNUM           2U
#define FTM2_C1SC_MSx_MASK              48U
#define FTM2_C1SC_MSx_BITNUM            4U


/*** FTM2_C1V - FTM2 Timer Channel 1 Value Register; 0x000030C9 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_C1VH - Channel Value High; 0x000030C9 ***/
    union {
      byte Byte;
    } FTM2_C1VHSTR;
    #define FTM2_C1VH                   _FTM2_C1V.Overlap_STR.FTM2_C1VHSTR.Byte
    

    /*** FTM2_C1VL - Channel Value Low; 0x000030CA ***/
    union {
      byte Byte;
    } FTM2_C1VLSTR;
    #define FTM2_C1VL                   _FTM2_C1V.Overlap_STR.FTM2_C1VLSTR.Byte
    
  } Overlap_STR;

} FTM2_C1VSTR;
extern volatile FTM2_C1VSTR _FTM2_C1V @0x000030C9;
#define FTM2_C1V                        _FTM2_C1V.Word


/*** FTM2_C2SC - Channel Status and Control; 0x000030CB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_C2SCSTR;
extern volatile FTM2_C2SCSTR _FTM2_C2SC @0x000030CB;
#define FTM2_C2SC                       _FTM2_C2SC.Byte
#define FTM2_C2SC_ELSA                  _FTM2_C2SC.Bits.ELSA
#define FTM2_C2SC_ELSB                  _FTM2_C2SC.Bits.ELSB
#define FTM2_C2SC_MSA                   _FTM2_C2SC.Bits.MSA
#define FTM2_C2SC_MSB                   _FTM2_C2SC.Bits.MSB
#define FTM2_C2SC_CHIE                  _FTM2_C2SC.Bits.CHIE
#define FTM2_C2SC_CHF                   _FTM2_C2SC.Bits.CHF
#define FTM2_C2SC_ELSx                  _FTM2_C2SC.MergedBits.grpELSx
#define FTM2_C2SC_MSx                   _FTM2_C2SC.MergedBits.grpMSx

#define FTM2_C2SC_ELSA_MASK             4U
#define FTM2_C2SC_ELSB_MASK             8U
#define FTM2_C2SC_MSA_MASK              16U
#define FTM2_C2SC_MSB_MASK              32U
#define FTM2_C2SC_CHIE_MASK             64U
#define FTM2_C2SC_CHF_MASK              128U
#define FTM2_C2SC_ELSx_MASK             12U
#define FTM2_C2SC_ELSx_BITNUM           2U
#define FTM2_C2SC_MSx_MASK              48U
#define FTM2_C2SC_MSx_BITNUM            4U


/*** FTM2_C2V - FTM2 Timer Channel 2 Value Register; 0x000030CC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_C2VH - Channel Value High; 0x000030CC ***/
    union {
      byte Byte;
    } FTM2_C2VHSTR;
    #define FTM2_C2VH                   _FTM2_C2V.Overlap_STR.FTM2_C2VHSTR.Byte
    

    /*** FTM2_C2VL - Channel Value Low; 0x000030CD ***/
    union {
      byte Byte;
    } FTM2_C2VLSTR;
    #define FTM2_C2VL                   _FTM2_C2V.Overlap_STR.FTM2_C2VLSTR.Byte
    
  } Overlap_STR;

} FTM2_C2VSTR;
extern volatile FTM2_C2VSTR _FTM2_C2V @0x000030CC;
#define FTM2_C2V                        _FTM2_C2V.Word


/*** FTM2_C3SC - Channel Status and Control; 0x000030CE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_C3SCSTR;
extern volatile FTM2_C3SCSTR _FTM2_C3SC @0x000030CE;
#define FTM2_C3SC                       _FTM2_C3SC.Byte
#define FTM2_C3SC_ELSA                  _FTM2_C3SC.Bits.ELSA
#define FTM2_C3SC_ELSB                  _FTM2_C3SC.Bits.ELSB
#define FTM2_C3SC_MSA                   _FTM2_C3SC.Bits.MSA
#define FTM2_C3SC_MSB                   _FTM2_C3SC.Bits.MSB
#define FTM2_C3SC_CHIE                  _FTM2_C3SC.Bits.CHIE
#define FTM2_C3SC_CHF                   _FTM2_C3SC.Bits.CHF
#define FTM2_C3SC_ELSx                  _FTM2_C3SC.MergedBits.grpELSx
#define FTM2_C3SC_MSx                   _FTM2_C3SC.MergedBits.grpMSx

#define FTM2_C3SC_ELSA_MASK             4U
#define FTM2_C3SC_ELSB_MASK             8U
#define FTM2_C3SC_MSA_MASK              16U
#define FTM2_C3SC_MSB_MASK              32U
#define FTM2_C3SC_CHIE_MASK             64U
#define FTM2_C3SC_CHF_MASK              128U
#define FTM2_C3SC_ELSx_MASK             12U
#define FTM2_C3SC_ELSx_BITNUM           2U
#define FTM2_C3SC_MSx_MASK              48U
#define FTM2_C3SC_MSx_BITNUM            4U


/*** FTM2_C3V - FTM2 Timer Channel 3 Value Register; 0x000030CF ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_C3VH - Channel Value High; 0x000030CF ***/
    union {
      byte Byte;
    } FTM2_C3VHSTR;
    #define FTM2_C3VH                   _FTM2_C3V.Overlap_STR.FTM2_C3VHSTR.Byte
    

    /*** FTM2_C3VL - Channel Value Low; 0x000030D0 ***/
    union {
      byte Byte;
    } FTM2_C3VLSTR;
    #define FTM2_C3VL                   _FTM2_C3V.Overlap_STR.FTM2_C3VLSTR.Byte
    
  } Overlap_STR;

} FTM2_C3VSTR;
extern volatile FTM2_C3VSTR _FTM2_C3V @0x000030CF;
#define FTM2_C3V                        _FTM2_C3V.Word


/*** FTM2_C4SC - Channel Status and Control; 0x000030D1 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_C4SCSTR;
extern volatile FTM2_C4SCSTR _FTM2_C4SC @0x000030D1;
#define FTM2_C4SC                       _FTM2_C4SC.Byte
#define FTM2_C4SC_ELSA                  _FTM2_C4SC.Bits.ELSA
#define FTM2_C4SC_ELSB                  _FTM2_C4SC.Bits.ELSB
#define FTM2_C4SC_MSA                   _FTM2_C4SC.Bits.MSA
#define FTM2_C4SC_MSB                   _FTM2_C4SC.Bits.MSB
#define FTM2_C4SC_CHIE                  _FTM2_C4SC.Bits.CHIE
#define FTM2_C4SC_CHF                   _FTM2_C4SC.Bits.CHF
#define FTM2_C4SC_ELSx                  _FTM2_C4SC.MergedBits.grpELSx
#define FTM2_C4SC_MSx                   _FTM2_C4SC.MergedBits.grpMSx

#define FTM2_C4SC_ELSA_MASK             4U
#define FTM2_C4SC_ELSB_MASK             8U
#define FTM2_C4SC_MSA_MASK              16U
#define FTM2_C4SC_MSB_MASK              32U
#define FTM2_C4SC_CHIE_MASK             64U
#define FTM2_C4SC_CHF_MASK              128U
#define FTM2_C4SC_ELSx_MASK             12U
#define FTM2_C4SC_ELSx_BITNUM           2U
#define FTM2_C4SC_MSx_MASK              48U
#define FTM2_C4SC_MSx_BITNUM            4U


/*** FTM2_C4V - FTM2 Timer Channel 4 Value Register; 0x000030D2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_C4VH - Channel Value High; 0x000030D2 ***/
    union {
      byte Byte;
    } FTM2_C4VHSTR;
    #define FTM2_C4VH                   _FTM2_C4V.Overlap_STR.FTM2_C4VHSTR.Byte
    

    /*** FTM2_C4VL - Channel Value Low; 0x000030D3 ***/
    union {
      byte Byte;
    } FTM2_C4VLSTR;
    #define FTM2_C4VL                   _FTM2_C4V.Overlap_STR.FTM2_C4VLSTR.Byte
    
  } Overlap_STR;

} FTM2_C4VSTR;
extern volatile FTM2_C4VSTR _FTM2_C4V @0x000030D2;
#define FTM2_C4V                        _FTM2_C4V.Word


/*** FTM2_C5SC - Channel Status and Control; 0x000030D4 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELSA        :1;                                       /* Edge or Level Select */
    byte ELSB        :1;                                       /* Edge or Level Select */
    byte MSA         :1;                                       /* Channel Mode Select */
    byte MSB         :1;                                       /* Channel Mode Select */
    byte CHIE        :1;                                       /* Channel Interrupt Enable */
    byte CHF         :1;                                       /* Channel Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELSx :2;
    byte grpMSx  :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_C5SCSTR;
extern volatile FTM2_C5SCSTR _FTM2_C5SC @0x000030D4;
#define FTM2_C5SC                       _FTM2_C5SC.Byte
#define FTM2_C5SC_ELSA                  _FTM2_C5SC.Bits.ELSA
#define FTM2_C5SC_ELSB                  _FTM2_C5SC.Bits.ELSB
#define FTM2_C5SC_MSA                   _FTM2_C5SC.Bits.MSA
#define FTM2_C5SC_MSB                   _FTM2_C5SC.Bits.MSB
#define FTM2_C5SC_CHIE                  _FTM2_C5SC.Bits.CHIE
#define FTM2_C5SC_CHF                   _FTM2_C5SC.Bits.CHF
#define FTM2_C5SC_ELSx                  _FTM2_C5SC.MergedBits.grpELSx
#define FTM2_C5SC_MSx                   _FTM2_C5SC.MergedBits.grpMSx

#define FTM2_C5SC_ELSA_MASK             4U
#define FTM2_C5SC_ELSB_MASK             8U
#define FTM2_C5SC_MSA_MASK              16U
#define FTM2_C5SC_MSB_MASK              32U
#define FTM2_C5SC_CHIE_MASK             64U
#define FTM2_C5SC_CHF_MASK              128U
#define FTM2_C5SC_ELSx_MASK             12U
#define FTM2_C5SC_ELSx_BITNUM           2U
#define FTM2_C5SC_MSx_MASK              48U
#define FTM2_C5SC_MSx_BITNUM            4U


/*** FTM2_C5V - FTM2 Timer Channel 5 Value Register; 0x000030D5 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_C5VH - Channel Value High; 0x000030D5 ***/
    union {
      byte Byte;
    } FTM2_C5VHSTR;
    #define FTM2_C5VH                   _FTM2_C5V.Overlap_STR.FTM2_C5VHSTR.Byte
    

    /*** FTM2_C5VL - Channel Value Low; 0x000030D6 ***/
    union {
      byte Byte;
    } FTM2_C5VLSTR;
    #define FTM2_C5VL                   _FTM2_C5V.Overlap_STR.FTM2_C5VLSTR.Byte
    
  } Overlap_STR;

} FTM2_C5VSTR;
extern volatile FTM2_C5VSTR _FTM2_C5V @0x000030D5;
#define FTM2_C5V                        _FTM2_C5V.Word


/*** FTM2_CNTIN - FTM2 Counter Initial Value Registers; 0x000030D7 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2_CNTINH - Counter Initial Value High; 0x000030D7 ***/
    union {
      byte Byte;
      struct {
        byte INIT_H0     :1;                                       /* Counter Initial Value High Byte, bit 0 */
        byte INIT_H1     :1;                                       /* Counter Initial Value High Byte, bit 1 */
        byte INIT_H2     :1;                                       /* Counter Initial Value High Byte, bit 2 */
        byte INIT_H3     :1;                                       /* Counter Initial Value High Byte, bit 3 */
        byte INIT_H4     :1;                                       /* Counter Initial Value High Byte, bit 4 */
        byte INIT_H5     :1;                                       /* Counter Initial Value High Byte, bit 5 */
        byte INIT_H6     :1;                                       /* Counter Initial Value High Byte, bit 6 */
        byte INIT_H7     :1;                                       /* Counter Initial Value High Byte, bit 7 */
      } Bits;
    } FTM2_CNTINHSTR;
    #define FTM2_CNTINH                 _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Byte
    #define FTM2_CNTINH_INIT_H0         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Bits.INIT_H0
    #define FTM2_CNTINH_INIT_H1         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Bits.INIT_H1
    #define FTM2_CNTINH_INIT_H2         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Bits.INIT_H2
    #define FTM2_CNTINH_INIT_H3         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Bits.INIT_H3
    #define FTM2_CNTINH_INIT_H4         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Bits.INIT_H4
    #define FTM2_CNTINH_INIT_H5         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Bits.INIT_H5
    #define FTM2_CNTINH_INIT_H6         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Bits.INIT_H6
    #define FTM2_CNTINH_INIT_H7         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINHSTR.Bits.INIT_H7
    
    #define FTM2_CNTINH_INIT_H0_MASK    1U
    #define FTM2_CNTINH_INIT_H1_MASK    2U
    #define FTM2_CNTINH_INIT_H2_MASK    4U
    #define FTM2_CNTINH_INIT_H3_MASK    8U
    #define FTM2_CNTINH_INIT_H4_MASK    16U
    #define FTM2_CNTINH_INIT_H5_MASK    32U
    #define FTM2_CNTINH_INIT_H6_MASK    64U
    #define FTM2_CNTINH_INIT_H7_MASK    128U
    

    /*** FTM2_CNTINL - Counter Initial Value Low; 0x000030D8 ***/
    union {
      byte Byte;
      struct {
        byte INIT_L0     :1;                                       /* Counter Initial Value Low Byte, bit 0 */
        byte INIT_L1     :1;                                       /* Counter Initial Value Low Byte, bit 1 */
        byte INIT_L2     :1;                                       /* Counter Initial Value Low Byte, bit 2 */
        byte INIT_L3     :1;                                       /* Counter Initial Value Low Byte, bit 3 */
        byte INIT_L4     :1;                                       /* Counter Initial Value Low Byte, bit 4 */
        byte INIT_L5     :1;                                       /* Counter Initial Value Low Byte, bit 5 */
        byte INIT_L6     :1;                                       /* Counter Initial Value Low Byte, bit 6 */
        byte INIT_L7     :1;                                       /* Counter Initial Value Low Byte, bit 7 */
      } Bits;
    } FTM2_CNTINLSTR;
    #define FTM2_CNTINL                 _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Byte
    #define FTM2_CNTINL_INIT_L0         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Bits.INIT_L0
    #define FTM2_CNTINL_INIT_L1         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Bits.INIT_L1
    #define FTM2_CNTINL_INIT_L2         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Bits.INIT_L2
    #define FTM2_CNTINL_INIT_L3         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Bits.INIT_L3
    #define FTM2_CNTINL_INIT_L4         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Bits.INIT_L4
    #define FTM2_CNTINL_INIT_L5         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Bits.INIT_L5
    #define FTM2_CNTINL_INIT_L6         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Bits.INIT_L6
    #define FTM2_CNTINL_INIT_L7         _FTM2_CNTIN.Overlap_STR.FTM2_CNTINLSTR.Bits.INIT_L7
    
    #define FTM2_CNTINL_INIT_L0_MASK    1U
    #define FTM2_CNTINL_INIT_L1_MASK    2U
    #define FTM2_CNTINL_INIT_L2_MASK    4U
    #define FTM2_CNTINL_INIT_L3_MASK    8U
    #define FTM2_CNTINL_INIT_L4_MASK    16U
    #define FTM2_CNTINL_INIT_L5_MASK    32U
    #define FTM2_CNTINL_INIT_L6_MASK    64U
    #define FTM2_CNTINL_INIT_L7_MASK    128U
    
  } Overlap_STR;

} FTM2_CNTINSTR;
extern volatile FTM2_CNTINSTR _FTM2_CNTIN @0x000030D7;
#define FTM2_CNTIN                      _FTM2_CNTIN.Word


/*** FTM2_STATUS - Capture and Compare Status; 0x000030D9 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0F        :1;                                       /* Channel 0 Flag */
    byte CH1F        :1;                                       /* Channel 1 Flag */
    byte CH2F        :1;                                       /* Channel 2 Flag */
    byte CH3F        :1;                                       /* Channel 3 Flag */
    byte CH4F        :1;                                       /* Channel 4 Flag */
    byte CH5F        :1;                                       /* Channel 5 Flag */
    byte CH6F        :1;                                       /* Channel 6 Flag */
    byte CH7F        :1;                                       /* Channel 7 Flag */
  } Bits;
} FTM2_STATUSSTR;
extern volatile FTM2_STATUSSTR _FTM2_STATUS @0x000030D9;
#define FTM2_STATUS                     _FTM2_STATUS.Byte
#define FTM2_STATUS_CH0F                _FTM2_STATUS.Bits.CH0F
#define FTM2_STATUS_CH1F                _FTM2_STATUS.Bits.CH1F
#define FTM2_STATUS_CH2F                _FTM2_STATUS.Bits.CH2F
#define FTM2_STATUS_CH3F                _FTM2_STATUS.Bits.CH3F
#define FTM2_STATUS_CH4F                _FTM2_STATUS.Bits.CH4F
#define FTM2_STATUS_CH5F                _FTM2_STATUS.Bits.CH5F
#define FTM2_STATUS_CH6F                _FTM2_STATUS.Bits.CH6F
#define FTM2_STATUS_CH7F                _FTM2_STATUS.Bits.CH7F

#define FTM2_STATUS_CH0F_MASK           1U
#define FTM2_STATUS_CH1F_MASK           2U
#define FTM2_STATUS_CH2F_MASK           4U
#define FTM2_STATUS_CH3F_MASK           8U
#define FTM2_STATUS_CH4F_MASK           16U
#define FTM2_STATUS_CH5F_MASK           32U
#define FTM2_STATUS_CH6F_MASK           64U
#define FTM2_STATUS_CH7F_MASK           128U


/*** FTM2_MODE - Features Mode Selection; 0x000030DA ***/
typedef union {
  byte Byte;
  struct {
    byte FTMEN       :1;                                       /* FTM Enable */
    byte INIT        :1;                                       /* Initialize the Output Channels */
    byte WPDIS       :1;                                       /* Write Protection Disable */
    byte PWMSYNC     :1;                                       /* PWM Synchronization Mode */
    byte CAPTEST     :1;                                       /* Capture Test Mode Enable */
    byte FAULTM0     :1;                                       /* Fault Control Mode, bit 0 */
    byte FAULTM1     :1;                                       /* Fault Control Mode, bit 1 */
    byte FAULTIE     :1;                                       /* Fault Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFAULTM :2;
    byte         :1;
  } MergedBits;
} FTM2_MODESTR;
extern volatile FTM2_MODESTR _FTM2_MODE @0x000030DA;
#define FTM2_MODE                       _FTM2_MODE.Byte
#define FTM2_MODE_FTMEN                 _FTM2_MODE.Bits.FTMEN
#define FTM2_MODE_INIT                  _FTM2_MODE.Bits.INIT
#define FTM2_MODE_WPDIS                 _FTM2_MODE.Bits.WPDIS
#define FTM2_MODE_PWMSYNC               _FTM2_MODE.Bits.PWMSYNC
#define FTM2_MODE_CAPTEST               _FTM2_MODE.Bits.CAPTEST
#define FTM2_MODE_FAULTM0               _FTM2_MODE.Bits.FAULTM0
#define FTM2_MODE_FAULTM1               _FTM2_MODE.Bits.FAULTM1
#define FTM2_MODE_FAULTIE               _FTM2_MODE.Bits.FAULTIE
#define FTM2_MODE_FAULTM                _FTM2_MODE.MergedBits.grpFAULTM

#define FTM2_MODE_FTMEN_MASK            1U
#define FTM2_MODE_INIT_MASK             2U
#define FTM2_MODE_WPDIS_MASK            4U
#define FTM2_MODE_PWMSYNC_MASK          8U
#define FTM2_MODE_CAPTEST_MASK          16U
#define FTM2_MODE_FAULTM0_MASK          32U
#define FTM2_MODE_FAULTM1_MASK          64U
#define FTM2_MODE_FAULTIE_MASK          128U
#define FTM2_MODE_FAULTM_MASK           96U
#define FTM2_MODE_FAULTM_BITNUM         5U


/*** FTM2_SYNC - Synchronization; 0x000030DB ***/
typedef union {
  byte Byte;
  struct {
    byte CNTMIN      :1;                                       /* Minimum Boundary Cycle Enable */
    byte CNTMAX      :1;                                       /* Maximum Boundary Cycle Enable */
    byte REINIT      :1;                                       /* FTM Counter Reinitialization by Synchronization (See "FTM Counter Synchronization") */
    byte SYNCHOM     :1;                                       /* Output Mask Synchronization */
    byte TRIG0       :1;                                       /* PWM Synchronization External Trigger 0 */
    byte TRIG1       :1;                                       /* PWM Synchronization External Trigger 1 */
    byte TRIG2       :1;                                       /* PWM Synchronization External Trigger 2 */
    byte SWSYNC      :1;                                       /* PWM Synchronization Software Trigger */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTRIG :3;
    byte         :1;
  } MergedBits;
} FTM2_SYNCSTR;
extern volatile FTM2_SYNCSTR _FTM2_SYNC @0x000030DB;
#define FTM2_SYNC                       _FTM2_SYNC.Byte
#define FTM2_SYNC_CNTMIN                _FTM2_SYNC.Bits.CNTMIN
#define FTM2_SYNC_CNTMAX                _FTM2_SYNC.Bits.CNTMAX
#define FTM2_SYNC_REINIT                _FTM2_SYNC.Bits.REINIT
#define FTM2_SYNC_SYNCHOM               _FTM2_SYNC.Bits.SYNCHOM
#define FTM2_SYNC_TRIG0                 _FTM2_SYNC.Bits.TRIG0
#define FTM2_SYNC_TRIG1                 _FTM2_SYNC.Bits.TRIG1
#define FTM2_SYNC_TRIG2                 _FTM2_SYNC.Bits.TRIG2
#define FTM2_SYNC_SWSYNC                _FTM2_SYNC.Bits.SWSYNC
#define FTM2_SYNC_TRIG                  _FTM2_SYNC.MergedBits.grpTRIG

#define FTM2_SYNC_CNTMIN_MASK           1U
#define FTM2_SYNC_CNTMAX_MASK           2U
#define FTM2_SYNC_REINIT_MASK           4U
#define FTM2_SYNC_SYNCHOM_MASK          8U
#define FTM2_SYNC_TRIG0_MASK            16U
#define FTM2_SYNC_TRIG1_MASK            32U
#define FTM2_SYNC_TRIG2_MASK            64U
#define FTM2_SYNC_SWSYNC_MASK           128U
#define FTM2_SYNC_TRIG_MASK             112U
#define FTM2_SYNC_TRIG_BITNUM           4U


/*** FTM2_OUTINIT - Initial State for Channel Output; 0x000030DC ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OI       :1;                                       /* Channel 0 Output Initialization Value */
    byte CH1OI       :1;                                       /* Channel 1 Output Initialization Value */
    byte CH2OI       :1;                                       /* Channel 2 Output Initialization Value */
    byte CH3OI       :1;                                       /* Channel 3 Output Initialization Value */
    byte CH4OI       :1;                                       /* Channel 4 Output Initialization Value */
    byte CH5OI       :1;                                       /* Channel 5 Output Initialization Value */
    byte CH6OI       :1;                                       /* Channel 6 Output Initialization Value */
    byte CH7OI       :1;                                       /* Channel 7 Output Initialization Value */
  } Bits;
} FTM2_OUTINITSTR;
extern volatile FTM2_OUTINITSTR _FTM2_OUTINIT @0x000030DC;
#define FTM2_OUTINIT                    _FTM2_OUTINIT.Byte
#define FTM2_OUTINIT_CH0OI              _FTM2_OUTINIT.Bits.CH0OI
#define FTM2_OUTINIT_CH1OI              _FTM2_OUTINIT.Bits.CH1OI
#define FTM2_OUTINIT_CH2OI              _FTM2_OUTINIT.Bits.CH2OI
#define FTM2_OUTINIT_CH3OI              _FTM2_OUTINIT.Bits.CH3OI
#define FTM2_OUTINIT_CH4OI              _FTM2_OUTINIT.Bits.CH4OI
#define FTM2_OUTINIT_CH5OI              _FTM2_OUTINIT.Bits.CH5OI
#define FTM2_OUTINIT_CH6OI              _FTM2_OUTINIT.Bits.CH6OI
#define FTM2_OUTINIT_CH7OI              _FTM2_OUTINIT.Bits.CH7OI

#define FTM2_OUTINIT_CH0OI_MASK         1U
#define FTM2_OUTINIT_CH1OI_MASK         2U
#define FTM2_OUTINIT_CH2OI_MASK         4U
#define FTM2_OUTINIT_CH3OI_MASK         8U
#define FTM2_OUTINIT_CH4OI_MASK         16U
#define FTM2_OUTINIT_CH5OI_MASK         32U
#define FTM2_OUTINIT_CH6OI_MASK         64U
#define FTM2_OUTINIT_CH7OI_MASK         128U


/*** FTM2_OUTMASK - Output Mask; 0x000030DD ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OM       :1;                                       /* Channel 0 Output Mask */
    byte CH1OM       :1;                                       /* Channel 1 Output Mask */
    byte CH2OM       :1;                                       /* Channel 2 Output Mask */
    byte CH3OM       :1;                                       /* Channel 3 Output Mask */
    byte CH4OM       :1;                                       /* Channel 4 Output Mask */
    byte CH5OM       :1;                                       /* Channel 5 Output Mask */
    byte CH6OM       :1;                                       /* Channel 6 Output Mask */
    byte CH7OM       :1;                                       /* Channel 7 Output Mask */
  } Bits;
} FTM2_OUTMASKSTR;
extern volatile FTM2_OUTMASKSTR _FTM2_OUTMASK @0x000030DD;
#define FTM2_OUTMASK                    _FTM2_OUTMASK.Byte
#define FTM2_OUTMASK_CH0OM              _FTM2_OUTMASK.Bits.CH0OM
#define FTM2_OUTMASK_CH1OM              _FTM2_OUTMASK.Bits.CH1OM
#define FTM2_OUTMASK_CH2OM              _FTM2_OUTMASK.Bits.CH2OM
#define FTM2_OUTMASK_CH3OM              _FTM2_OUTMASK.Bits.CH3OM
#define FTM2_OUTMASK_CH4OM              _FTM2_OUTMASK.Bits.CH4OM
#define FTM2_OUTMASK_CH5OM              _FTM2_OUTMASK.Bits.CH5OM
#define FTM2_OUTMASK_CH6OM              _FTM2_OUTMASK.Bits.CH6OM
#define FTM2_OUTMASK_CH7OM              _FTM2_OUTMASK.Bits.CH7OM

#define FTM2_OUTMASK_CH0OM_MASK         1U
#define FTM2_OUTMASK_CH1OM_MASK         2U
#define FTM2_OUTMASK_CH2OM_MASK         4U
#define FTM2_OUTMASK_CH3OM_MASK         8U
#define FTM2_OUTMASK_CH4OM_MASK         16U
#define FTM2_OUTMASK_CH5OM_MASK         32U
#define FTM2_OUTMASK_CH6OM_MASK         64U
#define FTM2_OUTMASK_CH7OM_MASK         128U


/*** FTM2_COMBINE0 - Function for Linked Channels; 0x000030DE ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Combine Channels */
    byte COMP        :1;                                       /* Complement of Channel (n) */
    byte DECAPEN     :1;                                       /* Dual Edge Capture Mode Enable */
    byte DECAP       :1;                                       /* Dual Edge Capture Mode Captures */
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2_COMBINE0STR;
extern volatile FTM2_COMBINE0STR _FTM2_COMBINE0 @0x000030DE;
#define FTM2_COMBINE0                   _FTM2_COMBINE0.Byte
#define FTM2_COMBINE0_COMBINE           _FTM2_COMBINE0.Bits.COMBINE
#define FTM2_COMBINE0_COMP              _FTM2_COMBINE0.Bits.COMP
#define FTM2_COMBINE0_DECAPEN           _FTM2_COMBINE0.Bits.DECAPEN
#define FTM2_COMBINE0_DECAP             _FTM2_COMBINE0.Bits.DECAP
#define FTM2_COMBINE0_DTEN              _FTM2_COMBINE0.Bits.DTEN
#define FTM2_COMBINE0_SYNCEN            _FTM2_COMBINE0.Bits.SYNCEN
#define FTM2_COMBINE0_FAULTEN           _FTM2_COMBINE0.Bits.FAULTEN
/* FTM2_COMBINE_ARR: Access 3 FTM2_COMBINEx registers in an array */
#define FTM2_COMBINE_ARR                ((volatile byte * __far) &FTM2_COMBINE0)

#define FTM2_COMBINE0_COMBINE_MASK      1U
#define FTM2_COMBINE0_COMP_MASK         2U
#define FTM2_COMBINE0_DECAPEN_MASK      4U
#define FTM2_COMBINE0_DECAP_MASK        8U
#define FTM2_COMBINE0_DTEN_MASK         16U
#define FTM2_COMBINE0_SYNCEN_MASK       32U
#define FTM2_COMBINE0_FAULTEN_MASK      64U


/*** FTM2_COMBINE1 - Function for Linked Channels; 0x000030DF ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Combine Channels */
    byte COMP        :1;                                       /* Complement of Channel (n) */
    byte DECAPEN     :1;                                       /* Dual Edge Capture Mode Enable */
    byte DECAP       :1;                                       /* Dual Edge Capture Mode Captures */
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2_COMBINE1STR;
extern volatile FTM2_COMBINE1STR _FTM2_COMBINE1 @0x000030DF;
#define FTM2_COMBINE1                   _FTM2_COMBINE1.Byte
#define FTM2_COMBINE1_COMBINE           _FTM2_COMBINE1.Bits.COMBINE
#define FTM2_COMBINE1_COMP              _FTM2_COMBINE1.Bits.COMP
#define FTM2_COMBINE1_DECAPEN           _FTM2_COMBINE1.Bits.DECAPEN
#define FTM2_COMBINE1_DECAP             _FTM2_COMBINE1.Bits.DECAP
#define FTM2_COMBINE1_DTEN              _FTM2_COMBINE1.Bits.DTEN
#define FTM2_COMBINE1_SYNCEN            _FTM2_COMBINE1.Bits.SYNCEN
#define FTM2_COMBINE1_FAULTEN           _FTM2_COMBINE1.Bits.FAULTEN

#define FTM2_COMBINE1_COMBINE_MASK      1U
#define FTM2_COMBINE1_COMP_MASK         2U
#define FTM2_COMBINE1_DECAPEN_MASK      4U
#define FTM2_COMBINE1_DECAP_MASK        8U
#define FTM2_COMBINE1_DTEN_MASK         16U
#define FTM2_COMBINE1_SYNCEN_MASK       32U
#define FTM2_COMBINE1_FAULTEN_MASK      64U


/*** FTM2_COMBINE2 - Function for Linked Channels; 0x000030E0 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Combine Channels */
    byte COMP        :1;                                       /* Complement of Channel (n) */
    byte DECAPEN     :1;                                       /* Dual Edge Capture Mode Enable */
    byte DECAP       :1;                                       /* Dual Edge Capture Mode Captures */
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2_COMBINE2STR;
extern volatile FTM2_COMBINE2STR _FTM2_COMBINE2 @0x000030E0;
#define FTM2_COMBINE2                   _FTM2_COMBINE2.Byte
#define FTM2_COMBINE2_COMBINE           _FTM2_COMBINE2.Bits.COMBINE
#define FTM2_COMBINE2_COMP              _FTM2_COMBINE2.Bits.COMP
#define FTM2_COMBINE2_DECAPEN           _FTM2_COMBINE2.Bits.DECAPEN
#define FTM2_COMBINE2_DECAP             _FTM2_COMBINE2.Bits.DECAP
#define FTM2_COMBINE2_DTEN              _FTM2_COMBINE2.Bits.DTEN
#define FTM2_COMBINE2_SYNCEN            _FTM2_COMBINE2.Bits.SYNCEN
#define FTM2_COMBINE2_FAULTEN           _FTM2_COMBINE2.Bits.FAULTEN

#define FTM2_COMBINE2_COMBINE_MASK      1U
#define FTM2_COMBINE2_COMP_MASK         2U
#define FTM2_COMBINE2_DECAPEN_MASK      4U
#define FTM2_COMBINE2_DECAP_MASK        8U
#define FTM2_COMBINE2_DTEN_MASK         16U
#define FTM2_COMBINE2_SYNCEN_MASK       32U
#define FTM2_COMBINE2_FAULTEN_MASK      64U


/*** FTM2_DEADTIME - Deadtime Insertion Control; 0x000030E2 ***/
typedef union {
  byte Byte;
  struct {
    byte DTVAL0      :1;                                       /* Deadtime Value, bit 0 */
    byte DTVAL1      :1;                                       /* Deadtime Value, bit 1 */
    byte DTVAL2      :1;                                       /* Deadtime Value, bit 2 */
    byte DTVAL3      :1;                                       /* Deadtime Value, bit 3 */
    byte DTVAL4      :1;                                       /* Deadtime Value, bit 4 */
    byte DTVAL5      :1;                                       /* Deadtime Value, bit 5 */
    byte DTPS0       :1;                                       /* Deadtime Prescaler Value, bit 0 */
    byte DTPS1       :1;                                       /* Deadtime Prescaler Value, bit 1 */
  } Bits;
  struct {
    byte grpDTVAL :6;
    byte grpDTPS :2;
  } MergedBits;
} FTM2_DEADTIMESTR;
extern volatile FTM2_DEADTIMESTR _FTM2_DEADTIME @0x000030E2;
#define FTM2_DEADTIME                   _FTM2_DEADTIME.Byte
#define FTM2_DEADTIME_DTVAL0            _FTM2_DEADTIME.Bits.DTVAL0
#define FTM2_DEADTIME_DTVAL1            _FTM2_DEADTIME.Bits.DTVAL1
#define FTM2_DEADTIME_DTVAL2            _FTM2_DEADTIME.Bits.DTVAL2
#define FTM2_DEADTIME_DTVAL3            _FTM2_DEADTIME.Bits.DTVAL3
#define FTM2_DEADTIME_DTVAL4            _FTM2_DEADTIME.Bits.DTVAL4
#define FTM2_DEADTIME_DTVAL5            _FTM2_DEADTIME.Bits.DTVAL5
#define FTM2_DEADTIME_DTPS0             _FTM2_DEADTIME.Bits.DTPS0
#define FTM2_DEADTIME_DTPS1             _FTM2_DEADTIME.Bits.DTPS1
#define FTM2_DEADTIME_DTVAL             _FTM2_DEADTIME.MergedBits.grpDTVAL
#define FTM2_DEADTIME_DTPS              _FTM2_DEADTIME.MergedBits.grpDTPS

#define FTM2_DEADTIME_DTVAL0_MASK       1U
#define FTM2_DEADTIME_DTVAL1_MASK       2U
#define FTM2_DEADTIME_DTVAL2_MASK       4U
#define FTM2_DEADTIME_DTVAL3_MASK       8U
#define FTM2_DEADTIME_DTVAL4_MASK       16U
#define FTM2_DEADTIME_DTVAL5_MASK       32U
#define FTM2_DEADTIME_DTPS0_MASK        64U
#define FTM2_DEADTIME_DTPS1_MASK        128U
#define FTM2_DEADTIME_DTVAL_MASK        63U
#define FTM2_DEADTIME_DTVAL_BITNUM      0U
#define FTM2_DEADTIME_DTPS_MASK         192U
#define FTM2_DEADTIME_DTPS_BITNUM       6U


/*** FTM2_EXTTRIG - External Trigger; 0x000030E3 ***/
typedef union {
  byte Byte;
  struct {
    byte CH2TRIG     :1;                                       /* Channel 2 Trigger Enable */
    byte CH3TRIG     :1;                                       /* Channel 3 Trigger Enable */
    byte CH4TRIG     :1;                                       /* Channel 4 Trigger Enable */
    byte CH5TRIG     :1;                                       /* Channel 5 Trigger Enable */
    byte CH0TRIG     :1;                                       /* Channel 0 Trigger Enable */
    byte CH1TRIG     :1;                                       /* Channel 1 Trigger Enable */
    byte INITTRIGEN  :1;                                       /* Initialization Trigger Enable */
    byte TRIGF       :1;                                       /* Channel Trigger Flag */
  } Bits;
} FTM2_EXTTRIGSTR;
extern volatile FTM2_EXTTRIGSTR _FTM2_EXTTRIG @0x000030E3;
#define FTM2_EXTTRIG                    _FTM2_EXTTRIG.Byte
#define FTM2_EXTTRIG_CH2TRIG            _FTM2_EXTTRIG.Bits.CH2TRIG
#define FTM2_EXTTRIG_CH3TRIG            _FTM2_EXTTRIG.Bits.CH3TRIG
#define FTM2_EXTTRIG_CH4TRIG            _FTM2_EXTTRIG.Bits.CH4TRIG
#define FTM2_EXTTRIG_CH5TRIG            _FTM2_EXTTRIG.Bits.CH5TRIG
#define FTM2_EXTTRIG_CH0TRIG            _FTM2_EXTTRIG.Bits.CH0TRIG
#define FTM2_EXTTRIG_CH1TRIG            _FTM2_EXTTRIG.Bits.CH1TRIG
#define FTM2_EXTTRIG_INITTRIGEN         _FTM2_EXTTRIG.Bits.INITTRIGEN
#define FTM2_EXTTRIG_TRIGF              _FTM2_EXTTRIG.Bits.TRIGF

#define FTM2_EXTTRIG_CH2TRIG_MASK       1U
#define FTM2_EXTTRIG_CH3TRIG_MASK       2U
#define FTM2_EXTTRIG_CH4TRIG_MASK       4U
#define FTM2_EXTTRIG_CH5TRIG_MASK       8U
#define FTM2_EXTTRIG_CH0TRIG_MASK       16U
#define FTM2_EXTTRIG_CH1TRIG_MASK       32U
#define FTM2_EXTTRIG_INITTRIGEN_MASK    64U
#define FTM2_EXTTRIG_TRIGF_MASK         128U


/*** FTM2_POL - Channels Polarity; 0x000030E4 ***/
typedef union {
  byte Byte;
  struct {
    byte POL0        :1;                                       /* Channel 0 Polarity */
    byte POL1        :1;                                       /* Channel 1 Polarity */
    byte POL2        :1;                                       /* Channel 2 Polarity */
    byte POL3        :1;                                       /* Channel 3 Polarity */
    byte POL4        :1;                                       /* Channel 4 Polarity */
    byte POL5        :1;                                       /* Channel 5 Polarity */
    byte POL6        :1;                                       /* Channel 6 Polarity */
    byte POL7        :1;                                       /* Channel 7 Polarity */
  } Bits;
} FTM2_POLSTR;
extern volatile FTM2_POLSTR _FTM2_POL @0x000030E4;
#define FTM2_POL                        _FTM2_POL.Byte
#define FTM2_POL_POL0                   _FTM2_POL.Bits.POL0
#define FTM2_POL_POL1                   _FTM2_POL.Bits.POL1
#define FTM2_POL_POL2                   _FTM2_POL.Bits.POL2
#define FTM2_POL_POL3                   _FTM2_POL.Bits.POL3
#define FTM2_POL_POL4                   _FTM2_POL.Bits.POL4
#define FTM2_POL_POL5                   _FTM2_POL.Bits.POL5
#define FTM2_POL_POL6                   _FTM2_POL.Bits.POL6
#define FTM2_POL_POL7                   _FTM2_POL.Bits.POL7

#define FTM2_POL_POL0_MASK              1U
#define FTM2_POL_POL1_MASK              2U
#define FTM2_POL_POL2_MASK              4U
#define FTM2_POL_POL3_MASK              8U
#define FTM2_POL_POL4_MASK              16U
#define FTM2_POL_POL5_MASK              32U
#define FTM2_POL_POL6_MASK              64U
#define FTM2_POL_POL7_MASK              128U


/*** FTM2_FMS - Fault Mode Status; 0x000030E5 ***/
typedef union {
  byte Byte;
  struct {
    byte FAULTF0     :1;                                       /* Fault Detection Flag 0 */
    byte FAULTF1     :1;                                       /* Fault Detection Flag 1 */
    byte FAULTF2     :1;                                       /* Fault Detection Flag 2 */
    byte FAULTF3     :1;                                       /* Fault Detection Flag 3 */
    byte             :1; 
    byte FAULTIN     :1;                                       /* Fault Inputs */
    byte WPEN        :1;                                       /* Write Protection Enable */
    byte FAULTF      :1;                                       /* Fault Detection Flag */
  } Bits;
  struct {
    byte         :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_FMSSTR;
extern volatile FTM2_FMSSTR _FTM2_FMS @0x000030E5;
#define FTM2_FMS                        _FTM2_FMS.Byte
#define FTM2_FMS_FAULTF0                _FTM2_FMS.Bits.FAULTF0
#define FTM2_FMS_FAULTF1                _FTM2_FMS.Bits.FAULTF1
#define FTM2_FMS_FAULTF2                _FTM2_FMS.Bits.FAULTF2
#define FTM2_FMS_FAULTF3                _FTM2_FMS.Bits.FAULTF3
#define FTM2_FMS_FAULTIN                _FTM2_FMS.Bits.FAULTIN
#define FTM2_FMS_WPEN                   _FTM2_FMS.Bits.WPEN
#define FTM2_FMS_FAULTF                 _FTM2_FMS.Bits.FAULTF

#define FTM2_FMS_FAULTF0_MASK           1U
#define FTM2_FMS_FAULTF1_MASK           2U
#define FTM2_FMS_FAULTF2_MASK           4U
#define FTM2_FMS_FAULTF3_MASK           8U
#define FTM2_FMS_FAULTIN_MASK           32U
#define FTM2_FMS_WPEN_MASK              64U
#define FTM2_FMS_FAULTF_MASK            128U


/*** FTM2_FILTER0 - Input Capture Filter Control; 0x000030E6 ***/
typedef union {
  byte Byte;
  struct {
    byte CHevenFVAL0 :1;                                       /* Input Filter for Even Channel, bit 0 */
    byte CHevenFVAL1 :1;                                       /* Input Filter for Even Channel, bit 1 */
    byte CHevenFVAL2 :1;                                       /* Input Filter for Even Channel, bit 2 */
    byte CHevenFVAL3 :1;                                       /* Input Filter for Even Channel, bit 3 */
    byte CHoddFVAL0  :1;                                       /* Input Filter for Odd Channel, bit 0 */
    byte CHoddFVAL1  :1;                                       /* Input Filter for Odd Channel, bit 1 */
    byte CHoddFVAL2  :1;                                       /* Input Filter for Odd Channel, bit 2 */
    byte CHoddFVAL3  :1;                                       /* Input Filter for Odd Channel, bit 3 */
  } Bits;
  struct {
    byte grpCHevenFVAL :4;
    byte grpCHoddFVAL :4;
  } MergedBits;
} FTM2_FILTER0STR;
extern volatile FTM2_FILTER0STR _FTM2_FILTER0 @0x000030E6;
#define FTM2_FILTER0                    _FTM2_FILTER0.Byte
#define FTM2_FILTER0_CHevenFVAL0        _FTM2_FILTER0.Bits.CHevenFVAL0
#define FTM2_FILTER0_CHevenFVAL1        _FTM2_FILTER0.Bits.CHevenFVAL1
#define FTM2_FILTER0_CHevenFVAL2        _FTM2_FILTER0.Bits.CHevenFVAL2
#define FTM2_FILTER0_CHevenFVAL3        _FTM2_FILTER0.Bits.CHevenFVAL3
#define FTM2_FILTER0_CHoddFVAL0         _FTM2_FILTER0.Bits.CHoddFVAL0
#define FTM2_FILTER0_CHoddFVAL1         _FTM2_FILTER0.Bits.CHoddFVAL1
#define FTM2_FILTER0_CHoddFVAL2         _FTM2_FILTER0.Bits.CHoddFVAL2
#define FTM2_FILTER0_CHoddFVAL3         _FTM2_FILTER0.Bits.CHoddFVAL3
/* FTM2_FILTER_ARR: Access 2 FTM2_FILTERx registers in an array */
#define FTM2_FILTER_ARR                 ((volatile byte * __far) &FTM2_FILTER0)
#define FTM2_FILTER0_CHevenFVAL         _FTM2_FILTER0.MergedBits.grpCHevenFVAL
#define FTM2_FILTER0_CHoddFVAL          _FTM2_FILTER0.MergedBits.grpCHoddFVAL

#define FTM2_FILTER0_CHevenFVAL0_MASK   1U
#define FTM2_FILTER0_CHevenFVAL1_MASK   2U
#define FTM2_FILTER0_CHevenFVAL2_MASK   4U
#define FTM2_FILTER0_CHevenFVAL3_MASK   8U
#define FTM2_FILTER0_CHoddFVAL0_MASK    16U
#define FTM2_FILTER0_CHoddFVAL1_MASK    32U
#define FTM2_FILTER0_CHoddFVAL2_MASK    64U
#define FTM2_FILTER0_CHoddFVAL3_MASK    128U
#define FTM2_FILTER0_CHevenFVAL_MASK    15U
#define FTM2_FILTER0_CHevenFVAL_BITNUM  0U
#define FTM2_FILTER0_CHoddFVAL_MASK     240U
#define FTM2_FILTER0_CHoddFVAL_BITNUM   4U


/*** FTM2_FILTER1 - Input Capture Filter Control; 0x000030E7 ***/
typedef union {
  byte Byte;
  struct {
    byte CHevenFVAL0 :1;                                       /* Input Filter for Even Channel, bit 0 */
    byte CHevenFVAL1 :1;                                       /* Input Filter for Even Channel, bit 1 */
    byte CHevenFVAL2 :1;                                       /* Input Filter for Even Channel, bit 2 */
    byte CHevenFVAL3 :1;                                       /* Input Filter for Even Channel, bit 3 */
    byte CHoddFVAL0  :1;                                       /* Input Filter for Odd Channel, bit 0 */
    byte CHoddFVAL1  :1;                                       /* Input Filter for Odd Channel, bit 1 */
    byte CHoddFVAL2  :1;                                       /* Input Filter for Odd Channel, bit 2 */
    byte CHoddFVAL3  :1;                                       /* Input Filter for Odd Channel, bit 3 */
  } Bits;
  struct {
    byte grpCHevenFVAL :4;
    byte grpCHoddFVAL :4;
  } MergedBits;
} FTM2_FILTER1STR;
extern volatile FTM2_FILTER1STR _FTM2_FILTER1 @0x000030E7;
#define FTM2_FILTER1                    _FTM2_FILTER1.Byte
#define FTM2_FILTER1_CHevenFVAL0        _FTM2_FILTER1.Bits.CHevenFVAL0
#define FTM2_FILTER1_CHevenFVAL1        _FTM2_FILTER1.Bits.CHevenFVAL1
#define FTM2_FILTER1_CHevenFVAL2        _FTM2_FILTER1.Bits.CHevenFVAL2
#define FTM2_FILTER1_CHevenFVAL3        _FTM2_FILTER1.Bits.CHevenFVAL3
#define FTM2_FILTER1_CHoddFVAL0         _FTM2_FILTER1.Bits.CHoddFVAL0
#define FTM2_FILTER1_CHoddFVAL1         _FTM2_FILTER1.Bits.CHoddFVAL1
#define FTM2_FILTER1_CHoddFVAL2         _FTM2_FILTER1.Bits.CHoddFVAL2
#define FTM2_FILTER1_CHoddFVAL3         _FTM2_FILTER1.Bits.CHoddFVAL3
#define FTM2_FILTER1_CHevenFVAL         _FTM2_FILTER1.MergedBits.grpCHevenFVAL
#define FTM2_FILTER1_CHoddFVAL          _FTM2_FILTER1.MergedBits.grpCHoddFVAL

#define FTM2_FILTER1_CHevenFVAL0_MASK   1U
#define FTM2_FILTER1_CHevenFVAL1_MASK   2U
#define FTM2_FILTER1_CHevenFVAL2_MASK   4U
#define FTM2_FILTER1_CHevenFVAL3_MASK   8U
#define FTM2_FILTER1_CHoddFVAL0_MASK    16U
#define FTM2_FILTER1_CHoddFVAL1_MASK    32U
#define FTM2_FILTER1_CHoddFVAL2_MASK    64U
#define FTM2_FILTER1_CHoddFVAL3_MASK    128U
#define FTM2_FILTER1_CHevenFVAL_MASK    15U
#define FTM2_FILTER1_CHevenFVAL_BITNUM  0U
#define FTM2_FILTER1_CHoddFVAL_MASK     240U
#define FTM2_FILTER1_CHoddFVAL_BITNUM   4U


/*** FTM2_FLTFILTER - Fault Input Filter Control; 0x000030E8 ***/
typedef union {
  byte Byte;
  struct {
    byte FFVAL0      :1;                                       /* Fault Input Filter, bit 0 */
    byte FFVAL1      :1;                                       /* Fault Input Filter, bit 1 */
    byte FFVAL2      :1;                                       /* Fault Input Filter, bit 2 */
    byte FFVAL3      :1;                                       /* Fault Input Filter, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFFVAL :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2_FLTFILTERSTR;
extern volatile FTM2_FLTFILTERSTR _FTM2_FLTFILTER @0x000030E8;
#define FTM2_FLTFILTER                  _FTM2_FLTFILTER.Byte
#define FTM2_FLTFILTER_FFVAL0           _FTM2_FLTFILTER.Bits.FFVAL0
#define FTM2_FLTFILTER_FFVAL1           _FTM2_FLTFILTER.Bits.FFVAL1
#define FTM2_FLTFILTER_FFVAL2           _FTM2_FLTFILTER.Bits.FFVAL2
#define FTM2_FLTFILTER_FFVAL3           _FTM2_FLTFILTER.Bits.FFVAL3
#define FTM2_FLTFILTER_FFVAL            _FTM2_FLTFILTER.MergedBits.grpFFVAL

#define FTM2_FLTFILTER_FFVAL0_MASK      1U
#define FTM2_FLTFILTER_FFVAL1_MASK      2U
#define FTM2_FLTFILTER_FFVAL2_MASK      4U
#define FTM2_FLTFILTER_FFVAL3_MASK      8U
#define FTM2_FLTFILTER_FFVAL_MASK       15U
#define FTM2_FLTFILTER_FFVAL_BITNUM     0U


/*** FTM2_FLTCTRL - Fault Input Control; 0x000030E9 ***/
typedef union {
  byte Byte;
  struct {
    byte FAULT0EN    :1;                                       /* Fault Input 0 Enable */
    byte FAULT1EN    :1;                                       /* Fault Input 1 Enable */
    byte FAULT2EN    :1;                                       /* Fault Input 2 Enable */
    byte FAULT3EN    :1;                                       /* Fault Input 3 Enable */
    byte FFLTR0EN    :1;                                       /* Fault Input 0 Filter Enable */
    byte FFLTR1EN    :1;                                       /* Fault Input 1 Filter Enable */
    byte FFLTR2EN    :1;                                       /* Fault Input 2 Filter Enable */
    byte FFLTR3EN    :1;                                       /* Fault Input 3 Filter Enable */
  } Bits;
} FTM2_FLTCTRLSTR;
extern volatile FTM2_FLTCTRLSTR _FTM2_FLTCTRL @0x000030E9;
#define FTM2_FLTCTRL                    _FTM2_FLTCTRL.Byte
#define FTM2_FLTCTRL_FAULT0EN           _FTM2_FLTCTRL.Bits.FAULT0EN
#define FTM2_FLTCTRL_FAULT1EN           _FTM2_FLTCTRL.Bits.FAULT1EN
#define FTM2_FLTCTRL_FAULT2EN           _FTM2_FLTCTRL.Bits.FAULT2EN
#define FTM2_FLTCTRL_FAULT3EN           _FTM2_FLTCTRL.Bits.FAULT3EN
#define FTM2_FLTCTRL_FFLTR0EN           _FTM2_FLTCTRL.Bits.FFLTR0EN
#define FTM2_FLTCTRL_FFLTR1EN           _FTM2_FLTCTRL.Bits.FFLTR1EN
#define FTM2_FLTCTRL_FFLTR2EN           _FTM2_FLTCTRL.Bits.FFLTR2EN
#define FTM2_FLTCTRL_FFLTR3EN           _FTM2_FLTCTRL.Bits.FFLTR3EN

#define FTM2_FLTCTRL_FAULT0EN_MASK      1U
#define FTM2_FLTCTRL_FAULT1EN_MASK      2U
#define FTM2_FLTCTRL_FAULT2EN_MASK      4U
#define FTM2_FLTCTRL_FAULT3EN_MASK      8U
#define FTM2_FLTCTRL_FFLTR0EN_MASK      16U
#define FTM2_FLTCTRL_FFLTR1EN_MASK      32U
#define FTM2_FLTCTRL_FFLTR2EN_MASK      64U
#define FTM2_FLTCTRL_FFLTR3EN_MASK      128U


/*** PORT_IOFLT0 - Port Filter Register 0; 0x000030EC ***/
typedef union {
  byte Byte;
  struct {
    byte FLTA0       :1;                                       /* Filter selection for input from PTA, bit 0 */
    byte FLTA1       :1;                                       /* Filter selection for input from PTA, bit 1 */
    byte FLTB0       :1;                                       /* Filter selection for input from PTB, bit 0 */
    byte FLTB1       :1;                                       /* Filter selection for input from PTB, bit 1 */
    byte FLTC0       :1;                                       /* Filter selection for input from PTC, bit 0 */
    byte FLTC1       :1;                                       /* Filter selection for input from PTC, bit 1 */
    byte FLTD0       :1;                                       /* Filter selection for input from PTD, bit 0 */
    byte FLTD1       :1;                                       /* Filter selection for input from PTD, bit 1 */
  } Bits;
  struct {
    byte grpFLTA :2;
    byte grpFLTB :2;
    byte grpFLTC :2;
    byte grpFLTD :2;
  } MergedBits;
} PORT_IOFLT0STR;
extern volatile PORT_IOFLT0STR _PORT_IOFLT0 @0x000030EC;
#define PORT_IOFLT0                     _PORT_IOFLT0.Byte
#define PORT_IOFLT0_FLTA0               _PORT_IOFLT0.Bits.FLTA0
#define PORT_IOFLT0_FLTA1               _PORT_IOFLT0.Bits.FLTA1
#define PORT_IOFLT0_FLTB0               _PORT_IOFLT0.Bits.FLTB0
#define PORT_IOFLT0_FLTB1               _PORT_IOFLT0.Bits.FLTB1
#define PORT_IOFLT0_FLTC0               _PORT_IOFLT0.Bits.FLTC0
#define PORT_IOFLT0_FLTC1               _PORT_IOFLT0.Bits.FLTC1
#define PORT_IOFLT0_FLTD0               _PORT_IOFLT0.Bits.FLTD0
#define PORT_IOFLT0_FLTD1               _PORT_IOFLT0.Bits.FLTD1
/* PORT_IOFLT_ARR: Access 3 PORT_IOFLTx registers in an array */
#define PORT_IOFLT_ARR                  ((volatile byte * __far) &PORT_IOFLT0)
#define PORT_IOFLT0_FLTA                _PORT_IOFLT0.MergedBits.grpFLTA
#define PORT_IOFLT0_FLTB                _PORT_IOFLT0.MergedBits.grpFLTB
#define PORT_IOFLT0_FLTC                _PORT_IOFLT0.MergedBits.grpFLTC
#define PORT_IOFLT0_FLTD                _PORT_IOFLT0.MergedBits.grpFLTD

#define PORT_IOFLT0_FLTA0_MASK          1U
#define PORT_IOFLT0_FLTA1_MASK          2U
#define PORT_IOFLT0_FLTB0_MASK          4U
#define PORT_IOFLT0_FLTB1_MASK          8U
#define PORT_IOFLT0_FLTC0_MASK          16U
#define PORT_IOFLT0_FLTC1_MASK          32U
#define PORT_IOFLT0_FLTD0_MASK          64U
#define PORT_IOFLT0_FLTD1_MASK          128U
#define PORT_IOFLT0_FLTA_MASK           3U
#define PORT_IOFLT0_FLTA_BITNUM         0U
#define PORT_IOFLT0_FLTB_MASK           12U
#define PORT_IOFLT0_FLTB_BITNUM         2U
#define PORT_IOFLT0_FLTC_MASK           48U
#define PORT_IOFLT0_FLTC_BITNUM         4U
#define PORT_IOFLT0_FLTD_MASK           192U
#define PORT_IOFLT0_FLTD_BITNUM         6U


/*** PORT_IOFLT1 - Port Filter Register 1; 0x000030ED ***/
typedef union {
  byte Byte;
  struct {
    byte FLTE0       :1;                                       /* Filter selection for input from PTE, bit 0 */
    byte FLTE1       :1;                                       /* Filter selection for input from PTE, bit 1 */
    byte FLTF0       :1;                                       /* Filter selection for input from PTF, bit 0 */
    byte FLTF1       :1;                                       /* Filter selection for input from PTF, bit 1 */
    byte FLTG0       :1;                                       /* Filter selection for input from PTG, bit 0 */
    byte FLTG1       :1;                                       /* Filter selection for input from PTG, bit 1 */
    byte FLTH0       :1;                                       /* Filter selection for input from PTH, bit 0 */
    byte FLTH1       :1;                                       /* Filter selection for input from PTH, bit 1 */
  } Bits;
  struct {
    byte grpFLTE :2;
    byte grpFLTF :2;
    byte grpFLTG :2;
    byte grpFLTH :2;
  } MergedBits;
} PORT_IOFLT1STR;
extern volatile PORT_IOFLT1STR _PORT_IOFLT1 @0x000030ED;
#define PORT_IOFLT1                     _PORT_IOFLT1.Byte
#define PORT_IOFLT1_FLTE0               _PORT_IOFLT1.Bits.FLTE0
#define PORT_IOFLT1_FLTE1               _PORT_IOFLT1.Bits.FLTE1
#define PORT_IOFLT1_FLTF0               _PORT_IOFLT1.Bits.FLTF0
#define PORT_IOFLT1_FLTF1               _PORT_IOFLT1.Bits.FLTF1
#define PORT_IOFLT1_FLTG0               _PORT_IOFLT1.Bits.FLTG0
#define PORT_IOFLT1_FLTG1               _PORT_IOFLT1.Bits.FLTG1
#define PORT_IOFLT1_FLTH0               _PORT_IOFLT1.Bits.FLTH0
#define PORT_IOFLT1_FLTH1               _PORT_IOFLT1.Bits.FLTH1
#define PORT_IOFLT1_FLTE                _PORT_IOFLT1.MergedBits.grpFLTE
#define PORT_IOFLT1_FLTF                _PORT_IOFLT1.MergedBits.grpFLTF
#define PORT_IOFLT1_FLTG                _PORT_IOFLT1.MergedBits.grpFLTG
#define PORT_IOFLT1_FLTH                _PORT_IOFLT1.MergedBits.grpFLTH

#define PORT_IOFLT1_FLTE0_MASK          1U
#define PORT_IOFLT1_FLTE1_MASK          2U
#define PORT_IOFLT1_FLTF0_MASK          4U
#define PORT_IOFLT1_FLTF1_MASK          8U
#define PORT_IOFLT1_FLTG0_MASK          16U
#define PORT_IOFLT1_FLTG1_MASK          32U
#define PORT_IOFLT1_FLTH0_MASK          64U
#define PORT_IOFLT1_FLTH1_MASK          128U
#define PORT_IOFLT1_FLTE_MASK           3U
#define PORT_IOFLT1_FLTE_BITNUM         0U
#define PORT_IOFLT1_FLTF_MASK           12U
#define PORT_IOFLT1_FLTF_BITNUM         2U
#define PORT_IOFLT1_FLTG_MASK           48U
#define PORT_IOFLT1_FLTG_BITNUM         4U
#define PORT_IOFLT1_FLTH_MASK           192U
#define PORT_IOFLT1_FLTH_BITNUM         6U


/*** PORT_IOFLT2 - Port Filter Register 2; 0x000030EE ***/
typedef union {
  byte Byte;
  struct {
    byte FLTRST0     :1;                                       /* Filter selection for input from RESET/IRQ, bit 0 */
    byte FLTRST1     :1;                                       /* Filter selection for input from RESET/IRQ, bit 1 */
    byte FLTKBI00    :1;                                       /* Filter selection for input from KBI0, bit 0 */
    byte FLTKBI01    :1;                                       /* Filter selection for input from KBI0, bit 1 */
    byte FLTKBI10    :1;                                       /* Filter selection for input from KBI1, bit 0 */
    byte FLTKBI11    :1;                                       /* Filter selection for input from KBI1, bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFLTRST :2;
    byte grpFLTKBI0 :2;
    byte grpFLTKBI1 :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} PORT_IOFLT2STR;
extern volatile PORT_IOFLT2STR _PORT_IOFLT2 @0x000030EE;
#define PORT_IOFLT2                     _PORT_IOFLT2.Byte
#define PORT_IOFLT2_FLTRST0             _PORT_IOFLT2.Bits.FLTRST0
#define PORT_IOFLT2_FLTRST1             _PORT_IOFLT2.Bits.FLTRST1
#define PORT_IOFLT2_FLTKBI00            _PORT_IOFLT2.Bits.FLTKBI00
#define PORT_IOFLT2_FLTKBI01            _PORT_IOFLT2.Bits.FLTKBI01
#define PORT_IOFLT2_FLTKBI10            _PORT_IOFLT2.Bits.FLTKBI10
#define PORT_IOFLT2_FLTKBI11            _PORT_IOFLT2.Bits.FLTKBI11
#define PORT_IOFLT2_FLTRST              _PORT_IOFLT2.MergedBits.grpFLTRST
#define PORT_IOFLT2_FLTKBI0             _PORT_IOFLT2.MergedBits.grpFLTKBI0
#define PORT_IOFLT2_FLTKBI1             _PORT_IOFLT2.MergedBits.grpFLTKBI1

#define PORT_IOFLT2_FLTRST0_MASK        1U
#define PORT_IOFLT2_FLTRST1_MASK        2U
#define PORT_IOFLT2_FLTKBI00_MASK       4U
#define PORT_IOFLT2_FLTKBI01_MASK       8U
#define PORT_IOFLT2_FLTKBI10_MASK       16U
#define PORT_IOFLT2_FLTKBI11_MASK       32U
#define PORT_IOFLT2_FLTRST_MASK         3U
#define PORT_IOFLT2_FLTRST_BITNUM       0U
#define PORT_IOFLT2_FLTKBI0_MASK        12U
#define PORT_IOFLT2_FLTKBI0_BITNUM      2U
#define PORT_IOFLT2_FLTKBI1_MASK        48U
#define PORT_IOFLT2_FLTKBI1_BITNUM      4U


/*** PORT_FCLKDIV - Port Clock Division Register; 0x000030EF ***/
typedef union {
  byte Byte;
  struct {
    byte FLTDIV10    :1;                                       /* , bit 0 */
    byte FLTDIV11    :1;                                       /* , bit 1 */
    byte FLTDIV20    :1;                                       /* , bit 0 */
    byte FLTDIV21    :1;                                       /* , bit 1 */
    byte FLTDIV22    :1;                                       /* , bit 2 */
    byte FLTDIV30    :1;                                       /* , bit 0 */
    byte FLTDIV31    :1;                                       /* , bit 1 */
    byte FLTDIV32    :1;                                       /* , bit 2 */
  } Bits;
  struct {
    byte grpFLTDIV1 :2;
    byte grpFLTDIV2 :3;
    byte grpFLTDIV3 :3;
  } MergedBits;
} PORT_FCLKDIVSTR;
extern volatile PORT_FCLKDIVSTR _PORT_FCLKDIV @0x000030EF;
#define PORT_FCLKDIV                    _PORT_FCLKDIV.Byte
#define PORT_FCLKDIV_FLTDIV10           _PORT_FCLKDIV.Bits.FLTDIV10
#define PORT_FCLKDIV_FLTDIV11           _PORT_FCLKDIV.Bits.FLTDIV11
#define PORT_FCLKDIV_FLTDIV20           _PORT_FCLKDIV.Bits.FLTDIV20
#define PORT_FCLKDIV_FLTDIV21           _PORT_FCLKDIV.Bits.FLTDIV21
#define PORT_FCLKDIV_FLTDIV22           _PORT_FCLKDIV.Bits.FLTDIV22
#define PORT_FCLKDIV_FLTDIV30           _PORT_FCLKDIV.Bits.FLTDIV30
#define PORT_FCLKDIV_FLTDIV31           _PORT_FCLKDIV.Bits.FLTDIV31
#define PORT_FCLKDIV_FLTDIV32           _PORT_FCLKDIV.Bits.FLTDIV32
#define PORT_FCLKDIV_FLTDIV1            _PORT_FCLKDIV.MergedBits.grpFLTDIV1
#define PORT_FCLKDIV_FLTDIV2            _PORT_FCLKDIV.MergedBits.grpFLTDIV2
#define PORT_FCLKDIV_FLTDIV3            _PORT_FCLKDIV.MergedBits.grpFLTDIV3

#define PORT_FCLKDIV_FLTDIV10_MASK      1U
#define PORT_FCLKDIV_FLTDIV11_MASK      2U
#define PORT_FCLKDIV_FLTDIV20_MASK      4U
#define PORT_FCLKDIV_FLTDIV21_MASK      8U
#define PORT_FCLKDIV_FLTDIV22_MASK      16U
#define PORT_FCLKDIV_FLTDIV30_MASK      32U
#define PORT_FCLKDIV_FLTDIV31_MASK      64U
#define PORT_FCLKDIV_FLTDIV32_MASK      128U
#define PORT_FCLKDIV_FLTDIV1_MASK       3U
#define PORT_FCLKDIV_FLTDIV1_BITNUM     0U
#define PORT_FCLKDIV_FLTDIV2_MASK       28U
#define PORT_FCLKDIV_FLTDIV2_BITNUM     2U
#define PORT_FCLKDIV_FLTDIV3_MASK       224U
#define PORT_FCLKDIV_FLTDIV3_BITNUM     5U


/*** PORT_PTAPE - Port A Pullup Enable Register; 0x000030F0 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Pull Enable for Port A Bit 3 */
    byte             :1; 
    byte PTAPE5      :1;                                       /* Pull Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Pull Enable for Port A Bit 7 */
  } Bits;
  struct {
    byte grpPTAPE :4;
    byte         :1;
    byte grpPTAPE_5 :3;
  } MergedBits;
} PORT_PTAPESTR;
extern volatile PORT_PTAPESTR _PORT_PTAPE @0x000030F0;
#define PORT_PTAPE                      _PORT_PTAPE.Byte
#define PORT_PTAPE_PTAPE0               _PORT_PTAPE.Bits.PTAPE0
#define PORT_PTAPE_PTAPE1               _PORT_PTAPE.Bits.PTAPE1
#define PORT_PTAPE_PTAPE2               _PORT_PTAPE.Bits.PTAPE2
#define PORT_PTAPE_PTAPE3               _PORT_PTAPE.Bits.PTAPE3
#define PORT_PTAPE_PTAPE5               _PORT_PTAPE.Bits.PTAPE5
#define PORT_PTAPE_PTAPE6               _PORT_PTAPE.Bits.PTAPE6
#define PORT_PTAPE_PTAPE7               _PORT_PTAPE.Bits.PTAPE7
#define PORT_PTAPE_PTAPE                _PORT_PTAPE.MergedBits.grpPTAPE
#define PORT_PTAPE_PTAPE_5              _PORT_PTAPE.MergedBits.grpPTAPE_5

#define PORT_PTAPE_PTAPE0_MASK          1U
#define PORT_PTAPE_PTAPE1_MASK          2U
#define PORT_PTAPE_PTAPE2_MASK          4U
#define PORT_PTAPE_PTAPE3_MASK          8U
#define PORT_PTAPE_PTAPE5_MASK          32U
#define PORT_PTAPE_PTAPE6_MASK          64U
#define PORT_PTAPE_PTAPE7_MASK          128U
#define PORT_PTAPE_PTAPE_MASK           15U
#define PORT_PTAPE_PTAPE_BITNUM         0U
#define PORT_PTAPE_PTAPE_5_MASK         224U
#define PORT_PTAPE_PTAPE_5_BITNUM       5U


/*** PORT_PTBPE - Port B Pullup Enable Register; 0x000030F1 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Pull Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Pull Enable for Port B Bit 2 */
    byte PTBPE3      :1;                                       /* Pull Enable for Port B Bit 3 */
    byte PTBPE4      :1;                                       /* Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Pull Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Pull Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Pull Enable for Port B Bit 7 */
  } Bits;
} PORT_PTBPESTR;
extern volatile PORT_PTBPESTR _PORT_PTBPE @0x000030F1;
#define PORT_PTBPE                      _PORT_PTBPE.Byte
#define PORT_PTBPE_PTBPE0               _PORT_PTBPE.Bits.PTBPE0
#define PORT_PTBPE_PTBPE1               _PORT_PTBPE.Bits.PTBPE1
#define PORT_PTBPE_PTBPE2               _PORT_PTBPE.Bits.PTBPE2
#define PORT_PTBPE_PTBPE3               _PORT_PTBPE.Bits.PTBPE3
#define PORT_PTBPE_PTBPE4               _PORT_PTBPE.Bits.PTBPE4
#define PORT_PTBPE_PTBPE5               _PORT_PTBPE.Bits.PTBPE5
#define PORT_PTBPE_PTBPE6               _PORT_PTBPE.Bits.PTBPE6
#define PORT_PTBPE_PTBPE7               _PORT_PTBPE.Bits.PTBPE7

#define PORT_PTBPE_PTBPE0_MASK          1U
#define PORT_PTBPE_PTBPE1_MASK          2U
#define PORT_PTBPE_PTBPE2_MASK          4U
#define PORT_PTBPE_PTBPE3_MASK          8U
#define PORT_PTBPE_PTBPE4_MASK          16U
#define PORT_PTBPE_PTBPE5_MASK          32U
#define PORT_PTBPE_PTBPE6_MASK          64U
#define PORT_PTBPE_PTBPE7_MASK          128U


/*** PORT_PTCPE - Port C Pullup Enable Register; 0x000030F2 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Pull Enable for Port C Bit 0 */
    byte PTCPE1      :1;                                       /* Pull Enable for Port C Bit 1 */
    byte PTCPE2      :1;                                       /* Pull Enable for Port C Bit 2 */
    byte PTCPE3      :1;                                       /* Pull Enable for Port C Bit 3 */
    byte PTCPE4      :1;                                       /* Pull Enable for Port C Bit 4 */
    byte PTCPE5      :1;                                       /* Pull Enable for Port C Bit 5 */
    byte PTCPE6      :1;                                       /* Pull Enable for Port C Bit 6 */
    byte PTCPE7      :1;                                       /* Pull Enable for Port C Bit 7 */
  } Bits;
} PORT_PTCPESTR;
extern volatile PORT_PTCPESTR _PORT_PTCPE @0x000030F2;
#define PORT_PTCPE                      _PORT_PTCPE.Byte
#define PORT_PTCPE_PTCPE0               _PORT_PTCPE.Bits.PTCPE0
#define PORT_PTCPE_PTCPE1               _PORT_PTCPE.Bits.PTCPE1
#define PORT_PTCPE_PTCPE2               _PORT_PTCPE.Bits.PTCPE2
#define PORT_PTCPE_PTCPE3               _PORT_PTCPE.Bits.PTCPE3
#define PORT_PTCPE_PTCPE4               _PORT_PTCPE.Bits.PTCPE4
#define PORT_PTCPE_PTCPE5               _PORT_PTCPE.Bits.PTCPE5
#define PORT_PTCPE_PTCPE6               _PORT_PTCPE.Bits.PTCPE6
#define PORT_PTCPE_PTCPE7               _PORT_PTCPE.Bits.PTCPE7

#define PORT_PTCPE_PTCPE0_MASK          1U
#define PORT_PTCPE_PTCPE1_MASK          2U
#define PORT_PTCPE_PTCPE2_MASK          4U
#define PORT_PTCPE_PTCPE3_MASK          8U
#define PORT_PTCPE_PTCPE4_MASK          16U
#define PORT_PTCPE_PTCPE5_MASK          32U
#define PORT_PTCPE_PTCPE6_MASK          64U
#define PORT_PTCPE_PTCPE7_MASK          128U


/*** PORT_PTDPE - Port D Pullup Enable Register; 0x000030F3 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDPE0      :1;                                       /* Pull Enable for Port D Bit 0 */
    byte PTDPE1      :1;                                       /* Pull Enable for Port D Bit 1 */
    byte PTDPE2      :1;                                       /* Pull Enable for Port D Bit 2 */
    byte PTDPE3      :1;                                       /* Pull Enable for Port D Bit 3 */
    byte PTDPE4      :1;                                       /* Pull Enable for Port D Bit 4 */
    byte PTDPE5      :1;                                       /* Pull Enable for Port D Bit 5 */
    byte PTDPE6      :1;                                       /* Pull Enable for Port D Bit 6 */
    byte PTDPE7      :1;                                       /* Pull Enable for Port D Bit 7 */
  } Bits;
} PORT_PTDPESTR;
extern volatile PORT_PTDPESTR _PORT_PTDPE @0x000030F3;
#define PORT_PTDPE                      _PORT_PTDPE.Byte
#define PORT_PTDPE_PTDPE0               _PORT_PTDPE.Bits.PTDPE0
#define PORT_PTDPE_PTDPE1               _PORT_PTDPE.Bits.PTDPE1
#define PORT_PTDPE_PTDPE2               _PORT_PTDPE.Bits.PTDPE2
#define PORT_PTDPE_PTDPE3               _PORT_PTDPE.Bits.PTDPE3
#define PORT_PTDPE_PTDPE4               _PORT_PTDPE.Bits.PTDPE4
#define PORT_PTDPE_PTDPE5               _PORT_PTDPE.Bits.PTDPE5
#define PORT_PTDPE_PTDPE6               _PORT_PTDPE.Bits.PTDPE6
#define PORT_PTDPE_PTDPE7               _PORT_PTDPE.Bits.PTDPE7

#define PORT_PTDPE_PTDPE0_MASK          1U
#define PORT_PTDPE_PTDPE1_MASK          2U
#define PORT_PTDPE_PTDPE2_MASK          4U
#define PORT_PTDPE_PTDPE3_MASK          8U
#define PORT_PTDPE_PTDPE4_MASK          16U
#define PORT_PTDPE_PTDPE5_MASK          32U
#define PORT_PTDPE_PTDPE6_MASK          64U
#define PORT_PTDPE_PTDPE7_MASK          128U


/*** PORT_PTEPE - Port E Pullup Enable Register; 0x000030F4 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEPE0      :1;                                       /* Pull Enable for Port E Bit 0 */
    byte PTEPE1      :1;                                       /* Pull Enable for Port E Bit 1 */
    byte PTEPE2      :1;                                       /* Pull Enable for Port E Bit 2 */
    byte PTEPE3      :1;                                       /* Pull Enable for Port E Bit 3 */
    byte PTEPE4      :1;                                       /* Pull Enable for Port E Bit 4 */
    byte PTEPE5      :1;                                       /* Pull Enable for Port E Bit 5 */
    byte PTEPE6      :1;                                       /* Pull Enable for Port E Bit 6 */
    byte PTEPE7      :1;                                       /* Pull Enable for Port E Bit 7 */
  } Bits;
} PORT_PTEPESTR;
extern volatile PORT_PTEPESTR _PORT_PTEPE @0x000030F4;
#define PORT_PTEPE                      _PORT_PTEPE.Byte
#define PORT_PTEPE_PTEPE0               _PORT_PTEPE.Bits.PTEPE0
#define PORT_PTEPE_PTEPE1               _PORT_PTEPE.Bits.PTEPE1
#define PORT_PTEPE_PTEPE2               _PORT_PTEPE.Bits.PTEPE2
#define PORT_PTEPE_PTEPE3               _PORT_PTEPE.Bits.PTEPE3
#define PORT_PTEPE_PTEPE4               _PORT_PTEPE.Bits.PTEPE4
#define PORT_PTEPE_PTEPE5               _PORT_PTEPE.Bits.PTEPE5
#define PORT_PTEPE_PTEPE6               _PORT_PTEPE.Bits.PTEPE6
#define PORT_PTEPE_PTEPE7               _PORT_PTEPE.Bits.PTEPE7

#define PORT_PTEPE_PTEPE0_MASK          1U
#define PORT_PTEPE_PTEPE1_MASK          2U
#define PORT_PTEPE_PTEPE2_MASK          4U
#define PORT_PTEPE_PTEPE3_MASK          8U
#define PORT_PTEPE_PTEPE4_MASK          16U
#define PORT_PTEPE_PTEPE5_MASK          32U
#define PORT_PTEPE_PTEPE6_MASK          64U
#define PORT_PTEPE_PTEPE7_MASK          128U


/*** PORT_PTFPE - Port F Pullup Enable Register; 0x000030F5 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFPE0      :1;                                       /* Pull Enable for Port F Bit 0 */
    byte PTFPE1      :1;                                       /* Pull Enable for Port F Bit 1 */
    byte PTFPE2      :1;                                       /* Pull Enable for Port F Bit 2 */
    byte PTFPE3      :1;                                       /* Pull Enable for Port F Bit 3 */
    byte PTFPE4      :1;                                       /* Pull Enable for Port F Bit 4 */
    byte PTFPE5      :1;                                       /* Pull Enable for Port F Bit 5 */
    byte PTFPE6      :1;                                       /* Pull Enable for Port F Bit 6 */
    byte PTFPE7      :1;                                       /* Pull Enable for Port F Bit 7 */
  } Bits;
} PORT_PTFPESTR;
extern volatile PORT_PTFPESTR _PORT_PTFPE @0x000030F5;
#define PORT_PTFPE                      _PORT_PTFPE.Byte
#define PORT_PTFPE_PTFPE0               _PORT_PTFPE.Bits.PTFPE0
#define PORT_PTFPE_PTFPE1               _PORT_PTFPE.Bits.PTFPE1
#define PORT_PTFPE_PTFPE2               _PORT_PTFPE.Bits.PTFPE2
#define PORT_PTFPE_PTFPE3               _PORT_PTFPE.Bits.PTFPE3
#define PORT_PTFPE_PTFPE4               _PORT_PTFPE.Bits.PTFPE4
#define PORT_PTFPE_PTFPE5               _PORT_PTFPE.Bits.PTFPE5
#define PORT_PTFPE_PTFPE6               _PORT_PTFPE.Bits.PTFPE6
#define PORT_PTFPE_PTFPE7               _PORT_PTFPE.Bits.PTFPE7

#define PORT_PTFPE_PTFPE0_MASK          1U
#define PORT_PTFPE_PTFPE1_MASK          2U
#define PORT_PTFPE_PTFPE2_MASK          4U
#define PORT_PTFPE_PTFPE3_MASK          8U
#define PORT_PTFPE_PTFPE4_MASK          16U
#define PORT_PTFPE_PTFPE5_MASK          32U
#define PORT_PTFPE_PTFPE6_MASK          64U
#define PORT_PTFPE_PTFPE7_MASK          128U


/*** PORT_PTGPE - Port G Pullup Enable Register; 0x000030F6 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGPE0      :1;                                       /* Pull Enable for Port G Bit 0 */
    byte PTGPE1      :1;                                       /* Pull Enable for Port G Bit 1 */
    byte PTGPE2      :1;                                       /* Pull Enable for Port G Bit 2 */
    byte PTGPE3      :1;                                       /* Pull Enable for Port G Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGPE :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PORT_PTGPESTR;
extern volatile PORT_PTGPESTR _PORT_PTGPE @0x000030F6;
#define PORT_PTGPE                      _PORT_PTGPE.Byte
#define PORT_PTGPE_PTGPE0               _PORT_PTGPE.Bits.PTGPE0
#define PORT_PTGPE_PTGPE1               _PORT_PTGPE.Bits.PTGPE1
#define PORT_PTGPE_PTGPE2               _PORT_PTGPE.Bits.PTGPE2
#define PORT_PTGPE_PTGPE3               _PORT_PTGPE.Bits.PTGPE3
#define PORT_PTGPE_PTGPE                _PORT_PTGPE.MergedBits.grpPTGPE

#define PORT_PTGPE_PTGPE0_MASK          1U
#define PORT_PTGPE_PTGPE1_MASK          2U
#define PORT_PTGPE_PTGPE2_MASK          4U
#define PORT_PTGPE_PTGPE3_MASK          8U
#define PORT_PTGPE_PTGPE_MASK           15U
#define PORT_PTGPE_PTGPE_BITNUM         0U


/*** PORT_PTHPE - Port H Pullup Enable Register; 0x000030F7 ***/
typedef union {
  byte Byte;
  struct {
    byte PTHPE0      :1;                                       /* Pull Enable for Port H Bit 0 */
    byte PTHPE1      :1;                                       /* Pull Enable for Port H Bit 1 */
    byte PTHPE2      :1;                                       /* Pull Enable for Port H Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTHPE6      :1;                                       /* Pull Enable for Port H Bit 6 */
    byte PTHPE7      :1;                                       /* Pull Enable for Port H Bit 7 */
  } Bits;
  struct {
    byte grpPTHPE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpPTHPE_6 :2;
  } MergedBits;
} PORT_PTHPESTR;
extern volatile PORT_PTHPESTR _PORT_PTHPE @0x000030F7;
#define PORT_PTHPE                      _PORT_PTHPE.Byte
#define PORT_PTHPE_PTHPE0               _PORT_PTHPE.Bits.PTHPE0
#define PORT_PTHPE_PTHPE1               _PORT_PTHPE.Bits.PTHPE1
#define PORT_PTHPE_PTHPE2               _PORT_PTHPE.Bits.PTHPE2
#define PORT_PTHPE_PTHPE6               _PORT_PTHPE.Bits.PTHPE6
#define PORT_PTHPE_PTHPE7               _PORT_PTHPE.Bits.PTHPE7
#define PORT_PTHPE_PTHPE                _PORT_PTHPE.MergedBits.grpPTHPE
#define PORT_PTHPE_PTHPE_6              _PORT_PTHPE.MergedBits.grpPTHPE_6

#define PORT_PTHPE_PTHPE0_MASK          1U
#define PORT_PTHPE_PTHPE1_MASK          2U
#define PORT_PTHPE_PTHPE2_MASK          4U
#define PORT_PTHPE_PTHPE6_MASK          64U
#define PORT_PTHPE_PTHPE7_MASK          128U
#define PORT_PTHPE_PTHPE_MASK           7U
#define PORT_PTHPE_PTHPE_BITNUM         0U
#define PORT_PTHPE_PTHPE_6_MASK         192U
#define PORT_PTHPE_PTHPE_6_BITNUM       6U


/*** SYS_UUID1 - Universally Unique Identifier Register 1; 0x000030F8 ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Universally Unique Identifier, bit 0 */
    byte ID1         :1;                                       /* Universally Unique Identifier, bit 1 */
    byte ID2         :1;                                       /* Universally Unique Identifier, bit 2 */
    byte ID3         :1;                                       /* Universally Unique Identifier, bit 3 */
    byte ID4         :1;                                       /* Universally Unique Identifier, bit 4 */
    byte ID5         :1;                                       /* Universally Unique Identifier, bit 5 */
    byte ID6         :1;                                       /* Universally Unique Identifier, bit 6 */
    byte ID7         :1;                                       /* Universally Unique Identifier, bit 7 */
  } Bits;
} SYS_UUID1STR;
extern volatile SYS_UUID1STR _SYS_UUID1 @0x000030F8;
#define SYS_UUID1                       _SYS_UUID1.Byte
#define SYS_UUID1_ID0                   _SYS_UUID1.Bits.ID0
#define SYS_UUID1_ID1                   _SYS_UUID1.Bits.ID1
#define SYS_UUID1_ID2                   _SYS_UUID1.Bits.ID2
#define SYS_UUID1_ID3                   _SYS_UUID1.Bits.ID3
#define SYS_UUID1_ID4                   _SYS_UUID1.Bits.ID4
#define SYS_UUID1_ID5                   _SYS_UUID1.Bits.ID5
#define SYS_UUID1_ID6                   _SYS_UUID1.Bits.ID6
#define SYS_UUID1_ID7                   _SYS_UUID1.Bits.ID7

#define SYS_UUID1_ID0_MASK              1U
#define SYS_UUID1_ID1_MASK              2U
#define SYS_UUID1_ID2_MASK              4U
#define SYS_UUID1_ID3_MASK              8U
#define SYS_UUID1_ID4_MASK              16U
#define SYS_UUID1_ID5_MASK              32U
#define SYS_UUID1_ID6_MASK              64U
#define SYS_UUID1_ID7_MASK              128U


/*** SYS_UUID2 - Universally Unique Identifier Register 2; 0x000030F9 ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Universally Unique Identifier, bit 0 */
    byte ID1         :1;                                       /* Universally Unique Identifier, bit 1 */
    byte ID2         :1;                                       /* Universally Unique Identifier, bit 2 */
    byte ID3         :1;                                       /* Universally Unique Identifier, bit 3 */
    byte ID4         :1;                                       /* Universally Unique Identifier, bit 4 */
    byte ID5         :1;                                       /* Universally Unique Identifier, bit 5 */
    byte ID6         :1;                                       /* Universally Unique Identifier, bit 6 */
    byte ID7         :1;                                       /* Universally Unique Identifier, bit 7 */
  } Bits;
} SYS_UUID2STR;
extern volatile SYS_UUID2STR _SYS_UUID2 @0x000030F9;
#define SYS_UUID2                       _SYS_UUID2.Byte
#define SYS_UUID2_ID0                   _SYS_UUID2.Bits.ID0
#define SYS_UUID2_ID1                   _SYS_UUID2.Bits.ID1
#define SYS_UUID2_ID2                   _SYS_UUID2.Bits.ID2
#define SYS_UUID2_ID3                   _SYS_UUID2.Bits.ID3
#define SYS_UUID2_ID4                   _SYS_UUID2.Bits.ID4
#define SYS_UUID2_ID5                   _SYS_UUID2.Bits.ID5
#define SYS_UUID2_ID6                   _SYS_UUID2.Bits.ID6
#define SYS_UUID2_ID7                   _SYS_UUID2.Bits.ID7

#define SYS_UUID2_ID0_MASK              1U
#define SYS_UUID2_ID1_MASK              2U
#define SYS_UUID2_ID2_MASK              4U
#define SYS_UUID2_ID3_MASK              8U
#define SYS_UUID2_ID4_MASK              16U
#define SYS_UUID2_ID5_MASK              32U
#define SYS_UUID2_ID6_MASK              64U
#define SYS_UUID2_ID7_MASK              128U


/*** SYS_UUID3 - Universally Unique Identifier Register 3; 0x000030FA ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Universally Unique Identifier, bit 0 */
    byte ID1         :1;                                       /* Universally Unique Identifier, bit 1 */
    byte ID2         :1;                                       /* Universally Unique Identifier, bit 2 */
    byte ID3         :1;                                       /* Universally Unique Identifier, bit 3 */
    byte ID4         :1;                                       /* Universally Unique Identifier, bit 4 */
    byte ID5         :1;                                       /* Universally Unique Identifier, bit 5 */
    byte ID6         :1;                                       /* Universally Unique Identifier, bit 6 */
    byte ID7         :1;                                       /* Universally Unique Identifier, bit 7 */
  } Bits;
} SYS_UUID3STR;
extern volatile SYS_UUID3STR _SYS_UUID3 @0x000030FA;
#define SYS_UUID3                       _SYS_UUID3.Byte
#define SYS_UUID3_ID0                   _SYS_UUID3.Bits.ID0
#define SYS_UUID3_ID1                   _SYS_UUID3.Bits.ID1
#define SYS_UUID3_ID2                   _SYS_UUID3.Bits.ID2
#define SYS_UUID3_ID3                   _SYS_UUID3.Bits.ID3
#define SYS_UUID3_ID4                   _SYS_UUID3.Bits.ID4
#define SYS_UUID3_ID5                   _SYS_UUID3.Bits.ID5
#define SYS_UUID3_ID6                   _SYS_UUID3.Bits.ID6
#define SYS_UUID3_ID7                   _SYS_UUID3.Bits.ID7

#define SYS_UUID3_ID0_MASK              1U
#define SYS_UUID3_ID1_MASK              2U
#define SYS_UUID3_ID2_MASK              4U
#define SYS_UUID3_ID3_MASK              8U
#define SYS_UUID3_ID4_MASK              16U
#define SYS_UUID3_ID5_MASK              32U
#define SYS_UUID3_ID6_MASK              64U
#define SYS_UUID3_ID7_MASK              128U


/*** SYS_UUID4 - Universally Unique Identifier Register 4; 0x000030FB ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Universally Unique Identifier, bit 0 */
    byte ID1         :1;                                       /* Universally Unique Identifier, bit 1 */
    byte ID2         :1;                                       /* Universally Unique Identifier, bit 2 */
    byte ID3         :1;                                       /* Universally Unique Identifier, bit 3 */
    byte ID4         :1;                                       /* Universally Unique Identifier, bit 4 */
    byte ID5         :1;                                       /* Universally Unique Identifier, bit 5 */
    byte ID6         :1;                                       /* Universally Unique Identifier, bit 6 */
    byte ID7         :1;                                       /* Universally Unique Identifier, bit 7 */
  } Bits;
} SYS_UUID4STR;
extern volatile SYS_UUID4STR _SYS_UUID4 @0x000030FB;
#define SYS_UUID4                       _SYS_UUID4.Byte
#define SYS_UUID4_ID0                   _SYS_UUID4.Bits.ID0
#define SYS_UUID4_ID1                   _SYS_UUID4.Bits.ID1
#define SYS_UUID4_ID2                   _SYS_UUID4.Bits.ID2
#define SYS_UUID4_ID3                   _SYS_UUID4.Bits.ID3
#define SYS_UUID4_ID4                   _SYS_UUID4.Bits.ID4
#define SYS_UUID4_ID5                   _SYS_UUID4.Bits.ID5
#define SYS_UUID4_ID6                   _SYS_UUID4.Bits.ID6
#define SYS_UUID4_ID7                   _SYS_UUID4.Bits.ID7

#define SYS_UUID4_ID0_MASK              1U
#define SYS_UUID4_ID1_MASK              2U
#define SYS_UUID4_ID2_MASK              4U
#define SYS_UUID4_ID3_MASK              8U
#define SYS_UUID4_ID4_MASK              16U
#define SYS_UUID4_ID5_MASK              32U
#define SYS_UUID4_ID6_MASK              64U
#define SYS_UUID4_ID7_MASK              128U


/*** SYS_UUID5 - Universally Unique Identifier Register 5; 0x000030FC ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Universally Unique Identifier, bit 0 */
    byte ID1         :1;                                       /* Universally Unique Identifier, bit 1 */
    byte ID2         :1;                                       /* Universally Unique Identifier, bit 2 */
    byte ID3         :1;                                       /* Universally Unique Identifier, bit 3 */
    byte ID4         :1;                                       /* Universally Unique Identifier, bit 4 */
    byte ID5         :1;                                       /* Universally Unique Identifier, bit 5 */
    byte ID6         :1;                                       /* Universally Unique Identifier, bit 6 */
    byte ID7         :1;                                       /* Universally Unique Identifier, bit 7 */
  } Bits;
} SYS_UUID5STR;
extern volatile SYS_UUID5STR _SYS_UUID5 @0x000030FC;
#define SYS_UUID5                       _SYS_UUID5.Byte
#define SYS_UUID5_ID0                   _SYS_UUID5.Bits.ID0
#define SYS_UUID5_ID1                   _SYS_UUID5.Bits.ID1
#define SYS_UUID5_ID2                   _SYS_UUID5.Bits.ID2
#define SYS_UUID5_ID3                   _SYS_UUID5.Bits.ID3
#define SYS_UUID5_ID4                   _SYS_UUID5.Bits.ID4
#define SYS_UUID5_ID5                   _SYS_UUID5.Bits.ID5
#define SYS_UUID5_ID6                   _SYS_UUID5.Bits.ID6
#define SYS_UUID5_ID7                   _SYS_UUID5.Bits.ID7

#define SYS_UUID5_ID0_MASK              1U
#define SYS_UUID5_ID1_MASK              2U
#define SYS_UUID5_ID2_MASK              4U
#define SYS_UUID5_ID3_MASK              8U
#define SYS_UUID5_ID4_MASK              16U
#define SYS_UUID5_ID5_MASK              32U
#define SYS_UUID5_ID6_MASK              64U
#define SYS_UUID5_ID7_MASK              128U


/*** SYS_UUID6 - Universally Unique Identifier Register 6; 0x000030FD ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Universally Unique Identifier, bit 0 */
    byte ID1         :1;                                       /* Universally Unique Identifier, bit 1 */
    byte ID2         :1;                                       /* Universally Unique Identifier, bit 2 */
    byte ID3         :1;                                       /* Universally Unique Identifier, bit 3 */
    byte ID4         :1;                                       /* Universally Unique Identifier, bit 4 */
    byte ID5         :1;                                       /* Universally Unique Identifier, bit 5 */
    byte ID6         :1;                                       /* Universally Unique Identifier, bit 6 */
    byte ID7         :1;                                       /* Universally Unique Identifier, bit 7 */
  } Bits;
} SYS_UUID6STR;
extern volatile SYS_UUID6STR _SYS_UUID6 @0x000030FD;
#define SYS_UUID6                       _SYS_UUID6.Byte
#define SYS_UUID6_ID0                   _SYS_UUID6.Bits.ID0
#define SYS_UUID6_ID1                   _SYS_UUID6.Bits.ID1
#define SYS_UUID6_ID2                   _SYS_UUID6.Bits.ID2
#define SYS_UUID6_ID3                   _SYS_UUID6.Bits.ID3
#define SYS_UUID6_ID4                   _SYS_UUID6.Bits.ID4
#define SYS_UUID6_ID5                   _SYS_UUID6.Bits.ID5
#define SYS_UUID6_ID6                   _SYS_UUID6.Bits.ID6
#define SYS_UUID6_ID7                   _SYS_UUID6.Bits.ID7

#define SYS_UUID6_ID0_MASK              1U
#define SYS_UUID6_ID1_MASK              2U
#define SYS_UUID6_ID2_MASK              4U
#define SYS_UUID6_ID3_MASK              8U
#define SYS_UUID6_ID4_MASK              16U
#define SYS_UUID6_ID5_MASK              32U
#define SYS_UUID6_ID6_MASK              64U
#define SYS_UUID6_ID7_MASK              128U


/*** SYS_UUID7 - Universally Unique Identifier Register 7; 0x000030FE ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Universally Unique Identifier, bit 0 */
    byte ID1         :1;                                       /* Universally Unique Identifier, bit 1 */
    byte ID2         :1;                                       /* Universally Unique Identifier, bit 2 */
    byte ID3         :1;                                       /* Universally Unique Identifier, bit 3 */
    byte ID4         :1;                                       /* Universally Unique Identifier, bit 4 */
    byte ID5         :1;                                       /* Universally Unique Identifier, bit 5 */
    byte ID6         :1;                                       /* Universally Unique Identifier, bit 6 */
    byte ID7         :1;                                       /* Universally Unique Identifier, bit 7 */
  } Bits;
} SYS_UUID7STR;
extern volatile SYS_UUID7STR _SYS_UUID7 @0x000030FE;
#define SYS_UUID7                       _SYS_UUID7.Byte
#define SYS_UUID7_ID0                   _SYS_UUID7.Bits.ID0
#define SYS_UUID7_ID1                   _SYS_UUID7.Bits.ID1
#define SYS_UUID7_ID2                   _SYS_UUID7.Bits.ID2
#define SYS_UUID7_ID3                   _SYS_UUID7.Bits.ID3
#define SYS_UUID7_ID4                   _SYS_UUID7.Bits.ID4
#define SYS_UUID7_ID5                   _SYS_UUID7.Bits.ID5
#define SYS_UUID7_ID6                   _SYS_UUID7.Bits.ID6
#define SYS_UUID7_ID7                   _SYS_UUID7.Bits.ID7

#define SYS_UUID7_ID0_MASK              1U
#define SYS_UUID7_ID1_MASK              2U
#define SYS_UUID7_ID2_MASK              4U
#define SYS_UUID7_ID3_MASK              8U
#define SYS_UUID7_ID4_MASK              16U
#define SYS_UUID7_ID5_MASK              32U
#define SYS_UUID7_ID6_MASK              64U
#define SYS_UUID7_ID7_MASK              128U


/*** SYS_UUID8 - Universally Unique Identifier Register 8; 0x000030FF ***/
typedef union {
  byte Byte;
  struct {
    byte ID0         :1;                                       /* Universally Unique Identifier, bit 0 */
    byte ID1         :1;                                       /* Universally Unique Identifier, bit 1 */
    byte ID2         :1;                                       /* Universally Unique Identifier, bit 2 */
    byte ID3         :1;                                       /* Universally Unique Identifier, bit 3 */
    byte ID4         :1;                                       /* Universally Unique Identifier, bit 4 */
    byte ID5         :1;                                       /* Universally Unique Identifier, bit 5 */
    byte ID6         :1;                                       /* Universally Unique Identifier, bit 6 */
    byte ID7         :1;                                       /* Universally Unique Identifier, bit 7 */
  } Bits;
} SYS_UUID8STR;
extern volatile SYS_UUID8STR _SYS_UUID8 @0x000030FF;
#define SYS_UUID8                       _SYS_UUID8.Byte
#define SYS_UUID8_ID0                   _SYS_UUID8.Bits.ID0
#define SYS_UUID8_ID1                   _SYS_UUID8.Bits.ID1
#define SYS_UUID8_ID2                   _SYS_UUID8.Bits.ID2
#define SYS_UUID8_ID3                   _SYS_UUID8.Bits.ID3
#define SYS_UUID8_ID4                   _SYS_UUID8.Bits.ID4
#define SYS_UUID8_ID5                   _SYS_UUID8.Bits.ID5
#define SYS_UUID8_ID6                   _SYS_UUID8.Bits.ID6
#define SYS_UUID8_ID7                   _SYS_UUID8.Bits.ID7

#define SYS_UUID8_ID0_MASK              1U
#define SYS_UUID8_ID1_MASK              2U
#define SYS_UUID8_ID2_MASK              4U
#define SYS_UUID8_ID3_MASK              8U
#define SYS_UUID8_ID4_MASK              16U
#define SYS_UUID8_ID5_MASK              32U
#define SYS_UUID8_ID6_MASK              64U
#define SYS_UUID8_ID7_MASK              128U


/*** NV_BACKKEY0 - Back Door Key Register n; 0x0000FF70 ***/
typedef union {
  byte Byte;
  struct {
    byte BACKKEY0    :1;                                       /* Back Door Key, bit 0 */
    byte BACKKEY1    :1;                                       /* Back Door Key, bit 1 */
    byte BACKKEY2    :1;                                       /* Back Door Key, bit 2 */
    byte BACKKEY3    :1;                                       /* Back Door Key, bit 3 */
    byte BACKKEY4    :1;                                       /* Back Door Key, bit 4 */
    byte BACKKEY5    :1;                                       /* Back Door Key, bit 5 */
    byte BACKKEY6    :1;                                       /* Back Door Key, bit 6 */
    byte BACKKEY7    :1;                                       /* Back Door Key, bit 7 */
  } Bits;
} NV_BACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NV_BACKKEY0_INIT @0x0000FF70 = <NV_BACKKEY0_INITVAL>; */
#define _NV_BACKKEY0 (*(const NV_BACKKEY0STR * __far)0x0000FF70)
#define NV_BACKKEY0                     _NV_BACKKEY0.Byte
#define NV_BACKKEY0_BACKKEY0            _NV_BACKKEY0.Bits.BACKKEY0
#define NV_BACKKEY0_BACKKEY1            _NV_BACKKEY0.Bits.BACKKEY1
#define NV_BACKKEY0_BACKKEY2            _NV_BACKKEY0.Bits.BACKKEY2
#define NV_BACKKEY0_BACKKEY3            _NV_BACKKEY0.Bits.BACKKEY3
#define NV_BACKKEY0_BACKKEY4            _NV_BACKKEY0.Bits.BACKKEY4
#define NV_BACKKEY0_BACKKEY5            _NV_BACKKEY0.Bits.BACKKEY5
#define NV_BACKKEY0_BACKKEY6            _NV_BACKKEY0.Bits.BACKKEY6
#define NV_BACKKEY0_BACKKEY7            _NV_BACKKEY0.Bits.BACKKEY7
/* NV_BACKKEY_ARR: Access 8 NV_BACKKEYx registers in an array */
#define NV_BACKKEY_ARR                  ((volatile byte * __far) &NV_BACKKEY0)

#define NV_BACKKEY0_BACKKEY0_MASK       1U
#define NV_BACKKEY0_BACKKEY1_MASK       2U
#define NV_BACKKEY0_BACKKEY2_MASK       4U
#define NV_BACKKEY0_BACKKEY3_MASK       8U
#define NV_BACKKEY0_BACKKEY4_MASK       16U
#define NV_BACKKEY0_BACKKEY5_MASK       32U
#define NV_BACKKEY0_BACKKEY6_MASK       64U
#define NV_BACKKEY0_BACKKEY7_MASK       128U


/*** NV_BACKKEY1 - Back Door Key Register n; 0x0000FF71 ***/
typedef union {
  byte Byte;
  struct {
    byte BACKKEY0    :1;                                       /* Back Door Key, bit 0 */
    byte BACKKEY1    :1;                                       /* Back Door Key, bit 1 */
    byte BACKKEY2    :1;                                       /* Back Door Key, bit 2 */
    byte BACKKEY3    :1;                                       /* Back Door Key, bit 3 */
    byte BACKKEY4    :1;                                       /* Back Door Key, bit 4 */
    byte BACKKEY5    :1;                                       /* Back Door Key, bit 5 */
    byte BACKKEY6    :1;                                       /* Back Door Key, bit 6 */
    byte BACKKEY7    :1;                                       /* Back Door Key, bit 7 */
  } Bits;
} NV_BACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NV_BACKKEY1_INIT @0x0000FF71 = <NV_BACKKEY1_INITVAL>; */
#define _NV_BACKKEY1 (*(const NV_BACKKEY1STR * __far)0x0000FF71)
#define NV_BACKKEY1                     _NV_BACKKEY1.Byte
#define NV_BACKKEY1_BACKKEY0            _NV_BACKKEY1.Bits.BACKKEY0
#define NV_BACKKEY1_BACKKEY1            _NV_BACKKEY1.Bits.BACKKEY1
#define NV_BACKKEY1_BACKKEY2            _NV_BACKKEY1.Bits.BACKKEY2
#define NV_BACKKEY1_BACKKEY3            _NV_BACKKEY1.Bits.BACKKEY3
#define NV_BACKKEY1_BACKKEY4            _NV_BACKKEY1.Bits.BACKKEY4
#define NV_BACKKEY1_BACKKEY5            _NV_BACKKEY1.Bits.BACKKEY5
#define NV_BACKKEY1_BACKKEY6            _NV_BACKKEY1.Bits.BACKKEY6
#define NV_BACKKEY1_BACKKEY7            _NV_BACKKEY1.Bits.BACKKEY7

#define NV_BACKKEY1_BACKKEY0_MASK       1U
#define NV_BACKKEY1_BACKKEY1_MASK       2U
#define NV_BACKKEY1_BACKKEY2_MASK       4U
#define NV_BACKKEY1_BACKKEY3_MASK       8U
#define NV_BACKKEY1_BACKKEY4_MASK       16U
#define NV_BACKKEY1_BACKKEY5_MASK       32U
#define NV_BACKKEY1_BACKKEY6_MASK       64U
#define NV_BACKKEY1_BACKKEY7_MASK       128U


/*** NV_BACKKEY2 - Back Door Key Register n; 0x0000FF72 ***/
typedef union {
  byte Byte;
  struct {
    byte BACKKEY0    :1;                                       /* Back Door Key, bit 0 */
    byte BACKKEY1    :1;                                       /* Back Door Key, bit 1 */
    byte BACKKEY2    :1;                                       /* Back Door Key, bit 2 */
    byte BACKKEY3    :1;                                       /* Back Door Key, bit 3 */
    byte BACKKEY4    :1;                                       /* Back Door Key, bit 4 */
    byte BACKKEY5    :1;                                       /* Back Door Key, bit 5 */
    byte BACKKEY6    :1;                                       /* Back Door Key, bit 6 */
    byte BACKKEY7    :1;                                       /* Back Door Key, bit 7 */
  } Bits;
} NV_BACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NV_BACKKEY2_INIT @0x0000FF72 = <NV_BACKKEY2_INITVAL>; */
#define _NV_BACKKEY2 (*(const NV_BACKKEY2STR * __far)0x0000FF72)
#define NV_BACKKEY2                     _NV_BACKKEY2.Byte
#define NV_BACKKEY2_BACKKEY0            _NV_BACKKEY2.Bits.BACKKEY0
#define NV_BACKKEY2_BACKKEY1            _NV_BACKKEY2.Bits.BACKKEY1
#define NV_BACKKEY2_BACKKEY2            _NV_BACKKEY2.Bits.BACKKEY2
#define NV_BACKKEY2_BACKKEY3            _NV_BACKKEY2.Bits.BACKKEY3
#define NV_BACKKEY2_BACKKEY4            _NV_BACKKEY2.Bits.BACKKEY4
#define NV_BACKKEY2_BACKKEY5            _NV_BACKKEY2.Bits.BACKKEY5
#define NV_BACKKEY2_BACKKEY6            _NV_BACKKEY2.Bits.BACKKEY6
#define NV_BACKKEY2_BACKKEY7            _NV_BACKKEY2.Bits.BACKKEY7

#define NV_BACKKEY2_BACKKEY0_MASK       1U
#define NV_BACKKEY2_BACKKEY1_MASK       2U
#define NV_BACKKEY2_BACKKEY2_MASK       4U
#define NV_BACKKEY2_BACKKEY3_MASK       8U
#define NV_BACKKEY2_BACKKEY4_MASK       16U
#define NV_BACKKEY2_BACKKEY5_MASK       32U
#define NV_BACKKEY2_BACKKEY6_MASK       64U
#define NV_BACKKEY2_BACKKEY7_MASK       128U


/*** NV_BACKKEY3 - Back Door Key Register n; 0x0000FF73 ***/
typedef union {
  byte Byte;
  struct {
    byte BACKKEY0    :1;                                       /* Back Door Key, bit 0 */
    byte BACKKEY1    :1;                                       /* Back Door Key, bit 1 */
    byte BACKKEY2    :1;                                       /* Back Door Key, bit 2 */
    byte BACKKEY3    :1;                                       /* Back Door Key, bit 3 */
    byte BACKKEY4    :1;                                       /* Back Door Key, bit 4 */
    byte BACKKEY5    :1;                                       /* Back Door Key, bit 5 */
    byte BACKKEY6    :1;                                       /* Back Door Key, bit 6 */
    byte BACKKEY7    :1;                                       /* Back Door Key, bit 7 */
  } Bits;
} NV_BACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NV_BACKKEY3_INIT @0x0000FF73 = <NV_BACKKEY3_INITVAL>; */
#define _NV_BACKKEY3 (*(const NV_BACKKEY3STR * __far)0x0000FF73)
#define NV_BACKKEY3                     _NV_BACKKEY3.Byte
#define NV_BACKKEY3_BACKKEY0            _NV_BACKKEY3.Bits.BACKKEY0
#define NV_BACKKEY3_BACKKEY1            _NV_BACKKEY3.Bits.BACKKEY1
#define NV_BACKKEY3_BACKKEY2            _NV_BACKKEY3.Bits.BACKKEY2
#define NV_BACKKEY3_BACKKEY3            _NV_BACKKEY3.Bits.BACKKEY3
#define NV_BACKKEY3_BACKKEY4            _NV_BACKKEY3.Bits.BACKKEY4
#define NV_BACKKEY3_BACKKEY5            _NV_BACKKEY3.Bits.BACKKEY5
#define NV_BACKKEY3_BACKKEY6            _NV_BACKKEY3.Bits.BACKKEY6
#define NV_BACKKEY3_BACKKEY7            _NV_BACKKEY3.Bits.BACKKEY7

#define NV_BACKKEY3_BACKKEY0_MASK       1U
#define NV_BACKKEY3_BACKKEY1_MASK       2U
#define NV_BACKKEY3_BACKKEY2_MASK       4U
#define NV_BACKKEY3_BACKKEY3_MASK       8U
#define NV_BACKKEY3_BACKKEY4_MASK       16U
#define NV_BACKKEY3_BACKKEY5_MASK       32U
#define NV_BACKKEY3_BACKKEY6_MASK       64U
#define NV_BACKKEY3_BACKKEY7_MASK       128U


/*** NV_BACKKEY4 - Back Door Key Register n; 0x0000FF74 ***/
typedef union {
  byte Byte;
  struct {
    byte BACKKEY0    :1;                                       /* Back Door Key, bit 0 */
    byte BACKKEY1    :1;                                       /* Back Door Key, bit 1 */
    byte BACKKEY2    :1;                                       /* Back Door Key, bit 2 */
    byte BACKKEY3    :1;                                       /* Back Door Key, bit 3 */
    byte BACKKEY4    :1;                                       /* Back Door Key, bit 4 */
    byte BACKKEY5    :1;                                       /* Back Door Key, bit 5 */
    byte BACKKEY6    :1;                                       /* Back Door Key, bit 6 */
    byte BACKKEY7    :1;                                       /* Back Door Key, bit 7 */
  } Bits;
} NV_BACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NV_BACKKEY4_INIT @0x0000FF74 = <NV_BACKKEY4_INITVAL>; */
#define _NV_BACKKEY4 (*(const NV_BACKKEY4STR * __far)0x0000FF74)
#define NV_BACKKEY4                     _NV_BACKKEY4.Byte
#define NV_BACKKEY4_BACKKEY0            _NV_BACKKEY4.Bits.BACKKEY0
#define NV_BACKKEY4_BACKKEY1            _NV_BACKKEY4.Bits.BACKKEY1
#define NV_BACKKEY4_BACKKEY2            _NV_BACKKEY4.Bits.BACKKEY2
#define NV_BACKKEY4_BACKKEY3            _NV_BACKKEY4.Bits.BACKKEY3
#define NV_BACKKEY4_BACKKEY4            _NV_BACKKEY4.Bits.BACKKEY4
#define NV_BACKKEY4_BACKKEY5            _NV_BACKKEY4.Bits.BACKKEY5
#define NV_BACKKEY4_BACKKEY6            _NV_BACKKEY4.Bits.BACKKEY6
#define NV_BACKKEY4_BACKKEY7            _NV_BACKKEY4.Bits.BACKKEY7

#define NV_BACKKEY4_BACKKEY0_MASK       1U
#define NV_BACKKEY4_BACKKEY1_MASK       2U
#define NV_BACKKEY4_BACKKEY2_MASK       4U
#define NV_BACKKEY4_BACKKEY3_MASK       8U
#define NV_BACKKEY4_BACKKEY4_MASK       16U
#define NV_BACKKEY4_BACKKEY5_MASK       32U
#define NV_BACKKEY4_BACKKEY6_MASK       64U
#define NV_BACKKEY4_BACKKEY7_MASK       128U


/*** NV_BACKKEY5 - Back Door Key Register n; 0x0000FF75 ***/
typedef union {
  byte Byte;
  struct {
    byte BACKKEY0    :1;                                       /* Back Door Key, bit 0 */
    byte BACKKEY1    :1;                                       /* Back Door Key, bit 1 */
    byte BACKKEY2    :1;                                       /* Back Door Key, bit 2 */
    byte BACKKEY3    :1;                                       /* Back Door Key, bit 3 */
    byte BACKKEY4    :1;                                       /* Back Door Key, bit 4 */
    byte BACKKEY5    :1;                                       /* Back Door Key, bit 5 */
    byte BACKKEY6    :1;                                       /* Back Door Key, bit 6 */
    byte BACKKEY7    :1;                                       /* Back Door Key, bit 7 */
  } Bits;
} NV_BACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NV_BACKKEY5_INIT @0x0000FF75 = <NV_BACKKEY5_INITVAL>; */
#define _NV_BACKKEY5 (*(const NV_BACKKEY5STR * __far)0x0000FF75)
#define NV_BACKKEY5                     _NV_BACKKEY5.Byte
#define NV_BACKKEY5_BACKKEY0            _NV_BACKKEY5.Bits.BACKKEY0
#define NV_BACKKEY5_BACKKEY1            _NV_BACKKEY5.Bits.BACKKEY1
#define NV_BACKKEY5_BACKKEY2            _NV_BACKKEY5.Bits.BACKKEY2
#define NV_BACKKEY5_BACKKEY3            _NV_BACKKEY5.Bits.BACKKEY3
#define NV_BACKKEY5_BACKKEY4            _NV_BACKKEY5.Bits.BACKKEY4
#define NV_BACKKEY5_BACKKEY5            _NV_BACKKEY5.Bits.BACKKEY5
#define NV_BACKKEY5_BACKKEY6            _NV_BACKKEY5.Bits.BACKKEY6
#define NV_BACKKEY5_BACKKEY7            _NV_BACKKEY5.Bits.BACKKEY7

#define NV_BACKKEY5_BACKKEY0_MASK       1U
#define NV_BACKKEY5_BACKKEY1_MASK       2U
#define NV_BACKKEY5_BACKKEY2_MASK       4U
#define NV_BACKKEY5_BACKKEY3_MASK       8U
#define NV_BACKKEY5_BACKKEY4_MASK       16U
#define NV_BACKKEY5_BACKKEY5_MASK       32U
#define NV_BACKKEY5_BACKKEY6_MASK       64U
#define NV_BACKKEY5_BACKKEY7_MASK       128U


/*** NV_BACKKEY6 - Back Door Key Register n; 0x0000FF76 ***/
typedef union {
  byte Byte;
  struct {
    byte BACKKEY0    :1;                                       /* Back Door Key, bit 0 */
    byte BACKKEY1    :1;                                       /* Back Door Key, bit 1 */
    byte BACKKEY2    :1;                                       /* Back Door Key, bit 2 */
    byte BACKKEY3    :1;                                       /* Back Door Key, bit 3 */
    byte BACKKEY4    :1;                                       /* Back Door Key, bit 4 */
    byte BACKKEY5    :1;                                       /* Back Door Key, bit 5 */
    byte BACKKEY6    :1;                                       /* Back Door Key, bit 6 */
    byte BACKKEY7    :1;                                       /* Back Door Key, bit 7 */
  } Bits;
} NV_BACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NV_BACKKEY6_INIT @0x0000FF76 = <NV_BACKKEY6_INITVAL>; */
#define _NV_BACKKEY6 (*(const NV_BACKKEY6STR * __far)0x0000FF76)
#define NV_BACKKEY6                     _NV_BACKKEY6.Byte
#define NV_BACKKEY6_BACKKEY0            _NV_BACKKEY6.Bits.BACKKEY0
#define NV_BACKKEY6_BACKKEY1            _NV_BACKKEY6.Bits.BACKKEY1
#define NV_BACKKEY6_BACKKEY2            _NV_BACKKEY6.Bits.BACKKEY2
#define NV_BACKKEY6_BACKKEY3            _NV_BACKKEY6.Bits.BACKKEY3
#define NV_BACKKEY6_BACKKEY4            _NV_BACKKEY6.Bits.BACKKEY4
#define NV_BACKKEY6_BACKKEY5            _NV_BACKKEY6.Bits.BACKKEY5
#define NV_BACKKEY6_BACKKEY6            _NV_BACKKEY6.Bits.BACKKEY6
#define NV_BACKKEY6_BACKKEY7            _NV_BACKKEY6.Bits.BACKKEY7

#define NV_BACKKEY6_BACKKEY0_MASK       1U
#define NV_BACKKEY6_BACKKEY1_MASK       2U
#define NV_BACKKEY6_BACKKEY2_MASK       4U
#define NV_BACKKEY6_BACKKEY3_MASK       8U
#define NV_BACKKEY6_BACKKEY4_MASK       16U
#define NV_BACKKEY6_BACKKEY5_MASK       32U
#define NV_BACKKEY6_BACKKEY6_MASK       64U
#define NV_BACKKEY6_BACKKEY7_MASK       128U


/*** NV_BACKKEY7 - Back Door Key Register n; 0x0000FF77 ***/
typedef union {
  byte Byte;
  struct {
    byte BACKKEY0    :1;                                       /* Back Door Key, bit 0 */
    byte BACKKEY1    :1;                                       /* Back Door Key, bit 1 */
    byte BACKKEY2    :1;                                       /* Back Door Key, bit 2 */
    byte BACKKEY3    :1;                                       /* Back Door Key, bit 3 */
    byte BACKKEY4    :1;                                       /* Back Door Key, bit 4 */
    byte BACKKEY5    :1;                                       /* Back Door Key, bit 5 */
    byte BACKKEY6    :1;                                       /* Back Door Key, bit 6 */
    byte BACKKEY7    :1;                                       /* Back Door Key, bit 7 */
  } Bits;
} NV_BACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NV_BACKKEY7_INIT @0x0000FF77 = <NV_BACKKEY7_INITVAL>; */
#define _NV_BACKKEY7 (*(const NV_BACKKEY7STR * __far)0x0000FF77)
#define NV_BACKKEY7                     _NV_BACKKEY7.Byte
#define NV_BACKKEY7_BACKKEY0            _NV_BACKKEY7.Bits.BACKKEY0
#define NV_BACKKEY7_BACKKEY1            _NV_BACKKEY7.Bits.BACKKEY1
#define NV_BACKKEY7_BACKKEY2            _NV_BACKKEY7.Bits.BACKKEY2
#define NV_BACKKEY7_BACKKEY3            _NV_BACKKEY7.Bits.BACKKEY3
#define NV_BACKKEY7_BACKKEY4            _NV_BACKKEY7.Bits.BACKKEY4
#define NV_BACKKEY7_BACKKEY5            _NV_BACKKEY7.Bits.BACKKEY5
#define NV_BACKKEY7_BACKKEY6            _NV_BACKKEY7.Bits.BACKKEY6
#define NV_BACKKEY7_BACKKEY7            _NV_BACKKEY7.Bits.BACKKEY7

#define NV_BACKKEY7_BACKKEY0_MASK       1U
#define NV_BACKKEY7_BACKKEY1_MASK       2U
#define NV_BACKKEY7_BACKKEY2_MASK       4U
#define NV_BACKKEY7_BACKKEY3_MASK       8U
#define NV_BACKKEY7_BACKKEY4_MASK       16U
#define NV_BACKKEY7_BACKKEY5_MASK       32U
#define NV_BACKKEY7_BACKKEY6_MASK       64U
#define NV_BACKKEY7_BACKKEY7_MASK       128U


/*** NV_FPROT - Flash Protection Register; 0x0000FF7C ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size, bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size, bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size, bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size, bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte             :1; 
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NV_FPROTSTR;
/* Tip for register initialization in the user code:  const byte NV_FPROT_INIT @0x0000FF7C = <NV_FPROT_INITVAL>; */
#define _NV_FPROT (*(const NV_FPROTSTR * __far)0x0000FF7C)
#define NV_FPROT                        _NV_FPROT.Byte
#define NV_FPROT_FPLS0                  _NV_FPROT.Bits.FPLS0
#define NV_FPROT_FPLS1                  _NV_FPROT.Bits.FPLS1
#define NV_FPROT_FPLDIS                 _NV_FPROT.Bits.FPLDIS
#define NV_FPROT_FPHS0                  _NV_FPROT.Bits.FPHS0
#define NV_FPROT_FPHS1                  _NV_FPROT.Bits.FPHS1
#define NV_FPROT_FPHDIS                 _NV_FPROT.Bits.FPHDIS
#define NV_FPROT_FPOPEN                 _NV_FPROT.Bits.FPOPEN
#define NV_FPROT_FPLS                   _NV_FPROT.MergedBits.grpFPLS
#define NV_FPROT_FPHS                   _NV_FPROT.MergedBits.grpFPHS

#define NV_FPROT_FPLS0_MASK             1U
#define NV_FPROT_FPLS1_MASK             2U
#define NV_FPROT_FPLDIS_MASK            4U
#define NV_FPROT_FPHS0_MASK             8U
#define NV_FPROT_FPHS1_MASK             16U
#define NV_FPROT_FPHDIS_MASK            32U
#define NV_FPROT_FPOPEN_MASK            128U
#define NV_FPROT_FPLS_MASK              3U
#define NV_FPROT_FPLS_BITNUM            0U
#define NV_FPROT_FPHS_MASK              24U
#define NV_FPROT_FPHS_BITNUM            3U


/*** NV_EEPROT - EEPROM Protection Register; 0x0000FF7D ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* EEPROM Protection Size, bit 0 */
    byte DPS1        :1;                                       /* EEPROM Protection Size, bit 1 */
    byte DPS2        :1;                                       /* EEPROM Protection Size, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* EEPROM Protection Control */
  } Bits;
  struct {
    byte grpDPS  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NV_EEPROTSTR;
/* Tip for register initialization in the user code:  const byte NV_EEPROT_INIT @0x0000FF7D = <NV_EEPROT_INITVAL>; */
#define _NV_EEPROT (*(const NV_EEPROTSTR * __far)0x0000FF7D)
#define NV_EEPROT                       _NV_EEPROT.Byte
#define NV_EEPROT_DPS0                  _NV_EEPROT.Bits.DPS0
#define NV_EEPROT_DPS1                  _NV_EEPROT.Bits.DPS1
#define NV_EEPROT_DPS2                  _NV_EEPROT.Bits.DPS2
#define NV_EEPROT_DPOPEN                _NV_EEPROT.Bits.DPOPEN
#define NV_EEPROT_DPS                   _NV_EEPROT.MergedBits.grpDPS

#define NV_EEPROT_DPS0_MASK             1U
#define NV_EEPROT_DPS1_MASK             2U
#define NV_EEPROT_DPS2_MASK             4U
#define NV_EEPROT_DPOPEN_MASK           128U
#define NV_EEPROT_DPS_MASK              7U
#define NV_EEPROT_DPS_BITNUM            0U


/*** NV_FOPT - Flash Option Register; 0x0000FF7E ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bits, bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bits, bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bits, bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bits, bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bits, bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bits, bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bits, bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bits, bit 7 */
  } Bits;
} NV_FOPTSTR;
/* Tip for register initialization in the user code:  const byte NV_FOPT_INIT @0x0000FF7E = <NV_FOPT_INITVAL>; */
#define _NV_FOPT (*(const NV_FOPTSTR * __far)0x0000FF7E)
#define NV_FOPT                         _NV_FOPT.Byte
#define NV_FOPT_NV0                     _NV_FOPT.Bits.NV0
#define NV_FOPT_NV1                     _NV_FOPT.Bits.NV1
#define NV_FOPT_NV2                     _NV_FOPT.Bits.NV2
#define NV_FOPT_NV3                     _NV_FOPT.Bits.NV3
#define NV_FOPT_NV4                     _NV_FOPT.Bits.NV4
#define NV_FOPT_NV5                     _NV_FOPT.Bits.NV5
#define NV_FOPT_NV6                     _NV_FOPT.Bits.NV6
#define NV_FOPT_NV7                     _NV_FOPT.Bits.NV7

#define NV_FOPT_NV0_MASK                1U
#define NV_FOPT_NV1_MASK                2U
#define NV_FOPT_NV2_MASK                4U
#define NV_FOPT_NV3_MASK                8U
#define NV_FOPT_NV4_MASK                16U
#define NV_FOPT_NV5_MASK                32U
#define NV_FOPT_NV6_MASK                64U
#define NV_FOPT_NV7_MASK                128U


/*** NV_FSEC - Flash Security Register; 0x0000FF7F ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bits, bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bits, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bits, bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bits, bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} NV_FSECSTR;
/* Tip for register initialization in the user code:  const byte NV_FSEC_INIT @0x0000FF7F = <NV_FSEC_INITVAL>; */
#define _NV_FSEC (*(const NV_FSECSTR * __far)0x0000FF7F)
#define NV_FSEC                         _NV_FSEC.Byte
#define NV_FSEC_SEC0                    _NV_FSEC.Bits.SEC0
#define NV_FSEC_SEC1                    _NV_FSEC.Bits.SEC1
#define NV_FSEC_KEYEN0                  _NV_FSEC.Bits.KEYEN0
#define NV_FSEC_KEYEN1                  _NV_FSEC.Bits.KEYEN1
#define NV_FSEC_SEC                     _NV_FSEC.MergedBits.grpSEC
#define NV_FSEC_KEYEN                   _NV_FSEC.MergedBits.grpKEYEN

#define NV_FSEC_SEC0_MASK               1U
#define NV_FSEC_SEC1_MASK               2U
#define NV_FSEC_KEYEN0_MASK             64U
#define NV_FSEC_KEYEN1_MASK             128U
#define NV_FSEC_SEC_MASK                3U
#define NV_FSEC_SEC_BITNUM              0U
#define NV_FSEC_KEYEN_MASK              192U
#define NV_FSEC_KEYEN_BITNUM            6U



/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 1/16/2012 5:50:57 PM */

#define SPI0_DL                          SPI0_D
#define SPI0_DL_Bits0                    This_symb_has_been_depreciated
#define SPI0_DL_Bits1                    This_symb_has_been_depreciated
#define SPI0_DL_Bits2                    This_symb_has_been_depreciated
#define SPI0_DL_Bits3                    This_symb_has_been_depreciated
#define SPI0_DL_Bits4                    This_symb_has_been_depreciated
#define SPI0_DL_Bits5                    This_symb_has_been_depreciated
#define SPI0_DL_Bits6                    This_symb_has_been_depreciated
#define SPI0_DL_Bits7                    This_symb_has_been_depreciated
#define SPI0_DL_Bits0_MASK               This_symb_has_been_depreciated
#define SPI0_DL_Bits1_MASK               This_symb_has_been_depreciated
#define SPI0_DL_Bits2_MASK               This_symb_has_been_depreciated
#define SPI0_DL_Bits3_MASK               This_symb_has_been_depreciated
#define SPI0_DL_Bits4_MASK               This_symb_has_been_depreciated
#define SPI0_DL_Bits5_MASK               This_symb_has_been_depreciated
#define SPI0_DL_Bits6_MASK               This_symb_has_been_depreciated
#define SPI0_DL_Bits7_MASK               This_symb_has_been_depreciated
#define SPI0_ML                          SPI0_M
#define SPI0_ML_Bits0                    This_symb_has_been_depreciated
#define SPI0_ML_Bits1                    This_symb_has_been_depreciated
#define SPI0_ML_Bits2                    This_symb_has_been_depreciated
#define SPI0_ML_Bits3                    This_symb_has_been_depreciated
#define SPI0_ML_Bits4                    This_symb_has_been_depreciated
#define SPI0_ML_Bits5                    This_symb_has_been_depreciated
#define SPI0_ML_Bits6                    This_symb_has_been_depreciated
#define SPI0_ML_Bits7                    This_symb_has_been_depreciated
#define SPI0_ML_Bits0_MASK               This_symb_has_been_depreciated
#define SPI0_ML_Bits1_MASK               This_symb_has_been_depreciated
#define SPI0_ML_Bits2_MASK               This_symb_has_been_depreciated
#define SPI0_ML_Bits3_MASK               This_symb_has_been_depreciated
#define SPI0_ML_Bits4_MASK               This_symb_has_been_depreciated
#define SPI0_ML_Bits5_MASK               This_symb_has_been_depreciated
#define SPI0_ML_Bits6_MASK               This_symb_has_been_depreciated
#define SPI0_ML_Bits7_MASK               This_symb_has_been_depreciated
#define SPI0_M_Bits0                     This_symb_has_been_depreciated
#define SPI0_M_Bits1                     This_symb_has_been_depreciated
#define SPI0_M_Bits2                     This_symb_has_been_depreciated
#define SPI0_M_Bits3                     This_symb_has_been_depreciated
#define SPI0_M_Bits4                     This_symb_has_been_depreciated
#define SPI0_M_Bits5                     This_symb_has_been_depreciated
#define SPI0_M_Bits6                     This_symb_has_been_depreciated
#define SPI0_M_Bits7                     This_symb_has_been_depreciated
#define SPI0_M_Bits0_MASK                This_symb_has_been_depreciated
#define SPI0_M_Bits1_MASK                This_symb_has_been_depreciated
#define SPI0_M_Bits2_MASK                This_symb_has_been_depreciated
#define SPI0_M_Bits3_MASK                This_symb_has_been_depreciated
#define SPI0_M_Bits4_MASK                This_symb_has_been_depreciated
#define SPI0_M_Bits5_MASK                This_symb_has_been_depreciated
#define SPI0_M_Bits6_MASK                This_symb_has_been_depreciated
#define SPI0_M_Bits7_MASK                This_symb_has_been_depreciated
#define SPI1_MH_Bits0                    This_symb_has_been_depreciated
#define SPI1_MH_Bits1                    This_symb_has_been_depreciated
#define SPI1_MH_Bits2                    This_symb_has_been_depreciated
#define SPI1_MH_Bits3                    This_symb_has_been_depreciated
#define SPI1_MH_Bits4                    This_symb_has_been_depreciated
#define SPI1_MH_Bits5                    This_symb_has_been_depreciated
#define SPI1_MH_Bits6                    This_symb_has_been_depreciated
#define SPI1_MH_Bits7                    This_symb_has_been_depreciated
#define SPI1_MH_Bits0_MASK               This_symb_has_been_depreciated
#define SPI1_MH_Bits1_MASK               This_symb_has_been_depreciated
#define SPI1_MH_Bits2_MASK               This_symb_has_been_depreciated
#define SPI1_MH_Bits3_MASK               This_symb_has_been_depreciated
#define SPI1_MH_Bits4_MASK               This_symb_has_been_depreciated
#define SPI1_MH_Bits5_MASK               This_symb_has_been_depreciated
#define SPI1_MH_Bits6_MASK               This_symb_has_been_depreciated
#define SPI1_MH_Bits7_MASK               This_symb_has_been_depreciated
#define SPI1_ML_Bits0                    This_symb_has_been_depreciated
#define SPI1_ML_Bits1                    This_symb_has_been_depreciated
#define SPI1_ML_Bits2                    This_symb_has_been_depreciated
#define SPI1_ML_Bits3                    This_symb_has_been_depreciated
#define SPI1_ML_Bits4                    This_symb_has_been_depreciated
#define SPI1_ML_Bits5                    This_symb_has_been_depreciated
#define SPI1_ML_Bits6                    This_symb_has_been_depreciated
#define SPI1_ML_Bits7                    This_symb_has_been_depreciated
#define SPI1_ML_Bits0_MASK               This_symb_has_been_depreciated
#define SPI1_ML_Bits1_MASK               This_symb_has_been_depreciated
#define SPI1_ML_Bits2_MASK               This_symb_has_been_depreciated
#define SPI1_ML_Bits3_MASK               This_symb_has_been_depreciated
#define SPI1_ML_Bits4_MASK               This_symb_has_been_depreciated
#define SPI1_ML_Bits5_MASK               This_symb_has_been_depreciated
#define SPI1_ML_Bits6_MASK               This_symb_has_been_depreciated
#define SPI1_ML_Bits7_MASK               This_symb_has_been_depreciated
#define PORT_IOFLT0_FILA0                PORT_IOFLT0_FLTA0
#define PORT_IOFLT0_FILA1                PORT_IOFLT0_FLTA1
#define PORT_IOFLT0_FILB0                PORT_IOFLT0_FLTB0
#define PORT_IOFLT0_FILB1                PORT_IOFLT0_FLTB1
#define PORT_IOFLT0_FILC0                PORT_IOFLT0_FLTC0
#define PORT_IOFLT0_FILC1                PORT_IOFLT0_FLTC1
#define PORT_IOFLT0_FILD0                PORT_IOFLT0_FLTD0
#define PORT_IOFLT0_FILD1                PORT_IOFLT0_FLTD1
#define PORT_IOFLT0_FILA                 PORT_IOFLT0_FLTA
#define PORT_IOFLT0_FILB                 PORT_IOFLT0_FLTB
#define PORT_IOFLT0_FILC                 PORT_IOFLT0_FLTC
#define PORT_IOFLT0_FILD                 PORT_IOFLT0_FLTD
#define PORT_IOFLT0_FILA0_MASK           PORT_IOFLT0_FLTA0_MASK
#define PORT_IOFLT0_FILA1_MASK           PORT_IOFLT0_FLTA1_MASK
#define PORT_IOFLT0_FILB0_MASK           PORT_IOFLT0_FLTB0_MASK
#define PORT_IOFLT0_FILB1_MASK           PORT_IOFLT0_FLTB1_MASK
#define PORT_IOFLT0_FILC0_MASK           PORT_IOFLT0_FLTC0_MASK
#define PORT_IOFLT0_FILC1_MASK           PORT_IOFLT0_FLTC1_MASK
#define PORT_IOFLT0_FILD0_MASK           PORT_IOFLT0_FLTD0_MASK
#define PORT_IOFLT0_FILD1_MASK           PORT_IOFLT0_FLTD1_MASK
#define PORT_IOFLT0_FILA_MASK            PORT_IOFLT0_FLTA_MASK
#define PORT_IOFLT0_FILA_BITNUM          PORT_IOFLT0_FLTA_BITNUM
#define PORT_IOFLT0_FILB_MASK            PORT_IOFLT0_FLTB_MASK
#define PORT_IOFLT0_FILB_BITNUM          PORT_IOFLT0_FLTB_BITNUM
#define PORT_IOFLT0_FILC_MASK            PORT_IOFLT0_FLTC_MASK
#define PORT_IOFLT0_FILC_BITNUM          PORT_IOFLT0_FLTC_BITNUM
#define PORT_IOFLT0_FILD_MASK            PORT_IOFLT0_FLTD_MASK
#define PORT_IOFLT0_FILD_BITNUM          PORT_IOFLT0_FLTD_BITNUM
#define PORT_IOFLT1_FILE0                PORT_IOFLT1_FLTE0
#define PORT_IOFLT1_FILE1                PORT_IOFLT1_FLTE1
#define PORT_IOFLT1_FILF0                PORT_IOFLT1_FLTF0
#define PORT_IOFLT1_FILF1                PORT_IOFLT1_FLTF1
#define PORT_IOFLT1_FILG0                PORT_IOFLT1_FLTG0
#define PORT_IOFLT1_FILG1                PORT_IOFLT1_FLTG1
#define PORT_IOFLT1_FILH0                PORT_IOFLT1_FLTH0
#define PORT_IOFLT1_FILH1                PORT_IOFLT1_FLTH1
#define PORT_IOFLT1_FILE                 PORT_IOFLT1_FLTE
#define PORT_IOFLT1_FILF                 PORT_IOFLT1_FLTF
#define PORT_IOFLT1_FILG                 PORT_IOFLT1_FLTG
#define PORT_IOFLT1_FILH                 PORT_IOFLT1_FLTH
#define PORT_IOFLT1_FILE0_MASK           PORT_IOFLT1_FLTE0_MASK
#define PORT_IOFLT1_FILE1_MASK           PORT_IOFLT1_FLTE1_MASK
#define PORT_IOFLT1_FILF0_MASK           PORT_IOFLT1_FLTF0_MASK
#define PORT_IOFLT1_FILF1_MASK           PORT_IOFLT1_FLTF1_MASK
#define PORT_IOFLT1_FILG0_MASK           PORT_IOFLT1_FLTG0_MASK
#define PORT_IOFLT1_FILG1_MASK           PORT_IOFLT1_FLTG1_MASK
#define PORT_IOFLT1_FILH0_MASK           PORT_IOFLT1_FLTH0_MASK
#define PORT_IOFLT1_FILH1_MASK           PORT_IOFLT1_FLTH1_MASK
#define PORT_IOFLT1_FILE_MASK            PORT_IOFLT1_FLTE_MASK
#define PORT_IOFLT1_FILE_BITNUM          PORT_IOFLT1_FLTE_BITNUM
#define PORT_IOFLT1_FILF_MASK            PORT_IOFLT1_FLTF_MASK
#define PORT_IOFLT1_FILF_BITNUM          PORT_IOFLT1_FLTF_BITNUM
#define PORT_IOFLT1_FILG_MASK            PORT_IOFLT1_FLTG_MASK
#define PORT_IOFLT1_FILG_BITNUM          PORT_IOFLT1_FLTG_BITNUM
#define PORT_IOFLT1_FILH_MASK            PORT_IOFLT1_FLTH_MASK
#define PORT_IOFLT1_FILH_BITNUM          PORT_IOFLT1_FLTH_BITNUM
#define PORT_IOFLT2_FILRST0              PORT_IOFLT2_FLTRST0
#define PORT_IOFLT2_FILRST1              PORT_IOFLT2_FLTRST1
#define PORT_IOFLT2_KBI00                PORT_IOFLT2_FLTKBI00
#define PORT_IOFLT2_KBI01                PORT_IOFLT2_FLTKBI01
#define PORT_IOFLT2_KBI10                PORT_IOFLT2_FLTKBI10
#define PORT_IOFLT2_KBI11                PORT_IOFLT2_FLTKBI11
#define PORT_IOFLT2_FILRST               PORT_IOFLT2_FLTRST
#define PORT_IOFLT2_KBI0                 PORT_IOFLT2_FLTKBI0
#define PORT_IOFLT2_KBI1                 PORT_IOFLT2_FLTKBI1
#define PORT_IOFLT2_FILRST0_MASK         PORT_IOFLT2_FLTRST0_MASK
#define PORT_IOFLT2_FILRST1_MASK         PORT_IOFLT2_FLTRST1_MASK
#define PORT_IOFLT2_KBI00_MASK           PORT_IOFLT2_FLTKBI00_MASK
#define PORT_IOFLT2_KBI01_MASK           PORT_IOFLT2_FLTKBI01_MASK
#define PORT_IOFLT2_KBI10_MASK           PORT_IOFLT2_FLTKBI10_MASK
#define PORT_IOFLT2_KBI11_MASK           PORT_IOFLT2_FLTKBI11_MASK
#define PORT_IOFLT2_FILRST_MASK          PORT_IOFLT2_FLTRST_MASK
#define PORT_IOFLT2_FILRST_BITNUM        PORT_IOFLT2_FLTRST_BITNUM
#define PORT_IOFLT2_KBI0_MASK            PORT_IOFLT2_FLTKBI0_MASK
#define PORT_IOFLT2_KBI0_BITNUM          PORT_IOFLT2_FLTKBI0_BITNUM
#define PORT_IOFLT2_KBI1_MASK            PORT_IOFLT2_FLTKBI1_MASK
#define PORT_IOFLT2_KBI1_BITNUM          PORT_IOFLT2_FLTKBI1_BITNUM
#define PORT_PTAPE_PTAPE4                This_symb_has_been_depreciated
#define PORT_PTAPE_PTAPE4_MASK           This_symb_has_been_depreciated
#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
