/* Based on CPU DB MC9S12ZVML128_64, version 3.00.000 (RegistersPrg V2.33) */
/*
** ###################################################################
**     Filename  : mc9s12zvml128.h
**     Processor : MC9S12ZVML128MKH
**     FileFormat: V2.33
**     DataSheet : Rev. 1.2 23 APR 2013
**     Compiler  : CodeWarrior compiler
**     Date/Time : 6/27/2013, 9:39 AM
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 12.1.2012, V3.00.0:
**              - Registers updated according to the new reference manual revision - Rev. 0.09, 12 Dec 2011
**              - ECC: Removed registers ECCADDRx. 
**              - DBG: Data and data mask registers listed with indexes 0-3. Corrected bit indexing of DBGAD, DBGADM, DBGCD, DBGCDM registers.
**              - PIM: Changed the bitnames of MODRR0/1/2 to more meaningful names. Corrected the address of PIMMISC register.
**              - FTMRZ: Removed wait state description (WSTAT). Register NVFPSTAT changed to FPROTKEY.
**              - PMF: Bits VLMODE[0:1] merged to the VLMODE group. Bits ISENS[0:1] merged to the ISENS group.
**              - CPMU: Removed illegal address reset flag (ILAF).
**      - 25.06.2012, V3.00.1:
**              - ADC0,ADC1: Added pointers to the 24-bit registers ADCxCBP, ADCxRBP.
**              - CAN: Added CAN0 module
**              - DBG: Added pointers to the 24-bit registers DBGAA, DBGBA, DBGCA, DBGDA.
**              - MMC: Added pointer to the 24-bit register MMCPC.
**              - PTU: Added pointer to the 24-bit register PTUPTR.
**              - SRAM_ECC: Added pointer to the 24-bit register ECCDPTR.
**      - 04.09.2012, V3.00.2:
**              - Updates for new silicon revision (V2.0)
**              - Registers updated according to the new reference manual revision - Rev. 0.13, 03 Aug 2012
**              - Removed X-GATE reference and registers: INT_XGPRIO, INT_CFDATAx[RQST].
**              - FTMRZ: Added wait state control bits WSTATACK, WSTAT. Removed double bit fault detect interrupt bits: DFDIE, rename DFDIF to DFDF.
**              - ADC: Fix RIDX_IMD size. 
**              - GDU: New module version (GDUV2), new module base address (0x6A0). Rename GCSxE bits to GCSEx, rename GCSxO bits to GCSOx, added overcurrent interrupt enable bit GOCIE, rename GDUPHS register to GDUSTAT and added extra status bits GOCS, GHHDS, GLVLSS. Added extra flags to GDUF register: GSUF, GOCIF. Added overcurrent registers: GDUOC0, GDUOC1.
**              - CPMU: Added CPMUOSC2 register.
**      - 16.05.2013, V3.00.3:
**              - Updates for new silicon revision (V3.0)
**              - Registers updated according to the new reference manual revision - Rev. 1.2, 23 APR 2013
**              - CPU: Removed mapping of VRL to PAD7
**              - PARTID: New part id value
**              - SCI: Moved bits IREN, TNP1, TNP0 to SCIACR22 register. Added bits SBR15, SBR14, SBR13 to SCIBDH1 register.
**              - LINPHY: Removed LPOC bit and added LPDT bit to LPSR register. Moved LPOCIE bit and added LPDTIE bit to LPIE register. Moved LPOCIF bit and added LPDTIF bit to LPIF register.
**
**     File-Format-Revisions:
**               - none
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC9S12ZVML128_H
#define _MC9S12ZVML128_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma bfield_gap_limit -1 /*this guarantee correct bitfield positions*/

/**************** interrupt vector numbers ****************/
#define VectorNumber_VReserved123       123U
#define VectorNumber_VReserved122       122U
#define VectorNumber_VReserved121       121U
#define VectorNumber_VReserved120       120U
#define VectorNumber_VReserved119       119U
#define VectorNumber_VReserved118       118U
#define VectorNumber_VReserved117       117U
#define VectorNumber_VReserved116       116U
#define VectorNumber_VReserved115       115U
#define VectorNumber_VReserved114       114U
#define VectorNumber_VReserved113       113U
#define VectorNumber_VReserved112       112U
#define VectorNumber_VReserved111       111U
#define VectorNumber_VReserved110       110U
#define VectorNumber_VReserved109       109U
#define VectorNumber_VReserved108       108U
#define VectorNumber_VReserved107       107U
#define VectorNumber_VReserved106       106U
#define VectorNumber_VReserved105       105U
#define VectorNumber_VReserved104       104U
#define VectorNumber_VReserved103       103U
#define VectorNumber_VReserved102       102U
#define VectorNumber_VReserved101       101U
#define VectorNumber_VReserved100       100U
#define VectorNumber_VReserved99        99U
#define VectorNumber_VReserved98        98U
#define VectorNumber_VReserved97        97U
#define VectorNumber_VReserved96        96U
#define VectorNumber_VReserved95        95U
#define VectorNumber_VReserved94        94U
#define VectorNumber_VReserved93        93U
#define VectorNumber_VReserved92        92U
#define VectorNumber_VReserved91        91U
#define VectorNumber_VReserved90        90U
#define VectorNumber_VReserved89        89U
#define VectorNumber_VReserved88        88U
#define VectorNumber_VReserved87        87U
#define VectorNumber_VReserved86        86U
#define VectorNumber_VReserved85        85U
#define VectorNumber_VReserved84        84U
#define VectorNumber_VReserved83        83U
#define VectorNumber_VReserved82        82U
#define VectorNumber_VReserved81        81U
#define VectorNumber_VReserved80        80U
#define VectorNumber_Vpmfro             79U
#define VectorNumber_Vpmffault          78U
#define VectorNumber_Vpmfrc             77U
#define VectorNumber_Vpmfrb             76U
#define VectorNumber_Vpmfra             75U
#define VectorNumber_VReserved74        74U
#define VectorNumber_VReserved73        73U
#define VectorNumber_VReserved72        72U
#define VectorNumber_Vptutg1dn          71U
#define VectorNumber_Vptutg0dn          70U
#define VectorNumber_Vptutg1err         69U
#define VectorNumber_Vptutg0err         68U
#define VectorNumber_Vpturo             67U
#define VectorNumber_Vportad            66U
#define VectorNumber_VReserved65        65U
#define VectorNumber_Vhti               64U
#define VectorNumber_Vapi               63U
#define VectorNumber_Vlvi               62U
#define VectorNumber_Vevddx             61U
#define VectorNumber_Vportp             60U
#define VectorNumber_VReserved59        59U
#define VectorNumber_Vadc1conv_compl    58U
#define VectorNumber_Vadc1conv_seq_abrt 57U
#define VectorNumber_Vadc1err           56U
#define VectorNumber_VReserved55        55U
#define VectorNumber_Vports             54U
#define VectorNumber_VReserved53        53U
#define VectorNumber_VReserved52        52U
#define VectorNumber_VReserved51        51U
#define VectorNumber_VReserved50        50U
#define VectorNumber_Vgdu_vld           49U
#define VectorNumber_Vgdu_des_err       48U
#define VectorNumber_Vbats              47U
#define VectorNumber_Vlinphy0           46U
#define VectorNumber_VReserved45        45U
#define VectorNumber_VReserved44        44U
#define VectorNumber_Vcan0tx            43U
#define VectorNumber_Vcan0rx            42U
#define VectorNumber_Vcan0err           41U
#define VectorNumber_Vcan0wkup          40U
#define VectorNumber_Vflash             39U
#define VectorNumber_Vflasherr          38U
#define VectorNumber_VReserved37        37U
#define VectorNumber_VReserved36        36U
#define VectorNumber_VRAM_err           35U
#define VectorNumber_VReserved34        34U
#define VectorNumber_VReserved33        33U
#define VectorNumber_Vcpmuplllck        32U
#define VectorNumber_Vcpmuosc           31U
#define VectorNumber_Vadc0conv_compl    30U
#define VectorNumber_Vadc0conv_seq_abrt 29U
#define VectorNumber_Vadc0err           28U
#define VectorNumber_VReserved27        27U
#define VectorNumber_VReserved26        26U
#define VectorNumber_Vsci1              25U
#define VectorNumber_Vsci0              24U
#define VectorNumber_Vspi0              23U
#define VectorNumber_VReserved22        22U
#define VectorNumber_VReserved21        21U
#define VectorNumber_Vtim0ovf           20U
#define VectorNumber_VReserved19        19U
#define VectorNumber_VReserved18        18U
#define VectorNumber_VReserved17        17U
#define VectorNumber_VReserved16        16U
#define VectorNumber_Vtim0ch3           15U
#define VectorNumber_Vtim0ch2           14U
#define VectorNumber_Vtim0ch1           13U
#define VectorNumber_Vtim0ch0           12U
#define VectorNumber_Vrti               11U
#define VectorNumber_Virq               10U
#define VectorNumber_Vxirq              9U
#define VectorNumber_Vsi                8U
#define VectorNumber_VReserved7         7U
#define VectorNumber_VReserved6         6U
#define VectorNumber_Vme                5U
#define VectorNumber_Vsys               4U
#define VectorNumber_Vswi               3U
#define VectorNumber_Vtrap              2U
#define VectorNumber_Vspare             1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define VReserved123                    0x00FFFE10UL
#define VReserved122                    0x00FFFE14UL
#define VReserved121                    0x00FFFE18UL
#define VReserved120                    0x00FFFE1CUL
#define VReserved119                    0x00FFFE20UL
#define VReserved118                    0x00FFFE24UL
#define VReserved117                    0x00FFFE28UL
#define VReserved116                    0x00FFFE2CUL
#define VReserved115                    0x00FFFE30UL
#define VReserved114                    0x00FFFE34UL
#define VReserved113                    0x00FFFE38UL
#define VReserved112                    0x00FFFE3CUL
#define VReserved111                    0x00FFFE40UL
#define VReserved110                    0x00FFFE44UL
#define VReserved109                    0x00FFFE48UL
#define VReserved108                    0x00FFFE4CUL
#define VReserved107                    0x00FFFE50UL
#define VReserved106                    0x00FFFE54UL
#define VReserved105                    0x00FFFE58UL
#define VReserved104                    0x00FFFE5CUL
#define VReserved103                    0x00FFFE60UL
#define VReserved102                    0x00FFFE64UL
#define VReserved101                    0x00FFFE68UL
#define VReserved100                    0x00FFFE6CUL
#define VReserved99                     0x00FFFE70UL
#define VReserved98                     0x00FFFE74UL
#define VReserved97                     0x00FFFE78UL
#define VReserved96                     0x00FFFE7CUL
#define VReserved95                     0x00FFFE80UL
#define VReserved94                     0x00FFFE84UL
#define VReserved93                     0x00FFFE88UL
#define VReserved92                     0x00FFFE8CUL
#define VReserved91                     0x00FFFE90UL
#define VReserved90                     0x00FFFE94UL
#define VReserved89                     0x00FFFE98UL
#define VReserved88                     0x00FFFE9CUL
#define VReserved87                     0x00FFFEA0UL
#define VReserved86                     0x00FFFEA4UL
#define VReserved85                     0x00FFFEA8UL
#define VReserved84                     0x00FFFEACUL
#define VReserved83                     0x00FFFEB0UL
#define VReserved82                     0x00FFFEB4UL
#define VReserved81                     0x00FFFEB8UL
#define VReserved80                     0x00FFFEBCUL
#define Vpmfro                          0x00FFFEC0UL
#define Vpmffault                       0x00FFFEC4UL
#define Vpmfrc                          0x00FFFEC8UL
#define Vpmfrb                          0x00FFFECCUL
#define Vpmfra                          0x00FFFED0UL
#define VReserved74                     0x00FFFED4UL
#define VReserved73                     0x00FFFED8UL
#define VReserved72                     0x00FFFEDCUL
#define Vptutg1dn                       0x00FFFEE0UL
#define Vptutg0dn                       0x00FFFEE4UL
#define Vptutg1err                      0x00FFFEE8UL
#define Vptutg0err                      0x00FFFEECUL
#define Vpturo                          0x00FFFEF0UL
#define Vportad                         0x00FFFEF4UL
#define VReserved65                     0x00FFFEF8UL
#define Vhti                            0x00FFFEFCUL
#define Vapi                            0x00FFFF00UL
#define Vlvi                            0x00FFFF04UL
#define Vevddx                          0x00FFFF08UL
#define Vportp                          0x00FFFF0CUL
#define VReserved59                     0x00FFFF10UL
#define Vadc1conv_compl                 0x00FFFF14UL
#define Vadc1conv_seq_abrt              0x00FFFF18UL
#define Vadc1err                        0x00FFFF1CUL
#define VReserved55                     0x00FFFF20UL
#define Vports                          0x00FFFF24UL
#define VReserved53                     0x00FFFF28UL
#define VReserved52                     0x00FFFF2CUL
#define VReserved51                     0x00FFFF30UL
#define VReserved50                     0x00FFFF34UL
#define Vgdu_vld                        0x00FFFF38UL
#define Vgdu_des_err                    0x00FFFF3CUL
#define Vbats                           0x00FFFF40UL
#define Vlinphy0                        0x00FFFF44UL
#define VReserved45                     0x00FFFF48UL
#define VReserved44                     0x00FFFF4CUL
#define Vcan0tx                         0x00FFFF50UL
#define Vcan0rx                         0x00FFFF54UL
#define Vcan0err                        0x00FFFF58UL
#define Vcan0wkup                       0x00FFFF5CUL
#define Vflash                          0x00FFFF60UL
#define Vflasherr                       0x00FFFF64UL
#define VReserved37                     0x00FFFF68UL
#define VReserved36                     0x00FFFF6CUL
#define VRAM_err                        0x00FFFF70UL
#define VReserved34                     0x00FFFF74UL
#define VReserved33                     0x00FFFF78UL
#define Vcpmuplllck                     0x00FFFF7CUL
#define Vcpmuosc                        0x00FFFF80UL
#define Vadc0conv_compl                 0x00FFFF84UL
#define Vadc0conv_seq_abrt              0x00FFFF88UL
#define Vadc0err                        0x00FFFF8CUL
#define VReserved27                     0x00FFFF90UL
#define VReserved26                     0x00FFFF94UL
#define Vsci1                           0x00FFFF98UL
#define Vsci0                           0x00FFFF9CUL
#define Vspi0                           0x00FFFFA0UL
#define VReserved22                     0x00FFFFA4UL
#define VReserved21                     0x00FFFFA8UL
#define Vtim0ovf                        0x00FFFFACUL
#define VReserved19                     0x00FFFFB0UL
#define VReserved18                     0x00FFFFB4UL
#define VReserved17                     0x00FFFFB8UL
#define VReserved16                     0x00FFFFBCUL
#define Vtim0ch3                        0x00FFFFC0UL
#define Vtim0ch2                        0x00FFFFC4UL
#define Vtim0ch1                        0x00FFFFC8UL
#define Vtim0ch0                        0x00FFFFCCUL
#define Vrti                            0x00FFFFD0UL
#define Virq                            0x00FFFFD4UL
#define Vxirq                           0x00FFFFD8UL
#define Vsi                             0x00FFFFDCUL
#define VReserved7                      0x00FFFFE0UL
#define VReserved6                      0x00FFFFE4UL
#define Vme                             0x00FFFFE8UL
#define Vsys                            0x00FFFFECUL
#define Vswi                            0x00FFFFF0UL
#define Vtrap                           0x00FFFFF4UL
#define Vspare                          0x00FFFFF8UL
#define Vreset                          0x00FFFFFCUL

/**************** registers I/O map ****************/

/*** PARTID - Part ID Register; 0x00000000 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** PARTID0 - Part ID Register 0; 0x00000000 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :8;                                       /* Part ID 0 */
      } Bits;
    } PARTID0STR;
    #define PARTID0                     _PARTID.Overlap_STR.PARTID0STR.Byte
    #define PARTID0_ID0                 _PARTID.Overlap_STR.PARTID0STR.Bits.ID0
    /* PARTID_ARR: Access 4 PARTIDx registers in an array */
    #define PARTID_ARR                  ((volatile byte *) &PARTID0)
    
    #define PARTID0_ID0_MASK            255U
    #define PARTID0_ID0_BITNUM          0U
    

    /*** PARTID1 - Part ID Register 1; 0x00000001 ***/
    union {
      byte Byte;
      struct {
        byte ID1         :8;                                       /* Part ID 1 */
      } Bits;
    } PARTID1STR;
    #define PARTID1                     _PARTID.Overlap_STR.PARTID1STR.Byte
    #define PARTID1_ID1                 _PARTID.Overlap_STR.PARTID1STR.Bits.ID1
    
    #define PARTID1_ID1_MASK            255U
    #define PARTID1_ID1_BITNUM          0U
    

    /*** PARTID2 - Part ID Register 2; 0x00000002 ***/
    union {
      byte Byte;
      struct {
        byte ID2         :8;                                       /* Part ID 2 */
      } Bits;
    } PARTID2STR;
    #define PARTID2                     _PARTID.Overlap_STR.PARTID2STR.Byte
    #define PARTID2_ID2                 _PARTID.Overlap_STR.PARTID2STR.Bits.ID2
    
    #define PARTID2_ID2_MASK            255U
    #define PARTID2_ID2_BITNUM          0U
    

    /*** PARTID3 - Part ID Register 3; 0x00000003 ***/
    union {
      byte Byte;
      struct {
        byte ID3         :8;                                       /* Part ID 3 */
      } Bits;
    } PARTID3STR;
    #define PARTID3                     _PARTID.Overlap_STR.PARTID3STR.Byte
    #define PARTID3_ID3                 _PARTID.Overlap_STR.PARTID3STR.Bits.ID3
    
    #define PARTID3_ID3_MASK            255U
    #define PARTID3_ID3_BITNUM          0U
    
  } Overlap_STR;

} PARTIDSTR;
extern volatile PARTIDSTR _PARTID @0x00000000;
#define PARTID                          _PARTID.Dword


/*** IVBR - Interrupt Vector Base Register; 0x00000010 ***/
typedef union {
  word Word;
  struct {
    word             :1; 
    word IVB_ADDR    :15;                                      /* Interrupt Vector Base Address Bits */
  } Bits;
} IVBRSTR;
extern volatile IVBRSTR _IVBR @0x00000010;
#define IVBR                            _IVBR.Word
#define IVBR_IVB_ADDR                   _IVBR.Bits.IVB_ADDR

#define IVBR_IVB_ADDR_MASK              65534U
#define IVBR_IVB_ADDR_BITNUM            1U


/*** INT_CFADDR - Interrupt Request Configuration Address Register; 0x00000017 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte INT_CFADDR_grp :4;                                    /* Interrupt Request Configuration Data Register Select Bits */ /*Warning: group name is duplicated with register name*/
    byte             :1; 
  } Bits;
} INT_CFADDRSTR;
extern volatile INT_CFADDRSTR _INT_CFADDR @0x00000017;
#define INT_CFADDR                      _INT_CFADDR.Byte
#define INT_CFADDR_INT_CFADDR           _INT_CFADDR.Bits.INT_CFADDR_grp

#define INT_CFADDR_INT_CFADDR_MASK      120U
#define INT_CFADDR_INT_CFADDR_BITNUM    3U


/*** INT_CFDATA0 - Interrupt Request Configuration Data Register 0; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_CFDATA0STR;
extern volatile INT_CFDATA0STR _INT_CFDATA0 @0x00000018;
#define INT_CFDATA0                     _INT_CFDATA0.Byte
#define INT_CFDATA0_PRIOLVL             _INT_CFDATA0.Bits.PRIOLVL
/* INT_CFDATA_ARR: Access 8 INT_CFDATAx registers in an array */
#define INT_CFDATA_ARR                  ((volatile byte *) &INT_CFDATA0)

#define INT_CFDATA0_PRIOLVL_MASK        7U
#define INT_CFDATA0_PRIOLVL_BITNUM      0U


/*** INT_CFDATA1 - Interrupt Request Configuration Data Register 1; 0x00000019 ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_CFDATA1STR;
extern volatile INT_CFDATA1STR _INT_CFDATA1 @0x00000019;
#define INT_CFDATA1                     _INT_CFDATA1.Byte
#define INT_CFDATA1_PRIOLVL             _INT_CFDATA1.Bits.PRIOLVL

#define INT_CFDATA1_PRIOLVL_MASK        7U
#define INT_CFDATA1_PRIOLVL_BITNUM      0U


/*** INT_CFDATA2 - Interrupt Request Configuration Data Register 2; 0x0000001A ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_CFDATA2STR;
extern volatile INT_CFDATA2STR _INT_CFDATA2 @0x0000001A;
#define INT_CFDATA2                     _INT_CFDATA2.Byte
#define INT_CFDATA2_PRIOLVL             _INT_CFDATA2.Bits.PRIOLVL

#define INT_CFDATA2_PRIOLVL_MASK        7U
#define INT_CFDATA2_PRIOLVL_BITNUM      0U


/*** INT_CFDATA3 - Interrupt Request Configuration Data Register 3; 0x0000001B ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_CFDATA3STR;
extern volatile INT_CFDATA3STR _INT_CFDATA3 @0x0000001B;
#define INT_CFDATA3                     _INT_CFDATA3.Byte
#define INT_CFDATA3_PRIOLVL             _INT_CFDATA3.Bits.PRIOLVL

#define INT_CFDATA3_PRIOLVL_MASK        7U
#define INT_CFDATA3_PRIOLVL_BITNUM      0U


/*** INT_CFDATA4 - Interrupt Request Configuration Data Register 4; 0x0000001C ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_CFDATA4STR;
extern volatile INT_CFDATA4STR _INT_CFDATA4 @0x0000001C;
#define INT_CFDATA4                     _INT_CFDATA4.Byte
#define INT_CFDATA4_PRIOLVL             _INT_CFDATA4.Bits.PRIOLVL

#define INT_CFDATA4_PRIOLVL_MASK        7U
#define INT_CFDATA4_PRIOLVL_BITNUM      0U


/*** INT_CFDATA5 - Interrupt Request Configuration Data Register 5; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_CFDATA5STR;
extern volatile INT_CFDATA5STR _INT_CFDATA5 @0x0000001D;
#define INT_CFDATA5                     _INT_CFDATA5.Byte
#define INT_CFDATA5_PRIOLVL             _INT_CFDATA5.Bits.PRIOLVL

#define INT_CFDATA5_PRIOLVL_MASK        7U
#define INT_CFDATA5_PRIOLVL_BITNUM      0U


/*** INT_CFDATA6 - Interrupt Request Configuration Data Register 6; 0x0000001E ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_CFDATA6STR;
extern volatile INT_CFDATA6STR _INT_CFDATA6 @0x0000001E;
#define INT_CFDATA6                     _INT_CFDATA6.Byte
#define INT_CFDATA6_PRIOLVL             _INT_CFDATA6.Bits.PRIOLVL

#define INT_CFDATA6_PRIOLVL_MASK        7U
#define INT_CFDATA6_PRIOLVL_BITNUM      0U


/*** INT_CFDATA7 - Interrupt Request Configuration Data Register 7; 0x0000001F ***/
typedef union {
  byte Byte;
  struct {
    byte PRIOLVL     :3;                                       /* Interrupt Request Priority Level Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} INT_CFDATA7STR;
extern volatile INT_CFDATA7STR _INT_CFDATA7 @0x0000001F;
#define INT_CFDATA7                     _INT_CFDATA7.Byte
#define INT_CFDATA7_PRIOLVL             _INT_CFDATA7.Bits.PRIOLVL

#define INT_CFDATA7_PRIOLVL_MASK        7U
#define INT_CFDATA7_PRIOLVL_BITNUM      0U


/*** MODE - Mode Register; 0x00000070 ***/
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
    byte MODC        :1;                                       /* Mode Select Bit */
  } Bits;
} MODESTR;
extern volatile MODESTR _MODE @0x00000070;
#define MODE                            _MODE.Byte
#define MODE_MODC                       _MODE.Bits.MODC

#define MODE_MODC_MASK                  128U


/*** MMCEC - Error code register; 0x00000080 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MMCECH - Error code register high; 0x00000080 ***/
    union {
      byte Byte;
      struct {
        byte TGT         :4;                                       /* Target Field */
        byte ITR         :4;                                       /* Initiator Field */
      } Bits;
    } MMCECHSTR;
    #define MMCECH                      _MMCEC.Overlap_STR.MMCECHSTR.Byte
    #define MMCECH_TGT                  _MMCEC.Overlap_STR.MMCECHSTR.Bits.TGT
    #define MMCECH_ITR                  _MMCEC.Overlap_STR.MMCECHSTR.Bits.ITR
    
    #define MMCECH_TGT_MASK             15U
    #define MMCECH_TGT_BITNUM           0U
    #define MMCECH_ITR_MASK             240U
    #define MMCECH_ITR_BITNUM           4U
    

    /*** MMCECL - Error code register low; 0x00000081 ***/
    union {
      byte Byte;
      struct {
        byte ERR         :4;                                       /* Error Type Field */
        byte ACC         :4;                                       /* Access Type Field */
      } Bits;
    } MMCECLSTR;
    #define MMCECL                      _MMCEC.Overlap_STR.MMCECLSTR.Byte
    #define MMCECL_ERR                  _MMCEC.Overlap_STR.MMCECLSTR.Bits.ERR
    #define MMCECL_ACC                  _MMCEC.Overlap_STR.MMCECLSTR.Bits.ACC
    
    #define MMCECL_ERR_MASK             15U
    #define MMCECL_ERR_BITNUM           0U
    #define MMCECL_ACC_MASK             240U
    #define MMCECL_ACC_BITNUM           4U
    
  } Overlap_STR;

  struct {
    word ERR         :4;                                       /* Error Type Field */
    word ACC         :4;                                       /* Access Type Field */
    word TGT         :4;                                       /* Target Field */
    word ITR         :4;                                       /* Initiator Field */
  } Bits;
} MMCECSTR;
extern volatile MMCECSTR _MMCEC @0x00000080;
#define MMCEC                           _MMCEC.Word
#define MMCEC_ERR                       _MMCEC.Bits.ERR
#define MMCEC_ACC                       _MMCEC.Bits.ACC
#define MMCEC_TGT                       _MMCEC.Bits.TGT
#define MMCEC_ITR                       _MMCEC.Bits.ITR

#define MMCEC_ERR_MASK                  15U
#define MMCEC_ERR_BITNUM                0U
#define MMCEC_ACC_MASK                  240U
#define MMCEC_ACC_BITNUM                4U
#define MMCEC_TGT_MASK                  3840U
#define MMCEC_TGT_BITNUM                8U
#define MMCEC_ITR_MASK                  61440U
#define MMCEC_ITR_BITNUM                12U


/*** MMCCCR - Captured S12ZCPU Condition Code Register Low; 0x00000082 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** MMCCCRH - Captured S12ZCPU Condition Code Register High; 0x00000082 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte CPUU        :1;                                       /* S12ZCPU User State Flag */
      } Bits;
    } MMCCCRHSTR;
    #define MMCCCRH                     _MMCCCR.Overlap_STR.MMCCCRHSTR.Byte
    #define MMCCCRH_CPUU                _MMCCCR.Overlap_STR.MMCCCRHSTR.Bits.CPUU
    
    #define MMCCCRH_CPUU_MASK           128U
    

    /*** MMCCCRL - Captured S12ZCPU Condition Code Register Low; 0x00000083 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte CPUI        :1;                                       /* S12ZCPU I-Interrupt Mask */
        byte             :1; 
        byte CPUX        :1;                                       /* S12ZCPU X-Interrupt Mask */
        byte             :1; 
      } Bits;
    } MMCCCRLSTR;
    #define MMCCCRL                     _MMCCCR.Overlap_STR.MMCCCRLSTR.Byte
    #define MMCCCRL_CPUI                _MMCCCR.Overlap_STR.MMCCCRLSTR.Bits.CPUI
    #define MMCCCRL_CPUX                _MMCCCR.Overlap_STR.MMCCCRLSTR.Bits.CPUX
    
    #define MMCCCRL_CPUI_MASK           16U
    #define MMCCCRL_CPUX_MASK           64U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word CPUI        :1;                                       /* S12ZCPU I-Interrupt Mask */
    word             :1; 
    word CPUX        :1;                                       /* S12ZCPU X-Interrupt Mask */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word CPUU        :1;                                       /* S12ZCPU User State Flag */
  } Bits;
} MMCCCRSTR;
extern volatile MMCCCRSTR _MMCCCR @0x00000082;
#define MMCCCR                          _MMCCCR.Word
#define MMCCCR_CPUI                     _MMCCCR.Bits.CPUI
#define MMCCCR_CPUX                     _MMCCCR.Bits.CPUX
#define MMCCCR_CPUU                     _MMCCCR.Bits.CPUU

#define MMCCCR_CPUI_MASK                16U
#define MMCCCR_CPUX_MASK                64U
#define MMCCCR_CPUU_MASK                32768U


/*** MMCPCH - Captured S12ZCPU Program Counter High; 0x00000085 ***/
typedef union {
  byte Byte;
  struct {
    byte CPUPC       :8;                                       /* S12ZCPU Program Counter Value */
  } Bits;
} MMCPCHSTR;
extern volatile MMCPCHSTR _MMCPCH @0x00000085;
#define MMCPCH                          _MMCPCH.Byte
#define MMCPCH_CPUPC                    _MMCPCH.Bits.CPUPC

#define MMCPCH_CPUPC_MASK               255U
#define MMCPCH_CPUPC_BITNUM             0U


/*** MMCPCM - Captured S12ZCPU Program Counter Middle; 0x00000086 ***/
typedef union {
  byte Byte;
  struct {
    byte CPUPC       :8;                                       /* S12ZCPU Program Counter Value */
  } Bits;
} MMCPCMSTR;
extern volatile MMCPCMSTR _MMCPCM @0x00000086;
#define MMCPCM                          _MMCPCM.Byte
#define MMCPCM_CPUPC                    _MMCPCM.Bits.CPUPC

#define MMCPCM_CPUPC_MASK               255U
#define MMCPCM_CPUPC_BITNUM             0U


/*** MMCPCL - Captured S12ZCPU Program Counter Low; 0x00000087 ***/
typedef union {
  byte Byte;
  struct {
    byte CPUPC       :8;                                       /* S12ZCPU Program Counter Value */
  } Bits;
} MMCPCLSTR;
extern volatile MMCPCLSTR _MMCPCL @0x00000087;
#define MMCPCL                          _MMCPCL.Byte
#define MMCPCL_CPUPC                    _MMCPCL.Bits.CPUPC

#define MMCPCL_CPUPC_MASK               255U
#define MMCPCL_CPUPC_BITNUM             0U


/*** DBGC1 - Debug Control Register 1; 0x00000100 ***/
typedef union {
  byte Byte;
  struct {
    byte EEVE        :2;                                       /* External Event Enable Bits */
    byte             :1; 
    byte BRKCPU      :1;                                       /* CPU Breakpoint Enable */
    byte BDMBP       :1;                                       /* Background Debug Mode Enable */
    byte             :1; 
    byte TRIG        :1;                                       /* Immediate Trigger Request Bit */
    byte ARM         :1;                                       /* Arm Bit */
  } Bits;
} DBGC1STR;
extern volatile DBGC1STR _DBGC1 @0x00000100;
#define DBGC1                           _DBGC1.Byte
#define DBGC1_EEVE                      _DBGC1.Bits.EEVE
#define DBGC1_BRKCPU                    _DBGC1.Bits.BRKCPU
#define DBGC1_BDMBP                     _DBGC1.Bits.BDMBP
#define DBGC1_TRIG                      _DBGC1.Bits.TRIG
#define DBGC1_ARM                       _DBGC1.Bits.ARM

#define DBGC1_EEVE_MASK                 3U
#define DBGC1_EEVE_BITNUM               0U
#define DBGC1_BRKCPU_MASK               8U
#define DBGC1_BDMBP_MASK                16U
#define DBGC1_TRIG_MASK                 64U
#define DBGC1_ARM_MASK                  128U


/*** DBGC2 - Debug Control Register 2; 0x00000101 ***/
typedef union {
  byte Byte;
  struct {
    byte ABCM        :2;                                       /* A and B Comparator Match Control */
    byte CDCM        :2;                                       /* C and D Comparator Match Control */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGC2STR;
extern volatile DBGC2STR _DBGC2 @0x00000101;
#define DBGC2                           _DBGC2.Byte
#define DBGC2_ABCM                      _DBGC2.Bits.ABCM
#define DBGC2_CDCM                      _DBGC2.Bits.CDCM

#define DBGC2_ABCM_MASK                 3U
#define DBGC2_ABCM_BITNUM               0U
#define DBGC2_CDCM_MASK                 12U
#define DBGC2_CDCM_BITNUM               2U


/*** DBGTCRH - Debug Trace Control Register High; 0x00000102 ***/
typedef union {
  byte Byte;
  struct {
    byte TALIGN      :2;                                       /* Trigger Align Bits */
    byte TRCMOD      :2;                                       /* Trace Mode Bits */
    byte TRANGE      :2;                                       /* Trace Range Bits */
    byte TSOURCE     :1;                                       /* Trace Source Control Bits */
    byte             :1; 
  } Bits;
} DBGTCRHSTR;
extern volatile DBGTCRHSTR _DBGTCRH @0x00000102;
#define DBGTCRH                         _DBGTCRH.Byte
#define DBGTCRH_TALIGN                  _DBGTCRH.Bits.TALIGN
#define DBGTCRH_TRCMOD                  _DBGTCRH.Bits.TRCMOD
#define DBGTCRH_TRANGE                  _DBGTCRH.Bits.TRANGE
#define DBGTCRH_TSOURCE                 _DBGTCRH.Bits.TSOURCE

#define DBGTCRH_TALIGN_MASK             3U
#define DBGTCRH_TALIGN_BITNUM           0U
#define DBGTCRH_TRCMOD_MASK             12U
#define DBGTCRH_TRCMOD_BITNUM           2U
#define DBGTCRH_TRANGE_MASK             48U
#define DBGTCRH_TRANGE_BITNUM           4U
#define DBGTCRH_TSOURCE_MASK            64U


/*** DBGTCRL - Debug Trace Control Register Low; 0x00000103 ***/
typedef union {
  byte Byte;
  struct {
    byte STAMP       :1;                                       /* Timestamp Enable */
    byte PROFILE     :1;                                       /* Profile Enable */
    byte PDOE        :1;                                       /* Profile Data Out Enable */
    byte DSTAMP      :1;                                       /* Comparator D Timestamp Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGTCRLSTR;
extern volatile DBGTCRLSTR _DBGTCRL @0x00000103;
#define DBGTCRL                         _DBGTCRL.Byte
#define DBGTCRL_STAMP                   _DBGTCRL.Bits.STAMP
#define DBGTCRL_PROFILE                 _DBGTCRL.Bits.PROFILE
#define DBGTCRL_PDOE                    _DBGTCRL.Bits.PDOE
#define DBGTCRL_DSTAMP                  _DBGTCRL.Bits.DSTAMP

#define DBGTCRL_STAMP_MASK              1U
#define DBGTCRL_PROFILE_MASK            2U
#define DBGTCRL_PDOE_MASK               4U
#define DBGTCRL_DSTAMP_MASK             8U


/*** DBGTB - Debug Trace Buffer Register; 0x00000104 ***/
typedef union {
  word Word;
  struct {
    word BIT0        :1;                                       /* Trace Buffer Data Bits */
    word BIT1        :1;                                       /* Trace Buffer Data Bit 1 */
    word BIT2        :1;                                       /* Trace Buffer Data Bit 2 */
    word BIT3        :1;                                       /* Trace Buffer Data Bit 3 */
    word BIT4        :1;                                       /* Trace Buffer Data Bit 4 */
    word BIT5        :1;                                       /* Trace Buffer Data Bit 5 */
    word BIT6        :1;                                       /* Trace Buffer Data Bit 6 */
    word BIT7        :1;                                       /* Trace Buffer Data Bit 7 */
    word BIT8        :1;                                       /* Trace Buffer Data Bit 8 */
    word BIT9        :1;                                       /* Trace Buffer Data Bit 9 */
    word BIT10       :1;                                       /* Trace Buffer Data Bit 10 */
    word BIT11       :1;                                       /* Trace Buffer Data Bit 11 */
    word BIT12       :1;                                       /* Trace Buffer Data Bit 12 */
    word BIT13       :1;                                       /* Trace Buffer Data Bit 13 */
    word BIT14       :1;                                       /* Trace Buffer Data Bit 14 */
    word BIT15       :1;                                       /* Trace Buffer Data Bit 15 */
  } Bits;
} DBGTBSTR;
extern volatile DBGTBSTR _DBGTB @0x00000104;
#define DBGTB                           _DBGTB.Word
#define DBGTB_BIT0                      _DBGTB.Bits.BIT0
#define DBGTB_BIT1                      _DBGTB.Bits.BIT1
#define DBGTB_BIT2                      _DBGTB.Bits.BIT2
#define DBGTB_BIT3                      _DBGTB.Bits.BIT3
#define DBGTB_BIT4                      _DBGTB.Bits.BIT4
#define DBGTB_BIT5                      _DBGTB.Bits.BIT5
#define DBGTB_BIT6                      _DBGTB.Bits.BIT6
#define DBGTB_BIT7                      _DBGTB.Bits.BIT7
#define DBGTB_BIT8                      _DBGTB.Bits.BIT8
#define DBGTB_BIT9                      _DBGTB.Bits.BIT9
#define DBGTB_BIT10                     _DBGTB.Bits.BIT10
#define DBGTB_BIT11                     _DBGTB.Bits.BIT11
#define DBGTB_BIT12                     _DBGTB.Bits.BIT12
#define DBGTB_BIT13                     _DBGTB.Bits.BIT13
#define DBGTB_BIT14                     _DBGTB.Bits.BIT14
#define DBGTB_BIT15                     _DBGTB.Bits.BIT15

#define DBGTB_BIT0_MASK                 1U
#define DBGTB_BIT1_MASK                 2U
#define DBGTB_BIT2_MASK                 4U
#define DBGTB_BIT3_MASK                 8U
#define DBGTB_BIT4_MASK                 16U
#define DBGTB_BIT5_MASK                 32U
#define DBGTB_BIT6_MASK                 64U
#define DBGTB_BIT7_MASK                 128U
#define DBGTB_BIT8_MASK                 256U
#define DBGTB_BIT9_MASK                 512U
#define DBGTB_BIT10_MASK                1024U
#define DBGTB_BIT11_MASK                2048U
#define DBGTB_BIT12_MASK                4096U
#define DBGTB_BIT13_MASK                8192U
#define DBGTB_BIT14_MASK                16384U
#define DBGTB_BIT15_MASK                32768U


/*** DBGCNT - Debug Count Register; 0x00000106 ***/
typedef union {
  byte Byte;
  struct {
    byte CNT         :7;                                       /* Count Value */
    byte             :1; 
  } Bits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @0x00000106;
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT                      _DBGCNT.Bits.CNT

#define DBGCNT_CNT_MASK                 127U
#define DBGCNT_CNT_BITNUM               0U


/*** DBGSCR1 - Debug State Control Register 1; 0x00000107 ***/
typedef union {
  byte Byte;
  struct {
    byte C0SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C1SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C2SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C3SC        :2;                                       /* Match State Sequencer Transitions Bits */
  } Bits;
} DBGSCR1STR;
extern volatile DBGSCR1STR _DBGSCR1 @0x00000107;
#define DBGSCR1                         _DBGSCR1.Byte
#define DBGSCR1_C0SC                    _DBGSCR1.Bits.C0SC
#define DBGSCR1_C1SC                    _DBGSCR1.Bits.C1SC
#define DBGSCR1_C2SC                    _DBGSCR1.Bits.C2SC
#define DBGSCR1_C3SC                    _DBGSCR1.Bits.C3SC

#define DBGSCR1_C0SC_MASK               3U
#define DBGSCR1_C0SC_BITNUM             0U
#define DBGSCR1_C1SC_MASK               12U
#define DBGSCR1_C1SC_BITNUM             2U
#define DBGSCR1_C2SC_MASK               48U
#define DBGSCR1_C2SC_BITNUM             4U
#define DBGSCR1_C3SC_MASK               192U
#define DBGSCR1_C3SC_BITNUM             6U


/*** DBGSCR2 - Debug State Control Register 2; 0x00000108 ***/
typedef union {
  byte Byte;
  struct {
    byte C0SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C1SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C2SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C3SC        :2;                                       /* Match State Sequencer Transitions Bits */
  } Bits;
} DBGSCR2STR;
extern volatile DBGSCR2STR _DBGSCR2 @0x00000108;
#define DBGSCR2                         _DBGSCR2.Byte
#define DBGSCR2_C0SC                    _DBGSCR2.Bits.C0SC
#define DBGSCR2_C1SC                    _DBGSCR2.Bits.C1SC
#define DBGSCR2_C2SC                    _DBGSCR2.Bits.C2SC
#define DBGSCR2_C3SC                    _DBGSCR2.Bits.C3SC

#define DBGSCR2_C0SC_MASK               3U
#define DBGSCR2_C0SC_BITNUM             0U
#define DBGSCR2_C1SC_MASK               12U
#define DBGSCR2_C1SC_BITNUM             2U
#define DBGSCR2_C2SC_MASK               48U
#define DBGSCR2_C2SC_BITNUM             4U
#define DBGSCR2_C3SC_MASK               192U
#define DBGSCR2_C3SC_BITNUM             6U


/*** DBGSCR3 - Debug State Control Register 3; 0x00000109 ***/
typedef union {
  byte Byte;
  struct {
    byte C0SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C1SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C2SC        :2;                                       /* Match State Sequencer Transitions Bits */
    byte C3SC        :2;                                       /* Match State Sequencer Transitions Bits */
  } Bits;
} DBGSCR3STR;
extern volatile DBGSCR3STR _DBGSCR3 @0x00000109;
#define DBGSCR3                         _DBGSCR3.Byte
#define DBGSCR3_C0SC                    _DBGSCR3.Bits.C0SC
#define DBGSCR3_C1SC                    _DBGSCR3.Bits.C1SC
#define DBGSCR3_C2SC                    _DBGSCR3.Bits.C2SC
#define DBGSCR3_C3SC                    _DBGSCR3.Bits.C3SC

#define DBGSCR3_C0SC_MASK               3U
#define DBGSCR3_C0SC_BITNUM             0U
#define DBGSCR3_C1SC_MASK               12U
#define DBGSCR3_C1SC_BITNUM             2U
#define DBGSCR3_C2SC_MASK               48U
#define DBGSCR3_C2SC_BITNUM             4U
#define DBGSCR3_C3SC_MASK               192U
#define DBGSCR3_C3SC_BITNUM             6U


/*** DBGEFR - Debug Event Flag Register; 0x0000010A ***/
typedef union {
  byte Byte;
  struct {
    byte ME0         :1;                                       /* Match Event 0 */
    byte ME1         :1;                                       /* Match Event 1 */
    byte ME2         :1;                                       /* Match Event 2 */
    byte ME3         :1;                                       /* Match Event 3 */
    byte EEVF        :1;                                       /* External Event Flag */
    byte             :1; 
    byte TRIGF       :1;                                       /* TRIG Flag */
    byte PTBOVF      :1;                                       /* Profiling Trace Buffer Overflow Flag */
  } Bits;
  struct {
    byte grpME   :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGEFRSTR;
extern volatile DBGEFRSTR _DBGEFR @0x0000010A;
#define DBGEFR                          _DBGEFR.Byte
#define DBGEFR_ME0                      _DBGEFR.Bits.ME0
#define DBGEFR_ME1                      _DBGEFR.Bits.ME1
#define DBGEFR_ME2                      _DBGEFR.Bits.ME2
#define DBGEFR_ME3                      _DBGEFR.Bits.ME3
#define DBGEFR_EEVF                     _DBGEFR.Bits.EEVF
#define DBGEFR_TRIGF                    _DBGEFR.Bits.TRIGF
#define DBGEFR_PTBOVF                   _DBGEFR.Bits.PTBOVF
#define DBGEFR_ME                       _DBGEFR.MergedBits.grpME

#define DBGEFR_ME0_MASK                 1U
#define DBGEFR_ME1_MASK                 2U
#define DBGEFR_ME2_MASK                 4U
#define DBGEFR_ME3_MASK                 8U
#define DBGEFR_EEVF_MASK                16U
#define DBGEFR_TRIGF_MASK               64U
#define DBGEFR_PTBOVF_MASK              128U
#define DBGEFR_ME_MASK                  15U
#define DBGEFR_ME_BITNUM                0U


/*** DBGSR - Debug Status Register; 0x0000010B ***/
typedef union {
  byte Byte;
  struct {
    byte SSF0        :1;                                       /* State Sequencer Flag Bits */
    byte SSF1        :1;                                       /* State Sequencer Flag Bit 1 */
    byte SSF2        :1;                                       /* State Sequencer Flag Bit 2 */
    byte             :1; 
    byte PTACT       :1;                                       /* Profiling Transmission Active */
    byte             :1; 
    byte             :1; 
    byte TBF         :1;                                       /* Trace Buffer Full */
  } Bits;
  struct {
    byte grpSSF  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGSRSTR;
extern volatile DBGSRSTR _DBGSR @0x0000010B;
#define DBGSR                           _DBGSR.Byte
#define DBGSR_SSF0                      _DBGSR.Bits.SSF0
#define DBGSR_SSF1                      _DBGSR.Bits.SSF1
#define DBGSR_SSF2                      _DBGSR.Bits.SSF2
#define DBGSR_PTACT                     _DBGSR.Bits.PTACT
#define DBGSR_TBF                       _DBGSR.Bits.TBF
#define DBGSR_SSF                       _DBGSR.MergedBits.grpSSF

#define DBGSR_SSF0_MASK                 1U
#define DBGSR_SSF1_MASK                 2U
#define DBGSR_SSF2_MASK                 4U
#define DBGSR_PTACT_MASK                16U
#define DBGSR_TBF_MASK                  128U
#define DBGSR_SSF_MASK                  7U
#define DBGSR_SSF_BITNUM                0U


/*** DBGACTL - Debug Comparator A Control Register; 0x00000110 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte             :1; 
    byte INST        :1;                                       /* Instruction Select */
    byte NDB         :1;                                       /* Not Data Bus */
    byte             :1; 
  } Bits;
} DBGACTLSTR;
extern volatile DBGACTLSTR _DBGACTL @0x00000110;
#define DBGACTL                         _DBGACTL.Byte
#define DBGACTL_COMPE                   _DBGACTL.Bits.COMPE
#define DBGACTL_RWE                     _DBGACTL.Bits.RWE
#define DBGACTL_RW                      _DBGACTL.Bits.RW
#define DBGACTL_INST                    _DBGACTL.Bits.INST
#define DBGACTL_NDB                     _DBGACTL.Bits.NDB

#define DBGACTL_COMPE_MASK              1U
#define DBGACTL_RWE_MASK                4U
#define DBGACTL_RW_MASK                 8U
#define DBGACTL_INST_MASK               32U
#define DBGACTL_NDB_MASK                64U


/*** DBGAAH - Debug Comparator A Address Register High; 0x00000115 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGAA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGAAHSTR;
extern volatile DBGAAHSTR _DBGAAH @0x00000115;
#define DBGAAH                          _DBGAAH.Byte
#define DBGAAH_DBGAA                    _DBGAAH.Bits.DBGAA

#define DBGAAH_DBGAA_MASK               255U
#define DBGAAH_DBGAA_BITNUM             0U


/*** DBGAAM - Debug Comparator A Address Register Middle; 0x00000116 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGAA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGAAMSTR;
extern volatile DBGAAMSTR _DBGAAM @0x00000116;
#define DBGAAM                          _DBGAAM.Byte
#define DBGAAM_DBGAA                    _DBGAAM.Bits.DBGAA

#define DBGAAM_DBGAA_MASK               255U
#define DBGAAM_DBGAA_BITNUM             0U


/*** DBGAAL - Debug Comparator A Address Register Low; 0x00000117 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGAA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGAALSTR;
extern volatile DBGAALSTR _DBGAAL @0x00000117;
#define DBGAAL                          _DBGAAL.Byte
#define DBGAAL_DBGAA                    _DBGAAL.Bits.DBGAA

#define DBGAAL_DBGAA_MASK               255U
#define DBGAAL_DBGAA_BITNUM             0U


/*** DBGAD0 - Debug Comparator A Data Register 0; 0x00000118 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT24       :1;                                       /* Comparator Data Bit 24 */
    byte BIT25       :1;                                       /* Comparator Data Bit 25 */
    byte BIT26       :1;                                       /* Comparator Data Bit 26 */
    byte BIT27       :1;                                       /* Comparator Data Bit 27 */
    byte BIT28       :1;                                       /* Comparator Data Bit 28 */
    byte BIT29       :1;                                       /* Comparator Data Bit 29 */
    byte BIT30       :1;                                       /* Comparator Data Bit 30 */
    byte BIT31       :1;                                       /* Comparator Data Bit 31 */
  } Bits;
} DBGAD0STR;
extern volatile DBGAD0STR _DBGAD0 @0x00000118;
#define DBGAD0                          _DBGAD0.Byte
#define DBGAD0_BIT24                    _DBGAD0.Bits.BIT24
#define DBGAD0_BIT25                    _DBGAD0.Bits.BIT25
#define DBGAD0_BIT26                    _DBGAD0.Bits.BIT26
#define DBGAD0_BIT27                    _DBGAD0.Bits.BIT27
#define DBGAD0_BIT28                    _DBGAD0.Bits.BIT28
#define DBGAD0_BIT29                    _DBGAD0.Bits.BIT29
#define DBGAD0_BIT30                    _DBGAD0.Bits.BIT30
#define DBGAD0_BIT31                    _DBGAD0.Bits.BIT31
/* DBGAD_ARR: Access 4 DBGADx registers in an array */
#define DBGAD_ARR                       ((volatile byte *) &DBGAD0)

#define DBGAD0_BIT24_MASK               1U
#define DBGAD0_BIT25_MASK               2U
#define DBGAD0_BIT26_MASK               4U
#define DBGAD0_BIT27_MASK               8U
#define DBGAD0_BIT28_MASK               16U
#define DBGAD0_BIT29_MASK               32U
#define DBGAD0_BIT30_MASK               64U
#define DBGAD0_BIT31_MASK               128U


/*** DBGAD1 - Debug Comparator A Data Register 1; 0x00000119 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Data Bit 16 */
    byte BIT17       :1;                                       /* Comparator Data Bit 17 */
    byte BIT18       :1;                                       /* Comparator Data Bit 18 */
    byte BIT19       :1;                                       /* Comparator Data Bit 19 */
    byte BIT20       :1;                                       /* Comparator Data Bit 20 */
    byte BIT21       :1;                                       /* Comparator Data Bit 21 */
    byte BIT22       :1;                                       /* Comparator Data Bit 22 */
    byte BIT23       :1;                                       /* Comparator Data Bit 23 */
  } Bits;
} DBGAD1STR;
extern volatile DBGAD1STR _DBGAD1 @0x00000119;
#define DBGAD1                          _DBGAD1.Byte
#define DBGAD1_BIT16                    _DBGAD1.Bits.BIT16
#define DBGAD1_BIT17                    _DBGAD1.Bits.BIT17
#define DBGAD1_BIT18                    _DBGAD1.Bits.BIT18
#define DBGAD1_BIT19                    _DBGAD1.Bits.BIT19
#define DBGAD1_BIT20                    _DBGAD1.Bits.BIT20
#define DBGAD1_BIT21                    _DBGAD1.Bits.BIT21
#define DBGAD1_BIT22                    _DBGAD1.Bits.BIT22
#define DBGAD1_BIT23                    _DBGAD1.Bits.BIT23

#define DBGAD1_BIT16_MASK               1U
#define DBGAD1_BIT17_MASK               2U
#define DBGAD1_BIT18_MASK               4U
#define DBGAD1_BIT19_MASK               8U
#define DBGAD1_BIT20_MASK               16U
#define DBGAD1_BIT21_MASK               32U
#define DBGAD1_BIT22_MASK               64U
#define DBGAD1_BIT23_MASK               128U


/*** DBGAD2 - Debug Comparator A Data Register 2; 0x0000011A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data Bit 15 */
  } Bits;
} DBGAD2STR;
extern volatile DBGAD2STR _DBGAD2 @0x0000011A;
#define DBGAD2                          _DBGAD2.Byte
#define DBGAD2_BIT8                     _DBGAD2.Bits.BIT8
#define DBGAD2_BIT9                     _DBGAD2.Bits.BIT9
#define DBGAD2_BIT10                    _DBGAD2.Bits.BIT10
#define DBGAD2_BIT11                    _DBGAD2.Bits.BIT11
#define DBGAD2_BIT12                    _DBGAD2.Bits.BIT12
#define DBGAD2_BIT13                    _DBGAD2.Bits.BIT13
#define DBGAD2_BIT14                    _DBGAD2.Bits.BIT14
#define DBGAD2_BIT15                    _DBGAD2.Bits.BIT15

#define DBGAD2_BIT8_MASK                1U
#define DBGAD2_BIT9_MASK                2U
#define DBGAD2_BIT10_MASK               4U
#define DBGAD2_BIT11_MASK               8U
#define DBGAD2_BIT12_MASK               16U
#define DBGAD2_BIT13_MASK               32U
#define DBGAD2_BIT14_MASK               64U
#define DBGAD2_BIT15_MASK               128U


/*** DBGAD3 - Debug Comparator A Data Register 3; 0x0000011B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Bit 7 */
  } Bits;
} DBGAD3STR;
extern volatile DBGAD3STR _DBGAD3 @0x0000011B;
#define DBGAD3                          _DBGAD3.Byte
#define DBGAD3_BIT0                     _DBGAD3.Bits.BIT0
#define DBGAD3_BIT1                     _DBGAD3.Bits.BIT1
#define DBGAD3_BIT2                     _DBGAD3.Bits.BIT2
#define DBGAD3_BIT3                     _DBGAD3.Bits.BIT3
#define DBGAD3_BIT4                     _DBGAD3.Bits.BIT4
#define DBGAD3_BIT5                     _DBGAD3.Bits.BIT5
#define DBGAD3_BIT6                     _DBGAD3.Bits.BIT6
#define DBGAD3_BIT7                     _DBGAD3.Bits.BIT7

#define DBGAD3_BIT0_MASK                1U
#define DBGAD3_BIT1_MASK                2U
#define DBGAD3_BIT2_MASK                4U
#define DBGAD3_BIT3_MASK                8U
#define DBGAD3_BIT4_MASK                16U
#define DBGAD3_BIT5_MASK                32U
#define DBGAD3_BIT6_MASK                64U
#define DBGAD3_BIT7_MASK                128U


/*** DBGADM0 - Debug Comparator A Data Mask Register 0; 0x0000011C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT24       :1;                                       /* Comparator Data Mask Bit 24 */
    byte BIT25       :1;                                       /* Comparator Data Mask Bit 25 */
    byte BIT26       :1;                                       /* Comparator Data Mask Bit 26 */
    byte BIT27       :1;                                       /* Comparator Data Mask Bit 27 */
    byte BIT28       :1;                                       /* Comparator Data Mask Bit 28 */
    byte BIT29       :1;                                       /* Comparator Data Mask Bit 29 */
    byte BIT30       :1;                                       /* Comparator Data Mask Bit 30 */
    byte BIT31       :1;                                       /* Comparator Data Mask Bit 31 */
  } Bits;
} DBGADM0STR;
extern volatile DBGADM0STR _DBGADM0 @0x0000011C;
#define DBGADM0                         _DBGADM0.Byte
#define DBGADM0_BIT24                   _DBGADM0.Bits.BIT24
#define DBGADM0_BIT25                   _DBGADM0.Bits.BIT25
#define DBGADM0_BIT26                   _DBGADM0.Bits.BIT26
#define DBGADM0_BIT27                   _DBGADM0.Bits.BIT27
#define DBGADM0_BIT28                   _DBGADM0.Bits.BIT28
#define DBGADM0_BIT29                   _DBGADM0.Bits.BIT29
#define DBGADM0_BIT30                   _DBGADM0.Bits.BIT30
#define DBGADM0_BIT31                   _DBGADM0.Bits.BIT31
/* DBGADM_ARR: Access 4 DBGADMx registers in an array */
#define DBGADM_ARR                      ((volatile byte *) &DBGADM0)

#define DBGADM0_BIT24_MASK              1U
#define DBGADM0_BIT25_MASK              2U
#define DBGADM0_BIT26_MASK              4U
#define DBGADM0_BIT27_MASK              8U
#define DBGADM0_BIT28_MASK              16U
#define DBGADM0_BIT29_MASK              32U
#define DBGADM0_BIT30_MASK              64U
#define DBGADM0_BIT31_MASK              128U


/*** DBGADM1 - Debug Comparator A Data Mask Register 1; 0x0000011D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Data Mask Bit 16 */
    byte BIT17       :1;                                       /* Comparator Data Mask Bit 17 */
    byte BIT18       :1;                                       /* Comparator Data Mask Bit 18 */
    byte BIT19       :1;                                       /* Comparator Data Mask Bit 19 */
    byte BIT20       :1;                                       /* Comparator Data Mask Bit 20 */
    byte BIT21       :1;                                       /* Comparator Data Mask Bit 21 */
    byte BIT22       :1;                                       /* Comparator Data Mask Bit 22 */
    byte BIT23       :1;                                       /* Comparator Data Mask Bit 23 */
  } Bits;
} DBGADM1STR;
extern volatile DBGADM1STR _DBGADM1 @0x0000011D;
#define DBGADM1                         _DBGADM1.Byte
#define DBGADM1_BIT16                   _DBGADM1.Bits.BIT16
#define DBGADM1_BIT17                   _DBGADM1.Bits.BIT17
#define DBGADM1_BIT18                   _DBGADM1.Bits.BIT18
#define DBGADM1_BIT19                   _DBGADM1.Bits.BIT19
#define DBGADM1_BIT20                   _DBGADM1.Bits.BIT20
#define DBGADM1_BIT21                   _DBGADM1.Bits.BIT21
#define DBGADM1_BIT22                   _DBGADM1.Bits.BIT22
#define DBGADM1_BIT23                   _DBGADM1.Bits.BIT23

#define DBGADM1_BIT16_MASK              1U
#define DBGADM1_BIT17_MASK              2U
#define DBGADM1_BIT18_MASK              4U
#define DBGADM1_BIT19_MASK              8U
#define DBGADM1_BIT20_MASK              16U
#define DBGADM1_BIT21_MASK              32U
#define DBGADM1_BIT22_MASK              64U
#define DBGADM1_BIT23_MASK              128U


/*** DBGADM2 - Debug Comparator A Data Mask Register 2; 0x0000011E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data Mask Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data Mask Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data Mask Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data Mask Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data Mask Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data Mask Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data Mask Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data Mask Bit 15 */
  } Bits;
} DBGADM2STR;
extern volatile DBGADM2STR _DBGADM2 @0x0000011E;
#define DBGADM2                         _DBGADM2.Byte
#define DBGADM2_BIT8                    _DBGADM2.Bits.BIT8
#define DBGADM2_BIT9                    _DBGADM2.Bits.BIT9
#define DBGADM2_BIT10                   _DBGADM2.Bits.BIT10
#define DBGADM2_BIT11                   _DBGADM2.Bits.BIT11
#define DBGADM2_BIT12                   _DBGADM2.Bits.BIT12
#define DBGADM2_BIT13                   _DBGADM2.Bits.BIT13
#define DBGADM2_BIT14                   _DBGADM2.Bits.BIT14
#define DBGADM2_BIT15                   _DBGADM2.Bits.BIT15

#define DBGADM2_BIT8_MASK               1U
#define DBGADM2_BIT9_MASK               2U
#define DBGADM2_BIT10_MASK              4U
#define DBGADM2_BIT11_MASK              8U
#define DBGADM2_BIT12_MASK              16U
#define DBGADM2_BIT13_MASK              32U
#define DBGADM2_BIT14_MASK              64U
#define DBGADM2_BIT15_MASK              128U


/*** DBGADM3 - Debug Comparator A Data Mask Register 3; 0x0000011F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Mask Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Mask Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Mask Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Mask Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Mask Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Mask Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Mask Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Mask Bit 7 */
  } Bits;
} DBGADM3STR;
extern volatile DBGADM3STR _DBGADM3 @0x0000011F;
#define DBGADM3                         _DBGADM3.Byte
#define DBGADM3_BIT0                    _DBGADM3.Bits.BIT0
#define DBGADM3_BIT1                    _DBGADM3.Bits.BIT1
#define DBGADM3_BIT2                    _DBGADM3.Bits.BIT2
#define DBGADM3_BIT3                    _DBGADM3.Bits.BIT3
#define DBGADM3_BIT4                    _DBGADM3.Bits.BIT4
#define DBGADM3_BIT5                    _DBGADM3.Bits.BIT5
#define DBGADM3_BIT6                    _DBGADM3.Bits.BIT6
#define DBGADM3_BIT7                    _DBGADM3.Bits.BIT7

#define DBGADM3_BIT0_MASK               1U
#define DBGADM3_BIT1_MASK               2U
#define DBGADM3_BIT2_MASK               4U
#define DBGADM3_BIT3_MASK               8U
#define DBGADM3_BIT4_MASK               16U
#define DBGADM3_BIT5_MASK               32U
#define DBGADM3_BIT6_MASK               64U
#define DBGADM3_BIT7_MASK               128U


/*** DBGBCTL - Debug Comparator B Control Register; 0x00000120 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte             :1; 
    byte INST        :1;                                       /* Instruction Select */
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGBCTLSTR;
extern volatile DBGBCTLSTR _DBGBCTL @0x00000120;
#define DBGBCTL                         _DBGBCTL.Byte
#define DBGBCTL_COMPE                   _DBGBCTL.Bits.COMPE
#define DBGBCTL_RWE                     _DBGBCTL.Bits.RWE
#define DBGBCTL_RW                      _DBGBCTL.Bits.RW
#define DBGBCTL_INST                    _DBGBCTL.Bits.INST

#define DBGBCTL_COMPE_MASK              1U
#define DBGBCTL_RWE_MASK                4U
#define DBGBCTL_RW_MASK                 8U
#define DBGBCTL_INST_MASK               32U


/*** DBGBAH - Debug Comparator B Address Register High; 0x00000125 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGBA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGBAHSTR;
extern volatile DBGBAHSTR _DBGBAH @0x00000125;
#define DBGBAH                          _DBGBAH.Byte
#define DBGBAH_DBGBA                    _DBGBAH.Bits.DBGBA

#define DBGBAH_DBGBA_MASK               255U
#define DBGBAH_DBGBA_BITNUM             0U


/*** DBGBAM - Debug Comparator B Address Register Middle; 0x00000126 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGBA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGBAMSTR;
extern volatile DBGBAMSTR _DBGBAM @0x00000126;
#define DBGBAM                          _DBGBAM.Byte
#define DBGBAM_DBGBA                    _DBGBAM.Bits.DBGBA

#define DBGBAM_DBGBA_MASK               255U
#define DBGBAM_DBGBA_BITNUM             0U


/*** DBGBAL - Debug Comparator B Address Register Low; 0x00000127 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGBA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGBALSTR;
extern volatile DBGBALSTR _DBGBAL @0x00000127;
#define DBGBAL                          _DBGBAL.Byte
#define DBGBAL_DBGBA                    _DBGBAL.Bits.DBGBA

#define DBGBAL_DBGBA_MASK               255U
#define DBGBAL_DBGBA_BITNUM             0U


/*** DBGCCTL - Debug Comparator C Control Register; 0x00000130 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte             :1; 
    byte INST        :1;                                       /* Instruction Select */
    byte NDB         :1;                                       /* Not Data Bus */
    byte             :1; 
  } Bits;
} DBGCCTLSTR;
extern volatile DBGCCTLSTR _DBGCCTL @0x00000130;
#define DBGCCTL                         _DBGCCTL.Byte
#define DBGCCTL_COMPE                   _DBGCCTL.Bits.COMPE
#define DBGCCTL_RWE                     _DBGCCTL.Bits.RWE
#define DBGCCTL_RW                      _DBGCCTL.Bits.RW
#define DBGCCTL_INST                    _DBGCCTL.Bits.INST
#define DBGCCTL_NDB                     _DBGCCTL.Bits.NDB

#define DBGCCTL_COMPE_MASK              1U
#define DBGCCTL_RWE_MASK                4U
#define DBGCCTL_RW_MASK                 8U
#define DBGCCTL_INST_MASK               32U
#define DBGCCTL_NDB_MASK                64U


/*** DBGCAH - Debug Comparator C Address Register High; 0x00000135 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGCA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGCAHSTR;
extern volatile DBGCAHSTR _DBGCAH @0x00000135;
#define DBGCAH                          _DBGCAH.Byte
#define DBGCAH_DBGCA                    _DBGCAH.Bits.DBGCA

#define DBGCAH_DBGCA_MASK               255U
#define DBGCAH_DBGCA_BITNUM             0U


/*** DBGCAM - Debug Comparator C Address Register Middle; 0x00000136 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGCA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGCAMSTR;
extern volatile DBGCAMSTR _DBGCAM @0x00000136;
#define DBGCAM                          _DBGCAM.Byte
#define DBGCAM_DBGCA                    _DBGCAM.Bits.DBGCA

#define DBGCAM_DBGCA_MASK               255U
#define DBGCAM_DBGCA_BITNUM             0U


/*** DBGCAL - Debug Comparator C Address Register Low; 0x00000137 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGCA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGCALSTR;
extern volatile DBGCALSTR _DBGCAL @0x00000137;
#define DBGCAL                          _DBGCAL.Byte
#define DBGCAL_DBGCA                    _DBGCAL.Bits.DBGCA

#define DBGCAL_DBGCA_MASK               255U
#define DBGCAL_DBGCA_BITNUM             0U


/*** DBGCD0 - Debug Comparator C Data Register 0; 0x00000138 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT24       :1;                                       /* Comparator Data Bit 24 */
    byte BIT25       :1;                                       /* Comparator Data Bit 25 */
    byte BIT26       :1;                                       /* Comparator Data Bit 26 */
    byte BIT27       :1;                                       /* Comparator Data Bit 27 */
    byte BIT28       :1;                                       /* Comparator Data Bit 28 */
    byte BIT29       :1;                                       /* Comparator Data Bit 29 */
    byte BIT30       :1;                                       /* Comparator Data Bit 30 */
    byte BIT31       :1;                                       /* Comparator Data Bit 31 */
  } Bits;
} DBGCD0STR;
extern volatile DBGCD0STR _DBGCD0 @0x00000138;
#define DBGCD0                          _DBGCD0.Byte
#define DBGCD0_BIT24                    _DBGCD0.Bits.BIT24
#define DBGCD0_BIT25                    _DBGCD0.Bits.BIT25
#define DBGCD0_BIT26                    _DBGCD0.Bits.BIT26
#define DBGCD0_BIT27                    _DBGCD0.Bits.BIT27
#define DBGCD0_BIT28                    _DBGCD0.Bits.BIT28
#define DBGCD0_BIT29                    _DBGCD0.Bits.BIT29
#define DBGCD0_BIT30                    _DBGCD0.Bits.BIT30
#define DBGCD0_BIT31                    _DBGCD0.Bits.BIT31
/* DBGCD_ARR: Access 4 DBGCDx registers in an array */
#define DBGCD_ARR                       ((volatile byte *) &DBGCD0)

#define DBGCD0_BIT24_MASK               1U
#define DBGCD0_BIT25_MASK               2U
#define DBGCD0_BIT26_MASK               4U
#define DBGCD0_BIT27_MASK               8U
#define DBGCD0_BIT28_MASK               16U
#define DBGCD0_BIT29_MASK               32U
#define DBGCD0_BIT30_MASK               64U
#define DBGCD0_BIT31_MASK               128U


/*** DBGCD1 - Debug Comparator C Data Register 1; 0x00000139 ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Data Bit 16 */
    byte BIT17       :1;                                       /* Comparator Data Bit 17 */
    byte BIT18       :1;                                       /* Comparator Data Bit 18 */
    byte BIT19       :1;                                       /* Comparator Data Bit 19 */
    byte BIT20       :1;                                       /* Comparator Data Bit 20 */
    byte BIT21       :1;                                       /* Comparator Data Bit 21 */
    byte BIT22       :1;                                       /* Comparator Data Bit 22 */
    byte BIT23       :1;                                       /* Comparator Data Bit 23 */
  } Bits;
} DBGCD1STR;
extern volatile DBGCD1STR _DBGCD1 @0x00000139;
#define DBGCD1                          _DBGCD1.Byte
#define DBGCD1_BIT16                    _DBGCD1.Bits.BIT16
#define DBGCD1_BIT17                    _DBGCD1.Bits.BIT17
#define DBGCD1_BIT18                    _DBGCD1.Bits.BIT18
#define DBGCD1_BIT19                    _DBGCD1.Bits.BIT19
#define DBGCD1_BIT20                    _DBGCD1.Bits.BIT20
#define DBGCD1_BIT21                    _DBGCD1.Bits.BIT21
#define DBGCD1_BIT22                    _DBGCD1.Bits.BIT22
#define DBGCD1_BIT23                    _DBGCD1.Bits.BIT23

#define DBGCD1_BIT16_MASK               1U
#define DBGCD1_BIT17_MASK               2U
#define DBGCD1_BIT18_MASK               4U
#define DBGCD1_BIT19_MASK               8U
#define DBGCD1_BIT20_MASK               16U
#define DBGCD1_BIT21_MASK               32U
#define DBGCD1_BIT22_MASK               64U
#define DBGCD1_BIT23_MASK               128U


/*** DBGCD2 - Debug Comparator C Data Register 2; 0x0000013A ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data Bit 15 */
  } Bits;
} DBGCD2STR;
extern volatile DBGCD2STR _DBGCD2 @0x0000013A;
#define DBGCD2                          _DBGCD2.Byte
#define DBGCD2_BIT8                     _DBGCD2.Bits.BIT8
#define DBGCD2_BIT9                     _DBGCD2.Bits.BIT9
#define DBGCD2_BIT10                    _DBGCD2.Bits.BIT10
#define DBGCD2_BIT11                    _DBGCD2.Bits.BIT11
#define DBGCD2_BIT12                    _DBGCD2.Bits.BIT12
#define DBGCD2_BIT13                    _DBGCD2.Bits.BIT13
#define DBGCD2_BIT14                    _DBGCD2.Bits.BIT14
#define DBGCD2_BIT15                    _DBGCD2.Bits.BIT15

#define DBGCD2_BIT8_MASK                1U
#define DBGCD2_BIT9_MASK                2U
#define DBGCD2_BIT10_MASK               4U
#define DBGCD2_BIT11_MASK               8U
#define DBGCD2_BIT12_MASK               16U
#define DBGCD2_BIT13_MASK               32U
#define DBGCD2_BIT14_MASK               64U
#define DBGCD2_BIT15_MASK               128U


/*** DBGCD3 - Debug Comparator C Data Register 3; 0x0000013B ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Bit 7 */
  } Bits;
} DBGCD3STR;
extern volatile DBGCD3STR _DBGCD3 @0x0000013B;
#define DBGCD3                          _DBGCD3.Byte
#define DBGCD3_BIT0                     _DBGCD3.Bits.BIT0
#define DBGCD3_BIT1                     _DBGCD3.Bits.BIT1
#define DBGCD3_BIT2                     _DBGCD3.Bits.BIT2
#define DBGCD3_BIT3                     _DBGCD3.Bits.BIT3
#define DBGCD3_BIT4                     _DBGCD3.Bits.BIT4
#define DBGCD3_BIT5                     _DBGCD3.Bits.BIT5
#define DBGCD3_BIT6                     _DBGCD3.Bits.BIT6
#define DBGCD3_BIT7                     _DBGCD3.Bits.BIT7

#define DBGCD3_BIT0_MASK                1U
#define DBGCD3_BIT1_MASK                2U
#define DBGCD3_BIT2_MASK                4U
#define DBGCD3_BIT3_MASK                8U
#define DBGCD3_BIT4_MASK                16U
#define DBGCD3_BIT5_MASK                32U
#define DBGCD3_BIT6_MASK                64U
#define DBGCD3_BIT7_MASK                128U


/*** DBGCDM0 - Debug Comparator C Data Mask Register 0; 0x0000013C ***/
typedef union {
  byte Byte;
  struct {
    byte BIT24       :1;                                       /* Comparator Data Mask Bit 24 */
    byte BIT25       :1;                                       /* Comparator Data Mask Bit 25 */
    byte BIT26       :1;                                       /* Comparator Data Mask Bit 26 */
    byte BIT27       :1;                                       /* Comparator Data Mask Bit 27 */
    byte BIT28       :1;                                       /* Comparator Data Mask Bit 28 */
    byte BIT29       :1;                                       /* Comparator Data Mask Bit 29 */
    byte BIT30       :1;                                       /* Comparator Data Mask Bit 30 */
    byte BIT31       :1;                                       /* Comparator Data Mask Bit 31 */
  } Bits;
} DBGCDM0STR;
extern volatile DBGCDM0STR _DBGCDM0 @0x0000013C;
#define DBGCDM0                         _DBGCDM0.Byte
#define DBGCDM0_BIT24                   _DBGCDM0.Bits.BIT24
#define DBGCDM0_BIT25                   _DBGCDM0.Bits.BIT25
#define DBGCDM0_BIT26                   _DBGCDM0.Bits.BIT26
#define DBGCDM0_BIT27                   _DBGCDM0.Bits.BIT27
#define DBGCDM0_BIT28                   _DBGCDM0.Bits.BIT28
#define DBGCDM0_BIT29                   _DBGCDM0.Bits.BIT29
#define DBGCDM0_BIT30                   _DBGCDM0.Bits.BIT30
#define DBGCDM0_BIT31                   _DBGCDM0.Bits.BIT31
/* DBGCDM_ARR: Access 4 DBGCDMx registers in an array */
#define DBGCDM_ARR                      ((volatile byte *) &DBGCDM0)

#define DBGCDM0_BIT24_MASK              1U
#define DBGCDM0_BIT25_MASK              2U
#define DBGCDM0_BIT26_MASK              4U
#define DBGCDM0_BIT27_MASK              8U
#define DBGCDM0_BIT28_MASK              16U
#define DBGCDM0_BIT29_MASK              32U
#define DBGCDM0_BIT30_MASK              64U
#define DBGCDM0_BIT31_MASK              128U


/*** DBGCDM1 - Debug Comparator C Data Mask Register 1; 0x0000013D ***/
typedef union {
  byte Byte;
  struct {
    byte BIT16       :1;                                       /* Comparator Data Mask Bit 16 */
    byte BIT17       :1;                                       /* Comparator Data Mask Bit 17 */
    byte BIT18       :1;                                       /* Comparator Data Mask Bit 18 */
    byte BIT19       :1;                                       /* Comparator Data Mask Bit 19 */
    byte BIT20       :1;                                       /* Comparator Data Mask Bit 20 */
    byte BIT21       :1;                                       /* Comparator Data Mask Bit 21 */
    byte BIT22       :1;                                       /* Comparator Data Mask Bit 22 */
    byte BIT23       :1;                                       /* Comparator Data Mask Bit 23 */
  } Bits;
} DBGCDM1STR;
extern volatile DBGCDM1STR _DBGCDM1 @0x0000013D;
#define DBGCDM1                         _DBGCDM1.Byte
#define DBGCDM1_BIT16                   _DBGCDM1.Bits.BIT16
#define DBGCDM1_BIT17                   _DBGCDM1.Bits.BIT17
#define DBGCDM1_BIT18                   _DBGCDM1.Bits.BIT18
#define DBGCDM1_BIT19                   _DBGCDM1.Bits.BIT19
#define DBGCDM1_BIT20                   _DBGCDM1.Bits.BIT20
#define DBGCDM1_BIT21                   _DBGCDM1.Bits.BIT21
#define DBGCDM1_BIT22                   _DBGCDM1.Bits.BIT22
#define DBGCDM1_BIT23                   _DBGCDM1.Bits.BIT23

#define DBGCDM1_BIT16_MASK              1U
#define DBGCDM1_BIT17_MASK              2U
#define DBGCDM1_BIT18_MASK              4U
#define DBGCDM1_BIT19_MASK              8U
#define DBGCDM1_BIT20_MASK              16U
#define DBGCDM1_BIT21_MASK              32U
#define DBGCDM1_BIT22_MASK              64U
#define DBGCDM1_BIT23_MASK              128U


/*** DBGCDM2 - Debug Comparator C Data Mask Register 2; 0x0000013E ***/
typedef union {
  byte Byte;
  struct {
    byte BIT8        :1;                                       /* Comparator Data Mask Bit 8 */
    byte BIT9        :1;                                       /* Comparator Data Mask Bit 9 */
    byte BIT10       :1;                                       /* Comparator Data Mask Bit 10 */
    byte BIT11       :1;                                       /* Comparator Data Mask Bit 11 */
    byte BIT12       :1;                                       /* Comparator Data Mask Bit 12 */
    byte BIT13       :1;                                       /* Comparator Data Mask Bit 13 */
    byte BIT14       :1;                                       /* Comparator Data Mask Bit 14 */
    byte BIT15       :1;                                       /* Comparator Data Mask Bit 15 */
  } Bits;
} DBGCDM2STR;
extern volatile DBGCDM2STR _DBGCDM2 @0x0000013E;
#define DBGCDM2                         _DBGCDM2.Byte
#define DBGCDM2_BIT8                    _DBGCDM2.Bits.BIT8
#define DBGCDM2_BIT9                    _DBGCDM2.Bits.BIT9
#define DBGCDM2_BIT10                   _DBGCDM2.Bits.BIT10
#define DBGCDM2_BIT11                   _DBGCDM2.Bits.BIT11
#define DBGCDM2_BIT12                   _DBGCDM2.Bits.BIT12
#define DBGCDM2_BIT13                   _DBGCDM2.Bits.BIT13
#define DBGCDM2_BIT14                   _DBGCDM2.Bits.BIT14
#define DBGCDM2_BIT15                   _DBGCDM2.Bits.BIT15

#define DBGCDM2_BIT8_MASK               1U
#define DBGCDM2_BIT9_MASK               2U
#define DBGCDM2_BIT10_MASK              4U
#define DBGCDM2_BIT11_MASK              8U
#define DBGCDM2_BIT12_MASK              16U
#define DBGCDM2_BIT13_MASK              32U
#define DBGCDM2_BIT14_MASK              64U
#define DBGCDM2_BIT15_MASK              128U


/*** DBGCDM3 - Debug Comparator C Data Mask Register 3; 0x0000013F ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* Comparator Data Mask Bit 0 */
    byte BIT1        :1;                                       /* Comparator Data Mask Bit 1 */
    byte BIT2        :1;                                       /* Comparator Data Mask Bit 2 */
    byte BIT3        :1;                                       /* Comparator Data Mask Bit 3 */
    byte BIT4        :1;                                       /* Comparator Data Mask Bit 4 */
    byte BIT5        :1;                                       /* Comparator Data Mask Bit 5 */
    byte BIT6        :1;                                       /* Comparator Data Mask Bit 6 */
    byte BIT7        :1;                                       /* Comparator Data Mask Bit 7 */
  } Bits;
} DBGCDM3STR;
extern volatile DBGCDM3STR _DBGCDM3 @0x0000013F;
#define DBGCDM3                         _DBGCDM3.Byte
#define DBGCDM3_BIT0                    _DBGCDM3.Bits.BIT0
#define DBGCDM3_BIT1                    _DBGCDM3.Bits.BIT1
#define DBGCDM3_BIT2                    _DBGCDM3.Bits.BIT2
#define DBGCDM3_BIT3                    _DBGCDM3.Bits.BIT3
#define DBGCDM3_BIT4                    _DBGCDM3.Bits.BIT4
#define DBGCDM3_BIT5                    _DBGCDM3.Bits.BIT5
#define DBGCDM3_BIT6                    _DBGCDM3.Bits.BIT6
#define DBGCDM3_BIT7                    _DBGCDM3.Bits.BIT7

#define DBGCDM3_BIT0_MASK               1U
#define DBGCDM3_BIT1_MASK               2U
#define DBGCDM3_BIT2_MASK               4U
#define DBGCDM3_BIT3_MASK               8U
#define DBGCDM3_BIT4_MASK               16U
#define DBGCDM3_BIT5_MASK               32U
#define DBGCDM3_BIT6_MASK               64U
#define DBGCDM3_BIT7_MASK               128U


/*** DBGDCTL - Debug Comparator D Control Register; 0x00000140 ***/
typedef union {
  byte Byte;
  struct {
    byte COMPE       :1;                                       /* Determines if comparator is enabled */
    byte             :1; 
    byte RWE         :1;                                       /* Read/Write Enable Bit */
    byte RW          :1;                                       /* Read/Write Comparator Value Bit */
    byte             :1; 
    byte INST        :1;                                       /* Instruction Select */
    byte             :1; 
    byte             :1; 
  } Bits;
} DBGDCTLSTR;
extern volatile DBGDCTLSTR _DBGDCTL @0x00000140;
#define DBGDCTL                         _DBGDCTL.Byte
#define DBGDCTL_COMPE                   _DBGDCTL.Bits.COMPE
#define DBGDCTL_RWE                     _DBGDCTL.Bits.RWE
#define DBGDCTL_RW                      _DBGDCTL.Bits.RW
#define DBGDCTL_INST                    _DBGDCTL.Bits.INST

#define DBGDCTL_COMPE_MASK              1U
#define DBGDCTL_RWE_MASK                4U
#define DBGDCTL_RW_MASK                 8U
#define DBGDCTL_INST_MASK               32U


/*** DBGDAH - Debug Comparator D Address Register High; 0x00000145 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGDA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGDAHSTR;
extern volatile DBGDAHSTR _DBGDAH @0x00000145;
#define DBGDAH                          _DBGDAH.Byte
#define DBGDAH_DBGDA                    _DBGDAH.Bits.DBGDA

#define DBGDAH_DBGDA_MASK               255U
#define DBGDAH_DBGDA_BITNUM             0U


/*** DBGDAM - Debug Comparator D Address Register Middle; 0x00000146 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGDA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGDAMSTR;
extern volatile DBGDAMSTR _DBGDAM @0x00000146;
#define DBGDAM                          _DBGDAM.Byte
#define DBGDAM_DBGDA                    _DBGDAM.Bits.DBGDA

#define DBGDAM_DBGDA_MASK               255U
#define DBGDAM_DBGDA_BITNUM             0U


/*** DBGDAL - Debug Comparator D Address Register Low; 0x00000147 ***/
typedef union {
  byte Byte;
  struct {
    byte DBGDA       :8;                                       /* Comparator Address Bits */
  } Bits;
} DBGDALSTR;
extern volatile DBGDALSTR _DBGDAL @0x00000147;
#define DBGDAL                          _DBGDAL.Byte
#define DBGDAL_DBGDA                    _DBGDAL.Bits.DBGDA

#define DBGDAL_DBGDA_MASK               255U
#define DBGDAL_DBGDA_BITNUM             0U


/*** MODRR0 - Module Routing Register 0; 0x00000200 ***/
typedef union {
  byte Byte;
  struct {
    byte S0L0RR      :3;                                       /* SCI0-LINPHY routing */
    byte SCI1RR      :1;                                       /* SCI1 routing */
    byte SPI0RR      :1;                                       /* SPI routing */
    byte SPI0SSRR    :1;                                       /* SPI SS routing */
    byte             :1; 
    byte             :1; 
  } Bits;
} MODRR0STR;
extern volatile MODRR0STR _MODRR0 @0x00000200;
#define MODRR0                          _MODRR0.Byte
#define MODRR0_S0L0RR                   _MODRR0.Bits.S0L0RR
#define MODRR0_SCI1RR                   _MODRR0.Bits.SCI1RR
#define MODRR0_SPI0RR                   _MODRR0.Bits.SPI0RR
#define MODRR0_SPI0SSRR                 _MODRR0.Bits.SPI0SSRR
/* MODRR_ARR: Access 3 MODRRx registers in an array */
#define MODRR_ARR                       ((volatile byte *) &MODRR0)

#define MODRR0_S0L0RR_MASK              7U
#define MODRR0_S0L0RR_BITNUM            0U
#define MODRR0_SCI1RR_MASK              8U
#define MODRR0_SPI0RR_MASK              16U
#define MODRR0_SPI0SSRR_MASK            32U


/*** MODRR1 - Module Routing Register 1; 0x00000201 ***/
typedef union {
  byte Byte;
  struct {
    byte PWM10RR     :1;                                       /* PWM0 and PWM1 routing */
    byte PWM32RR     :1;                                       /* PWM2 and PWM3 routing */
    byte PWM54RR     :1;                                       /* PWM4 and PWM5 routing */
    byte PWMPRR      :1;                                       /* PWM probe */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} MODRR1STR;
extern volatile MODRR1STR _MODRR1 @0x00000201;
#define MODRR1                          _MODRR1.Byte
#define MODRR1_PWM10RR                  _MODRR1.Bits.PWM10RR
#define MODRR1_PWM32RR                  _MODRR1.Bits.PWM32RR
#define MODRR1_PWM54RR                  _MODRR1.Bits.PWM54RR
#define MODRR1_PWMPRR                   _MODRR1.Bits.PWMPRR

#define MODRR1_PWM10RR_MASK             1U
#define MODRR1_PWM32RR_MASK             2U
#define MODRR1_PWM54RR_MASK             4U
#define MODRR1_PWMPRR_MASK              8U


/*** MODRR2 - Module Routing Register 2; 0x00000202 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte T0IC1RR     :1;                                       /* TIM IC1 routing */
    byte T0IC3RR     :2;                                       /* TIM IC3 routing */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} MODRR2STR;
extern volatile MODRR2STR _MODRR2 @0x00000202;
#define MODRR2                          _MODRR2.Byte
#define MODRR2_T0IC1RR                  _MODRR2.Bits.T0IC1RR
#define MODRR2_T0IC3RR                  _MODRR2.Bits.T0IC3RR

#define MODRR2_T0IC1RR_MASK             2U
#define MODRR2_T0IC3RR_MASK             12U
#define MODRR2_T0IC3RR_BITNUM           2U


/*** ECLKCTL - ECLK Control Register; 0x00000208 ***/
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
    byte NECLK       :1;                                       /* No ECLK */
  } Bits;
} ECLKCTLSTR;
extern volatile ECLKCTLSTR _ECLKCTL @0x00000208;
#define ECLKCTL                         _ECLKCTL.Byte
#define ECLKCTL_NECLK                   _ECLKCTL.Bits.NECLK

#define ECLKCTL_NECLK_MASK              128U


/*** IRQCR - Interrupt Control Register; 0x00000209 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte IRQEN       :1;                                       /* External IRQ Enable */
    byte IRQE        :1;                                       /* IRQ Select Edge Sensitive Only */
  } Bits;
} IRQCRSTR;
extern volatile IRQCRSTR _IRQCR @0x00000209;
#define IRQCR                           _IRQCR.Byte
#define IRQCR_IRQEN                     _IRQCR.Bits.IRQEN
#define IRQCR_IRQE                      _IRQCR.Bits.IRQE

#define IRQCR_IRQEN_MASK                64U
#define IRQCR_IRQE_MASK                 128U


/*** PIMMISC - PIM Miscellaneous Register; 0x0000020A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte OCPE1       :1;                                       /* Activate over-current detector on PP0 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PIMMISCSTR;
extern volatile PIMMISCSTR _PIMMISC @0x0000020A;
#define PIMMISC                         _PIMMISC.Byte
#define PIMMISC_OCPE1                   _PIMMISC.Bits.OCPE1

#define PIMMISC_OCPE1_MASK              2U


/*** PTE - Port E Data Register; 0x00000260 ***/
typedef union {
  byte Byte;
  struct {
    byte PTE0        :1;                                       /* Port E general purpose I/O data 0 */
    byte PTE1        :1;                                       /* Port E general purpose I/O data 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTE  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTESTR;
extern volatile PTESTR _PTE @0x00000260;
#define PTE                             _PTE.Byte
#define PTE_PTE0                        _PTE.Bits.PTE0
#define PTE_PTE1                        _PTE.Bits.PTE1
#define PTE_PTE                         _PTE.MergedBits.grpPTE

#define PTE_PTE0_MASK                   1U
#define PTE_PTE1_MASK                   2U
#define PTE_PTE_MASK                    3U
#define PTE_PTE_BITNUM                  0U


/*** PTIE - Port E Input Register; 0x00000262 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIE0       :1;                                       /* Port E data input 0 */
    byte PTIE1       :1;                                       /* Port E data input 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTIESTR;
extern volatile PTIESTR _PTIE @0x00000262;
#define PTIE                            _PTIE.Byte
#define PTIE_PTIE0                      _PTIE.Bits.PTIE0
#define PTIE_PTIE1                      _PTIE.Bits.PTIE1
#define PTIE_PTIE                       _PTIE.MergedBits.grpPTIE

#define PTIE_PTIE0_MASK                 1U
#define PTIE_PTIE1_MASK                 2U
#define PTIE_PTIE_MASK                  3U
#define PTIE_PTIE_BITNUM                0U


/*** DDRE - Port E Data Direction Register; 0x00000264 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRE0       :1;                                       /* Port E data direction select 0 */
    byte DDRE1       :1;                                       /* Port E data direction select 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRESTR;
extern volatile DDRESTR _DDRE @0x00000264;
#define DDRE                            _DDRE.Byte
#define DDRE_DDRE0                      _DDRE.Bits.DDRE0
#define DDRE_DDRE1                      _DDRE.Bits.DDRE1
#define DDRE_DDRE                       _DDRE.MergedBits.grpDDRE

#define DDRE_DDRE0_MASK                 1U
#define DDRE_DDRE1_MASK                 2U
#define DDRE_DDRE_MASK                  3U
#define DDRE_DDRE_BITNUM                0U


/*** PERE - Port E Pull Device Enable Register; 0x00000266 ***/
typedef union {
  byte Byte;
  struct {
    byte PERE0       :1;                                       /* Port E pull device enable 0 */
    byte PERE1       :1;                                       /* Port E pull device enable 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERESTR;
extern volatile PERESTR _PERE @0x00000266;
#define PERE                            _PERE.Byte
#define PERE_PERE0                      _PERE.Bits.PERE0
#define PERE_PERE1                      _PERE.Bits.PERE1
#define PERE_PERE                       _PERE.MergedBits.grpPERE

#define PERE_PERE0_MASK                 1U
#define PERE_PERE1_MASK                 2U
#define PERE_PERE_MASK                  3U
#define PERE_PERE_BITNUM                0U


/*** PPSE - Port E Polarity Select Register; 0x00000268 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSE0       :1;                                       /* Port E pull polarity select 0 */
    byte PPSE1       :1;                                       /* Port E pull polarity select 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSE :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSESTR;
extern volatile PPSESTR _PPSE @0x00000268;
#define PPSE                            _PPSE.Byte
#define PPSE_PPSE0                      _PPSE.Bits.PPSE0
#define PPSE_PPSE1                      _PPSE.Bits.PPSE1
#define PPSE_PPSE                       _PPSE.MergedBits.grpPPSE

#define PPSE_PPSE0_MASK                 1U
#define PPSE_PPSE1_MASK                 2U
#define PPSE_PPSE_MASK                  3U
#define PPSE_PPSE_BITNUM                0U


/*** PTAD - Port AD Data Register; 0x00000280 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PTADH - Port ADH Data Register; 0x00000280 ***/
    union {
      byte Byte;
      struct {
        byte PTADH0      :1;                                       /* Port ADH general purpose I/O data 0 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } PTADHSTR;
    #define PTADH                       _PTAD.Overlap_STR.PTADHSTR.Byte
    #define PTADH_PTADH0                _PTAD.Overlap_STR.PTADHSTR.Bits.PTADH0
    
    #define PTADH_PTADH0_MASK           1U
    

    /*** PTADL - Port ADL Data Register; 0x00000281 ***/
    union {
      byte Byte;
      struct {
        byte PTADL0      :1;                                       /* Port ADL general purpose I/O data 0 */
        byte PTADL1      :1;                                       /* Port ADL general purpose I/O data 1 */
        byte PTADL2      :1;                                       /* Port ADL general purpose I/O data 2 */
        byte PTADL3      :1;                                       /* Port ADL general purpose I/O data 3 */
        byte PTADL4      :1;                                       /* Port ADL general purpose I/O data 4 */
        byte PTADL5      :1;                                       /* Port ADL general purpose I/O data 5 */
        byte PTADL6      :1;                                       /* Port ADL general purpose I/O data 6 */
        byte PTADL7      :1;                                       /* Port ADL general purpose I/O data 7 */
      } Bits;
    } PTADLSTR;
    #define PTADL                       _PTAD.Overlap_STR.PTADLSTR.Byte
    #define PTADL_PTADL0                _PTAD.Overlap_STR.PTADLSTR.Bits.PTADL0
    #define PTADL_PTADL1                _PTAD.Overlap_STR.PTADLSTR.Bits.PTADL1
    #define PTADL_PTADL2                _PTAD.Overlap_STR.PTADLSTR.Bits.PTADL2
    #define PTADL_PTADL3                _PTAD.Overlap_STR.PTADLSTR.Bits.PTADL3
    #define PTADL_PTADL4                _PTAD.Overlap_STR.PTADLSTR.Bits.PTADL4
    #define PTADL_PTADL5                _PTAD.Overlap_STR.PTADLSTR.Bits.PTADL5
    #define PTADL_PTADL6                _PTAD.Overlap_STR.PTADLSTR.Bits.PTADL6
    #define PTADL_PTADL7                _PTAD.Overlap_STR.PTADLSTR.Bits.PTADL7
    
    #define PTADL_PTADL0_MASK           1U
    #define PTADL_PTADL1_MASK           2U
    #define PTADL_PTADL2_MASK           4U
    #define PTADL_PTADL3_MASK           8U
    #define PTADL_PTADL4_MASK           16U
    #define PTADL_PTADL5_MASK           32U
    #define PTADL_PTADL6_MASK           64U
    #define PTADL_PTADL7_MASK           128U
    
  } Overlap_STR;

  struct {
    word PTADL0      :1;                                       /* Port AD general purpose I/O data 0 */
    word PTADL1      :1;                                       /* Port AD general purpose I/O data 1 */
    word PTADL2      :1;                                       /* Port AD general purpose I/O data 2 */
    word PTADL3      :1;                                       /* Port AD general purpose I/O data 3 */
    word PTADL4      :1;                                       /* Port AD general purpose I/O data 4 */
    word PTADL5      :1;                                       /* Port AD general purpose I/O data 5 */
    word PTADL6      :1;                                       /* Port AD general purpose I/O data 6 */
    word PTADL7      :1;                                       /* Port AD general purpose I/O data 7 */
    word PTADH0      :1;                                       /* Port AD general purpose I/O data 8 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPTADL :8;
    word grpPTADH :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0x00000280;
#define PTAD                            _PTAD.Word
#define PTAD_PTADL0                     _PTAD.Bits.PTADL0
#define PTAD_PTADL1                     _PTAD.Bits.PTADL1
#define PTAD_PTADL2                     _PTAD.Bits.PTADL2
#define PTAD_PTADL3                     _PTAD.Bits.PTADL3
#define PTAD_PTADL4                     _PTAD.Bits.PTADL4
#define PTAD_PTADL5                     _PTAD.Bits.PTADL5
#define PTAD_PTADL6                     _PTAD.Bits.PTADL6
#define PTAD_PTADL7                     _PTAD.Bits.PTADL7
#define PTAD_PTADH0                     _PTAD.Bits.PTADH0
#define PTAD_PTADL                      _PTAD.MergedBits.grpPTADL

#define PTAD_PTADL0_MASK                1U
#define PTAD_PTADL1_MASK                2U
#define PTAD_PTADL2_MASK                4U
#define PTAD_PTADL3_MASK                8U
#define PTAD_PTADL4_MASK                16U
#define PTAD_PTADL5_MASK                32U
#define PTAD_PTADL6_MASK                64U
#define PTAD_PTADL7_MASK                128U
#define PTAD_PTADH0_MASK                256U
#define PTAD_PTADL_MASK                 255U
#define PTAD_PTADL_BITNUM               0U


/*** PTIAD - Port AD Input Register; 0x00000282 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PTIADH - Port ADH Input Register; 0x00000282 ***/
    union {
      byte Byte;
      struct {
        byte PTIADH0     :1;                                       /* Port ADH data input 0 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } PTIADHSTR;
    #define PTIADH                      _PTIAD.Overlap_STR.PTIADHSTR.Byte
    #define PTIADH_PTIADH0              _PTIAD.Overlap_STR.PTIADHSTR.Bits.PTIADH0
    
    #define PTIADH_PTIADH0_MASK         1U
    

    /*** PTIADL - Port ADL Input Register; 0x00000283 ***/
    union {
      byte Byte;
      struct {
        byte PTIADL0     :1;                                       /* Port ADL data input 0 */
        byte PTIADL1     :1;                                       /* Port ADL data input 1 */
        byte PTIADL2     :1;                                       /* Port ADL data input 2 */
        byte PTIADL3     :1;                                       /* Port ADL data input 3 */
        byte PTIADL4     :1;                                       /* Port ADL data input 4 */
        byte PTIADL5     :1;                                       /* Port ADL data input 5 */
        byte PTIADL6     :1;                                       /* Port ADL data input 6 */
        byte PTIADL7     :1;                                       /* Port ADL data input 7 */
      } Bits;
    } PTIADLSTR;
    #define PTIADL                      _PTIAD.Overlap_STR.PTIADLSTR.Byte
    #define PTIADL_PTIADL0              _PTIAD.Overlap_STR.PTIADLSTR.Bits.PTIADL0
    #define PTIADL_PTIADL1              _PTIAD.Overlap_STR.PTIADLSTR.Bits.PTIADL1
    #define PTIADL_PTIADL2              _PTIAD.Overlap_STR.PTIADLSTR.Bits.PTIADL2
    #define PTIADL_PTIADL3              _PTIAD.Overlap_STR.PTIADLSTR.Bits.PTIADL3
    #define PTIADL_PTIADL4              _PTIAD.Overlap_STR.PTIADLSTR.Bits.PTIADL4
    #define PTIADL_PTIADL5              _PTIAD.Overlap_STR.PTIADLSTR.Bits.PTIADL5
    #define PTIADL_PTIADL6              _PTIAD.Overlap_STR.PTIADLSTR.Bits.PTIADL6
    #define PTIADL_PTIADL7              _PTIAD.Overlap_STR.PTIADLSTR.Bits.PTIADL7
    
    #define PTIADL_PTIADL0_MASK         1U
    #define PTIADL_PTIADL1_MASK         2U
    #define PTIADL_PTIADL2_MASK         4U
    #define PTIADL_PTIADL3_MASK         8U
    #define PTIADL_PTIADL4_MASK         16U
    #define PTIADL_PTIADL5_MASK         32U
    #define PTIADL_PTIADL6_MASK         64U
    #define PTIADL_PTIADL7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PTIADL0     :1;                                       /* Port AD data input 0 */
    word PTIADL1     :1;                                       /* Port AD data input 1 */
    word PTIADL2     :1;                                       /* Port AD data input 2 */
    word PTIADL3     :1;                                       /* Port AD data input 3 */
    word PTIADL4     :1;                                       /* Port AD data input 4 */
    word PTIADL5     :1;                                       /* Port AD data input 5 */
    word PTIADL6     :1;                                       /* Port AD data input 6 */
    word PTIADL7     :1;                                       /* Port AD data input 7 */
    word PTIADH0     :1;                                       /* Port AD data input 0 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPTIADL :8;
    word grpPTIADH :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PTIADSTR;
extern volatile PTIADSTR _PTIAD @0x00000282;
#define PTIAD                           _PTIAD.Word
#define PTIAD_PTIADL0                   _PTIAD.Bits.PTIADL0
#define PTIAD_PTIADL1                   _PTIAD.Bits.PTIADL1
#define PTIAD_PTIADL2                   _PTIAD.Bits.PTIADL2
#define PTIAD_PTIADL3                   _PTIAD.Bits.PTIADL3
#define PTIAD_PTIADL4                   _PTIAD.Bits.PTIADL4
#define PTIAD_PTIADL5                   _PTIAD.Bits.PTIADL5
#define PTIAD_PTIADL6                   _PTIAD.Bits.PTIADL6
#define PTIAD_PTIADL7                   _PTIAD.Bits.PTIADL7
#define PTIAD_PTIADH0                   _PTIAD.Bits.PTIADH0
#define PTIAD_PTIADL                    _PTIAD.MergedBits.grpPTIADL

#define PTIAD_PTIADL0_MASK              1U
#define PTIAD_PTIADL1_MASK              2U
#define PTIAD_PTIADL2_MASK              4U
#define PTIAD_PTIADL3_MASK              8U
#define PTIAD_PTIADL4_MASK              16U
#define PTIAD_PTIADL5_MASK              32U
#define PTIAD_PTIADL6_MASK              64U
#define PTIAD_PTIADL7_MASK              128U
#define PTIAD_PTIADH0_MASK              256U
#define PTIAD_PTIADL_MASK               255U
#define PTIAD_PTIADL_BITNUM             0U


/*** DDRAD - Port AD Data Direction Register; 0x00000284 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DDRADH - Port ADH Data Direction Register; 0x00000284 ***/
    union {
      byte Byte;
      struct {
        byte DDRADH0     :1;                                       /* Port ADH data direction select 0 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } DDRADHSTR;
    #define DDRADH                      _DDRAD.Overlap_STR.DDRADHSTR.Byte
    #define DDRADH_DDRADH0              _DDRAD.Overlap_STR.DDRADHSTR.Bits.DDRADH0
    
    #define DDRADH_DDRADH0_MASK         1U
    

    /*** DDRADL - Port ADL Data Direction Register; 0x00000285 ***/
    union {
      byte Byte;
      struct {
        byte DDRADL0     :1;                                       /* Port ADL data direction select 0 */
        byte DDRADL1     :1;                                       /* Port ADL data direction select 1 */
        byte DDRADL2     :1;                                       /* Port ADL data direction select 2 */
        byte DDRADL3     :1;                                       /* Port ADL data direction select 3 */
        byte DDRADL4     :1;                                       /* Port ADL data direction select 4 */
        byte DDRADL5     :1;                                       /* Port ADL data direction select 5 */
        byte DDRADL6     :1;                                       /* Port ADL data direction select 6 */
        byte DDRADL7     :1;                                       /* Port ADL data direction select 7 */
      } Bits;
    } DDRADLSTR;
    #define DDRADL                      _DDRAD.Overlap_STR.DDRADLSTR.Byte
    #define DDRADL_DDRADL0              _DDRAD.Overlap_STR.DDRADLSTR.Bits.DDRADL0
    #define DDRADL_DDRADL1              _DDRAD.Overlap_STR.DDRADLSTR.Bits.DDRADL1
    #define DDRADL_DDRADL2              _DDRAD.Overlap_STR.DDRADLSTR.Bits.DDRADL2
    #define DDRADL_DDRADL3              _DDRAD.Overlap_STR.DDRADLSTR.Bits.DDRADL3
    #define DDRADL_DDRADL4              _DDRAD.Overlap_STR.DDRADLSTR.Bits.DDRADL4
    #define DDRADL_DDRADL5              _DDRAD.Overlap_STR.DDRADLSTR.Bits.DDRADL5
    #define DDRADL_DDRADL6              _DDRAD.Overlap_STR.DDRADLSTR.Bits.DDRADL6
    #define DDRADL_DDRADL7              _DDRAD.Overlap_STR.DDRADLSTR.Bits.DDRADL7
    
    #define DDRADL_DDRADL0_MASK         1U
    #define DDRADL_DDRADL1_MASK         2U
    #define DDRADL_DDRADL2_MASK         4U
    #define DDRADL_DDRADL3_MASK         8U
    #define DDRADL_DDRADL4_MASK         16U
    #define DDRADL_DDRADL5_MASK         32U
    #define DDRADL_DDRADL6_MASK         64U
    #define DDRADL_DDRADL7_MASK         128U
    
  } Overlap_STR;

  struct {
    word DDRADL0     :1;                                       /* Port AD data direction select 0 */
    word DDRADL1     :1;                                       /* Port AD data direction select 1 */
    word DDRADL2     :1;                                       /* Port AD data direction select 2 */
    word DDRADL3     :1;                                       /* Port AD data direction select 3 */
    word DDRADL4     :1;                                       /* Port AD data direction select 4 */
    word DDRADL5     :1;                                       /* Port AD data direction select 5 */
    word DDRADL6     :1;                                       /* Port AD data direction select 6 */
    word DDRADL7     :1;                                       /* Port AD data direction select 7 */
    word DDRADH0     :1;                                       /* Port AD data direction select 8 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpDDRADL :8;
    word grpDDRADH :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} DDRADSTR;
extern volatile DDRADSTR _DDRAD @0x00000284;
#define DDRAD                           _DDRAD.Word
#define DDRAD_DDRADL0                   _DDRAD.Bits.DDRADL0
#define DDRAD_DDRADL1                   _DDRAD.Bits.DDRADL1
#define DDRAD_DDRADL2                   _DDRAD.Bits.DDRADL2
#define DDRAD_DDRADL3                   _DDRAD.Bits.DDRADL3
#define DDRAD_DDRADL4                   _DDRAD.Bits.DDRADL4
#define DDRAD_DDRADL5                   _DDRAD.Bits.DDRADL5
#define DDRAD_DDRADL6                   _DDRAD.Bits.DDRADL6
#define DDRAD_DDRADL7                   _DDRAD.Bits.DDRADL7
#define DDRAD_DDRADH0                   _DDRAD.Bits.DDRADH0
#define DDRAD_DDRADL                    _DDRAD.MergedBits.grpDDRADL

#define DDRAD_DDRADL0_MASK              1U
#define DDRAD_DDRADL1_MASK              2U
#define DDRAD_DDRADL2_MASK              4U
#define DDRAD_DDRADL3_MASK              8U
#define DDRAD_DDRADL4_MASK              16U
#define DDRAD_DDRADL5_MASK              32U
#define DDRAD_DDRADL6_MASK              64U
#define DDRAD_DDRADL7_MASK              128U
#define DDRAD_DDRADH0_MASK              256U
#define DDRAD_DDRADL_MASK               255U
#define DDRAD_DDRADL_BITNUM             0U


/*** PERAD - Port AD Pull Up Enable Register; 0x00000286 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PERADH - Port ADH Pull Device Enable Register; 0x00000286 ***/
    union {
      byte Byte;
      struct {
        byte PERADH0     :1;                                       /* Port ADH pull device enable 0 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } PERADHSTR;
    #define PERADH                      _PERAD.Overlap_STR.PERADHSTR.Byte
    #define PERADH_PERADH0              _PERAD.Overlap_STR.PERADHSTR.Bits.PERADH0
    
    #define PERADH_PERADH0_MASK         1U
    

    /*** PERADL - Port ADL Pull Device Enable Register; 0x00000287 ***/
    union {
      byte Byte;
      struct {
        byte PERADL0     :1;                                       /* Port ADL pull device enable 0 */
        byte PERADL1     :1;                                       /* Port ADL pull device enable 1 */
        byte PERADL2     :1;                                       /* Port ADL pull device enable 2 */
        byte PERADL3     :1;                                       /* Port ADL pull device enable 3 */
        byte PERADL4     :1;                                       /* Port ADL pull device enable 4 */
        byte PERADL5     :1;                                       /* Port ADL pull device enable 5 */
        byte PERADL6     :1;                                       /* Port ADL pull device enable 6 */
        byte PERADL7     :1;                                       /* Port ADL pull device enable 7 */
      } Bits;
    } PERADLSTR;
    #define PERADL                      _PERAD.Overlap_STR.PERADLSTR.Byte
    #define PERADL_PERADL0              _PERAD.Overlap_STR.PERADLSTR.Bits.PERADL0
    #define PERADL_PERADL1              _PERAD.Overlap_STR.PERADLSTR.Bits.PERADL1
    #define PERADL_PERADL2              _PERAD.Overlap_STR.PERADLSTR.Bits.PERADL2
    #define PERADL_PERADL3              _PERAD.Overlap_STR.PERADLSTR.Bits.PERADL3
    #define PERADL_PERADL4              _PERAD.Overlap_STR.PERADLSTR.Bits.PERADL4
    #define PERADL_PERADL5              _PERAD.Overlap_STR.PERADLSTR.Bits.PERADL5
    #define PERADL_PERADL6              _PERAD.Overlap_STR.PERADLSTR.Bits.PERADL6
    #define PERADL_PERADL7              _PERAD.Overlap_STR.PERADLSTR.Bits.PERADL7
    
    #define PERADL_PERADL0_MASK         1U
    #define PERADL_PERADL1_MASK         2U
    #define PERADL_PERADL2_MASK         4U
    #define PERADL_PERADL3_MASK         8U
    #define PERADL_PERADL4_MASK         16U
    #define PERADL_PERADL5_MASK         32U
    #define PERADL_PERADL6_MASK         64U
    #define PERADL_PERADL7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PERADL0     :1;                                       /* Port AD pull device enable 0 */
    word PERADL1     :1;                                       /* Port AD pull device enable 1 */
    word PERADL2     :1;                                       /* Port AD pull device enable 2 */
    word PERADL3     :1;                                       /* Port AD pull device enable 3 */
    word PERADL4     :1;                                       /* Port AD pull device enable 4 */
    word PERADL5     :1;                                       /* Port AD pull device enable 5 */
    word PERADL6     :1;                                       /* Port AD pull device enable 6 */
    word PERADL7     :1;                                       /* Port AD pull device enable 7 */
    word PERADH0     :1;                                       /* Port AD pull device enable 8 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPERADL :8;
    word grpPERADH :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PERADSTR;
extern volatile PERADSTR _PERAD @0x00000286;
#define PERAD                           _PERAD.Word
#define PERAD_PERADL0                   _PERAD.Bits.PERADL0
#define PERAD_PERADL1                   _PERAD.Bits.PERADL1
#define PERAD_PERADL2                   _PERAD.Bits.PERADL2
#define PERAD_PERADL3                   _PERAD.Bits.PERADL3
#define PERAD_PERADL4                   _PERAD.Bits.PERADL4
#define PERAD_PERADL5                   _PERAD.Bits.PERADL5
#define PERAD_PERADL6                   _PERAD.Bits.PERADL6
#define PERAD_PERADL7                   _PERAD.Bits.PERADL7
#define PERAD_PERADH0                   _PERAD.Bits.PERADH0
#define PERAD_PERADL                    _PERAD.MergedBits.grpPERADL

#define PERAD_PERADL0_MASK              1U
#define PERAD_PERADL1_MASK              2U
#define PERAD_PERADL2_MASK              4U
#define PERAD_PERADL3_MASK              8U
#define PERAD_PERADL4_MASK              16U
#define PERAD_PERADL5_MASK              32U
#define PERAD_PERADL6_MASK              64U
#define PERAD_PERADL7_MASK              128U
#define PERAD_PERADH0_MASK              256U
#define PERAD_PERADL_MASK               255U
#define PERAD_PERADL_BITNUM             0U


/*** PPSAD - Port AD Polarity Select Register; 0x00000288 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PPSADH - Port ADH Polarity Select Register; 0x00000288 ***/
    union {
      byte Byte;
      struct {
        byte PPSADH0     :1;                                       /* Port ADH pull polarity select 0 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } PPSADHSTR;
    #define PPSADH                      _PPSAD.Overlap_STR.PPSADHSTR.Byte
    #define PPSADH_PPSADH0              _PPSAD.Overlap_STR.PPSADHSTR.Bits.PPSADH0
    
    #define PPSADH_PPSADH0_MASK         1U
    

    /*** PPSADL - Port ADL Polarity Select Register; 0x00000289 ***/
    union {
      byte Byte;
      struct {
        byte PPSADL0     :1;                                       /* Port ADL pull polarity select 0 */
        byte PPSADL1     :1;                                       /* Port ADL pull polarity select 1 */
        byte PPSADL2     :1;                                       /* Port ADL pull polarity select 2 */
        byte PPSADL3     :1;                                       /* Port ADL pull polarity select 3 */
        byte PPSADL4     :1;                                       /* Port ADL pull polarity select 4 */
        byte PPSADL5     :1;                                       /* Port ADL pull polarity select 5 */
        byte PPSADL6     :1;                                       /* Port ADL pull polarity select 6 */
        byte PPSADL7     :1;                                       /* Port ADL pull polarity select 7 */
      } Bits;
    } PPSADLSTR;
    #define PPSADL                      _PPSAD.Overlap_STR.PPSADLSTR.Byte
    #define PPSADL_PPSADL0              _PPSAD.Overlap_STR.PPSADLSTR.Bits.PPSADL0
    #define PPSADL_PPSADL1              _PPSAD.Overlap_STR.PPSADLSTR.Bits.PPSADL1
    #define PPSADL_PPSADL2              _PPSAD.Overlap_STR.PPSADLSTR.Bits.PPSADL2
    #define PPSADL_PPSADL3              _PPSAD.Overlap_STR.PPSADLSTR.Bits.PPSADL3
    #define PPSADL_PPSADL4              _PPSAD.Overlap_STR.PPSADLSTR.Bits.PPSADL4
    #define PPSADL_PPSADL5              _PPSAD.Overlap_STR.PPSADLSTR.Bits.PPSADL5
    #define PPSADL_PPSADL6              _PPSAD.Overlap_STR.PPSADLSTR.Bits.PPSADL6
    #define PPSADL_PPSADL7              _PPSAD.Overlap_STR.PPSADLSTR.Bits.PPSADL7
    
    #define PPSADL_PPSADL0_MASK         1U
    #define PPSADL_PPSADL1_MASK         2U
    #define PPSADL_PPSADL2_MASK         4U
    #define PPSADL_PPSADL3_MASK         8U
    #define PPSADL_PPSADL4_MASK         16U
    #define PPSADL_PPSADL5_MASK         32U
    #define PPSADL_PPSADL6_MASK         64U
    #define PPSADL_PPSADL7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PPSADL0     :1;                                       /* Port AD pull polarity select 0 */
    word PPSADL1     :1;                                       /* Port AD pull polarity select 1 */
    word PPSADL2     :1;                                       /* Port AD pull polarity select 2 */
    word PPSADL3     :1;                                       /* Port AD pull polarity select 3 */
    word PPSADL4     :1;                                       /* Port AD pull polarity select 4 */
    word PPSADL5     :1;                                       /* Port AD pull polarity select 5 */
    word PPSADL6     :1;                                       /* Port AD pull polarity select 6 */
    word PPSADL7     :1;                                       /* Port AD pull polarity select 7 */
    word PPSADH0     :1;                                       /* Port AD pull polarity select 0 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPPSADL :8;
    word grpPPSADH :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PPSADSTR;
extern volatile PPSADSTR _PPSAD @0x00000288;
#define PPSAD                           _PPSAD.Word
#define PPSAD_PPSADL0                   _PPSAD.Bits.PPSADL0
#define PPSAD_PPSADL1                   _PPSAD.Bits.PPSADL1
#define PPSAD_PPSADL2                   _PPSAD.Bits.PPSADL2
#define PPSAD_PPSADL3                   _PPSAD.Bits.PPSADL3
#define PPSAD_PPSADL4                   _PPSAD.Bits.PPSADL4
#define PPSAD_PPSADL5                   _PPSAD.Bits.PPSADL5
#define PPSAD_PPSADL6                   _PPSAD.Bits.PPSADL6
#define PPSAD_PPSADL7                   _PPSAD.Bits.PPSADL7
#define PPSAD_PPSADH0                   _PPSAD.Bits.PPSADH0
#define PPSAD_PPSADL                    _PPSAD.MergedBits.grpPPSADL

#define PPSAD_PPSADL0_MASK              1U
#define PPSAD_PPSADL1_MASK              2U
#define PPSAD_PPSADL2_MASK              4U
#define PPSAD_PPSADL3_MASK              8U
#define PPSAD_PPSADL4_MASK              16U
#define PPSAD_PPSADL5_MASK              32U
#define PPSAD_PPSADL6_MASK              64U
#define PPSAD_PPSADL7_MASK              128U
#define PPSAD_PPSADH0_MASK              256U
#define PPSAD_PPSADL_MASK               255U
#define PPSAD_PPSADL_BITNUM             0U


/*** PIEAD - Port AD Interrupt Enable Register; 0x0000028C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PIEADH - Port ADH Interrupt Enable Register; 0x0000028C ***/
    union {
      byte Byte;
      struct {
        byte PIEADH0     :1;                                       /* Port ADH interrupt enable 0 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } PIEADHSTR;
    #define PIEADH                      _PIEAD.Overlap_STR.PIEADHSTR.Byte
    #define PIEADH_PIEADH0              _PIEAD.Overlap_STR.PIEADHSTR.Bits.PIEADH0
    
    #define PIEADH_PIEADH0_MASK         1U
    

    /*** PIEADL - Port ADL Interrupt Enable Register; 0x0000028D ***/
    union {
      byte Byte;
      struct {
        byte PIEADL0     :1;                                       /* Port ADL interrupt enable 0 */
        byte PIEADL1     :1;                                       /* Port ADL interrupt enable 1 */
        byte PIEADL2     :1;                                       /* Port ADL interrupt enable 2 */
        byte PIEADL3     :1;                                       /* Port ADL interrupt enable 3 */
        byte PIEADL4     :1;                                       /* Port ADL interrupt enable 4 */
        byte PIEADL5     :1;                                       /* Port ADL interrupt enable 5 */
        byte PIEADL6     :1;                                       /* Port ADL interrupt enable 6 */
        byte PIEADL7     :1;                                       /* Port ADL interrupt enable 7 */
      } Bits;
    } PIEADLSTR;
    #define PIEADL                      _PIEAD.Overlap_STR.PIEADLSTR.Byte
    #define PIEADL_PIEADL0              _PIEAD.Overlap_STR.PIEADLSTR.Bits.PIEADL0
    #define PIEADL_PIEADL1              _PIEAD.Overlap_STR.PIEADLSTR.Bits.PIEADL1
    #define PIEADL_PIEADL2              _PIEAD.Overlap_STR.PIEADLSTR.Bits.PIEADL2
    #define PIEADL_PIEADL3              _PIEAD.Overlap_STR.PIEADLSTR.Bits.PIEADL3
    #define PIEADL_PIEADL4              _PIEAD.Overlap_STR.PIEADLSTR.Bits.PIEADL4
    #define PIEADL_PIEADL5              _PIEAD.Overlap_STR.PIEADLSTR.Bits.PIEADL5
    #define PIEADL_PIEADL6              _PIEAD.Overlap_STR.PIEADLSTR.Bits.PIEADL6
    #define PIEADL_PIEADL7              _PIEAD.Overlap_STR.PIEADLSTR.Bits.PIEADL7
    
    #define PIEADL_PIEADL0_MASK         1U
    #define PIEADL_PIEADL1_MASK         2U
    #define PIEADL_PIEADL2_MASK         4U
    #define PIEADL_PIEADL3_MASK         8U
    #define PIEADL_PIEADL4_MASK         16U
    #define PIEADL_PIEADL5_MASK         32U
    #define PIEADL_PIEADL6_MASK         64U
    #define PIEADL_PIEADL7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PIEADL0     :1;                                       /* Port AD interrupt enable 0 */
    word PIEADL1     :1;                                       /* Port AD interrupt enable 1 */
    word PIEADL2     :1;                                       /* Port AD interrupt enable 2 */
    word PIEADL3     :1;                                       /* Port AD interrupt enable 3 */
    word PIEADL4     :1;                                       /* Port AD interrupt enable 4 */
    word PIEADL5     :1;                                       /* Port AD interrupt enable 5 */
    word PIEADL6     :1;                                       /* Port AD interrupt enable 6 */
    word PIEADL7     :1;                                       /* Port AD interrupt enable 7 */
    word PIEADH0     :1;                                       /* Port AD interrupt enable 0 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPIEADL :8;
    word grpPIEADH :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PIEADSTR;
extern volatile PIEADSTR _PIEAD @0x0000028C;
#define PIEAD                           _PIEAD.Word
#define PIEAD_PIEADL0                   _PIEAD.Bits.PIEADL0
#define PIEAD_PIEADL1                   _PIEAD.Bits.PIEADL1
#define PIEAD_PIEADL2                   _PIEAD.Bits.PIEADL2
#define PIEAD_PIEADL3                   _PIEAD.Bits.PIEADL3
#define PIEAD_PIEADL4                   _PIEAD.Bits.PIEADL4
#define PIEAD_PIEADL5                   _PIEAD.Bits.PIEADL5
#define PIEAD_PIEADL6                   _PIEAD.Bits.PIEADL6
#define PIEAD_PIEADL7                   _PIEAD.Bits.PIEADL7
#define PIEAD_PIEADH0                   _PIEAD.Bits.PIEADH0
#define PIEAD_PIEADL                    _PIEAD.MergedBits.grpPIEADL

#define PIEAD_PIEADL0_MASK              1U
#define PIEAD_PIEADL1_MASK              2U
#define PIEAD_PIEADL2_MASK              4U
#define PIEAD_PIEADL3_MASK              8U
#define PIEAD_PIEADL4_MASK              16U
#define PIEAD_PIEADL5_MASK              32U
#define PIEAD_PIEADL6_MASK              64U
#define PIEAD_PIEADL7_MASK              128U
#define PIEAD_PIEADH0_MASK              256U
#define PIEAD_PIEADL_MASK               255U
#define PIEAD_PIEADL_BITNUM             0U


/*** PIFAD - Port AD Interrupt Flag Register; 0x0000028E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** PIFADH - Port ADH Interrupt Flag Register; 0x0000028E ***/
    union {
      byte Byte;
      struct {
        byte PIFADH0     :1;                                       /* Port ADH interrupt flag 0 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } PIFADHSTR;
    #define PIFADH                      _PIFAD.Overlap_STR.PIFADHSTR.Byte
    #define PIFADH_PIFADH0              _PIFAD.Overlap_STR.PIFADHSTR.Bits.PIFADH0
    
    #define PIFADH_PIFADH0_MASK         1U
    

    /*** PIFADL - Port ADL Interrupt Flag Register; 0x0000028F ***/
    union {
      byte Byte;
      struct {
        byte PIFADL0     :1;                                       /* Port ADL interrupt flag 0 */
        byte PIFADL1     :1;                                       /* Port ADL interrupt flag 1 */
        byte PIFADL2     :1;                                       /* Port ADL interrupt flag 2 */
        byte PIFADL3     :1;                                       /* Port ADL interrupt flag 3 */
        byte PIFADL4     :1;                                       /* Port ADL interrupt flag 4 */
        byte PIFADL5     :1;                                       /* Port ADL interrupt flag 5 */
        byte PIFADL6     :1;                                       /* Port ADL interrupt flag 6 */
        byte PIFADL7     :1;                                       /* Port ADL interrupt flag 7 */
      } Bits;
    } PIFADLSTR;
    #define PIFADL                      _PIFAD.Overlap_STR.PIFADLSTR.Byte
    #define PIFADL_PIFADL0              _PIFAD.Overlap_STR.PIFADLSTR.Bits.PIFADL0
    #define PIFADL_PIFADL1              _PIFAD.Overlap_STR.PIFADLSTR.Bits.PIFADL1
    #define PIFADL_PIFADL2              _PIFAD.Overlap_STR.PIFADLSTR.Bits.PIFADL2
    #define PIFADL_PIFADL3              _PIFAD.Overlap_STR.PIFADLSTR.Bits.PIFADL3
    #define PIFADL_PIFADL4              _PIFAD.Overlap_STR.PIFADLSTR.Bits.PIFADL4
    #define PIFADL_PIFADL5              _PIFAD.Overlap_STR.PIFADLSTR.Bits.PIFADL5
    #define PIFADL_PIFADL6              _PIFAD.Overlap_STR.PIFADLSTR.Bits.PIFADL6
    #define PIFADL_PIFADL7              _PIFAD.Overlap_STR.PIFADLSTR.Bits.PIFADL7
    
    #define PIFADL_PIFADL0_MASK         1U
    #define PIFADL_PIFADL1_MASK         2U
    #define PIFADL_PIFADL2_MASK         4U
    #define PIFADL_PIFADL3_MASK         8U
    #define PIFADL_PIFADL4_MASK         16U
    #define PIFADL_PIFADL5_MASK         32U
    #define PIFADL_PIFADL6_MASK         64U
    #define PIFADL_PIFADL7_MASK         128U
    
  } Overlap_STR;

  struct {
    word PIFADL0     :1;                                       /* Port AD interrupt flag 0 */
    word PIFADL1     :1;                                       /* Port AD interrupt flag 1 */
    word PIFADL2     :1;                                       /* Port AD interrupt flag 2 */
    word PIFADL3     :1;                                       /* Port AD interrupt flag 3 */
    word PIFADL4     :1;                                       /* Port AD interrupt flag 4 */
    word PIFADL5     :1;                                       /* Port AD interrupt flag 5 */
    word PIFADL6     :1;                                       /* Port AD interrupt flag 6 */
    word PIFADL7     :1;                                       /* Port AD interrupt flag 7 */
    word PIFADH0     :1;                                       /* Port AD interrupt flag 0 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpPIFADL :8;
    word grpPIFADH :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} PIFADSTR;
extern volatile PIFADSTR _PIFAD @0x0000028E;
#define PIFAD                           _PIFAD.Word
#define PIFAD_PIFADL0                   _PIFAD.Bits.PIFADL0
#define PIFAD_PIFADL1                   _PIFAD.Bits.PIFADL1
#define PIFAD_PIFADL2                   _PIFAD.Bits.PIFADL2
#define PIFAD_PIFADL3                   _PIFAD.Bits.PIFADL3
#define PIFAD_PIFADL4                   _PIFAD.Bits.PIFADL4
#define PIFAD_PIFADL5                   _PIFAD.Bits.PIFADL5
#define PIFAD_PIFADL6                   _PIFAD.Bits.PIFADL6
#define PIFAD_PIFADL7                   _PIFAD.Bits.PIFADL7
#define PIFAD_PIFADH0                   _PIFAD.Bits.PIFADH0
#define PIFAD_PIFADL                    _PIFAD.MergedBits.grpPIFADL

#define PIFAD_PIFADL0_MASK              1U
#define PIFAD_PIFADL1_MASK              2U
#define PIFAD_PIFADL2_MASK              4U
#define PIFAD_PIFADL3_MASK              8U
#define PIFAD_PIFADL4_MASK              16U
#define PIFAD_PIFADL5_MASK              32U
#define PIFAD_PIFADL6_MASK              64U
#define PIFAD_PIFADL7_MASK              128U
#define PIFAD_PIFADH0_MASK              256U
#define PIFAD_PIFADL_MASK               255U
#define PIFAD_PIFADL_BITNUM             0U


/*** DIENAD - Digital Input Enable Register; 0x00000298 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DIENADH - Digital Input Enable Register; 0x00000298 ***/
    union {
      byte Byte;
      struct {
        byte DIENADH0    :1;                                       /* Digital input enable 0 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
    } DIENADHSTR;
    #define DIENADH                     _DIENAD.Overlap_STR.DIENADHSTR.Byte
    #define DIENADH_DIENADH0            _DIENAD.Overlap_STR.DIENADHSTR.Bits.DIENADH0
    
    #define DIENADH_DIENADH0_MASK       1U
    

    /*** DIENADL - Digital Input Enable Register; 0x00000299 ***/
    union {
      byte Byte;
      struct {
        byte DIENADL0    :1;                                       /* Digital input enable 0 */
        byte DIENADL1    :1;                                       /* Digital input enable 1 */
        byte DIENADL2    :1;                                       /* Digital input enable 2 */
        byte DIENADL3    :1;                                       /* Digital input enable 3 */
        byte DIENADL4    :1;                                       /* Digital input enable 4 */
        byte DIENADL5    :1;                                       /* Digital input enable 5 */
        byte DIENADL6    :1;                                       /* Digital input enable 6 */
        byte DIENADL7    :1;                                       /* Digital input enable 7 */
      } Bits;
    } DIENADLSTR;
    #define DIENADL                     _DIENAD.Overlap_STR.DIENADLSTR.Byte
    #define DIENADL_DIENADL0            _DIENAD.Overlap_STR.DIENADLSTR.Bits.DIENADL0
    #define DIENADL_DIENADL1            _DIENAD.Overlap_STR.DIENADLSTR.Bits.DIENADL1
    #define DIENADL_DIENADL2            _DIENAD.Overlap_STR.DIENADLSTR.Bits.DIENADL2
    #define DIENADL_DIENADL3            _DIENAD.Overlap_STR.DIENADLSTR.Bits.DIENADL3
    #define DIENADL_DIENADL4            _DIENAD.Overlap_STR.DIENADLSTR.Bits.DIENADL4
    #define DIENADL_DIENADL5            _DIENAD.Overlap_STR.DIENADLSTR.Bits.DIENADL5
    #define DIENADL_DIENADL6            _DIENAD.Overlap_STR.DIENADLSTR.Bits.DIENADL6
    #define DIENADL_DIENADL7            _DIENAD.Overlap_STR.DIENADLSTR.Bits.DIENADL7
    
    #define DIENADL_DIENADL0_MASK       1U
    #define DIENADL_DIENADL1_MASK       2U
    #define DIENADL_DIENADL2_MASK       4U
    #define DIENADL_DIENADL3_MASK       8U
    #define DIENADL_DIENADL4_MASK       16U
    #define DIENADL_DIENADL5_MASK       32U
    #define DIENADL_DIENADL6_MASK       64U
    #define DIENADL_DIENADL7_MASK       128U
    
  } Overlap_STR;

  struct {
    word DIENADL0    :1;                                       /* Digital input enable 0 */
    word DIENADL1    :1;                                       /* Digital input enable 1 */
    word DIENADL2    :1;                                       /* Digital input enable 2 */
    word DIENADL3    :1;                                       /* Digital input enable 3 */
    word DIENADL4    :1;                                       /* Digital input enable 4 */
    word DIENADL5    :1;                                       /* Digital input enable 5 */
    word DIENADL6    :1;                                       /* Digital input enable 6 */
    word DIENADL7    :1;                                       /* Digital input enable 7 */
    word DIENADH0    :1;                                       /* Digital input enable 8 */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
  struct {
    word grpDIENADL :8;
    word grpDIENADH :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
    word         :1;
  } MergedBits;
} DIENADSTR;
extern volatile DIENADSTR _DIENAD @0x00000298;
#define DIENAD                          _DIENAD.Word
#define DIENAD_DIENADL0                 _DIENAD.Bits.DIENADL0
#define DIENAD_DIENADL1                 _DIENAD.Bits.DIENADL1
#define DIENAD_DIENADL2                 _DIENAD.Bits.DIENADL2
#define DIENAD_DIENADL3                 _DIENAD.Bits.DIENADL3
#define DIENAD_DIENADL4                 _DIENAD.Bits.DIENADL4
#define DIENAD_DIENADL5                 _DIENAD.Bits.DIENADL5
#define DIENAD_DIENADL6                 _DIENAD.Bits.DIENADL6
#define DIENAD_DIENADL7                 _DIENAD.Bits.DIENADL7
#define DIENAD_DIENADH0                 _DIENAD.Bits.DIENADH0
#define DIENAD_DIENADL                  _DIENAD.MergedBits.grpDIENADL

#define DIENAD_DIENADL0_MASK            1U
#define DIENAD_DIENADL1_MASK            2U
#define DIENAD_DIENADL2_MASK            4U
#define DIENAD_DIENADL3_MASK            8U
#define DIENAD_DIENADL4_MASK            16U
#define DIENAD_DIENADL5_MASK            32U
#define DIENAD_DIENADL6_MASK            64U
#define DIENAD_DIENADL7_MASK            128U
#define DIENAD_DIENADH0_MASK            256U
#define DIENAD_DIENADL_MASK             255U
#define DIENAD_DIENADL_BITNUM           0U


/*** PTT - Port T Data Register; 0x000002C0 ***/
typedef union {
  byte Byte;
  struct {
    byte PTT0        :1;                                       /* Port T general purpose I/O data 0 */
    byte PTT1        :1;                                       /* Port T general purpose I/O data 1 */
    byte PTT2        :1;                                       /* Port T general purpose I/O data 2 */
    byte PTT3        :1;                                       /* Port T general purpose I/O data 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTTSTR;
extern volatile PTTSTR _PTT @0x000002C0;
#define PTT                             _PTT.Byte
#define PTT_PTT0                        _PTT.Bits.PTT0
#define PTT_PTT1                        _PTT.Bits.PTT1
#define PTT_PTT2                        _PTT.Bits.PTT2
#define PTT_PTT3                        _PTT.Bits.PTT3
#define PTT_PTT                         _PTT.MergedBits.grpPTT

#define PTT_PTT0_MASK                   1U
#define PTT_PTT1_MASK                   2U
#define PTT_PTT2_MASK                   4U
#define PTT_PTT3_MASK                   8U
#define PTT_PTT_MASK                    15U
#define PTT_PTT_BITNUM                  0U


/*** PTIT - Port T Input Register; 0x000002C1 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIT0       :1;                                       /* Port T data input 0 */
    byte PTIT1       :1;                                       /* Port T data input 1 */
    byte PTIT2       :1;                                       /* Port T data input 2 */
    byte PTIT3       :1;                                       /* Port T data input 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIT :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTITSTR;
extern volatile PTITSTR _PTIT @0x000002C1;
#define PTIT                            _PTIT.Byte
#define PTIT_PTIT0                      _PTIT.Bits.PTIT0
#define PTIT_PTIT1                      _PTIT.Bits.PTIT1
#define PTIT_PTIT2                      _PTIT.Bits.PTIT2
#define PTIT_PTIT3                      _PTIT.Bits.PTIT3
#define PTIT_PTIT                       _PTIT.MergedBits.grpPTIT

#define PTIT_PTIT0_MASK                 1U
#define PTIT_PTIT1_MASK                 2U
#define PTIT_PTIT2_MASK                 4U
#define PTIT_PTIT3_MASK                 8U
#define PTIT_PTIT_MASK                  15U
#define PTIT_PTIT_BITNUM                0U


/*** DDRT - Port T Data Direction Register; 0x000002C2 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRT0       :1;                                       /* Port T data direction select 0 */
    byte DDRT1       :1;                                       /* Port T data direction select 1 */
    byte DDRT2       :1;                                       /* Port T data direction select 2 */
    byte DDRT3       :1;                                       /* Port T data direction select 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRT :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRTSTR;
extern volatile DDRTSTR _DDRT @0x000002C2;
#define DDRT                            _DDRT.Byte
#define DDRT_DDRT0                      _DDRT.Bits.DDRT0
#define DDRT_DDRT1                      _DDRT.Bits.DDRT1
#define DDRT_DDRT2                      _DDRT.Bits.DDRT2
#define DDRT_DDRT3                      _DDRT.Bits.DDRT3
#define DDRT_DDRT                       _DDRT.MergedBits.grpDDRT

#define DDRT_DDRT0_MASK                 1U
#define DDRT_DDRT1_MASK                 2U
#define DDRT_DDRT2_MASK                 4U
#define DDRT_DDRT3_MASK                 8U
#define DDRT_DDRT_MASK                  15U
#define DDRT_DDRT_BITNUM                0U


/*** PERT - Port T Pull Device Enable Register; 0x000002C3 ***/
typedef union {
  byte Byte;
  struct {
    byte PERT0       :1;                                       /* Port T pull device enable 0 */
    byte PERT1       :1;                                       /* Port T pull device enable 1 */
    byte PERT2       :1;                                       /* Port T pull device enable 2 */
    byte PERT3       :1;                                       /* Port T pull device enable 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERT :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERTSTR;
extern volatile PERTSTR _PERT @0x000002C3;
#define PERT                            _PERT.Byte
#define PERT_PERT0                      _PERT.Bits.PERT0
#define PERT_PERT1                      _PERT.Bits.PERT1
#define PERT_PERT2                      _PERT.Bits.PERT2
#define PERT_PERT3                      _PERT.Bits.PERT3
#define PERT_PERT                       _PERT.MergedBits.grpPERT

#define PERT_PERT0_MASK                 1U
#define PERT_PERT1_MASK                 2U
#define PERT_PERT2_MASK                 4U
#define PERT_PERT3_MASK                 8U
#define PERT_PERT_MASK                  15U
#define PERT_PERT_BITNUM                0U


/*** PPST - Port T Polarity Select Register; 0x000002C4 ***/
typedef union {
  byte Byte;
  struct {
    byte PPST0       :1;                                       /* Port T pull polarity select 0 */
    byte PPST1       :1;                                       /* Port T pull polarity select 1 */
    byte PPST2       :1;                                       /* Port T pull polarity select 2 */
    byte PPST3       :1;                                       /* Port T pull polarity select 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPST :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSTSTR;
extern volatile PPSTSTR _PPST @0x000002C4;
#define PPST                            _PPST.Byte
#define PPST_PPST0                      _PPST.Bits.PPST0
#define PPST_PPST1                      _PPST.Bits.PPST1
#define PPST_PPST2                      _PPST.Bits.PPST2
#define PPST_PPST3                      _PPST.Bits.PPST3
#define PPST_PPST                       _PPST.MergedBits.grpPPST

#define PPST_PPST0_MASK                 1U
#define PPST_PPST1_MASK                 2U
#define PPST_PPST2_MASK                 4U
#define PPST_PPST3_MASK                 8U
#define PPST_PPST_MASK                  15U
#define PPST_PPST_BITNUM                0U


/*** PTS - Port S Data Register; 0x000002D0 ***/
typedef union {
  byte Byte;
  struct {
    byte PTS0        :1;                                       /* Port S general purpose I/O data 0 */
    byte PTS1        :1;                                       /* Port S general purpose I/O data 1 */
    byte PTS2        :1;                                       /* Port S general purpose I/O data 2 */
    byte PTS3        :1;                                       /* Port S general purpose I/O data 3 */
    byte PTS4        :1;                                       /* Port S general purpose I/O data 4 */
    byte PTS5        :1;                                       /* Port S general purpose I/O data 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTS  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTSSTR;
extern volatile PTSSTR _PTS @0x000002D0;
#define PTS                             _PTS.Byte
#define PTS_PTS0                        _PTS.Bits.PTS0
#define PTS_PTS1                        _PTS.Bits.PTS1
#define PTS_PTS2                        _PTS.Bits.PTS2
#define PTS_PTS3                        _PTS.Bits.PTS3
#define PTS_PTS4                        _PTS.Bits.PTS4
#define PTS_PTS5                        _PTS.Bits.PTS5
#define PTS_PTS                         _PTS.MergedBits.grpPTS

#define PTS_PTS0_MASK                   1U
#define PTS_PTS1_MASK                   2U
#define PTS_PTS2_MASK                   4U
#define PTS_PTS3_MASK                   8U
#define PTS_PTS4_MASK                   16U
#define PTS_PTS5_MASK                   32U
#define PTS_PTS_MASK                    63U
#define PTS_PTS_BITNUM                  0U


/*** PTIS - Port S Input Register; 0x000002D1 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIS0       :1;                                       /* Port S data input 0 */
    byte PTIS1       :1;                                       /* Port S data input 1 */
    byte PTIS2       :1;                                       /* Port S data input 2 */
    byte PTIS3       :1;                                       /* Port S data input 3 */
    byte PTIS4       :1;                                       /* Port S data input 4 */
    byte PTIS5       :1;                                       /* Port S data input 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTISSTR;
extern volatile PTISSTR _PTIS @0x000002D1;
#define PTIS                            _PTIS.Byte
#define PTIS_PTIS0                      _PTIS.Bits.PTIS0
#define PTIS_PTIS1                      _PTIS.Bits.PTIS1
#define PTIS_PTIS2                      _PTIS.Bits.PTIS2
#define PTIS_PTIS3                      _PTIS.Bits.PTIS3
#define PTIS_PTIS4                      _PTIS.Bits.PTIS4
#define PTIS_PTIS5                      _PTIS.Bits.PTIS5
#define PTIS_PTIS                       _PTIS.MergedBits.grpPTIS

#define PTIS_PTIS0_MASK                 1U
#define PTIS_PTIS1_MASK                 2U
#define PTIS_PTIS2_MASK                 4U
#define PTIS_PTIS3_MASK                 8U
#define PTIS_PTIS4_MASK                 16U
#define PTIS_PTIS5_MASK                 32U
#define PTIS_PTIS_MASK                  63U
#define PTIS_PTIS_BITNUM                0U


/*** DDRS - Port S Data Direction Register; 0x000002D2 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRS0       :1;                                       /* Port S data direction select 0 */
    byte DDRS1       :1;                                       /* Port S data direction select 1 */
    byte DDRS2       :1;                                       /* Port S data direction select 2 */
    byte DDRS3       :1;                                       /* Port S data direction select 3 */
    byte DDRS4       :1;                                       /* Port S data direction select 4 */
    byte DDRS5       :1;                                       /* Port S data direction select 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRSSTR;
extern volatile DDRSSTR _DDRS @0x000002D2;
#define DDRS                            _DDRS.Byte
#define DDRS_DDRS0                      _DDRS.Bits.DDRS0
#define DDRS_DDRS1                      _DDRS.Bits.DDRS1
#define DDRS_DDRS2                      _DDRS.Bits.DDRS2
#define DDRS_DDRS3                      _DDRS.Bits.DDRS3
#define DDRS_DDRS4                      _DDRS.Bits.DDRS4
#define DDRS_DDRS5                      _DDRS.Bits.DDRS5
#define DDRS_DDRS                       _DDRS.MergedBits.grpDDRS

#define DDRS_DDRS0_MASK                 1U
#define DDRS_DDRS1_MASK                 2U
#define DDRS_DDRS2_MASK                 4U
#define DDRS_DDRS3_MASK                 8U
#define DDRS_DDRS4_MASK                 16U
#define DDRS_DDRS5_MASK                 32U
#define DDRS_DDRS_MASK                  63U
#define DDRS_DDRS_BITNUM                0U


/*** PERS - Port S Pull Device Enable Register; 0x000002D3 ***/
typedef union {
  byte Byte;
  struct {
    byte PERS0       :1;                                       /* Port S pull device enable 0 */
    byte PERS1       :1;                                       /* Port S pull device enable 1 */
    byte PERS2       :1;                                       /* Port S pull device enable 2 */
    byte PERS3       :1;                                       /* Port S pull device enable 3 */
    byte PERS4       :1;                                       /* Port S pull device enable 4 */
    byte PERS5       :1;                                       /* Port S pull device enable 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERSSTR;
extern volatile PERSSTR _PERS @0x000002D3;
#define PERS                            _PERS.Byte
#define PERS_PERS0                      _PERS.Bits.PERS0
#define PERS_PERS1                      _PERS.Bits.PERS1
#define PERS_PERS2                      _PERS.Bits.PERS2
#define PERS_PERS3                      _PERS.Bits.PERS3
#define PERS_PERS4                      _PERS.Bits.PERS4
#define PERS_PERS5                      _PERS.Bits.PERS5
#define PERS_PERS                       _PERS.MergedBits.grpPERS

#define PERS_PERS0_MASK                 1U
#define PERS_PERS1_MASK                 2U
#define PERS_PERS2_MASK                 4U
#define PERS_PERS3_MASK                 8U
#define PERS_PERS4_MASK                 16U
#define PERS_PERS5_MASK                 32U
#define PERS_PERS_MASK                  63U
#define PERS_PERS_BITNUM                0U


/*** PPSS - Port S Polarity Select Register; 0x000002D4 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSS0       :1;                                       /* Port S pull polarity select 0 */
    byte PPSS1       :1;                                       /* Port S pull polarity select 1 */
    byte PPSS2       :1;                                       /* Port S pull polarity select 2 */
    byte PPSS3       :1;                                       /* Port S pull polarity select 3 */
    byte PPSS4       :1;                                       /* Port S pull polarity select 4 */
    byte PPSS5       :1;                                       /* Port S pull polarity select 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSSSTR;
extern volatile PPSSSTR _PPSS @0x000002D4;
#define PPSS                            _PPSS.Byte
#define PPSS_PPSS0                      _PPSS.Bits.PPSS0
#define PPSS_PPSS1                      _PPSS.Bits.PPSS1
#define PPSS_PPSS2                      _PPSS.Bits.PPSS2
#define PPSS_PPSS3                      _PPSS.Bits.PPSS3
#define PPSS_PPSS4                      _PPSS.Bits.PPSS4
#define PPSS_PPSS5                      _PPSS.Bits.PPSS5
#define PPSS_PPSS                       _PPSS.MergedBits.grpPPSS

#define PPSS_PPSS0_MASK                 1U
#define PPSS_PPSS1_MASK                 2U
#define PPSS_PPSS2_MASK                 4U
#define PPSS_PPSS3_MASK                 8U
#define PPSS_PPSS4_MASK                 16U
#define PPSS_PPSS5_MASK                 32U
#define PPSS_PPSS_MASK                  63U
#define PPSS_PPSS_BITNUM                0U


/*** PIES - Port S Interrupt Enable Register; 0x000002D6 ***/
typedef union {
  byte Byte;
  struct {
    byte PIES0       :1;                                       /* Port S interrupt enable 0 */
    byte PIES1       :1;                                       /* Port S interrupt enable 1 */
    byte PIES2       :1;                                       /* Port S interrupt enable 2 */
    byte PIES3       :1;                                       /* Port S interrupt enable 3 */
    byte PIES4       :1;                                       /* Port S interrupt enable 4 */
    byte PIES5       :1;                                       /* Port S interrupt enable 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIES :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIESSTR;
extern volatile PIESSTR _PIES @0x000002D6;
#define PIES                            _PIES.Byte
#define PIES_PIES0                      _PIES.Bits.PIES0
#define PIES_PIES1                      _PIES.Bits.PIES1
#define PIES_PIES2                      _PIES.Bits.PIES2
#define PIES_PIES3                      _PIES.Bits.PIES3
#define PIES_PIES4                      _PIES.Bits.PIES4
#define PIES_PIES5                      _PIES.Bits.PIES5
#define PIES_PIES                       _PIES.MergedBits.grpPIES

#define PIES_PIES0_MASK                 1U
#define PIES_PIES1_MASK                 2U
#define PIES_PIES2_MASK                 4U
#define PIES_PIES3_MASK                 8U
#define PIES_PIES4_MASK                 16U
#define PIES_PIES5_MASK                 32U
#define PIES_PIES_MASK                  63U
#define PIES_PIES_BITNUM                0U


/*** PIFS - Port S Interrupt Flag Register; 0x000002D7 ***/
typedef union {
  byte Byte;
  struct {
    byte PIFS0       :1;                                       /* Port S interrupt flag 0 */
    byte PIFS1       :1;                                       /* Port S interrupt flag 1 */
    byte PIFS2       :1;                                       /* Port S interrupt flag 2 */
    byte PIFS3       :1;                                       /* Port S interrupt flag 3 */
    byte PIFS4       :1;                                       /* Port S interrupt flag 4 */
    byte PIFS5       :1;                                       /* Port S interrupt flag 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPIFS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PIFSSTR;
extern volatile PIFSSTR _PIFS @0x000002D7;
#define PIFS                            _PIFS.Byte
#define PIFS_PIFS0                      _PIFS.Bits.PIFS0
#define PIFS_PIFS1                      _PIFS.Bits.PIFS1
#define PIFS_PIFS2                      _PIFS.Bits.PIFS2
#define PIFS_PIFS3                      _PIFS.Bits.PIFS3
#define PIFS_PIFS4                      _PIFS.Bits.PIFS4
#define PIFS_PIFS5                      _PIFS.Bits.PIFS5
#define PIFS_PIFS                       _PIFS.MergedBits.grpPIFS

#define PIFS_PIFS0_MASK                 1U
#define PIFS_PIFS1_MASK                 2U
#define PIFS_PIFS2_MASK                 4U
#define PIFS_PIFS3_MASK                 8U
#define PIFS_PIFS4_MASK                 16U
#define PIFS_PIFS5_MASK                 32U
#define PIFS_PIFS_MASK                  63U
#define PIFS_PIFS_BITNUM                0U


/*** WOMS - Port S Wired-Or Mode Register; 0x000002DF ***/
typedef union {
  byte Byte;
  struct {
    byte WOMS0       :1;                                       /* Port S wired-or mode 0 */
    byte WOMS1       :1;                                       /* Port S wired-or mode 1 */
    byte WOMS2       :1;                                       /* Port S wired-or mode 2 */
    byte WOMS3       :1;                                       /* Port S wired-or mode 3 */
    byte WOMS4       :1;                                       /* Port S wired-or mode 4 */
    byte WOMS5       :1;                                       /* Port S wired-or mode 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpWOMS :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} WOMSSTR;
extern volatile WOMSSTR _WOMS @0x000002DF;
#define WOMS                            _WOMS.Byte
#define WOMS_WOMS0                      _WOMS.Bits.WOMS0
#define WOMS_WOMS1                      _WOMS.Bits.WOMS1
#define WOMS_WOMS2                      _WOMS.Bits.WOMS2
#define WOMS_WOMS3                      _WOMS.Bits.WOMS3
#define WOMS_WOMS4                      _WOMS.Bits.WOMS4
#define WOMS_WOMS5                      _WOMS.Bits.WOMS5
#define WOMS_WOMS                       _WOMS.MergedBits.grpWOMS

#define WOMS_WOMS0_MASK                 1U
#define WOMS_WOMS1_MASK                 2U
#define WOMS_WOMS2_MASK                 4U
#define WOMS_WOMS3_MASK                 8U
#define WOMS_WOMS4_MASK                 16U
#define WOMS_WOMS5_MASK                 32U
#define WOMS_WOMS_MASK                  63U
#define WOMS_WOMS_BITNUM                0U


/*** PTP - Port P Data Register; 0x000002F0 ***/
typedef union {
  byte Byte;
  struct {
    byte PTP0        :1;                                       /* Port P general purpose I/O data 0 */
    byte PTP1        :1;                                       /* Port P general purpose I/O data 1 */
    byte PTP2        :1;                                       /* Port P general purpose I/O data 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTP  :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTPSTR;
extern volatile PTPSTR _PTP @0x000002F0;
#define PTP                             _PTP.Byte
#define PTP_PTP0                        _PTP.Bits.PTP0
#define PTP_PTP1                        _PTP.Bits.PTP1
#define PTP_PTP2                        _PTP.Bits.PTP2
#define PTP_PTP                         _PTP.MergedBits.grpPTP

#define PTP_PTP0_MASK                   1U
#define PTP_PTP1_MASK                   2U
#define PTP_PTP2_MASK                   4U
#define PTP_PTP_MASK                    7U
#define PTP_PTP_BITNUM                  0U


/*** PTIP - Port P Input Register; 0x000002F1 ***/
typedef union {
  byte Byte;
  struct {
    byte PTIP0       :1;                                       /* Port P data input 0 */
    byte PTIP1       :1;                                       /* Port P data input 1 */
    byte PTIP2       :1;                                       /* Port P data input 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPTIP :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PTIPSTR;
extern volatile PTIPSTR _PTIP @0x000002F1;
#define PTIP                            _PTIP.Byte
#define PTIP_PTIP0                      _PTIP.Bits.PTIP0
#define PTIP_PTIP1                      _PTIP.Bits.PTIP1
#define PTIP_PTIP2                      _PTIP.Bits.PTIP2
#define PTIP_PTIP                       _PTIP.MergedBits.grpPTIP

#define PTIP_PTIP0_MASK                 1U
#define PTIP_PTIP1_MASK                 2U
#define PTIP_PTIP2_MASK                 4U
#define PTIP_PTIP_MASK                  7U
#define PTIP_PTIP_BITNUM                0U


/*** DDRP - Port P Data Direction Register; 0x000002F2 ***/
typedef union {
  byte Byte;
  struct {
    byte DDRP0       :1;                                       /* Port P data direction select 0 */
    byte DDRP1       :1;                                       /* Port P data direction select 1 */
    byte DDRP2       :1;                                       /* Port P data direction select 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDDRP :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DDRPSTR;
extern volatile DDRPSTR _DDRP @0x000002F2;
#define DDRP                            _DDRP.Byte
#define DDRP_DDRP0                      _DDRP.Bits.DDRP0
#define DDRP_DDRP1                      _DDRP.Bits.DDRP1
#define DDRP_DDRP2                      _DDRP.Bits.DDRP2
#define DDRP_DDRP                       _DDRP.MergedBits.grpDDRP

#define DDRP_DDRP0_MASK                 1U
#define DDRP_DDRP1_MASK                 2U
#define DDRP_DDRP2_MASK                 4U
#define DDRP_DDRP_MASK                  7U
#define DDRP_DDRP_BITNUM                0U


/*** PERP - Port P Pull Device Enable Register; 0x000002F3 ***/
typedef union {
  byte Byte;
  struct {
    byte PERP0       :1;                                       /* Port P pull device enable 0 */
    byte PERP1       :1;                                       /* Port P pull device enable 1 */
    byte PERP2       :1;                                       /* Port P pull device enable 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPERP :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PERPSTR;
extern volatile PERPSTR _PERP @0x000002F3;
#define PERP                            _PERP.Byte
#define PERP_PERP0                      _PERP.Bits.PERP0
#define PERP_PERP1                      _PERP.Bits.PERP1
#define PERP_PERP2                      _PERP.Bits.PERP2
#define PERP_PERP                       _PERP.MergedBits.grpPERP

#define PERP_PERP0_MASK                 1U
#define PERP_PERP1_MASK                 2U
#define PERP_PERP2_MASK                 4U
#define PERP_PERP_MASK                  7U
#define PERP_PERP_BITNUM                0U


/*** PPSP - Port P Polarity Select Register; 0x000002F4 ***/
typedef union {
  byte Byte;
  struct {
    byte PPSP0       :1;                                       /* Port P pull polarity select 0 */
    byte PPSP1       :1;                                       /* Port P pull polarity select 1 */
    byte PPSP2       :1;                                       /* Port P pull polarity select 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPPSP :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPSPSTR;
extern volatile PPSPSTR _PPSP @0x000002F4;
#define PPSP                            _PPSP.Byte
#define PPSP_PPSP0                      _PPSP.Bits.PPSP0
#define PPSP_PPSP1                      _PPSP.Bits.PPSP1
#define PPSP_PPSP2                      _PPSP.Bits.PPSP2
#define PPSP_PPSP                       _PPSP.MergedBits.grpPPSP

#define PPSP_PPSP0_MASK                 1U
#define PPSP_PPSP1_MASK                 2U
#define PPSP_PPSP2_MASK                 4U
#define PPSP_PPSP_MASK                  7U
#define PPSP_PPSP_BITNUM                0U


/*** PIEP - Port P Interrupt Enable Register; 0x000002F6 ***/
typedef union {
  byte Byte;
  struct {
    byte PIEP0       :1;                                       /* Port P interrupt enable 0 */
    byte PIEP1       :1;                                       /* Port P interrupt enable 1 */
    byte PIEP2       :1;                                       /* Port P interrupt enable 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte OCIE1       :1;                                       /* Over-current interrupt enable */
  } Bits;
  struct {
    byte grpPIEP :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpOCIE_1 :1;
  } MergedBits;
} PIEPSTR;
extern volatile PIEPSTR _PIEP @0x000002F6;
#define PIEP                            _PIEP.Byte
#define PIEP_PIEP0                      _PIEP.Bits.PIEP0
#define PIEP_PIEP1                      _PIEP.Bits.PIEP1
#define PIEP_PIEP2                      _PIEP.Bits.PIEP2
#define PIEP_OCIE1                      _PIEP.Bits.OCIE1
#define PIEP_PIEP                       _PIEP.MergedBits.grpPIEP

#define PIEP_PIEP0_MASK                 1U
#define PIEP_PIEP1_MASK                 2U
#define PIEP_PIEP2_MASK                 4U
#define PIEP_OCIE1_MASK                 128U
#define PIEP_PIEP_MASK                  7U
#define PIEP_PIEP_BITNUM                0U


/*** PIFP - Port P Interrupt Flag Register; 0x000002F7 ***/
typedef union {
  byte Byte;
  struct {
    byte PIFP0       :1;                                       /* Port P interrupt flag 0 */
    byte PIFP1       :1;                                       /* Port P interrupt flag 1 */
    byte PIFP2       :1;                                       /* Port P interrupt flag 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte OCIF1       :1;                                       /* Over-current interrupt flag */
  } Bits;
  struct {
    byte grpPIFP :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpOCIF_1 :1;
  } MergedBits;
} PIFPSTR;
extern volatile PIFPSTR _PIFP @0x000002F7;
#define PIFP                            _PIFP.Byte
#define PIFP_PIFP0                      _PIFP.Bits.PIFP0
#define PIFP_PIFP1                      _PIFP.Bits.PIFP1
#define PIFP_PIFP2                      _PIFP.Bits.PIFP2
#define PIFP_OCIF1                      _PIFP.Bits.OCIF1
#define PIFP_PIFP                       _PIFP.MergedBits.grpPIFP

#define PIFP_PIFP0_MASK                 1U
#define PIFP_PIFP1_MASK                 2U
#define PIFP_PIFP2_MASK                 4U
#define PIFP_OCIF1_MASK                 128U
#define PIFP_PIFP_MASK                  7U
#define PIFP_PIFP_BITNUM                0U


/*** RDRP - Port P Reduced Drive Register; 0x000002FD ***/
typedef union {
  byte Byte;
  struct {
    byte RDRP0       :1;                                       /* Port P reduced drive select 0 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} RDRPSTR;
extern volatile RDRPSTR _RDRP @0x000002FD;
#define RDRP                            _RDRP.Byte
#define RDRP_RDRP0                      _RDRP.Bits.RDRP0

#define RDRP_RDRP0_MASK                 1U


/*** FCLKDIV - Flash Clock Divider Register; 0x00000380 ***/
typedef union {
  byte Byte;
  struct {
    byte FDIV0       :1;                                       /* Clock Divider Bit 0 */
    byte FDIV1       :1;                                       /* Clock Divider Bit 1 */
    byte FDIV2       :1;                                       /* Clock Divider Bit 2 */
    byte FDIV3       :1;                                       /* Clock Divider Bit 3 */
    byte FDIV4       :1;                                       /* Clock Divider Bit 4 */
    byte FDIV5       :1;                                       /* Clock Divider Bit 5 */
    byte FDIVLCK     :1;                                       /* Clock divider locked */
    byte FDIVLD      :1;                                       /* Clock Divider Loaded */
  } Bits;
  struct {
    byte grpFDIV :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} FCLKDIVSTR;
extern volatile FCLKDIVSTR _FCLKDIV @0x00000380;
#define FCLKDIV                         _FCLKDIV.Byte
#define FCLKDIV_FDIV0                   _FCLKDIV.Bits.FDIV0
#define FCLKDIV_FDIV1                   _FCLKDIV.Bits.FDIV1
#define FCLKDIV_FDIV2                   _FCLKDIV.Bits.FDIV2
#define FCLKDIV_FDIV3                   _FCLKDIV.Bits.FDIV3
#define FCLKDIV_FDIV4                   _FCLKDIV.Bits.FDIV4
#define FCLKDIV_FDIV5                   _FCLKDIV.Bits.FDIV5
#define FCLKDIV_FDIVLCK                 _FCLKDIV.Bits.FDIVLCK
#define FCLKDIV_FDIVLD                  _FCLKDIV.Bits.FDIVLD
#define FCLKDIV_FDIV                    _FCLKDIV.MergedBits.grpFDIV

#define FCLKDIV_FDIV0_MASK              1U
#define FCLKDIV_FDIV1_MASK              2U
#define FCLKDIV_FDIV2_MASK              4U
#define FCLKDIV_FDIV3_MASK              8U
#define FCLKDIV_FDIV4_MASK              16U
#define FCLKDIV_FDIV5_MASK              32U
#define FCLKDIV_FDIVLCK_MASK            64U
#define FCLKDIV_FDIVLD_MASK             128U
#define FCLKDIV_FDIV_MASK               63U
#define FCLKDIV_FDIV_BITNUM             0U


/*** FSEC - Flash Security Register; 0x00000381 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} FSECSTR;
extern volatile FSECSTR _FSEC @0x00000381;
#define FSEC                            _FSEC.Byte
#define FSEC_SEC0                       _FSEC.Bits.SEC0
#define FSEC_SEC1                       _FSEC.Bits.SEC1
#define FSEC_RNV2                       _FSEC.Bits.RNV2
#define FSEC_RNV3                       _FSEC.Bits.RNV3
#define FSEC_RNV4                       _FSEC.Bits.RNV4
#define FSEC_RNV5                       _FSEC.Bits.RNV5
#define FSEC_KEYEN0                     _FSEC.Bits.KEYEN0
#define FSEC_KEYEN1                     _FSEC.Bits.KEYEN1
#define FSEC_SEC                        _FSEC.MergedBits.grpSEC
#define FSEC_RNV_2                      _FSEC.MergedBits.grpRNV_2
#define FSEC_KEYEN                      _FSEC.MergedBits.grpKEYEN
#define FSEC_RNV                        FSEC_RNV_2

#define FSEC_SEC0_MASK                  1U
#define FSEC_SEC1_MASK                  2U
#define FSEC_RNV2_MASK                  4U
#define FSEC_RNV3_MASK                  8U
#define FSEC_RNV4_MASK                  16U
#define FSEC_RNV5_MASK                  32U
#define FSEC_KEYEN0_MASK                64U
#define FSEC_KEYEN1_MASK                128U
#define FSEC_SEC_MASK                   3U
#define FSEC_SEC_BITNUM                 0U
#define FSEC_RNV_2_MASK                 60U
#define FSEC_RNV_2_BITNUM               2U
#define FSEC_KEYEN_MASK                 192U
#define FSEC_KEYEN_BITNUM               6U


/*** FCCOBIX - Flash CCOB Index Register; 0x00000382 ***/
typedef union {
  byte Byte;
  struct {
    byte CCOBIX0     :1;                                       /* Common Command Register Index Bit 0 */
    byte CCOBIX1     :1;                                       /* Common Command Register Index Bit 1 */
    byte CCOBIX2     :1;                                       /* Common Command Register Index Bit 2 */
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
} FCCOBIXSTR;
extern volatile FCCOBIXSTR _FCCOBIX @0x00000382;
#define FCCOBIX                         _FCCOBIX.Byte
#define FCCOBIX_CCOBIX0                 _FCCOBIX.Bits.CCOBIX0
#define FCCOBIX_CCOBIX1                 _FCCOBIX.Bits.CCOBIX1
#define FCCOBIX_CCOBIX2                 _FCCOBIX.Bits.CCOBIX2
#define FCCOBIX_CCOBIX                  _FCCOBIX.MergedBits.grpCCOBIX

#define FCCOBIX_CCOBIX0_MASK            1U
#define FCCOBIX_CCOBIX1_MASK            2U
#define FCCOBIX_CCOBIX2_MASK            4U
#define FCCOBIX_CCOBIX_MASK             7U
#define FCCOBIX_CCOBIX_BITNUM           0U


/*** FPSTAT - Flash Protection Status Register; 0x00000383 ***/
typedef union {
  byte Byte;
  struct {
    byte WSTATACK    :1;                                       /* Wait-State Switch Acknowledge */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FPOVRD      :1;                                       /* Flash Protection Override Status */
  } Bits;
} FPSTATSTR;
extern volatile FPSTATSTR _FPSTAT @0x00000383;
#define FPSTAT                          _FPSTAT.Byte
#define FPSTAT_WSTATACK                 _FPSTAT.Bits.WSTATACK
#define FPSTAT_FPOVRD                   _FPSTAT.Bits.FPOVRD

#define FPSTAT_WSTATACK_MASK            1U
#define FPSTAT_FPOVRD_MASK              128U


/*** FCNFG - Flash Configuration Register; 0x00000384 ***/
typedef union {
  byte Byte;
  struct {
    byte FSFD        :1;                                       /* Force Single Bit Fault Detect */
    byte FDFD        :1;                                       /* Force Double Bit Fault Detect */
    byte WSTAT       :2;                                       /* Wait State control bits */
    byte IGNSF       :1;                                       /* Ignore Single Bit Fault */
    byte ERSAREQ     :1;                                       /* Erase All Request */
    byte             :1; 
    byte CCIE        :1;                                       /* Command Complete Interrupt Enable */
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00000384;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_FSFD                      _FCNFG.Bits.FSFD
#define FCNFG_FDFD                      _FCNFG.Bits.FDFD
#define FCNFG_WSTAT                     _FCNFG.Bits.WSTAT
#define FCNFG_IGNSF                     _FCNFG.Bits.IGNSF
#define FCNFG_ERSAREQ                   _FCNFG.Bits.ERSAREQ
#define FCNFG_CCIE                      _FCNFG.Bits.CCIE

#define FCNFG_FSFD_MASK                 1U
#define FCNFG_FDFD_MASK                 2U
#define FCNFG_WSTAT_MASK                12U
#define FCNFG_WSTAT_BITNUM              2U
#define FCNFG_IGNSF_MASK                16U
#define FCNFG_ERSAREQ_MASK              32U
#define FCNFG_CCIE_MASK                 128U


/*** FERCNFG - Flash Error Configuration Register; 0x00000385 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIE       :1;                                       /* Single Bit Fault Detect Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERCNFGSTR;
extern volatile FERCNFGSTR _FERCNFG @0x00000385;
#define FERCNFG                         _FERCNFG.Byte
#define FERCNFG_SFDIE                   _FERCNFG.Bits.SFDIE

#define FERCNFG_SFDIE_MASK              1U


/*** FSTAT - Flash Status Register; 0x00000386 ***/
typedef union {
  byte Byte;
  struct {
    byte MGSTAT0     :1;                                       /* Memory Controller Command Completion Status Flag 0 */
    byte MGSTAT1     :1;                                       /* Memory Controller Command Completion Status Flag 1 */
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
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00000386;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_MGSTAT0                   _FSTAT.Bits.MGSTAT0
#define FSTAT_MGSTAT1                   _FSTAT.Bits.MGSTAT1
#define FSTAT_MGBUSY                    _FSTAT.Bits.MGBUSY
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_ACCERR                    _FSTAT.Bits.ACCERR
#define FSTAT_CCIF                      _FSTAT.Bits.CCIF
#define FSTAT_MGSTAT                    _FSTAT.MergedBits.grpMGSTAT

#define FSTAT_MGSTAT0_MASK              1U
#define FSTAT_MGSTAT1_MASK              2U
#define FSTAT_MGBUSY_MASK               8U
#define FSTAT_FPVIOL_MASK               16U
#define FSTAT_ACCERR_MASK               32U
#define FSTAT_CCIF_MASK                 128U
#define FSTAT_MGSTAT_MASK               3U
#define FSTAT_MGSTAT_BITNUM             0U


/*** FERSTAT - Flash Error Status Register; 0x00000387 ***/
typedef union {
  byte Byte;
  struct {
    byte SFDIF       :1;                                       /* Single Bit Fault Detect Interrupt Flag */
    byte DFDF        :1;                                       /* Double Bit Fault Detect Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} FERSTATSTR;
extern volatile FERSTATSTR _FERSTAT @0x00000387;
#define FERSTAT                         _FERSTAT.Byte
#define FERSTAT_SFDIF                   _FERSTAT.Bits.SFDIF
#define FERSTAT_DFDF                    _FERSTAT.Bits.DFDF

#define FERSTAT_SFDIF_MASK              1U
#define FERSTAT_DFDF_MASK               2U


/*** FPROT - P-Flash Protection Register; 0x00000388 ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00000388;
#define FPROT                           _FPROT.Byte
#define FPROT_FPLS0                     _FPROT.Bits.FPLS0
#define FPROT_FPLS1                     _FPROT.Bits.FPLS1
#define FPROT_FPLDIS                    _FPROT.Bits.FPLDIS
#define FPROT_FPHS0                     _FPROT.Bits.FPHS0
#define FPROT_FPHS1                     _FPROT.Bits.FPHS1
#define FPROT_FPHDIS                    _FPROT.Bits.FPHDIS
#define FPROT_RNV6                      _FPROT.Bits.RNV6
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPLS                      _FPROT.MergedBits.grpFPLS
#define FPROT_FPHS                      _FPROT.MergedBits.grpFPHS

#define FPROT_FPLS0_MASK                1U
#define FPROT_FPLS1_MASK                2U
#define FPROT_FPLDIS_MASK               4U
#define FPROT_FPHS0_MASK                8U
#define FPROT_FPHS1_MASK                16U
#define FPROT_FPHDIS_MASK               32U
#define FPROT_RNV6_MASK                 64U
#define FPROT_FPOPEN_MASK               128U
#define FPROT_FPLS_MASK                 3U
#define FPROT_FPLS_BITNUM               0U
#define FPROT_FPHS_MASK                 24U
#define FPROT_FPHS_BITNUM               3U


/*** DFPROT - D-Flash Protection Register; 0x00000389 ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DFPROTSTR;
extern volatile DFPROTSTR _DFPROT @0x00000389;
#define DFPROT                          _DFPROT.Byte
#define DFPROT_DPS0                     _DFPROT.Bits.DPS0
#define DFPROT_DPS1                     _DFPROT.Bits.DPS1
#define DFPROT_DPS2                     _DFPROT.Bits.DPS2
#define DFPROT_DPS3                     _DFPROT.Bits.DPS3
#define DFPROT_DPOPEN                   _DFPROT.Bits.DPOPEN
#define DFPROT_DPS                      _DFPROT.MergedBits.grpDPS

#define DFPROT_DPS0_MASK                1U
#define DFPROT_DPS1_MASK                2U
#define DFPROT_DPS2_MASK                4U
#define DFPROT_DPS3_MASK                8U
#define DFPROT_DPOPEN_MASK              128U
#define DFPROT_DPS_MASK                 15U
#define DFPROT_DPS_BITNUM               0U


/*** FOPT - Flash Option Register; 0x0000038A ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x0000038A;
#define FOPT                            _FOPT.Byte
#define FOPT_NV0                        _FOPT.Bits.NV0
#define FOPT_NV1                        _FOPT.Bits.NV1
#define FOPT_NV2                        _FOPT.Bits.NV2
#define FOPT_NV3                        _FOPT.Bits.NV3
#define FOPT_NV4                        _FOPT.Bits.NV4
#define FOPT_NV5                        _FOPT.Bits.NV5
#define FOPT_NV6                        _FOPT.Bits.NV6
#define FOPT_NV7                        _FOPT.Bits.NV7

#define FOPT_NV0_MASK                   1U
#define FOPT_NV1_MASK                   2U
#define FOPT_NV2_MASK                   4U
#define FOPT_NV3_MASK                   8U
#define FOPT_NV4_MASK                   16U
#define FOPT_NV5_MASK                   32U
#define FOPT_NV6_MASK                   64U
#define FOPT_NV7_MASK                   128U


/*** FCCOB0 - Flash Common Command Object Register; 0x0000038C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB0HI - Flash Common Command Object Register High; 0x0000038C ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB0HISTR;
    #define FCCOB0HI                    _FCCOB0.Overlap_STR.FCCOB0HISTR.Byte
    #define FCCOB0HI_CCOB8              _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB8
    #define FCCOB0HI_CCOB9              _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB9
    #define FCCOB0HI_CCOB10             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB10
    #define FCCOB0HI_CCOB11             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB11
    #define FCCOB0HI_CCOB12             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB12
    #define FCCOB0HI_CCOB13             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB13
    #define FCCOB0HI_CCOB14             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB14
    #define FCCOB0HI_CCOB15             _FCCOB0.Overlap_STR.FCCOB0HISTR.Bits.CCOB15
    
    #define FCCOB0HI_CCOB8_MASK         1U
    #define FCCOB0HI_CCOB9_MASK         2U
    #define FCCOB0HI_CCOB10_MASK        4U
    #define FCCOB0HI_CCOB11_MASK        8U
    #define FCCOB0HI_CCOB12_MASK        16U
    #define FCCOB0HI_CCOB13_MASK        32U
    #define FCCOB0HI_CCOB14_MASK        64U
    #define FCCOB0HI_CCOB15_MASK        128U
    

    /*** FCCOB0LO - Flash Common Command Object Register Low; 0x0000038D ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB0LOSTR;
    #define FCCOB0LO                    _FCCOB0.Overlap_STR.FCCOB0LOSTR.Byte
    #define FCCOB0LO_CCOB0              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB0
    #define FCCOB0LO_CCOB1              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB1
    #define FCCOB0LO_CCOB2              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB2
    #define FCCOB0LO_CCOB3              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB3
    #define FCCOB0LO_CCOB4              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB4
    #define FCCOB0LO_CCOB5              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB5
    #define FCCOB0LO_CCOB6              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB6
    #define FCCOB0LO_CCOB7              _FCCOB0.Overlap_STR.FCCOB0LOSTR.Bits.CCOB7
    
    #define FCCOB0LO_CCOB0_MASK         1U
    #define FCCOB0LO_CCOB1_MASK         2U
    #define FCCOB0LO_CCOB2_MASK         4U
    #define FCCOB0LO_CCOB3_MASK         8U
    #define FCCOB0LO_CCOB4_MASK         16U
    #define FCCOB0LO_CCOB5_MASK         32U
    #define FCCOB0LO_CCOB6_MASK         64U
    #define FCCOB0LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB0STR;
extern volatile FCCOB0STR _FCCOB0 @0x0000038C;
#define FCCOB0                          _FCCOB0.Word
#define FCCOB0_CCOB0                    _FCCOB0.Bits.CCOB0
#define FCCOB0_CCOB1                    _FCCOB0.Bits.CCOB1
#define FCCOB0_CCOB2                    _FCCOB0.Bits.CCOB2
#define FCCOB0_CCOB3                    _FCCOB0.Bits.CCOB3
#define FCCOB0_CCOB4                    _FCCOB0.Bits.CCOB4
#define FCCOB0_CCOB5                    _FCCOB0.Bits.CCOB5
#define FCCOB0_CCOB6                    _FCCOB0.Bits.CCOB6
#define FCCOB0_CCOB7                    _FCCOB0.Bits.CCOB7
#define FCCOB0_CCOB8                    _FCCOB0.Bits.CCOB8
#define FCCOB0_CCOB9                    _FCCOB0.Bits.CCOB9
#define FCCOB0_CCOB10                   _FCCOB0.Bits.CCOB10
#define FCCOB0_CCOB11                   _FCCOB0.Bits.CCOB11
#define FCCOB0_CCOB12                   _FCCOB0.Bits.CCOB12
#define FCCOB0_CCOB13                   _FCCOB0.Bits.CCOB13
#define FCCOB0_CCOB14                   _FCCOB0.Bits.CCOB14
#define FCCOB0_CCOB15                   _FCCOB0.Bits.CCOB15
/* FCCOB_ARR: Access 6 FCCOBx registers in an array */
#define FCCOB_ARR                       ((volatile word *) &FCCOB0)

#define FCCOB0_CCOB0_MASK               1U
#define FCCOB0_CCOB1_MASK               2U
#define FCCOB0_CCOB2_MASK               4U
#define FCCOB0_CCOB3_MASK               8U
#define FCCOB0_CCOB4_MASK               16U
#define FCCOB0_CCOB5_MASK               32U
#define FCCOB0_CCOB6_MASK               64U
#define FCCOB0_CCOB7_MASK               128U
#define FCCOB0_CCOB8_MASK               256U
#define FCCOB0_CCOB9_MASK               512U
#define FCCOB0_CCOB10_MASK              1024U
#define FCCOB0_CCOB11_MASK              2048U
#define FCCOB0_CCOB12_MASK              4096U
#define FCCOB0_CCOB13_MASK              8192U
#define FCCOB0_CCOB14_MASK              16384U
#define FCCOB0_CCOB15_MASK              32768U


/*** FCCOB1 - Flash Common Command Object Register; 0x0000038E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB1HI - Flash Common Command Object Register High; 0x0000038E ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB1HISTR;
    #define FCCOB1HI                    _FCCOB1.Overlap_STR.FCCOB1HISTR.Byte
    #define FCCOB1HI_CCOB8              _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB8
    #define FCCOB1HI_CCOB9              _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB9
    #define FCCOB1HI_CCOB10             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB10
    #define FCCOB1HI_CCOB11             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB11
    #define FCCOB1HI_CCOB12             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB12
    #define FCCOB1HI_CCOB13             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB13
    #define FCCOB1HI_CCOB14             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB14
    #define FCCOB1HI_CCOB15             _FCCOB1.Overlap_STR.FCCOB1HISTR.Bits.CCOB15
    
    #define FCCOB1HI_CCOB8_MASK         1U
    #define FCCOB1HI_CCOB9_MASK         2U
    #define FCCOB1HI_CCOB10_MASK        4U
    #define FCCOB1HI_CCOB11_MASK        8U
    #define FCCOB1HI_CCOB12_MASK        16U
    #define FCCOB1HI_CCOB13_MASK        32U
    #define FCCOB1HI_CCOB14_MASK        64U
    #define FCCOB1HI_CCOB15_MASK        128U
    

    /*** FCCOB1LO - Flash Common Command Object Register Low; 0x0000038F ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB1LOSTR;
    #define FCCOB1LO                    _FCCOB1.Overlap_STR.FCCOB1LOSTR.Byte
    #define FCCOB1LO_CCOB0              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB0
    #define FCCOB1LO_CCOB1              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB1
    #define FCCOB1LO_CCOB2              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB2
    #define FCCOB1LO_CCOB3              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB3
    #define FCCOB1LO_CCOB4              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB4
    #define FCCOB1LO_CCOB5              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB5
    #define FCCOB1LO_CCOB6              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB6
    #define FCCOB1LO_CCOB7              _FCCOB1.Overlap_STR.FCCOB1LOSTR.Bits.CCOB7
    
    #define FCCOB1LO_CCOB0_MASK         1U
    #define FCCOB1LO_CCOB1_MASK         2U
    #define FCCOB1LO_CCOB2_MASK         4U
    #define FCCOB1LO_CCOB3_MASK         8U
    #define FCCOB1LO_CCOB4_MASK         16U
    #define FCCOB1LO_CCOB5_MASK         32U
    #define FCCOB1LO_CCOB6_MASK         64U
    #define FCCOB1LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB1STR;
extern volatile FCCOB1STR _FCCOB1 @0x0000038E;
#define FCCOB1                          _FCCOB1.Word
#define FCCOB1_CCOB0                    _FCCOB1.Bits.CCOB0
#define FCCOB1_CCOB1                    _FCCOB1.Bits.CCOB1
#define FCCOB1_CCOB2                    _FCCOB1.Bits.CCOB2
#define FCCOB1_CCOB3                    _FCCOB1.Bits.CCOB3
#define FCCOB1_CCOB4                    _FCCOB1.Bits.CCOB4
#define FCCOB1_CCOB5                    _FCCOB1.Bits.CCOB5
#define FCCOB1_CCOB6                    _FCCOB1.Bits.CCOB6
#define FCCOB1_CCOB7                    _FCCOB1.Bits.CCOB7
#define FCCOB1_CCOB8                    _FCCOB1.Bits.CCOB8
#define FCCOB1_CCOB9                    _FCCOB1.Bits.CCOB9
#define FCCOB1_CCOB10                   _FCCOB1.Bits.CCOB10
#define FCCOB1_CCOB11                   _FCCOB1.Bits.CCOB11
#define FCCOB1_CCOB12                   _FCCOB1.Bits.CCOB12
#define FCCOB1_CCOB13                   _FCCOB1.Bits.CCOB13
#define FCCOB1_CCOB14                   _FCCOB1.Bits.CCOB14
#define FCCOB1_CCOB15                   _FCCOB1.Bits.CCOB15

#define FCCOB1_CCOB0_MASK               1U
#define FCCOB1_CCOB1_MASK               2U
#define FCCOB1_CCOB2_MASK               4U
#define FCCOB1_CCOB3_MASK               8U
#define FCCOB1_CCOB4_MASK               16U
#define FCCOB1_CCOB5_MASK               32U
#define FCCOB1_CCOB6_MASK               64U
#define FCCOB1_CCOB7_MASK               128U
#define FCCOB1_CCOB8_MASK               256U
#define FCCOB1_CCOB9_MASK               512U
#define FCCOB1_CCOB10_MASK              1024U
#define FCCOB1_CCOB11_MASK              2048U
#define FCCOB1_CCOB12_MASK              4096U
#define FCCOB1_CCOB13_MASK              8192U
#define FCCOB1_CCOB14_MASK              16384U
#define FCCOB1_CCOB15_MASK              32768U


/*** FCCOB2 - Flash Common Command Object Register; 0x00000390 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB2HI - Flash Common Command Object Register High; 0x00000390 ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB2HISTR;
    #define FCCOB2HI                    _FCCOB2.Overlap_STR.FCCOB2HISTR.Byte
    #define FCCOB2HI_CCOB8              _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB8
    #define FCCOB2HI_CCOB9              _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB9
    #define FCCOB2HI_CCOB10             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB10
    #define FCCOB2HI_CCOB11             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB11
    #define FCCOB2HI_CCOB12             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB12
    #define FCCOB2HI_CCOB13             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB13
    #define FCCOB2HI_CCOB14             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB14
    #define FCCOB2HI_CCOB15             _FCCOB2.Overlap_STR.FCCOB2HISTR.Bits.CCOB15
    
    #define FCCOB2HI_CCOB8_MASK         1U
    #define FCCOB2HI_CCOB9_MASK         2U
    #define FCCOB2HI_CCOB10_MASK        4U
    #define FCCOB2HI_CCOB11_MASK        8U
    #define FCCOB2HI_CCOB12_MASK        16U
    #define FCCOB2HI_CCOB13_MASK        32U
    #define FCCOB2HI_CCOB14_MASK        64U
    #define FCCOB2HI_CCOB15_MASK        128U
    

    /*** FCCOB2LO - Flash Common Command Object Register Low; 0x00000391 ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB2LOSTR;
    #define FCCOB2LO                    _FCCOB2.Overlap_STR.FCCOB2LOSTR.Byte
    #define FCCOB2LO_CCOB0              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB0
    #define FCCOB2LO_CCOB1              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB1
    #define FCCOB2LO_CCOB2              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB2
    #define FCCOB2LO_CCOB3              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB3
    #define FCCOB2LO_CCOB4              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB4
    #define FCCOB2LO_CCOB5              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB5
    #define FCCOB2LO_CCOB6              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB6
    #define FCCOB2LO_CCOB7              _FCCOB2.Overlap_STR.FCCOB2LOSTR.Bits.CCOB7
    
    #define FCCOB2LO_CCOB0_MASK         1U
    #define FCCOB2LO_CCOB1_MASK         2U
    #define FCCOB2LO_CCOB2_MASK         4U
    #define FCCOB2LO_CCOB3_MASK         8U
    #define FCCOB2LO_CCOB4_MASK         16U
    #define FCCOB2LO_CCOB5_MASK         32U
    #define FCCOB2LO_CCOB6_MASK         64U
    #define FCCOB2LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB2STR;
extern volatile FCCOB2STR _FCCOB2 @0x00000390;
#define FCCOB2                          _FCCOB2.Word
#define FCCOB2_CCOB0                    _FCCOB2.Bits.CCOB0
#define FCCOB2_CCOB1                    _FCCOB2.Bits.CCOB1
#define FCCOB2_CCOB2                    _FCCOB2.Bits.CCOB2
#define FCCOB2_CCOB3                    _FCCOB2.Bits.CCOB3
#define FCCOB2_CCOB4                    _FCCOB2.Bits.CCOB4
#define FCCOB2_CCOB5                    _FCCOB2.Bits.CCOB5
#define FCCOB2_CCOB6                    _FCCOB2.Bits.CCOB6
#define FCCOB2_CCOB7                    _FCCOB2.Bits.CCOB7
#define FCCOB2_CCOB8                    _FCCOB2.Bits.CCOB8
#define FCCOB2_CCOB9                    _FCCOB2.Bits.CCOB9
#define FCCOB2_CCOB10                   _FCCOB2.Bits.CCOB10
#define FCCOB2_CCOB11                   _FCCOB2.Bits.CCOB11
#define FCCOB2_CCOB12                   _FCCOB2.Bits.CCOB12
#define FCCOB2_CCOB13                   _FCCOB2.Bits.CCOB13
#define FCCOB2_CCOB14                   _FCCOB2.Bits.CCOB14
#define FCCOB2_CCOB15                   _FCCOB2.Bits.CCOB15

#define FCCOB2_CCOB0_MASK               1U
#define FCCOB2_CCOB1_MASK               2U
#define FCCOB2_CCOB2_MASK               4U
#define FCCOB2_CCOB3_MASK               8U
#define FCCOB2_CCOB4_MASK               16U
#define FCCOB2_CCOB5_MASK               32U
#define FCCOB2_CCOB6_MASK               64U
#define FCCOB2_CCOB7_MASK               128U
#define FCCOB2_CCOB8_MASK               256U
#define FCCOB2_CCOB9_MASK               512U
#define FCCOB2_CCOB10_MASK              1024U
#define FCCOB2_CCOB11_MASK              2048U
#define FCCOB2_CCOB12_MASK              4096U
#define FCCOB2_CCOB13_MASK              8192U
#define FCCOB2_CCOB14_MASK              16384U
#define FCCOB2_CCOB15_MASK              32768U


/*** FCCOB3 - Flash Common Command Object Register; 0x00000392 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB3HI - Flash Common Command Object Register High; 0x00000392 ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB3HISTR;
    #define FCCOB3HI                    _FCCOB3.Overlap_STR.FCCOB3HISTR.Byte
    #define FCCOB3HI_CCOB8              _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB8
    #define FCCOB3HI_CCOB9              _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB9
    #define FCCOB3HI_CCOB10             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB10
    #define FCCOB3HI_CCOB11             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB11
    #define FCCOB3HI_CCOB12             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB12
    #define FCCOB3HI_CCOB13             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB13
    #define FCCOB3HI_CCOB14             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB14
    #define FCCOB3HI_CCOB15             _FCCOB3.Overlap_STR.FCCOB3HISTR.Bits.CCOB15
    
    #define FCCOB3HI_CCOB8_MASK         1U
    #define FCCOB3HI_CCOB9_MASK         2U
    #define FCCOB3HI_CCOB10_MASK        4U
    #define FCCOB3HI_CCOB11_MASK        8U
    #define FCCOB3HI_CCOB12_MASK        16U
    #define FCCOB3HI_CCOB13_MASK        32U
    #define FCCOB3HI_CCOB14_MASK        64U
    #define FCCOB3HI_CCOB15_MASK        128U
    

    /*** FCCOB3LO - Flash Common Command Object Register Low; 0x00000393 ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB3LOSTR;
    #define FCCOB3LO                    _FCCOB3.Overlap_STR.FCCOB3LOSTR.Byte
    #define FCCOB3LO_CCOB0              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB0
    #define FCCOB3LO_CCOB1              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB1
    #define FCCOB3LO_CCOB2              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB2
    #define FCCOB3LO_CCOB3              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB3
    #define FCCOB3LO_CCOB4              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB4
    #define FCCOB3LO_CCOB5              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB5
    #define FCCOB3LO_CCOB6              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB6
    #define FCCOB3LO_CCOB7              _FCCOB3.Overlap_STR.FCCOB3LOSTR.Bits.CCOB7
    
    #define FCCOB3LO_CCOB0_MASK         1U
    #define FCCOB3LO_CCOB1_MASK         2U
    #define FCCOB3LO_CCOB2_MASK         4U
    #define FCCOB3LO_CCOB3_MASK         8U
    #define FCCOB3LO_CCOB4_MASK         16U
    #define FCCOB3LO_CCOB5_MASK         32U
    #define FCCOB3LO_CCOB6_MASK         64U
    #define FCCOB3LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB3STR;
extern volatile FCCOB3STR _FCCOB3 @0x00000392;
#define FCCOB3                          _FCCOB3.Word
#define FCCOB3_CCOB0                    _FCCOB3.Bits.CCOB0
#define FCCOB3_CCOB1                    _FCCOB3.Bits.CCOB1
#define FCCOB3_CCOB2                    _FCCOB3.Bits.CCOB2
#define FCCOB3_CCOB3                    _FCCOB3.Bits.CCOB3
#define FCCOB3_CCOB4                    _FCCOB3.Bits.CCOB4
#define FCCOB3_CCOB5                    _FCCOB3.Bits.CCOB5
#define FCCOB3_CCOB6                    _FCCOB3.Bits.CCOB6
#define FCCOB3_CCOB7                    _FCCOB3.Bits.CCOB7
#define FCCOB3_CCOB8                    _FCCOB3.Bits.CCOB8
#define FCCOB3_CCOB9                    _FCCOB3.Bits.CCOB9
#define FCCOB3_CCOB10                   _FCCOB3.Bits.CCOB10
#define FCCOB3_CCOB11                   _FCCOB3.Bits.CCOB11
#define FCCOB3_CCOB12                   _FCCOB3.Bits.CCOB12
#define FCCOB3_CCOB13                   _FCCOB3.Bits.CCOB13
#define FCCOB3_CCOB14                   _FCCOB3.Bits.CCOB14
#define FCCOB3_CCOB15                   _FCCOB3.Bits.CCOB15

#define FCCOB3_CCOB0_MASK               1U
#define FCCOB3_CCOB1_MASK               2U
#define FCCOB3_CCOB2_MASK               4U
#define FCCOB3_CCOB3_MASK               8U
#define FCCOB3_CCOB4_MASK               16U
#define FCCOB3_CCOB5_MASK               32U
#define FCCOB3_CCOB6_MASK               64U
#define FCCOB3_CCOB7_MASK               128U
#define FCCOB3_CCOB8_MASK               256U
#define FCCOB3_CCOB9_MASK               512U
#define FCCOB3_CCOB10_MASK              1024U
#define FCCOB3_CCOB11_MASK              2048U
#define FCCOB3_CCOB12_MASK              4096U
#define FCCOB3_CCOB13_MASK              8192U
#define FCCOB3_CCOB14_MASK              16384U
#define FCCOB3_CCOB15_MASK              32768U


/*** FCCOB4 - Flash Common Command Object Register; 0x00000394 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB4HI - Flash Common Command Object Register High; 0x00000394 ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB4HISTR;
    #define FCCOB4HI                    _FCCOB4.Overlap_STR.FCCOB4HISTR.Byte
    #define FCCOB4HI_CCOB8              _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB8
    #define FCCOB4HI_CCOB9              _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB9
    #define FCCOB4HI_CCOB10             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB10
    #define FCCOB4HI_CCOB11             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB11
    #define FCCOB4HI_CCOB12             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB12
    #define FCCOB4HI_CCOB13             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB13
    #define FCCOB4HI_CCOB14             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB14
    #define FCCOB4HI_CCOB15             _FCCOB4.Overlap_STR.FCCOB4HISTR.Bits.CCOB15
    
    #define FCCOB4HI_CCOB8_MASK         1U
    #define FCCOB4HI_CCOB9_MASK         2U
    #define FCCOB4HI_CCOB10_MASK        4U
    #define FCCOB4HI_CCOB11_MASK        8U
    #define FCCOB4HI_CCOB12_MASK        16U
    #define FCCOB4HI_CCOB13_MASK        32U
    #define FCCOB4HI_CCOB14_MASK        64U
    #define FCCOB4HI_CCOB15_MASK        128U
    

    /*** FCCOB4LO - Flash Common Command Object Register Low; 0x00000395 ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB4LOSTR;
    #define FCCOB4LO                    _FCCOB4.Overlap_STR.FCCOB4LOSTR.Byte
    #define FCCOB4LO_CCOB0              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB0
    #define FCCOB4LO_CCOB1              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB1
    #define FCCOB4LO_CCOB2              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB2
    #define FCCOB4LO_CCOB3              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB3
    #define FCCOB4LO_CCOB4              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB4
    #define FCCOB4LO_CCOB5              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB5
    #define FCCOB4LO_CCOB6              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB6
    #define FCCOB4LO_CCOB7              _FCCOB4.Overlap_STR.FCCOB4LOSTR.Bits.CCOB7
    
    #define FCCOB4LO_CCOB0_MASK         1U
    #define FCCOB4LO_CCOB1_MASK         2U
    #define FCCOB4LO_CCOB2_MASK         4U
    #define FCCOB4LO_CCOB3_MASK         8U
    #define FCCOB4LO_CCOB4_MASK         16U
    #define FCCOB4LO_CCOB5_MASK         32U
    #define FCCOB4LO_CCOB6_MASK         64U
    #define FCCOB4LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB4STR;
extern volatile FCCOB4STR _FCCOB4 @0x00000394;
#define FCCOB4                          _FCCOB4.Word
#define FCCOB4_CCOB0                    _FCCOB4.Bits.CCOB0
#define FCCOB4_CCOB1                    _FCCOB4.Bits.CCOB1
#define FCCOB4_CCOB2                    _FCCOB4.Bits.CCOB2
#define FCCOB4_CCOB3                    _FCCOB4.Bits.CCOB3
#define FCCOB4_CCOB4                    _FCCOB4.Bits.CCOB4
#define FCCOB4_CCOB5                    _FCCOB4.Bits.CCOB5
#define FCCOB4_CCOB6                    _FCCOB4.Bits.CCOB6
#define FCCOB4_CCOB7                    _FCCOB4.Bits.CCOB7
#define FCCOB4_CCOB8                    _FCCOB4.Bits.CCOB8
#define FCCOB4_CCOB9                    _FCCOB4.Bits.CCOB9
#define FCCOB4_CCOB10                   _FCCOB4.Bits.CCOB10
#define FCCOB4_CCOB11                   _FCCOB4.Bits.CCOB11
#define FCCOB4_CCOB12                   _FCCOB4.Bits.CCOB12
#define FCCOB4_CCOB13                   _FCCOB4.Bits.CCOB13
#define FCCOB4_CCOB14                   _FCCOB4.Bits.CCOB14
#define FCCOB4_CCOB15                   _FCCOB4.Bits.CCOB15

#define FCCOB4_CCOB0_MASK               1U
#define FCCOB4_CCOB1_MASK               2U
#define FCCOB4_CCOB2_MASK               4U
#define FCCOB4_CCOB3_MASK               8U
#define FCCOB4_CCOB4_MASK               16U
#define FCCOB4_CCOB5_MASK               32U
#define FCCOB4_CCOB6_MASK               64U
#define FCCOB4_CCOB7_MASK               128U
#define FCCOB4_CCOB8_MASK               256U
#define FCCOB4_CCOB9_MASK               512U
#define FCCOB4_CCOB10_MASK              1024U
#define FCCOB4_CCOB11_MASK              2048U
#define FCCOB4_CCOB12_MASK              4096U
#define FCCOB4_CCOB13_MASK              8192U
#define FCCOB4_CCOB14_MASK              16384U
#define FCCOB4_CCOB15_MASK              32768U


/*** FCCOB5 - Flash Common Command Object Register; 0x00000396 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** FCCOB5HI - Flash Common Command Object Register High; 0x00000396 ***/
    union {
      byte Byte;
      struct {
        byte CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
        byte CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
        byte CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
        byte CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
        byte CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
        byte CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
        byte CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
        byte CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
      } Bits;
    } FCCOB5HISTR;
    #define FCCOB5HI                    _FCCOB5.Overlap_STR.FCCOB5HISTR.Byte
    #define FCCOB5HI_CCOB8              _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB8
    #define FCCOB5HI_CCOB9              _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB9
    #define FCCOB5HI_CCOB10             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB10
    #define FCCOB5HI_CCOB11             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB11
    #define FCCOB5HI_CCOB12             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB12
    #define FCCOB5HI_CCOB13             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB13
    #define FCCOB5HI_CCOB14             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB14
    #define FCCOB5HI_CCOB15             _FCCOB5.Overlap_STR.FCCOB5HISTR.Bits.CCOB15
    
    #define FCCOB5HI_CCOB8_MASK         1U
    #define FCCOB5HI_CCOB9_MASK         2U
    #define FCCOB5HI_CCOB10_MASK        4U
    #define FCCOB5HI_CCOB11_MASK        8U
    #define FCCOB5HI_CCOB12_MASK        16U
    #define FCCOB5HI_CCOB13_MASK        32U
    #define FCCOB5HI_CCOB14_MASK        64U
    #define FCCOB5HI_CCOB15_MASK        128U
    

    /*** FCCOB5LO - Flash Common Command Object Register Low; 0x00000397 ***/
    union {
      byte Byte;
      struct {
        byte CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
        byte CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
        byte CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
        byte CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
        byte CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
        byte CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
        byte CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
        byte CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
      } Bits;
    } FCCOB5LOSTR;
    #define FCCOB5LO                    _FCCOB5.Overlap_STR.FCCOB5LOSTR.Byte
    #define FCCOB5LO_CCOB0              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB0
    #define FCCOB5LO_CCOB1              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB1
    #define FCCOB5LO_CCOB2              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB2
    #define FCCOB5LO_CCOB3              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB3
    #define FCCOB5LO_CCOB4              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB4
    #define FCCOB5LO_CCOB5              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB5
    #define FCCOB5LO_CCOB6              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB6
    #define FCCOB5LO_CCOB7              _FCCOB5.Overlap_STR.FCCOB5LOSTR.Bits.CCOB7
    
    #define FCCOB5LO_CCOB0_MASK         1U
    #define FCCOB5LO_CCOB1_MASK         2U
    #define FCCOB5LO_CCOB2_MASK         4U
    #define FCCOB5LO_CCOB3_MASK         8U
    #define FCCOB5LO_CCOB4_MASK         16U
    #define FCCOB5LO_CCOB5_MASK         32U
    #define FCCOB5LO_CCOB6_MASK         64U
    #define FCCOB5LO_CCOB7_MASK         128U
    
  } Overlap_STR;

  struct {
    word CCOB0       :1;                                       /* Flash Common Command Object Bit 0 */
    word CCOB1       :1;                                       /* Flash Common Command Object Bit 1 */
    word CCOB2       :1;                                       /* Flash Common Command Object Bit 2 */
    word CCOB3       :1;                                       /* Flash Common Command Object Bit 3 */
    word CCOB4       :1;                                       /* Flash Common Command Object Bit 4 */
    word CCOB5       :1;                                       /* Flash Common Command Object Bit 5 */
    word CCOB6       :1;                                       /* Flash Common Command Object Bit 6 */
    word CCOB7       :1;                                       /* Flash Common Command Object Bit 7 */
    word CCOB8       :1;                                       /* Flash Common Command Object Bit 8 */
    word CCOB9       :1;                                       /* Flash Common Command Object Bit 9 */
    word CCOB10      :1;                                       /* Flash Common Command Object Bit 10 */
    word CCOB11      :1;                                       /* Flash Common Command Object Bit 11 */
    word CCOB12      :1;                                       /* Flash Common Command Object Bit 12 */
    word CCOB13      :1;                                       /* Flash Common Command Object Bit 13 */
    word CCOB14      :1;                                       /* Flash Common Command Object Bit 14 */
    word CCOB15      :1;                                       /* Flash Common Command Object Bit 15 */
  } Bits;
} FCCOB5STR;
extern volatile FCCOB5STR _FCCOB5 @0x00000396;
#define FCCOB5                          _FCCOB5.Word
#define FCCOB5_CCOB0                    _FCCOB5.Bits.CCOB0
#define FCCOB5_CCOB1                    _FCCOB5.Bits.CCOB1
#define FCCOB5_CCOB2                    _FCCOB5.Bits.CCOB2
#define FCCOB5_CCOB3                    _FCCOB5.Bits.CCOB3
#define FCCOB5_CCOB4                    _FCCOB5.Bits.CCOB4
#define FCCOB5_CCOB5                    _FCCOB5.Bits.CCOB5
#define FCCOB5_CCOB6                    _FCCOB5.Bits.CCOB6
#define FCCOB5_CCOB7                    _FCCOB5.Bits.CCOB7
#define FCCOB5_CCOB8                    _FCCOB5.Bits.CCOB8
#define FCCOB5_CCOB9                    _FCCOB5.Bits.CCOB9
#define FCCOB5_CCOB10                   _FCCOB5.Bits.CCOB10
#define FCCOB5_CCOB11                   _FCCOB5.Bits.CCOB11
#define FCCOB5_CCOB12                   _FCCOB5.Bits.CCOB12
#define FCCOB5_CCOB13                   _FCCOB5.Bits.CCOB13
#define FCCOB5_CCOB14                   _FCCOB5.Bits.CCOB14
#define FCCOB5_CCOB15                   _FCCOB5.Bits.CCOB15

#define FCCOB5_CCOB0_MASK               1U
#define FCCOB5_CCOB1_MASK               2U
#define FCCOB5_CCOB2_MASK               4U
#define FCCOB5_CCOB3_MASK               8U
#define FCCOB5_CCOB4_MASK               16U
#define FCCOB5_CCOB5_MASK               32U
#define FCCOB5_CCOB6_MASK               64U
#define FCCOB5_CCOB7_MASK               128U
#define FCCOB5_CCOB8_MASK               256U
#define FCCOB5_CCOB9_MASK               512U
#define FCCOB5_CCOB10_MASK              1024U
#define FCCOB5_CCOB11_MASK              2048U
#define FCCOB5_CCOB12_MASK              4096U
#define FCCOB5_CCOB13_MASK              8192U
#define FCCOB5_CCOB14_MASK              16384U
#define FCCOB5_CCOB15_MASK              32768U


/*** ECCSTAT - ECC Status Register; 0x000003C0 ***/
typedef union {
  byte Byte;
  struct {
    byte RDY         :1;                                       /* ECC Ready */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ECCSTATSTR;
extern volatile ECCSTATSTR _ECCSTAT @0x000003C0;
#define ECCSTAT                         _ECCSTAT.Byte
#define ECCSTAT_RDY                     _ECCSTAT.Bits.RDY

#define ECCSTAT_RDY_MASK                1U


/*** ECCIE - ECC Interrupt Enable Register; 0x000003C1 ***/
typedef union {
  byte Byte;
  struct {
    byte SBEEIE      :1;                                       /* Single Bit ECC Error Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ECCIESTR;
extern volatile ECCIESTR _ECCIE @0x000003C1;
#define ECCIE                           _ECCIE.Byte
#define ECCIE_SBEEIE                    _ECCIE.Bits.SBEEIE

#define ECCIE_SBEEIE_MASK               1U


/*** ECCIF - ECC Interrupt Flag Register; 0x000003C2 ***/
typedef union {
  byte Byte;
  struct {
    byte SBEEIF      :1;                                       /* Single bit ECC Error Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ECCIFSTR;
extern volatile ECCIFSTR _ECCIF @0x000003C2;
#define ECCIF                           _ECCIF.Byte
#define ECCIF_SBEEIF                    _ECCIF.Bits.SBEEIF

#define ECCIF_SBEEIF_MASK               1U


/*** ECCDPTRH - ECC Debug Point Register High; 0x000003C7 ***/
typedef union {
  byte Byte;
  struct {
    byte DPTR        :8;                                       /* ECC Debug Pointer */
  } Bits;
} ECCDPTRHSTR;
extern volatile ECCDPTRHSTR _ECCDPTRH @0x000003C7;
#define ECCDPTRH                        _ECCDPTRH.Byte
#define ECCDPTRH_DPTR                   _ECCDPTRH.Bits.DPTR

#define ECCDPTRH_DPTR_MASK              255U
#define ECCDPTRH_DPTR_BITNUM            0U


/*** ECCDPTRM - ECC Debug Point Register Middle; 0x000003C8 ***/
typedef union {
  byte Byte;
  struct {
    byte DPTR        :8;                                       /* ECC Debug Pointer */
  } Bits;
} ECCDPTRMSTR;
extern volatile ECCDPTRMSTR _ECCDPTRM @0x000003C8;
#define ECCDPTRM                        _ECCDPTRM.Byte
#define ECCDPTRM_DPTR                   _ECCDPTRM.Bits.DPTR

#define ECCDPTRM_DPTR_MASK              255U
#define ECCDPTRM_DPTR_BITNUM            0U


/*** ECCDPTRL - ECC Debug Point Register Low; 0x000003C9 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte DPTR        :7;                                       /* ECC Debug Pointer */
  } Bits;
} ECCDPTRLSTR;
extern volatile ECCDPTRLSTR _ECCDPTRL @0x000003C9;
#define ECCDPTRL                        _ECCDPTRL.Byte
#define ECCDPTRL_DPTR                   _ECCDPTRL.Bits.DPTR

#define ECCDPTRL_DPTR_MASK              254U
#define ECCDPTRL_DPTR_BITNUM            1U


/*** ECCDD - ECC Debug Data; 0x000003CC ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ECCDDH - ECC Debug Data High; 0x000003CC ***/
    union {
      byte Byte;
      struct {
        byte DDATA       :8;                                       /* ECC Debug Data */
      } Bits;
    } ECCDDHSTR;
    #define ECCDDH                      _ECCDD.Overlap_STR.ECCDDHSTR.Byte
    #define ECCDDH_DDATA                _ECCDD.Overlap_STR.ECCDDHSTR.Bits.DDATA
    
    #define ECCDDH_DDATA_MASK           255U
    #define ECCDDH_DDATA_BITNUM         0U
    

    /*** ECCDDL - ECC Debug Data Low; 0x000003CD ***/
    union {
      byte Byte;
      struct {
        byte DDATA       :8;                                       /* ECC Debug Data */
      } Bits;
    } ECCDDLSTR;
    #define ECCDDL                      _ECCDD.Overlap_STR.ECCDDLSTR.Byte
    #define ECCDDL_DDATA                _ECCDD.Overlap_STR.ECCDDLSTR.Bits.DDATA
    
    #define ECCDDL_DDATA_MASK           255U
    #define ECCDDL_DDATA_BITNUM         0U
    
  } Overlap_STR;

  struct {
    word DDATA       :16;                                      /* ECC Debug Data */
  } Bits;
} ECCDDSTR;
extern volatile ECCDDSTR _ECCDD @0x000003CC;
#define ECCDD                           _ECCDD.Word
#define ECCDD_DDATA                     _ECCDD.Bits.DDATA

#define ECCDD_DDATA_MASK                65535U
#define ECCDD_DDATA_BITNUM              0U


/*** ECCDE - ECC Debug ECC; 0x000003CE ***/
typedef union {
  byte Byte;
  struct {
    byte DECC        :6;                                       /* ECC Debug ECC */
    byte             :1; 
    byte             :1; 
  } Bits;
} ECCDESTR;
extern volatile ECCDESTR _ECCDE @0x000003CE;
#define ECCDE                           _ECCDE.Byte
#define ECCDE_DECC                      _ECCDE.Bits.DECC

#define ECCDE_DECC_MASK                 63U
#define ECCDE_DECC_BITNUM               0U


/*** ECCDCMD - ECC Debug Comamnd; 0x000003CF ***/
typedef union {
  byte Byte;
  struct {
    byte ECCDR       :1;                                       /* ECC Debug Read Command */
    byte ECCDW       :1;                                       /* ECC Debug Write Command */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ECCDRR      :1;                                       /* ECC Disable Read Repair Function */
  } Bits;
} ECCDCMDSTR;
extern volatile ECCDCMDSTR _ECCDCMD @0x000003CF;
#define ECCDCMD                         _ECCDCMD.Byte
#define ECCDCMD_ECCDR                   _ECCDCMD.Bits.ECCDR
#define ECCDCMD_ECCDW                   _ECCDCMD.Bits.ECCDW
#define ECCDCMD_ECCDRR                  _ECCDCMD.Bits.ECCDRR

#define ECCDCMD_ECCDR_MASK              1U
#define ECCDCMD_ECCDW_MASK              2U
#define ECCDCMD_ECCDRR_MASK             128U


/*** PMFCFG0 - PMF Configure 0 Register; 0x00000500 ***/
typedef union {
  byte Byte;
  struct {
    byte INDEPA      :1;                                       /* Independent or Complimentary Operation for Pair A */
    byte INDEPB      :1;                                       /* Independent or Complimentary Operation for Pair B */
    byte INDEPC      :1;                                       /* Independent or Complimentary Operation for Pair C */
    byte EDGEA       :1;                                       /* Edge-Aligned or Center-Aligned PWM for Pair A */
    byte EDGEB       :1;                                       /* Edge-Aligned or Center-Aligned PWM for Pair B */
    byte EDGEC       :1;                                       /* Edge-Aligned or Center-Aligned PWM for Pair C */
    byte MTG         :1;                                       /* Multiple Timebase Generators */
    byte WP          :1;                                       /* Write Protect */
  } Bits;
  struct {
    byte grpINDEPx :3;
    byte grpEDGEx :3;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFCFG0STR;
extern volatile PMFCFG0STR _PMFCFG0 @0x00000500;
#define PMFCFG0                         _PMFCFG0.Byte
#define PMFCFG0_INDEPA                  _PMFCFG0.Bits.INDEPA
#define PMFCFG0_INDEPB                  _PMFCFG0.Bits.INDEPB
#define PMFCFG0_INDEPC                  _PMFCFG0.Bits.INDEPC
#define PMFCFG0_EDGEA                   _PMFCFG0.Bits.EDGEA
#define PMFCFG0_EDGEB                   _PMFCFG0.Bits.EDGEB
#define PMFCFG0_EDGEC                   _PMFCFG0.Bits.EDGEC
#define PMFCFG0_MTG                     _PMFCFG0.Bits.MTG
#define PMFCFG0_WP                      _PMFCFG0.Bits.WP
/* PMFCFG_ARR: Access 4 PMFCFGx registers in an array */
#define PMFCFG_ARR                      ((volatile byte *) &PMFCFG0)
#define PMFCFG0_INDEPx                  _PMFCFG0.MergedBits.grpINDEPx
#define PMFCFG0_EDGEx                   _PMFCFG0.MergedBits.grpEDGEx

#define PMFCFG0_INDEPA_MASK             1U
#define PMFCFG0_INDEPB_MASK             2U
#define PMFCFG0_INDEPC_MASK             4U
#define PMFCFG0_EDGEA_MASK              8U
#define PMFCFG0_EDGEB_MASK              16U
#define PMFCFG0_EDGEC_MASK              32U
#define PMFCFG0_MTG_MASK                64U
#define PMFCFG0_WP_MASK                 128U
#define PMFCFG0_INDEPx_MASK             7U
#define PMFCFG0_INDEPx_BITNUM           0U
#define PMFCFG0_EDGEx_MASK              56U
#define PMFCFG0_EDGEx_BITNUM            3U


/*** PMFCFG1 - PMF Configure 1 Register; 0x00000501 ***/
typedef union {
  byte Byte;
  struct {
    byte TOPNEGA     :1;                                       /* Pair A Top-Side PWM Polarity */
    byte BOTNEGA     :1;                                       /* Pair A Bottom-Side PWM Polarity */
    byte TOPNEGB     :1;                                       /* Pair B Top-Side PWM Polarity */
    byte BOTNEGB     :1;                                       /* Pair B Bottom-Side PWM Polarity */
    byte TOPNEGC     :1;                                       /* Pair C Top-Side PWM Polarity */
    byte BOTNEGC     :1;                                       /* Pair C Bottom-Side PWM Polarity */
    byte ENCE        :1;                                       /* Enable Commutation Event */
    byte             :1; 
  } Bits;
} PMFCFG1STR;
extern volatile PMFCFG1STR _PMFCFG1 @0x00000501;
#define PMFCFG1                         _PMFCFG1.Byte
#define PMFCFG1_TOPNEGA                 _PMFCFG1.Bits.TOPNEGA
#define PMFCFG1_BOTNEGA                 _PMFCFG1.Bits.BOTNEGA
#define PMFCFG1_TOPNEGB                 _PMFCFG1.Bits.TOPNEGB
#define PMFCFG1_BOTNEGB                 _PMFCFG1.Bits.BOTNEGB
#define PMFCFG1_TOPNEGC                 _PMFCFG1.Bits.TOPNEGC
#define PMFCFG1_BOTNEGC                 _PMFCFG1.Bits.BOTNEGC
#define PMFCFG1_ENCE                    _PMFCFG1.Bits.ENCE

#define PMFCFG1_TOPNEGA_MASK            1U
#define PMFCFG1_BOTNEGA_MASK            2U
#define PMFCFG1_TOPNEGB_MASK            4U
#define PMFCFG1_BOTNEGB_MASK            8U
#define PMFCFG1_TOPNEGC_MASK            16U
#define PMFCFG1_BOTNEGC_MASK            32U
#define PMFCFG1_ENCE_MASK               64U


/*** PMFCFG2 - PMF Configure 2 Register; 0x00000502 ***/
typedef union {
  byte Byte;
  struct {
    byte MSK0        :1;                                       /* Mask PWM0 Bit0 */
    byte MSK1        :1;                                       /* Mask PWM1 Bit1 */
    byte MSK2        :1;                                       /* Mask PWM2 Bit2 */
    byte MSK3        :1;                                       /* Mask PWM3 Bit3 */
    byte MSK4        :1;                                       /* Mask PWM4 Bit4 */
    byte MSK5        :1;                                       /* Mask PWM5 Bit5 */
    byte REV0        :1;                                       /* Reload event Bit0 */
    byte REV1        :1;                                       /* Reload event Bit1 */
  } Bits;
  struct {
    byte grpMSK  :6;
    byte grpREV  :2;
  } MergedBits;
} PMFCFG2STR;
extern volatile PMFCFG2STR _PMFCFG2 @0x00000502;
#define PMFCFG2                         _PMFCFG2.Byte
#define PMFCFG2_MSK0                    _PMFCFG2.Bits.MSK0
#define PMFCFG2_MSK1                    _PMFCFG2.Bits.MSK1
#define PMFCFG2_MSK2                    _PMFCFG2.Bits.MSK2
#define PMFCFG2_MSK3                    _PMFCFG2.Bits.MSK3
#define PMFCFG2_MSK4                    _PMFCFG2.Bits.MSK4
#define PMFCFG2_MSK5                    _PMFCFG2.Bits.MSK5
#define PMFCFG2_REV0                    _PMFCFG2.Bits.REV0
#define PMFCFG2_REV1                    _PMFCFG2.Bits.REV1
#define PMFCFG2_MSK                     _PMFCFG2.MergedBits.grpMSK
#define PMFCFG2_REV                     _PMFCFG2.MergedBits.grpREV

#define PMFCFG2_MSK0_MASK               1U
#define PMFCFG2_MSK1_MASK               2U
#define PMFCFG2_MSK2_MASK               4U
#define PMFCFG2_MSK3_MASK               8U
#define PMFCFG2_MSK4_MASK               16U
#define PMFCFG2_MSK5_MASK               32U
#define PMFCFG2_REV0_MASK               64U
#define PMFCFG2_REV1_MASK               128U
#define PMFCFG2_MSK_MASK                63U
#define PMFCFG2_MSK_BITNUM              0U
#define PMFCFG2_REV_MASK                192U
#define PMFCFG2_REV_BITNUM              6U


/*** PMFCFG3 - PMF Configure 3 Register; 0x00000503 ***/
typedef union {
  byte Byte;
  struct {
    byte PINVA       :1;                                       /* PWM Invert Complement Source Pair A */
    byte PINVB       :1;                                       /* PWM Invert Complement Source Pair B */
    byte PINVC       :1;                                       /* PWM Invert Complement Source Pair C */
    byte VLMODE      :2;                                       /* Value Register Load Mode */
    byte             :1; 
    byte PMFFRZ      :1;                                       /* PMF Stops While in FREEZE Mode */
    byte PMFWAI      :1;                                       /* PMF Stops While in WAIT Mode */
  } Bits;
  struct {
    byte grpPINVx :3;
    byte         :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFCFG3STR;
extern volatile PMFCFG3STR _PMFCFG3 @0x00000503;
#define PMFCFG3                         _PMFCFG3.Byte
#define PMFCFG3_PINVA                   _PMFCFG3.Bits.PINVA
#define PMFCFG3_PINVB                   _PMFCFG3.Bits.PINVB
#define PMFCFG3_PINVC                   _PMFCFG3.Bits.PINVC
#define PMFCFG3_VLMODE                  _PMFCFG3.Bits.VLMODE
#define PMFCFG3_PMFFRZ                  _PMFCFG3.Bits.PMFFRZ
#define PMFCFG3_PMFWAI                  _PMFCFG3.Bits.PMFWAI
#define PMFCFG3_PINVx                   _PMFCFG3.MergedBits.grpPINVx

#define PMFCFG3_PINVA_MASK              1U
#define PMFCFG3_PINVB_MASK              2U
#define PMFCFG3_PINVC_MASK              4U
#define PMFCFG3_VLMODE_MASK             24U
#define PMFCFG3_VLMODE_BITNUM           3U
#define PMFCFG3_PMFFRZ_MASK             64U
#define PMFCFG3_PMFWAI_MASK             128U
#define PMFCFG3_PINVx_MASK              7U
#define PMFCFG3_PINVx_BITNUM            0U


/*** PMFFEN - PMF Fault Enable Register; 0x00000504 ***/
typedef union {
  byte Byte;
  struct {
    byte FEN0        :1;                                       /* Fault 0 Enable */
    byte FEN1        :1;                                       /* Fault 1 Enable */
    byte FEN2        :1;                                       /* Fault 2 Enable */
    byte FEN3        :1;                                       /* Fault 3 Enable */
    byte FEN4        :1;                                       /* Fault 4 Enable */
    byte             :1; 
    byte FEN5        :1;                                       /* Fault 5 Enable */
    byte             :1; 
  } Bits;
  struct {
    byte grpFEN  :5;
    byte         :1;
    byte grpFEN_5 :1;
    byte         :1;
  } MergedBits;
} PMFFENSTR;
extern volatile PMFFENSTR _PMFFEN @0x00000504;
#define PMFFEN                          _PMFFEN.Byte
#define PMFFEN_FEN0                     _PMFFEN.Bits.FEN0
#define PMFFEN_FEN1                     _PMFFEN.Bits.FEN1
#define PMFFEN_FEN2                     _PMFFEN.Bits.FEN2
#define PMFFEN_FEN3                     _PMFFEN.Bits.FEN3
#define PMFFEN_FEN4                     _PMFFEN.Bits.FEN4
#define PMFFEN_FEN5                     _PMFFEN.Bits.FEN5
#define PMFFEN_FEN                      _PMFFEN.MergedBits.grpFEN

#define PMFFEN_FEN0_MASK                1U
#define PMFFEN_FEN1_MASK                2U
#define PMFFEN_FEN2_MASK                4U
#define PMFFEN_FEN3_MASK                8U
#define PMFFEN_FEN4_MASK                16U
#define PMFFEN_FEN5_MASK                64U
#define PMFFEN_FEN_MASK                 31U
#define PMFFEN_FEN_BITNUM               0U


/*** PMFFMOD - PMF Fault Mode Register; 0x00000505 ***/
typedef union {
  byte Byte;
  struct {
    byte FMOD0       :1;                                       /* Fault 0 Pin Clearing Mode */
    byte FMOD1       :1;                                       /* Fault 1 Pin Clearing Mode */
    byte FMOD2       :1;                                       /* Fault 2 Pin Clearing Mode */
    byte FMOD3       :1;                                       /* Fault 3 Pin Clearing Mode */
    byte FMOD4       :1;                                       /* Fault 4 Pin Clearing Mode */
    byte             :1; 
    byte FMOD5       :1;                                       /* Fault 5 Pin Clearing Mode */
    byte             :1; 
  } Bits;
  struct {
    byte grpFMOD :5;
    byte         :1;
    byte grpFMOD_5 :1;
    byte         :1;
  } MergedBits;
} PMFFMODSTR;
extern volatile PMFFMODSTR _PMFFMOD @0x00000505;
#define PMFFMOD                         _PMFFMOD.Byte
#define PMFFMOD_FMOD0                   _PMFFMOD.Bits.FMOD0
#define PMFFMOD_FMOD1                   _PMFFMOD.Bits.FMOD1
#define PMFFMOD_FMOD2                   _PMFFMOD.Bits.FMOD2
#define PMFFMOD_FMOD3                   _PMFFMOD.Bits.FMOD3
#define PMFFMOD_FMOD4                   _PMFFMOD.Bits.FMOD4
#define PMFFMOD_FMOD5                   _PMFFMOD.Bits.FMOD5
#define PMFFMOD_FMOD                    _PMFFMOD.MergedBits.grpFMOD

#define PMFFMOD_FMOD0_MASK              1U
#define PMFFMOD_FMOD1_MASK              2U
#define PMFFMOD_FMOD2_MASK              4U
#define PMFFMOD_FMOD3_MASK              8U
#define PMFFMOD_FMOD4_MASK              16U
#define PMFFMOD_FMOD5_MASK              64U
#define PMFFMOD_FMOD_MASK               31U
#define PMFFMOD_FMOD_BITNUM             0U


/*** PMFFIE - PMF Fault Interrupt Enable Register; 0x00000506 ***/
typedef union {
  byte Byte;
  struct {
    byte FIE0        :1;                                       /* Fault 0 Pin Interrupt Enable */
    byte FIE1        :1;                                       /* Fault 1 Pin Interrupt Enable */
    byte FIE2        :1;                                       /* Fault 2 Pin Interrupt Enable */
    byte FIE3        :1;                                       /* Fault 3 Pin Interrupt Enable */
    byte FIE4        :1;                                       /* Fault 4 Pin Interrupt Enable */
    byte             :1; 
    byte FIE5        :1;                                       /* Fault 5 Pin Interrupt Enable */
    byte             :1; 
  } Bits;
  struct {
    byte grpFIE  :5;
    byte         :1;
    byte grpFIE_5 :1;
    byte         :1;
  } MergedBits;
} PMFFIESTR;
extern volatile PMFFIESTR _PMFFIE @0x00000506;
#define PMFFIE                          _PMFFIE.Byte
#define PMFFIE_FIE0                     _PMFFIE.Bits.FIE0
#define PMFFIE_FIE1                     _PMFFIE.Bits.FIE1
#define PMFFIE_FIE2                     _PMFFIE.Bits.FIE2
#define PMFFIE_FIE3                     _PMFFIE.Bits.FIE3
#define PMFFIE_FIE4                     _PMFFIE.Bits.FIE4
#define PMFFIE_FIE5                     _PMFFIE.Bits.FIE5
#define PMFFIE_FIE                      _PMFFIE.MergedBits.grpFIE

#define PMFFIE_FIE0_MASK                1U
#define PMFFIE_FIE1_MASK                2U
#define PMFFIE_FIE2_MASK                4U
#define PMFFIE_FIE3_MASK                8U
#define PMFFIE_FIE4_MASK                16U
#define PMFFIE_FIE5_MASK                64U
#define PMFFIE_FIE_MASK                 31U
#define PMFFIE_FIE_BITNUM               0U


/*** PMFFIF - PMF Fault Interrupt Flag Register; 0x00000507 ***/
typedef union {
  byte Byte;
  struct {
    byte FIF0        :1;                                       /* Fault 0 Interrupt Flag */
    byte FIF1        :1;                                       /* Fault 1 Interrupt Flag */
    byte FIF2        :1;                                       /* Fault 2 Interrupt Flag */
    byte FIF3        :1;                                       /* Fault 3 Interrupt Flag */
    byte FIF4        :1;                                       /* Fault 4 Interrupt Flag */
    byte             :1; 
    byte FIF5        :1;                                       /* Fault 5 Interrupt Flag */
    byte             :1; 
  } Bits;
  struct {
    byte grpFIF  :5;
    byte         :1;
    byte grpFIF_5 :1;
    byte         :1;
  } MergedBits;
} PMFFIFSTR;
extern volatile PMFFIFSTR _PMFFIF @0x00000507;
#define PMFFIF                          _PMFFIF.Byte
#define PMFFIF_FIF0                     _PMFFIF.Bits.FIF0
#define PMFFIF_FIF1                     _PMFFIF.Bits.FIF1
#define PMFFIF_FIF2                     _PMFFIF.Bits.FIF2
#define PMFFIF_FIF3                     _PMFFIF.Bits.FIF3
#define PMFFIF_FIF4                     _PMFFIF.Bits.FIF4
#define PMFFIF_FIF5                     _PMFFIF.Bits.FIF5
#define PMFFIF_FIF                      _PMFFIF.MergedBits.grpFIF

#define PMFFIF_FIF0_MASK                1U
#define PMFFIF_FIF1_MASK                2U
#define PMFFIF_FIF2_MASK                4U
#define PMFFIF_FIF3_MASK                8U
#define PMFFIF_FIF4_MASK                16U
#define PMFFIF_FIF5_MASK                64U
#define PMFFIF_FIF_MASK                 31U
#define PMFFIF_FIF_BITNUM               0U


/*** PMFQSMP0 - PMF Fault Qualifying Samples Register 0; 0x00000508 ***/
typedef union {
  byte Byte;
  struct {
    byte QSMP4       :2;                                       /* Fault 4 Qualifying Samples */
    byte QSMP5       :2;                                       /* Fault 5 Qualifying Samples */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PMFQSMP0STR;
extern volatile PMFQSMP0STR _PMFQSMP0 @0x00000508;
#define PMFQSMP0                        _PMFQSMP0.Byte
#define PMFQSMP0_QSMP4                  _PMFQSMP0.Bits.QSMP4
#define PMFQSMP0_QSMP5                  _PMFQSMP0.Bits.QSMP5
/* PMFQSMP_ARR: Access 2 PMFQSMPx registers in an array */
#define PMFQSMP_ARR                     ((volatile byte *) &PMFQSMP0)

#define PMFQSMP0_QSMP4_MASK             3U
#define PMFQSMP0_QSMP4_BITNUM           0U
#define PMFQSMP0_QSMP5_MASK             12U
#define PMFQSMP0_QSMP5_BITNUM           2U


/*** PMFQSMP1 - PMF Fault Qualifying Samples Register 1; 0x00000509 ***/
typedef union {
  byte Byte;
  struct {
    byte QSMP0       :2;                                       /* Fault 0 Qualifying Samples */
    byte QSMP1       :2;                                       /* Fault 1 Qualifying Samples */
    byte QSMP2       :2;                                       /* Fault 2 Qualifying Samples */
    byte QSMP3       :2;                                       /* Fault 3 Qualifying Samples */
  } Bits;
} PMFQSMP1STR;
extern volatile PMFQSMP1STR _PMFQSMP1 @0x00000509;
#define PMFQSMP1                        _PMFQSMP1.Byte
#define PMFQSMP1_QSMP0                  _PMFQSMP1.Bits.QSMP0
#define PMFQSMP1_QSMP1                  _PMFQSMP1.Bits.QSMP1
#define PMFQSMP1_QSMP2                  _PMFQSMP1.Bits.QSMP2
#define PMFQSMP1_QSMP3                  _PMFQSMP1.Bits.QSMP3

#define PMFQSMP1_QSMP0_MASK             3U
#define PMFQSMP1_QSMP0_BITNUM           0U
#define PMFQSMP1_QSMP1_MASK             12U
#define PMFQSMP1_QSMP1_BITNUM           2U
#define PMFQSMP1_QSMP2_MASK             48U
#define PMFQSMP1_QSMP2_BITNUM           4U
#define PMFQSMP1_QSMP3_MASK             192U
#define PMFQSMP1_QSMP3_BITNUM           6U


/*** PMFOUTC - PMF Output Control Register; 0x0000050C ***/
typedef union {
  byte Byte;
  struct {
    byte OUTCTL0     :1;                                       /* OUTCTL0 Bits */
    byte OUTCTL1     :1;                                       /* OUTCTL1 Bits */
    byte OUTCTL2     :1;                                       /* OUTCTL2 Bits */
    byte OUTCTL3     :1;                                       /* OUTCTL3 Bits */
    byte OUTCTL4     :1;                                       /* OUTCTL4 Bits */
    byte OUTCTL5     :1;                                       /* OUTCTL5 Bits */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOUTCTL :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFOUTCSTR;
extern volatile PMFOUTCSTR _PMFOUTC @0x0000050C;
#define PMFOUTC                         _PMFOUTC.Byte
#define PMFOUTC_OUTCTL0                 _PMFOUTC.Bits.OUTCTL0
#define PMFOUTC_OUTCTL1                 _PMFOUTC.Bits.OUTCTL1
#define PMFOUTC_OUTCTL2                 _PMFOUTC.Bits.OUTCTL2
#define PMFOUTC_OUTCTL3                 _PMFOUTC.Bits.OUTCTL3
#define PMFOUTC_OUTCTL4                 _PMFOUTC.Bits.OUTCTL4
#define PMFOUTC_OUTCTL5                 _PMFOUTC.Bits.OUTCTL5
#define PMFOUTC_OUTCTL                  _PMFOUTC.MergedBits.grpOUTCTL

#define PMFOUTC_OUTCTL0_MASK            1U
#define PMFOUTC_OUTCTL1_MASK            2U
#define PMFOUTC_OUTCTL2_MASK            4U
#define PMFOUTC_OUTCTL3_MASK            8U
#define PMFOUTC_OUTCTL4_MASK            16U
#define PMFOUTC_OUTCTL5_MASK            32U
#define PMFOUTC_OUTCTL_MASK             63U
#define PMFOUTC_OUTCTL_BITNUM           0U


/*** PMFOUTB - PMF Output Control Bit Register; 0x0000050D ***/
typedef union {
  byte Byte;
  struct {
    byte OUT0        :1;                                       /* OUT Bits */
    byte OUT1        :1;                                       /* OUT Bits */
    byte OUT2        :1;                                       /* OUT Bits */
    byte OUT3        :1;                                       /* OUT Bits */
    byte OUT4        :1;                                       /* OUT Bits */
    byte OUT5        :1;                                       /* OUT Bits */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOUT  :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFOUTBSTR;
extern volatile PMFOUTBSTR _PMFOUTB @0x0000050D;
#define PMFOUTB                         _PMFOUTB.Byte
#define PMFOUTB_OUT0                    _PMFOUTB.Bits.OUT0
#define PMFOUTB_OUT1                    _PMFOUTB.Bits.OUT1
#define PMFOUTB_OUT2                    _PMFOUTB.Bits.OUT2
#define PMFOUTB_OUT3                    _PMFOUTB.Bits.OUT3
#define PMFOUTB_OUT4                    _PMFOUTB.Bits.OUT4
#define PMFOUTB_OUT5                    _PMFOUTB.Bits.OUT5
#define PMFOUTB_OUT                     _PMFOUTB.MergedBits.grpOUT

#define PMFOUTB_OUT0_MASK               1U
#define PMFOUTB_OUT1_MASK               2U
#define PMFOUTB_OUT2_MASK               4U
#define PMFOUTB_OUT3_MASK               8U
#define PMFOUTB_OUT4_MASK               16U
#define PMFOUTB_OUT5_MASK               32U
#define PMFOUTB_OUT_MASK                63U
#define PMFOUTB_OUT_BITNUM              0U


/*** PMFDTMS - PMF Deadtime Sample Register; 0x0000050E ***/
typedef union {
  byte Byte;
  struct {
    byte DT0         :1;                                       /* DT0 Bits */
    byte DT1         :1;                                       /* DT1 Bits */
    byte DT2         :1;                                       /* DT2 Bits */
    byte DT3         :1;                                       /* DT3 Bits */
    byte DT4         :1;                                       /* DT4 Bits */
    byte DT5         :1;                                       /* DT5 Bits */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpDT   :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFDTMSSTR;
extern volatile PMFDTMSSTR _PMFDTMS @0x0000050E;
#define PMFDTMS                         _PMFDTMS.Byte
#define PMFDTMS_DT0                     _PMFDTMS.Bits.DT0
#define PMFDTMS_DT1                     _PMFDTMS.Bits.DT1
#define PMFDTMS_DT2                     _PMFDTMS.Bits.DT2
#define PMFDTMS_DT3                     _PMFDTMS.Bits.DT3
#define PMFDTMS_DT4                     _PMFDTMS.Bits.DT4
#define PMFDTMS_DT5                     _PMFDTMS.Bits.DT5
#define PMFDTMS_DT                      _PMFDTMS.MergedBits.grpDT

#define PMFDTMS_DT0_MASK                1U
#define PMFDTMS_DT1_MASK                2U
#define PMFDTMS_DT2_MASK                4U
#define PMFDTMS_DT3_MASK                8U
#define PMFDTMS_DT4_MASK                16U
#define PMFDTMS_DT5_MASK                32U
#define PMFDTMS_DT_MASK                 63U
#define PMFDTMS_DT_BITNUM               0U


/*** PMFCCTL - PMF Correction Control Register; 0x0000050F ***/
typedef union {
  byte Byte;
  struct {
    byte IPOLA       :1;                                       /* Current Polarity */
    byte IPOLB       :1;                                       /* Current Polarity */
    byte IPOLC       :1;                                       /* Current Polarity */
    byte             :1; 
    byte ISENS       :2;                                       /* Current Status Sensing Method */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIPOLx :3;
    byte         :1;
    byte         :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFCCTLSTR;
extern volatile PMFCCTLSTR _PMFCCTL @0x0000050F;
#define PMFCCTL                         _PMFCCTL.Byte
#define PMFCCTL_IPOLA                   _PMFCCTL.Bits.IPOLA
#define PMFCCTL_IPOLB                   _PMFCCTL.Bits.IPOLB
#define PMFCCTL_IPOLC                   _PMFCCTL.Bits.IPOLC
#define PMFCCTL_ISENS                   _PMFCCTL.Bits.ISENS
#define PMFCCTL_IPOLx                   _PMFCCTL.MergedBits.grpIPOLx

#define PMFCCTL_IPOLA_MASK              1U
#define PMFCCTL_IPOLB_MASK              2U
#define PMFCCTL_IPOLC_MASK              4U
#define PMFCCTL_ISENS_MASK              48U
#define PMFCCTL_ISENS_BITNUM            4U
#define PMFCCTL_IPOLx_MASK              7U
#define PMFCCTL_IPOLx_BITNUM            0U


/*** PMFVAL0 - PMF Value 0 Register; 0x00000510 ***/
typedef union {
  word Word;
} PMFVAL0STR;
extern volatile PMFVAL0STR _PMFVAL0 @0x00000510;
#define PMFVAL0                         _PMFVAL0.Word
/* PMFVAL_ARR: Access 6 PMFVALx registers in an array */
#define PMFVAL_ARR                      ((volatile word *) &PMFVAL0)


/*** PMFVAL1 - PMF Value 1 Register; 0x00000512 ***/
typedef union {
  word Word;
} PMFVAL1STR;
extern volatile PMFVAL1STR _PMFVAL1 @0x00000512;
#define PMFVAL1                         _PMFVAL1.Word


/*** PMFVAL2 - PMF Value 2 Register; 0x00000514 ***/
typedef union {
  word Word;
} PMFVAL2STR;
extern volatile PMFVAL2STR _PMFVAL2 @0x00000514;
#define PMFVAL2                         _PMFVAL2.Word


/*** PMFVAL3 - PMF Value 3 Register; 0x00000516 ***/
typedef union {
  word Word;
} PMFVAL3STR;
extern volatile PMFVAL3STR _PMFVAL3 @0x00000516;
#define PMFVAL3                         _PMFVAL3.Word


/*** PMFVAL4 - PMF Value 4 Register; 0x00000518 ***/
typedef union {
  word Word;
} PMFVAL4STR;
extern volatile PMFVAL4STR _PMFVAL4 @0x00000518;
#define PMFVAL4                         _PMFVAL4.Word


/*** PMFVAL5 - PMF Value 5 Register; 0x0000051A ***/
typedef union {
  word Word;
} PMFVAL5STR;
extern volatile PMFVAL5STR _PMFVAL5 @0x0000051A;
#define PMFVAL5                         _PMFVAL5.Word


/*** PMFROIE - PMF Reload Overrun Interrupt Enable Register; 0x0000051C ***/
typedef union {
  byte Byte;
  struct {
    byte PMFROIEA    :1;                                       /* Reload Overrun Interrupt Enable A */
    byte PMFROIEB    :1;                                       /* Reload Overrun Interrupt Enable B */
    byte PMFROIEC    :1;                                       /* Reload Overrun Interrupt Enable C */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPMFROIEx :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFROIESTR;
extern volatile PMFROIESTR _PMFROIE @0x0000051C;
#define PMFROIE                         _PMFROIE.Byte
#define PMFROIE_PMFROIEA                _PMFROIE.Bits.PMFROIEA
#define PMFROIE_PMFROIEB                _PMFROIE.Bits.PMFROIEB
#define PMFROIE_PMFROIEC                _PMFROIE.Bits.PMFROIEC
#define PMFROIE_PMFROIEx                _PMFROIE.MergedBits.grpPMFROIEx

#define PMFROIE_PMFROIEA_MASK           1U
#define PMFROIE_PMFROIEB_MASK           2U
#define PMFROIE_PMFROIEC_MASK           4U
#define PMFROIE_PMFROIEx_MASK           7U
#define PMFROIE_PMFROIEx_BITNUM         0U


/*** PMFROIF - PMF Interrupt Flag Register; 0x0000051D ***/
typedef union {
  byte Byte;
  struct {
    byte PMFROIFA    :1;                                       /* Reload Overrun Interrupt Flag A */
    byte PMFROIFB    :1;                                       /* Reload Overrun Interrupt Flag B */
    byte PMFROIFC    :1;                                       /* Reload Overrun Interrupt Flag C */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPMFROIFx :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFROIFSTR;
extern volatile PMFROIFSTR _PMFROIF @0x0000051D;
#define PMFROIF                         _PMFROIF.Byte
#define PMFROIF_PMFROIFA                _PMFROIF.Bits.PMFROIFA
#define PMFROIF_PMFROIFB                _PMFROIF.Bits.PMFROIFB
#define PMFROIF_PMFROIFC                _PMFROIF.Bits.PMFROIFC
#define PMFROIF_PMFROIFx                _PMFROIF.MergedBits.grpPMFROIFx

#define PMFROIF_PMFROIFA_MASK           1U
#define PMFROIF_PMFROIFB_MASK           2U
#define PMFROIF_PMFROIFC_MASK           4U
#define PMFROIF_PMFROIFx_MASK           7U
#define PMFROIF_PMFROIFx_BITNUM         0U


/*** PMFICCTL - PMF Internal Correction Control Register; 0x0000051E ***/
typedef union {
  byte Byte;
  struct {
    byte ICCA        :1;                                       /* Internal Correction Control 0 */
    byte ICCB        :1;                                       /* Internal Correction Control 1 */
    byte ICCC        :1;                                       /* Internal Correction Control 2 */
    byte PECA        :1;                                       /* Pulse Edge Control 0 */
    byte PECB        :1;                                       /* Pulse Edge Control 1 */
    byte PECC        :1;                                       /* Pulse Edge Control 2 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpICCx :3;
    byte grpPECx :3;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFICCTLSTR;
extern volatile PMFICCTLSTR _PMFICCTL @0x0000051E;
#define PMFICCTL                        _PMFICCTL.Byte
#define PMFICCTL_ICCA                   _PMFICCTL.Bits.ICCA
#define PMFICCTL_ICCB                   _PMFICCTL.Bits.ICCB
#define PMFICCTL_ICCC                   _PMFICCTL.Bits.ICCC
#define PMFICCTL_PECA                   _PMFICCTL.Bits.PECA
#define PMFICCTL_PECB                   _PMFICCTL.Bits.PECB
#define PMFICCTL_PECC                   _PMFICCTL.Bits.PECC
#define PMFICCTL_ICCx                   _PMFICCTL.MergedBits.grpICCx
#define PMFICCTL_PECx                   _PMFICCTL.MergedBits.grpPECx

#define PMFICCTL_ICCA_MASK              1U
#define PMFICCTL_ICCB_MASK              2U
#define PMFICCTL_ICCC_MASK              4U
#define PMFICCTL_PECA_MASK              8U
#define PMFICCTL_PECB_MASK              16U
#define PMFICCTL_PECC_MASK              32U
#define PMFICCTL_ICCx_MASK              7U
#define PMFICCTL_ICCx_BITNUM            0U
#define PMFICCTL_PECx_MASK              56U
#define PMFICCTL_PECx_BITNUM            3U


/*** PMFCINV - PMF Compare Invert Register; 0x0000051F ***/
typedef union {
  byte Byte;
  struct {
    byte CINV0       :1;                                       /* PWM Compare Invert 0 */
    byte CINV1       :1;                                       /* PWM Compare Invert 1 */
    byte CINV2       :1;                                       /* PWM Compare Invert 2 */
    byte CINV3       :1;                                       /* PWM Compare Invert 3 */
    byte CINV4       :1;                                       /* PWM Compare Invert 4 */
    byte CINV5       :1;                                       /* PWM Compare Invert 5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCINV :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFCINVSTR;
extern volatile PMFCINVSTR _PMFCINV @0x0000051F;
#define PMFCINV                         _PMFCINV.Byte
#define PMFCINV_CINV0                   _PMFCINV.Bits.CINV0
#define PMFCINV_CINV1                   _PMFCINV.Bits.CINV1
#define PMFCINV_CINV2                   _PMFCINV.Bits.CINV2
#define PMFCINV_CINV3                   _PMFCINV.Bits.CINV3
#define PMFCINV_CINV4                   _PMFCINV.Bits.CINV4
#define PMFCINV_CINV5                   _PMFCINV.Bits.CINV5
#define PMFCINV_CINV                    _PMFCINV.MergedBits.grpCINV

#define PMFCINV_CINV0_MASK              1U
#define PMFCINV_CINV1_MASK              2U
#define PMFCINV_CINV2_MASK              4U
#define PMFCINV_CINV3_MASK              8U
#define PMFCINV_CINV4_MASK              16U
#define PMFCINV_CINV5_MASK              32U
#define PMFCINV_CINV_MASK               63U
#define PMFCINV_CINV_BITNUM             0U


/*** PMFENCA - PMF Enable Control A Register; 0x00000520 ***/
typedef union {
  byte Byte;
  struct {
    byte PWMRIEA     :1;                                       /* PWM Reload Interrupt Enable A */
    byte LDOKA       :1;                                       /* Load Okay A */
    byte RSTRTA      :1;                                       /* Restart Generator A */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte GLDOKA      :1;                                       /* Global Load Okay A */
    byte PWMENA      :1;                                       /* PWM Generator A Enable */
  } Bits;
} PMFENCASTR;
extern volatile PMFENCASTR _PMFENCA @0x00000520;
#define PMFENCA                         _PMFENCA.Byte
#define PMFENCA_PWMRIEA                 _PMFENCA.Bits.PWMRIEA
#define PMFENCA_LDOKA                   _PMFENCA.Bits.LDOKA
#define PMFENCA_RSTRTA                  _PMFENCA.Bits.RSTRTA
#define PMFENCA_GLDOKA                  _PMFENCA.Bits.GLDOKA
#define PMFENCA_PWMENA                  _PMFENCA.Bits.PWMENA

#define PMFENCA_PWMRIEA_MASK            1U
#define PMFENCA_LDOKA_MASK              2U
#define PMFENCA_RSTRTA_MASK             4U
#define PMFENCA_GLDOKA_MASK             64U
#define PMFENCA_PWMENA_MASK             128U


/*** PMFFQCA - PMF Frequency Control A Register; 0x00000521 ***/
typedef union {
  byte Byte;
  struct {
    byte PWMRFA      :1;                                       /* PWM Reload Flag A */
    byte PRSCA       :2;                                       /* Prescaler A */
    byte HALFA       :1;                                       /* Half Cycle Reload A */
    byte LDFQA       :4;                                       /* Load Frequency A */
  } Bits;
} PMFFQCASTR;
extern volatile PMFFQCASTR _PMFFQCA @0x00000521;
#define PMFFQCA                         _PMFFQCA.Byte
#define PMFFQCA_PWMRFA                  _PMFFQCA.Bits.PWMRFA
#define PMFFQCA_PRSCA                   _PMFFQCA.Bits.PRSCA
#define PMFFQCA_HALFA                   _PMFFQCA.Bits.HALFA
#define PMFFQCA_LDFQA                   _PMFFQCA.Bits.LDFQA

#define PMFFQCA_PWMRFA_MASK             1U
#define PMFFQCA_PRSCA_MASK              6U
#define PMFFQCA_PRSCA_BITNUM            1U
#define PMFFQCA_HALFA_MASK              8U
#define PMFFQCA_LDFQA_MASK              240U
#define PMFFQCA_LDFQA_BITNUM            4U


/*** PMFCNTA - PMF counter A Register; 0x00000522 ***/
typedef union {
  word Word;
  struct {
    word PMFCNTA_grp :15;                                      /* PMF counter */ /*Warning: group name is duplicated with register name*/
    word             :1; 
  } Bits;
} PMFCNTASTR;
extern volatile PMFCNTASTR _PMFCNTA @0x00000522;
#define PMFCNTA                         _PMFCNTA.Word
#define PMFCNTA_PMFCNTA                 _PMFCNTA.Bits.PMFCNTA_grp

#define PMFCNTA_PMFCNTA_MASK            32767U
#define PMFCNTA_PMFCNTA_BITNUM          0U


/*** PMFMODA - PMF modulo counter A Register; 0x00000524 ***/
typedef union {
  word Word;
  struct {
    word PMFMODA_grp :15;                                      /* PMF modulo counter */ /*Warning: group name is duplicated with register name*/
    word             :1; 
  } Bits;
} PMFMODASTR;
extern volatile PMFMODASTR _PMFMODA @0x00000524;
#define PMFMODA                         _PMFMODA.Word
#define PMFMODA_PMFMODA                 _PMFMODA.Bits.PMFMODA_grp

#define PMFMODA_PMFMODA_MASK            32767U
#define PMFMODA_PMFMODA_BITNUM          0U


/*** PMFDTMA - PMF deadtime A Register; 0x00000526 ***/
typedef union {
  word Word;
  struct {
    word PMFDTMA_grp :12;                                      /* PMF Value 0 */ /*Warning: group name is duplicated with register name*/
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} PMFDTMASTR;
extern volatile PMFDTMASTR _PMFDTMA @0x00000526;
#define PMFDTMA                         _PMFDTMA.Word
#define PMFDTMA_PMFDTMA                 _PMFDTMA.Bits.PMFDTMA_grp

#define PMFDTMA_PMFDTMA_MASK            4095U
#define PMFDTMA_PMFDTMA_BITNUM          0U


/*** PMFENCB - PMF Enable Control B Register; 0x00000528 ***/
typedef union {
  byte Byte;
  struct {
    byte PWMRIEB     :1;                                       /* PWM Reload Interrupt Enable B */
    byte LDOKB       :1;                                       /* Load Okay B */
    byte RSTRTB      :1;                                       /* Restart Generator B */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte GLDOKB      :1;                                       /* Global Load Okay B */
    byte PWMENB      :1;                                       /* PWM Generator B Enable */
  } Bits;
} PMFENCBSTR;
extern volatile PMFENCBSTR _PMFENCB @0x00000528;
#define PMFENCB                         _PMFENCB.Byte
#define PMFENCB_PWMRIEB                 _PMFENCB.Bits.PWMRIEB
#define PMFENCB_LDOKB                   _PMFENCB.Bits.LDOKB
#define PMFENCB_RSTRTB                  _PMFENCB.Bits.RSTRTB
#define PMFENCB_GLDOKB                  _PMFENCB.Bits.GLDOKB
#define PMFENCB_PWMENB                  _PMFENCB.Bits.PWMENB

#define PMFENCB_PWMRIEB_MASK            1U
#define PMFENCB_LDOKB_MASK              2U
#define PMFENCB_RSTRTB_MASK             4U
#define PMFENCB_GLDOKB_MASK             64U
#define PMFENCB_PWMENB_MASK             128U


/*** PMFFQCB - PMF Frequency Control B Register; 0x00000529 ***/
typedef union {
  byte Byte;
  struct {
    byte PWMRFB      :1;                                       /* PWM Reload Interrupt Flag B */
    byte PRSCB       :2;                                       /* Prescaler B */
    byte HALFB       :1;                                       /* Half Cycle Reload B */
    byte LDFQB       :4;                                       /* Load Frequency B */
  } Bits;
} PMFFQCBSTR;
extern volatile PMFFQCBSTR _PMFFQCB @0x00000529;
#define PMFFQCB                         _PMFFQCB.Byte
#define PMFFQCB_PWMRFB                  _PMFFQCB.Bits.PWMRFB
#define PMFFQCB_PRSCB                   _PMFFQCB.Bits.PRSCB
#define PMFFQCB_HALFB                   _PMFFQCB.Bits.HALFB
#define PMFFQCB_LDFQB                   _PMFFQCB.Bits.LDFQB

#define PMFFQCB_PWMRFB_MASK             1U
#define PMFFQCB_PRSCB_MASK              6U
#define PMFFQCB_PRSCB_BITNUM            1U
#define PMFFQCB_HALFB_MASK              8U
#define PMFFQCB_LDFQB_MASK              240U
#define PMFFQCB_LDFQB_BITNUM            4U


/*** PMFCNTB - PMF counter B Register; 0x0000052A ***/
typedef union {
  word Word;
  struct {
    word PMFCNTB_grp :15;                                      /* PMF counter */ /*Warning: group name is duplicated with register name*/
    word             :1; 
  } Bits;
} PMFCNTBSTR;
extern volatile PMFCNTBSTR _PMFCNTB @0x0000052A;
#define PMFCNTB                         _PMFCNTB.Word
#define PMFCNTB_PMFCNTB                 _PMFCNTB.Bits.PMFCNTB_grp

#define PMFCNTB_PMFCNTB_MASK            32767U
#define PMFCNTB_PMFCNTB_BITNUM          0U


/*** PMFMODB - PMF modulo counter B Register; 0x0000052C ***/
typedef union {
  word Word;
  struct {
    word PMFMODB_grp :15;                                      /* PMF modulo counter */ /*Warning: group name is duplicated with register name*/
    word             :1; 
  } Bits;
} PMFMODBSTR;
extern volatile PMFMODBSTR _PMFMODB @0x0000052C;
#define PMFMODB                         _PMFMODB.Word
#define PMFMODB_PMFMODB                 _PMFMODB.Bits.PMFMODB_grp

#define PMFMODB_PMFMODB_MASK            32767U
#define PMFMODB_PMFMODB_BITNUM          0U


/*** PMFDTMB - PMF deadtime B Register; 0x0000052E ***/
typedef union {
  word Word;
  struct {
    word PMFDTMB_grp :12;                                      /* PMF Value 0 */ /*Warning: group name is duplicated with register name*/
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} PMFDTMBSTR;
extern volatile PMFDTMBSTR _PMFDTMB @0x0000052E;
#define PMFDTMB                         _PMFDTMB.Word
#define PMFDTMB_PMFDTMB                 _PMFDTMB.Bits.PMFDTMB_grp

#define PMFDTMB_PMFDTMB_MASK            4095U
#define PMFDTMB_PMFDTMB_BITNUM          0U


/*** PMFENCC - PMF Enable Control C Register; 0x00000530 ***/
typedef union {
  byte Byte;
  struct {
    byte PWMRIEC     :1;                                       /* PWM Reload Interrupt Enable C */
    byte LDOKC       :1;                                       /* Load Okay C */
    byte RSTRTC      :1;                                       /* Restart Generator C */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte GLDOKC      :1;                                       /* Global Load Okay C */
    byte PWMENC      :1;                                       /* PWM Generator C Enable */
  } Bits;
} PMFENCCSTR;
extern volatile PMFENCCSTR _PMFENCC @0x00000530;
#define PMFENCC                         _PMFENCC.Byte
#define PMFENCC_PWMRIEC                 _PMFENCC.Bits.PWMRIEC
#define PMFENCC_LDOKC                   _PMFENCC.Bits.LDOKC
#define PMFENCC_RSTRTC                  _PMFENCC.Bits.RSTRTC
#define PMFENCC_GLDOKC                  _PMFENCC.Bits.GLDOKC
#define PMFENCC_PWMENC                  _PMFENCC.Bits.PWMENC

#define PMFENCC_PWMRIEC_MASK            1U
#define PMFENCC_LDOKC_MASK              2U
#define PMFENCC_RSTRTC_MASK             4U
#define PMFENCC_GLDOKC_MASK             64U
#define PMFENCC_PWMENC_MASK             128U


/*** PMFFQCC - PMF Frequency Control C Register; 0x00000531 ***/
typedef union {
  byte Byte;
  struct {
    byte PWMRFC      :1;                                       /* PWM Reload Interrupt Flag C */
    byte PRSCC       :2;                                       /* Prescaler C */
    byte HALFC       :1;                                       /* Half Cycle Reload B */
    byte LDFQC       :4;                                       /* Load Frequency C */
  } Bits;
} PMFFQCCSTR;
extern volatile PMFFQCCSTR _PMFFQCC @0x00000531;
#define PMFFQCC                         _PMFFQCC.Byte
#define PMFFQCC_PWMRFC                  _PMFFQCC.Bits.PWMRFC
#define PMFFQCC_PRSCC                   _PMFFQCC.Bits.PRSCC
#define PMFFQCC_HALFC                   _PMFFQCC.Bits.HALFC
#define PMFFQCC_LDFQC                   _PMFFQCC.Bits.LDFQC

#define PMFFQCC_PWMRFC_MASK             1U
#define PMFFQCC_PRSCC_MASK              6U
#define PMFFQCC_PRSCC_BITNUM            1U
#define PMFFQCC_HALFC_MASK              8U
#define PMFFQCC_LDFQC_MASK              240U
#define PMFFQCC_LDFQC_BITNUM            4U


/*** PMFCNTC - PMF counter C Register; 0x00000532 ***/
typedef union {
  word Word;
  struct {
    word PMFCNTC_grp :15;                                      /* PMF counter */ /*Warning: group name is duplicated with register name*/
    word             :1; 
  } Bits;
} PMFCNTCSTR;
extern volatile PMFCNTCSTR _PMFCNTC @0x00000532;
#define PMFCNTC                         _PMFCNTC.Word
#define PMFCNTC_PMFCNTC                 _PMFCNTC.Bits.PMFCNTC_grp

#define PMFCNTC_PMFCNTC_MASK            32767U
#define PMFCNTC_PMFCNTC_BITNUM          0U


/*** PMFMODC - PMF modulo counter C Register; 0x00000534 ***/
typedef union {
  word Word;
  struct {
    word PMFMODC_grp :15;                                      /* PMF modulo counter */ /*Warning: group name is duplicated with register name*/
    word             :1; 
  } Bits;
} PMFMODCSTR;
extern volatile PMFMODCSTR _PMFMODC @0x00000534;
#define PMFMODC                         _PMFMODC.Word
#define PMFMODC_PMFMODC                 _PMFMODC.Bits.PMFMODC_grp

#define PMFMODC_PMFMODC_MASK            32767U
#define PMFMODC_PMFMODC_BITNUM          0U


/*** PMFDTMC - PMF deadtime C Register; 0x00000536 ***/
typedef union {
  word Word;
  struct {
    word PMFDTMC_grp :12;                                      /* PMF Value 0 */ /*Warning: group name is duplicated with register name*/
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
  } Bits;
} PMFDTMCSTR;
extern volatile PMFDTMCSTR _PMFDTMC @0x00000536;
#define PMFDTMC                         _PMFDTMC.Word
#define PMFDTMC_PMFDTMC                 _PMFDTMC.Bits.PMFDTMC_grp

#define PMFDTMC_PMFDTMC_MASK            4095U
#define PMFDTMC_PMFDTMC_BITNUM          0U


/*** PMFDMP0 - PMF Disable Mapping Register 0; 0x00000538 ***/
typedef union {
  byte Byte;
  struct {
    byte DMP00       :1;                                       /* PWM Disable Mapping Channel 0 FAULT0 */
    byte DMP01       :1;                                       /* PWM Disable Mapping Channel 0 FAULT1 */
    byte DMP02       :1;                                       /* PWM Disable Mapping Channel 0 FAULT2 */
    byte DMP03       :1;                                       /* PWM Disable Mapping Channel 0 FAULT3 */
    byte DMP04       :2;                                       /* PWM Disable Mapping Channel 0 FAULT4 */
    byte DMP05       :2;                                       /* PWM Disable Mapping Channel 0 FAULT5 */
  } Bits;
  struct {
    byte grpDMP0 :4;
    byte         :2;
    byte         :2;
  } MergedBits;
} PMFDMP0STR;
extern volatile PMFDMP0STR _PMFDMP0 @0x00000538;
#define PMFDMP0                         _PMFDMP0.Byte
#define PMFDMP0_DMP00                   _PMFDMP0.Bits.DMP00
#define PMFDMP0_DMP01                   _PMFDMP0.Bits.DMP01
#define PMFDMP0_DMP02                   _PMFDMP0.Bits.DMP02
#define PMFDMP0_DMP03                   _PMFDMP0.Bits.DMP03
#define PMFDMP0_DMP04                   _PMFDMP0.Bits.DMP04
#define PMFDMP0_DMP05                   _PMFDMP0.Bits.DMP05
/* PMFDMP_ARR: Access 6 PMFDMPx registers in an array */
#define PMFDMP_ARR                      ((volatile byte *) &PMFDMP0)
#define PMFDMP0_DMP0                    _PMFDMP0.MergedBits.grpDMP0

#define PMFDMP0_DMP00_MASK              1U
#define PMFDMP0_DMP01_MASK              2U
#define PMFDMP0_DMP02_MASK              4U
#define PMFDMP0_DMP03_MASK              8U
#define PMFDMP0_DMP04_MASK              48U
#define PMFDMP0_DMP04_BITNUM            4U
#define PMFDMP0_DMP05_MASK              192U
#define PMFDMP0_DMP05_BITNUM            6U
#define PMFDMP0_DMP0_MASK               15U
#define PMFDMP0_DMP0_BITNUM             0U


/*** PMFDMP1 - PMF Disable Mapping Register 1; 0x00000539 ***/
typedef union {
  byte Byte;
  struct {
    byte DMP10       :1;                                       /* PWM Disable Mapping Channel 1 FAULT0 */
    byte DMP11       :1;                                       /* PWM Disable Mapping Channel 1 FAULT1 */
    byte DMP12       :1;                                       /* PWM Disable Mapping Channel 1 FAULT2 */
    byte DMP13       :1;                                       /* PWM Disable Mapping Channel 1 FAULT3 */
    byte DMP14       :2;                                       /* PWM Disable Mapping Channel 1 FAULT4 */
    byte DMP15       :2;                                       /* PWM Disable Mapping Channel 1 FAULT5 */
  } Bits;
  struct {
    byte grpDMP_10 :4;
    byte         :2;
    byte         :2;
  } MergedBits;
} PMFDMP1STR;
extern volatile PMFDMP1STR _PMFDMP1 @0x00000539;
#define PMFDMP1                         _PMFDMP1.Byte
#define PMFDMP1_DMP10                   _PMFDMP1.Bits.DMP10
#define PMFDMP1_DMP11                   _PMFDMP1.Bits.DMP11
#define PMFDMP1_DMP12                   _PMFDMP1.Bits.DMP12
#define PMFDMP1_DMP13                   _PMFDMP1.Bits.DMP13
#define PMFDMP1_DMP14                   _PMFDMP1.Bits.DMP14
#define PMFDMP1_DMP15                   _PMFDMP1.Bits.DMP15
#define PMFDMP1_DMP_10                  _PMFDMP1.MergedBits.grpDMP_10
#define PMFDMP1_DMP                     PMFDMP1_DMP_10

#define PMFDMP1_DMP10_MASK              1U
#define PMFDMP1_DMP11_MASK              2U
#define PMFDMP1_DMP12_MASK              4U
#define PMFDMP1_DMP13_MASK              8U
#define PMFDMP1_DMP14_MASK              48U
#define PMFDMP1_DMP14_BITNUM            4U
#define PMFDMP1_DMP15_MASK              192U
#define PMFDMP1_DMP15_BITNUM            6U
#define PMFDMP1_DMP_10_MASK             15U
#define PMFDMP1_DMP_10_BITNUM           0U


/*** PMFDMP2 - PMF Disable Mapping Register 2; 0x0000053A ***/
typedef union {
  byte Byte;
  struct {
    byte DMP20       :1;                                       /* PWM Disable Mapping Channel 2 FAULT0 */
    byte DMP21       :1;                                       /* PWM Disable Mapping Channel 2 FAULT1 */
    byte DMP22       :1;                                       /* PWM Disable Mapping Channel 2 FAULT2 */
    byte DMP23       :1;                                       /* PWM Disable Mapping Channel 2 FAULT3 */
    byte DMP24       :2;                                       /* PWM Disable Mapping Channel 2 FAULT4 */
    byte DMP25       :2;                                       /* PWM Disable Mapping Channel 2 FAULT5 */
  } Bits;
  struct {
    byte grpDMP_20 :4;
    byte         :2;
    byte         :2;
  } MergedBits;
} PMFDMP2STR;
extern volatile PMFDMP2STR _PMFDMP2 @0x0000053A;
#define PMFDMP2                         _PMFDMP2.Byte
#define PMFDMP2_DMP20                   _PMFDMP2.Bits.DMP20
#define PMFDMP2_DMP21                   _PMFDMP2.Bits.DMP21
#define PMFDMP2_DMP22                   _PMFDMP2.Bits.DMP22
#define PMFDMP2_DMP23                   _PMFDMP2.Bits.DMP23
#define PMFDMP2_DMP24                   _PMFDMP2.Bits.DMP24
#define PMFDMP2_DMP25                   _PMFDMP2.Bits.DMP25
#define PMFDMP2_DMP_20                  _PMFDMP2.MergedBits.grpDMP_20
#define PMFDMP2_DMP                     PMFDMP2_DMP_20

#define PMFDMP2_DMP20_MASK              1U
#define PMFDMP2_DMP21_MASK              2U
#define PMFDMP2_DMP22_MASK              4U
#define PMFDMP2_DMP23_MASK              8U
#define PMFDMP2_DMP24_MASK              48U
#define PMFDMP2_DMP24_BITNUM            4U
#define PMFDMP2_DMP25_MASK              192U
#define PMFDMP2_DMP25_BITNUM            6U
#define PMFDMP2_DMP_20_MASK             15U
#define PMFDMP2_DMP_20_BITNUM           0U


/*** PMFDMP3 - PMF Disable Mapping Register 3; 0x0000053B ***/
typedef union {
  byte Byte;
  struct {
    byte DMP30       :1;                                       /* PWM Disable Mapping Channel 3 FAULT0 */
    byte DMP31       :1;                                       /* PWM Disable Mapping Channel 3 FAULT1 */
    byte DMP32       :1;                                       /* PWM Disable Mapping Channel 3 FAULT2 */
    byte DMP33       :1;                                       /* PWM Disable Mapping Channel 3 FAULT3 */
    byte DMP34       :2;                                       /* PWM Disable Mapping Channel 3 FAULT4 */
    byte DMP35       :2;                                       /* PWM Disable Mapping Channel 3 FAULT5 */
  } Bits;
  struct {
    byte grpDMP_30 :4;
    byte         :2;
    byte         :2;
  } MergedBits;
} PMFDMP3STR;
extern volatile PMFDMP3STR _PMFDMP3 @0x0000053B;
#define PMFDMP3                         _PMFDMP3.Byte
#define PMFDMP3_DMP30                   _PMFDMP3.Bits.DMP30
#define PMFDMP3_DMP31                   _PMFDMP3.Bits.DMP31
#define PMFDMP3_DMP32                   _PMFDMP3.Bits.DMP32
#define PMFDMP3_DMP33                   _PMFDMP3.Bits.DMP33
#define PMFDMP3_DMP34                   _PMFDMP3.Bits.DMP34
#define PMFDMP3_DMP35                   _PMFDMP3.Bits.DMP35
#define PMFDMP3_DMP_30                  _PMFDMP3.MergedBits.grpDMP_30
#define PMFDMP3_DMP                     PMFDMP3_DMP_30

#define PMFDMP3_DMP30_MASK              1U
#define PMFDMP3_DMP31_MASK              2U
#define PMFDMP3_DMP32_MASK              4U
#define PMFDMP3_DMP33_MASK              8U
#define PMFDMP3_DMP34_MASK              48U
#define PMFDMP3_DMP34_BITNUM            4U
#define PMFDMP3_DMP35_MASK              192U
#define PMFDMP3_DMP35_BITNUM            6U
#define PMFDMP3_DMP_30_MASK             15U
#define PMFDMP3_DMP_30_BITNUM           0U


/*** PMFDMP4 - PMF Disable Mapping Register 4; 0x0000053C ***/
typedef union {
  byte Byte;
  struct {
    byte DMP40       :1;                                       /* PWM Disable Mapping Channel 4 FAULT0 */
    byte DMP41       :1;                                       /* PWM Disable Mapping Channel 4 FAULT1 */
    byte DMP42       :1;                                       /* PWM Disable Mapping Channel 4 FAULT2 */
    byte DMP43       :1;                                       /* PWM Disable Mapping Channel 4 FAULT3 */
    byte DMP44       :2;                                       /* PWM Disable Mapping Channel 4 FAULT4 */
    byte DMP45       :2;                                       /* PWM Disable Mapping Channel 4 FAULT5 */
  } Bits;
  struct {
    byte grpDMP_40 :4;
    byte         :2;
    byte         :2;
  } MergedBits;
} PMFDMP4STR;
extern volatile PMFDMP4STR _PMFDMP4 @0x0000053C;
#define PMFDMP4                         _PMFDMP4.Byte
#define PMFDMP4_DMP40                   _PMFDMP4.Bits.DMP40
#define PMFDMP4_DMP41                   _PMFDMP4.Bits.DMP41
#define PMFDMP4_DMP42                   _PMFDMP4.Bits.DMP42
#define PMFDMP4_DMP43                   _PMFDMP4.Bits.DMP43
#define PMFDMP4_DMP44                   _PMFDMP4.Bits.DMP44
#define PMFDMP4_DMP45                   _PMFDMP4.Bits.DMP45
#define PMFDMP4_DMP_40                  _PMFDMP4.MergedBits.grpDMP_40
#define PMFDMP4_DMP                     PMFDMP4_DMP_40

#define PMFDMP4_DMP40_MASK              1U
#define PMFDMP4_DMP41_MASK              2U
#define PMFDMP4_DMP42_MASK              4U
#define PMFDMP4_DMP43_MASK              8U
#define PMFDMP4_DMP44_MASK              48U
#define PMFDMP4_DMP44_BITNUM            4U
#define PMFDMP4_DMP45_MASK              192U
#define PMFDMP4_DMP45_BITNUM            6U
#define PMFDMP4_DMP_40_MASK             15U
#define PMFDMP4_DMP_40_BITNUM           0U


/*** PMFDMP5 - PMF Disable Mapping Register 5; 0x0000053D ***/
typedef union {
  byte Byte;
  struct {
    byte DMP50       :1;                                       /* PWM Disable Mapping Channel 5 FAULT0 */
    byte DMP51       :1;                                       /* PWM Disable Mapping Channel 5 FAULT1 */
    byte DMP52       :1;                                       /* PWM Disable Mapping Channel 5 FAULT2 */
    byte DMP53       :1;                                       /* PWM Disable Mapping Channel 5 FAULT3 */
    byte DMP54       :2;                                       /* PWM Disable Mapping Channel 5 FAULT4 */
    byte DMP55       :2;                                       /* PWM Disable Mapping Channel 5 FAULT5 */
  } Bits;
  struct {
    byte grpDMP_50 :4;
    byte         :2;
    byte         :2;
  } MergedBits;
} PMFDMP5STR;
extern volatile PMFDMP5STR _PMFDMP5 @0x0000053D;
#define PMFDMP5                         _PMFDMP5.Byte
#define PMFDMP5_DMP50                   _PMFDMP5.Bits.DMP50
#define PMFDMP5_DMP51                   _PMFDMP5.Bits.DMP51
#define PMFDMP5_DMP52                   _PMFDMP5.Bits.DMP52
#define PMFDMP5_DMP53                   _PMFDMP5.Bits.DMP53
#define PMFDMP5_DMP54                   _PMFDMP5.Bits.DMP54
#define PMFDMP5_DMP55                   _PMFDMP5.Bits.DMP55
#define PMFDMP5_DMP_50                  _PMFDMP5.MergedBits.grpDMP_50
#define PMFDMP5_DMP                     PMFDMP5_DMP_50

#define PMFDMP5_DMP50_MASK              1U
#define PMFDMP5_DMP51_MASK              2U
#define PMFDMP5_DMP52_MASK              4U
#define PMFDMP5_DMP53_MASK              8U
#define PMFDMP5_DMP54_MASK              48U
#define PMFDMP5_DMP54_BITNUM            4U
#define PMFDMP5_DMP55_MASK              192U
#define PMFDMP5_DMP55_BITNUM            6U
#define PMFDMP5_DMP_50_MASK             15U
#define PMFDMP5_DMP_50_BITNUM           0U


/*** PMFOUTF - PMF Output Control on Fault Register; 0x0000053E ***/
typedef union {
  byte Byte;
  struct {
    byte OUTF0       :1;                                       /* OUTF Bit0 */
    byte OUTF1       :1;                                       /* OUTF Bit1 */
    byte OUTF2       :1;                                       /* OUTF Bit2 */
    byte OUTF3       :1;                                       /* OUTF Bit3 */
    byte OUTF4       :1;                                       /* OUTF Bit4 */
    byte OUTF5       :1;                                       /* OUTF Bit5 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOUTF :6;
    byte         :1;
    byte         :1;
  } MergedBits;
} PMFOUTFSTR;
extern volatile PMFOUTFSTR _PMFOUTF @0x0000053E;
#define PMFOUTF                         _PMFOUTF.Byte
#define PMFOUTF_OUTF0                   _PMFOUTF.Bits.OUTF0
#define PMFOUTF_OUTF1                   _PMFOUTF.Bits.OUTF1
#define PMFOUTF_OUTF2                   _PMFOUTF.Bits.OUTF2
#define PMFOUTF_OUTF3                   _PMFOUTF.Bits.OUTF3
#define PMFOUTF_OUTF4                   _PMFOUTF.Bits.OUTF4
#define PMFOUTF_OUTF5                   _PMFOUTF.Bits.OUTF5
#define PMFOUTF_OUTF                    _PMFOUTF.MergedBits.grpOUTF

#define PMFOUTF_OUTF0_MASK              1U
#define PMFOUTF_OUTF1_MASK              2U
#define PMFOUTF_OUTF2_MASK              4U
#define PMFOUTF_OUTF3_MASK              8U
#define PMFOUTF_OUTF4_MASK              16U
#define PMFOUTF_OUTF5_MASK              32U
#define PMFOUTF_OUTF_MASK               63U
#define PMFOUTF_OUTF_BITNUM             0U


/*** PTUE - PTU Enable Register; 0x00000580 ***/
typedef union {
  byte Byte;
  struct {
    byte TG0EN       :1;                                       /* Trigger Generator 0 Enable */
    byte TG1EN       :1;                                       /* Trigger Generator 1 Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PTUFRZ      :1;                                       /* PTU Stop in Freeze Mode */
    byte             :1; 
  } Bits;
} PTUESTR;
extern volatile PTUESTR _PTUE @0x00000580;
#define PTUE                            _PTUE.Byte
#define PTUE_TG0EN                      _PTUE.Bits.TG0EN
#define PTUE_TG1EN                      _PTUE.Bits.TG1EN
#define PTUE_PTUFRZ                     _PTUE.Bits.PTUFRZ

#define PTUE_TG0EN_MASK                 1U
#define PTUE_TG1EN_MASK                 2U
#define PTUE_PTUFRZ_MASK                64U


/*** PTUC - PTU Module Control Register; 0x00000581 ***/
typedef union {
  byte Byte;
  struct {
    byte PTULDOK     :1;                                       /* Load Okay */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PTUCSTR;
extern volatile PTUCSTR _PTUC @0x00000581;
#define PTUC                            _PTUC.Byte
#define PTUC_PTULDOK                    _PTUC.Bits.PTULDOK

#define PTUC_PTULDOK_MASK               1U


/*** PTUIEH - PTU Interrupt Enable Register High; 0x00000582 ***/
typedef union {
  byte Byte;
  struct {
    byte PTUROIE     :1;                                       /* PTU Reload Overrun Interrupt Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PTUIEHSTR;
extern volatile PTUIEHSTR _PTUIEH @0x00000582;
#define PTUIEH                          _PTUIEH.Byte
#define PTUIEH_PTUROIE                  _PTUIEH.Bits.PTUROIE

#define PTUIEH_PTUROIE_MASK             1U


/*** PTUIEL - PTU Interrupt Enable Register Low; 0x00000583 ***/
typedef union {
  byte Byte;
  struct {
    byte TG0DIE      :1;                                       /* Trigger Generator 0 Done Interrupt Enable */
    byte TG0TEIE     :1;                                       /* Trigger Generator 0 Timing Error Interrupt Enable */
    byte TG0REIE     :1;                                       /* Trigger Generator 0 Reload Error Interrupt Enable */
    byte TG0AEIE     :1;                                       /* Trigger Generator 0 Memory Access Error Interrupt Enable */
    byte TG1DIE      :1;                                       /* Trigger Generator 1 Done Interrupt Enable */
    byte TG1TEIE     :1;                                       /* Trigger Generator 1 Timing Error Interrupt Enable */
    byte TG1REIE     :1;                                       /* Trigger Generator 1 Reload Error Interrupt Enable */
    byte TG1AEIE     :1;                                       /* Trigger Generator 1 Memory Access Error Interrupt Enable */
  } Bits;
} PTUIELSTR;
extern volatile PTUIELSTR _PTUIEL @0x00000583;
#define PTUIEL                          _PTUIEL.Byte
#define PTUIEL_TG0DIE                   _PTUIEL.Bits.TG0DIE
#define PTUIEL_TG0TEIE                  _PTUIEL.Bits.TG0TEIE
#define PTUIEL_TG0REIE                  _PTUIEL.Bits.TG0REIE
#define PTUIEL_TG0AEIE                  _PTUIEL.Bits.TG0AEIE
#define PTUIEL_TG1DIE                   _PTUIEL.Bits.TG1DIE
#define PTUIEL_TG1TEIE                  _PTUIEL.Bits.TG1TEIE
#define PTUIEL_TG1REIE                  _PTUIEL.Bits.TG1REIE
#define PTUIEL_TG1AEIE                  _PTUIEL.Bits.TG1AEIE

#define PTUIEL_TG0DIE_MASK              1U
#define PTUIEL_TG0TEIE_MASK             2U
#define PTUIEL_TG0REIE_MASK             4U
#define PTUIEL_TG0AEIE_MASK             8U
#define PTUIEL_TG1DIE_MASK              16U
#define PTUIEL_TG1TEIE_MASK             32U
#define PTUIEL_TG1REIE_MASK             64U
#define PTUIEL_TG1AEIE_MASK             128U


/*** PTUIFH - PTU Interrupt Flag Register High; 0x00000584 ***/
typedef union {
  byte Byte;
  struct {
    byte PTUROIF     :1;                                       /* PTU Reload Overrun Interrupt Flag */
    byte PTUDEEF     :1;                                       /* PTU Double bit ECC Error Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PTUIFHSTR;
extern volatile PTUIFHSTR _PTUIFH @0x00000584;
#define PTUIFH                          _PTUIFH.Byte
#define PTUIFH_PTUROIF                  _PTUIFH.Bits.PTUROIF
#define PTUIFH_PTUDEEF                  _PTUIFH.Bits.PTUDEEF

#define PTUIFH_PTUROIF_MASK             1U
#define PTUIFH_PTUDEEF_MASK             2U


/*** PTUIFL - PTU Interrupt Flag Register Low; 0x00000585 ***/
typedef union {
  byte Byte;
  struct {
    byte TG0DIF      :1;                                       /* Trigger Generator 0 Done Interrupt Flag */
    byte TG0EIF      :1;                                       /* Trigger Generator 0 Timing Error Interrupt Flag */
    byte TG0REIF     :1;                                       /* Trigger Generator 0 Reload Error Interrupt Flag */
    byte TG0AEIF     :1;                                       /* Trigger Generator 0 Memory Access Error Interrupt Flag */
    byte TG1DIF      :1;                                       /* Trigger Generator 1 Done Interrupt Flag */
    byte TG1EIF      :1;                                       /* Trigger Generator 1 Timing Error Interrupt Flag */
    byte TG1REIF     :1;                                       /* Trigger Generator 1 Reload Error Interrupt Flag */
    byte TG1AEIF     :1;                                       /* Trigger Generator 1 Memory Access Error Interrupt Flag */
  } Bits;
} PTUIFLSTR;
extern volatile PTUIFLSTR _PTUIFL @0x00000585;
#define PTUIFL                          _PTUIFL.Byte
#define PTUIFL_TG0DIF                   _PTUIFL.Bits.TG0DIF
#define PTUIFL_TG0EIF                   _PTUIFL.Bits.TG0EIF
#define PTUIFL_TG0REIF                  _PTUIFL.Bits.TG0REIF
#define PTUIFL_TG0AEIF                  _PTUIFL.Bits.TG0AEIF
#define PTUIFL_TG1DIF                   _PTUIFL.Bits.TG1DIF
#define PTUIFL_TG1EIF                   _PTUIFL.Bits.TG1EIF
#define PTUIFL_TG1REIF                  _PTUIFL.Bits.TG1REIF
#define PTUIFL_TG1AEIF                  _PTUIFL.Bits.TG1AEIF

#define PTUIFL_TG0DIF_MASK              1U
#define PTUIFL_TG0EIF_MASK              2U
#define PTUIFL_TG0REIF_MASK             4U
#define PTUIFL_TG0AEIF_MASK             8U
#define PTUIFL_TG1DIF_MASK              16U
#define PTUIFL_TG1EIF_MASK              32U
#define PTUIFL_TG1REIF_MASK             64U
#define PTUIFL_TG1AEIF_MASK             128U


/*** TG0LIST - Trigger Generator 0 List Register; 0x00000586 ***/
typedef union {
  byte Byte;
  struct {
    byte TG0LIST_bit :1;                                       /* Trigger Generator 0 List */ /*Warning: bit name is duplicated with register name*/
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TG0LISTSTR;
extern volatile TG0LISTSTR _TG0LIST @0x00000586;
#define TG0LIST                         _TG0LIST.Byte
#define TG0LIST_TG0LIST                 _TG0LIST.Bits.TG0LIST_bit

#define TG0LIST_TG0LIST_MASK            1U


/*** TG0TNUM - Trigger Generator 0 Trigger Number Register; 0x00000587 ***/
typedef union {
  byte Byte;
  struct {
    byte TG0TNUM_grp :5;                                       /* Trigger Generator 0 Trigger Number */ /*Warning: group name is duplicated with register name*/
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TG0TNUMSTR;
extern volatile TG0TNUMSTR _TG0TNUM @0x00000587;
#define TG0TNUM                         _TG0TNUM.Byte
#define TG0TNUM_TG0TNUM                 _TG0TNUM.Bits.TG0TNUM_grp

#define TG0TNUM_TG0TNUM_MASK            31U
#define TG0TNUM_TG0TNUM_BITNUM          0U


/*** TG0TVH - Trigger Generator 0 Trigger Value; 0x00000588 ***/
typedef union {
  byte Byte;
} TG0TVHSTR;
extern volatile TG0TVHSTR _TG0TVH @0x00000588;
#define TG0TVH                          _TG0TVH.Byte


/*** TG0TVL - Trigger Generator 0 Trigger Value; 0x00000589 ***/
typedef union {
  byte Byte;
} TG0TVLSTR;
extern volatile TG0TVLSTR _TG0TVL @0x00000589;
#define TG0TVL                          _TG0TVL.Byte


/*** TG1LIST - Trigger Generator 1 List Register; 0x0000058A ***/
typedef union {
  byte Byte;
  struct {
    byte TG1LIST_bit :1;                                       /* Trigger Generator 1 List */ /*Warning: bit name is duplicated with register name*/
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TG1LISTSTR;
extern volatile TG1LISTSTR _TG1LIST @0x0000058A;
#define TG1LIST                         _TG1LIST.Byte
#define TG1LIST_TG1LIST                 _TG1LIST.Bits.TG1LIST_bit

#define TG1LIST_TG1LIST_MASK            1U


/*** TG1TNUM - Trigger Generator 1 Trigger Number Register; 0x0000058B ***/
typedef union {
  byte Byte;
  struct {
    byte TG1TNUM_grp :5;                                       /* Trigger Generator 1 Trigger Number */ /*Warning: group name is duplicated with register name*/
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TG1TNUMSTR;
extern volatile TG1TNUMSTR _TG1TNUM @0x0000058B;
#define TG1TNUM                         _TG1TNUM.Byte
#define TG1TNUM_TG1TNUM                 _TG1TNUM.Bits.TG1TNUM_grp

#define TG1TNUM_TG1TNUM_MASK            31U
#define TG1TNUM_TG1TNUM_BITNUM          0U


/*** TG1TVH - Trigger Generator 1 Trigger Value; 0x0000058C ***/
typedef union {
  byte Byte;
} TG1TVHSTR;
extern volatile TG1TVHSTR _TG1TVH @0x0000058C;
#define TG1TVH                          _TG1TVH.Byte


/*** TG1TVL - Trigger Generator 1 Trigger Value; 0x0000058D ***/
typedef union {
  byte Byte;
} TG1TVLSTR;
extern volatile TG1TVLSTR _TG1TVL @0x0000058D;
#define TG1TVL                          _TG1TVL.Byte


/*** PTUCNTH - PTU Counter Register; 0x0000058E ***/
typedef union {
  byte Byte;
} PTUCNTHSTR;
extern volatile PTUCNTHSTR _PTUCNTH @0x0000058E;
#define PTUCNTH                         _PTUCNTH.Byte


/*** PTUCNTL - PTU Counter Register; 0x0000058F ***/
typedef union {
  byte Byte;
} PTUCNTLSTR;
extern volatile PTUCNTLSTR _PTUCNTL @0x0000058F;
#define PTUCNTL                         _PTUCNTL.Byte


/*** PTUPTRH - PTU Pointer Register; 0x00000591 ***/
typedef union {
  byte Byte;
} PTUPTRHSTR;
extern volatile PTUPTRHSTR _PTUPTRH @0x00000591;
#define PTUPTRH                         _PTUPTRH.Byte


/*** PTUPTRM - PTU Pointer Register; 0x00000592 ***/
typedef union {
  byte Byte;
} PTUPTRMSTR;
extern volatile PTUPTRMSTR _PTUPTRM @0x00000592;
#define PTUPTRM                         _PTUPTRM.Byte


/*** PTUPTRL - PTU Pointer Register; 0x00000593 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte PTUPTR      :7;                                       /* PTU Pointer */
  } Bits;
} PTUPTRLSTR;
extern volatile PTUPTRLSTR _PTUPTRL @0x00000593;
#define PTUPTRL                         _PTUPTRL.Byte
#define PTUPTRL_PTUPTR                  _PTUPTRL.Bits.PTUPTR

#define PTUPTRL_PTUPTR_MASK             254U
#define PTUPTRL_PTUPTR_BITNUM           1U


/*** TG0L0IDX - Trigger Generator 0 List 0 Index Register; 0x00000594 ***/
typedef union {
  byte Byte;
  struct {
    byte TG0L0IDX_grp :7;                                      /* Trigger Generator 0 List 0 Index */ /*Warning: group name is duplicated with register name*/
    byte             :1; 
  } Bits;
} TG0L0IDXSTR;
extern volatile TG0L0IDXSTR _TG0L0IDX @0x00000594;
#define TG0L0IDX                        _TG0L0IDX.Byte
#define TG0L0IDX_TG0L0IDX               _TG0L0IDX.Bits.TG0L0IDX_grp

#define TG0L0IDX_TG0L0IDX_MASK          127U
#define TG0L0IDX_TG0L0IDX_BITNUM        0U


/*** TG0L1IDX - Trigger Generator 0 List 1 Index Register; 0x00000595 ***/
typedef union {
  byte Byte;
  struct {
    byte TG0L1IDX_grp :7;                                      /* Trigger Generator 0 List 1 Index */ /*Warning: group name is duplicated with register name*/
    byte             :1; 
  } Bits;
} TG0L1IDXSTR;
extern volatile TG0L1IDXSTR _TG0L1IDX @0x00000595;
#define TG0L1IDX                        _TG0L1IDX.Byte
#define TG0L1IDX_TG0L1IDX               _TG0L1IDX.Bits.TG0L1IDX_grp

#define TG0L1IDX_TG0L1IDX_MASK          127U
#define TG0L1IDX_TG0L1IDX_BITNUM        0U


/*** TG1L0IDX - Trigger Generator 1 List 0 Index Register; 0x00000596 ***/
typedef union {
  byte Byte;
  struct {
    byte TG1L0IDX_grp :7;                                      /* Trigger Generator 1 List 0 Index */ /*Warning: group name is duplicated with register name*/
    byte             :1; 
  } Bits;
} TG1L0IDXSTR;
extern volatile TG1L0IDXSTR _TG1L0IDX @0x00000596;
#define TG1L0IDX                        _TG1L0IDX.Byte
#define TG1L0IDX_TG1L0IDX               _TG1L0IDX.Bits.TG1L0IDX_grp

#define TG1L0IDX_TG1L0IDX_MASK          127U
#define TG1L0IDX_TG1L0IDX_BITNUM        0U


/*** TG1L1IDX - Trigger Generator 1 List 1 Index Register; 0x00000597 ***/
typedef union {
  byte Byte;
  struct {
    byte TG1L1IDX_grp :7;                                      /* Trigger Generator 1 List 1 Index */ /*Warning: group name is duplicated with register name*/
    byte             :1; 
  } Bits;
} TG1L1IDXSTR;
extern volatile TG1L1IDXSTR _TG1L1IDX @0x00000597;
#define TG1L1IDX                        _TG1L1IDX.Byte
#define TG1L1IDX_TG1L1IDX               _TG1L1IDX.Bits.TG1L1IDX_grp

#define TG1L1IDX_TG1L1IDX_MASK          127U
#define TG1L1IDX_TG1L1IDX_BITNUM        0U


/*** PTUDEBUG - PTU Debug Register; 0x0000059F ***/
typedef union {
  byte Byte;
  struct {
    byte TG0FTE      :1;                                       /* Trigger Generator 0 Force Trigger Event */
    byte TG1FTE      :1;                                       /* Trigger Generator 1 Force Trigger Event */
    byte PTUFRE      :1;                                       /* Force Reload event generation */
    byte             :1; 
    byte PTUT0PE     :1;                                       /* PTU PTUT0 Pin Enable */
    byte PTUT1PE     :1;                                       /* PTU PTUT1 Pin Enable */
    byte PTUREPE     :1;                                       /* PTU PTURE Pin Enable */
    byte             :1; 
  } Bits;
} PTUDEBUGSTR;
extern volatile PTUDEBUGSTR _PTUDEBUG @0x0000059F;
#define PTUDEBUG                        _PTUDEBUG.Byte
#define PTUDEBUG_TG0FTE                 _PTUDEBUG.Bits.TG0FTE
#define PTUDEBUG_TG1FTE                 _PTUDEBUG.Bits.TG1FTE
#define PTUDEBUG_PTUFRE                 _PTUDEBUG.Bits.PTUFRE
#define PTUDEBUG_PTUT0PE                _PTUDEBUG.Bits.PTUT0PE
#define PTUDEBUG_PTUT1PE                _PTUDEBUG.Bits.PTUT1PE
#define PTUDEBUG_PTUREPE                _PTUDEBUG.Bits.PTUREPE

#define PTUDEBUG_TG0FTE_MASK            1U
#define PTUDEBUG_TG1FTE_MASK            2U
#define PTUDEBUG_PTUFRE_MASK            4U
#define PTUDEBUG_PTUT0PE_MASK           16U
#define PTUDEBUG_PTUT1PE_MASK           32U
#define PTUDEBUG_PTUREPE_MASK           64U


/*** TIM0TIOS - Timer Input Capture/Output Compare Select; 0x000005C0 ***/
typedef union {
  byte Byte;
  struct {
    byte IOS0        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 0 */
    byte IOS1        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 1 */
    byte IOS2        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 2 */
    byte IOS3        :1;                                       /* Input Capture or Output Compare Channel Configuration Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpIOS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM0TIOSSTR;
extern volatile TIM0TIOSSTR _TIM0TIOS @0x000005C0;
#define TIM0TIOS                        _TIM0TIOS.Byte
#define TIM0TIOS_IOS0                   _TIM0TIOS.Bits.IOS0
#define TIM0TIOS_IOS1                   _TIM0TIOS.Bits.IOS1
#define TIM0TIOS_IOS2                   _TIM0TIOS.Bits.IOS2
#define TIM0TIOS_IOS3                   _TIM0TIOS.Bits.IOS3
#define TIM0TIOS_IOS                    _TIM0TIOS.MergedBits.grpIOS

#define TIM0TIOS_IOS0_MASK              1U
#define TIM0TIOS_IOS1_MASK              2U
#define TIM0TIOS_IOS2_MASK              4U
#define TIM0TIOS_IOS3_MASK              8U
#define TIM0TIOS_IOS_MASK               15U
#define TIM0TIOS_IOS_BITNUM             0U


/*** TIM0CFORC - Timer Compare Force Register; 0x000005C1 ***/
typedef union {
  byte Byte;
  struct {
    byte FOC0        :1;                                       /* Force Output Compare Action for Channel 0 */
    byte FOC1        :1;                                       /* Force Output Compare Action for Channel 1 */
    byte FOC2        :1;                                       /* Force Output Compare Action for Channel 2 */
    byte FOC3        :1;                                       /* Force Output Compare Action for Channel 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpFOC  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM0CFORCSTR;
extern volatile TIM0CFORCSTR _TIM0CFORC @0x000005C1;
#define TIM0CFORC                       _TIM0CFORC.Byte
#define TIM0CFORC_FOC0                  _TIM0CFORC.Bits.FOC0
#define TIM0CFORC_FOC1                  _TIM0CFORC.Bits.FOC1
#define TIM0CFORC_FOC2                  _TIM0CFORC.Bits.FOC2
#define TIM0CFORC_FOC3                  _TIM0CFORC.Bits.FOC3
#define TIM0CFORC_FOC                   _TIM0CFORC.MergedBits.grpFOC

#define TIM0CFORC_FOC0_MASK             1U
#define TIM0CFORC_FOC1_MASK             2U
#define TIM0CFORC_FOC2_MASK             4U
#define TIM0CFORC_FOC3_MASK             8U
#define TIM0CFORC_FOC_MASK              15U
#define TIM0CFORC_FOC_BITNUM            0U


/*** TIM0TCNT - Timer Count Register; 0x000005C4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0TCNTHi - Timer Count Register High (OBSOLETE - defined for backward compatibility); 0x000005C4 ***/
    union {
      byte Byte;
      /*** TIM0TCNTHi - Timer Count Register High (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TCNTHi                _TIM0TCNT.Overlap_STR.TIM0TCNTHiSTR.Byte
      
      /*** TIM0TCNTH - Timer Count Register High; Several registers at the same address ***/
      #define TIM0TCNTH                 _TIM0TCNT.Overlap_STR.TIM0TCNTHiSTR.Byte
      
    } TIM0TCNTHiSTR;
    

    /*** TIM0TCNTLo - Timer Count Register Low (OBSOLETE - defined for backward compatibility); 0x000005C5 ***/
    union {
      byte Byte;
      /*** TIM0TCNTLo - Timer Count Register Low (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TCNTLo                _TIM0TCNT.Overlap_STR.TIM0TCNTLoSTR.Byte
      
      /*** TIM0TCNTL - Timer Count Register Low; Several registers at the same address ***/
      #define TIM0TCNTL                 _TIM0TCNT.Overlap_STR.TIM0TCNTLoSTR.Byte
      
    } TIM0TCNTLoSTR;
    
  } Overlap_STR;

} TIM0TCNTSTR;
extern volatile TIM0TCNTSTR _TIM0TCNT @0x000005C4;
#define TIM0TCNT                        _TIM0TCNT.Word


/*** TIM0TSCR1 - Timer System Control Register1; 0x000005C6 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PRNT        :1;                                       /* Precision Timer */
    byte TFFCA       :1;                                       /* Timer Fast Flag Clear All */
    byte TSFRZ       :1;                                       /* Timer and Modulus Counter Stop While in Freeze Mode */
    byte TSWAI       :1;                                       /* Timer Module Stops While in Wait */
    byte TEN         :1;                                       /* Timer Enable */
  } Bits;
} TIM0TSCR1STR;
extern volatile TIM0TSCR1STR _TIM0TSCR1 @0x000005C6;
#define TIM0TSCR1                       _TIM0TSCR1.Byte
#define TIM0TSCR1_PRNT                  _TIM0TSCR1.Bits.PRNT
#define TIM0TSCR1_TFFCA                 _TIM0TSCR1.Bits.TFFCA
#define TIM0TSCR1_TSFRZ                 _TIM0TSCR1.Bits.TSFRZ
#define TIM0TSCR1_TSWAI                 _TIM0TSCR1.Bits.TSWAI
#define TIM0TSCR1_TEN                   _TIM0TSCR1.Bits.TEN

#define TIM0TSCR1_PRNT_MASK             8U
#define TIM0TSCR1_TFFCA_MASK            16U
#define TIM0TSCR1_TSFRZ_MASK            32U
#define TIM0TSCR1_TSWAI_MASK            64U
#define TIM0TSCR1_TEN_MASK              128U


/*** TIM0TTOV - Timer Toggle On Overflow Register; 0x000005C7 ***/
typedef union {
  byte Byte;
  struct {
    byte TOV0        :1;                                       /* Toggle On Overflow Bit 0 */
    byte TOV1        :1;                                       /* Toggle On Overflow Bit 1 */
    byte TOV2        :1;                                       /* Toggle On Overflow Bit 2 */
    byte TOV3        :1;                                       /* Toggle On Overflow Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpTOV  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM0TTOVSTR;
extern volatile TIM0TTOVSTR _TIM0TTOV @0x000005C7;
#define TIM0TTOV                        _TIM0TTOV.Byte
#define TIM0TTOV_TOV0                   _TIM0TTOV.Bits.TOV0
#define TIM0TTOV_TOV1                   _TIM0TTOV.Bits.TOV1
#define TIM0TTOV_TOV2                   _TIM0TTOV.Bits.TOV2
#define TIM0TTOV_TOV3                   _TIM0TTOV.Bits.TOV3
#define TIM0TTOV_TOV                    _TIM0TTOV.MergedBits.grpTOV

#define TIM0TTOV_TOV0_MASK              1U
#define TIM0TTOV_TOV1_MASK              2U
#define TIM0TTOV_TOV2_MASK              4U
#define TIM0TTOV_TOV3_MASK              8U
#define TIM0TTOV_TOV_MASK               15U
#define TIM0TTOV_TOV_BITNUM             0U


/*** TIM0TCTL2 - Timer Control Register 2; 0x000005C9 ***/
typedef union {
  byte Byte;
  struct {
    byte OL0         :1;                                       /* Output Level Bit 0 */
    byte OM0         :1;                                       /* Output Mode Bit 0 */
    byte OL1         :1;                                       /* Output Level Bit 1 */
    byte OM1         :1;                                       /* Output Mode Bit 1 */
    byte OL2         :1;                                       /* Output Level Bit 2 */
    byte OM2         :1;                                       /* Output Mode Bit 2 */
    byte OL3         :1;                                       /* Output Level Bit 3 */
    byte OM3         :1;                                       /* Output Mode Bit 3 */
  } Bits;
} TIM0TCTL2STR;
extern volatile TIM0TCTL2STR _TIM0TCTL2 @0x000005C9;
#define TIM0TCTL2                       _TIM0TCTL2.Byte
#define TIM0TCTL2_OL0                   _TIM0TCTL2.Bits.OL0
#define TIM0TCTL2_OM0                   _TIM0TCTL2.Bits.OM0
#define TIM0TCTL2_OL1                   _TIM0TCTL2.Bits.OL1
#define TIM0TCTL2_OM1                   _TIM0TCTL2.Bits.OM1
#define TIM0TCTL2_OL2                   _TIM0TCTL2.Bits.OL2
#define TIM0TCTL2_OM2                   _TIM0TCTL2.Bits.OM2
#define TIM0TCTL2_OL3                   _TIM0TCTL2.Bits.OL3
#define TIM0TCTL2_OM3                   _TIM0TCTL2.Bits.OM3

#define TIM0TCTL2_OL0_MASK              1U
#define TIM0TCTL2_OM0_MASK              2U
#define TIM0TCTL2_OL1_MASK              4U
#define TIM0TCTL2_OM1_MASK              8U
#define TIM0TCTL2_OL2_MASK              16U
#define TIM0TCTL2_OM2_MASK              32U
#define TIM0TCTL2_OL3_MASK              64U
#define TIM0TCTL2_OM3_MASK              128U


/*** TIM0TCTL4 - Timer Control Register 4; 0x000005CB ***/
typedef union {
  byte Byte;
  struct {
    byte EDG0A       :1;                                       /* Input Capture Edge Control 0A */
    byte EDG0B       :1;                                       /* Input Capture Edge Control 0B */
    byte EDG1A       :1;                                       /* Input Capture Edge Control 1A */
    byte EDG1B       :1;                                       /* Input Capture Edge Control 1B */
    byte EDG2A       :1;                                       /* Input Capture Edge Control 2A */
    byte EDG2B       :1;                                       /* Input Capture Edge Control 2B */
    byte EDG3A       :1;                                       /* Input Capture Edge Control 3A */
    byte EDG3B       :1;                                       /* Input Capture Edge Control 3B */
  } Bits;
  struct {
    byte grpEDG0x :2;
    byte grpEDG1x :2;
    byte grpEDG2x :2;
    byte grpEDG3x :2;
  } MergedBits;
} TIM0TCTL4STR;
extern volatile TIM0TCTL4STR _TIM0TCTL4 @0x000005CB;
#define TIM0TCTL4                       _TIM0TCTL4.Byte
#define TIM0TCTL4_EDG0A                 _TIM0TCTL4.Bits.EDG0A
#define TIM0TCTL4_EDG0B                 _TIM0TCTL4.Bits.EDG0B
#define TIM0TCTL4_EDG1A                 _TIM0TCTL4.Bits.EDG1A
#define TIM0TCTL4_EDG1B                 _TIM0TCTL4.Bits.EDG1B
#define TIM0TCTL4_EDG2A                 _TIM0TCTL4.Bits.EDG2A
#define TIM0TCTL4_EDG2B                 _TIM0TCTL4.Bits.EDG2B
#define TIM0TCTL4_EDG3A                 _TIM0TCTL4.Bits.EDG3A
#define TIM0TCTL4_EDG3B                 _TIM0TCTL4.Bits.EDG3B
#define TIM0TCTL4_EDG0x                 _TIM0TCTL4.MergedBits.grpEDG0x
#define TIM0TCTL4_EDG1x                 _TIM0TCTL4.MergedBits.grpEDG1x
#define TIM0TCTL4_EDG2x                 _TIM0TCTL4.MergedBits.grpEDG2x
#define TIM0TCTL4_EDG3x                 _TIM0TCTL4.MergedBits.grpEDG3x

#define TIM0TCTL4_EDG0A_MASK            1U
#define TIM0TCTL4_EDG0B_MASK            2U
#define TIM0TCTL4_EDG1A_MASK            4U
#define TIM0TCTL4_EDG1B_MASK            8U
#define TIM0TCTL4_EDG2A_MASK            16U
#define TIM0TCTL4_EDG2B_MASK            32U
#define TIM0TCTL4_EDG3A_MASK            64U
#define TIM0TCTL4_EDG3B_MASK            128U
#define TIM0TCTL4_EDG0x_MASK            3U
#define TIM0TCTL4_EDG0x_BITNUM          0U
#define TIM0TCTL4_EDG1x_MASK            12U
#define TIM0TCTL4_EDG1x_BITNUM          2U
#define TIM0TCTL4_EDG2x_MASK            48U
#define TIM0TCTL4_EDG2x_BITNUM          4U
#define TIM0TCTL4_EDG3x_MASK            192U
#define TIM0TCTL4_EDG3x_BITNUM          6U


/*** TIM0TIE - Timer Interrupt Enable Register; 0x000005CC ***/
typedef union {
  byte Byte;
  struct {
    byte C0I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 0 */
    byte C1I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 1 */
    byte C2I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 2 */
    byte C3I         :1;                                       /* Input Capture/Output Compare Interrupt Enable Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TIM0TIESTR;
extern volatile TIM0TIESTR _TIM0TIE @0x000005CC;
#define TIM0TIE                         _TIM0TIE.Byte
#define TIM0TIE_C0I                     _TIM0TIE.Bits.C0I
#define TIM0TIE_C1I                     _TIM0TIE.Bits.C1I
#define TIM0TIE_C2I                     _TIM0TIE.Bits.C2I
#define TIM0TIE_C3I                     _TIM0TIE.Bits.C3I

#define TIM0TIE_C0I_MASK                1U
#define TIM0TIE_C1I_MASK                2U
#define TIM0TIE_C2I_MASK                4U
#define TIM0TIE_C3I_MASK                8U


/*** TIM0TSCR2 - Timer System Control Register 2; 0x000005CD ***/
typedef union {
  byte Byte;
  struct {
    byte PR0         :1;                                       /* Timer Prescaler Select Bit 0 */
    byte PR1         :1;                                       /* Timer Prescaler Select Bit 1 */
    byte PR2         :1;                                       /* Timer Prescaler Select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TOI         :1;                                       /* Timer Overflow Interrupt Enable */
  } Bits;
  struct {
    byte grpPR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM0TSCR2STR;
extern volatile TIM0TSCR2STR _TIM0TSCR2 @0x000005CD;
#define TIM0TSCR2                       _TIM0TSCR2.Byte
#define TIM0TSCR2_PR0                   _TIM0TSCR2.Bits.PR0
#define TIM0TSCR2_PR1                   _TIM0TSCR2.Bits.PR1
#define TIM0TSCR2_PR2                   _TIM0TSCR2.Bits.PR2
#define TIM0TSCR2_TOI                   _TIM0TSCR2.Bits.TOI
#define TIM0TSCR2_PR                    _TIM0TSCR2.MergedBits.grpPR

#define TIM0TSCR2_PR0_MASK              1U
#define TIM0TSCR2_PR1_MASK              2U
#define TIM0TSCR2_PR2_MASK              4U
#define TIM0TSCR2_TOI_MASK              128U
#define TIM0TSCR2_PR_MASK               7U
#define TIM0TSCR2_PR_BITNUM             0U


/*** TIM0TFLG1 - Main Timer Interrupt Flag 1; 0x000005CE ***/
typedef union {
  byte Byte;
  struct {
    byte C0F         :1;                                       /* Input Capture/Output Compare Channel interrupt flag 0 */
    byte C1F         :1;                                       /* Input Capture/Output Compare Channel interrupt flag 1 */
    byte C2F         :1;                                       /* Input Capture/Output Compare Channel interrupt flag 2 */
    byte C3F         :1;                                       /* Input Capture/Output Compare Channel interrupt flag 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} TIM0TFLG1STR;
extern volatile TIM0TFLG1STR _TIM0TFLG1 @0x000005CE;
#define TIM0TFLG1                       _TIM0TFLG1.Byte
#define TIM0TFLG1_C0F                   _TIM0TFLG1.Bits.C0F
#define TIM0TFLG1_C1F                   _TIM0TFLG1.Bits.C1F
#define TIM0TFLG1_C2F                   _TIM0TFLG1.Bits.C2F
#define TIM0TFLG1_C3F                   _TIM0TFLG1.Bits.C3F

#define TIM0TFLG1_C0F_MASK              1U
#define TIM0TFLG1_C1F_MASK              2U
#define TIM0TFLG1_C2F_MASK              4U
#define TIM0TFLG1_C3F_MASK              8U


/*** TIM0TFLG2 - Main Timer Interrupt Flag 2; 0x000005CF ***/
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
    byte TOF         :1;                                       /* Timer Overflow interrupt flag */
  } Bits;
} TIM0TFLG2STR;
extern volatile TIM0TFLG2STR _TIM0TFLG2 @0x000005CF;
#define TIM0TFLG2                       _TIM0TFLG2.Byte
#define TIM0TFLG2_TOF                   _TIM0TFLG2.Bits.TOF

#define TIM0TFLG2_TOF_MASK              128U


/*** TIM0TC0 - Timer Input Capture/Output Compare Register 0; 0x000005D0 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0TC0Hi - Timer Input Capture/Output Compare Register 0 High (OBSOLETE - defined for backward compatibility); 0x000005D0 ***/
    union {
      byte Byte;
      /*** TIM0TC0Hi - Timer Input Capture/Output Compare Register 0 High (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TC0Hi                 _TIM0TC0.Overlap_STR.TIM0TC0HiSTR.Byte
      
      /*** TIM0TC0H - Timer Input Capture/Output Compare Register 0 High; Several registers at the same address ***/
      #define TIM0TC0H                  _TIM0TC0.Overlap_STR.TIM0TC0HiSTR.Byte
      
    } TIM0TC0HiSTR;
    

    /*** TIM0TC0Lo - Timer Input Capture/Output Compare Register 0 Low (OBSOLETE - defined for backward compatibility); 0x000005D1 ***/
    union {
      byte Byte;
      /*** TIM0TC0Lo - Timer Input Capture/Output Compare Register 0 Low (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TC0Lo                 _TIM0TC0.Overlap_STR.TIM0TC0LoSTR.Byte
      
      /*** TIM0TC0L - Timer Input Capture/Output Compare Register 0 Low; Several registers at the same address ***/
      #define TIM0TC0L                  _TIM0TC0.Overlap_STR.TIM0TC0LoSTR.Byte
      
    } TIM0TC0LoSTR;
    
  } Overlap_STR;

} TIM0TC0STR;
extern volatile TIM0TC0STR _TIM0TC0 @0x000005D0;
#define TIM0TC0                         _TIM0TC0.Word
/* TIM0TC_ARR: Access 4 TIM0TCx registers in an array */
#define TIM0TC_ARR                      ((volatile word *) &TIM0TC0)


/*** TIM0TC1 - Timer Input Capture/Output Compare Register 1; 0x000005D2 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0TC1Hi - Timer Input Capture/Output Compare Register 1 High (OBSOLETE - defined for backward compatibility); 0x000005D2 ***/
    union {
      byte Byte;
      /*** TIM0TC1Hi - Timer Input Capture/Output Compare Register 1 High (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TC1Hi                 _TIM0TC1.Overlap_STR.TIM0TC1HiSTR.Byte
      
      /*** TIM0TC1H - Timer Input Capture/Output Compare Register 1 High; Several registers at the same address ***/
      #define TIM0TC1H                  _TIM0TC1.Overlap_STR.TIM0TC1HiSTR.Byte
      
    } TIM0TC1HiSTR;
    

    /*** TIM0TC1Lo - Timer Input Capture/Output Compare Register 1 Low (OBSOLETE - defined for backward compatibility); 0x000005D3 ***/
    union {
      byte Byte;
      /*** TIM0TC1Lo - Timer Input Capture/Output Compare Register 1 Low (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TC1Lo                 _TIM0TC1.Overlap_STR.TIM0TC1LoSTR.Byte
      
      /*** TIM0TC1L - Timer Input Capture/Output Compare Register 1 Low; Several registers at the same address ***/
      #define TIM0TC1L                  _TIM0TC1.Overlap_STR.TIM0TC1LoSTR.Byte
      
    } TIM0TC1LoSTR;
    
  } Overlap_STR;

} TIM0TC1STR;
extern volatile TIM0TC1STR _TIM0TC1 @0x000005D2;
#define TIM0TC1                         _TIM0TC1.Word


/*** TIM0TC2 - Timer Input Capture/Output Compare Register 2; 0x000005D4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0TC2Hi - Timer Input Capture/Output Compare Register 2 High (OBSOLETE - defined for backward compatibility); 0x000005D4 ***/
    union {
      byte Byte;
      /*** TIM0TC2Hi - Timer Input Capture/Output Compare Register 2 High (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TC2Hi                 _TIM0TC2.Overlap_STR.TIM0TC2HiSTR.Byte
      
      /*** TIM0TC2H - Timer Input Capture/Output Compare Register 2 High; Several registers at the same address ***/
      #define TIM0TC2H                  _TIM0TC2.Overlap_STR.TIM0TC2HiSTR.Byte
      
    } TIM0TC2HiSTR;
    

    /*** TIM0TC2Lo - Timer Input Capture/Output Compare Register 2 Low (OBSOLETE - defined for backward compatibility); 0x000005D5 ***/
    union {
      byte Byte;
      /*** TIM0TC2Lo - Timer Input Capture/Output Compare Register 2 Low (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TC2Lo                 _TIM0TC2.Overlap_STR.TIM0TC2LoSTR.Byte
      
      /*** TIM0TC2L - Timer Input Capture/Output Compare Register 2 Low; Several registers at the same address ***/
      #define TIM0TC2L                  _TIM0TC2.Overlap_STR.TIM0TC2LoSTR.Byte
      
    } TIM0TC2LoSTR;
    
  } Overlap_STR;

} TIM0TC2STR;
extern volatile TIM0TC2STR _TIM0TC2 @0x000005D4;
#define TIM0TC2                         _TIM0TC2.Word


/*** TIM0TC3 - Timer Input Capture/Output Compare Register 3; 0x000005D6 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TIM0TC3Hi - Timer Input Capture/Output Compare Register 3 High (OBSOLETE - defined for backward compatibility); 0x000005D6 ***/
    union {
      byte Byte;
      /*** TIM0TC3Hi - Timer Input Capture/Output Compare Register 3 High (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TC3Hi                 _TIM0TC3.Overlap_STR.TIM0TC3HiSTR.Byte
      
      /*** TIM0TC3H - Timer Input Capture/Output Compare Register 3 High; Several registers at the same address ***/
      #define TIM0TC3H                  _TIM0TC3.Overlap_STR.TIM0TC3HiSTR.Byte
      
    } TIM0TC3HiSTR;
    

    /*** TIM0TC3Lo - Timer Input Capture/Output Compare Register 3 Low (OBSOLETE - defined for backward compatibility); 0x000005D7 ***/
    union {
      byte Byte;
      /*** TIM0TC3Lo - Timer Input Capture/Output Compare Register 3 Low (OBSOLETE - defined for backward compatibility); Several registers at the same address ***/
      #define TIM0TC3Lo                 _TIM0TC3.Overlap_STR.TIM0TC3LoSTR.Byte
      
      /*** TIM0TC3L - Timer Input Capture/Output Compare Register 3 Low; Several registers at the same address ***/
      #define TIM0TC3L                  _TIM0TC3.Overlap_STR.TIM0TC3LoSTR.Byte
      
    } TIM0TC3LoSTR;
    
  } Overlap_STR;

} TIM0TC3STR;
extern volatile TIM0TC3STR _TIM0TC3 @0x000005D6;
#define TIM0TC3                         _TIM0TC3.Word


/*** TIM0OCPD - Output Compare Pin Disconnect Register; 0x000005EC ***/
typedef union {
  byte Byte;
  struct {
    byte OCPD0       :1;                                       /* Output Compare Pin Disconnect Bit 0 */
    byte OCPD1       :1;                                       /* Output Compare Pin Disconnect Bit 1 */
    byte OCPD2       :1;                                       /* Output Compare Pin Disconnect Bit 2 */
    byte OCPD3       :1;                                       /* Output Compare Pin Disconnect Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpOCPD :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TIM0OCPDSTR;
extern volatile TIM0OCPDSTR _TIM0OCPD @0x000005EC;
#define TIM0OCPD                        _TIM0OCPD.Byte
#define TIM0OCPD_OCPD0                  _TIM0OCPD.Bits.OCPD0
#define TIM0OCPD_OCPD1                  _TIM0OCPD.Bits.OCPD1
#define TIM0OCPD_OCPD2                  _TIM0OCPD.Bits.OCPD2
#define TIM0OCPD_OCPD3                  _TIM0OCPD.Bits.OCPD3
#define TIM0OCPD_OCPD                   _TIM0OCPD.MergedBits.grpOCPD

#define TIM0OCPD_OCPD0_MASK             1U
#define TIM0OCPD_OCPD1_MASK             2U
#define TIM0OCPD_OCPD2_MASK             4U
#define TIM0OCPD_OCPD3_MASK             8U
#define TIM0OCPD_OCPD_MASK              15U
#define TIM0OCPD_OCPD_BITNUM            0U


/*** TIM0PTPSR - Precision Timer Prescaler Select Register; 0x000005EE ***/
typedef union {
  byte Byte;
  struct {
    byte PTPS0       :1;                                       /* Precision Timer Prescaler Select Bit 0 */
    byte PTPS1       :1;                                       /* Precision Timer Prescaler Select Bit 1 */
    byte PTPS2       :1;                                       /* Precision Timer Prescaler Select Bit 2 */
    byte PTPS3       :1;                                       /* Precision Timer Prescaler Select Bit 3 */
    byte PTPS4       :1;                                       /* Precision Timer Prescaler Select Bit 4 */
    byte PTPS5       :1;                                       /* Precision Timer Prescaler Select Bit 5 */
    byte PTPS6       :1;                                       /* Precision Timer Prescaler Select Bit 6 */
    byte PTPS7       :1;                                       /* Precision Timer Prescaler Select Bit 7 */
  } Bits;
} TIM0PTPSRSTR;
extern volatile TIM0PTPSRSTR _TIM0PTPSR @0x000005EE;
#define TIM0PTPSR                       _TIM0PTPSR.Byte
#define TIM0PTPSR_PTPS0                 _TIM0PTPSR.Bits.PTPS0
#define TIM0PTPSR_PTPS1                 _TIM0PTPSR.Bits.PTPS1
#define TIM0PTPSR_PTPS2                 _TIM0PTPSR.Bits.PTPS2
#define TIM0PTPSR_PTPS3                 _TIM0PTPSR.Bits.PTPS3
#define TIM0PTPSR_PTPS4                 _TIM0PTPSR.Bits.PTPS4
#define TIM0PTPSR_PTPS5                 _TIM0PTPSR.Bits.PTPS5
#define TIM0PTPSR_PTPS6                 _TIM0PTPSR.Bits.PTPS6
#define TIM0PTPSR_PTPS7                 _TIM0PTPSR.Bits.PTPS7

#define TIM0PTPSR_PTPS0_MASK            1U
#define TIM0PTPSR_PTPS1_MASK            2U
#define TIM0PTPSR_PTPS2_MASK            4U
#define TIM0PTPSR_PTPS3_MASK            8U
#define TIM0PTPSR_PTPS4_MASK            16U
#define TIM0PTPSR_PTPS5_MASK            32U
#define TIM0PTPSR_PTPS6_MASK            64U
#define TIM0PTPSR_PTPS7_MASK            128U


/*** ADC0CTL - ADC0 Control Register; 0x00000600 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC0CTL_0 - ADC0 Control Register 0; 0x00000600 ***/
    union {
      byte Byte;
      struct {
        byte MOD_CFG     :1;                                       /* Trigger Mode Configuration */
        byte STR_SEQA    :1;                                       /* Handling Restart Requests during End Of List Command Type Execution */
        byte ACC_CFG     :2;                                       /* ADCFLWCTL Register Access Configuration */
        byte SWAI        :1;                                       /* Wait Mode Configuration */
        byte FRZ_MOD     :1;                                       /* Freeze Mode Configuration */
        byte ADC_SR      :1;                                       /* ADC Soft Reset */
        byte ADC_EN      :1;                                       /* ADC Enable Bit */
      } Bits;
    } ADC0CTL_0STR;
    #define ADC0CTL_0                   _ADC0CTL.Overlap_STR.ADC0CTL_0STR.Byte
    #define ADC0CTL_0_MOD_CFG           _ADC0CTL.Overlap_STR.ADC0CTL_0STR.Bits.MOD_CFG
    #define ADC0CTL_0_STR_SEQA          _ADC0CTL.Overlap_STR.ADC0CTL_0STR.Bits.STR_SEQA
    #define ADC0CTL_0_ACC_CFG           _ADC0CTL.Overlap_STR.ADC0CTL_0STR.Bits.ACC_CFG
    #define ADC0CTL_0_SWAI              _ADC0CTL.Overlap_STR.ADC0CTL_0STR.Bits.SWAI
    #define ADC0CTL_0_FRZ_MOD           _ADC0CTL.Overlap_STR.ADC0CTL_0STR.Bits.FRZ_MOD
    #define ADC0CTL_0_ADC_SR            _ADC0CTL.Overlap_STR.ADC0CTL_0STR.Bits.ADC_SR
    #define ADC0CTL_0_ADC_EN            _ADC0CTL.Overlap_STR.ADC0CTL_0STR.Bits.ADC_EN
    /* ADC0CTL__ARR: Access 2 ADC0CTL_x registers in an array */
    #define ADC0CTL__ARR                ((volatile byte *) &ADC0CTL_0)
    
    #define ADC0CTL_0_MOD_CFG_MASK      1U
    #define ADC0CTL_0_STR_SEQA_MASK     2U
    #define ADC0CTL_0_ACC_CFG_MASK      12U
    #define ADC0CTL_0_ACC_CFG_BITNUM    2U
    #define ADC0CTL_0_SWAI_MASK         16U
    #define ADC0CTL_0_FRZ_MOD_MASK      32U
    #define ADC0CTL_0_ADC_SR_MASK       64U
    #define ADC0CTL_0_ADC_EN_MASK       128U
    

    /*** ADC0CTL_1 - ADC0 Control Register 1; 0x00000601 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte AUT_RSTA    :1;                                       /* Automatic Restart Event after exit from MCU Stop and Wait Mode */
        byte SMOD_ACC    :1;                                       /* Special Mode Access Control */
        byte RVL_BMOD    :1;                                       /* RVL Buffer Mode Select */
        byte CSL_BMOD    :1;                                       /* CSL Buffer Mode Select */
      } Bits;
    } ADC0CTL_1STR;
    #define ADC0CTL_1                   _ADC0CTL.Overlap_STR.ADC0CTL_1STR.Byte
    #define ADC0CTL_1_AUT_RSTA          _ADC0CTL.Overlap_STR.ADC0CTL_1STR.Bits.AUT_RSTA
    #define ADC0CTL_1_SMOD_ACC          _ADC0CTL.Overlap_STR.ADC0CTL_1STR.Bits.SMOD_ACC
    #define ADC0CTL_1_RVL_BMOD          _ADC0CTL.Overlap_STR.ADC0CTL_1STR.Bits.RVL_BMOD
    #define ADC0CTL_1_CSL_BMOD          _ADC0CTL.Overlap_STR.ADC0CTL_1STR.Bits.CSL_BMOD
    
    #define ADC0CTL_1_AUT_RSTA_MASK     16U
    #define ADC0CTL_1_SMOD_ACC_MASK     32U
    #define ADC0CTL_1_RVL_BMOD_MASK     64U
    #define ADC0CTL_1_CSL_BMOD_MASK     128U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word AUT_RSTA    :1;                                       /* Automatic Restart Event after exit from MCU Stop and Wait Mode */
    word SMOD_ACC    :1;                                       /* Special Mode Access Control */
    word RVL_BMOD    :1;                                       /* RVL Buffer Mode Select */
    word CSL_BMOD    :1;                                       /* CSL Buffer Mode Select */
    word MOD_CFG     :1;                                       /* Trigger Mode Configuration */
    word STR_SEQA    :1;                                       /* Control Of Conversion Result Storage during Sequence abort (SEQA) or Restart request (RSTA) */
    word ACC_CFG     :2;                                       /* ADCFLWCTL Register Access Configuration */
    word SWAI        :1;                                       /* Wait Mode Configuration */
    word FRZ_MOD     :1;                                       /* Freeze Mode Configuration */
    word ADC_SR      :1;                                       /* ADC Soft Reset */
    word ADC_EN      :1;                                       /* ADC Enable Bit */
  } Bits;
} ADC0CTLSTR;
extern volatile ADC0CTLSTR _ADC0CTL @0x00000600;
#define ADC0CTL                         _ADC0CTL.Word
#define ADC0CTL_AUT_RSTA                _ADC0CTL.Bits.AUT_RSTA
#define ADC0CTL_SMOD_ACC                _ADC0CTL.Bits.SMOD_ACC
#define ADC0CTL_RVL_BMOD                _ADC0CTL.Bits.RVL_BMOD
#define ADC0CTL_CSL_BMOD                _ADC0CTL.Bits.CSL_BMOD
#define ADC0CTL_MOD_CFG                 _ADC0CTL.Bits.MOD_CFG
#define ADC0CTL_STR_SEQA                _ADC0CTL.Bits.STR_SEQA
#define ADC0CTL_ACC_CFG                 _ADC0CTL.Bits.ACC_CFG
#define ADC0CTL_SWAI                    _ADC0CTL.Bits.SWAI
#define ADC0CTL_FRZ_MOD                 _ADC0CTL.Bits.FRZ_MOD
#define ADC0CTL_ADC_SR                  _ADC0CTL.Bits.ADC_SR
#define ADC0CTL_ADC_EN                  _ADC0CTL.Bits.ADC_EN

#define ADC0CTL_AUT_RSTA_MASK           16U
#define ADC0CTL_SMOD_ACC_MASK           32U
#define ADC0CTL_RVL_BMOD_MASK           64U
#define ADC0CTL_CSL_BMOD_MASK           128U
#define ADC0CTL_MOD_CFG_MASK            256U
#define ADC0CTL_STR_SEQA_MASK           512U
#define ADC0CTL_ACC_CFG_MASK            3072U
#define ADC0CTL_ACC_CFG_BITNUM          10U
#define ADC0CTL_SWAI_MASK               4096U
#define ADC0CTL_FRZ_MOD_MASK            8192U
#define ADC0CTL_ADC_SR_MASK             16384U
#define ADC0CTL_ADC_EN_MASK             32768U


/*** ADC0STS - ADC0 Status Register; 0x00000602 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte READY       :1;                                       /* Flag indicates that ADC is in its idle state and ready for a Restart Event */
    byte             :1; 
    byte DBECC_ERR   :1;                                       /* Double Bit ECC Error Flag */
    byte RVL_SEL     :1;                                       /* Result Value List Select */
    byte CSL_SEL     :1;                                       /* Command Sequence List Select */
  } Bits;
} ADC0STSSTR;
extern volatile ADC0STSSTR _ADC0STS @0x00000602;
#define ADC0STS                         _ADC0STS.Byte
#define ADC0STS_READY                   _ADC0STS.Bits.READY
#define ADC0STS_DBECC_ERR               _ADC0STS.Bits.DBECC_ERR
#define ADC0STS_RVL_SEL                 _ADC0STS.Bits.RVL_SEL
#define ADC0STS_CSL_SEL                 _ADC0STS.Bits.CSL_SEL

#define ADC0STS_READY_MASK              8U
#define ADC0STS_DBECC_ERR_MASK          32U
#define ADC0STS_RVL_SEL_MASK            64U
#define ADC0STS_CSL_SEL_MASK            128U


/*** ADC0TIM - ADC0 Timing Register; 0x00000603 ***/
typedef union {
  byte Byte;
  struct {
    byte PRS         :7;                                       /* ADC Clock Prescaler */
    byte             :1; 
  } Bits;
} ADC0TIMSTR;
extern volatile ADC0TIMSTR _ADC0TIM @0x00000603;
#define ADC0TIM                         _ADC0TIM.Byte
#define ADC0TIM_PRS                     _ADC0TIM.Bits.PRS

#define ADC0TIM_PRS_MASK                127U
#define ADC0TIM_PRS_BITNUM              0U


/*** ADC0FMT - ADC0 Format Register; 0x00000604 ***/
typedef union {
  byte Byte;
  struct {
    byte SRES        :3;                                       /* ADC Resolution Select */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DJM         :1;                                       /* Result Register Data Justification */
  } Bits;
} ADC0FMTSTR;
extern volatile ADC0FMTSTR _ADC0FMT @0x00000604;
#define ADC0FMT                         _ADC0FMT.Byte
#define ADC0FMT_SRES                    _ADC0FMT.Bits.SRES
#define ADC0FMT_DJM                     _ADC0FMT.Bits.DJM

#define ADC0FMT_SRES_MASK               7U
#define ADC0FMT_SRES_BITNUM             0U
#define ADC0FMT_DJM_MASK                128U


/*** ADC0FLWCTL - ADC0 Conversion Flow Control Register; 0x00000605 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LDOK        :1;                                       /* Load OK for alternative Command Sequence List */
    byte RSTA        :1;                                       /* Restart Event (Restart from Top of Command Sequence List) */
    byte TRIG        :1;                                       /* Conversion Sequence Trigger */
    byte SEQA        :1;                                       /* Conversion Sequence Abort Event */
  } Bits;
} ADC0FLWCTLSTR;
extern volatile ADC0FLWCTLSTR _ADC0FLWCTL @0x00000605;
#define ADC0FLWCTL                      _ADC0FLWCTL.Byte
#define ADC0FLWCTL_LDOK                 _ADC0FLWCTL.Bits.LDOK
#define ADC0FLWCTL_RSTA                 _ADC0FLWCTL.Bits.RSTA
#define ADC0FLWCTL_TRIG                 _ADC0FLWCTL.Bits.TRIG
#define ADC0FLWCTL_SEQA                 _ADC0FLWCTL.Bits.SEQA

#define ADC0FLWCTL_LDOK_MASK            16U
#define ADC0FLWCTL_RSTA_MASK            32U
#define ADC0FLWCTL_TRIG_MASK            64U
#define ADC0FLWCTL_SEQA_MASK            128U


/*** ADC0EIE - ADC0 Error Interrupt Enable Register; 0x00000606 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LDOK_EIE    :1;                                       /* Load OK Error Interrupt Enable */
    byte RSTAR_EIE   :1;                                       /* Restart Request Error Interrupt Enable */
    byte TRIG_EIE    :1;                                       /* Conversion Sequence Trigger Error Interrupt Enable */
    byte             :1; 
    byte EOL_EIE     :1;                                       /* End Of List Error Interrupt Enable */
    byte CMD_EIE     :1;                                       /* Command Value Error Interrupt Enable */
    byte IA_EIE      :1;                                       /* Illegal Access Error Interrupt Enable */
  } Bits;
} ADC0EIESTR;
extern volatile ADC0EIESTR _ADC0EIE @0x00000606;
#define ADC0EIE                         _ADC0EIE.Byte
#define ADC0EIE_LDOK_EIE                _ADC0EIE.Bits.LDOK_EIE
#define ADC0EIE_RSTAR_EIE               _ADC0EIE.Bits.RSTAR_EIE
#define ADC0EIE_TRIG_EIE                _ADC0EIE.Bits.TRIG_EIE
#define ADC0EIE_EOL_EIE                 _ADC0EIE.Bits.EOL_EIE
#define ADC0EIE_CMD_EIE                 _ADC0EIE.Bits.CMD_EIE
#define ADC0EIE_IA_EIE                  _ADC0EIE.Bits.IA_EIE

#define ADC0EIE_LDOK_EIE_MASK           2U
#define ADC0EIE_RSTAR_EIE_MASK          4U
#define ADC0EIE_TRIG_EIE_MASK           8U
#define ADC0EIE_EOL_EIE_MASK            32U
#define ADC0EIE_CMD_EIE_MASK            64U
#define ADC0EIE_IA_EIE_MASK             128U


/*** ADC0IE - ADC0 Interrupt Enable Register; 0x00000607 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CONIF_OIE   :1;                                       /* ADCCONIF Register Flags Overrun Interrupt Enable */
    byte SEQAD_IE    :1;                                       /* Conversion Sequence Abort Done Interrupt Enable */
  } Bits;
} ADC0IESTR;
extern volatile ADC0IESTR _ADC0IE @0x00000607;
#define ADC0IE                          _ADC0IE.Byte
#define ADC0IE_CONIF_OIE                _ADC0IE.Bits.CONIF_OIE
#define ADC0IE_SEQAD_IE                 _ADC0IE.Bits.SEQAD_IE

#define ADC0IE_CONIF_OIE_MASK           64U
#define ADC0IE_SEQAD_IE_MASK            128U


/*** ADC0EIF - ADC0 Error Interrupt Flag Register; 0x00000608 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LDOK_EIF    :1;                                       /* Load OK Error Interrupt Flag */
    byte RSTAR_EIF   :1;                                       /* Restart Request Error Interrupt Flag */
    byte TRIG_EIF    :1;                                       /* Trigger Error Interrupt Flag */
    byte             :1; 
    byte EOL_EIF     :1;                                       /* End Of List Error Interrupt Flag */
    byte CMD_EIF     :1;                                       /* Command Value Error Interrupt Flag */
    byte IA_EIF      :1;                                       /* Illegal Access Error Interrupt Flag */
  } Bits;
} ADC0EIFSTR;
extern volatile ADC0EIFSTR _ADC0EIF @0x00000608;
#define ADC0EIF                         _ADC0EIF.Byte
#define ADC0EIF_LDOK_EIF                _ADC0EIF.Bits.LDOK_EIF
#define ADC0EIF_RSTAR_EIF               _ADC0EIF.Bits.RSTAR_EIF
#define ADC0EIF_TRIG_EIF                _ADC0EIF.Bits.TRIG_EIF
#define ADC0EIF_EOL_EIF                 _ADC0EIF.Bits.EOL_EIF
#define ADC0EIF_CMD_EIF                 _ADC0EIF.Bits.CMD_EIF
#define ADC0EIF_IA_EIF                  _ADC0EIF.Bits.IA_EIF

#define ADC0EIF_LDOK_EIF_MASK           2U
#define ADC0EIF_RSTAR_EIF_MASK          4U
#define ADC0EIF_TRIG_EIF_MASK           8U
#define ADC0EIF_EOL_EIF_MASK            32U
#define ADC0EIF_CMD_EIF_MASK            64U
#define ADC0EIF_IA_EIF_MASK             128U


/*** ADC0IF - ADC0 Interrupt Flag Register; 0x00000609 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CONIF_OIF   :1;                                       /* ADCxCONIF Register Flags Overrun Interrupt Flag */
    byte SEQAD_IF    :1;                                       /* Conversion Sequence Abort Done Interrupt Flag */
  } Bits;
} ADC0IFSTR;
extern volatile ADC0IFSTR _ADC0IF @0x00000609;
#define ADC0IF                          _ADC0IF.Byte
#define ADC0IF_CONIF_OIF                _ADC0IF.Bits.CONIF_OIF
#define ADC0IF_SEQAD_IF                 _ADC0IF.Bits.SEQAD_IF

#define ADC0IF_CONIF_OIF_MASK           64U
#define ADC0IF_SEQAD_IF_MASK            128U


/*** ADC0CONIE - ADC0 Conversion Interrupt Enable Register; 0x0000060A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC0CONIE_0 - ADC0 Conversion Interrupt Enable Register 0; 0x0000060A ***/
    union {
      byte Byte;
      struct {
        byte CON_IE8     :1;                                       /* Conversion Interrupt 8 Enable */
        byte CON_IE9     :1;                                       /* Conversion Interrupt 9 Enable */
        byte CON_IE10    :1;                                       /* Conversion Interrupt 10 Enable */
        byte CON_IE11    :1;                                       /* Conversion Interrupt 11 Enable */
        byte CON_IE12    :1;                                       /* Conversion Interrupt 12 Enable */
        byte CON_IE13    :1;                                       /* Conversion Interrupt 13 Enable */
        byte CON_IE14    :1;                                       /* Conversion Interrupt 14 Enable */
        byte CON_IE15    :1;                                       /* Conversion Interrupt 15 Enable */
      } Bits;
    } ADC0CONIE_0STR;
    #define ADC0CONIE_0                 _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Byte
    #define ADC0CONIE_0_CON_IE8         _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Bits.CON_IE8
    #define ADC0CONIE_0_CON_IE9         _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Bits.CON_IE9
    #define ADC0CONIE_0_CON_IE10        _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Bits.CON_IE10
    #define ADC0CONIE_0_CON_IE11        _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Bits.CON_IE11
    #define ADC0CONIE_0_CON_IE12        _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Bits.CON_IE12
    #define ADC0CONIE_0_CON_IE13        _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Bits.CON_IE13
    #define ADC0CONIE_0_CON_IE14        _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Bits.CON_IE14
    #define ADC0CONIE_0_CON_IE15        _ADC0CONIE.Overlap_STR.ADC0CONIE_0STR.Bits.CON_IE15
    /* ADC0CONIE__ARR: Access 2 ADC0CONIE_x registers in an array */
    #define ADC0CONIE__ARR              ((volatile byte *) &ADC0CONIE_0)
    
    #define ADC0CONIE_0_CON_IE8_MASK    1U
    #define ADC0CONIE_0_CON_IE9_MASK    2U
    #define ADC0CONIE_0_CON_IE10_MASK   4U
    #define ADC0CONIE_0_CON_IE11_MASK   8U
    #define ADC0CONIE_0_CON_IE12_MASK   16U
    #define ADC0CONIE_0_CON_IE13_MASK   32U
    #define ADC0CONIE_0_CON_IE14_MASK   64U
    #define ADC0CONIE_0_CON_IE15_MASK   128U
    

    /*** ADC0CONIE_1 - ADC0 Conversion Interrupt Enable Register 1; 0x0000060B ***/
    union {
      byte Byte;
      struct {
        byte EOL_IE      :1;                                       /* End Of List Interrupt Enable */
        byte CON_IE1     :1;                                       /* Conversion Interrupt 1 Enable */
        byte CON_IE2     :1;                                       /* Conversion Interrupt 2 Enable */
        byte CON_IE3     :1;                                       /* Conversion Interrupt 3 Enable */
        byte CON_IE4     :1;                                       /* Conversion Interrupt 4 Enable */
        byte CON_IE5     :1;                                       /* Conversion Interrupt 5 Enable */
        byte CON_IE6     :1;                                       /* Conversion Interrupt 6 Enable */
        byte CON_IE7     :1;                                       /* Conversion Interrupt 7 Enable */
      } Bits;
      struct {
        byte     :1;
        byte grpCON_IE_1 :7;
      } MergedBits;
    } ADC0CONIE_1STR;
    #define ADC0CONIE_1                 _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Byte
    #define ADC0CONIE_1_EOL_IE          _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Bits.EOL_IE
    #define ADC0CONIE_1_CON_IE1         _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Bits.CON_IE1
    #define ADC0CONIE_1_CON_IE2         _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Bits.CON_IE2
    #define ADC0CONIE_1_CON_IE3         _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Bits.CON_IE3
    #define ADC0CONIE_1_CON_IE4         _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Bits.CON_IE4
    #define ADC0CONIE_1_CON_IE5         _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Bits.CON_IE5
    #define ADC0CONIE_1_CON_IE6         _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Bits.CON_IE6
    #define ADC0CONIE_1_CON_IE7         _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.Bits.CON_IE7
    #define ADC0CONIE_1_CON_IE_1        _ADC0CONIE.Overlap_STR.ADC0CONIE_1STR.MergedBits.grpCON_IE_1
    #define ADC0CONIE_1_CON_IE          ADC0CONIE_1_CON_IE_1
    
    #define ADC0CONIE_1_EOL_IE_MASK     1U
    #define ADC0CONIE_1_CON_IE1_MASK    2U
    #define ADC0CONIE_1_CON_IE2_MASK    4U
    #define ADC0CONIE_1_CON_IE3_MASK    8U
    #define ADC0CONIE_1_CON_IE4_MASK    16U
    #define ADC0CONIE_1_CON_IE5_MASK    32U
    #define ADC0CONIE_1_CON_IE6_MASK    64U
    #define ADC0CONIE_1_CON_IE7_MASK    128U
    #define ADC0CONIE_1_CON_IE_1_MASK   254U
    #define ADC0CONIE_1_CON_IE_1_BITNUM 1U
    
  } Overlap_STR;

  struct {
    word EOL_IE      :1;                                       /* End Of List Interrupt Enable */
    word CON_IE1     :1;                                       /* Conversion Interrupt 1 Enable */
    word CON_IE2     :1;                                       /* Conversion Interrupt 2 Enable */
    word CON_IE3     :1;                                       /* Conversion Interrupt 3 Enable */
    word CON_IE4     :1;                                       /* Conversion Interrupt 4 Enable */
    word CON_IE5     :1;                                       /* Conversion Interrupt 5 Enable */
    word CON_IE6     :1;                                       /* Conversion Interrupt 6 Enable */
    word CON_IE7     :1;                                       /* Conversion Interrupt 7 Enable */
    word CON_IE8     :1;                                       /* Conversion Interrupt 8 Enable */
    word CON_IE9     :1;                                       /* Conversion Interrupt 9 Enable */
    word CON_IE10    :1;                                       /* Conversion Interrupt 10 Enable */
    word CON_IE11    :1;                                       /* Conversion Interrupt 11 Enable */
    word CON_IE12    :1;                                       /* Conversion Interrupt 12 Enable */
    word CON_IE13    :1;                                       /* Conversion Interrupt 13 Enable */
    word CON_IE14    :1;                                       /* Conversion Interrupt 14 Enable */
    word CON_IE15    :1;                                       /* Conversion Interrupt 15 Enable */
  } Bits;
  struct {
    word         :1;
    word grpCON_IE_1 :15;
  } MergedBits;
} ADC0CONIESTR;
extern volatile ADC0CONIESTR _ADC0CONIE @0x0000060A;
#define ADC0CONIE                       _ADC0CONIE.Word
#define ADC0CONIE_EOL_IE                _ADC0CONIE.Bits.EOL_IE
#define ADC0CONIE_CON_IE1               _ADC0CONIE.Bits.CON_IE1
#define ADC0CONIE_CON_IE2               _ADC0CONIE.Bits.CON_IE2
#define ADC0CONIE_CON_IE3               _ADC0CONIE.Bits.CON_IE3
#define ADC0CONIE_CON_IE4               _ADC0CONIE.Bits.CON_IE4
#define ADC0CONIE_CON_IE5               _ADC0CONIE.Bits.CON_IE5
#define ADC0CONIE_CON_IE6               _ADC0CONIE.Bits.CON_IE6
#define ADC0CONIE_CON_IE7               _ADC0CONIE.Bits.CON_IE7
#define ADC0CONIE_CON_IE8               _ADC0CONIE.Bits.CON_IE8
#define ADC0CONIE_CON_IE9               _ADC0CONIE.Bits.CON_IE9
#define ADC0CONIE_CON_IE10              _ADC0CONIE.Bits.CON_IE10
#define ADC0CONIE_CON_IE11              _ADC0CONIE.Bits.CON_IE11
#define ADC0CONIE_CON_IE12              _ADC0CONIE.Bits.CON_IE12
#define ADC0CONIE_CON_IE13              _ADC0CONIE.Bits.CON_IE13
#define ADC0CONIE_CON_IE14              _ADC0CONIE.Bits.CON_IE14
#define ADC0CONIE_CON_IE15              _ADC0CONIE.Bits.CON_IE15
#define ADC0CONIE_CON_IE_1              _ADC0CONIE.MergedBits.grpCON_IE_1
#define ADC0CONIE_CON_IE                ADC0CONIE_CON_IE_1

#define ADC0CONIE_EOL_IE_MASK           1U
#define ADC0CONIE_CON_IE1_MASK          2U
#define ADC0CONIE_CON_IE2_MASK          4U
#define ADC0CONIE_CON_IE3_MASK          8U
#define ADC0CONIE_CON_IE4_MASK          16U
#define ADC0CONIE_CON_IE5_MASK          32U
#define ADC0CONIE_CON_IE6_MASK          64U
#define ADC0CONIE_CON_IE7_MASK          128U
#define ADC0CONIE_CON_IE8_MASK          256U
#define ADC0CONIE_CON_IE9_MASK          512U
#define ADC0CONIE_CON_IE10_MASK         1024U
#define ADC0CONIE_CON_IE11_MASK         2048U
#define ADC0CONIE_CON_IE12_MASK         4096U
#define ADC0CONIE_CON_IE13_MASK         8192U
#define ADC0CONIE_CON_IE14_MASK         16384U
#define ADC0CONIE_CON_IE15_MASK         32768U
#define ADC0CONIE_CON_IE_1_MASK         65534U
#define ADC0CONIE_CON_IE_1_BITNUM       1U


/*** ADC0CONIF - ADC0 Conversion Interrupt Flag Register; 0x0000060C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC0CONIF_0 - ADC0 Conversion Interrupt Flag Register 0; 0x0000060C ***/
    union {
      byte Byte;
      struct {
        byte CON_IF8     :1;                                       /* Conversion Interrupt 8 Flag */
        byte CON_IF9     :1;                                       /* Conversion Interrupt 9 Flag */
        byte CON_IF10    :1;                                       /* Conversion Interrupt 10 Flag */
        byte CON_IF11    :1;                                       /* Conversion Interrupt 11 Flag */
        byte CON_IF12    :1;                                       /* Conversion Interrupt 12 Flag */
        byte CON_IF13    :1;                                       /* Conversion Interrupt 13 Flag */
        byte CON_IF14    :1;                                       /* Conversion Interrupt 14 Flag */
        byte CON_IF15    :1;                                       /* Conversion Interrupt 15 Flag */
      } Bits;
    } ADC0CONIF_0STR;
    #define ADC0CONIF_0                 _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Byte
    #define ADC0CONIF_0_CON_IF8         _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Bits.CON_IF8
    #define ADC0CONIF_0_CON_IF9         _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Bits.CON_IF9
    #define ADC0CONIF_0_CON_IF10        _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Bits.CON_IF10
    #define ADC0CONIF_0_CON_IF11        _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Bits.CON_IF11
    #define ADC0CONIF_0_CON_IF12        _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Bits.CON_IF12
    #define ADC0CONIF_0_CON_IF13        _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Bits.CON_IF13
    #define ADC0CONIF_0_CON_IF14        _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Bits.CON_IF14
    #define ADC0CONIF_0_CON_IF15        _ADC0CONIF.Overlap_STR.ADC0CONIF_0STR.Bits.CON_IF15
    /* ADC0CONIF__ARR: Access 2 ADC0CONIF_x registers in an array */
    #define ADC0CONIF__ARR              ((volatile byte *) &ADC0CONIF_0)
    
    #define ADC0CONIF_0_CON_IF8_MASK    1U
    #define ADC0CONIF_0_CON_IF9_MASK    2U
    #define ADC0CONIF_0_CON_IF10_MASK   4U
    #define ADC0CONIF_0_CON_IF11_MASK   8U
    #define ADC0CONIF_0_CON_IF12_MASK   16U
    #define ADC0CONIF_0_CON_IF13_MASK   32U
    #define ADC0CONIF_0_CON_IF14_MASK   64U
    #define ADC0CONIF_0_CON_IF15_MASK   128U
    

    /*** ADC0CONIF_1 - ADC0 Conversion Interrupt Flag Register 1; 0x0000060D ***/
    union {
      byte Byte;
      struct {
        byte EOL_IF      :1;                                       /* End Of List Interrupt Flag */
        byte CON_IF1     :1;                                       /* Conversion Interrupt 1 Flag */
        byte CON_IF2     :1;                                       /* Conversion Interrupt 2 Flag */
        byte CON_IF3     :1;                                       /* Conversion Interrupt 3 Flag */
        byte CON_IF4     :1;                                       /* Conversion Interrupt 4 Flag */
        byte CON_IF5     :1;                                       /* Conversion Interrupt 5 Flag */
        byte CON_IF6     :1;                                       /* Conversion Interrupt 6 Flag */
        byte CON_IF7     :1;                                       /* Conversion Interrupt 7 Flag */
      } Bits;
      struct {
        byte     :1;
        byte grpCON_IF_1 :7;
      } MergedBits;
    } ADC0CONIF_1STR;
    #define ADC0CONIF_1                 _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Byte
    #define ADC0CONIF_1_EOL_IF          _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Bits.EOL_IF
    #define ADC0CONIF_1_CON_IF1         _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Bits.CON_IF1
    #define ADC0CONIF_1_CON_IF2         _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Bits.CON_IF2
    #define ADC0CONIF_1_CON_IF3         _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Bits.CON_IF3
    #define ADC0CONIF_1_CON_IF4         _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Bits.CON_IF4
    #define ADC0CONIF_1_CON_IF5         _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Bits.CON_IF5
    #define ADC0CONIF_1_CON_IF6         _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Bits.CON_IF6
    #define ADC0CONIF_1_CON_IF7         _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.Bits.CON_IF7
    #define ADC0CONIF_1_CON_IF_1        _ADC0CONIF.Overlap_STR.ADC0CONIF_1STR.MergedBits.grpCON_IF_1
    #define ADC0CONIF_1_CON_IF          ADC0CONIF_1_CON_IF_1
    
    #define ADC0CONIF_1_EOL_IF_MASK     1U
    #define ADC0CONIF_1_CON_IF1_MASK    2U
    #define ADC0CONIF_1_CON_IF2_MASK    4U
    #define ADC0CONIF_1_CON_IF3_MASK    8U
    #define ADC0CONIF_1_CON_IF4_MASK    16U
    #define ADC0CONIF_1_CON_IF5_MASK    32U
    #define ADC0CONIF_1_CON_IF6_MASK    64U
    #define ADC0CONIF_1_CON_IF7_MASK    128U
    #define ADC0CONIF_1_CON_IF_1_MASK   254U
    #define ADC0CONIF_1_CON_IF_1_BITNUM 1U
    
  } Overlap_STR;

  struct {
    word EOL_IF      :1;                                       /* End Of List Interrupt Flag */
    word CON_IF1     :1;                                       /* Conversion Interrupt 1 Flag */
    word CON_IF2     :1;                                       /* Conversion Interrupt 2 Flag */
    word CON_IF3     :1;                                       /* Conversion Interrupt 3 Flag */
    word CON_IF4     :1;                                       /* Conversion Interrupt 4 Flag */
    word CON_IF5     :1;                                       /* Conversion Interrupt 5 Flag */
    word CON_IF6     :1;                                       /* Conversion Interrupt 6 Flag */
    word CON_IF7     :1;                                       /* Conversion Interrupt 7 Flag */
    word CON_IF8     :1;                                       /* Conversion Interrupt 8 Flag */
    word CON_IF9     :1;                                       /* Conversion Interrupt 9 Flag */
    word CON_IF10    :1;                                       /* Conversion Interrupt 10 Flag */
    word CON_IF11    :1;                                       /* Conversion Interrupt 11 Flag */
    word CON_IF12    :1;                                       /* Conversion Interrupt 12 Flag */
    word CON_IF13    :1;                                       /* Conversion Interrupt 13 Flag */
    word CON_IF14    :1;                                       /* Conversion Interrupt 14 Flag */
    word CON_IF15    :1;                                       /* Conversion Interrupt 15 Flag */
  } Bits;
  struct {
    word         :1;
    word grpCON_IF_1 :15;
  } MergedBits;
} ADC0CONIFSTR;
extern volatile ADC0CONIFSTR _ADC0CONIF @0x0000060C;
#define ADC0CONIF                       _ADC0CONIF.Word
#define ADC0CONIF_EOL_IF                _ADC0CONIF.Bits.EOL_IF
#define ADC0CONIF_CON_IF1               _ADC0CONIF.Bits.CON_IF1
#define ADC0CONIF_CON_IF2               _ADC0CONIF.Bits.CON_IF2
#define ADC0CONIF_CON_IF3               _ADC0CONIF.Bits.CON_IF3
#define ADC0CONIF_CON_IF4               _ADC0CONIF.Bits.CON_IF4
#define ADC0CONIF_CON_IF5               _ADC0CONIF.Bits.CON_IF5
#define ADC0CONIF_CON_IF6               _ADC0CONIF.Bits.CON_IF6
#define ADC0CONIF_CON_IF7               _ADC0CONIF.Bits.CON_IF7
#define ADC0CONIF_CON_IF8               _ADC0CONIF.Bits.CON_IF8
#define ADC0CONIF_CON_IF9               _ADC0CONIF.Bits.CON_IF9
#define ADC0CONIF_CON_IF10              _ADC0CONIF.Bits.CON_IF10
#define ADC0CONIF_CON_IF11              _ADC0CONIF.Bits.CON_IF11
#define ADC0CONIF_CON_IF12              _ADC0CONIF.Bits.CON_IF12
#define ADC0CONIF_CON_IF13              _ADC0CONIF.Bits.CON_IF13
#define ADC0CONIF_CON_IF14              _ADC0CONIF.Bits.CON_IF14
#define ADC0CONIF_CON_IF15              _ADC0CONIF.Bits.CON_IF15
#define ADC0CONIF_CON_IF_1              _ADC0CONIF.MergedBits.grpCON_IF_1
#define ADC0CONIF_CON_IF                ADC0CONIF_CON_IF_1

#define ADC0CONIF_EOL_IF_MASK           1U
#define ADC0CONIF_CON_IF1_MASK          2U
#define ADC0CONIF_CON_IF2_MASK          4U
#define ADC0CONIF_CON_IF3_MASK          8U
#define ADC0CONIF_CON_IF4_MASK          16U
#define ADC0CONIF_CON_IF5_MASK          32U
#define ADC0CONIF_CON_IF6_MASK          64U
#define ADC0CONIF_CON_IF7_MASK          128U
#define ADC0CONIF_CON_IF8_MASK          256U
#define ADC0CONIF_CON_IF9_MASK          512U
#define ADC0CONIF_CON_IF10_MASK         1024U
#define ADC0CONIF_CON_IF11_MASK         2048U
#define ADC0CONIF_CON_IF12_MASK         4096U
#define ADC0CONIF_CON_IF13_MASK         8192U
#define ADC0CONIF_CON_IF14_MASK         16384U
#define ADC0CONIF_CON_IF15_MASK         32768U
#define ADC0CONIF_CON_IF_1_MASK         65534U
#define ADC0CONIF_CON_IF_1_BITNUM       1U


/*** ADC0IMDRI - ADC0 Intermediate Result Information Register; 0x0000060E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC0IMDRI_0 - ADC0 Intermediate Result Information Register 0; 0x0000060E ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte RVL_IMD     :1;                                       /* Active RVL At Intermediate Event */
        byte CSL_IMD     :1;                                       /* Active CSL At Intermediate Event */
      } Bits;
    } ADC0IMDRI_0STR;
    #define ADC0IMDRI_0                 _ADC0IMDRI.Overlap_STR.ADC0IMDRI_0STR.Byte
    #define ADC0IMDRI_0_RVL_IMD         _ADC0IMDRI.Overlap_STR.ADC0IMDRI_0STR.Bits.RVL_IMD
    #define ADC0IMDRI_0_CSL_IMD         _ADC0IMDRI.Overlap_STR.ADC0IMDRI_0STR.Bits.CSL_IMD
    /* ADC0IMDRI__ARR: Access 2 ADC0IMDRI_x registers in an array */
    #define ADC0IMDRI__ARR              ((volatile byte *) &ADC0IMDRI_0)
    
    #define ADC0IMDRI_0_RVL_IMD_MASK    64U
    #define ADC0IMDRI_0_CSL_IMD_MASK    128U
    

    /*** ADC0IMDRI_1 - ADC0 Intermediate Result Information Register 1; 0x0000060F ***/
    union {
      byte Byte;
      struct {
        byte RIDX_IMD    :6;                                       /* RES_IDX Value At Intermediate Event */
        byte             :1; 
        byte             :1; 
      } Bits;
    } ADC0IMDRI_1STR;
    #define ADC0IMDRI_1                 _ADC0IMDRI.Overlap_STR.ADC0IMDRI_1STR.Byte
    #define ADC0IMDRI_1_RIDX_IMD        _ADC0IMDRI.Overlap_STR.ADC0IMDRI_1STR.Bits.RIDX_IMD
    
    #define ADC0IMDRI_1_RIDX_IMD_MASK   63U
    #define ADC0IMDRI_1_RIDX_IMD_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word RIDX_IMD    :6;                                       /* RES_IDX Value At Intermediate Event */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word RVL_IMD     :1;                                       /* Active RVL At Intermediate Event */
    word CSL_IMD     :1;                                       /* Active CSL At Intermediate Event */
  } Bits;
} ADC0IMDRISTR;
extern volatile ADC0IMDRISTR _ADC0IMDRI @0x0000060E;
#define ADC0IMDRI                       _ADC0IMDRI.Word
#define ADC0IMDRI_RIDX_IMD              _ADC0IMDRI.Bits.RIDX_IMD
#define ADC0IMDRI_RVL_IMD               _ADC0IMDRI.Bits.RVL_IMD
#define ADC0IMDRI_CSL_IMD               _ADC0IMDRI.Bits.CSL_IMD

#define ADC0IMDRI_RIDX_IMD_MASK         63U
#define ADC0IMDRI_RIDX_IMD_BITNUM       0U
#define ADC0IMDRI_RVL_IMD_MASK          16384U
#define ADC0IMDRI_CSL_IMD_MASK          32768U


/*** ADC0EOLRI - ADC0 End Of List Result Information Register; 0x00000610 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RVL_EOL     :1;                                       /* Active RVL When End Of List Command Type Was Executed */
    byte CSL_EOL     :1;                                       /* Active CSL When End Of List Command Type Was Executed */
  } Bits;
} ADC0EOLRISTR;
extern volatile ADC0EOLRISTR _ADC0EOLRI @0x00000610;
#define ADC0EOLRI                       _ADC0EOLRI.Byte
#define ADC0EOLRI_RVL_EOL               _ADC0EOLRI.Bits.RVL_EOL
#define ADC0EOLRI_CSL_EOL               _ADC0EOLRI.Bits.CSL_EOL

#define ADC0EOLRI_RVL_EOL_MASK          64U
#define ADC0EOLRI_CSL_EOL_MASK          128U


/*** ADC0CMD - ADC0 Command Register; 0x00000614 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** ADC0CMD_01 - ADC0 Command Register 01; 0x00000614 ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** ADC0CMD_0 - ADC0 Command Register 0; 0x00000614 ***/
        union {
          byte Byte;
          struct {
            byte INTFLG_SEL  :4;                                       /* Conversion Interrupt Flag Select */
            byte             :1; 
            byte             :1; 
            byte CMD_SEL     :2;                                       /* Conversion Command Select */
          } Bits;
        } ADC0CMD_0STR;
        #define ADC0CMD_0               _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Overlap_STR.ADC0CMD_0STR.Byte
        #define ADC0CMD_0_INTFLG_SEL    _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Overlap_STR.ADC0CMD_0STR.Bits.INTFLG_SEL
        #define ADC0CMD_0_CMD_SEL       _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Overlap_STR.ADC0CMD_0STR.Bits.CMD_SEL
        /* ADC0CMD__ARR: Access 4 ADC0CMD_x registers in an array */
        #define ADC0CMD__ARR            ((volatile byte *) &ADC0CMD_0)
        
        #define ADC0CMD_0_INTFLG_SEL_MASK 15U
        #define ADC0CMD_0_INTFLG_SEL_BITNUM 0U
        #define ADC0CMD_0_CMD_SEL_MASK  192U
        #define ADC0CMD_0_CMD_SEL_BITNUM 6U
        
    
        /*** ADC0CMD_1 - ADC0 Command Register 1; 0x00000615 ***/
        union {
          byte Byte;
          struct {
            byte CH_SEL      :6;                                       /* ADC Input Channel Select */
            byte VRL_SEL     :1;                                       /* Reference Low Voltage Select */
            byte VRH_SEL     :1;                                       /* Reference High Voltage Select */
          } Bits;
        } ADC0CMD_1STR;
        #define ADC0CMD_1               _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Overlap_STR.ADC0CMD_1STR.Byte
        #define ADC0CMD_1_CH_SEL        _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Overlap_STR.ADC0CMD_1STR.Bits.CH_SEL
        #define ADC0CMD_1_VRL_SEL       _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Overlap_STR.ADC0CMD_1STR.Bits.VRL_SEL
        #define ADC0CMD_1_VRH_SEL       _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Overlap_STR.ADC0CMD_1STR.Bits.VRH_SEL
        
        #define ADC0CMD_1_CH_SEL_MASK   63U
        #define ADC0CMD_1_CH_SEL_BITNUM 0U
        #define ADC0CMD_1_VRL_SEL_MASK  64U
        #define ADC0CMD_1_VRH_SEL_MASK  128U
        
      } Overlap_STR;
    
      struct {
        word CH_SEL      :6;                                       /* ADC Input Channel Select */
        word VRL_SEL     :1;                                       /* Reference Low Voltage Select */
        word VRH_SEL     :1;                                       /* Reference High Voltage Select */
        word INTFLG_SEL  :4;                                       /* Conversion Interrupt Flag Select */
        word             :1; 
        word             :1; 
        word CMD_SEL     :2;                                       /* Conversion Command Select */
      } Bits;
    } ADC0CMD_01STR;
    #define ADC0CMD_01                  _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Word
    #define ADC0CMD_01_CH_SEL           _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Bits.CH_SEL
    #define ADC0CMD_01_VRL_SEL          _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Bits.VRL_SEL
    #define ADC0CMD_01_VRH_SEL          _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Bits.VRH_SEL
    #define ADC0CMD_01_INTFLG_SEL       _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Bits.INTFLG_SEL
    #define ADC0CMD_01_CMD_SEL          _ADC0CMD.Overlap_STR.ADC0CMD_01STR.Bits.CMD_SEL
    
    #define ADC0CMD_01_CH_SEL_MASK      63U
    #define ADC0CMD_01_CH_SEL_BITNUM    0U
    #define ADC0CMD_01_VRL_SEL_MASK     64U
    #define ADC0CMD_01_VRH_SEL_MASK     128U
    #define ADC0CMD_01_INTFLG_SEL_MASK  3840U
    #define ADC0CMD_01_INTFLG_SEL_BITNUM 8U
    #define ADC0CMD_01_CMD_SEL_MASK     49152U
    #define ADC0CMD_01_CMD_SEL_BITNUM   14U
    

    /*** ADC0CMD_23 - ADC0 Command Register 23; 0x00000616 ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** ADC0CMD_2 - ADC0 Command Register 2; 0x00000616 ***/
        union {
          byte Byte;
          struct {
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte SMP         :5;                                       /* Sample Time Select */
          } Bits;
        } ADC0CMD_2STR;
        #define ADC0CMD_2               _ADC0CMD.Overlap_STR.ADC0CMD_23STR.Overlap_STR.ADC0CMD_2STR.Byte
        #define ADC0CMD_2_SMP           _ADC0CMD.Overlap_STR.ADC0CMD_23STR.Overlap_STR.ADC0CMD_2STR.Bits.SMP
        
        #define ADC0CMD_2_SMP_MASK      248U
        #define ADC0CMD_2_SMP_BITNUM    3U
        
    
        /*** ADC0CMD_3 - ADC0 Command Register 3; 0x00000617 ***/
        union {
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
        } ADC0CMD_3STR;
        #define ADC0CMD_3               _ADC0CMD.Overlap_STR.ADC0CMD_23STR.Overlap_STR.ADC0CMD_3STR.Byte
        
      } Overlap_STR;
    
      struct {
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word SMP         :5;                                       /* Sample Time Select */
      } Bits;
    } ADC0CMD_23STR;
    #define ADC0CMD_23                  _ADC0CMD.Overlap_STR.ADC0CMD_23STR.Word
    #define ADC0CMD_23_SMP              _ADC0CMD.Overlap_STR.ADC0CMD_23STR.Bits.SMP
    
    #define ADC0CMD_23_SMP_MASK         63488U
    #define ADC0CMD_23_SMP_BITNUM       11U
    
  } Overlap_STR;

} ADC0CMDSTR;
extern volatile ADC0CMDSTR _ADC0CMD @0x00000614;
#define ADC0CMD                         _ADC0CMD.Dword


/*** ADC0CIDX - ADC0 Command Index Register; 0x0000061C ***/
typedef union {
  byte Byte;
  struct {
    byte CMD_IDX     :6;                                       /* ADC Command Index */
    byte             :1; 
    byte             :1; 
  } Bits;
} ADC0CIDXSTR;
extern volatile ADC0CIDXSTR _ADC0CIDX @0x0000061C;
#define ADC0CIDX                        _ADC0CIDX.Byte
#define ADC0CIDX_CMD_IDX                _ADC0CIDX.Bits.CMD_IDX

#define ADC0CIDX_CMD_IDX_MASK           63U
#define ADC0CIDX_CMD_IDX_BITNUM         0U


/*** ADC0CBP_0 - ADC0 Command Base Pointer Register 0; 0x0000061D ***/
typedef union {
  byte Byte;
  struct {
    byte CMD_PTR     :8;                                       /* ADC Command Base Pointer Address */
  } Bits;
} ADC0CBP_0STR;
extern volatile ADC0CBP_0STR _ADC0CBP_0 @0x0000061D;
#define ADC0CBP_0                       _ADC0CBP_0.Byte
#define ADC0CBP_0_CMD_PTR               _ADC0CBP_0.Bits.CMD_PTR
/* ADC0CBP__ARR: Access 3 ADC0CBP_x registers in an array */
#define ADC0CBP__ARR                    ((volatile byte *) &ADC0CBP_0)

#define ADC0CBP_0_CMD_PTR_MASK          255U
#define ADC0CBP_0_CMD_PTR_BITNUM        0U


/*** ADC0CBP_1 - ADC0 Command Base Pointer Register 1; 0x0000061E ***/
typedef union {
  byte Byte;
  struct {
    byte CMD_PTR     :8;                                       /* ADC Command Base Pointer Address */
  } Bits;
} ADC0CBP_1STR;
extern volatile ADC0CBP_1STR _ADC0CBP_1 @0x0000061E;
#define ADC0CBP_1                       _ADC0CBP_1.Byte
#define ADC0CBP_1_CMD_PTR               _ADC0CBP_1.Bits.CMD_PTR

#define ADC0CBP_1_CMD_PTR_MASK          255U
#define ADC0CBP_1_CMD_PTR_BITNUM        0U


/*** ADC0CBP_2 - ADC0 Command Base Pointer Register 2; 0x0000061F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte CMD_PTR     :6;                                       /* ADC Command Base Pointer Address */
  } Bits;
} ADC0CBP_2STR;
extern volatile ADC0CBP_2STR _ADC0CBP_2 @0x0000061F;
#define ADC0CBP_2                       _ADC0CBP_2.Byte
#define ADC0CBP_2_CMD_PTR               _ADC0CBP_2.Bits.CMD_PTR

#define ADC0CBP_2_CMD_PTR_MASK          252U
#define ADC0CBP_2_CMD_PTR_BITNUM        2U


/*** ADC0RIDX - ADC0 Result Index Register; 0x00000620 ***/
typedef union {
  byte Byte;
  struct {
    byte RES_IDX     :6;                                       /* ADC Result Index */
    byte             :1; 
    byte             :1; 
  } Bits;
} ADC0RIDXSTR;
extern volatile ADC0RIDXSTR _ADC0RIDX @0x00000620;
#define ADC0RIDX                        _ADC0RIDX.Byte
#define ADC0RIDX_RES_IDX                _ADC0RIDX.Bits.RES_IDX

#define ADC0RIDX_RES_IDX_MASK           63U
#define ADC0RIDX_RES_IDX_BITNUM         0U


/*** ADC0RBP_0 - ADC0 Result Base Pointer Register 0; 0x00000621 ***/
typedef union {
  byte Byte;
  struct {
    byte RES_PTR     :4;                                       /* ADC Result Base Pointer Address */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ADC0RBP_0STR;
extern volatile ADC0RBP_0STR _ADC0RBP_0 @0x00000621;
#define ADC0RBP_0                       _ADC0RBP_0.Byte
#define ADC0RBP_0_RES_PTR               _ADC0RBP_0.Bits.RES_PTR
/* ADC0RBP__ARR: Access 3 ADC0RBP_x registers in an array */
#define ADC0RBP__ARR                    ((volatile byte *) &ADC0RBP_0)

#define ADC0RBP_0_RES_PTR_MASK          15U
#define ADC0RBP_0_RES_PTR_BITNUM        0U


/*** ADC0RBP_1 - ADC0 Result Base Pointer Register 1; 0x00000622 ***/
typedef union {
  byte Byte;
  struct {
    byte RES_PTR     :8;                                       /* ADC Result Base Pointer Address */
  } Bits;
} ADC0RBP_1STR;
extern volatile ADC0RBP_1STR _ADC0RBP_1 @0x00000622;
#define ADC0RBP_1                       _ADC0RBP_1.Byte
#define ADC0RBP_1_RES_PTR               _ADC0RBP_1.Bits.RES_PTR

#define ADC0RBP_1_RES_PTR_MASK          255U
#define ADC0RBP_1_RES_PTR_BITNUM        0U


/*** ADC0RBP_2 - ADC0 Result Base Pointer Register 2; 0x00000623 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte RES_PTR     :6;                                       /* ADC Result Base Pointer Address */
  } Bits;
} ADC0RBP_2STR;
extern volatile ADC0RBP_2STR _ADC0RBP_2 @0x00000623;
#define ADC0RBP_2                       _ADC0RBP_2.Byte
#define ADC0RBP_2_RES_PTR               _ADC0RBP_2.Bits.RES_PTR

#define ADC0RBP_2_RES_PTR_MASK          252U
#define ADC0RBP_2_RES_PTR_BITNUM        2U


/*** ADC0CROFF0 - ADC0 Command and Result Offset Register 0; 0x00000624 ***/
typedef union {
  byte Byte;
  struct {
    byte CMDRES_OFF0 :7;                                       /* ADC Command and Result Offset Value refer to CSL_0 and RVL_0 */
    byte             :1; 
  } Bits;
} ADC0CROFF0STR;
extern volatile ADC0CROFF0STR _ADC0CROFF0 @0x00000624;
#define ADC0CROFF0                      _ADC0CROFF0.Byte
#define ADC0CROFF0_CMDRES_OFF0          _ADC0CROFF0.Bits.CMDRES_OFF0
/* ADC0CROFF_ARR: Access 2 ADC0CROFFx registers in an array */
#define ADC0CROFF_ARR                   ((volatile byte *) &ADC0CROFF0)

#define ADC0CROFF0_CMDRES_OFF0_MASK     127U
#define ADC0CROFF0_CMDRES_OFF0_BITNUM   0U


/*** ADC0CROFF1 - ADC0 Command and Result Offset Register 1; 0x00000625 ***/
typedef union {
  byte Byte;
  struct {
    byte CMDRES_OFF1 :7;                                       /* ADC Command and Result Offset Value refer to CSL_1 and RVL_1 */
    byte             :1; 
  } Bits;
} ADC0CROFF1STR;
extern volatile ADC0CROFF1STR _ADC0CROFF1 @0x00000625;
#define ADC0CROFF1                      _ADC0CROFF1.Byte
#define ADC0CROFF1_CMDRES_OFF1          _ADC0CROFF1.Bits.CMDRES_OFF1

#define ADC0CROFF1_CMDRES_OFF1_MASK     127U
#define ADC0CROFF1_CMDRES_OFF1_BITNUM   0U


/*** ADC1CTL - ADC1 Control Register; 0x00000640 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC1CTL_0 - ADC1 Control Register 0; 0x00000640 ***/
    union {
      byte Byte;
      struct {
        byte MOD_CFG     :1;                                       /* Trigger Mode Configuration */
        byte STR_SEQA    :1;                                       /* Handling Restart Requests during End Of List Command Type Execution */
        byte ACC_CFG     :2;                                       /* ADCFLWCTL Register Access Configuration */
        byte SWAI        :1;                                       /* Wait Mode Configuration */
        byte FRZ_MOD     :1;                                       /* Freeze Mode Configuration */
        byte ADC_SR      :1;                                       /* ADC Soft Reset */
        byte ADC_EN      :1;                                       /* ADC Enable Bit */
      } Bits;
    } ADC1CTL_0STR;
    #define ADC1CTL_0                   _ADC1CTL.Overlap_STR.ADC1CTL_0STR.Byte
    #define ADC1CTL_0_MOD_CFG           _ADC1CTL.Overlap_STR.ADC1CTL_0STR.Bits.MOD_CFG
    #define ADC1CTL_0_STR_SEQA          _ADC1CTL.Overlap_STR.ADC1CTL_0STR.Bits.STR_SEQA
    #define ADC1CTL_0_ACC_CFG           _ADC1CTL.Overlap_STR.ADC1CTL_0STR.Bits.ACC_CFG
    #define ADC1CTL_0_SWAI              _ADC1CTL.Overlap_STR.ADC1CTL_0STR.Bits.SWAI
    #define ADC1CTL_0_FRZ_MOD           _ADC1CTL.Overlap_STR.ADC1CTL_0STR.Bits.FRZ_MOD
    #define ADC1CTL_0_ADC_SR            _ADC1CTL.Overlap_STR.ADC1CTL_0STR.Bits.ADC_SR
    #define ADC1CTL_0_ADC_EN            _ADC1CTL.Overlap_STR.ADC1CTL_0STR.Bits.ADC_EN
    /* ADC1CTL__ARR: Access 2 ADC1CTL_x registers in an array */
    #define ADC1CTL__ARR                ((volatile byte *) &ADC1CTL_0)
    
    #define ADC1CTL_0_MOD_CFG_MASK      1U
    #define ADC1CTL_0_STR_SEQA_MASK     2U
    #define ADC1CTL_0_ACC_CFG_MASK      12U
    #define ADC1CTL_0_ACC_CFG_BITNUM    2U
    #define ADC1CTL_0_SWAI_MASK         16U
    #define ADC1CTL_0_FRZ_MOD_MASK      32U
    #define ADC1CTL_0_ADC_SR_MASK       64U
    #define ADC1CTL_0_ADC_EN_MASK       128U
    

    /*** ADC1CTL_1 - ADC1 Control Register 1; 0x00000641 ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte AUT_RSTA    :1;                                       /* Automatic Restart Event after exit from MCU Stop and Wait Mode */
        byte SMOD_ACC    :1;                                       /* Special Mode Access Control */
        byte RVL_BMOD    :1;                                       /* RVL Buffer Mode Select */
        byte CSL_BMOD    :1;                                       /* CSL Buffer Mode Select */
      } Bits;
    } ADC1CTL_1STR;
    #define ADC1CTL_1                   _ADC1CTL.Overlap_STR.ADC1CTL_1STR.Byte
    #define ADC1CTL_1_AUT_RSTA          _ADC1CTL.Overlap_STR.ADC1CTL_1STR.Bits.AUT_RSTA
    #define ADC1CTL_1_SMOD_ACC          _ADC1CTL.Overlap_STR.ADC1CTL_1STR.Bits.SMOD_ACC
    #define ADC1CTL_1_RVL_BMOD          _ADC1CTL.Overlap_STR.ADC1CTL_1STR.Bits.RVL_BMOD
    #define ADC1CTL_1_CSL_BMOD          _ADC1CTL.Overlap_STR.ADC1CTL_1STR.Bits.CSL_BMOD
    
    #define ADC1CTL_1_AUT_RSTA_MASK     16U
    #define ADC1CTL_1_SMOD_ACC_MASK     32U
    #define ADC1CTL_1_RVL_BMOD_MASK     64U
    #define ADC1CTL_1_CSL_BMOD_MASK     128U
    
  } Overlap_STR;

  struct {
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word AUT_RSTA    :1;                                       /* Automatic Restart Event after exit from MCU Stop and Wait Mode */
    word SMOD_ACC    :1;                                       /* Special Mode Access Control */
    word RVL_BMOD    :1;                                       /* RVL Buffer Mode Select */
    word CSL_BMOD    :1;                                       /* CSL Buffer Mode Select */
    word MOD_CFG     :1;                                       /* Trigger Mode Configuration */
    word STR_SEQA    :1;                                       /* Control Of Conversion Result Storage during Sequence abort (SEQA) or Restart request (RSTA) */
    word ACC_CFG     :2;                                       /* ADCFLWCTL Register Access Configuration */
    word SWAI        :1;                                       /* Wait Mode Configuration */
    word FRZ_MOD     :1;                                       /* Freeze Mode Configuration */
    word ADC_SR      :1;                                       /* ADC Soft Reset */
    word ADC_EN      :1;                                       /* ADC Enable Bit */
  } Bits;
} ADC1CTLSTR;
extern volatile ADC1CTLSTR _ADC1CTL @0x00000640;
#define ADC1CTL                         _ADC1CTL.Word
#define ADC1CTL_AUT_RSTA                _ADC1CTL.Bits.AUT_RSTA
#define ADC1CTL_SMOD_ACC                _ADC1CTL.Bits.SMOD_ACC
#define ADC1CTL_RVL_BMOD                _ADC1CTL.Bits.RVL_BMOD
#define ADC1CTL_CSL_BMOD                _ADC1CTL.Bits.CSL_BMOD
#define ADC1CTL_MOD_CFG                 _ADC1CTL.Bits.MOD_CFG
#define ADC1CTL_STR_SEQA                _ADC1CTL.Bits.STR_SEQA
#define ADC1CTL_ACC_CFG                 _ADC1CTL.Bits.ACC_CFG
#define ADC1CTL_SWAI                    _ADC1CTL.Bits.SWAI
#define ADC1CTL_FRZ_MOD                 _ADC1CTL.Bits.FRZ_MOD
#define ADC1CTL_ADC_SR                  _ADC1CTL.Bits.ADC_SR
#define ADC1CTL_ADC_EN                  _ADC1CTL.Bits.ADC_EN

#define ADC1CTL_AUT_RSTA_MASK           16U
#define ADC1CTL_SMOD_ACC_MASK           32U
#define ADC1CTL_RVL_BMOD_MASK           64U
#define ADC1CTL_CSL_BMOD_MASK           128U
#define ADC1CTL_MOD_CFG_MASK            256U
#define ADC1CTL_STR_SEQA_MASK           512U
#define ADC1CTL_ACC_CFG_MASK            3072U
#define ADC1CTL_ACC_CFG_BITNUM          10U
#define ADC1CTL_SWAI_MASK               4096U
#define ADC1CTL_FRZ_MOD_MASK            8192U
#define ADC1CTL_ADC_SR_MASK             16384U
#define ADC1CTL_ADC_EN_MASK             32768U


/*** ADC1STS - ADC1 Status Register; 0x00000642 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte READY       :1;                                       /* Flag indicates that ADC is in its idle state and ready for a Restart Event */
    byte             :1; 
    byte DBECC_ERR   :1;                                       /* Double Bit ECC Error Flag */
    byte RVL_SEL     :1;                                       /* Result Value List Select */
    byte CSL_SEL     :1;                                       /* Command Sequence List Select */
  } Bits;
} ADC1STSSTR;
extern volatile ADC1STSSTR _ADC1STS @0x00000642;
#define ADC1STS                         _ADC1STS.Byte
#define ADC1STS_READY                   _ADC1STS.Bits.READY
#define ADC1STS_DBECC_ERR               _ADC1STS.Bits.DBECC_ERR
#define ADC1STS_RVL_SEL                 _ADC1STS.Bits.RVL_SEL
#define ADC1STS_CSL_SEL                 _ADC1STS.Bits.CSL_SEL

#define ADC1STS_READY_MASK              8U
#define ADC1STS_DBECC_ERR_MASK          32U
#define ADC1STS_RVL_SEL_MASK            64U
#define ADC1STS_CSL_SEL_MASK            128U


/*** ADC1TIM - ADC1 Timing Register; 0x00000643 ***/
typedef union {
  byte Byte;
  struct {
    byte PRS         :7;                                       /* ADC Clock Prescaler */
    byte             :1; 
  } Bits;
} ADC1TIMSTR;
extern volatile ADC1TIMSTR _ADC1TIM @0x00000643;
#define ADC1TIM                         _ADC1TIM.Byte
#define ADC1TIM_PRS                     _ADC1TIM.Bits.PRS

#define ADC1TIM_PRS_MASK                127U
#define ADC1TIM_PRS_BITNUM              0U


/*** ADC1FMT - ADC1 Format Register; 0x00000644 ***/
typedef union {
  byte Byte;
  struct {
    byte SRES        :3;                                       /* ADC Resolution Select */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DJM         :1;                                       /* Result Register Data Justification */
  } Bits;
} ADC1FMTSTR;
extern volatile ADC1FMTSTR _ADC1FMT @0x00000644;
#define ADC1FMT                         _ADC1FMT.Byte
#define ADC1FMT_SRES                    _ADC1FMT.Bits.SRES
#define ADC1FMT_DJM                     _ADC1FMT.Bits.DJM

#define ADC1FMT_SRES_MASK               7U
#define ADC1FMT_SRES_BITNUM             0U
#define ADC1FMT_DJM_MASK                128U


/*** ADC1FLWCTL - ADC1 Conversion Flow Control Register; 0x00000645 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LDOK        :1;                                       /* Load OK for alternative Command Sequence List */
    byte RSTA        :1;                                       /* Restart Event (Restart from Top of Command Sequence List) */
    byte TRIG        :1;                                       /* Conversion Sequence Trigger */
    byte SEQA        :1;                                       /* Conversion Sequence Abort Event */
  } Bits;
} ADC1FLWCTLSTR;
extern volatile ADC1FLWCTLSTR _ADC1FLWCTL @0x00000645;
#define ADC1FLWCTL                      _ADC1FLWCTL.Byte
#define ADC1FLWCTL_LDOK                 _ADC1FLWCTL.Bits.LDOK
#define ADC1FLWCTL_RSTA                 _ADC1FLWCTL.Bits.RSTA
#define ADC1FLWCTL_TRIG                 _ADC1FLWCTL.Bits.TRIG
#define ADC1FLWCTL_SEQA                 _ADC1FLWCTL.Bits.SEQA

#define ADC1FLWCTL_LDOK_MASK            16U
#define ADC1FLWCTL_RSTA_MASK            32U
#define ADC1FLWCTL_TRIG_MASK            64U
#define ADC1FLWCTL_SEQA_MASK            128U


/*** ADC1EIE - ADC1 Error Interrupt Enable Register; 0x00000646 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LDOK_EIE    :1;                                       /* Load OK Error Interrupt Enable */
    byte RSTAR_EIE   :1;                                       /* Restart Request Error Interrupt Enable */
    byte TRIG_EIE    :1;                                       /* Conversion Sequence Trigger Error Interrupt Enable */
    byte             :1; 
    byte EOL_EIE     :1;                                       /* End Of List Error Interrupt Enable */
    byte CMD_EIE     :1;                                       /* Command Value Error Interrupt Enable */
    byte IA_EIE      :1;                                       /* Illegal Access Error Interrupt Enable */
  } Bits;
} ADC1EIESTR;
extern volatile ADC1EIESTR _ADC1EIE @0x00000646;
#define ADC1EIE                         _ADC1EIE.Byte
#define ADC1EIE_LDOK_EIE                _ADC1EIE.Bits.LDOK_EIE
#define ADC1EIE_RSTAR_EIE               _ADC1EIE.Bits.RSTAR_EIE
#define ADC1EIE_TRIG_EIE                _ADC1EIE.Bits.TRIG_EIE
#define ADC1EIE_EOL_EIE                 _ADC1EIE.Bits.EOL_EIE
#define ADC1EIE_CMD_EIE                 _ADC1EIE.Bits.CMD_EIE
#define ADC1EIE_IA_EIE                  _ADC1EIE.Bits.IA_EIE

#define ADC1EIE_LDOK_EIE_MASK           2U
#define ADC1EIE_RSTAR_EIE_MASK          4U
#define ADC1EIE_TRIG_EIE_MASK           8U
#define ADC1EIE_EOL_EIE_MASK            32U
#define ADC1EIE_CMD_EIE_MASK            64U
#define ADC1EIE_IA_EIE_MASK             128U


/*** ADC1IE - ADC1 Interrupt Enable Register; 0x00000647 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CONIF_OIE   :1;                                       /* ADCCONIF Register Flags Overrun Interrupt Enable */
    byte SEQAD_IE    :1;                                       /* Conversion Sequence Abort Done Interrupt Enable */
  } Bits;
} ADC1IESTR;
extern volatile ADC1IESTR _ADC1IE @0x00000647;
#define ADC1IE                          _ADC1IE.Byte
#define ADC1IE_CONIF_OIE                _ADC1IE.Bits.CONIF_OIE
#define ADC1IE_SEQAD_IE                 _ADC1IE.Bits.SEQAD_IE

#define ADC1IE_CONIF_OIE_MASK           64U
#define ADC1IE_SEQAD_IE_MASK            128U


/*** ADC1EIF - ADC1 Error Interrupt Flag Register; 0x00000648 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LDOK_EIF    :1;                                       /* Load OK Error Interrupt Flag */
    byte RSTAR_EIF   :1;                                       /* Restart Request Error Interrupt Flag */
    byte TRIG_EIF    :1;                                       /* Trigger Error Interrupt Flag */
    byte             :1; 
    byte EOL_EIF     :1;                                       /* End Of List Error Interrupt Flag */
    byte CMD_EIF     :1;                                       /* Command Value Error Interrupt Flag */
    byte IA_EIF      :1;                                       /* Illegal Access Error Interrupt Flag */
  } Bits;
} ADC1EIFSTR;
extern volatile ADC1EIFSTR _ADC1EIF @0x00000648;
#define ADC1EIF                         _ADC1EIF.Byte
#define ADC1EIF_LDOK_EIF                _ADC1EIF.Bits.LDOK_EIF
#define ADC1EIF_RSTAR_EIF               _ADC1EIF.Bits.RSTAR_EIF
#define ADC1EIF_TRIG_EIF                _ADC1EIF.Bits.TRIG_EIF
#define ADC1EIF_EOL_EIF                 _ADC1EIF.Bits.EOL_EIF
#define ADC1EIF_CMD_EIF                 _ADC1EIF.Bits.CMD_EIF
#define ADC1EIF_IA_EIF                  _ADC1EIF.Bits.IA_EIF

#define ADC1EIF_LDOK_EIF_MASK           2U
#define ADC1EIF_RSTAR_EIF_MASK          4U
#define ADC1EIF_TRIG_EIF_MASK           8U
#define ADC1EIF_EOL_EIF_MASK            32U
#define ADC1EIF_CMD_EIF_MASK            64U
#define ADC1EIF_IA_EIF_MASK             128U


/*** ADC1IF - ADC1 Interrupt Flag Register; 0x00000649 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CONIF_OIF   :1;                                       /* ADCxCONIF Register Flags Overrun Interrupt Flag */
    byte SEQAD_IF    :1;                                       /* Conversion Sequence Abort Done Interrupt Flag */
  } Bits;
} ADC1IFSTR;
extern volatile ADC1IFSTR _ADC1IF @0x00000649;
#define ADC1IF                          _ADC1IF.Byte
#define ADC1IF_CONIF_OIF                _ADC1IF.Bits.CONIF_OIF
#define ADC1IF_SEQAD_IF                 _ADC1IF.Bits.SEQAD_IF

#define ADC1IF_CONIF_OIF_MASK           64U
#define ADC1IF_SEQAD_IF_MASK            128U


/*** ADC1CONIE - ADC1 Conversion Interrupt Enable Register; 0x0000064A ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC1CONIE_0 - ADC1 Conversion Interrupt Enable Register 0; 0x0000064A ***/
    union {
      byte Byte;
      struct {
        byte CON_IE8     :1;                                       /* Conversion Interrupt 8 Enable */
        byte CON_IE9     :1;                                       /* Conversion Interrupt 9 Enable */
        byte CON_IE10    :1;                                       /* Conversion Interrupt 10 Enable */
        byte CON_IE11    :1;                                       /* Conversion Interrupt 11 Enable */
        byte CON_IE12    :1;                                       /* Conversion Interrupt 12 Enable */
        byte CON_IE13    :1;                                       /* Conversion Interrupt 13 Enable */
        byte CON_IE14    :1;                                       /* Conversion Interrupt 14 Enable */
        byte CON_IE15    :1;                                       /* Conversion Interrupt 15 Enable */
      } Bits;
    } ADC1CONIE_0STR;
    #define ADC1CONIE_0                 _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Byte
    #define ADC1CONIE_0_CON_IE8         _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Bits.CON_IE8
    #define ADC1CONIE_0_CON_IE9         _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Bits.CON_IE9
    #define ADC1CONIE_0_CON_IE10        _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Bits.CON_IE10
    #define ADC1CONIE_0_CON_IE11        _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Bits.CON_IE11
    #define ADC1CONIE_0_CON_IE12        _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Bits.CON_IE12
    #define ADC1CONIE_0_CON_IE13        _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Bits.CON_IE13
    #define ADC1CONIE_0_CON_IE14        _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Bits.CON_IE14
    #define ADC1CONIE_0_CON_IE15        _ADC1CONIE.Overlap_STR.ADC1CONIE_0STR.Bits.CON_IE15
    /* ADC1CONIE__ARR: Access 2 ADC1CONIE_x registers in an array */
    #define ADC1CONIE__ARR              ((volatile byte *) &ADC1CONIE_0)
    
    #define ADC1CONIE_0_CON_IE8_MASK    1U
    #define ADC1CONIE_0_CON_IE9_MASK    2U
    #define ADC1CONIE_0_CON_IE10_MASK   4U
    #define ADC1CONIE_0_CON_IE11_MASK   8U
    #define ADC1CONIE_0_CON_IE12_MASK   16U
    #define ADC1CONIE_0_CON_IE13_MASK   32U
    #define ADC1CONIE_0_CON_IE14_MASK   64U
    #define ADC1CONIE_0_CON_IE15_MASK   128U
    

    /*** ADC1CONIE_1 - ADC1 Conversion Interrupt Enable Register 1; 0x0000064B ***/
    union {
      byte Byte;
      struct {
        byte EOL_IE      :1;                                       /* End Of List Interrupt Enable */
        byte CON_IE1     :1;                                       /* Conversion Interrupt 1 Enable */
        byte CON_IE2     :1;                                       /* Conversion Interrupt 2 Enable */
        byte CON_IE3     :1;                                       /* Conversion Interrupt 3 Enable */
        byte CON_IE4     :1;                                       /* Conversion Interrupt 4 Enable */
        byte CON_IE5     :1;                                       /* Conversion Interrupt 5 Enable */
        byte CON_IE6     :1;                                       /* Conversion Interrupt 6 Enable */
        byte CON_IE7     :1;                                       /* Conversion Interrupt 7 Enable */
      } Bits;
      struct {
        byte     :1;
        byte grpCON_IE_1 :7;
      } MergedBits;
    } ADC1CONIE_1STR;
    #define ADC1CONIE_1                 _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Byte
    #define ADC1CONIE_1_EOL_IE          _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Bits.EOL_IE
    #define ADC1CONIE_1_CON_IE1         _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Bits.CON_IE1
    #define ADC1CONIE_1_CON_IE2         _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Bits.CON_IE2
    #define ADC1CONIE_1_CON_IE3         _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Bits.CON_IE3
    #define ADC1CONIE_1_CON_IE4         _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Bits.CON_IE4
    #define ADC1CONIE_1_CON_IE5         _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Bits.CON_IE5
    #define ADC1CONIE_1_CON_IE6         _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Bits.CON_IE6
    #define ADC1CONIE_1_CON_IE7         _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.Bits.CON_IE7
    #define ADC1CONIE_1_CON_IE_1        _ADC1CONIE.Overlap_STR.ADC1CONIE_1STR.MergedBits.grpCON_IE_1
    #define ADC1CONIE_1_CON_IE          ADC1CONIE_1_CON_IE_1
    
    #define ADC1CONIE_1_EOL_IE_MASK     1U
    #define ADC1CONIE_1_CON_IE1_MASK    2U
    #define ADC1CONIE_1_CON_IE2_MASK    4U
    #define ADC1CONIE_1_CON_IE3_MASK    8U
    #define ADC1CONIE_1_CON_IE4_MASK    16U
    #define ADC1CONIE_1_CON_IE5_MASK    32U
    #define ADC1CONIE_1_CON_IE6_MASK    64U
    #define ADC1CONIE_1_CON_IE7_MASK    128U
    #define ADC1CONIE_1_CON_IE_1_MASK   254U
    #define ADC1CONIE_1_CON_IE_1_BITNUM 1U
    
  } Overlap_STR;

  struct {
    word EOL_IE      :1;                                       /* End Of List Interrupt Enable */
    word CON_IE1     :1;                                       /* Conversion Interrupt 1 Enable */
    word CON_IE2     :1;                                       /* Conversion Interrupt 2 Enable */
    word CON_IE3     :1;                                       /* Conversion Interrupt 3 Enable */
    word CON_IE4     :1;                                       /* Conversion Interrupt 4 Enable */
    word CON_IE5     :1;                                       /* Conversion Interrupt 5 Enable */
    word CON_IE6     :1;                                       /* Conversion Interrupt 6 Enable */
    word CON_IE7     :1;                                       /* Conversion Interrupt 7 Enable */
    word CON_IE8     :1;                                       /* Conversion Interrupt 8 Enable */
    word CON_IE9     :1;                                       /* Conversion Interrupt 9 Enable */
    word CON_IE10    :1;                                       /* Conversion Interrupt 10 Enable */
    word CON_IE11    :1;                                       /* Conversion Interrupt 11 Enable */
    word CON_IE12    :1;                                       /* Conversion Interrupt 12 Enable */
    word CON_IE13    :1;                                       /* Conversion Interrupt 13 Enable */
    word CON_IE14    :1;                                       /* Conversion Interrupt 14 Enable */
    word CON_IE15    :1;                                       /* Conversion Interrupt 15 Enable */
  } Bits;
  struct {
    word         :1;
    word grpCON_IE_1 :15;
  } MergedBits;
} ADC1CONIESTR;
extern volatile ADC1CONIESTR _ADC1CONIE @0x0000064A;
#define ADC1CONIE                       _ADC1CONIE.Word
#define ADC1CONIE_EOL_IE                _ADC1CONIE.Bits.EOL_IE
#define ADC1CONIE_CON_IE1               _ADC1CONIE.Bits.CON_IE1
#define ADC1CONIE_CON_IE2               _ADC1CONIE.Bits.CON_IE2
#define ADC1CONIE_CON_IE3               _ADC1CONIE.Bits.CON_IE3
#define ADC1CONIE_CON_IE4               _ADC1CONIE.Bits.CON_IE4
#define ADC1CONIE_CON_IE5               _ADC1CONIE.Bits.CON_IE5
#define ADC1CONIE_CON_IE6               _ADC1CONIE.Bits.CON_IE6
#define ADC1CONIE_CON_IE7               _ADC1CONIE.Bits.CON_IE7
#define ADC1CONIE_CON_IE8               _ADC1CONIE.Bits.CON_IE8
#define ADC1CONIE_CON_IE9               _ADC1CONIE.Bits.CON_IE9
#define ADC1CONIE_CON_IE10              _ADC1CONIE.Bits.CON_IE10
#define ADC1CONIE_CON_IE11              _ADC1CONIE.Bits.CON_IE11
#define ADC1CONIE_CON_IE12              _ADC1CONIE.Bits.CON_IE12
#define ADC1CONIE_CON_IE13              _ADC1CONIE.Bits.CON_IE13
#define ADC1CONIE_CON_IE14              _ADC1CONIE.Bits.CON_IE14
#define ADC1CONIE_CON_IE15              _ADC1CONIE.Bits.CON_IE15
#define ADC1CONIE_CON_IE_1              _ADC1CONIE.MergedBits.grpCON_IE_1
#define ADC1CONIE_CON_IE                ADC1CONIE_CON_IE_1

#define ADC1CONIE_EOL_IE_MASK           1U
#define ADC1CONIE_CON_IE1_MASK          2U
#define ADC1CONIE_CON_IE2_MASK          4U
#define ADC1CONIE_CON_IE3_MASK          8U
#define ADC1CONIE_CON_IE4_MASK          16U
#define ADC1CONIE_CON_IE5_MASK          32U
#define ADC1CONIE_CON_IE6_MASK          64U
#define ADC1CONIE_CON_IE7_MASK          128U
#define ADC1CONIE_CON_IE8_MASK          256U
#define ADC1CONIE_CON_IE9_MASK          512U
#define ADC1CONIE_CON_IE10_MASK         1024U
#define ADC1CONIE_CON_IE11_MASK         2048U
#define ADC1CONIE_CON_IE12_MASK         4096U
#define ADC1CONIE_CON_IE13_MASK         8192U
#define ADC1CONIE_CON_IE14_MASK         16384U
#define ADC1CONIE_CON_IE15_MASK         32768U
#define ADC1CONIE_CON_IE_1_MASK         65534U
#define ADC1CONIE_CON_IE_1_BITNUM       1U


/*** ADC1CONIF - ADC1 Conversion Interrupt Flag Register; 0x0000064C ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC1CONIF_0 - ADC1 Conversion Interrupt Flag Register 0; 0x0000064C ***/
    union {
      byte Byte;
      struct {
        byte CON_IF8     :1;                                       /* Conversion Interrupt 8 Flag */
        byte CON_IF9     :1;                                       /* Conversion Interrupt 9 Flag */
        byte CON_IF10    :1;                                       /* Conversion Interrupt 10 Flag */
        byte CON_IF11    :1;                                       /* Conversion Interrupt 11 Flag */
        byte CON_IF12    :1;                                       /* Conversion Interrupt 12 Flag */
        byte CON_IF13    :1;                                       /* Conversion Interrupt 13 Flag */
        byte CON_IF14    :1;                                       /* Conversion Interrupt 14 Flag */
        byte CON_IF15    :1;                                       /* Conversion Interrupt 15 Flag */
      } Bits;
    } ADC1CONIF_0STR;
    #define ADC1CONIF_0                 _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Byte
    #define ADC1CONIF_0_CON_IF8         _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Bits.CON_IF8
    #define ADC1CONIF_0_CON_IF9         _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Bits.CON_IF9
    #define ADC1CONIF_0_CON_IF10        _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Bits.CON_IF10
    #define ADC1CONIF_0_CON_IF11        _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Bits.CON_IF11
    #define ADC1CONIF_0_CON_IF12        _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Bits.CON_IF12
    #define ADC1CONIF_0_CON_IF13        _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Bits.CON_IF13
    #define ADC1CONIF_0_CON_IF14        _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Bits.CON_IF14
    #define ADC1CONIF_0_CON_IF15        _ADC1CONIF.Overlap_STR.ADC1CONIF_0STR.Bits.CON_IF15
    /* ADC1CONIF__ARR: Access 2 ADC1CONIF_x registers in an array */
    #define ADC1CONIF__ARR              ((volatile byte *) &ADC1CONIF_0)
    
    #define ADC1CONIF_0_CON_IF8_MASK    1U
    #define ADC1CONIF_0_CON_IF9_MASK    2U
    #define ADC1CONIF_0_CON_IF10_MASK   4U
    #define ADC1CONIF_0_CON_IF11_MASK   8U
    #define ADC1CONIF_0_CON_IF12_MASK   16U
    #define ADC1CONIF_0_CON_IF13_MASK   32U
    #define ADC1CONIF_0_CON_IF14_MASK   64U
    #define ADC1CONIF_0_CON_IF15_MASK   128U
    

    /*** ADC1CONIF_1 - ADC1 Conversion Interrupt Flag Register 1; 0x0000064D ***/
    union {
      byte Byte;
      struct {
        byte EOL_IF      :1;                                       /* End Of List Interrupt Flag */
        byte CON_IF1     :1;                                       /* Conversion Interrupt 1 Flag */
        byte CON_IF2     :1;                                       /* Conversion Interrupt 2 Flag */
        byte CON_IF3     :1;                                       /* Conversion Interrupt 3 Flag */
        byte CON_IF4     :1;                                       /* Conversion Interrupt 4 Flag */
        byte CON_IF5     :1;                                       /* Conversion Interrupt 5 Flag */
        byte CON_IF6     :1;                                       /* Conversion Interrupt 6 Flag */
        byte CON_IF7     :1;                                       /* Conversion Interrupt 7 Flag */
      } Bits;
      struct {
        byte     :1;
        byte grpCON_IF_1 :7;
      } MergedBits;
    } ADC1CONIF_1STR;
    #define ADC1CONIF_1                 _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Byte
    #define ADC1CONIF_1_EOL_IF          _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Bits.EOL_IF
    #define ADC1CONIF_1_CON_IF1         _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Bits.CON_IF1
    #define ADC1CONIF_1_CON_IF2         _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Bits.CON_IF2
    #define ADC1CONIF_1_CON_IF3         _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Bits.CON_IF3
    #define ADC1CONIF_1_CON_IF4         _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Bits.CON_IF4
    #define ADC1CONIF_1_CON_IF5         _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Bits.CON_IF5
    #define ADC1CONIF_1_CON_IF6         _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Bits.CON_IF6
    #define ADC1CONIF_1_CON_IF7         _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.Bits.CON_IF7
    #define ADC1CONIF_1_CON_IF_1        _ADC1CONIF.Overlap_STR.ADC1CONIF_1STR.MergedBits.grpCON_IF_1
    #define ADC1CONIF_1_CON_IF          ADC1CONIF_1_CON_IF_1
    
    #define ADC1CONIF_1_EOL_IF_MASK     1U
    #define ADC1CONIF_1_CON_IF1_MASK    2U
    #define ADC1CONIF_1_CON_IF2_MASK    4U
    #define ADC1CONIF_1_CON_IF3_MASK    8U
    #define ADC1CONIF_1_CON_IF4_MASK    16U
    #define ADC1CONIF_1_CON_IF5_MASK    32U
    #define ADC1CONIF_1_CON_IF6_MASK    64U
    #define ADC1CONIF_1_CON_IF7_MASK    128U
    #define ADC1CONIF_1_CON_IF_1_MASK   254U
    #define ADC1CONIF_1_CON_IF_1_BITNUM 1U
    
  } Overlap_STR;

  struct {
    word EOL_IF      :1;                                       /* End Of List Interrupt Flag */
    word CON_IF1     :1;                                       /* Conversion Interrupt 1 Flag */
    word CON_IF2     :1;                                       /* Conversion Interrupt 2 Flag */
    word CON_IF3     :1;                                       /* Conversion Interrupt 3 Flag */
    word CON_IF4     :1;                                       /* Conversion Interrupt 4 Flag */
    word CON_IF5     :1;                                       /* Conversion Interrupt 5 Flag */
    word CON_IF6     :1;                                       /* Conversion Interrupt 6 Flag */
    word CON_IF7     :1;                                       /* Conversion Interrupt 7 Flag */
    word CON_IF8     :1;                                       /* Conversion Interrupt 8 Flag */
    word CON_IF9     :1;                                       /* Conversion Interrupt 9 Flag */
    word CON_IF10    :1;                                       /* Conversion Interrupt 10 Flag */
    word CON_IF11    :1;                                       /* Conversion Interrupt 11 Flag */
    word CON_IF12    :1;                                       /* Conversion Interrupt 12 Flag */
    word CON_IF13    :1;                                       /* Conversion Interrupt 13 Flag */
    word CON_IF14    :1;                                       /* Conversion Interrupt 14 Flag */
    word CON_IF15    :1;                                       /* Conversion Interrupt 15 Flag */
  } Bits;
  struct {
    word         :1;
    word grpCON_IF_1 :15;
  } MergedBits;
} ADC1CONIFSTR;
extern volatile ADC1CONIFSTR _ADC1CONIF @0x0000064C;
#define ADC1CONIF                       _ADC1CONIF.Word
#define ADC1CONIF_EOL_IF                _ADC1CONIF.Bits.EOL_IF
#define ADC1CONIF_CON_IF1               _ADC1CONIF.Bits.CON_IF1
#define ADC1CONIF_CON_IF2               _ADC1CONIF.Bits.CON_IF2
#define ADC1CONIF_CON_IF3               _ADC1CONIF.Bits.CON_IF3
#define ADC1CONIF_CON_IF4               _ADC1CONIF.Bits.CON_IF4
#define ADC1CONIF_CON_IF5               _ADC1CONIF.Bits.CON_IF5
#define ADC1CONIF_CON_IF6               _ADC1CONIF.Bits.CON_IF6
#define ADC1CONIF_CON_IF7               _ADC1CONIF.Bits.CON_IF7
#define ADC1CONIF_CON_IF8               _ADC1CONIF.Bits.CON_IF8
#define ADC1CONIF_CON_IF9               _ADC1CONIF.Bits.CON_IF9
#define ADC1CONIF_CON_IF10              _ADC1CONIF.Bits.CON_IF10
#define ADC1CONIF_CON_IF11              _ADC1CONIF.Bits.CON_IF11
#define ADC1CONIF_CON_IF12              _ADC1CONIF.Bits.CON_IF12
#define ADC1CONIF_CON_IF13              _ADC1CONIF.Bits.CON_IF13
#define ADC1CONIF_CON_IF14              _ADC1CONIF.Bits.CON_IF14
#define ADC1CONIF_CON_IF15              _ADC1CONIF.Bits.CON_IF15
#define ADC1CONIF_CON_IF_1              _ADC1CONIF.MergedBits.grpCON_IF_1
#define ADC1CONIF_CON_IF                ADC1CONIF_CON_IF_1

#define ADC1CONIF_EOL_IF_MASK           1U
#define ADC1CONIF_CON_IF1_MASK          2U
#define ADC1CONIF_CON_IF2_MASK          4U
#define ADC1CONIF_CON_IF3_MASK          8U
#define ADC1CONIF_CON_IF4_MASK          16U
#define ADC1CONIF_CON_IF5_MASK          32U
#define ADC1CONIF_CON_IF6_MASK          64U
#define ADC1CONIF_CON_IF7_MASK          128U
#define ADC1CONIF_CON_IF8_MASK          256U
#define ADC1CONIF_CON_IF9_MASK          512U
#define ADC1CONIF_CON_IF10_MASK         1024U
#define ADC1CONIF_CON_IF11_MASK         2048U
#define ADC1CONIF_CON_IF12_MASK         4096U
#define ADC1CONIF_CON_IF13_MASK         8192U
#define ADC1CONIF_CON_IF14_MASK         16384U
#define ADC1CONIF_CON_IF15_MASK         32768U
#define ADC1CONIF_CON_IF_1_MASK         65534U
#define ADC1CONIF_CON_IF_1_BITNUM       1U


/*** ADC1IMDRI - ADC1 Intermediate Result Information Register; 0x0000064E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** ADC1IMDRI_0 - ADC1 Intermediate Result Information Register 0; 0x0000064E ***/
    union {
      byte Byte;
      struct {
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte RVL_IMD     :1;                                       /* Active RVL At Intermediate Event */
        byte CSL_IMD     :1;                                       /* Active CSL At Intermediate Event */
      } Bits;
    } ADC1IMDRI_0STR;
    #define ADC1IMDRI_0                 _ADC1IMDRI.Overlap_STR.ADC1IMDRI_0STR.Byte
    #define ADC1IMDRI_0_RVL_IMD         _ADC1IMDRI.Overlap_STR.ADC1IMDRI_0STR.Bits.RVL_IMD
    #define ADC1IMDRI_0_CSL_IMD         _ADC1IMDRI.Overlap_STR.ADC1IMDRI_0STR.Bits.CSL_IMD
    /* ADC1IMDRI__ARR: Access 2 ADC1IMDRI_x registers in an array */
    #define ADC1IMDRI__ARR              ((volatile byte *) &ADC1IMDRI_0)
    
    #define ADC1IMDRI_0_RVL_IMD_MASK    64U
    #define ADC1IMDRI_0_CSL_IMD_MASK    128U
    

    /*** ADC1IMDRI_1 - ADC1 Intermediate Result Information Register 1; 0x0000064F ***/
    union {
      byte Byte;
      struct {
        byte RIDX_IMD    :6;                                       /* RES_IDX Value At Intermediate Event */
        byte             :1; 
        byte             :1; 
      } Bits;
    } ADC1IMDRI_1STR;
    #define ADC1IMDRI_1                 _ADC1IMDRI.Overlap_STR.ADC1IMDRI_1STR.Byte
    #define ADC1IMDRI_1_RIDX_IMD        _ADC1IMDRI.Overlap_STR.ADC1IMDRI_1STR.Bits.RIDX_IMD
    
    #define ADC1IMDRI_1_RIDX_IMD_MASK   63U
    #define ADC1IMDRI_1_RIDX_IMD_BITNUM 0U
    
  } Overlap_STR;

  struct {
    word RIDX_IMD    :6;                                       /* RES_IDX Value At Intermediate Event */
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word             :1; 
    word RVL_IMD     :1;                                       /* Active RVL At Intermediate Event */
    word CSL_IMD     :1;                                       /* Active CSL At Intermediate Event */
  } Bits;
} ADC1IMDRISTR;
extern volatile ADC1IMDRISTR _ADC1IMDRI @0x0000064E;
#define ADC1IMDRI                       _ADC1IMDRI.Word
#define ADC1IMDRI_RIDX_IMD              _ADC1IMDRI.Bits.RIDX_IMD
#define ADC1IMDRI_RVL_IMD               _ADC1IMDRI.Bits.RVL_IMD
#define ADC1IMDRI_CSL_IMD               _ADC1IMDRI.Bits.CSL_IMD

#define ADC1IMDRI_RIDX_IMD_MASK         63U
#define ADC1IMDRI_RIDX_IMD_BITNUM       0U
#define ADC1IMDRI_RVL_IMD_MASK          16384U
#define ADC1IMDRI_CSL_IMD_MASK          32768U


/*** ADC1EOLRI - ADC1 End Of List Result Information Register; 0x00000650 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte RVL_EOL     :1;                                       /* Active RVL When End Of List Command Type Was Executed */
    byte CSL_EOL     :1;                                       /* Active CSL When End Of List Command Type Was Executed */
  } Bits;
} ADC1EOLRISTR;
extern volatile ADC1EOLRISTR _ADC1EOLRI @0x00000650;
#define ADC1EOLRI                       _ADC1EOLRI.Byte
#define ADC1EOLRI_RVL_EOL               _ADC1EOLRI.Bits.RVL_EOL
#define ADC1EOLRI_CSL_EOL               _ADC1EOLRI.Bits.CSL_EOL

#define ADC1EOLRI_RVL_EOL_MASK          64U
#define ADC1EOLRI_CSL_EOL_MASK          128U


/*** ADC1CMD - ADC1 Command Register; 0x00000654 ***/
typedef union {
  dword Dword;
   /* Overlapped registers: */
  struct {
    /*** ADC1CMD_01 - ADC1 Command Register 01; 0x00000654 ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** ADC1CMD_0 - ADC1 Command Register 0; 0x00000654 ***/
        union {
          byte Byte;
          struct {
            byte INTFLG_SEL  :4;                                       /* Conversion Interrupt Flag Select */
            byte             :1; 
            byte             :1; 
            byte CMD_SEL     :2;                                       /* Conversion Command Select */
          } Bits;
        } ADC1CMD_0STR;
        #define ADC1CMD_0               _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Overlap_STR.ADC1CMD_0STR.Byte
        #define ADC1CMD_0_INTFLG_SEL    _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Overlap_STR.ADC1CMD_0STR.Bits.INTFLG_SEL
        #define ADC1CMD_0_CMD_SEL       _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Overlap_STR.ADC1CMD_0STR.Bits.CMD_SEL
        /* ADC1CMD__ARR: Access 4 ADC1CMD_x registers in an array */
        #define ADC1CMD__ARR            ((volatile byte *) &ADC1CMD_0)
        
        #define ADC1CMD_0_INTFLG_SEL_MASK 15U
        #define ADC1CMD_0_INTFLG_SEL_BITNUM 0U
        #define ADC1CMD_0_CMD_SEL_MASK  192U
        #define ADC1CMD_0_CMD_SEL_BITNUM 6U
        
    
        /*** ADC1CMD_1 - ADC1 Command Register 1; 0x00000655 ***/
        union {
          byte Byte;
          struct {
            byte CH_SEL      :6;                                       /* ADC Input Channel Select */
            byte VRL_SEL     :1;                                       /* Reference Low Voltage Select */
            byte VRH_SEL     :1;                                       /* Reference High Voltage Select */
          } Bits;
        } ADC1CMD_1STR;
        #define ADC1CMD_1               _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Overlap_STR.ADC1CMD_1STR.Byte
        #define ADC1CMD_1_CH_SEL        _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Overlap_STR.ADC1CMD_1STR.Bits.CH_SEL
        #define ADC1CMD_1_VRL_SEL       _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Overlap_STR.ADC1CMD_1STR.Bits.VRL_SEL
        #define ADC1CMD_1_VRH_SEL       _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Overlap_STR.ADC1CMD_1STR.Bits.VRH_SEL
        
        #define ADC1CMD_1_CH_SEL_MASK   63U
        #define ADC1CMD_1_CH_SEL_BITNUM 0U
        #define ADC1CMD_1_VRL_SEL_MASK  64U
        #define ADC1CMD_1_VRH_SEL_MASK  128U
        
      } Overlap_STR;
    
      struct {
        word CH_SEL      :6;                                       /* ADC Input Channel Select */
        word VRL_SEL     :1;                                       /* Reference Low Voltage Select */
        word VRH_SEL     :1;                                       /* Reference High Voltage Select */
        word INTFLG_SEL  :4;                                       /* Conversion Interrupt Flag Select */
        word             :1; 
        word             :1; 
        word CMD_SEL     :2;                                       /* Conversion Command Select */
      } Bits;
    } ADC1CMD_01STR;
    #define ADC1CMD_01                  _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Word
    #define ADC1CMD_01_CH_SEL           _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Bits.CH_SEL
    #define ADC1CMD_01_VRL_SEL          _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Bits.VRL_SEL
    #define ADC1CMD_01_VRH_SEL          _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Bits.VRH_SEL
    #define ADC1CMD_01_INTFLG_SEL       _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Bits.INTFLG_SEL
    #define ADC1CMD_01_CMD_SEL          _ADC1CMD.Overlap_STR.ADC1CMD_01STR.Bits.CMD_SEL
    
    #define ADC1CMD_01_CH_SEL_MASK      63U
    #define ADC1CMD_01_CH_SEL_BITNUM    0U
    #define ADC1CMD_01_VRL_SEL_MASK     64U
    #define ADC1CMD_01_VRH_SEL_MASK     128U
    #define ADC1CMD_01_INTFLG_SEL_MASK  3840U
    #define ADC1CMD_01_INTFLG_SEL_BITNUM 8U
    #define ADC1CMD_01_CMD_SEL_MASK     49152U
    #define ADC1CMD_01_CMD_SEL_BITNUM   14U
    

    /*** ADC1CMD_23 - ADC1 Command Register 23; 0x00000656 ***/
    union {
      word Word;
       /* Overlapped registers: */
      struct {
        /*** ADC1CMD_2 - ADC1 Command Register 2; 0x00000656 ***/
        union {
          byte Byte;
          struct {
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte SMP         :5;                                       /* Sample Time Select */
          } Bits;
        } ADC1CMD_2STR;
        #define ADC1CMD_2               _ADC1CMD.Overlap_STR.ADC1CMD_23STR.Overlap_STR.ADC1CMD_2STR.Byte
        #define ADC1CMD_2_SMP           _ADC1CMD.Overlap_STR.ADC1CMD_23STR.Overlap_STR.ADC1CMD_2STR.Bits.SMP
        
        #define ADC1CMD_2_SMP_MASK      248U
        #define ADC1CMD_2_SMP_BITNUM    3U
        
    
        /*** ADC1CMD_3 - ADC1 Command Register 3; 0x00000657 ***/
        union {
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
        } ADC1CMD_3STR;
        #define ADC1CMD_3               _ADC1CMD.Overlap_STR.ADC1CMD_23STR.Overlap_STR.ADC1CMD_3STR.Byte
        
      } Overlap_STR;
    
      struct {
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word             :1; 
        word SMP         :5;                                       /* Sample Time Select */
      } Bits;
    } ADC1CMD_23STR;
    #define ADC1CMD_23                  _ADC1CMD.Overlap_STR.ADC1CMD_23STR.Word
    #define ADC1CMD_23_SMP              _ADC1CMD.Overlap_STR.ADC1CMD_23STR.Bits.SMP
    
    #define ADC1CMD_23_SMP_MASK         63488U
    #define ADC1CMD_23_SMP_BITNUM       11U
    
  } Overlap_STR;

} ADC1CMDSTR;
extern volatile ADC1CMDSTR _ADC1CMD @0x00000654;
#define ADC1CMD                         _ADC1CMD.Dword


/*** ADC1CIDX - ADC1 Command Index Register; 0x0000065C ***/
typedef union {
  byte Byte;
  struct {
    byte CMD_IDX     :6;                                       /* ADC Command Index */
    byte             :1; 
    byte             :1; 
  } Bits;
} ADC1CIDXSTR;
extern volatile ADC1CIDXSTR _ADC1CIDX @0x0000065C;
#define ADC1CIDX                        _ADC1CIDX.Byte
#define ADC1CIDX_CMD_IDX                _ADC1CIDX.Bits.CMD_IDX

#define ADC1CIDX_CMD_IDX_MASK           63U
#define ADC1CIDX_CMD_IDX_BITNUM         0U


/*** ADC1CBP_0 - ADC1 Command Base Pointer Register 0; 0x0000065D ***/
typedef union {
  byte Byte;
  struct {
    byte CMD_PTR     :8;                                       /* ADC Command Base Pointer Address */
  } Bits;
} ADC1CBP_0STR;
extern volatile ADC1CBP_0STR _ADC1CBP_0 @0x0000065D;
#define ADC1CBP_0                       _ADC1CBP_0.Byte
#define ADC1CBP_0_CMD_PTR               _ADC1CBP_0.Bits.CMD_PTR
/* ADC1CBP__ARR: Access 3 ADC1CBP_x registers in an array */
#define ADC1CBP__ARR                    ((volatile byte *) &ADC1CBP_0)

#define ADC1CBP_0_CMD_PTR_MASK          255U
#define ADC1CBP_0_CMD_PTR_BITNUM        0U


/*** ADC1CBP_1 - ADC1 Command Base Pointer Register 1; 0x0000065E ***/
typedef union {
  byte Byte;
  struct {
    byte CMD_PTR     :8;                                       /* ADC Command Base Pointer Address */
  } Bits;
} ADC1CBP_1STR;
extern volatile ADC1CBP_1STR _ADC1CBP_1 @0x0000065E;
#define ADC1CBP_1                       _ADC1CBP_1.Byte
#define ADC1CBP_1_CMD_PTR               _ADC1CBP_1.Bits.CMD_PTR

#define ADC1CBP_1_CMD_PTR_MASK          255U
#define ADC1CBP_1_CMD_PTR_BITNUM        0U


/*** ADC1CBP_2 - ADC1 Command Base Pointer Register 2; 0x0000065F ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte CMD_PTR     :6;                                       /* ADC Command Base Pointer Address */
  } Bits;
} ADC1CBP_2STR;
extern volatile ADC1CBP_2STR _ADC1CBP_2 @0x0000065F;
#define ADC1CBP_2                       _ADC1CBP_2.Byte
#define ADC1CBP_2_CMD_PTR               _ADC1CBP_2.Bits.CMD_PTR

#define ADC1CBP_2_CMD_PTR_MASK          252U
#define ADC1CBP_2_CMD_PTR_BITNUM        2U


/*** ADC1RIDX - ADC1 Result Index Register; 0x00000660 ***/
typedef union {
  byte Byte;
  struct {
    byte RES_IDX     :6;                                       /* ADC Result Index */
    byte             :1; 
    byte             :1; 
  } Bits;
} ADC1RIDXSTR;
extern volatile ADC1RIDXSTR _ADC1RIDX @0x00000660;
#define ADC1RIDX                        _ADC1RIDX.Byte
#define ADC1RIDX_RES_IDX                _ADC1RIDX.Bits.RES_IDX

#define ADC1RIDX_RES_IDX_MASK           63U
#define ADC1RIDX_RES_IDX_BITNUM         0U


/*** ADC1RBP_0 - ADC1 Result Base Pointer Register 0; 0x00000661 ***/
typedef union {
  byte Byte;
  struct {
    byte RES_PTR     :4;                                       /* ADC Result Base Pointer Address */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} ADC1RBP_0STR;
extern volatile ADC1RBP_0STR _ADC1RBP_0 @0x00000661;
#define ADC1RBP_0                       _ADC1RBP_0.Byte
#define ADC1RBP_0_RES_PTR               _ADC1RBP_0.Bits.RES_PTR
/* ADC1RBP__ARR: Access 3 ADC1RBP_x registers in an array */
#define ADC1RBP__ARR                    ((volatile byte *) &ADC1RBP_0)

#define ADC1RBP_0_RES_PTR_MASK          15U
#define ADC1RBP_0_RES_PTR_BITNUM        0U


/*** ADC1RBP_1 - ADC1 Result Base Pointer Register 1; 0x00000662 ***/
typedef union {
  byte Byte;
  struct {
    byte RES_PTR     :8;                                       /* ADC Result Base Pointer Address */
  } Bits;
} ADC1RBP_1STR;
extern volatile ADC1RBP_1STR _ADC1RBP_1 @0x00000662;
#define ADC1RBP_1                       _ADC1RBP_1.Byte
#define ADC1RBP_1_RES_PTR               _ADC1RBP_1.Bits.RES_PTR

#define ADC1RBP_1_RES_PTR_MASK          255U
#define ADC1RBP_1_RES_PTR_BITNUM        0U


/*** ADC1RBP_2 - ADC1 Result Base Pointer Register 2; 0x00000663 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte RES_PTR     :6;                                       /* ADC Result Base Pointer Address */
  } Bits;
} ADC1RBP_2STR;
extern volatile ADC1RBP_2STR _ADC1RBP_2 @0x00000663;
#define ADC1RBP_2                       _ADC1RBP_2.Byte
#define ADC1RBP_2_RES_PTR               _ADC1RBP_2.Bits.RES_PTR

#define ADC1RBP_2_RES_PTR_MASK          252U
#define ADC1RBP_2_RES_PTR_BITNUM        2U


/*** ADC1CROFF0 - ADC1 Command and Result Offset Register 0; 0x00000664 ***/
typedef union {
  byte Byte;
  struct {
    byte CMDRES_OFF0 :7;                                       /* ADC Command and Result Offset Value refer to CSL_0 and RVL_0 */
    byte             :1; 
  } Bits;
} ADC1CROFF0STR;
extern volatile ADC1CROFF0STR _ADC1CROFF0 @0x00000664;
#define ADC1CROFF0                      _ADC1CROFF0.Byte
#define ADC1CROFF0_CMDRES_OFF0          _ADC1CROFF0.Bits.CMDRES_OFF0
/* ADC1CROFF_ARR: Access 2 ADC1CROFFx registers in an array */
#define ADC1CROFF_ARR                   ((volatile byte *) &ADC1CROFF0)

#define ADC1CROFF0_CMDRES_OFF0_MASK     127U
#define ADC1CROFF0_CMDRES_OFF0_BITNUM   0U


/*** ADC1CROFF1 - ADC1 Command and Result Offset Register 1; 0x00000665 ***/
typedef union {
  byte Byte;
  struct {
    byte CMDRES_OFF1 :7;                                       /* ADC Command and Result Offset Value refer to CSL_1 and RVL_1 */
    byte             :1; 
  } Bits;
} ADC1CROFF1STR;
extern volatile ADC1CROFF1STR _ADC1CROFF1 @0x00000665;
#define ADC1CROFF1                      _ADC1CROFF1.Byte
#define ADC1CROFF1_CMDRES_OFF1          _ADC1CROFF1.Bits.CMDRES_OFF1

#define ADC1CROFF1_CMDRES_OFF1_MASK     127U
#define ADC1CROFF1_CMDRES_OFF1_BITNUM   0U


/*** GDUE - GDU Module Enable Register; 0x000006A0 ***/
typedef union {
  byte Byte;
  struct {
    byte GFDE        :1;                                       /* GDU FET Pre-Driver Enable */
    byte GCPE        :1;                                       /* GDU Charge Pump Enable */
    byte GCSE0       :1;                                       /* GDU Current Sense Amplifier 0 Enable */
    byte GBOE        :1;                                       /* GDU Boost Converter Enable */
    byte GCSE1       :1;                                       /* GDU Current Sense Amplifier 1 Enable */
    byte EPRES       :1;                                       /* Enable High-Side Driver Preserve Functionality */
    byte             :1; 
    byte GWP         :1;                                       /* GDU Write Protect */
  } Bits;
} GDUESTR;
extern volatile GDUESTR _GDUE @0x000006A0;
#define GDUE                            _GDUE.Byte
#define GDUE_GFDE                       _GDUE.Bits.GFDE
#define GDUE_GCPE                       _GDUE.Bits.GCPE
#define GDUE_GCSE0                      _GDUE.Bits.GCSE0
#define GDUE_GBOE                       _GDUE.Bits.GBOE
#define GDUE_GCSE1                      _GDUE.Bits.GCSE1
#define GDUE_EPRES                      _GDUE.Bits.EPRES
#define GDUE_GWP                        _GDUE.Bits.GWP

#define GDUE_GFDE_MASK                  1U
#define GDUE_GCPE_MASK                  2U
#define GDUE_GCSE0_MASK                 4U
#define GDUE_GBOE_MASK                  8U
#define GDUE_GCSE1_MASK                 16U
#define GDUE_EPRES_MASK                 32U
#define GDUE_GWP_MASK                   128U


/*** GDUCTR - GDU Control Register; 0x000006A1 ***/
typedef union {
  byte Byte;
  struct {
    byte GBKTIM1     :2;                                       /* GDU Blanking Time */
    byte GBKTIM2     :4;                                       /* GDU Blanking Time */
    byte             :1; 
    byte GHHDLVL     :1;                                       /* GDU High HD Level Select */
  } Bits;
} GDUCTRSTR;
extern volatile GDUCTRSTR _GDUCTR @0x000006A1;
#define GDUCTR                          _GDUCTR.Byte
#define GDUCTR_GBKTIM1                  _GDUCTR.Bits.GBKTIM1
#define GDUCTR_GBKTIM2                  _GDUCTR.Bits.GBKTIM2
#define GDUCTR_GHHDLVL                  _GDUCTR.Bits.GHHDLVL

#define GDUCTR_GBKTIM1_MASK             3U
#define GDUCTR_GBKTIM1_BITNUM           0U
#define GDUCTR_GBKTIM2_MASK             60U
#define GDUCTR_GBKTIM2_BITNUM           2U
#define GDUCTR_GHHDLVL_MASK             128U


/*** GDUIE - GDU Interrupt Enable Register; 0x000006A2 ***/
typedef union {
  byte Byte;
  struct {
    byte GLVLSIE     :1;                                       /* GDU Low VLS Interrupt Enable */
    byte GHHDIE      :1;                                       /* GDU High HD Interrupt Enable */
    byte GDSEIE      :1;                                       /* GDU Desaturation Error Interrupt Enable */
    byte GOCIE0      :1;                                       /* GDU Overcurrent Interrupt Enable 0 */
    byte GOCIE1      :1;                                       /* GDU Overcurrent Interrupt Enable 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpGOCIE :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} GDUIESTR;
extern volatile GDUIESTR _GDUIE @0x000006A2;
#define GDUIE                           _GDUIE.Byte
#define GDUIE_GLVLSIE                   _GDUIE.Bits.GLVLSIE
#define GDUIE_GHHDIE                    _GDUIE.Bits.GHHDIE
#define GDUIE_GDSEIE                    _GDUIE.Bits.GDSEIE
#define GDUIE_GOCIE0                    _GDUIE.Bits.GOCIE0
#define GDUIE_GOCIE1                    _GDUIE.Bits.GOCIE1
#define GDUIE_GOCIE                     _GDUIE.MergedBits.grpGOCIE

#define GDUIE_GLVLSIE_MASK              1U
#define GDUIE_GHHDIE_MASK               2U
#define GDUIE_GDSEIE_MASK               4U
#define GDUIE_GOCIE0_MASK               8U
#define GDUIE_GOCIE1_MASK               16U
#define GDUIE_GOCIE_MASK                24U
#define GDUIE_GOCIE_BITNUM              3U


/*** GDUDSE - GDU Desaturation Error Flag Register; 0x000006A3 ***/
typedef union {
  byte Byte;
  struct {
    byte GDLSIF0     :1;                                       /* Low-side desaturation error flag for channel 0 */
    byte GDLSIF1     :1;                                       /* Low-side desaturation error flag for channel 1 */
    byte GDLSIF2     :1;                                       /* Low-side desaturation error flag for channel 2 */
    byte             :1; 
    byte GDHSIF0     :1;                                       /* High-side desaturation error flag for channel 0 */
    byte GDHSIF1     :1;                                       /* High-side desaturation error flag for channel 1 */
    byte GDHSIF2     :1;                                       /* High-side desaturation error flag for channel 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpGDLSIF :3;
    byte         :1;
    byte grpGDHSIF :3;
    byte         :1;
  } MergedBits;
} GDUDSESTR;
extern volatile GDUDSESTR _GDUDSE @0x000006A3;
#define GDUDSE                          _GDUDSE.Byte
#define GDUDSE_GDLSIF0                  _GDUDSE.Bits.GDLSIF0
#define GDUDSE_GDLSIF1                  _GDUDSE.Bits.GDLSIF1
#define GDUDSE_GDLSIF2                  _GDUDSE.Bits.GDLSIF2
#define GDUDSE_GDHSIF0                  _GDUDSE.Bits.GDHSIF0
#define GDUDSE_GDHSIF1                  _GDUDSE.Bits.GDHSIF1
#define GDUDSE_GDHSIF2                  _GDUDSE.Bits.GDHSIF2
#define GDUDSE_GDLSIF                   _GDUDSE.MergedBits.grpGDLSIF
#define GDUDSE_GDHSIF                   _GDUDSE.MergedBits.grpGDHSIF

#define GDUDSE_GDLSIF0_MASK             1U
#define GDUDSE_GDLSIF1_MASK             2U
#define GDUDSE_GDLSIF2_MASK             4U
#define GDUDSE_GDHSIF0_MASK             16U
#define GDUDSE_GDHSIF1_MASK             32U
#define GDUDSE_GDHSIF2_MASK             64U
#define GDUDSE_GDLSIF_MASK              7U
#define GDUDSE_GDLSIF_BITNUM            0U
#define GDUDSE_GDHSIF_MASK              112U
#define GDUDSE_GDHSIF_BITNUM            4U


/*** GDUSTAT - GDU Status Register; 0x000006A4 ***/
typedef union {
  byte Byte;
  struct {
    byte GLVLSS      :1;                                       /* GDU Low VLS Status */
    byte GHHDS       :1;                                       /* GDU High HD Supply Status */
    byte             :1; 
    byte GOCS0       :1;                                       /* GDU Overcurrent Status 0 */
    byte GOCS1       :1;                                       /* GDU Overcurrent Status 1 */
    byte GPHS0       :1;                                       /* GDU Phase Status 0 */
    byte GPHS1       :1;                                       /* GDU Phase Status 1 */
    byte GPHS2       :1;                                       /* GDU Phase Status 2 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpGOCS :2;
    byte grpGPHS :3;
  } MergedBits;
} GDUSTATSTR;
extern volatile GDUSTATSTR _GDUSTAT @0x000006A4;
#define GDUSTAT                         _GDUSTAT.Byte
#define GDUSTAT_GLVLSS                  _GDUSTAT.Bits.GLVLSS
#define GDUSTAT_GHHDS                   _GDUSTAT.Bits.GHHDS
#define GDUSTAT_GOCS0                   _GDUSTAT.Bits.GOCS0
#define GDUSTAT_GOCS1                   _GDUSTAT.Bits.GOCS1
#define GDUSTAT_GPHS0                   _GDUSTAT.Bits.GPHS0
#define GDUSTAT_GPHS1                   _GDUSTAT.Bits.GPHS1
#define GDUSTAT_GPHS2                   _GDUSTAT.Bits.GPHS2
#define GDUSTAT_GOCS                    _GDUSTAT.MergedBits.grpGOCS
#define GDUSTAT_GPHS                    _GDUSTAT.MergedBits.grpGPHS

#define GDUSTAT_GLVLSS_MASK             1U
#define GDUSTAT_GHHDS_MASK              2U
#define GDUSTAT_GOCS0_MASK              8U
#define GDUSTAT_GOCS1_MASK              16U
#define GDUSTAT_GPHS0_MASK              32U
#define GDUSTAT_GPHS1_MASK              64U
#define GDUSTAT_GPHS2_MASK              128U
#define GDUSTAT_GOCS_MASK               24U
#define GDUSTAT_GOCS_BITNUM             3U
#define GDUSTAT_GPHS_MASK               224U
#define GDUSTAT_GPHS_BITNUM             5U


/*** GDUSRC - GDU Slew Rate Control Register; 0x000006A5 ***/
typedef union {
  byte Byte;
  struct {
    byte GSRCLS0     :1;                                       /* This bit controls the slew rate on the LG0 */
    byte GSRCLS1     :1;                                       /* This bit controls the slew rate on the LG1 */
    byte GSRCLS2     :1;                                       /* This bit controls the slew rate on the LG2 */
    byte             :1; 
    byte GSRCHS0     :1;                                       /* This bit controls the slew rate on the HG0 */
    byte GSRCHS1     :1;                                       /* This bit controls the slew rate on the HG1 */
    byte GSRCHS2     :1;                                       /* This bit controls the slew rate on the HG2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpGSRCLS :3;
    byte         :1;
    byte grpGSRCHS :3;
    byte         :1;
  } MergedBits;
} GDUSRCSTR;
extern volatile GDUSRCSTR _GDUSRC @0x000006A5;
#define GDUSRC                          _GDUSRC.Byte
#define GDUSRC_GSRCLS0                  _GDUSRC.Bits.GSRCLS0
#define GDUSRC_GSRCLS1                  _GDUSRC.Bits.GSRCLS1
#define GDUSRC_GSRCLS2                  _GDUSRC.Bits.GSRCLS2
#define GDUSRC_GSRCHS0                  _GDUSRC.Bits.GSRCHS0
#define GDUSRC_GSRCHS1                  _GDUSRC.Bits.GSRCHS1
#define GDUSRC_GSRCHS2                  _GDUSRC.Bits.GSRCHS2
#define GDUSRC_GSRCLS                   _GDUSRC.MergedBits.grpGSRCLS
#define GDUSRC_GSRCHS                   _GDUSRC.MergedBits.grpGSRCHS

#define GDUSRC_GSRCLS0_MASK             1U
#define GDUSRC_GSRCLS1_MASK             2U
#define GDUSRC_GSRCLS2_MASK             4U
#define GDUSRC_GSRCHS0_MASK             16U
#define GDUSRC_GSRCHS1_MASK             32U
#define GDUSRC_GSRCHS2_MASK             64U
#define GDUSRC_GSRCLS_MASK              7U
#define GDUSRC_GSRCLS_BITNUM            0U
#define GDUSRC_GSRCHS_MASK              112U
#define GDUSRC_GSRCHS_BITNUM            4U


/*** GDUF - GDU Flag Register; 0x000006A6 ***/
typedef union {
  byte Byte;
  struct {
    byte GLVLSIF     :1;                                       /* GDU Low VLS Supply Interrupt Flag */
    byte GHHDIF      :1;                                       /* GDU High VHD Supply Interrupt Flag */
    byte             :1; 
    byte GOCIF0      :1;                                       /* GDU Overcurrent Interrupt Flag 0 */
    byte GOCIF1      :1;                                       /* GDU Overcurrent Interrupt Flag 1 */
    byte GLVLSF      :1;                                       /* GDU Low VLS Supply Flag */
    byte GHHDF       :1;                                       /* GDU High VHD Supply Flag */
    byte GSUF        :1;                                       /* GDU Start-up Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpGOCIF :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} GDUFSTR;
extern volatile GDUFSTR _GDUF @0x000006A6;
#define GDUF                            _GDUF.Byte
#define GDUF_GLVLSIF                    _GDUF.Bits.GLVLSIF
#define GDUF_GHHDIF                     _GDUF.Bits.GHHDIF
#define GDUF_GOCIF0                     _GDUF.Bits.GOCIF0
#define GDUF_GOCIF1                     _GDUF.Bits.GOCIF1
#define GDUF_GLVLSF                     _GDUF.Bits.GLVLSF
#define GDUF_GHHDF                      _GDUF.Bits.GHHDF
#define GDUF_GSUF                       _GDUF.Bits.GSUF
#define GDUF_GOCIF                      _GDUF.MergedBits.grpGOCIF

#define GDUF_GLVLSIF_MASK               1U
#define GDUF_GHHDIF_MASK                2U
#define GDUF_GOCIF0_MASK                8U
#define GDUF_GOCIF1_MASK                16U
#define GDUF_GLVLSF_MASK                32U
#define GDUF_GHHDF_MASK                 64U
#define GDUF_GSUF_MASK                  128U
#define GDUF_GOCIF_MASK                 24U
#define GDUF_GOCIF_BITNUM               3U


/*** GDUCLK1 - GDU Clock Control Register 1; 0x000006A7 ***/
typedef union {
  byte Byte;
  struct {
    byte GBODC       :2;                                       /* GDU Boost Option Clock Duty Cycle */
    byte GBOCD       :5;                                       /* GDU Boost Option Clock Divider */
    byte             :1; 
  } Bits;
} GDUCLK1STR;
extern volatile GDUCLK1STR _GDUCLK1 @0x000006A7;
#define GDUCLK1                         _GDUCLK1.Byte
#define GDUCLK1_GBODC                   _GDUCLK1.Bits.GBODC
#define GDUCLK1_GBOCD                   _GDUCLK1.Bits.GBOCD

#define GDUCLK1_GBODC_MASK              3U
#define GDUCLK1_GBODC_BITNUM            0U
#define GDUCLK1_GBOCD_MASK              124U
#define GDUCLK1_GBOCD_BITNUM            2U


/*** GDUBCL - GDU Boost Current Limit Register; 0x000006A8 ***/
typedef union {
  byte Byte;
  struct {
    byte GBCL        :4;                                       /* GDU Boost Current Limit Register */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} GDUBCLSTR;
extern volatile GDUBCLSTR _GDUBCL @0x000006A8;
#define GDUBCL                          _GDUBCL.Byte
#define GDUBCL_GBCL                     _GDUBCL.Bits.GBCL

#define GDUBCL_GBCL_MASK                15U
#define GDUBCL_GBCL_BITNUM              0U


/*** GDUPHMUX - GDU Phase Mux Register; 0x000006A9 ***/
typedef union {
  byte Byte;
  struct {
    byte GPHMX       :2;                                       /* GDU Phase Multplexer */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} GDUPHMUXSTR;
extern volatile GDUPHMUXSTR _GDUPHMUX @0x000006A9;
#define GDUPHMUX                        _GDUPHMUX.Byte
#define GDUPHMUX_GPHMX                  _GDUPHMUX.Bits.GPHMX

#define GDUPHMUX_GPHMX_MASK             3U
#define GDUPHMUX_GPHMX_BITNUM           0U


/*** GDUCSO - GDU Current Sense Offset Register; 0x000006AA ***/
typedef union {
  byte Byte;
  struct {
    byte GCSO0       :3;                                       /* GDU Current Sense Amplifier 0 Offset */
    byte             :1; 
    byte GCSO1       :3;                                       /* GDU Current Sense Amplifier 1 Offset */
    byte             :1; 
  } Bits;
} GDUCSOSTR;
extern volatile GDUCSOSTR _GDUCSO @0x000006AA;
#define GDUCSO                          _GDUCSO.Byte
#define GDUCSO_GCSO0                    _GDUCSO.Bits.GCSO0
#define GDUCSO_GCSO1                    _GDUCSO.Bits.GCSO1

#define GDUCSO_GCSO0_MASK               7U
#define GDUCSO_GCSO0_BITNUM             0U
#define GDUCSO_GCSO1_MASK               112U
#define GDUCSO_GCSO1_BITNUM             4U


/*** GDUDSLVL - GDU Desaturation Level Register; 0x000006AB ***/
typedef union {
  byte Byte;
  struct {
    byte GDSLLS      :3;                                       /* GDU Desaturation Level for Low-Side Drivers */
    byte             :1; 
    byte GDSLHS      :3;                                       /* GDU Desaturation Level for High-Side Drivers */
    byte             :1; 
  } Bits;
} GDUDSLVLSTR;
extern volatile GDUDSLVLSTR _GDUDSLVL @0x000006AB;
#define GDUDSLVL                        _GDUDSLVL.Byte
#define GDUDSLVL_GDSLLS                 _GDUDSLVL.Bits.GDSLLS
#define GDUDSLVL_GDSLHS                 _GDUDSLVL.Bits.GDSLHS

#define GDUDSLVL_GDSLLS_MASK            7U
#define GDUDSLVL_GDSLLS_BITNUM          0U
#define GDUDSLVL_GDSLHS_MASK            112U
#define GDUDSLVL_GDSLHS_BITNUM          4U


/*** GDUPHL - GDU Phase Log Register; 0x000006AC ***/
typedef union {
  byte Byte;
  struct {
    byte GPHL        :3;                                       /* GDU Phase Log Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} GDUPHLSTR;
extern volatile GDUPHLSTR _GDUPHL @0x000006AC;
#define GDUPHL                          _GDUPHL.Byte
#define GDUPHL_GPHL                     _GDUPHL.Bits.GPHL

#define GDUPHL_GPHL_MASK                7U
#define GDUPHL_GPHL_BITNUM              0U


/*** GDUCLK2 - GDU Clock Control Register 2; 0x000006AD ***/
typedef union {
  byte Byte;
  struct {
    byte GCPCD       :4;                                       /* GDU Charge Pump Clock Divider */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} GDUCLK2STR;
extern volatile GDUCLK2STR _GDUCLK2 @0x000006AD;
#define GDUCLK2                         _GDUCLK2.Byte
#define GDUCLK2_GCPCD                   _GDUCLK2.Bits.GCPCD

#define GDUCLK2_GCPCD_MASK              15U
#define GDUCLK2_GCPCD_BITNUM            0U


/*** GDUOC0 - GDU Overcurrent Register 0; 0x000006AE ***/
typedef union {
  byte Byte;
  struct {
    byte GOCT0       :4;                                       /* GDU Overcurrent Comparator Threshold */
    byte             :1; 
    byte             :1; 
    byte GOCE0       :1;                                       /* GDU Overcurrent Comparator Enable */
    byte GOCA0       :1;                                       /* GDU Overcurrent Action */
  } Bits;
} GDUOC0STR;
extern volatile GDUOC0STR _GDUOC0 @0x000006AE;
#define GDUOC0                          _GDUOC0.Byte
#define GDUOC0_GOCT0                    _GDUOC0.Bits.GOCT0
#define GDUOC0_GOCE0                    _GDUOC0.Bits.GOCE0
#define GDUOC0_GOCA0                    _GDUOC0.Bits.GOCA0
/* GDUOC_ARR: Access 2 GDUOCx registers in an array */
#define GDUOC_ARR                       ((volatile byte *) &GDUOC0)

#define GDUOC0_GOCT0_MASK               15U
#define GDUOC0_GOCT0_BITNUM             0U
#define GDUOC0_GOCE0_MASK               64U
#define GDUOC0_GOCA0_MASK               128U


/*** GDUOC1 - GDU Overcurrent Register 1; 0x000006AF ***/
typedef union {
  byte Byte;
  struct {
    byte GOCT1       :4;                                       /* GDU Overcurrent Comparator Threshold */
    byte             :1; 
    byte             :1; 
    byte GOCE1       :1;                                       /* GDU Overcurrent Comparator Enable */
    byte GOCA1       :1;                                       /* GDU Overcurrent Action */
  } Bits;
} GDUOC1STR;
extern volatile GDUOC1STR _GDUOC1 @0x000006AF;
#define GDUOC1                          _GDUOC1.Byte
#define GDUOC1_GOCT1                    _GDUOC1.Bits.GOCT1
#define GDUOC1_GOCE1                    _GDUOC1.Bits.GOCE1
#define GDUOC1_GOCA1                    _GDUOC1.Bits.GOCA1

#define GDUOC1_GOCT1_MASK               15U
#define GDUOC1_GOCT1_BITNUM             0U
#define GDUOC1_GOCE1_MASK               64U
#define GDUOC1_GOCA1_MASK               128U


/*** CPMURFLG - CPMU Reset Flags Register; 0x000006C3 ***/
typedef union {
  byte Byte;
  struct {
    byte PMRF        :1;                                       /* PLL Clock Monitor Reset Flag */
    byte OMRF        :1;                                       /* Oscillator Clock Monitor Reset Flag */
    byte             :1; 
    byte COPRF       :1;                                       /* COP Reset Flag */
    byte             :1; 
    byte LVRF        :1;                                       /* Low Voltage Reset Flag */
    byte PORF        :1;                                       /* Power on Reset Flag */
    byte             :1; 
  } Bits;
} CPMURFLGSTR;
extern volatile CPMURFLGSTR _CPMURFLG @0x000006C3;
#define CPMURFLG                        _CPMURFLG.Byte
#define CPMURFLG_PMRF                   _CPMURFLG.Bits.PMRF
#define CPMURFLG_OMRF                   _CPMURFLG.Bits.OMRF
#define CPMURFLG_COPRF                  _CPMURFLG.Bits.COPRF
#define CPMURFLG_LVRF                   _CPMURFLG.Bits.LVRF
#define CPMURFLG_PORF                   _CPMURFLG.Bits.PORF

#define CPMURFLG_PMRF_MASK              1U
#define CPMURFLG_OMRF_MASK              2U
#define CPMURFLG_COPRF_MASK             8U
#define CPMURFLG_LVRF_MASK              32U
#define CPMURFLG_PORF_MASK              64U


/*** CPMUSYNR - CPMU Synthesizer Register; 0x000006C4 ***/
typedef union {
  byte Byte;
  struct {
    byte SYNDIV0     :1;                                       /* Multiplication factor of the IPLL bit 0 */
    byte SYNDIV1     :1;                                       /* Multiplication factor of the IPLL bit 1 */
    byte SYNDIV2     :1;                                       /* Multiplication factor of the IPLL bit 2 */
    byte SYNDIV3     :1;                                       /* Multiplication factor of the IPLL bit 3 */
    byte SYNDIV4     :1;                                       /* Multiplication factor of the IPLL bit 4 */
    byte SYNDIV5     :1;                                       /* Multiplication factor of the IPLL bit 5 */
    byte VCOFRQ0     :1;                                       /* VCO frequency range bit 0 */
    byte VCOFRQ1     :1;                                       /* VCO frequency range bit 1 */
  } Bits;
  struct {
    byte grpSYNDIV :6;
    byte grpVCOFRQ :2;
  } MergedBits;
} CPMUSYNRSTR;
extern volatile CPMUSYNRSTR _CPMUSYNR @0x000006C4;
#define CPMUSYNR                        _CPMUSYNR.Byte
#define CPMUSYNR_SYNDIV0                _CPMUSYNR.Bits.SYNDIV0
#define CPMUSYNR_SYNDIV1                _CPMUSYNR.Bits.SYNDIV1
#define CPMUSYNR_SYNDIV2                _CPMUSYNR.Bits.SYNDIV2
#define CPMUSYNR_SYNDIV3                _CPMUSYNR.Bits.SYNDIV3
#define CPMUSYNR_SYNDIV4                _CPMUSYNR.Bits.SYNDIV4
#define CPMUSYNR_SYNDIV5                _CPMUSYNR.Bits.SYNDIV5
#define CPMUSYNR_VCOFRQ0                _CPMUSYNR.Bits.VCOFRQ0
#define CPMUSYNR_VCOFRQ1                _CPMUSYNR.Bits.VCOFRQ1
#define CPMUSYNR_SYNDIV                 _CPMUSYNR.MergedBits.grpSYNDIV
#define CPMUSYNR_VCOFRQ                 _CPMUSYNR.MergedBits.grpVCOFRQ

#define CPMUSYNR_SYNDIV0_MASK           1U
#define CPMUSYNR_SYNDIV1_MASK           2U
#define CPMUSYNR_SYNDIV2_MASK           4U
#define CPMUSYNR_SYNDIV3_MASK           8U
#define CPMUSYNR_SYNDIV4_MASK           16U
#define CPMUSYNR_SYNDIV5_MASK           32U
#define CPMUSYNR_VCOFRQ0_MASK           64U
#define CPMUSYNR_VCOFRQ1_MASK           128U
#define CPMUSYNR_SYNDIV_MASK            63U
#define CPMUSYNR_SYNDIV_BITNUM          0U
#define CPMUSYNR_VCOFRQ_MASK            192U
#define CPMUSYNR_VCOFRQ_BITNUM          6U


/*** CPMUREFDIV - CPMU Reference Divider Register; 0x000006C5 ***/
typedef union {
  byte Byte;
  struct {
    byte REFDIV0     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 0 */
    byte REFDIV1     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 1 */
    byte REFDIV2     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 2 */
    byte REFDIV3     :1;                                       /* Finer granularity for the IPLL multiplier steps bit 3 */
    byte             :1; 
    byte             :1; 
    byte REFFRQ0     :1;                                       /* IPLL optimal stability and lock time configuration bit 0 */
    byte REFFRQ1     :1;                                       /* IPLL optimal stability and lock time configuration bit 1 */
  } Bits;
  struct {
    byte grpREFDIV :4;
    byte         :1;
    byte         :1;
    byte grpREFFRQ :2;
  } MergedBits;
} CPMUREFDIVSTR;
extern volatile CPMUREFDIVSTR _CPMUREFDIV @0x000006C5;
#define CPMUREFDIV                      _CPMUREFDIV.Byte
#define CPMUREFDIV_REFDIV0              _CPMUREFDIV.Bits.REFDIV0
#define CPMUREFDIV_REFDIV1              _CPMUREFDIV.Bits.REFDIV1
#define CPMUREFDIV_REFDIV2              _CPMUREFDIV.Bits.REFDIV2
#define CPMUREFDIV_REFDIV3              _CPMUREFDIV.Bits.REFDIV3
#define CPMUREFDIV_REFFRQ0              _CPMUREFDIV.Bits.REFFRQ0
#define CPMUREFDIV_REFFRQ1              _CPMUREFDIV.Bits.REFFRQ1
#define CPMUREFDIV_REFDIV               _CPMUREFDIV.MergedBits.grpREFDIV
#define CPMUREFDIV_REFFRQ               _CPMUREFDIV.MergedBits.grpREFFRQ

#define CPMUREFDIV_REFDIV0_MASK         1U
#define CPMUREFDIV_REFDIV1_MASK         2U
#define CPMUREFDIV_REFDIV2_MASK         4U
#define CPMUREFDIV_REFDIV3_MASK         8U
#define CPMUREFDIV_REFFRQ0_MASK         64U
#define CPMUREFDIV_REFFRQ1_MASK         128U
#define CPMUREFDIV_REFDIV_MASK          15U
#define CPMUREFDIV_REFDIV_BITNUM        0U
#define CPMUREFDIV_REFFRQ_MASK          192U
#define CPMUREFDIV_REFFRQ_BITNUM        6U


/*** CPMUPOSTDIV - CPMU Post Divider Register; 0x000006C6 ***/
typedef union {
  byte Byte;
  struct {
    byte POSTDIV0    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 0 */
    byte POSTDIV1    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 1 */
    byte POSTDIV2    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 2 */
    byte POSTDIV3    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 3 */
    byte POSTDIV4    :1;                                       /* Frequency ratio between the VCOCLK and PLLCLK control bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpPOSTDIV :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUPOSTDIVSTR;
extern volatile CPMUPOSTDIVSTR _CPMUPOSTDIV @0x000006C6;
#define CPMUPOSTDIV                     _CPMUPOSTDIV.Byte
#define CPMUPOSTDIV_POSTDIV0            _CPMUPOSTDIV.Bits.POSTDIV0
#define CPMUPOSTDIV_POSTDIV1            _CPMUPOSTDIV.Bits.POSTDIV1
#define CPMUPOSTDIV_POSTDIV2            _CPMUPOSTDIV.Bits.POSTDIV2
#define CPMUPOSTDIV_POSTDIV3            _CPMUPOSTDIV.Bits.POSTDIV3
#define CPMUPOSTDIV_POSTDIV4            _CPMUPOSTDIV.Bits.POSTDIV4
#define CPMUPOSTDIV_POSTDIV             _CPMUPOSTDIV.MergedBits.grpPOSTDIV

#define CPMUPOSTDIV_POSTDIV0_MASK       1U
#define CPMUPOSTDIV_POSTDIV1_MASK       2U
#define CPMUPOSTDIV_POSTDIV2_MASK       4U
#define CPMUPOSTDIV_POSTDIV3_MASK       8U
#define CPMUPOSTDIV_POSTDIV4_MASK       16U
#define CPMUPOSTDIV_POSTDIV_MASK        31U
#define CPMUPOSTDIV_POSTDIV_BITNUM      0U


/*** CPMUIFLG - CPMU Interrupt Flags Register; 0x000006C7 ***/
typedef union {
  byte Byte;
  struct {
    byte UPOSC       :1;                                       /* Oscillator Status Bit */
    byte OSCIF       :1;                                       /* Oscillator Interrupt Flag */
    byte             :1; 
    byte LOCK        :1;                                       /* Lock Status Bit */
    byte LOCKIF      :1;                                       /* PLL Lock Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte RTIF        :1;                                       /* Real Time Interrupt Flag */
  } Bits;
} CPMUIFLGSTR;
extern volatile CPMUIFLGSTR _CPMUIFLG @0x000006C7;
#define CPMUIFLG                        _CPMUIFLG.Byte
#define CPMUIFLG_UPOSC                  _CPMUIFLG.Bits.UPOSC
#define CPMUIFLG_OSCIF                  _CPMUIFLG.Bits.OSCIF
#define CPMUIFLG_LOCK                   _CPMUIFLG.Bits.LOCK
#define CPMUIFLG_LOCKIF                 _CPMUIFLG.Bits.LOCKIF
#define CPMUIFLG_RTIF                   _CPMUIFLG.Bits.RTIF

#define CPMUIFLG_UPOSC_MASK             1U
#define CPMUIFLG_OSCIF_MASK             2U
#define CPMUIFLG_LOCK_MASK              8U
#define CPMUIFLG_LOCKIF_MASK            16U
#define CPMUIFLG_RTIF_MASK              128U


/*** CPMUINT - CPMU Interrupt Enable Register; 0x000006C8 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte OSCIE       :1;                                       /* Oscillator Corrupt Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte LOCKIE      :1;                                       /* Lock Interrupt Enable Bit */
    byte             :1; 
    byte             :1; 
    byte RTIE        :1;                                       /* Real Time Interrupt Enable Bit */
  } Bits;
} CPMUINTSTR;
extern volatile CPMUINTSTR _CPMUINT @0x000006C8;
#define CPMUINT                         _CPMUINT.Byte
#define CPMUINT_OSCIE                   _CPMUINT.Bits.OSCIE
#define CPMUINT_LOCKIE                  _CPMUINT.Bits.LOCKIE
#define CPMUINT_RTIE                    _CPMUINT.Bits.RTIE

#define CPMUINT_OSCIE_MASK              2U
#define CPMUINT_LOCKIE_MASK             16U
#define CPMUINT_RTIE_MASK               128U


/*** CPMUCLKS - CPMU Clock Select Register; 0x000006C9 ***/
typedef union {
  byte Byte;
  struct {
    byte COPOSCSEL0  :1;                                       /* COP Clock Select 0 */
    byte RTIOSCSEL   :1;                                       /* RTI Clock Select */
    byte PCE         :1;                                       /* COP Enable During Pseudo Stop Bit */
    byte PRE         :1;                                       /* RTI Enable During Pseudo Stop Bit */
    byte COPOSCSEL1  :1;                                       /* COP Clock Select 1 */
    byte CSAD        :1;                                       /* COP in Stop Mode ACLK Disable */
    byte PSTP        :1;                                       /* Pseudo Stop Bit */
    byte PLLSEL      :1;                                       /* PLL Select Bit */
  } Bits;
} CPMUCLKSSTR;
extern volatile CPMUCLKSSTR _CPMUCLKS @0x000006C9;
#define CPMUCLKS                        _CPMUCLKS.Byte
#define CPMUCLKS_COPOSCSEL0             _CPMUCLKS.Bits.COPOSCSEL0
#define CPMUCLKS_RTIOSCSEL              _CPMUCLKS.Bits.RTIOSCSEL
#define CPMUCLKS_PCE                    _CPMUCLKS.Bits.PCE
#define CPMUCLKS_PRE                    _CPMUCLKS.Bits.PRE
#define CPMUCLKS_COPOSCSEL1             _CPMUCLKS.Bits.COPOSCSEL1
#define CPMUCLKS_CSAD                   _CPMUCLKS.Bits.CSAD
#define CPMUCLKS_PSTP                   _CPMUCLKS.Bits.PSTP
#define CPMUCLKS_PLLSEL                 _CPMUCLKS.Bits.PLLSEL

#define CPMUCLKS_COPOSCSEL0_MASK        1U
#define CPMUCLKS_RTIOSCSEL_MASK         2U
#define CPMUCLKS_PCE_MASK               4U
#define CPMUCLKS_PRE_MASK               8U
#define CPMUCLKS_COPOSCSEL1_MASK        16U
#define CPMUCLKS_CSAD_MASK              32U
#define CPMUCLKS_PSTP_MASK              64U
#define CPMUCLKS_PLLSEL_MASK            128U


/*** CPMUPLL - CPMU PLL Control Register; 0x000006CA ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte FM0         :1;                                       /* PLL Frequency Modulation Enable Bit 0 */
    byte FM1         :1;                                       /* PLL Frequency Modulation Enable Bit 1 */
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpFM   :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUPLLSTR;
extern volatile CPMUPLLSTR _CPMUPLL @0x000006CA;
#define CPMUPLL                         _CPMUPLL.Byte
#define CPMUPLL_FM0                     _CPMUPLL.Bits.FM0
#define CPMUPLL_FM1                     _CPMUPLL.Bits.FM1
#define CPMUPLL_FM                      _CPMUPLL.MergedBits.grpFM

#define CPMUPLL_FM0_MASK                16U
#define CPMUPLL_FM1_MASK                32U
#define CPMUPLL_FM_MASK                 48U
#define CPMUPLL_FM_BITNUM               4U


/*** CPMURTI - CPMU RTI Control Register; 0x000006CB ***/
typedef union {
  byte Byte;
  struct {
    byte RTR0        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 0 */
    byte RTR1        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 1 */
    byte RTR2        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 2 */
    byte RTR3        :1;                                       /* Real Time Interrupt Modulus Counter Select Bit 3 */
    byte RTR4        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 4 */
    byte RTR5        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 5 */
    byte RTR6        :1;                                       /* Real Time Interrupt Prescale Rate Select Bit 6 */
    byte RTDEC       :1;                                       /* Decimal or Binary Divider Select Bit */
  } Bits;
  struct {
    byte grpRTR  :7;
    byte         :1;
  } MergedBits;
} CPMURTISTR;
extern volatile CPMURTISTR _CPMURTI @0x000006CB;
#define CPMURTI                         _CPMURTI.Byte
#define CPMURTI_RTR0                    _CPMURTI.Bits.RTR0
#define CPMURTI_RTR1                    _CPMURTI.Bits.RTR1
#define CPMURTI_RTR2                    _CPMURTI.Bits.RTR2
#define CPMURTI_RTR3                    _CPMURTI.Bits.RTR3
#define CPMURTI_RTR4                    _CPMURTI.Bits.RTR4
#define CPMURTI_RTR5                    _CPMURTI.Bits.RTR5
#define CPMURTI_RTR6                    _CPMURTI.Bits.RTR6
#define CPMURTI_RTDEC                   _CPMURTI.Bits.RTDEC
#define CPMURTI_RTR                     _CPMURTI.MergedBits.grpRTR

#define CPMURTI_RTR0_MASK               1U
#define CPMURTI_RTR1_MASK               2U
#define CPMURTI_RTR2_MASK               4U
#define CPMURTI_RTR3_MASK               8U
#define CPMURTI_RTR4_MASK               16U
#define CPMURTI_RTR5_MASK               32U
#define CPMURTI_RTR6_MASK               64U
#define CPMURTI_RTDEC_MASK              128U
#define CPMURTI_RTR_MASK                127U
#define CPMURTI_RTR_BITNUM              0U


/*** CPMUCOP - CPMU COP Control Register; 0x000006CC ***/
typedef union {
  byte Byte;
  struct {
    byte CR0         :1;                                       /* COP Watchdog Timer Rate select Bit 0 */
    byte CR1         :1;                                       /* COP Watchdog Timer Rate select Bit 1 */
    byte CR2         :1;                                       /* COP Watchdog Timer Rate select Bit 2 */
    byte             :1; 
    byte             :1; 
    byte WRTMASK     :1;                                       /* Write Mask for WCOP */
    byte RSBCK       :1;                                       /* COP and RTI stop in Active BDM mode Bit */
    byte WCOP        :1;                                       /* Window COP mode */
  } Bits;
  struct {
    byte grpCR   :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} CPMUCOPSTR;
extern volatile CPMUCOPSTR _CPMUCOP @0x000006CC;
#define CPMUCOP                         _CPMUCOP.Byte
#define CPMUCOP_CR0                     _CPMUCOP.Bits.CR0
#define CPMUCOP_CR1                     _CPMUCOP.Bits.CR1
#define CPMUCOP_CR2                     _CPMUCOP.Bits.CR2
#define CPMUCOP_WRTMASK                 _CPMUCOP.Bits.WRTMASK
#define CPMUCOP_RSBCK                   _CPMUCOP.Bits.RSBCK
#define CPMUCOP_WCOP                    _CPMUCOP.Bits.WCOP
#define CPMUCOP_CR                      _CPMUCOP.MergedBits.grpCR

#define CPMUCOP_CR0_MASK                1U
#define CPMUCOP_CR1_MASK                2U
#define CPMUCOP_CR2_MASK                4U
#define CPMUCOP_WRTMASK_MASK            32U
#define CPMUCOP_RSBCK_MASK              64U
#define CPMUCOP_WCOP_MASK               128U
#define CPMUCOP_CR_MASK                 7U
#define CPMUCOP_CR_BITNUM               0U


/*** CPMUARMCOP - CPMU COP Timer Arm/Reset Register; 0x000006CF ***/
typedef union {
  byte Byte;
  struct {
    byte BIT0        :1;                                       /* CPMU COP Timer Arm/Reset Bit 0 */
    byte BIT1        :1;                                       /* CPMU COP Timer Arm/Reset Bit 1 */
    byte BIT2        :1;                                       /* CPMU COP Timer Arm/Reset Bit 2 */
    byte BIT3        :1;                                       /* CPMU COP Timer Arm/Reset Bit 3 */
    byte BIT4        :1;                                       /* CPMU COP Timer Arm/Reset Bit 4 */
    byte BIT5        :1;                                       /* CPMU COP Timer Arm/Reset Bit 5 */
    byte BIT6        :1;                                       /* CPMU COP Timer Arm/Reset Bit 6 */
    byte BIT7        :1;                                       /* CPMU COP Timer Arm/Reset Bit 7 */
  } Bits;
} CPMUARMCOPSTR;
extern volatile CPMUARMCOPSTR _CPMUARMCOP @0x000006CF;
#define CPMUARMCOP                      _CPMUARMCOP.Byte
#define CPMUARMCOP_BIT0                 _CPMUARMCOP.Bits.BIT0
#define CPMUARMCOP_BIT1                 _CPMUARMCOP.Bits.BIT1
#define CPMUARMCOP_BIT2                 _CPMUARMCOP.Bits.BIT2
#define CPMUARMCOP_BIT3                 _CPMUARMCOP.Bits.BIT3
#define CPMUARMCOP_BIT4                 _CPMUARMCOP.Bits.BIT4
#define CPMUARMCOP_BIT5                 _CPMUARMCOP.Bits.BIT5
#define CPMUARMCOP_BIT6                 _CPMUARMCOP.Bits.BIT6
#define CPMUARMCOP_BIT7                 _CPMUARMCOP.Bits.BIT7

#define CPMUARMCOP_BIT0_MASK            1U
#define CPMUARMCOP_BIT1_MASK            2U
#define CPMUARMCOP_BIT2_MASK            4U
#define CPMUARMCOP_BIT3_MASK            8U
#define CPMUARMCOP_BIT4_MASK            16U
#define CPMUARMCOP_BIT5_MASK            32U
#define CPMUARMCOP_BIT6_MASK            64U
#define CPMUARMCOP_BIT7_MASK            128U


/*** CPMUHTCTL - High Temperature Control Register; 0x000006D0 ***/
typedef union {
  byte Byte;
  struct {
    byte HTIF        :1;                                       /* High Temperature Interrupt Flag */
    byte HTIE        :1;                                       /* High Temperature Interrupt Enable Bit */
    byte HTDS        :1;                                       /* High Temperature Detect Status Bi */
    byte HTE         :1;                                       /* High Temperature Sensor/Bandgap Voltage Enable Bit */
    byte             :1; 
    byte VSEL        :1;                                       /* Voltage Access Select Bit */
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUHTCTLSTR;
extern volatile CPMUHTCTLSTR _CPMUHTCTL @0x000006D0;
#define CPMUHTCTL                       _CPMUHTCTL.Byte
#define CPMUHTCTL_HTIF                  _CPMUHTCTL.Bits.HTIF
#define CPMUHTCTL_HTIE                  _CPMUHTCTL.Bits.HTIE
#define CPMUHTCTL_HTDS                  _CPMUHTCTL.Bits.HTDS
#define CPMUHTCTL_HTE                   _CPMUHTCTL.Bits.HTE
#define CPMUHTCTL_VSEL                  _CPMUHTCTL.Bits.VSEL

#define CPMUHTCTL_HTIF_MASK             1U
#define CPMUHTCTL_HTIE_MASK             2U
#define CPMUHTCTL_HTDS_MASK             4U
#define CPMUHTCTL_HTE_MASK              8U
#define CPMUHTCTL_VSEL_MASK             32U


/*** CPMULVCTL - Low Voltage Control Register; 0x000006D1 ***/
typedef union {
  byte Byte;
  struct {
    byte LVIF        :1;                                       /* Low-Voltage Interrupt Flag */
    byte LVIE        :1;                                       /* Low-Voltage Interrupt Enable Bit */
    byte LVDS        :1;                                       /* Low-Voltage Detect Status Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMULVCTLSTR;
extern volatile CPMULVCTLSTR _CPMULVCTL @0x000006D1;
#define CPMULVCTL                       _CPMULVCTL.Byte
#define CPMULVCTL_LVIF                  _CPMULVCTL.Bits.LVIF
#define CPMULVCTL_LVIE                  _CPMULVCTL.Bits.LVIE
#define CPMULVCTL_LVDS                  _CPMULVCTL.Bits.LVDS

#define CPMULVCTL_LVIF_MASK             1U
#define CPMULVCTL_LVIE_MASK             2U
#define CPMULVCTL_LVDS_MASK             4U


/*** CPMUAPICTL - Autonomous Periodical Interrupt Control Register; 0x000006D2 ***/
typedef union {
  byte Byte;
  struct {
    byte APIF        :1;                                       /* Autonomous Periodical Interrupt Flag */
    byte APIE        :1;                                       /* Autonomous Periodical Interrupt Enable Bit */
    byte APIFE       :1;                                       /* Autonomous Periodical Interrupt Feature Enable Bit */
    byte APIEA       :1;                                       /* Autonomous Periodical Interrupt External Access Enable Bit */
    byte APIES       :1;                                       /* Autonomous Periodical Interrupt External Select Bit */
    byte             :1; 
    byte             :1; 
    byte APICLK      :1;                                       /* Autonomous Periodical Interrupt Clock Select Bit */
  } Bits;
} CPMUAPICTLSTR;
extern volatile CPMUAPICTLSTR _CPMUAPICTL @0x000006D2;
#define CPMUAPICTL                      _CPMUAPICTL.Byte
#define CPMUAPICTL_APIF                 _CPMUAPICTL.Bits.APIF
#define CPMUAPICTL_APIE                 _CPMUAPICTL.Bits.APIE
#define CPMUAPICTL_APIFE                _CPMUAPICTL.Bits.APIFE
#define CPMUAPICTL_APIEA                _CPMUAPICTL.Bits.APIEA
#define CPMUAPICTL_APIES                _CPMUAPICTL.Bits.APIES
#define CPMUAPICTL_APICLK               _CPMUAPICTL.Bits.APICLK

#define CPMUAPICTL_APIF_MASK            1U
#define CPMUAPICTL_APIE_MASK            2U
#define CPMUAPICTL_APIFE_MASK           4U
#define CPMUAPICTL_APIEA_MASK           8U
#define CPMUAPICTL_APIES_MASK           16U
#define CPMUAPICTL_APICLK_MASK          128U


/*** CPMUACLKTR - Autonomous Clock Trimming Register; 0x000006D3 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ACLKTR0     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 0 */
    byte ACLKTR1     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 1 */
    byte ACLKTR2     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 2 */
    byte ACLKTR3     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 3 */
    byte ACLKTR4     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 4 */
    byte ACLKTR5     :1;                                       /* Autonomous Periodical Interrupt Period Trimming Bit 5 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpACLKTR :6;
  } MergedBits;
} CPMUACLKTRSTR;
extern volatile CPMUACLKTRSTR _CPMUACLKTR @0x000006D3;
#define CPMUACLKTR                      _CPMUACLKTR.Byte
#define CPMUACLKTR_ACLKTR0              _CPMUACLKTR.Bits.ACLKTR0
#define CPMUACLKTR_ACLKTR1              _CPMUACLKTR.Bits.ACLKTR1
#define CPMUACLKTR_ACLKTR2              _CPMUACLKTR.Bits.ACLKTR2
#define CPMUACLKTR_ACLKTR3              _CPMUACLKTR.Bits.ACLKTR3
#define CPMUACLKTR_ACLKTR4              _CPMUACLKTR.Bits.ACLKTR4
#define CPMUACLKTR_ACLKTR5              _CPMUACLKTR.Bits.ACLKTR5
#define CPMUACLKTR_ACLKTR               _CPMUACLKTR.MergedBits.grpACLKTR

#define CPMUACLKTR_ACLKTR0_MASK         4U
#define CPMUACLKTR_ACLKTR1_MASK         8U
#define CPMUACLKTR_ACLKTR2_MASK         16U
#define CPMUACLKTR_ACLKTR3_MASK         32U
#define CPMUACLKTR_ACLKTR4_MASK         64U
#define CPMUACLKTR_ACLKTR5_MASK         128U
#define CPMUACLKTR_ACLKTR_MASK          252U
#define CPMUACLKTR_ACLKTR_BITNUM        2U


/*** CPMUAPIR - Autonomous Periodical Interrupt Rate Register; 0x000006D4 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CPMUAPIRH - Autonomous Periodical Interrupt Rate Register High; 0x000006D4 ***/
    union {
      byte Byte;
      struct {
        byte APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
        byte APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
        byte APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
        byte APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
        byte APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
        byte APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
        byte APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
        byte APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
      } Bits;
    } CPMUAPIRHSTR;
    #define CPMUAPIRH                   _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Byte
    #define CPMUAPIRH_APIR8             _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR8
    #define CPMUAPIRH_APIR9             _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR9
    #define CPMUAPIRH_APIR10            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR10
    #define CPMUAPIRH_APIR11            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR11
    #define CPMUAPIRH_APIR12            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR12
    #define CPMUAPIRH_APIR13            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR13
    #define CPMUAPIRH_APIR14            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR14
    #define CPMUAPIRH_APIR15            _CPMUAPIR.Overlap_STR.CPMUAPIRHSTR.Bits.APIR15
    
    #define CPMUAPIRH_APIR8_MASK        1U
    #define CPMUAPIRH_APIR9_MASK        2U
    #define CPMUAPIRH_APIR10_MASK       4U
    #define CPMUAPIRH_APIR11_MASK       8U
    #define CPMUAPIRH_APIR12_MASK       16U
    #define CPMUAPIRH_APIR13_MASK       32U
    #define CPMUAPIRH_APIR14_MASK       64U
    #define CPMUAPIRH_APIR15_MASK       128U
    

    /*** CPMUAPIRL - Autonomous Periodical Interrupt Rate Register Low; 0x000006D5 ***/
    union {
      byte Byte;
      struct {
        byte APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
        byte APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
        byte APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
        byte APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
        byte APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
        byte APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
        byte APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
        byte APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
      } Bits;
    } CPMUAPIRLSTR;
    #define CPMUAPIRL                   _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Byte
    #define CPMUAPIRL_APIR0             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR0
    #define CPMUAPIRL_APIR1             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR1
    #define CPMUAPIRL_APIR2             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR2
    #define CPMUAPIRL_APIR3             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR3
    #define CPMUAPIRL_APIR4             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR4
    #define CPMUAPIRL_APIR5             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR5
    #define CPMUAPIRL_APIR6             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR6
    #define CPMUAPIRL_APIR7             _CPMUAPIR.Overlap_STR.CPMUAPIRLSTR.Bits.APIR7
    
    #define CPMUAPIRL_APIR0_MASK        1U
    #define CPMUAPIRL_APIR1_MASK        2U
    #define CPMUAPIRL_APIR2_MASK        4U
    #define CPMUAPIRL_APIR3_MASK        8U
    #define CPMUAPIRL_APIR4_MASK        16U
    #define CPMUAPIRL_APIR5_MASK        32U
    #define CPMUAPIRL_APIR6_MASK        64U
    #define CPMUAPIRL_APIR7_MASK        128U
    
  } Overlap_STR;

  struct {
    word APIR0       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 0 */
    word APIR1       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 1 */
    word APIR2       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 2 */
    word APIR3       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 3 */
    word APIR4       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 4 */
    word APIR5       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 5 */
    word APIR6       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 6 */
    word APIR7       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 7 */
    word APIR8       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 8 */
    word APIR9       :1;                                       /* Autonomous Periodical Interrupt Rate Bit 9 */
    word APIR10      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 10 */
    word APIR11      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 11 */
    word APIR12      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 12 */
    word APIR13      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 13 */
    word APIR14      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 14 */
    word APIR15      :1;                                       /* Autonomous Periodical Interrupt Rate Bit 15 */
  } Bits;
} CPMUAPIRSTR;
extern volatile CPMUAPIRSTR _CPMUAPIR @0x000006D4;
#define CPMUAPIR                        _CPMUAPIR.Word
#define CPMUAPIR_APIR0                  _CPMUAPIR.Bits.APIR0
#define CPMUAPIR_APIR1                  _CPMUAPIR.Bits.APIR1
#define CPMUAPIR_APIR2                  _CPMUAPIR.Bits.APIR2
#define CPMUAPIR_APIR3                  _CPMUAPIR.Bits.APIR3
#define CPMUAPIR_APIR4                  _CPMUAPIR.Bits.APIR4
#define CPMUAPIR_APIR5                  _CPMUAPIR.Bits.APIR5
#define CPMUAPIR_APIR6                  _CPMUAPIR.Bits.APIR6
#define CPMUAPIR_APIR7                  _CPMUAPIR.Bits.APIR7
#define CPMUAPIR_APIR8                  _CPMUAPIR.Bits.APIR8
#define CPMUAPIR_APIR9                  _CPMUAPIR.Bits.APIR9
#define CPMUAPIR_APIR10                 _CPMUAPIR.Bits.APIR10
#define CPMUAPIR_APIR11                 _CPMUAPIR.Bits.APIR11
#define CPMUAPIR_APIR12                 _CPMUAPIR.Bits.APIR12
#define CPMUAPIR_APIR13                 _CPMUAPIR.Bits.APIR13
#define CPMUAPIR_APIR14                 _CPMUAPIR.Bits.APIR14
#define CPMUAPIR_APIR15                 _CPMUAPIR.Bits.APIR15

#define CPMUAPIR_APIR0_MASK             1U
#define CPMUAPIR_APIR1_MASK             2U
#define CPMUAPIR_APIR2_MASK             4U
#define CPMUAPIR_APIR3_MASK             8U
#define CPMUAPIR_APIR4_MASK             16U
#define CPMUAPIR_APIR5_MASK             32U
#define CPMUAPIR_APIR6_MASK             64U
#define CPMUAPIR_APIR7_MASK             128U
#define CPMUAPIR_APIR8_MASK             256U
#define CPMUAPIR_APIR9_MASK             512U
#define CPMUAPIR_APIR10_MASK            1024U
#define CPMUAPIR_APIR11_MASK            2048U
#define CPMUAPIR_APIR12_MASK            4096U
#define CPMUAPIR_APIR13_MASK            8192U
#define CPMUAPIR_APIR14_MASK            16384U
#define CPMUAPIR_APIR15_MASK            32768U


/*** CPMUHTTR - High Temperature Trimming Register; 0x000006D7 ***/
typedef union {
  byte Byte;
  struct {
    byte HTTR        :4;                                       /* High Temperature Trimming Bits */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte HTOE        :1;                                       /* High Temperature Offeset Enable Bit */
  } Bits;
} CPMUHTTRSTR;
extern volatile CPMUHTTRSTR _CPMUHTTR @0x000006D7;
#define CPMUHTTR                        _CPMUHTTR.Byte
#define CPMUHTTR_HTTR                   _CPMUHTTR.Bits.HTTR
#define CPMUHTTR_HTOE                   _CPMUHTTR.Bits.HTOE

#define CPMUHTTR_HTTR_MASK              15U
#define CPMUHTTR_HTTR_BITNUM            0U
#define CPMUHTTR_HTOE_MASK              128U


/*** CPMUIRCTRIM - CPMU IRC1M Trim Registers; 0x000006D8 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CPMUIRCTRIMH - CPMU IRC1M Trim Registers High; 0x000006D8 ***/
    union {
      byte Byte;
      struct {
        byte IRCTRIM8    :1;                                       /* IRC1M Frequency Trim Bit 8 */
        byte IRCTRIM9    :1;                                       /* IRC1M Frequency Trim Bit 9 */
        byte             :1; 
        byte TCTRIM0     :1;                                       /* IRC1M temperature coeficient Trim Bit 0 */
        byte TCTRIM1     :1;                                       /* IRC1M temperature coeficient Trim Bit 1 */
        byte TCTRIM2     :1;                                       /* IRC1M temperature coeficient Trim Bit 2 */
        byte TCTRIM3     :1;                                       /* IRC1M temperature coeficient Trim Bit 3 */
        byte TCTRIM4     :1;                                       /* IRC1M temperature coeficient Trim Bit 4 */
      } Bits;
      struct {
        byte grpIRCTRIM_8 :2;
        byte     :1;
        byte grpTCTRIM :5;
      } MergedBits;
    } CPMUIRCTRIMHSTR;
    #define CPMUIRCTRIMH                _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Byte
    #define CPMUIRCTRIMH_IRCTRIM8       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.IRCTRIM8
    #define CPMUIRCTRIMH_IRCTRIM9       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.IRCTRIM9
    #define CPMUIRCTRIMH_TCTRIM0        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM0
    #define CPMUIRCTRIMH_TCTRIM1        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM1
    #define CPMUIRCTRIMH_TCTRIM2        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM2
    #define CPMUIRCTRIMH_TCTRIM3        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM3
    #define CPMUIRCTRIMH_TCTRIM4        _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.Bits.TCTRIM4
    #define CPMUIRCTRIMH_IRCTRIM_8      _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.MergedBits.grpIRCTRIM_8
    #define CPMUIRCTRIMH_TCTRIM         _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMHSTR.MergedBits.grpTCTRIM
    #define CPMUIRCTRIMH_IRCTRIM        CPMUIRCTRIMH_IRCTRIM_8
    
    #define CPMUIRCTRIMH_IRCTRIM8_MASK  1U
    #define CPMUIRCTRIMH_IRCTRIM9_MASK  2U
    #define CPMUIRCTRIMH_TCTRIM0_MASK   8U
    #define CPMUIRCTRIMH_TCTRIM1_MASK   16U
    #define CPMUIRCTRIMH_TCTRIM2_MASK   32U
    #define CPMUIRCTRIMH_TCTRIM3_MASK   64U
    #define CPMUIRCTRIMH_TCTRIM4_MASK   128U
    #define CPMUIRCTRIMH_IRCTRIM_8_MASK 3U
    #define CPMUIRCTRIMH_IRCTRIM_8_BITNUM 0U
    #define CPMUIRCTRIMH_TCTRIM_MASK    248U
    #define CPMUIRCTRIMH_TCTRIM_BITNUM  3U
    

    /*** CPMUIRCTRIML - CPMU IRC1M Trim Registers Low; 0x000006D9 ***/
    union {
      byte Byte;
      struct {
        byte IRCTRIM0    :1;                                       /* IRC1M Frequency Trim Bit 0 */
        byte IRCTRIM1    :1;                                       /* IRC1M Frequency Trim Bit 1 */
        byte IRCTRIM2    :1;                                       /* IRC1M Frequency Trim Bit 2 */
        byte IRCTRIM3    :1;                                       /* IRC1M Frequency Trim Bit 3 */
        byte IRCTRIM4    :1;                                       /* IRC1M Frequency Trim Bit 4 */
        byte IRCTRIM5    :1;                                       /* IRC1M Frequency Trim Bit 5 */
        byte IRCTRIM6    :1;                                       /* IRC1M Frequency Trim Bit 6 */
        byte IRCTRIM7    :1;                                       /* IRC1M Frequency Trim Bit 7 */
      } Bits;
    } CPMUIRCTRIMLSTR;
    #define CPMUIRCTRIML                _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Byte
    #define CPMUIRCTRIML_IRCTRIM0       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM0
    #define CPMUIRCTRIML_IRCTRIM1       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM1
    #define CPMUIRCTRIML_IRCTRIM2       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM2
    #define CPMUIRCTRIML_IRCTRIM3       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM3
    #define CPMUIRCTRIML_IRCTRIM4       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM4
    #define CPMUIRCTRIML_IRCTRIM5       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM5
    #define CPMUIRCTRIML_IRCTRIM6       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM6
    #define CPMUIRCTRIML_IRCTRIM7       _CPMUIRCTRIM.Overlap_STR.CPMUIRCTRIMLSTR.Bits.IRCTRIM7
    
    #define CPMUIRCTRIML_IRCTRIM0_MASK  1U
    #define CPMUIRCTRIML_IRCTRIM1_MASK  2U
    #define CPMUIRCTRIML_IRCTRIM2_MASK  4U
    #define CPMUIRCTRIML_IRCTRIM3_MASK  8U
    #define CPMUIRCTRIML_IRCTRIM4_MASK  16U
    #define CPMUIRCTRIML_IRCTRIM5_MASK  32U
    #define CPMUIRCTRIML_IRCTRIM6_MASK  64U
    #define CPMUIRCTRIML_IRCTRIM7_MASK  128U
    
  } Overlap_STR;

  struct {
    word IRCTRIM0    :1;                                       /* IRC1M Frequency Trim Bit 0 */
    word IRCTRIM1    :1;                                       /* IRC1M Frequency Trim Bit 1 */
    word IRCTRIM2    :1;                                       /* IRC1M Frequency Trim Bit 2 */
    word IRCTRIM3    :1;                                       /* IRC1M Frequency Trim Bit 3 */
    word IRCTRIM4    :1;                                       /* IRC1M Frequency Trim Bit 4 */
    word IRCTRIM5    :1;                                       /* IRC1M Frequency Trim Bit 5 */
    word IRCTRIM6    :1;                                       /* IRC1M Frequency Trim Bit 6 */
    word IRCTRIM7    :1;                                       /* IRC1M Frequency Trim Bit 7 */
    word IRCTRIM8    :1;                                       /* IRC1M Frequency Trim Bit 8 */
    word IRCTRIM9    :1;                                       /* IRC1M Frequency Trim Bit 9 */
    word             :1; 
    word TCTRIM0     :1;                                       /* IRC1M temperature coeficient Trim Bit 0 */
    word TCTRIM1     :1;                                       /* IRC1M temperature coeficient Trim Bit 1 */
    word TCTRIM2     :1;                                       /* IRC1M temperature coeficient Trim Bit 2 */
    word TCTRIM3     :1;                                       /* IRC1M temperature coeficient Trim Bit 3 */
    word TCTRIM4     :1;                                       /* IRC1M temperature coeficient Trim Bit 4 */
  } Bits;
  struct {
    word grpIRCTRIM :10;
    word         :1;
    word grpTCTRIM :5;
  } MergedBits;
} CPMUIRCTRIMSTR;
extern volatile CPMUIRCTRIMSTR _CPMUIRCTRIM @0x000006D8;
#define CPMUIRCTRIM                     _CPMUIRCTRIM.Word
#define CPMUIRCTRIM_IRCTRIM0            _CPMUIRCTRIM.Bits.IRCTRIM0
#define CPMUIRCTRIM_IRCTRIM1            _CPMUIRCTRIM.Bits.IRCTRIM1
#define CPMUIRCTRIM_IRCTRIM2            _CPMUIRCTRIM.Bits.IRCTRIM2
#define CPMUIRCTRIM_IRCTRIM3            _CPMUIRCTRIM.Bits.IRCTRIM3
#define CPMUIRCTRIM_IRCTRIM4            _CPMUIRCTRIM.Bits.IRCTRIM4
#define CPMUIRCTRIM_IRCTRIM5            _CPMUIRCTRIM.Bits.IRCTRIM5
#define CPMUIRCTRIM_IRCTRIM6            _CPMUIRCTRIM.Bits.IRCTRIM6
#define CPMUIRCTRIM_IRCTRIM7            _CPMUIRCTRIM.Bits.IRCTRIM7
#define CPMUIRCTRIM_IRCTRIM8            _CPMUIRCTRIM.Bits.IRCTRIM8
#define CPMUIRCTRIM_IRCTRIM9            _CPMUIRCTRIM.Bits.IRCTRIM9
#define CPMUIRCTRIM_TCTRIM0             _CPMUIRCTRIM.Bits.TCTRIM0
#define CPMUIRCTRIM_TCTRIM1             _CPMUIRCTRIM.Bits.TCTRIM1
#define CPMUIRCTRIM_TCTRIM2             _CPMUIRCTRIM.Bits.TCTRIM2
#define CPMUIRCTRIM_TCTRIM3             _CPMUIRCTRIM.Bits.TCTRIM3
#define CPMUIRCTRIM_TCTRIM4             _CPMUIRCTRIM.Bits.TCTRIM4
#define CPMUIRCTRIM_IRCTRIM             _CPMUIRCTRIM.MergedBits.grpIRCTRIM
#define CPMUIRCTRIM_TCTRIM              _CPMUIRCTRIM.MergedBits.grpTCTRIM

#define CPMUIRCTRIM_IRCTRIM0_MASK       1U
#define CPMUIRCTRIM_IRCTRIM1_MASK       2U
#define CPMUIRCTRIM_IRCTRIM2_MASK       4U
#define CPMUIRCTRIM_IRCTRIM3_MASK       8U
#define CPMUIRCTRIM_IRCTRIM4_MASK       16U
#define CPMUIRCTRIM_IRCTRIM5_MASK       32U
#define CPMUIRCTRIM_IRCTRIM6_MASK       64U
#define CPMUIRCTRIM_IRCTRIM7_MASK       128U
#define CPMUIRCTRIM_IRCTRIM8_MASK       256U
#define CPMUIRCTRIM_IRCTRIM9_MASK       512U
#define CPMUIRCTRIM_TCTRIM0_MASK        2048U
#define CPMUIRCTRIM_TCTRIM1_MASK        4096U
#define CPMUIRCTRIM_TCTRIM2_MASK        8192U
#define CPMUIRCTRIM_TCTRIM3_MASK        16384U
#define CPMUIRCTRIM_TCTRIM4_MASK        32768U
#define CPMUIRCTRIM_IRCTRIM_MASK        1023U
#define CPMUIRCTRIM_IRCTRIM_BITNUM      0U
#define CPMUIRCTRIM_TCTRIM_MASK         63488U
#define CPMUIRCTRIM_TCTRIM_BITNUM       11U


/*** CPMUOSC - CPMU Oscillator Register; 0x000006DA ***/
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
    byte OSCE        :1;                                       /* Oscillator Enable Bit */
  } Bits;
} CPMUOSCSTR;
extern volatile CPMUOSCSTR _CPMUOSC @0x000006DA;
#define CPMUOSC                         _CPMUOSC.Byte
#define CPMUOSC_OSCE                    _CPMUOSC.Bits.OSCE

#define CPMUOSC_OSCE_MASK               128U


/*** CPMUPROT - CPMUV1 Protection Register; 0x000006DB ***/
typedef union {
  byte Byte;
  struct {
    byte PROT        :1;                                       /* Clock Configuration Registers Protection Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUPROTSTR;
extern volatile CPMUPROTSTR _CPMUPROT @0x000006DB;
#define CPMUPROT                        _CPMUPROT.Byte
#define CPMUPROT_PROT                   _CPMUPROT.Bits.PROT

#define CPMUPROT_PROT_MASK              1U


/*** CPMUVREGCTL - Voltage Regulator Control Register; 0x000006DD ***/
typedef union {
  byte Byte;
  struct {
    byte INTXON      :1;                                       /* Internal voltage regulator Enable for VDDX domain */
    byte EXTXON      :1;                                       /* External voltage regulator Enable for VDDX domain */
    byte EXTCON      :1;                                       /* External voltage regulator Enable for VDDC domain */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUVREGCTLSTR;
extern volatile CPMUVREGCTLSTR _CPMUVREGCTL @0x000006DD;
#define CPMUVREGCTL                     _CPMUVREGCTL.Byte
#define CPMUVREGCTL_INTXON              _CPMUVREGCTL.Bits.INTXON
#define CPMUVREGCTL_EXTXON              _CPMUVREGCTL.Bits.EXTXON
#define CPMUVREGCTL_EXTCON              _CPMUVREGCTL.Bits.EXTCON

#define CPMUVREGCTL_INTXON_MASK         1U
#define CPMUVREGCTL_EXTXON_MASK         2U
#define CPMUVREGCTL_EXTCON_MASK         4U


/*** CPMUOSC2 - CPMU Oscillator Register 2; 0x000006DE ***/
typedef union {
  byte Byte;
  struct {
    byte OSCMOD      :1;                                       /* This bit selects the mode of the external oscillator (XOSCLCP) */
    byte OMRE        :1;                                       /* This bit enables the oscillator clock monitor reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CPMUOSC2STR;
extern volatile CPMUOSC2STR _CPMUOSC2 @0x000006DE;
#define CPMUOSC2                        _CPMUOSC2.Byte
#define CPMUOSC2_OSCMOD                 _CPMUOSC2.Bits.OSCMOD
#define CPMUOSC2_OMRE                   _CPMUOSC2.Bits.OMRE

#define CPMUOSC2_OSCMOD_MASK            1U
#define CPMUOSC2_OMRE_MASK              2U


/*** BATE - BATS Module Enable Register; 0x000006F0 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte BSUSE       :1;                                       /* BATS VSUP Level Sense Enable */
    byte BSUAE       :1;                                       /* BATS VSUP ADC Connection Enable */
    byte BVLS        :2;                                       /* BATS Voltage Low Select */
    byte BVHS        :1;                                       /* BATS Voltage High Select */
    byte             :1; 
  } Bits;
} BATESTR;
extern volatile BATESTR _BATE @0x000006F0;
#define BATE                            _BATE.Byte
#define BATE_BSUSE                      _BATE.Bits.BSUSE
#define BATE_BSUAE                      _BATE.Bits.BSUAE
#define BATE_BVLS                       _BATE.Bits.BVLS
#define BATE_BVHS                       _BATE.Bits.BVHS

#define BATE_BSUSE_MASK                 4U
#define BATE_BSUAE_MASK                 8U
#define BATE_BVLS_MASK                  48U
#define BATE_BVLS_BITNUM                4U
#define BATE_BVHS_MASK                  64U


/*** BATSR - BATS Module Status Register; 0x000006F1 ***/
typedef union {
  byte Byte;
  struct {
    byte BVLC        :1;                                       /* BATS Voltage Sense Low Condition Bit */
    byte BVHC        :1;                                       /* BATS Voltage Sense High Condition Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} BATSRSTR;
extern volatile BATSRSTR _BATSR @0x000006F1;
#define BATSR                           _BATSR.Byte
#define BATSR_BVLC                      _BATSR.Bits.BVLC
#define BATSR_BVHC                      _BATSR.Bits.BVHC

#define BATSR_BVLC_MASK                 1U
#define BATSR_BVHC_MASK                 2U


/*** BATIE - BATS Interrupt Enable Register; 0x000006F2 ***/
typedef union {
  byte Byte;
  struct {
    byte BVLIE       :1;                                       /* BATS Interrupt Enable Low */
    byte BVHIE       :1;                                       /* BATS Interrupt Enable High */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} BATIESTR;
extern volatile BATIESTR _BATIE @0x000006F2;
#define BATIE                           _BATIE.Byte
#define BATIE_BVLIE                     _BATIE.Bits.BVLIE
#define BATIE_BVHIE                     _BATIE.Bits.BVHIE

#define BATIE_BVLIE_MASK                1U
#define BATIE_BVHIE_MASK                2U


/*** BATIF - BATS Interrupt Flag Register; 0x000006F3 ***/
typedef union {
  byte Byte;
  struct {
    byte BVLIF       :1;                                       /* BATS Interrupt Flag Low Detect */
    byte BVHIF       :1;                                       /* BATS Interrupt Flag High Detect */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} BATIFSTR;
extern volatile BATIFSTR _BATIF @0x000006F3;
#define BATIF                           _BATIF.Byte
#define BATIF_BVLIF                     _BATIF.Bits.BVLIF
#define BATIF_BVHIF                     _BATIF.Bits.BVHIF

#define BATIF_BVLIF_MASK                1U
#define BATIF_BVHIF_MASK                2U


/*** SCI0BD - SCI 0 Baud Rate Register; 0x00000700 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI0ASR1 - SCI 0 Alternative Status Register 1; 0x00000700 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI0ASR1 - SCI 0 Alternative Status Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIF       :1;                                       /* Break Detect Interrupt Flag */
            byte BERRIF      :1;                                       /* Bit Error Interrupt Flag */
            byte BERRV       :1;                                       /* Bit Error Value */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIF     :1;                                       /* Receive Input Active Edge Interrupt Flag */
          } Bits;
        } SCI0ASR1STR;
        #define SCI0ASR1                _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0ASR1_BKDIF          _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BKDIF
        #define SCI0ASR1_BERRIF         _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BERRIF
        #define SCI0ASR1_BERRV          _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.BERRV
        #define SCI0ASR1_RXEDGIF        _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0ASR1STR.Bits.RXEDGIF
        
        #define SCI0ASR1_BKDIF_MASK     1U
        #define SCI0ASR1_BERRIF_MASK    2U
        #define SCI0ASR1_BERRV_MASK     4U
        #define SCI0ASR1_RXEDGIF_MASK   128U
        
        /*** SCI0BDH - SCI 0 Baud Rate Register High; Several registers at the same address ***/
        union {
          struct {
            byte SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
            byte SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
            byte SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
            byte SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
            byte SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
            byte SBR13       :1;                                       /* SCI Baud Rate Bit 13 */
            byte SBR14       :1;                                       /* SCI Baud Rate Bit 14 */
            byte SBR15       :1;                                       /* SCI Baud Rate Bit 15 */
          } Bits;
        } SCI0BDHSTR;
        #define SCI0BDH                 _SCI0BD.Overlap_STR.SCI0ASR1STR.Byte
        #define SCI0BDH_SBR8            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR8
        #define SCI0BDH_SBR9            _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR9
        #define SCI0BDH_SBR10           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR10
        #define SCI0BDH_SBR11           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR11
        #define SCI0BDH_SBR12           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR12
        #define SCI0BDH_SBR13           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR13
        #define SCI0BDH_SBR14           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR14
        #define SCI0BDH_SBR15           _SCI0BD.Overlap_STR.SCI0ASR1STR.SameAddr_STR.SCI0BDHSTR.Bits.SBR15
        
        #define SCI0BDH_SBR8_MASK       1U
        #define SCI0BDH_SBR9_MASK       2U
        #define SCI0BDH_SBR10_MASK      4U
        #define SCI0BDH_SBR11_MASK      8U
        #define SCI0BDH_SBR12_MASK      16U
        #define SCI0BDH_SBR13_MASK      32U
        #define SCI0BDH_SBR14_MASK      64U
        #define SCI0BDH_SBR15_MASK      128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI0ASR1STR;
    

    /*** SCI0ACR1 - SCI 0 Alternative Control Register 1; 0x00000701 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI0ACR1 - SCI 0 Alternative Control Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIE       :1;                                       /* Break Detect Interrupt Enable */
            byte BERRIE      :1;                                       /* Bit Error Interrupt Enable */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIE     :1;                                       /* Receive Input Active Edge Interrupt Enable */
          } Bits;
        } SCI0ACR1STR;
        #define SCI0ACR1                _SCI0BD.Overlap_STR.SCI0ACR1STR.Byte
        #define SCI0ACR1_BKDIE          _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.BKDIE
        #define SCI0ACR1_BERRIE         _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.BERRIE
        #define SCI0ACR1_RXEDGIE        _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0ACR1STR.Bits.RXEDGIE
        
        #define SCI0ACR1_BKDIE_MASK     1U
        #define SCI0ACR1_BERRIE_MASK    2U
        #define SCI0ACR1_RXEDGIE_MASK   128U
        
        /*** SCI0BDL - SCI 0 Baud Rate Register Low; Several registers at the same address ***/
        union {
          struct {
            byte SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
            byte SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
            byte SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
            byte SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
            byte SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
            byte SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
            byte SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
            byte SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
          } Bits;
        } SCI0BDLSTR;
        #define SCI0BDL                 _SCI0BD.Overlap_STR.SCI0ACR1STR.Byte
        #define SCI0BDL_SBR0            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR0
        #define SCI0BDL_SBR1            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR1
        #define SCI0BDL_SBR2            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR2
        #define SCI0BDL_SBR3            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR3
        #define SCI0BDL_SBR4            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR4
        #define SCI0BDL_SBR5            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR5
        #define SCI0BDL_SBR6            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR6
        #define SCI0BDL_SBR7            _SCI0BD.Overlap_STR.SCI0ACR1STR.SameAddr_STR.SCI0BDLSTR.Bits.SBR7
        
        #define SCI0BDL_SBR0_MASK       1U
        #define SCI0BDL_SBR1_MASK       2U
        #define SCI0BDL_SBR2_MASK       4U
        #define SCI0BDL_SBR3_MASK       8U
        #define SCI0BDL_SBR4_MASK       16U
        #define SCI0BDL_SBR5_MASK       32U
        #define SCI0BDL_SBR6_MASK       64U
        #define SCI0BDL_SBR7_MASK       128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI0ACR1STR;
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
    word SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
    word SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
    word SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
    word SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
    word SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
    word SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
    word SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
    word SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
    word SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
    word SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
    word SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
    word SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
    word SBR13       :1;                                       /* SCI Baud Rate Bit 13 */
    word SBR14       :1;                                       /* SCI Baud Rate Bit 14 */
    word SBR15       :1;                                       /* SCI Baud Rate Bit 15 */
  } Bits;
} SCI0BDSTR;
extern volatile SCI0BDSTR _SCI0BD @0x00000700;
#define SCI0BD                          _SCI0BD.Word
#define SCI0BD_SBR0                     _SCI0BD.Bits.SBR0
#define SCI0BD_SBR1                     _SCI0BD.Bits.SBR1
#define SCI0BD_SBR2                     _SCI0BD.Bits.SBR2
#define SCI0BD_SBR3                     _SCI0BD.Bits.SBR3
#define SCI0BD_SBR4                     _SCI0BD.Bits.SBR4
#define SCI0BD_SBR5                     _SCI0BD.Bits.SBR5
#define SCI0BD_SBR6                     _SCI0BD.Bits.SBR6
#define SCI0BD_SBR7                     _SCI0BD.Bits.SBR7
#define SCI0BD_SBR8                     _SCI0BD.Bits.SBR8
#define SCI0BD_SBR9                     _SCI0BD.Bits.SBR9
#define SCI0BD_SBR10                    _SCI0BD.Bits.SBR10
#define SCI0BD_SBR11                    _SCI0BD.Bits.SBR11
#define SCI0BD_SBR12                    _SCI0BD.Bits.SBR12
#define SCI0BD_SBR13                    _SCI0BD.Bits.SBR13
#define SCI0BD_SBR14                    _SCI0BD.Bits.SBR14
#define SCI0BD_SBR15                    _SCI0BD.Bits.SBR15

#define SCI0BD_SBR0_MASK                1U
#define SCI0BD_SBR1_MASK                2U
#define SCI0BD_SBR2_MASK                4U
#define SCI0BD_SBR3_MASK                8U
#define SCI0BD_SBR4_MASK                16U
#define SCI0BD_SBR5_MASK                32U
#define SCI0BD_SBR6_MASK                64U
#define SCI0BD_SBR7_MASK                128U
#define SCI0BD_SBR8_MASK                256U
#define SCI0BD_SBR9_MASK                512U
#define SCI0BD_SBR10_MASK               1024U
#define SCI0BD_SBR11_MASK               2048U
#define SCI0BD_SBR12_MASK               4096U
#define SCI0BD_SBR13_MASK               8192U
#define SCI0BD_SBR14_MASK               16384U
#define SCI0BD_SBR15_MASK               32768U


/*** SCI0ACR2 - SCI 0 Alternative Control Register 2; 0x00000702 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** SCI0ACR2 - SCI 0 Alternative Control Register 2; Several registers at the same address ***/
    union {
      struct {
        byte BKDFE       :1;                                       /* Break Detect Feature Enable */
        byte BERRM0      :1;                                       /* Bit Error Mode 0 */
        byte BERRM1      :1;                                       /* Bit Error Mode 1 */
        byte             :1; 
        byte             :1; 
        byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
        byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
        byte IREN        :1;                                       /* Infrared Enable Bit */
      } Bits;
      struct {
        byte     :1;
        byte grpBERRM :2;
        byte     :1;
        byte     :1;
        byte grpTNP :2;
        byte     :1;
      } MergedBits;
    } SCI0ACR2STR;
    #define SCI0ACR2                    _SCI0ACR2.Byte
    #define SCI0ACR2_BKDFE              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BKDFE
    #define SCI0ACR2_BERRM0             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM0
    #define SCI0ACR2_BERRM1             _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.BERRM1
    #define SCI0ACR2_TNP0               _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.TNP0
    #define SCI0ACR2_TNP1               _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.TNP1
    #define SCI0ACR2_IREN               _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.Bits.IREN
    #define SCI0ACR2_BERRM              _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.MergedBits.grpBERRM
    #define SCI0ACR2_TNP                _SCI0ACR2.SameAddr_STR.SCI0ACR2STR.MergedBits.grpTNP
    
    #define SCI0ACR2_BKDFE_MASK         1U
    #define SCI0ACR2_BERRM0_MASK        2U
    #define SCI0ACR2_BERRM1_MASK        4U
    #define SCI0ACR2_TNP0_MASK          32U
    #define SCI0ACR2_TNP1_MASK          64U
    #define SCI0ACR2_IREN_MASK          128U
    #define SCI0ACR2_BERRM_MASK         6U
    #define SCI0ACR2_BERRM_BITNUM       1U
    #define SCI0ACR2_TNP_MASK           96U
    #define SCI0ACR2_TNP_BITNUM         5U
    
    /*** SCI0CR1 - SCI 0 Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte PT          :1;                                       /* Parity Type Bit */
        byte PE          :1;                                       /* Parity Enable Bit */
        byte ILT         :1;                                       /* Idle Line Type Bit */
        byte WAKE        :1;                                       /* Wakeup Condition Bit */
        byte M           :1;                                       /* Data Format Mode Bit */
        byte RSRC        :1;                                       /* Receiver Source Bit */
        byte SCISWAI     :1;                                       /* SCI Stop in Wait Mode Bit */
        byte LOOPS       :1;                                       /* Loop Select Bit */
      } Bits;
    } SCI0CR1STR;
    #define SCI0CR1                     _SCI0ACR2.Byte
    #define SCI0CR1_PT                  _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.PT
    #define SCI0CR1_PE                  _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.PE
    #define SCI0CR1_ILT                 _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.ILT
    #define SCI0CR1_WAKE                _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.WAKE
    #define SCI0CR1_M                   _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.M
    #define SCI0CR1_RSRC                _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.RSRC
    #define SCI0CR1_SCISWAI             _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.SCISWAI
    #define SCI0CR1_LOOPS               _SCI0ACR2.SameAddr_STR.SCI0CR1STR.Bits.LOOPS
    
    #define SCI0CR1_PT_MASK             1U
    #define SCI0CR1_PE_MASK             2U
    #define SCI0CR1_ILT_MASK            4U
    #define SCI0CR1_WAKE_MASK           8U
    #define SCI0CR1_M_MASK              16U
    #define SCI0CR1_RSRC_MASK           32U
    #define SCI0CR1_SCISWAI_MASK        64U
    #define SCI0CR1_LOOPS_MASK          128U
    
  } SameAddr_STR; /*Several registers at the same address */

} SCI0ACR2STR;
extern volatile SCI0ACR2STR _SCI0ACR2 @0x00000702;


/*** SCI0CR2 - SCI 0 Control Register 2; 0x00000703 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte TIE         :1;                                       /* Transmitter Interrupt Enable Bit */
  } Bits;
} SCI0CR2STR;
extern volatile SCI0CR2STR _SCI0CR2 @0x00000703;
#define SCI0CR2                         _SCI0CR2.Byte
#define SCI0CR2_SBK                     _SCI0CR2.Bits.SBK
#define SCI0CR2_RWU                     _SCI0CR2.Bits.RWU
#define SCI0CR2_RE                      _SCI0CR2.Bits.RE
#define SCI0CR2_TE                      _SCI0CR2.Bits.TE
#define SCI0CR2_ILIE                    _SCI0CR2.Bits.ILIE
#define SCI0CR2_RIE                     _SCI0CR2.Bits.RIE
#define SCI0CR2_TCIE                    _SCI0CR2.Bits.TCIE
#define SCI0CR2_TIE                     _SCI0CR2.Bits.TIE

#define SCI0CR2_SBK_MASK                1U
#define SCI0CR2_RWU_MASK                2U
#define SCI0CR2_RE_MASK                 4U
#define SCI0CR2_TE_MASK                 8U
#define SCI0CR2_ILIE_MASK               16U
#define SCI0CR2_RIE_MASK                32U
#define SCI0CR2_TCIE_MASK               64U
#define SCI0CR2_TIE_MASK                128U


/*** SCI0SR1 - SCI 0 Status Register 1; 0x00000704 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI0SR1STR;
extern volatile SCI0SR1STR _SCI0SR1 @0x00000704;
#define SCI0SR1                         _SCI0SR1.Byte
#define SCI0SR1_PF                      _SCI0SR1.Bits.PF
#define SCI0SR1_FE                      _SCI0SR1.Bits.FE
#define SCI0SR1_NF                      _SCI0SR1.Bits.NF
#define SCI0SR1_OR                      _SCI0SR1.Bits.OR
#define SCI0SR1_IDLE                    _SCI0SR1.Bits.IDLE
#define SCI0SR1_RDRF                    _SCI0SR1.Bits.RDRF
#define SCI0SR1_TC                      _SCI0SR1.Bits.TC
#define SCI0SR1_TDRE                    _SCI0SR1.Bits.TDRE

#define SCI0SR1_PF_MASK                 1U
#define SCI0SR1_FE_MASK                 2U
#define SCI0SR1_NF_MASK                 4U
#define SCI0SR1_OR_MASK                 8U
#define SCI0SR1_IDLE_MASK               16U
#define SCI0SR1_RDRF_MASK               32U
#define SCI0SR1_TC_MASK                 64U
#define SCI0SR1_TDRE_MASK               128U


/*** SCI0SR2 - SCI 0 Status Register 2; 0x00000705 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte RXPOL       :1;                                       /* Receive Polarity */
    byte TXPOL       :1;                                       /* Transmit Polarity */
    byte             :1; 
    byte             :1; 
    byte AMAP        :1;                                       /* Alternative Map */
  } Bits;
} SCI0SR2STR;
extern volatile SCI0SR2STR _SCI0SR2 @0x00000705;
#define SCI0SR2                         _SCI0SR2.Byte
#define SCI0SR2_RAF                     _SCI0SR2.Bits.RAF
#define SCI0SR2_TXDIR                   _SCI0SR2.Bits.TXDIR
#define SCI0SR2_BRK13                   _SCI0SR2.Bits.BRK13
#define SCI0SR2_RXPOL                   _SCI0SR2.Bits.RXPOL
#define SCI0SR2_TXPOL                   _SCI0SR2.Bits.TXPOL
#define SCI0SR2_AMAP                    _SCI0SR2.Bits.AMAP

#define SCI0SR2_RAF_MASK                1U
#define SCI0SR2_TXDIR_MASK              2U
#define SCI0SR2_BRK13_MASK              4U
#define SCI0SR2_RXPOL_MASK              8U
#define SCI0SR2_TXPOL_MASK              16U
#define SCI0SR2_AMAP_MASK               128U


/*** SCI0DRH - SCI 0 Data Register High; 0x00000706 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI0DRHSTR;
extern volatile SCI0DRHSTR _SCI0DRH @0x00000706;
#define SCI0DRH                         _SCI0DRH.Byte
#define SCI0DRH_T8                      _SCI0DRH.Bits.T8
#define SCI0DRH_R8                      _SCI0DRH.Bits.R8

#define SCI0DRH_T8_MASK                 64U
#define SCI0DRH_R8_MASK                 128U


/*** SCI0DRL - SCI 0 Data Register Low; 0x00000707 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI0DRLSTR;
extern volatile SCI0DRLSTR _SCI0DRL @0x00000707;
#define SCI0DRL                         _SCI0DRL.Byte
#define SCI0DRL_R0_T0                   _SCI0DRL.Bits.R0_T0
#define SCI0DRL_R1_T1                   _SCI0DRL.Bits.R1_T1
#define SCI0DRL_R2_T2                   _SCI0DRL.Bits.R2_T2
#define SCI0DRL_R3_T3                   _SCI0DRL.Bits.R3_T3
#define SCI0DRL_R4_T4                   _SCI0DRL.Bits.R4_T4
#define SCI0DRL_R5_T5                   _SCI0DRL.Bits.R5_T5
#define SCI0DRL_R6_T6                   _SCI0DRL.Bits.R6_T6
#define SCI0DRL_R7_T7                   _SCI0DRL.Bits.R7_T7

#define SCI0DRL_R0_T0_MASK              1U
#define SCI0DRL_R1_T1_MASK              2U
#define SCI0DRL_R2_T2_MASK              4U
#define SCI0DRL_R3_T3_MASK              8U
#define SCI0DRL_R4_T4_MASK              16U
#define SCI0DRL_R5_T5_MASK              32U
#define SCI0DRL_R6_T6_MASK              64U
#define SCI0DRL_R7_T7_MASK              128U


/*** SCI1BD - SCI 1 Baud Rate Register; 0x00000710 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCI1ASR1 - SCI 1 Alternative Status Register 1; 0x00000710 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI1ASR1 - SCI 1 Alternative Status Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIF       :1;                                       /* Break Detect Interrupt Flag */
            byte BERRIF      :1;                                       /* Bit Error Interrupt Flag */
            byte BERRV       :1;                                       /* Bit Error Value */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIF     :1;                                       /* Receive Input Active Edge Interrupt Flag */
          } Bits;
        } SCI1ASR1STR;
        #define SCI1ASR1                _SCI1BD.Overlap_STR.SCI1ASR1STR.Byte
        #define SCI1ASR1_BKDIF          _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BKDIF
        #define SCI1ASR1_BERRIF         _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BERRIF
        #define SCI1ASR1_BERRV          _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.BERRV
        #define SCI1ASR1_RXEDGIF        _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1ASR1STR.Bits.RXEDGIF
        
        #define SCI1ASR1_BKDIF_MASK     1U
        #define SCI1ASR1_BERRIF_MASK    2U
        #define SCI1ASR1_BERRV_MASK     4U
        #define SCI1ASR1_RXEDGIF_MASK   128U
        
        /*** SCI1BDH - SCI 1 Baud Rate Register High; Several registers at the same address ***/
        union {
          struct {
            byte SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
            byte SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
            byte SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
            byte SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
            byte SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
            byte SBR13       :1;                                       /* SCI Baud Rate Bit 13 */
            byte SBR14       :1;                                       /* SCI Baud Rate Bit 14 */
            byte SBR15       :1;                                       /* SCI Baud Rate Bit 15 */
          } Bits;
        } SCI1BDHSTR;
        #define SCI1BDH                 _SCI1BD.Overlap_STR.SCI1ASR1STR.Byte
        #define SCI1BDH_SBR8            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR8
        #define SCI1BDH_SBR9            _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR9
        #define SCI1BDH_SBR10           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR10
        #define SCI1BDH_SBR11           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR11
        #define SCI1BDH_SBR12           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR12
        #define SCI1BDH_SBR13           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR13
        #define SCI1BDH_SBR14           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR14
        #define SCI1BDH_SBR15           _SCI1BD.Overlap_STR.SCI1ASR1STR.SameAddr_STR.SCI1BDHSTR.Bits.SBR15
        
        #define SCI1BDH_SBR8_MASK       1U
        #define SCI1BDH_SBR9_MASK       2U
        #define SCI1BDH_SBR10_MASK      4U
        #define SCI1BDH_SBR11_MASK      8U
        #define SCI1BDH_SBR12_MASK      16U
        #define SCI1BDH_SBR13_MASK      32U
        #define SCI1BDH_SBR14_MASK      64U
        #define SCI1BDH_SBR15_MASK      128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI1ASR1STR;
    

    /*** SCI1ACR1 - SCI 1 Alternative Control Register 1; 0x00000711 ***/
    union {
      byte Byte;
      union { /* Several registers at the same address */
        /*** SCI1ACR1 - SCI 1 Alternative Control Register 1; Several registers at the same address ***/
        union {
          struct {
            byte BKDIE       :1;                                       /* Break Detect Interrupt Enable */
            byte BERRIE      :1;                                       /* Bit Error Interrupt Enable */
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte             :1; 
            byte RXEDGIE     :1;                                       /* Receive Input Active Edge Interrupt Enable */
          } Bits;
        } SCI1ACR1STR;
        #define SCI1ACR1                _SCI1BD.Overlap_STR.SCI1ACR1STR.Byte
        #define SCI1ACR1_BKDIE          _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.BKDIE
        #define SCI1ACR1_BERRIE         _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.BERRIE
        #define SCI1ACR1_RXEDGIE        _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1ACR1STR.Bits.RXEDGIE
        
        #define SCI1ACR1_BKDIE_MASK     1U
        #define SCI1ACR1_BERRIE_MASK    2U
        #define SCI1ACR1_RXEDGIE_MASK   128U
        
        /*** SCI1BDL - SCI 1 Baud Rate Register Low; Several registers at the same address ***/
        union {
          struct {
            byte SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
            byte SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
            byte SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
            byte SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
            byte SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
            byte SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
            byte SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
            byte SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
          } Bits;
        } SCI1BDLSTR;
        #define SCI1BDL                 _SCI1BD.Overlap_STR.SCI1ACR1STR.Byte
        #define SCI1BDL_SBR0            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR0
        #define SCI1BDL_SBR1            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR1
        #define SCI1BDL_SBR2            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR2
        #define SCI1BDL_SBR3            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR3
        #define SCI1BDL_SBR4            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR4
        #define SCI1BDL_SBR5            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR5
        #define SCI1BDL_SBR6            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR6
        #define SCI1BDL_SBR7            _SCI1BD.Overlap_STR.SCI1ACR1STR.SameAddr_STR.SCI1BDLSTR.Bits.SBR7
        
        #define SCI1BDL_SBR0_MASK       1U
        #define SCI1BDL_SBR1_MASK       2U
        #define SCI1BDL_SBR2_MASK       4U
        #define SCI1BDL_SBR3_MASK       8U
        #define SCI1BDL_SBR4_MASK       16U
        #define SCI1BDL_SBR5_MASK       32U
        #define SCI1BDL_SBR6_MASK       64U
        #define SCI1BDL_SBR7_MASK       128U
        
      } SameAddr_STR; /*Several registers at the same address */
    
    } SCI1ACR1STR;
    
  } Overlap_STR;

  struct {
    word SBR0        :1;                                       /* SCI Baud Rate Bit 0 */
    word SBR1        :1;                                       /* SCI Baud Rate Bit 1 */
    word SBR2        :1;                                       /* SCI Baud Rate Bit 2 */
    word SBR3        :1;                                       /* SCI Baud Rate Bit 3 */
    word SBR4        :1;                                       /* SCI Baud Rate Bit 4 */
    word SBR5        :1;                                       /* SCI Baud Rate Bit 5 */
    word SBR6        :1;                                       /* SCI Baud Rate Bit 6 */
    word SBR7        :1;                                       /* SCI Baud Rate Bit 7 */
    word SBR8        :1;                                       /* SCI Baud Rate Bit 8 */
    word SBR9        :1;                                       /* SCI Baud Rate Bit 9 */
    word SBR10       :1;                                       /* SCI Baud Rate Bit 10 */
    word SBR11       :1;                                       /* SCI Baud Rate Bit 11 */
    word SBR12       :1;                                       /* SCI Baud Rate Bit 12 */
    word SBR13       :1;                                       /* SCI Baud Rate Bit 13 */
    word SBR14       :1;                                       /* SCI Baud Rate Bit 14 */
    word SBR15       :1;                                       /* SCI Baud Rate Bit 15 */
  } Bits;
} SCI1BDSTR;
extern volatile SCI1BDSTR _SCI1BD @0x00000710;
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
#define SCI1BD_SBR13                    _SCI1BD.Bits.SBR13
#define SCI1BD_SBR14                    _SCI1BD.Bits.SBR14
#define SCI1BD_SBR15                    _SCI1BD.Bits.SBR15

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
#define SCI1BD_SBR13_MASK               8192U
#define SCI1BD_SBR14_MASK               16384U
#define SCI1BD_SBR15_MASK               32768U


/*** SCI1ACR2 - SCI 1 Alternative Control Register 2; 0x00000712 ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** SCI1ACR2 - SCI 1 Alternative Control Register 2; Several registers at the same address ***/
    union {
      struct {
        byte BKDFE       :1;                                       /* Break Detect Feature Enable */
        byte BERRM0      :1;                                       /* Bit Error Mode 0 */
        byte BERRM1      :1;                                       /* Bit Error Mode 1 */
        byte             :1; 
        byte             :1; 
        byte TNP0        :1;                                       /* Transmitter Narrow Pulse Bit 0 */
        byte TNP1        :1;                                       /* Transmitter Narrow Pulse Bit 1 */
        byte IREN        :1;                                       /* Infrared Enable Bit */
      } Bits;
      struct {
        byte     :1;
        byte grpBERRM :2;
        byte     :1;
        byte     :1;
        byte grpTNP :2;
        byte     :1;
      } MergedBits;
    } SCI1ACR2STR;
    #define SCI1ACR2                    _SCI1ACR2.Byte
    #define SCI1ACR2_BKDFE              _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BKDFE
    #define SCI1ACR2_BERRM0             _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BERRM0
    #define SCI1ACR2_BERRM1             _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.BERRM1
    #define SCI1ACR2_TNP0               _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.TNP0
    #define SCI1ACR2_TNP1               _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.TNP1
    #define SCI1ACR2_IREN               _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.Bits.IREN
    #define SCI1ACR2_BERRM              _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.MergedBits.grpBERRM
    #define SCI1ACR2_TNP                _SCI1ACR2.SameAddr_STR.SCI1ACR2STR.MergedBits.grpTNP
    
    #define SCI1ACR2_BKDFE_MASK         1U
    #define SCI1ACR2_BERRM0_MASK        2U
    #define SCI1ACR2_BERRM1_MASK        4U
    #define SCI1ACR2_TNP0_MASK          32U
    #define SCI1ACR2_TNP1_MASK          64U
    #define SCI1ACR2_IREN_MASK          128U
    #define SCI1ACR2_BERRM_MASK         6U
    #define SCI1ACR2_BERRM_BITNUM       1U
    #define SCI1ACR2_TNP_MASK           96U
    #define SCI1ACR2_TNP_BITNUM         5U
    
    /*** SCI1CR1 - SCI 1 Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte PT          :1;                                       /* Parity Type Bit */
        byte PE          :1;                                       /* Parity Enable Bit */
        byte ILT         :1;                                       /* Idle Line Type Bit */
        byte WAKE        :1;                                       /* Wakeup Condition Bit */
        byte M           :1;                                       /* Data Format Mode Bit */
        byte RSRC        :1;                                       /* Receiver Source Bit */
        byte SCISWAI     :1;                                       /* SCI Stop in Wait Mode Bit */
        byte LOOPS       :1;                                       /* Loop Select Bit */
      } Bits;
    } SCI1CR1STR;
    #define SCI1CR1                     _SCI1ACR2.Byte
    #define SCI1CR1_PT                  _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.PT
    #define SCI1CR1_PE                  _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.PE
    #define SCI1CR1_ILT                 _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.ILT
    #define SCI1CR1_WAKE                _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.WAKE
    #define SCI1CR1_M                   _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.M
    #define SCI1CR1_RSRC                _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.RSRC
    #define SCI1CR1_SCISWAI             _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.SCISWAI
    #define SCI1CR1_LOOPS               _SCI1ACR2.SameAddr_STR.SCI1CR1STR.Bits.LOOPS
    
    #define SCI1CR1_PT_MASK             1U
    #define SCI1CR1_PE_MASK             2U
    #define SCI1CR1_ILT_MASK            4U
    #define SCI1CR1_WAKE_MASK           8U
    #define SCI1CR1_M_MASK              16U
    #define SCI1CR1_RSRC_MASK           32U
    #define SCI1CR1_SCISWAI_MASK        64U
    #define SCI1CR1_LOOPS_MASK          128U
    
  } SameAddr_STR; /*Several registers at the same address */

} SCI1ACR2STR;
extern volatile SCI1ACR2STR _SCI1ACR2 @0x00000712;


/*** SCI1CR2 - SCI 1 Control Register 2; 0x00000713 ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break Bit */
    byte RWU         :1;                                       /* Receiver Wakeup Bit */
    byte RE          :1;                                       /* Receiver Enable Bit */
    byte TE          :1;                                       /* Transmitter Enable Bit */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable Bit */
    byte RIE         :1;                                       /* Receiver Full Interrupt Enable Bit */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable Bit */
    byte TIE         :1;                                       /* Transmitter Interrupt Enable Bit */
  } Bits;
} SCI1CR2STR;
extern volatile SCI1CR2STR _SCI1CR2 @0x00000713;
#define SCI1CR2                         _SCI1CR2.Byte
#define SCI1CR2_SBK                     _SCI1CR2.Bits.SBK
#define SCI1CR2_RWU                     _SCI1CR2.Bits.RWU
#define SCI1CR2_RE                      _SCI1CR2.Bits.RE
#define SCI1CR2_TE                      _SCI1CR2.Bits.TE
#define SCI1CR2_ILIE                    _SCI1CR2.Bits.ILIE
#define SCI1CR2_RIE                     _SCI1CR2.Bits.RIE
#define SCI1CR2_TCIE                    _SCI1CR2.Bits.TCIE
#define SCI1CR2_TIE                     _SCI1CR2.Bits.TIE

#define SCI1CR2_SBK_MASK                1U
#define SCI1CR2_RWU_MASK                2U
#define SCI1CR2_RE_MASK                 4U
#define SCI1CR2_TE_MASK                 8U
#define SCI1CR2_ILIE_MASK               16U
#define SCI1CR2_RIE_MASK                32U
#define SCI1CR2_TCIE_MASK               64U
#define SCI1CR2_TIE_MASK                128U


/*** SCI1SR1 - SCI 1 Status Register 1; 0x00000714 ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmit Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCI1SR1STR;
extern volatile SCI1SR1STR _SCI1SR1 @0x00000714;
#define SCI1SR1                         _SCI1SR1.Byte
#define SCI1SR1_PF                      _SCI1SR1.Bits.PF
#define SCI1SR1_FE                      _SCI1SR1.Bits.FE
#define SCI1SR1_NF                      _SCI1SR1.Bits.NF
#define SCI1SR1_OR                      _SCI1SR1.Bits.OR
#define SCI1SR1_IDLE                    _SCI1SR1.Bits.IDLE
#define SCI1SR1_RDRF                    _SCI1SR1.Bits.RDRF
#define SCI1SR1_TC                      _SCI1SR1.Bits.TC
#define SCI1SR1_TDRE                    _SCI1SR1.Bits.TDRE

#define SCI1SR1_PF_MASK                 1U
#define SCI1SR1_FE_MASK                 2U
#define SCI1SR1_NF_MASK                 4U
#define SCI1SR1_OR_MASK                 8U
#define SCI1SR1_IDLE_MASK               16U
#define SCI1SR1_RDRF_MASK               32U
#define SCI1SR1_TC_MASK                 64U
#define SCI1SR1_TDRE_MASK               128U


/*** SCI1SR2 - SCI 1 Status Register 2; 0x00000715 ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte TXDIR       :1;                                       /* Transmitter pin data direction in Single-Wire mode */
    byte BRK13       :1;                                       /* Break Transmit character length */
    byte RXPOL       :1;                                       /* Receive Polarity */
    byte TXPOL       :1;                                       /* Transmit Polarity */
    byte             :1; 
    byte             :1; 
    byte AMAP        :1;                                       /* Alternative Map */
  } Bits;
} SCI1SR2STR;
extern volatile SCI1SR2STR _SCI1SR2 @0x00000715;
#define SCI1SR2                         _SCI1SR2.Byte
#define SCI1SR2_RAF                     _SCI1SR2.Bits.RAF
#define SCI1SR2_TXDIR                   _SCI1SR2.Bits.TXDIR
#define SCI1SR2_BRK13                   _SCI1SR2.Bits.BRK13
#define SCI1SR2_RXPOL                   _SCI1SR2.Bits.RXPOL
#define SCI1SR2_TXPOL                   _SCI1SR2.Bits.TXPOL
#define SCI1SR2_AMAP                    _SCI1SR2.Bits.AMAP

#define SCI1SR2_RAF_MASK                1U
#define SCI1SR2_TXDIR_MASK              2U
#define SCI1SR2_BRK13_MASK              4U
#define SCI1SR2_RXPOL_MASK              8U
#define SCI1SR2_TXPOL_MASK              16U
#define SCI1SR2_AMAP_MASK               128U


/*** SCI1DRH - SCI 1 Data Register High; 0x00000716 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte T8          :1;                                       /* Transmit Bit 8 */
    byte R8          :1;                                       /* Received Bit 8 */
  } Bits;
} SCI1DRHSTR;
extern volatile SCI1DRHSTR _SCI1DRH @0x00000716;
#define SCI1DRH                         _SCI1DRH.Byte
#define SCI1DRH_T8                      _SCI1DRH.Bits.T8
#define SCI1DRH_R8                      _SCI1DRH.Bits.R8

#define SCI1DRH_T8_MASK                 64U
#define SCI1DRH_R8_MASK                 128U


/*** SCI1DRL - SCI 1 Data Register Low; 0x00000717 ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Received bit 0 or Transmit bit 0 */
    byte R1_T1       :1;                                       /* Received bit 1 or Transmit bit 1 */
    byte R2_T2       :1;                                       /* Received bit 2 or Transmit bit 2 */
    byte R3_T3       :1;                                       /* Received bit 3 or Transmit bit 3 */
    byte R4_T4       :1;                                       /* Received bit 4 or Transmit bit 4 */
    byte R5_T5       :1;                                       /* Received bit 5 or Transmit bit 5 */
    byte R6_T6       :1;                                       /* Received bit 6 or Transmit bit 6 */
    byte R7_T7       :1;                                       /* Received bit 7 or Transmit bit 7 */
  } Bits;
} SCI1DRLSTR;
extern volatile SCI1DRLSTR _SCI1DRL @0x00000717;
#define SCI1DRL                         _SCI1DRL.Byte
#define SCI1DRL_R0_T0                   _SCI1DRL.Bits.R0_T0
#define SCI1DRL_R1_T1                   _SCI1DRL.Bits.R1_T1
#define SCI1DRL_R2_T2                   _SCI1DRL.Bits.R2_T2
#define SCI1DRL_R3_T3                   _SCI1DRL.Bits.R3_T3
#define SCI1DRL_R4_T4                   _SCI1DRL.Bits.R4_T4
#define SCI1DRL_R5_T5                   _SCI1DRL.Bits.R5_T5
#define SCI1DRL_R6_T6                   _SCI1DRL.Bits.R6_T6
#define SCI1DRL_R7_T7                   _SCI1DRL.Bits.R7_T7

#define SCI1DRL_R0_T0_MASK              1U
#define SCI1DRL_R1_T1_MASK              2U
#define SCI1DRL_R2_T2_MASK              4U
#define SCI1DRL_R3_T3_MASK              8U
#define SCI1DRL_R4_T4_MASK              16U
#define SCI1DRL_R5_T5_MASK              32U
#define SCI1DRL_R6_T6_MASK              64U
#define SCI1DRL_R7_T7_MASK              128U


/*** SPI0CR1 - SPI 0 Control Register 1; 0x00000780 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* SPI LSB-First Enable */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* SPI Clock Phase Bit */
    byte CPOL        :1;                                       /* SPI Clock Polarity Bit */
    byte MSTR        :1;                                       /* SPI Master/Slave Mode Select Bit */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable Bit */
    byte SPIE        :1;                                       /* SPI Interrupt Enable Bit */
  } Bits;
} SPI0CR1STR;
extern volatile SPI0CR1STR _SPI0CR1 @0x00000780;
#define SPI0CR1                         _SPI0CR1.Byte
#define SPI0CR1_LSBFE                   _SPI0CR1.Bits.LSBFE
#define SPI0CR1_SSOE                    _SPI0CR1.Bits.SSOE
#define SPI0CR1_CPHA                    _SPI0CR1.Bits.CPHA
#define SPI0CR1_CPOL                    _SPI0CR1.Bits.CPOL
#define SPI0CR1_MSTR                    _SPI0CR1.Bits.MSTR
#define SPI0CR1_SPTIE                   _SPI0CR1.Bits.SPTIE
#define SPI0CR1_SPE                     _SPI0CR1.Bits.SPE
#define SPI0CR1_SPIE                    _SPI0CR1.Bits.SPIE

#define SPI0CR1_LSBFE_MASK              1U
#define SPI0CR1_SSOE_MASK               2U
#define SPI0CR1_CPHA_MASK               4U
#define SPI0CR1_CPOL_MASK               8U
#define SPI0CR1_MSTR_MASK               16U
#define SPI0CR1_SPTIE_MASK              32U
#define SPI0CR1_SPE_MASK                64U
#define SPI0CR1_SPIE_MASK               128U


/*** SPI0CR2 - SPI 0 Control Register 2; 0x00000781 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* Serial Pin Control Bit 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode Bit */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Output enable in the Bidirectional mode of operation */
    byte MODFEN      :1;                                       /* Mode Fault Enable Bit */
    byte             :1; 
    byte XFRW        :1;                                       /* Transfer Width */
    byte             :1; 
  } Bits;
} SPI0CR2STR;
extern volatile SPI0CR2STR _SPI0CR2 @0x00000781;
#define SPI0CR2                         _SPI0CR2.Byte
#define SPI0CR2_SPC0                    _SPI0CR2.Bits.SPC0
#define SPI0CR2_SPISWAI                 _SPI0CR2.Bits.SPISWAI
#define SPI0CR2_BIDIROE                 _SPI0CR2.Bits.BIDIROE
#define SPI0CR2_MODFEN                  _SPI0CR2.Bits.MODFEN
#define SPI0CR2_XFRW                    _SPI0CR2.Bits.XFRW

#define SPI0CR2_SPC0_MASK               1U
#define SPI0CR2_SPISWAI_MASK            2U
#define SPI0CR2_BIDIROE_MASK            8U
#define SPI0CR2_MODFEN_MASK             16U
#define SPI0CR2_XFRW_MASK               64U


/*** SPI0BR - SPI 0 Baud Rate Register; 0x00000782 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Selection Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Selection Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Selection Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Preselection Bits 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Preselection Bits 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Preselection Bits 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPI0BRSTR;
extern volatile SPI0BRSTR _SPI0BR @0x00000782;
#define SPI0BR                          _SPI0BR.Byte
#define SPI0BR_SPR0                     _SPI0BR.Bits.SPR0
#define SPI0BR_SPR1                     _SPI0BR.Bits.SPR1
#define SPI0BR_SPR2                     _SPI0BR.Bits.SPR2
#define SPI0BR_SPPR0                    _SPI0BR.Bits.SPPR0
#define SPI0BR_SPPR1                    _SPI0BR.Bits.SPPR1
#define SPI0BR_SPPR2                    _SPI0BR.Bits.SPPR2
#define SPI0BR_SPR                      _SPI0BR.MergedBits.grpSPR
#define SPI0BR_SPPR                     _SPI0BR.MergedBits.grpSPPR

#define SPI0BR_SPR0_MASK                1U
#define SPI0BR_SPR1_MASK                2U
#define SPI0BR_SPR2_MASK                4U
#define SPI0BR_SPPR0_MASK               16U
#define SPI0BR_SPPR1_MASK               32U
#define SPI0BR_SPPR2_MASK               64U
#define SPI0BR_SPR_MASK                 7U
#define SPI0BR_SPR_BITNUM               0U
#define SPI0BR_SPPR_MASK                112U
#define SPI0BR_SPPR_BITNUM              4U


/*** SPI0SR - SPI 0 Status Register; 0x00000783 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Empty Interrupt Flag */
    byte             :1; 
    byte SPIF        :1;                                       /* SPIF Receive Interrupt Flag */
  } Bits;
} SPI0SRSTR;
extern volatile SPI0SRSTR _SPI0SR @0x00000783;
#define SPI0SR                          _SPI0SR.Byte
#define SPI0SR_MODF                     _SPI0SR.Bits.MODF
#define SPI0SR_SPTEF                    _SPI0SR.Bits.SPTEF
#define SPI0SR_SPIF                     _SPI0SR.Bits.SPIF

#define SPI0SR_MODF_MASK                16U
#define SPI0SR_SPTEF_MASK               32U
#define SPI0SR_SPIF_MASK                128U


/*** SPI0DR - SPI 0 Data Register; 0x00000784 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SPI0DRH - SPI 0 Data Register High; 0x00000784 ***/
    union {
      byte Byte;
      struct {
        byte R8_T8       :1;                                       /* SPI 0 Data Bit 8 */
        byte R9_T9       :1;                                       /* SPI 0 Data Bit 9 */
        byte R10_T10     :1;                                       /* SPI 0 Data Bit 10 */
        byte R11_T11     :1;                                       /* SPI 0 Data Bit 11 */
        byte R12_T12     :1;                                       /* SPI 0 Data Bit 12 */
        byte R13_T13     :1;                                       /* SPI 0 Data Bit 13 */
        byte R14_T14     :1;                                       /* SPI 0 Data Bit 14 */
        byte R15_T15     :1;                                       /* SPI 0 Data Bit 15 */
      } Bits;
    } SPI0DRHSTR;
    #define SPI0DRH                     _SPI0DR.Overlap_STR.SPI0DRHSTR.Byte
    #define SPI0DRH_R8_T8               _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R8_T8
    #define SPI0DRH_R9_T9               _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R9_T9
    #define SPI0DRH_R10_T10             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R10_T10
    #define SPI0DRH_R11_T11             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R11_T11
    #define SPI0DRH_R12_T12             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R12_T12
    #define SPI0DRH_R13_T13             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R13_T13
    #define SPI0DRH_R14_T14             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R14_T14
    #define SPI0DRH_R15_T15             _SPI0DR.Overlap_STR.SPI0DRHSTR.Bits.R15_T15
    
    #define SPI0DRH_R8_T8_MASK          1U
    #define SPI0DRH_R9_T9_MASK          2U
    #define SPI0DRH_R10_T10_MASK        4U
    #define SPI0DRH_R11_T11_MASK        8U
    #define SPI0DRH_R12_T12_MASK        16U
    #define SPI0DRH_R13_T13_MASK        32U
    #define SPI0DRH_R14_T14_MASK        64U
    #define SPI0DRH_R15_T15_MASK        128U
    

    /*** SPI0DRL - SPI 0 Data Register Low; 0x00000785 ***/
    union {
      byte Byte;
      struct {
        byte R0_T0       :1;                                       /* SPI 0 Data Bit 0 */
        byte R1_T1       :1;                                       /* SPI 0 Data Bit 1 */
        byte R2_T2       :1;                                       /* SPI 0 Data Bit 2 */
        byte R3_T3       :1;                                       /* SPI 0 Data Bit 3 */
        byte R4_T4       :1;                                       /* SPI 0 Data Bit 4 */
        byte R5_T5       :1;                                       /* SPI 0 Data Bit 5 */
        byte R6_T6       :1;                                       /* SPI 0 Data Bit 6 */
        byte R7_T7       :1;                                       /* SPI 0 Data Bit 7 */
      } Bits;
    } SPI0DRLSTR;
    #define SPI0DRL                     _SPI0DR.Overlap_STR.SPI0DRLSTR.Byte
    #define SPI0DRL_R0_T0               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R0_T0
    #define SPI0DRL_R1_T1               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R1_T1
    #define SPI0DRL_R2_T2               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R2_T2
    #define SPI0DRL_R3_T3               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R3_T3
    #define SPI0DRL_R4_T4               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R4_T4
    #define SPI0DRL_R5_T5               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R5_T5
    #define SPI0DRL_R6_T6               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R6_T6
    #define SPI0DRL_R7_T7               _SPI0DR.Overlap_STR.SPI0DRLSTR.Bits.R7_T7
    
    #define SPI0DRL_R0_T0_MASK          1U
    #define SPI0DRL_R1_T1_MASK          2U
    #define SPI0DRL_R2_T2_MASK          4U
    #define SPI0DRL_R3_T3_MASK          8U
    #define SPI0DRL_R4_T4_MASK          16U
    #define SPI0DRL_R5_T5_MASK          32U
    #define SPI0DRL_R6_T6_MASK          64U
    #define SPI0DRL_R7_T7_MASK          128U
    
  } Overlap_STR;

  struct {
    word R0_T0       :1;                                       /* SPI 0 Data Bit 0 */
    word R1_T1       :1;                                       /* SPI 0 Data Bit 1 */
    word R2_T2       :1;                                       /* SPI 0 Data Bit 2 */
    word R3_T3       :1;                                       /* SPI 0 Data Bit 3 */
    word R4_T4       :1;                                       /* SPI 0 Data Bit 4 */
    word R5_T5       :1;                                       /* SPI 0 Data Bit 5 */
    word R6_T6       :1;                                       /* SPI 0 Data Bit 6 */
    word R7_T7       :1;                                       /* SPI 0 Data Bit 7 */
    word R8_T8       :1;                                       /* SPI 0 Data Bit 8 */
    word R9_T9       :1;                                       /* SPI 0 Data Bit 9 */
    word R10_T10     :1;                                       /* SPI 0 Data Bit 10 */
    word R11_T11     :1;                                       /* SPI 0 Data Bit 11 */
    word R12_T12     :1;                                       /* SPI 0 Data Bit 12 */
    word R13_T13     :1;                                       /* SPI 0 Data Bit 13 */
    word R14_T14     :1;                                       /* SPI 0 Data Bit 14 */
    word R15_T15     :1;                                       /* SPI 0 Data Bit 15 */
  } Bits;
} SPI0DRSTR;
extern volatile SPI0DRSTR _SPI0DR @0x00000784;
#define SPI0DR                          _SPI0DR.Word
#define SPI0DR_R0_T0                    _SPI0DR.Bits.R0_T0
#define SPI0DR_R1_T1                    _SPI0DR.Bits.R1_T1
#define SPI0DR_R2_T2                    _SPI0DR.Bits.R2_T2
#define SPI0DR_R3_T3                    _SPI0DR.Bits.R3_T3
#define SPI0DR_R4_T4                    _SPI0DR.Bits.R4_T4
#define SPI0DR_R5_T5                    _SPI0DR.Bits.R5_T5
#define SPI0DR_R6_T6                    _SPI0DR.Bits.R6_T6
#define SPI0DR_R7_T7                    _SPI0DR.Bits.R7_T7
#define SPI0DR_R8_T8                    _SPI0DR.Bits.R8_T8
#define SPI0DR_R9_T9                    _SPI0DR.Bits.R9_T9
#define SPI0DR_R10_T10                  _SPI0DR.Bits.R10_T10
#define SPI0DR_R11_T11                  _SPI0DR.Bits.R11_T11
#define SPI0DR_R12_T12                  _SPI0DR.Bits.R12_T12
#define SPI0DR_R13_T13                  _SPI0DR.Bits.R13_T13
#define SPI0DR_R14_T14                  _SPI0DR.Bits.R14_T14
#define SPI0DR_R15_T15                  _SPI0DR.Bits.R15_T15

#define SPI0DR_R0_T0_MASK               1U
#define SPI0DR_R1_T1_MASK               2U
#define SPI0DR_R2_T2_MASK               4U
#define SPI0DR_R3_T3_MASK               8U
#define SPI0DR_R4_T4_MASK               16U
#define SPI0DR_R5_T5_MASK               32U
#define SPI0DR_R6_T6_MASK               64U
#define SPI0DR_R7_T7_MASK               128U
#define SPI0DR_R8_T8_MASK               256U
#define SPI0DR_R9_T9_MASK               512U
#define SPI0DR_R10_T10_MASK             1024U
#define SPI0DR_R11_T11_MASK             2048U
#define SPI0DR_R12_T12_MASK             4096U
#define SPI0DR_R13_T13_MASK             8192U
#define SPI0DR_R14_T14_MASK             16384U
#define SPI0DR_R15_T15_MASK             32768U


/*** CAN0CTL0 - MSCAN0 Control 0 Register; 0x00000800 ***/
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
} CAN0CTL0STR;
extern volatile CAN0CTL0STR _CAN0CTL0 @0x00000800;
#define CAN0CTL0                        _CAN0CTL0.Byte
#define CAN0CTL0_INITRQ                 _CAN0CTL0.Bits.INITRQ
#define CAN0CTL0_SLPRQ                  _CAN0CTL0.Bits.SLPRQ
#define CAN0CTL0_WUPE                   _CAN0CTL0.Bits.WUPE
#define CAN0CTL0_TIME                   _CAN0CTL0.Bits.TIME
#define CAN0CTL0_SYNCH                  _CAN0CTL0.Bits.SYNCH
#define CAN0CTL0_CSWAI                  _CAN0CTL0.Bits.CSWAI
#define CAN0CTL0_RXACT                  _CAN0CTL0.Bits.RXACT
#define CAN0CTL0_RXFRM                  _CAN0CTL0.Bits.RXFRM
/* CAN0CTL_ARR: Access 2 CAN0CTLx registers in an array */
#define CAN0CTL_ARR                     ((volatile byte *) &CAN0CTL0)

#define CAN0CTL0_INITRQ_MASK            1U
#define CAN0CTL0_SLPRQ_MASK             2U
#define CAN0CTL0_WUPE_MASK              4U
#define CAN0CTL0_TIME_MASK              8U
#define CAN0CTL0_SYNCH_MASK             16U
#define CAN0CTL0_CSWAI_MASK             32U
#define CAN0CTL0_RXACT_MASK             64U
#define CAN0CTL0_RXFRM_MASK             128U


/*** CAN0CTL1 - MSCAN0 Control 1 Register; 0x00000801 ***/
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
} CAN0CTL1STR;
extern volatile CAN0CTL1STR _CAN0CTL1 @0x00000801;
#define CAN0CTL1                        _CAN0CTL1.Byte
#define CAN0CTL1_INITAK                 _CAN0CTL1.Bits.INITAK
#define CAN0CTL1_SLPAK                  _CAN0CTL1.Bits.SLPAK
#define CAN0CTL1_WUPM                   _CAN0CTL1.Bits.WUPM
#define CAN0CTL1_BORM                   _CAN0CTL1.Bits.BORM
#define CAN0CTL1_LISTEN                 _CAN0CTL1.Bits.LISTEN
#define CAN0CTL1_LOOPB                  _CAN0CTL1.Bits.LOOPB
#define CAN0CTL1_CLKSRC                 _CAN0CTL1.Bits.CLKSRC
#define CAN0CTL1_CANE                   _CAN0CTL1.Bits.CANE

#define CAN0CTL1_INITAK_MASK            1U
#define CAN0CTL1_SLPAK_MASK             2U
#define CAN0CTL1_WUPM_MASK              4U
#define CAN0CTL1_BORM_MASK              8U
#define CAN0CTL1_LISTEN_MASK            16U
#define CAN0CTL1_LOOPB_MASK             32U
#define CAN0CTL1_CLKSRC_MASK            64U
#define CAN0CTL1_CANE_MASK              128U


/*** CAN0BTR0 - MSCAN0 Bus Timing Register 0; 0x00000802 ***/
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
} CAN0BTR0STR;
extern volatile CAN0BTR0STR _CAN0BTR0 @0x00000802;
#define CAN0BTR0                        _CAN0BTR0.Byte
#define CAN0BTR0_BRP0                   _CAN0BTR0.Bits.BRP0
#define CAN0BTR0_BRP1                   _CAN0BTR0.Bits.BRP1
#define CAN0BTR0_BRP2                   _CAN0BTR0.Bits.BRP2
#define CAN0BTR0_BRP3                   _CAN0BTR0.Bits.BRP3
#define CAN0BTR0_BRP4                   _CAN0BTR0.Bits.BRP4
#define CAN0BTR0_BRP5                   _CAN0BTR0.Bits.BRP5
#define CAN0BTR0_SJW0                   _CAN0BTR0.Bits.SJW0
#define CAN0BTR0_SJW1                   _CAN0BTR0.Bits.SJW1
/* CAN0BTR_ARR: Access 2 CAN0BTRx registers in an array */
#define CAN0BTR_ARR                     ((volatile byte *) &CAN0BTR0)
#define CAN0BTR0_BRP                    _CAN0BTR0.MergedBits.grpBRP
#define CAN0BTR0_SJW                    _CAN0BTR0.MergedBits.grpSJW

#define CAN0BTR0_BRP0_MASK              1U
#define CAN0BTR0_BRP1_MASK              2U
#define CAN0BTR0_BRP2_MASK              4U
#define CAN0BTR0_BRP3_MASK              8U
#define CAN0BTR0_BRP4_MASK              16U
#define CAN0BTR0_BRP5_MASK              32U
#define CAN0BTR0_SJW0_MASK              64U
#define CAN0BTR0_SJW1_MASK              128U
#define CAN0BTR0_BRP_MASK               63U
#define CAN0BTR0_BRP_BITNUM             0U
#define CAN0BTR0_SJW_MASK               192U
#define CAN0BTR0_SJW_BITNUM             6U


/*** CAN0BTR1 - MSCAN0 Bus Timing Register 1; 0x00000803 ***/
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
} CAN0BTR1STR;
extern volatile CAN0BTR1STR _CAN0BTR1 @0x00000803;
#define CAN0BTR1                        _CAN0BTR1.Byte
#define CAN0BTR1_TSEG10                 _CAN0BTR1.Bits.TSEG10
#define CAN0BTR1_TSEG11                 _CAN0BTR1.Bits.TSEG11
#define CAN0BTR1_TSEG12                 _CAN0BTR1.Bits.TSEG12
#define CAN0BTR1_TSEG13                 _CAN0BTR1.Bits.TSEG13
#define CAN0BTR1_TSEG20                 _CAN0BTR1.Bits.TSEG20
#define CAN0BTR1_TSEG21                 _CAN0BTR1.Bits.TSEG21
#define CAN0BTR1_TSEG22                 _CAN0BTR1.Bits.TSEG22
#define CAN0BTR1_SAMP                   _CAN0BTR1.Bits.SAMP
#define CAN0BTR1_TSEG_10                _CAN0BTR1.MergedBits.grpTSEG_10
#define CAN0BTR1_TSEG_20                _CAN0BTR1.MergedBits.grpTSEG_20
#define CAN0BTR1_TSEG                   CAN0BTR1_TSEG_10

#define CAN0BTR1_TSEG10_MASK            1U
#define CAN0BTR1_TSEG11_MASK            2U
#define CAN0BTR1_TSEG12_MASK            4U
#define CAN0BTR1_TSEG13_MASK            8U
#define CAN0BTR1_TSEG20_MASK            16U
#define CAN0BTR1_TSEG21_MASK            32U
#define CAN0BTR1_TSEG22_MASK            64U
#define CAN0BTR1_SAMP_MASK              128U
#define CAN0BTR1_TSEG_10_MASK           15U
#define CAN0BTR1_TSEG_10_BITNUM         0U
#define CAN0BTR1_TSEG_20_MASK           112U
#define CAN0BTR1_TSEG_20_BITNUM         4U


/*** CAN0RFLG - MSCAN0 Receiver Flag Register; 0x00000804 ***/
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
} CAN0RFLGSTR;
extern volatile CAN0RFLGSTR _CAN0RFLG @0x00000804;
#define CAN0RFLG                        _CAN0RFLG.Byte
#define CAN0RFLG_RXF                    _CAN0RFLG.Bits.RXF
#define CAN0RFLG_OVRIF                  _CAN0RFLG.Bits.OVRIF
#define CAN0RFLG_TSTAT0                 _CAN0RFLG.Bits.TSTAT0
#define CAN0RFLG_TSTAT1                 _CAN0RFLG.Bits.TSTAT1
#define CAN0RFLG_RSTAT0                 _CAN0RFLG.Bits.RSTAT0
#define CAN0RFLG_RSTAT1                 _CAN0RFLG.Bits.RSTAT1
#define CAN0RFLG_CSCIF                  _CAN0RFLG.Bits.CSCIF
#define CAN0RFLG_WUPIF                  _CAN0RFLG.Bits.WUPIF
#define CAN0RFLG_TSTAT                  _CAN0RFLG.MergedBits.grpTSTAT
#define CAN0RFLG_RSTAT                  _CAN0RFLG.MergedBits.grpRSTAT

#define CAN0RFLG_RXF_MASK               1U
#define CAN0RFLG_OVRIF_MASK             2U
#define CAN0RFLG_TSTAT0_MASK            4U
#define CAN0RFLG_TSTAT1_MASK            8U
#define CAN0RFLG_RSTAT0_MASK            16U
#define CAN0RFLG_RSTAT1_MASK            32U
#define CAN0RFLG_CSCIF_MASK             64U
#define CAN0RFLG_WUPIF_MASK             128U
#define CAN0RFLG_TSTAT_MASK             12U
#define CAN0RFLG_TSTAT_BITNUM           2U
#define CAN0RFLG_RSTAT_MASK             48U
#define CAN0RFLG_RSTAT_BITNUM           4U


/*** CAN0RIER - MSCAN0 Receiver Interrupt Enable Register; 0x00000805 ***/
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
} CAN0RIERSTR;
extern volatile CAN0RIERSTR _CAN0RIER @0x00000805;
#define CAN0RIER                        _CAN0RIER.Byte
#define CAN0RIER_RXFIE                  _CAN0RIER.Bits.RXFIE
#define CAN0RIER_OVRIE                  _CAN0RIER.Bits.OVRIE
#define CAN0RIER_TSTATE0                _CAN0RIER.Bits.TSTATE0
#define CAN0RIER_TSTATE1                _CAN0RIER.Bits.TSTATE1
#define CAN0RIER_RSTATE0                _CAN0RIER.Bits.RSTATE0
#define CAN0RIER_RSTATE1                _CAN0RIER.Bits.RSTATE1
#define CAN0RIER_CSCIE                  _CAN0RIER.Bits.CSCIE
#define CAN0RIER_WUPIE                  _CAN0RIER.Bits.WUPIE
#define CAN0RIER_TSTATE                 _CAN0RIER.MergedBits.grpTSTATE
#define CAN0RIER_RSTATE                 _CAN0RIER.MergedBits.grpRSTATE

#define CAN0RIER_RXFIE_MASK             1U
#define CAN0RIER_OVRIE_MASK             2U
#define CAN0RIER_TSTATE0_MASK           4U
#define CAN0RIER_TSTATE1_MASK           8U
#define CAN0RIER_RSTATE0_MASK           16U
#define CAN0RIER_RSTATE1_MASK           32U
#define CAN0RIER_CSCIE_MASK             64U
#define CAN0RIER_WUPIE_MASK             128U
#define CAN0RIER_TSTATE_MASK            12U
#define CAN0RIER_TSTATE_BITNUM          2U
#define CAN0RIER_RSTATE_MASK            48U
#define CAN0RIER_RSTATE_BITNUM          4U


/*** CAN0TFLG - MSCAN0 Transmitter Flag Register; 0x00000806 ***/
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
} CAN0TFLGSTR;
extern volatile CAN0TFLGSTR _CAN0TFLG @0x00000806;
#define CAN0TFLG                        _CAN0TFLG.Byte
#define CAN0TFLG_TXE0                   _CAN0TFLG.Bits.TXE0
#define CAN0TFLG_TXE1                   _CAN0TFLG.Bits.TXE1
#define CAN0TFLG_TXE2                   _CAN0TFLG.Bits.TXE2
#define CAN0TFLG_TXE                    _CAN0TFLG.MergedBits.grpTXE

#define CAN0TFLG_TXE0_MASK              1U
#define CAN0TFLG_TXE1_MASK              2U
#define CAN0TFLG_TXE2_MASK              4U
#define CAN0TFLG_TXE_MASK               7U
#define CAN0TFLG_TXE_BITNUM             0U


/*** CAN0TIER - MSCAN0 Transmitter Interrupt Enable Register; 0x00000807 ***/
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
} CAN0TIERSTR;
extern volatile CAN0TIERSTR _CAN0TIER @0x00000807;
#define CAN0TIER                        _CAN0TIER.Byte
#define CAN0TIER_TXEIE0                 _CAN0TIER.Bits.TXEIE0
#define CAN0TIER_TXEIE1                 _CAN0TIER.Bits.TXEIE1
#define CAN0TIER_TXEIE2                 _CAN0TIER.Bits.TXEIE2
#define CAN0TIER_TXEIE                  _CAN0TIER.MergedBits.grpTXEIE

#define CAN0TIER_TXEIE0_MASK            1U
#define CAN0TIER_TXEIE1_MASK            2U
#define CAN0TIER_TXEIE2_MASK            4U
#define CAN0TIER_TXEIE_MASK             7U
#define CAN0TIER_TXEIE_BITNUM           0U


/*** CAN0TARQ - MSCAN0 Transmitter Message Abort Request; 0x00000808 ***/
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
} CAN0TARQSTR;
extern volatile CAN0TARQSTR _CAN0TARQ @0x00000808;
#define CAN0TARQ                        _CAN0TARQ.Byte
#define CAN0TARQ_ABTRQ0                 _CAN0TARQ.Bits.ABTRQ0
#define CAN0TARQ_ABTRQ1                 _CAN0TARQ.Bits.ABTRQ1
#define CAN0TARQ_ABTRQ2                 _CAN0TARQ.Bits.ABTRQ2
#define CAN0TARQ_ABTRQ                  _CAN0TARQ.MergedBits.grpABTRQ

#define CAN0TARQ_ABTRQ0_MASK            1U
#define CAN0TARQ_ABTRQ1_MASK            2U
#define CAN0TARQ_ABTRQ2_MASK            4U
#define CAN0TARQ_ABTRQ_MASK             7U
#define CAN0TARQ_ABTRQ_BITNUM           0U


/*** CAN0TAAK - MSCAN0 Transmitter Message Abort Acknowledge; 0x00000809 ***/
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
} CAN0TAAKSTR;
extern volatile CAN0TAAKSTR _CAN0TAAK @0x00000809;
#define CAN0TAAK                        _CAN0TAAK.Byte
#define CAN0TAAK_ABTAK0                 _CAN0TAAK.Bits.ABTAK0
#define CAN0TAAK_ABTAK1                 _CAN0TAAK.Bits.ABTAK1
#define CAN0TAAK_ABTAK2                 _CAN0TAAK.Bits.ABTAK2
#define CAN0TAAK_ABTAK                  _CAN0TAAK.MergedBits.grpABTAK

#define CAN0TAAK_ABTAK0_MASK            1U
#define CAN0TAAK_ABTAK1_MASK            2U
#define CAN0TAAK_ABTAK2_MASK            4U
#define CAN0TAAK_ABTAK_MASK             7U
#define CAN0TAAK_ABTAK_BITNUM           0U


/*** CAN0TBSEL - MSCAN0 Transmit Buffer Selection; 0x0000080A ***/
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
} CAN0TBSELSTR;
extern volatile CAN0TBSELSTR _CAN0TBSEL @0x0000080A;
#define CAN0TBSEL                       _CAN0TBSEL.Byte
#define CAN0TBSEL_TX0                   _CAN0TBSEL.Bits.TX0
#define CAN0TBSEL_TX1                   _CAN0TBSEL.Bits.TX1
#define CAN0TBSEL_TX2                   _CAN0TBSEL.Bits.TX2
#define CAN0TBSEL_TX                    _CAN0TBSEL.MergedBits.grpTX

#define CAN0TBSEL_TX0_MASK              1U
#define CAN0TBSEL_TX1_MASK              2U
#define CAN0TBSEL_TX2_MASK              4U
#define CAN0TBSEL_TX_MASK               7U
#define CAN0TBSEL_TX_BITNUM             0U


/*** CAN0IDAC - MSCAN0 Identifier Acceptance Control Register; 0x0000080B ***/
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
} CAN0IDACSTR;
extern volatile CAN0IDACSTR _CAN0IDAC @0x0000080B;
#define CAN0IDAC                        _CAN0IDAC.Byte
#define CAN0IDAC_IDHIT0                 _CAN0IDAC.Bits.IDHIT0
#define CAN0IDAC_IDHIT1                 _CAN0IDAC.Bits.IDHIT1
#define CAN0IDAC_IDHIT2                 _CAN0IDAC.Bits.IDHIT2
#define CAN0IDAC_IDAM0                  _CAN0IDAC.Bits.IDAM0
#define CAN0IDAC_IDAM1                  _CAN0IDAC.Bits.IDAM1
#define CAN0IDAC_IDHIT                  _CAN0IDAC.MergedBits.grpIDHIT
#define CAN0IDAC_IDAM                   _CAN0IDAC.MergedBits.grpIDAM

#define CAN0IDAC_IDHIT0_MASK            1U
#define CAN0IDAC_IDHIT1_MASK            2U
#define CAN0IDAC_IDHIT2_MASK            4U
#define CAN0IDAC_IDAM0_MASK             16U
#define CAN0IDAC_IDAM1_MASK             32U
#define CAN0IDAC_IDHIT_MASK             7U
#define CAN0IDAC_IDHIT_BITNUM           0U
#define CAN0IDAC_IDAM_MASK              48U
#define CAN0IDAC_IDAM_BITNUM            4U


/*** CAN0MISC - MSCAN0 Miscellaneous Register; 0x0000080D ***/
typedef union {
  byte Byte;
  struct {
    byte BOHOLD      :1;                                       /* Bus-off State Hold Until User Request */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} CAN0MISCSTR;
extern volatile CAN0MISCSTR _CAN0MISC @0x0000080D;
#define CAN0MISC                        _CAN0MISC.Byte
#define CAN0MISC_BOHOLD                 _CAN0MISC.Bits.BOHOLD

#define CAN0MISC_BOHOLD_MASK            1U


/*** CAN0RXERR - MSCAN0 Receive Error Counter Register; 0x0000080E ***/
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
} CAN0RXERRSTR;
extern volatile CAN0RXERRSTR _CAN0RXERR @0x0000080E;
#define CAN0RXERR                       _CAN0RXERR.Byte
#define CAN0RXERR_RXERR0                _CAN0RXERR.Bits.RXERR0
#define CAN0RXERR_RXERR1                _CAN0RXERR.Bits.RXERR1
#define CAN0RXERR_RXERR2                _CAN0RXERR.Bits.RXERR2
#define CAN0RXERR_RXERR3                _CAN0RXERR.Bits.RXERR3
#define CAN0RXERR_RXERR4                _CAN0RXERR.Bits.RXERR4
#define CAN0RXERR_RXERR5                _CAN0RXERR.Bits.RXERR5
#define CAN0RXERR_RXERR6                _CAN0RXERR.Bits.RXERR6
#define CAN0RXERR_RXERR7                _CAN0RXERR.Bits.RXERR7

#define CAN0RXERR_RXERR0_MASK           1U
#define CAN0RXERR_RXERR1_MASK           2U
#define CAN0RXERR_RXERR2_MASK           4U
#define CAN0RXERR_RXERR3_MASK           8U
#define CAN0RXERR_RXERR4_MASK           16U
#define CAN0RXERR_RXERR5_MASK           32U
#define CAN0RXERR_RXERR6_MASK           64U
#define CAN0RXERR_RXERR7_MASK           128U


/*** CAN0TXERR - MSCAN0 Transmit Error Counter Register; 0x0000080F ***/
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
} CAN0TXERRSTR;
extern volatile CAN0TXERRSTR _CAN0TXERR @0x0000080F;
#define CAN0TXERR                       _CAN0TXERR.Byte
#define CAN0TXERR_TXERR0                _CAN0TXERR.Bits.TXERR0
#define CAN0TXERR_TXERR1                _CAN0TXERR.Bits.TXERR1
#define CAN0TXERR_TXERR2                _CAN0TXERR.Bits.TXERR2
#define CAN0TXERR_TXERR3                _CAN0TXERR.Bits.TXERR3
#define CAN0TXERR_TXERR4                _CAN0TXERR.Bits.TXERR4
#define CAN0TXERR_TXERR5                _CAN0TXERR.Bits.TXERR5
#define CAN0TXERR_TXERR6                _CAN0TXERR.Bits.TXERR6
#define CAN0TXERR_TXERR7                _CAN0TXERR.Bits.TXERR7

#define CAN0TXERR_TXERR0_MASK           1U
#define CAN0TXERR_TXERR1_MASK           2U
#define CAN0TXERR_TXERR2_MASK           4U
#define CAN0TXERR_TXERR3_MASK           8U
#define CAN0TXERR_TXERR4_MASK           16U
#define CAN0TXERR_TXERR5_MASK           32U
#define CAN0TXERR_TXERR6_MASK           64U
#define CAN0TXERR_TXERR7_MASK           128U


/*** CAN0IDAR0 - MSCAN0 Identifier Acceptance Register 0; 0x00000810 ***/
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
} CAN0IDAR0STR;
extern volatile CAN0IDAR0STR _CAN0IDAR0 @0x00000810;
#define CAN0IDAR0                       _CAN0IDAR0.Byte
#define CAN0IDAR0_AC0                   _CAN0IDAR0.Bits.AC0
#define CAN0IDAR0_AC1                   _CAN0IDAR0.Bits.AC1
#define CAN0IDAR0_AC2                   _CAN0IDAR0.Bits.AC2
#define CAN0IDAR0_AC3                   _CAN0IDAR0.Bits.AC3
#define CAN0IDAR0_AC4                   _CAN0IDAR0.Bits.AC4
#define CAN0IDAR0_AC5                   _CAN0IDAR0.Bits.AC5
#define CAN0IDAR0_AC6                   _CAN0IDAR0.Bits.AC6
#define CAN0IDAR0_AC7                   _CAN0IDAR0.Bits.AC7
/* CAN0IDAR_ARR: Access 4 CAN0IDARx registers in an array */
#define CAN0IDAR_ARR                    ((volatile byte *) &CAN0IDAR0)

#define CAN0IDAR0_AC0_MASK              1U
#define CAN0IDAR0_AC1_MASK              2U
#define CAN0IDAR0_AC2_MASK              4U
#define CAN0IDAR0_AC3_MASK              8U
#define CAN0IDAR0_AC4_MASK              16U
#define CAN0IDAR0_AC5_MASK              32U
#define CAN0IDAR0_AC6_MASK              64U
#define CAN0IDAR0_AC7_MASK              128U


/*** CAN0IDAR1 - MSCAN0 Identifier Acceptance Register 1; 0x00000811 ***/
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
} CAN0IDAR1STR;
extern volatile CAN0IDAR1STR _CAN0IDAR1 @0x00000811;
#define CAN0IDAR1                       _CAN0IDAR1.Byte
#define CAN0IDAR1_AC0                   _CAN0IDAR1.Bits.AC0
#define CAN0IDAR1_AC1                   _CAN0IDAR1.Bits.AC1
#define CAN0IDAR1_AC2                   _CAN0IDAR1.Bits.AC2
#define CAN0IDAR1_AC3                   _CAN0IDAR1.Bits.AC3
#define CAN0IDAR1_AC4                   _CAN0IDAR1.Bits.AC4
#define CAN0IDAR1_AC5                   _CAN0IDAR1.Bits.AC5
#define CAN0IDAR1_AC6                   _CAN0IDAR1.Bits.AC6
#define CAN0IDAR1_AC7                   _CAN0IDAR1.Bits.AC7

#define CAN0IDAR1_AC0_MASK              1U
#define CAN0IDAR1_AC1_MASK              2U
#define CAN0IDAR1_AC2_MASK              4U
#define CAN0IDAR1_AC3_MASK              8U
#define CAN0IDAR1_AC4_MASK              16U
#define CAN0IDAR1_AC5_MASK              32U
#define CAN0IDAR1_AC6_MASK              64U
#define CAN0IDAR1_AC7_MASK              128U


/*** CAN0IDAR2 - MSCAN0 Identifier Acceptance Register 2; 0x00000812 ***/
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
} CAN0IDAR2STR;
extern volatile CAN0IDAR2STR _CAN0IDAR2 @0x00000812;
#define CAN0IDAR2                       _CAN0IDAR2.Byte
#define CAN0IDAR2_AC0                   _CAN0IDAR2.Bits.AC0
#define CAN0IDAR2_AC1                   _CAN0IDAR2.Bits.AC1
#define CAN0IDAR2_AC2                   _CAN0IDAR2.Bits.AC2
#define CAN0IDAR2_AC3                   _CAN0IDAR2.Bits.AC3
#define CAN0IDAR2_AC4                   _CAN0IDAR2.Bits.AC4
#define CAN0IDAR2_AC5                   _CAN0IDAR2.Bits.AC5
#define CAN0IDAR2_AC6                   _CAN0IDAR2.Bits.AC6
#define CAN0IDAR2_AC7                   _CAN0IDAR2.Bits.AC7

#define CAN0IDAR2_AC0_MASK              1U
#define CAN0IDAR2_AC1_MASK              2U
#define CAN0IDAR2_AC2_MASK              4U
#define CAN0IDAR2_AC3_MASK              8U
#define CAN0IDAR2_AC4_MASK              16U
#define CAN0IDAR2_AC5_MASK              32U
#define CAN0IDAR2_AC6_MASK              64U
#define CAN0IDAR2_AC7_MASK              128U


/*** CAN0IDAR3 - MSCAN0 Identifier Acceptance Register 3; 0x00000813 ***/
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
} CAN0IDAR3STR;
extern volatile CAN0IDAR3STR _CAN0IDAR3 @0x00000813;
#define CAN0IDAR3                       _CAN0IDAR3.Byte
#define CAN0IDAR3_AC0                   _CAN0IDAR3.Bits.AC0
#define CAN0IDAR3_AC1                   _CAN0IDAR3.Bits.AC1
#define CAN0IDAR3_AC2                   _CAN0IDAR3.Bits.AC2
#define CAN0IDAR3_AC3                   _CAN0IDAR3.Bits.AC3
#define CAN0IDAR3_AC4                   _CAN0IDAR3.Bits.AC4
#define CAN0IDAR3_AC5                   _CAN0IDAR3.Bits.AC5
#define CAN0IDAR3_AC6                   _CAN0IDAR3.Bits.AC6
#define CAN0IDAR3_AC7                   _CAN0IDAR3.Bits.AC7

#define CAN0IDAR3_AC0_MASK              1U
#define CAN0IDAR3_AC1_MASK              2U
#define CAN0IDAR3_AC2_MASK              4U
#define CAN0IDAR3_AC3_MASK              8U
#define CAN0IDAR3_AC4_MASK              16U
#define CAN0IDAR3_AC5_MASK              32U
#define CAN0IDAR3_AC6_MASK              64U
#define CAN0IDAR3_AC7_MASK              128U


/*** CAN0IDMR0 - MSCAN0 Identifier Mask Register 0; 0x00000814 ***/
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
} CAN0IDMR0STR;
extern volatile CAN0IDMR0STR _CAN0IDMR0 @0x00000814;
#define CAN0IDMR0                       _CAN0IDMR0.Byte
#define CAN0IDMR0_AM0                   _CAN0IDMR0.Bits.AM0
#define CAN0IDMR0_AM1                   _CAN0IDMR0.Bits.AM1
#define CAN0IDMR0_AM2                   _CAN0IDMR0.Bits.AM2
#define CAN0IDMR0_AM3                   _CAN0IDMR0.Bits.AM3
#define CAN0IDMR0_AM4                   _CAN0IDMR0.Bits.AM4
#define CAN0IDMR0_AM5                   _CAN0IDMR0.Bits.AM5
#define CAN0IDMR0_AM6                   _CAN0IDMR0.Bits.AM6
#define CAN0IDMR0_AM7                   _CAN0IDMR0.Bits.AM7
/* CAN0IDMR_ARR: Access 4 CAN0IDMRx registers in an array */
#define CAN0IDMR_ARR                    ((volatile byte *) &CAN0IDMR0)

#define CAN0IDMR0_AM0_MASK              1U
#define CAN0IDMR0_AM1_MASK              2U
#define CAN0IDMR0_AM2_MASK              4U
#define CAN0IDMR0_AM3_MASK              8U
#define CAN0IDMR0_AM4_MASK              16U
#define CAN0IDMR0_AM5_MASK              32U
#define CAN0IDMR0_AM6_MASK              64U
#define CAN0IDMR0_AM7_MASK              128U


/*** CAN0IDMR1 - MSCAN0 Identifier Mask Register 1; 0x00000815 ***/
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
} CAN0IDMR1STR;
extern volatile CAN0IDMR1STR _CAN0IDMR1 @0x00000815;
#define CAN0IDMR1                       _CAN0IDMR1.Byte
#define CAN0IDMR1_AM0                   _CAN0IDMR1.Bits.AM0
#define CAN0IDMR1_AM1                   _CAN0IDMR1.Bits.AM1
#define CAN0IDMR1_AM2                   _CAN0IDMR1.Bits.AM2
#define CAN0IDMR1_AM3                   _CAN0IDMR1.Bits.AM3
#define CAN0IDMR1_AM4                   _CAN0IDMR1.Bits.AM4
#define CAN0IDMR1_AM5                   _CAN0IDMR1.Bits.AM5
#define CAN0IDMR1_AM6                   _CAN0IDMR1.Bits.AM6
#define CAN0IDMR1_AM7                   _CAN0IDMR1.Bits.AM7

#define CAN0IDMR1_AM0_MASK              1U
#define CAN0IDMR1_AM1_MASK              2U
#define CAN0IDMR1_AM2_MASK              4U
#define CAN0IDMR1_AM3_MASK              8U
#define CAN0IDMR1_AM4_MASK              16U
#define CAN0IDMR1_AM5_MASK              32U
#define CAN0IDMR1_AM6_MASK              64U
#define CAN0IDMR1_AM7_MASK              128U


/*** CAN0IDMR2 - MSCAN0 Identifier Mask Register 2; 0x00000816 ***/
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
} CAN0IDMR2STR;
extern volatile CAN0IDMR2STR _CAN0IDMR2 @0x00000816;
#define CAN0IDMR2                       _CAN0IDMR2.Byte
#define CAN0IDMR2_AM0                   _CAN0IDMR2.Bits.AM0
#define CAN0IDMR2_AM1                   _CAN0IDMR2.Bits.AM1
#define CAN0IDMR2_AM2                   _CAN0IDMR2.Bits.AM2
#define CAN0IDMR2_AM3                   _CAN0IDMR2.Bits.AM3
#define CAN0IDMR2_AM4                   _CAN0IDMR2.Bits.AM4
#define CAN0IDMR2_AM5                   _CAN0IDMR2.Bits.AM5
#define CAN0IDMR2_AM6                   _CAN0IDMR2.Bits.AM6
#define CAN0IDMR2_AM7                   _CAN0IDMR2.Bits.AM7

#define CAN0IDMR2_AM0_MASK              1U
#define CAN0IDMR2_AM1_MASK              2U
#define CAN0IDMR2_AM2_MASK              4U
#define CAN0IDMR2_AM3_MASK              8U
#define CAN0IDMR2_AM4_MASK              16U
#define CAN0IDMR2_AM5_MASK              32U
#define CAN0IDMR2_AM6_MASK              64U
#define CAN0IDMR2_AM7_MASK              128U


/*** CAN0IDMR3 - MSCAN0 Identifier Mask Register 3; 0x00000817 ***/
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
} CAN0IDMR3STR;
extern volatile CAN0IDMR3STR _CAN0IDMR3 @0x00000817;
#define CAN0IDMR3                       _CAN0IDMR3.Byte
#define CAN0IDMR3_AM0                   _CAN0IDMR3.Bits.AM0
#define CAN0IDMR3_AM1                   _CAN0IDMR3.Bits.AM1
#define CAN0IDMR3_AM2                   _CAN0IDMR3.Bits.AM2
#define CAN0IDMR3_AM3                   _CAN0IDMR3.Bits.AM3
#define CAN0IDMR3_AM4                   _CAN0IDMR3.Bits.AM4
#define CAN0IDMR3_AM5                   _CAN0IDMR3.Bits.AM5
#define CAN0IDMR3_AM6                   _CAN0IDMR3.Bits.AM6
#define CAN0IDMR3_AM7                   _CAN0IDMR3.Bits.AM7

#define CAN0IDMR3_AM0_MASK              1U
#define CAN0IDMR3_AM1_MASK              2U
#define CAN0IDMR3_AM2_MASK              4U
#define CAN0IDMR3_AM3_MASK              8U
#define CAN0IDMR3_AM4_MASK              16U
#define CAN0IDMR3_AM5_MASK              32U
#define CAN0IDMR3_AM6_MASK              64U
#define CAN0IDMR3_AM7_MASK              128U


/*** CAN0IDAR4 - MSCAN0 Identifier Acceptance Register 4; 0x00000818 ***/
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
} CAN0IDAR4STR;
extern volatile CAN0IDAR4STR _CAN0IDAR4 @0x00000818;
#define CAN0IDAR4                       _CAN0IDAR4.Byte
#define CAN0IDAR4_AC0                   _CAN0IDAR4.Bits.AC0
#define CAN0IDAR4_AC1                   _CAN0IDAR4.Bits.AC1
#define CAN0IDAR4_AC2                   _CAN0IDAR4.Bits.AC2
#define CAN0IDAR4_AC3                   _CAN0IDAR4.Bits.AC3
#define CAN0IDAR4_AC4                   _CAN0IDAR4.Bits.AC4
#define CAN0IDAR4_AC5                   _CAN0IDAR4.Bits.AC5
#define CAN0IDAR4_AC6                   _CAN0IDAR4.Bits.AC6
#define CAN0IDAR4_AC7                   _CAN0IDAR4.Bits.AC7

#define CAN0IDAR4_AC0_MASK              1U
#define CAN0IDAR4_AC1_MASK              2U
#define CAN0IDAR4_AC2_MASK              4U
#define CAN0IDAR4_AC3_MASK              8U
#define CAN0IDAR4_AC4_MASK              16U
#define CAN0IDAR4_AC5_MASK              32U
#define CAN0IDAR4_AC6_MASK              64U
#define CAN0IDAR4_AC7_MASK              128U


/*** CAN0IDAR5 - MSCAN0 Identifier Acceptance Register 5; 0x00000819 ***/
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
} CAN0IDAR5STR;
extern volatile CAN0IDAR5STR _CAN0IDAR5 @0x00000819;
#define CAN0IDAR5                       _CAN0IDAR5.Byte
#define CAN0IDAR5_AC0                   _CAN0IDAR5.Bits.AC0
#define CAN0IDAR5_AC1                   _CAN0IDAR5.Bits.AC1
#define CAN0IDAR5_AC2                   _CAN0IDAR5.Bits.AC2
#define CAN0IDAR5_AC3                   _CAN0IDAR5.Bits.AC3
#define CAN0IDAR5_AC4                   _CAN0IDAR5.Bits.AC4
#define CAN0IDAR5_AC5                   _CAN0IDAR5.Bits.AC5
#define CAN0IDAR5_AC6                   _CAN0IDAR5.Bits.AC6
#define CAN0IDAR5_AC7                   _CAN0IDAR5.Bits.AC7

#define CAN0IDAR5_AC0_MASK              1U
#define CAN0IDAR5_AC1_MASK              2U
#define CAN0IDAR5_AC2_MASK              4U
#define CAN0IDAR5_AC3_MASK              8U
#define CAN0IDAR5_AC4_MASK              16U
#define CAN0IDAR5_AC5_MASK              32U
#define CAN0IDAR5_AC6_MASK              64U
#define CAN0IDAR5_AC7_MASK              128U


/*** CAN0IDAR6 - MSCAN0 Identifier Acceptance Register 6; 0x0000081A ***/
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
} CAN0IDAR6STR;
extern volatile CAN0IDAR6STR _CAN0IDAR6 @0x0000081A;
#define CAN0IDAR6                       _CAN0IDAR6.Byte
#define CAN0IDAR6_AC0                   _CAN0IDAR6.Bits.AC0
#define CAN0IDAR6_AC1                   _CAN0IDAR6.Bits.AC1
#define CAN0IDAR6_AC2                   _CAN0IDAR6.Bits.AC2
#define CAN0IDAR6_AC3                   _CAN0IDAR6.Bits.AC3
#define CAN0IDAR6_AC4                   _CAN0IDAR6.Bits.AC4
#define CAN0IDAR6_AC5                   _CAN0IDAR6.Bits.AC5
#define CAN0IDAR6_AC6                   _CAN0IDAR6.Bits.AC6
#define CAN0IDAR6_AC7                   _CAN0IDAR6.Bits.AC7

#define CAN0IDAR6_AC0_MASK              1U
#define CAN0IDAR6_AC1_MASK              2U
#define CAN0IDAR6_AC2_MASK              4U
#define CAN0IDAR6_AC3_MASK              8U
#define CAN0IDAR6_AC4_MASK              16U
#define CAN0IDAR6_AC5_MASK              32U
#define CAN0IDAR6_AC6_MASK              64U
#define CAN0IDAR6_AC7_MASK              128U


/*** CAN0IDAR7 - MSCAN0 Identifier Acceptance Register 7; 0x0000081B ***/
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
} CAN0IDAR7STR;
extern volatile CAN0IDAR7STR _CAN0IDAR7 @0x0000081B;
#define CAN0IDAR7                       _CAN0IDAR7.Byte
#define CAN0IDAR7_AC0                   _CAN0IDAR7.Bits.AC0
#define CAN0IDAR7_AC1                   _CAN0IDAR7.Bits.AC1
#define CAN0IDAR7_AC2                   _CAN0IDAR7.Bits.AC2
#define CAN0IDAR7_AC3                   _CAN0IDAR7.Bits.AC3
#define CAN0IDAR7_AC4                   _CAN0IDAR7.Bits.AC4
#define CAN0IDAR7_AC5                   _CAN0IDAR7.Bits.AC5
#define CAN0IDAR7_AC6                   _CAN0IDAR7.Bits.AC6
#define CAN0IDAR7_AC7                   _CAN0IDAR7.Bits.AC7

#define CAN0IDAR7_AC0_MASK              1U
#define CAN0IDAR7_AC1_MASK              2U
#define CAN0IDAR7_AC2_MASK              4U
#define CAN0IDAR7_AC3_MASK              8U
#define CAN0IDAR7_AC4_MASK              16U
#define CAN0IDAR7_AC5_MASK              32U
#define CAN0IDAR7_AC6_MASK              64U
#define CAN0IDAR7_AC7_MASK              128U


/*** CAN0IDMR4 - MSCAN0 Identifier Mask Register 4; 0x0000081C ***/
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
} CAN0IDMR4STR;
extern volatile CAN0IDMR4STR _CAN0IDMR4 @0x0000081C;
#define CAN0IDMR4                       _CAN0IDMR4.Byte
#define CAN0IDMR4_AM0                   _CAN0IDMR4.Bits.AM0
#define CAN0IDMR4_AM1                   _CAN0IDMR4.Bits.AM1
#define CAN0IDMR4_AM2                   _CAN0IDMR4.Bits.AM2
#define CAN0IDMR4_AM3                   _CAN0IDMR4.Bits.AM3
#define CAN0IDMR4_AM4                   _CAN0IDMR4.Bits.AM4
#define CAN0IDMR4_AM5                   _CAN0IDMR4.Bits.AM5
#define CAN0IDMR4_AM6                   _CAN0IDMR4.Bits.AM6
#define CAN0IDMR4_AM7                   _CAN0IDMR4.Bits.AM7

#define CAN0IDMR4_AM0_MASK              1U
#define CAN0IDMR4_AM1_MASK              2U
#define CAN0IDMR4_AM2_MASK              4U
#define CAN0IDMR4_AM3_MASK              8U
#define CAN0IDMR4_AM4_MASK              16U
#define CAN0IDMR4_AM5_MASK              32U
#define CAN0IDMR4_AM6_MASK              64U
#define CAN0IDMR4_AM7_MASK              128U


/*** CAN0IDMR5 - MSCAN0 Identifier Mask Register 5; 0x0000081D ***/
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
} CAN0IDMR5STR;
extern volatile CAN0IDMR5STR _CAN0IDMR5 @0x0000081D;
#define CAN0IDMR5                       _CAN0IDMR5.Byte
#define CAN0IDMR5_AM0                   _CAN0IDMR5.Bits.AM0
#define CAN0IDMR5_AM1                   _CAN0IDMR5.Bits.AM1
#define CAN0IDMR5_AM2                   _CAN0IDMR5.Bits.AM2
#define CAN0IDMR5_AM3                   _CAN0IDMR5.Bits.AM3
#define CAN0IDMR5_AM4                   _CAN0IDMR5.Bits.AM4
#define CAN0IDMR5_AM5                   _CAN0IDMR5.Bits.AM5
#define CAN0IDMR5_AM6                   _CAN0IDMR5.Bits.AM6
#define CAN0IDMR5_AM7                   _CAN0IDMR5.Bits.AM7

#define CAN0IDMR5_AM0_MASK              1U
#define CAN0IDMR5_AM1_MASK              2U
#define CAN0IDMR5_AM2_MASK              4U
#define CAN0IDMR5_AM3_MASK              8U
#define CAN0IDMR5_AM4_MASK              16U
#define CAN0IDMR5_AM5_MASK              32U
#define CAN0IDMR5_AM6_MASK              64U
#define CAN0IDMR5_AM7_MASK              128U


/*** CAN0IDMR6 - MSCAN0 Identifier Mask Register 6; 0x0000081E ***/
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
} CAN0IDMR6STR;
extern volatile CAN0IDMR6STR _CAN0IDMR6 @0x0000081E;
#define CAN0IDMR6                       _CAN0IDMR6.Byte
#define CAN0IDMR6_AM0                   _CAN0IDMR6.Bits.AM0
#define CAN0IDMR6_AM1                   _CAN0IDMR6.Bits.AM1
#define CAN0IDMR6_AM2                   _CAN0IDMR6.Bits.AM2
#define CAN0IDMR6_AM3                   _CAN0IDMR6.Bits.AM3
#define CAN0IDMR6_AM4                   _CAN0IDMR6.Bits.AM4
#define CAN0IDMR6_AM5                   _CAN0IDMR6.Bits.AM5
#define CAN0IDMR6_AM6                   _CAN0IDMR6.Bits.AM6
#define CAN0IDMR6_AM7                   _CAN0IDMR6.Bits.AM7

#define CAN0IDMR6_AM0_MASK              1U
#define CAN0IDMR6_AM1_MASK              2U
#define CAN0IDMR6_AM2_MASK              4U
#define CAN0IDMR6_AM3_MASK              8U
#define CAN0IDMR6_AM4_MASK              16U
#define CAN0IDMR6_AM5_MASK              32U
#define CAN0IDMR6_AM6_MASK              64U
#define CAN0IDMR6_AM7_MASK              128U


/*** CAN0IDMR7 - MSCAN0 Identifier Mask Register 7; 0x0000081F ***/
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
} CAN0IDMR7STR;
extern volatile CAN0IDMR7STR _CAN0IDMR7 @0x0000081F;
#define CAN0IDMR7                       _CAN0IDMR7.Byte
#define CAN0IDMR7_AM0                   _CAN0IDMR7.Bits.AM0
#define CAN0IDMR7_AM1                   _CAN0IDMR7.Bits.AM1
#define CAN0IDMR7_AM2                   _CAN0IDMR7.Bits.AM2
#define CAN0IDMR7_AM3                   _CAN0IDMR7.Bits.AM3
#define CAN0IDMR7_AM4                   _CAN0IDMR7.Bits.AM4
#define CAN0IDMR7_AM5                   _CAN0IDMR7.Bits.AM5
#define CAN0IDMR7_AM6                   _CAN0IDMR7.Bits.AM6
#define CAN0IDMR7_AM7                   _CAN0IDMR7.Bits.AM7

#define CAN0IDMR7_AM0_MASK              1U
#define CAN0IDMR7_AM1_MASK              2U
#define CAN0IDMR7_AM2_MASK              4U
#define CAN0IDMR7_AM3_MASK              8U
#define CAN0IDMR7_AM4_MASK              16U
#define CAN0IDMR7_AM5_MASK              32U
#define CAN0IDMR7_AM6_MASK              64U
#define CAN0IDMR7_AM7_MASK              128U


/*** CAN0RXIDR0 - MSCAN0 Receive Identifier Register 0; 0x00000820 ***/
typedef union {
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
} CAN0RXIDR0STR;
extern volatile CAN0RXIDR0STR _CAN0RXIDR0 @0x00000820;
#define CAN0RXIDR0                      _CAN0RXIDR0.Byte
#define CAN0RXIDR0_ID21                 _CAN0RXIDR0.Bits.ID21
#define CAN0RXIDR0_ID22                 _CAN0RXIDR0.Bits.ID22
#define CAN0RXIDR0_ID23                 _CAN0RXIDR0.Bits.ID23
#define CAN0RXIDR0_ID24                 _CAN0RXIDR0.Bits.ID24
#define CAN0RXIDR0_ID25                 _CAN0RXIDR0.Bits.ID25
#define CAN0RXIDR0_ID26                 _CAN0RXIDR0.Bits.ID26
#define CAN0RXIDR0_ID27                 _CAN0RXIDR0.Bits.ID27
#define CAN0RXIDR0_ID28                 _CAN0RXIDR0.Bits.ID28
/* CAN0RXIDR_ARR: Access 4 CAN0RXIDRx registers in an array */
#define CAN0RXIDR_ARR                   ((volatile byte *) &CAN0RXIDR0)

#define CAN0RXIDR0_ID21_MASK            1U
#define CAN0RXIDR0_ID22_MASK            2U
#define CAN0RXIDR0_ID23_MASK            4U
#define CAN0RXIDR0_ID24_MASK            8U
#define CAN0RXIDR0_ID25_MASK            16U
#define CAN0RXIDR0_ID26_MASK            32U
#define CAN0RXIDR0_ID27_MASK            64U
#define CAN0RXIDR0_ID28_MASK            128U


/*** CAN0RXIDR1 - MSCAN0 Receive Identifier Register 1; 0x00000821 ***/
typedef union {
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
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CAN0RXIDR1STR;
extern volatile CAN0RXIDR1STR _CAN0RXIDR1 @0x00000821;
#define CAN0RXIDR1                      _CAN0RXIDR1.Byte
#define CAN0RXIDR1_ID15                 _CAN0RXIDR1.Bits.ID15
#define CAN0RXIDR1_ID16                 _CAN0RXIDR1.Bits.ID16
#define CAN0RXIDR1_ID17                 _CAN0RXIDR1.Bits.ID17
#define CAN0RXIDR1_IDE                  _CAN0RXIDR1.Bits.IDE
#define CAN0RXIDR1_SRR                  _CAN0RXIDR1.Bits.SRR
#define CAN0RXIDR1_ID18                 _CAN0RXIDR1.Bits.ID18
#define CAN0RXIDR1_ID19                 _CAN0RXIDR1.Bits.ID19
#define CAN0RXIDR1_ID20                 _CAN0RXIDR1.Bits.ID20
#define CAN0RXIDR1_ID_15                _CAN0RXIDR1.MergedBits.grpID_15
#define CAN0RXIDR1_ID_18                _CAN0RXIDR1.MergedBits.grpID_18
#define CAN0RXIDR1_ID                   CAN0RXIDR1_ID_15

#define CAN0RXIDR1_ID15_MASK            1U
#define CAN0RXIDR1_ID16_MASK            2U
#define CAN0RXIDR1_ID17_MASK            4U
#define CAN0RXIDR1_IDE_MASK             8U
#define CAN0RXIDR1_SRR_MASK             16U
#define CAN0RXIDR1_ID18_MASK            32U
#define CAN0RXIDR1_ID19_MASK            64U
#define CAN0RXIDR1_ID20_MASK            128U
#define CAN0RXIDR1_ID_15_MASK           7U
#define CAN0RXIDR1_ID_15_BITNUM         0U
#define CAN0RXIDR1_ID_18_MASK           224U
#define CAN0RXIDR1_ID_18_BITNUM         5U


/*** CAN0RXIDR2 - MSCAN0 Receive Identifier Register 2; 0x00000822 ***/
typedef union {
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
} CAN0RXIDR2STR;
extern volatile CAN0RXIDR2STR _CAN0RXIDR2 @0x00000822;
#define CAN0RXIDR2                      _CAN0RXIDR2.Byte
#define CAN0RXIDR2_ID7                  _CAN0RXIDR2.Bits.ID7
#define CAN0RXIDR2_ID8                  _CAN0RXIDR2.Bits.ID8
#define CAN0RXIDR2_ID9                  _CAN0RXIDR2.Bits.ID9
#define CAN0RXIDR2_ID10                 _CAN0RXIDR2.Bits.ID10
#define CAN0RXIDR2_ID11                 _CAN0RXIDR2.Bits.ID11
#define CAN0RXIDR2_ID12                 _CAN0RXIDR2.Bits.ID12
#define CAN0RXIDR2_ID13                 _CAN0RXIDR2.Bits.ID13
#define CAN0RXIDR2_ID14                 _CAN0RXIDR2.Bits.ID14

#define CAN0RXIDR2_ID7_MASK             1U
#define CAN0RXIDR2_ID8_MASK             2U
#define CAN0RXIDR2_ID9_MASK             4U
#define CAN0RXIDR2_ID10_MASK            8U
#define CAN0RXIDR2_ID11_MASK            16U
#define CAN0RXIDR2_ID12_MASK            32U
#define CAN0RXIDR2_ID13_MASK            64U
#define CAN0RXIDR2_ID14_MASK            128U


/*** CAN0RXIDR3 - MSCAN0 Receive Identifier Register 3; 0x00000823 ***/
typedef union {
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
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CAN0RXIDR3STR;
extern volatile CAN0RXIDR3STR _CAN0RXIDR3 @0x00000823;
#define CAN0RXIDR3                      _CAN0RXIDR3.Byte
#define CAN0RXIDR3_RTR                  _CAN0RXIDR3.Bits.RTR
#define CAN0RXIDR3_ID0                  _CAN0RXIDR3.Bits.ID0
#define CAN0RXIDR3_ID1                  _CAN0RXIDR3.Bits.ID1
#define CAN0RXIDR3_ID2                  _CAN0RXIDR3.Bits.ID2
#define CAN0RXIDR3_ID3                  _CAN0RXIDR3.Bits.ID3
#define CAN0RXIDR3_ID4                  _CAN0RXIDR3.Bits.ID4
#define CAN0RXIDR3_ID5                  _CAN0RXIDR3.Bits.ID5
#define CAN0RXIDR3_ID6                  _CAN0RXIDR3.Bits.ID6
#define CAN0RXIDR3_ID                   _CAN0RXIDR3.MergedBits.grpID

#define CAN0RXIDR3_RTR_MASK             1U
#define CAN0RXIDR3_ID0_MASK             2U
#define CAN0RXIDR3_ID1_MASK             4U
#define CAN0RXIDR3_ID2_MASK             8U
#define CAN0RXIDR3_ID3_MASK             16U
#define CAN0RXIDR3_ID4_MASK             32U
#define CAN0RXIDR3_ID5_MASK             64U
#define CAN0RXIDR3_ID6_MASK             128U
#define CAN0RXIDR3_ID_MASK              254U
#define CAN0RXIDR3_ID_BITNUM            1U


/*** CAN0RXDSR0 - MSCAN0 Receive Data Segment Register 0; 0x00000824 ***/
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
} CAN0RXDSR0STR;
extern volatile CAN0RXDSR0STR _CAN0RXDSR0 @0x00000824;
#define CAN0RXDSR0                      _CAN0RXDSR0.Byte
#define CAN0RXDSR0_DB0                  _CAN0RXDSR0.Bits.DB0
#define CAN0RXDSR0_DB1                  _CAN0RXDSR0.Bits.DB1
#define CAN0RXDSR0_DB2                  _CAN0RXDSR0.Bits.DB2
#define CAN0RXDSR0_DB3                  _CAN0RXDSR0.Bits.DB3
#define CAN0RXDSR0_DB4                  _CAN0RXDSR0.Bits.DB4
#define CAN0RXDSR0_DB5                  _CAN0RXDSR0.Bits.DB5
#define CAN0RXDSR0_DB6                  _CAN0RXDSR0.Bits.DB6
#define CAN0RXDSR0_DB7                  _CAN0RXDSR0.Bits.DB7
/* CAN0RXDSR_ARR: Access 8 CAN0RXDSRx registers in an array */
#define CAN0RXDSR_ARR                   ((volatile byte *) &CAN0RXDSR0)

#define CAN0RXDSR0_DB0_MASK             1U
#define CAN0RXDSR0_DB1_MASK             2U
#define CAN0RXDSR0_DB2_MASK             4U
#define CAN0RXDSR0_DB3_MASK             8U
#define CAN0RXDSR0_DB4_MASK             16U
#define CAN0RXDSR0_DB5_MASK             32U
#define CAN0RXDSR0_DB6_MASK             64U
#define CAN0RXDSR0_DB7_MASK             128U


/*** CAN0RXDSR1 - MSCAN0 Receive Data Segment Register 1; 0x00000825 ***/
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
} CAN0RXDSR1STR;
extern volatile CAN0RXDSR1STR _CAN0RXDSR1 @0x00000825;
#define CAN0RXDSR1                      _CAN0RXDSR1.Byte
#define CAN0RXDSR1_DB0                  _CAN0RXDSR1.Bits.DB0
#define CAN0RXDSR1_DB1                  _CAN0RXDSR1.Bits.DB1
#define CAN0RXDSR1_DB2                  _CAN0RXDSR1.Bits.DB2
#define CAN0RXDSR1_DB3                  _CAN0RXDSR1.Bits.DB3
#define CAN0RXDSR1_DB4                  _CAN0RXDSR1.Bits.DB4
#define CAN0RXDSR1_DB5                  _CAN0RXDSR1.Bits.DB5
#define CAN0RXDSR1_DB6                  _CAN0RXDSR1.Bits.DB6
#define CAN0RXDSR1_DB7                  _CAN0RXDSR1.Bits.DB7

#define CAN0RXDSR1_DB0_MASK             1U
#define CAN0RXDSR1_DB1_MASK             2U
#define CAN0RXDSR1_DB2_MASK             4U
#define CAN0RXDSR1_DB3_MASK             8U
#define CAN0RXDSR1_DB4_MASK             16U
#define CAN0RXDSR1_DB5_MASK             32U
#define CAN0RXDSR1_DB6_MASK             64U
#define CAN0RXDSR1_DB7_MASK             128U


/*** CAN0RXDSR2 - MSCAN0 Receive Data Segment Register 2; 0x00000826 ***/
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
} CAN0RXDSR2STR;
extern volatile CAN0RXDSR2STR _CAN0RXDSR2 @0x00000826;
#define CAN0RXDSR2                      _CAN0RXDSR2.Byte
#define CAN0RXDSR2_DB0                  _CAN0RXDSR2.Bits.DB0
#define CAN0RXDSR2_DB1                  _CAN0RXDSR2.Bits.DB1
#define CAN0RXDSR2_DB2                  _CAN0RXDSR2.Bits.DB2
#define CAN0RXDSR2_DB3                  _CAN0RXDSR2.Bits.DB3
#define CAN0RXDSR2_DB4                  _CAN0RXDSR2.Bits.DB4
#define CAN0RXDSR2_DB5                  _CAN0RXDSR2.Bits.DB5
#define CAN0RXDSR2_DB6                  _CAN0RXDSR2.Bits.DB6
#define CAN0RXDSR2_DB7                  _CAN0RXDSR2.Bits.DB7

#define CAN0RXDSR2_DB0_MASK             1U
#define CAN0RXDSR2_DB1_MASK             2U
#define CAN0RXDSR2_DB2_MASK             4U
#define CAN0RXDSR2_DB3_MASK             8U
#define CAN0RXDSR2_DB4_MASK             16U
#define CAN0RXDSR2_DB5_MASK             32U
#define CAN0RXDSR2_DB6_MASK             64U
#define CAN0RXDSR2_DB7_MASK             128U


/*** CAN0RXDSR3 - MSCAN0 Receive Data Segment Register 3; 0x00000827 ***/
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
} CAN0RXDSR3STR;
extern volatile CAN0RXDSR3STR _CAN0RXDSR3 @0x00000827;
#define CAN0RXDSR3                      _CAN0RXDSR3.Byte
#define CAN0RXDSR3_DB0                  _CAN0RXDSR3.Bits.DB0
#define CAN0RXDSR3_DB1                  _CAN0RXDSR3.Bits.DB1
#define CAN0RXDSR3_DB2                  _CAN0RXDSR3.Bits.DB2
#define CAN0RXDSR3_DB3                  _CAN0RXDSR3.Bits.DB3
#define CAN0RXDSR3_DB4                  _CAN0RXDSR3.Bits.DB4
#define CAN0RXDSR3_DB5                  _CAN0RXDSR3.Bits.DB5
#define CAN0RXDSR3_DB6                  _CAN0RXDSR3.Bits.DB6
#define CAN0RXDSR3_DB7                  _CAN0RXDSR3.Bits.DB7

#define CAN0RXDSR3_DB0_MASK             1U
#define CAN0RXDSR3_DB1_MASK             2U
#define CAN0RXDSR3_DB2_MASK             4U
#define CAN0RXDSR3_DB3_MASK             8U
#define CAN0RXDSR3_DB4_MASK             16U
#define CAN0RXDSR3_DB5_MASK             32U
#define CAN0RXDSR3_DB6_MASK             64U
#define CAN0RXDSR3_DB7_MASK             128U


/*** CAN0RXDSR4 - MSCAN0 Receive Data Segment Register 4; 0x00000828 ***/
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
} CAN0RXDSR4STR;
extern volatile CAN0RXDSR4STR _CAN0RXDSR4 @0x00000828;
#define CAN0RXDSR4                      _CAN0RXDSR4.Byte
#define CAN0RXDSR4_DB0                  _CAN0RXDSR4.Bits.DB0
#define CAN0RXDSR4_DB1                  _CAN0RXDSR4.Bits.DB1
#define CAN0RXDSR4_DB2                  _CAN0RXDSR4.Bits.DB2
#define CAN0RXDSR4_DB3                  _CAN0RXDSR4.Bits.DB3
#define CAN0RXDSR4_DB4                  _CAN0RXDSR4.Bits.DB4
#define CAN0RXDSR4_DB5                  _CAN0RXDSR4.Bits.DB5
#define CAN0RXDSR4_DB6                  _CAN0RXDSR4.Bits.DB6
#define CAN0RXDSR4_DB7                  _CAN0RXDSR4.Bits.DB7

#define CAN0RXDSR4_DB0_MASK             1U
#define CAN0RXDSR4_DB1_MASK             2U
#define CAN0RXDSR4_DB2_MASK             4U
#define CAN0RXDSR4_DB3_MASK             8U
#define CAN0RXDSR4_DB4_MASK             16U
#define CAN0RXDSR4_DB5_MASK             32U
#define CAN0RXDSR4_DB6_MASK             64U
#define CAN0RXDSR4_DB7_MASK             128U


/*** CAN0RXDSR5 - MSCAN0 Receive Data Segment Register 5; 0x00000829 ***/
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
} CAN0RXDSR5STR;
extern volatile CAN0RXDSR5STR _CAN0RXDSR5 @0x00000829;
#define CAN0RXDSR5                      _CAN0RXDSR5.Byte
#define CAN0RXDSR5_DB0                  _CAN0RXDSR5.Bits.DB0
#define CAN0RXDSR5_DB1                  _CAN0RXDSR5.Bits.DB1
#define CAN0RXDSR5_DB2                  _CAN0RXDSR5.Bits.DB2
#define CAN0RXDSR5_DB3                  _CAN0RXDSR5.Bits.DB3
#define CAN0RXDSR5_DB4                  _CAN0RXDSR5.Bits.DB4
#define CAN0RXDSR5_DB5                  _CAN0RXDSR5.Bits.DB5
#define CAN0RXDSR5_DB6                  _CAN0RXDSR5.Bits.DB6
#define CAN0RXDSR5_DB7                  _CAN0RXDSR5.Bits.DB7

#define CAN0RXDSR5_DB0_MASK             1U
#define CAN0RXDSR5_DB1_MASK             2U
#define CAN0RXDSR5_DB2_MASK             4U
#define CAN0RXDSR5_DB3_MASK             8U
#define CAN0RXDSR5_DB4_MASK             16U
#define CAN0RXDSR5_DB5_MASK             32U
#define CAN0RXDSR5_DB6_MASK             64U
#define CAN0RXDSR5_DB7_MASK             128U


/*** CAN0RXDSR6 - MSCAN0 Receive Data Segment Register 6; 0x0000082A ***/
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
} CAN0RXDSR6STR;
extern volatile CAN0RXDSR6STR _CAN0RXDSR6 @0x0000082A;
#define CAN0RXDSR6                      _CAN0RXDSR6.Byte
#define CAN0RXDSR6_DB0                  _CAN0RXDSR6.Bits.DB0
#define CAN0RXDSR6_DB1                  _CAN0RXDSR6.Bits.DB1
#define CAN0RXDSR6_DB2                  _CAN0RXDSR6.Bits.DB2
#define CAN0RXDSR6_DB3                  _CAN0RXDSR6.Bits.DB3
#define CAN0RXDSR6_DB4                  _CAN0RXDSR6.Bits.DB4
#define CAN0RXDSR6_DB5                  _CAN0RXDSR6.Bits.DB5
#define CAN0RXDSR6_DB6                  _CAN0RXDSR6.Bits.DB6
#define CAN0RXDSR6_DB7                  _CAN0RXDSR6.Bits.DB7

#define CAN0RXDSR6_DB0_MASK             1U
#define CAN0RXDSR6_DB1_MASK             2U
#define CAN0RXDSR6_DB2_MASK             4U
#define CAN0RXDSR6_DB3_MASK             8U
#define CAN0RXDSR6_DB4_MASK             16U
#define CAN0RXDSR6_DB5_MASK             32U
#define CAN0RXDSR6_DB6_MASK             64U
#define CAN0RXDSR6_DB7_MASK             128U


/*** CAN0RXDSR7 - MSCAN0 Receive Data Segment Register 7; 0x0000082B ***/
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
} CAN0RXDSR7STR;
extern volatile CAN0RXDSR7STR _CAN0RXDSR7 @0x0000082B;
#define CAN0RXDSR7                      _CAN0RXDSR7.Byte
#define CAN0RXDSR7_DB0                  _CAN0RXDSR7.Bits.DB0
#define CAN0RXDSR7_DB1                  _CAN0RXDSR7.Bits.DB1
#define CAN0RXDSR7_DB2                  _CAN0RXDSR7.Bits.DB2
#define CAN0RXDSR7_DB3                  _CAN0RXDSR7.Bits.DB3
#define CAN0RXDSR7_DB4                  _CAN0RXDSR7.Bits.DB4
#define CAN0RXDSR7_DB5                  _CAN0RXDSR7.Bits.DB5
#define CAN0RXDSR7_DB6                  _CAN0RXDSR7.Bits.DB6
#define CAN0RXDSR7_DB7                  _CAN0RXDSR7.Bits.DB7

#define CAN0RXDSR7_DB0_MASK             1U
#define CAN0RXDSR7_DB1_MASK             2U
#define CAN0RXDSR7_DB2_MASK             4U
#define CAN0RXDSR7_DB3_MASK             8U
#define CAN0RXDSR7_DB4_MASK             16U
#define CAN0RXDSR7_DB5_MASK             32U
#define CAN0RXDSR7_DB6_MASK             64U
#define CAN0RXDSR7_DB7_MASK             128U


/*** CAN0RXDLR - MSCAN0 Receive Data Length Register; 0x0000082C ***/
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
} CAN0RXDLRSTR;
extern volatile CAN0RXDLRSTR _CAN0RXDLR @0x0000082C;
#define CAN0RXDLR                       _CAN0RXDLR.Byte
#define CAN0RXDLR_DLC0                  _CAN0RXDLR.Bits.DLC0
#define CAN0RXDLR_DLC1                  _CAN0RXDLR.Bits.DLC1
#define CAN0RXDLR_DLC2                  _CAN0RXDLR.Bits.DLC2
#define CAN0RXDLR_DLC3                  _CAN0RXDLR.Bits.DLC3
#define CAN0RXDLR_DLC                   _CAN0RXDLR.MergedBits.grpDLC

#define CAN0RXDLR_DLC0_MASK             1U
#define CAN0RXDLR_DLC1_MASK             2U
#define CAN0RXDLR_DLC2_MASK             4U
#define CAN0RXDLR_DLC3_MASK             8U
#define CAN0RXDLR_DLC_MASK              15U
#define CAN0RXDLR_DLC_BITNUM            0U


/*** CAN0RXTSR - MSCAN0 Receive Time Stamp Register; 0x0000082E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CAN0RXTSRH - MSCAN0 Receive Time Stamp Register High; 0x0000082E ***/
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
    } CAN0RXTSRHSTR;
    #define CAN0RXTSRH                  _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Byte
    #define CAN0RXTSRH_TSR8             _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR8
    #define CAN0RXTSRH_TSR9             _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR9
    #define CAN0RXTSRH_TSR10            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR10
    #define CAN0RXTSRH_TSR11            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR11
    #define CAN0RXTSRH_TSR12            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR12
    #define CAN0RXTSRH_TSR13            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR13
    #define CAN0RXTSRH_TSR14            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR14
    #define CAN0RXTSRH_TSR15            _CAN0RXTSR.Overlap_STR.CAN0RXTSRHSTR.Bits.TSR15
    
    #define CAN0RXTSRH_TSR8_MASK        1U
    #define CAN0RXTSRH_TSR9_MASK        2U
    #define CAN0RXTSRH_TSR10_MASK       4U
    #define CAN0RXTSRH_TSR11_MASK       8U
    #define CAN0RXTSRH_TSR12_MASK       16U
    #define CAN0RXTSRH_TSR13_MASK       32U
    #define CAN0RXTSRH_TSR14_MASK       64U
    #define CAN0RXTSRH_TSR15_MASK       128U
    

    /*** CAN0RXTSRL - MSCAN0 Receive Time Stamp Register Low; 0x0000082F ***/
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
    } CAN0RXTSRLSTR;
    #define CAN0RXTSRL                  _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Byte
    #define CAN0RXTSRL_TSR0             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR0
    #define CAN0RXTSRL_TSR1             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR1
    #define CAN0RXTSRL_TSR2             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR2
    #define CAN0RXTSRL_TSR3             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR3
    #define CAN0RXTSRL_TSR4             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR4
    #define CAN0RXTSRL_TSR5             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR5
    #define CAN0RXTSRL_TSR6             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR6
    #define CAN0RXTSRL_TSR7             _CAN0RXTSR.Overlap_STR.CAN0RXTSRLSTR.Bits.TSR7
    
    #define CAN0RXTSRL_TSR0_MASK        1U
    #define CAN0RXTSRL_TSR1_MASK        2U
    #define CAN0RXTSRL_TSR2_MASK        4U
    #define CAN0RXTSRL_TSR3_MASK        8U
    #define CAN0RXTSRL_TSR4_MASK        16U
    #define CAN0RXTSRL_TSR5_MASK        32U
    #define CAN0RXTSRL_TSR6_MASK        64U
    #define CAN0RXTSRL_TSR7_MASK        128U
    
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
} CAN0RXTSRSTR;
extern volatile CAN0RXTSRSTR _CAN0RXTSR @0x0000082E;
#define CAN0RXTSR                       _CAN0RXTSR.Word
#define CAN0RXTSR_TSR0                  _CAN0RXTSR.Bits.TSR0
#define CAN0RXTSR_TSR1                  _CAN0RXTSR.Bits.TSR1
#define CAN0RXTSR_TSR2                  _CAN0RXTSR.Bits.TSR2
#define CAN0RXTSR_TSR3                  _CAN0RXTSR.Bits.TSR3
#define CAN0RXTSR_TSR4                  _CAN0RXTSR.Bits.TSR4
#define CAN0RXTSR_TSR5                  _CAN0RXTSR.Bits.TSR5
#define CAN0RXTSR_TSR6                  _CAN0RXTSR.Bits.TSR6
#define CAN0RXTSR_TSR7                  _CAN0RXTSR.Bits.TSR7
#define CAN0RXTSR_TSR8                  _CAN0RXTSR.Bits.TSR8
#define CAN0RXTSR_TSR9                  _CAN0RXTSR.Bits.TSR9
#define CAN0RXTSR_TSR10                 _CAN0RXTSR.Bits.TSR10
#define CAN0RXTSR_TSR11                 _CAN0RXTSR.Bits.TSR11
#define CAN0RXTSR_TSR12                 _CAN0RXTSR.Bits.TSR12
#define CAN0RXTSR_TSR13                 _CAN0RXTSR.Bits.TSR13
#define CAN0RXTSR_TSR14                 _CAN0RXTSR.Bits.TSR14
#define CAN0RXTSR_TSR15                 _CAN0RXTSR.Bits.TSR15

#define CAN0RXTSR_TSR0_MASK             1U
#define CAN0RXTSR_TSR1_MASK             2U
#define CAN0RXTSR_TSR2_MASK             4U
#define CAN0RXTSR_TSR3_MASK             8U
#define CAN0RXTSR_TSR4_MASK             16U
#define CAN0RXTSR_TSR5_MASK             32U
#define CAN0RXTSR_TSR6_MASK             64U
#define CAN0RXTSR_TSR7_MASK             128U
#define CAN0RXTSR_TSR8_MASK             256U
#define CAN0RXTSR_TSR9_MASK             512U
#define CAN0RXTSR_TSR10_MASK            1024U
#define CAN0RXTSR_TSR11_MASK            2048U
#define CAN0RXTSR_TSR12_MASK            4096U
#define CAN0RXTSR_TSR13_MASK            8192U
#define CAN0RXTSR_TSR14_MASK            16384U
#define CAN0RXTSR_TSR15_MASK            32768U


/*** CAN0TXIDR0 - MSCAN0 Transmit Identifier Register 0; 0x00000830 ***/
typedef union {
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
} CAN0TXIDR0STR;
extern volatile CAN0TXIDR0STR _CAN0TXIDR0 @0x00000830;
#define CAN0TXIDR0                      _CAN0TXIDR0.Byte
#define CAN0TXIDR0_ID21                 _CAN0TXIDR0.Bits.ID21
#define CAN0TXIDR0_ID22                 _CAN0TXIDR0.Bits.ID22
#define CAN0TXIDR0_ID23                 _CAN0TXIDR0.Bits.ID23
#define CAN0TXIDR0_ID24                 _CAN0TXIDR0.Bits.ID24
#define CAN0TXIDR0_ID25                 _CAN0TXIDR0.Bits.ID25
#define CAN0TXIDR0_ID26                 _CAN0TXIDR0.Bits.ID26
#define CAN0TXIDR0_ID27                 _CAN0TXIDR0.Bits.ID27
#define CAN0TXIDR0_ID28                 _CAN0TXIDR0.Bits.ID28
/* CAN0TXIDR_ARR: Access 4 CAN0TXIDRx registers in an array */
#define CAN0TXIDR_ARR                   ((volatile byte *) &CAN0TXIDR0)

#define CAN0TXIDR0_ID21_MASK            1U
#define CAN0TXIDR0_ID22_MASK            2U
#define CAN0TXIDR0_ID23_MASK            4U
#define CAN0TXIDR0_ID24_MASK            8U
#define CAN0TXIDR0_ID25_MASK            16U
#define CAN0TXIDR0_ID26_MASK            32U
#define CAN0TXIDR0_ID27_MASK            64U
#define CAN0TXIDR0_ID28_MASK            128U


/*** CAN0TXIDR1 - MSCAN0 Transmit Identifier Register 1; 0x00000831 ***/
typedef union {
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
    byte         :1;
    byte         :1;
    byte grpID_18 :3;
  } MergedBits;
} CAN0TXIDR1STR;
extern volatile CAN0TXIDR1STR _CAN0TXIDR1 @0x00000831;
#define CAN0TXIDR1                      _CAN0TXIDR1.Byte
#define CAN0TXIDR1_ID15                 _CAN0TXIDR1.Bits.ID15
#define CAN0TXIDR1_ID16                 _CAN0TXIDR1.Bits.ID16
#define CAN0TXIDR1_ID17                 _CAN0TXIDR1.Bits.ID17
#define CAN0TXIDR1_IDE                  _CAN0TXIDR1.Bits.IDE
#define CAN0TXIDR1_SRR                  _CAN0TXIDR1.Bits.SRR
#define CAN0TXIDR1_ID18                 _CAN0TXIDR1.Bits.ID18
#define CAN0TXIDR1_ID19                 _CAN0TXIDR1.Bits.ID19
#define CAN0TXIDR1_ID20                 _CAN0TXIDR1.Bits.ID20
#define CAN0TXIDR1_ID_15                _CAN0TXIDR1.MergedBits.grpID_15
#define CAN0TXIDR1_ID_18                _CAN0TXIDR1.MergedBits.grpID_18
#define CAN0TXIDR1_ID                   CAN0TXIDR1_ID_15

#define CAN0TXIDR1_ID15_MASK            1U
#define CAN0TXIDR1_ID16_MASK            2U
#define CAN0TXIDR1_ID17_MASK            4U
#define CAN0TXIDR1_IDE_MASK             8U
#define CAN0TXIDR1_SRR_MASK             16U
#define CAN0TXIDR1_ID18_MASK            32U
#define CAN0TXIDR1_ID19_MASK            64U
#define CAN0TXIDR1_ID20_MASK            128U
#define CAN0TXIDR1_ID_15_MASK           7U
#define CAN0TXIDR1_ID_15_BITNUM         0U
#define CAN0TXIDR1_ID_18_MASK           224U
#define CAN0TXIDR1_ID_18_BITNUM         5U


/*** CAN0TXIDR2 - MSCAN0 Transmit Identifier Register 2; 0x00000832 ***/
typedef union {
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
} CAN0TXIDR2STR;
extern volatile CAN0TXIDR2STR _CAN0TXIDR2 @0x00000832;
#define CAN0TXIDR2                      _CAN0TXIDR2.Byte
#define CAN0TXIDR2_ID7                  _CAN0TXIDR2.Bits.ID7
#define CAN0TXIDR2_ID8                  _CAN0TXIDR2.Bits.ID8
#define CAN0TXIDR2_ID9                  _CAN0TXIDR2.Bits.ID9
#define CAN0TXIDR2_ID10                 _CAN0TXIDR2.Bits.ID10
#define CAN0TXIDR2_ID11                 _CAN0TXIDR2.Bits.ID11
#define CAN0TXIDR2_ID12                 _CAN0TXIDR2.Bits.ID12
#define CAN0TXIDR2_ID13                 _CAN0TXIDR2.Bits.ID13
#define CAN0TXIDR2_ID14                 _CAN0TXIDR2.Bits.ID14

#define CAN0TXIDR2_ID7_MASK             1U
#define CAN0TXIDR2_ID8_MASK             2U
#define CAN0TXIDR2_ID9_MASK             4U
#define CAN0TXIDR2_ID10_MASK            8U
#define CAN0TXIDR2_ID11_MASK            16U
#define CAN0TXIDR2_ID12_MASK            32U
#define CAN0TXIDR2_ID13_MASK            64U
#define CAN0TXIDR2_ID14_MASK            128U


/*** CAN0TXIDR3 - MSCAN0 Transmit Identifier Register 3; 0x00000833 ***/
typedef union {
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
    byte         :1;
    byte grpID   :7;
  } MergedBits;
} CAN0TXIDR3STR;
extern volatile CAN0TXIDR3STR _CAN0TXIDR3 @0x00000833;
#define CAN0TXIDR3                      _CAN0TXIDR3.Byte
#define CAN0TXIDR3_RTR                  _CAN0TXIDR3.Bits.RTR
#define CAN0TXIDR3_ID0                  _CAN0TXIDR3.Bits.ID0
#define CAN0TXIDR3_ID1                  _CAN0TXIDR3.Bits.ID1
#define CAN0TXIDR3_ID2                  _CAN0TXIDR3.Bits.ID2
#define CAN0TXIDR3_ID3                  _CAN0TXIDR3.Bits.ID3
#define CAN0TXIDR3_ID4                  _CAN0TXIDR3.Bits.ID4
#define CAN0TXIDR3_ID5                  _CAN0TXIDR3.Bits.ID5
#define CAN0TXIDR3_ID6                  _CAN0TXIDR3.Bits.ID6
#define CAN0TXIDR3_ID                   _CAN0TXIDR3.MergedBits.grpID

#define CAN0TXIDR3_RTR_MASK             1U
#define CAN0TXIDR3_ID0_MASK             2U
#define CAN0TXIDR3_ID1_MASK             4U
#define CAN0TXIDR3_ID2_MASK             8U
#define CAN0TXIDR3_ID3_MASK             16U
#define CAN0TXIDR3_ID4_MASK             32U
#define CAN0TXIDR3_ID5_MASK             64U
#define CAN0TXIDR3_ID6_MASK             128U
#define CAN0TXIDR3_ID_MASK              254U
#define CAN0TXIDR3_ID_BITNUM            1U


/*** CAN0TXDSR0 - MSCAN0 Transmit Data Segment Register 0; 0x00000834 ***/
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
} CAN0TXDSR0STR;
extern volatile CAN0TXDSR0STR _CAN0TXDSR0 @0x00000834;
#define CAN0TXDSR0                      _CAN0TXDSR0.Byte
#define CAN0TXDSR0_DB0                  _CAN0TXDSR0.Bits.DB0
#define CAN0TXDSR0_DB1                  _CAN0TXDSR0.Bits.DB1
#define CAN0TXDSR0_DB2                  _CAN0TXDSR0.Bits.DB2
#define CAN0TXDSR0_DB3                  _CAN0TXDSR0.Bits.DB3
#define CAN0TXDSR0_DB4                  _CAN0TXDSR0.Bits.DB4
#define CAN0TXDSR0_DB5                  _CAN0TXDSR0.Bits.DB5
#define CAN0TXDSR0_DB6                  _CAN0TXDSR0.Bits.DB6
#define CAN0TXDSR0_DB7                  _CAN0TXDSR0.Bits.DB7
/* CAN0TXDSR_ARR: Access 8 CAN0TXDSRx registers in an array */
#define CAN0TXDSR_ARR                   ((volatile byte *) &CAN0TXDSR0)

#define CAN0TXDSR0_DB0_MASK             1U
#define CAN0TXDSR0_DB1_MASK             2U
#define CAN0TXDSR0_DB2_MASK             4U
#define CAN0TXDSR0_DB3_MASK             8U
#define CAN0TXDSR0_DB4_MASK             16U
#define CAN0TXDSR0_DB5_MASK             32U
#define CAN0TXDSR0_DB6_MASK             64U
#define CAN0TXDSR0_DB7_MASK             128U


/*** CAN0TXDSR1 - MSCAN0 Transmit Data Segment Register 1; 0x00000835 ***/
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
} CAN0TXDSR1STR;
extern volatile CAN0TXDSR1STR _CAN0TXDSR1 @0x00000835;
#define CAN0TXDSR1                      _CAN0TXDSR1.Byte
#define CAN0TXDSR1_DB0                  _CAN0TXDSR1.Bits.DB0
#define CAN0TXDSR1_DB1                  _CAN0TXDSR1.Bits.DB1
#define CAN0TXDSR1_DB2                  _CAN0TXDSR1.Bits.DB2
#define CAN0TXDSR1_DB3                  _CAN0TXDSR1.Bits.DB3
#define CAN0TXDSR1_DB4                  _CAN0TXDSR1.Bits.DB4
#define CAN0TXDSR1_DB5                  _CAN0TXDSR1.Bits.DB5
#define CAN0TXDSR1_DB6                  _CAN0TXDSR1.Bits.DB6
#define CAN0TXDSR1_DB7                  _CAN0TXDSR1.Bits.DB7

#define CAN0TXDSR1_DB0_MASK             1U
#define CAN0TXDSR1_DB1_MASK             2U
#define CAN0TXDSR1_DB2_MASK             4U
#define CAN0TXDSR1_DB3_MASK             8U
#define CAN0TXDSR1_DB4_MASK             16U
#define CAN0TXDSR1_DB5_MASK             32U
#define CAN0TXDSR1_DB6_MASK             64U
#define CAN0TXDSR1_DB7_MASK             128U


/*** CAN0TXDSR2 - MSCAN0 Transmit Data Segment Register 2; 0x00000836 ***/
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
} CAN0TXDSR2STR;
extern volatile CAN0TXDSR2STR _CAN0TXDSR2 @0x00000836;
#define CAN0TXDSR2                      _CAN0TXDSR2.Byte
#define CAN0TXDSR2_DB0                  _CAN0TXDSR2.Bits.DB0
#define CAN0TXDSR2_DB1                  _CAN0TXDSR2.Bits.DB1
#define CAN0TXDSR2_DB2                  _CAN0TXDSR2.Bits.DB2
#define CAN0TXDSR2_DB3                  _CAN0TXDSR2.Bits.DB3
#define CAN0TXDSR2_DB4                  _CAN0TXDSR2.Bits.DB4
#define CAN0TXDSR2_DB5                  _CAN0TXDSR2.Bits.DB5
#define CAN0TXDSR2_DB6                  _CAN0TXDSR2.Bits.DB6
#define CAN0TXDSR2_DB7                  _CAN0TXDSR2.Bits.DB7

#define CAN0TXDSR2_DB0_MASK             1U
#define CAN0TXDSR2_DB1_MASK             2U
#define CAN0TXDSR2_DB2_MASK             4U
#define CAN0TXDSR2_DB3_MASK             8U
#define CAN0TXDSR2_DB4_MASK             16U
#define CAN0TXDSR2_DB5_MASK             32U
#define CAN0TXDSR2_DB6_MASK             64U
#define CAN0TXDSR2_DB7_MASK             128U


/*** CAN0TXDSR3 - MSCAN0 Transmit Data Segment Register 3; 0x00000837 ***/
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
} CAN0TXDSR3STR;
extern volatile CAN0TXDSR3STR _CAN0TXDSR3 @0x00000837;
#define CAN0TXDSR3                      _CAN0TXDSR3.Byte
#define CAN0TXDSR3_DB0                  _CAN0TXDSR3.Bits.DB0
#define CAN0TXDSR3_DB1                  _CAN0TXDSR3.Bits.DB1
#define CAN0TXDSR3_DB2                  _CAN0TXDSR3.Bits.DB2
#define CAN0TXDSR3_DB3                  _CAN0TXDSR3.Bits.DB3
#define CAN0TXDSR3_DB4                  _CAN0TXDSR3.Bits.DB4
#define CAN0TXDSR3_DB5                  _CAN0TXDSR3.Bits.DB5
#define CAN0TXDSR3_DB6                  _CAN0TXDSR3.Bits.DB6
#define CAN0TXDSR3_DB7                  _CAN0TXDSR3.Bits.DB7

#define CAN0TXDSR3_DB0_MASK             1U
#define CAN0TXDSR3_DB1_MASK             2U
#define CAN0TXDSR3_DB2_MASK             4U
#define CAN0TXDSR3_DB3_MASK             8U
#define CAN0TXDSR3_DB4_MASK             16U
#define CAN0TXDSR3_DB5_MASK             32U
#define CAN0TXDSR3_DB6_MASK             64U
#define CAN0TXDSR3_DB7_MASK             128U


/*** CAN0TXDSR4 - MSCAN0 Transmit Data Segment Register 4; 0x00000838 ***/
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
} CAN0TXDSR4STR;
extern volatile CAN0TXDSR4STR _CAN0TXDSR4 @0x00000838;
#define CAN0TXDSR4                      _CAN0TXDSR4.Byte
#define CAN0TXDSR4_DB0                  _CAN0TXDSR4.Bits.DB0
#define CAN0TXDSR4_DB1                  _CAN0TXDSR4.Bits.DB1
#define CAN0TXDSR4_DB2                  _CAN0TXDSR4.Bits.DB2
#define CAN0TXDSR4_DB3                  _CAN0TXDSR4.Bits.DB3
#define CAN0TXDSR4_DB4                  _CAN0TXDSR4.Bits.DB4
#define CAN0TXDSR4_DB5                  _CAN0TXDSR4.Bits.DB5
#define CAN0TXDSR4_DB6                  _CAN0TXDSR4.Bits.DB6
#define CAN0TXDSR4_DB7                  _CAN0TXDSR4.Bits.DB7

#define CAN0TXDSR4_DB0_MASK             1U
#define CAN0TXDSR4_DB1_MASK             2U
#define CAN0TXDSR4_DB2_MASK             4U
#define CAN0TXDSR4_DB3_MASK             8U
#define CAN0TXDSR4_DB4_MASK             16U
#define CAN0TXDSR4_DB5_MASK             32U
#define CAN0TXDSR4_DB6_MASK             64U
#define CAN0TXDSR4_DB7_MASK             128U


/*** CAN0TXDSR5 - MSCAN0 Transmit Data Segment Register 5; 0x00000839 ***/
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
} CAN0TXDSR5STR;
extern volatile CAN0TXDSR5STR _CAN0TXDSR5 @0x00000839;
#define CAN0TXDSR5                      _CAN0TXDSR5.Byte
#define CAN0TXDSR5_DB0                  _CAN0TXDSR5.Bits.DB0
#define CAN0TXDSR5_DB1                  _CAN0TXDSR5.Bits.DB1
#define CAN0TXDSR5_DB2                  _CAN0TXDSR5.Bits.DB2
#define CAN0TXDSR5_DB3                  _CAN0TXDSR5.Bits.DB3
#define CAN0TXDSR5_DB4                  _CAN0TXDSR5.Bits.DB4
#define CAN0TXDSR5_DB5                  _CAN0TXDSR5.Bits.DB5
#define CAN0TXDSR5_DB6                  _CAN0TXDSR5.Bits.DB6
#define CAN0TXDSR5_DB7                  _CAN0TXDSR5.Bits.DB7

#define CAN0TXDSR5_DB0_MASK             1U
#define CAN0TXDSR5_DB1_MASK             2U
#define CAN0TXDSR5_DB2_MASK             4U
#define CAN0TXDSR5_DB3_MASK             8U
#define CAN0TXDSR5_DB4_MASK             16U
#define CAN0TXDSR5_DB5_MASK             32U
#define CAN0TXDSR5_DB6_MASK             64U
#define CAN0TXDSR5_DB7_MASK             128U


/*** CAN0TXDSR6 - MSCAN0 Transmit Data Segment Register 6; 0x0000083A ***/
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
} CAN0TXDSR6STR;
extern volatile CAN0TXDSR6STR _CAN0TXDSR6 @0x0000083A;
#define CAN0TXDSR6                      _CAN0TXDSR6.Byte
#define CAN0TXDSR6_DB0                  _CAN0TXDSR6.Bits.DB0
#define CAN0TXDSR6_DB1                  _CAN0TXDSR6.Bits.DB1
#define CAN0TXDSR6_DB2                  _CAN0TXDSR6.Bits.DB2
#define CAN0TXDSR6_DB3                  _CAN0TXDSR6.Bits.DB3
#define CAN0TXDSR6_DB4                  _CAN0TXDSR6.Bits.DB4
#define CAN0TXDSR6_DB5                  _CAN0TXDSR6.Bits.DB5
#define CAN0TXDSR6_DB6                  _CAN0TXDSR6.Bits.DB6
#define CAN0TXDSR6_DB7                  _CAN0TXDSR6.Bits.DB7

#define CAN0TXDSR6_DB0_MASK             1U
#define CAN0TXDSR6_DB1_MASK             2U
#define CAN0TXDSR6_DB2_MASK             4U
#define CAN0TXDSR6_DB3_MASK             8U
#define CAN0TXDSR6_DB4_MASK             16U
#define CAN0TXDSR6_DB5_MASK             32U
#define CAN0TXDSR6_DB6_MASK             64U
#define CAN0TXDSR6_DB7_MASK             128U


/*** CAN0TXDSR7 - MSCAN0 Transmit Data Segment Register 7; 0x0000083B ***/
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
} CAN0TXDSR7STR;
extern volatile CAN0TXDSR7STR _CAN0TXDSR7 @0x0000083B;
#define CAN0TXDSR7                      _CAN0TXDSR7.Byte
#define CAN0TXDSR7_DB0                  _CAN0TXDSR7.Bits.DB0
#define CAN0TXDSR7_DB1                  _CAN0TXDSR7.Bits.DB1
#define CAN0TXDSR7_DB2                  _CAN0TXDSR7.Bits.DB2
#define CAN0TXDSR7_DB3                  _CAN0TXDSR7.Bits.DB3
#define CAN0TXDSR7_DB4                  _CAN0TXDSR7.Bits.DB4
#define CAN0TXDSR7_DB5                  _CAN0TXDSR7.Bits.DB5
#define CAN0TXDSR7_DB6                  _CAN0TXDSR7.Bits.DB6
#define CAN0TXDSR7_DB7                  _CAN0TXDSR7.Bits.DB7

#define CAN0TXDSR7_DB0_MASK             1U
#define CAN0TXDSR7_DB1_MASK             2U
#define CAN0TXDSR7_DB2_MASK             4U
#define CAN0TXDSR7_DB3_MASK             8U
#define CAN0TXDSR7_DB4_MASK             16U
#define CAN0TXDSR7_DB5_MASK             32U
#define CAN0TXDSR7_DB6_MASK             64U
#define CAN0TXDSR7_DB7_MASK             128U


/*** CAN0TXDLR - MSCAN0 Transmit Data Length Register; 0x0000083C ***/
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
} CAN0TXDLRSTR;
extern volatile CAN0TXDLRSTR _CAN0TXDLR @0x0000083C;
#define CAN0TXDLR                       _CAN0TXDLR.Byte
#define CAN0TXDLR_DLC0                  _CAN0TXDLR.Bits.DLC0
#define CAN0TXDLR_DLC1                  _CAN0TXDLR.Bits.DLC1
#define CAN0TXDLR_DLC2                  _CAN0TXDLR.Bits.DLC2
#define CAN0TXDLR_DLC3                  _CAN0TXDLR.Bits.DLC3
#define CAN0TXDLR_DLC                   _CAN0TXDLR.MergedBits.grpDLC

#define CAN0TXDLR_DLC0_MASK             1U
#define CAN0TXDLR_DLC1_MASK             2U
#define CAN0TXDLR_DLC2_MASK             4U
#define CAN0TXDLR_DLC3_MASK             8U
#define CAN0TXDLR_DLC_MASK              15U
#define CAN0TXDLR_DLC_BITNUM            0U


/*** CAN0TXTBPR - MSCAN0 Transmit Buffer Priority; 0x0000083D ***/
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
} CAN0TXTBPRSTR;
extern volatile CAN0TXTBPRSTR _CAN0TXTBPR @0x0000083D;
#define CAN0TXTBPR                      _CAN0TXTBPR.Byte
#define CAN0TXTBPR_PRIO0                _CAN0TXTBPR.Bits.PRIO0
#define CAN0TXTBPR_PRIO1                _CAN0TXTBPR.Bits.PRIO1
#define CAN0TXTBPR_PRIO2                _CAN0TXTBPR.Bits.PRIO2
#define CAN0TXTBPR_PRIO3                _CAN0TXTBPR.Bits.PRIO3
#define CAN0TXTBPR_PRIO4                _CAN0TXTBPR.Bits.PRIO4
#define CAN0TXTBPR_PRIO5                _CAN0TXTBPR.Bits.PRIO5
#define CAN0TXTBPR_PRIO6                _CAN0TXTBPR.Bits.PRIO6
#define CAN0TXTBPR_PRIO7                _CAN0TXTBPR.Bits.PRIO7

#define CAN0TXTBPR_PRIO0_MASK           1U
#define CAN0TXTBPR_PRIO1_MASK           2U
#define CAN0TXTBPR_PRIO2_MASK           4U
#define CAN0TXTBPR_PRIO3_MASK           8U
#define CAN0TXTBPR_PRIO4_MASK           16U
#define CAN0TXTBPR_PRIO5_MASK           32U
#define CAN0TXTBPR_PRIO6_MASK           64U
#define CAN0TXTBPR_PRIO7_MASK           128U


/*** CAN0TXTSR - MSCAN0 Transmit Time Stamp Register; 0x0000083E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CAN0TXTSRH - MSCAN0 Transmit Time Stamp Register High; 0x0000083E ***/
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
    } CAN0TXTSRHSTR;
    #define CAN0TXTSRH                  _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Byte
    #define CAN0TXTSRH_TSR8             _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR8
    #define CAN0TXTSRH_TSR9             _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR9
    #define CAN0TXTSRH_TSR10            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR10
    #define CAN0TXTSRH_TSR11            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR11
    #define CAN0TXTSRH_TSR12            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR12
    #define CAN0TXTSRH_TSR13            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR13
    #define CAN0TXTSRH_TSR14            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR14
    #define CAN0TXTSRH_TSR15            _CAN0TXTSR.Overlap_STR.CAN0TXTSRHSTR.Bits.TSR15
    
    #define CAN0TXTSRH_TSR8_MASK        1U
    #define CAN0TXTSRH_TSR9_MASK        2U
    #define CAN0TXTSRH_TSR10_MASK       4U
    #define CAN0TXTSRH_TSR11_MASK       8U
    #define CAN0TXTSRH_TSR12_MASK       16U
    #define CAN0TXTSRH_TSR13_MASK       32U
    #define CAN0TXTSRH_TSR14_MASK       64U
    #define CAN0TXTSRH_TSR15_MASK       128U
    

    /*** CAN0TXTSRL - MSCAN0 Transmit Time Stamp Register Low; 0x0000083F ***/
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
    } CAN0TXTSRLSTR;
    #define CAN0TXTSRL                  _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Byte
    #define CAN0TXTSRL_TSR0             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR0
    #define CAN0TXTSRL_TSR1             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR1
    #define CAN0TXTSRL_TSR2             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR2
    #define CAN0TXTSRL_TSR3             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR3
    #define CAN0TXTSRL_TSR4             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR4
    #define CAN0TXTSRL_TSR5             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR5
    #define CAN0TXTSRL_TSR6             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR6
    #define CAN0TXTSRL_TSR7             _CAN0TXTSR.Overlap_STR.CAN0TXTSRLSTR.Bits.TSR7
    
    #define CAN0TXTSRL_TSR0_MASK        1U
    #define CAN0TXTSRL_TSR1_MASK        2U
    #define CAN0TXTSRL_TSR2_MASK        4U
    #define CAN0TXTSRL_TSR3_MASK        8U
    #define CAN0TXTSRL_TSR4_MASK        16U
    #define CAN0TXTSRL_TSR5_MASK        32U
    #define CAN0TXTSRL_TSR6_MASK        64U
    #define CAN0TXTSRL_TSR7_MASK        128U
    
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
} CAN0TXTSRSTR;
extern volatile CAN0TXTSRSTR _CAN0TXTSR @0x0000083E;
#define CAN0TXTSR                       _CAN0TXTSR.Word
#define CAN0TXTSR_TSR0                  _CAN0TXTSR.Bits.TSR0
#define CAN0TXTSR_TSR1                  _CAN0TXTSR.Bits.TSR1
#define CAN0TXTSR_TSR2                  _CAN0TXTSR.Bits.TSR2
#define CAN0TXTSR_TSR3                  _CAN0TXTSR.Bits.TSR3
#define CAN0TXTSR_TSR4                  _CAN0TXTSR.Bits.TSR4
#define CAN0TXTSR_TSR5                  _CAN0TXTSR.Bits.TSR5
#define CAN0TXTSR_TSR6                  _CAN0TXTSR.Bits.TSR6
#define CAN0TXTSR_TSR7                  _CAN0TXTSR.Bits.TSR7
#define CAN0TXTSR_TSR8                  _CAN0TXTSR.Bits.TSR8
#define CAN0TXTSR_TSR9                  _CAN0TXTSR.Bits.TSR9
#define CAN0TXTSR_TSR10                 _CAN0TXTSR.Bits.TSR10
#define CAN0TXTSR_TSR11                 _CAN0TXTSR.Bits.TSR11
#define CAN0TXTSR_TSR12                 _CAN0TXTSR.Bits.TSR12
#define CAN0TXTSR_TSR13                 _CAN0TXTSR.Bits.TSR13
#define CAN0TXTSR_TSR14                 _CAN0TXTSR.Bits.TSR14
#define CAN0TXTSR_TSR15                 _CAN0TXTSR.Bits.TSR15

#define CAN0TXTSR_TSR0_MASK             1U
#define CAN0TXTSR_TSR1_MASK             2U
#define CAN0TXTSR_TSR2_MASK             4U
#define CAN0TXTSR_TSR3_MASK             8U
#define CAN0TXTSR_TSR4_MASK             16U
#define CAN0TXTSR_TSR5_MASK             32U
#define CAN0TXTSR_TSR6_MASK             64U
#define CAN0TXTSR_TSR7_MASK             128U
#define CAN0TXTSR_TSR8_MASK             256U
#define CAN0TXTSR_TSR9_MASK             512U
#define CAN0TXTSR_TSR10_MASK            1024U
#define CAN0TXTSR_TSR11_MASK            2048U
#define CAN0TXTSR_TSR12_MASK            4096U
#define CAN0TXTSR_TSR13_MASK            8192U
#define CAN0TXTSR_TSR14_MASK            16384U
#define CAN0TXTSR_TSR15_MASK            32768U


/*** LP0DR - Port LP Data Register; 0x00000980 ***/
typedef union {
  byte Byte;
  struct {
    byte LPDR0       :1;                                       /* LIN Rx data */
    byte LPDR1       :1;                                       /* LIN Tx data */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpLPDR :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} LP0DRSTR;
extern volatile LP0DRSTR _LP0DR @0x00000980;
#define LP0DR                           _LP0DR.Byte
#define LP0DR_LPDR0                     _LP0DR.Bits.LPDR0
#define LP0DR_LPDR1                     _LP0DR.Bits.LPDR1
#define LP0DR_LPDR                      _LP0DR.MergedBits.grpLPDR

#define LP0DR_LPDR0_MASK                1U
#define LP0DR_LPDR1_MASK                2U
#define LP0DR_LPDR_MASK                 3U
#define LP0DR_LPDR_BITNUM               0U


/*** LP0CR - LIN Control Register; 0x00000981 ***/
typedef union {
  byte Byte;
  struct {
    byte LPPUE       :1;                                       /* LIN pull-up enable */
    byte LPWUE       :1;                                       /* LIN wake-up enable */
    byte RXONLY      :1;                                       /* Receive only mode */
    byte LPE         :1;                                       /* LIN enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} LP0CRSTR;
extern volatile LP0CRSTR _LP0CR @0x00000981;
#define LP0CR                           _LP0CR.Byte
#define LP0CR_LPPUE                     _LP0CR.Bits.LPPUE
#define LP0CR_LPWUE                     _LP0CR.Bits.LPWUE
#define LP0CR_RXONLY                    _LP0CR.Bits.RXONLY
#define LP0CR_LPE                       _LP0CR.Bits.LPE

#define LP0CR_LPPUE_MASK                1U
#define LP0CR_LPWUE_MASK                2U
#define LP0CR_RXONLY_MASK               4U
#define LP0CR_LPE_MASK                  8U


/*** LP0SLRM - LIN Slew Rate Register; 0x00000983 ***/
typedef union {
  byte Byte;
  struct {
    byte LPSLR       :2;                                       /* Slew rate select */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPDTDIS     :1;                                       /* TxD-dominant timeout disable */
  } Bits;
} LP0SLRMSTR;
extern volatile LP0SLRMSTR _LP0SLRM @0x00000983;
#define LP0SLRM                         _LP0SLRM.Byte
#define LP0SLRM_LPSLR                   _LP0SLRM.Bits.LPSLR
#define LP0SLRM_LPDTDIS                 _LP0SLRM.Bits.LPDTDIS

#define LP0SLRM_LPSLR_MASK              3U
#define LP0SLRM_LPSLR_BITNUM            0U
#define LP0SLRM_LPDTDIS_MASK            128U


/*** LP0SR - LIN Status Register; 0x00000985 ***/
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
    byte LPDT        :1;                                       /* LIN Transmitter TxD-dominant timeout Status */
  } Bits;
} LP0SRSTR;
extern volatile LP0SRSTR _LP0SR @0x00000985;
#define LP0SR                           _LP0SR.Byte
#define LP0SR_LPDT                      _LP0SR.Bits.LPDT

#define LP0SR_LPDT_MASK                 128U


/*** LP0IE - LIN Interrupt Enable Register; 0x00000986 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPOCIE      :1;                                       /* LIN over-current interrupt enable */
    byte LPDTIE      :1;                                       /* LIN TxD-dominant timeout Interrupt Enable */
  } Bits;
} LP0IESTR;
extern volatile LP0IESTR _LP0IE @0x00000986;
#define LP0IE                           _LP0IE.Byte
#define LP0IE_LPOCIE                    _LP0IE.Bits.LPOCIE
#define LP0IE_LPDTIE                    _LP0IE.Bits.LPDTIE

#define LP0IE_LPOCIE_MASK               64U
#define LP0IE_LPDTIE_MASK               128U


/*** LP0IF - LIN Interrupt Flags Register; 0x00000987 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LPOCIF      :1;                                       /* LIN transmitter over-current interrupt flag */
    byte LPDTIF      :1;                                       /* LIN Transmitter TxD-dominant timeout Interrupt Flag */
  } Bits;
} LP0IFSTR;
extern volatile LP0IFSTR _LP0IF @0x00000987;
#define LP0IF                           _LP0IF.Byte
#define LP0IF_LPOCIF                    _LP0IF.Bits.LPOCIF
#define LP0IF_LPDTIF                    _LP0IF.Bits.LPDTIF

#define LP0IF_LPOCIF_MASK               64U
#define LP0IF_LPDTIF_MASK               128U


/*** BAKEY0 - Backdoor Comparison Key 0; 0x00FFFE00 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Backdoor Comparison Key Bits */
  } Bits;
} BAKEY0STR;
/* Tip for register initialization in the user code:  const word BAKEY0_INIT @0x00FFFE00 = <BAKEY0_INITVAL>; */
#define _BAKEY0 (*(const BAKEY0STR *)0x00FFFE00)
#define BAKEY0                          _BAKEY0.Word
#define BAKEY0_KEY                      _BAKEY0.Bits.KEY
/* BAKEY_ARR: Access 4 BAKEYx registers in an array */
#define BAKEY_ARR                       ((volatile word *) &BAKEY0)

#define BAKEY0_KEY_MASK                 65535U
#define BAKEY0_KEY_BITNUM               0U


/*** BAKEY1 - Backdoor Comparison Key 1; 0x00FFFE02 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Backdoor Comparison Key Bits */
  } Bits;
} BAKEY1STR;
/* Tip for register initialization in the user code:  const word BAKEY1_INIT @0x00FFFE02 = <BAKEY1_INITVAL>; */
#define _BAKEY1 (*(const BAKEY1STR *)0x00FFFE02)
#define BAKEY1                          _BAKEY1.Word
#define BAKEY1_KEY                      _BAKEY1.Bits.KEY

#define BAKEY1_KEY_MASK                 65535U
#define BAKEY1_KEY_BITNUM               0U


/*** BAKEY2 - Backdoor Comparison Key 2; 0x00FFFE04 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Backdoor Comparison Key Bits */
  } Bits;
} BAKEY2STR;
/* Tip for register initialization in the user code:  const word BAKEY2_INIT @0x00FFFE04 = <BAKEY2_INITVAL>; */
#define _BAKEY2 (*(const BAKEY2STR *)0x00FFFE04)
#define BAKEY2                          _BAKEY2.Word
#define BAKEY2_KEY                      _BAKEY2.Bits.KEY

#define BAKEY2_KEY_MASK                 65535U
#define BAKEY2_KEY_BITNUM               0U


/*** BAKEY3 - Backdoor Comparison Key 3; 0x00FFFE06 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Backdoor Comparison Key Bits */
  } Bits;
} BAKEY3STR;
/* Tip for register initialization in the user code:  const word BAKEY3_INIT @0x00FFFE06 = <BAKEY3_INITVAL>; */
#define _BAKEY3 (*(const BAKEY3STR *)0x00FFFE06)
#define BAKEY3                          _BAKEY3.Word
#define BAKEY3_KEY                      _BAKEY3.Bits.KEY

#define BAKEY3_KEY_MASK                 65535U
#define BAKEY3_KEY_BITNUM               0U


/*** PROTKEY - Non Volatile Protection Override Comparison Key; 0x00FFFE08 ***/
typedef union {
  word Word;
  struct {
    word KEY         :16;                                      /* Protection Override Comparison Key Bits */
  } Bits;
} PROTKEYSTR;
/* Tip for register initialization in the user code:  const word PROTKEY_INIT @0x00FFFE08 = <PROTKEY_INITVAL>; */
#define _PROTKEY (*(const PROTKEYSTR *)0x00FFFE08)
#define PROTKEY                         _PROTKEY.Word
#define PROTKEY_KEY                     _PROTKEY.Bits.KEY

#define PROTKEY_KEY_MASK                65535U
#define PROTKEY_KEY_BITNUM              0U


/*** NVFPROT - Non Volatile P-Flash Protection Register; 0x00FFFE0C ***/
typedef union {
  byte Byte;
  struct {
    byte FPLS0       :1;                                       /* Flash Protection Lower Address Size Bit 0 */
    byte FPLS1       :1;                                       /* Flash Protection Lower Address Size Bit 1 */
    byte FPLDIS      :1;                                       /* Flash Protection Lower Address Range Disable */
    byte FPHS0       :1;                                       /* Flash Protection Higher Address Size Bit 0 */
    byte FPHS1       :1;                                       /* Flash Protection Higher Address Size Bit 1 */
    byte FPHDIS      :1;                                       /* Flash Protection Higher Address Range Disable */
    byte RNV6        :1;                                       /* Reserved Nonvolatile Bit */
    byte FPOPEN      :1;                                       /* Flash Protection Operation Enable */
  } Bits;
  struct {
    byte grpFPLS :2;
    byte         :1;
    byte grpFPHS :2;
    byte         :1;
    byte grpRNV_6 :1;
    byte         :1;
  } MergedBits;
} NVFPROTSTR;
/* Tip for register initialization in the user code:  const byte NVFPROT_INIT @0x00FFFE0C = <NVFPROT_INITVAL>; */
#define _NVFPROT (*(const NVFPROTSTR *)0x00FFFE0C)
#define NVFPROT                         _NVFPROT.Byte
#define NVFPROT_FPLS0                   _NVFPROT.Bits.FPLS0
#define NVFPROT_FPLS1                   _NVFPROT.Bits.FPLS1
#define NVFPROT_FPLDIS                  _NVFPROT.Bits.FPLDIS
#define NVFPROT_FPHS0                   _NVFPROT.Bits.FPHS0
#define NVFPROT_FPHS1                   _NVFPROT.Bits.FPHS1
#define NVFPROT_FPHDIS                  _NVFPROT.Bits.FPHDIS
#define NVFPROT_RNV6                    _NVFPROT.Bits.RNV6
#define NVFPROT_FPOPEN                  _NVFPROT.Bits.FPOPEN
#define NVFPROT_FPLS                    _NVFPROT.MergedBits.grpFPLS
#define NVFPROT_FPHS                    _NVFPROT.MergedBits.grpFPHS

#define NVFPROT_FPLS0_MASK              1U
#define NVFPROT_FPLS1_MASK              2U
#define NVFPROT_FPLDIS_MASK             4U
#define NVFPROT_FPHS0_MASK              8U
#define NVFPROT_FPHS1_MASK              16U
#define NVFPROT_FPHDIS_MASK             32U
#define NVFPROT_RNV6_MASK               64U
#define NVFPROT_FPOPEN_MASK             128U
#define NVFPROT_FPLS_MASK               3U
#define NVFPROT_FPLS_BITNUM             0U
#define NVFPROT_FPHS_MASK               24U
#define NVFPROT_FPHS_BITNUM             3U


/*** NVDFPROT - Non Volatile D-Flash Protection Register; 0x00FFFE0D ***/
typedef union {
  byte Byte;
  struct {
    byte DPS0        :1;                                       /* D-Flash Protection Size Bit 0 */
    byte DPS1        :1;                                       /* D-Flash Protection Size Bit 1 */
    byte DPS2        :1;                                       /* D-Flash Protection Size Bit 2 */
    byte DPS3        :1;                                       /* D-Flash Protection Size Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte DPOPEN      :1;                                       /* D-Flash Protection Control */
  } Bits;
  struct {
    byte grpDPS  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} NVDFPROTSTR;
/* Tip for register initialization in the user code:  const byte NVDFPROT_INIT @0x00FFFE0D = <NVDFPROT_INITVAL>; */
#define _NVDFPROT (*(const NVDFPROTSTR *)0x00FFFE0D)
#define NVDFPROT                        _NVDFPROT.Byte
#define NVDFPROT_DPS0                   _NVDFPROT.Bits.DPS0
#define NVDFPROT_DPS1                   _NVDFPROT.Bits.DPS1
#define NVDFPROT_DPS2                   _NVDFPROT.Bits.DPS2
#define NVDFPROT_DPS3                   _NVDFPROT.Bits.DPS3
#define NVDFPROT_DPOPEN                 _NVDFPROT.Bits.DPOPEN
#define NVDFPROT_DPS                    _NVDFPROT.MergedBits.grpDPS

#define NVDFPROT_DPS0_MASK              1U
#define NVDFPROT_DPS1_MASK              2U
#define NVDFPROT_DPS2_MASK              4U
#define NVDFPROT_DPS3_MASK              8U
#define NVDFPROT_DPOPEN_MASK            128U
#define NVDFPROT_DPS_MASK               15U
#define NVDFPROT_DPS_BITNUM             0U


/*** NVFOPT - Non Volatile Flash Option Register; 0x00FFFE0E ***/
typedef union {
  byte Byte;
  struct {
    byte NV0         :1;                                       /* Nonvolatile Bit 0 */
    byte NV1         :1;                                       /* Nonvolatile Bit 1 */
    byte NV2         :1;                                       /* Nonvolatile Bit 2 */
    byte NV3         :1;                                       /* Nonvolatile Bit 3 */
    byte NV4         :1;                                       /* Nonvolatile Bit 4 */
    byte NV5         :1;                                       /* Nonvolatile Bit 5 */
    byte NV6         :1;                                       /* Nonvolatile Bit 6 */
    byte NV7         :1;                                       /* Nonvolatile Bit 7 */
  } Bits;
} NVFOPTSTR;
/* Tip for register initialization in the user code:  const byte NVFOPT_INIT @0x00FFFE0E = <NVFOPT_INITVAL>; */
#define _NVFOPT (*(const NVFOPTSTR *)0x00FFFE0E)
#define NVFOPT                          _NVFOPT.Byte
#define NVFOPT_NV0                      _NVFOPT.Bits.NV0
#define NVFOPT_NV1                      _NVFOPT.Bits.NV1
#define NVFOPT_NV2                      _NVFOPT.Bits.NV2
#define NVFOPT_NV3                      _NVFOPT.Bits.NV3
#define NVFOPT_NV4                      _NVFOPT.Bits.NV4
#define NVFOPT_NV5                      _NVFOPT.Bits.NV5
#define NVFOPT_NV6                      _NVFOPT.Bits.NV6
#define NVFOPT_NV7                      _NVFOPT.Bits.NV7

#define NVFOPT_NV0_MASK                 1U
#define NVFOPT_NV1_MASK                 2U
#define NVFOPT_NV2_MASK                 4U
#define NVFOPT_NV3_MASK                 8U
#define NVFOPT_NV4_MASK                 16U
#define NVFOPT_NV5_MASK                 32U
#define NVFOPT_NV6_MASK                 64U
#define NVFOPT_NV7_MASK                 128U


/*** NVFSEC - Non Volatile Flash Security Register; 0x00FFFE0F ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte RNV2        :1;                                       /* Reserved Nonvolatile Bit 2 */
    byte RNV3        :1;                                       /* Reserved Nonvolatile Bit 3 */
    byte RNV4        :1;                                       /* Reserved Nonvolatile Bit 4 */
    byte RNV5        :1;                                       /* Reserved Nonvolatile Bit 5 */
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte grpRNV_2 :4;
    byte grpKEYEN :2;
  } MergedBits;
} NVFSECSTR;
/* Tip for register initialization in the user code:  const byte NVFSEC_INIT @0x00FFFE0F = <NVFSEC_INITVAL>; */
#define _NVFSEC (*(const NVFSECSTR *)0x00FFFE0F)
#define NVFSEC                          _NVFSEC.Byte
#define NVFSEC_SEC0                     _NVFSEC.Bits.SEC0
#define NVFSEC_SEC1                     _NVFSEC.Bits.SEC1
#define NVFSEC_RNV2                     _NVFSEC.Bits.RNV2
#define NVFSEC_RNV3                     _NVFSEC.Bits.RNV3
#define NVFSEC_RNV4                     _NVFSEC.Bits.RNV4
#define NVFSEC_RNV5                     _NVFSEC.Bits.RNV5
#define NVFSEC_KEYEN0                   _NVFSEC.Bits.KEYEN0
#define NVFSEC_KEYEN1                   _NVFSEC.Bits.KEYEN1
#define NVFSEC_SEC                      _NVFSEC.MergedBits.grpSEC
#define NVFSEC_RNV_2                    _NVFSEC.MergedBits.grpRNV_2
#define NVFSEC_KEYEN                    _NVFSEC.MergedBits.grpKEYEN
#define NVFSEC_RNV                      NVFSEC_RNV_2

#define NVFSEC_SEC0_MASK                1U
#define NVFSEC_SEC1_MASK                2U
#define NVFSEC_RNV2_MASK                4U
#define NVFSEC_RNV3_MASK                8U
#define NVFSEC_RNV4_MASK                16U
#define NVFSEC_RNV5_MASK                32U
#define NVFSEC_KEYEN0_MASK              64U
#define NVFSEC_KEYEN1_MASK              128U
#define NVFSEC_SEC_MASK                 3U
#define NVFSEC_SEC_BITNUM               0U
#define NVFSEC_RNV_2_MASK               60U
#define NVFSEC_RNV_2_BITNUM             2U
#define NVFSEC_KEYEN_MASK               192U
#define NVFSEC_KEYEN_BITNUM             6U


/* * * * *  24-BIT ADDRESS REGISTERS  * * * * * * * * * * * * * * * * * * * * * * */
extern volatile void* volatile MMCPC @0x00000085;          /* Captured S12ZCPU Program Counter Low; 0x00000087 */
extern volatile void* volatile DBGAA @0x00000115;          /* Debug Comparator A Address Register Low; 0x00000117 */
extern volatile void* volatile DBGBA @0x00000125;          /* Debug Comparator B Address Register Low; 0x00000127 */
extern volatile void* volatile DBGCA @0x00000135;          /* Debug Comparator C Address Register Low; 0x00000137 */
extern volatile void* volatile DBGDA @0x00000145;          /* Debug Comparator D Address Register Low; 0x00000147 */
extern volatile void* volatile ECCDPTR @0x000003C7;        /* ECC Debug Point Register Low; 0x000003C9 */
extern volatile void* volatile PTUPTR @0x00000591;         /* PTU Pointer Register; 0x00000593 */
extern volatile void* volatile ADC0CBP @0x0000061D;        /* ADC0 Command Base Pointer Register 0; 0x00000593 */
extern volatile void* volatile ADC0RBP @0x00000621;        /* ADC0 Result Base Pointer Register 0; 0x00000593 */
extern volatile void* volatile ADC1CBP @0x0000065D;        /* ADC1 Command Base Pointer Register 0; 0x00000593 */
extern volatile void* volatile ADC1RBP @0x00000661;        /* ADC1 Result Base Pointer Register 0; 0x00000593 */


  /* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() (CPMUARMCOP = 0x55U, CPMUARMCOP = 0xAAU)
#endif
#endif /* __RESET_WATCHDOG */


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 1/12/2012 2:56:04 PM */

#define ECCADDRH                         This_symb_has_been_depreciated
#define ECCADDRH_ECCADDR                 This_symb_has_been_depreciated
#define ECCADDRH_ECCADDR_MASK            This_symb_has_been_depreciated
#define ECCADDRH_ECCADDR_BITNUM          This_symb_has_been_depreciated
#define ECCADDRM                         This_symb_has_been_depreciated
#define ECCADDRM_ECCADDR                 This_symb_has_been_depreciated
#define ECCADDRM_ECCADDR_MASK            This_symb_has_been_depreciated
#define ECCADDRM_ECCADDR_BITNUM          This_symb_has_been_depreciated
#define ECCADDRL                         This_symb_has_been_depreciated
#define ECCADDRL_ECCADDR                 This_symb_has_been_depreciated
#define ECCADDRL_ECCADDR_MASK            This_symb_has_been_depreciated
#define ECCADDRL_ECCADDR_BITNUM          This_symb_has_been_depreciated
#define DBGAD                            DBGAD0
#define DBGADM                           DBGADM0
#define DBGCD                            DBGCD0
#define DBGCDM                           DBGCDM0
#define MODRR0_S0LRR                     MODRR0_S0L0RR
#define MODRR0_SPIRR                     MODRR0_SPI0RR
#define MODRR0_SPISSRR                   MODRR0_SPI0SSRR
#define MODRR0_S0LRR_MASK                MODRR0_S0L0RR_MASK
#define MODRR0_S0LRR_BITNUM              MODRR0_S0L0RR_BITNUM
#define MODRR0_SPIRR_MASK                MODRR0_SPI0RR_MASK
#define MODRR0_SPISSRR_MASK              MODRR0_SPI0SSRR_MASK
#define MODRR2_IC1RR                     MODRR2_T0IC1RR
#define MODRR2_IC3RR                     MODRR2_T0IC3RR
#define MODRR2_IC1RR_MASK                MODRR2_T0IC1RR_MASK
#define MODRR2_IC3RR_MASK                MODRR2_T0IC3RR_MASK
#define MODRR2_IC3RR_BITNUM              MODRR2_T0IC3RR_BITNUM
#define PMFCFG3_VLMODE0                  This_symb_has_been_depreciated
#define PMFCFG3_VLMODE1                  This_symb_has_been_depreciated
#define PMFCFG3_VLMODE0_MASK             This_symb_has_been_depreciated
#define PMFCFG3_VLMODE1_MASK             This_symb_has_been_depreciated
#define PMFCCTL_ISENS0                   This_symb_has_been_depreciated
#define PMFCCTL_ISENS1                   This_symb_has_been_depreciated
#define PMFCCTL_ISENS0_MASK              This_symb_has_been_depreciated
#define PMFCCTL_ISENS1_MASK              This_symb_has_been_depreciated
#define CPMURFLG_ILAF                    This_symb_has_been_depreciated
#define CPMURFLG_ILAF_MASK               This_symb_has_been_depreciated
#define _NVFPSTAT                        _PROTKEY
#define NVFPSTAT                         PROTKEY
#define NVFPSTAT_FPOVRD                  This_symb_has_been_depreciated
#define NVFPSTAT_FPOVRD_MASK             This_symb_has_been_depreciated

/* **** 9/05/2012 10:09:14 AM */
#define INT_XGPRIO                       This_symb_has_been_depreciated
#define INT_XGPRIO_XILVL                 This_symb_has_been_depreciated
#define INT_XGPRIO_XILVL_MASK            This_symb_has_been_depreciated
#define INT_XGPRIO_XILVL_BITNUM          This_symb_has_been_depreciated
#define INT_CFDATA0_RQST                 This_symb_has_been_depreciated
#define INT_CFDATA1_RQST                 This_symb_has_been_depreciated
#define INT_CFDATA2_RQST                 This_symb_has_been_depreciated
#define INT_CFDATA3_RQST                 This_symb_has_been_depreciated
#define INT_CFDATA4_RQST                 This_symb_has_been_depreciated
#define INT_CFDATA5_RQST                 This_symb_has_been_depreciated
#define INT_CFDATA6_RQST                 This_symb_has_been_depreciated
#define INT_CFDATA7_RQST                 This_symb_has_been_depreciated
#define INT_CFDATA0_RQST_MASK            This_symb_has_been_depreciated
#define INT_CFDATA1_RQST_MASK            This_symb_has_been_depreciated
#define INT_CFDATA2_RQST_MASK            This_symb_has_been_depreciated
#define INT_CFDATA3_RQST_MASK            This_symb_has_been_depreciated
#define INT_CFDATA4_RQST_MASK            This_symb_has_been_depreciated
#define INT_CFDATA5_RQST_MASK            This_symb_has_been_depreciated
#define INT_CFDATA6_RQST_MASK            This_symb_has_been_depreciated
#define INT_CFDATA7_RQST_MASK            This_symb_has_been_depreciated
#define FERCNFG_DFDIE                    This_symb_has_been_depreciated
#define FERCNFG_DFDIE_MASK               This_symb_has_been_depreciated
#define FERSTAT_DFDIF                    This_symb_has_been_depreciated
#define FERSTAT_DFDIF_MASK               This_symb_has_been_depreciated
#define GDUE_GCS0E                       This_symb_has_been_depreciated
#define GDUE_GCS1E                       This_symb_has_been_depreciated
#define GDUE_GCS0E_MASK                  This_symb_has_been_depreciated
#define GDUE_GCS1E_MASK                  This_symb_has_been_depreciated
#define GDUIE_GLVLSFIE                   This_symb_has_been_depreciated
#define GDUIE_GHHDFIE                    This_symb_has_been_depreciated
#define GDUIE_GLVLSFIE_MASK              This_symb_has_been_depreciated
#define GDUIE_GHHDFIE_MASK               This_symb_has_been_depreciated
#define GDUPHS                           This_symb_has_been_depreciated
#define GDUPHS_MASK                      This_symb_has_been_depreciated
#define GDUPHS_BITNUM                    This_symb_has_been_depreciated
#define GDUPHS_GPHS0                     This_symb_has_been_depreciated
#define GDUPHS_GPHS1                     This_symb_has_been_depreciated
#define GDUPHS_GPHS2                     This_symb_has_been_depreciated
#define GDUPHS_GPHS0_MASK                This_symb_has_been_depreciated
#define GDUPHS_GPHS1_MASK                This_symb_has_been_depreciated
#define GDUPHS_GPHS2_MASK                This_symb_has_been_depreciated
#define GDUCSO_GCS0O                     This_symb_has_been_depreciated
#define GDUCSO_GCS1O                     This_symb_has_been_depreciated
#define GDUCSO_GCS0O_MASK                This_symb_has_been_depreciated
#define GDUCSO_GCS1O_MASK                This_symb_has_been_depreciated
#define GDUCSO_GCS0O_BITNUM              This_symb_has_been_depreciated
#define GDUCSO_GCS1O_BITNUM              This_symb_has_been_depreciated
#define PTUE_PTUWP                       This_symb_has_been_depreciated
#define PTUE_PTUWP_MASK                  This_symb_has_been_depreciated

/* **** 1/25/2012 3:28:13 PM */

#define DBGAD0_BIT0                      DBGAD0_BIT24
#define DBGAD0_BIT1                      DBGAD0_BIT25
#define DBGAD0_BIT2                      DBGAD0_BIT26
#define DBGAD0_BIT3                      DBGAD0_BIT27
#define DBGAD0_BIT4                      DBGAD0_BIT28
#define DBGAD0_BIT5                      DBGAD0_BIT29
#define DBGAD0_BIT6                      DBGAD0_BIT30
#define DBGAD0_BIT7                      DBGAD0_BIT31
#define DBGAD0_BIT0_MASK                 DBGAD0_BIT24_MASK
#define DBGAD0_BIT1_MASK                 DBGAD0_BIT25_MASK
#define DBGAD0_BIT2_MASK                 DBGAD0_BIT26_MASK
#define DBGAD0_BIT3_MASK                 DBGAD0_BIT27_MASK
#define DBGAD0_BIT4_MASK                 DBGAD0_BIT28_MASK
#define DBGAD0_BIT5_MASK                 DBGAD0_BIT29_MASK
#define DBGAD0_BIT6_MASK                 DBGAD0_BIT30_MASK
#define DBGAD0_BIT7_MASK                 DBGAD0_BIT31_MASK
#define DBGAD1_BIT8                      DBGAD1_BIT16
#define DBGAD1_BIT9                      DBGAD1_BIT17
#define DBGAD1_BIT10                     DBGAD1_BIT18
#define DBGAD1_BIT11                     DBGAD1_BIT19
#define DBGAD1_BIT12                     DBGAD1_BIT20
#define DBGAD1_BIT13                     DBGAD1_BIT21
#define DBGAD1_BIT14                     DBGAD1_BIT22
#define DBGAD1_BIT15                     DBGAD1_BIT23
#define DBGAD1_BIT8_MASK                 DBGAD1_BIT16_MASK
#define DBGAD1_BIT9_MASK                 DBGAD1_BIT17_MASK
#define DBGAD1_BIT10_MASK                DBGAD1_BIT18_MASK
#define DBGAD1_BIT11_MASK                DBGAD1_BIT19_MASK
#define DBGAD1_BIT12_MASK                DBGAD1_BIT20_MASK
#define DBGAD1_BIT13_MASK                DBGAD1_BIT21_MASK
#define DBGAD1_BIT14_MASK                DBGAD1_BIT22_MASK
#define DBGAD1_BIT15_MASK                DBGAD1_BIT23_MASK
#define DBGAD2_BIT16                     DBGAD2_BIT8
#define DBGAD2_BIT17                     DBGAD2_BIT9
#define DBGAD2_BIT18                     DBGAD2_BIT10
#define DBGAD2_BIT19                     DBGAD2_BIT11
#define DBGAD2_BIT20                     DBGAD2_BIT12
#define DBGAD2_BIT21                     DBGAD2_BIT13
#define DBGAD2_BIT22                     DBGAD2_BIT14
#define DBGAD2_BIT23                     DBGAD2_BIT15
#define DBGAD2_BIT16_MASK                DBGAD2_BIT8_MASK
#define DBGAD2_BIT17_MASK                DBGAD2_BIT9_MASK
#define DBGAD2_BIT18_MASK                DBGAD2_BIT10_MASK
#define DBGAD2_BIT19_MASK                DBGAD2_BIT11_MASK
#define DBGAD2_BIT20_MASK                DBGAD2_BIT12_MASK
#define DBGAD2_BIT21_MASK                DBGAD2_BIT13_MASK
#define DBGAD2_BIT22_MASK                DBGAD2_BIT14_MASK
#define DBGAD2_BIT23_MASK                DBGAD2_BIT15_MASK
#define DBGAD3_BIT24                     DBGAD3_BIT0
#define DBGAD3_BIT25                     DBGAD3_BIT1
#define DBGAD3_BIT26                     DBGAD3_BIT2
#define DBGAD3_BIT27                     DBGAD3_BIT3
#define DBGAD3_BIT28                     DBGAD3_BIT4
#define DBGAD3_BIT29                     DBGAD3_BIT5
#define DBGAD3_BIT30                     DBGAD3_BIT6
#define DBGAD3_BIT31                     DBGAD3_BIT7
#define DBGAD3_BIT24_MASK                DBGAD3_BIT0_MASK
#define DBGAD3_BIT25_MASK                DBGAD3_BIT1_MASK
#define DBGAD3_BIT26_MASK                DBGAD3_BIT2_MASK
#define DBGAD3_BIT27_MASK                DBGAD3_BIT3_MASK
#define DBGAD3_BIT28_MASK                DBGAD3_BIT4_MASK
#define DBGAD3_BIT29_MASK                DBGAD3_BIT5_MASK
#define DBGAD3_BIT30_MASK                DBGAD3_BIT6_MASK
#define DBGAD3_BIT31_MASK                DBGAD3_BIT7_MASK
#define DBGADM0_BIT0                     DBGADM0_BIT24
#define DBGADM0_BIT1                     DBGADM0_BIT25
#define DBGADM0_BIT2                     DBGADM0_BIT26
#define DBGADM0_BIT3                     DBGADM0_BIT27
#define DBGADM0_BIT4                     DBGADM0_BIT28
#define DBGADM0_BIT5                     DBGADM0_BIT29
#define DBGADM0_BIT6                     DBGADM0_BIT30
#define DBGADM0_BIT7                     DBGADM0_BIT31
#define DBGADM0_BIT0_MASK                DBGADM0_BIT24_MASK
#define DBGADM0_BIT1_MASK                DBGADM0_BIT25_MASK
#define DBGADM0_BIT2_MASK                DBGADM0_BIT26_MASK
#define DBGADM0_BIT3_MASK                DBGADM0_BIT27_MASK
#define DBGADM0_BIT4_MASK                DBGADM0_BIT28_MASK
#define DBGADM0_BIT5_MASK                DBGADM0_BIT29_MASK
#define DBGADM0_BIT6_MASK                DBGADM0_BIT30_MASK
#define DBGADM0_BIT7_MASK                DBGADM0_BIT31_MASK
#define DBGADM1_BIT8                     DBGADM1_BIT16
#define DBGADM1_BIT9                     DBGADM1_BIT17
#define DBGADM1_BIT10                    DBGADM1_BIT18
#define DBGADM1_BIT11                    DBGADM1_BIT19
#define DBGADM1_BIT12                    DBGADM1_BIT20
#define DBGADM1_BIT13                    DBGADM1_BIT21
#define DBGADM1_BIT14                    DBGADM1_BIT22
#define DBGADM1_BIT15                    DBGADM1_BIT23
#define DBGADM1_BIT8_MASK                DBGADM1_BIT16_MASK
#define DBGADM1_BIT9_MASK                DBGADM1_BIT17_MASK
#define DBGADM1_BIT10_MASK               DBGADM1_BIT18_MASK
#define DBGADM1_BIT11_MASK               DBGADM1_BIT19_MASK
#define DBGADM1_BIT12_MASK               DBGADM1_BIT20_MASK
#define DBGADM1_BIT13_MASK               DBGADM1_BIT21_MASK
#define DBGADM1_BIT14_MASK               DBGADM1_BIT22_MASK
#define DBGADM1_BIT15_MASK               DBGADM1_BIT23_MASK
#define DBGADM2_BIT16                    DBGADM2_BIT8
#define DBGADM2_BIT17                    DBGADM2_BIT9
#define DBGADM2_BIT18                    DBGADM2_BIT10
#define DBGADM2_BIT19                    DBGADM2_BIT11
#define DBGADM2_BIT20                    DBGADM2_BIT12
#define DBGADM2_BIT21                    DBGADM2_BIT13
#define DBGADM2_BIT22                    DBGADM2_BIT14
#define DBGADM2_BIT23                    DBGADM2_BIT15
#define DBGADM2_BIT16_MASK               DBGADM2_BIT8_MASK
#define DBGADM2_BIT17_MASK               DBGADM2_BIT9_MASK
#define DBGADM2_BIT18_MASK               DBGADM2_BIT10_MASK
#define DBGADM2_BIT19_MASK               DBGADM2_BIT11_MASK
#define DBGADM2_BIT20_MASK               DBGADM2_BIT12_MASK
#define DBGADM2_BIT21_MASK               DBGADM2_BIT13_MASK
#define DBGADM2_BIT22_MASK               DBGADM2_BIT14_MASK
#define DBGADM2_BIT23_MASK               DBGADM2_BIT15_MASK
#define DBGADM3_BIT24                    DBGADM3_BIT0
#define DBGADM3_BIT25                    DBGADM3_BIT1
#define DBGADM3_BIT26                    DBGADM3_BIT2
#define DBGADM3_BIT27                    DBGADM3_BIT3
#define DBGADM3_BIT28                    DBGADM3_BIT4
#define DBGADM3_BIT29                    DBGADM3_BIT5
#define DBGADM3_BIT30                    DBGADM3_BIT6
#define DBGADM3_BIT31                    DBGADM3_BIT7
#define DBGADM3_BIT24_MASK               DBGADM3_BIT0_MASK
#define DBGADM3_BIT25_MASK               DBGADM3_BIT1_MASK
#define DBGADM3_BIT26_MASK               DBGADM3_BIT2_MASK
#define DBGADM3_BIT27_MASK               DBGADM3_BIT3_MASK
#define DBGADM3_BIT28_MASK               DBGADM3_BIT4_MASK
#define DBGADM3_BIT29_MASK               DBGADM3_BIT5_MASK
#define DBGADM3_BIT30_MASK               DBGADM3_BIT6_MASK
#define DBGADM3_BIT31_MASK               DBGADM3_BIT7_MASK
#define DBGCD0_BIT0                      DBGCD0_BIT24
#define DBGCD0_BIT1                      DBGCD0_BIT25
#define DBGCD0_BIT2                      DBGCD0_BIT26
#define DBGCD0_BIT3                      DBGCD0_BIT27
#define DBGCD0_BIT4                      DBGCD0_BIT28
#define DBGCD0_BIT5                      DBGCD0_BIT29
#define DBGCD0_BIT6                      DBGCD0_BIT30
#define DBGCD0_BIT7                      DBGCD0_BIT31
#define DBGCD0_BIT0_MASK                 DBGCD0_BIT24_MASK
#define DBGCD0_BIT1_MASK                 DBGCD0_BIT25_MASK
#define DBGCD0_BIT2_MASK                 DBGCD0_BIT26_MASK
#define DBGCD0_BIT3_MASK                 DBGCD0_BIT27_MASK
#define DBGCD0_BIT4_MASK                 DBGCD0_BIT28_MASK
#define DBGCD0_BIT5_MASK                 DBGCD0_BIT29_MASK
#define DBGCD0_BIT6_MASK                 DBGCD0_BIT30_MASK
#define DBGCD0_BIT7_MASK                 DBGCD0_BIT31_MASK
#define DBGCD1_BIT8                      DBGCD1_BIT16
#define DBGCD1_BIT9                      DBGCD1_BIT17
#define DBGCD1_BIT10                     DBGCD1_BIT18
#define DBGCD1_BIT11                     DBGCD1_BIT19
#define DBGCD1_BIT12                     DBGCD1_BIT20
#define DBGCD1_BIT13                     DBGCD1_BIT21
#define DBGCD1_BIT14                     DBGCD1_BIT22
#define DBGCD1_BIT15                     DBGCD1_BIT23
#define DBGCD1_BIT8_MASK                 DBGCD1_BIT16_MASK
#define DBGCD1_BIT9_MASK                 DBGCD1_BIT17_MASK
#define DBGCD1_BIT10_MASK                DBGCD1_BIT18_MASK
#define DBGCD1_BIT11_MASK                DBGCD1_BIT19_MASK
#define DBGCD1_BIT12_MASK                DBGCD1_BIT20_MASK
#define DBGCD1_BIT13_MASK                DBGCD1_BIT21_MASK
#define DBGCD1_BIT14_MASK                DBGCD1_BIT22_MASK
#define DBGCD1_BIT15_MASK                DBGCD1_BIT23_MASK
#define DBGCD2_BIT16                     DBGCD2_BIT8
#define DBGCD2_BIT17                     DBGCD2_BIT9
#define DBGCD2_BIT18                     DBGCD2_BIT10
#define DBGCD2_BIT19                     DBGCD2_BIT11
#define DBGCD2_BIT20                     DBGCD2_BIT12
#define DBGCD2_BIT21                     DBGCD2_BIT13
#define DBGCD2_BIT22                     DBGCD2_BIT14
#define DBGCD2_BIT23                     DBGCD2_BIT15
#define DBGCD2_BIT16_MASK                DBGCD2_BIT8_MASK
#define DBGCD2_BIT17_MASK                DBGCD2_BIT9_MASK
#define DBGCD2_BIT18_MASK                DBGCD2_BIT10_MASK
#define DBGCD2_BIT19_MASK                DBGCD2_BIT11_MASK
#define DBGCD2_BIT20_MASK                DBGCD2_BIT12_MASK
#define DBGCD2_BIT21_MASK                DBGCD2_BIT13_MASK
#define DBGCD2_BIT22_MASK                DBGCD2_BIT14_MASK
#define DBGCD2_BIT23_MASK                DBGCD2_BIT15_MASK
#define DBGCD3_BIT24                     DBGCD3_BIT0
#define DBGCD3_BIT25                     DBGCD3_BIT1
#define DBGCD3_BIT26                     DBGCD3_BIT2
#define DBGCD3_BIT27                     DBGCD3_BIT3
#define DBGCD3_BIT28                     DBGCD3_BIT4
#define DBGCD3_BIT29                     DBGCD3_BIT5
#define DBGCD3_BIT30                     DBGCD3_BIT6
#define DBGCD3_BIT31                     DBGCD3_BIT7
#define DBGCD3_BIT24_MASK                DBGCD3_BIT0_MASK
#define DBGCD3_BIT25_MASK                DBGCD3_BIT1_MASK
#define DBGCD3_BIT26_MASK                DBGCD3_BIT2_MASK
#define DBGCD3_BIT27_MASK                DBGCD3_BIT3_MASK
#define DBGCD3_BIT28_MASK                DBGCD3_BIT4_MASK
#define DBGCD3_BIT29_MASK                DBGCD3_BIT5_MASK
#define DBGCD3_BIT30_MASK                DBGCD3_BIT6_MASK
#define DBGCD3_BIT31_MASK                DBGCD3_BIT7_MASK
#define DBGCDM0_BIT0                     DBGCDM0_BIT24
#define DBGCDM0_BIT1                     DBGCDM0_BIT25
#define DBGCDM0_BIT2                     DBGCDM0_BIT26
#define DBGCDM0_BIT3                     DBGCDM0_BIT27
#define DBGCDM0_BIT4                     DBGCDM0_BIT28
#define DBGCDM0_BIT5                     DBGCDM0_BIT29
#define DBGCDM0_BIT6                     DBGCDM0_BIT30
#define DBGCDM0_BIT7                     DBGCDM0_BIT31
#define DBGCDM0_BIT0_MASK                DBGCDM0_BIT24_MASK
#define DBGCDM0_BIT1_MASK                DBGCDM0_BIT25_MASK
#define DBGCDM0_BIT2_MASK                DBGCDM0_BIT26_MASK
#define DBGCDM0_BIT3_MASK                DBGCDM0_BIT27_MASK
#define DBGCDM0_BIT4_MASK                DBGCDM0_BIT28_MASK
#define DBGCDM0_BIT5_MASK                DBGCDM0_BIT29_MASK
#define DBGCDM0_BIT6_MASK                DBGCDM0_BIT30_MASK
#define DBGCDM0_BIT7_MASK                DBGCDM0_BIT31_MASK
#define DBGCDM1_BIT8                     DBGCDM1_BIT16
#define DBGCDM1_BIT9                     DBGCDM1_BIT17
#define DBGCDM1_BIT10                    DBGCDM1_BIT18
#define DBGCDM1_BIT11                    DBGCDM1_BIT19
#define DBGCDM1_BIT12                    DBGCDM1_BIT20
#define DBGCDM1_BIT13                    DBGCDM1_BIT21
#define DBGCDM1_BIT14                    DBGCDM1_BIT22
#define DBGCDM1_BIT15                    DBGCDM1_BIT23
#define DBGCDM1_BIT8_MASK                DBGCDM1_BIT16_MASK
#define DBGCDM1_BIT9_MASK                DBGCDM1_BIT17_MASK
#define DBGCDM1_BIT10_MASK               DBGCDM1_BIT18_MASK
#define DBGCDM1_BIT11_MASK               DBGCDM1_BIT19_MASK
#define DBGCDM1_BIT12_MASK               DBGCDM1_BIT20_MASK
#define DBGCDM1_BIT13_MASK               DBGCDM1_BIT21_MASK
#define DBGCDM1_BIT14_MASK               DBGCDM1_BIT22_MASK
#define DBGCDM1_BIT15_MASK               DBGCDM1_BIT23_MASK
#define DBGCDM2_BIT16                    DBGCDM2_BIT8
#define DBGCDM2_BIT17                    DBGCDM2_BIT9
#define DBGCDM2_BIT18                    DBGCDM2_BIT10
#define DBGCDM2_BIT19                    DBGCDM2_BIT11
#define DBGCDM2_BIT20                    DBGCDM2_BIT12
#define DBGCDM2_BIT21                    DBGCDM2_BIT13
#define DBGCDM2_BIT22                    DBGCDM2_BIT14
#define DBGCDM2_BIT23                    DBGCDM2_BIT15
#define DBGCDM2_BIT16_MASK               DBGCDM2_BIT8_MASK
#define DBGCDM2_BIT17_MASK               DBGCDM2_BIT9_MASK
#define DBGCDM2_BIT18_MASK               DBGCDM2_BIT10_MASK
#define DBGCDM2_BIT19_MASK               DBGCDM2_BIT11_MASK
#define DBGCDM2_BIT20_MASK               DBGCDM2_BIT12_MASK
#define DBGCDM2_BIT21_MASK               DBGCDM2_BIT13_MASK
#define DBGCDM2_BIT22_MASK               DBGCDM2_BIT14_MASK
#define DBGCDM2_BIT23_MASK               DBGCDM2_BIT15_MASK
#define DBGCDM3_BIT24                    DBGCDM3_BIT0
#define DBGCDM3_BIT25                    DBGCDM3_BIT1
#define DBGCDM3_BIT26                    DBGCDM3_BIT2
#define DBGCDM3_BIT27                    DBGCDM3_BIT3
#define DBGCDM3_BIT28                    DBGCDM3_BIT4
#define DBGCDM3_BIT29                    DBGCDM3_BIT5
#define DBGCDM3_BIT30                    DBGCDM3_BIT6
#define DBGCDM3_BIT31                    DBGCDM3_BIT7
#define DBGCDM3_BIT24_MASK               DBGCDM3_BIT0_MASK
#define DBGCDM3_BIT25_MASK               DBGCDM3_BIT1_MASK
#define DBGCDM3_BIT26_MASK               DBGCDM3_BIT2_MASK
#define DBGCDM3_BIT27_MASK               DBGCDM3_BIT3_MASK
#define DBGCDM3_BIT28_MASK               DBGCDM3_BIT4_MASK
#define DBGCDM3_BIT29_MASK               DBGCDM3_BIT5_MASK
#define DBGCDM3_BIT30_MASK               DBGCDM3_BIT6_MASK
#define DBGCDM3_BIT31_MASK               DBGCDM3_BIT7_MASK

/* **** 05/16/2013 5:53:17 PM  - updates for new silicon revision (V3.0) */

#define SCI0BDH_TNP0                     This_symb_has_been_depreciated
#define SCI0BDH_TNP1                     This_symb_has_been_depreciated
#define SCI0BDH_IREN                     This_symb_has_been_depreciated
#define SCI0BDH_SBR_8                    This_symb_has_been_depreciated
#define SCI0BDH_TNP                      This_symb_has_been_depreciated
#define SCI0BDH_SBR                      This_symb_has_been_depreciated
#define SCI0BDH_TNP0_MASK                This_symb_has_been_depreciated
#define SCI0BDH_TNP1_MASK                This_symb_has_been_depreciated
#define SCI0BDH_IREN_MASK                This_symb_has_been_depreciated
#define SCI0BDH_SBR_8_MASK               This_symb_has_been_depreciated
#define SCI0BDH_SBR_8_BITNUM             This_symb_has_been_depreciated
#define SCI0BDH_TNP_MASK                 This_symb_has_been_depreciated
#define SCI0BDH_TNP_BITNUM               This_symb_has_been_depreciated
#define SCI0BD_TNP0                      This_symb_has_been_depreciated
#define SCI0BD_TNP1                      This_symb_has_been_depreciated
#define SCI0BD_IREN                      This_symb_has_been_depreciated
#define SCI0BD_SBR                       This_symb_has_been_depreciated
#define SCI0BD_TNP                       This_symb_has_been_depreciated
#define SCI0BD_TNP0_MASK                 This_symb_has_been_depreciated
#define SCI0BD_TNP1_MASK                 This_symb_has_been_depreciated
#define SCI0BD_IREN_MASK                 This_symb_has_been_depreciated
#define SCI0BD_SBR_MASK                  This_symb_has_been_depreciated
#define SCI0BD_SBR_BITNUM                This_symb_has_been_depreciated
#define SCI0BD_TNP_MASK                  This_symb_has_been_depreciated
#define SCI0BD_TNP_BITNUM                This_symb_has_been_depreciated
#define SCI1BDH_TNP0                     This_symb_has_been_depreciated
#define SCI1BDH_TNP1                     This_symb_has_been_depreciated
#define SCI1BDH_IREN                     This_symb_has_been_depreciated
#define SCI1BDH_SBR_8                    This_symb_has_been_depreciated
#define SCI1BDH_TNP                      This_symb_has_been_depreciated
#define SCI1BDH_SBR                      This_symb_has_been_depreciated
#define SCI1BDH_TNP0_MASK                This_symb_has_been_depreciated
#define SCI1BDH_TNP1_MASK                This_symb_has_been_depreciated
#define SCI1BDH_IREN_MASK                This_symb_has_been_depreciated
#define SCI1BDH_SBR_8_MASK               This_symb_has_been_depreciated
#define SCI1BDH_SBR_8_BITNUM             This_symb_has_been_depreciated
#define SCI1BDH_TNP_MASK                 This_symb_has_been_depreciated
#define SCI1BDH_TNP_BITNUM               This_symb_has_been_depreciated
#define SCI1BD_TNP0                      This_symb_has_been_depreciated
#define SCI1BD_TNP1                      This_symb_has_been_depreciated
#define SCI1BD_IREN                      This_symb_has_been_depreciated
#define SCI1BD_SBR                       This_symb_has_been_depreciated
#define SCI1BD_TNP                       This_symb_has_been_depreciated
#define SCI1BD_TNP0_MASK                 This_symb_has_been_depreciated
#define SCI1BD_TNP1_MASK                 This_symb_has_been_depreciated
#define SCI1BD_IREN_MASK                 This_symb_has_been_depreciated
#define SCI1BD_SBR_MASK                  This_symb_has_been_depreciated
#define SCI1BD_SBR_BITNUM                This_symb_has_been_depreciated
#define SCI1BD_TNP_MASK                  This_symb_has_been_depreciated
#define SCI1BD_TNP_BITNUM                This_symb_has_been_depreciated
#define LP0SLR_LPSLRWD                   This_symb_has_been_depreciated
#define LP0SLR_LPSLRWD_MASK              This_symb_has_been_depreciated
#define LP0SLR                           LP0SLRM
#define LP0SLR_LPSLR                     LP0SLRM_LPSLR
#define LP0SLR_LPSLR_MASK                LP0SLRM_LPSLR_MASK
#define LP0SLR_LPSLR_BITNUM              LP0SLRM_LPSLR_BITNUM
#define LP0SR_LPOC                       This_symb_has_been_depreciated
#define LP0SR_LPOC_MASK                  This_symb_has_been_depreciated

/*lint -restore  +esym(960,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
#endif
