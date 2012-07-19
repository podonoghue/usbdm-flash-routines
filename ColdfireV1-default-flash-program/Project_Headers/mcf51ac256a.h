/* Based on CPU DB MCF51AC256A_80, version 3.00.059 (RegistersPrg V2.32) */
/*
** ###################################################################
**     Filename  : mcf51ac256a.h
**     Processor : MCF51AC256ACLK
**     FileFormat: V2.32
**     DataSheet : MCF51AC256RM Rev. 4, 5/2009
**     Compiler  : CodeWarrior compiler
**     Date/Time : 5.10.2010, 14:36
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2010 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 30.04.2008, V3.00.0:
**              - Renamed register FTM1ADCTRIG ==> FTM1EXTTRIG. Removed register FTM2ADCTRIG.
**              -   REASON: Changes in data sheet (from Draft D, 2/2008 to Draft F, 4/2008).
**      - 6.06.2008, V3.00.1:
**              - Renamed bits FTMxCNTINH[0:7] -> FTMxCNTINH[8:15]. 
**              - Removed bits FTMxSTATUS[CH6F,CH7F], FTMxOUTINIT[CH6OI,CH7OI], FTMxOUTMASK[CH6OM,CH7OM], FTMxPOL[POL6,POL7].
**              - Removed register FTMxCOMBINE3.
**              -   REASON: Bug-fif(#6229 in the Issue Manager).
**      - 8.07.2008, V3.00.2:
**              - Renamed IIC module registers to use prefix IIC instead of the IIC1.
**              - Renamed bit SCGC1[IIC1] -> SCGC1[IIC]. Renamed register FTMxFAULTFILTER -> FTMxFLTFILTER.
**              - Removed bits FTM1EXTTRIG[INITTRIGEN,CH6TRIG,CH7TRIG].
**              -   REASON: Changes in data sheet (from Rev. 0, Draft F, 04/2008 to Rev. 2, 06/2008).
**      - 22.08.2008, V3.00.3:
**              - Added definition of the 32-bit registers CANTIDR(0x000018B0), CANRIDR(0x000018A0).
**              -   REASON: Bug-fix (#6328 in Issue Manager). 
**      - 4.09.2008, V3.00.4:
**              - Renamed ADC module registers to use prefix ADC instead of the ADC1.
**              -   REASON: Bug-fix (#6556 in Issue Manager).
**      - 04.03.2009, V3.00.5:
**              - Added SPI2C3[INTCLR] bit and SPI2CI register.
**              -   REASON: Changes in the RM (From Rev. 2 to Rev. 3).
**      - 30.06.2009, V3.00.6:
**              - Added REQN5 bit to INTC_PL6P{7,6} register.
**              -   REASON: Changes in the RM (from Rev. 3 to Rev. 4).
**
**     File-Format-Revisions:
**      - 06.08.2007, V2.19 :
**               - CPUDB revisions generated ahead of the file-format revisions.
**      - 11.09.2007, V2.20 :
**               - Added comment about initialization of unbonded pins.
**      - 02.01.2008, V2.21 :
**               - pragma push/pack replaced by pragma options align, issue #5608
**      - 13.02.2008, V2.22 :
**               - ASM header files: fixed too long lines and pseudo-instructions format (leading dot)
**      - 20.02.2008, V2.23 :
**               - Changes have not affected this file (because they are related to another family)
**      - 03.07.2008, V2.24 :
**               - Added support for bits with name starting with number (like "1HZ")
**      - 28.11.2008, V2.25 :
**               - StandBy RAM array declaration for ANSI-C added
**      - 1.12.2008, V2.26 :
**               - Duplication of bit (or bit-group) name with register name is not marked as a problem, if register is internal only and it is not displayed in I/O map.
**      - 17.3.2009, V2.27 :
**               - Merged bit-group is not generated, if the name matches with another bit name in the register
**      - 6.4.2009, V2.28 :
**               - Fixed generation of merged bits for bit-groups with a digit at the end, if group-name is defined in CPUDB
**      - 3.8.2009, V2.29 :
**               - If there is just one bits group matching register name, single bits are not generated
**      - 10.9.2009, V2.30 :
**               - Fixed generation of registers arrays.
**      - 15.10.2009, V2.31 :
**               - Changes have not affected this file (because they are related to another family)
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MCF51AC256A_H
#define _MCF51AC256A_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned short word;
typedef unsigned long dword;

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (void)(SRS = 0x00U)
#endif
#endif /* __RESET_WATCHDOG */

#pragma options align=packed

/**************** interrupt vector numbers ****************/
#define VectorNumber_INITSP             0U
#define VectorNumber_INITPC             1U
#define VectorNumber_Vaccerr            2U
#define VectorNumber_Vadderr            3U
#define VectorNumber_Viinstr            4U
#define VectorNumber_VReserved5         5U
#define VectorNumber_VReserved6         6U
#define VectorNumber_VReserved7         7U
#define VectorNumber_Vprviol            8U
#define VectorNumber_Vtrace             9U
#define VectorNumber_Vunilaop           10U
#define VectorNumber_Vunilfop           11U
#define VectorNumber_Vdbgi              12U
#define VectorNumber_VReserved13        13U
#define VectorNumber_Vferror            14U
#define VectorNumber_VReserved15        15U
#define VectorNumber_VReserved16        16U
#define VectorNumber_VReserved17        17U
#define VectorNumber_VReserved18        18U
#define VectorNumber_VReserved19        19U
#define VectorNumber_VReserved20        20U
#define VectorNumber_VReserved21        21U
#define VectorNumber_VReserved22        22U
#define VectorNumber_VReserved23        23U
#define VectorNumber_Vspuri             24U
#define VectorNumber_VReserved25        25U
#define VectorNumber_VReserved26        26U
#define VectorNumber_VReserved27        27U
#define VectorNumber_VReserved28        28U
#define VectorNumber_VReserved29        29U
#define VectorNumber_VReserved30        30U
#define VectorNumber_VReserved31        31U
#define VectorNumber_Vtrap0             32U
#define VectorNumber_Vtrap1             33U
#define VectorNumber_Vtrap2             34U
#define VectorNumber_Vtrap3             35U
#define VectorNumber_Vtrap4             36U
#define VectorNumber_Vtrap5             37U
#define VectorNumber_Vtrap6             38U
#define VectorNumber_Vtrap7             39U
#define VectorNumber_Vtrap8             40U
#define VectorNumber_Vtrap9             41U
#define VectorNumber_Vtrap10            42U
#define VectorNumber_Vtrap11            43U
#define VectorNumber_Vtrap12            44U
#define VectorNumber_Vtrap13            45U
#define VectorNumber_Vtrap14            46U
#define VectorNumber_Vtrap15            47U
#define VectorNumber_VReserved48        48U
#define VectorNumber_VReserved49        49U
#define VectorNumber_VReserved50        50U
#define VectorNumber_VReserved51        51U
#define VectorNumber_VReserved52        52U
#define VectorNumber_VReserved53        53U
#define VectorNumber_VReserved54        54U
#define VectorNumber_VReserved55        55U
#define VectorNumber_VReserved56        56U
#define VectorNumber_VReserved57        57U
#define VectorNumber_VReserved58        58U
#define VectorNumber_VReserved59        59U
#define VectorNumber_VReserved60        60U
#define VectorNumber_Vunsinstr          61U
#define VectorNumber_VReserved62        62U
#define VectorNumber_VReserved63        63U
#define VectorNumber_Virq               64U
#define VectorNumber_Vlvd               65U
#define VectorNumber_Vlol               66U
#define VectorNumber_Vftm1ch0           67U
#define VectorNumber_Vftm1ch1           68U
#define VectorNumber_Vftm1ch2           69U
#define VectorNumber_Vftm1ch3           70U
#define VectorNumber_Vftm1ch4           71U
#define VectorNumber_Vftm1ch5           72U
#define VectorNumber_Vftm1ovf           73U
#define VectorNumber_Vftm2ch0           74U
#define VectorNumber_Vftm2ch1           75U
#define VectorNumber_Vftm2ch2           76U
#define VectorNumber_Vftm2ch3           77U
#define VectorNumber_Vftm2ch4           78U
#define VectorNumber_Vftm2ch5           79U
#define VectorNumber_Vftm2ovf           80U
#define VectorNumber_Vspi1              81U
#define VectorNumber_Vsci1err           82U
#define VectorNumber_Vsci1rx            83U
#define VectorNumber_Vsci1tx            84U
#define VectorNumber_Vsci2err           85U
#define VectorNumber_Vsci2rx            86U
#define VectorNumber_Vsci2tx            87U
#define VectorNumber_Vkeyboard          88U
#define VectorNumber_Vadc1              89U
#define VectorNumber_Viic1              90U
#define VectorNumber_Vrti               91U
#define VectorNumber_Vtpm3ch0           92U
#define VectorNumber_Vtpm3ch1           93U
#define VectorNumber_VReserved94        94U
#define VectorNumber_VReserved95        95U
#define VectorNumber_VReserved96        96U
#define VectorNumber_VReserved97        97U
#define VectorNumber_VReserved98        98U
#define VectorNumber_VReserved99        99U
#define VectorNumber_VReserved100       100U
#define VectorNumber_VReserved101       101U
#define VectorNumber_VReserved102       102U
#define VectorNumber_VL7swi             103U
#define VectorNumber_VL6swi             104U
#define VectorNumber_VL5swi             105U
#define VectorNumber_VL4swi             106U
#define VectorNumber_VL3swi             107U
#define VectorNumber_VL2swi             108U
#define VectorNumber_VL1swi             109U
#define VectorNumber_Vtpm3ovf           110U
#define VectorNumber_Vspi2              111U
#define VectorNumber_Vftm1fault         112U
#define VectorNumber_Vftm2fault         113U
#define VectorNumber_Vcanwu             114U
#define VectorNumber_Vcanerr            115U
#define VectorNumber_Vcanrx             116U
#define VectorNumber_Vcantx             117U
#define VectorNumber_Vacmp1             118U
#define VectorNumber_Vacmp2             119U

/**************** interrupt vector table ****************/
#define INITSP                          0x0000U
#define INITPC                          0x0004U
#define Vaccerr                         0x0008U
#define Vadderr                         0x000CU
#define Viinstr                         0x0010U
#define VReserved5                      0x0014U
#define VReserved6                      0x0018U
#define VReserved7                      0x001CU
#define Vprviol                         0x0020U
#define Vtrace                          0x0024U
#define Vunilaop                        0x0028U
#define Vunilfop                        0x002CU
#define Vdbgi                           0x0030U
#define VReserved13                     0x0034U
#define Vferror                         0x0038U
#define VReserved15                     0x003CU
#define VReserved16                     0x0040U
#define VReserved17                     0x0044U
#define VReserved18                     0x0048U
#define VReserved19                     0x004CU
#define VReserved20                     0x0050U
#define VReserved21                     0x0054U
#define VReserved22                     0x0058U
#define VReserved23                     0x005CU
#define Vspuri                          0x0060U
#define VReserved25                     0x0064U
#define VReserved26                     0x0068U
#define VReserved27                     0x006CU
#define VReserved28                     0x0070U
#define VReserved29                     0x0074U
#define VReserved30                     0x0078U
#define VReserved31                     0x007CU
#define Vtrap0                          0x0080U
#define Vtrap1                          0x0084U
#define Vtrap2                          0x0088U
#define Vtrap3                          0x008CU
#define Vtrap4                          0x0090U
#define Vtrap5                          0x0094U
#define Vtrap6                          0x0098U
#define Vtrap7                          0x009CU
#define Vtrap8                          0x00A0U
#define Vtrap9                          0x00A4U
#define Vtrap10                         0x00A8U
#define Vtrap11                         0x00ACU
#define Vtrap12                         0x00B0U
#define Vtrap13                         0x00B4U
#define Vtrap14                         0x00B8U
#define Vtrap15                         0x00BCU
#define VReserved48                     0x00C0U
#define VReserved49                     0x00C4U
#define VReserved50                     0x00C8U
#define VReserved51                     0x00CCU
#define VReserved52                     0x00D0U
#define VReserved53                     0x00D4U
#define VReserved54                     0x00D8U
#define VReserved55                     0x00DCU
#define VReserved56                     0x00E0U
#define VReserved57                     0x00E4U
#define VReserved58                     0x00E8U
#define VReserved59                     0x00ECU
#define VReserved60                     0x00F0U
#define Vunsinstr                       0x00F4U
#define VReserved62                     0x00F8U
#define VReserved63                     0x00FCU
#define Virq                            0x0100U
#define Vlvd                            0x0104U
#define Vlol                            0x0108U
#define Vftm1ch0                        0x010CU
#define Vftm1ch1                        0x0110U
#define Vftm1ch2                        0x0114U
#define Vftm1ch3                        0x0118U
#define Vftm1ch4                        0x011CU
#define Vftm1ch5                        0x0120U
#define Vftm1ovf                        0x0124U
#define Vftm2ch0                        0x0128U
#define Vftm2ch1                        0x012CU
#define Vftm2ch2                        0x0130U
#define Vftm2ch3                        0x0134U
#define Vftm2ch4                        0x0138U
#define Vftm2ch5                        0x013CU
#define Vftm2ovf                        0x0140U
#define Vspi1                           0x0144U
#define Vsci1err                        0x0148U
#define Vsci1rx                         0x014CU
#define Vsci1tx                         0x0150U
#define Vsci2err                        0x0154U
#define Vsci2rx                         0x0158U
#define Vsci2tx                         0x015CU
#define Vkeyboard                       0x0160U
#define Vadc1                           0x0164U
#define Viic1                           0x0168U
#define Vrti                            0x016CU
#define Vtpm3ch0                        0x0170U
#define Vtpm3ch1                        0x0174U
#define VReserved94                     0x0178U
#define VReserved95                     0x017CU
#define VReserved96                     0x0180U
#define VReserved97                     0x0184U
#define VReserved98                     0x0188U
#define VReserved99                     0x018CU
#define VReserved100                    0x0190U
#define VReserved101                    0x0194U
#define VReserved102                    0x0198U
#define VL7swi                          0x019CU
#define VL6swi                          0x01A0U
#define VL5swi                          0x01A4U
#define VL4swi                          0x01A8U
#define VL3swi                          0x01ACU
#define VL2swi                          0x01B0U
#define VL1swi                          0x01B4U
#define Vtpm3ovf                        0x01B8U
#define Vspi2                           0x01BCU
#define Vftm1fault                      0x01C0U
#define Vftm2fault                      0x01C4U
#define Vcanwu                          0x01C8U
#define Vcanerr                         0x01CCU
#define Vcanrx                          0x01D0U
#define Vcantx                          0x01D4U
#define Vacmp1                          0x01D8U
#define Vacmp2                          0x01DCU

/**************** registers I/O map ****************/

/*** NVFTRIM - Nonvolatile MCG Fine Trim; 0x000003FE ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* MCG Fine Trim */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} NVFTRIMSTR;
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x000003FE = <NVFTRIM_INITVAL>; */
#define _NVFTRIM (*(const NVFTRIMSTR *)0x000003FE)
#define NVFTRIM                         _NVFTRIM.Byte
#define NVFTRIM_FTRIM                   _NVFTRIM.Bits.FTRIM

#define NVFTRIM_FTRIM_MASK              1U


/*** NVMCGTRM - Nonvolatile MCG Trim Register; 0x000003FF ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* MCG Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* MCG Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* MCG Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* MCG Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* MCG Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* MCG Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* MCG Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* MCG Trim Setting, bit 7 */
  } Bits;
} NVMCGTRMSTR;
/* Tip for register initialization in the user code:  const byte NVMCGTRM_INIT @0x000003FF = <NVMCGTRM_INITVAL>; */
#define _NVMCGTRM (*(const NVMCGTRMSTR *)0x000003FF)
#define NVMCGTRM                        _NVMCGTRM.Byte
#define NVMCGTRM_TRIM0                  _NVMCGTRM.Bits.TRIM0
#define NVMCGTRM_TRIM1                  _NVMCGTRM.Bits.TRIM1
#define NVMCGTRM_TRIM2                  _NVMCGTRM.Bits.TRIM2
#define NVMCGTRM_TRIM3                  _NVMCGTRM.Bits.TRIM3
#define NVMCGTRM_TRIM4                  _NVMCGTRM.Bits.TRIM4
#define NVMCGTRM_TRIM5                  _NVMCGTRM.Bits.TRIM5
#define NVMCGTRM_TRIM6                  _NVMCGTRM.Bits.TRIM6
#define NVMCGTRM_TRIM7                  _NVMCGTRM.Bits.TRIM7

#define NVMCGTRM_TRIM0_MASK             1U
#define NVMCGTRM_TRIM1_MASK             2U
#define NVMCGTRM_TRIM2_MASK             4U
#define NVMCGTRM_TRIM3_MASK             8U
#define NVMCGTRM_TRIM4_MASK             16U
#define NVMCGTRM_TRIM5_MASK             32U
#define NVMCGTRM_TRIM6_MASK             64U
#define NVMCGTRM_TRIM7_MASK             128U


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x00000400 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x00000400 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR *)0x00000400)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte *) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1U
#define NVBACKKEY0_KEY1_MASK            2U
#define NVBACKKEY0_KEY2_MASK            4U
#define NVBACKKEY0_KEY3_MASK            8U
#define NVBACKKEY0_KEY4_MASK            16U
#define NVBACKKEY0_KEY5_MASK            32U
#define NVBACKKEY0_KEY6_MASK            64U
#define NVBACKKEY0_KEY7_MASK            128U


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x00000401 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x00000401 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR *)0x00000401)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1U
#define NVBACKKEY1_KEY1_MASK            2U
#define NVBACKKEY1_KEY2_MASK            4U
#define NVBACKKEY1_KEY3_MASK            8U
#define NVBACKKEY1_KEY4_MASK            16U
#define NVBACKKEY1_KEY5_MASK            32U
#define NVBACKKEY1_KEY6_MASK            64U
#define NVBACKKEY1_KEY7_MASK            128U


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x00000402 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x00000402 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR *)0x00000402)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1U
#define NVBACKKEY2_KEY1_MASK            2U
#define NVBACKKEY2_KEY2_MASK            4U
#define NVBACKKEY2_KEY3_MASK            8U
#define NVBACKKEY2_KEY4_MASK            16U
#define NVBACKKEY2_KEY5_MASK            32U
#define NVBACKKEY2_KEY6_MASK            64U
#define NVBACKKEY2_KEY7_MASK            128U


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x00000403 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x00000403 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR *)0x00000403)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1U
#define NVBACKKEY3_KEY1_MASK            2U
#define NVBACKKEY3_KEY2_MASK            4U
#define NVBACKKEY3_KEY3_MASK            8U
#define NVBACKKEY3_KEY4_MASK            16U
#define NVBACKKEY3_KEY5_MASK            32U
#define NVBACKKEY3_KEY6_MASK            64U
#define NVBACKKEY3_KEY7_MASK            128U


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x00000404 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x00000404 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR *)0x00000404)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1U
#define NVBACKKEY4_KEY1_MASK            2U
#define NVBACKKEY4_KEY2_MASK            4U
#define NVBACKKEY4_KEY3_MASK            8U
#define NVBACKKEY4_KEY4_MASK            16U
#define NVBACKKEY4_KEY5_MASK            32U
#define NVBACKKEY4_KEY6_MASK            64U
#define NVBACKKEY4_KEY7_MASK            128U


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x00000405 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x00000405 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR *)0x00000405)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1U
#define NVBACKKEY5_KEY1_MASK            2U
#define NVBACKKEY5_KEY2_MASK            4U
#define NVBACKKEY5_KEY3_MASK            8U
#define NVBACKKEY5_KEY4_MASK            16U
#define NVBACKKEY5_KEY5_MASK            32U
#define NVBACKKEY5_KEY6_MASK            64U
#define NVBACKKEY5_KEY7_MASK            128U


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x00000406 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x00000406 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR *)0x00000406)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1U
#define NVBACKKEY6_KEY1_MASK            2U
#define NVBACKKEY6_KEY2_MASK            4U
#define NVBACKKEY6_KEY3_MASK            8U
#define NVBACKKEY6_KEY4_MASK            16U
#define NVBACKKEY6_KEY5_MASK            32U
#define NVBACKKEY6_KEY6_MASK            64U
#define NVBACKKEY6_KEY7_MASK            128U


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x00000407 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x00000407 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR *)0x00000407)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1U
#define NVBACKKEY7_KEY1_MASK            2U
#define NVBACKKEY7_KEY2_MASK            4U
#define NVBACKKEY7_KEY3_MASK            8U
#define NVBACKKEY7_KEY4_MASK            16U
#define NVBACKKEY7_KEY5_MASK            32U
#define NVBACKKEY7_KEY6_MASK            64U
#define NVBACKKEY7_KEY7_MASK            128U


/*** NVPROT - Nonvolatile Flash Protection Register; 0x0000040D ***/
typedef union {
  byte Byte;
  struct {
    byte FPOPEN      :1;                                       /* Flash Protection Open */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000040D = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR *)0x0000040D)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPOPEN                   _NVPROT.Bits.FPOPEN
#define NVPROT_FPS0                     _NVPROT.Bits.FPS0
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS                      _NVPROT.MergedBits.grpFPS

#define NVPROT_FPOPEN_MASK              1U
#define NVPROT_FPS0_MASK                2U
#define NVPROT_FPS1_MASK                4U
#define NVPROT_FPS2_MASK                8U
#define NVPROT_FPS3_MASK                16U
#define NVPROT_FPS4_MASK                32U
#define NVPROT_FPS5_MASK                64U
#define NVPROT_FPS6_MASK                128U
#define NVPROT_FPS_MASK                 254U
#define NVPROT_FPS_BITNUM               1U


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000040F ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000040F = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR *)0x0000040F)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC0                      _NVOPT.Bits.SEC0
#define NVOPT_SEC1                      _NVOPT.Bits.SEC1
#define NVOPT_KEYEN0                    _NVOPT.Bits.KEYEN0
#define NVOPT_KEYEN1                    _NVOPT.Bits.KEYEN1
#define NVOPT_SEC                       _NVOPT.MergedBits.grpSEC
#define NVOPT_KEYEN                     _NVOPT.MergedBits.grpKEYEN

#define NVOPT_SEC0_MASK                 1U
#define NVOPT_SEC1_MASK                 2U
#define NVOPT_KEYEN0_MASK               64U
#define NVOPT_KEYEN1_MASK               128U
#define NVOPT_SEC_MASK                  3U
#define NVOPT_SEC_BITNUM                0U
#define NVOPT_KEYEN_MASK                192U
#define NVOPT_KEYEN_BITNUM              6U


/*** RGPIO_DIR - RGPIO Data Direction Register; 0x00C00000 ***/
typedef union {
  word Word;
  struct {
    word DIR0        :1;                                       /* RGPIO data direction bit 0 */
    word DIR1        :1;                                       /* RGPIO data direction bit 1 */
    word DIR2        :1;                                       /* RGPIO data direction bit 2 */
    word DIR3        :1;                                       /* RGPIO data direction bit 3 */
    word DIR4        :1;                                       /* RGPIO data direction bit 4 */
    word DIR5        :1;                                       /* RGPIO data direction bit 5 */
    word DIR6        :1;                                       /* RGPIO data direction bit 6 */
    word DIR7        :1;                                       /* RGPIO data direction bit 7 */
    word DIR8        :1;                                       /* RGPIO data direction bit 8 */
    word DIR9        :1;                                       /* RGPIO data direction bit 9 */
    word DIR10       :1;                                       /* RGPIO data direction bit 10 */
    word DIR11       :1;                                       /* RGPIO data direction bit 11 */
    word DIR12       :1;                                       /* RGPIO data direction bit 12 */
    word DIR13       :1;                                       /* RGPIO data direction bit 13 */
    word DIR14       :1;                                       /* RGPIO data direction bit 14 */
    word DIR15       :1;                                       /* RGPIO data direction bit 15 */
  } Bits;
} RGPIO_DIRSTR;
extern volatile RGPIO_DIRSTR _RGPIO_DIR @0x00C00000;
#define RGPIO_DIR                       _RGPIO_DIR.Word
#define RGPIO_DIR_DIR0                  _RGPIO_DIR.Bits.DIR0
#define RGPIO_DIR_DIR1                  _RGPIO_DIR.Bits.DIR1
#define RGPIO_DIR_DIR2                  _RGPIO_DIR.Bits.DIR2
#define RGPIO_DIR_DIR3                  _RGPIO_DIR.Bits.DIR3
#define RGPIO_DIR_DIR4                  _RGPIO_DIR.Bits.DIR4
#define RGPIO_DIR_DIR5                  _RGPIO_DIR.Bits.DIR5
#define RGPIO_DIR_DIR6                  _RGPIO_DIR.Bits.DIR6
#define RGPIO_DIR_DIR7                  _RGPIO_DIR.Bits.DIR7
#define RGPIO_DIR_DIR8                  _RGPIO_DIR.Bits.DIR8
#define RGPIO_DIR_DIR9                  _RGPIO_DIR.Bits.DIR9
#define RGPIO_DIR_DIR10                 _RGPIO_DIR.Bits.DIR10
#define RGPIO_DIR_DIR11                 _RGPIO_DIR.Bits.DIR11
#define RGPIO_DIR_DIR12                 _RGPIO_DIR.Bits.DIR12
#define RGPIO_DIR_DIR13                 _RGPIO_DIR.Bits.DIR13
#define RGPIO_DIR_DIR14                 _RGPIO_DIR.Bits.DIR14
#define RGPIO_DIR_DIR15                 _RGPIO_DIR.Bits.DIR15

#define RGPIO_DIR_DIR0_MASK             1U
#define RGPIO_DIR_DIR1_MASK             2U
#define RGPIO_DIR_DIR2_MASK             4U
#define RGPIO_DIR_DIR3_MASK             8U
#define RGPIO_DIR_DIR4_MASK             16U
#define RGPIO_DIR_DIR5_MASK             32U
#define RGPIO_DIR_DIR6_MASK             64U
#define RGPIO_DIR_DIR7_MASK             128U
#define RGPIO_DIR_DIR8_MASK             256U
#define RGPIO_DIR_DIR9_MASK             512U
#define RGPIO_DIR_DIR10_MASK            1024U
#define RGPIO_DIR_DIR11_MASK            2048U
#define RGPIO_DIR_DIR12_MASK            4096U
#define RGPIO_DIR_DIR13_MASK            8192U
#define RGPIO_DIR_DIR14_MASK            16384U
#define RGPIO_DIR_DIR15_MASK            32768U


/*** RGPIO_DATA - RGPIO Data Register; 0x00C00002 ***/
typedef union {
  word Word;
  struct {
    word DATA0       :1;                                       /* RGPIO data bit 0 */
    word DATA1       :1;                                       /* RGPIO data bit 1 */
    word DATA2       :1;                                       /* RGPIO data bit 2 */
    word DATA3       :1;                                       /* RGPIO data bit 3 */
    word DATA4       :1;                                       /* RGPIO data bit 4 */
    word DATA5       :1;                                       /* RGPIO data bit 5 */
    word DATA6       :1;                                       /* RGPIO data bit 6 */
    word DATA7       :1;                                       /* RGPIO data bit 7 */
    word DATA8       :1;                                       /* RGPIO data bit 8 */
    word DATA9       :1;                                       /* RGPIO data bit 9 */
    word DATA10      :1;                                       /* RGPIO data bit 10 */
    word DATA11      :1;                                       /* RGPIO data bit 11 */
    word DATA12      :1;                                       /* RGPIO data bit 12 */
    word DATA13      :1;                                       /* RGPIO data bit 13 */
    word DATA14      :1;                                       /* RGPIO data bit 14 */
    word DATA15      :1;                                       /* RGPIO data bit 15 */
  } Bits;
} RGPIO_DATASTR;
extern volatile RGPIO_DATASTR _RGPIO_DATA @0x00C00002;
#define RGPIO_DATA                      _RGPIO_DATA.Word
#define RGPIO_DATA_DATA0                _RGPIO_DATA.Bits.DATA0
#define RGPIO_DATA_DATA1                _RGPIO_DATA.Bits.DATA1
#define RGPIO_DATA_DATA2                _RGPIO_DATA.Bits.DATA2
#define RGPIO_DATA_DATA3                _RGPIO_DATA.Bits.DATA3
#define RGPIO_DATA_DATA4                _RGPIO_DATA.Bits.DATA4
#define RGPIO_DATA_DATA5                _RGPIO_DATA.Bits.DATA5
#define RGPIO_DATA_DATA6                _RGPIO_DATA.Bits.DATA6
#define RGPIO_DATA_DATA7                _RGPIO_DATA.Bits.DATA7
#define RGPIO_DATA_DATA8                _RGPIO_DATA.Bits.DATA8
#define RGPIO_DATA_DATA9                _RGPIO_DATA.Bits.DATA9
#define RGPIO_DATA_DATA10               _RGPIO_DATA.Bits.DATA10
#define RGPIO_DATA_DATA11               _RGPIO_DATA.Bits.DATA11
#define RGPIO_DATA_DATA12               _RGPIO_DATA.Bits.DATA12
#define RGPIO_DATA_DATA13               _RGPIO_DATA.Bits.DATA13
#define RGPIO_DATA_DATA14               _RGPIO_DATA.Bits.DATA14
#define RGPIO_DATA_DATA15               _RGPIO_DATA.Bits.DATA15

#define RGPIO_DATA_DATA0_MASK           1U
#define RGPIO_DATA_DATA1_MASK           2U
#define RGPIO_DATA_DATA2_MASK           4U
#define RGPIO_DATA_DATA3_MASK           8U
#define RGPIO_DATA_DATA4_MASK           16U
#define RGPIO_DATA_DATA5_MASK           32U
#define RGPIO_DATA_DATA6_MASK           64U
#define RGPIO_DATA_DATA7_MASK           128U
#define RGPIO_DATA_DATA8_MASK           256U
#define RGPIO_DATA_DATA9_MASK           512U
#define RGPIO_DATA_DATA10_MASK          1024U
#define RGPIO_DATA_DATA11_MASK          2048U
#define RGPIO_DATA_DATA12_MASK          4096U
#define RGPIO_DATA_DATA13_MASK          8192U
#define RGPIO_DATA_DATA14_MASK          16384U
#define RGPIO_DATA_DATA15_MASK          32768U


/*** RGPIO_ENB - RGPIO Pin Enable Register; 0x00C00004 ***/
typedef union {
  word Word;
  struct {
    word ENB0        :1;                                       /* RGPIO enable bit 0 */
    word ENB1        :1;                                       /* RGPIO enable bit 1 */
    word ENB2        :1;                                       /* RGPIO enable bit 2 */
    word ENB3        :1;                                       /* RGPIO enable bit 3 */
    word ENB4        :1;                                       /* RGPIO enable bit 4 */
    word ENB5        :1;                                       /* RGPIO enable bit 5 */
    word ENB6        :1;                                       /* RGPIO enable bit 6 */
    word ENB7        :1;                                       /* RGPIO enable bit 7 */
    word ENB8        :1;                                       /* RGPIO enable bit 8 */
    word ENB9        :1;                                       /* RGPIO enable bit 9 */
    word ENB10       :1;                                       /* RGPIO enable bit 10 */
    word ENB11       :1;                                       /* RGPIO enable bit 11 */
    word ENB12       :1;                                       /* RGPIO enable bit 12 */
    word ENB13       :1;                                       /* RGPIO enable bit 13 */
    word ENB14       :1;                                       /* RGPIO enable bit 14 */
    word ENB15       :1;                                       /* RGPIO enable bit 15 */
  } Bits;
} RGPIO_ENBSTR;
extern volatile RGPIO_ENBSTR _RGPIO_ENB @0x00C00004;
#define RGPIO_ENB                       _RGPIO_ENB.Word
#define RGPIO_ENB_ENB0                  _RGPIO_ENB.Bits.ENB0
#define RGPIO_ENB_ENB1                  _RGPIO_ENB.Bits.ENB1
#define RGPIO_ENB_ENB2                  _RGPIO_ENB.Bits.ENB2
#define RGPIO_ENB_ENB3                  _RGPIO_ENB.Bits.ENB3
#define RGPIO_ENB_ENB4                  _RGPIO_ENB.Bits.ENB4
#define RGPIO_ENB_ENB5                  _RGPIO_ENB.Bits.ENB5
#define RGPIO_ENB_ENB6                  _RGPIO_ENB.Bits.ENB6
#define RGPIO_ENB_ENB7                  _RGPIO_ENB.Bits.ENB7
#define RGPIO_ENB_ENB8                  _RGPIO_ENB.Bits.ENB8
#define RGPIO_ENB_ENB9                  _RGPIO_ENB.Bits.ENB9
#define RGPIO_ENB_ENB10                 _RGPIO_ENB.Bits.ENB10
#define RGPIO_ENB_ENB11                 _RGPIO_ENB.Bits.ENB11
#define RGPIO_ENB_ENB12                 _RGPIO_ENB.Bits.ENB12
#define RGPIO_ENB_ENB13                 _RGPIO_ENB.Bits.ENB13
#define RGPIO_ENB_ENB14                 _RGPIO_ENB.Bits.ENB14
#define RGPIO_ENB_ENB15                 _RGPIO_ENB.Bits.ENB15

#define RGPIO_ENB_ENB0_MASK             1U
#define RGPIO_ENB_ENB1_MASK             2U
#define RGPIO_ENB_ENB2_MASK             4U
#define RGPIO_ENB_ENB3_MASK             8U
#define RGPIO_ENB_ENB4_MASK             16U
#define RGPIO_ENB_ENB5_MASK             32U
#define RGPIO_ENB_ENB6_MASK             64U
#define RGPIO_ENB_ENB7_MASK             128U
#define RGPIO_ENB_ENB8_MASK             256U
#define RGPIO_ENB_ENB9_MASK             512U
#define RGPIO_ENB_ENB10_MASK            1024U
#define RGPIO_ENB_ENB11_MASK            2048U
#define RGPIO_ENB_ENB12_MASK            4096U
#define RGPIO_ENB_ENB13_MASK            8192U
#define RGPIO_ENB_ENB14_MASK            16384U
#define RGPIO_ENB_ENB15_MASK            32768U


/*** RGPIO_CLR - RGPIO Clear Data Register; 0x00C00006 ***/
typedef union {
  word Word;
  struct {
    word CLR0        :1;                                       /* RGPIO clear data bit 0 */
    word CLR1        :1;                                       /* RGPIO clear data bit 1 */
    word CLR2        :1;                                       /* RGPIO clear data bit 2 */
    word CLR3        :1;                                       /* RGPIO clear data bit 3 */
    word CLR4        :1;                                       /* RGPIO clear data bit 4 */
    word CLR5        :1;                                       /* RGPIO clear data bit 5 */
    word CLR6        :1;                                       /* RGPIO clear data bit 6 */
    word CLR7        :1;                                       /* RGPIO clear data bit 7 */
    word CLR8        :1;                                       /* RGPIO clear data bit 8 */
    word CLR9        :1;                                       /* RGPIO clear data bit 9 */
    word CLR10       :1;                                       /* RGPIO clear data bit 10 */
    word CLR11       :1;                                       /* RGPIO clear data bit 11 */
    word CLR12       :1;                                       /* RGPIO clear data bit 12 */
    word CLR13       :1;                                       /* RGPIO clear data bit 13 */
    word CLR14       :1;                                       /* RGPIO clear data bit 14 */
    word CLR15       :1;                                       /* RGPIO clear data bit 15 */
  } Bits;
} RGPIO_CLRSTR;
extern volatile RGPIO_CLRSTR _RGPIO_CLR @0x00C00006;
#define RGPIO_CLR                       _RGPIO_CLR.Word
#define RGPIO_CLR_CLR0                  _RGPIO_CLR.Bits.CLR0
#define RGPIO_CLR_CLR1                  _RGPIO_CLR.Bits.CLR1
#define RGPIO_CLR_CLR2                  _RGPIO_CLR.Bits.CLR2
#define RGPIO_CLR_CLR3                  _RGPIO_CLR.Bits.CLR3
#define RGPIO_CLR_CLR4                  _RGPIO_CLR.Bits.CLR4
#define RGPIO_CLR_CLR5                  _RGPIO_CLR.Bits.CLR5
#define RGPIO_CLR_CLR6                  _RGPIO_CLR.Bits.CLR6
#define RGPIO_CLR_CLR7                  _RGPIO_CLR.Bits.CLR7
#define RGPIO_CLR_CLR8                  _RGPIO_CLR.Bits.CLR8
#define RGPIO_CLR_CLR9                  _RGPIO_CLR.Bits.CLR9
#define RGPIO_CLR_CLR10                 _RGPIO_CLR.Bits.CLR10
#define RGPIO_CLR_CLR11                 _RGPIO_CLR.Bits.CLR11
#define RGPIO_CLR_CLR12                 _RGPIO_CLR.Bits.CLR12
#define RGPIO_CLR_CLR13                 _RGPIO_CLR.Bits.CLR13
#define RGPIO_CLR_CLR14                 _RGPIO_CLR.Bits.CLR14
#define RGPIO_CLR_CLR15                 _RGPIO_CLR.Bits.CLR15

#define RGPIO_CLR_CLR0_MASK             1U
#define RGPIO_CLR_CLR1_MASK             2U
#define RGPIO_CLR_CLR2_MASK             4U
#define RGPIO_CLR_CLR3_MASK             8U
#define RGPIO_CLR_CLR4_MASK             16U
#define RGPIO_CLR_CLR5_MASK             32U
#define RGPIO_CLR_CLR6_MASK             64U
#define RGPIO_CLR_CLR7_MASK             128U
#define RGPIO_CLR_CLR8_MASK             256U
#define RGPIO_CLR_CLR9_MASK             512U
#define RGPIO_CLR_CLR10_MASK            1024U
#define RGPIO_CLR_CLR11_MASK            2048U
#define RGPIO_CLR_CLR12_MASK            4096U
#define RGPIO_CLR_CLR13_MASK            8192U
#define RGPIO_CLR_CLR14_MASK            16384U
#define RGPIO_CLR_CLR15_MASK            32768U


/*** RGPIO_SET - RGPIO Set Data Register; 0x00C0000A ***/
typedef union {
  word Word;
  struct {
    word SET0        :1;                                       /* RGPIO set data bit 0 */
    word SET1        :1;                                       /* RGPIO set data bit 1 */
    word SET2        :1;                                       /* RGPIO set data bit 2 */
    word SET3        :1;                                       /* RGPIO set data bit 3 */
    word SET4        :1;                                       /* RGPIO set data bit 4 */
    word SET5        :1;                                       /* RGPIO set data bit 5 */
    word SET6        :1;                                       /* RGPIO set data bit 6 */
    word SET7        :1;                                       /* RGPIO set data bit 7 */
    word SET8        :1;                                       /* RGPIO set data bit 8 */
    word SET9        :1;                                       /* RGPIO set data bit 9 */
    word SET10       :1;                                       /* RGPIO set data bit 10 */
    word SET11       :1;                                       /* RGPIO set data bit 11 */
    word SET12       :1;                                       /* RGPIO set data bit 12 */
    word SET13       :1;                                       /* RGPIO set data bit 13 */
    word SET14       :1;                                       /* RGPIO set data bit 14 */
    word SET15       :1;                                       /* RGPIO set data bit 15 */
  } Bits;
} RGPIO_SETSTR;
extern volatile RGPIO_SETSTR _RGPIO_SET @0x00C0000A;
#define RGPIO_SET                       _RGPIO_SET.Word
#define RGPIO_SET_SET0                  _RGPIO_SET.Bits.SET0
#define RGPIO_SET_SET1                  _RGPIO_SET.Bits.SET1
#define RGPIO_SET_SET2                  _RGPIO_SET.Bits.SET2
#define RGPIO_SET_SET3                  _RGPIO_SET.Bits.SET3
#define RGPIO_SET_SET4                  _RGPIO_SET.Bits.SET4
#define RGPIO_SET_SET5                  _RGPIO_SET.Bits.SET5
#define RGPIO_SET_SET6                  _RGPIO_SET.Bits.SET6
#define RGPIO_SET_SET7                  _RGPIO_SET.Bits.SET7
#define RGPIO_SET_SET8                  _RGPIO_SET.Bits.SET8
#define RGPIO_SET_SET9                  _RGPIO_SET.Bits.SET9
#define RGPIO_SET_SET10                 _RGPIO_SET.Bits.SET10
#define RGPIO_SET_SET11                 _RGPIO_SET.Bits.SET11
#define RGPIO_SET_SET12                 _RGPIO_SET.Bits.SET12
#define RGPIO_SET_SET13                 _RGPIO_SET.Bits.SET13
#define RGPIO_SET_SET14                 _RGPIO_SET.Bits.SET14
#define RGPIO_SET_SET15                 _RGPIO_SET.Bits.SET15

#define RGPIO_SET_SET0_MASK             1U
#define RGPIO_SET_SET1_MASK             2U
#define RGPIO_SET_SET2_MASK             4U
#define RGPIO_SET_SET3_MASK             8U
#define RGPIO_SET_SET4_MASK             16U
#define RGPIO_SET_SET5_MASK             32U
#define RGPIO_SET_SET6_MASK             64U
#define RGPIO_SET_SET7_MASK             128U
#define RGPIO_SET_SET8_MASK             256U
#define RGPIO_SET_SET9_MASK             512U
#define RGPIO_SET_SET10_MASK            1024U
#define RGPIO_SET_SET11_MASK            2048U
#define RGPIO_SET_SET12_MASK            4096U
#define RGPIO_SET_SET13_MASK            8192U
#define RGPIO_SET_SET14_MASK            16384U
#define RGPIO_SET_SET15_MASK            32768U


/*** RGPIO_TOG - RGPIO Toggle Data Register; 0x00C0000E ***/
typedef union {
  word Word;
  struct {
    word TOG0        :1;                                       /* RGPIO toggle data bit 0 */
    word TOG1        :1;                                       /* RGPIO toggle data bit 1 */
    word TOG2        :1;                                       /* RGPIO toggle data bit 2 */
    word TOG3        :1;                                       /* RGPIO toggle data bit 3 */
    word TOG4        :1;                                       /* RGPIO toggle data bit 4 */
    word TOG5        :1;                                       /* RGPIO toggle data bit 5 */
    word TOG6        :1;                                       /* RGPIO toggle data bit 6 */
    word TOG7        :1;                                       /* RGPIO toggle data bit 7 */
    word TOG8        :1;                                       /* RGPIO toggle data bit 8 */
    word TOG9        :1;                                       /* RGPIO toggle data bit 9 */
    word TOG10       :1;                                       /* RGPIO toggle data bit 10 */
    word TOG11       :1;                                       /* RGPIO toggle data bit 11 */
    word TOG12       :1;                                       /* RGPIO toggle data bit 12 */
    word TOG13       :1;                                       /* RGPIO toggle data bit 13 */
    word TOG14       :1;                                       /* RGPIO toggle data bit 14 */
    word TOG15       :1;                                       /* RGPIO toggle data bit 15 */
  } Bits;
} RGPIO_TOGSTR;
extern volatile RGPIO_TOGSTR _RGPIO_TOG @0x00C0000E;
#define RGPIO_TOG                       _RGPIO_TOG.Word
#define RGPIO_TOG_TOG0                  _RGPIO_TOG.Bits.TOG0
#define RGPIO_TOG_TOG1                  _RGPIO_TOG.Bits.TOG1
#define RGPIO_TOG_TOG2                  _RGPIO_TOG.Bits.TOG2
#define RGPIO_TOG_TOG3                  _RGPIO_TOG.Bits.TOG3
#define RGPIO_TOG_TOG4                  _RGPIO_TOG.Bits.TOG4
#define RGPIO_TOG_TOG5                  _RGPIO_TOG.Bits.TOG5
#define RGPIO_TOG_TOG6                  _RGPIO_TOG.Bits.TOG6
#define RGPIO_TOG_TOG7                  _RGPIO_TOG.Bits.TOG7
#define RGPIO_TOG_TOG8                  _RGPIO_TOG.Bits.TOG8
#define RGPIO_TOG_TOG9                  _RGPIO_TOG.Bits.TOG9
#define RGPIO_TOG_TOG10                 _RGPIO_TOG.Bits.TOG10
#define RGPIO_TOG_TOG11                 _RGPIO_TOG.Bits.TOG11
#define RGPIO_TOG_TOG12                 _RGPIO_TOG.Bits.TOG12
#define RGPIO_TOG_TOG13                 _RGPIO_TOG.Bits.TOG13
#define RGPIO_TOG_TOG14                 _RGPIO_TOG.Bits.TOG14
#define RGPIO_TOG_TOG15                 _RGPIO_TOG.Bits.TOG15

#define RGPIO_TOG_TOG0_MASK             1U
#define RGPIO_TOG_TOG1_MASK             2U
#define RGPIO_TOG_TOG2_MASK             4U
#define RGPIO_TOG_TOG3_MASK             8U
#define RGPIO_TOG_TOG4_MASK             16U
#define RGPIO_TOG_TOG5_MASK             32U
#define RGPIO_TOG_TOG6_MASK             64U
#define RGPIO_TOG_TOG7_MASK             128U
#define RGPIO_TOG_TOG8_MASK             256U
#define RGPIO_TOG_TOG9_MASK             512U
#define RGPIO_TOG_TOG10_MASK            1024U
#define RGPIO_TOG_TOG11_MASK            2048U
#define RGPIO_TOG_TOG12_MASK            4096U
#define RGPIO_TOG_TOG13_MASK            8192U
#define RGPIO_TOG_TOG14_MASK            16384U
#define RGPIO_TOG_TOG15_MASK            32768U


/*** PTAD - Port A Data Register; 0xFFFF8000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte PTAD5       :1;                                       /* Port A Data Register Bit 5 */
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0xFFFF8000;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD4_MASK                 16U
#define PTAD_PTAD5_MASK                 32U
#define PTAD_PTAD6_MASK                 64U
#define PTAD_PTAD7_MASK                 128U


/*** PTADD - Port A Data Direction Register; 0xFFFF8001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte PTADD5      :1;                                       /* Data Direction for Port A Bit 5 */
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD @0xFFFF8001;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1U
#define PTADD_PTADD1_MASK               2U
#define PTADD_PTADD2_MASK               4U
#define PTADD_PTADD3_MASK               8U
#define PTADD_PTADD4_MASK               16U
#define PTADD_PTADD5_MASK               32U
#define PTADD_PTADD6_MASK               64U
#define PTADD_PTADD7_MASK               128U


/*** PTBD - Port B Data Register; 0xFFFF8002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte PTBD3       :1;                                       /* Port B Data Register Bit 3 */
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte PTBD6       :1;                                       /* Port B Data Register Bit 6 */
    byte PTBD7       :1;                                       /* Port B Data Register Bit 7 */
  } Bits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD @0xFFFF8002;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7

#define PTBD_PTBD0_MASK                 1U
#define PTBD_PTBD1_MASK                 2U
#define PTBD_PTBD2_MASK                 4U
#define PTBD_PTBD3_MASK                 8U
#define PTBD_PTBD4_MASK                 16U
#define PTBD_PTBD5_MASK                 32U
#define PTBD_PTBD6_MASK                 64U
#define PTBD_PTBD7_MASK                 128U


/*** PTBDD - Port B Data Direction Register; 0xFFFF8003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte PTBDD2      :1;                                       /* Data Direction for Port B Bit 2 */
    byte PTBDD3      :1;                                       /* Data Direction for Port B Bit 3 */
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte PTBDD6      :1;                                       /* Data Direction for Port B Bit 6 */
    byte PTBDD7      :1;                                       /* Data Direction for Port B Bit 7 */
  } Bits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD @0xFFFF8003;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD3                    _PTBDD.Bits.PTBDD3
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7

#define PTBDD_PTBDD0_MASK               1U
#define PTBDD_PTBDD1_MASK               2U
#define PTBDD_PTBDD2_MASK               4U
#define PTBDD_PTBDD3_MASK               8U
#define PTBDD_PTBDD4_MASK               16U
#define PTBDD_PTBDD5_MASK               32U
#define PTBDD_PTBDD6_MASK               64U
#define PTBDD_PTBDD7_MASK               128U


/*** PTCD - Port C Data Register; 0xFFFF8004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       /* Port C Data Register Bit 0 */
    byte PTCD1       :1;                                       /* Port C Data Register Bit 1 */
    byte PTCD2       :1;                                       /* Port C Data Register Bit 2 */
    byte PTCD3       :1;                                       /* Port C Data Register Bit 3 */
    byte PTCD4       :1;                                       /* Port C Data Register Bit 4 */
    byte PTCD5       :1;                                       /* Port C Data Register Bit 5 */
    byte PTCD6       :1;                                       /* Port C Data Register Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTCD :7;
    byte         :1;
  } MergedBits;
} PTCDSTR;
extern volatile PTCDSTR _PTCD @0xFFFF8004;
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD                       _PTCD.MergedBits.grpPTCD

#define PTCD_PTCD0_MASK                 1U
#define PTCD_PTCD1_MASK                 2U
#define PTCD_PTCD2_MASK                 4U
#define PTCD_PTCD3_MASK                 8U
#define PTCD_PTCD4_MASK                 16U
#define PTCD_PTCD5_MASK                 32U
#define PTCD_PTCD6_MASK                 64U
#define PTCD_PTCD_MASK                  127U
#define PTCD_PTCD_BITNUM                0U


/*** PTCDD - Port C Data Direction Register; 0xFFFF8005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       /* Data Direction for Port C Bit 0 */
    byte PTCDD1      :1;                                       /* Data Direction for Port C Bit 1 */
    byte PTCDD2      :1;                                       /* Data Direction for Port C Bit 2 */
    byte PTCDD3      :1;                                       /* Data Direction for Port C Bit 3 */
    byte PTCDD4      :1;                                       /* Data Direction for Port C Bit 4 */
    byte PTCDD5      :1;                                       /* Data Direction for Port C Bit 5 */
    byte PTCDD6      :1;                                       /* Data Direction for Port C Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTCDD :7;
    byte         :1;
  } MergedBits;
} PTCDDSTR;
extern volatile PTCDDSTR _PTCDD @0xFFFF8005;
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD                     _PTCDD.MergedBits.grpPTCDD

#define PTCDD_PTCDD0_MASK               1U
#define PTCDD_PTCDD1_MASK               2U
#define PTCDD_PTCDD2_MASK               4U
#define PTCDD_PTCDD3_MASK               8U
#define PTCDD_PTCDD4_MASK               16U
#define PTCDD_PTCDD5_MASK               32U
#define PTCDD_PTCDD6_MASK               64U
#define PTCDD_PTCDD_MASK                127U
#define PTCDD_PTCDD_BITNUM              0U


/*** PTDD - Port D Data Register; 0xFFFF8006 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDD0       :1;                                       /* Port D Data Register Bit 0 */
    byte PTDD1       :1;                                       /* Port D Data Register Bit 1 */
    byte PTDD2       :1;                                       /* Port D Data Register Bit 2 */
    byte PTDD3       :1;                                       /* Port D Data Register Bit 3 */
    byte PTDD4       :1;                                       /* Port D Data Register Bit 4 */
    byte PTDD5       :1;                                       /* Port D Data Register Bit 5 */
    byte PTDD6       :1;                                       /* Port D Data Register Bit 6 */
    byte PTDD7       :1;                                       /* Port D Data Register Bit 7 */
  } Bits;
} PTDDSTR;
extern volatile PTDDSTR _PTDD @0xFFFF8006;
#define PTDD                            _PTDD.Byte
#define PTDD_PTDD0                      _PTDD.Bits.PTDD0
#define PTDD_PTDD1                      _PTDD.Bits.PTDD1
#define PTDD_PTDD2                      _PTDD.Bits.PTDD2
#define PTDD_PTDD3                      _PTDD.Bits.PTDD3
#define PTDD_PTDD4                      _PTDD.Bits.PTDD4
#define PTDD_PTDD5                      _PTDD.Bits.PTDD5
#define PTDD_PTDD6                      _PTDD.Bits.PTDD6
#define PTDD_PTDD7                      _PTDD.Bits.PTDD7

#define PTDD_PTDD0_MASK                 1U
#define PTDD_PTDD1_MASK                 2U
#define PTDD_PTDD2_MASK                 4U
#define PTDD_PTDD3_MASK                 8U
#define PTDD_PTDD4_MASK                 16U
#define PTDD_PTDD5_MASK                 32U
#define PTDD_PTDD6_MASK                 64U
#define PTDD_PTDD7_MASK                 128U


/*** PTDDD - Port D Data Direction Register; 0xFFFF8007 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDD0      :1;                                       /* Data Direction for Port D Bit 0 */
    byte PTDDD1      :1;                                       /* Data Direction for Port D Bit 1 */
    byte PTDDD2      :1;                                       /* Data Direction for Port D Bit 2 */
    byte PTDDD3      :1;                                       /* Data Direction for Port D Bit 3 */
    byte PTDDD4      :1;                                       /* Data Direction for Port D Bit 4 */
    byte PTDDD5      :1;                                       /* Data Direction for Port D Bit 5 */
    byte PTDDD6      :1;                                       /* Data Direction for Port D Bit 6 */
    byte PTDDD7      :1;                                       /* Data Direction for Port D Bit 7 */
  } Bits;
} PTDDDSTR;
extern volatile PTDDDSTR _PTDDD @0xFFFF8007;
#define PTDDD                           _PTDDD.Byte
#define PTDDD_PTDDD0                    _PTDDD.Bits.PTDDD0
#define PTDDD_PTDDD1                    _PTDDD.Bits.PTDDD1
#define PTDDD_PTDDD2                    _PTDDD.Bits.PTDDD2
#define PTDDD_PTDDD3                    _PTDDD.Bits.PTDDD3
#define PTDDD_PTDDD4                    _PTDDD.Bits.PTDDD4
#define PTDDD_PTDDD5                    _PTDDD.Bits.PTDDD5
#define PTDDD_PTDDD6                    _PTDDD.Bits.PTDDD6
#define PTDDD_PTDDD7                    _PTDDD.Bits.PTDDD7

#define PTDDD_PTDDD0_MASK               1U
#define PTDDD_PTDDD1_MASK               2U
#define PTDDD_PTDDD2_MASK               4U
#define PTDDD_PTDDD3_MASK               8U
#define PTDDD_PTDDD4_MASK               16U
#define PTDDD_PTDDD5_MASK               32U
#define PTDDD_PTDDD6_MASK               64U
#define PTDDD_PTDDD7_MASK               128U


/*** PTED - Port E Data Register; 0xFFFF8008 ***/
typedef union {
  byte Byte;
  struct {
    byte PTED0       :1;                                       /* Port E Data Register Bit 0 */
    byte PTED1       :1;                                       /* Port E Data Register Bit 1 */
    byte PTED2       :1;                                       /* Port E Data Register Bit 2 */
    byte PTED3       :1;                                       /* Port E Data Register Bit 3 */
    byte PTED4       :1;                                       /* Port E Data Register Bit 4 */
    byte PTED5       :1;                                       /* Port E Data Register Bit 5 */
    byte PTED6       :1;                                       /* Port E Data Register Bit 6 */
    byte PTED7       :1;                                       /* Port E Data Register Bit 7 */
  } Bits;
} PTEDSTR;
extern volatile PTEDSTR _PTED @0xFFFF8008;
#define PTED                            _PTED.Byte
#define PTED_PTED0                      _PTED.Bits.PTED0
#define PTED_PTED1                      _PTED.Bits.PTED1
#define PTED_PTED2                      _PTED.Bits.PTED2
#define PTED_PTED3                      _PTED.Bits.PTED3
#define PTED_PTED4                      _PTED.Bits.PTED4
#define PTED_PTED5                      _PTED.Bits.PTED5
#define PTED_PTED6                      _PTED.Bits.PTED6
#define PTED_PTED7                      _PTED.Bits.PTED7

#define PTED_PTED0_MASK                 1U
#define PTED_PTED1_MASK                 2U
#define PTED_PTED2_MASK                 4U
#define PTED_PTED3_MASK                 8U
#define PTED_PTED4_MASK                 16U
#define PTED_PTED5_MASK                 32U
#define PTED_PTED6_MASK                 64U
#define PTED_PTED7_MASK                 128U


/*** PTEDD - Port E Data Direction Register; 0xFFFF8009 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDD0      :1;                                       /* Data Direction for Port E Bit 0 */
    byte PTEDD1      :1;                                       /* Data Direction for Port E Bit 1 */
    byte PTEDD2      :1;                                       /* Data Direction for Port E Bit 2 */
    byte PTEDD3      :1;                                       /* Data Direction for Port E Bit 3 */
    byte PTEDD4      :1;                                       /* Data Direction for Port E Bit 4 */
    byte PTEDD5      :1;                                       /* Data Direction for Port E Bit 5 */
    byte PTEDD6      :1;                                       /* Data Direction for Port E Bit 6 */
    byte PTEDD7      :1;                                       /* Data Direction for Port E Bit 7 */
  } Bits;
} PTEDDSTR;
extern volatile PTEDDSTR _PTEDD @0xFFFF8009;
#define PTEDD                           _PTEDD.Byte
#define PTEDD_PTEDD0                    _PTEDD.Bits.PTEDD0
#define PTEDD_PTEDD1                    _PTEDD.Bits.PTEDD1
#define PTEDD_PTEDD2                    _PTEDD.Bits.PTEDD2
#define PTEDD_PTEDD3                    _PTEDD.Bits.PTEDD3
#define PTEDD_PTEDD4                    _PTEDD.Bits.PTEDD4
#define PTEDD_PTEDD5                    _PTEDD.Bits.PTEDD5
#define PTEDD_PTEDD6                    _PTEDD.Bits.PTEDD6
#define PTEDD_PTEDD7                    _PTEDD.Bits.PTEDD7

#define PTEDD_PTEDD0_MASK               1U
#define PTEDD_PTEDD1_MASK               2U
#define PTEDD_PTEDD2_MASK               4U
#define PTEDD_PTEDD3_MASK               8U
#define PTEDD_PTEDD4_MASK               16U
#define PTEDD_PTEDD5_MASK               32U
#define PTEDD_PTEDD6_MASK               64U
#define PTEDD_PTEDD7_MASK               128U


/*** PTFD - Port F Data Register; 0xFFFF800A ***/
typedef union {
  byte Byte;
  struct {
    byte PTFD0       :1;                                       /* Port F Data Register Bit 0 */
    byte PTFD1       :1;                                       /* Port F Data Register Bit 1 */
    byte PTFD2       :1;                                       /* Port F Data Register Bit 2 */
    byte PTFD3       :1;                                       /* Port F Data Register Bit 3 */
    byte PTFD4       :1;                                       /* Port F Data Register Bit 4 */
    byte PTFD5       :1;                                       /* Port F Data Register Bit 5 */
    byte PTFD6       :1;                                       /* Port F Data Register Bit 6 */
    byte PTFD7       :1;                                       /* Port F Data Register Bit 7 */
  } Bits;
} PTFDSTR;
extern volatile PTFDSTR _PTFD @0xFFFF800A;
#define PTFD                            _PTFD.Byte
#define PTFD_PTFD0                      _PTFD.Bits.PTFD0
#define PTFD_PTFD1                      _PTFD.Bits.PTFD1
#define PTFD_PTFD2                      _PTFD.Bits.PTFD2
#define PTFD_PTFD3                      _PTFD.Bits.PTFD3
#define PTFD_PTFD4                      _PTFD.Bits.PTFD4
#define PTFD_PTFD5                      _PTFD.Bits.PTFD5
#define PTFD_PTFD6                      _PTFD.Bits.PTFD6
#define PTFD_PTFD7                      _PTFD.Bits.PTFD7

#define PTFD_PTFD0_MASK                 1U
#define PTFD_PTFD1_MASK                 2U
#define PTFD_PTFD2_MASK                 4U
#define PTFD_PTFD3_MASK                 8U
#define PTFD_PTFD4_MASK                 16U
#define PTFD_PTFD5_MASK                 32U
#define PTFD_PTFD6_MASK                 64U
#define PTFD_PTFD7_MASK                 128U


/*** PTFDD - Port F Data Direction Register; 0xFFFF800B ***/
typedef union {
  byte Byte;
  struct {
    byte PTFDD0      :1;                                       /* Data Direction for Port F Bit 0 */
    byte PTFDD1      :1;                                       /* Data Direction for Port F Bit 1 */
    byte PTFDD2      :1;                                       /* Data Direction for Port F Bit 2 */
    byte PTFDD3      :1;                                       /* Data Direction for Port F Bit 3 */
    byte PTFDD4      :1;                                       /* Data Direction for Port F Bit 4 */
    byte PTFDD5      :1;                                       /* Data Direction for Port F Bit 5 */
    byte PTFDD6      :1;                                       /* Data Direction for Port F Bit 6 */
    byte PTFDD7      :1;                                       /* Data Direction for Port F Bit 7 */
  } Bits;
} PTFDDSTR;
extern volatile PTFDDSTR _PTFDD @0xFFFF800B;
#define PTFDD                           _PTFDD.Byte
#define PTFDD_PTFDD0                    _PTFDD.Bits.PTFDD0
#define PTFDD_PTFDD1                    _PTFDD.Bits.PTFDD1
#define PTFDD_PTFDD2                    _PTFDD.Bits.PTFDD2
#define PTFDD_PTFDD3                    _PTFDD.Bits.PTFDD3
#define PTFDD_PTFDD4                    _PTFDD.Bits.PTFDD4
#define PTFDD_PTFDD5                    _PTFDD.Bits.PTFDD5
#define PTFDD_PTFDD6                    _PTFDD.Bits.PTFDD6
#define PTFDD_PTFDD7                    _PTFDD.Bits.PTFDD7

#define PTFDD_PTFDD0_MASK               1U
#define PTFDD_PTFDD1_MASK               2U
#define PTFDD_PTFDD2_MASK               4U
#define PTFDD_PTFDD3_MASK               8U
#define PTFDD_PTFDD4_MASK               16U
#define PTFDD_PTFDD5_MASK               32U
#define PTFDD_PTFDD6_MASK               64U
#define PTFDD_PTFDD7_MASK               128U


/*** PTGD - Port G Data Register; 0xFFFF800C ***/
typedef union {
  byte Byte;
  struct {
    byte PTGD0       :1;                                       /* Port G Data Register Bit 0 */
    byte PTGD1       :1;                                       /* Port G Data Register Bit 1 */
    byte PTGD2       :1;                                       /* Port G Data Register Bit 2 */
    byte PTGD3       :1;                                       /* Port G Data Register Bit 3 */
    byte PTGD4       :1;                                       /* Port G Data Register Bit 4 */
    byte PTGD5       :1;                                       /* Port G Data Register Bit 5 */
    byte PTGD6       :1;                                       /* Port G Data Register Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGD :7;
    byte         :1;
  } MergedBits;
} PTGDSTR;
extern volatile PTGDSTR _PTGD @0xFFFF800C;
#define PTGD                            _PTGD.Byte
#define PTGD_PTGD0                      _PTGD.Bits.PTGD0
#define PTGD_PTGD1                      _PTGD.Bits.PTGD1
#define PTGD_PTGD2                      _PTGD.Bits.PTGD2
#define PTGD_PTGD3                      _PTGD.Bits.PTGD3
#define PTGD_PTGD4                      _PTGD.Bits.PTGD4
#define PTGD_PTGD5                      _PTGD.Bits.PTGD5
#define PTGD_PTGD6                      _PTGD.Bits.PTGD6
#define PTGD_PTGD                       _PTGD.MergedBits.grpPTGD

#define PTGD_PTGD0_MASK                 1U
#define PTGD_PTGD1_MASK                 2U
#define PTGD_PTGD2_MASK                 4U
#define PTGD_PTGD3_MASK                 8U
#define PTGD_PTGD4_MASK                 16U
#define PTGD_PTGD5_MASK                 32U
#define PTGD_PTGD6_MASK                 64U
#define PTGD_PTGD_MASK                  127U
#define PTGD_PTGD_BITNUM                0U


/*** PTGDD - Port G Data Direction Register; 0xFFFF800D ***/
typedef union {
  byte Byte;
  struct {
    byte PTGDD0      :1;                                       /* Data Direction for Port G Bit 0 */
    byte PTGDD1      :1;                                       /* Data Direction for Port G Bit 1 */
    byte PTGDD2      :1;                                       /* Data Direction for Port G Bit 2 */
    byte PTGDD3      :1;                                       /* Data Direction for Port G Bit 3 */
    byte PTGDD4      :1;                                       /* Data Direction for Port G Bit 4 */
    byte PTGDD5      :1;                                       /* Data Direction for Port G Bit 5 */
    byte PTGDD6      :1;                                       /* Data Direction for Port G Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGDD :7;
    byte         :1;
  } MergedBits;
} PTGDDSTR;
extern volatile PTGDDSTR _PTGDD @0xFFFF800D;
#define PTGDD                           _PTGDD.Byte
#define PTGDD_PTGDD0                    _PTGDD.Bits.PTGDD0
#define PTGDD_PTGDD1                    _PTGDD.Bits.PTGDD1
#define PTGDD_PTGDD2                    _PTGDD.Bits.PTGDD2
#define PTGDD_PTGDD3                    _PTGDD.Bits.PTGDD3
#define PTGDD_PTGDD4                    _PTGDD.Bits.PTGDD4
#define PTGDD_PTGDD5                    _PTGDD.Bits.PTGDD5
#define PTGDD_PTGDD6                    _PTGDD.Bits.PTGDD6
#define PTGDD_PTGDD                     _PTGDD.MergedBits.grpPTGDD

#define PTGDD_PTGDD0_MASK               1U
#define PTGDD_PTGDD1_MASK               2U
#define PTGDD_PTGDD2_MASK               4U
#define PTGDD_PTGDD3_MASK               8U
#define PTGDD_PTGDD4_MASK               16U
#define PTGDD_PTGDD5_MASK               32U
#define PTGDD_PTGDD6_MASK               64U
#define PTGDD_PTGDD_MASK                127U
#define PTGDD_PTGDD_BITNUM              0U


/*** PTHD - Port H Data Register; 0xFFFF800E ***/
typedef union {
  byte Byte;
  struct {
    byte PTHD0       :1;                                       /* Port H Data Register Bit 0 */
    byte PTHD1       :1;                                       /* Port H Data Register Bit 1 */
    byte PTHD2       :1;                                       /* Port H Data Register Bit 2 */
    byte PTHD3       :1;                                       /* Port H Data Register Bit 3 */
    byte PTHD4       :1;                                       /* Port H Data Register Bit 4 */
    byte PTHD5       :1;                                       /* Port H Data Register Bit 5 */
    byte PTHD6       :1;                                       /* Port H Data Register Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHD :7;
    byte         :1;
  } MergedBits;
} PTHDSTR;
extern volatile PTHDSTR _PTHD @0xFFFF800E;
#define PTHD                            _PTHD.Byte
#define PTHD_PTHD0                      _PTHD.Bits.PTHD0
#define PTHD_PTHD1                      _PTHD.Bits.PTHD1
#define PTHD_PTHD2                      _PTHD.Bits.PTHD2
#define PTHD_PTHD3                      _PTHD.Bits.PTHD3
#define PTHD_PTHD4                      _PTHD.Bits.PTHD4
#define PTHD_PTHD5                      _PTHD.Bits.PTHD5
#define PTHD_PTHD6                      _PTHD.Bits.PTHD6
#define PTHD_PTHD                       _PTHD.MergedBits.grpPTHD

#define PTHD_PTHD0_MASK                 1U
#define PTHD_PTHD1_MASK                 2U
#define PTHD_PTHD2_MASK                 4U
#define PTHD_PTHD3_MASK                 8U
#define PTHD_PTHD4_MASK                 16U
#define PTHD_PTHD5_MASK                 32U
#define PTHD_PTHD6_MASK                 64U
#define PTHD_PTHD_MASK                  127U
#define PTHD_PTHD_BITNUM                0U


/*** PTHDD - Port H Data Direction Register; 0xFFFF800F ***/
typedef union {
  byte Byte;
  struct {
    byte PTHDD0      :1;                                       /* Data Direction for Port H Bit 0 */
    byte PTHDD1      :1;                                       /* Data Direction for Port H Bit 1 */
    byte PTHDD2      :1;                                       /* Data Direction for Port H Bit 2 */
    byte PTHDD3      :1;                                       /* Data Direction for Port H Bit 3 */
    byte PTHDD4      :1;                                       /* Data Direction for Port H Bit 4 */
    byte PTHDD5      :1;                                       /* Data Direction for Port H Bit 5 */
    byte PTHDD6      :1;                                       /* Data Direction for Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHDD :7;
    byte         :1;
  } MergedBits;
} PTHDDSTR;
extern volatile PTHDDSTR _PTHDD @0xFFFF800F;
#define PTHDD                           _PTHDD.Byte
#define PTHDD_PTHDD0                    _PTHDD.Bits.PTHDD0
#define PTHDD_PTHDD1                    _PTHDD.Bits.PTHDD1
#define PTHDD_PTHDD2                    _PTHDD.Bits.PTHDD2
#define PTHDD_PTHDD3                    _PTHDD.Bits.PTHDD3
#define PTHDD_PTHDD4                    _PTHDD.Bits.PTHDD4
#define PTHDD_PTHDD5                    _PTHDD.Bits.PTHDD5
#define PTHDD_PTHDD6                    _PTHDD.Bits.PTHDD6
#define PTHDD_PTHDD                     _PTHDD.MergedBits.grpPTHDD

#define PTHDD_PTHDD0_MASK               1U
#define PTHDD_PTHDD1_MASK               2U
#define PTHDD_PTHDD2_MASK               4U
#define PTHDD_PTHDD3_MASK               8U
#define PTHDD_PTHDD4_MASK               16U
#define PTHDD_PTHDD5_MASK               32U
#define PTHDD_PTHDD6_MASK               64U
#define PTHDD_PTHDD_MASK                127U
#define PTHDD_PTHDD_BITNUM              0U


/*** ADCSC1 - Status and Control Register 1; 0xFFFF8010 ***/
typedef union {
  byte Byte;
  struct {
    byte ADCH0       :1;                                       /* Input Channel Select Bit 0 */
    byte ADCH1       :1;                                       /* Input Channel Select Bit 1 */
    byte ADCH2       :1;                                       /* Input Channel Select Bit 2 */
    byte ADCH3       :1;                                       /* Input Channel Select Bit 3 */
    byte ADCH4       :1;                                       /* Input Channel Select Bit 4 */
    byte ADCO        :1;                                       /* Continuous Conversion Enable - ADCO is used to enable continuous conversions */
    byte AIEN        :1;                                       /* Interrupt Enable - AIEN is used to enable conversion complete interrupts. When COCO becomes set while AIEN is high, an interrupt is asserted */
    byte COCO        :1;                                       /* Conversion Complete Flag */
  } Bits;
  struct {
    byte grpADCH :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} ADCSC1STR;
extern volatile ADCSC1STR _ADCSC1 @0xFFFF8010;
#define ADCSC1                          _ADCSC1.Byte
#define ADCSC1_ADCH0                    _ADCSC1.Bits.ADCH0
#define ADCSC1_ADCH1                    _ADCSC1.Bits.ADCH1
#define ADCSC1_ADCH2                    _ADCSC1.Bits.ADCH2
#define ADCSC1_ADCH3                    _ADCSC1.Bits.ADCH3
#define ADCSC1_ADCH4                    _ADCSC1.Bits.ADCH4
#define ADCSC1_ADCO                     _ADCSC1.Bits.ADCO
#define ADCSC1_AIEN                     _ADCSC1.Bits.AIEN
#define ADCSC1_COCO                     _ADCSC1.Bits.COCO
#define ADCSC1_ADCH                     _ADCSC1.MergedBits.grpADCH

#define ADCSC1_ADCH0_MASK               1U
#define ADCSC1_ADCH1_MASK               2U
#define ADCSC1_ADCH2_MASK               4U
#define ADCSC1_ADCH3_MASK               8U
#define ADCSC1_ADCH4_MASK               16U
#define ADCSC1_ADCO_MASK                32U
#define ADCSC1_AIEN_MASK                64U
#define ADCSC1_COCO_MASK                128U
#define ADCSC1_ADCH_MASK                31U
#define ADCSC1_ADCH_BITNUM              0U


/*** ADCSC2 - Status and Control Register 2; 0xFFFF8011 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ACFGT       :1;                                       /* Compare Function Greater Than Enable */
    byte ACFE        :1;                                       /* Compare Function Enable - ACFE is used to enable the compare function */
    byte ADTRG       :1;                                       /* Conversion Trigger Select-ADTRG is used to select the type of trigger to be used for initiating a conversion */
    byte ADACT       :1;                                       /* Conversion Active - ADACT indicates that a conversion is in progress. ADACT is set when a conversion is initiated and cleared when a conversion is completed or aborted */
  } Bits;
} ADCSC2STR;
extern volatile ADCSC2STR _ADCSC2 @0xFFFF8011;
#define ADCSC2                          _ADCSC2.Byte
#define ADCSC2_ACFGT                    _ADCSC2.Bits.ACFGT
#define ADCSC2_ACFE                     _ADCSC2.Bits.ACFE
#define ADCSC2_ADTRG                    _ADCSC2.Bits.ADTRG
#define ADCSC2_ADACT                    _ADCSC2.Bits.ADACT

#define ADCSC2_ACFGT_MASK               16U
#define ADCSC2_ACFE_MASK                32U
#define ADCSC2_ADTRG_MASK               64U
#define ADCSC2_ADACT_MASK               128U


/*** ADCR - Data Result Register; 0xFFFF8012 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCRH - Data Result High Register; 0xFFFF8012 ***/
    union {
      byte Byte;
      struct {
        byte ADR8        :1;                                       /* ADC Result Data Bit 8 */
        byte ADR9        :1;                                       /* ADC Result Data Bit 9 */
        byte ADR10       :1;                                       /* ADC Result Data Bit 10 */
        byte ADR11       :1;                                       /* ADC Result Data Bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADR_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCRHSTR;
    #define ADCRH                       _ADCR.Overlap_STR.ADCRHSTR.Byte
    #define ADCRH_ADR8                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR8
    #define ADCRH_ADR9                  _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR9
    #define ADCRH_ADR10                 _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR10
    #define ADCRH_ADR11                 _ADCR.Overlap_STR.ADCRHSTR.Bits.ADR11
    #define ADCRH_ADR_8                 _ADCR.Overlap_STR.ADCRHSTR.MergedBits.grpADR_8
    #define ADCRH_ADR                   ADCRH_ADR_8
    
    #define ADCRH_ADR8_MASK             1U
    #define ADCRH_ADR9_MASK             2U
    #define ADCRH_ADR10_MASK            4U
    #define ADCRH_ADR11_MASK            8U
    #define ADCRH_ADR_8_MASK            15U
    #define ADCRH_ADR_8_BITNUM          0U
    

    /*** ADCRL - Data Result Low Register; 0xFFFF8013 ***/
    union {
      byte Byte;
      struct {
        byte ADR0        :1;                                       /* ADC Result Data Bit 0 */
        byte ADR1        :1;                                       /* ADC Result Data Bit 1 */
        byte ADR2        :1;                                       /* ADC Result Data Bit 2 */
        byte ADR3        :1;                                       /* ADC Result Data Bit 3 */
        byte ADR4        :1;                                       /* ADC Result Data Bit 4 */
        byte ADR5        :1;                                       /* ADC Result Data Bit 5 */
        byte ADR6        :1;                                       /* ADC Result Data Bit 6 */
        byte ADR7        :1;                                       /* ADC Result Data Bit 7 */
      } Bits;
    } ADCRLSTR;
    #define ADCRL                       _ADCR.Overlap_STR.ADCRLSTR.Byte
    #define ADCRL_ADR0                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR0
    #define ADCRL_ADR1                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR1
    #define ADCRL_ADR2                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR2
    #define ADCRL_ADR3                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR3
    #define ADCRL_ADR4                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR4
    #define ADCRL_ADR5                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR5
    #define ADCRL_ADR6                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR6
    #define ADCRL_ADR7                  _ADCR.Overlap_STR.ADCRLSTR.Bits.ADR7
    
    #define ADCRL_ADR0_MASK             1U
    #define ADCRL_ADR1_MASK             2U
    #define ADCRL_ADR2_MASK             4U
    #define ADCRL_ADR3_MASK             8U
    #define ADCRL_ADR4_MASK             16U
    #define ADCRL_ADR5_MASK             32U
    #define ADCRL_ADR6_MASK             64U
    #define ADCRL_ADR7_MASK             128U
    
  } Overlap_STR;

  struct {
    word ADR0        :1;                                       /* ADC Result Data Bit 0 */
    word ADR1        :1;                                       /* ADC Result Data Bit 1 */
    word ADR2        :1;                                       /* ADC Result Data Bit 2 */
    word ADR3        :1;                                       /* ADC Result Data Bit 3 */
    word ADR4        :1;                                       /* ADC Result Data Bit 4 */
    word ADR5        :1;                                       /* ADC Result Data Bit 5 */
    word ADR6        :1;                                       /* ADC Result Data Bit 6 */
    word ADR7        :1;                                       /* ADC Result Data Bit 7 */
    word ADR8        :1;                                       /* ADC Result Data Bit 8 */
    word ADR9        :1;                                       /* ADC Result Data Bit 9 */
    word ADR10       :1;                                       /* ADC Result Data Bit 10 */
    word ADR11       :1;                                       /* ADC Result Data Bit 11 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpADR  :12;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ADCRSTR;
extern volatile ADCRSTR _ADCR @0xFFFF8012;
#define ADCR                            _ADCR.Word
#define ADCR_ADR0                       _ADCR.Bits.ADR0
#define ADCR_ADR1                       _ADCR.Bits.ADR1
#define ADCR_ADR2                       _ADCR.Bits.ADR2
#define ADCR_ADR3                       _ADCR.Bits.ADR3
#define ADCR_ADR4                       _ADCR.Bits.ADR4
#define ADCR_ADR5                       _ADCR.Bits.ADR5
#define ADCR_ADR6                       _ADCR.Bits.ADR6
#define ADCR_ADR7                       _ADCR.Bits.ADR7
#define ADCR_ADR8                       _ADCR.Bits.ADR8
#define ADCR_ADR9                       _ADCR.Bits.ADR9
#define ADCR_ADR10                      _ADCR.Bits.ADR10
#define ADCR_ADR11                      _ADCR.Bits.ADR11
#define ADCR_ADR                        _ADCR.MergedBits.grpADR

#define ADCR_ADR0_MASK                  1U
#define ADCR_ADR1_MASK                  2U
#define ADCR_ADR2_MASK                  4U
#define ADCR_ADR3_MASK                  8U
#define ADCR_ADR4_MASK                  16U
#define ADCR_ADR5_MASK                  32U
#define ADCR_ADR6_MASK                  64U
#define ADCR_ADR7_MASK                  128U
#define ADCR_ADR8_MASK                  256U
#define ADCR_ADR9_MASK                  512U
#define ADCR_ADR10_MASK                 1024U
#define ADCR_ADR11_MASK                 2048U
#define ADCR_ADR_MASK                   4095U
#define ADCR_ADR_BITNUM                 0U


/*** ADCCV - Compare Value Register; 0xFFFF8014 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADCCVH - Compare Value High Register; 0xFFFF8014 ***/
    union {
      byte Byte;
      struct {
        byte ADCV8       :1;                                       /* Compare Function Value 8 */
        byte ADCV9       :1;                                       /* Compare Function Value 9 */
        byte ADCV10      :1;                                       /* Compare Function Value 10 */
        byte ADCV11      :1;                                       /* Compare Function Value 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpADCV_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } ADCCVHSTR;
    #define ADCCVH                      _ADCCV.Overlap_STR.ADCCVHSTR.Byte
    #define ADCCVH_ADCV8                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV8
    #define ADCCVH_ADCV9                _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV9
    #define ADCCVH_ADCV10               _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV10
    #define ADCCVH_ADCV11               _ADCCV.Overlap_STR.ADCCVHSTR.Bits.ADCV11
    #define ADCCVH_ADCV_8               _ADCCV.Overlap_STR.ADCCVHSTR.MergedBits.grpADCV_8
    #define ADCCVH_ADCV                 ADCCVH_ADCV_8
    
    #define ADCCVH_ADCV8_MASK           1U
    #define ADCCVH_ADCV9_MASK           2U
    #define ADCCVH_ADCV10_MASK          4U
    #define ADCCVH_ADCV11_MASK          8U
    #define ADCCVH_ADCV_8_MASK          15U
    #define ADCCVH_ADCV_8_BITNUM        0U
    

    /*** ADCCVL - Compare Value Low Register; 0xFFFF8015 ***/
    union {
      byte Byte;
      struct {
        byte ADCV0       :1;                                       /* Compare Function Value 0 */
        byte ADCV1       :1;                                       /* Compare Function Value 1 */
        byte ADCV2       :1;                                       /* Compare Function Value 2 */
        byte ADCV3       :1;                                       /* Compare Function Value 3 */
        byte ADCV4       :1;                                       /* Compare Function Value 4 */
        byte ADCV5       :1;                                       /* Compare Function Value 5 */
        byte ADCV6       :1;                                       /* Compare Function Value 6 */
        byte ADCV7       :1;                                       /* Compare Function Value 7 */
      } Bits;
    } ADCCVLSTR;
    #define ADCCVL                      _ADCCV.Overlap_STR.ADCCVLSTR.Byte
    #define ADCCVL_ADCV0                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV0
    #define ADCCVL_ADCV1                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV1
    #define ADCCVL_ADCV2                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV2
    #define ADCCVL_ADCV3                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV3
    #define ADCCVL_ADCV4                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV4
    #define ADCCVL_ADCV5                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV5
    #define ADCCVL_ADCV6                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV6
    #define ADCCVL_ADCV7                _ADCCV.Overlap_STR.ADCCVLSTR.Bits.ADCV7
    
    #define ADCCVL_ADCV0_MASK           1U
    #define ADCCVL_ADCV1_MASK           2U
    #define ADCCVL_ADCV2_MASK           4U
    #define ADCCVL_ADCV3_MASK           8U
    #define ADCCVL_ADCV4_MASK           16U
    #define ADCCVL_ADCV5_MASK           32U
    #define ADCCVL_ADCV6_MASK           64U
    #define ADCCVL_ADCV7_MASK           128U
    
  } Overlap_STR;

  struct {
    word ADCV0       :1;                                       /* Compare Function Value 0 */
    word ADCV1       :1;                                       /* Compare Function Value 1 */
    word ADCV2       :1;                                       /* Compare Function Value 2 */
    word ADCV3       :1;                                       /* Compare Function Value 3 */
    word ADCV4       :1;                                       /* Compare Function Value 4 */
    word ADCV5       :1;                                       /* Compare Function Value 5 */
    word ADCV6       :1;                                       /* Compare Function Value 6 */
    word ADCV7       :1;                                       /* Compare Function Value 7 */
    word ADCV8       :1;                                       /* Compare Function Value 8 */
    word ADCV9       :1;                                       /* Compare Function Value 9 */
    word ADCV10      :1;                                       /* Compare Function Value 10 */
    word ADCV11      :1;                                       /* Compare Function Value 11 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpADCV :12;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} ADCCVSTR;
extern volatile ADCCVSTR _ADCCV @0xFFFF8014;
#define ADCCV                           _ADCCV.Word
#define ADCCV_ADCV0                     _ADCCV.Bits.ADCV0
#define ADCCV_ADCV1                     _ADCCV.Bits.ADCV1
#define ADCCV_ADCV2                     _ADCCV.Bits.ADCV2
#define ADCCV_ADCV3                     _ADCCV.Bits.ADCV3
#define ADCCV_ADCV4                     _ADCCV.Bits.ADCV4
#define ADCCV_ADCV5                     _ADCCV.Bits.ADCV5
#define ADCCV_ADCV6                     _ADCCV.Bits.ADCV6
#define ADCCV_ADCV7                     _ADCCV.Bits.ADCV7
#define ADCCV_ADCV8                     _ADCCV.Bits.ADCV8
#define ADCCV_ADCV9                     _ADCCV.Bits.ADCV9
#define ADCCV_ADCV10                    _ADCCV.Bits.ADCV10
#define ADCCV_ADCV11                    _ADCCV.Bits.ADCV11
#define ADCCV_ADCV                      _ADCCV.MergedBits.grpADCV

#define ADCCV_ADCV0_MASK                1U
#define ADCCV_ADCV1_MASK                2U
#define ADCCV_ADCV2_MASK                4U
#define ADCCV_ADCV3_MASK                8U
#define ADCCV_ADCV4_MASK                16U
#define ADCCV_ADCV5_MASK                32U
#define ADCCV_ADCV6_MASK                64U
#define ADCCV_ADCV7_MASK                128U
#define ADCCV_ADCV8_MASK                256U
#define ADCCV_ADCV9_MASK                512U
#define ADCCV_ADCV10_MASK               1024U
#define ADCCV_ADCV11_MASK               2048U
#define ADCCV_ADCV_MASK                 4095U
#define ADCCV_ADCV_BITNUM               0U


/*** ADCCFG - Configuration Register; 0xFFFF8016 ***/
typedef union {
  byte Byte;
  struct {
    byte ADICLK0     :1;                                       /* Input Clock Select Bit 0 */
    byte ADICLK1     :1;                                       /* Input Clock Select Bit 1 */
    byte MODE0       :1;                                       /* Conversion Mode Selection Bit 0 */
    byte MODE1       :1;                                       /* Conversion Mode Selection Bit 1 */
    byte ADLSMP      :1;                                       /* Long Sample Time Configuration */
    byte ADIV0       :1;                                       /* Clock Divide Select Bit 0 */
    byte ADIV1       :1;                                       /* Clock Divide Select Bit 1 */
    byte ADLPC       :1;                                       /* Low Power Configuration */
  } Bits;
  struct {
    byte grpADICLK :2;
    byte grpMODE :2;
    byte         :1;
    byte grpADIV :2;
    byte         :1;
  } MergedBits;
} ADCCFGSTR;
extern volatile ADCCFGSTR _ADCCFG @0xFFFF8016;
#define ADCCFG                          _ADCCFG.Byte
#define ADCCFG_ADICLK0                  _ADCCFG.Bits.ADICLK0
#define ADCCFG_ADICLK1                  _ADCCFG.Bits.ADICLK1
#define ADCCFG_MODE0                    _ADCCFG.Bits.MODE0
#define ADCCFG_MODE1                    _ADCCFG.Bits.MODE1
#define ADCCFG_ADLSMP                   _ADCCFG.Bits.ADLSMP
#define ADCCFG_ADIV0                    _ADCCFG.Bits.ADIV0
#define ADCCFG_ADIV1                    _ADCCFG.Bits.ADIV1
#define ADCCFG_ADLPC                    _ADCCFG.Bits.ADLPC
#define ADCCFG_ADICLK                   _ADCCFG.MergedBits.grpADICLK
#define ADCCFG_MODE                     _ADCCFG.MergedBits.grpMODE
#define ADCCFG_ADIV                     _ADCCFG.MergedBits.grpADIV

#define ADCCFG_ADICLK0_MASK             1U
#define ADCCFG_ADICLK1_MASK             2U
#define ADCCFG_MODE0_MASK               4U
#define ADCCFG_MODE1_MASK               8U
#define ADCCFG_ADLSMP_MASK              16U
#define ADCCFG_ADIV0_MASK               32U
#define ADCCFG_ADIV1_MASK               64U
#define ADCCFG_ADLPC_MASK               128U
#define ADCCFG_ADICLK_MASK              3U
#define ADCCFG_ADICLK_BITNUM            0U
#define ADCCFG_MODE_MASK                12U
#define ADCCFG_MODE_BITNUM              2U
#define ADCCFG_ADIV_MASK                96U
#define ADCCFG_ADIV_BITNUM              5U


/*** APCTL1 - Pin Control 1 Register; 0xFFFF8017 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC0       :1;                                       /* ADC Pin Control 0 - ADPC0 is used to control the pin associated with channel AD0 */
    byte ADPC1       :1;                                       /* ADC Pin Control 1 - ADPC1 is used to control the pin associated with channel AD1 */
    byte ADPC2       :1;                                       /* ADC Pin Control 2 - ADPC2 is used to control the pin associated with channel AD2 */
    byte ADPC3       :1;                                       /* ADC Pin Control 3 - ADPC3 is used to control the pin associated with channel AD3 */
    byte ADPC4       :1;                                       /* ADC Pin Control 4 - ADPC4 is used to control the pin associated with channel AD4 */
    byte ADPC5       :1;                                       /* ADC Pin Control 5 - ADPC5 is used to control the pin associated with channel AD5 */
    byte ADPC6       :1;                                       /* ADC Pin Control 6 - ADPC6 is used to control the pin associated with channel AD6 */
    byte ADPC7       :1;                                       /* ADC Pin Control 7 - ADPC7 is used to control the pin associated with channel AD7 */
  } Bits;
} APCTL1STR;
extern volatile APCTL1STR _APCTL1 @0xFFFF8017;
#define APCTL1                          _APCTL1.Byte
#define APCTL1_ADPC0                    _APCTL1.Bits.ADPC0
#define APCTL1_ADPC1                    _APCTL1.Bits.ADPC1
#define APCTL1_ADPC2                    _APCTL1.Bits.ADPC2
#define APCTL1_ADPC3                    _APCTL1.Bits.ADPC3
#define APCTL1_ADPC4                    _APCTL1.Bits.ADPC4
#define APCTL1_ADPC5                    _APCTL1.Bits.ADPC5
#define APCTL1_ADPC6                    _APCTL1.Bits.ADPC6
#define APCTL1_ADPC7                    _APCTL1.Bits.ADPC7

#define APCTL1_ADPC0_MASK               1U
#define APCTL1_ADPC1_MASK               2U
#define APCTL1_ADPC2_MASK               4U
#define APCTL1_ADPC3_MASK               8U
#define APCTL1_ADPC4_MASK               16U
#define APCTL1_ADPC5_MASK               32U
#define APCTL1_ADPC6_MASK               64U
#define APCTL1_ADPC7_MASK               128U


/*** APCTL2 - Pin Control 2 Register; 0xFFFF8018 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC8       :1;                                       /* ADC Pin Control 8 - ADPC8 is used to control the pin associated with channel AD8 */
    byte ADPC9       :1;                                       /* ADC Pin Control 9 - ADPC9 is used to control the pin associated with channel AD9 */
    byte ADPC10      :1;                                       /* ADC Pin Control 10 - ADPC10 is used to control the pin associated with channel AD10 */
    byte ADPC11      :1;                                       /* ADC Pin Control 11 - ADPC11 is used to control the pin associated with channel AD11 */
    byte ADPC12      :1;                                       /* ADC Pin Control 12 - ADPC12 is used to control the pin associated with channel AD12 */
    byte ADPC13      :1;                                       /* ADC Pin Control 13 - ADPC13 is used to control the pin associated with channel AD13 */
    byte ADPC14      :1;                                       /* ADC Pin Control 14 - ADPC14 is used to control the pin associated with channel AD14 */
    byte ADPC15      :1;                                       /* ADC Pin Control 15 - ADPC15 is used to control the pin associated with channel AD15 */
  } Bits;
} APCTL2STR;
extern volatile APCTL2STR _APCTL2 @0xFFFF8018;
#define APCTL2                          _APCTL2.Byte
#define APCTL2_ADPC8                    _APCTL2.Bits.ADPC8
#define APCTL2_ADPC9                    _APCTL2.Bits.ADPC9
#define APCTL2_ADPC10                   _APCTL2.Bits.ADPC10
#define APCTL2_ADPC11                   _APCTL2.Bits.ADPC11
#define APCTL2_ADPC12                   _APCTL2.Bits.ADPC12
#define APCTL2_ADPC13                   _APCTL2.Bits.ADPC13
#define APCTL2_ADPC14                   _APCTL2.Bits.ADPC14
#define APCTL2_ADPC15                   _APCTL2.Bits.ADPC15

#define APCTL2_ADPC8_MASK               1U
#define APCTL2_ADPC9_MASK               2U
#define APCTL2_ADPC10_MASK              4U
#define APCTL2_ADPC11_MASK              8U
#define APCTL2_ADPC12_MASK              16U
#define APCTL2_ADPC13_MASK              32U
#define APCTL2_ADPC14_MASK              64U
#define APCTL2_ADPC15_MASK              128U


/*** APCTL3 - Pin Control 3 Register; 0xFFFF8019 ***/
typedef union {
  byte Byte;
  struct {
    byte ADPC16      :1;                                       /* ADC Pin Control 16 - ADPC16 is used to control the pin associated with channel AD16 */
    byte ADPC17      :1;                                       /* ADC Pin Control 17 - ADPC17 is used to control the pin associated with channel AD17 */
    byte ADPC18      :1;                                       /* ADC Pin Control 18 - ADPC18 is used to control the pin associated with channel AD18 */
    byte ADPC19      :1;                                       /* ADC Pin Control 19 - ADPC19 is used to control the pin associated with channel AD19 */
    byte ADPC20      :1;                                       /* ADC Pin Control 20 - ADPC20 is used to control the pin associated with channel AD20 */
    byte ADPC21      :1;                                       /* ADC Pin Control 21 - ADPC21 is used to control the pin associated with channel AD21 */
    byte ADPC22      :1;                                       /* ADC Pin Control 22 - ADPC22 is used to control the pin associated with channel AD22 */
    byte ADPC23      :1;                                       /* ADC Pin Control 23 - ADPC23 is used to control the pin associated with channel AD23 */
  } Bits;
} APCTL3STR;
extern volatile APCTL3STR _APCTL3 @0xFFFF8019;
#define APCTL3                          _APCTL3.Byte
#define APCTL3_ADPC16                   _APCTL3.Bits.ADPC16
#define APCTL3_ADPC17                   _APCTL3.Bits.ADPC17
#define APCTL3_ADPC18                   _APCTL3.Bits.ADPC18
#define APCTL3_ADPC19                   _APCTL3.Bits.ADPC19
#define APCTL3_ADPC20                   _APCTL3.Bits.ADPC20
#define APCTL3_ADPC21                   _APCTL3.Bits.ADPC21
#define APCTL3_ADPC22                   _APCTL3.Bits.ADPC22
#define APCTL3_ADPC23                   _APCTL3.Bits.ADPC23

#define APCTL3_ADPC16_MASK              1U
#define APCTL3_ADPC17_MASK              2U
#define APCTL3_ADPC18_MASK              4U
#define APCTL3_ADPC19_MASK              8U
#define APCTL3_ADPC20_MASK              16U
#define APCTL3_ADPC21_MASK              32U
#define APCTL3_ADPC22_MASK              64U
#define APCTL3_ADPC23_MASK              128U


/*** PTJD - Port J Data Register; 0xFFFF801A ***/
typedef union {
  byte Byte;
  struct {
    byte PTJD0       :1;                                       /* Port J Data Register Bit 0 */
    byte PTJD1       :1;                                       /* Port J Data Register Bit 1 */
    byte PTJD2       :1;                                       /* Port J Data Register Bit 2 */
    byte PTJD3       :1;                                       /* Port J Data Register Bit 3 */
    byte PTJD4       :1;                                       /* Port J Data Register Bit 4 */
    byte PTJD5       :1;                                       /* Port J Data Register Bit 5 */
    byte PTJD6       :1;                                       /* Port J Data Register Bit 6 */
    byte PTJD7       :1;                                       /* Port J Data Register Bit 7 */
  } Bits;
} PTJDSTR;
extern volatile PTJDSTR _PTJD @0xFFFF801A;
#define PTJD                            _PTJD.Byte
#define PTJD_PTJD0                      _PTJD.Bits.PTJD0
#define PTJD_PTJD1                      _PTJD.Bits.PTJD1
#define PTJD_PTJD2                      _PTJD.Bits.PTJD2
#define PTJD_PTJD3                      _PTJD.Bits.PTJD3
#define PTJD_PTJD4                      _PTJD.Bits.PTJD4
#define PTJD_PTJD5                      _PTJD.Bits.PTJD5
#define PTJD_PTJD6                      _PTJD.Bits.PTJD6
#define PTJD_PTJD7                      _PTJD.Bits.PTJD7

#define PTJD_PTJD0_MASK                 1U
#define PTJD_PTJD1_MASK                 2U
#define PTJD_PTJD2_MASK                 4U
#define PTJD_PTJD3_MASK                 8U
#define PTJD_PTJD4_MASK                 16U
#define PTJD_PTJD5_MASK                 32U
#define PTJD_PTJD6_MASK                 64U
#define PTJD_PTJD7_MASK                 128U


/*** PTJDD - Port J Data Direction Register; 0xFFFF801B ***/
typedef union {
  byte Byte;
  struct {
    byte PTJDD0      :1;                                       /* Data Direction for Port J Bit 0 */
    byte PTJDD1      :1;                                       /* Data Direction for Port J Bit 1 */
    byte PTJDD2      :1;                                       /* Data Direction for Port J Bit 2 */
    byte PTJDD3      :1;                                       /* Data Direction for Port J Bit 3 */
    byte PTJDD4      :1;                                       /* Data Direction for Port J Bit 4 */
    byte PTJDD5      :1;                                       /* Data Direction for Port J Bit 5 */
    byte PTJDD6      :1;                                       /* Data Direction for Port J Bit 6 */
    byte PTJDD7      :1;                                       /* Data Direction for Port J Bit 7 */
  } Bits;
} PTJDDSTR;
extern volatile PTJDDSTR _PTJDD @0xFFFF801B;
#define PTJDD                           _PTJDD.Byte
#define PTJDD_PTJDD0                    _PTJDD.Bits.PTJDD0
#define PTJDD_PTJDD1                    _PTJDD.Bits.PTJDD1
#define PTJDD_PTJDD2                    _PTJDD.Bits.PTJDD2
#define PTJDD_PTJDD3                    _PTJDD.Bits.PTJDD3
#define PTJDD_PTJDD4                    _PTJDD.Bits.PTJDD4
#define PTJDD_PTJDD5                    _PTJDD.Bits.PTJDD5
#define PTJDD_PTJDD6                    _PTJDD.Bits.PTJDD6
#define PTJDD_PTJDD7                    _PTJDD.Bits.PTJDD7

#define PTJDD_PTJDD0_MASK               1U
#define PTJDD_PTJDD1_MASK               2U
#define PTJDD_PTJDD2_MASK               4U
#define PTJDD_PTJDD3_MASK               8U
#define PTJDD_PTJDD4_MASK               16U
#define PTJDD_PTJDD5_MASK               32U
#define PTJDD_PTJDD6_MASK               64U
#define PTJDD_PTJDD7_MASK               128U


/*** IRQSC - Interrupt request status and control register; 0xFFFF801C ***/
typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       /* IRQ Detection Mode */
    byte IRQIE       :1;                                       /* IRQ Interrupt Enable */
    byte IRQACK      :1;                                       /* IRQ Acknowledge */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte IRQPE       :1;                                       /* IRQ Pin Enable */
    byte IRQEDG      :1;                                       /* IRQ Edge Select */
    byte IRQPDD      :1;                                       /* IRQ Pull Device Disable */
    byte             :1; 
  } Bits;
} IRQSCSTR;
extern volatile IRQSCSTR _IRQSC @0xFFFF801C;
#define IRQSC                           _IRQSC.Byte
#define IRQSC_IRQMOD                    _IRQSC.Bits.IRQMOD
#define IRQSC_IRQIE                     _IRQSC.Bits.IRQIE
#define IRQSC_IRQACK                    _IRQSC.Bits.IRQACK
#define IRQSC_IRQF                      _IRQSC.Bits.IRQF
#define IRQSC_IRQPE                     _IRQSC.Bits.IRQPE
#define IRQSC_IRQEDG                    _IRQSC.Bits.IRQEDG
#define IRQSC_IRQPDD                    _IRQSC.Bits.IRQPDD

#define IRQSC_IRQMOD_MASK               1U
#define IRQSC_IRQIE_MASK                2U
#define IRQSC_IRQACK_MASK               4U
#define IRQSC_IRQF_MASK                 8U
#define IRQSC_IRQPE_MASK                16U
#define IRQSC_IRQEDG_MASK               32U
#define IRQSC_IRQPDD_MASK               64U


/*** KBISC - KBI Status and Control Register; 0xFFFF801E ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select for KBI Port Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select for KBI Port Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select for KBI Port Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select for KBI Port Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKBEDG_4 :4;
  } MergedBits;
} KBISCSTR;
extern volatile KBISCSTR _KBISC @0xFFFF801E;
#define KBISC                           _KBISC.Byte
#define KBISC_KBIMOD                    _KBISC.Bits.KBIMOD
#define KBISC_KBIE                      _KBISC.Bits.KBIE
#define KBISC_KBACK                     _KBISC.Bits.KBACK
#define KBISC_KBF                       _KBISC.Bits.KBF
#define KBISC_KBEDG4                    _KBISC.Bits.KBEDG4
#define KBISC_KBEDG5                    _KBISC.Bits.KBEDG5
#define KBISC_KBEDG6                    _KBISC.Bits.KBEDG6
#define KBISC_KBEDG7                    _KBISC.Bits.KBEDG7
#define KBISC_KBEDG_4                   _KBISC.MergedBits.grpKBEDG_4
#define KBISC_KBEDG                     KBISC_KBEDG_4

#define KBISC_KBIMOD_MASK               1U
#define KBISC_KBIE_MASK                 2U
#define KBISC_KBACK_MASK                4U
#define KBISC_KBF_MASK                  8U
#define KBISC_KBEDG4_MASK               16U
#define KBISC_KBEDG5_MASK               32U
#define KBISC_KBEDG6_MASK               64U
#define KBISC_KBEDG7_MASK               128U
#define KBISC_KBEDG_4_MASK              240U
#define KBISC_KBEDG_4_BITNUM            4U


/*** KBIPE - KBI Pin Enable Register; 0xFFFF801F ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* KBI Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* KBI Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* KBI Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* KBI Pin Enable for KBI Port Bit 3 */
    byte KBIPE4      :1;                                       /* KBI Pin Enable for KBI Port Bit 4 */
    byte KBIPE5      :1;                                       /* KBI Pin Enable for KBI Port Bit 5 */
    byte KBIPE6      :1;                                       /* KBI Pin Enable for KBI Port Bit 6 */
    byte KBIPE7      :1;                                       /* KBI Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBIPESTR;
extern volatile KBIPESTR _KBIPE @0xFFFF801F;
#define KBIPE                           _KBIPE.Byte
#define KBIPE_KBIPE0                    _KBIPE.Bits.KBIPE0
#define KBIPE_KBIPE1                    _KBIPE.Bits.KBIPE1
#define KBIPE_KBIPE2                    _KBIPE.Bits.KBIPE2
#define KBIPE_KBIPE3                    _KBIPE.Bits.KBIPE3
#define KBIPE_KBIPE4                    _KBIPE.Bits.KBIPE4
#define KBIPE_KBIPE5                    _KBIPE.Bits.KBIPE5
#define KBIPE_KBIPE6                    _KBIPE.Bits.KBIPE6
#define KBIPE_KBIPE7                    _KBIPE.Bits.KBIPE7

#define KBIPE_KBIPE0_MASK               1U
#define KBIPE_KBIPE1_MASK               2U
#define KBIPE_KBIPE2_MASK               4U
#define KBIPE_KBIPE3_MASK               8U
#define KBIPE_KBIPE4_MASK               16U
#define KBIPE_KBIPE5_MASK               32U
#define KBIPE_KBIPE6_MASK               64U
#define KBIPE_KBIPE7_MASK               128U


/*** SCI1BD - SCI1 Baud Rate Register; 0xFFFF8038 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1BDH - SCI1 Baud Rate Register High; 0xFFFF8038 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI1BDHSTR;
    #define SCI1BDH                     _SCI1BD.Overlap_STR.SCI1BDHSTR.Byte
    #define SCI1BDH_SBR8                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR8
    #define SCI1BDH_SBR9                _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR9
    #define SCI1BDH_SBR10               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR10
    #define SCI1BDH_SBR11               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR11
    #define SCI1BDH_SBR12               _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.SBR12
    #define SCI1BDH_RXEDGIE             _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.RXEDGIE
    #define SCI1BDH_LBKDIE              _SCI1BD.Overlap_STR.SCI1BDHSTR.Bits.LBKDIE
    #define SCI1BDH_SBR_8               _SCI1BD.Overlap_STR.SCI1BDHSTR.MergedBits.grpSBR_8
    #define SCI1BDH_SBR                 SCI1BDH_SBR_8
    
    #define SCI1BDH_SBR8_MASK           1U
    #define SCI1BDH_SBR9_MASK           2U
    #define SCI1BDH_SBR10_MASK          4U
    #define SCI1BDH_SBR11_MASK          8U
    #define SCI1BDH_SBR12_MASK          16U
    #define SCI1BDH_RXEDGIE_MASK        64U
    #define SCI1BDH_LBKDIE_MASK         128U
    #define SCI1BDH_SBR_8_MASK          31U
    #define SCI1BDH_SBR_8_BITNUM        0U
    

    /*** SCI1BDL - SCI1 Baud Rate Register Low; 0xFFFF8039 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCI1BDLSTR;
    #define SCI1BDL                     _SCI1BD.Overlap_STR.SCI1BDLSTR.Byte
    #define SCI1BDL_SBR0                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR0
    #define SCI1BDL_SBR1                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR1
    #define SCI1BDL_SBR2                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR2
    #define SCI1BDL_SBR3                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR3
    #define SCI1BDL_SBR4                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR4
    #define SCI1BDL_SBR5                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR5
    #define SCI1BDL_SBR6                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR6
    #define SCI1BDL_SBR7                _SCI1BD.Overlap_STR.SCI1BDLSTR.Bits.SBR7
    
    #define SCI1BDL_SBR0_MASK           1U
    #define SCI1BDL_SBR1_MASK           2U
    #define SCI1BDL_SBR2_MASK           4U
    #define SCI1BDL_SBR3_MASK           8U
    #define SCI1BDL_SBR4_MASK           16U
    #define SCI1BDL_SBR5_MASK           32U
    #define SCI1BDL_SBR6_MASK           64U
    #define SCI1BDL_SBR7_MASK           128U
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
    word SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
    word SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
    word SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
    word SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
    word SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
    word SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
    word SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
    word SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
    word SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
    word SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
    word SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
    word SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
    word             :1; 
    word RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
    word LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
  } Bits;
  struct {
    word grpSBR  :13;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} SCI1BDSTR;
extern volatile SCI1BDSTR _SCI1BD @0xFFFF8038;
#define SCI1BD                          _SCI1BD.Word
#define SCI1BD_SBR0                     _SCI1BD.Bits.SBR0
#define SCI1BD_SBR1                     _SCI1BD.Bits.SBR1
#define SCI1BD_SBR2                     _SCI1BD.Bits.SBR2
#define SCI1BD_SBR3                     _SCI1BD.Bits.SBR3
#define SCI1BD_SBR4                     _SCI1BD.Bits.SBR4
#define SCI1BD_SBR5                     _SCI1BD.Bits.SBR5
#define SCI1BD_SBR6                     _SCI1BD.Bits.SBR6
#define SCI1BD_SBR7                     _SCI1BD.Bits.SBR7
#define SCI1BD_SBR8                     _SCI1BD.Bits.SBR8
#define SCI1BD_SBR9                     _SCI1BD.Bits.SBR9
#define SCI1BD_SBR10                    _SCI1BD.Bits.SBR10
#define SCI1BD_SBR11                    _SCI1BD.Bits.SBR11
#define SCI1BD_SBR12                    _SCI1BD.Bits.SBR12
#define SCI1BD_RXEDGIE                  _SCI1BD.Bits.RXEDGIE
#define SCI1BD_LBKDIE                   _SCI1BD.Bits.LBKDIE
#define SCI1BD_SBR                      _SCI1BD.MergedBits.grpSBR

#define SCI1BD_SBR0_MASK                1U
#define SCI1BD_SBR1_MASK                2U
#define SCI1BD_SBR2_MASK                4U
#define SCI1BD_SBR3_MASK                8U
#define SCI1BD_SBR4_MASK                16U
#define SCI1BD_SBR5_MASK                32U
#define SCI1BD_SBR6_MASK                64U
#define SCI1BD_SBR7_MASK                128U
#define SCI1BD_SBR8_MASK                256U
#define SCI1BD_SBR9_MASK                512U
#define SCI1BD_SBR10_MASK               1024U
#define SCI1BD_SBR11_MASK               2048U
#define SCI1BD_SBR12_MASK               4096U
#define SCI1BD_RXEDGIE_MASK             16384U
#define SCI1BD_LBKDIE_MASK              32768U
#define SCI1BD_SBR_MASK                 8191U
#define SCI1BD_SBR_BITNUM               0U


/*** SCI1C1 - SCI1 Control Register 1; 0xFFFF803A ***/
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
} SCI1C1STR;
extern volatile SCI1C1STR _SCI1C1 @0xFFFF803A;
#define SCI1C1                          _SCI1C1.Byte
#define SCI1C1_PT                       _SCI1C1.Bits.PT
#define SCI1C1_PE                       _SCI1C1.Bits.PE
#define SCI1C1_ILT                      _SCI1C1.Bits.ILT
#define SCI1C1_WAKE                     _SCI1C1.Bits.WAKE
#define SCI1C1_M                        _SCI1C1.Bits.M
#define SCI1C1_RSRC                     _SCI1C1.Bits.RSRC
#define SCI1C1_SCISWAI                  _SCI1C1.Bits.SCISWAI
#define SCI1C1_LOOPS                    _SCI1C1.Bits.LOOPS

#define SCI1C1_PT_MASK                  1U
#define SCI1C1_PE_MASK                  2U
#define SCI1C1_ILT_MASK                 4U
#define SCI1C1_WAKE_MASK                8U
#define SCI1C1_M_MASK                   16U
#define SCI1C1_RSRC_MASK                32U
#define SCI1C1_SCISWAI_MASK             64U
#define SCI1C1_LOOPS_MASK               128U


/*** SCI1C2 - SCI1 Control Register 2; 0xFFFF803B ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCI1C2STR;
extern volatile SCI1C2STR _SCI1C2 @0xFFFF803B;
#define SCI1C2                          _SCI1C2.Byte
#define SCI1C2_SBK                      _SCI1C2.Bits.SBK
#define SCI1C2_RWU                      _SCI1C2.Bits.RWU
#define SCI1C2_RE                       _SCI1C2.Bits.RE
#define SCI1C2_TE                       _SCI1C2.Bits.TE
#define SCI1C2_ILIE                     _SCI1C2.Bits.ILIE
#define SCI1C2_RIE                      _SCI1C2.Bits.RIE
#define SCI1C2_TCIE                     _SCI1C2.Bits.TCIE
#define SCI1C2_TIE                      _SCI1C2.Bits.TIE

#define SCI1C2_SBK_MASK                 1U
#define SCI1C2_RWU_MASK                 2U
#define SCI1C2_RE_MASK                  4U
#define SCI1C2_TE_MASK                  8U
#define SCI1C2_ILIE_MASK                16U
#define SCI1C2_RIE_MASK                 32U
#define SCI1C2_TCIE_MASK                64U
#define SCI1C2_TIE_MASK                 128U


/*** SCI1S1 - SCI1 Status Register 1; 0xFFFF803C ***/
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
} SCI1S1STR;
extern volatile SCI1S1STR _SCI1S1 @0xFFFF803C;
#define SCI1S1                          _SCI1S1.Byte
#define SCI1S1_PF                       _SCI1S1.Bits.PF
#define SCI1S1_FE                       _SCI1S1.Bits.FE
#define SCI1S1_NF                       _SCI1S1.Bits.NF
#define SCI1S1_OR                       _SCI1S1.Bits.OR
#define SCI1S1_IDLE                     _SCI1S1.Bits.IDLE
#define SCI1S1_RDRF                     _SCI1S1.Bits.RDRF
#define SCI1S1_TC                       _SCI1S1.Bits.TC
#define SCI1S1_TDRE                     _SCI1S1.Bits.TDRE

#define SCI1S1_PF_MASK                  1U
#define SCI1S1_FE_MASK                  2U
#define SCI1S1_NF_MASK                  4U
#define SCI1S1_OR_MASK                  8U
#define SCI1S1_IDLE_MASK                16U
#define SCI1S1_RDRF_MASK                32U
#define SCI1S1_TC_MASK                  64U
#define SCI1S1_TDRE_MASK                128U


/*** SCI1S2 - SCI1 Status Register 2; 0xFFFF803D ***/
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
} SCI1S2STR;
extern volatile SCI1S2STR _SCI1S2 @0xFFFF803D;
#define SCI1S2                          _SCI1S2.Byte
#define SCI1S2_RAF                      _SCI1S2.Bits.RAF
#define SCI1S2_LBKDE                    _SCI1S2.Bits.LBKDE
#define SCI1S2_BRK13                    _SCI1S2.Bits.BRK13
#define SCI1S2_RWUID                    _SCI1S2.Bits.RWUID
#define SCI1S2_RXINV                    _SCI1S2.Bits.RXINV
#define SCI1S2_RXEDGIF                  _SCI1S2.Bits.RXEDGIF
#define SCI1S2_LBKDIF                   _SCI1S2.Bits.LBKDIF

#define SCI1S2_RAF_MASK                 1U
#define SCI1S2_LBKDE_MASK               2U
#define SCI1S2_BRK13_MASK               4U
#define SCI1S2_RWUID_MASK               8U
#define SCI1S2_RXINV_MASK               16U
#define SCI1S2_RXEDGIF_MASK             64U
#define SCI1S2_LBKDIF_MASK              128U


/*** SCI1C3 - SCI1 Control Register 3; 0xFFFF803E ***/
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
} SCI1C3STR;
extern volatile SCI1C3STR _SCI1C3 @0xFFFF803E;
#define SCI1C3                          _SCI1C3.Byte
#define SCI1C3_PEIE                     _SCI1C3.Bits.PEIE
#define SCI1C3_FEIE                     _SCI1C3.Bits.FEIE
#define SCI1C3_NEIE                     _SCI1C3.Bits.NEIE
#define SCI1C3_ORIE                     _SCI1C3.Bits.ORIE
#define SCI1C3_TXINV                    _SCI1C3.Bits.TXINV
#define SCI1C3_TXDIR                    _SCI1C3.Bits.TXDIR
#define SCI1C3_T8                       _SCI1C3.Bits.T8
#define SCI1C3_R8                       _SCI1C3.Bits.R8

#define SCI1C3_PEIE_MASK                1U
#define SCI1C3_FEIE_MASK                2U
#define SCI1C3_NEIE_MASK                4U
#define SCI1C3_ORIE_MASK                8U
#define SCI1C3_TXINV_MASK               16U
#define SCI1C3_TXDIR_MASK               32U
#define SCI1C3_T8_MASK                  64U
#define SCI1C3_R8_MASK                  128U


/*** SCI1D - SCI1 Data Register; 0xFFFF803F ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCI1DSTR;
extern volatile SCI1DSTR _SCI1D @0xFFFF803F;
#define SCI1D                           _SCI1D.Byte
#define SCI1D_R0_T0                     _SCI1D.Bits.R0_T0
#define SCI1D_R1_T1                     _SCI1D.Bits.R1_T1
#define SCI1D_R2_T2                     _SCI1D.Bits.R2_T2
#define SCI1D_R3_T3                     _SCI1D.Bits.R3_T3
#define SCI1D_R4_T4                     _SCI1D.Bits.R4_T4
#define SCI1D_R5_T5                     _SCI1D.Bits.R5_T5
#define SCI1D_R6_T6                     _SCI1D.Bits.R6_T6
#define SCI1D_R7_T7                     _SCI1D.Bits.R7_T7

#define SCI1D_R0_T0_MASK                1U
#define SCI1D_R1_T1_MASK                2U
#define SCI1D_R2_T2_MASK                4U
#define SCI1D_R3_T3_MASK                8U
#define SCI1D_R4_T4_MASK                16U
#define SCI1D_R5_T5_MASK                32U
#define SCI1D_R6_T6_MASK                64U
#define SCI1D_R7_T7_MASK                128U


/*** SCI2BD - SCI2 Baud Rate Register; 0xFFFF8040 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI2BDH - SCI2 Baud Rate Register High; 0xFFFF8040 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCI2BDHSTR;
    #define SCI2BDH                     _SCI2BD.Overlap_STR.SCI2BDHSTR.Byte
    #define SCI2BDH_SBR8                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR8
    #define SCI2BDH_SBR9                _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR9
    #define SCI2BDH_SBR10               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR10
    #define SCI2BDH_SBR11               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR11
    #define SCI2BDH_SBR12               _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.SBR12
    #define SCI2BDH_RXEDGIE             _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.RXEDGIE
    #define SCI2BDH_LBKDIE              _SCI2BD.Overlap_STR.SCI2BDHSTR.Bits.LBKDIE
    #define SCI2BDH_SBR_8               _SCI2BD.Overlap_STR.SCI2BDHSTR.MergedBits.grpSBR_8
    #define SCI2BDH_SBR                 SCI2BDH_SBR_8
    
    #define SCI2BDH_SBR8_MASK           1U
    #define SCI2BDH_SBR9_MASK           2U
    #define SCI2BDH_SBR10_MASK          4U
    #define SCI2BDH_SBR11_MASK          8U
    #define SCI2BDH_SBR12_MASK          16U
    #define SCI2BDH_RXEDGIE_MASK        64U
    #define SCI2BDH_LBKDIE_MASK         128U
    #define SCI2BDH_SBR_8_MASK          31U
    #define SCI2BDH_SBR_8_BITNUM        0U
    

    /*** SCI2BDL - SCI2 Baud Rate Register Low; 0xFFFF8041 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCI2BDLSTR;
    #define SCI2BDL                     _SCI2BD.Overlap_STR.SCI2BDLSTR.Byte
    #define SCI2BDL_SBR0                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR0
    #define SCI2BDL_SBR1                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR1
    #define SCI2BDL_SBR2                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR2
    #define SCI2BDL_SBR3                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR3
    #define SCI2BDL_SBR4                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR4
    #define SCI2BDL_SBR5                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR5
    #define SCI2BDL_SBR6                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR6
    #define SCI2BDL_SBR7                _SCI2BD.Overlap_STR.SCI2BDLSTR.Bits.SBR7
    
    #define SCI2BDL_SBR0_MASK           1U
    #define SCI2BDL_SBR1_MASK           2U
    #define SCI2BDL_SBR2_MASK           4U
    #define SCI2BDL_SBR3_MASK           8U
    #define SCI2BDL_SBR4_MASK           16U
    #define SCI2BDL_SBR5_MASK           32U
    #define SCI2BDL_SBR6_MASK           64U
    #define SCI2BDL_SBR7_MASK           128U
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
    word SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
    word SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
    word SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
    word SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
    word SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
    word SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
    word SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
    word SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
    word SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
    word SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
    word SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
    word SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
    word             :1; 
    word RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
    word LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
  } Bits;
  struct {
    word grpSBR  :13;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} SCI2BDSTR;
extern volatile SCI2BDSTR _SCI2BD @0xFFFF8040;
#define SCI2BD                          _SCI2BD.Word
#define SCI2BD_SBR0                     _SCI2BD.Bits.SBR0
#define SCI2BD_SBR1                     _SCI2BD.Bits.SBR1
#define SCI2BD_SBR2                     _SCI2BD.Bits.SBR2
#define SCI2BD_SBR3                     _SCI2BD.Bits.SBR3
#define SCI2BD_SBR4                     _SCI2BD.Bits.SBR4
#define SCI2BD_SBR5                     _SCI2BD.Bits.SBR5
#define SCI2BD_SBR6                     _SCI2BD.Bits.SBR6
#define SCI2BD_SBR7                     _SCI2BD.Bits.SBR7
#define SCI2BD_SBR8                     _SCI2BD.Bits.SBR8
#define SCI2BD_SBR9                     _SCI2BD.Bits.SBR9
#define SCI2BD_SBR10                    _SCI2BD.Bits.SBR10
#define SCI2BD_SBR11                    _SCI2BD.Bits.SBR11
#define SCI2BD_SBR12                    _SCI2BD.Bits.SBR12
#define SCI2BD_RXEDGIE                  _SCI2BD.Bits.RXEDGIE
#define SCI2BD_LBKDIE                   _SCI2BD.Bits.LBKDIE
#define SCI2BD_SBR                      _SCI2BD.MergedBits.grpSBR

#define SCI2BD_SBR0_MASK                1U
#define SCI2BD_SBR1_MASK                2U
#define SCI2BD_SBR2_MASK                4U
#define SCI2BD_SBR3_MASK                8U
#define SCI2BD_SBR4_MASK                16U
#define SCI2BD_SBR5_MASK                32U
#define SCI2BD_SBR6_MASK                64U
#define SCI2BD_SBR7_MASK                128U
#define SCI2BD_SBR8_MASK                256U
#define SCI2BD_SBR9_MASK                512U
#define SCI2BD_SBR10_MASK               1024U
#define SCI2BD_SBR11_MASK               2048U
#define SCI2BD_SBR12_MASK               4096U
#define SCI2BD_RXEDGIE_MASK             16384U
#define SCI2BD_LBKDIE_MASK              32768U
#define SCI2BD_SBR_MASK                 8191U
#define SCI2BD_SBR_BITNUM               0U


/*** SCI2C1 - SCI2 Control Register 1; 0xFFFF8042 ***/
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
} SCI2C1STR;
extern volatile SCI2C1STR _SCI2C1 @0xFFFF8042;
#define SCI2C1                          _SCI2C1.Byte
#define SCI2C1_PT                       _SCI2C1.Bits.PT
#define SCI2C1_PE                       _SCI2C1.Bits.PE
#define SCI2C1_ILT                      _SCI2C1.Bits.ILT
#define SCI2C1_WAKE                     _SCI2C1.Bits.WAKE
#define SCI2C1_M                        _SCI2C1.Bits.M
#define SCI2C1_RSRC                     _SCI2C1.Bits.RSRC
#define SCI2C1_SCISWAI                  _SCI2C1.Bits.SCISWAI
#define SCI2C1_LOOPS                    _SCI2C1.Bits.LOOPS

#define SCI2C1_PT_MASK                  1U
#define SCI2C1_PE_MASK                  2U
#define SCI2C1_ILT_MASK                 4U
#define SCI2C1_WAKE_MASK                8U
#define SCI2C1_M_MASK                   16U
#define SCI2C1_RSRC_MASK                32U
#define SCI2C1_SCISWAI_MASK             64U
#define SCI2C1_LOOPS_MASK               128U


/*** SCI2C2 - SCI2 Control Register 2; 0xFFFF8043 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCI2C2STR;
extern volatile SCI2C2STR _SCI2C2 @0xFFFF8043;
#define SCI2C2                          _SCI2C2.Byte
#define SCI2C2_SBK                      _SCI2C2.Bits.SBK
#define SCI2C2_RWU                      _SCI2C2.Bits.RWU
#define SCI2C2_RE                       _SCI2C2.Bits.RE
#define SCI2C2_TE                       _SCI2C2.Bits.TE
#define SCI2C2_ILIE                     _SCI2C2.Bits.ILIE
#define SCI2C2_RIE                      _SCI2C2.Bits.RIE
#define SCI2C2_TCIE                     _SCI2C2.Bits.TCIE
#define SCI2C2_TIE                      _SCI2C2.Bits.TIE

#define SCI2C2_SBK_MASK                 1U
#define SCI2C2_RWU_MASK                 2U
#define SCI2C2_RE_MASK                  4U
#define SCI2C2_TE_MASK                  8U
#define SCI2C2_ILIE_MASK                16U
#define SCI2C2_RIE_MASK                 32U
#define SCI2C2_TCIE_MASK                64U
#define SCI2C2_TIE_MASK                 128U


/*** SCI2S1 - SCI2 Status Register 1; 0xFFFF8044 ***/
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
} SCI2S1STR;
extern volatile SCI2S1STR _SCI2S1 @0xFFFF8044;
#define SCI2S1                          _SCI2S1.Byte
#define SCI2S1_PF                       _SCI2S1.Bits.PF
#define SCI2S1_FE                       _SCI2S1.Bits.FE
#define SCI2S1_NF                       _SCI2S1.Bits.NF
#define SCI2S1_OR                       _SCI2S1.Bits.OR
#define SCI2S1_IDLE                     _SCI2S1.Bits.IDLE
#define SCI2S1_RDRF                     _SCI2S1.Bits.RDRF
#define SCI2S1_TC                       _SCI2S1.Bits.TC
#define SCI2S1_TDRE                     _SCI2S1.Bits.TDRE

#define SCI2S1_PF_MASK                  1U
#define SCI2S1_FE_MASK                  2U
#define SCI2S1_NF_MASK                  4U
#define SCI2S1_OR_MASK                  8U
#define SCI2S1_IDLE_MASK                16U
#define SCI2S1_RDRF_MASK                32U
#define SCI2S1_TC_MASK                  64U
#define SCI2S1_TDRE_MASK                128U


/*** SCI2S2 - SCI2 Status Register 2; 0xFFFF8045 ***/
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
} SCI2S2STR;
extern volatile SCI2S2STR _SCI2S2 @0xFFFF8045;
#define SCI2S2                          _SCI2S2.Byte
#define SCI2S2_RAF                      _SCI2S2.Bits.RAF
#define SCI2S2_LBKDE                    _SCI2S2.Bits.LBKDE
#define SCI2S2_BRK13                    _SCI2S2.Bits.BRK13
#define SCI2S2_RWUID                    _SCI2S2.Bits.RWUID
#define SCI2S2_RXINV                    _SCI2S2.Bits.RXINV
#define SCI2S2_RXEDGIF                  _SCI2S2.Bits.RXEDGIF
#define SCI2S2_LBKDIF                   _SCI2S2.Bits.LBKDIF

#define SCI2S2_RAF_MASK                 1U
#define SCI2S2_LBKDE_MASK               2U
#define SCI2S2_BRK13_MASK               4U
#define SCI2S2_RWUID_MASK               8U
#define SCI2S2_RXINV_MASK               16U
#define SCI2S2_RXEDGIF_MASK             64U
#define SCI2S2_LBKDIF_MASK              128U


/*** SCI2C3 - SCI2 Control Register 3; 0xFFFF8046 ***/
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
} SCI2C3STR;
extern volatile SCI2C3STR _SCI2C3 @0xFFFF8046;
#define SCI2C3                          _SCI2C3.Byte
#define SCI2C3_PEIE                     _SCI2C3.Bits.PEIE
#define SCI2C3_FEIE                     _SCI2C3.Bits.FEIE
#define SCI2C3_NEIE                     _SCI2C3.Bits.NEIE
#define SCI2C3_ORIE                     _SCI2C3.Bits.ORIE
#define SCI2C3_TXINV                    _SCI2C3.Bits.TXINV
#define SCI2C3_TXDIR                    _SCI2C3.Bits.TXDIR
#define SCI2C3_T8                       _SCI2C3.Bits.T8
#define SCI2C3_R8                       _SCI2C3.Bits.R8

#define SCI2C3_PEIE_MASK                1U
#define SCI2C3_FEIE_MASK                2U
#define SCI2C3_NEIE_MASK                4U
#define SCI2C3_ORIE_MASK                8U
#define SCI2C3_TXINV_MASK               16U
#define SCI2C3_TXDIR_MASK               32U
#define SCI2C3_T8_MASK                  64U
#define SCI2C3_R8_MASK                  128U


/*** SCI2D - SCI2 Data Register; 0xFFFF8047 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCI2DSTR;
extern volatile SCI2DSTR _SCI2D @0xFFFF8047;
#define SCI2D                           _SCI2D.Byte
#define SCI2D_R0_T0                     _SCI2D.Bits.R0_T0
#define SCI2D_R1_T1                     _SCI2D.Bits.R1_T1
#define SCI2D_R2_T2                     _SCI2D.Bits.R2_T2
#define SCI2D_R3_T3                     _SCI2D.Bits.R3_T3
#define SCI2D_R4_T4                     _SCI2D.Bits.R4_T4
#define SCI2D_R5_T5                     _SCI2D.Bits.R5_T5
#define SCI2D_R6_T6                     _SCI2D.Bits.R6_T6
#define SCI2D_R7_T7                     _SCI2D.Bits.R7_T7

#define SCI2D_R0_T0_MASK                1U
#define SCI2D_R1_T1_MASK                2U
#define SCI2D_R2_T2_MASK                4U
#define SCI2D_R3_T3_MASK                8U
#define SCI2D_R4_T4_MASK                16U
#define SCI2D_R5_T5_MASK                32U
#define SCI2D_R6_T6_MASK                64U
#define SCI2D_R7_T7_MASK                128U


/*** MCGC1 - MCG Control Register 1; 0xFFFF8048 ***/
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
} MCGC1STR;
extern volatile MCGC1STR _MCGC1 @0xFFFF8048;
#define MCGC1                           _MCGC1.Byte
#define MCGC1_IREFSTEN                  _MCGC1.Bits.IREFSTEN
#define MCGC1_IRCLKEN                   _MCGC1.Bits.IRCLKEN
#define MCGC1_IREFS                     _MCGC1.Bits.IREFS
#define MCGC1_RDIV0                     _MCGC1.Bits.RDIV0
#define MCGC1_RDIV1                     _MCGC1.Bits.RDIV1
#define MCGC1_RDIV2                     _MCGC1.Bits.RDIV2
#define MCGC1_CLKS0                     _MCGC1.Bits.CLKS0
#define MCGC1_CLKS1                     _MCGC1.Bits.CLKS1
#define MCGC1_RDIV                      _MCGC1.MergedBits.grpRDIV
#define MCGC1_CLKS                      _MCGC1.MergedBits.grpCLKS

#define MCGC1_IREFSTEN_MASK             1U
#define MCGC1_IRCLKEN_MASK              2U
#define MCGC1_IREFS_MASK                4U
#define MCGC1_RDIV0_MASK                8U
#define MCGC1_RDIV1_MASK                16U
#define MCGC1_RDIV2_MASK                32U
#define MCGC1_CLKS0_MASK                64U
#define MCGC1_CLKS1_MASK                128U
#define MCGC1_RDIV_MASK                 56U
#define MCGC1_RDIV_BITNUM               3U
#define MCGC1_CLKS_MASK                 192U
#define MCGC1_CLKS_BITNUM               6U


/*** MCGC2 - MCG Control Register 2; 0xFFFF8049 ***/
typedef union {
  byte Byte;
  struct {
    byte EREFSTEN    :1;                                       /* External Reference Stop Enable */
    byte ERCLKEN     :1;                                       /* External Reference Enable */
    byte EREFS       :1;                                       /* External Reference Select */
    byte LP          :1;                                       /* Low Power Select */
    byte HGO         :1;                                       /* High Gain Oscillator Select */
    byte RANGE       :1;                                       /* Frequency Range Select */
    byte BDIV0       :1;                                       /* Bus Frequency Divider, bit 0 */
    byte BDIV1       :1;                                       /* Bus Frequency Divider, bit 1 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpBDIV :2;
  } MergedBits;
} MCGC2STR;
extern volatile MCGC2STR _MCGC2 @0xFFFF8049;
#define MCGC2                           _MCGC2.Byte
#define MCGC2_EREFSTEN                  _MCGC2.Bits.EREFSTEN
#define MCGC2_ERCLKEN                   _MCGC2.Bits.ERCLKEN
#define MCGC2_EREFS                     _MCGC2.Bits.EREFS
#define MCGC2_LP                        _MCGC2.Bits.LP
#define MCGC2_HGO                       _MCGC2.Bits.HGO
#define MCGC2_RANGE                     _MCGC2.Bits.RANGE
#define MCGC2_BDIV0                     _MCGC2.Bits.BDIV0
#define MCGC2_BDIV1                     _MCGC2.Bits.BDIV1
#define MCGC2_BDIV                      _MCGC2.MergedBits.grpBDIV

#define MCGC2_EREFSTEN_MASK             1U
#define MCGC2_ERCLKEN_MASK              2U
#define MCGC2_EREFS_MASK                4U
#define MCGC2_LP_MASK                   8U
#define MCGC2_HGO_MASK                  16U
#define MCGC2_RANGE_MASK                32U
#define MCGC2_BDIV0_MASK                64U
#define MCGC2_BDIV1_MASK                128U
#define MCGC2_BDIV_MASK                 192U
#define MCGC2_BDIV_BITNUM               6U


/*** MCGTRM - MCG Trim Register; 0xFFFF804A ***/
typedef union {
  byte Byte;
  struct {
    byte TRIM0       :1;                                       /* MCG Trim Setting, bit 0 */
    byte TRIM1       :1;                                       /* MCG Trim Setting, bit 1 */
    byte TRIM2       :1;                                       /* MCG Trim Setting, bit 2 */
    byte TRIM3       :1;                                       /* MCG Trim Setting, bit 3 */
    byte TRIM4       :1;                                       /* MCG Trim Setting, bit 4 */
    byte TRIM5       :1;                                       /* MCG Trim Setting, bit 5 */
    byte TRIM6       :1;                                       /* MCG Trim Setting, bit 6 */
    byte TRIM7       :1;                                       /* MCG Trim Setting, bit 7 */
  } Bits;
} MCGTRMSTR;
extern volatile MCGTRMSTR _MCGTRM @0xFFFF804A;
#define MCGTRM                          _MCGTRM.Byte
#define MCGTRM_TRIM0                    _MCGTRM.Bits.TRIM0
#define MCGTRM_TRIM1                    _MCGTRM.Bits.TRIM1
#define MCGTRM_TRIM2                    _MCGTRM.Bits.TRIM2
#define MCGTRM_TRIM3                    _MCGTRM.Bits.TRIM3
#define MCGTRM_TRIM4                    _MCGTRM.Bits.TRIM4
#define MCGTRM_TRIM5                    _MCGTRM.Bits.TRIM5
#define MCGTRM_TRIM6                    _MCGTRM.Bits.TRIM6
#define MCGTRM_TRIM7                    _MCGTRM.Bits.TRIM7

#define MCGTRM_TRIM0_MASK               1U
#define MCGTRM_TRIM1_MASK               2U
#define MCGTRM_TRIM2_MASK               4U
#define MCGTRM_TRIM3_MASK               8U
#define MCGTRM_TRIM4_MASK               16U
#define MCGTRM_TRIM5_MASK               32U
#define MCGTRM_TRIM6_MASK               64U
#define MCGTRM_TRIM7_MASK               128U


/*** MCGSC - MCG Status and Control Register; 0xFFFF804B ***/
typedef union {
  byte Byte;
  struct {
    byte FTRIM       :1;                                       /* MCG Fine Trim */
    byte OSCINIT     :1;                                       /* OSC Initialization */
    byte CLKST0      :1;                                       /* Clock Mode Status, bit 0 */
    byte CLKST1      :1;                                       /* Clock Mode Status, bit 1 */
    byte IREFST      :1;                                       /* Internal Reference Status */
    byte PLLST       :1;                                       /* PLL Select Status */
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
} MCGSCSTR;
extern volatile MCGSCSTR _MCGSC @0xFFFF804B;
#define MCGSC                           _MCGSC.Byte
#define MCGSC_FTRIM                     _MCGSC.Bits.FTRIM
#define MCGSC_OSCINIT                   _MCGSC.Bits.OSCINIT
#define MCGSC_CLKST0                    _MCGSC.Bits.CLKST0
#define MCGSC_CLKST1                    _MCGSC.Bits.CLKST1
#define MCGSC_IREFST                    _MCGSC.Bits.IREFST
#define MCGSC_PLLST                     _MCGSC.Bits.PLLST
#define MCGSC_LOCK                      _MCGSC.Bits.LOCK
#define MCGSC_LOLS                      _MCGSC.Bits.LOLS
#define MCGSC_CLKST                     _MCGSC.MergedBits.grpCLKST

#define MCGSC_FTRIM_MASK                1U
#define MCGSC_OSCINIT_MASK              2U
#define MCGSC_CLKST0_MASK               4U
#define MCGSC_CLKST1_MASK               8U
#define MCGSC_IREFST_MASK               16U
#define MCGSC_PLLST_MASK                32U
#define MCGSC_LOCK_MASK                 64U
#define MCGSC_LOLS_MASK                 128U
#define MCGSC_CLKST_MASK                12U
#define MCGSC_CLKST_BITNUM              2U


/*** MCGC3 - MCG Control Register 3; 0xFFFF804C ***/
typedef union {
  byte Byte;
  struct {
    byte VDIV0       :1;                                       /* VCO Divider, bit 0 */
    byte VDIV1       :1;                                       /* VCO Divider, bit 1 */
    byte VDIV2       :1;                                       /* VCO Divider, bit 2 */
    byte VDIV3       :1;                                       /* VCO Divider, bit 3 */
    byte DIV32       :1;                                       /* Divide-by-32 Enable */
    byte CME         :1;                                       /* Clock Monitor Enable */
    byte PLLS        :1;                                       /* PLL Select */
    byte LOLIE       :1;                                       /* Loss of Lock Interrupt Enable */
  } Bits;
  struct {
    byte grpVDIV :4;
    byte grpDIV_32 :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGC3STR;
extern volatile MCGC3STR _MCGC3 @0xFFFF804C;
#define MCGC3                           _MCGC3.Byte
#define MCGC3_VDIV0                     _MCGC3.Bits.VDIV0
#define MCGC3_VDIV1                     _MCGC3.Bits.VDIV1
#define MCGC3_VDIV2                     _MCGC3.Bits.VDIV2
#define MCGC3_VDIV3                     _MCGC3.Bits.VDIV3
#define MCGC3_DIV32                     _MCGC3.Bits.DIV32
#define MCGC3_CME                       _MCGC3.Bits.CME
#define MCGC3_PLLS                      _MCGC3.Bits.PLLS
#define MCGC3_LOLIE                     _MCGC3.Bits.LOLIE
#define MCGC3_VDIV                      _MCGC3.MergedBits.grpVDIV

#define MCGC3_VDIV0_MASK                1U
#define MCGC3_VDIV1_MASK                2U
#define MCGC3_VDIV2_MASK                4U
#define MCGC3_VDIV3_MASK                8U
#define MCGC3_DIV32_MASK                16U
#define MCGC3_CME_MASK                  32U
#define MCGC3_PLLS_MASK                 64U
#define MCGC3_LOLIE_MASK                128U
#define MCGC3_VDIV_MASK                 15U
#define MCGC3_VDIV_BITNUM               0U


/*** MCGC4 - MCG Control Register 4; 0xFFFF804D ***/
typedef union {
  byte Byte;
  struct {
    byte DRST_DRS0   :1;                                       /* DCO Range Status / DCO Range Select, bit 0 */
    byte DRST_DRS1   :1;                                       /* DCO Range Status / DCO Range Select, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DMX32       :1;                                       /* DCO Maximum frequency with 32.768 kHz reference */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDRST_DRS :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDMX_32 :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} MCGC4STR;
extern volatile MCGC4STR _MCGC4 @0xFFFF804D;
#define MCGC4                           _MCGC4.Byte
#define MCGC4_DRST_DRS0                 _MCGC4.Bits.DRST_DRS0
#define MCGC4_DRST_DRS1                 _MCGC4.Bits.DRST_DRS1
#define MCGC4_DMX32                     _MCGC4.Bits.DMX32
#define MCGC4_DRST_DRS                  _MCGC4.MergedBits.grpDRST_DRS

#define MCGC4_DRST_DRS0_MASK            1U
#define MCGC4_DRST_DRS1_MASK            2U
#define MCGC4_DMX32_MASK                32U
#define MCGC4_DRST_DRS_MASK             3U
#define MCGC4_DRST_DRS_BITNUM           0U


/*** SPI1C1 - SPI1 Control Register 1; 0xFFFF8050 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPI1C1STR;
extern volatile SPI1C1STR _SPI1C1 @0xFFFF8050;
#define SPI1C1                          _SPI1C1.Byte
#define SPI1C1_LSBFE                    _SPI1C1.Bits.LSBFE
#define SPI1C1_SSOE                     _SPI1C1.Bits.SSOE
#define SPI1C1_CPHA                     _SPI1C1.Bits.CPHA
#define SPI1C1_CPOL                     _SPI1C1.Bits.CPOL
#define SPI1C1_MSTR                     _SPI1C1.Bits.MSTR
#define SPI1C1_SPTIE                    _SPI1C1.Bits.SPTIE
#define SPI1C1_SPE                      _SPI1C1.Bits.SPE
#define SPI1C1_SPIE                     _SPI1C1.Bits.SPIE

#define SPI1C1_LSBFE_MASK               1U
#define SPI1C1_SSOE_MASK                2U
#define SPI1C1_CPHA_MASK                4U
#define SPI1C1_CPOL_MASK                8U
#define SPI1C1_MSTR_MASK                16U
#define SPI1C1_SPTIE_MASK               32U
#define SPI1C1_SPE_MASK                 64U
#define SPI1C1_SPIE_MASK                128U


/*** SPI1C2 - SPI1 Control Register 2; 0xFFFF8051 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI1C2STR;
extern volatile SPI1C2STR _SPI1C2 @0xFFFF8051;
#define SPI1C2                          _SPI1C2.Byte
#define SPI1C2_SPC0                     _SPI1C2.Bits.SPC0
#define SPI1C2_SPISWAI                  _SPI1C2.Bits.SPISWAI
#define SPI1C2_BIDIROE                  _SPI1C2.Bits.BIDIROE
#define SPI1C2_MODFEN                   _SPI1C2.Bits.MODFEN

#define SPI1C2_SPC0_MASK                1U
#define SPI1C2_SPISWAI_MASK             2U
#define SPI1C2_BIDIROE_MASK             8U
#define SPI1C2_MODFEN_MASK              16U


/*** SPI1BR - SPI1 Baud Rate Register; 0xFFFF8052 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI1BRSTR;
extern volatile SPI1BRSTR _SPI1BR @0xFFFF8052;
#define SPI1BR                          _SPI1BR.Byte
#define SPI1BR_SPR0                     _SPI1BR.Bits.SPR0
#define SPI1BR_SPR1                     _SPI1BR.Bits.SPR1
#define SPI1BR_SPR2                     _SPI1BR.Bits.SPR2
#define SPI1BR_SPPR0                    _SPI1BR.Bits.SPPR0
#define SPI1BR_SPPR1                    _SPI1BR.Bits.SPPR1
#define SPI1BR_SPPR2                    _SPI1BR.Bits.SPPR2
#define SPI1BR_SPR                      _SPI1BR.MergedBits.grpSPR
#define SPI1BR_SPPR                     _SPI1BR.MergedBits.grpSPPR

#define SPI1BR_SPR0_MASK                1U
#define SPI1BR_SPR1_MASK                2U
#define SPI1BR_SPR2_MASK                4U
#define SPI1BR_SPPR0_MASK               16U
#define SPI1BR_SPPR1_MASK               32U
#define SPI1BR_SPPR2_MASK               64U
#define SPI1BR_SPR_MASK                 7U
#define SPI1BR_SPR_BITNUM               0U
#define SPI1BR_SPPR_MASK                112U
#define SPI1BR_SPPR_BITNUM              4U


/*** SPI1S - SPI1 Status Register; 0xFFFF8053 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPI1SSTR;
extern volatile SPI1SSTR _SPI1S @0xFFFF8053;
#define SPI1S                           _SPI1S.Byte
#define SPI1S_MODF                      _SPI1S.Bits.MODF
#define SPI1S_SPTEF                     _SPI1S.Bits.SPTEF
#define SPI1S_SPRF                      _SPI1S.Bits.SPRF

#define SPI1S_MODF_MASK                 16U
#define SPI1S_SPTEF_MASK                32U
#define SPI1S_SPRF_MASK                 128U


/*** SPI1D - SPI1 Data Register; 0xFFFF8055 ***/
typedef union {
  byte Byte;
} SPI1DSTR;
extern volatile SPI1DSTR _SPI1D @0xFFFF8055;
#define SPI1D                           _SPI1D.Byte


/*** IICA - IIC Address Register; 0xFFFF8058 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte AD1         :1;                                       /* Slave Address Bit 1 */
    byte AD2         :1;                                       /* Slave Address Bit 2 */
    byte AD3         :1;                                       /* Slave Address Bit 3 */
    byte AD4         :1;                                       /* Slave Address Bit 4 */
    byte AD5         :1;                                       /* Slave Address Bit 5 */
    byte AD6         :1;                                       /* Slave Address Bit 6 */
    byte AD7         :1;                                       /* Slave Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpAD_1 :7;
  } MergedBits;
} IICASTR;
extern volatile IICASTR _IICA @0xFFFF8058;
#define IICA                            _IICA.Byte
#define IICA_AD1                        _IICA.Bits.AD1
#define IICA_AD2                        _IICA.Bits.AD2
#define IICA_AD3                        _IICA.Bits.AD3
#define IICA_AD4                        _IICA.Bits.AD4
#define IICA_AD5                        _IICA.Bits.AD5
#define IICA_AD6                        _IICA.Bits.AD6
#define IICA_AD7                        _IICA.Bits.AD7
#define IICA_AD_1                       _IICA.MergedBits.grpAD_1
#define IICA_AD                         IICA_AD_1

#define IICA_AD1_MASK                   2U
#define IICA_AD2_MASK                   4U
#define IICA_AD3_MASK                   8U
#define IICA_AD4_MASK                   16U
#define IICA_AD5_MASK                   32U
#define IICA_AD6_MASK                   64U
#define IICA_AD7_MASK                   128U
#define IICA_AD_1_MASK                  254U
#define IICA_AD_1_BITNUM                1U


/*** IICF - IIC Frequency Divider Register; 0xFFFF8059 ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IICFSTR;
extern volatile IICFSTR _IICF @0xFFFF8059;
#define IICF                            _IICF.Byte
#define IICF_ICR0                       _IICF.Bits.ICR0
#define IICF_ICR1                       _IICF.Bits.ICR1
#define IICF_ICR2                       _IICF.Bits.ICR2
#define IICF_ICR3                       _IICF.Bits.ICR3
#define IICF_ICR4                       _IICF.Bits.ICR4
#define IICF_ICR5                       _IICF.Bits.ICR5
#define IICF_MULT0                      _IICF.Bits.MULT0
#define IICF_MULT1                      _IICF.Bits.MULT1
#define IICF_ICR                        _IICF.MergedBits.grpICR
#define IICF_MULT                       _IICF.MergedBits.grpMULT

#define IICF_ICR0_MASK                  1U
#define IICF_ICR1_MASK                  2U
#define IICF_ICR2_MASK                  4U
#define IICF_ICR3_MASK                  8U
#define IICF_ICR4_MASK                  16U
#define IICF_ICR5_MASK                  32U
#define IICF_MULT0_MASK                 64U
#define IICF_MULT1_MASK                 128U
#define IICF_ICR_MASK                   63U
#define IICF_ICR_BITNUM                 0U
#define IICF_MULT_MASK                  192U
#define IICF_MULT_BITNUM                6U


/*** IICC1 - IIC Control Register 1; 0xFFFF805A ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IICC1 - IIC Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICC1STR;
    #define IICC1                       _IICC1.Byte
    #define IICC1_RSTA                  _IICC1.SameAddr_STR.IICC1STR.Bits.RSTA
    #define IICC1_TXAK                  _IICC1.SameAddr_STR.IICC1STR.Bits.TXAK
    #define IICC1_TX                    _IICC1.SameAddr_STR.IICC1STR.Bits.TX
    #define IICC1_MST                   _IICC1.SameAddr_STR.IICC1STR.Bits.MST
    #define IICC1_IICIE                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICIE
    #define IICC1_IICEN                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICEN
    
    #define IICC1_RSTA_MASK             4U
    #define IICC1_TXAK_MASK             8U
    #define IICC1_TX_MASK               16U
    #define IICC1_MST_MASK              32U
    #define IICC1_IICIE_MASK            64U
    #define IICC1_IICEN_MASK            128U
    
    /*** IICC - IIC Control Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICCSTR;
    #define IICC                        _IICC1.Byte
    #define IICC_RSTA                   _IICC1.SameAddr_STR.IICCSTR.Bits.RSTA
    #define IICC_TXAK                   _IICC1.SameAddr_STR.IICCSTR.Bits.TXAK
    #define IICC_TX                     _IICC1.SameAddr_STR.IICCSTR.Bits.TX
    #define IICC_MST                    _IICC1.SameAddr_STR.IICCSTR.Bits.MST
    #define IICC_IICIE                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICIE
    #define IICC_IICEN                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICEN
    
    #define IICC_RSTA_MASK              4U
    #define IICC_TXAK_MASK              8U
    #define IICC_TX_MASK                16U
    #define IICC_MST_MASK               32U
    #define IICC_IICIE_MASK             64U
    #define IICC_IICEN_MASK             128U
    
  } SameAddr_STR; /*Several registers at the same address */

} IICC1STR;
extern volatile IICC1STR _IICC1 @0xFFFF805A;


/*** IICS - IIC Status Register; 0xFFFF805B ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy */
    byte IAAS        :1;                                       /* Addressed as a Slave */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IICSSTR;
extern volatile IICSSTR _IICS @0xFFFF805B;
#define IICS                            _IICS.Byte
#define IICS_RXAK                       _IICS.Bits.RXAK
#define IICS_IICIF                      _IICS.Bits.IICIF
#define IICS_SRW                        _IICS.Bits.SRW
#define IICS_ARBL                       _IICS.Bits.ARBL
#define IICS_BUSY                       _IICS.Bits.BUSY
#define IICS_IAAS                       _IICS.Bits.IAAS
#define IICS_TCF                        _IICS.Bits.TCF

#define IICS_RXAK_MASK                  1U
#define IICS_IICIF_MASK                 2U
#define IICS_SRW_MASK                   4U
#define IICS_ARBL_MASK                  16U
#define IICS_BUSY_MASK                  32U
#define IICS_IAAS_MASK                  64U
#define IICS_TCF_MASK                   128U


/*** IICD - IIC Data I/O Register; 0xFFFF805C ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IICDSTR;
extern volatile IICDSTR _IICD @0xFFFF805C;
#define IICD                            _IICD.Byte
#define IICD_DATA0                      _IICD.Bits.DATA0
#define IICD_DATA1                      _IICD.Bits.DATA1
#define IICD_DATA2                      _IICD.Bits.DATA2
#define IICD_DATA3                      _IICD.Bits.DATA3
#define IICD_DATA4                      _IICD.Bits.DATA4
#define IICD_DATA5                      _IICD.Bits.DATA5
#define IICD_DATA6                      _IICD.Bits.DATA6
#define IICD_DATA7                      _IICD.Bits.DATA7

#define IICD_DATA0_MASK                 1U
#define IICD_DATA1_MASK                 2U
#define IICD_DATA2_MASK                 4U
#define IICD_DATA3_MASK                 8U
#define IICD_DATA4_MASK                 16U
#define IICD_DATA5_MASK                 32U
#define IICD_DATA6_MASK                 64U
#define IICD_DATA7_MASK                 128U


/*** IICC2 - IIC Control Register 2; 0xFFFF805D ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       /* Slave Address Bit 8 */
    byte AD9         :1;                                       /* Slave Address Bit 9 */
    byte AD10        :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       /* Address Extension */
    byte GCAEN       :1;                                       /* General Call Address Enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICC2STR;
extern volatile IICC2STR _IICC2 @0xFFFF805D;
#define IICC2                           _IICC2.Byte
#define IICC2_AD8                       _IICC2.Bits.AD8
#define IICC2_AD9                       _IICC2.Bits.AD9
#define IICC2_AD10                      _IICC2.Bits.AD10
#define IICC2_ADEXT                     _IICC2.Bits.ADEXT
#define IICC2_GCAEN                     _IICC2.Bits.GCAEN
#define IICC2_AD_8                      _IICC2.MergedBits.grpAD_8
#define IICC2_AD                        IICC2_AD_8

#define IICC2_AD8_MASK                  1U
#define IICC2_AD9_MASK                  2U
#define IICC2_AD10_MASK                 4U
#define IICC2_ADEXT_MASK                64U
#define IICC2_GCAEN_MASK                128U
#define IICC2_AD_8_MASK                 7U
#define IICC2_AD_8_BITNUM               0U


/*** ACMP1SC - ACMP1 Status and Control Register; 0xFFFF805E ***/
typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       /* Analog Comparator Mode Bit 0 */
    byte ACMOD1      :1;                                       /* Analog Comparator Mode Bit 1 */
    byte ACOPE       :1;                                       /* Analog Comparator Output Pin Enable */
    byte ACO         :1;                                       /* Analog Comparator Output */
    byte ACIE        :1;                                       /* Analog Comparator Interrupt Enable */
    byte ACF         :1;                                       /* Analog Comparator Flag */
    byte ACBGS       :1;                                       /* Analog Comparator Bandgap Select */
    byte ACME        :1;                                       /* Analog Comparator Module Enable */
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
} ACMP1SCSTR;
extern volatile ACMP1SCSTR _ACMP1SC @0xFFFF805E;
#define ACMP1SC                         _ACMP1SC.Byte
#define ACMP1SC_ACMOD0                  _ACMP1SC.Bits.ACMOD0
#define ACMP1SC_ACMOD1                  _ACMP1SC.Bits.ACMOD1
#define ACMP1SC_ACOPE                   _ACMP1SC.Bits.ACOPE
#define ACMP1SC_ACO                     _ACMP1SC.Bits.ACO
#define ACMP1SC_ACIE                    _ACMP1SC.Bits.ACIE
#define ACMP1SC_ACF                     _ACMP1SC.Bits.ACF
#define ACMP1SC_ACBGS                   _ACMP1SC.Bits.ACBGS
#define ACMP1SC_ACME                    _ACMP1SC.Bits.ACME
#define ACMP1SC_ACMOD                   _ACMP1SC.MergedBits.grpACMOD

#define ACMP1SC_ACMOD0_MASK             1U
#define ACMP1SC_ACMOD1_MASK             2U
#define ACMP1SC_ACOPE_MASK              4U
#define ACMP1SC_ACO_MASK                8U
#define ACMP1SC_ACIE_MASK               16U
#define ACMP1SC_ACF_MASK                32U
#define ACMP1SC_ACBGS_MASK              64U
#define ACMP1SC_ACME_MASK               128U
#define ACMP1SC_ACMOD_MASK              3U
#define ACMP1SC_ACMOD_BITNUM            0U


/*** ACMP2SC - ACMP2 Status and Control Register; 0xFFFF805F ***/
typedef union {
  byte Byte;
  struct {
    byte ACMOD0      :1;                                       /* Analog Comparator Mode Bit 0 */
    byte ACMOD1      :1;                                       /* Analog Comparator Mode Bit 1 */
    byte ACOPE       :1;                                       /* Analog Comparator Output Pin Enable */
    byte ACO         :1;                                       /* Analog Comparator Output */
    byte ACIE        :1;                                       /* Analog Comparator Interrupt Enable */
    byte ACF         :1;                                       /* Analog Comparator Flag */
    byte ACBGS       :1;                                       /* Analog Comparator Bandgap Select */
    byte ACME        :1;                                       /* Analog Comparator Module Enable */
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
} ACMP2SCSTR;
extern volatile ACMP2SCSTR _ACMP2SC @0xFFFF805F;
#define ACMP2SC                         _ACMP2SC.Byte
#define ACMP2SC_ACMOD0                  _ACMP2SC.Bits.ACMOD0
#define ACMP2SC_ACMOD1                  _ACMP2SC.Bits.ACMOD1
#define ACMP2SC_ACOPE                   _ACMP2SC.Bits.ACOPE
#define ACMP2SC_ACO                     _ACMP2SC.Bits.ACO
#define ACMP2SC_ACIE                    _ACMP2SC.Bits.ACIE
#define ACMP2SC_ACF                     _ACMP2SC.Bits.ACF
#define ACMP2SC_ACBGS                   _ACMP2SC.Bits.ACBGS
#define ACMP2SC_ACME                    _ACMP2SC.Bits.ACME
#define ACMP2SC_ACMOD                   _ACMP2SC.MergedBits.grpACMOD

#define ACMP2SC_ACMOD0_MASK             1U
#define ACMP2SC_ACMOD1_MASK             2U
#define ACMP2SC_ACOPE_MASK              4U
#define ACMP2SC_ACO_MASK                8U
#define ACMP2SC_ACIE_MASK               16U
#define ACMP2SC_ACF_MASK                32U
#define ACMP2SC_ACBGS_MASK              64U
#define ACMP2SC_ACME_MASK               128U
#define ACMP2SC_ACMOD_MASK              3U
#define ACMP2SC_ACMOD_BITNUM            0U


/*** FTM1SC - FTM1 Status and Control Register; 0xFFFF8080 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1SCSTR;
extern volatile FTM1SCSTR _FTM1SC @0xFFFF8080;
#define FTM1SC                          _FTM1SC.Byte
#define FTM1SC_PS0                      _FTM1SC.Bits.PS0
#define FTM1SC_PS1                      _FTM1SC.Bits.PS1
#define FTM1SC_PS2                      _FTM1SC.Bits.PS2
#define FTM1SC_CLKSA                    _FTM1SC.Bits.CLKSA
#define FTM1SC_CLKSB                    _FTM1SC.Bits.CLKSB
#define FTM1SC_CPWMS                    _FTM1SC.Bits.CPWMS
#define FTM1SC_TOIE                     _FTM1SC.Bits.TOIE
#define FTM1SC_TOF                      _FTM1SC.Bits.TOF
#define FTM1SC_PS                       _FTM1SC.MergedBits.grpPS
#define FTM1SC_CLKSx                    _FTM1SC.MergedBits.grpCLKSx

#define FTM1SC_PS0_MASK                 1U
#define FTM1SC_PS1_MASK                 2U
#define FTM1SC_PS2_MASK                 4U
#define FTM1SC_CLKSA_MASK               8U
#define FTM1SC_CLKSB_MASK               16U
#define FTM1SC_CPWMS_MASK               32U
#define FTM1SC_TOIE_MASK                64U
#define FTM1SC_TOF_MASK                 128U
#define FTM1SC_PS_MASK                  7U
#define FTM1SC_PS_BITNUM                0U
#define FTM1SC_CLKSx_MASK               24U
#define FTM1SC_CLKSx_BITNUM             3U


/*** FTM1CNT - FTM1 Timer Counter Register; 0xFFFF8081 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1CNTH - FTM1 Timer Counter Register High; 0xFFFF8081 ***/
    union {
      byte Byte;
    } FTM1CNTHSTR;
    #define FTM1CNTH                    _FTM1CNT.Overlap_STR.FTM1CNTHSTR.Byte
    

    /*** FTM1CNTL - FTM1 Timer Counter Register Low; 0xFFFF8082 ***/
    union {
      byte Byte;
    } FTM1CNTLSTR;
    #define FTM1CNTL                    _FTM1CNT.Overlap_STR.FTM1CNTLSTR.Byte
    
  } Overlap_STR;

} FTM1CNTSTR;
extern volatile FTM1CNTSTR _FTM1CNT @0xFFFF8081;
#define FTM1CNT                         _FTM1CNT.Word


/*** FTM1MOD - FTM1 Timer Counter Modulo Register; 0xFFFF8083 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1MODH - FTM1 Timer Counter Modulo Register High; 0xFFFF8083 ***/
    union {
      byte Byte;
    } FTM1MODHSTR;
    #define FTM1MODH                    _FTM1MOD.Overlap_STR.FTM1MODHSTR.Byte
    

    /*** FTM1MODL - FTM1 Timer Counter Modulo Register Low; 0xFFFF8084 ***/
    union {
      byte Byte;
    } FTM1MODLSTR;
    #define FTM1MODL                    _FTM1MOD.Overlap_STR.FTM1MODLSTR.Byte
    
  } Overlap_STR;

} FTM1MODSTR;
extern volatile FTM1MODSTR _FTM1MOD @0xFFFF8083;
#define FTM1MOD                         _FTM1MOD.Word


/*** FTM1C0SC - FTM1 Timer Channel 0 Status and Control Register; 0xFFFF8085 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for FTM1 Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for FTM1 Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1C0SCSTR;
extern volatile FTM1C0SCSTR _FTM1C0SC @0xFFFF8085;
#define FTM1C0SC                        _FTM1C0SC.Byte
#define FTM1C0SC_ELS0A                  _FTM1C0SC.Bits.ELS0A
#define FTM1C0SC_ELS0B                  _FTM1C0SC.Bits.ELS0B
#define FTM1C0SC_MS0A                   _FTM1C0SC.Bits.MS0A
#define FTM1C0SC_MS0B                   _FTM1C0SC.Bits.MS0B
#define FTM1C0SC_CH0IE                  _FTM1C0SC.Bits.CH0IE
#define FTM1C0SC_CH0F                   _FTM1C0SC.Bits.CH0F
#define FTM1C0SC_ELS0x                  _FTM1C0SC.MergedBits.grpELS0x
#define FTM1C0SC_MS0x                   _FTM1C0SC.MergedBits.grpMS0x

#define FTM1C0SC_ELS0A_MASK             4U
#define FTM1C0SC_ELS0B_MASK             8U
#define FTM1C0SC_MS0A_MASK              16U
#define FTM1C0SC_MS0B_MASK              32U
#define FTM1C0SC_CH0IE_MASK             64U
#define FTM1C0SC_CH0F_MASK              128U
#define FTM1C0SC_ELS0x_MASK             12U
#define FTM1C0SC_ELS0x_BITNUM           2U
#define FTM1C0SC_MS0x_MASK              48U
#define FTM1C0SC_MS0x_BITNUM            4U


/*** FTM1C0V - FTM1 Timer Channel 0 Value Register; 0xFFFF8086 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1C0VH - FTM1 Timer Channel 0 Value Register High; 0xFFFF8086 ***/
    union {
      byte Byte;
    } FTM1C0VHSTR;
    #define FTM1C0VH                    _FTM1C0V.Overlap_STR.FTM1C0VHSTR.Byte
    

    /*** FTM1C0VL - FTM1 Timer Channel 0 Value Register Low; 0xFFFF8087 ***/
    union {
      byte Byte;
    } FTM1C0VLSTR;
    #define FTM1C0VL                    _FTM1C0V.Overlap_STR.FTM1C0VLSTR.Byte
    
  } Overlap_STR;

} FTM1C0VSTR;
extern volatile FTM1C0VSTR _FTM1C0V @0xFFFF8086;
#define FTM1C0V                         _FTM1C0V.Word


/*** FTM1C1SC - FTM1 Timer Channel 1 Status and Control Register; 0xFFFF8088 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for FTM1 Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for FTM1 Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1C1SCSTR;
extern volatile FTM1C1SCSTR _FTM1C1SC @0xFFFF8088;
#define FTM1C1SC                        _FTM1C1SC.Byte
#define FTM1C1SC_ELS1A                  _FTM1C1SC.Bits.ELS1A
#define FTM1C1SC_ELS1B                  _FTM1C1SC.Bits.ELS1B
#define FTM1C1SC_MS1A                   _FTM1C1SC.Bits.MS1A
#define FTM1C1SC_MS1B                   _FTM1C1SC.Bits.MS1B
#define FTM1C1SC_CH1IE                  _FTM1C1SC.Bits.CH1IE
#define FTM1C1SC_CH1F                   _FTM1C1SC.Bits.CH1F
#define FTM1C1SC_ELS1x                  _FTM1C1SC.MergedBits.grpELS1x
#define FTM1C1SC_MS1x                   _FTM1C1SC.MergedBits.grpMS1x

#define FTM1C1SC_ELS1A_MASK             4U
#define FTM1C1SC_ELS1B_MASK             8U
#define FTM1C1SC_MS1A_MASK              16U
#define FTM1C1SC_MS1B_MASK              32U
#define FTM1C1SC_CH1IE_MASK             64U
#define FTM1C1SC_CH1F_MASK              128U
#define FTM1C1SC_ELS1x_MASK             12U
#define FTM1C1SC_ELS1x_BITNUM           2U
#define FTM1C1SC_MS1x_MASK              48U
#define FTM1C1SC_MS1x_BITNUM            4U


/*** FTM1C1V - FTM1 Timer Channel 1 Value Register; 0xFFFF8089 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1C1VH - FTM1 Timer Channel 1 Value Register High; 0xFFFF8089 ***/
    union {
      byte Byte;
    } FTM1C1VHSTR;
    #define FTM1C1VH                    _FTM1C1V.Overlap_STR.FTM1C1VHSTR.Byte
    

    /*** FTM1C1VL - FTM1 Timer Channel 1 Value Register Low; 0xFFFF808A ***/
    union {
      byte Byte;
    } FTM1C1VLSTR;
    #define FTM1C1VL                    _FTM1C1V.Overlap_STR.FTM1C1VLSTR.Byte
    
  } Overlap_STR;

} FTM1C1VSTR;
extern volatile FTM1C1VSTR _FTM1C1V @0xFFFF8089;
#define FTM1C1V                         _FTM1C1V.Word


/*** FTM1C2SC - FTM1 Timer Channel 2 Status and Control Register; 0xFFFF808B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS2A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS2B       :1;                                       /* Edge/Level Select Bit B */
    byte MS2A        :1;                                       /* Mode Select A for FTM1 Channel 2 */
    byte MS2B        :1;                                       /* Mode Select B for FTM1 Channel 2 */
    byte CH2IE       :1;                                       /* Channel 2 Interrupt Enable */
    byte CH2F        :1;                                       /* Channel 2 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS2x :2;
    byte grpMS2x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1C2SCSTR;
extern volatile FTM1C2SCSTR _FTM1C2SC @0xFFFF808B;
#define FTM1C2SC                        _FTM1C2SC.Byte
#define FTM1C2SC_ELS2A                  _FTM1C2SC.Bits.ELS2A
#define FTM1C2SC_ELS2B                  _FTM1C2SC.Bits.ELS2B
#define FTM1C2SC_MS2A                   _FTM1C2SC.Bits.MS2A
#define FTM1C2SC_MS2B                   _FTM1C2SC.Bits.MS2B
#define FTM1C2SC_CH2IE                  _FTM1C2SC.Bits.CH2IE
#define FTM1C2SC_CH2F                   _FTM1C2SC.Bits.CH2F
#define FTM1C2SC_ELS2x                  _FTM1C2SC.MergedBits.grpELS2x
#define FTM1C2SC_MS2x                   _FTM1C2SC.MergedBits.grpMS2x

#define FTM1C2SC_ELS2A_MASK             4U
#define FTM1C2SC_ELS2B_MASK             8U
#define FTM1C2SC_MS2A_MASK              16U
#define FTM1C2SC_MS2B_MASK              32U
#define FTM1C2SC_CH2IE_MASK             64U
#define FTM1C2SC_CH2F_MASK              128U
#define FTM1C2SC_ELS2x_MASK             12U
#define FTM1C2SC_ELS2x_BITNUM           2U
#define FTM1C2SC_MS2x_MASK              48U
#define FTM1C2SC_MS2x_BITNUM            4U


/*** FTM1C2V - FTM1 Timer Channel 2 Value Register; 0xFFFF808C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1C2VH - FTM1 Timer Channel 2 Value Register High; 0xFFFF808C ***/
    union {
      byte Byte;
    } FTM1C2VHSTR;
    #define FTM1C2VH                    _FTM1C2V.Overlap_STR.FTM1C2VHSTR.Byte
    

    /*** FTM1C2VL - FTM1 Timer Channel 2 Value Register Low; 0xFFFF808D ***/
    union {
      byte Byte;
    } FTM1C2VLSTR;
    #define FTM1C2VL                    _FTM1C2V.Overlap_STR.FTM1C2VLSTR.Byte
    
  } Overlap_STR;

} FTM1C2VSTR;
extern volatile FTM1C2VSTR _FTM1C2V @0xFFFF808C;
#define FTM1C2V                         _FTM1C2V.Word


/*** FTM1C3SC - FTM1 Timer Channel 3 Status and Control Register; 0xFFFF808E ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS3A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS3B       :1;                                       /* Edge/Level Select Bit B */
    byte MS3A        :1;                                       /* Mode Select A for FTM1 Channel 3 */
    byte MS3B        :1;                                       /* Mode Select B for FTM1 Channel 3 */
    byte CH3IE       :1;                                       /* Channel 3 Interrupt Enable */
    byte CH3F        :1;                                       /* Channel 3 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS3x :2;
    byte grpMS3x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1C3SCSTR;
extern volatile FTM1C3SCSTR _FTM1C3SC @0xFFFF808E;
#define FTM1C3SC                        _FTM1C3SC.Byte
#define FTM1C3SC_ELS3A                  _FTM1C3SC.Bits.ELS3A
#define FTM1C3SC_ELS3B                  _FTM1C3SC.Bits.ELS3B
#define FTM1C3SC_MS3A                   _FTM1C3SC.Bits.MS3A
#define FTM1C3SC_MS3B                   _FTM1C3SC.Bits.MS3B
#define FTM1C3SC_CH3IE                  _FTM1C3SC.Bits.CH3IE
#define FTM1C3SC_CH3F                   _FTM1C3SC.Bits.CH3F
#define FTM1C3SC_ELS3x                  _FTM1C3SC.MergedBits.grpELS3x
#define FTM1C3SC_MS3x                   _FTM1C3SC.MergedBits.grpMS3x

#define FTM1C3SC_ELS3A_MASK             4U
#define FTM1C3SC_ELS3B_MASK             8U
#define FTM1C3SC_MS3A_MASK              16U
#define FTM1C3SC_MS3B_MASK              32U
#define FTM1C3SC_CH3IE_MASK             64U
#define FTM1C3SC_CH3F_MASK              128U
#define FTM1C3SC_ELS3x_MASK             12U
#define FTM1C3SC_ELS3x_BITNUM           2U
#define FTM1C3SC_MS3x_MASK              48U
#define FTM1C3SC_MS3x_BITNUM            4U


/*** FTM1C3V - FTM1 Timer Channel 3 Value Register; 0xFFFF808F ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1C3VH - FTM1 Timer Channel 3 Value Register High; 0xFFFF808F ***/
    union {
      byte Byte;
    } FTM1C3VHSTR;
    #define FTM1C3VH                    _FTM1C3V.Overlap_STR.FTM1C3VHSTR.Byte
    

    /*** FTM1C3VL - FTM1 Timer Channel 3 Value Register Low; 0xFFFF8090 ***/
    union {
      byte Byte;
    } FTM1C3VLSTR;
    #define FTM1C3VL                    _FTM1C3V.Overlap_STR.FTM1C3VLSTR.Byte
    
  } Overlap_STR;

} FTM1C3VSTR;
extern volatile FTM1C3VSTR _FTM1C3V @0xFFFF808F;
#define FTM1C3V                         _FTM1C3V.Word


/*** FTM1C4SC - FTM1 Timer Channel 4 Status and Control Register; 0xFFFF8091 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS4A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS4B       :1;                                       /* Edge/Level Select Bit B */
    byte MS4A        :1;                                       /* Mode Select A for FTM1 Channel 4 */
    byte MS4B        :1;                                       /* Mode Select B for FTM1 Channel 4 */
    byte CH4IE       :1;                                       /* Channel 4 Interrupt Enable */
    byte CH4F        :1;                                       /* Channel 4 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS4x :2;
    byte grpMS4x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1C4SCSTR;
extern volatile FTM1C4SCSTR _FTM1C4SC @0xFFFF8091;
#define FTM1C4SC                        _FTM1C4SC.Byte
#define FTM1C4SC_ELS4A                  _FTM1C4SC.Bits.ELS4A
#define FTM1C4SC_ELS4B                  _FTM1C4SC.Bits.ELS4B
#define FTM1C4SC_MS4A                   _FTM1C4SC.Bits.MS4A
#define FTM1C4SC_MS4B                   _FTM1C4SC.Bits.MS4B
#define FTM1C4SC_CH4IE                  _FTM1C4SC.Bits.CH4IE
#define FTM1C4SC_CH4F                   _FTM1C4SC.Bits.CH4F
#define FTM1C4SC_ELS4x                  _FTM1C4SC.MergedBits.grpELS4x
#define FTM1C4SC_MS4x                   _FTM1C4SC.MergedBits.grpMS4x

#define FTM1C4SC_ELS4A_MASK             4U
#define FTM1C4SC_ELS4B_MASK             8U
#define FTM1C4SC_MS4A_MASK              16U
#define FTM1C4SC_MS4B_MASK              32U
#define FTM1C4SC_CH4IE_MASK             64U
#define FTM1C4SC_CH4F_MASK              128U
#define FTM1C4SC_ELS4x_MASK             12U
#define FTM1C4SC_ELS4x_BITNUM           2U
#define FTM1C4SC_MS4x_MASK              48U
#define FTM1C4SC_MS4x_BITNUM            4U


/*** FTM1C4V - FTM1 Timer Channel 4 Value Register; 0xFFFF8092 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1C4VH - FTM1 Timer Channel 4 Value Register High; 0xFFFF8092 ***/
    union {
      byte Byte;
    } FTM1C4VHSTR;
    #define FTM1C4VH                    _FTM1C4V.Overlap_STR.FTM1C4VHSTR.Byte
    

    /*** FTM1C4VL - FTM1 Timer Channel 4 Value Register Low; 0xFFFF8093 ***/
    union {
      byte Byte;
    } FTM1C4VLSTR;
    #define FTM1C4VL                    _FTM1C4V.Overlap_STR.FTM1C4VLSTR.Byte
    
  } Overlap_STR;

} FTM1C4VSTR;
extern volatile FTM1C4VSTR _FTM1C4V @0xFFFF8092;
#define FTM1C4V                         _FTM1C4V.Word


/*** FTM1C5SC - FTM1 Timer Channel 5 Status and Control Register; 0xFFFF8094 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS5A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS5B       :1;                                       /* Edge/Level Select Bit B */
    byte MS5A        :1;                                       /* Mode Select A for FTM1 Channel 5 */
    byte MS5B        :1;                                       /* Mode Select B for FTM1 Channel 5 */
    byte CH5IE       :1;                                       /* Channel 5 Interrupt Enable */
    byte CH5F        :1;                                       /* Channel 5 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS5x :2;
    byte grpMS5x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1C5SCSTR;
extern volatile FTM1C5SCSTR _FTM1C5SC @0xFFFF8094;
#define FTM1C5SC                        _FTM1C5SC.Byte
#define FTM1C5SC_ELS5A                  _FTM1C5SC.Bits.ELS5A
#define FTM1C5SC_ELS5B                  _FTM1C5SC.Bits.ELS5B
#define FTM1C5SC_MS5A                   _FTM1C5SC.Bits.MS5A
#define FTM1C5SC_MS5B                   _FTM1C5SC.Bits.MS5B
#define FTM1C5SC_CH5IE                  _FTM1C5SC.Bits.CH5IE
#define FTM1C5SC_CH5F                   _FTM1C5SC.Bits.CH5F
#define FTM1C5SC_ELS5x                  _FTM1C5SC.MergedBits.grpELS5x
#define FTM1C5SC_MS5x                   _FTM1C5SC.MergedBits.grpMS5x

#define FTM1C5SC_ELS5A_MASK             4U
#define FTM1C5SC_ELS5B_MASK             8U
#define FTM1C5SC_MS5A_MASK              16U
#define FTM1C5SC_MS5B_MASK              32U
#define FTM1C5SC_CH5IE_MASK             64U
#define FTM1C5SC_CH5F_MASK              128U
#define FTM1C5SC_ELS5x_MASK             12U
#define FTM1C5SC_ELS5x_BITNUM           2U
#define FTM1C5SC_MS5x_MASK              48U
#define FTM1C5SC_MS5x_BITNUM            4U


/*** FTM1C5V - FTM1 Timer Channel 5 Value Register; 0xFFFF8095 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1C5VH - FTM1 Timer Channel 5 Value Register High; 0xFFFF8095 ***/
    union {
      byte Byte;
    } FTM1C5VHSTR;
    #define FTM1C5VH                    _FTM1C5V.Overlap_STR.FTM1C5VHSTR.Byte
    

    /*** FTM1C5VL - FTM1 Timer Channel 5 Value Register Low; 0xFFFF8096 ***/
    union {
      byte Byte;
    } FTM1C5VLSTR;
    #define FTM1C5VL                    _FTM1C5V.Overlap_STR.FTM1C5VLSTR.Byte
    
  } Overlap_STR;

} FTM1C5VSTR;
extern volatile FTM1C5VSTR _FTM1C5V @0xFFFF8095;
#define FTM1C5V                         _FTM1C5V.Word


/*** FTM1CNTIN - FTM1 Counter Initial Value Registers; 0xFFFF809D ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM1CNTINH - FTM1 Counter Initial Value Registers High; 0xFFFF809D ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* FTM1 Counter Initial Value Bit 8 */
        byte BIT9        :1;                                       /* FTM1 Counter Initial Value Bit 9 */
        byte BIT10       :1;                                       /* FTM1 Counter Initial Value Bit 10 */
        byte BIT11       :1;                                       /* FTM1 Counter Initial Value Bit 11 */
        byte BIT12       :1;                                       /* FTM1 Counter Initial Value Bit 12 */
        byte BIT13       :1;                                       /* FTM1 Counter Initial Value Bit 13 */
        byte BIT14       :1;                                       /* FTM1 Counter Initial Value Bit 14 */
        byte BIT15       :1;                                       /* FTM1 Counter Initial Value Bit 15 */
      } Bits;
    } FTM1CNTINHSTR;
    #define FTM1CNTINH                  _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Byte
    #define FTM1CNTINH_BIT8             _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT8
    #define FTM1CNTINH_BIT9             _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT9
    #define FTM1CNTINH_BIT10            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT10
    #define FTM1CNTINH_BIT11            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT11
    #define FTM1CNTINH_BIT12            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT12
    #define FTM1CNTINH_BIT13            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT13
    #define FTM1CNTINH_BIT14            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT14
    #define FTM1CNTINH_BIT15            _FTM1CNTIN.Overlap_STR.FTM1CNTINHSTR.Bits.BIT15
    
    #define FTM1CNTINH_BIT8_MASK        1U
    #define FTM1CNTINH_BIT9_MASK        2U
    #define FTM1CNTINH_BIT10_MASK       4U
    #define FTM1CNTINH_BIT11_MASK       8U
    #define FTM1CNTINH_BIT12_MASK       16U
    #define FTM1CNTINH_BIT13_MASK       32U
    #define FTM1CNTINH_BIT14_MASK       64U
    #define FTM1CNTINH_BIT15_MASK       128U
    

    /*** FTM1CNTINL - FTM1 Counter Initial Value Registers Low; 0xFFFF809E ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* FTM1 Counter Initial Value Bit 0 */
        byte BIT1        :1;                                       /* FTM1 Counter Initial Value Bit 1 */
        byte BIT2        :1;                                       /* FTM1 Counter Initial Value Bit 2 */
        byte BIT3        :1;                                       /* FTM1 Counter Initial Value Bit 3 */
        byte BIT4        :1;                                       /* FTM1 Counter Initial Value Bit 4 */
        byte BIT5        :1;                                       /* FTM1 Counter Initial Value Bit 5 */
        byte BIT6        :1;                                       /* FTM1 Counter Initial Value Bit 6 */
        byte BIT7        :1;                                       /* FTM1 Counter Initial Value Bit 7 */
      } Bits;
    } FTM1CNTINLSTR;
    #define FTM1CNTINL                  _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Byte
    #define FTM1CNTINL_BIT0             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT0
    #define FTM1CNTINL_BIT1             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT1
    #define FTM1CNTINL_BIT2             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT2
    #define FTM1CNTINL_BIT3             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT3
    #define FTM1CNTINL_BIT4             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT4
    #define FTM1CNTINL_BIT5             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT5
    #define FTM1CNTINL_BIT6             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT6
    #define FTM1CNTINL_BIT7             _FTM1CNTIN.Overlap_STR.FTM1CNTINLSTR.Bits.BIT7
    
    #define FTM1CNTINL_BIT0_MASK        1U
    #define FTM1CNTINL_BIT1_MASK        2U
    #define FTM1CNTINL_BIT2_MASK        4U
    #define FTM1CNTINL_BIT3_MASK        8U
    #define FTM1CNTINL_BIT4_MASK        16U
    #define FTM1CNTINL_BIT5_MASK        32U
    #define FTM1CNTINL_BIT6_MASK        64U
    #define FTM1CNTINL_BIT7_MASK        128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* FTM1 Counter Initial Value Bit 0 */
    word BIT1        :1;                                       /* FTM1 Counter Initial Value Bit 1 */
    word BIT2        :1;                                       /* FTM1 Counter Initial Value Bit 2 */
    word BIT3        :1;                                       /* FTM1 Counter Initial Value Bit 3 */
    word BIT4        :1;                                       /* FTM1 Counter Initial Value Bit 4 */
    word BIT5        :1;                                       /* FTM1 Counter Initial Value Bit 5 */
    word BIT6        :1;                                       /* FTM1 Counter Initial Value Bit 6 */
    word BIT7        :1;                                       /* FTM1 Counter Initial Value Bit 7 */
    word BIT8        :1;                                       /* FTM1 Counter Initial Value Bit 8 */
    word BIT9        :1;                                       /* FTM1 Counter Initial Value Bit 9 */
    word BIT10       :1;                                       /* FTM1 Counter Initial Value Bit 10 */
    word BIT11       :1;                                       /* FTM1 Counter Initial Value Bit 11 */
    word BIT12       :1;                                       /* FTM1 Counter Initial Value Bit 12 */
    word BIT13       :1;                                       /* FTM1 Counter Initial Value Bit 13 */
    word BIT14       :1;                                       /* FTM1 Counter Initial Value Bit 14 */
    word BIT15       :1;                                       /* FTM1 Counter Initial Value Bit 15 */
  } Bits;
} FTM1CNTINSTR;
extern volatile FTM1CNTINSTR _FTM1CNTIN @0xFFFF809D;
#define FTM1CNTIN                       _FTM1CNTIN.Word
#define FTM1CNTIN_BIT0                  _FTM1CNTIN.Bits.BIT0
#define FTM1CNTIN_BIT1                  _FTM1CNTIN.Bits.BIT1
#define FTM1CNTIN_BIT2                  _FTM1CNTIN.Bits.BIT2
#define FTM1CNTIN_BIT3                  _FTM1CNTIN.Bits.BIT3
#define FTM1CNTIN_BIT4                  _FTM1CNTIN.Bits.BIT4
#define FTM1CNTIN_BIT5                  _FTM1CNTIN.Bits.BIT5
#define FTM1CNTIN_BIT6                  _FTM1CNTIN.Bits.BIT6
#define FTM1CNTIN_BIT7                  _FTM1CNTIN.Bits.BIT7
#define FTM1CNTIN_BIT8                  _FTM1CNTIN.Bits.BIT8
#define FTM1CNTIN_BIT9                  _FTM1CNTIN.Bits.BIT9
#define FTM1CNTIN_BIT10                 _FTM1CNTIN.Bits.BIT10
#define FTM1CNTIN_BIT11                 _FTM1CNTIN.Bits.BIT11
#define FTM1CNTIN_BIT12                 _FTM1CNTIN.Bits.BIT12
#define FTM1CNTIN_BIT13                 _FTM1CNTIN.Bits.BIT13
#define FTM1CNTIN_BIT14                 _FTM1CNTIN.Bits.BIT14
#define FTM1CNTIN_BIT15                 _FTM1CNTIN.Bits.BIT15

#define FTM1CNTIN_BIT0_MASK             1U
#define FTM1CNTIN_BIT1_MASK             2U
#define FTM1CNTIN_BIT2_MASK             4U
#define FTM1CNTIN_BIT3_MASK             8U
#define FTM1CNTIN_BIT4_MASK             16U
#define FTM1CNTIN_BIT5_MASK             32U
#define FTM1CNTIN_BIT6_MASK             64U
#define FTM1CNTIN_BIT7_MASK             128U
#define FTM1CNTIN_BIT8_MASK             256U
#define FTM1CNTIN_BIT9_MASK             512U
#define FTM1CNTIN_BIT10_MASK            1024U
#define FTM1CNTIN_BIT11_MASK            2048U
#define FTM1CNTIN_BIT12_MASK            4096U
#define FTM1CNTIN_BIT13_MASK            8192U
#define FTM1CNTIN_BIT14_MASK            16384U
#define FTM1CNTIN_BIT15_MASK            32768U


/*** FTM1STATUS - FTM1 Capture and Compare Status Register; 0xFFFF809F ***/
typedef union {
  byte Byte;
  struct {
    byte CH0F        :1;                                       /* Channel 0 Flag */
    byte CH1F        :1;                                       /* Channel 1 Flag */
    byte CH2F        :1;                                       /* Channel 2 Flag */
    byte CH3F        :1;                                       /* Channel 3 Flag */
    byte CH4F        :1;                                       /* Channel 4 Flag */
    byte CH5F        :1;                                       /* Channel 5 Flag */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM1STATUSSTR;
extern volatile FTM1STATUSSTR _FTM1STATUS @0xFFFF809F;
#define FTM1STATUS                      _FTM1STATUS.Byte
#define FTM1STATUS_CH0F                 _FTM1STATUS.Bits.CH0F
#define FTM1STATUS_CH1F                 _FTM1STATUS.Bits.CH1F
#define FTM1STATUS_CH2F                 _FTM1STATUS.Bits.CH2F
#define FTM1STATUS_CH3F                 _FTM1STATUS.Bits.CH3F
#define FTM1STATUS_CH4F                 _FTM1STATUS.Bits.CH4F
#define FTM1STATUS_CH5F                 _FTM1STATUS.Bits.CH5F

#define FTM1STATUS_CH0F_MASK            1U
#define FTM1STATUS_CH1F_MASK            2U
#define FTM1STATUS_CH2F_MASK            4U
#define FTM1STATUS_CH3F_MASK            8U
#define FTM1STATUS_CH4F_MASK            16U
#define FTM1STATUS_CH5F_MASK            32U


/*** FTM1MODE - FTM1 Features Mode Selection Register; 0xFFFF80A0 ***/
typedef union {
  byte Byte;
  struct {
    byte FTMEN       :1;                                       /* FTM1 Enable */
    byte INIT        :1;                                       /* Initialize the Channels Output */
    byte WPDIS       :1;                                       /* Write Protected Disable */
    byte             :1; 
    byte             :1; 
    byte FAULTM0     :1;                                       /* Fault Control Mode Bits, bit 0 */
    byte FAULTM1     :1;                                       /* Fault Control Mode Bits, bit 1 */
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
} FTM1MODESTR;
extern volatile FTM1MODESTR _FTM1MODE @0xFFFF80A0;
#define FTM1MODE                        _FTM1MODE.Byte
#define FTM1MODE_FTMEN                  _FTM1MODE.Bits.FTMEN
#define FTM1MODE_INIT                   _FTM1MODE.Bits.INIT
#define FTM1MODE_WPDIS                  _FTM1MODE.Bits.WPDIS
#define FTM1MODE_FAULTM0                _FTM1MODE.Bits.FAULTM0
#define FTM1MODE_FAULTM1                _FTM1MODE.Bits.FAULTM1
#define FTM1MODE_FAULTIE                _FTM1MODE.Bits.FAULTIE
#define FTM1MODE_FAULTM                 _FTM1MODE.MergedBits.grpFAULTM

#define FTM1MODE_FTMEN_MASK             1U
#define FTM1MODE_INIT_MASK              2U
#define FTM1MODE_WPDIS_MASK             4U
#define FTM1MODE_FAULTM0_MASK           32U
#define FTM1MODE_FAULTM1_MASK           64U
#define FTM1MODE_FAULTIE_MASK           128U
#define FTM1MODE_FAULTM_MASK            96U
#define FTM1MODE_FAULTM_BITNUM          5U


/*** FTM1SYNC - FTM1 Synchronization Register; 0xFFFF80A1 ***/
typedef union {
  byte Byte;
  struct {
    byte CNTMIN      :1;                                       /* FTM1 Counter is Minimum */
    byte CNTMAX      :1;                                       /* FTM1 Counter is Maximum */
    byte REINIT      :1;                                       /* Reinitialization of FTM1 Counter by Synchronization */
    byte SYNCHOM     :1;                                       /* Output Mask by Synchronization */
    byte TRIG0       :1;                                       /* External Trigger Bit 0 for Synchronization */
    byte TRIG1       :1;                                       /* External Trigger Bit 1 for Synchronization */
    byte TRIG2       :1;                                       /* External Trigger Bit 2 for Synchronization */
    byte SWSYNC      :1;                                       /* Software Trigger for Synchronization */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTRIG :3;
    byte         :1;
  } MergedBits;
} FTM1SYNCSTR;
extern volatile FTM1SYNCSTR _FTM1SYNC @0xFFFF80A1;
#define FTM1SYNC                        _FTM1SYNC.Byte
#define FTM1SYNC_CNTMIN                 _FTM1SYNC.Bits.CNTMIN
#define FTM1SYNC_CNTMAX                 _FTM1SYNC.Bits.CNTMAX
#define FTM1SYNC_REINIT                 _FTM1SYNC.Bits.REINIT
#define FTM1SYNC_SYNCHOM                _FTM1SYNC.Bits.SYNCHOM
#define FTM1SYNC_TRIG0                  _FTM1SYNC.Bits.TRIG0
#define FTM1SYNC_TRIG1                  _FTM1SYNC.Bits.TRIG1
#define FTM1SYNC_TRIG2                  _FTM1SYNC.Bits.TRIG2
#define FTM1SYNC_SWSYNC                 _FTM1SYNC.Bits.SWSYNC
#define FTM1SYNC_TRIG                   _FTM1SYNC.MergedBits.grpTRIG

#define FTM1SYNC_CNTMIN_MASK            1U
#define FTM1SYNC_CNTMAX_MASK            2U
#define FTM1SYNC_REINIT_MASK            4U
#define FTM1SYNC_SYNCHOM_MASK           8U
#define FTM1SYNC_TRIG0_MASK             16U
#define FTM1SYNC_TRIG1_MASK             32U
#define FTM1SYNC_TRIG2_MASK             64U
#define FTM1SYNC_SWSYNC_MASK            128U
#define FTM1SYNC_TRIG_MASK              112U
#define FTM1SYNC_TRIG_BITNUM            4U


/*** FTM1OUTINIT - FTM1 Initial State for Channels Output Register; 0xFFFF80A2 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OI       :1;                                       /* Initial State for Channel 0 Output */
    byte CH1OI       :1;                                       /* Initial State for Channel 1 Output */
    byte CH2OI       :1;                                       /* Initial State for Channel 2 Output */
    byte CH3OI       :1;                                       /* Initial State for Channel 3 Output */
    byte CH4OI       :1;                                       /* Initial State for Channel 4 Output */
    byte CH5OI       :1;                                       /* Initial State for Channel 5 Output */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM1OUTINITSTR;
extern volatile FTM1OUTINITSTR _FTM1OUTINIT @0xFFFF80A2;
#define FTM1OUTINIT                     _FTM1OUTINIT.Byte
#define FTM1OUTINIT_CH0OI               _FTM1OUTINIT.Bits.CH0OI
#define FTM1OUTINIT_CH1OI               _FTM1OUTINIT.Bits.CH1OI
#define FTM1OUTINIT_CH2OI               _FTM1OUTINIT.Bits.CH2OI
#define FTM1OUTINIT_CH3OI               _FTM1OUTINIT.Bits.CH3OI
#define FTM1OUTINIT_CH4OI               _FTM1OUTINIT.Bits.CH4OI
#define FTM1OUTINIT_CH5OI               _FTM1OUTINIT.Bits.CH5OI

#define FTM1OUTINIT_CH0OI_MASK          1U
#define FTM1OUTINIT_CH1OI_MASK          2U
#define FTM1OUTINIT_CH2OI_MASK          4U
#define FTM1OUTINIT_CH3OI_MASK          8U
#define FTM1OUTINIT_CH4OI_MASK          16U
#define FTM1OUTINIT_CH5OI_MASK          32U


/*** FTM1OUTMASK - FTM1 Output Mask Register; 0xFFFF80A3 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OM       :1;                                       /* Channel 0 Output Mask */
    byte CH1OM       :1;                                       /* Channel 1 Output Mask */
    byte CH2OM       :1;                                       /* Channel 2 Output Mask */
    byte CH3OM       :1;                                       /* Channel 3 Output Mask */
    byte CH4OM       :1;                                       /* Channel 4 Output Mask */
    byte CH5OM       :1;                                       /* Channel 5 Output Mask */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM1OUTMASKSTR;
extern volatile FTM1OUTMASKSTR _FTM1OUTMASK @0xFFFF80A3;
#define FTM1OUTMASK                     _FTM1OUTMASK.Byte
#define FTM1OUTMASK_CH0OM               _FTM1OUTMASK.Bits.CH0OM
#define FTM1OUTMASK_CH1OM               _FTM1OUTMASK.Bits.CH1OM
#define FTM1OUTMASK_CH2OM               _FTM1OUTMASK.Bits.CH2OM
#define FTM1OUTMASK_CH3OM               _FTM1OUTMASK.Bits.CH3OM
#define FTM1OUTMASK_CH4OM               _FTM1OUTMASK.Bits.CH4OM
#define FTM1OUTMASK_CH5OM               _FTM1OUTMASK.Bits.CH5OM

#define FTM1OUTMASK_CH0OM_MASK          1U
#define FTM1OUTMASK_CH1OM_MASK          2U
#define FTM1OUTMASK_CH2OM_MASK          4U
#define FTM1OUTMASK_CH3OM_MASK          8U
#define FTM1OUTMASK_CH4OM_MASK          16U
#define FTM1OUTMASK_CH5OM_MASK          32U


/*** FTM1COMBINE0 - FTM1 Function For Linked Channel 0 Register; 0xFFFF80A4 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 0 and 1 */
    byte COMP        :1;                                       /* Complementary of Channel 0 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM1COMBINE0STR;
extern volatile FTM1COMBINE0STR _FTM1COMBINE0 @0xFFFF80A4;
#define FTM1COMBINE0                    _FTM1COMBINE0.Byte
#define FTM1COMBINE0_COMBINE            _FTM1COMBINE0.Bits.COMBINE
#define FTM1COMBINE0_COMP               _FTM1COMBINE0.Bits.COMP
#define FTM1COMBINE0_DTEN               _FTM1COMBINE0.Bits.DTEN
#define FTM1COMBINE0_SYNCEN             _FTM1COMBINE0.Bits.SYNCEN
#define FTM1COMBINE0_FAULTEN            _FTM1COMBINE0.Bits.FAULTEN
/* FTM1COMBINE_ARR: Access 3 FTM1COMBINEx registers in an array */
#define FTM1COMBINE_ARR                 ((volatile byte *) &FTM1COMBINE0)

#define FTM1COMBINE0_COMBINE_MASK       1U
#define FTM1COMBINE0_COMP_MASK          2U
#define FTM1COMBINE0_DTEN_MASK          16U
#define FTM1COMBINE0_SYNCEN_MASK        32U
#define FTM1COMBINE0_FAULTEN_MASK       64U


/*** FTM1COMBINE1 - FTM1 Function For Linked Channel 1 Register; 0xFFFF80A5 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 2 and 3 */
    byte COMP        :1;                                       /* Complementary of Channel 2 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM1COMBINE1STR;
extern volatile FTM1COMBINE1STR _FTM1COMBINE1 @0xFFFF80A5;
#define FTM1COMBINE1                    _FTM1COMBINE1.Byte
#define FTM1COMBINE1_COMBINE            _FTM1COMBINE1.Bits.COMBINE
#define FTM1COMBINE1_COMP               _FTM1COMBINE1.Bits.COMP
#define FTM1COMBINE1_DTEN               _FTM1COMBINE1.Bits.DTEN
#define FTM1COMBINE1_SYNCEN             _FTM1COMBINE1.Bits.SYNCEN
#define FTM1COMBINE1_FAULTEN            _FTM1COMBINE1.Bits.FAULTEN

#define FTM1COMBINE1_COMBINE_MASK       1U
#define FTM1COMBINE1_COMP_MASK          2U
#define FTM1COMBINE1_DTEN_MASK          16U
#define FTM1COMBINE1_SYNCEN_MASK        32U
#define FTM1COMBINE1_FAULTEN_MASK       64U


/*** FTM1COMBINE2 - FTM1 Function For Linked Channel 2 Register; 0xFFFF80A6 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 4 and 5 */
    byte COMP        :1;                                       /* Complementary of Channel 4 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM1COMBINE2STR;
extern volatile FTM1COMBINE2STR _FTM1COMBINE2 @0xFFFF80A6;
#define FTM1COMBINE2                    _FTM1COMBINE2.Byte
#define FTM1COMBINE2_COMBINE            _FTM1COMBINE2.Bits.COMBINE
#define FTM1COMBINE2_COMP               _FTM1COMBINE2.Bits.COMP
#define FTM1COMBINE2_DTEN               _FTM1COMBINE2.Bits.DTEN
#define FTM1COMBINE2_SYNCEN             _FTM1COMBINE2.Bits.SYNCEN
#define FTM1COMBINE2_FAULTEN            _FTM1COMBINE2.Bits.FAULTEN

#define FTM1COMBINE2_COMBINE_MASK       1U
#define FTM1COMBINE2_COMP_MASK          2U
#define FTM1COMBINE2_DTEN_MASK          16U
#define FTM1COMBINE2_SYNCEN_MASK        32U
#define FTM1COMBINE2_FAULTEN_MASK       64U


/*** FTM1DEADTIME - FTM1 Deadtime Insertion Control Register; 0xFFFF80A8 ***/
typedef union {
  byte Byte;
  struct {
    byte DTVAL0      :1;                                       /* Deadtime Value Bits, bit 0 */
    byte DTVAL1      :1;                                       /* Deadtime Value Bits, bit 1 */
    byte DTVAL2      :1;                                       /* Deadtime Value Bits, bit 2 */
    byte DTVAL3      :1;                                       /* Deadtime Value Bits, bit 3 */
    byte DTVAL4      :1;                                       /* Deadtime Value Bits, bit 4 */
    byte DTVAL5      :1;                                       /* Deadtime Value Bits, bit 5 */
    byte DTPS0       :1;                                       /* Deadtime Prescaler Value Bits, bit 0 */
    byte DTPS1       :1;                                       /* Deadtime Prescaler Value Bits, bit 1 */
  } Bits;
  struct {
    byte grpDTVAL :6;
    byte grpDTPS :2;
  } MergedBits;
} FTM1DEADTIMESTR;
extern volatile FTM1DEADTIMESTR _FTM1DEADTIME @0xFFFF80A8;
#define FTM1DEADTIME                    _FTM1DEADTIME.Byte
#define FTM1DEADTIME_DTVAL0             _FTM1DEADTIME.Bits.DTVAL0
#define FTM1DEADTIME_DTVAL1             _FTM1DEADTIME.Bits.DTVAL1
#define FTM1DEADTIME_DTVAL2             _FTM1DEADTIME.Bits.DTVAL2
#define FTM1DEADTIME_DTVAL3             _FTM1DEADTIME.Bits.DTVAL3
#define FTM1DEADTIME_DTVAL4             _FTM1DEADTIME.Bits.DTVAL4
#define FTM1DEADTIME_DTVAL5             _FTM1DEADTIME.Bits.DTVAL5
#define FTM1DEADTIME_DTPS0              _FTM1DEADTIME.Bits.DTPS0
#define FTM1DEADTIME_DTPS1              _FTM1DEADTIME.Bits.DTPS1
#define FTM1DEADTIME_DTVAL              _FTM1DEADTIME.MergedBits.grpDTVAL
#define FTM1DEADTIME_DTPS               _FTM1DEADTIME.MergedBits.grpDTPS

#define FTM1DEADTIME_DTVAL0_MASK        1U
#define FTM1DEADTIME_DTVAL1_MASK        2U
#define FTM1DEADTIME_DTVAL2_MASK        4U
#define FTM1DEADTIME_DTVAL3_MASK        8U
#define FTM1DEADTIME_DTVAL4_MASK        16U
#define FTM1DEADTIME_DTVAL5_MASK        32U
#define FTM1DEADTIME_DTPS0_MASK         64U
#define FTM1DEADTIME_DTPS1_MASK         128U
#define FTM1DEADTIME_DTVAL_MASK         63U
#define FTM1DEADTIME_DTVAL_BITNUM       0U
#define FTM1DEADTIME_DTPS_MASK          192U
#define FTM1DEADTIME_DTPS_BITNUM        6U


/*** FTM1EXTTRIG - FTM1 ExternalTrigger Register; 0xFFFF80A9 ***/
typedef union {
  byte Byte;
  struct {
    byte CH2TRIG     :1;                                       /* Channel 2 trigger enable */
    byte CH3TRIG     :1;                                       /* Channel 3 trigger enable */
    byte CH4TRIG     :1;                                       /* Channel 4 trigger enable */
    byte CH5TRIG     :1;                                       /* Channel 5 trigger enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TRIGF       :1;                                       /* Channel trigger flag */
  } Bits;
} FTM1EXTTRIGSTR;
extern volatile FTM1EXTTRIGSTR _FTM1EXTTRIG @0xFFFF80A9;
#define FTM1EXTTRIG                     _FTM1EXTTRIG.Byte
#define FTM1EXTTRIG_CH2TRIG             _FTM1EXTTRIG.Bits.CH2TRIG
#define FTM1EXTTRIG_CH3TRIG             _FTM1EXTTRIG.Bits.CH3TRIG
#define FTM1EXTTRIG_CH4TRIG             _FTM1EXTTRIG.Bits.CH4TRIG
#define FTM1EXTTRIG_CH5TRIG             _FTM1EXTTRIG.Bits.CH5TRIG
#define FTM1EXTTRIG_TRIGF               _FTM1EXTTRIG.Bits.TRIGF

#define FTM1EXTTRIG_CH2TRIG_MASK        1U
#define FTM1EXTTRIG_CH3TRIG_MASK        2U
#define FTM1EXTTRIG_CH4TRIG_MASK        4U
#define FTM1EXTTRIG_CH5TRIG_MASK        8U
#define FTM1EXTTRIG_TRIGF_MASK          128U


/*** FTM1POL - FTM1 Channels Polarity Register; 0xFFFF80AA ***/
typedef union {
  byte Byte;
  struct {
    byte POL0        :1;                                       /* Channel 0 Polarity */
    byte POL1        :1;                                       /* Channel 1 Polarity */
    byte POL2        :1;                                       /* Channel 2 Polarity */
    byte POL3        :1;                                       /* Channel 3 Polarity */
    byte POL4        :1;                                       /* Channel 4 Polarity */
    byte POL5        :1;                                       /* Channel 5 Polarity */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOL  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM1POLSTR;
extern volatile FTM1POLSTR _FTM1POL @0xFFFF80AA;
#define FTM1POL                         _FTM1POL.Byte
#define FTM1POL_POL0                    _FTM1POL.Bits.POL0
#define FTM1POL_POL1                    _FTM1POL.Bits.POL1
#define FTM1POL_POL2                    _FTM1POL.Bits.POL2
#define FTM1POL_POL3                    _FTM1POL.Bits.POL3
#define FTM1POL_POL4                    _FTM1POL.Bits.POL4
#define FTM1POL_POL5                    _FTM1POL.Bits.POL5
#define FTM1POL_POL                     _FTM1POL.MergedBits.grpPOL

#define FTM1POL_POL0_MASK               1U
#define FTM1POL_POL1_MASK               2U
#define FTM1POL_POL2_MASK               4U
#define FTM1POL_POL3_MASK               8U
#define FTM1POL_POL4_MASK               16U
#define FTM1POL_POL5_MASK               32U
#define FTM1POL_POL_MASK                63U
#define FTM1POL_POL_BITNUM              0U


/*** FTM1FMS - FTM1 Fault Mode Status Register; 0xFFFF80AB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FAULTIN     :1;                                       /* Fault Input */
    byte WPEN        :1;                                       /* Write Protected Enable */
    byte FAULTF      :1;                                       /* Fault Detection Flag */
  } Bits;
} FTM1FMSSTR;
extern volatile FTM1FMSSTR _FTM1FMS @0xFFFF80AB;
#define FTM1FMS                         _FTM1FMS.Byte
#define FTM1FMS_FAULTIN                 _FTM1FMS.Bits.FAULTIN
#define FTM1FMS_WPEN                    _FTM1FMS.Bits.WPEN
#define FTM1FMS_FAULTF                  _FTM1FMS.Bits.FAULTF

#define FTM1FMS_FAULTIN_MASK            32U
#define FTM1FMS_WPEN_MASK               64U
#define FTM1FMS_FAULTF_MASK             128U


/*** FTM1FILTER0 - FTM1 Input Capture Filter Control Register 0; 0xFFFF80AC ***/
typedef union {
  byte Byte;
  struct {
    byte CH0FVAL0    :1;                                       /* Channel 0 Input Filter Bits, bit 0 */
    byte CH0FVAL1    :1;                                       /* Channel 0 Input Filter Bits, bit 1 */
    byte CH0FVAL2    :1;                                       /* Channel 0 Input Filter Bits, bit 2 */
    byte CH0FVAL3    :1;                                       /* Channel 0 Input Filter Bits, bit 3 */
    byte CH1FVAL0    :1;                                       /* Channel 1 Input Filter Bits, bit 0 */
    byte CH1FVAL1    :1;                                       /* Channel 1 Input Filter Bits, bit 1 */
    byte CH1FVAL2    :1;                                       /* Channel 1 Input Filter Bits, bit 2 */
    byte CH1FVAL3    :1;                                       /* Channel 1 Input Filter Bits, bit 3 */
  } Bits;
  struct {
    byte grpCH0FVAL :4;
    byte grpCH1FVAL :4;
  } MergedBits;
} FTM1FILTER0STR;
extern volatile FTM1FILTER0STR _FTM1FILTER0 @0xFFFF80AC;
#define FTM1FILTER0                     _FTM1FILTER0.Byte
#define FTM1FILTER0_CH0FVAL0            _FTM1FILTER0.Bits.CH0FVAL0
#define FTM1FILTER0_CH0FVAL1            _FTM1FILTER0.Bits.CH0FVAL1
#define FTM1FILTER0_CH0FVAL2            _FTM1FILTER0.Bits.CH0FVAL2
#define FTM1FILTER0_CH0FVAL3            _FTM1FILTER0.Bits.CH0FVAL3
#define FTM1FILTER0_CH1FVAL0            _FTM1FILTER0.Bits.CH1FVAL0
#define FTM1FILTER0_CH1FVAL1            _FTM1FILTER0.Bits.CH1FVAL1
#define FTM1FILTER0_CH1FVAL2            _FTM1FILTER0.Bits.CH1FVAL2
#define FTM1FILTER0_CH1FVAL3            _FTM1FILTER0.Bits.CH1FVAL3
/* FTM1FILTER_ARR: Access 2 FTM1FILTERx registers in an array */
#define FTM1FILTER_ARR                  ((volatile byte *) &FTM1FILTER0)
#define FTM1FILTER0_CH0FVAL             _FTM1FILTER0.MergedBits.grpCH0FVAL
#define FTM1FILTER0_CH1FVAL             _FTM1FILTER0.MergedBits.grpCH1FVAL

#define FTM1FILTER0_CH0FVAL0_MASK       1U
#define FTM1FILTER0_CH0FVAL1_MASK       2U
#define FTM1FILTER0_CH0FVAL2_MASK       4U
#define FTM1FILTER0_CH0FVAL3_MASK       8U
#define FTM1FILTER0_CH1FVAL0_MASK       16U
#define FTM1FILTER0_CH1FVAL1_MASK       32U
#define FTM1FILTER0_CH1FVAL2_MASK       64U
#define FTM1FILTER0_CH1FVAL3_MASK       128U
#define FTM1FILTER0_CH0FVAL_MASK        15U
#define FTM1FILTER0_CH0FVAL_BITNUM      0U
#define FTM1FILTER0_CH1FVAL_MASK        240U
#define FTM1FILTER0_CH1FVAL_BITNUM      4U


/*** FTM1FILTER1 - FTM1 Input Capture Filter Control Register 1; 0xFFFF80AD ***/
typedef union {
  byte Byte;
  struct {
    byte CH2FVAL0    :1;                                       /* Channel 2 Input Filter Bits, bit 0 */
    byte CH2FVAL1    :1;                                       /* Channel 2 Input Filter Bits, bit 1 */
    byte CH2FVAL2    :1;                                       /* Channel 2 Input Filter Bits, bit 2 */
    byte CH2FVAL3    :1;                                       /* Channel 2 Input Filter Bits, bit 3 */
    byte CH3FVAL0    :1;                                       /* Channel 3 Input Filter Bits, bit 0 */
    byte CH3FVAL1    :1;                                       /* Channel 3 Input Filter Bits, bit 1 */
    byte CH3FVAL2    :1;                                       /* Channel 3 Input Filter Bits, bit 2 */
    byte CH3FVAL3    :1;                                       /* Channel 3 Input Filter Bits, bit 3 */
  } Bits;
  struct {
    byte grpCH2FVAL :4;
    byte grpCH3FVAL :4;
  } MergedBits;
} FTM1FILTER1STR;
extern volatile FTM1FILTER1STR _FTM1FILTER1 @0xFFFF80AD;
#define FTM1FILTER1                     _FTM1FILTER1.Byte
#define FTM1FILTER1_CH2FVAL0            _FTM1FILTER1.Bits.CH2FVAL0
#define FTM1FILTER1_CH2FVAL1            _FTM1FILTER1.Bits.CH2FVAL1
#define FTM1FILTER1_CH2FVAL2            _FTM1FILTER1.Bits.CH2FVAL2
#define FTM1FILTER1_CH2FVAL3            _FTM1FILTER1.Bits.CH2FVAL3
#define FTM1FILTER1_CH3FVAL0            _FTM1FILTER1.Bits.CH3FVAL0
#define FTM1FILTER1_CH3FVAL1            _FTM1FILTER1.Bits.CH3FVAL1
#define FTM1FILTER1_CH3FVAL2            _FTM1FILTER1.Bits.CH3FVAL2
#define FTM1FILTER1_CH3FVAL3            _FTM1FILTER1.Bits.CH3FVAL3
#define FTM1FILTER1_CH2FVAL             _FTM1FILTER1.MergedBits.grpCH2FVAL
#define FTM1FILTER1_CH3FVAL             _FTM1FILTER1.MergedBits.grpCH3FVAL

#define FTM1FILTER1_CH2FVAL0_MASK       1U
#define FTM1FILTER1_CH2FVAL1_MASK       2U
#define FTM1FILTER1_CH2FVAL2_MASK       4U
#define FTM1FILTER1_CH2FVAL3_MASK       8U
#define FTM1FILTER1_CH3FVAL0_MASK       16U
#define FTM1FILTER1_CH3FVAL1_MASK       32U
#define FTM1FILTER1_CH3FVAL2_MASK       64U
#define FTM1FILTER1_CH3FVAL3_MASK       128U
#define FTM1FILTER1_CH2FVAL_MASK        15U
#define FTM1FILTER1_CH2FVAL_BITNUM      0U
#define FTM1FILTER1_CH3FVAL_MASK        240U
#define FTM1FILTER1_CH3FVAL_BITNUM      4U


/*** FTM1FLTFILTER - FTM1 Fault Input Filter Control Register; 0xFFFF80AE ***/
typedef union {
  byte Byte;
  struct {
    byte FFVAL0      :1;                                       /* Fault Input Filter Bits, bit 0 */
    byte FFVAL1      :1;                                       /* Fault Input Filter Bits, bit 1 */
    byte FFVAL2      :1;                                       /* Fault Input Filter Bits, bit 2 */
    byte FFVAL3      :1;                                       /* Fault Input Filter Bits, bit 3 */
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
} FTM1FLTFILTERSTR;
extern volatile FTM1FLTFILTERSTR _FTM1FLTFILTER @0xFFFF80AE;
#define FTM1FLTFILTER                   _FTM1FLTFILTER.Byte
#define FTM1FLTFILTER_FFVAL0            _FTM1FLTFILTER.Bits.FFVAL0
#define FTM1FLTFILTER_FFVAL1            _FTM1FLTFILTER.Bits.FFVAL1
#define FTM1FLTFILTER_FFVAL2            _FTM1FLTFILTER.Bits.FFVAL2
#define FTM1FLTFILTER_FFVAL3            _FTM1FLTFILTER.Bits.FFVAL3
#define FTM1FLTFILTER_FFVAL             _FTM1FLTFILTER.MergedBits.grpFFVAL

#define FTM1FLTFILTER_FFVAL0_MASK       1U
#define FTM1FLTFILTER_FFVAL1_MASK       2U
#define FTM1FLTFILTER_FFVAL2_MASK       4U
#define FTM1FLTFILTER_FFVAL3_MASK       8U
#define FTM1FLTFILTER_FFVAL_MASK        15U
#define FTM1FLTFILTER_FFVAL_BITNUM      0U


/*** FTM1RFU - FTM1 Register for Future Use; 0xFFFF80AF ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM1RFUSTR;
extern volatile FTM1RFUSTR _FTM1RFU @0xFFFF80AF;
#define FTM1RFU                         _FTM1RFU.Byte


/*** FTM2SC - FTM2 Status and Control Register; 0xFFFF80C0 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2SCSTR;
extern volatile FTM2SCSTR _FTM2SC @0xFFFF80C0;
#define FTM2SC                          _FTM2SC.Byte
#define FTM2SC_PS0                      _FTM2SC.Bits.PS0
#define FTM2SC_PS1                      _FTM2SC.Bits.PS1
#define FTM2SC_PS2                      _FTM2SC.Bits.PS2
#define FTM2SC_CLKSA                    _FTM2SC.Bits.CLKSA
#define FTM2SC_CLKSB                    _FTM2SC.Bits.CLKSB
#define FTM2SC_CPWMS                    _FTM2SC.Bits.CPWMS
#define FTM2SC_TOIE                     _FTM2SC.Bits.TOIE
#define FTM2SC_TOF                      _FTM2SC.Bits.TOF
#define FTM2SC_PS                       _FTM2SC.MergedBits.grpPS
#define FTM2SC_CLKSx                    _FTM2SC.MergedBits.grpCLKSx

#define FTM2SC_PS0_MASK                 1U
#define FTM2SC_PS1_MASK                 2U
#define FTM2SC_PS2_MASK                 4U
#define FTM2SC_CLKSA_MASK               8U
#define FTM2SC_CLKSB_MASK               16U
#define FTM2SC_CPWMS_MASK               32U
#define FTM2SC_TOIE_MASK                64U
#define FTM2SC_TOF_MASK                 128U
#define FTM2SC_PS_MASK                  7U
#define FTM2SC_PS_BITNUM                0U
#define FTM2SC_CLKSx_MASK               24U
#define FTM2SC_CLKSx_BITNUM             3U


/*** FTM2CNT - FTM2 Timer Counter Register; 0xFFFF80C1 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2CNTH - FTM2 Timer Counter Register High; 0xFFFF80C1 ***/
    union {
      byte Byte;
    } FTM2CNTHSTR;
    #define FTM2CNTH                    _FTM2CNT.Overlap_STR.FTM2CNTHSTR.Byte
    

    /*** FTM2CNTL - FTM2 Timer Counter Register Low; 0xFFFF80C2 ***/
    union {
      byte Byte;
    } FTM2CNTLSTR;
    #define FTM2CNTL                    _FTM2CNT.Overlap_STR.FTM2CNTLSTR.Byte
    
  } Overlap_STR;

} FTM2CNTSTR;
extern volatile FTM2CNTSTR _FTM2CNT @0xFFFF80C1;
#define FTM2CNT                         _FTM2CNT.Word


/*** FTM2MOD - FTM2 Timer Counter Modulo Register; 0xFFFF80C3 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2MODH - FTM2 Timer Counter Modulo Register High; 0xFFFF80C3 ***/
    union {
      byte Byte;
    } FTM2MODHSTR;
    #define FTM2MODH                    _FTM2MOD.Overlap_STR.FTM2MODHSTR.Byte
    

    /*** FTM2MODL - FTM2 Timer Counter Modulo Register Low; 0xFFFF80C4 ***/
    union {
      byte Byte;
    } FTM2MODLSTR;
    #define FTM2MODL                    _FTM2MOD.Overlap_STR.FTM2MODLSTR.Byte
    
  } Overlap_STR;

} FTM2MODSTR;
extern volatile FTM2MODSTR _FTM2MOD @0xFFFF80C3;
#define FTM2MOD                         _FTM2MOD.Word


/*** FTM2C0SC - FTM2 Timer Channel 0 Status and Control Register; 0xFFFF80C5 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for FTM2 Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for FTM2 Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C0SCSTR;
extern volatile FTM2C0SCSTR _FTM2C0SC @0xFFFF80C5;
#define FTM2C0SC                        _FTM2C0SC.Byte
#define FTM2C0SC_ELS0A                  _FTM2C0SC.Bits.ELS0A
#define FTM2C0SC_ELS0B                  _FTM2C0SC.Bits.ELS0B
#define FTM2C0SC_MS0A                   _FTM2C0SC.Bits.MS0A
#define FTM2C0SC_MS0B                   _FTM2C0SC.Bits.MS0B
#define FTM2C0SC_CH0IE                  _FTM2C0SC.Bits.CH0IE
#define FTM2C0SC_CH0F                   _FTM2C0SC.Bits.CH0F
#define FTM2C0SC_ELS0x                  _FTM2C0SC.MergedBits.grpELS0x
#define FTM2C0SC_MS0x                   _FTM2C0SC.MergedBits.grpMS0x

#define FTM2C0SC_ELS0A_MASK             4U
#define FTM2C0SC_ELS0B_MASK             8U
#define FTM2C0SC_MS0A_MASK              16U
#define FTM2C0SC_MS0B_MASK              32U
#define FTM2C0SC_CH0IE_MASK             64U
#define FTM2C0SC_CH0F_MASK              128U
#define FTM2C0SC_ELS0x_MASK             12U
#define FTM2C0SC_ELS0x_BITNUM           2U
#define FTM2C0SC_MS0x_MASK              48U
#define FTM2C0SC_MS0x_BITNUM            4U


/*** FTM2C0V - FTM2 Timer Channel 0 Value Register; 0xFFFF80C6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C0VH - FTM2 Timer Channel 0 Value Register High; 0xFFFF80C6 ***/
    union {
      byte Byte;
    } FTM2C0VHSTR;
    #define FTM2C0VH                    _FTM2C0V.Overlap_STR.FTM2C0VHSTR.Byte
    

    /*** FTM2C0VL - FTM2 Timer Channel 0 Value Register Low; 0xFFFF80C7 ***/
    union {
      byte Byte;
    } FTM2C0VLSTR;
    #define FTM2C0VL                    _FTM2C0V.Overlap_STR.FTM2C0VLSTR.Byte
    
  } Overlap_STR;

} FTM2C0VSTR;
extern volatile FTM2C0VSTR _FTM2C0V @0xFFFF80C6;
#define FTM2C0V                         _FTM2C0V.Word


/*** FTM2C1SC - FTM2 Timer Channel 1 Status and Control Register; 0xFFFF80C8 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for FTM2 Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for FTM2 Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C1SCSTR;
extern volatile FTM2C1SCSTR _FTM2C1SC @0xFFFF80C8;
#define FTM2C1SC                        _FTM2C1SC.Byte
#define FTM2C1SC_ELS1A                  _FTM2C1SC.Bits.ELS1A
#define FTM2C1SC_ELS1B                  _FTM2C1SC.Bits.ELS1B
#define FTM2C1SC_MS1A                   _FTM2C1SC.Bits.MS1A
#define FTM2C1SC_MS1B                   _FTM2C1SC.Bits.MS1B
#define FTM2C1SC_CH1IE                  _FTM2C1SC.Bits.CH1IE
#define FTM2C1SC_CH1F                   _FTM2C1SC.Bits.CH1F
#define FTM2C1SC_ELS1x                  _FTM2C1SC.MergedBits.grpELS1x
#define FTM2C1SC_MS1x                   _FTM2C1SC.MergedBits.grpMS1x

#define FTM2C1SC_ELS1A_MASK             4U
#define FTM2C1SC_ELS1B_MASK             8U
#define FTM2C1SC_MS1A_MASK              16U
#define FTM2C1SC_MS1B_MASK              32U
#define FTM2C1SC_CH1IE_MASK             64U
#define FTM2C1SC_CH1F_MASK              128U
#define FTM2C1SC_ELS1x_MASK             12U
#define FTM2C1SC_ELS1x_BITNUM           2U
#define FTM2C1SC_MS1x_MASK              48U
#define FTM2C1SC_MS1x_BITNUM            4U


/*** FTM2C1V - FTM2 Timer Channel 1 Value Register; 0xFFFF80C9 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C1VH - FTM2 Timer Channel 1 Value Register High; 0xFFFF80C9 ***/
    union {
      byte Byte;
    } FTM2C1VHSTR;
    #define FTM2C1VH                    _FTM2C1V.Overlap_STR.FTM2C1VHSTR.Byte
    

    /*** FTM2C1VL - FTM2 Timer Channel 1 Value Register Low; 0xFFFF80CA ***/
    union {
      byte Byte;
    } FTM2C1VLSTR;
    #define FTM2C1VL                    _FTM2C1V.Overlap_STR.FTM2C1VLSTR.Byte
    
  } Overlap_STR;

} FTM2C1VSTR;
extern volatile FTM2C1VSTR _FTM2C1V @0xFFFF80C9;
#define FTM2C1V                         _FTM2C1V.Word


/*** FTM2C2SC - FTM2 Timer Channel 2 Status and Control Register; 0xFFFF80CB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS2A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS2B       :1;                                       /* Edge/Level Select Bit B */
    byte MS2A        :1;                                       /* Mode Select A for FTM2 Channel 2 */
    byte MS2B        :1;                                       /* Mode Select B for FTM2 Channel 2 */
    byte CH2IE       :1;                                       /* Channel 2 Interrupt Enable */
    byte CH2F        :1;                                       /* Channel 2 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS2x :2;
    byte grpMS2x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C2SCSTR;
extern volatile FTM2C2SCSTR _FTM2C2SC @0xFFFF80CB;
#define FTM2C2SC                        _FTM2C2SC.Byte
#define FTM2C2SC_ELS2A                  _FTM2C2SC.Bits.ELS2A
#define FTM2C2SC_ELS2B                  _FTM2C2SC.Bits.ELS2B
#define FTM2C2SC_MS2A                   _FTM2C2SC.Bits.MS2A
#define FTM2C2SC_MS2B                   _FTM2C2SC.Bits.MS2B
#define FTM2C2SC_CH2IE                  _FTM2C2SC.Bits.CH2IE
#define FTM2C2SC_CH2F                   _FTM2C2SC.Bits.CH2F
#define FTM2C2SC_ELS2x                  _FTM2C2SC.MergedBits.grpELS2x
#define FTM2C2SC_MS2x                   _FTM2C2SC.MergedBits.grpMS2x

#define FTM2C2SC_ELS2A_MASK             4U
#define FTM2C2SC_ELS2B_MASK             8U
#define FTM2C2SC_MS2A_MASK              16U
#define FTM2C2SC_MS2B_MASK              32U
#define FTM2C2SC_CH2IE_MASK             64U
#define FTM2C2SC_CH2F_MASK              128U
#define FTM2C2SC_ELS2x_MASK             12U
#define FTM2C2SC_ELS2x_BITNUM           2U
#define FTM2C2SC_MS2x_MASK              48U
#define FTM2C2SC_MS2x_BITNUM            4U


/*** FTM2C2V - FTM2 Timer Channel 2 Value Register; 0xFFFF80CC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C2VH - FTM2 Timer Channel 2 Value Register High; 0xFFFF80CC ***/
    union {
      byte Byte;
    } FTM2C2VHSTR;
    #define FTM2C2VH                    _FTM2C2V.Overlap_STR.FTM2C2VHSTR.Byte
    

    /*** FTM2C2VL - FTM2 Timer Channel 2 Value Register Low; 0xFFFF80CD ***/
    union {
      byte Byte;
    } FTM2C2VLSTR;
    #define FTM2C2VL                    _FTM2C2V.Overlap_STR.FTM2C2VLSTR.Byte
    
  } Overlap_STR;

} FTM2C2VSTR;
extern volatile FTM2C2VSTR _FTM2C2V @0xFFFF80CC;
#define FTM2C2V                         _FTM2C2V.Word


/*** FTM2C3SC - FTM2 Timer Channel 3 Status and Control Register; 0xFFFF80CE ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS3A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS3B       :1;                                       /* Edge/Level Select Bit B */
    byte MS3A        :1;                                       /* Mode Select A for FTM2 Channel 3 */
    byte MS3B        :1;                                       /* Mode Select B for FTM2 Channel 3 */
    byte CH3IE       :1;                                       /* Channel 3 Interrupt Enable */
    byte CH3F        :1;                                       /* Channel 3 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS3x :2;
    byte grpMS3x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C3SCSTR;
extern volatile FTM2C3SCSTR _FTM2C3SC @0xFFFF80CE;
#define FTM2C3SC                        _FTM2C3SC.Byte
#define FTM2C3SC_ELS3A                  _FTM2C3SC.Bits.ELS3A
#define FTM2C3SC_ELS3B                  _FTM2C3SC.Bits.ELS3B
#define FTM2C3SC_MS3A                   _FTM2C3SC.Bits.MS3A
#define FTM2C3SC_MS3B                   _FTM2C3SC.Bits.MS3B
#define FTM2C3SC_CH3IE                  _FTM2C3SC.Bits.CH3IE
#define FTM2C3SC_CH3F                   _FTM2C3SC.Bits.CH3F
#define FTM2C3SC_ELS3x                  _FTM2C3SC.MergedBits.grpELS3x
#define FTM2C3SC_MS3x                   _FTM2C3SC.MergedBits.grpMS3x

#define FTM2C3SC_ELS3A_MASK             4U
#define FTM2C3SC_ELS3B_MASK             8U
#define FTM2C3SC_MS3A_MASK              16U
#define FTM2C3SC_MS3B_MASK              32U
#define FTM2C3SC_CH3IE_MASK             64U
#define FTM2C3SC_CH3F_MASK              128U
#define FTM2C3SC_ELS3x_MASK             12U
#define FTM2C3SC_ELS3x_BITNUM           2U
#define FTM2C3SC_MS3x_MASK              48U
#define FTM2C3SC_MS3x_BITNUM            4U


/*** FTM2C3V - FTM2 Timer Channel 3 Value Register; 0xFFFF80CF ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C3VH - FTM2 Timer Channel 3 Value Register High; 0xFFFF80CF ***/
    union {
      byte Byte;
    } FTM2C3VHSTR;
    #define FTM2C3VH                    _FTM2C3V.Overlap_STR.FTM2C3VHSTR.Byte
    

    /*** FTM2C3VL - FTM2 Timer Channel 3 Value Register Low; 0xFFFF80D0 ***/
    union {
      byte Byte;
    } FTM2C3VLSTR;
    #define FTM2C3VL                    _FTM2C3V.Overlap_STR.FTM2C3VLSTR.Byte
    
  } Overlap_STR;

} FTM2C3VSTR;
extern volatile FTM2C3VSTR _FTM2C3V @0xFFFF80CF;
#define FTM2C3V                         _FTM2C3V.Word


/*** FTM2C4SC - FTM2 Timer Channel 4 Status and Control Register; 0xFFFF80D1 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS4A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS4B       :1;                                       /* Edge/Level Select Bit B */
    byte MS4A        :1;                                       /* Mode Select A for FTM2 Channel 4 */
    byte MS4B        :1;                                       /* Mode Select B for FTM2 Channel 4 */
    byte CH4IE       :1;                                       /* Channel 4 Interrupt Enable */
    byte CH4F        :1;                                       /* Channel 4 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS4x :2;
    byte grpMS4x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C4SCSTR;
extern volatile FTM2C4SCSTR _FTM2C4SC @0xFFFF80D1;
#define FTM2C4SC                        _FTM2C4SC.Byte
#define FTM2C4SC_ELS4A                  _FTM2C4SC.Bits.ELS4A
#define FTM2C4SC_ELS4B                  _FTM2C4SC.Bits.ELS4B
#define FTM2C4SC_MS4A                   _FTM2C4SC.Bits.MS4A
#define FTM2C4SC_MS4B                   _FTM2C4SC.Bits.MS4B
#define FTM2C4SC_CH4IE                  _FTM2C4SC.Bits.CH4IE
#define FTM2C4SC_CH4F                   _FTM2C4SC.Bits.CH4F
#define FTM2C4SC_ELS4x                  _FTM2C4SC.MergedBits.grpELS4x
#define FTM2C4SC_MS4x                   _FTM2C4SC.MergedBits.grpMS4x

#define FTM2C4SC_ELS4A_MASK             4U
#define FTM2C4SC_ELS4B_MASK             8U
#define FTM2C4SC_MS4A_MASK              16U
#define FTM2C4SC_MS4B_MASK              32U
#define FTM2C4SC_CH4IE_MASK             64U
#define FTM2C4SC_CH4F_MASK              128U
#define FTM2C4SC_ELS4x_MASK             12U
#define FTM2C4SC_ELS4x_BITNUM           2U
#define FTM2C4SC_MS4x_MASK              48U
#define FTM2C4SC_MS4x_BITNUM            4U


/*** FTM2C4V - FTM2 Timer Channel 4 Value Register; 0xFFFF80D2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C4VH - FTM2 Timer Channel 4 Value Register High; 0xFFFF80D2 ***/
    union {
      byte Byte;
    } FTM2C4VHSTR;
    #define FTM2C4VH                    _FTM2C4V.Overlap_STR.FTM2C4VHSTR.Byte
    

    /*** FTM2C4VL - FTM2 Timer Channel 4 Value Register Low; 0xFFFF80D3 ***/
    union {
      byte Byte;
    } FTM2C4VLSTR;
    #define FTM2C4VL                    _FTM2C4V.Overlap_STR.FTM2C4VLSTR.Byte
    
  } Overlap_STR;

} FTM2C4VSTR;
extern volatile FTM2C4VSTR _FTM2C4V @0xFFFF80D2;
#define FTM2C4V                         _FTM2C4V.Word


/*** FTM2C5SC - FTM2 Timer Channel 5 Status and Control Register; 0xFFFF80D4 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS5A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS5B       :1;                                       /* Edge/Level Select Bit B */
    byte MS5A        :1;                                       /* Mode Select A for FTM2 Channel 5 */
    byte MS5B        :1;                                       /* Mode Select B for FTM2 Channel 5 */
    byte CH5IE       :1;                                       /* Channel 5 Interrupt Enable */
    byte CH5F        :1;                                       /* Channel 5 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS5x :2;
    byte grpMS5x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2C5SCSTR;
extern volatile FTM2C5SCSTR _FTM2C5SC @0xFFFF80D4;
#define FTM2C5SC                        _FTM2C5SC.Byte
#define FTM2C5SC_ELS5A                  _FTM2C5SC.Bits.ELS5A
#define FTM2C5SC_ELS5B                  _FTM2C5SC.Bits.ELS5B
#define FTM2C5SC_MS5A                   _FTM2C5SC.Bits.MS5A
#define FTM2C5SC_MS5B                   _FTM2C5SC.Bits.MS5B
#define FTM2C5SC_CH5IE                  _FTM2C5SC.Bits.CH5IE
#define FTM2C5SC_CH5F                   _FTM2C5SC.Bits.CH5F
#define FTM2C5SC_ELS5x                  _FTM2C5SC.MergedBits.grpELS5x
#define FTM2C5SC_MS5x                   _FTM2C5SC.MergedBits.grpMS5x

#define FTM2C5SC_ELS5A_MASK             4U
#define FTM2C5SC_ELS5B_MASK             8U
#define FTM2C5SC_MS5A_MASK              16U
#define FTM2C5SC_MS5B_MASK              32U
#define FTM2C5SC_CH5IE_MASK             64U
#define FTM2C5SC_CH5F_MASK              128U
#define FTM2C5SC_ELS5x_MASK             12U
#define FTM2C5SC_ELS5x_BITNUM           2U
#define FTM2C5SC_MS5x_MASK              48U
#define FTM2C5SC_MS5x_BITNUM            4U


/*** FTM2C5V - FTM2 Timer Channel 5 Value Register; 0xFFFF80D5 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2C5VH - FTM2 Timer Channel 5 Value Register High; 0xFFFF80D5 ***/
    union {
      byte Byte;
    } FTM2C5VHSTR;
    #define FTM2C5VH                    _FTM2C5V.Overlap_STR.FTM2C5VHSTR.Byte
    

    /*** FTM2C5VL - FTM2 Timer Channel 5 Value Register Low; 0xFFFF80D6 ***/
    union {
      byte Byte;
    } FTM2C5VLSTR;
    #define FTM2C5VL                    _FTM2C5V.Overlap_STR.FTM2C5VLSTR.Byte
    
  } Overlap_STR;

} FTM2C5VSTR;
extern volatile FTM2C5VSTR _FTM2C5V @0xFFFF80D5;
#define FTM2C5V                         _FTM2C5V.Word


/*** FTM2CNTIN - FTM2 Counter Initial Value Registers; 0xFFFF80DD ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FTM2CNTINH - FTM2 Counter Initial Value Registers High; 0xFFFF80DD ***/
    union {
      byte Byte;
      struct {
        byte BIT8        :1;                                       /* FTM2 Counter Initial Value Bit 8 */
        byte BIT9        :1;                                       /* FTM2 Counter Initial Value Bit 9 */
        byte BIT10       :1;                                       /* FTM2 Counter Initial Value Bit 10 */
        byte BIT11       :1;                                       /* FTM2 Counter Initial Value Bit 11 */
        byte BIT12       :1;                                       /* FTM2 Counter Initial Value Bit 12 */
        byte BIT13       :1;                                       /* FTM2 Counter Initial Value Bit 13 */
        byte BIT14       :1;                                       /* FTM2 Counter Initial Value Bit 14 */
        byte BIT15       :1;                                       /* FTM2 Counter Initial Value Bit 15 */
      } Bits;
    } FTM2CNTINHSTR;
    #define FTM2CNTINH                  _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Byte
    #define FTM2CNTINH_BIT8             _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT8
    #define FTM2CNTINH_BIT9             _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT9
    #define FTM2CNTINH_BIT10            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT10
    #define FTM2CNTINH_BIT11            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT11
    #define FTM2CNTINH_BIT12            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT12
    #define FTM2CNTINH_BIT13            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT13
    #define FTM2CNTINH_BIT14            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT14
    #define FTM2CNTINH_BIT15            _FTM2CNTIN.Overlap_STR.FTM2CNTINHSTR.Bits.BIT15
    
    #define FTM2CNTINH_BIT8_MASK        1U
    #define FTM2CNTINH_BIT9_MASK        2U
    #define FTM2CNTINH_BIT10_MASK       4U
    #define FTM2CNTINH_BIT11_MASK       8U
    #define FTM2CNTINH_BIT12_MASK       16U
    #define FTM2CNTINH_BIT13_MASK       32U
    #define FTM2CNTINH_BIT14_MASK       64U
    #define FTM2CNTINH_BIT15_MASK       128U
    

    /*** FTM2CNTINL - FTM2 Counter Initial Value Registers Low; 0xFFFF80DE ***/
    union {
      byte Byte;
      struct {
        byte BIT0        :1;                                       /* FTM2 Counter Initial Value Bit 0 */
        byte BIT1        :1;                                       /* FTM2 Counter Initial Value Bit 1 */
        byte BIT2        :1;                                       /* FTM2 Counter Initial Value Bit 2 */
        byte BIT3        :1;                                       /* FTM2 Counter Initial Value Bit 3 */
        byte BIT4        :1;                                       /* FTM2 Counter Initial Value Bit 4 */
        byte BIT5        :1;                                       /* FTM2 Counter Initial Value Bit 5 */
        byte BIT6        :1;                                       /* FTM2 Counter Initial Value Bit 6 */
        byte BIT7        :1;                                       /* FTM2 Counter Initial Value Bit 7 */
      } Bits;
    } FTM2CNTINLSTR;
    #define FTM2CNTINL                  _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Byte
    #define FTM2CNTINL_BIT0             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT0
    #define FTM2CNTINL_BIT1             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT1
    #define FTM2CNTINL_BIT2             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT2
    #define FTM2CNTINL_BIT3             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT3
    #define FTM2CNTINL_BIT4             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT4
    #define FTM2CNTINL_BIT5             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT5
    #define FTM2CNTINL_BIT6             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT6
    #define FTM2CNTINL_BIT7             _FTM2CNTIN.Overlap_STR.FTM2CNTINLSTR.Bits.BIT7
    
    #define FTM2CNTINL_BIT0_MASK        1U
    #define FTM2CNTINL_BIT1_MASK        2U
    #define FTM2CNTINL_BIT2_MASK        4U
    #define FTM2CNTINL_BIT3_MASK        8U
    #define FTM2CNTINL_BIT4_MASK        16U
    #define FTM2CNTINL_BIT5_MASK        32U
    #define FTM2CNTINL_BIT6_MASK        64U
    #define FTM2CNTINL_BIT7_MASK        128U
    
  } Overlap_STR;

  struct {
    word BIT0        :1;                                       /* FTM2 Counter Initial Value Bit 0 */
    word BIT1        :1;                                       /* FTM2 Counter Initial Value Bit 1 */
    word BIT2        :1;                                       /* FTM2 Counter Initial Value Bit 2 */
    word BIT3        :1;                                       /* FTM2 Counter Initial Value Bit 3 */
    word BIT4        :1;                                       /* FTM2 Counter Initial Value Bit 4 */
    word BIT5        :1;                                       /* FTM2 Counter Initial Value Bit 5 */
    word BIT6        :1;                                       /* FTM2 Counter Initial Value Bit 6 */
    word BIT7        :1;                                       /* FTM2 Counter Initial Value Bit 7 */
    word BIT8        :1;                                       /* FTM2 Counter Initial Value Bit 8 */
    word BIT9        :1;                                       /* FTM2 Counter Initial Value Bit 9 */
    word BIT10       :1;                                       /* FTM2 Counter Initial Value Bit 10 */
    word BIT11       :1;                                       /* FTM2 Counter Initial Value Bit 11 */
    word BIT12       :1;                                       /* FTM2 Counter Initial Value Bit 12 */
    word BIT13       :1;                                       /* FTM2 Counter Initial Value Bit 13 */
    word BIT14       :1;                                       /* FTM2 Counter Initial Value Bit 14 */
    word BIT15       :1;                                       /* FTM2 Counter Initial Value Bit 15 */
  } Bits;
} FTM2CNTINSTR;
extern volatile FTM2CNTINSTR _FTM2CNTIN @0xFFFF80DD;
#define FTM2CNTIN                       _FTM2CNTIN.Word
#define FTM2CNTIN_BIT0                  _FTM2CNTIN.Bits.BIT0
#define FTM2CNTIN_BIT1                  _FTM2CNTIN.Bits.BIT1
#define FTM2CNTIN_BIT2                  _FTM2CNTIN.Bits.BIT2
#define FTM2CNTIN_BIT3                  _FTM2CNTIN.Bits.BIT3
#define FTM2CNTIN_BIT4                  _FTM2CNTIN.Bits.BIT4
#define FTM2CNTIN_BIT5                  _FTM2CNTIN.Bits.BIT5
#define FTM2CNTIN_BIT6                  _FTM2CNTIN.Bits.BIT6
#define FTM2CNTIN_BIT7                  _FTM2CNTIN.Bits.BIT7
#define FTM2CNTIN_BIT8                  _FTM2CNTIN.Bits.BIT8
#define FTM2CNTIN_BIT9                  _FTM2CNTIN.Bits.BIT9
#define FTM2CNTIN_BIT10                 _FTM2CNTIN.Bits.BIT10
#define FTM2CNTIN_BIT11                 _FTM2CNTIN.Bits.BIT11
#define FTM2CNTIN_BIT12                 _FTM2CNTIN.Bits.BIT12
#define FTM2CNTIN_BIT13                 _FTM2CNTIN.Bits.BIT13
#define FTM2CNTIN_BIT14                 _FTM2CNTIN.Bits.BIT14
#define FTM2CNTIN_BIT15                 _FTM2CNTIN.Bits.BIT15

#define FTM2CNTIN_BIT0_MASK             1U
#define FTM2CNTIN_BIT1_MASK             2U
#define FTM2CNTIN_BIT2_MASK             4U
#define FTM2CNTIN_BIT3_MASK             8U
#define FTM2CNTIN_BIT4_MASK             16U
#define FTM2CNTIN_BIT5_MASK             32U
#define FTM2CNTIN_BIT6_MASK             64U
#define FTM2CNTIN_BIT7_MASK             128U
#define FTM2CNTIN_BIT8_MASK             256U
#define FTM2CNTIN_BIT9_MASK             512U
#define FTM2CNTIN_BIT10_MASK            1024U
#define FTM2CNTIN_BIT11_MASK            2048U
#define FTM2CNTIN_BIT12_MASK            4096U
#define FTM2CNTIN_BIT13_MASK            8192U
#define FTM2CNTIN_BIT14_MASK            16384U
#define FTM2CNTIN_BIT15_MASK            32768U


/*** FTM2STATUS - FTM2 Capture and Compare Status Register; 0xFFFF80DF ***/
typedef union {
  byte Byte;
  struct {
    byte CH0F        :1;                                       /* Channel 0 Flag */
    byte CH1F        :1;                                       /* Channel 1 Flag */
    byte CH2F        :1;                                       /* Channel 2 Flag */
    byte CH3F        :1;                                       /* Channel 3 Flag */
    byte CH4F        :1;                                       /* Channel 4 Flag */
    byte CH5F        :1;                                       /* Channel 5 Flag */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM2STATUSSTR;
extern volatile FTM2STATUSSTR _FTM2STATUS @0xFFFF80DF;
#define FTM2STATUS                      _FTM2STATUS.Byte
#define FTM2STATUS_CH0F                 _FTM2STATUS.Bits.CH0F
#define FTM2STATUS_CH1F                 _FTM2STATUS.Bits.CH1F
#define FTM2STATUS_CH2F                 _FTM2STATUS.Bits.CH2F
#define FTM2STATUS_CH3F                 _FTM2STATUS.Bits.CH3F
#define FTM2STATUS_CH4F                 _FTM2STATUS.Bits.CH4F
#define FTM2STATUS_CH5F                 _FTM2STATUS.Bits.CH5F

#define FTM2STATUS_CH0F_MASK            1U
#define FTM2STATUS_CH1F_MASK            2U
#define FTM2STATUS_CH2F_MASK            4U
#define FTM2STATUS_CH3F_MASK            8U
#define FTM2STATUS_CH4F_MASK            16U
#define FTM2STATUS_CH5F_MASK            32U


/*** FTM2MODE - FTM2 Features Mode Selection Register; 0xFFFF80E0 ***/
typedef union {
  byte Byte;
  struct {
    byte FTMEN       :1;                                       /* FTM2 Enable */
    byte INIT        :1;                                       /* Initialize the Channels Output */
    byte WPDIS       :1;                                       /* Write Protected Disable */
    byte             :1; 
    byte             :1; 
    byte FAULTM0     :1;                                       /* Fault Control Mode Bits, bit 0 */
    byte FAULTM1     :1;                                       /* Fault Control Mode Bits, bit 1 */
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
} FTM2MODESTR;
extern volatile FTM2MODESTR _FTM2MODE @0xFFFF80E0;
#define FTM2MODE                        _FTM2MODE.Byte
#define FTM2MODE_FTMEN                  _FTM2MODE.Bits.FTMEN
#define FTM2MODE_INIT                   _FTM2MODE.Bits.INIT
#define FTM2MODE_WPDIS                  _FTM2MODE.Bits.WPDIS
#define FTM2MODE_FAULTM0                _FTM2MODE.Bits.FAULTM0
#define FTM2MODE_FAULTM1                _FTM2MODE.Bits.FAULTM1
#define FTM2MODE_FAULTIE                _FTM2MODE.Bits.FAULTIE
#define FTM2MODE_FAULTM                 _FTM2MODE.MergedBits.grpFAULTM

#define FTM2MODE_FTMEN_MASK             1U
#define FTM2MODE_INIT_MASK              2U
#define FTM2MODE_WPDIS_MASK             4U
#define FTM2MODE_FAULTM0_MASK           32U
#define FTM2MODE_FAULTM1_MASK           64U
#define FTM2MODE_FAULTIE_MASK           128U
#define FTM2MODE_FAULTM_MASK            96U
#define FTM2MODE_FAULTM_BITNUM          5U


/*** FTM2SYNC - FTM2 Synchronization Register; 0xFFFF80E1 ***/
typedef union {
  byte Byte;
  struct {
    byte CNTMIN      :1;                                       /* FTM2 Counter is Minimum */
    byte CNTMAX      :1;                                       /* FTM2 Counter is Maximum */
    byte REINIT      :1;                                       /* Reinitialization of FTM2 Counter by Synchronization */
    byte SYNCHOM     :1;                                       /* Output Mask by Synchronization */
    byte TRIG0       :1;                                       /* External Trigger Bit 0 for Synchronization */
    byte TRIG1       :1;                                       /* External Trigger Bit 1 for Synchronization */
    byte TRIG2       :1;                                       /* External Trigger Bit 2 for Synchronization */
    byte SWSYNC      :1;                                       /* Software Trigger for Synchronization */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTRIG :3;
    byte         :1;
  } MergedBits;
} FTM2SYNCSTR;
extern volatile FTM2SYNCSTR _FTM2SYNC @0xFFFF80E1;
#define FTM2SYNC                        _FTM2SYNC.Byte
#define FTM2SYNC_CNTMIN                 _FTM2SYNC.Bits.CNTMIN
#define FTM2SYNC_CNTMAX                 _FTM2SYNC.Bits.CNTMAX
#define FTM2SYNC_REINIT                 _FTM2SYNC.Bits.REINIT
#define FTM2SYNC_SYNCHOM                _FTM2SYNC.Bits.SYNCHOM
#define FTM2SYNC_TRIG0                  _FTM2SYNC.Bits.TRIG0
#define FTM2SYNC_TRIG1                  _FTM2SYNC.Bits.TRIG1
#define FTM2SYNC_TRIG2                  _FTM2SYNC.Bits.TRIG2
#define FTM2SYNC_SWSYNC                 _FTM2SYNC.Bits.SWSYNC
#define FTM2SYNC_TRIG                   _FTM2SYNC.MergedBits.grpTRIG

#define FTM2SYNC_CNTMIN_MASK            1U
#define FTM2SYNC_CNTMAX_MASK            2U
#define FTM2SYNC_REINIT_MASK            4U
#define FTM2SYNC_SYNCHOM_MASK           8U
#define FTM2SYNC_TRIG0_MASK             16U
#define FTM2SYNC_TRIG1_MASK             32U
#define FTM2SYNC_TRIG2_MASK             64U
#define FTM2SYNC_SWSYNC_MASK            128U
#define FTM2SYNC_TRIG_MASK              112U
#define FTM2SYNC_TRIG_BITNUM            4U


/*** FTM2OUTINIT - FTM2 Initial State for Channels Output Register; 0xFFFF80E2 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OI       :1;                                       /* Initial State for Channel 0 Output */
    byte CH1OI       :1;                                       /* Initial State for Channel 1 Output */
    byte CH2OI       :1;                                       /* Initial State for Channel 2 Output */
    byte CH3OI       :1;                                       /* Initial State for Channel 3 Output */
    byte CH4OI       :1;                                       /* Initial State for Channel 4 Output */
    byte CH5OI       :1;                                       /* Initial State for Channel 5 Output */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM2OUTINITSTR;
extern volatile FTM2OUTINITSTR _FTM2OUTINIT @0xFFFF80E2;
#define FTM2OUTINIT                     _FTM2OUTINIT.Byte
#define FTM2OUTINIT_CH0OI               _FTM2OUTINIT.Bits.CH0OI
#define FTM2OUTINIT_CH1OI               _FTM2OUTINIT.Bits.CH1OI
#define FTM2OUTINIT_CH2OI               _FTM2OUTINIT.Bits.CH2OI
#define FTM2OUTINIT_CH3OI               _FTM2OUTINIT.Bits.CH3OI
#define FTM2OUTINIT_CH4OI               _FTM2OUTINIT.Bits.CH4OI
#define FTM2OUTINIT_CH5OI               _FTM2OUTINIT.Bits.CH5OI

#define FTM2OUTINIT_CH0OI_MASK          1U
#define FTM2OUTINIT_CH1OI_MASK          2U
#define FTM2OUTINIT_CH2OI_MASK          4U
#define FTM2OUTINIT_CH3OI_MASK          8U
#define FTM2OUTINIT_CH4OI_MASK          16U
#define FTM2OUTINIT_CH5OI_MASK          32U


/*** FTM2OUTMASK - FTM2 Output Mask Register; 0xFFFF80E3 ***/
typedef union {
  byte Byte;
  struct {
    byte CH0OM       :1;                                       /* Channel 0 Output Mask */
    byte CH1OM       :1;                                       /* Channel 1 Output Mask */
    byte CH2OM       :1;                                       /* Channel 2 Output Mask */
    byte CH3OM       :1;                                       /* Channel 3 Output Mask */
    byte CH4OM       :1;                                       /* Channel 4 Output Mask */
    byte CH5OM       :1;                                       /* Channel 5 Output Mask */
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM2OUTMASKSTR;
extern volatile FTM2OUTMASKSTR _FTM2OUTMASK @0xFFFF80E3;
#define FTM2OUTMASK                     _FTM2OUTMASK.Byte
#define FTM2OUTMASK_CH0OM               _FTM2OUTMASK.Bits.CH0OM
#define FTM2OUTMASK_CH1OM               _FTM2OUTMASK.Bits.CH1OM
#define FTM2OUTMASK_CH2OM               _FTM2OUTMASK.Bits.CH2OM
#define FTM2OUTMASK_CH3OM               _FTM2OUTMASK.Bits.CH3OM
#define FTM2OUTMASK_CH4OM               _FTM2OUTMASK.Bits.CH4OM
#define FTM2OUTMASK_CH5OM               _FTM2OUTMASK.Bits.CH5OM

#define FTM2OUTMASK_CH0OM_MASK          1U
#define FTM2OUTMASK_CH1OM_MASK          2U
#define FTM2OUTMASK_CH2OM_MASK          4U
#define FTM2OUTMASK_CH3OM_MASK          8U
#define FTM2OUTMASK_CH4OM_MASK          16U
#define FTM2OUTMASK_CH5OM_MASK          32U


/*** FTM2COMBINE0 - FTM2 Function For Linked Channel 0 Register; 0xFFFF80E4 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 0 and 1 */
    byte COMP        :1;                                       /* Complementary of Channel 0 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2COMBINE0STR;
extern volatile FTM2COMBINE0STR _FTM2COMBINE0 @0xFFFF80E4;
#define FTM2COMBINE0                    _FTM2COMBINE0.Byte
#define FTM2COMBINE0_COMBINE            _FTM2COMBINE0.Bits.COMBINE
#define FTM2COMBINE0_COMP               _FTM2COMBINE0.Bits.COMP
#define FTM2COMBINE0_DTEN               _FTM2COMBINE0.Bits.DTEN
#define FTM2COMBINE0_SYNCEN             _FTM2COMBINE0.Bits.SYNCEN
#define FTM2COMBINE0_FAULTEN            _FTM2COMBINE0.Bits.FAULTEN
/* FTM2COMBINE_ARR: Access 3 FTM2COMBINEx registers in an array */
#define FTM2COMBINE_ARR                 ((volatile byte *) &FTM2COMBINE0)

#define FTM2COMBINE0_COMBINE_MASK       1U
#define FTM2COMBINE0_COMP_MASK          2U
#define FTM2COMBINE0_DTEN_MASK          16U
#define FTM2COMBINE0_SYNCEN_MASK        32U
#define FTM2COMBINE0_FAULTEN_MASK       64U


/*** FTM2COMBINE1 - FTM2 Function For Linked Channel 1 Register; 0xFFFF80E5 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 2 and 3 */
    byte COMP        :1;                                       /* Complementary of Channel 2 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2COMBINE1STR;
extern volatile FTM2COMBINE1STR _FTM2COMBINE1 @0xFFFF80E5;
#define FTM2COMBINE1                    _FTM2COMBINE1.Byte
#define FTM2COMBINE1_COMBINE            _FTM2COMBINE1.Bits.COMBINE
#define FTM2COMBINE1_COMP               _FTM2COMBINE1.Bits.COMP
#define FTM2COMBINE1_DTEN               _FTM2COMBINE1.Bits.DTEN
#define FTM2COMBINE1_SYNCEN             _FTM2COMBINE1.Bits.SYNCEN
#define FTM2COMBINE1_FAULTEN            _FTM2COMBINE1.Bits.FAULTEN

#define FTM2COMBINE1_COMBINE_MASK       1U
#define FTM2COMBINE1_COMP_MASK          2U
#define FTM2COMBINE1_DTEN_MASK          16U
#define FTM2COMBINE1_SYNCEN_MASK        32U
#define FTM2COMBINE1_FAULTEN_MASK       64U


/*** FTM2COMBINE2 - FTM2 Function For Linked Channel 2 Register; 0xFFFF80E6 ***/
typedef union {
  byte Byte;
  struct {
    byte COMBINE     :1;                                       /* Enables the Combine of the Channels 4 and 5 */
    byte COMP        :1;                                       /* Complementary of Channel 4 */
    byte             :1; 
    byte             :1; 
    byte DTEN        :1;                                       /* Deadtime Enable */
    byte SYNCEN      :1;                                       /* Synchronization Enable */
    byte FAULTEN     :1;                                       /* Fault Control Enable */
    byte             :1; 
  } Bits;
} FTM2COMBINE2STR;
extern volatile FTM2COMBINE2STR _FTM2COMBINE2 @0xFFFF80E6;
#define FTM2COMBINE2                    _FTM2COMBINE2.Byte
#define FTM2COMBINE2_COMBINE            _FTM2COMBINE2.Bits.COMBINE
#define FTM2COMBINE2_COMP               _FTM2COMBINE2.Bits.COMP
#define FTM2COMBINE2_DTEN               _FTM2COMBINE2.Bits.DTEN
#define FTM2COMBINE2_SYNCEN             _FTM2COMBINE2.Bits.SYNCEN
#define FTM2COMBINE2_FAULTEN            _FTM2COMBINE2.Bits.FAULTEN

#define FTM2COMBINE2_COMBINE_MASK       1U
#define FTM2COMBINE2_COMP_MASK          2U
#define FTM2COMBINE2_DTEN_MASK          16U
#define FTM2COMBINE2_SYNCEN_MASK        32U
#define FTM2COMBINE2_FAULTEN_MASK       64U


/*** FTM2DEADTIME - FTM2 Deadtime Insertion Control Register; 0xFFFF80E8 ***/
typedef union {
  byte Byte;
  struct {
    byte DTVAL0      :1;                                       /* Deadtime Value Bits, bit 0 */
    byte DTVAL1      :1;                                       /* Deadtime Value Bits, bit 1 */
    byte DTVAL2      :1;                                       /* Deadtime Value Bits, bit 2 */
    byte DTVAL3      :1;                                       /* Deadtime Value Bits, bit 3 */
    byte DTVAL4      :1;                                       /* Deadtime Value Bits, bit 4 */
    byte DTVAL5      :1;                                       /* Deadtime Value Bits, bit 5 */
    byte DTPS0       :1;                                       /* Deadtime Prescaler Value Bits, bit 0 */
    byte DTPS1       :1;                                       /* Deadtime Prescaler Value Bits, bit 1 */
  } Bits;
  struct {
    byte grpDTVAL :6;
    byte grpDTPS :2;
  } MergedBits;
} FTM2DEADTIMESTR;
extern volatile FTM2DEADTIMESTR _FTM2DEADTIME @0xFFFF80E8;
#define FTM2DEADTIME                    _FTM2DEADTIME.Byte
#define FTM2DEADTIME_DTVAL0             _FTM2DEADTIME.Bits.DTVAL0
#define FTM2DEADTIME_DTVAL1             _FTM2DEADTIME.Bits.DTVAL1
#define FTM2DEADTIME_DTVAL2             _FTM2DEADTIME.Bits.DTVAL2
#define FTM2DEADTIME_DTVAL3             _FTM2DEADTIME.Bits.DTVAL3
#define FTM2DEADTIME_DTVAL4             _FTM2DEADTIME.Bits.DTVAL4
#define FTM2DEADTIME_DTVAL5             _FTM2DEADTIME.Bits.DTVAL5
#define FTM2DEADTIME_DTPS0              _FTM2DEADTIME.Bits.DTPS0
#define FTM2DEADTIME_DTPS1              _FTM2DEADTIME.Bits.DTPS1
#define FTM2DEADTIME_DTVAL              _FTM2DEADTIME.MergedBits.grpDTVAL
#define FTM2DEADTIME_DTPS               _FTM2DEADTIME.MergedBits.grpDTPS

#define FTM2DEADTIME_DTVAL0_MASK        1U
#define FTM2DEADTIME_DTVAL1_MASK        2U
#define FTM2DEADTIME_DTVAL2_MASK        4U
#define FTM2DEADTIME_DTVAL3_MASK        8U
#define FTM2DEADTIME_DTVAL4_MASK        16U
#define FTM2DEADTIME_DTVAL5_MASK        32U
#define FTM2DEADTIME_DTPS0_MASK         64U
#define FTM2DEADTIME_DTPS1_MASK         128U
#define FTM2DEADTIME_DTVAL_MASK         63U
#define FTM2DEADTIME_DTVAL_BITNUM       0U
#define FTM2DEADTIME_DTPS_MASK          192U
#define FTM2DEADTIME_DTPS_BITNUM        6U


/*** FTM2POL - FTM2 Channels Polarity Register; 0xFFFF80EA ***/
typedef union {
  byte Byte;
  struct {
    byte POL0        :1;                                       /* Channel 0 Polarity */
    byte POL1        :1;                                       /* Channel 1 Polarity */
    byte POL2        :1;                                       /* Channel 2 Polarity */
    byte POL3        :1;                                       /* Channel 3 Polarity */
    byte POL4        :1;                                       /* Channel 4 Polarity */
    byte POL5        :1;                                       /* Channel 5 Polarity */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOL  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} FTM2POLSTR;
extern volatile FTM2POLSTR _FTM2POL @0xFFFF80EA;
#define FTM2POL                         _FTM2POL.Byte
#define FTM2POL_POL0                    _FTM2POL.Bits.POL0
#define FTM2POL_POL1                    _FTM2POL.Bits.POL1
#define FTM2POL_POL2                    _FTM2POL.Bits.POL2
#define FTM2POL_POL3                    _FTM2POL.Bits.POL3
#define FTM2POL_POL4                    _FTM2POL.Bits.POL4
#define FTM2POL_POL5                    _FTM2POL.Bits.POL5
#define FTM2POL_POL                     _FTM2POL.MergedBits.grpPOL

#define FTM2POL_POL0_MASK               1U
#define FTM2POL_POL1_MASK               2U
#define FTM2POL_POL2_MASK               4U
#define FTM2POL_POL3_MASK               8U
#define FTM2POL_POL4_MASK               16U
#define FTM2POL_POL5_MASK               32U
#define FTM2POL_POL_MASK                63U
#define FTM2POL_POL_BITNUM              0U


/*** FTM2FMS - FTM2 Fault Mode Status Register; 0xFFFF80EB ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FAULTIN     :1;                                       /* Fault Input */
    byte WPEN        :1;                                       /* Write Protected Enable */
    byte FAULTF      :1;                                       /* Fault Detection Flag */
  } Bits;
} FTM2FMSSTR;
extern volatile FTM2FMSSTR _FTM2FMS @0xFFFF80EB;
#define FTM2FMS                         _FTM2FMS.Byte
#define FTM2FMS_FAULTIN                 _FTM2FMS.Bits.FAULTIN
#define FTM2FMS_WPEN                    _FTM2FMS.Bits.WPEN
#define FTM2FMS_FAULTF                  _FTM2FMS.Bits.FAULTF

#define FTM2FMS_FAULTIN_MASK            32U
#define FTM2FMS_WPEN_MASK               64U
#define FTM2FMS_FAULTF_MASK             128U


/*** FTM2FILTER0 - FTM2 Input Capture Filter Control Register 0; 0xFFFF80EC ***/
typedef union {
  byte Byte;
  struct {
    byte CH0FVAL0    :1;                                       /* Channel 0 Input Filter Bits, bit 0 */
    byte CH0FVAL1    :1;                                       /* Channel 0 Input Filter Bits, bit 1 */
    byte CH0FVAL2    :1;                                       /* Channel 0 Input Filter Bits, bit 2 */
    byte CH0FVAL3    :1;                                       /* Channel 0 Input Filter Bits, bit 3 */
    byte CH1FVAL0    :1;                                       /* Channel 1 Input Filter Bits, bit 0 */
    byte CH1FVAL1    :1;                                       /* Channel 1 Input Filter Bits, bit 1 */
    byte CH1FVAL2    :1;                                       /* Channel 1 Input Filter Bits, bit 2 */
    byte CH1FVAL3    :1;                                       /* Channel 1 Input Filter Bits, bit 3 */
  } Bits;
  struct {
    byte grpCH0FVAL :4;
    byte grpCH1FVAL :4;
  } MergedBits;
} FTM2FILTER0STR;
extern volatile FTM2FILTER0STR _FTM2FILTER0 @0xFFFF80EC;
#define FTM2FILTER0                     _FTM2FILTER0.Byte
#define FTM2FILTER0_CH0FVAL0            _FTM2FILTER0.Bits.CH0FVAL0
#define FTM2FILTER0_CH0FVAL1            _FTM2FILTER0.Bits.CH0FVAL1
#define FTM2FILTER0_CH0FVAL2            _FTM2FILTER0.Bits.CH0FVAL2
#define FTM2FILTER0_CH0FVAL3            _FTM2FILTER0.Bits.CH0FVAL3
#define FTM2FILTER0_CH1FVAL0            _FTM2FILTER0.Bits.CH1FVAL0
#define FTM2FILTER0_CH1FVAL1            _FTM2FILTER0.Bits.CH1FVAL1
#define FTM2FILTER0_CH1FVAL2            _FTM2FILTER0.Bits.CH1FVAL2
#define FTM2FILTER0_CH1FVAL3            _FTM2FILTER0.Bits.CH1FVAL3
/* FTM2FILTER_ARR: Access 2 FTM2FILTERx registers in an array */
#define FTM2FILTER_ARR                  ((volatile byte *) &FTM2FILTER0)
#define FTM2FILTER0_CH0FVAL             _FTM2FILTER0.MergedBits.grpCH0FVAL
#define FTM2FILTER0_CH1FVAL             _FTM2FILTER0.MergedBits.grpCH1FVAL

#define FTM2FILTER0_CH0FVAL0_MASK       1U
#define FTM2FILTER0_CH0FVAL1_MASK       2U
#define FTM2FILTER0_CH0FVAL2_MASK       4U
#define FTM2FILTER0_CH0FVAL3_MASK       8U
#define FTM2FILTER0_CH1FVAL0_MASK       16U
#define FTM2FILTER0_CH1FVAL1_MASK       32U
#define FTM2FILTER0_CH1FVAL2_MASK       64U
#define FTM2FILTER0_CH1FVAL3_MASK       128U
#define FTM2FILTER0_CH0FVAL_MASK        15U
#define FTM2FILTER0_CH0FVAL_BITNUM      0U
#define FTM2FILTER0_CH1FVAL_MASK        240U
#define FTM2FILTER0_CH1FVAL_BITNUM      4U


/*** FTM2FILTER1 - FTM2 Input Capture Filter Control Register 1; 0xFFFF80ED ***/
typedef union {
  byte Byte;
  struct {
    byte CH2FVAL0    :1;                                       /* Channel 2 Input Filter Bits, bit 0 */
    byte CH2FVAL1    :1;                                       /* Channel 2 Input Filter Bits, bit 1 */
    byte CH2FVAL2    :1;                                       /* Channel 2 Input Filter Bits, bit 2 */
    byte CH2FVAL3    :1;                                       /* Channel 2 Input Filter Bits, bit 3 */
    byte CH3FVAL0    :1;                                       /* Channel 3 Input Filter Bits, bit 0 */
    byte CH3FVAL1    :1;                                       /* Channel 3 Input Filter Bits, bit 1 */
    byte CH3FVAL2    :1;                                       /* Channel 3 Input Filter Bits, bit 2 */
    byte CH3FVAL3    :1;                                       /* Channel 3 Input Filter Bits, bit 3 */
  } Bits;
  struct {
    byte grpCH2FVAL :4;
    byte grpCH3FVAL :4;
  } MergedBits;
} FTM2FILTER1STR;
extern volatile FTM2FILTER1STR _FTM2FILTER1 @0xFFFF80ED;
#define FTM2FILTER1                     _FTM2FILTER1.Byte
#define FTM2FILTER1_CH2FVAL0            _FTM2FILTER1.Bits.CH2FVAL0
#define FTM2FILTER1_CH2FVAL1            _FTM2FILTER1.Bits.CH2FVAL1
#define FTM2FILTER1_CH2FVAL2            _FTM2FILTER1.Bits.CH2FVAL2
#define FTM2FILTER1_CH2FVAL3            _FTM2FILTER1.Bits.CH2FVAL3
#define FTM2FILTER1_CH3FVAL0            _FTM2FILTER1.Bits.CH3FVAL0
#define FTM2FILTER1_CH3FVAL1            _FTM2FILTER1.Bits.CH3FVAL1
#define FTM2FILTER1_CH3FVAL2            _FTM2FILTER1.Bits.CH3FVAL2
#define FTM2FILTER1_CH3FVAL3            _FTM2FILTER1.Bits.CH3FVAL3
#define FTM2FILTER1_CH2FVAL             _FTM2FILTER1.MergedBits.grpCH2FVAL
#define FTM2FILTER1_CH3FVAL             _FTM2FILTER1.MergedBits.grpCH3FVAL

#define FTM2FILTER1_CH2FVAL0_MASK       1U
#define FTM2FILTER1_CH2FVAL1_MASK       2U
#define FTM2FILTER1_CH2FVAL2_MASK       4U
#define FTM2FILTER1_CH2FVAL3_MASK       8U
#define FTM2FILTER1_CH3FVAL0_MASK       16U
#define FTM2FILTER1_CH3FVAL1_MASK       32U
#define FTM2FILTER1_CH3FVAL2_MASK       64U
#define FTM2FILTER1_CH3FVAL3_MASK       128U
#define FTM2FILTER1_CH2FVAL_MASK        15U
#define FTM2FILTER1_CH2FVAL_BITNUM      0U
#define FTM2FILTER1_CH3FVAL_MASK        240U
#define FTM2FILTER1_CH3FVAL_BITNUM      4U


/*** FTM2FLTFILTER - FTM2 Fault Input Filter Control Register; 0xFFFF80EE ***/
typedef union {
  byte Byte;
  struct {
    byte FFVAL0      :1;                                       /* Fault Input Filter Bits, bit 0 */
    byte FFVAL1      :1;                                       /* Fault Input Filter Bits, bit 1 */
    byte FFVAL2      :1;                                       /* Fault Input Filter Bits, bit 2 */
    byte FFVAL3      :1;                                       /* Fault Input Filter Bits, bit 3 */
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
} FTM2FLTFILTERSTR;
extern volatile FTM2FLTFILTERSTR _FTM2FLTFILTER @0xFFFF80EE;
#define FTM2FLTFILTER                   _FTM2FLTFILTER.Byte
#define FTM2FLTFILTER_FFVAL0            _FTM2FLTFILTER.Bits.FFVAL0
#define FTM2FLTFILTER_FFVAL1            _FTM2FLTFILTER.Bits.FFVAL1
#define FTM2FLTFILTER_FFVAL2            _FTM2FLTFILTER.Bits.FFVAL2
#define FTM2FLTFILTER_FFVAL3            _FTM2FLTFILTER.Bits.FFVAL3
#define FTM2FLTFILTER_FFVAL             _FTM2FLTFILTER.MergedBits.grpFFVAL

#define FTM2FLTFILTER_FFVAL0_MASK       1U
#define FTM2FLTFILTER_FFVAL1_MASK       2U
#define FTM2FLTFILTER_FFVAL2_MASK       4U
#define FTM2FLTFILTER_FFVAL3_MASK       8U
#define FTM2FLTFILTER_FFVAL_MASK        15U
#define FTM2FLTFILTER_FFVAL_BITNUM      0U


/*** FTM2RFU - FTM2 Register for Future Use; 0xFFFF80EF ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FTM2RFUSTR;
extern volatile FTM2RFUSTR _FTM2RFU @0xFFFF80EF;
#define FTM2RFU                         _FTM2RFU.Byte


/*** SRS - System Reset Status Register; 0xFFFF9800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte LOC         :1;                                       /* Loss-of-Clock Reset */
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS @0xFFFF9800;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_LOC                         _SRS.Bits.LOC
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2U
#define SRS_LOC_MASK                    4U
#define SRS_ILAD_MASK                   8U
#define SRS_ILOP_MASK                   16U
#define SRS_COP_MASK                    32U
#define SRS_PIN_MASK                    64U
#define SRS_POR_MASK                    128U


/*** SOPT - System Options Register; 0xFFFF9802 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte WAITE       :1;                                       /* WAIT Mode Enable */
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT        :1;                                       /* COP Watchdog Timeout */
    byte COPE        :1;                                       /* COP Watchdog Enable */
  } Bits;
} SOPTSTR;
extern volatile SOPTSTR _SOPT @0xFFFF9802;
#define SOPT                            _SOPT.Byte
#define SOPT_WAITE                      _SOPT.Bits.WAITE
#define SOPT_STOPE                      _SOPT.Bits.STOPE
#define SOPT_COPT                       _SOPT.Bits.COPT
#define SOPT_COPE                       _SOPT.Bits.COPE

#define SOPT_WAITE_MASK                 16U
#define SOPT_STOPE_MASK                 32U
#define SOPT_COPT_MASK                  64U
#define SOPT_COPE_MASK                  128U


/*** SMCLK - System MCLK Control Register; 0xFFFF9803 ***/
typedef union {
  byte Byte;
  struct {
    byte MCSEL0      :1;                                       /* MCLK Divide Select, bit 0 */
    byte MCSEL1      :1;                                       /* MCLK Divide Select, bit 1 */
    byte MCSEL2      :1;                                       /* MCLK Divide Select, bit 2 */
    byte             :1; 
    byte MPE         :1;                                       /* MCLK Pin Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpMCSEL :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SMCLKSTR;
extern volatile SMCLKSTR _SMCLK @0xFFFF9803;
#define SMCLK                           _SMCLK.Byte
#define SMCLK_MCSEL0                    _SMCLK.Bits.MCSEL0
#define SMCLK_MCSEL1                    _SMCLK.Bits.MCSEL1
#define SMCLK_MCSEL2                    _SMCLK.Bits.MCSEL2
#define SMCLK_MPE                       _SMCLK.Bits.MPE
#define SMCLK_MCSEL                     _SMCLK.MergedBits.grpMCSEL

#define SMCLK_MCSEL0_MASK               1U
#define SMCLK_MCSEL1_MASK               2U
#define SMCLK_MCSEL2_MASK               4U
#define SMCLK_MPE_MASK                  16U
#define SMCLK_MCSEL_MASK                7U
#define SMCLK_MCSEL_BITNUM              0U


/*** SDID - System Device Identification Register; 0xFFFF9806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0xFFFF9806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpID_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1U
    #define SDIDH_ID9_MASK              2U
    #define SDIDH_ID10_MASK             4U
    #define SDIDH_ID11_MASK             8U
    #define SDIDH_ID_8_MASK             15U
    #define SDIDH_ID_8_BITNUM           0U
    

    /*** SDIDL - System Device Identification Register Low; 0xFFFF9807 ***/
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
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1U
    #define SDIDL_ID1_MASK              2U
    #define SDIDL_ID2_MASK              4U
    #define SDIDL_ID3_MASK              8U
    #define SDIDL_ID4_MASK              16U
    #define SDIDL_ID5_MASK              32U
    #define SDIDL_ID6_MASK              64U
    #define SDIDL_ID7_MASK              128U
    
  } Overlap_STR;

  struct {
    word ID0         :1;                                       /* Part Identification Number, bit 0 */
    word ID1         :1;                                       /* Part Identification Number, bit 1 */
    word ID2         :1;                                       /* Part Identification Number, bit 2 */
    word ID3         :1;                                       /* Part Identification Number, bit 3 */
    word ID4         :1;                                       /* Part Identification Number, bit 4 */
    word ID5         :1;                                       /* Part Identification Number, bit 5 */
    word ID6         :1;                                       /* Part Identification Number, bit 6 */
    word ID7         :1;                                       /* Part Identification Number, bit 7 */
    word ID8         :1;                                       /* Part Identification Number, bit 8 */
    word ID9         :1;                                       /* Part Identification Number, bit 9 */
    word ID10        :1;                                       /* Part Identification Number, bit 10 */
    word ID11        :1;                                       /* Part Identification Number, bit 11 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpID   :12;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} SDIDSTR;
extern volatile SDIDSTR _SDID @0xFFFF9806;
#define SDID                            _SDID.Word
#define SDID_ID0                        _SDID.Bits.ID0
#define SDID_ID1                        _SDID.Bits.ID1
#define SDID_ID2                        _SDID.Bits.ID2
#define SDID_ID3                        _SDID.Bits.ID3
#define SDID_ID4                        _SDID.Bits.ID4
#define SDID_ID5                        _SDID.Bits.ID5
#define SDID_ID6                        _SDID.Bits.ID6
#define SDID_ID7                        _SDID.Bits.ID7
#define SDID_ID8                        _SDID.Bits.ID8
#define SDID_ID9                        _SDID.Bits.ID9
#define SDID_ID10                       _SDID.Bits.ID10
#define SDID_ID11                       _SDID.Bits.ID11
#define SDID_ID                         _SDID.MergedBits.grpID

#define SDID_ID0_MASK                   1U
#define SDID_ID1_MASK                   2U
#define SDID_ID2_MASK                   4U
#define SDID_ID3_MASK                   8U
#define SDID_ID4_MASK                   16U
#define SDID_ID5_MASK                   32U
#define SDID_ID6_MASK                   64U
#define SDID_ID7_MASK                   128U
#define SDID_ID8_MASK                   256U
#define SDID_ID9_MASK                   512U
#define SDID_ID10_MASK                  1024U
#define SDID_ID11_MASK                  2048U
#define SDID_ID_MASK                    4095U
#define SDID_ID_BITNUM                  0U


/*** SRTISC - System Real-Time Interrupt Status and Control Register; 0xFFFF9808 ***/
typedef union {
  byte Byte;
  struct {
    byte RTIS0       :1;                                       /* Real-Time Interrupt Delay Selects, bit 0 */
    byte RTIS1       :1;                                       /* Real-Time Interrupt Delay Selects, bit 1 */
    byte RTIS2       :1;                                       /* Real-Time Interrupt Delay Selects, bit 2 */
    byte             :1; 
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTICLKS     :1;                                       /* Real-Time Interrupt Clock Select */
    byte RTIACK      :1;                                       /* Real-Time Interrupt Acknowledge */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
  struct {
    byte grpRTIS :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SRTISCSTR;
extern volatile SRTISCSTR _SRTISC @0xFFFF9808;
#define SRTISC                          _SRTISC.Byte
#define SRTISC_RTIS0                    _SRTISC.Bits.RTIS0
#define SRTISC_RTIS1                    _SRTISC.Bits.RTIS1
#define SRTISC_RTIS2                    _SRTISC.Bits.RTIS2
#define SRTISC_RTIE                     _SRTISC.Bits.RTIE
#define SRTISC_RTICLKS                  _SRTISC.Bits.RTICLKS
#define SRTISC_RTIACK                   _SRTISC.Bits.RTIACK
#define SRTISC_RTIF                     _SRTISC.Bits.RTIF
#define SRTISC_RTIS                     _SRTISC.MergedBits.grpRTIS

#define SRTISC_RTIS0_MASK               1U
#define SRTISC_RTIS1_MASK               2U
#define SRTISC_RTIS2_MASK               4U
#define SRTISC_RTIE_MASK                16U
#define SRTISC_RTICLKS_MASK             32U
#define SRTISC_RTIACK_MASK              64U
#define SRTISC_RTIF_MASK                128U
#define SRTISC_RTIS_MASK                7U
#define SRTISC_RTIS_BITNUM              0U


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0xFFFF9809 ***/
typedef union {
  byte Byte;
  struct {
    byte BGBE        :1;                                       /* Bandgap Buffer Enable */
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVDIE       :1;                                       /* Low-Voltage Detect Interrupt Enable */
    byte LVDACK      :1;                                       /* Low-Voltage Detect Acknowledge */
    byte LVDF        :1;                                       /* Low-Voltage Detect Flag */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1 @0xFFFF9809;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_BGBE                     _SPMSC1.Bits.BGBE
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVDIE                    _SPMSC1.Bits.LVDIE
#define SPMSC1_LVDACK                   _SPMSC1.Bits.LVDACK
#define SPMSC1_LVDF                     _SPMSC1.Bits.LVDF

#define SPMSC1_BGBE_MASK                1U
#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVDIE_MASK               32U
#define SPMSC1_LVDACK_MASK              64U
#define SPMSC1_LVDF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0xFFFF980A ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte             :1; 
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning Flag */
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2 @0xFFFF980A;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LVWV                     _SPMSC2.Bits.LVWV
#define SPMSC2_LVDV                     _SPMSC2.Bits.LVDV
#define SPMSC2_LVWACK                   _SPMSC2.Bits.LVWACK
#define SPMSC2_LVWF                     _SPMSC2.Bits.LVWF

#define SPMSC2_PPDC_MASK                1U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PPDF_MASK                8U
#define SPMSC2_LVWV_MASK                16U
#define SPMSC2_LVDV_MASK                32U
#define SPMSC2_LVWACK_MASK              64U
#define SPMSC2_LVWF_MASK                128U


/*** SOPT2 - System Options Register 2; 0xFFFF980C ***/
typedef union {
  byte Byte;
  struct {
    byte ADHWTS0     :1;                                       /* ADC Hardware Trigger Select, bit 0 */
    byte ADHWTS1     :1;                                       /* ADC Hardware Trigger Select, bit 1 */
    byte ACIC1       :1;                                       /* Analog Comparator 1 to Input Capture Enable */
    byte TPMCCFG     :1;                                       /* TPM Clock Confguration */
    byte ACIC2       :1;                                       /* Analog Comparator 2 to Input Capture Enable */
    byte SPI1FE      :1;                                       /* SPI1 Ports Input Filter Enable */
    byte SPI2FE      :1;                                       /* SPI2 Ports Input Filter Enable */
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
  struct {
    byte grpADHWTS :2;
    byte grpACIC_1 :1;
    byte         :1;
    byte grpACIC_2 :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SOPT2STR;
extern volatile SOPT2STR _SOPT2 @0xFFFF980C;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_ADHWTS0                   _SOPT2.Bits.ADHWTS0
#define SOPT2_ADHWTS1                   _SOPT2.Bits.ADHWTS1
#define SOPT2_ACIC1                     _SOPT2.Bits.ACIC1
#define SOPT2_TPMCCFG                   _SOPT2.Bits.TPMCCFG
#define SOPT2_ACIC2                     _SOPT2.Bits.ACIC2
#define SOPT2_SPI1FE                    _SOPT2.Bits.SPI1FE
#define SOPT2_SPI2FE                    _SOPT2.Bits.SPI2FE
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS
#define SOPT2_ADHWTS                    _SOPT2.MergedBits.grpADHWTS

#define SOPT2_ADHWTS0_MASK              1U
#define SOPT2_ADHWTS1_MASK              2U
#define SOPT2_ACIC1_MASK                4U
#define SOPT2_TPMCCFG_MASK              8U
#define SOPT2_ACIC2_MASK                16U
#define SOPT2_SPI1FE_MASK               32U
#define SOPT2_SPI2FE_MASK               64U
#define SOPT2_COPCLKS_MASK              128U
#define SOPT2_ADHWTS_MASK               3U
#define SOPT2_ADHWTS_BITNUM             0U


/*** SCGC1 - System Clock Gating Control 1 Register; 0xFFFF980D ***/
typedef union {
  byte Byte;
  struct {
    byte SCI1        :1;                                       /* SCI1 Clock Gate Control */
    byte SCI2        :1;                                       /* SCI2 Clock Gate Control */
    byte IIC         :1;                                       /* IIC Clock Gate Control */
    byte CAN         :1;                                       /* CAN Clock Gate Control */
    byte ADC         :1;                                       /* ADC Clock Gate Control */
    byte FTM1        :1;                                       /* FTM1 Clock Gate Control */
    byte FTM2        :1;                                       /* FTM2 Clock Gate Control */
    byte TPM3        :1;                                       /* TPM3 Clock Gate Control */
  } Bits;
  struct {
    byte grpSCI_1 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFTM_1 :2;
    byte grpTPM_3 :1;
  } MergedBits;
} SCGC1STR;
extern volatile SCGC1STR _SCGC1 @0xFFFF980D;
#define SCGC1                           _SCGC1.Byte
#define SCGC1_SCI1                      _SCGC1.Bits.SCI1
#define SCGC1_SCI2                      _SCGC1.Bits.SCI2
#define SCGC1_IIC                       _SCGC1.Bits.IIC
#define SCGC1_CAN                       _SCGC1.Bits.CAN
#define SCGC1_ADC                       _SCGC1.Bits.ADC
#define SCGC1_FTM1                      _SCGC1.Bits.FTM1
#define SCGC1_FTM2                      _SCGC1.Bits.FTM2
#define SCGC1_TPM3                      _SCGC1.Bits.TPM3
#define SCGC1_SCI_1                     _SCGC1.MergedBits.grpSCI_1
#define SCGC1_FTM_1                     _SCGC1.MergedBits.grpFTM_1
#define SCGC1_SCI                       SCGC1_SCI_1
#define SCGC1_FTM                       SCGC1_FTM_1

#define SCGC1_SCI1_MASK                 1U
#define SCGC1_SCI2_MASK                 2U
#define SCGC1_IIC_MASK                  4U
#define SCGC1_CAN_MASK                  8U
#define SCGC1_ADC_MASK                  16U
#define SCGC1_FTM1_MASK                 32U
#define SCGC1_FTM2_MASK                 64U
#define SCGC1_TPM3_MASK                 128U
#define SCGC1_SCI_1_MASK                3U
#define SCGC1_SCI_1_BITNUM              0U
#define SCGC1_FTM_1_MASK                96U
#define SCGC1_FTM_1_BITNUM              5U


/*** SCGC2 - System Clock Gating Control 2 Register; 0xFFFF980E ***/
typedef union {
  byte Byte;
  struct {
    byte SPI1        :1;                                       /* SPI1 Clock Gate Control */
    byte SPI2        :1;                                       /* SPI2 Clock Gate Control */
    byte RTI         :1;                                       /* RTI Clock Gate Control */
    byte ACMP        :1;                                       /* ACMP Clock Gate Control */
    byte KBI         :1;                                       /* KBI Clock Gate Control */
    byte IRQ         :1;                                       /* IRQ Clock Gate Control */
    byte FLS         :1;                                       /* FLASH Register Clock Gate Control */
    byte CRC         :1;                                       /* CRC Clock Gate Control */
  } Bits;
  struct {
    byte grpSPI_1 :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SCGC2STR;
extern volatile SCGC2STR _SCGC2 @0xFFFF980E;
#define SCGC2                           _SCGC2.Byte
#define SCGC2_SPI1                      _SCGC2.Bits.SPI1
#define SCGC2_SPI2                      _SCGC2.Bits.SPI2
#define SCGC2_RTI                       _SCGC2.Bits.RTI
#define SCGC2_ACMP                      _SCGC2.Bits.ACMP
#define SCGC2_KBI                       _SCGC2.Bits.KBI
#define SCGC2_IRQ                       _SCGC2.Bits.IRQ
#define SCGC2_FLS                       _SCGC2.Bits.FLS
#define SCGC2_CRC                       _SCGC2.Bits.CRC
#define SCGC2_SPI_1                     _SCGC2.MergedBits.grpSPI_1
#define SCGC2_SPI                       SCGC2_SPI_1

#define SCGC2_SPI1_MASK                 1U
#define SCGC2_SPI2_MASK                 2U
#define SCGC2_RTI_MASK                  4U
#define SCGC2_ACMP_MASK                 8U
#define SCGC2_KBI_MASK                  16U
#define SCGC2_IRQ_MASK                  32U
#define SCGC2_FLS_MASK                  64U
#define SCGC2_CRC_MASK                  128U
#define SCGC2_SPI_1_MASK                3U
#define SCGC2_SPI_1_BITNUM              0U


/*** FCDIV - FLASH Clock Divider Register; 0xFFFF9820 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Divisor for FLASH Clock Divider, bit 0 */
    byte FDIV1       :1;                                       /* Divisor for FLASH Clock Divider, bit 1 */
    byte FDIV2       :1;                                       /* Divisor for FLASH Clock Divider, bit 2 */
    byte FDIV3       :1;                                       /* Divisor for FLASH Clock Divider, bit 3 */
    byte FDIV4       :1;                                       /* Divisor for FLASH Clock Divider, bit 4 */
    byte FDIV5       :1;                                       /* Divisor for FLASH Clock Divider, bit 5 */
    byte PRDIV8      :1;                                       /* Prescale (Divide) FLASH Clock by 8 */
    byte FDIVLD      :1;                                       /* Divisor Loaded Status Flag */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte grpPRDIV_8 :1;
    byte         :1;
  } MergedBits;
} FCDIVSTR;
extern volatile FCDIVSTR _FCDIV @0xFFFF9820;
#define FCDIV                           _FCDIV.Byte
#define FCDIV_FDIV0                     _FCDIV.Bits.FDIV0
#define FCDIV_FDIV1                     _FCDIV.Bits.FDIV1
#define FCDIV_FDIV2                     _FCDIV.Bits.FDIV2
#define FCDIV_FDIV3                     _FCDIV.Bits.FDIV3
#define FCDIV_FDIV4                     _FCDIV.Bits.FDIV4
#define FCDIV_FDIV5                     _FCDIV.Bits.FDIV5
#define FCDIV_PRDIV8                    _FCDIV.Bits.PRDIV8
#define FCDIV_FDIVLD                    _FCDIV.Bits.FDIVLD
#define FCDIV_FDIV                      _FCDIV.MergedBits.grpFDIV

#define FCDIV_FDIV0_MASK                1U
#define FCDIV_FDIV1_MASK                2U
#define FCDIV_FDIV2_MASK                4U
#define FCDIV_FDIV3_MASK                8U
#define FCDIV_FDIV4_MASK                16U
#define FCDIV_FDIV5_MASK                32U
#define FCDIV_PRDIV8_MASK               64U
#define FCDIV_FDIVLD_MASK               128U
#define FCDIV_FDIV_MASK                 63U
#define FCDIV_FDIV_BITNUM               0U


/*** FOPT - Flash Options Register; 0xFFFF9821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0xFFFF9821;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC0                       _FOPT.Bits.SEC0
#define FOPT_SEC1                       _FOPT.Bits.SEC1
#define FOPT_KEYEN0                     _FOPT.Bits.KEYEN0
#define FOPT_KEYEN1                     _FOPT.Bits.KEYEN1
#define FOPT_SEC                        _FOPT.MergedBits.grpSEC
#define FOPT_KEYEN                      _FOPT.MergedBits.grpKEYEN

#define FOPT_SEC0_MASK                  1U
#define FOPT_SEC1_MASK                  2U
#define FOPT_KEYEN0_MASK                64U
#define FOPT_KEYEN1_MASK                128U
#define FOPT_SEC_MASK                   3U
#define FOPT_SEC_BITNUM                 0U
#define FOPT_KEYEN_MASK                 192U
#define FOPT_KEYEN_BITNUM               6U


/*** FCNFG - Flash Configuration Register; 0xFFFF9823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Security Key Writing */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0xFFFF9823;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - Flash Protection Register; 0xFFFF9824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPOPEN      :1;                                       /* Flash Protection Open */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0xFFFF9824;
#define FPROT                           _FPROT.Byte
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPS0                      _FPROT.Bits.FPS0
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS                       _FPROT.MergedBits.grpFPS

#define FPROT_FPOPEN_MASK               1U
#define FPROT_FPS0_MASK                 2U
#define FPROT_FPS1_MASK                 4U
#define FPROT_FPS2_MASK                 8U
#define FPROT_FPS3_MASK                 16U
#define FPROT_FPS4_MASK                 32U
#define FPROT_FPS5_MASK                 64U
#define FPROT_FPS6_MASK                 128U
#define FPROT_FPS_MASK                  254U
#define FPROT_FPS_BITNUM                1U


/*** FSTAT - Flash Status Register; 0xFFFF9825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0xFFFF9825;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4U
#define FSTAT_FACCERR_MASK              16U
#define FSTAT_FPVIOL_MASK               32U
#define FSTAT_FCCF_MASK                 64U
#define FSTAT_FCBEF_MASK                128U


/*** FCMD - Flash Command Register; 0xFFFF9826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* Flash Command, bit 0 */
    byte FCMD1       :1;                                       /* Flash Command, bit 1 */
    byte FCMD2       :1;                                       /* Flash Command, bit 2 */
    byte FCMD3       :1;                                       /* Flash Command, bit 3 */
    byte FCMD4       :1;                                       /* Flash Command, bit 4 */
    byte FCMD5       :1;                                       /* Flash Command, bit 5 */
    byte FCMD6       :1;                                       /* Flash Command, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpFCMD :7;
    byte         :1;
  } MergedBits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @0xFFFF9826;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD                       _FCMD.MergedBits.grpFCMD

#define FCMD_FCMD0_MASK                 1U
#define FCMD_FCMD1_MASK                 2U
#define FCMD_FCMD2_MASK                 4U
#define FCMD_FCMD3_MASK                 8U
#define FCMD_FCMD4_MASK                 16U
#define FCMD_FCMD5_MASK                 32U
#define FCMD_FCMD6_MASK                 64U
#define FCMD_FCMD_MASK                  127U
#define FCMD_FCMD_BITNUM                0U


/*** TPM3SC - TPM3 Status and Control Register; 0xFFFF9830 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM3SCSTR;
extern volatile TPM3SCSTR _TPM3SC @0xFFFF9830;
#define TPM3SC                          _TPM3SC.Byte
#define TPM3SC_PS0                      _TPM3SC.Bits.PS0
#define TPM3SC_PS1                      _TPM3SC.Bits.PS1
#define TPM3SC_PS2                      _TPM3SC.Bits.PS2
#define TPM3SC_CLKSA                    _TPM3SC.Bits.CLKSA
#define TPM3SC_CLKSB                    _TPM3SC.Bits.CLKSB
#define TPM3SC_CPWMS                    _TPM3SC.Bits.CPWMS
#define TPM3SC_TOIE                     _TPM3SC.Bits.TOIE
#define TPM3SC_TOF                      _TPM3SC.Bits.TOF
#define TPM3SC_PS                       _TPM3SC.MergedBits.grpPS
#define TPM3SC_CLKSx                    _TPM3SC.MergedBits.grpCLKSx

#define TPM3SC_PS0_MASK                 1U
#define TPM3SC_PS1_MASK                 2U
#define TPM3SC_PS2_MASK                 4U
#define TPM3SC_CLKSA_MASK               8U
#define TPM3SC_CLKSB_MASK               16U
#define TPM3SC_CPWMS_MASK               32U
#define TPM3SC_TOIE_MASK                64U
#define TPM3SC_TOF_MASK                 128U
#define TPM3SC_PS_MASK                  7U
#define TPM3SC_PS_BITNUM                0U
#define TPM3SC_CLKSx_MASK               24U
#define TPM3SC_CLKSx_BITNUM             3U


/*** TPM3CNT - TPM3 Timer Counter Register; 0xFFFF9831 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM3CNTH - TPM3 Timer Counter Register High; 0xFFFF9831 ***/
    union {
      byte Byte;
    } TPM3CNTHSTR;
    #define TPM3CNTH                    _TPM3CNT.Overlap_STR.TPM3CNTHSTR.Byte
    

    /*** TPM3CNTL - TPM3 Timer Counter Register Low; 0xFFFF9832 ***/
    union {
      byte Byte;
    } TPM3CNTLSTR;
    #define TPM3CNTL                    _TPM3CNT.Overlap_STR.TPM3CNTLSTR.Byte
    
  } Overlap_STR;

} TPM3CNTSTR;
extern volatile TPM3CNTSTR _TPM3CNT @0xFFFF9831;
#define TPM3CNT                         _TPM3CNT.Word


/*** TPM3MOD - TPM3 Timer Counter Modulo Register; 0xFFFF9833 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM3MODH - TPM3 Timer Counter Modulo Register High; 0xFFFF9833 ***/
    union {
      byte Byte;
    } TPM3MODHSTR;
    #define TPM3MODH                    _TPM3MOD.Overlap_STR.TPM3MODHSTR.Byte
    

    /*** TPM3MODL - TPM3 Timer Counter Modulo Register Low; 0xFFFF9834 ***/
    union {
      byte Byte;
    } TPM3MODLSTR;
    #define TPM3MODL                    _TPM3MOD.Overlap_STR.TPM3MODLSTR.Byte
    
  } Overlap_STR;

} TPM3MODSTR;
extern volatile TPM3MODSTR _TPM3MOD @0xFFFF9833;
#define TPM3MOD                         _TPM3MOD.Word


/*** TPM3C0SC - TPM3 Timer Channel 0 Status and Control Register; 0xFFFF9835 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM3C0SCSTR;
extern volatile TPM3C0SCSTR _TPM3C0SC @0xFFFF9835;
#define TPM3C0SC                        _TPM3C0SC.Byte
#define TPM3C0SC_ELS0A                  _TPM3C0SC.Bits.ELS0A
#define TPM3C0SC_ELS0B                  _TPM3C0SC.Bits.ELS0B
#define TPM3C0SC_MS0A                   _TPM3C0SC.Bits.MS0A
#define TPM3C0SC_MS0B                   _TPM3C0SC.Bits.MS0B
#define TPM3C0SC_CH0IE                  _TPM3C0SC.Bits.CH0IE
#define TPM3C0SC_CH0F                   _TPM3C0SC.Bits.CH0F
#define TPM3C0SC_ELS0x                  _TPM3C0SC.MergedBits.grpELS0x
#define TPM3C0SC_MS0x                   _TPM3C0SC.MergedBits.grpMS0x

#define TPM3C0SC_ELS0A_MASK             4U
#define TPM3C0SC_ELS0B_MASK             8U
#define TPM3C0SC_MS0A_MASK              16U
#define TPM3C0SC_MS0B_MASK              32U
#define TPM3C0SC_CH0IE_MASK             64U
#define TPM3C0SC_CH0F_MASK              128U
#define TPM3C0SC_ELS0x_MASK             12U
#define TPM3C0SC_ELS0x_BITNUM           2U
#define TPM3C0SC_MS0x_MASK              48U
#define TPM3C0SC_MS0x_BITNUM            4U


/*** TPM3C0V - TPM3 Timer Channel 0 Value Register; 0xFFFF9836 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM3C0VH - TPM3 Timer Channel 0 Value Register High; 0xFFFF9836 ***/
    union {
      byte Byte;
    } TPM3C0VHSTR;
    #define TPM3C0VH                    _TPM3C0V.Overlap_STR.TPM3C0VHSTR.Byte
    

    /*** TPM3C0VL - TPM3 Timer Channel 0 Value Register Low; 0xFFFF9837 ***/
    union {
      byte Byte;
    } TPM3C0VLSTR;
    #define TPM3C0VL                    _TPM3C0V.Overlap_STR.TPM3C0VLSTR.Byte
    
  } Overlap_STR;

} TPM3C0VSTR;
extern volatile TPM3C0VSTR _TPM3C0V @0xFFFF9836;
#define TPM3C0V                         _TPM3C0V.Word


/*** TPM3C1SC - TPM3 Timer Channel 1 Status and Control Register; 0xFFFF9838 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS1A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS1B       :1;                                       /* Edge/Level Select Bit B */
    byte MS1A        :1;                                       /* Mode Select A for TPM Channel 1 */
    byte MS1B        :1;                                       /* Mode Select B for TPM Channel 1 */
    byte CH1IE       :1;                                       /* Channel 1 Interrupt Enable */
    byte CH1F        :1;                                       /* Channel 1 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS1x :2;
    byte grpMS1x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM3C1SCSTR;
extern volatile TPM3C1SCSTR _TPM3C1SC @0xFFFF9838;
#define TPM3C1SC                        _TPM3C1SC.Byte
#define TPM3C1SC_ELS1A                  _TPM3C1SC.Bits.ELS1A
#define TPM3C1SC_ELS1B                  _TPM3C1SC.Bits.ELS1B
#define TPM3C1SC_MS1A                   _TPM3C1SC.Bits.MS1A
#define TPM3C1SC_MS1B                   _TPM3C1SC.Bits.MS1B
#define TPM3C1SC_CH1IE                  _TPM3C1SC.Bits.CH1IE
#define TPM3C1SC_CH1F                   _TPM3C1SC.Bits.CH1F
#define TPM3C1SC_ELS1x                  _TPM3C1SC.MergedBits.grpELS1x
#define TPM3C1SC_MS1x                   _TPM3C1SC.MergedBits.grpMS1x

#define TPM3C1SC_ELS1A_MASK             4U
#define TPM3C1SC_ELS1B_MASK             8U
#define TPM3C1SC_MS1A_MASK              16U
#define TPM3C1SC_MS1B_MASK              32U
#define TPM3C1SC_CH1IE_MASK             64U
#define TPM3C1SC_CH1F_MASK              128U
#define TPM3C1SC_ELS1x_MASK             12U
#define TPM3C1SC_ELS1x_BITNUM           2U
#define TPM3C1SC_MS1x_MASK              48U
#define TPM3C1SC_MS1x_BITNUM            4U


/*** TPM3C1V - TPM3 Timer Channel 1 Value Register; 0xFFFF9839 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM3C1VH - TPM3 Timer Channel 1 Value Register High; 0xFFFF9839 ***/
    union {
      byte Byte;
    } TPM3C1VHSTR;
    #define TPM3C1VH                    _TPM3C1V.Overlap_STR.TPM3C1VHSTR.Byte
    

    /*** TPM3C1VL - TPM3 Timer Channel 1 Value Register Low; 0xFFFF983A ***/
    union {
      byte Byte;
    } TPM3C1VLSTR;
    #define TPM3C1VL                    _TPM3C1V.Overlap_STR.TPM3C1VLSTR.Byte
    
  } Overlap_STR;

} TPM3C1VSTR;
extern volatile TPM3C1VSTR _TPM3C1V @0xFFFF9839;
#define TPM3C1V                         _TPM3C1V.Word


/*** PTAPE - Port A Pull Enable Register; 0xFFFF9840 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Internal Pull Enable for Port A Bit 4 */
    byte PTAPE5      :1;                                       /* Internal Pull Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Internal Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Internal Pull Enable for Port A Bit 7 */
  } Bits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE @0xFFFF9840;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1U
#define PTAPE_PTAPE1_MASK               2U
#define PTAPE_PTAPE2_MASK               4U
#define PTAPE_PTAPE3_MASK               8U
#define PTAPE_PTAPE4_MASK               16U
#define PTAPE_PTAPE5_MASK               32U
#define PTAPE_PTAPE6_MASK               64U
#define PTAPE_PTAPE7_MASK               128U


/*** PTASE - Port A Slew Rate Enable Register; 0xFFFF9841 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Output Slew Rate Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Output Slew Rate Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Output Slew Rate Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Output Slew Rate Enable for Port A Bit 3 */
    byte PTASE4      :1;                                       /* Output Slew Rate Enable for Port A Bit 4 */
    byte PTASE5      :1;                                       /* Output Slew Rate Enable for Port A Bit 5 */
    byte PTASE6      :1;                                       /* Output Slew Rate Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Output Slew Rate Enable for Port A Bit 7 */
  } Bits;
} PTASESTR;
extern volatile PTASESTR _PTASE @0xFFFF9841;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1U
#define PTASE_PTASE1_MASK               2U
#define PTASE_PTASE2_MASK               4U
#define PTASE_PTASE3_MASK               8U
#define PTASE_PTASE4_MASK               16U
#define PTASE_PTASE5_MASK               32U
#define PTASE_PTASE6_MASK               64U
#define PTASE_PTASE7_MASK               128U


/*** PTADS - Port A Drive Strength Selection Register; 0xFFFF9842 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte PTADS4      :1;                                       /* Output Drive Strength Selection for Port A Bit 4 */
    byte PTADS5      :1;                                       /* Output Drive Strength Selection for Port A Bit 5 */
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
} PTADSSTR;
extern volatile PTADSSTR _PTADS @0xFFFF9842;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1U
#define PTADS_PTADS1_MASK               2U
#define PTADS_PTADS2_MASK               4U
#define PTADS_PTADS3_MASK               8U
#define PTADS_PTADS4_MASK               16U
#define PTADS_PTADS5_MASK               32U
#define PTADS_PTADS6_MASK               64U
#define PTADS_PTADS7_MASK               128U


/*** PTBPE - Port B Pull Enable Register; 0xFFFF9844 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Internal Pull Enable for Port B Bit 2 */
    byte PTBPE3      :1;                                       /* Internal Pull Enable for Port B Bit 3 */
    byte PTBPE4      :1;                                       /* Internal Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Internal Pull Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Internal Pull Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Internal Pull Enable for Port B Bit 7 */
  } Bits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE @0xFFFF9844;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE3                    _PTBPE.Bits.PTBPE3
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7

#define PTBPE_PTBPE0_MASK               1U
#define PTBPE_PTBPE1_MASK               2U
#define PTBPE_PTBPE2_MASK               4U
#define PTBPE_PTBPE3_MASK               8U
#define PTBPE_PTBPE4_MASK               16U
#define PTBPE_PTBPE5_MASK               32U
#define PTBPE_PTBPE6_MASK               64U
#define PTBPE_PTBPE7_MASK               128U


/*** PTBSE - Port B Slew Rate Enable Register; 0xFFFF9845 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       /* Output Slew Rate Enable for Port B Bit 0 */
    byte PTBSE1      :1;                                       /* Output Slew Rate Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Output Slew Rate Enable for Port B Bit 2 */
    byte PTBSE3      :1;                                       /* Output Slew Rate Enable for Port B Bit 3 */
    byte PTBSE4      :1;                                       /* Output Slew Rate Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Output Slew Rate Enable for Port B Bit 5 */
    byte PTBSE6      :1;                                       /* Output Slew Rate Enable for Port B Bit 6 */
    byte PTBSE7      :1;                                       /* Output Slew Rate Enable for Port B Bit 7 */
  } Bits;
} PTBSESTR;
extern volatile PTBSESTR _PTBSE @0xFFFF9845;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7

#define PTBSE_PTBSE0_MASK               1U
#define PTBSE_PTBSE1_MASK               2U
#define PTBSE_PTBSE2_MASK               4U
#define PTBSE_PTBSE3_MASK               8U
#define PTBSE_PTBSE4_MASK               16U
#define PTBSE_PTBSE5_MASK               32U
#define PTBSE_PTBSE6_MASK               64U
#define PTBSE_PTBSE7_MASK               128U


/*** PTBDS - Port B Drive Strength Selection Register; 0xFFFF9846 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTBDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTBDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTBDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
} PTBDSSTR;
extern volatile PTBDSSTR _PTBDS @0xFFFF9846;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7

#define PTBDS_PTBDS0_MASK               1U
#define PTBDS_PTBDS1_MASK               2U
#define PTBDS_PTBDS2_MASK               4U
#define PTBDS_PTBDS3_MASK               8U
#define PTBDS_PTBDS4_MASK               16U
#define PTBDS_PTBDS5_MASK               32U
#define PTBDS_PTBDS6_MASK               64U
#define PTBDS_PTBDS7_MASK               128U


/*** PTCPE - Port C Pull Enable Register; 0xFFFF9848 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Internal Pull Enable for Port C Bit 0 */
    byte PTCPE1      :1;                                       /* Internal Pull Enable for Port C Bit 1 */
    byte PTCPE2      :1;                                       /* Internal Pull Enable for Port C Bit 2 */
    byte PTCPE3      :1;                                       /* Internal Pull Enable for Port C Bit 3 */
    byte PTCPE4      :1;                                       /* Internal Pull Enable for Port C Bit 4 */
    byte PTCPE5      :1;                                       /* Internal Pull Enable for Port C Bit 5 */
    byte PTCPE6      :1;                                       /* Internal Pull Enable for Port C Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTCPE :7;
    byte         :1;
  } MergedBits;
} PTCPESTR;
extern volatile PTCPESTR _PTCPE @0xFFFF9848;
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE                     _PTCPE.MergedBits.grpPTCPE

#define PTCPE_PTCPE0_MASK               1U
#define PTCPE_PTCPE1_MASK               2U
#define PTCPE_PTCPE2_MASK               4U
#define PTCPE_PTCPE3_MASK               8U
#define PTCPE_PTCPE4_MASK               16U
#define PTCPE_PTCPE5_MASK               32U
#define PTCPE_PTCPE6_MASK               64U
#define PTCPE_PTCPE_MASK                127U
#define PTCPE_PTCPE_BITNUM              0U


/*** PTCSE - Port C Slew Rate Enable Register; 0xFFFF9849 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       /* Output Slew Rate Enable for Port C Bit 0 */
    byte PTCSE1      :1;                                       /* Output Slew Rate Enable for Port C Bit 1 */
    byte PTCSE2      :1;                                       /* Output Slew Rate Enable for Port C Bit 2 */
    byte PTCSE3      :1;                                       /* Output Slew Rate Enable for Port C Bit 3 */
    byte PTCSE4      :1;                                       /* Output Slew Rate Enable for Port C Bit 4 */
    byte PTCSE5      :1;                                       /* Output Slew Rate Enable for Port C Bit 5 */
    byte PTCSE6      :1;                                       /* Output Slew Rate Enable for Port C Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTCSE :7;
    byte         :1;
  } MergedBits;
} PTCSESTR;
extern volatile PTCSESTR _PTCSE @0xFFFF9849;
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE                     _PTCSE.MergedBits.grpPTCSE

#define PTCSE_PTCSE0_MASK               1U
#define PTCSE_PTCSE1_MASK               2U
#define PTCSE_PTCSE2_MASK               4U
#define PTCSE_PTCSE3_MASK               8U
#define PTCSE_PTCSE4_MASK               16U
#define PTCSE_PTCSE5_MASK               32U
#define PTCSE_PTCSE6_MASK               64U
#define PTCSE_PTCSE_MASK                127U
#define PTCSE_PTCSE_BITNUM              0U


/*** PTCDS - Port C Drive Strength Selection Register; 0xFFFF984A ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       /* Output Drive Strength Selection for Port C Bit 0 */
    byte PTCDS1      :1;                                       /* Output Drive Strength Selection for Port C Bit 1 */
    byte PTCDS2      :1;                                       /* Output Drive Strength Selection for Port C Bit 2 */
    byte PTCDS3      :1;                                       /* Output Drive Strength Selection for Port C Bit 3 */
    byte PTCDS4      :1;                                       /* Output Drive Strength Selection for Port C Bit 4 */
    byte PTCDS5      :1;                                       /* Output Drive Strength Selection for Port C Bit 5 */
    byte PTCDS6      :1;                                       /* Output Drive Strength Selection for Port C Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTCDS :7;
    byte         :1;
  } MergedBits;
} PTCDSSTR;
extern volatile PTCDSSTR _PTCDS @0xFFFF984A;
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS                     _PTCDS.MergedBits.grpPTCDS

#define PTCDS_PTCDS0_MASK               1U
#define PTCDS_PTCDS1_MASK               2U
#define PTCDS_PTCDS2_MASK               4U
#define PTCDS_PTCDS3_MASK               8U
#define PTCDS_PTCDS4_MASK               16U
#define PTCDS_PTCDS5_MASK               32U
#define PTCDS_PTCDS6_MASK               64U
#define PTCDS_PTCDS_MASK                127U
#define PTCDS_PTCDS_BITNUM              0U


/*** PTDPE - Port D Pull Enable Register; 0xFFFF984C ***/
typedef union {
  byte Byte;
  struct {
    byte PTDPE0      :1;                                       /* Internal Pull Enable for Port D Bit 0 */
    byte PTDPE1      :1;                                       /* Internal Pull Enable for Port D Bit 1 */
    byte PTDPE2      :1;                                       /* Internal Pull Enable for Port D Bit 2 */
    byte PTDPE3      :1;                                       /* Internal Pull Enable for Port D Bit 3 */
    byte PTDPE4      :1;                                       /* Internal Pull Enable for Port D Bit 4 */
    byte PTDPE5      :1;                                       /* Internal Pull Enable for Port D Bit 5 */
    byte PTDPE6      :1;                                       /* Internal Pull Enable for Port D Bit 6 */
    byte PTDPE7      :1;                                       /* Internal Pull Enable for Port D Bit 7 */
  } Bits;
} PTDPESTR;
extern volatile PTDPESTR _PTDPE @0xFFFF984C;
#define PTDPE                           _PTDPE.Byte
#define PTDPE_PTDPE0                    _PTDPE.Bits.PTDPE0
#define PTDPE_PTDPE1                    _PTDPE.Bits.PTDPE1
#define PTDPE_PTDPE2                    _PTDPE.Bits.PTDPE2
#define PTDPE_PTDPE3                    _PTDPE.Bits.PTDPE3
#define PTDPE_PTDPE4                    _PTDPE.Bits.PTDPE4
#define PTDPE_PTDPE5                    _PTDPE.Bits.PTDPE5
#define PTDPE_PTDPE6                    _PTDPE.Bits.PTDPE6
#define PTDPE_PTDPE7                    _PTDPE.Bits.PTDPE7

#define PTDPE_PTDPE0_MASK               1U
#define PTDPE_PTDPE1_MASK               2U
#define PTDPE_PTDPE2_MASK               4U
#define PTDPE_PTDPE3_MASK               8U
#define PTDPE_PTDPE4_MASK               16U
#define PTDPE_PTDPE5_MASK               32U
#define PTDPE_PTDPE6_MASK               64U
#define PTDPE_PTDPE7_MASK               128U


/*** PTDSE - Port D Slew Rate Enable Register; 0xFFFF984D ***/
typedef union {
  byte Byte;
  struct {
    byte PTDSE0      :1;                                       /* Output Slew Rate Enable for Port D Bit 0 */
    byte PTDSE1      :1;                                       /* Output Slew Rate Enable for Port D Bit 1 */
    byte PTDSE2      :1;                                       /* Output Slew Rate Enable for Port D Bit 2 */
    byte PTDSE3      :1;                                       /* Output Slew Rate Enable for Port D Bit 3 */
    byte PTDSE4      :1;                                       /* Output Slew Rate Enable for Port D Bit 4 */
    byte PTDSE5      :1;                                       /* Output Slew Rate Enable for Port D Bit 5 */
    byte PTDSE6      :1;                                       /* Output Slew Rate Enable for Port D Bit 6 */
    byte PTDSE7      :1;                                       /* Output Slew Rate Enable for Port D Bit 7 */
  } Bits;
} PTDSESTR;
extern volatile PTDSESTR _PTDSE @0xFFFF984D;
#define PTDSE                           _PTDSE.Byte
#define PTDSE_PTDSE0                    _PTDSE.Bits.PTDSE0
#define PTDSE_PTDSE1                    _PTDSE.Bits.PTDSE1
#define PTDSE_PTDSE2                    _PTDSE.Bits.PTDSE2
#define PTDSE_PTDSE3                    _PTDSE.Bits.PTDSE3
#define PTDSE_PTDSE4                    _PTDSE.Bits.PTDSE4
#define PTDSE_PTDSE5                    _PTDSE.Bits.PTDSE5
#define PTDSE_PTDSE6                    _PTDSE.Bits.PTDSE6
#define PTDSE_PTDSE7                    _PTDSE.Bits.PTDSE7

#define PTDSE_PTDSE0_MASK               1U
#define PTDSE_PTDSE1_MASK               2U
#define PTDSE_PTDSE2_MASK               4U
#define PTDSE_PTDSE3_MASK               8U
#define PTDSE_PTDSE4_MASK               16U
#define PTDSE_PTDSE5_MASK               32U
#define PTDSE_PTDSE6_MASK               64U
#define PTDSE_PTDSE7_MASK               128U


/*** PTDDS - Port D Drive Strength Selection Register; 0xFFFF984E ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDS0      :1;                                       /* Output Drive Strength Selection for Port D Bit 0 */
    byte PTDDS1      :1;                                       /* Output Drive Strength Selection for Port D Bit 1 */
    byte PTDDS2      :1;                                       /* Output Drive Strength Selection for Port D Bit 2 */
    byte PTDDS3      :1;                                       /* Output Drive Strength Selection for Port D Bit 3 */
    byte PTDDS4      :1;                                       /* Output Drive Strength Selection for Port D Bit 4 */
    byte PTDDS5      :1;                                       /* Output Drive Strength Selection for Port D Bit 5 */
    byte PTDDS6      :1;                                       /* Output Drive Strength Selection for Port D Bit 6 */
    byte PTDDS7      :1;                                       /* Output Drive Strength Selection for Port D Bit 7 */
  } Bits;
} PTDDSSTR;
extern volatile PTDDSSTR _PTDDS @0xFFFF984E;
#define PTDDS                           _PTDDS.Byte
#define PTDDS_PTDDS0                    _PTDDS.Bits.PTDDS0
#define PTDDS_PTDDS1                    _PTDDS.Bits.PTDDS1
#define PTDDS_PTDDS2                    _PTDDS.Bits.PTDDS2
#define PTDDS_PTDDS3                    _PTDDS.Bits.PTDDS3
#define PTDDS_PTDDS4                    _PTDDS.Bits.PTDDS4
#define PTDDS_PTDDS5                    _PTDDS.Bits.PTDDS5
#define PTDDS_PTDDS6                    _PTDDS.Bits.PTDDS6
#define PTDDS_PTDDS7                    _PTDDS.Bits.PTDDS7

#define PTDDS_PTDDS0_MASK               1U
#define PTDDS_PTDDS1_MASK               2U
#define PTDDS_PTDDS2_MASK               4U
#define PTDDS_PTDDS3_MASK               8U
#define PTDDS_PTDDS4_MASK               16U
#define PTDDS_PTDDS5_MASK               32U
#define PTDDS_PTDDS6_MASK               64U
#define PTDDS_PTDDS7_MASK               128U


/*** PTEPE - Port E Pull Enable Register; 0xFFFF9850 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEPE0      :1;                                       /* Internal Pull Enable for Port E Bit 0 */
    byte PTEPE1      :1;                                       /* Internal Pull Enable for Port E Bit 1 */
    byte PTEPE2      :1;                                       /* Internal Pull Enable for Port E Bit 2 */
    byte PTEPE3      :1;                                       /* Internal Pull Enable for Port E Bit 3 */
    byte PTEPE4      :1;                                       /* Internal Pull Enable for Port E Bit 4 */
    byte PTEPE5      :1;                                       /* Internal Pull Enable for Port E Bit 5 */
    byte PTEPE6      :1;                                       /* Internal Pull Enable for Port E Bit 6 */
    byte PTEPE7      :1;                                       /* Internal Pull Enable for Port E Bit 7 */
  } Bits;
} PTEPESTR;
extern volatile PTEPESTR _PTEPE @0xFFFF9850;
#define PTEPE                           _PTEPE.Byte
#define PTEPE_PTEPE0                    _PTEPE.Bits.PTEPE0
#define PTEPE_PTEPE1                    _PTEPE.Bits.PTEPE1
#define PTEPE_PTEPE2                    _PTEPE.Bits.PTEPE2
#define PTEPE_PTEPE3                    _PTEPE.Bits.PTEPE3
#define PTEPE_PTEPE4                    _PTEPE.Bits.PTEPE4
#define PTEPE_PTEPE5                    _PTEPE.Bits.PTEPE5
#define PTEPE_PTEPE6                    _PTEPE.Bits.PTEPE6
#define PTEPE_PTEPE7                    _PTEPE.Bits.PTEPE7

#define PTEPE_PTEPE0_MASK               1U
#define PTEPE_PTEPE1_MASK               2U
#define PTEPE_PTEPE2_MASK               4U
#define PTEPE_PTEPE3_MASK               8U
#define PTEPE_PTEPE4_MASK               16U
#define PTEPE_PTEPE5_MASK               32U
#define PTEPE_PTEPE6_MASK               64U
#define PTEPE_PTEPE7_MASK               128U


/*** PTESE - Port E Slew Rate Enable Register; 0xFFFF9851 ***/
typedef union {
  byte Byte;
  struct {
    byte PTESE0      :1;                                       /* Output Slew Rate Enable for Port E Bit 0 */
    byte PTESE1      :1;                                       /* Output Slew Rate Enable for Port E Bit 1 */
    byte PTESE2      :1;                                       /* Output Slew Rate Enable for Port E Bit 2 */
    byte PTESE3      :1;                                       /* Output Slew Rate Enable for Port E Bit 3 */
    byte PTESE4      :1;                                       /* Output Slew Rate Enable for Port E Bit 4 */
    byte PTESE5      :1;                                       /* Output Slew Rate Enable for Port E Bit 5 */
    byte PTESE6      :1;                                       /* Output Slew Rate Enable for Port E Bit 6 */
    byte PTESE7      :1;                                       /* Output Slew Rate Enable for Port E Bit 7 */
  } Bits;
} PTESESTR;
extern volatile PTESESTR _PTESE @0xFFFF9851;
#define PTESE                           _PTESE.Byte
#define PTESE_PTESE0                    _PTESE.Bits.PTESE0
#define PTESE_PTESE1                    _PTESE.Bits.PTESE1
#define PTESE_PTESE2                    _PTESE.Bits.PTESE2
#define PTESE_PTESE3                    _PTESE.Bits.PTESE3
#define PTESE_PTESE4                    _PTESE.Bits.PTESE4
#define PTESE_PTESE5                    _PTESE.Bits.PTESE5
#define PTESE_PTESE6                    _PTESE.Bits.PTESE6
#define PTESE_PTESE7                    _PTESE.Bits.PTESE7

#define PTESE_PTESE0_MASK               1U
#define PTESE_PTESE1_MASK               2U
#define PTESE_PTESE2_MASK               4U
#define PTESE_PTESE3_MASK               8U
#define PTESE_PTESE4_MASK               16U
#define PTESE_PTESE5_MASK               32U
#define PTESE_PTESE6_MASK               64U
#define PTESE_PTESE7_MASK               128U


/*** PTEDS - Port E Drive Strength Selection Register; 0xFFFF9852 ***/
typedef union {
  byte Byte;
  struct {
    byte PTEDS0      :1;                                       /* Output Drive Strength Selection for Port E Bit 0 */
    byte PTEDS1      :1;                                       /* Output Drive Strength Selection for Port E Bit 1 */
    byte PTEDS2      :1;                                       /* Output Drive Strength Selection for Port E Bit 2 */
    byte PTEDS3      :1;                                       /* Output Drive Strength Selection for Port E Bit 3 */
    byte PTEDS4      :1;                                       /* Output Drive Strength Selection for Port E Bit 4 */
    byte PTEDS5      :1;                                       /* Output Drive Strength Selection for Port E Bit 5 */
    byte PTEDS6      :1;                                       /* Output Drive Strength Selection for Port E Bit 6 */
    byte PTEDS7      :1;                                       /* Output Drive Strength Selection for Port E Bit 7 */
  } Bits;
} PTEDSSTR;
extern volatile PTEDSSTR _PTEDS @0xFFFF9852;
#define PTEDS                           _PTEDS.Byte
#define PTEDS_PTEDS0                    _PTEDS.Bits.PTEDS0
#define PTEDS_PTEDS1                    _PTEDS.Bits.PTEDS1
#define PTEDS_PTEDS2                    _PTEDS.Bits.PTEDS2
#define PTEDS_PTEDS3                    _PTEDS.Bits.PTEDS3
#define PTEDS_PTEDS4                    _PTEDS.Bits.PTEDS4
#define PTEDS_PTEDS5                    _PTEDS.Bits.PTEDS5
#define PTEDS_PTEDS6                    _PTEDS.Bits.PTEDS6
#define PTEDS_PTEDS7                    _PTEDS.Bits.PTEDS7

#define PTEDS_PTEDS0_MASK               1U
#define PTEDS_PTEDS1_MASK               2U
#define PTEDS_PTEDS2_MASK               4U
#define PTEDS_PTEDS3_MASK               8U
#define PTEDS_PTEDS4_MASK               16U
#define PTEDS_PTEDS5_MASK               32U
#define PTEDS_PTEDS6_MASK               64U
#define PTEDS_PTEDS7_MASK               128U


/*** PTFPE - Port F Pull Enable Register; 0xFFFF9854 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFPE0      :1;                                       /* Internal Pull Enable for Port F Bit 0 */
    byte PTFPE1      :1;                                       /* Internal Pull Enable for Port F Bit 1 */
    byte PTFPE2      :1;                                       /* Internal Pull Enable for Port F Bit 2 */
    byte PTFPE3      :1;                                       /* Internal Pull Enable for Port F Bit 3 */
    byte PTFPE4      :1;                                       /* Internal Pull Enable for Port F Bit 4 */
    byte PTFPE5      :1;                                       /* Internal Pull Enable for Port F Bit 5 */
    byte PTFPE6      :1;                                       /* Internal Pull Enable for Port F Bit 6 */
    byte PTFPE7      :1;                                       /* Internal Pull Enable for Port F Bit 7 */
  } Bits;
} PTFPESTR;
extern volatile PTFPESTR _PTFPE @0xFFFF9854;
#define PTFPE                           _PTFPE.Byte
#define PTFPE_PTFPE0                    _PTFPE.Bits.PTFPE0
#define PTFPE_PTFPE1                    _PTFPE.Bits.PTFPE1
#define PTFPE_PTFPE2                    _PTFPE.Bits.PTFPE2
#define PTFPE_PTFPE3                    _PTFPE.Bits.PTFPE3
#define PTFPE_PTFPE4                    _PTFPE.Bits.PTFPE4
#define PTFPE_PTFPE5                    _PTFPE.Bits.PTFPE5
#define PTFPE_PTFPE6                    _PTFPE.Bits.PTFPE6
#define PTFPE_PTFPE7                    _PTFPE.Bits.PTFPE7

#define PTFPE_PTFPE0_MASK               1U
#define PTFPE_PTFPE1_MASK               2U
#define PTFPE_PTFPE2_MASK               4U
#define PTFPE_PTFPE3_MASK               8U
#define PTFPE_PTFPE4_MASK               16U
#define PTFPE_PTFPE5_MASK               32U
#define PTFPE_PTFPE6_MASK               64U
#define PTFPE_PTFPE7_MASK               128U


/*** PTFSE - Port F Slew Rate Enable Register; 0xFFFF9855 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFSE0      :1;                                       /* Output Slew Rate Enable for Port F Bit 0 */
    byte PTFSE1      :1;                                       /* Output Slew Rate Enable for Port F Bit 1 */
    byte PTFSE2      :1;                                       /* Output Slew Rate Enable for Port F Bit 2 */
    byte PTFSE3      :1;                                       /* Output Slew Rate Enable for Port F Bit 3 */
    byte PTFSE4      :1;                                       /* Output Slew Rate Enable for Port F Bit 4 */
    byte PTFSE5      :1;                                       /* Output Slew Rate Enable for Port F Bit 5 */
    byte PTFSE6      :1;                                       /* Output Slew Rate Enable for Port F Bit 6 */
    byte PTFSE7      :1;                                       /* Output Slew Rate Enable for Port F Bit 7 */
  } Bits;
} PTFSESTR;
extern volatile PTFSESTR _PTFSE @0xFFFF9855;
#define PTFSE                           _PTFSE.Byte
#define PTFSE_PTFSE0                    _PTFSE.Bits.PTFSE0
#define PTFSE_PTFSE1                    _PTFSE.Bits.PTFSE1
#define PTFSE_PTFSE2                    _PTFSE.Bits.PTFSE2
#define PTFSE_PTFSE3                    _PTFSE.Bits.PTFSE3
#define PTFSE_PTFSE4                    _PTFSE.Bits.PTFSE4
#define PTFSE_PTFSE5                    _PTFSE.Bits.PTFSE5
#define PTFSE_PTFSE6                    _PTFSE.Bits.PTFSE6
#define PTFSE_PTFSE7                    _PTFSE.Bits.PTFSE7

#define PTFSE_PTFSE0_MASK               1U
#define PTFSE_PTFSE1_MASK               2U
#define PTFSE_PTFSE2_MASK               4U
#define PTFSE_PTFSE3_MASK               8U
#define PTFSE_PTFSE4_MASK               16U
#define PTFSE_PTFSE5_MASK               32U
#define PTFSE_PTFSE6_MASK               64U
#define PTFSE_PTFSE7_MASK               128U


/*** PTFDS - Port F Drive Strength Selection Register; 0xFFFF9856 ***/
typedef union {
  byte Byte;
  struct {
    byte PTFDS0      :1;                                       /* Output Drive Strength Selection for Port F Bit 0 */
    byte PTFDS1      :1;                                       /* Output Drive Strength Selection for Port F Bit 1 */
    byte PTFDS2      :1;                                       /* Output Drive Strength Selection for Port F Bit 2 */
    byte PTFDS3      :1;                                       /* Output Drive Strength Selection for Port F Bit 3 */
    byte PTFDS4      :1;                                       /* Output Drive Strength Selection for Port F Bit 4 */
    byte PTFDS5      :1;                                       /* Output Drive Strength Selection for Port F Bit 5 */
    byte PTFDS6      :1;                                       /* Output Drive Strength Selection for Port F Bit 6 */
    byte PTFDS7      :1;                                       /* Output Drive Strength Selection for Port F Bit 7 */
  } Bits;
} PTFDSSTR;
extern volatile PTFDSSTR _PTFDS @0xFFFF9856;
#define PTFDS                           _PTFDS.Byte
#define PTFDS_PTFDS0                    _PTFDS.Bits.PTFDS0
#define PTFDS_PTFDS1                    _PTFDS.Bits.PTFDS1
#define PTFDS_PTFDS2                    _PTFDS.Bits.PTFDS2
#define PTFDS_PTFDS3                    _PTFDS.Bits.PTFDS3
#define PTFDS_PTFDS4                    _PTFDS.Bits.PTFDS4
#define PTFDS_PTFDS5                    _PTFDS.Bits.PTFDS5
#define PTFDS_PTFDS6                    _PTFDS.Bits.PTFDS6
#define PTFDS_PTFDS7                    _PTFDS.Bits.PTFDS7

#define PTFDS_PTFDS0_MASK               1U
#define PTFDS_PTFDS1_MASK               2U
#define PTFDS_PTFDS2_MASK               4U
#define PTFDS_PTFDS3_MASK               8U
#define PTFDS_PTFDS4_MASK               16U
#define PTFDS_PTFDS5_MASK               32U
#define PTFDS_PTFDS6_MASK               64U
#define PTFDS_PTFDS7_MASK               128U


/*** PTGPE - Port G Pull Enable Register; 0xFFFF9858 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGPE0      :1;                                       /* Internal Pull Enable for Port G Bit 0 */
    byte PTGPE1      :1;                                       /* Internal Pull Enable for Port G Bit 1 */
    byte PTGPE2      :1;                                       /* Internal Pull Enable for Port G Bit 2 */
    byte PTGPE3      :1;                                       /* Internal Pull Enable for Port G Bit 3 */
    byte PTGPE4      :1;                                       /* Internal Pull Enable for Port G Bit 4 */
    byte PTGPE5      :1;                                       /* Internal Pull Enable for Port G Bit 5 */
    byte PTGPE6      :1;                                       /* Internal Pull Enable for Port G Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGPE :7;
    byte         :1;
  } MergedBits;
} PTGPESTR;
extern volatile PTGPESTR _PTGPE @0xFFFF9858;
#define PTGPE                           _PTGPE.Byte
#define PTGPE_PTGPE0                    _PTGPE.Bits.PTGPE0
#define PTGPE_PTGPE1                    _PTGPE.Bits.PTGPE1
#define PTGPE_PTGPE2                    _PTGPE.Bits.PTGPE2
#define PTGPE_PTGPE3                    _PTGPE.Bits.PTGPE3
#define PTGPE_PTGPE4                    _PTGPE.Bits.PTGPE4
#define PTGPE_PTGPE5                    _PTGPE.Bits.PTGPE5
#define PTGPE_PTGPE6                    _PTGPE.Bits.PTGPE6
#define PTGPE_PTGPE                     _PTGPE.MergedBits.grpPTGPE

#define PTGPE_PTGPE0_MASK               1U
#define PTGPE_PTGPE1_MASK               2U
#define PTGPE_PTGPE2_MASK               4U
#define PTGPE_PTGPE3_MASK               8U
#define PTGPE_PTGPE4_MASK               16U
#define PTGPE_PTGPE5_MASK               32U
#define PTGPE_PTGPE6_MASK               64U
#define PTGPE_PTGPE_MASK                127U
#define PTGPE_PTGPE_BITNUM              0U


/*** PTGSE - Port G Slew Rate Enable Register; 0xFFFF9859 ***/
typedef union {
  byte Byte;
  struct {
    byte PTGSE0      :1;                                       /* Output Slew Rate Enable for Port G Bit 0 */
    byte PTGSE1      :1;                                       /* Output Slew Rate Enable for Port G Bit 1 */
    byte PTGSE2      :1;                                       /* Output Slew Rate Enable for Port G Bit 2 */
    byte PTGSE3      :1;                                       /* Output Slew Rate Enable for Port G Bit 3 */
    byte PTGSE4      :1;                                       /* Output Slew Rate Enable for Port G Bit 4 */
    byte PTGSE5      :1;                                       /* Output Slew Rate Enable for Port G Bit 5 */
    byte PTGSE6      :1;                                       /* Output Slew Rate Enable for Port G Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGSE :7;
    byte         :1;
  } MergedBits;
} PTGSESTR;
extern volatile PTGSESTR _PTGSE @0xFFFF9859;
#define PTGSE                           _PTGSE.Byte
#define PTGSE_PTGSE0                    _PTGSE.Bits.PTGSE0
#define PTGSE_PTGSE1                    _PTGSE.Bits.PTGSE1
#define PTGSE_PTGSE2                    _PTGSE.Bits.PTGSE2
#define PTGSE_PTGSE3                    _PTGSE.Bits.PTGSE3
#define PTGSE_PTGSE4                    _PTGSE.Bits.PTGSE4
#define PTGSE_PTGSE5                    _PTGSE.Bits.PTGSE5
#define PTGSE_PTGSE6                    _PTGSE.Bits.PTGSE6
#define PTGSE_PTGSE                     _PTGSE.MergedBits.grpPTGSE

#define PTGSE_PTGSE0_MASK               1U
#define PTGSE_PTGSE1_MASK               2U
#define PTGSE_PTGSE2_MASK               4U
#define PTGSE_PTGSE3_MASK               8U
#define PTGSE_PTGSE4_MASK               16U
#define PTGSE_PTGSE5_MASK               32U
#define PTGSE_PTGSE6_MASK               64U
#define PTGSE_PTGSE_MASK                127U
#define PTGSE_PTGSE_BITNUM              0U


/*** PTGDS - Port G Drive Strength Selection Register; 0xFFFF985A ***/
typedef union {
  byte Byte;
  struct {
    byte PTGDS0      :1;                                       /* Output Drive Strength Selection for Port G Bit 0 */
    byte PTGDS1      :1;                                       /* Output Drive Strength Selection for Port G Bit 1 */
    byte PTGDS2      :1;                                       /* Output Drive Strength Selection for Port G Bit 2 */
    byte PTGDS3      :1;                                       /* Output Drive Strength Selection for Port G Bit 3 */
    byte PTGDS4      :1;                                       /* Output Drive Strength Selection for Port G Bit 4 */
    byte PTGDS5      :1;                                       /* Output Drive Strength Selection for Port G Bit 5 */
    byte PTGDS6      :1;                                       /* Output Drive Strength Selection for Port G Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTGDS :7;
    byte         :1;
  } MergedBits;
} PTGDSSTR;
extern volatile PTGDSSTR _PTGDS @0xFFFF985A;
#define PTGDS                           _PTGDS.Byte
#define PTGDS_PTGDS0                    _PTGDS.Bits.PTGDS0
#define PTGDS_PTGDS1                    _PTGDS.Bits.PTGDS1
#define PTGDS_PTGDS2                    _PTGDS.Bits.PTGDS2
#define PTGDS_PTGDS3                    _PTGDS.Bits.PTGDS3
#define PTGDS_PTGDS4                    _PTGDS.Bits.PTGDS4
#define PTGDS_PTGDS5                    _PTGDS.Bits.PTGDS5
#define PTGDS_PTGDS6                    _PTGDS.Bits.PTGDS6
#define PTGDS_PTGDS                     _PTGDS.MergedBits.grpPTGDS

#define PTGDS_PTGDS0_MASK               1U
#define PTGDS_PTGDS1_MASK               2U
#define PTGDS_PTGDS2_MASK               4U
#define PTGDS_PTGDS3_MASK               8U
#define PTGDS_PTGDS4_MASK               16U
#define PTGDS_PTGDS5_MASK               32U
#define PTGDS_PTGDS6_MASK               64U
#define PTGDS_PTGDS_MASK                127U
#define PTGDS_PTGDS_BITNUM              0U


/*** PTHPE - Port H Pull Enable Register; 0xFFFF985C ***/
typedef union {
  byte Byte;
  struct {
    byte PTHPE0      :1;                                       /* Internal Pull Enable for Port H Bit 0 */
    byte PTHPE1      :1;                                       /* Internal Pull Enable for Port H Bit 1 */
    byte PTHPE2      :1;                                       /* Internal Pull Enable for Port H Bit 2 */
    byte PTHPE3      :1;                                       /* Internal Pull Enable for Port H Bit 3 */
    byte PTHPE4      :1;                                       /* Internal Pull Enable for Port H Bit 4 */
    byte PTHPE5      :1;                                       /* Internal Pull Enable for Port H Bit 5 */
    byte PTHPE6      :1;                                       /* Internal Pull Enable for Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHPE :7;
    byte         :1;
  } MergedBits;
} PTHPESTR;
extern volatile PTHPESTR _PTHPE @0xFFFF985C;
#define PTHPE                           _PTHPE.Byte
#define PTHPE_PTHPE0                    _PTHPE.Bits.PTHPE0
#define PTHPE_PTHPE1                    _PTHPE.Bits.PTHPE1
#define PTHPE_PTHPE2                    _PTHPE.Bits.PTHPE2
#define PTHPE_PTHPE3                    _PTHPE.Bits.PTHPE3
#define PTHPE_PTHPE4                    _PTHPE.Bits.PTHPE4
#define PTHPE_PTHPE5                    _PTHPE.Bits.PTHPE5
#define PTHPE_PTHPE6                    _PTHPE.Bits.PTHPE6
#define PTHPE_PTHPE                     _PTHPE.MergedBits.grpPTHPE

#define PTHPE_PTHPE0_MASK               1U
#define PTHPE_PTHPE1_MASK               2U
#define PTHPE_PTHPE2_MASK               4U
#define PTHPE_PTHPE3_MASK               8U
#define PTHPE_PTHPE4_MASK               16U
#define PTHPE_PTHPE5_MASK               32U
#define PTHPE_PTHPE6_MASK               64U
#define PTHPE_PTHPE_MASK                127U
#define PTHPE_PTHPE_BITNUM              0U


/*** PTHSE - Port H Slew Rate Enable Register; 0xFFFF985D ***/
typedef union {
  byte Byte;
  struct {
    byte PTHSE0      :1;                                       /* Output Slew Rate Enable for Port H Bit 0 */
    byte PTHSE1      :1;                                       /* Output Slew Rate Enable for Port H Bit 1 */
    byte PTHSE2      :1;                                       /* Output Slew Rate Enable for Port H Bit 2 */
    byte PTHSE3      :1;                                       /* Output Slew Rate Enable for Port H Bit 3 */
    byte PTHSE4      :1;                                       /* Output Slew Rate Enable for Port H Bit 4 */
    byte PTHSE5      :1;                                       /* Output Slew Rate Enable for Port H Bit 5 */
    byte PTHSE6      :1;                                       /* Output Slew Rate Enable for Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHSE :7;
    byte         :1;
  } MergedBits;
} PTHSESTR;
extern volatile PTHSESTR _PTHSE @0xFFFF985D;
#define PTHSE                           _PTHSE.Byte
#define PTHSE_PTHSE0                    _PTHSE.Bits.PTHSE0
#define PTHSE_PTHSE1                    _PTHSE.Bits.PTHSE1
#define PTHSE_PTHSE2                    _PTHSE.Bits.PTHSE2
#define PTHSE_PTHSE3                    _PTHSE.Bits.PTHSE3
#define PTHSE_PTHSE4                    _PTHSE.Bits.PTHSE4
#define PTHSE_PTHSE5                    _PTHSE.Bits.PTHSE5
#define PTHSE_PTHSE6                    _PTHSE.Bits.PTHSE6
#define PTHSE_PTHSE                     _PTHSE.MergedBits.grpPTHSE

#define PTHSE_PTHSE0_MASK               1U
#define PTHSE_PTHSE1_MASK               2U
#define PTHSE_PTHSE2_MASK               4U
#define PTHSE_PTHSE3_MASK               8U
#define PTHSE_PTHSE4_MASK               16U
#define PTHSE_PTHSE5_MASK               32U
#define PTHSE_PTHSE6_MASK               64U
#define PTHSE_PTHSE_MASK                127U
#define PTHSE_PTHSE_BITNUM              0U


/*** PTHDS - Port H Drive Strength Selection Register; 0xFFFF985E ***/
typedef union {
  byte Byte;
  struct {
    byte PTHDS0      :1;                                       /* Output Drive Strength Selection for Port H Bit 0 */
    byte PTHDS1      :1;                                       /* Output Drive Strength Selection for Port H Bit 1 */
    byte PTHDS2      :1;                                       /* Output Drive Strength Selection for Port H Bit 2 */
    byte PTHDS3      :1;                                       /* Output Drive Strength Selection for Port H Bit 3 */
    byte PTHDS4      :1;                                       /* Output Drive Strength Selection for Port H Bit 4 */
    byte PTHDS5      :1;                                       /* Output Drive Strength Selection for Port H Bit 5 */
    byte PTHDS6      :1;                                       /* Output Drive Strength Selection for Port H Bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpPTHDS :7;
    byte         :1;
  } MergedBits;
} PTHDSSTR;
extern volatile PTHDSSTR _PTHDS @0xFFFF985E;
#define PTHDS                           _PTHDS.Byte
#define PTHDS_PTHDS0                    _PTHDS.Bits.PTHDS0
#define PTHDS_PTHDS1                    _PTHDS.Bits.PTHDS1
#define PTHDS_PTHDS2                    _PTHDS.Bits.PTHDS2
#define PTHDS_PTHDS3                    _PTHDS.Bits.PTHDS3
#define PTHDS_PTHDS4                    _PTHDS.Bits.PTHDS4
#define PTHDS_PTHDS5                    _PTHDS.Bits.PTHDS5
#define PTHDS_PTHDS6                    _PTHDS.Bits.PTHDS6
#define PTHDS_PTHDS                     _PTHDS.MergedBits.grpPTHDS

#define PTHDS_PTHDS0_MASK               1U
#define PTHDS_PTHDS1_MASK               2U
#define PTHDS_PTHDS2_MASK               4U
#define PTHDS_PTHDS3_MASK               8U
#define PTHDS_PTHDS4_MASK               16U
#define PTHDS_PTHDS5_MASK               32U
#define PTHDS_PTHDS6_MASK               64U
#define PTHDS_PTHDS_MASK                127U
#define PTHDS_PTHDS_BITNUM              0U


/*** PTJPE - Port J Pull Enable Register; 0xFFFF9860 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJPE0      :1;                                       /* Internal Pull Enable for Port J Bit 0 */
    byte PTJPE1      :1;                                       /* Internal Pull Enable for Port J Bit 1 */
    byte PTJPE2      :1;                                       /* Internal Pull Enable for Port J Bit 2 */
    byte PTJPE3      :1;                                       /* Internal Pull Enable for Port J Bit 3 */
    byte PTJPE4      :1;                                       /* Internal Pull Enable for Port J Bit 4 */
    byte PTJPE5      :1;                                       /* Internal Pull Enable for Port J Bit 5 */
    byte PTJPE6      :1;                                       /* Internal Pull Enable for Port J Bit 6 */
    byte PTJPE7      :1;                                       /* Internal Pull Enable for Port J Bit 7 */
  } Bits;
} PTJPESTR;
extern volatile PTJPESTR _PTJPE @0xFFFF9860;
#define PTJPE                           _PTJPE.Byte
#define PTJPE_PTJPE0                    _PTJPE.Bits.PTJPE0
#define PTJPE_PTJPE1                    _PTJPE.Bits.PTJPE1
#define PTJPE_PTJPE2                    _PTJPE.Bits.PTJPE2
#define PTJPE_PTJPE3                    _PTJPE.Bits.PTJPE3
#define PTJPE_PTJPE4                    _PTJPE.Bits.PTJPE4
#define PTJPE_PTJPE5                    _PTJPE.Bits.PTJPE5
#define PTJPE_PTJPE6                    _PTJPE.Bits.PTJPE6
#define PTJPE_PTJPE7                    _PTJPE.Bits.PTJPE7

#define PTJPE_PTJPE0_MASK               1U
#define PTJPE_PTJPE1_MASK               2U
#define PTJPE_PTJPE2_MASK               4U
#define PTJPE_PTJPE3_MASK               8U
#define PTJPE_PTJPE4_MASK               16U
#define PTJPE_PTJPE5_MASK               32U
#define PTJPE_PTJPE6_MASK               64U
#define PTJPE_PTJPE7_MASK               128U


/*** PTJSE - Port J Slew Rate Enable Register; 0xFFFF9861 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJSE0      :1;                                       /* Output Slew Rate Enable for Port J Bit 0 */
    byte PTJSE1      :1;                                       /* Output Slew Rate Enable for Port J Bit 1 */
    byte PTJSE2      :1;                                       /* Output Slew Rate Enable for Port J Bit 2 */
    byte PTJSE3      :1;                                       /* Output Slew Rate Enable for Port J Bit 3 */
    byte PTJSE4      :1;                                       /* Output Slew Rate Enable for Port J Bit 4 */
    byte PTJSE5      :1;                                       /* Output Slew Rate Enable for Port J Bit 5 */
    byte PTJSE6      :1;                                       /* Output Slew Rate Enable for Port J Bit 6 */
    byte PTJSE7      :1;                                       /* Output Slew Rate Enable for Port J Bit 7 */
  } Bits;
} PTJSESTR;
extern volatile PTJSESTR _PTJSE @0xFFFF9861;
#define PTJSE                           _PTJSE.Byte
#define PTJSE_PTJSE0                    _PTJSE.Bits.PTJSE0
#define PTJSE_PTJSE1                    _PTJSE.Bits.PTJSE1
#define PTJSE_PTJSE2                    _PTJSE.Bits.PTJSE2
#define PTJSE_PTJSE3                    _PTJSE.Bits.PTJSE3
#define PTJSE_PTJSE4                    _PTJSE.Bits.PTJSE4
#define PTJSE_PTJSE5                    _PTJSE.Bits.PTJSE5
#define PTJSE_PTJSE6                    _PTJSE.Bits.PTJSE6
#define PTJSE_PTJSE7                    _PTJSE.Bits.PTJSE7

#define PTJSE_PTJSE0_MASK               1U
#define PTJSE_PTJSE1_MASK               2U
#define PTJSE_PTJSE2_MASK               4U
#define PTJSE_PTJSE3_MASK               8U
#define PTJSE_PTJSE4_MASK               16U
#define PTJSE_PTJSE5_MASK               32U
#define PTJSE_PTJSE6_MASK               64U
#define PTJSE_PTJSE7_MASK               128U


/*** PTJDS - Port J Drive Strength Selection Register; 0xFFFF9862 ***/
typedef union {
  byte Byte;
  struct {
    byte PTJDS0      :1;                                       /* Output Drive Strength Selection for Port J Bit 0 */
    byte PTJDS1      :1;                                       /* Output Drive Strength Selection for Port J Bit 1 */
    byte PTJDS2      :1;                                       /* Output Drive Strength Selection for Port J Bit 2 */
    byte PTJDS3      :1;                                       /* Output Drive Strength Selection for Port J Bit 3 */
    byte PTJDS4      :1;                                       /* Output Drive Strength Selection for Port J Bit 4 */
    byte PTJDS5      :1;                                       /* Output Drive Strength Selection for Port J Bit 5 */
    byte PTJDS6      :1;                                       /* Output Drive Strength Selection for Port J Bit 6 */
    byte PTJDS7      :1;                                       /* Output Drive Strength Selection for Port J Bit 7 */
  } Bits;
} PTJDSSTR;
extern volatile PTJDSSTR _PTJDS @0xFFFF9862;
#define PTJDS                           _PTJDS.Byte
#define PTJDS_PTJDS0                    _PTJDS.Bits.PTJDS0
#define PTJDS_PTJDS1                    _PTJDS.Bits.PTJDS1
#define PTJDS_PTJDS2                    _PTJDS.Bits.PTJDS2
#define PTJDS_PTJDS3                    _PTJDS.Bits.PTJDS3
#define PTJDS_PTJDS4                    _PTJDS.Bits.PTJDS4
#define PTJDS_PTJDS5                    _PTJDS.Bits.PTJDS5
#define PTJDS_PTJDS6                    _PTJDS.Bits.PTJDS6
#define PTJDS_PTJDS7                    _PTJDS.Bits.PTJDS7

#define PTJDS_PTJDS0_MASK               1U
#define PTJDS_PTJDS1_MASK               2U
#define PTJDS_PTJDS2_MASK               4U
#define PTJDS_PTJDS3_MASK               8U
#define PTJDS_PTJDS4_MASK               16U
#define PTJDS_PTJDS5_MASK               32U
#define PTJDS_PTJDS6_MASK               64U
#define PTJDS_PTJDS7_MASK               128U


/*** SPI2C1 - SPI2 Control Register 1; 0xFFFF9868 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPI2C1STR;
extern volatile SPI2C1STR _SPI2C1 @0xFFFF9868;
#define SPI2C1                          _SPI2C1.Byte
#define SPI2C1_LSBFE                    _SPI2C1.Bits.LSBFE
#define SPI2C1_SSOE                     _SPI2C1.Bits.SSOE
#define SPI2C1_CPHA                     _SPI2C1.Bits.CPHA
#define SPI2C1_CPOL                     _SPI2C1.Bits.CPOL
#define SPI2C1_MSTR                     _SPI2C1.Bits.MSTR
#define SPI2C1_SPTIE                    _SPI2C1.Bits.SPTIE
#define SPI2C1_SPE                      _SPI2C1.Bits.SPE
#define SPI2C1_SPIE                     _SPI2C1.Bits.SPIE

#define SPI2C1_LSBFE_MASK               1U
#define SPI2C1_SSOE_MASK                2U
#define SPI2C1_CPHA_MASK                4U
#define SPI2C1_CPOL_MASK                8U
#define SPI2C1_MSTR_MASK                16U
#define SPI2C1_SPTIE_MASK               32U
#define SPI2C1_SPE_MASK                 64U
#define SPI2C1_SPIE_MASK                128U


/*** SPI2C2 - SPI2 Control Register 2; 0xFFFF9869 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte SPIMODE     :1;                                       /* SPI 8- or 16-bit Mode Select */
    byte SPMIE       :1;                                       /* SPI Match Interrupt Enable */
  } Bits;
} SPI2C2STR;
extern volatile SPI2C2STR _SPI2C2 @0xFFFF9869;
#define SPI2C2                          _SPI2C2.Byte
#define SPI2C2_SPC0                     _SPI2C2.Bits.SPC0
#define SPI2C2_SPISWAI                  _SPI2C2.Bits.SPISWAI
#define SPI2C2_BIDIROE                  _SPI2C2.Bits.BIDIROE
#define SPI2C2_MODFEN                   _SPI2C2.Bits.MODFEN
#define SPI2C2_SPIMODE                  _SPI2C2.Bits.SPIMODE
#define SPI2C2_SPMIE                    _SPI2C2.Bits.SPMIE

#define SPI2C2_SPC0_MASK                1U
#define SPI2C2_SPISWAI_MASK             2U
#define SPI2C2_BIDIROE_MASK             8U
#define SPI2C2_MODFEN_MASK              16U
#define SPI2C2_SPIMODE_MASK             64U
#define SPI2C2_SPMIE_MASK               128U


/*** SPI2BR - SPI2 Baud Rate Register; 0xFFFF986A ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI2BRSTR;
extern volatile SPI2BRSTR _SPI2BR @0xFFFF986A;
#define SPI2BR                          _SPI2BR.Byte
#define SPI2BR_SPR0                     _SPI2BR.Bits.SPR0
#define SPI2BR_SPR1                     _SPI2BR.Bits.SPR1
#define SPI2BR_SPR2                     _SPI2BR.Bits.SPR2
#define SPI2BR_SPPR0                    _SPI2BR.Bits.SPPR0
#define SPI2BR_SPPR1                    _SPI2BR.Bits.SPPR1
#define SPI2BR_SPPR2                    _SPI2BR.Bits.SPPR2
#define SPI2BR_SPR                      _SPI2BR.MergedBits.grpSPR
#define SPI2BR_SPPR                     _SPI2BR.MergedBits.grpSPPR

#define SPI2BR_SPR0_MASK                1U
#define SPI2BR_SPR1_MASK                2U
#define SPI2BR_SPR2_MASK                4U
#define SPI2BR_SPPR0_MASK               16U
#define SPI2BR_SPPR1_MASK               32U
#define SPI2BR_SPPR2_MASK               64U
#define SPI2BR_SPR_MASK                 7U
#define SPI2BR_SPR_BITNUM               0U
#define SPI2BR_SPPR_MASK                112U
#define SPI2BR_SPPR_BITNUM              4U


/*** SPI2S - SPI2 Status Register; 0xFFFF986B ***/
typedef union {
  byte Byte;
  struct {
    byte RFIFOEF     :1;                                       /* SPI Read FIFO Empty Flag */
    byte TXFULLF     :1;                                       /* SPI Transmit FIFO Full Flag */
    byte TNEAREF     :1;                                       /* SPI Transmit FIFO Nearly Empty Flag */
    byte RNFULLF     :1;                                       /* SPI Receive FIFO Nearly Full Flag */
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte SPMF        :1;                                       /* SPI Match Flag */
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPI2SSTR;
extern volatile SPI2SSTR _SPI2S @0xFFFF986B;
#define SPI2S                           _SPI2S.Byte
#define SPI2S_RFIFOEF                   _SPI2S.Bits.RFIFOEF
#define SPI2S_TXFULLF                   _SPI2S.Bits.TXFULLF
#define SPI2S_TNEAREF                   _SPI2S.Bits.TNEAREF
#define SPI2S_RNFULLF                   _SPI2S.Bits.RNFULLF
#define SPI2S_MODF                      _SPI2S.Bits.MODF
#define SPI2S_SPTEF                     _SPI2S.Bits.SPTEF
#define SPI2S_SPMF                      _SPI2S.Bits.SPMF
#define SPI2S_SPRF                      _SPI2S.Bits.SPRF

#define SPI2S_RFIFOEF_MASK              1U
#define SPI2S_TXFULLF_MASK              2U
#define SPI2S_TNEAREF_MASK              4U
#define SPI2S_RNFULLF_MASK              8U
#define SPI2S_MODF_MASK                 16U
#define SPI2S_SPTEF_MASK                32U
#define SPI2S_SPMF_MASK                 64U
#define SPI2S_SPRF_MASK                 128U


/*** SPI2D16 - SPI2 Data Register; 0xFFFF986C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI2DH - SPI2 Data Register High; 0xFFFF986C ***/
    union {
      byte Byte;
    } SPI2DHSTR;
    #define SPI2DH                      _SPI2D16.Overlap_STR.SPI2DHSTR.Byte
    

    /*** SPI2DL - SPI2 Data Register Low; 0xFFFF986D ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SPI2DL - SPI2 Data Register Low; Several registers at the same address ***/
        #define SPI2DL                  _SPI2D16.Overlap_STR.SPI2DLSTR.Byte
        
        /*** SPI2D - SPI2 Data Register Low; Several registers at the same address ***/
        union {
          struct {
            byte Bit0        :1;                                       /* SPI Data Bit 0 */
            byte Bit1        :1;                                       /* SPI Data Bit 1 */
            byte Bit2        :1;                                       /* SPI Data Bit 2 */
            byte Bit3        :1;                                       /* SPI Data Bit 3 */
            byte Bit4        :1;                                       /* SPI Data Bit 4 */
            byte Bit5        :1;                                       /* SPI Data Bit 5 */
            byte Bit6        :1;                                       /* SPI Data Bit 6 */
            byte Bit7        :1;                                       /* SPI Data Bit 7 */
          } Bits;
        } SPI2DSTR;
        #define SPI2D                   _SPI2D16.Overlap_STR.SPI2DLSTR.Byte
        #define SPI2D_Bit0              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit0
        #define SPI2D_Bit1              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit1
        #define SPI2D_Bit2              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit2
        #define SPI2D_Bit3              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit3
        #define SPI2D_Bit4              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit4
        #define SPI2D_Bit5              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit5
        #define SPI2D_Bit6              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit6
        #define SPI2D_Bit7              _SPI2D16.Overlap_STR.SPI2DLSTR.SameAddr_STR.SPI2DSTR.Bits.Bit7
        
        #define SPI2D_Bit0_MASK         1U
        #define SPI2D_Bit1_MASK         2U
        #define SPI2D_Bit2_MASK         4U
        #define SPI2D_Bit3_MASK         8U
        #define SPI2D_Bit4_MASK         16U
        #define SPI2D_Bit5_MASK         32U
        #define SPI2D_Bit6_MASK         64U
        #define SPI2D_Bit7_MASK         128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SPI2DLSTR;
    
  } Overlap_STR;

} SPI2D16STR;
extern volatile SPI2D16STR _SPI2D16 @0xFFFF986C;
#define SPI2D16                         _SPI2D16.Word


/*** SPI2M - SPI2 Match Register; 0xFFFF986E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI2MH - SPI2 Match Register High; 0xFFFF986E ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* SPI Match Value Bit 8 */
        byte Bit9        :1;                                       /* SPI Match Value Bit 9 */
        byte Bit10       :1;                                       /* SPI Match Value Bit 10 */
        byte Bit11       :1;                                       /* SPI Match Value Bit 11 */
        byte Bit12       :1;                                       /* SPI Match Value Bit 12 */
        byte Bit13       :1;                                       /* SPI Match Value Bit 13 */
        byte Bit14       :1;                                       /* SPI Match Value Bit 14 */
        byte Bit15       :1;                                       /* SPI Match Value Bit 15 */
      } Bits;
    } SPI2MHSTR;
    #define SPI2MH                      _SPI2M.Overlap_STR.SPI2MHSTR.Byte
    #define SPI2MH_Bit8                 _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit8
    #define SPI2MH_Bit9                 _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit9
    #define SPI2MH_Bit10                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit10
    #define SPI2MH_Bit11                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit11
    #define SPI2MH_Bit12                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit12
    #define SPI2MH_Bit13                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit13
    #define SPI2MH_Bit14                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit14
    #define SPI2MH_Bit15                _SPI2M.Overlap_STR.SPI2MHSTR.Bits.Bit15
    
    #define SPI2MH_Bit8_MASK            1U
    #define SPI2MH_Bit9_MASK            2U
    #define SPI2MH_Bit10_MASK           4U
    #define SPI2MH_Bit11_MASK           8U
    #define SPI2MH_Bit12_MASK           16U
    #define SPI2MH_Bit13_MASK           32U
    #define SPI2MH_Bit14_MASK           64U
    #define SPI2MH_Bit15_MASK           128U
    

    /*** SPI2ML - SPI2 Match Register Low; 0xFFFF986F ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* SPI Match Value Bit 0 */
        byte Bit1        :1;                                       /* SPI Match Value Bit 1 */
        byte Bit2        :1;                                       /* SPI Match Value Bit 2 */
        byte Bit3        :1;                                       /* SPI Match Value Bit 3 */
        byte Bit4        :1;                                       /* SPI Match Value Bit 4 */
        byte Bit5        :1;                                       /* SPI Match Value Bit 5 */
        byte Bit6        :1;                                       /* SPI Match Value Bit 6 */
        byte Bit7        :1;                                       /* SPI Match Value Bit 7 */
      } Bits;
    } SPI2MLSTR;
    #define SPI2ML                      _SPI2M.Overlap_STR.SPI2MLSTR.Byte
    #define SPI2ML_Bit0                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit0
    #define SPI2ML_Bit1                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit1
    #define SPI2ML_Bit2                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit2
    #define SPI2ML_Bit3                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit3
    #define SPI2ML_Bit4                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit4
    #define SPI2ML_Bit5                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit5
    #define SPI2ML_Bit6                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit6
    #define SPI2ML_Bit7                 _SPI2M.Overlap_STR.SPI2MLSTR.Bits.Bit7
    
    #define SPI2ML_Bit0_MASK            1U
    #define SPI2ML_Bit1_MASK            2U
    #define SPI2ML_Bit2_MASK            4U
    #define SPI2ML_Bit3_MASK            8U
    #define SPI2ML_Bit4_MASK            16U
    #define SPI2ML_Bit5_MASK            32U
    #define SPI2ML_Bit6_MASK            64U
    #define SPI2ML_Bit7_MASK            128U
    
  } Overlap_STR;

  struct {
    word Bit0        :1;                                       /* SPI Match Value Bit 0 */
    word Bit1        :1;                                       /* SPI Match Value Bit 1 */
    word Bit2        :1;                                       /* SPI Match Value Bit 2 */
    word Bit3        :1;                                       /* SPI Match Value Bit 3 */
    word Bit4        :1;                                       /* SPI Match Value Bit 4 */
    word Bit5        :1;                                       /* SPI Match Value Bit 5 */
    word Bit6        :1;                                       /* SPI Match Value Bit 6 */
    word Bit7        :1;                                       /* SPI Match Value Bit 7 */
    word Bit8        :1;                                       /* SPI Match Value Bit 8 */
    word Bit9        :1;                                       /* SPI Match Value Bit 9 */
    word Bit10       :1;                                       /* SPI Match Value Bit 10 */
    word Bit11       :1;                                       /* SPI Match Value Bit 11 */
    word Bit12       :1;                                       /* SPI Match Value Bit 12 */
    word Bit13       :1;                                       /* SPI Match Value Bit 13 */
    word Bit14       :1;                                       /* SPI Match Value Bit 14 */
    word Bit15       :1;                                       /* SPI Match Value Bit 15 */
  } Bits;
} SPI2MSTR;
extern volatile SPI2MSTR _SPI2M @0xFFFF986E;
#define SPI2M                           _SPI2M.Word
#define SPI2M_Bit0                      _SPI2M.Bits.Bit0
#define SPI2M_Bit1                      _SPI2M.Bits.Bit1
#define SPI2M_Bit2                      _SPI2M.Bits.Bit2
#define SPI2M_Bit3                      _SPI2M.Bits.Bit3
#define SPI2M_Bit4                      _SPI2M.Bits.Bit4
#define SPI2M_Bit5                      _SPI2M.Bits.Bit5
#define SPI2M_Bit6                      _SPI2M.Bits.Bit6
#define SPI2M_Bit7                      _SPI2M.Bits.Bit7
#define SPI2M_Bit8                      _SPI2M.Bits.Bit8
#define SPI2M_Bit9                      _SPI2M.Bits.Bit9
#define SPI2M_Bit10                     _SPI2M.Bits.Bit10
#define SPI2M_Bit11                     _SPI2M.Bits.Bit11
#define SPI2M_Bit12                     _SPI2M.Bits.Bit12
#define SPI2M_Bit13                     _SPI2M.Bits.Bit13
#define SPI2M_Bit14                     _SPI2M.Bits.Bit14
#define SPI2M_Bit15                     _SPI2M.Bits.Bit15

#define SPI2M_Bit0_MASK                 1U
#define SPI2M_Bit1_MASK                 2U
#define SPI2M_Bit2_MASK                 4U
#define SPI2M_Bit3_MASK                 8U
#define SPI2M_Bit4_MASK                 16U
#define SPI2M_Bit5_MASK                 32U
#define SPI2M_Bit6_MASK                 64U
#define SPI2M_Bit7_MASK                 128U
#define SPI2M_Bit8_MASK                 256U
#define SPI2M_Bit9_MASK                 512U
#define SPI2M_Bit10_MASK                1024U
#define SPI2M_Bit11_MASK                2048U
#define SPI2M_Bit12_MASK                4096U
#define SPI2M_Bit13_MASK                8192U
#define SPI2M_Bit14_MASK                16384U
#define SPI2M_Bit15_MASK                32768U


/*** SPI2C3 - SPI2 Control Register 3; 0xFFFF9870 ***/
typedef union {
  byte Byte;
  struct {
    byte FIFOMODE    :1;                                       /* SPI FIFO Mode Enable */
    byte RNFULLIEN   :1;                                       /* Receive FIFO Nearly Full Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPIE in the SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0 */
    byte TNEARIEN    :1;                                       /* Transmit FIFO Nearly Empty Interrupt Enable. This is an additional interrupt on the SPI and will only interrupt the CPU if SPTIE in the <br/>SPIxC1 register is also set. This bit is ignored and has no function if FIFOMODE=0 */
    byte INTCLR      :1;                                       /* Interrupt Clearing Mechanism Select - This bit selects the mechanism by which SPRF, SPTEF, TNEAREF, RNFULLF interrupts gets cleared */
    byte RNFULLF_MARK :1;                                      /* Receive FIFO Nearly Full Water Mark - This bit selects the mark for which RNFULLF flag is asserted */
    byte TNEAREF_MARK :1;                                      /* Transmit FIFO Nearly Empty Water Mark - This bit selects the mark after which TNEAREF flag is asserted */
    byte             :1; 
    byte             :1; 
  } Bits;
} SPI2C3STR;
extern volatile SPI2C3STR _SPI2C3 @0xFFFF9870;
#define SPI2C3                          _SPI2C3.Byte
#define SPI2C3_FIFOMODE                 _SPI2C3.Bits.FIFOMODE
#define SPI2C3_RNFULLIEN                _SPI2C3.Bits.RNFULLIEN
#define SPI2C3_TNEARIEN                 _SPI2C3.Bits.TNEARIEN
#define SPI2C3_INTCLR                   _SPI2C3.Bits.INTCLR
#define SPI2C3_RNFULLF_MARK             _SPI2C3.Bits.RNFULLF_MARK
#define SPI2C3_TNEAREF_MARK             _SPI2C3.Bits.TNEAREF_MARK

#define SPI2C3_FIFOMODE_MASK            1U
#define SPI2C3_RNFULLIEN_MASK           2U
#define SPI2C3_TNEARIEN_MASK            4U
#define SPI2C3_INTCLR_MASK              8U
#define SPI2C3_RNFULLF_MARK_MASK        16U
#define SPI2C3_TNEAREF_MARK_MASK        32U


/*** SPI2CI - SPI2 Clear Interrupt Register; 0xFFFF9871 ***/
typedef union {
  byte Byte;
  struct {
    byte SPRFCI      :1;                                       /* Receive FIFO Full Flag Clear Interrupt Bit - Write of 1 clears the TNEAREF interrupt provided SPIxC3[3] is set */
    byte SPTEFCI     :1;                                       /* Transmit FIFO Empty Flag Clear Interrupt Bit - Write of 1 clears the SPTEF interrupt provided SPIxC3[3] SPTEFCI is set */
    byte RNFULLFCI   :1;                                       /* Receive FIFO Nearly Full Flag Clear Interrupt - Write of 1 clears the RNFULLF interrupt provided SPIxC3[3] is set */
    byte TNEAREFCI   :1;                                       /* Transmit FIFO Nearly Empty Flag Clear Interrupt Bit - Write of 1 clears the TNEAREF interrupt provided SPIxC3[3] is set */
    byte RXFOF       :1;                                       /* RX FIFO Overflow Flag - This Flag indicates that RX FIFO overflow condition has occured */
    byte TXFOF       :1;                                       /* TX FIFO Overflow Flag - This Flag indicates that TX FIFO overflow condition has occured */
    byte RXFERR      :1;                                       /* Receive FIFO Error Flag - This flag indicates that RX FIFO error occured because entries in fifo goes above 8 */
    byte TXFERR      :1;                                       /* Transmit FIFO ErrorFlag - This flag indicates that TX FIFO error occured because entries in fifo goes above 8 */
  } Bits;
} SPI2CISTR;
extern volatile SPI2CISTR _SPI2CI @0xFFFF9871;
#define SPI2CI                          _SPI2CI.Byte
#define SPI2CI_SPRFCI                   _SPI2CI.Bits.SPRFCI
#define SPI2CI_SPTEFCI                  _SPI2CI.Bits.SPTEFCI
#define SPI2CI_RNFULLFCI                _SPI2CI.Bits.RNFULLFCI
#define SPI2CI_TNEAREFCI                _SPI2CI.Bits.TNEAREFCI
#define SPI2CI_RXFOF                    _SPI2CI.Bits.RXFOF
#define SPI2CI_TXFOF                    _SPI2CI.Bits.TXFOF
#define SPI2CI_RXFERR                   _SPI2CI.Bits.RXFERR
#define SPI2CI_TXFERR                   _SPI2CI.Bits.TXFERR

#define SPI2CI_SPRFCI_MASK              1U
#define SPI2CI_SPTEFCI_MASK             2U
#define SPI2CI_RNFULLFCI_MASK           4U
#define SPI2CI_TNEAREFCI_MASK           8U
#define SPI2CI_RXFOF_MASK               16U
#define SPI2CI_TXFOF_MASK               32U
#define SPI2CI_RXFERR_MASK              64U
#define SPI2CI_TXFERR_MASK              128U


/*** CANCTL0 - MSCAN Control 0 Register; 0xFFFF9880 ***/
typedef union {
  byte Byte;
  struct {
    byte INITRQ      :1;                                       /* Initialization Mode Request */
    byte SLPRQ       :1;                                       /* Sleep Mode Request */
    byte WUPE        :1;                                       /* Wake-Up Enable */
    byte TIME        :1;                                       /* Timer Enable */
    byte SYNCH       :1;                                       /* Synchronized Status */
    byte CSWAI       :1;                                       /* CAN Stops in Wait Mode */
    byte RXACT       :1;                                       /* Receiver Active Status */
    byte RXFRM       :1;                                       /* Received Frame Flag */
  } Bits;
} CANCTL0STR;
extern volatile CANCTL0STR _CANCTL0 @0xFFFF9880;
#define CANCTL0                         _CANCTL0.Byte
#define CANCTL0_INITRQ                  _CANCTL0.Bits.INITRQ
#define CANCTL0_SLPRQ                   _CANCTL0.Bits.SLPRQ
#define CANCTL0_WUPE                    _CANCTL0.Bits.WUPE
#define CANCTL0_TIME                    _CANCTL0.Bits.TIME
#define CANCTL0_SYNCH                   _CANCTL0.Bits.SYNCH
#define CANCTL0_CSWAI                   _CANCTL0.Bits.CSWAI
#define CANCTL0_RXACT                   _CANCTL0.Bits.RXACT
#define CANCTL0_RXFRM                   _CANCTL0.Bits.RXFRM
/* CANCTL_ARR: Access 2 CANCTLx registers in an array */
#define CANCTL_ARR                      ((volatile byte *) &CANCTL0)

#define CANCTL0_INITRQ_MASK             1U
#define CANCTL0_SLPRQ_MASK              2U
#define CANCTL0_WUPE_MASK               4U
#define CANCTL0_TIME_MASK               8U
#define CANCTL0_SYNCH_MASK              16U
#define CANCTL0_CSWAI_MASK              32U
#define CANCTL0_RXACT_MASK              64U
#define CANCTL0_RXFRM_MASK              128U


/*** CANCTL1 - MSCAN Control 1 Register; 0xFFFF9881 ***/
typedef union {
  byte Byte;
  struct {
    byte INITAK      :1;                                       /* Initialization Mode Acknowledge */
    byte SLPAK       :1;                                       /* Sleep Mode Acknowledge */
    byte WUPM        :1;                                       /* Wake-Up Mode */
    byte BORM        :1;                                       /* Bus-Off Recovery Mode */
    byte LISTEN      :1;                                       /* Listen Only Mode */
    byte LOOPB       :1;                                       /* Loop Back Self Test Mode */
    byte CLKSRC      :1;                                       /* MSCAN Clock Source */
    byte CANE        :1;                                       /* MSCAN Enable */
  } Bits;
} CANCTL1STR;
extern volatile CANCTL1STR _CANCTL1 @0xFFFF9881;
#define CANCTL1                         _CANCTL1.Byte
#define CANCTL1_INITAK                  _CANCTL1.Bits.INITAK
#define CANCTL1_SLPAK                   _CANCTL1.Bits.SLPAK
#define CANCTL1_WUPM                    _CANCTL1.Bits.WUPM
#define CANCTL1_BORM                    _CANCTL1.Bits.BORM
#define CANCTL1_LISTEN                  _CANCTL1.Bits.LISTEN
#define CANCTL1_LOOPB                   _CANCTL1.Bits.LOOPB
#define CANCTL1_CLKSRC                  _CANCTL1.Bits.CLKSRC
#define CANCTL1_CANE                    _CANCTL1.Bits.CANE

#define CANCTL1_INITAK_MASK             1U
#define CANCTL1_SLPAK_MASK              2U
#define CANCTL1_WUPM_MASK               4U
#define CANCTL1_BORM_MASK               8U
#define CANCTL1_LISTEN_MASK             16U
#define CANCTL1_LOOPB_MASK              32U
#define CANCTL1_CLKSRC_MASK             64U
#define CANCTL1_CANE_MASK               128U


/*** CANBTR0 - MSCAN Bus Timing Register 0; 0xFFFF9882 ***/
typedef union {
  byte Byte;
  struct {
    byte BRP0        :1;                                       /* Baud Rate Prescaler 0 */
    byte BRP1        :1;                                       /* Baud Rate Prescaler 1 */
    byte BRP2        :1;                                       /* Baud Rate Prescaler 2 */
    byte BRP3        :1;                                       /* Baud Rate Prescaler 3 */
    byte BRP4        :1;                                       /* Baud Rate Prescaler 4 */
    byte BRP5        :1;                                       /* Baud Rate Prescaler 5 */
    byte SJW0        :1;                                       /* Synchronization Jump Width 0 */
    byte SJW1        :1;                                       /* Synchronization Jump Width 1 */
  } Bits;
  struct {
    byte grpBRP  :6;
    byte grpSJW  :2;
  } MergedBits;
} CANBTR0STR;
extern volatile CANBTR0STR _CANBTR0 @0xFFFF9882;
#define CANBTR0                         _CANBTR0.Byte
#define CANBTR0_BRP0                    _CANBTR0.Bits.BRP0
#define CANBTR0_BRP1                    _CANBTR0.Bits.BRP1
#define CANBTR0_BRP2                    _CANBTR0.Bits.BRP2
#define CANBTR0_BRP3                    _CANBTR0.Bits.BRP3
#define CANBTR0_BRP4                    _CANBTR0.Bits.BRP4
#define CANBTR0_BRP5                    _CANBTR0.Bits.BRP5
#define CANBTR0_SJW0                    _CANBTR0.Bits.SJW0
#define CANBTR0_SJW1                    _CANBTR0.Bits.SJW1
/* CANBTR_ARR: Access 2 CANBTRx registers in an array */
#define CANBTR_ARR                      ((volatile byte *) &CANBTR0)
#define CANBTR0_BRP                     _CANBTR0.MergedBits.grpBRP
#define CANBTR0_SJW                     _CANBTR0.MergedBits.grpSJW

#define CANBTR0_BRP0_MASK               1U
#define CANBTR0_BRP1_MASK               2U
#define CANBTR0_BRP2_MASK               4U
#define CANBTR0_BRP3_MASK               8U
#define CANBTR0_BRP4_MASK               16U
#define CANBTR0_BRP5_MASK               32U
#define CANBTR0_SJW0_MASK               64U
#define CANBTR0_SJW1_MASK               128U
#define CANBTR0_BRP_MASK                63U
#define CANBTR0_BRP_BITNUM              0U
#define CANBTR0_SJW_MASK                192U
#define CANBTR0_SJW_BITNUM              6U


/*** CANBTR1 - MSCAN Bus Timing Register 1; 0xFFFF9883 ***/
typedef union {
  byte Byte;
  struct {
    byte TSEG10      :1;                                       /* Time Segment 10 */
    byte TSEG11      :1;                                       /* Time Segment 11 */
    byte TSEG12      :1;                                       /* Time Segment 12 */
    byte TSEG13      :1;                                       /* Time Segment 13 */
    byte TSEG20      :1;                                       /* Time Segment 20 */
    byte TSEG21      :1;                                       /* Time Segment 21 */
    byte TSEG22      :1;                                       /* Time Segment 22 */
    byte SAMP        :1;                                       /* Sampling */
  } Bits;
  struct {
    byte grpTSEG_10 :4;
    byte grpTSEG_20 :3;
    byte         :1;
  } MergedBits;
} CANBTR1STR;
extern volatile CANBTR1STR _CANBTR1 @0xFFFF9883;
#define CANBTR1                         _CANBTR1.Byte
#define CANBTR1_TSEG10                  _CANBTR1.Bits.TSEG10
#define CANBTR1_TSEG11                  _CANBTR1.Bits.TSEG11
#define CANBTR1_TSEG12                  _CANBTR1.Bits.TSEG12
#define CANBTR1_TSEG13                  _CANBTR1.Bits.TSEG13
#define CANBTR1_TSEG20                  _CANBTR1.Bits.TSEG20
#define CANBTR1_TSEG21                  _CANBTR1.Bits.TSEG21
#define CANBTR1_TSEG22                  _CANBTR1.Bits.TSEG22
#define CANBTR1_SAMP                    _CANBTR1.Bits.SAMP
#define CANBTR1_TSEG_10                 _CANBTR1.MergedBits.grpTSEG_10
#define CANBTR1_TSEG_20                 _CANBTR1.MergedBits.grpTSEG_20
#define CANBTR1_TSEG                    CANBTR1_TSEG_10

#define CANBTR1_TSEG10_MASK             1U
#define CANBTR1_TSEG11_MASK             2U
#define CANBTR1_TSEG12_MASK             4U
#define CANBTR1_TSEG13_MASK             8U
#define CANBTR1_TSEG20_MASK             16U
#define CANBTR1_TSEG21_MASK             32U
#define CANBTR1_TSEG22_MASK             64U
#define CANBTR1_SAMP_MASK               128U
#define CANBTR1_TSEG_10_MASK            15U
#define CANBTR1_TSEG_10_BITNUM          0U
#define CANBTR1_TSEG_20_MASK            112U
#define CANBTR1_TSEG_20_BITNUM          4U


/*** CANRFLG - MSCAN Receiver Flag Register; 0xFFFF9884 ***/
typedef union {
  byte Byte;
  struct {
    byte RXF         :1;                                       /* Receive Buffer Full */
    byte OVRIF       :1;                                       /* Overrun Interrupt Flag */
    byte TSTAT0      :1;                                       /* Transmitter Status Bit 0 */
    byte TSTAT1      :1;                                       /* Transmitter Status Bit 1 */
    byte RSTAT0      :1;                                       /* Receiver Status Bit 0 */
    byte RSTAT1      :1;                                       /* Receiver Status Bit 1 */
    byte CSCIF       :1;                                       /* CAN Status Change Interrupt Flag */
    byte WUPIF       :1;                                       /* Wake-up Interrupt Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTAT :2;
    byte grpRSTAT :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRFLGSTR;
extern volatile CANRFLGSTR _CANRFLG @0xFFFF9884;
#define CANRFLG                         _CANRFLG.Byte
#define CANRFLG_RXF                     _CANRFLG.Bits.RXF
#define CANRFLG_OVRIF                   _CANRFLG.Bits.OVRIF
#define CANRFLG_TSTAT0                  _CANRFLG.Bits.TSTAT0
#define CANRFLG_TSTAT1                  _CANRFLG.Bits.TSTAT1
#define CANRFLG_RSTAT0                  _CANRFLG.Bits.RSTAT0
#define CANRFLG_RSTAT1                  _CANRFLG.Bits.RSTAT1
#define CANRFLG_CSCIF                   _CANRFLG.Bits.CSCIF
#define CANRFLG_WUPIF                   _CANRFLG.Bits.WUPIF
#define CANRFLG_TSTAT                   _CANRFLG.MergedBits.grpTSTAT
#define CANRFLG_RSTAT                   _CANRFLG.MergedBits.grpRSTAT

#define CANRFLG_RXF_MASK                1U
#define CANRFLG_OVRIF_MASK              2U
#define CANRFLG_TSTAT0_MASK             4U
#define CANRFLG_TSTAT1_MASK             8U
#define CANRFLG_RSTAT0_MASK             16U
#define CANRFLG_RSTAT1_MASK             32U
#define CANRFLG_CSCIF_MASK              64U
#define CANRFLG_WUPIF_MASK              128U
#define CANRFLG_TSTAT_MASK              12U
#define CANRFLG_TSTAT_BITNUM            2U
#define CANRFLG_RSTAT_MASK              48U
#define CANRFLG_RSTAT_BITNUM            4U


/*** CANRIER - MSCAN Receiver Interrupt Enable Register; 0xFFFF9885 ***/
typedef union {
  byte Byte;
  struct {
    byte RXFIE       :1;                                       /* Receiver Full Interrupt Enable */
    byte OVRIE       :1;                                       /* Overrun Interrupt Enable */
    byte TSTATE0     :1;                                       /* Transmitter Status Change Enable 0 */
    byte TSTATE1     :1;                                       /* Transmitter Status Change Enable 1 */
    byte RSTATE0     :1;                                       /* Receiver Status Change Enable 0 */
    byte RSTATE1     :1;                                       /* Receiver Status Change Enable 1 */
    byte CSCIE       :1;                                       /* CAN Status Change Interrupt Enable */
    byte WUPIE       :1;                                       /* Wake-up Interrupt Enable */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpTSTATE :2;
    byte grpRSTATE :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRIERSTR;
extern volatile CANRIERSTR _CANRIER @0xFFFF9885;
#define CANRIER                         _CANRIER.Byte
#define CANRIER_RXFIE                   _CANRIER.Bits.RXFIE
#define CANRIER_OVRIE                   _CANRIER.Bits.OVRIE
#define CANRIER_TSTATE0                 _CANRIER.Bits.TSTATE0
#define CANRIER_TSTATE1                 _CANRIER.Bits.TSTATE1
#define CANRIER_RSTATE0                 _CANRIER.Bits.RSTATE0
#define CANRIER_RSTATE1                 _CANRIER.Bits.RSTATE1
#define CANRIER_CSCIE                   _CANRIER.Bits.CSCIE
#define CANRIER_WUPIE                   _CANRIER.Bits.WUPIE
#define CANRIER_TSTATE                  _CANRIER.MergedBits.grpTSTATE
#define CANRIER_RSTATE                  _CANRIER.MergedBits.grpRSTATE

#define CANRIER_RXFIE_MASK              1U
#define CANRIER_OVRIE_MASK              2U
#define CANRIER_TSTATE0_MASK            4U
#define CANRIER_TSTATE1_MASK            8U
#define CANRIER_RSTATE0_MASK            16U
#define CANRIER_RSTATE1_MASK            32U
#define CANRIER_CSCIE_MASK              64U
#define CANRIER_WUPIE_MASK              128U
#define CANRIER_TSTATE_MASK             12U
#define CANRIER_TSTATE_BITNUM           2U
#define CANRIER_RSTATE_MASK             48U
#define CANRIER_RSTATE_BITNUM           4U


/*** CANTFLG - MSCAN Transmitter Flag Register; 0xFFFF9886 ***/
typedef union {
  byte Byte;
  struct {
    byte TXE0        :1;                                       /* Transmitter Buffer Empty 0 */
    byte TXE1        :1;                                       /* Transmitter Buffer Empty 1 */
    byte TXE2        :1;                                       /* Transmitter Buffer Empty 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXE  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTFLGSTR;
extern volatile CANTFLGSTR _CANTFLG @0xFFFF9886;
#define CANTFLG                         _CANTFLG.Byte
#define CANTFLG_TXE0                    _CANTFLG.Bits.TXE0
#define CANTFLG_TXE1                    _CANTFLG.Bits.TXE1
#define CANTFLG_TXE2                    _CANTFLG.Bits.TXE2
#define CANTFLG_TXE                     _CANTFLG.MergedBits.grpTXE

#define CANTFLG_TXE0_MASK               1U
#define CANTFLG_TXE1_MASK               2U
#define CANTFLG_TXE2_MASK               4U
#define CANTFLG_TXE_MASK                7U
#define CANTFLG_TXE_BITNUM              0U


/*** CANTIER - MSCAN Transmitter Interrupt Enable Register; 0xFFFF9887 ***/
typedef union {
  byte Byte;
  struct {
    byte TXEIE0      :1;                                       /* Transmitter Empty Interrupt Enable 0 */
    byte TXEIE1      :1;                                       /* Transmitter Empty Interrupt Enable 1 */
    byte TXEIE2      :1;                                       /* Transmitter Empty Interrupt Enable 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTXEIE :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTIERSTR;
extern volatile CANTIERSTR _CANTIER @0xFFFF9887;
#define CANTIER                         _CANTIER.Byte
#define CANTIER_TXEIE0                  _CANTIER.Bits.TXEIE0
#define CANTIER_TXEIE1                  _CANTIER.Bits.TXEIE1
#define CANTIER_TXEIE2                  _CANTIER.Bits.TXEIE2
#define CANTIER_TXEIE                   _CANTIER.MergedBits.grpTXEIE

#define CANTIER_TXEIE0_MASK             1U
#define CANTIER_TXEIE1_MASK             2U
#define CANTIER_TXEIE2_MASK             4U
#define CANTIER_TXEIE_MASK              7U
#define CANTIER_TXEIE_BITNUM            0U


/*** CANTARQ - MSCAN Transmitter Message Abort Request; 0xFFFF9888 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTRQ0      :1;                                       /* Abort Request 0 */
    byte ABTRQ1      :1;                                       /* Abort Request 1 */
    byte ABTRQ2      :1;                                       /* Abort Request 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTRQ :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTARQSTR;
extern volatile CANTARQSTR _CANTARQ @0xFFFF9888;
#define CANTARQ                         _CANTARQ.Byte
#define CANTARQ_ABTRQ0                  _CANTARQ.Bits.ABTRQ0
#define CANTARQ_ABTRQ1                  _CANTARQ.Bits.ABTRQ1
#define CANTARQ_ABTRQ2                  _CANTARQ.Bits.ABTRQ2
#define CANTARQ_ABTRQ                   _CANTARQ.MergedBits.grpABTRQ

#define CANTARQ_ABTRQ0_MASK             1U
#define CANTARQ_ABTRQ1_MASK             2U
#define CANTARQ_ABTRQ2_MASK             4U
#define CANTARQ_ABTRQ_MASK              7U
#define CANTARQ_ABTRQ_BITNUM            0U


/*** CANTAAK - MSCAN Transmitter Message Abort Acknowledge; 0xFFFF9889 ***/
typedef union {
  byte Byte;
  struct {
    byte ABTAK0      :1;                                       /* Abort Acknowledge 0 */
    byte ABTAK1      :1;                                       /* Abort Acknowledge 1 */
    byte ABTAK2      :1;                                       /* Abort Acknowledge 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpABTAK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTAAKSTR;
extern volatile CANTAAKSTR _CANTAAK @0xFFFF9889;
#define CANTAAK                         _CANTAAK.Byte
#define CANTAAK_ABTAK0                  _CANTAAK.Bits.ABTAK0
#define CANTAAK_ABTAK1                  _CANTAAK.Bits.ABTAK1
#define CANTAAK_ABTAK2                  _CANTAAK.Bits.ABTAK2
#define CANTAAK_ABTAK                   _CANTAAK.MergedBits.grpABTAK

#define CANTAAK_ABTAK0_MASK             1U
#define CANTAAK_ABTAK1_MASK             2U
#define CANTAAK_ABTAK2_MASK             4U
#define CANTAAK_ABTAK_MASK              7U
#define CANTAAK_ABTAK_BITNUM            0U


/*** CANTBSEL - MSCAN Transmit Buffer Selection; 0xFFFF988A ***/
typedef union {
  byte Byte;
  struct {
    byte TX0         :1;                                       /* Transmit Buffer Select 0 */
    byte TX1         :1;                                       /* Transmit Buffer Select 1 */
    byte TX2         :1;                                       /* Transmit Buffer Select 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTX   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTBSELSTR;
extern volatile CANTBSELSTR _CANTBSEL @0xFFFF988A;
#define CANTBSEL                        _CANTBSEL.Byte
#define CANTBSEL_TX0                    _CANTBSEL.Bits.TX0
#define CANTBSEL_TX1                    _CANTBSEL.Bits.TX1
#define CANTBSEL_TX2                    _CANTBSEL.Bits.TX2
#define CANTBSEL_TX                     _CANTBSEL.MergedBits.grpTX

#define CANTBSEL_TX0_MASK               1U
#define CANTBSEL_TX1_MASK               2U
#define CANTBSEL_TX2_MASK               4U
#define CANTBSEL_TX_MASK                7U
#define CANTBSEL_TX_BITNUM              0U


/*** CANIDAC - MSCAN Identifier Acceptance Control Register; 0xFFFF988B ***/
typedef union {
  byte Byte;
  struct {
    byte IDHIT0      :1;                                       /* Identifier Acceptance Hit Indicator 0 */
    byte IDHIT1      :1;                                       /* Identifier Acceptance Hit Indicator 1 */
    byte IDHIT2      :1;                                       /* Identifier Acceptance Hit Indicator 2 */
    byte             :1; 
    byte IDAM0       :1;                                       /* Identifier Acceptance Mode 0 */
    byte IDAM1       :1;                                       /* Identifier Acceptance Mode 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIDHIT :3;
    byte         :1;
    byte grpIDAM :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANIDACSTR;
extern volatile CANIDACSTR _CANIDAC @0xFFFF988B;
#define CANIDAC                         _CANIDAC.Byte
#define CANIDAC_IDHIT0                  _CANIDAC.Bits.IDHIT0
#define CANIDAC_IDHIT1                  _CANIDAC.Bits.IDHIT1
#define CANIDAC_IDHIT2                  _CANIDAC.Bits.IDHIT2
#define CANIDAC_IDAM0                   _CANIDAC.Bits.IDAM0
#define CANIDAC_IDAM1                   _CANIDAC.Bits.IDAM1
#define CANIDAC_IDHIT                   _CANIDAC.MergedBits.grpIDHIT
#define CANIDAC_IDAM                    _CANIDAC.MergedBits.grpIDAM

#define CANIDAC_IDHIT0_MASK             1U
#define CANIDAC_IDHIT1_MASK             2U
#define CANIDAC_IDHIT2_MASK             4U
#define CANIDAC_IDAM0_MASK              16U
#define CANIDAC_IDAM1_MASK              32U
#define CANIDAC_IDHIT_MASK              7U
#define CANIDAC_IDHIT_BITNUM            0U
#define CANIDAC_IDAM_MASK               48U
#define CANIDAC_IDAM_BITNUM             4U


/*** CANMISC - MSCAN Miscellaneous Register; 0xFFFF988D ***/
typedef union {
  byte Byte;
  struct {
    byte BOHOLD      :1;                                       /* Bus-off State Hold Until User Request - If BORM is set */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CANMISCSTR;
extern volatile CANMISCSTR _CANMISC @0xFFFF988D;
#define CANMISC                         _CANMISC.Byte
#define CANMISC_BOHOLD                  _CANMISC.Bits.BOHOLD

#define CANMISC_BOHOLD_MASK             1U


/*** CANRXERR - MSCAN Receive Error Counter Register; 0xFFFF988E ***/
typedef union {
  byte Byte;
  struct {
    byte RXERR0      :1;                                       /* Bit 0 */
    byte RXERR1      :1;                                       /* Bit 1 */
    byte RXERR2      :1;                                       /* Bit 2 */
    byte RXERR3      :1;                                       /* Bit 3 */
    byte RXERR4      :1;                                       /* Bit 4 */
    byte RXERR5      :1;                                       /* Bit 5 */
    byte RXERR6      :1;                                       /* Bit 6 */
    byte RXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANRXERRSTR;
extern volatile CANRXERRSTR _CANRXERR @0xFFFF988E;
#define CANRXERR                        _CANRXERR.Byte
#define CANRXERR_RXERR0                 _CANRXERR.Bits.RXERR0
#define CANRXERR_RXERR1                 _CANRXERR.Bits.RXERR1
#define CANRXERR_RXERR2                 _CANRXERR.Bits.RXERR2
#define CANRXERR_RXERR3                 _CANRXERR.Bits.RXERR3
#define CANRXERR_RXERR4                 _CANRXERR.Bits.RXERR4
#define CANRXERR_RXERR5                 _CANRXERR.Bits.RXERR5
#define CANRXERR_RXERR6                 _CANRXERR.Bits.RXERR6
#define CANRXERR_RXERR7                 _CANRXERR.Bits.RXERR7

#define CANRXERR_RXERR0_MASK            1U
#define CANRXERR_RXERR1_MASK            2U
#define CANRXERR_RXERR2_MASK            4U
#define CANRXERR_RXERR3_MASK            8U
#define CANRXERR_RXERR4_MASK            16U
#define CANRXERR_RXERR5_MASK            32U
#define CANRXERR_RXERR6_MASK            64U
#define CANRXERR_RXERR7_MASK            128U


/*** CANTXERR - MSCAN Transmit Error Counter Register; 0xFFFF988F ***/
typedef union {
  byte Byte;
  struct {
    byte TXERR0      :1;                                       /* Bit 0 */
    byte TXERR1      :1;                                       /* Bit 1 */
    byte TXERR2      :1;                                       /* Bit 2 */
    byte TXERR3      :1;                                       /* Bit 3 */
    byte TXERR4      :1;                                       /* Bit 4 */
    byte TXERR5      :1;                                       /* Bit 5 */
    byte TXERR6      :1;                                       /* Bit 6 */
    byte TXERR7      :1;                                       /* Bit 7 */
  } Bits;
} CANTXERRSTR;
extern volatile CANTXERRSTR _CANTXERR @0xFFFF988F;
#define CANTXERR                        _CANTXERR.Byte
#define CANTXERR_TXERR0                 _CANTXERR.Bits.TXERR0
#define CANTXERR_TXERR1                 _CANTXERR.Bits.TXERR1
#define CANTXERR_TXERR2                 _CANTXERR.Bits.TXERR2
#define CANTXERR_TXERR3                 _CANTXERR.Bits.TXERR3
#define CANTXERR_TXERR4                 _CANTXERR.Bits.TXERR4
#define CANTXERR_TXERR5                 _CANTXERR.Bits.TXERR5
#define CANTXERR_TXERR6                 _CANTXERR.Bits.TXERR6
#define CANTXERR_TXERR7                 _CANTXERR.Bits.TXERR7

#define CANTXERR_TXERR0_MASK            1U
#define CANTXERR_TXERR1_MASK            2U
#define CANTXERR_TXERR2_MASK            4U
#define CANTXERR_TXERR3_MASK            8U
#define CANTXERR_TXERR4_MASK            16U
#define CANTXERR_TXERR5_MASK            32U
#define CANTXERR_TXERR6_MASK            64U
#define CANTXERR_TXERR7_MASK            128U


/*** CANIDAR0 - MSCAN Identifier Acceptance Register 0; 0xFFFF9890 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR0STR;
extern volatile CANIDAR0STR _CANIDAR0 @0xFFFF9890;
#define CANIDAR0                        _CANIDAR0.Byte
#define CANIDAR0_AC0                    _CANIDAR0.Bits.AC0
#define CANIDAR0_AC1                    _CANIDAR0.Bits.AC1
#define CANIDAR0_AC2                    _CANIDAR0.Bits.AC2
#define CANIDAR0_AC3                    _CANIDAR0.Bits.AC3
#define CANIDAR0_AC4                    _CANIDAR0.Bits.AC4
#define CANIDAR0_AC5                    _CANIDAR0.Bits.AC5
#define CANIDAR0_AC6                    _CANIDAR0.Bits.AC6
#define CANIDAR0_AC7                    _CANIDAR0.Bits.AC7
/* CANIDAR_ARR: Access 4 CANIDARx registers in an array */
#define CANIDAR_ARR                     ((volatile byte *) &CANIDAR0)

#define CANIDAR0_AC0_MASK               1U
#define CANIDAR0_AC1_MASK               2U
#define CANIDAR0_AC2_MASK               4U
#define CANIDAR0_AC3_MASK               8U
#define CANIDAR0_AC4_MASK               16U
#define CANIDAR0_AC5_MASK               32U
#define CANIDAR0_AC6_MASK               64U
#define CANIDAR0_AC7_MASK               128U


/*** CANIDAR1 - MSCAN Identifier Acceptance Register 1; 0xFFFF9891 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR1STR;
extern volatile CANIDAR1STR _CANIDAR1 @0xFFFF9891;
#define CANIDAR1                        _CANIDAR1.Byte
#define CANIDAR1_AC0                    _CANIDAR1.Bits.AC0
#define CANIDAR1_AC1                    _CANIDAR1.Bits.AC1
#define CANIDAR1_AC2                    _CANIDAR1.Bits.AC2
#define CANIDAR1_AC3                    _CANIDAR1.Bits.AC3
#define CANIDAR1_AC4                    _CANIDAR1.Bits.AC4
#define CANIDAR1_AC5                    _CANIDAR1.Bits.AC5
#define CANIDAR1_AC6                    _CANIDAR1.Bits.AC6
#define CANIDAR1_AC7                    _CANIDAR1.Bits.AC7

#define CANIDAR1_AC0_MASK               1U
#define CANIDAR1_AC1_MASK               2U
#define CANIDAR1_AC2_MASK               4U
#define CANIDAR1_AC3_MASK               8U
#define CANIDAR1_AC4_MASK               16U
#define CANIDAR1_AC5_MASK               32U
#define CANIDAR1_AC6_MASK               64U
#define CANIDAR1_AC7_MASK               128U


/*** CANIDAR2 - MSCAN Identifier Acceptance Register 2; 0xFFFF9892 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR2STR;
extern volatile CANIDAR2STR _CANIDAR2 @0xFFFF9892;
#define CANIDAR2                        _CANIDAR2.Byte
#define CANIDAR2_AC0                    _CANIDAR2.Bits.AC0
#define CANIDAR2_AC1                    _CANIDAR2.Bits.AC1
#define CANIDAR2_AC2                    _CANIDAR2.Bits.AC2
#define CANIDAR2_AC3                    _CANIDAR2.Bits.AC3
#define CANIDAR2_AC4                    _CANIDAR2.Bits.AC4
#define CANIDAR2_AC5                    _CANIDAR2.Bits.AC5
#define CANIDAR2_AC6                    _CANIDAR2.Bits.AC6
#define CANIDAR2_AC7                    _CANIDAR2.Bits.AC7

#define CANIDAR2_AC0_MASK               1U
#define CANIDAR2_AC1_MASK               2U
#define CANIDAR2_AC2_MASK               4U
#define CANIDAR2_AC3_MASK               8U
#define CANIDAR2_AC4_MASK               16U
#define CANIDAR2_AC5_MASK               32U
#define CANIDAR2_AC6_MASK               64U
#define CANIDAR2_AC7_MASK               128U


/*** CANIDAR3 - MSCAN Identifier Acceptance Register 3; 0xFFFF9893 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR3STR;
extern volatile CANIDAR3STR _CANIDAR3 @0xFFFF9893;
#define CANIDAR3                        _CANIDAR3.Byte
#define CANIDAR3_AC0                    _CANIDAR3.Bits.AC0
#define CANIDAR3_AC1                    _CANIDAR3.Bits.AC1
#define CANIDAR3_AC2                    _CANIDAR3.Bits.AC2
#define CANIDAR3_AC3                    _CANIDAR3.Bits.AC3
#define CANIDAR3_AC4                    _CANIDAR3.Bits.AC4
#define CANIDAR3_AC5                    _CANIDAR3.Bits.AC5
#define CANIDAR3_AC6                    _CANIDAR3.Bits.AC6
#define CANIDAR3_AC7                    _CANIDAR3.Bits.AC7

#define CANIDAR3_AC0_MASK               1U
#define CANIDAR3_AC1_MASK               2U
#define CANIDAR3_AC2_MASK               4U
#define CANIDAR3_AC3_MASK               8U
#define CANIDAR3_AC4_MASK               16U
#define CANIDAR3_AC5_MASK               32U
#define CANIDAR3_AC6_MASK               64U
#define CANIDAR3_AC7_MASK               128U


/*** CANIDMR0 - MSCAN Identifier Mask Register 0; 0xFFFF9894 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR0STR;
extern volatile CANIDMR0STR _CANIDMR0 @0xFFFF9894;
#define CANIDMR0                        _CANIDMR0.Byte
#define CANIDMR0_AM0                    _CANIDMR0.Bits.AM0
#define CANIDMR0_AM1                    _CANIDMR0.Bits.AM1
#define CANIDMR0_AM2                    _CANIDMR0.Bits.AM2
#define CANIDMR0_AM3                    _CANIDMR0.Bits.AM3
#define CANIDMR0_AM4                    _CANIDMR0.Bits.AM4
#define CANIDMR0_AM5                    _CANIDMR0.Bits.AM5
#define CANIDMR0_AM6                    _CANIDMR0.Bits.AM6
#define CANIDMR0_AM7                    _CANIDMR0.Bits.AM7
/* CANIDMR_ARR: Access 4 CANIDMRx registers in an array */
#define CANIDMR_ARR                     ((volatile byte *) &CANIDMR0)

#define CANIDMR0_AM0_MASK               1U
#define CANIDMR0_AM1_MASK               2U
#define CANIDMR0_AM2_MASK               4U
#define CANIDMR0_AM3_MASK               8U
#define CANIDMR0_AM4_MASK               16U
#define CANIDMR0_AM5_MASK               32U
#define CANIDMR0_AM6_MASK               64U
#define CANIDMR0_AM7_MASK               128U


/*** CANIDMR1 - MSCAN Identifier Mask Register 1; 0xFFFF9895 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR1STR;
extern volatile CANIDMR1STR _CANIDMR1 @0xFFFF9895;
#define CANIDMR1                        _CANIDMR1.Byte
#define CANIDMR1_AM0                    _CANIDMR1.Bits.AM0
#define CANIDMR1_AM1                    _CANIDMR1.Bits.AM1
#define CANIDMR1_AM2                    _CANIDMR1.Bits.AM2
#define CANIDMR1_AM3                    _CANIDMR1.Bits.AM3
#define CANIDMR1_AM4                    _CANIDMR1.Bits.AM4
#define CANIDMR1_AM5                    _CANIDMR1.Bits.AM5
#define CANIDMR1_AM6                    _CANIDMR1.Bits.AM6
#define CANIDMR1_AM7                    _CANIDMR1.Bits.AM7

#define CANIDMR1_AM0_MASK               1U
#define CANIDMR1_AM1_MASK               2U
#define CANIDMR1_AM2_MASK               4U
#define CANIDMR1_AM3_MASK               8U
#define CANIDMR1_AM4_MASK               16U
#define CANIDMR1_AM5_MASK               32U
#define CANIDMR1_AM6_MASK               64U
#define CANIDMR1_AM7_MASK               128U


/*** CANIDMR2 - MSCAN Identifier Mask Register 2; 0xFFFF9896 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR2STR;
extern volatile CANIDMR2STR _CANIDMR2 @0xFFFF9896;
#define CANIDMR2                        _CANIDMR2.Byte
#define CANIDMR2_AM0                    _CANIDMR2.Bits.AM0
#define CANIDMR2_AM1                    _CANIDMR2.Bits.AM1
#define CANIDMR2_AM2                    _CANIDMR2.Bits.AM2
#define CANIDMR2_AM3                    _CANIDMR2.Bits.AM3
#define CANIDMR2_AM4                    _CANIDMR2.Bits.AM4
#define CANIDMR2_AM5                    _CANIDMR2.Bits.AM5
#define CANIDMR2_AM6                    _CANIDMR2.Bits.AM6
#define CANIDMR2_AM7                    _CANIDMR2.Bits.AM7

#define CANIDMR2_AM0_MASK               1U
#define CANIDMR2_AM1_MASK               2U
#define CANIDMR2_AM2_MASK               4U
#define CANIDMR2_AM3_MASK               8U
#define CANIDMR2_AM4_MASK               16U
#define CANIDMR2_AM5_MASK               32U
#define CANIDMR2_AM6_MASK               64U
#define CANIDMR2_AM7_MASK               128U


/*** CANIDMR3 - MSCAN Identifier Mask Register 3; 0xFFFF9897 ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR3STR;
extern volatile CANIDMR3STR _CANIDMR3 @0xFFFF9897;
#define CANIDMR3                        _CANIDMR3.Byte
#define CANIDMR3_AM0                    _CANIDMR3.Bits.AM0
#define CANIDMR3_AM1                    _CANIDMR3.Bits.AM1
#define CANIDMR3_AM2                    _CANIDMR3.Bits.AM2
#define CANIDMR3_AM3                    _CANIDMR3.Bits.AM3
#define CANIDMR3_AM4                    _CANIDMR3.Bits.AM4
#define CANIDMR3_AM5                    _CANIDMR3.Bits.AM5
#define CANIDMR3_AM6                    _CANIDMR3.Bits.AM6
#define CANIDMR3_AM7                    _CANIDMR3.Bits.AM7

#define CANIDMR3_AM0_MASK               1U
#define CANIDMR3_AM1_MASK               2U
#define CANIDMR3_AM2_MASK               4U
#define CANIDMR3_AM3_MASK               8U
#define CANIDMR3_AM4_MASK               16U
#define CANIDMR3_AM5_MASK               32U
#define CANIDMR3_AM6_MASK               64U
#define CANIDMR3_AM7_MASK               128U


/*** CANIDAR4 - MSCAN Identifier Acceptance Register 4; 0xFFFF9898 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR4STR;
extern volatile CANIDAR4STR _CANIDAR4 @0xFFFF9898;
#define CANIDAR4                        _CANIDAR4.Byte
#define CANIDAR4_AC0                    _CANIDAR4.Bits.AC0
#define CANIDAR4_AC1                    _CANIDAR4.Bits.AC1
#define CANIDAR4_AC2                    _CANIDAR4.Bits.AC2
#define CANIDAR4_AC3                    _CANIDAR4.Bits.AC3
#define CANIDAR4_AC4                    _CANIDAR4.Bits.AC4
#define CANIDAR4_AC5                    _CANIDAR4.Bits.AC5
#define CANIDAR4_AC6                    _CANIDAR4.Bits.AC6
#define CANIDAR4_AC7                    _CANIDAR4.Bits.AC7

#define CANIDAR4_AC0_MASK               1U
#define CANIDAR4_AC1_MASK               2U
#define CANIDAR4_AC2_MASK               4U
#define CANIDAR4_AC3_MASK               8U
#define CANIDAR4_AC4_MASK               16U
#define CANIDAR4_AC5_MASK               32U
#define CANIDAR4_AC6_MASK               64U
#define CANIDAR4_AC7_MASK               128U


/*** CANIDAR5 - MSCAN Identifier Acceptance Register 5; 0xFFFF9899 ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR5STR;
extern volatile CANIDAR5STR _CANIDAR5 @0xFFFF9899;
#define CANIDAR5                        _CANIDAR5.Byte
#define CANIDAR5_AC0                    _CANIDAR5.Bits.AC0
#define CANIDAR5_AC1                    _CANIDAR5.Bits.AC1
#define CANIDAR5_AC2                    _CANIDAR5.Bits.AC2
#define CANIDAR5_AC3                    _CANIDAR5.Bits.AC3
#define CANIDAR5_AC4                    _CANIDAR5.Bits.AC4
#define CANIDAR5_AC5                    _CANIDAR5.Bits.AC5
#define CANIDAR5_AC6                    _CANIDAR5.Bits.AC6
#define CANIDAR5_AC7                    _CANIDAR5.Bits.AC7

#define CANIDAR5_AC0_MASK               1U
#define CANIDAR5_AC1_MASK               2U
#define CANIDAR5_AC2_MASK               4U
#define CANIDAR5_AC3_MASK               8U
#define CANIDAR5_AC4_MASK               16U
#define CANIDAR5_AC5_MASK               32U
#define CANIDAR5_AC6_MASK               64U
#define CANIDAR5_AC7_MASK               128U


/*** CANIDAR6 - MSCAN Identifier Acceptance Register 6; 0xFFFF989A ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR6STR;
extern volatile CANIDAR6STR _CANIDAR6 @0xFFFF989A;
#define CANIDAR6                        _CANIDAR6.Byte
#define CANIDAR6_AC0                    _CANIDAR6.Bits.AC0
#define CANIDAR6_AC1                    _CANIDAR6.Bits.AC1
#define CANIDAR6_AC2                    _CANIDAR6.Bits.AC2
#define CANIDAR6_AC3                    _CANIDAR6.Bits.AC3
#define CANIDAR6_AC4                    _CANIDAR6.Bits.AC4
#define CANIDAR6_AC5                    _CANIDAR6.Bits.AC5
#define CANIDAR6_AC6                    _CANIDAR6.Bits.AC6
#define CANIDAR6_AC7                    _CANIDAR6.Bits.AC7

#define CANIDAR6_AC0_MASK               1U
#define CANIDAR6_AC1_MASK               2U
#define CANIDAR6_AC2_MASK               4U
#define CANIDAR6_AC3_MASK               8U
#define CANIDAR6_AC4_MASK               16U
#define CANIDAR6_AC5_MASK               32U
#define CANIDAR6_AC6_MASK               64U
#define CANIDAR6_AC7_MASK               128U


/*** CANIDAR7 - MSCAN Identifier Acceptance Register 7; 0xFFFF989B ***/
typedef union {
  byte Byte;
  struct {
    byte AC0         :1;                                       /* Acceptance Code Bit 0 */
    byte AC1         :1;                                       /* Acceptance Code Bit 1 */
    byte AC2         :1;                                       /* Acceptance Code Bit 2 */
    byte AC3         :1;                                       /* Acceptance Code Bit 3 */
    byte AC4         :1;                                       /* Acceptance Code Bit 4 */
    byte AC5         :1;                                       /* Acceptance Code Bit 5 */
    byte AC6         :1;                                       /* Acceptance Code Bit 6 */
    byte AC7         :1;                                       /* Acceptance Code Bit 7 */
  } Bits;
} CANIDAR7STR;
extern volatile CANIDAR7STR _CANIDAR7 @0xFFFF989B;
#define CANIDAR7                        _CANIDAR7.Byte
#define CANIDAR7_AC0                    _CANIDAR7.Bits.AC0
#define CANIDAR7_AC1                    _CANIDAR7.Bits.AC1
#define CANIDAR7_AC2                    _CANIDAR7.Bits.AC2
#define CANIDAR7_AC3                    _CANIDAR7.Bits.AC3
#define CANIDAR7_AC4                    _CANIDAR7.Bits.AC4
#define CANIDAR7_AC5                    _CANIDAR7.Bits.AC5
#define CANIDAR7_AC6                    _CANIDAR7.Bits.AC6
#define CANIDAR7_AC7                    _CANIDAR7.Bits.AC7

#define CANIDAR7_AC0_MASK               1U
#define CANIDAR7_AC1_MASK               2U
#define CANIDAR7_AC2_MASK               4U
#define CANIDAR7_AC3_MASK               8U
#define CANIDAR7_AC4_MASK               16U
#define CANIDAR7_AC5_MASK               32U
#define CANIDAR7_AC6_MASK               64U
#define CANIDAR7_AC7_MASK               128U


/*** CANIDMR4 - MSCAN Identifier Mask Register 4; 0xFFFF989C ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR4STR;
extern volatile CANIDMR4STR _CANIDMR4 @0xFFFF989C;
#define CANIDMR4                        _CANIDMR4.Byte
#define CANIDMR4_AM0                    _CANIDMR4.Bits.AM0
#define CANIDMR4_AM1                    _CANIDMR4.Bits.AM1
#define CANIDMR4_AM2                    _CANIDMR4.Bits.AM2
#define CANIDMR4_AM3                    _CANIDMR4.Bits.AM3
#define CANIDMR4_AM4                    _CANIDMR4.Bits.AM4
#define CANIDMR4_AM5                    _CANIDMR4.Bits.AM5
#define CANIDMR4_AM6                    _CANIDMR4.Bits.AM6
#define CANIDMR4_AM7                    _CANIDMR4.Bits.AM7

#define CANIDMR4_AM0_MASK               1U
#define CANIDMR4_AM1_MASK               2U
#define CANIDMR4_AM2_MASK               4U
#define CANIDMR4_AM3_MASK               8U
#define CANIDMR4_AM4_MASK               16U
#define CANIDMR4_AM5_MASK               32U
#define CANIDMR4_AM6_MASK               64U
#define CANIDMR4_AM7_MASK               128U


/*** CANIDMR5 - MSCAN Identifier Mask Register 5; 0xFFFF989D ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR5STR;
extern volatile CANIDMR5STR _CANIDMR5 @0xFFFF989D;
#define CANIDMR5                        _CANIDMR5.Byte
#define CANIDMR5_AM0                    _CANIDMR5.Bits.AM0
#define CANIDMR5_AM1                    _CANIDMR5.Bits.AM1
#define CANIDMR5_AM2                    _CANIDMR5.Bits.AM2
#define CANIDMR5_AM3                    _CANIDMR5.Bits.AM3
#define CANIDMR5_AM4                    _CANIDMR5.Bits.AM4
#define CANIDMR5_AM5                    _CANIDMR5.Bits.AM5
#define CANIDMR5_AM6                    _CANIDMR5.Bits.AM6
#define CANIDMR5_AM7                    _CANIDMR5.Bits.AM7

#define CANIDMR5_AM0_MASK               1U
#define CANIDMR5_AM1_MASK               2U
#define CANIDMR5_AM2_MASK               4U
#define CANIDMR5_AM3_MASK               8U
#define CANIDMR5_AM4_MASK               16U
#define CANIDMR5_AM5_MASK               32U
#define CANIDMR5_AM6_MASK               64U
#define CANIDMR5_AM7_MASK               128U


/*** CANIDMR6 - MSCAN Identifier Mask Register 6; 0xFFFF989E ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR6STR;
extern volatile CANIDMR6STR _CANIDMR6 @0xFFFF989E;
#define CANIDMR6                        _CANIDMR6.Byte
#define CANIDMR6_AM0                    _CANIDMR6.Bits.AM0
#define CANIDMR6_AM1                    _CANIDMR6.Bits.AM1
#define CANIDMR6_AM2                    _CANIDMR6.Bits.AM2
#define CANIDMR6_AM3                    _CANIDMR6.Bits.AM3
#define CANIDMR6_AM4                    _CANIDMR6.Bits.AM4
#define CANIDMR6_AM5                    _CANIDMR6.Bits.AM5
#define CANIDMR6_AM6                    _CANIDMR6.Bits.AM6
#define CANIDMR6_AM7                    _CANIDMR6.Bits.AM7

#define CANIDMR6_AM0_MASK               1U
#define CANIDMR6_AM1_MASK               2U
#define CANIDMR6_AM2_MASK               4U
#define CANIDMR6_AM3_MASK               8U
#define CANIDMR6_AM4_MASK               16U
#define CANIDMR6_AM5_MASK               32U
#define CANIDMR6_AM6_MASK               64U
#define CANIDMR6_AM7_MASK               128U


/*** CANIDMR7 - MSCAN Identifier Mask Register 7; 0xFFFF989F ***/
typedef union {
  byte Byte;
  struct {
    byte AM0         :1;                                       /* Acceptance Mask Bit 0 */
    byte AM1         :1;                                       /* Acceptance Mask Bit 1 */
    byte AM2         :1;                                       /* Acceptance Mask Bit 2 */
    byte AM3         :1;                                       /* Acceptance Mask Bit 3 */
    byte AM4         :1;                                       /* Acceptance Mask Bit 4 */
    byte AM5         :1;                                       /* Acceptance Mask Bit 5 */
    byte AM6         :1;                                       /* Acceptance Mask Bit 6 */
    byte AM7         :1;                                       /* Acceptance Mask Bit 7 */
  } Bits;
} CANIDMR7STR;
extern volatile CANIDMR7STR _CANIDMR7 @0xFFFF989F;
#define CANIDMR7                        _CANIDMR7.Byte
#define CANIDMR7_AM0                    _CANIDMR7.Bits.AM0
#define CANIDMR7_AM1                    _CANIDMR7.Bits.AM1
#define CANIDMR7_AM2                    _CANIDMR7.Bits.AM2
#define CANIDMR7_AM3                    _CANIDMR7.Bits.AM3
#define CANIDMR7_AM4                    _CANIDMR7.Bits.AM4
#define CANIDMR7_AM5                    _CANIDMR7.Bits.AM5
#define CANIDMR7_AM6                    _CANIDMR7.Bits.AM6
#define CANIDMR7_AM7                    _CANIDMR7.Bits.AM7

#define CANIDMR7_AM0_MASK               1U
#define CANIDMR7_AM1_MASK               2U
#define CANIDMR7_AM2_MASK               4U
#define CANIDMR7_AM3_MASK               8U
#define CANIDMR7_AM4_MASK               16U
#define CANIDMR7_AM5_MASK               32U
#define CANIDMR7_AM6_MASK               64U
#define CANIDMR7_AM7_MASK               128U


/*** CANRIDR - MSCAN 0 Receive Identifier Register; 0xFFFF98A0 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** CANRIDR0 - MSCAN 0 Receive Identifier Register 0; 0xFFFF98A0 ***/
    union {
      byte Byte;
      struct {
        byte ID21        :1;                                       /* Extended format identifier Bit 21 */
        byte ID22        :1;                                       /* Extended format identifier Bit 22 */
        byte ID23        :1;                                       /* Extended format identifier Bit 23 */
        byte ID24        :1;                                       /* Extended format identifier Bit 24 */
        byte ID25        :1;                                       /* Extended format identifier Bit 25 */
        byte ID26        :1;                                       /* Extended format identifier Bit 26 */
        byte ID27        :1;                                       /* Extended format identifier Bit 27 */
        byte ID28        :1;                                       /* Extended format identifier Bit 28 */
      } Bits;
    } CANRIDR0STR;
    #define CANRIDR0                    _CANRIDR.Overlap_STR.CANRIDR0STR.Byte
    #define CANRIDR0_ID21               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID21
    #define CANRIDR0_ID22               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID22
    #define CANRIDR0_ID23               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID23
    #define CANRIDR0_ID24               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID24
    #define CANRIDR0_ID25               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID25
    #define CANRIDR0_ID26               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID26
    #define CANRIDR0_ID27               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID27
    #define CANRIDR0_ID28               _CANRIDR.Overlap_STR.CANRIDR0STR.Bits.ID28
    /* CANRIDR_ARR: Access 4 CANRIDRx registers in an array */
    #define CANRIDR_ARR                 ((volatile byte *) &CANRIDR0)
    
    #define CANRIDR0_ID21_MASK          1U
    #define CANRIDR0_ID22_MASK          2U
    #define CANRIDR0_ID23_MASK          4U
    #define CANRIDR0_ID24_MASK          8U
    #define CANRIDR0_ID25_MASK          16U
    #define CANRIDR0_ID26_MASK          32U
    #define CANRIDR0_ID27_MASK          64U
    #define CANRIDR0_ID28_MASK          128U
    

    /*** CANRIDR1 - MSCAN 0 Receive Identifier Register 1; 0xFFFF98A1 ***/
    union {
      byte Byte;
      struct {
        byte ID15        :1;                                       /* Extended format identifier Bit 15 */
        byte ID16        :1;                                       /* Extended format identifier Bit 16 */
        byte ID17        :1;                                       /* Extended format identifier Bit 17 */
        byte IDE         :1;                                       /* ID Extended */
        byte SRR         :1;                                       /* Substitute Remote Request */
        byte ID18        :1;                                       /* Extended format identifier Bit 18 */
        byte ID19        :1;                                       /* Extended format identifier Bit 19 */
        byte ID20        :1;                                       /* Extended format identifier Bit 20 */
      } Bits;
      struct {
        byte grpID_15 :3;
        byte     :1;
        byte     :1;
        byte grpID_18 :3;
      } MergedBits;
    } CANRIDR1STR;
    #define CANRIDR1                    _CANRIDR.Overlap_STR.CANRIDR1STR.Byte
    #define CANRIDR1_ID15               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID15
    #define CANRIDR1_ID16               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID16
    #define CANRIDR1_ID17               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID17
    #define CANRIDR1_IDE                _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.IDE
    #define CANRIDR1_SRR                _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.SRR
    #define CANRIDR1_ID18               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID18
    #define CANRIDR1_ID19               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID19
    #define CANRIDR1_ID20               _CANRIDR.Overlap_STR.CANRIDR1STR.Bits.ID20
    #define CANRIDR1_ID_15              _CANRIDR.Overlap_STR.CANRIDR1STR.MergedBits.grpID_15
    #define CANRIDR1_ID_18              _CANRIDR.Overlap_STR.CANRIDR1STR.MergedBits.grpID_18
    #define CANRIDR1_ID                 CANRIDR1_ID_15
    
    #define CANRIDR1_ID15_MASK          1U
    #define CANRIDR1_ID16_MASK          2U
    #define CANRIDR1_ID17_MASK          4U
    #define CANRIDR1_IDE_MASK           8U
    #define CANRIDR1_SRR_MASK           16U
    #define CANRIDR1_ID18_MASK          32U
    #define CANRIDR1_ID19_MASK          64U
    #define CANRIDR1_ID20_MASK          128U
    #define CANRIDR1_ID_15_MASK         7U
    #define CANRIDR1_ID_15_BITNUM       0U
    #define CANRIDR1_ID_18_MASK         224U
    #define CANRIDR1_ID_18_BITNUM       5U
    

    /*** CANRIDR2 - MSCAN 0 Receive Identifier Register 2; 0xFFFF98A2 ***/
    union {
      byte Byte;
      struct {
        byte ID7         :1;                                       /* Extended format identifier Bit 7 */
        byte ID8         :1;                                       /* Extended format identifier Bit 8 */
        byte ID9         :1;                                       /* Extended format identifier Bit 9 */
        byte ID10        :1;                                       /* Extended format identifier Bit 10 */
        byte ID11        :1;                                       /* Extended format identifier Bit 11 */
        byte ID12        :1;                                       /* Extended format identifier Bit 12 */
        byte ID13        :1;                                       /* Extended format identifier Bit 13 */
        byte ID14        :1;                                       /* Extended format identifier Bit 14 */
      } Bits;
    } CANRIDR2STR;
    #define CANRIDR2                    _CANRIDR.Overlap_STR.CANRIDR2STR.Byte
    #define CANRIDR2_ID7                _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID7
    #define CANRIDR2_ID8                _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID8
    #define CANRIDR2_ID9                _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID9
    #define CANRIDR2_ID10               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID10
    #define CANRIDR2_ID11               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID11
    #define CANRIDR2_ID12               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID12
    #define CANRIDR2_ID13               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID13
    #define CANRIDR2_ID14               _CANRIDR.Overlap_STR.CANRIDR2STR.Bits.ID14
    
    #define CANRIDR2_ID7_MASK           1U
    #define CANRIDR2_ID8_MASK           2U
    #define CANRIDR2_ID9_MASK           4U
    #define CANRIDR2_ID10_MASK          8U
    #define CANRIDR2_ID11_MASK          16U
    #define CANRIDR2_ID12_MASK          32U
    #define CANRIDR2_ID13_MASK          64U
    #define CANRIDR2_ID14_MASK          128U
    

    /*** CANRIDR3 - MSCAN 0 Receive Identifier Register 3; 0xFFFF98A3 ***/
    union {
      byte Byte;
      struct {
        byte RTR         :1;                                       /* Remote Transmission Request */
        byte ID0         :1;                                       /* Extended format identifier Bit 0 */
        byte ID1         :1;                                       /* Extended format identifier Bit 1 */
        byte ID2         :1;                                       /* Extended format identifier Bit 2 */
        byte ID3         :1;                                       /* Extended format identifier Bit 3 */
        byte ID4         :1;                                       /* Extended format identifier Bit 4 */
        byte ID5         :1;                                       /* Extended format identifier Bit 5 */
        byte ID6         :1;                                       /* Extended format identifier Bit 6 */
      } Bits;
      struct {
        byte     :1;
        byte grpID :7;
      } MergedBits;
    } CANRIDR3STR;
    #define CANRIDR3                    _CANRIDR.Overlap_STR.CANRIDR3STR.Byte
    #define CANRIDR3_RTR                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.RTR
    #define CANRIDR3_ID0                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID0
    #define CANRIDR3_ID1                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID1
    #define CANRIDR3_ID2                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID2
    #define CANRIDR3_ID3                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID3
    #define CANRIDR3_ID4                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID4
    #define CANRIDR3_ID5                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID5
    #define CANRIDR3_ID6                _CANRIDR.Overlap_STR.CANRIDR3STR.Bits.ID6
    #define CANRIDR3_ID                 _CANRIDR.Overlap_STR.CANRIDR3STR.MergedBits.grpID
    
    #define CANRIDR3_RTR_MASK           1U
    #define CANRIDR3_ID0_MASK           2U
    #define CANRIDR3_ID1_MASK           4U
    #define CANRIDR3_ID2_MASK           8U
    #define CANRIDR3_ID3_MASK           16U
    #define CANRIDR3_ID4_MASK           32U
    #define CANRIDR3_ID5_MASK           64U
    #define CANRIDR3_ID6_MASK           128U
    #define CANRIDR3_ID_MASK            254U
    #define CANRIDR3_ID_BITNUM          1U
    
  } Overlap_STR;

  struct {
    dword RTR        :1;                                       /* Remote Transmission Request */
    dword ID0        :1;                                       /* Extended format identifier Bit 0 */
    dword ID1        :1;                                       /* Extended format identifier Bit 1 */
    dword ID2        :1;                                       /* Extended format identifier Bit 2 */
    dword ID3        :1;                                       /* Extended format identifier Bit 3 */
    dword ID4        :1;                                       /* Extended format identifier Bit 4 */
    dword ID5        :1;                                       /* Extended format identifier Bit 5 */
    dword ID6        :1;                                       /* Extended format identifier Bit 6 */
    dword ID7        :1;                                       /* Extended format identifier Bit 7 */
    dword ID8        :1;                                       /* Extended format identifier Bit 8 */
    dword ID9        :1;                                       /* Extended format identifier Bit 9 */
    dword ID10       :1;                                       /* Extended format identifier Bit 10 */
    dword ID11       :1;                                       /* Extended format identifier Bit 11 */
    dword ID12       :1;                                       /* Extended format identifier Bit 12 */
    dword ID13       :1;                                       /* Extended format identifier Bit 13 */
    dword ID14       :1;                                       /* Extended format identifier Bit 14 */
    dword ID15       :1;                                       /* Extended format identifier Bit 15 */
    dword ID16       :1;                                       /* Extended format identifier Bit 16 */
    dword ID17       :1;                                       /* Extended format identifier Bit 17 */
    dword IDE        :1;                                       /* ID Extended */
    dword SRR        :1;                                       /* Substitute Remote Request */
    dword ID18       :1;                                       /* Extended format identifier Bit 18 */
    dword ID19       :1;                                       /* Extended format identifier Bit 19 */
    dword ID20       :1;                                       /* Extended format identifier Bit 20 */
    dword ID21       :1;                                       /* Extended format identifier Bit 21 */
    dword ID22       :1;                                       /* Extended format identifier Bit 22 */
    dword ID23       :1;                                       /* Extended format identifier Bit 23 */
    dword ID24       :1;                                       /* Extended format identifier Bit 24 */
    dword ID25       :1;                                       /* Extended format identifier Bit 25 */
    dword ID26       :1;                                       /* Extended format identifier Bit 26 */
    dword ID27       :1;                                       /* Extended format identifier Bit 27 */
    dword ID28       :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
  struct {
    dword        :1;
    dword grpID  :18;
    dword        :1;
    dword        :1;
    dword grpID_18 :11;
  } MergedBits;
} CANRIDRSTR;
extern volatile CANRIDRSTR _CANRIDR @0xFFFF98A0;
#define CANRIDR                         _CANRIDR.Dword
#define CANRIDR_RTR                     _CANRIDR.Bits.RTR
#define CANRIDR_ID0                     _CANRIDR.Bits.ID0
#define CANRIDR_ID1                     _CANRIDR.Bits.ID1
#define CANRIDR_ID2                     _CANRIDR.Bits.ID2
#define CANRIDR_ID3                     _CANRIDR.Bits.ID3
#define CANRIDR_ID4                     _CANRIDR.Bits.ID4
#define CANRIDR_ID5                     _CANRIDR.Bits.ID5
#define CANRIDR_ID6                     _CANRIDR.Bits.ID6
#define CANRIDR_ID7                     _CANRIDR.Bits.ID7
#define CANRIDR_ID8                     _CANRIDR.Bits.ID8
#define CANRIDR_ID9                     _CANRIDR.Bits.ID9
#define CANRIDR_ID10                    _CANRIDR.Bits.ID10
#define CANRIDR_ID11                    _CANRIDR.Bits.ID11
#define CANRIDR_ID12                    _CANRIDR.Bits.ID12
#define CANRIDR_ID13                    _CANRIDR.Bits.ID13
#define CANRIDR_ID14                    _CANRIDR.Bits.ID14
#define CANRIDR_ID15                    _CANRIDR.Bits.ID15
#define CANRIDR_ID16                    _CANRIDR.Bits.ID16
#define CANRIDR_ID17                    _CANRIDR.Bits.ID17
#define CANRIDR_IDE                     _CANRIDR.Bits.IDE
#define CANRIDR_SRR                     _CANRIDR.Bits.SRR
#define CANRIDR_ID18                    _CANRIDR.Bits.ID18
#define CANRIDR_ID19                    _CANRIDR.Bits.ID19
#define CANRIDR_ID20                    _CANRIDR.Bits.ID20
#define CANRIDR_ID21                    _CANRIDR.Bits.ID21
#define CANRIDR_ID22                    _CANRIDR.Bits.ID22
#define CANRIDR_ID23                    _CANRIDR.Bits.ID23
#define CANRIDR_ID24                    _CANRIDR.Bits.ID24
#define CANRIDR_ID25                    _CANRIDR.Bits.ID25
#define CANRIDR_ID26                    _CANRIDR.Bits.ID26
#define CANRIDR_ID27                    _CANRIDR.Bits.ID27
#define CANRIDR_ID28                    _CANRIDR.Bits.ID28
#define CANRIDR_ID                      _CANRIDR.MergedBits.grpID
#define CANRIDR_ID_18                   _CANRIDR.MergedBits.grpID_18

#define CANRIDR_RTR_MASK                1UL
#define CANRIDR_ID0_MASK                2UL
#define CANRIDR_ID1_MASK                4UL
#define CANRIDR_ID2_MASK                8UL
#define CANRIDR_ID3_MASK                16UL
#define CANRIDR_ID4_MASK                32UL
#define CANRIDR_ID5_MASK                64UL
#define CANRIDR_ID6_MASK                128UL
#define CANRIDR_ID7_MASK                256UL
#define CANRIDR_ID8_MASK                512UL
#define CANRIDR_ID9_MASK                1024UL
#define CANRIDR_ID10_MASK               2048UL
#define CANRIDR_ID11_MASK               4096UL
#define CANRIDR_ID12_MASK               8192UL
#define CANRIDR_ID13_MASK               16384UL
#define CANRIDR_ID14_MASK               32768UL
#define CANRIDR_ID15_MASK               65536UL
#define CANRIDR_ID16_MASK               131072UL
#define CANRIDR_ID17_MASK               262144UL
#define CANRIDR_IDE_MASK                524288UL
#define CANRIDR_SRR_MASK                1048576UL
#define CANRIDR_ID18_MASK               2097152UL
#define CANRIDR_ID19_MASK               4194304UL
#define CANRIDR_ID20_MASK               8388608UL
#define CANRIDR_ID21_MASK               16777216UL
#define CANRIDR_ID22_MASK               33554432UL
#define CANRIDR_ID23_MASK               67108864UL
#define CANRIDR_ID24_MASK               134217728UL
#define CANRIDR_ID25_MASK               268435456UL
#define CANRIDR_ID26_MASK               536870912UL
#define CANRIDR_ID27_MASK               1073741824UL
#define CANRIDR_ID28_MASK               2147483648UL
#define CANRIDR_ID_MASK                 524286U
#define CANRIDR_ID_BITNUM               1U
#define CANRIDR_ID_18_MASK              4292870144U
#define CANRIDR_ID_18_BITNUM            21U


/*** CANRDSR0 - MSCAN Receive Data Segment Register 0; 0xFFFF98A4 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR0STR;
extern volatile CANRDSR0STR _CANRDSR0 @0xFFFF98A4;
#define CANRDSR0                        _CANRDSR0.Byte
#define CANRDSR0_DB0                    _CANRDSR0.Bits.DB0
#define CANRDSR0_DB1                    _CANRDSR0.Bits.DB1
#define CANRDSR0_DB2                    _CANRDSR0.Bits.DB2
#define CANRDSR0_DB3                    _CANRDSR0.Bits.DB3
#define CANRDSR0_DB4                    _CANRDSR0.Bits.DB4
#define CANRDSR0_DB5                    _CANRDSR0.Bits.DB5
#define CANRDSR0_DB6                    _CANRDSR0.Bits.DB6
#define CANRDSR0_DB7                    _CANRDSR0.Bits.DB7
/* CANRDSR_ARR: Access 8 CANRDSRx registers in an array */
#define CANRDSR_ARR                     ((volatile byte *) &CANRDSR0)

#define CANRDSR0_DB0_MASK               1U
#define CANRDSR0_DB1_MASK               2U
#define CANRDSR0_DB2_MASK               4U
#define CANRDSR0_DB3_MASK               8U
#define CANRDSR0_DB4_MASK               16U
#define CANRDSR0_DB5_MASK               32U
#define CANRDSR0_DB6_MASK               64U
#define CANRDSR0_DB7_MASK               128U


/*** CANRDSR1 - MSCAN Receive Data Segment Register 1; 0xFFFF98A5 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR1STR;
extern volatile CANRDSR1STR _CANRDSR1 @0xFFFF98A5;
#define CANRDSR1                        _CANRDSR1.Byte
#define CANRDSR1_DB0                    _CANRDSR1.Bits.DB0
#define CANRDSR1_DB1                    _CANRDSR1.Bits.DB1
#define CANRDSR1_DB2                    _CANRDSR1.Bits.DB2
#define CANRDSR1_DB3                    _CANRDSR1.Bits.DB3
#define CANRDSR1_DB4                    _CANRDSR1.Bits.DB4
#define CANRDSR1_DB5                    _CANRDSR1.Bits.DB5
#define CANRDSR1_DB6                    _CANRDSR1.Bits.DB6
#define CANRDSR1_DB7                    _CANRDSR1.Bits.DB7

#define CANRDSR1_DB0_MASK               1U
#define CANRDSR1_DB1_MASK               2U
#define CANRDSR1_DB2_MASK               4U
#define CANRDSR1_DB3_MASK               8U
#define CANRDSR1_DB4_MASK               16U
#define CANRDSR1_DB5_MASK               32U
#define CANRDSR1_DB6_MASK               64U
#define CANRDSR1_DB7_MASK               128U


/*** CANRDSR2 - MSCAN Receive Data Segment Register 2; 0xFFFF98A6 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR2STR;
extern volatile CANRDSR2STR _CANRDSR2 @0xFFFF98A6;
#define CANRDSR2                        _CANRDSR2.Byte
#define CANRDSR2_DB0                    _CANRDSR2.Bits.DB0
#define CANRDSR2_DB1                    _CANRDSR2.Bits.DB1
#define CANRDSR2_DB2                    _CANRDSR2.Bits.DB2
#define CANRDSR2_DB3                    _CANRDSR2.Bits.DB3
#define CANRDSR2_DB4                    _CANRDSR2.Bits.DB4
#define CANRDSR2_DB5                    _CANRDSR2.Bits.DB5
#define CANRDSR2_DB6                    _CANRDSR2.Bits.DB6
#define CANRDSR2_DB7                    _CANRDSR2.Bits.DB7

#define CANRDSR2_DB0_MASK               1U
#define CANRDSR2_DB1_MASK               2U
#define CANRDSR2_DB2_MASK               4U
#define CANRDSR2_DB3_MASK               8U
#define CANRDSR2_DB4_MASK               16U
#define CANRDSR2_DB5_MASK               32U
#define CANRDSR2_DB6_MASK               64U
#define CANRDSR2_DB7_MASK               128U


/*** CANRDSR3 - MSCAN Receive Data Segment Register 3; 0xFFFF98A7 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR3STR;
extern volatile CANRDSR3STR _CANRDSR3 @0xFFFF98A7;
#define CANRDSR3                        _CANRDSR3.Byte
#define CANRDSR3_DB0                    _CANRDSR3.Bits.DB0
#define CANRDSR3_DB1                    _CANRDSR3.Bits.DB1
#define CANRDSR3_DB2                    _CANRDSR3.Bits.DB2
#define CANRDSR3_DB3                    _CANRDSR3.Bits.DB3
#define CANRDSR3_DB4                    _CANRDSR3.Bits.DB4
#define CANRDSR3_DB5                    _CANRDSR3.Bits.DB5
#define CANRDSR3_DB6                    _CANRDSR3.Bits.DB6
#define CANRDSR3_DB7                    _CANRDSR3.Bits.DB7

#define CANRDSR3_DB0_MASK               1U
#define CANRDSR3_DB1_MASK               2U
#define CANRDSR3_DB2_MASK               4U
#define CANRDSR3_DB3_MASK               8U
#define CANRDSR3_DB4_MASK               16U
#define CANRDSR3_DB5_MASK               32U
#define CANRDSR3_DB6_MASK               64U
#define CANRDSR3_DB7_MASK               128U


/*** CANRDSR4 - MSCAN Receive Data Segment Register 4; 0xFFFF98A8 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR4STR;
extern volatile CANRDSR4STR _CANRDSR4 @0xFFFF98A8;
#define CANRDSR4                        _CANRDSR4.Byte
#define CANRDSR4_DB0                    _CANRDSR4.Bits.DB0
#define CANRDSR4_DB1                    _CANRDSR4.Bits.DB1
#define CANRDSR4_DB2                    _CANRDSR4.Bits.DB2
#define CANRDSR4_DB3                    _CANRDSR4.Bits.DB3
#define CANRDSR4_DB4                    _CANRDSR4.Bits.DB4
#define CANRDSR4_DB5                    _CANRDSR4.Bits.DB5
#define CANRDSR4_DB6                    _CANRDSR4.Bits.DB6
#define CANRDSR4_DB7                    _CANRDSR4.Bits.DB7

#define CANRDSR4_DB0_MASK               1U
#define CANRDSR4_DB1_MASK               2U
#define CANRDSR4_DB2_MASK               4U
#define CANRDSR4_DB3_MASK               8U
#define CANRDSR4_DB4_MASK               16U
#define CANRDSR4_DB5_MASK               32U
#define CANRDSR4_DB6_MASK               64U
#define CANRDSR4_DB7_MASK               128U


/*** CANRDSR5 - MSCAN Receive Data Segment Register 5; 0xFFFF98A9 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR5STR;
extern volatile CANRDSR5STR _CANRDSR5 @0xFFFF98A9;
#define CANRDSR5                        _CANRDSR5.Byte
#define CANRDSR5_DB0                    _CANRDSR5.Bits.DB0
#define CANRDSR5_DB1                    _CANRDSR5.Bits.DB1
#define CANRDSR5_DB2                    _CANRDSR5.Bits.DB2
#define CANRDSR5_DB3                    _CANRDSR5.Bits.DB3
#define CANRDSR5_DB4                    _CANRDSR5.Bits.DB4
#define CANRDSR5_DB5                    _CANRDSR5.Bits.DB5
#define CANRDSR5_DB6                    _CANRDSR5.Bits.DB6
#define CANRDSR5_DB7                    _CANRDSR5.Bits.DB7

#define CANRDSR5_DB0_MASK               1U
#define CANRDSR5_DB1_MASK               2U
#define CANRDSR5_DB2_MASK               4U
#define CANRDSR5_DB3_MASK               8U
#define CANRDSR5_DB4_MASK               16U
#define CANRDSR5_DB5_MASK               32U
#define CANRDSR5_DB6_MASK               64U
#define CANRDSR5_DB7_MASK               128U


/*** CANRDSR6 - MSCAN Receive Data Segment Register 6; 0xFFFF98AA ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR6STR;
extern volatile CANRDSR6STR _CANRDSR6 @0xFFFF98AA;
#define CANRDSR6                        _CANRDSR6.Byte
#define CANRDSR6_DB0                    _CANRDSR6.Bits.DB0
#define CANRDSR6_DB1                    _CANRDSR6.Bits.DB1
#define CANRDSR6_DB2                    _CANRDSR6.Bits.DB2
#define CANRDSR6_DB3                    _CANRDSR6.Bits.DB3
#define CANRDSR6_DB4                    _CANRDSR6.Bits.DB4
#define CANRDSR6_DB5                    _CANRDSR6.Bits.DB5
#define CANRDSR6_DB6                    _CANRDSR6.Bits.DB6
#define CANRDSR6_DB7                    _CANRDSR6.Bits.DB7

#define CANRDSR6_DB0_MASK               1U
#define CANRDSR6_DB1_MASK               2U
#define CANRDSR6_DB2_MASK               4U
#define CANRDSR6_DB3_MASK               8U
#define CANRDSR6_DB4_MASK               16U
#define CANRDSR6_DB5_MASK               32U
#define CANRDSR6_DB6_MASK               64U
#define CANRDSR6_DB7_MASK               128U


/*** CANRDSR7 - MSCAN Receive Data Segment Register 7; 0xFFFF98AB ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANRDSR7STR;
extern volatile CANRDSR7STR _CANRDSR7 @0xFFFF98AB;
#define CANRDSR7                        _CANRDSR7.Byte
#define CANRDSR7_DB0                    _CANRDSR7.Bits.DB0
#define CANRDSR7_DB1                    _CANRDSR7.Bits.DB1
#define CANRDSR7_DB2                    _CANRDSR7.Bits.DB2
#define CANRDSR7_DB3                    _CANRDSR7.Bits.DB3
#define CANRDSR7_DB4                    _CANRDSR7.Bits.DB4
#define CANRDSR7_DB5                    _CANRDSR7.Bits.DB5
#define CANRDSR7_DB6                    _CANRDSR7.Bits.DB6
#define CANRDSR7_DB7                    _CANRDSR7.Bits.DB7

#define CANRDSR7_DB0_MASK               1U
#define CANRDSR7_DB1_MASK               2U
#define CANRDSR7_DB2_MASK               4U
#define CANRDSR7_DB3_MASK               8U
#define CANRDSR7_DB4_MASK               16U
#define CANRDSR7_DB5_MASK               32U
#define CANRDSR7_DB6_MASK               64U
#define CANRDSR7_DB7_MASK               128U


/*** CANRDLR - MSCAN Receive Data Length Register; 0xFFFF98AC ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANRDLRSTR;
extern volatile CANRDLRSTR _CANRDLR @0xFFFF98AC;
#define CANRDLR                         _CANRDLR.Byte
#define CANRDLR_DLC0                    _CANRDLR.Bits.DLC0
#define CANRDLR_DLC1                    _CANRDLR.Bits.DLC1
#define CANRDLR_DLC2                    _CANRDLR.Bits.DLC2
#define CANRDLR_DLC3                    _CANRDLR.Bits.DLC3
#define CANRDLR_DLC                     _CANRDLR.MergedBits.grpDLC

#define CANRDLR_DLC0_MASK               1U
#define CANRDLR_DLC1_MASK               2U
#define CANRDLR_DLC2_MASK               4U
#define CANRDLR_DLC3_MASK               8U
#define CANRDLR_DLC_MASK                15U
#define CANRDLR_DLC_BITNUM              0U


/*** CANRTSR - MSCAN Receive Time Stamp Register; 0xFFFF98AE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANRTSRH - MSCAN Receive Time Stamp Register High; 0xFFFF98AE ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANRTSRHSTR;
    #define CANRTSRH                    _CANRTSR.Overlap_STR.CANRTSRHSTR.Byte
    #define CANRTSRH_TSR8               _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR8
    #define CANRTSRH_TSR9               _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR9
    #define CANRTSRH_TSR10              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR10
    #define CANRTSRH_TSR11              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR11
    #define CANRTSRH_TSR12              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR12
    #define CANRTSRH_TSR13              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR13
    #define CANRTSRH_TSR14              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR14
    #define CANRTSRH_TSR15              _CANRTSR.Overlap_STR.CANRTSRHSTR.Bits.TSR15
    
    #define CANRTSRH_TSR8_MASK          1U
    #define CANRTSRH_TSR9_MASK          2U
    #define CANRTSRH_TSR10_MASK         4U
    #define CANRTSRH_TSR11_MASK         8U
    #define CANRTSRH_TSR12_MASK         16U
    #define CANRTSRH_TSR13_MASK         32U
    #define CANRTSRH_TSR14_MASK         64U
    #define CANRTSRH_TSR15_MASK         128U
    

    /*** CANRTSRL - MSCAN Receive Time Stamp Register Low; 0xFFFF98AF ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANRTSRLSTR;
    #define CANRTSRL                    _CANRTSR.Overlap_STR.CANRTSRLSTR.Byte
    #define CANRTSRL_TSR0               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR0
    #define CANRTSRL_TSR1               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR1
    #define CANRTSRL_TSR2               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR2
    #define CANRTSRL_TSR3               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR3
    #define CANRTSRL_TSR4               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR4
    #define CANRTSRL_TSR5               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR5
    #define CANRTSRL_TSR6               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR6
    #define CANRTSRL_TSR7               _CANRTSR.Overlap_STR.CANRTSRLSTR.Bits.TSR7
    
    #define CANRTSRL_TSR0_MASK          1U
    #define CANRTSRL_TSR1_MASK          2U
    #define CANRTSRL_TSR2_MASK          4U
    #define CANRTSRL_TSR3_MASK          8U
    #define CANRTSRL_TSR4_MASK          16U
    #define CANRTSRL_TSR5_MASK          32U
    #define CANRTSRL_TSR6_MASK          64U
    #define CANRTSRL_TSR7_MASK          128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANRTSRSTR;
extern volatile CANRTSRSTR _CANRTSR @0xFFFF98AE;
#define CANRTSR                         _CANRTSR.Word
#define CANRTSR_TSR0                    _CANRTSR.Bits.TSR0
#define CANRTSR_TSR1                    _CANRTSR.Bits.TSR1
#define CANRTSR_TSR2                    _CANRTSR.Bits.TSR2
#define CANRTSR_TSR3                    _CANRTSR.Bits.TSR3
#define CANRTSR_TSR4                    _CANRTSR.Bits.TSR4
#define CANRTSR_TSR5                    _CANRTSR.Bits.TSR5
#define CANRTSR_TSR6                    _CANRTSR.Bits.TSR6
#define CANRTSR_TSR7                    _CANRTSR.Bits.TSR7
#define CANRTSR_TSR8                    _CANRTSR.Bits.TSR8
#define CANRTSR_TSR9                    _CANRTSR.Bits.TSR9
#define CANRTSR_TSR10                   _CANRTSR.Bits.TSR10
#define CANRTSR_TSR11                   _CANRTSR.Bits.TSR11
#define CANRTSR_TSR12                   _CANRTSR.Bits.TSR12
#define CANRTSR_TSR13                   _CANRTSR.Bits.TSR13
#define CANRTSR_TSR14                   _CANRTSR.Bits.TSR14
#define CANRTSR_TSR15                   _CANRTSR.Bits.TSR15

#define CANRTSR_TSR0_MASK               1U
#define CANRTSR_TSR1_MASK               2U
#define CANRTSR_TSR2_MASK               4U
#define CANRTSR_TSR3_MASK               8U
#define CANRTSR_TSR4_MASK               16U
#define CANRTSR_TSR5_MASK               32U
#define CANRTSR_TSR6_MASK               64U
#define CANRTSR_TSR7_MASK               128U
#define CANRTSR_TSR8_MASK               256U
#define CANRTSR_TSR9_MASK               512U
#define CANRTSR_TSR10_MASK              1024U
#define CANRTSR_TSR11_MASK              2048U
#define CANRTSR_TSR12_MASK              4096U
#define CANRTSR_TSR13_MASK              8192U
#define CANRTSR_TSR14_MASK              16384U
#define CANRTSR_TSR15_MASK              32768U


/*** CANTIDR - MSCAN 0 Transmit Identifier Register; 0xFFFF98B0 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** CANTIDR0 - MSCAN 0 Transmit Identifier Register 0; 0xFFFF98B0 ***/
    union {
      byte Byte;
      struct {
        byte ID21        :1;                                       /* Extended format identifier Bit 21 */
        byte ID22        :1;                                       /* Extended format identifier Bit 22 */
        byte ID23        :1;                                       /* Extended format identifier Bit 23 */
        byte ID24        :1;                                       /* Extended format identifier Bit 24 */
        byte ID25        :1;                                       /* Extended format identifier Bit 25 */
        byte ID26        :1;                                       /* Extended format identifier Bit 26 */
        byte ID27        :1;                                       /* Extended format identifier Bit 27 */
        byte ID28        :1;                                       /* Extended format identifier Bit 28 */
      } Bits;
    } CANTIDR0STR;
    #define CANTIDR0                    _CANTIDR.Overlap_STR.CANTIDR0STR.Byte
    #define CANTIDR0_ID21               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID21
    #define CANTIDR0_ID22               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID22
    #define CANTIDR0_ID23               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID23
    #define CANTIDR0_ID24               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID24
    #define CANTIDR0_ID25               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID25
    #define CANTIDR0_ID26               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID26
    #define CANTIDR0_ID27               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID27
    #define CANTIDR0_ID28               _CANTIDR.Overlap_STR.CANTIDR0STR.Bits.ID28
    /* CANTIDR_ARR: Access 4 CANTIDRx registers in an array */
    #define CANTIDR_ARR                 ((volatile byte *) &CANTIDR0)
    
    #define CANTIDR0_ID21_MASK          1U
    #define CANTIDR0_ID22_MASK          2U
    #define CANTIDR0_ID23_MASK          4U
    #define CANTIDR0_ID24_MASK          8U
    #define CANTIDR0_ID25_MASK          16U
    #define CANTIDR0_ID26_MASK          32U
    #define CANTIDR0_ID27_MASK          64U
    #define CANTIDR0_ID28_MASK          128U
    

    /*** CANTIDR1 - MSCAN 0 Transmit Identifier Register 1; 0xFFFF98B1 ***/
    union {
      byte Byte;
      struct {
        byte ID15        :1;                                       /* Extended format identifier Bit 15 */
        byte ID16        :1;                                       /* Extended format identifier Bit 16 */
        byte ID17        :1;                                       /* Extended format identifier Bit 17 */
        byte IDE         :1;                                       /* ID Extended */
        byte SRR         :1;                                       /* Substitute Remote Request */
        byte ID18        :1;                                       /* Extended format identifier Bit 18 */
        byte ID19        :1;                                       /* Extended format identifier Bit 19 */
        byte ID20        :1;                                       /* Extended format identifier Bit 20 */
      } Bits;
      struct {
        byte grpID_15 :3;
        byte     :1;
        byte     :1;
        byte grpID_18 :3;
      } MergedBits;
    } CANTIDR1STR;
    #define CANTIDR1                    _CANTIDR.Overlap_STR.CANTIDR1STR.Byte
    #define CANTIDR1_ID15               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID15
    #define CANTIDR1_ID16               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID16
    #define CANTIDR1_ID17               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID17
    #define CANTIDR1_IDE                _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.IDE
    #define CANTIDR1_SRR                _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.SRR
    #define CANTIDR1_ID18               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID18
    #define CANTIDR1_ID19               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID19
    #define CANTIDR1_ID20               _CANTIDR.Overlap_STR.CANTIDR1STR.Bits.ID20
    #define CANTIDR1_ID_15              _CANTIDR.Overlap_STR.CANTIDR1STR.MergedBits.grpID_15
    #define CANTIDR1_ID_18              _CANTIDR.Overlap_STR.CANTIDR1STR.MergedBits.grpID_18
    #define CANTIDR1_ID                 CANTIDR1_ID_15
    
    #define CANTIDR1_ID15_MASK          1U
    #define CANTIDR1_ID16_MASK          2U
    #define CANTIDR1_ID17_MASK          4U
    #define CANTIDR1_IDE_MASK           8U
    #define CANTIDR1_SRR_MASK           16U
    #define CANTIDR1_ID18_MASK          32U
    #define CANTIDR1_ID19_MASK          64U
    #define CANTIDR1_ID20_MASK          128U
    #define CANTIDR1_ID_15_MASK         7U
    #define CANTIDR1_ID_15_BITNUM       0U
    #define CANTIDR1_ID_18_MASK         224U
    #define CANTIDR1_ID_18_BITNUM       5U
    

    /*** CANTIDR2 - MSCAN 0 Transmit Identifier Register 2; 0xFFFF98B2 ***/
    union {
      byte Byte;
      struct {
        byte ID7         :1;                                       /* Extended format identifier Bit 7 */
        byte ID8         :1;                                       /* Extended format identifier Bit 8 */
        byte ID9         :1;                                       /* Extended format identifier Bit 9 */
        byte ID10        :1;                                       /* Extended format identifier Bit 10 */
        byte ID11        :1;                                       /* Extended format identifier Bit 11 */
        byte ID12        :1;                                       /* Extended format identifier Bit 12 */
        byte ID13        :1;                                       /* Extended format identifier Bit 13 */
        byte ID14        :1;                                       /* Extended format identifier Bit 14 */
      } Bits;
    } CANTIDR2STR;
    #define CANTIDR2                    _CANTIDR.Overlap_STR.CANTIDR2STR.Byte
    #define CANTIDR2_ID7                _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID7
    #define CANTIDR2_ID8                _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID8
    #define CANTIDR2_ID9                _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID9
    #define CANTIDR2_ID10               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID10
    #define CANTIDR2_ID11               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID11
    #define CANTIDR2_ID12               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID12
    #define CANTIDR2_ID13               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID13
    #define CANTIDR2_ID14               _CANTIDR.Overlap_STR.CANTIDR2STR.Bits.ID14
    
    #define CANTIDR2_ID7_MASK           1U
    #define CANTIDR2_ID8_MASK           2U
    #define CANTIDR2_ID9_MASK           4U
    #define CANTIDR2_ID10_MASK          8U
    #define CANTIDR2_ID11_MASK          16U
    #define CANTIDR2_ID12_MASK          32U
    #define CANTIDR2_ID13_MASK          64U
    #define CANTIDR2_ID14_MASK          128U
    

    /*** CANTIDR3 - MSCAN 0 Transmit Identifier Register 3; 0xFFFF98B3 ***/
    union {
      byte Byte;
      struct {
        byte RTR         :1;                                       /* Remote Transmission Request */
        byte ID0         :1;                                       /* Extended format identifier Bit 0 */
        byte ID1         :1;                                       /* Extended format identifier Bit 1 */
        byte ID2         :1;                                       /* Extended format identifier Bit 2 */
        byte ID3         :1;                                       /* Extended format identifier Bit 3 */
        byte ID4         :1;                                       /* Extended format identifier Bit 4 */
        byte ID5         :1;                                       /* Extended format identifier Bit 5 */
        byte ID6         :1;                                       /* Extended format identifier Bit 6 */
      } Bits;
      struct {
        byte     :1;
        byte grpID :7;
      } MergedBits;
    } CANTIDR3STR;
    #define CANTIDR3                    _CANTIDR.Overlap_STR.CANTIDR3STR.Byte
    #define CANTIDR3_RTR                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.RTR
    #define CANTIDR3_ID0                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID0
    #define CANTIDR3_ID1                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID1
    #define CANTIDR3_ID2                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID2
    #define CANTIDR3_ID3                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID3
    #define CANTIDR3_ID4                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID4
    #define CANTIDR3_ID5                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID5
    #define CANTIDR3_ID6                _CANTIDR.Overlap_STR.CANTIDR3STR.Bits.ID6
    #define CANTIDR3_ID                 _CANTIDR.Overlap_STR.CANTIDR3STR.MergedBits.grpID
    
    #define CANTIDR3_RTR_MASK           1U
    #define CANTIDR3_ID0_MASK           2U
    #define CANTIDR3_ID1_MASK           4U
    #define CANTIDR3_ID2_MASK           8U
    #define CANTIDR3_ID3_MASK           16U
    #define CANTIDR3_ID4_MASK           32U
    #define CANTIDR3_ID5_MASK           64U
    #define CANTIDR3_ID6_MASK           128U
    #define CANTIDR3_ID_MASK            254U
    #define CANTIDR3_ID_BITNUM          1U
    
  } Overlap_STR;

  struct {
    dword RTR        :1;                                       /* Remote Transmission Request */
    dword ID0        :1;                                       /* Extended format identifier Bit 0 */
    dword ID1        :1;                                       /* Extended format identifier Bit 1 */
    dword ID2        :1;                                       /* Extended format identifier Bit 2 */
    dword ID3        :1;                                       /* Extended format identifier Bit 3 */
    dword ID4        :1;                                       /* Extended format identifier Bit 4 */
    dword ID5        :1;                                       /* Extended format identifier Bit 5 */
    dword ID6        :1;                                       /* Extended format identifier Bit 6 */
    dword ID7        :1;                                       /* Extended format identifier Bit 7 */
    dword ID8        :1;                                       /* Extended format identifier Bit 8 */
    dword ID9        :1;                                       /* Extended format identifier Bit 9 */
    dword ID10       :1;                                       /* Extended format identifier Bit 10 */
    dword ID11       :1;                                       /* Extended format identifier Bit 11 */
    dword ID12       :1;                                       /* Extended format identifier Bit 12 */
    dword ID13       :1;                                       /* Extended format identifier Bit 13 */
    dword ID14       :1;                                       /* Extended format identifier Bit 14 */
    dword ID15       :1;                                       /* Extended format identifier Bit 15 */
    dword ID16       :1;                                       /* Extended format identifier Bit 16 */
    dword ID17       :1;                                       /* Extended format identifier Bit 17 */
    dword IDE        :1;                                       /* ID Extended */
    dword SRR        :1;                                       /* Substitute Remote Request */
    dword ID18       :1;                                       /* Extended format identifier Bit 18 */
    dword ID19       :1;                                       /* Extended format identifier Bit 19 */
    dword ID20       :1;                                       /* Extended format identifier Bit 20 */
    dword ID21       :1;                                       /* Extended format identifier Bit 21 */
    dword ID22       :1;                                       /* Extended format identifier Bit 22 */
    dword ID23       :1;                                       /* Extended format identifier Bit 23 */
    dword ID24       :1;                                       /* Extended format identifier Bit 24 */
    dword ID25       :1;                                       /* Extended format identifier Bit 25 */
    dword ID26       :1;                                       /* Extended format identifier Bit 26 */
    dword ID27       :1;                                       /* Extended format identifier Bit 27 */
    dword ID28       :1;                                       /* Extended format identifier Bit 28 */
  } Bits;
  struct {
    dword        :1;
    dword grpID  :18;
    dword        :1;
    dword        :1;
    dword grpID_18 :11;
  } MergedBits;
} CANTIDRSTR;
extern volatile CANTIDRSTR _CANTIDR @0xFFFF98B0;
#define CANTIDR                         _CANTIDR.Dword
#define CANTIDR_RTR                     _CANTIDR.Bits.RTR
#define CANTIDR_ID0                     _CANTIDR.Bits.ID0
#define CANTIDR_ID1                     _CANTIDR.Bits.ID1
#define CANTIDR_ID2                     _CANTIDR.Bits.ID2
#define CANTIDR_ID3                     _CANTIDR.Bits.ID3
#define CANTIDR_ID4                     _CANTIDR.Bits.ID4
#define CANTIDR_ID5                     _CANTIDR.Bits.ID5
#define CANTIDR_ID6                     _CANTIDR.Bits.ID6
#define CANTIDR_ID7                     _CANTIDR.Bits.ID7
#define CANTIDR_ID8                     _CANTIDR.Bits.ID8
#define CANTIDR_ID9                     _CANTIDR.Bits.ID9
#define CANTIDR_ID10                    _CANTIDR.Bits.ID10
#define CANTIDR_ID11                    _CANTIDR.Bits.ID11
#define CANTIDR_ID12                    _CANTIDR.Bits.ID12
#define CANTIDR_ID13                    _CANTIDR.Bits.ID13
#define CANTIDR_ID14                    _CANTIDR.Bits.ID14
#define CANTIDR_ID15                    _CANTIDR.Bits.ID15
#define CANTIDR_ID16                    _CANTIDR.Bits.ID16
#define CANTIDR_ID17                    _CANTIDR.Bits.ID17
#define CANTIDR_IDE                     _CANTIDR.Bits.IDE
#define CANTIDR_SRR                     _CANTIDR.Bits.SRR
#define CANTIDR_ID18                    _CANTIDR.Bits.ID18
#define CANTIDR_ID19                    _CANTIDR.Bits.ID19
#define CANTIDR_ID20                    _CANTIDR.Bits.ID20
#define CANTIDR_ID21                    _CANTIDR.Bits.ID21
#define CANTIDR_ID22                    _CANTIDR.Bits.ID22
#define CANTIDR_ID23                    _CANTIDR.Bits.ID23
#define CANTIDR_ID24                    _CANTIDR.Bits.ID24
#define CANTIDR_ID25                    _CANTIDR.Bits.ID25
#define CANTIDR_ID26                    _CANTIDR.Bits.ID26
#define CANTIDR_ID27                    _CANTIDR.Bits.ID27
#define CANTIDR_ID28                    _CANTIDR.Bits.ID28
#define CANTIDR_ID                      _CANTIDR.MergedBits.grpID
#define CANTIDR_ID_18                   _CANTIDR.MergedBits.grpID_18

#define CANTIDR_RTR_MASK                1UL
#define CANTIDR_ID0_MASK                2UL
#define CANTIDR_ID1_MASK                4UL
#define CANTIDR_ID2_MASK                8UL
#define CANTIDR_ID3_MASK                16UL
#define CANTIDR_ID4_MASK                32UL
#define CANTIDR_ID5_MASK                64UL
#define CANTIDR_ID6_MASK                128UL
#define CANTIDR_ID7_MASK                256UL
#define CANTIDR_ID8_MASK                512UL
#define CANTIDR_ID9_MASK                1024UL
#define CANTIDR_ID10_MASK               2048UL
#define CANTIDR_ID11_MASK               4096UL
#define CANTIDR_ID12_MASK               8192UL
#define CANTIDR_ID13_MASK               16384UL
#define CANTIDR_ID14_MASK               32768UL
#define CANTIDR_ID15_MASK               65536UL
#define CANTIDR_ID16_MASK               131072UL
#define CANTIDR_ID17_MASK               262144UL
#define CANTIDR_IDE_MASK                524288UL
#define CANTIDR_SRR_MASK                1048576UL
#define CANTIDR_ID18_MASK               2097152UL
#define CANTIDR_ID19_MASK               4194304UL
#define CANTIDR_ID20_MASK               8388608UL
#define CANTIDR_ID21_MASK               16777216UL
#define CANTIDR_ID22_MASK               33554432UL
#define CANTIDR_ID23_MASK               67108864UL
#define CANTIDR_ID24_MASK               134217728UL
#define CANTIDR_ID25_MASK               268435456UL
#define CANTIDR_ID26_MASK               536870912UL
#define CANTIDR_ID27_MASK               1073741824UL
#define CANTIDR_ID28_MASK               2147483648UL
#define CANTIDR_ID_MASK                 524286U
#define CANTIDR_ID_BITNUM               1U
#define CANTIDR_ID_18_MASK              4292870144U
#define CANTIDR_ID_18_BITNUM            21U


/*** CANTDSR0 - MSCAN Transmit Data Segment Register 0; 0xFFFF98B4 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR0STR;
extern volatile CANTDSR0STR _CANTDSR0 @0xFFFF98B4;
#define CANTDSR0                        _CANTDSR0.Byte
#define CANTDSR0_DB0                    _CANTDSR0.Bits.DB0
#define CANTDSR0_DB1                    _CANTDSR0.Bits.DB1
#define CANTDSR0_DB2                    _CANTDSR0.Bits.DB2
#define CANTDSR0_DB3                    _CANTDSR0.Bits.DB3
#define CANTDSR0_DB4                    _CANTDSR0.Bits.DB4
#define CANTDSR0_DB5                    _CANTDSR0.Bits.DB5
#define CANTDSR0_DB6                    _CANTDSR0.Bits.DB6
#define CANTDSR0_DB7                    _CANTDSR0.Bits.DB7
/* CANTDSR_ARR: Access 8 CANTDSRx registers in an array */
#define CANTDSR_ARR                     ((volatile byte *) &CANTDSR0)

#define CANTDSR0_DB0_MASK               1U
#define CANTDSR0_DB1_MASK               2U
#define CANTDSR0_DB2_MASK               4U
#define CANTDSR0_DB3_MASK               8U
#define CANTDSR0_DB4_MASK               16U
#define CANTDSR0_DB5_MASK               32U
#define CANTDSR0_DB6_MASK               64U
#define CANTDSR0_DB7_MASK               128U


/*** CANTDSR1 - MSCAN Transmit Data Segment Register 1; 0xFFFF98B5 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR1STR;
extern volatile CANTDSR1STR _CANTDSR1 @0xFFFF98B5;
#define CANTDSR1                        _CANTDSR1.Byte
#define CANTDSR1_DB0                    _CANTDSR1.Bits.DB0
#define CANTDSR1_DB1                    _CANTDSR1.Bits.DB1
#define CANTDSR1_DB2                    _CANTDSR1.Bits.DB2
#define CANTDSR1_DB3                    _CANTDSR1.Bits.DB3
#define CANTDSR1_DB4                    _CANTDSR1.Bits.DB4
#define CANTDSR1_DB5                    _CANTDSR1.Bits.DB5
#define CANTDSR1_DB6                    _CANTDSR1.Bits.DB6
#define CANTDSR1_DB7                    _CANTDSR1.Bits.DB7

#define CANTDSR1_DB0_MASK               1U
#define CANTDSR1_DB1_MASK               2U
#define CANTDSR1_DB2_MASK               4U
#define CANTDSR1_DB3_MASK               8U
#define CANTDSR1_DB4_MASK               16U
#define CANTDSR1_DB5_MASK               32U
#define CANTDSR1_DB6_MASK               64U
#define CANTDSR1_DB7_MASK               128U


/*** CANTDSR2 - MSCAN Transmit Data Segment Register 2; 0xFFFF98B6 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR2STR;
extern volatile CANTDSR2STR _CANTDSR2 @0xFFFF98B6;
#define CANTDSR2                        _CANTDSR2.Byte
#define CANTDSR2_DB0                    _CANTDSR2.Bits.DB0
#define CANTDSR2_DB1                    _CANTDSR2.Bits.DB1
#define CANTDSR2_DB2                    _CANTDSR2.Bits.DB2
#define CANTDSR2_DB3                    _CANTDSR2.Bits.DB3
#define CANTDSR2_DB4                    _CANTDSR2.Bits.DB4
#define CANTDSR2_DB5                    _CANTDSR2.Bits.DB5
#define CANTDSR2_DB6                    _CANTDSR2.Bits.DB6
#define CANTDSR2_DB7                    _CANTDSR2.Bits.DB7

#define CANTDSR2_DB0_MASK               1U
#define CANTDSR2_DB1_MASK               2U
#define CANTDSR2_DB2_MASK               4U
#define CANTDSR2_DB3_MASK               8U
#define CANTDSR2_DB4_MASK               16U
#define CANTDSR2_DB5_MASK               32U
#define CANTDSR2_DB6_MASK               64U
#define CANTDSR2_DB7_MASK               128U


/*** CANTDSR3 - MSCAN Transmit Data Segment Register 3; 0xFFFF98B7 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR3STR;
extern volatile CANTDSR3STR _CANTDSR3 @0xFFFF98B7;
#define CANTDSR3                        _CANTDSR3.Byte
#define CANTDSR3_DB0                    _CANTDSR3.Bits.DB0
#define CANTDSR3_DB1                    _CANTDSR3.Bits.DB1
#define CANTDSR3_DB2                    _CANTDSR3.Bits.DB2
#define CANTDSR3_DB3                    _CANTDSR3.Bits.DB3
#define CANTDSR3_DB4                    _CANTDSR3.Bits.DB4
#define CANTDSR3_DB5                    _CANTDSR3.Bits.DB5
#define CANTDSR3_DB6                    _CANTDSR3.Bits.DB6
#define CANTDSR3_DB7                    _CANTDSR3.Bits.DB7

#define CANTDSR3_DB0_MASK               1U
#define CANTDSR3_DB1_MASK               2U
#define CANTDSR3_DB2_MASK               4U
#define CANTDSR3_DB3_MASK               8U
#define CANTDSR3_DB4_MASK               16U
#define CANTDSR3_DB5_MASK               32U
#define CANTDSR3_DB6_MASK               64U
#define CANTDSR3_DB7_MASK               128U


/*** CANTDSR4 - MSCAN Transmit Data Segment Register 4; 0xFFFF98B8 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR4STR;
extern volatile CANTDSR4STR _CANTDSR4 @0xFFFF98B8;
#define CANTDSR4                        _CANTDSR4.Byte
#define CANTDSR4_DB0                    _CANTDSR4.Bits.DB0
#define CANTDSR4_DB1                    _CANTDSR4.Bits.DB1
#define CANTDSR4_DB2                    _CANTDSR4.Bits.DB2
#define CANTDSR4_DB3                    _CANTDSR4.Bits.DB3
#define CANTDSR4_DB4                    _CANTDSR4.Bits.DB4
#define CANTDSR4_DB5                    _CANTDSR4.Bits.DB5
#define CANTDSR4_DB6                    _CANTDSR4.Bits.DB6
#define CANTDSR4_DB7                    _CANTDSR4.Bits.DB7

#define CANTDSR4_DB0_MASK               1U
#define CANTDSR4_DB1_MASK               2U
#define CANTDSR4_DB2_MASK               4U
#define CANTDSR4_DB3_MASK               8U
#define CANTDSR4_DB4_MASK               16U
#define CANTDSR4_DB5_MASK               32U
#define CANTDSR4_DB6_MASK               64U
#define CANTDSR4_DB7_MASK               128U


/*** CANTDSR5 - MSCAN Transmit Data Segment Register 5; 0xFFFF98B9 ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR5STR;
extern volatile CANTDSR5STR _CANTDSR5 @0xFFFF98B9;
#define CANTDSR5                        _CANTDSR5.Byte
#define CANTDSR5_DB0                    _CANTDSR5.Bits.DB0
#define CANTDSR5_DB1                    _CANTDSR5.Bits.DB1
#define CANTDSR5_DB2                    _CANTDSR5.Bits.DB2
#define CANTDSR5_DB3                    _CANTDSR5.Bits.DB3
#define CANTDSR5_DB4                    _CANTDSR5.Bits.DB4
#define CANTDSR5_DB5                    _CANTDSR5.Bits.DB5
#define CANTDSR5_DB6                    _CANTDSR5.Bits.DB6
#define CANTDSR5_DB7                    _CANTDSR5.Bits.DB7

#define CANTDSR5_DB0_MASK               1U
#define CANTDSR5_DB1_MASK               2U
#define CANTDSR5_DB2_MASK               4U
#define CANTDSR5_DB3_MASK               8U
#define CANTDSR5_DB4_MASK               16U
#define CANTDSR5_DB5_MASK               32U
#define CANTDSR5_DB6_MASK               64U
#define CANTDSR5_DB7_MASK               128U


/*** CANTDSR6 - MSCAN Transmit Data Segment Register 6; 0xFFFF98BA ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR6STR;
extern volatile CANTDSR6STR _CANTDSR6 @0xFFFF98BA;
#define CANTDSR6                        _CANTDSR6.Byte
#define CANTDSR6_DB0                    _CANTDSR6.Bits.DB0
#define CANTDSR6_DB1                    _CANTDSR6.Bits.DB1
#define CANTDSR6_DB2                    _CANTDSR6.Bits.DB2
#define CANTDSR6_DB3                    _CANTDSR6.Bits.DB3
#define CANTDSR6_DB4                    _CANTDSR6.Bits.DB4
#define CANTDSR6_DB5                    _CANTDSR6.Bits.DB5
#define CANTDSR6_DB6                    _CANTDSR6.Bits.DB6
#define CANTDSR6_DB7                    _CANTDSR6.Bits.DB7

#define CANTDSR6_DB0_MASK               1U
#define CANTDSR6_DB1_MASK               2U
#define CANTDSR6_DB2_MASK               4U
#define CANTDSR6_DB3_MASK               8U
#define CANTDSR6_DB4_MASK               16U
#define CANTDSR6_DB5_MASK               32U
#define CANTDSR6_DB6_MASK               64U
#define CANTDSR6_DB7_MASK               128U


/*** CANTDSR7 - MSCAN Transmit Data Segment Register 7; 0xFFFF98BB ***/
typedef union {
  byte Byte;
  struct {
    byte DB0         :1;                                       /* Data Bit 0 */
    byte DB1         :1;                                       /* Data Bit 1 */
    byte DB2         :1;                                       /* Data Bit 2 */
    byte DB3         :1;                                       /* Data Bit 3 */
    byte DB4         :1;                                       /* Data Bit 4 */
    byte DB5         :1;                                       /* Data Bit 5 */
    byte DB6         :1;                                       /* Data Bit 6 */
    byte DB7         :1;                                       /* Data Bit 7 */
  } Bits;
} CANTDSR7STR;
extern volatile CANTDSR7STR _CANTDSR7 @0xFFFF98BB;
#define CANTDSR7                        _CANTDSR7.Byte
#define CANTDSR7_DB0                    _CANTDSR7.Bits.DB0
#define CANTDSR7_DB1                    _CANTDSR7.Bits.DB1
#define CANTDSR7_DB2                    _CANTDSR7.Bits.DB2
#define CANTDSR7_DB3                    _CANTDSR7.Bits.DB3
#define CANTDSR7_DB4                    _CANTDSR7.Bits.DB4
#define CANTDSR7_DB5                    _CANTDSR7.Bits.DB5
#define CANTDSR7_DB6                    _CANTDSR7.Bits.DB6
#define CANTDSR7_DB7                    _CANTDSR7.Bits.DB7

#define CANTDSR7_DB0_MASK               1U
#define CANTDSR7_DB1_MASK               2U
#define CANTDSR7_DB2_MASK               4U
#define CANTDSR7_DB3_MASK               8U
#define CANTDSR7_DB4_MASK               16U
#define CANTDSR7_DB5_MASK               32U
#define CANTDSR7_DB6_MASK               64U
#define CANTDSR7_DB7_MASK               128U


/*** CANTDLR - MSCAN Transmit Data Length Register; 0xFFFF98BC ***/
typedef union {
  byte Byte;
  struct {
    byte DLC0        :1;                                       /* Data Length Code Bit 0 */
    byte DLC1        :1;                                       /* Data Length Code Bit 1 */
    byte DLC2        :1;                                       /* Data Length Code Bit 2 */
    byte DLC3        :1;                                       /* Data Length Code Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDLC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CANTDLRSTR;
extern volatile CANTDLRSTR _CANTDLR @0xFFFF98BC;
#define CANTDLR                         _CANTDLR.Byte
#define CANTDLR_DLC0                    _CANTDLR.Bits.DLC0
#define CANTDLR_DLC1                    _CANTDLR.Bits.DLC1
#define CANTDLR_DLC2                    _CANTDLR.Bits.DLC2
#define CANTDLR_DLC3                    _CANTDLR.Bits.DLC3
#define CANTDLR_DLC                     _CANTDLR.MergedBits.grpDLC

#define CANTDLR_DLC0_MASK               1U
#define CANTDLR_DLC1_MASK               2U
#define CANTDLR_DLC2_MASK               4U
#define CANTDLR_DLC3_MASK               8U
#define CANTDLR_DLC_MASK                15U
#define CANTDLR_DLC_BITNUM              0U


/*** CANTTBPR - MSCAN Transmit Buffer Priority; 0xFFFF98BD ***/
typedef union {
  byte Byte;
  struct {
    byte PRIO0       :1;                                       /* Transmit Buffer Priority Bit 0 */
    byte PRIO1       :1;                                       /* Transmit Buffer Priority Bit 1 */
    byte PRIO2       :1;                                       /* Transmit Buffer Priority Bit 2 */
    byte PRIO3       :1;                                       /* Transmit Buffer Priority Bit 3 */
    byte PRIO4       :1;                                       /* Transmit Buffer Priority Bit 4 */
    byte PRIO5       :1;                                       /* Transmit Buffer Priority Bit 5 */
    byte PRIO6       :1;                                       /* Transmit Buffer Priority Bit 6 */
    byte PRIO7       :1;                                       /* Transmit Buffer Priority Bit 7 */
  } Bits;
} CANTTBPRSTR;
extern volatile CANTTBPRSTR _CANTTBPR @0xFFFF98BD;
#define CANTTBPR                        _CANTTBPR.Byte
#define CANTTBPR_PRIO0                  _CANTTBPR.Bits.PRIO0
#define CANTTBPR_PRIO1                  _CANTTBPR.Bits.PRIO1
#define CANTTBPR_PRIO2                  _CANTTBPR.Bits.PRIO2
#define CANTTBPR_PRIO3                  _CANTTBPR.Bits.PRIO3
#define CANTTBPR_PRIO4                  _CANTTBPR.Bits.PRIO4
#define CANTTBPR_PRIO5                  _CANTTBPR.Bits.PRIO5
#define CANTTBPR_PRIO6                  _CANTTBPR.Bits.PRIO6
#define CANTTBPR_PRIO7                  _CANTTBPR.Bits.PRIO7

#define CANTTBPR_PRIO0_MASK             1U
#define CANTTBPR_PRIO1_MASK             2U
#define CANTTBPR_PRIO2_MASK             4U
#define CANTTBPR_PRIO3_MASK             8U
#define CANTTBPR_PRIO4_MASK             16U
#define CANTTBPR_PRIO5_MASK             32U
#define CANTTBPR_PRIO6_MASK             64U
#define CANTTBPR_PRIO7_MASK             128U


/*** CANTTSR - MSCAN Transmit Time Stamp Register; 0xFFFF98BE ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CANTTSRH - MSCAN Transmit Time Stamp Register High; 0xFFFF98BE ***/
    union {
      byte Byte;
      struct {
        byte TSR8        :1;                                       /* Time Stamp Bit 8 */
        byte TSR9        :1;                                       /* Time Stamp Bit 9 */
        byte TSR10       :1;                                       /* Time Stamp Bit 10 */
        byte TSR11       :1;                                       /* Time Stamp Bit 11 */
        byte TSR12       :1;                                       /* Time Stamp Bit 12 */
        byte TSR13       :1;                                       /* Time Stamp Bit 13 */
        byte TSR14       :1;                                       /* Time Stamp Bit 14 */
        byte TSR15       :1;                                       /* Time Stamp Bit 15 */
      } Bits;
    } CANTTSRHSTR;
    #define CANTTSRH                    _CANTTSR.Overlap_STR.CANTTSRHSTR.Byte
    #define CANTTSRH_TSR8               _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR8
    #define CANTTSRH_TSR9               _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR9
    #define CANTTSRH_TSR10              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR10
    #define CANTTSRH_TSR11              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR11
    #define CANTTSRH_TSR12              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR12
    #define CANTTSRH_TSR13              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR13
    #define CANTTSRH_TSR14              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR14
    #define CANTTSRH_TSR15              _CANTTSR.Overlap_STR.CANTTSRHSTR.Bits.TSR15
    
    #define CANTTSRH_TSR8_MASK          1U
    #define CANTTSRH_TSR9_MASK          2U
    #define CANTTSRH_TSR10_MASK         4U
    #define CANTTSRH_TSR11_MASK         8U
    #define CANTTSRH_TSR12_MASK         16U
    #define CANTTSRH_TSR13_MASK         32U
    #define CANTTSRH_TSR14_MASK         64U
    #define CANTTSRH_TSR15_MASK         128U
    

    /*** CANTTSRL - MSCAN Transmit Time Stamp Register Low; 0xFFFF98BF ***/
    union {
      byte Byte;
      struct {
        byte TSR0        :1;                                       /* Time Stamp Bit 0 */
        byte TSR1        :1;                                       /* Time Stamp Bit 1 */
        byte TSR2        :1;                                       /* Time Stamp Bit 2 */
        byte TSR3        :1;                                       /* Time Stamp Bit 3 */
        byte TSR4        :1;                                       /* Time Stamp Bit 4 */
        byte TSR5        :1;                                       /* Time Stamp Bit 5 */
        byte TSR6        :1;                                       /* Time Stamp Bit 6 */
        byte TSR7        :1;                                       /* Time Stamp Bit 7 */
      } Bits;
    } CANTTSRLSTR;
    #define CANTTSRL                    _CANTTSR.Overlap_STR.CANTTSRLSTR.Byte
    #define CANTTSRL_TSR0               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR0
    #define CANTTSRL_TSR1               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR1
    #define CANTTSRL_TSR2               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR2
    #define CANTTSRL_TSR3               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR3
    #define CANTTSRL_TSR4               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR4
    #define CANTTSRL_TSR5               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR5
    #define CANTTSRL_TSR6               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR6
    #define CANTTSRL_TSR7               _CANTTSR.Overlap_STR.CANTTSRLSTR.Bits.TSR7
    
    #define CANTTSRL_TSR0_MASK          1U
    #define CANTTSRL_TSR1_MASK          2U
    #define CANTTSRL_TSR2_MASK          4U
    #define CANTTSRL_TSR3_MASK          8U
    #define CANTTSRL_TSR4_MASK          16U
    #define CANTTSRL_TSR5_MASK          32U
    #define CANTTSRL_TSR6_MASK          64U
    #define CANTTSRL_TSR7_MASK          128U
    
  } Overlap_STR;

  struct {
    word TSR0        :1;                                       /* Time Stamp Bit 0 */
    word TSR1        :1;                                       /* Time Stamp Bit 1 */
    word TSR2        :1;                                       /* Time Stamp Bit 2 */
    word TSR3        :1;                                       /* Time Stamp Bit 3 */
    word TSR4        :1;                                       /* Time Stamp Bit 4 */
    word TSR5        :1;                                       /* Time Stamp Bit 5 */
    word TSR6        :1;                                       /* Time Stamp Bit 6 */
    word TSR7        :1;                                       /* Time Stamp Bit 7 */
    word TSR8        :1;                                       /* Time Stamp Bit 8 */
    word TSR9        :1;                                       /* Time Stamp Bit 9 */
    word TSR10       :1;                                       /* Time Stamp Bit 10 */
    word TSR11       :1;                                       /* Time Stamp Bit 11 */
    word TSR12       :1;                                       /* Time Stamp Bit 12 */
    word TSR13       :1;                                       /* Time Stamp Bit 13 */
    word TSR14       :1;                                       /* Time Stamp Bit 14 */
    word TSR15       :1;                                       /* Time Stamp Bit 15 */
  } Bits;
} CANTTSRSTR;
extern volatile CANTTSRSTR _CANTTSR @0xFFFF98BE;
#define CANTTSR                         _CANTTSR.Word
#define CANTTSR_TSR0                    _CANTTSR.Bits.TSR0
#define CANTTSR_TSR1                    _CANTTSR.Bits.TSR1
#define CANTTSR_TSR2                    _CANTTSR.Bits.TSR2
#define CANTTSR_TSR3                    _CANTTSR.Bits.TSR3
#define CANTTSR_TSR4                    _CANTTSR.Bits.TSR4
#define CANTTSR_TSR5                    _CANTTSR.Bits.TSR5
#define CANTTSR_TSR6                    _CANTTSR.Bits.TSR6
#define CANTTSR_TSR7                    _CANTTSR.Bits.TSR7
#define CANTTSR_TSR8                    _CANTTSR.Bits.TSR8
#define CANTTSR_TSR9                    _CANTTSR.Bits.TSR9
#define CANTTSR_TSR10                   _CANTTSR.Bits.TSR10
#define CANTTSR_TSR11                   _CANTTSR.Bits.TSR11
#define CANTTSR_TSR12                   _CANTTSR.Bits.TSR12
#define CANTTSR_TSR13                   _CANTTSR.Bits.TSR13
#define CANTTSR_TSR14                   _CANTTSR.Bits.TSR14
#define CANTTSR_TSR15                   _CANTTSR.Bits.TSR15

#define CANTTSR_TSR0_MASK               1U
#define CANTTSR_TSR1_MASK               2U
#define CANTTSR_TSR2_MASK               4U
#define CANTTSR_TSR3_MASK               8U
#define CANTTSR_TSR4_MASK               16U
#define CANTTSR_TSR5_MASK               32U
#define CANTTSR_TSR6_MASK               64U
#define CANTTSR_TSR7_MASK               128U
#define CANTTSR_TSR8_MASK               256U
#define CANTTSR_TSR9_MASK               512U
#define CANTTSR_TSR10_MASK              1024U
#define CANTTSR_TSR11_MASK              2048U
#define CANTTSR_TSR12_MASK              4096U
#define CANTTSR_TSR13_MASK              8192U
#define CANTTSR_TSR14_MASK              16384U
#define CANTTSR_TSR15_MASK              32768U


/*** CRCH - CRC High Register; 0xFFFF98C0 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* High byte of CRC register ,bit 8 */
    byte BIT9        :1;                                       /* High byte of CRC register ,bit 9 */
    byte BIT10       :1;                                       /* High byte of CRC register ,bit 10 */
    byte BIT11       :1;                                       /* High byte of CRC register ,bit 11 */
    byte BIT12       :1;                                       /* High byte of CRC register ,bit 12 */
    byte BIT13       :1;                                       /* High byte of CRC register ,bit 13 */
    byte BIT14       :1;                                       /* High byte of CRC register ,bit 14 */
    byte BIT15       :1;                                       /* High byte of CRC register ,bit 15 */
  } Bits;
} CRCHSTR;
extern volatile CRCHSTR _CRCH @0xFFFF98C0;
#define CRCH                            _CRCH.Byte
#define CRCH_BIT8                       _CRCH.Bits.BIT8
#define CRCH_BIT9                       _CRCH.Bits.BIT9
#define CRCH_BIT10                      _CRCH.Bits.BIT10
#define CRCH_BIT11                      _CRCH.Bits.BIT11
#define CRCH_BIT12                      _CRCH.Bits.BIT12
#define CRCH_BIT13                      _CRCH.Bits.BIT13
#define CRCH_BIT14                      _CRCH.Bits.BIT14
#define CRCH_BIT15                      _CRCH.Bits.BIT15

#define CRCH_BIT8_MASK                  1U
#define CRCH_BIT9_MASK                  2U
#define CRCH_BIT10_MASK                 4U
#define CRCH_BIT11_MASK                 8U
#define CRCH_BIT12_MASK                 16U
#define CRCH_BIT13_MASK                 32U
#define CRCH_BIT14_MASK                 64U
#define CRCH_BIT15_MASK                 128U


/*** CRCL - CRC Low Register; 0xFFFF98C1 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Low byte of CRC register, bit 0 */
    byte BIT1        :1;                                       /* Low byte of CRC register, bit 1 */
    byte BIT2        :1;                                       /* Low byte of CRC register, bit 2 */
    byte BIT3        :1;                                       /* Low byte of CRC register, bit 3 */
    byte BIT4        :1;                                       /* Low byte of CRC register, bit 4 */
    byte BIT5        :1;                                       /* Low byte of CRC register, bit 5 */
    byte BIT6        :1;                                       /* Low byte of CRC register, bit 6 */
    byte BIT7        :1;                                       /* Low byte of CRC register, bit 7 */
  } Bits;
} CRCLSTR;
extern volatile CRCLSTR _CRCL @0xFFFF98C1;
#define CRCL                            _CRCL.Byte
#define CRCL_BIT0                       _CRCL.Bits.BIT0
#define CRCL_BIT1                       _CRCL.Bits.BIT1
#define CRCL_BIT2                       _CRCL.Bits.BIT2
#define CRCL_BIT3                       _CRCL.Bits.BIT3
#define CRCL_BIT4                       _CRCL.Bits.BIT4
#define CRCL_BIT5                       _CRCL.Bits.BIT5
#define CRCL_BIT6                       _CRCL.Bits.BIT6
#define CRCL_BIT7                       _CRCL.Bits.BIT7

#define CRCL_BIT0_MASK                  1U
#define CRCL_BIT1_MASK                  2U
#define CRCL_BIT2_MASK                  4U
#define CRCL_BIT3_MASK                  8U
#define CRCL_BIT4_MASK                  16U
#define CRCL_BIT5_MASK                  32U
#define CRCL_BIT6_MASK                  64U
#define CRCL_BIT7_MASK                  128U


/*** CRCL0 - CRC Low Register 0; 0xFFFF98C4 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Low byte of CRC register, bit 0 */
    byte BIT1        :1;                                       /* Low byte of CRC register, bit 1 */
    byte BIT2        :1;                                       /* Low byte of CRC register, bit 2 */
    byte BIT3        :1;                                       /* Low byte of CRC register, bit 3 */
    byte BIT4        :1;                                       /* Low byte of CRC register, bit 4 */
    byte BIT5        :1;                                       /* Low byte of CRC register, bit 5 */
    byte BIT6        :1;                                       /* Low byte of CRC register, bit 6 */
    byte BIT7        :1;                                       /* Low byte of CRC register, bit 7 */
  } Bits;
} CRCL0STR;
extern volatile CRCL0STR _CRCL0 @0xFFFF98C4;
#define CRCL0                           _CRCL0.Byte
#define CRCL0_BIT0                      _CRCL0.Bits.BIT0
#define CRCL0_BIT1                      _CRCL0.Bits.BIT1
#define CRCL0_BIT2                      _CRCL0.Bits.BIT2
#define CRCL0_BIT3                      _CRCL0.Bits.BIT3
#define CRCL0_BIT4                      _CRCL0.Bits.BIT4
#define CRCL0_BIT5                      _CRCL0.Bits.BIT5
#define CRCL0_BIT6                      _CRCL0.Bits.BIT6
#define CRCL0_BIT7                      _CRCL0.Bits.BIT7
/* CRCL_ARR: Access 4 CRCLx registers in an array */
#define CRCL_ARR                        ((volatile byte *) &CRCL0)

#define CRCL0_BIT0_MASK                 1U
#define CRCL0_BIT1_MASK                 2U
#define CRCL0_BIT2_MASK                 4U
#define CRCL0_BIT3_MASK                 8U
#define CRCL0_BIT4_MASK                 16U
#define CRCL0_BIT5_MASK                 32U
#define CRCL0_BIT6_MASK                 64U
#define CRCL0_BIT7_MASK                 128U


/*** CRCL1 - CRC Low Register 1; 0xFFFF98C5 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Low byte of CRC register, bit 0 */
    byte BIT1        :1;                                       /* Low byte of CRC register, bit 1 */
    byte BIT2        :1;                                       /* Low byte of CRC register, bit 2 */
    byte BIT3        :1;                                       /* Low byte of CRC register, bit 3 */
    byte BIT4        :1;                                       /* Low byte of CRC register, bit 4 */
    byte BIT5        :1;                                       /* Low byte of CRC register, bit 5 */
    byte BIT6        :1;                                       /* Low byte of CRC register, bit 6 */
    byte BIT7        :1;                                       /* Low byte of CRC register, bit 7 */
  } Bits;
} CRCL1STR;
extern volatile CRCL1STR _CRCL1 @0xFFFF98C5;
#define CRCL1                           _CRCL1.Byte
#define CRCL1_BIT0                      _CRCL1.Bits.BIT0
#define CRCL1_BIT1                      _CRCL1.Bits.BIT1
#define CRCL1_BIT2                      _CRCL1.Bits.BIT2
#define CRCL1_BIT3                      _CRCL1.Bits.BIT3
#define CRCL1_BIT4                      _CRCL1.Bits.BIT4
#define CRCL1_BIT5                      _CRCL1.Bits.BIT5
#define CRCL1_BIT6                      _CRCL1.Bits.BIT6
#define CRCL1_BIT7                      _CRCL1.Bits.BIT7

#define CRCL1_BIT0_MASK                 1U
#define CRCL1_BIT1_MASK                 2U
#define CRCL1_BIT2_MASK                 4U
#define CRCL1_BIT3_MASK                 8U
#define CRCL1_BIT4_MASK                 16U
#define CRCL1_BIT5_MASK                 32U
#define CRCL1_BIT6_MASK                 64U
#define CRCL1_BIT7_MASK                 128U


/*** CRCL2 - CRC Low Register 2; 0xFFFF98C6 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Low byte of CRC register, bit 0 */
    byte BIT1        :1;                                       /* Low byte of CRC register, bit 1 */
    byte BIT2        :1;                                       /* Low byte of CRC register, bit 2 */
    byte BIT3        :1;                                       /* Low byte of CRC register, bit 3 */
    byte BIT4        :1;                                       /* Low byte of CRC register, bit 4 */
    byte BIT5        :1;                                       /* Low byte of CRC register, bit 5 */
    byte BIT6        :1;                                       /* Low byte of CRC register, bit 6 */
    byte BIT7        :1;                                       /* Low byte of CRC register, bit 7 */
  } Bits;
} CRCL2STR;
extern volatile CRCL2STR _CRCL2 @0xFFFF98C6;
#define CRCL2                           _CRCL2.Byte
#define CRCL2_BIT0                      _CRCL2.Bits.BIT0
#define CRCL2_BIT1                      _CRCL2.Bits.BIT1
#define CRCL2_BIT2                      _CRCL2.Bits.BIT2
#define CRCL2_BIT3                      _CRCL2.Bits.BIT3
#define CRCL2_BIT4                      _CRCL2.Bits.BIT4
#define CRCL2_BIT5                      _CRCL2.Bits.BIT5
#define CRCL2_BIT6                      _CRCL2.Bits.BIT6
#define CRCL2_BIT7                      _CRCL2.Bits.BIT7

#define CRCL2_BIT0_MASK                 1U
#define CRCL2_BIT1_MASK                 2U
#define CRCL2_BIT2_MASK                 4U
#define CRCL2_BIT3_MASK                 8U
#define CRCL2_BIT4_MASK                 16U
#define CRCL2_BIT5_MASK                 32U
#define CRCL2_BIT6_MASK                 64U
#define CRCL2_BIT7_MASK                 128U


/*** CRCL3 - CRC Low Register 3; 0xFFFF98C7 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Low byte of CRC register, bit 0 */
    byte BIT1        :1;                                       /* Low byte of CRC register, bit 1 */
    byte BIT2        :1;                                       /* Low byte of CRC register, bit 2 */
    byte BIT3        :1;                                       /* Low byte of CRC register, bit 3 */
    byte BIT4        :1;                                       /* Low byte of CRC register, bit 4 */
    byte BIT5        :1;                                       /* Low byte of CRC register, bit 5 */
    byte BIT6        :1;                                       /* Low byte of CRC register, bit 6 */
    byte BIT7        :1;                                       /* Low byte of CRC register, bit 7 */
  } Bits;
} CRCL3STR;
extern volatile CRCL3STR _CRCL3 @0xFFFF98C7;
#define CRCL3                           _CRCL3.Byte
#define CRCL3_BIT0                      _CRCL3.Bits.BIT0
#define CRCL3_BIT1                      _CRCL3.Bits.BIT1
#define CRCL3_BIT2                      _CRCL3.Bits.BIT2
#define CRCL3_BIT3                      _CRCL3.Bits.BIT3
#define CRCL3_BIT4                      _CRCL3.Bits.BIT4
#define CRCL3_BIT5                      _CRCL3.Bits.BIT5
#define CRCL3_BIT6                      _CRCL3.Bits.BIT6
#define CRCL3_BIT7                      _CRCL3.Bits.BIT7

#define CRCL3_BIT0_MASK                 1U
#define CRCL3_BIT1_MASK                 2U
#define CRCL3_BIT2_MASK                 4U
#define CRCL3_BIT3_MASK                 8U
#define CRCL3_BIT4_MASK                 16U
#define CRCL3_BIT5_MASK                 32U
#define CRCL3_BIT6_MASK                 64U
#define CRCL3_BIT7_MASK                 128U


/*** INTC_FRC - INTC Force Interrupt Register; 0xFFFFFFD0 ***/
typedef union {
  byte Byte;
  struct {
    byte LVL7        :1;                                       /* Force Level 7 interrupt */
    byte LVL6        :1;                                       /* Force Level 6 interrupt */
    byte LVL5        :1;                                       /* Force Level 5 interrupt */
    byte LVL4        :1;                                       /* Force Level 4 interrupt */
    byte LVL3        :1;                                       /* Force Level 3 interrupt */
    byte LVL2        :1;                                       /* Force Level 2 interrupt */
    byte LVL1        :1;                                       /* Force Level 1 interrupt */
    byte             :1; 
  } Bits;
} INTC_FRCSTR;
extern volatile INTC_FRCSTR _INTC_FRC @0xFFFFFFD0;
#define INTC_FRC                        _INTC_FRC.Byte
#define INTC_FRC_LVL7                   _INTC_FRC.Bits.LVL7
#define INTC_FRC_LVL6                   _INTC_FRC.Bits.LVL6
#define INTC_FRC_LVL5                   _INTC_FRC.Bits.LVL5
#define INTC_FRC_LVL4                   _INTC_FRC.Bits.LVL4
#define INTC_FRC_LVL3                   _INTC_FRC.Bits.LVL3
#define INTC_FRC_LVL2                   _INTC_FRC.Bits.LVL2
#define INTC_FRC_LVL1                   _INTC_FRC.Bits.LVL1

#define INTC_FRC_LVL7_MASK              1U
#define INTC_FRC_LVL6_MASK              2U
#define INTC_FRC_LVL5_MASK              4U
#define INTC_FRC_LVL4_MASK              8U
#define INTC_FRC_LVL3_MASK              16U
#define INTC_FRC_LVL2_MASK              32U
#define INTC_FRC_LVL1_MASK              64U


/*** INTC_PL6P7 - INTC Programmable Level 6, Priority 7 Register; 0xFFFFFFD8 ***/
typedef union {
  byte Byte;
  struct {
    byte REQN0       :1;                                       /* Request number, bit 0 */
    byte REQN1       :1;                                       /* Request number, bit 1 */
    byte REQN2       :1;                                       /* Request number, bit 2 */
    byte REQN3       :1;                                       /* Request number, bit 3 */
    byte REQN4       :1;                                       /* Request number, bit 4 */
    byte REQN5       :1;                                       /* Request number, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpREQN :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_PL6P7STR;
extern volatile INTC_PL6P7STR _INTC_PL6P7 @0xFFFFFFD8;
#define INTC_PL6P7                      _INTC_PL6P7.Byte
#define INTC_PL6P7_REQN0                _INTC_PL6P7.Bits.REQN0
#define INTC_PL6P7_REQN1                _INTC_PL6P7.Bits.REQN1
#define INTC_PL6P7_REQN2                _INTC_PL6P7.Bits.REQN2
#define INTC_PL6P7_REQN3                _INTC_PL6P7.Bits.REQN3
#define INTC_PL6P7_REQN4                _INTC_PL6P7.Bits.REQN4
#define INTC_PL6P7_REQN5                _INTC_PL6P7.Bits.REQN5
#define INTC_PL6P7_REQN                 _INTC_PL6P7.MergedBits.grpREQN

#define INTC_PL6P7_REQN0_MASK           1U
#define INTC_PL6P7_REQN1_MASK           2U
#define INTC_PL6P7_REQN2_MASK           4U
#define INTC_PL6P7_REQN3_MASK           8U
#define INTC_PL6P7_REQN4_MASK           16U
#define INTC_PL6P7_REQN5_MASK           32U
#define INTC_PL6P7_REQN_MASK            63U
#define INTC_PL6P7_REQN_BITNUM          0U


/*** INTC_PL6P6 - INTC Programmable Level 6, Priority 6 Register; 0xFFFFFFD9 ***/
typedef union {
  byte Byte;
  struct {
    byte REQN0       :1;                                       /* Request number, bit 0 */
    byte REQN1       :1;                                       /* Request number, bit 1 */
    byte REQN2       :1;                                       /* Request number, bit 2 */
    byte REQN3       :1;                                       /* Request number, bit 3 */
    byte REQN4       :1;                                       /* Request number, bit 4 */
    byte REQN5       :1;                                       /* Request number, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpREQN :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_PL6P6STR;
extern volatile INTC_PL6P6STR _INTC_PL6P6 @0xFFFFFFD9;
#define INTC_PL6P6                      _INTC_PL6P6.Byte
#define INTC_PL6P6_REQN0                _INTC_PL6P6.Bits.REQN0
#define INTC_PL6P6_REQN1                _INTC_PL6P6.Bits.REQN1
#define INTC_PL6P6_REQN2                _INTC_PL6P6.Bits.REQN2
#define INTC_PL6P6_REQN3                _INTC_PL6P6.Bits.REQN3
#define INTC_PL6P6_REQN4                _INTC_PL6P6.Bits.REQN4
#define INTC_PL6P6_REQN5                _INTC_PL6P6.Bits.REQN5
#define INTC_PL6P6_REQN                 _INTC_PL6P6.MergedBits.grpREQN

#define INTC_PL6P6_REQN0_MASK           1U
#define INTC_PL6P6_REQN1_MASK           2U
#define INTC_PL6P6_REQN2_MASK           4U
#define INTC_PL6P6_REQN3_MASK           8U
#define INTC_PL6P6_REQN4_MASK           16U
#define INTC_PL6P6_REQN5_MASK           32U
#define INTC_PL6P6_REQN_MASK            63U
#define INTC_PL6P6_REQN_BITNUM          0U


/*** INTC_WCR - INTC Wake-up Control Register; 0xFFFFFFDB ***/
typedef union {
  byte Byte;
  struct {
    byte MASK0       :1;                                       /* Interrupt mask level, bit 0 */
    byte MASK1       :1;                                       /* Interrupt mask level, bit 1 */
    byte MASK2       :1;                                       /* Interrupt mask level, bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ENB         :1;                                       /* Enable */
  } Bits;
  struct {
    byte grpMASK :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_WCRSTR;
extern volatile INTC_WCRSTR _INTC_WCR @0xFFFFFFDB;
#define INTC_WCR                        _INTC_WCR.Byte
#define INTC_WCR_MASK0                  _INTC_WCR.Bits.MASK0
#define INTC_WCR_MASK1                  _INTC_WCR.Bits.MASK1
#define INTC_WCR_MASK2                  _INTC_WCR.Bits.MASK2
#define INTC_WCR_ENB                    _INTC_WCR.Bits.ENB
#define INTC_WCR_MASK                   _INTC_WCR.MergedBits.grpMASK

#define INTC_WCR_MASK0_MASK             1U
#define INTC_WCR_MASK1_MASK             2U
#define INTC_WCR_MASK2_MASK             4U
#define INTC_WCR_ENB_MASK               128U
#define INTC_WCR_MASK_MASK              7U
#define INTC_WCR_MASK_BITNUM            0U


/*** INTC_SFRC - INTC Set Interrupt Force Register; 0xFFFFFFDE ***/
typedef union {
  byte Byte;
  struct {
    byte SET0        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 0 */
    byte SET1        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 1 */
    byte SET2        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 2 */
    byte SET3        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 3 */
    byte SET4        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 4 */
    byte SET5        :1;                                       /* Sets corresponding bits in the INTC_FRC register, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpSET  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_SFRCSTR;
extern volatile INTC_SFRCSTR _INTC_SFRC @0xFFFFFFDE;
#define INTC_SFRC                       _INTC_SFRC.Byte
#define INTC_SFRC_SET0                  _INTC_SFRC.Bits.SET0
#define INTC_SFRC_SET1                  _INTC_SFRC.Bits.SET1
#define INTC_SFRC_SET2                  _INTC_SFRC.Bits.SET2
#define INTC_SFRC_SET3                  _INTC_SFRC.Bits.SET3
#define INTC_SFRC_SET4                  _INTC_SFRC.Bits.SET4
#define INTC_SFRC_SET5                  _INTC_SFRC.Bits.SET5
#define INTC_SFRC_SET                   _INTC_SFRC.MergedBits.grpSET

#define INTC_SFRC_SET0_MASK             1U
#define INTC_SFRC_SET1_MASK             2U
#define INTC_SFRC_SET2_MASK             4U
#define INTC_SFRC_SET3_MASK             8U
#define INTC_SFRC_SET4_MASK             16U
#define INTC_SFRC_SET5_MASK             32U
#define INTC_SFRC_SET_MASK              63U
#define INTC_SFRC_SET_BITNUM            0U


/*** INTC_CFRC - INTC Clear Interrupt Force Register; 0xFFFFFFDF ***/
typedef union {
  byte Byte;
  struct {
    byte CLR0        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 0 */
    byte CLR1        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 1 */
    byte CLR2        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 2 */
    byte CLR3        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 3 */
    byte CLR4        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 4 */
    byte CLR5        :1;                                       /* Clears corresponding bits in the INTC_FRC register, bit 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCLR  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} INTC_CFRCSTR;
extern volatile INTC_CFRCSTR _INTC_CFRC @0xFFFFFFDF;
#define INTC_CFRC                       _INTC_CFRC.Byte
#define INTC_CFRC_CLR0                  _INTC_CFRC.Bits.CLR0
#define INTC_CFRC_CLR1                  _INTC_CFRC.Bits.CLR1
#define INTC_CFRC_CLR2                  _INTC_CFRC.Bits.CLR2
#define INTC_CFRC_CLR3                  _INTC_CFRC.Bits.CLR3
#define INTC_CFRC_CLR4                  _INTC_CFRC.Bits.CLR4
#define INTC_CFRC_CLR5                  _INTC_CFRC.Bits.CLR5
#define INTC_CFRC_CLR                   _INTC_CFRC.MergedBits.grpCLR

#define INTC_CFRC_CLR0_MASK             1U
#define INTC_CFRC_CLR1_MASK             2U
#define INTC_CFRC_CLR2_MASK             4U
#define INTC_CFRC_CLR3_MASK             8U
#define INTC_CFRC_CLR4_MASK             16U
#define INTC_CFRC_CLR5_MASK             32U
#define INTC_CFRC_CLR_MASK              63U
#define INTC_CFRC_CLR_BITNUM            0U


/*** INTC_SWIACK - INTC Software IACK Register; 0xFFFFFFE0 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_SWIACKSTR;
extern volatile INTC_SWIACKSTR _INTC_SWIACK @0xFFFFFFE0;
#define INTC_SWIACK                     _INTC_SWIACK.Byte
#define INTC_SWIACK_VECN0               _INTC_SWIACK.Bits.VECN0
#define INTC_SWIACK_VECN1               _INTC_SWIACK.Bits.VECN1
#define INTC_SWIACK_VECN2               _INTC_SWIACK.Bits.VECN2
#define INTC_SWIACK_VECN3               _INTC_SWIACK.Bits.VECN3
#define INTC_SWIACK_VECN4               _INTC_SWIACK.Bits.VECN4
#define INTC_SWIACK_VECN5               _INTC_SWIACK.Bits.VECN5
#define INTC_SWIACK_VECN6               _INTC_SWIACK.Bits.VECN6
#define INTC_SWIACK_VECN                _INTC_SWIACK.MergedBits.grpVECN

#define INTC_SWIACK_VECN0_MASK          1U
#define INTC_SWIACK_VECN1_MASK          2U
#define INTC_SWIACK_VECN2_MASK          4U
#define INTC_SWIACK_VECN3_MASK          8U
#define INTC_SWIACK_VECN4_MASK          16U
#define INTC_SWIACK_VECN5_MASK          32U
#define INTC_SWIACK_VECN6_MASK          64U
#define INTC_SWIACK_VECN_MASK           127U
#define INTC_SWIACK_VECN_BITNUM         0U


/*** INTC_LVL1IACK - INTC Level 1 IACK Register; 0xFFFFFFE4 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL1IACKSTR;
extern volatile INTC_LVL1IACKSTR _INTC_LVL1IACK @0xFFFFFFE4;
#define INTC_LVL1IACK                   _INTC_LVL1IACK.Byte
#define INTC_LVL1IACK_VECN0             _INTC_LVL1IACK.Bits.VECN0
#define INTC_LVL1IACK_VECN1             _INTC_LVL1IACK.Bits.VECN1
#define INTC_LVL1IACK_VECN2             _INTC_LVL1IACK.Bits.VECN2
#define INTC_LVL1IACK_VECN3             _INTC_LVL1IACK.Bits.VECN3
#define INTC_LVL1IACK_VECN4             _INTC_LVL1IACK.Bits.VECN4
#define INTC_LVL1IACK_VECN5             _INTC_LVL1IACK.Bits.VECN5
#define INTC_LVL1IACK_VECN6             _INTC_LVL1IACK.Bits.VECN6
#define INTC_LVL1IACK_VECN              _INTC_LVL1IACK.MergedBits.grpVECN

#define INTC_LVL1IACK_VECN0_MASK        1U
#define INTC_LVL1IACK_VECN1_MASK        2U
#define INTC_LVL1IACK_VECN2_MASK        4U
#define INTC_LVL1IACK_VECN3_MASK        8U
#define INTC_LVL1IACK_VECN4_MASK        16U
#define INTC_LVL1IACK_VECN5_MASK        32U
#define INTC_LVL1IACK_VECN6_MASK        64U
#define INTC_LVL1IACK_VECN_MASK         127U
#define INTC_LVL1IACK_VECN_BITNUM       0U


/*** INTC_LVL2IACK - INTC Level 2 IACK Register; 0xFFFFFFE8 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL2IACKSTR;
extern volatile INTC_LVL2IACKSTR _INTC_LVL2IACK @0xFFFFFFE8;
#define INTC_LVL2IACK                   _INTC_LVL2IACK.Byte
#define INTC_LVL2IACK_VECN0             _INTC_LVL2IACK.Bits.VECN0
#define INTC_LVL2IACK_VECN1             _INTC_LVL2IACK.Bits.VECN1
#define INTC_LVL2IACK_VECN2             _INTC_LVL2IACK.Bits.VECN2
#define INTC_LVL2IACK_VECN3             _INTC_LVL2IACK.Bits.VECN3
#define INTC_LVL2IACK_VECN4             _INTC_LVL2IACK.Bits.VECN4
#define INTC_LVL2IACK_VECN5             _INTC_LVL2IACK.Bits.VECN5
#define INTC_LVL2IACK_VECN6             _INTC_LVL2IACK.Bits.VECN6
#define INTC_LVL2IACK_VECN              _INTC_LVL2IACK.MergedBits.grpVECN

#define INTC_LVL2IACK_VECN0_MASK        1U
#define INTC_LVL2IACK_VECN1_MASK        2U
#define INTC_LVL2IACK_VECN2_MASK        4U
#define INTC_LVL2IACK_VECN3_MASK        8U
#define INTC_LVL2IACK_VECN4_MASK        16U
#define INTC_LVL2IACK_VECN5_MASK        32U
#define INTC_LVL2IACK_VECN6_MASK        64U
#define INTC_LVL2IACK_VECN_MASK         127U
#define INTC_LVL2IACK_VECN_BITNUM       0U


/*** INTC_LVL3IACK - INTC Level 3 IACK Register; 0xFFFFFFEC ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL3IACKSTR;
extern volatile INTC_LVL3IACKSTR _INTC_LVL3IACK @0xFFFFFFEC;
#define INTC_LVL3IACK                   _INTC_LVL3IACK.Byte
#define INTC_LVL3IACK_VECN0             _INTC_LVL3IACK.Bits.VECN0
#define INTC_LVL3IACK_VECN1             _INTC_LVL3IACK.Bits.VECN1
#define INTC_LVL3IACK_VECN2             _INTC_LVL3IACK.Bits.VECN2
#define INTC_LVL3IACK_VECN3             _INTC_LVL3IACK.Bits.VECN3
#define INTC_LVL3IACK_VECN4             _INTC_LVL3IACK.Bits.VECN4
#define INTC_LVL3IACK_VECN5             _INTC_LVL3IACK.Bits.VECN5
#define INTC_LVL3IACK_VECN6             _INTC_LVL3IACK.Bits.VECN6
#define INTC_LVL3IACK_VECN              _INTC_LVL3IACK.MergedBits.grpVECN

#define INTC_LVL3IACK_VECN0_MASK        1U
#define INTC_LVL3IACK_VECN1_MASK        2U
#define INTC_LVL3IACK_VECN2_MASK        4U
#define INTC_LVL3IACK_VECN3_MASK        8U
#define INTC_LVL3IACK_VECN4_MASK        16U
#define INTC_LVL3IACK_VECN5_MASK        32U
#define INTC_LVL3IACK_VECN6_MASK        64U
#define INTC_LVL3IACK_VECN_MASK         127U
#define INTC_LVL3IACK_VECN_BITNUM       0U


/*** INTC_LVL4IACK - INTC Level 4 IACK Register; 0xFFFFFFF0 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL4IACKSTR;
extern volatile INTC_LVL4IACKSTR _INTC_LVL4IACK @0xFFFFFFF0;
#define INTC_LVL4IACK                   _INTC_LVL4IACK.Byte
#define INTC_LVL4IACK_VECN0             _INTC_LVL4IACK.Bits.VECN0
#define INTC_LVL4IACK_VECN1             _INTC_LVL4IACK.Bits.VECN1
#define INTC_LVL4IACK_VECN2             _INTC_LVL4IACK.Bits.VECN2
#define INTC_LVL4IACK_VECN3             _INTC_LVL4IACK.Bits.VECN3
#define INTC_LVL4IACK_VECN4             _INTC_LVL4IACK.Bits.VECN4
#define INTC_LVL4IACK_VECN5             _INTC_LVL4IACK.Bits.VECN5
#define INTC_LVL4IACK_VECN6             _INTC_LVL4IACK.Bits.VECN6
#define INTC_LVL4IACK_VECN              _INTC_LVL4IACK.MergedBits.grpVECN

#define INTC_LVL4IACK_VECN0_MASK        1U
#define INTC_LVL4IACK_VECN1_MASK        2U
#define INTC_LVL4IACK_VECN2_MASK        4U
#define INTC_LVL4IACK_VECN3_MASK        8U
#define INTC_LVL4IACK_VECN4_MASK        16U
#define INTC_LVL4IACK_VECN5_MASK        32U
#define INTC_LVL4IACK_VECN6_MASK        64U
#define INTC_LVL4IACK_VECN_MASK         127U
#define INTC_LVL4IACK_VECN_BITNUM       0U


/*** INTC_LVL5IACK - INTC Level 5 IACK Register; 0xFFFFFFF4 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL5IACKSTR;
extern volatile INTC_LVL5IACKSTR _INTC_LVL5IACK @0xFFFFFFF4;
#define INTC_LVL5IACK                   _INTC_LVL5IACK.Byte
#define INTC_LVL5IACK_VECN0             _INTC_LVL5IACK.Bits.VECN0
#define INTC_LVL5IACK_VECN1             _INTC_LVL5IACK.Bits.VECN1
#define INTC_LVL5IACK_VECN2             _INTC_LVL5IACK.Bits.VECN2
#define INTC_LVL5IACK_VECN3             _INTC_LVL5IACK.Bits.VECN3
#define INTC_LVL5IACK_VECN4             _INTC_LVL5IACK.Bits.VECN4
#define INTC_LVL5IACK_VECN5             _INTC_LVL5IACK.Bits.VECN5
#define INTC_LVL5IACK_VECN6             _INTC_LVL5IACK.Bits.VECN6
#define INTC_LVL5IACK_VECN              _INTC_LVL5IACK.MergedBits.grpVECN

#define INTC_LVL5IACK_VECN0_MASK        1U
#define INTC_LVL5IACK_VECN1_MASK        2U
#define INTC_LVL5IACK_VECN2_MASK        4U
#define INTC_LVL5IACK_VECN3_MASK        8U
#define INTC_LVL5IACK_VECN4_MASK        16U
#define INTC_LVL5IACK_VECN5_MASK        32U
#define INTC_LVL5IACK_VECN6_MASK        64U
#define INTC_LVL5IACK_VECN_MASK         127U
#define INTC_LVL5IACK_VECN_BITNUM       0U


/*** INTC_LVL6IACK - INTC Level 6 IACK Register; 0xFFFFFFF8 ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL6IACKSTR;
extern volatile INTC_LVL6IACKSTR _INTC_LVL6IACK @0xFFFFFFF8;
#define INTC_LVL6IACK                   _INTC_LVL6IACK.Byte
#define INTC_LVL6IACK_VECN0             _INTC_LVL6IACK.Bits.VECN0
#define INTC_LVL6IACK_VECN1             _INTC_LVL6IACK.Bits.VECN1
#define INTC_LVL6IACK_VECN2             _INTC_LVL6IACK.Bits.VECN2
#define INTC_LVL6IACK_VECN3             _INTC_LVL6IACK.Bits.VECN3
#define INTC_LVL6IACK_VECN4             _INTC_LVL6IACK.Bits.VECN4
#define INTC_LVL6IACK_VECN5             _INTC_LVL6IACK.Bits.VECN5
#define INTC_LVL6IACK_VECN6             _INTC_LVL6IACK.Bits.VECN6
#define INTC_LVL6IACK_VECN              _INTC_LVL6IACK.MergedBits.grpVECN

#define INTC_LVL6IACK_VECN0_MASK        1U
#define INTC_LVL6IACK_VECN1_MASK        2U
#define INTC_LVL6IACK_VECN2_MASK        4U
#define INTC_LVL6IACK_VECN3_MASK        8U
#define INTC_LVL6IACK_VECN4_MASK        16U
#define INTC_LVL6IACK_VECN5_MASK        32U
#define INTC_LVL6IACK_VECN6_MASK        64U
#define INTC_LVL6IACK_VECN_MASK         127U
#define INTC_LVL6IACK_VECN_BITNUM       0U


/*** INTC_LVL7IACK - INTC Level 7 IACK Register; 0xFFFFFFFC ***/
typedef union {
  byte Byte;
  struct {
    byte VECN0       :1;                                       /* Vector number, bit 0 */
    byte VECN1       :1;                                       /* Vector number, bit 1 */
    byte VECN2       :1;                                       /* Vector number, bit 2 */
    byte VECN3       :1;                                       /* Vector number, bit 3 */
    byte VECN4       :1;                                       /* Vector number, bit 4 */
    byte VECN5       :1;                                       /* Vector number, bit 5 */
    byte VECN6       :1;                                       /* Vector number, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpVECN :7;
    byte         :1;
  } MergedBits;
} INTC_LVL7IACKSTR;
extern volatile INTC_LVL7IACKSTR _INTC_LVL7IACK @0xFFFFFFFC;
#define INTC_LVL7IACK                   _INTC_LVL7IACK.Byte
#define INTC_LVL7IACK_VECN0             _INTC_LVL7IACK.Bits.VECN0
#define INTC_LVL7IACK_VECN1             _INTC_LVL7IACK.Bits.VECN1
#define INTC_LVL7IACK_VECN2             _INTC_LVL7IACK.Bits.VECN2
#define INTC_LVL7IACK_VECN3             _INTC_LVL7IACK.Bits.VECN3
#define INTC_LVL7IACK_VECN4             _INTC_LVL7IACK.Bits.VECN4
#define INTC_LVL7IACK_VECN5             _INTC_LVL7IACK.Bits.VECN5
#define INTC_LVL7IACK_VECN6             _INTC_LVL7IACK.Bits.VECN6
#define INTC_LVL7IACK_VECN              _INTC_LVL7IACK.MergedBits.grpVECN

#define INTC_LVL7IACK_VECN0_MASK        1U
#define INTC_LVL7IACK_VECN1_MASK        2U
#define INTC_LVL7IACK_VECN2_MASK        4U
#define INTC_LVL7IACK_VECN3_MASK        8U
#define INTC_LVL7IACK_VECN4_MASK        16U
#define INTC_LVL7IACK_VECN5_MASK        32U
#define INTC_LVL7IACK_VECN6_MASK        64U
#define INTC_LVL7IACK_VECN_MASK         127U
#define INTC_LVL7IACK_VECN_BITNUM       0U



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 6.6.2008 12:57:36 */

#define FTM1ADCTRIG                      FTM1EXTTRIG
#define FTM1ADCTRIG_CH2TRIG              FTM1EXTTRIG_CH2TRIG
#define FTM1ADCTRIG_CH3TRIG              FTM1EXTTRIG_CH3TRIG
#define FTM1ADCTRIG_CH4TRIG              FTM1EXTTRIG_CH4TRIG
#define FTM1ADCTRIG_CH5TRIG              FTM1EXTTRIG_CH5TRIG
#define FTM1ADCTRIG_CH6TRIG              FTM1EXTTRIG_CH6TRIG
#define FTM1ADCTRIG_CH7TRIG              FTM1EXTTRIG_CH7TRIG
#define FTM1ADCTRIG_INITTRIGEN           FTM1EXTTRIG_INITTRIGEN
#define FTM1ADCTRIG_ADCF                 FTM1EXTTRIG_TRIGF
#define FTM1ADCTRIG_CH2TRIG_MASK         FTM1EXTTRIG_CH2TRIG_MASK
#define FTM1ADCTRIG_CH3TRIG_MASK         FTM1EXTTRIG_CH3TRIG_MASK
#define FTM1ADCTRIG_CH4TRIG_MASK         FTM1EXTTRIG_CH4TRIG_MASK
#define FTM1ADCTRIG_CH5TRIG_MASK         FTM1EXTTRIG_CH5TRIG_MASK
#define FTM1ADCTRIG_CH6TRIG_MASK         FTM1EXTTRIG_CH6TRIG_MASK
#define FTM1ADCTRIG_CH7TRIG_MASK         FTM1EXTTRIG_CH7TRIG_MASK
#define FTM1ADCTRIG_INITTRIGEN_MASK      FTM1EXTTRIG_INITTRIGEN_MASK
#define FTM1ADCTRIG_ADCF_MASK            FTM1EXTTRIG_TRIGF_MASK

/*** FTM2ADCTRIG - FTM2 Hardware Trigger Generated For ADC Register; 0xFFFF80E9 ***/
typedef union {
  byte Byte;
  struct {
    byte CH2TRIG     :1;                                       /* Enables the FTM2 Channel 2 to be Used in the Generation of the Hardware Triggers to ADC */
    byte CH3TRIG     :1;                                       /* Enables the FTM2 Channel 3 to be Used in the Generation of the Hardware Triggers to ADC */
    byte CH4TRIG     :1;                                       /* Enables the FTM2 Channel 4 to be Used in the Generation of the Hardware Triggers to ADC */
    byte CH5TRIG     :1;                                       /* Enables the FTM2 Channel 5 to be Used in the Generation of the Hardware Triggers to ADC */
    byte CH6TRIG     :1;                                       /* Enables the FTM2 Channel 6 to be Used in the Generation of the Hardware Triggers to ADC */
    byte CH7TRIG     :1;                                       /* Enables the FTM2 Channel 7 to be Used in the Generation of the Hardware Triggers to ADC */
    byte INITTRIGEN  :1;                                       /* Enables the Generation of a Trigger Signal */
    byte ADCF        :1;                                       /* ADC Hardware Trigger Flag */
  } Bits;
} FTM2ADCTRIGSTR;
extern volatile FTM2ADCTRIGSTR _FTM2ADCTRIG @0xFFFF80E9;
#define FTM2ADCTRIG                     _FTM2ADCTRIG.Byte
#define FTM2ADCTRIG_CH2TRIG             _FTM2ADCTRIG.Bits.CH2TRIG
#define FTM2ADCTRIG_CH3TRIG             _FTM2ADCTRIG.Bits.CH3TRIG
#define FTM2ADCTRIG_CH4TRIG             _FTM2ADCTRIG.Bits.CH4TRIG
#define FTM2ADCTRIG_CH5TRIG             _FTM2ADCTRIG.Bits.CH5TRIG
#define FTM2ADCTRIG_CH6TRIG             _FTM2ADCTRIG.Bits.CH6TRIG
#define FTM2ADCTRIG_CH7TRIG             _FTM2ADCTRIG.Bits.CH7TRIG
#define FTM2ADCTRIG_INITTRIGEN          _FTM2ADCTRIG.Bits.INITTRIGEN
#define FTM2ADCTRIG_ADCF                _FTM2ADCTRIG.Bits.ADCF

#define FTM2ADCTRIG_CH2TRIG_MASK        1
#define FTM2ADCTRIG_CH3TRIG_MASK        2
#define FTM2ADCTRIG_CH4TRIG_MASK        4
#define FTM2ADCTRIG_CH5TRIG_MASK        8
#define FTM2ADCTRIG_CH6TRIG_MASK        16
#define FTM2ADCTRIG_CH7TRIG_MASK        32
#define FTM2ADCTRIG_INITTRIGEN_MASK     64
#define FTM2ADCTRIG_ADCF_MASK           128


/* **** 9.6.2008 11:42:27 */

#define FTM1CNTINH_BIT0                  FTM1CNTINH_BIT8
#define FTM1CNTINH_BIT1                  FTM1CNTINH_BIT9
#define FTM1CNTINH_BIT2                  FTM1CNTINH_BIT10
#define FTM1CNTINH_BIT3                  FTM1CNTINH_BIT11
#define FTM1CNTINH_BIT4                  FTM1CNTINH_BIT12
#define FTM1CNTINH_BIT5                  FTM1CNTINH_BIT13
#define FTM1CNTINH_BIT6                  FTM1CNTINH_BIT14
#define FTM1CNTINH_BIT7                  FTM1CNTINH_BIT15
#define FTM1CNTINH_BIT0_MASK             FTM1CNTINH_BIT8_MASK
#define FTM1CNTINH_BIT1_MASK             FTM1CNTINH_BIT9_MASK
#define FTM1CNTINH_BIT2_MASK             FTM1CNTINH_BIT10_MASK
#define FTM1CNTINH_BIT3_MASK             FTM1CNTINH_BIT11_MASK
#define FTM1CNTINH_BIT4_MASK             FTM1CNTINH_BIT12_MASK
#define FTM1CNTINH_BIT5_MASK             FTM1CNTINH_BIT13_MASK
#define FTM1CNTINH_BIT6_MASK             FTM1CNTINH_BIT14_MASK
#define FTM1CNTINH_BIT7_MASK             FTM1CNTINH_BIT15_MASK
#define FTM1STATUS_CH6F                  This_symb_has_been_depreciated
#define FTM1STATUS_CH7F                  This_symb_has_been_depreciated
#define FTM1STATUS_CH6F_MASK             This_symb_has_been_depreciated
#define FTM1STATUS_CH7F_MASK             This_symb_has_been_depreciated
#define FTM1OUTINIT_CH6OI                This_symb_has_been_depreciated
#define FTM1OUTINIT_CH7OI                This_symb_has_been_depreciated
#define FTM1OUTINIT_CH6OI_MASK           This_symb_has_been_depreciated
#define FTM1OUTINIT_CH7OI_MASK           This_symb_has_been_depreciated
#define FTM1OUTMASK_CH6OM                This_symb_has_been_depreciated
#define FTM1OUTMASK_CH7OM                This_symb_has_been_depreciated
#define FTM1OUTMASK_CH6OM_MASK           This_symb_has_been_depreciated
#define FTM1OUTMASK_CH7OM_MASK           This_symb_has_been_depreciated
#define FTM1COMBINE3                     This_symb_has_been_depreciated
#define FTM1COMBINE3_COMBINE             This_symb_has_been_depreciated
#define FTM1COMBINE3_COMP                This_symb_has_been_depreciated
#define FTM1COMBINE3_DTEN                This_symb_has_been_depreciated
#define FTM1COMBINE3_SYNCEN              This_symb_has_been_depreciated
#define FTM1COMBINE3_FAULTEN             This_symb_has_been_depreciated
#define FTM1COMBINE3_COMBINE_MASK        This_symb_has_been_depreciated
#define FTM1COMBINE3_COMP_MASK           This_symb_has_been_depreciated
#define FTM1COMBINE3_DTEN_MASK           This_symb_has_been_depreciated
#define FTM1COMBINE3_SYNCEN_MASK         This_symb_has_been_depreciated
#define FTM1COMBINE3_FAULTEN_MASK        This_symb_has_been_depreciated
#define FTM1POL_POL6                     This_symb_has_been_depreciated
#define FTM1POL_POL7                     This_symb_has_been_depreciated
#define FTM1POL_POL6_MASK                This_symb_has_been_depreciated
#define FTM1POL_POL7_MASK                This_symb_has_been_depreciated
#define FTM2CNTINH_BIT0                  FTM2CNTINH_BIT8
#define FTM2CNTINH_BIT1                  FTM2CNTINH_BIT9
#define FTM2CNTINH_BIT2                  FTM2CNTINH_BIT10
#define FTM2CNTINH_BIT3                  FTM2CNTINH_BIT11
#define FTM2CNTINH_BIT4                  FTM2CNTINH_BIT12
#define FTM2CNTINH_BIT5                  FTM2CNTINH_BIT13
#define FTM2CNTINH_BIT6                  FTM2CNTINH_BIT14
#define FTM2CNTINH_BIT7                  FTM2CNTINH_BIT15
#define FTM2CNTINH_BIT0_MASK             FTM2CNTINH_BIT8_MASK
#define FTM2CNTINH_BIT1_MASK             FTM2CNTINH_BIT9_MASK
#define FTM2CNTINH_BIT2_MASK             FTM2CNTINH_BIT10_MASK
#define FTM2CNTINH_BIT3_MASK             FTM2CNTINH_BIT11_MASK
#define FTM2CNTINH_BIT4_MASK             FTM2CNTINH_BIT12_MASK
#define FTM2CNTINH_BIT5_MASK             FTM2CNTINH_BIT13_MASK
#define FTM2CNTINH_BIT6_MASK             FTM2CNTINH_BIT14_MASK
#define FTM2CNTINH_BIT7_MASK             FTM2CNTINH_BIT15_MASK
#define FTM2STATUS_CH6F                  This_symb_has_been_depreciated
#define FTM2STATUS_CH7F                  This_symb_has_been_depreciated
#define FTM2STATUS_CH6F_MASK             This_symb_has_been_depreciated
#define FTM2STATUS_CH7F_MASK             This_symb_has_been_depreciated
#define FTM2OUTINIT_CH6OI                This_symb_has_been_depreciated
#define FTM2OUTINIT_CH7OI                This_symb_has_been_depreciated
#define FTM2OUTINIT_CH6OI_MASK           This_symb_has_been_depreciated
#define FTM2OUTINIT_CH7OI_MASK           This_symb_has_been_depreciated
#define FTM2OUTMASK_CH6OM                This_symb_has_been_depreciated
#define FTM2OUTMASK_CH7OM                This_symb_has_been_depreciated
#define FTM2OUTMASK_CH6OM_MASK           This_symb_has_been_depreciated
#define FTM2OUTMASK_CH7OM_MASK           This_symb_has_been_depreciated
#define FTM2COMBINE3                     This_symb_has_been_depreciated
#define FTM2COMBINE3_COMBINE             This_symb_has_been_depreciated
#define FTM2COMBINE3_COMP                This_symb_has_been_depreciated
#define FTM2COMBINE3_DTEN                This_symb_has_been_depreciated
#define FTM2COMBINE3_SYNCEN              This_symb_has_been_depreciated
#define FTM2COMBINE3_FAULTEN             This_symb_has_been_depreciated
#define FTM2COMBINE3_COMBINE_MASK        This_symb_has_been_depreciated
#define FTM2COMBINE3_COMP_MASK           This_symb_has_been_depreciated
#define FTM2COMBINE3_DTEN_MASK           This_symb_has_been_depreciated
#define FTM2COMBINE3_SYNCEN_MASK         This_symb_has_been_depreciated
#define FTM2COMBINE3_FAULTEN_MASK        This_symb_has_been_depreciated
#define FTM2POL_POL6                     This_symb_has_been_depreciated
#define FTM2POL_POL7                     This_symb_has_been_depreciated
#define FTM2POL_POL6_MASK                This_symb_has_been_depreciated
#define FTM2POL_POL7_MASK                This_symb_has_been_depreciated


/* **** 8.7.2008 12:27:45 */

#define IIC1A                            IICA
#define IIC1A_AD1                        IICA_AD1
#define IIC1A_AD2                        IICA_AD2
#define IIC1A_AD3                        IICA_AD3
#define IIC1A_AD4                        IICA_AD4
#define IIC1A_AD5                        IICA_AD5
#define IIC1A_AD6                        IICA_AD6
#define IIC1A_AD7                        IICA_AD7
#define IIC1A_AD_1                       IICA_AD_1
#define IIC1A_AD                         IICA_AD
#define IIC1A_AD1_MASK                   IICA_AD1_MASK
#define IIC1A_AD2_MASK                   IICA_AD2_MASK
#define IIC1A_AD3_MASK                   IICA_AD3_MASK
#define IIC1A_AD4_MASK                   IICA_AD4_MASK
#define IIC1A_AD5_MASK                   IICA_AD5_MASK
#define IIC1A_AD6_MASK                   IICA_AD6_MASK
#define IIC1A_AD7_MASK                   IICA_AD7_MASK
#define IIC1A_AD_1_MASK                  IICA_AD_1_MASK
#define IIC1A_AD_1_BITNUM                IICA_AD_1_BITNUM
#define IIC1F                            IICF
#define IIC1F_ICR0                       IICF_ICR0
#define IIC1F_ICR1                       IICF_ICR1
#define IIC1F_ICR2                       IICF_ICR2
#define IIC1F_ICR3                       IICF_ICR3
#define IIC1F_ICR4                       IICF_ICR4
#define IIC1F_ICR5                       IICF_ICR5
#define IIC1F_MULT0                      IICF_MULT0
#define IIC1F_MULT1                      IICF_MULT1
#define IIC1F_ICR                        IICF_ICR
#define IIC1F_MULT                       IICF_MULT
#define IIC1F_ICR0_MASK                  IICF_ICR0_MASK
#define IIC1F_ICR1_MASK                  IICF_ICR1_MASK
#define IIC1F_ICR2_MASK                  IICF_ICR2_MASK
#define IIC1F_ICR3_MASK                  IICF_ICR3_MASK
#define IIC1F_ICR4_MASK                  IICF_ICR4_MASK
#define IIC1F_ICR5_MASK                  IICF_ICR5_MASK
#define IIC1F_MULT0_MASK                 IICF_MULT0_MASK
#define IIC1F_MULT1_MASK                 IICF_MULT1_MASK
#define IIC1F_ICR_MASK                   IICF_ICR_MASK
#define IIC1F_ICR_BITNUM                 IICF_ICR_BITNUM
#define IIC1F_MULT_MASK                  IICF_MULT_MASK
#define IIC1F_MULT_BITNUM                IICF_MULT_BITNUM
#define IIC1C1                           IICC1
#define IIC1C1_RSTA                      IICC1_RSTA
#define IIC1C1_TXAK                      IICC1_TXAK
#define IIC1C1_TX                        IICC1_TX
#define IIC1C1_MST                       IICC1_MST
#define IIC1C1_IICIE                     IICC1_IICIE
#define IIC1C1_IICEN                     IICC1_IICEN
#define IIC1C1_RSTA_MASK                 IICC1_RSTA_MASK
#define IIC1C1_TXAK_MASK                 IICC1_TXAK_MASK
#define IIC1C1_TX_MASK                   IICC1_TX_MASK
#define IIC1C1_MST_MASK                  IICC1_MST_MASK
#define IIC1C1_IICIE_MASK                IICC1_IICIE_MASK
#define IIC1C1_IICEN_MASK                IICC1_IICEN_MASK
#define IIC1C                            IICC           
#define IIC1C_RSTA                       IICC_RSTA      
#define IIC1C_TXAK                       IICC_TXAK      
#define IIC1C_TX                         IICC_TX        
#define IIC1C_MST                        IICC_MST       
#define IIC1C_IICIE                      IICC_IICIE     
#define IIC1C_IICEN                      IICC_IICEN     
#define IIC1C_RSTA_MASK                  IICC_RSTA_MASK 
#define IIC1C_TXAK_MASK                  IICC_TXAK_MASK 
#define IIC1C_TX_MASK                    IICC_TX_MASK   
#define IIC1C_MST_MASK                   IICC_MST_MASK  
#define IIC1C_IICIE_MASK                 IICC_IICIE_MASK
#define IIC1C_IICEN_MASK                 IICC_IICEN_MASK
#define IIC1S                            IICS
#define IIC1S_RXAK                       IICS_RXAK
#define IIC1S_IICIF                      IICS_IICIF
#define IIC1S_SRW                        IICS_SRW
#define IIC1S_ARBL                       IICS_ARBL
#define IIC1S_BUSY                       IICS_BUSY
#define IIC1S_IAAS                       IICS_IAAS
#define IIC1S_TCF                        IICS_TCF
#define IIC1S_RXAK_MASK                  IICS_RXAK_MASK
#define IIC1S_IICIF_MASK                 IICS_IICIF_MASK
#define IIC1S_SRW_MASK                   IICS_SRW_MASK
#define IIC1S_ARBL_MASK                  IICS_ARBL_MASK
#define IIC1S_BUSY_MASK                  IICS_BUSY_MASK
#define IIC1S_IAAS_MASK                  IICS_IAAS_MASK
#define IIC1S_TCF_MASK                   IICS_TCF_MASK
#define IIC1D                            IICD
#define IIC1D_DATA0                      IICD_DATA0
#define IIC1D_DATA1                      IICD_DATA1
#define IIC1D_DATA2                      IICD_DATA2
#define IIC1D_DATA3                      IICD_DATA3
#define IIC1D_DATA4                      IICD_DATA4
#define IIC1D_DATA5                      IICD_DATA5
#define IIC1D_DATA6                      IICD_DATA6
#define IIC1D_DATA7                      IICD_DATA7
#define IIC1D_DATA0_MASK                 IICD_DATA0_MASK
#define IIC1D_DATA1_MASK                 IICD_DATA1_MASK
#define IIC1D_DATA2_MASK                 IICD_DATA2_MASK
#define IIC1D_DATA3_MASK                 IICD_DATA3_MASK
#define IIC1D_DATA4_MASK                 IICD_DATA4_MASK
#define IIC1D_DATA5_MASK                 IICD_DATA5_MASK
#define IIC1D_DATA6_MASK                 IICD_DATA6_MASK
#define IIC1D_DATA7_MASK                 IICD_DATA7_MASK
#define IIC1C2                           IICC2
#define IIC1C2_AD8                       IICC2_AD8
#define IIC1C2_AD9                       IICC2_AD9
#define IIC1C2_AD10                      IICC2_AD10
#define IIC1C2_ADEXT                     IICC2_ADEXT
#define IIC1C2_GCAEN                     IICC2_GCAEN
#define IIC1C2_AD_8                      IICC2_AD_8
#define IIC1C2_AD                        IICC2_AD
#define IIC1C2_AD8_MASK                  IICC2_AD8_MASK
#define IIC1C2_AD9_MASK                  IICC2_AD9_MASK
#define IIC1C2_AD10_MASK                 IICC2_AD10_MASK
#define IIC1C2_ADEXT_MASK                IICC2_ADEXT_MASK
#define IIC1C2_GCAEN_MASK                IICC2_GCAEN_MASK
#define IIC1C2_AD_8_MASK                 IICC2_AD_8_MASK
#define IIC1C2_AD_8_BITNUM               IICC2_AD_8_BITNUM
#define FTM1FAULTFILTER                  FTM1FLTFILTER
#define FTM1FAULTFILTER_FFVAL0           FTM1FLTFILTER_FFVAL0
#define FTM1FAULTFILTER_FFVAL1           FTM1FLTFILTER_FFVAL1
#define FTM1FAULTFILTER_FFVAL2           FTM1FLTFILTER_FFVAL2
#define FTM1FAULTFILTER_FFVAL3           FTM1FLTFILTER_FFVAL3
#define FTM1FAULTFILTER_FFVAL            FTM1FLTFILTER_FFVAL
#define FTM1FAULTFILTER_FFVAL0_MASK      FTM1FLTFILTER_FFVAL0_MASK
#define FTM1FAULTFILTER_FFVAL1_MASK      FTM1FLTFILTER_FFVAL1_MASK
#define FTM1FAULTFILTER_FFVAL2_MASK      FTM1FLTFILTER_FFVAL2_MASK
#define FTM1FAULTFILTER_FFVAL3_MASK      FTM1FLTFILTER_FFVAL3_MASK
#define FTM1FAULTFILTER_FFVAL_MASK       FTM1FLTFILTER_FFVAL_MASK
#define FTM1FAULTFILTER_FFVAL_BITNUM     FTM1FLTFILTER_FFVAL_BITNUM
#define FTM2FAULTFILTER                  FTM2FLTFILTER
#define FTM2FAULTFILTER_FFVAL0           FTM2FLTFILTER_FFVAL0
#define FTM2FAULTFILTER_FFVAL1           FTM2FLTFILTER_FFVAL1
#define FTM2FAULTFILTER_FFVAL2           FTM2FLTFILTER_FFVAL2
#define FTM2FAULTFILTER_FFVAL3           FTM2FLTFILTER_FFVAL3
#define FTM2FAULTFILTER_FFVAL            FTM2FLTFILTER_FFVAL
#define FTM2FAULTFILTER_FFVAL0_MASK      FTM2FLTFILTER_FFVAL0_MASK
#define FTM2FAULTFILTER_FFVAL1_MASK      FTM2FLTFILTER_FFVAL1_MASK
#define FTM2FAULTFILTER_FFVAL2_MASK      FTM2FLTFILTER_FFVAL2_MASK
#define FTM2FAULTFILTER_FFVAL3_MASK      FTM2FLTFILTER_FFVAL3_MASK
#define FTM2FAULTFILTER_FFVAL_MASK       FTM2FLTFILTER_FFVAL_MASK
#define FTM2FAULTFILTER_FFVAL_BITNUM     FTM2FLTFILTER_FFVAL_BITNUM
#define SCGC1_IIC1                       SCGC1_IIC
#define SCGC1_IIC1_MASK                  SCGC1_IIC_MASK


/* **** 11.7.2008 14:51:15 */

#define FTM1EXTTRIG_CH6TRIG              This_symb_has_been_depreciated
#define FTM1EXTTRIG_CH7TRIG              This_symb_has_been_depreciated
#define FTM1EXTTRIG_INITTRIGEN           This_symb_has_been_depreciated
#define FTM1EXTTRIG_CH6TRIG_MASK         This_symb_has_been_depreciated
#define FTM1EXTTRIG_CH7TRIG_MASK         This_symb_has_been_depreciated
#define FTM1EXTTRIG_INITTRIGEN_MASK      This_symb_has_been_depreciated


/* **** 4.9.2008 15:25:38 */

#define VectorNumber_Vadc                VectorNumber_Vadc1
#define Vadc                             Vadc1
#define VectorNumber_Viic                VectorNumber_Viic1
#define Viic                             Viic1
#define ADC1SC1                          ADCSC1
#define ADC1SC1_ADCH0                    ADCSC1_ADCH0
#define ADC1SC1_ADCH1                    ADCSC1_ADCH1
#define ADC1SC1_ADCH2                    ADCSC1_ADCH2
#define ADC1SC1_ADCH3                    ADCSC1_ADCH3
#define ADC1SC1_ADCH4                    ADCSC1_ADCH4
#define ADC1SC1_ADCO                     ADCSC1_ADCO
#define ADC1SC1_AIEN                     ADCSC1_AIEN
#define ADC1SC1_COCO                     ADCSC1_COCO
#define ADC1SC1_ADCH                     ADCSC1_ADCH
#define ADC1SC1_ADCH0_MASK               ADCSC1_ADCH0_MASK
#define ADC1SC1_ADCH1_MASK               ADCSC1_ADCH1_MASK
#define ADC1SC1_ADCH2_MASK               ADCSC1_ADCH2_MASK
#define ADC1SC1_ADCH3_MASK               ADCSC1_ADCH3_MASK
#define ADC1SC1_ADCH4_MASK               ADCSC1_ADCH4_MASK
#define ADC1SC1_ADCO_MASK                ADCSC1_ADCO_MASK
#define ADC1SC1_AIEN_MASK                ADCSC1_AIEN_MASK
#define ADC1SC1_COCO_MASK                ADCSC1_COCO_MASK
#define ADC1SC1_ADCH_MASK                ADCSC1_ADCH_MASK
#define ADC1SC1_ADCH_BITNUM              ADCSC1_ADCH_BITNUM
#define ADC1SC2                          ADCSC2
#define ADC1SC2_ACFGT                    ADCSC2_ACFGT
#define ADC1SC2_ACFE                     ADCSC2_ACFE
#define ADC1SC2_ADTRG                    ADCSC2_ADTRG
#define ADC1SC2_ADACT                    ADCSC2_ADACT
#define ADC1SC2_ACFGT_MASK               ADCSC2_ACFGT_MASK
#define ADC1SC2_ACFE_MASK                ADCSC2_ACFE_MASK
#define ADC1SC2_ADTRG_MASK               ADCSC2_ADTRG_MASK
#define ADC1SC2_ADACT_MASK               ADCSC2_ADACT_MASK
#define ADC1RH                           ADCRH
#define ADC1RH_ADR8                      ADCRH_ADR8
#define ADC1RH_ADR9                      ADCRH_ADR9
#define ADC1RH_ADR10                     ADCRH_ADR10
#define ADC1RH_ADR11                     ADCRH_ADR11
#define ADC1RH_ADR_8                     ADCRH_ADR_8
#define ADC1RH_ADR                       ADCRH_ADR
#define ADC1RH_ADR8_MASK                 ADCRH_ADR8_MASK
#define ADC1RH_ADR9_MASK                 ADCRH_ADR9_MASK
#define ADC1RH_ADR10_MASK                ADCRH_ADR10_MASK
#define ADC1RH_ADR11_MASK                ADCRH_ADR11_MASK
#define ADC1RH_ADR_8_MASK                ADCRH_ADR_8_MASK
#define ADC1RH_ADR_8_BITNUM              ADCRH_ADR_8_BITNUM
#define ADC1RL                           ADCRL
#define ADC1RL_ADR0                      ADCRL_ADR0
#define ADC1RL_ADR1                      ADCRL_ADR1
#define ADC1RL_ADR2                      ADCRL_ADR2
#define ADC1RL_ADR3                      ADCRL_ADR3
#define ADC1RL_ADR4                      ADCRL_ADR4
#define ADC1RL_ADR5                      ADCRL_ADR5
#define ADC1RL_ADR6                      ADCRL_ADR6
#define ADC1RL_ADR7                      ADCRL_ADR7
#define ADC1RL_ADR0_MASK                 ADCRL_ADR0_MASK
#define ADC1RL_ADR1_MASK                 ADCRL_ADR1_MASK
#define ADC1RL_ADR2_MASK                 ADCRL_ADR2_MASK
#define ADC1RL_ADR3_MASK                 ADCRL_ADR3_MASK
#define ADC1RL_ADR4_MASK                 ADCRL_ADR4_MASK
#define ADC1RL_ADR5_MASK                 ADCRL_ADR5_MASK
#define ADC1RL_ADR6_MASK                 ADCRL_ADR6_MASK
#define ADC1RL_ADR7_MASK                 ADCRL_ADR7_MASK
#define ADC1R                            ADCR
#define ADC1R_ADR0                       ADCR_ADR0
#define ADC1R_ADR1                       ADCR_ADR1
#define ADC1R_ADR2                       ADCR_ADR2
#define ADC1R_ADR3                       ADCR_ADR3
#define ADC1R_ADR4                       ADCR_ADR4
#define ADC1R_ADR5                       ADCR_ADR5
#define ADC1R_ADR6                       ADCR_ADR6
#define ADC1R_ADR7                       ADCR_ADR7
#define ADC1R_ADR8                       ADCR_ADR8
#define ADC1R_ADR9                       ADCR_ADR9
#define ADC1R_ADR10                      ADCR_ADR10
#define ADC1R_ADR11                      ADCR_ADR11
#define ADC1R_ADR                        ADCR_ADR
#define ADC1R_ADR0_MASK                  ADCR_ADR0_MASK
#define ADC1R_ADR1_MASK                  ADCR_ADR1_MASK
#define ADC1R_ADR2_MASK                  ADCR_ADR2_MASK
#define ADC1R_ADR3_MASK                  ADCR_ADR3_MASK
#define ADC1R_ADR4_MASK                  ADCR_ADR4_MASK
#define ADC1R_ADR5_MASK                  ADCR_ADR5_MASK
#define ADC1R_ADR6_MASK                  ADCR_ADR6_MASK
#define ADC1R_ADR7_MASK                  ADCR_ADR7_MASK
#define ADC1R_ADR8_MASK                  ADCR_ADR8_MASK
#define ADC1R_ADR9_MASK                  ADCR_ADR9_MASK
#define ADC1R_ADR10_MASK                 ADCR_ADR10_MASK
#define ADC1R_ADR11_MASK                 ADCR_ADR11_MASK
#define ADC1R_ADR_MASK                   ADCR_ADR_MASK
#define ADC1R_ADR_BITNUM                 ADCR_ADR_BITNUM
#define ADC1CVH                          ADCCVH
#define ADC1CVH_ADCV8                    ADCCVH_ADCV8
#define ADC1CVH_ADCV9                    ADCCVH_ADCV9
#define ADC1CVH_ADCV10                   ADCCVH_ADCV10
#define ADC1CVH_ADCV11                   ADCCVH_ADCV11
#define ADC1CVH_ADCV_8                   ADCCVH_ADCV_8
#define ADC1CVH_ADCV                     ADCCVH_ADCV
#define ADC1CVH_ADCV8_MASK               ADCCVH_ADCV8_MASK
#define ADC1CVH_ADCV9_MASK               ADCCVH_ADCV9_MASK
#define ADC1CVH_ADCV10_MASK              ADCCVH_ADCV10_MASK
#define ADC1CVH_ADCV11_MASK              ADCCVH_ADCV11_MASK
#define ADC1CVH_ADCV_8_MASK              ADCCVH_ADCV_8_MASK
#define ADC1CVH_ADCV_8_BITNUM            ADCCVH_ADCV_8_BITNUM
#define ADC1CVL                          ADCCVL
#define ADC1CVL_ADCV0                    ADCCVL_ADCV0
#define ADC1CVL_ADCV1                    ADCCVL_ADCV1
#define ADC1CVL_ADCV2                    ADCCVL_ADCV2
#define ADC1CVL_ADCV3                    ADCCVL_ADCV3
#define ADC1CVL_ADCV4                    ADCCVL_ADCV4
#define ADC1CVL_ADCV5                    ADCCVL_ADCV5
#define ADC1CVL_ADCV6                    ADCCVL_ADCV6
#define ADC1CVL_ADCV7                    ADCCVL_ADCV7
#define ADC1CVL_ADCV0_MASK               ADCCVL_ADCV0_MASK
#define ADC1CVL_ADCV1_MASK               ADCCVL_ADCV1_MASK
#define ADC1CVL_ADCV2_MASK               ADCCVL_ADCV2_MASK
#define ADC1CVL_ADCV3_MASK               ADCCVL_ADCV3_MASK
#define ADC1CVL_ADCV4_MASK               ADCCVL_ADCV4_MASK
#define ADC1CVL_ADCV5_MASK               ADCCVL_ADCV5_MASK
#define ADC1CVL_ADCV6_MASK               ADCCVL_ADCV6_MASK
#define ADC1CVL_ADCV7_MASK               ADCCVL_ADCV7_MASK
#define ADC1CV                           ADCCV
#define ADC1CV_ADCV0                     ADCCV_ADCV0
#define ADC1CV_ADCV1                     ADCCV_ADCV1
#define ADC1CV_ADCV2                     ADCCV_ADCV2
#define ADC1CV_ADCV3                     ADCCV_ADCV3
#define ADC1CV_ADCV4                     ADCCV_ADCV4
#define ADC1CV_ADCV5                     ADCCV_ADCV5
#define ADC1CV_ADCV6                     ADCCV_ADCV6
#define ADC1CV_ADCV7                     ADCCV_ADCV7
#define ADC1CV_ADCV8                     ADCCV_ADCV8
#define ADC1CV_ADCV9                     ADCCV_ADCV9
#define ADC1CV_ADCV10                    ADCCV_ADCV10
#define ADC1CV_ADCV11                    ADCCV_ADCV11
#define ADC1CV_ADCV                      ADCCV_ADCV
#define ADC1CV_ADCV0_MASK                ADCCV_ADCV0_MASK
#define ADC1CV_ADCV1_MASK                ADCCV_ADCV1_MASK
#define ADC1CV_ADCV2_MASK                ADCCV_ADCV2_MASK
#define ADC1CV_ADCV3_MASK                ADCCV_ADCV3_MASK
#define ADC1CV_ADCV4_MASK                ADCCV_ADCV4_MASK
#define ADC1CV_ADCV5_MASK                ADCCV_ADCV5_MASK
#define ADC1CV_ADCV6_MASK                ADCCV_ADCV6_MASK
#define ADC1CV_ADCV7_MASK                ADCCV_ADCV7_MASK
#define ADC1CV_ADCV8_MASK                ADCCV_ADCV8_MASK
#define ADC1CV_ADCV9_MASK                ADCCV_ADCV9_MASK
#define ADC1CV_ADCV10_MASK               ADCCV_ADCV10_MASK
#define ADC1CV_ADCV11_MASK               ADCCV_ADCV11_MASK
#define ADC1CV_ADCV_MASK                 ADCCV_ADCV_MASK
#define ADC1CV_ADCV_BITNUM               ADCCV_ADCV_BITNUM
#define ADC1CFG                          ADCCFG
#define ADC1CFG_ADICLK0                  ADCCFG_ADICLK0
#define ADC1CFG_ADICLK1                  ADCCFG_ADICLK1
#define ADC1CFG_MODE0                    ADCCFG_MODE0
#define ADC1CFG_MODE1                    ADCCFG_MODE1
#define ADC1CFG_ADLSMP                   ADCCFG_ADLSMP
#define ADC1CFG_ADIV0                    ADCCFG_ADIV0
#define ADC1CFG_ADIV1                    ADCCFG_ADIV1
#define ADC1CFG_ADLPC                    ADCCFG_ADLPC
#define ADC1CFG_ADICLK                   ADCCFG_ADICLK
#define ADC1CFG_MODE                     ADCCFG_MODE
#define ADC1CFG_ADIV                     ADCCFG_ADIV
#define ADC1CFG_ADICLK0_MASK             ADCCFG_ADICLK0_MASK
#define ADC1CFG_ADICLK1_MASK             ADCCFG_ADICLK1_MASK
#define ADC1CFG_MODE0_MASK               ADCCFG_MODE0_MASK
#define ADC1CFG_MODE1_MASK               ADCCFG_MODE1_MASK
#define ADC1CFG_ADLSMP_MASK              ADCCFG_ADLSMP_MASK
#define ADC1CFG_ADIV0_MASK               ADCCFG_ADIV0_MASK
#define ADC1CFG_ADIV1_MASK               ADCCFG_ADIV1_MASK
#define ADC1CFG_ADLPC_MASK               ADCCFG_ADLPC_MASK
#define ADC1CFG_ADICLK_MASK              ADCCFG_ADICLK_MASK
#define ADC1CFG_ADICLK_BITNUM            ADCCFG_ADICLK_BITNUM
#define ADC1CFG_MODE_MASK                ADCCFG_MODE_MASK
#define ADC1CFG_MODE_BITNUM              ADCCFG_MODE_BITNUM
#define ADC1CFG_ADIV_MASK                ADCCFG_ADIV_MASK
#define ADC1CFG_ADIV_BITNUM              ADCCFG_ADIV_BITNUM
#pragma options align=reset

#endif
/*lint -restore  +esym(961,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
