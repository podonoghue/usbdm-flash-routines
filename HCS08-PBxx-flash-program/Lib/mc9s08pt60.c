/* Based on CPU DB MC9S08PT60_64, version 3.00.006 (RegistersPrg V2.33) */
/* DataSheet : MC9S08PT60RM Rev. 3 Draft A, 12/2011 */

#include <mc9s08pt60.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PORT_PTADSTR _PORT_PTAD;                          /* Port A Data Register; 0x00000000 */
volatile PORT_PTBDSTR _PORT_PTBD;                          /* Port B Data Register; 0x00000001 */
volatile PORT_PTCDSTR _PORT_PTCD;                          /* Port C Data Register; 0x00000002 */
volatile PORT_PTDDSTR _PORT_PTDD;                          /* Port D Data Register; 0x00000003 */
volatile PORT_PTEDSTR _PORT_PTED;                          /* Port E Data Register; 0x00000004 */
volatile PORT_PTFDSTR _PORT_PTFD;                          /* Port F Data Register; 0x00000005 */
volatile PORT_PTGDSTR _PORT_PTGD;                          /* Port G Data Register; 0x00000006 */
volatile PORT_PTHDSTR _PORT_PTHD;                          /* Port H Data Register; 0x00000007 */
volatile TSI_CS0STR _TSI_CS0;                              /* TSI Control and Status Register 0; 0x00000008 */
volatile TSI_CS1STR _TSI_CS1;                              /* TSI Control and Status Register 1; 0x00000009 */
volatile TSI_CS2STR _TSI_CS2;                              /* TSI Control and Status Register 2; 0x0000000A */
volatile TSI_CS3STR _TSI_CS3;                              /* TSI Control and Status Register 3; 0x0000000B */
volatile TSI_PEN0STR _TSI_PEN0;                            /* TSI Pin Enable Register 0; 0x0000000C */
volatile TSI_PEN1STR _TSI_PEN1;                            /* TSI Pin Enable Register 1; 0x0000000D */
volatile ADC_SC1STR _ADC_SC1;                              /* Status and Control Register 1; 0x00000010 */
volatile ADC_SC2STR _ADC_SC2;                              /* Status and Control Register 2; 0x00000011 */
volatile ADC_SC3STR _ADC_SC3;                              /* Status and Control Register 3; 0x00000012 */
volatile ADC_SC4STR _ADC_SC4;                              /* Status and Control Register 4; 0x00000013 */
volatile MTIM0_SCSTR _MTIM0_SC;                            /* MTIM Status and Control Register; 0x00000018 */
volatile MTIM0_CLKSTR _MTIM0_CLK;                          /* MTIM Clock Configuration Register; 0x00000019 */
volatile MTIM0_CNTSTR _MTIM0_CNT;                          /* MTIM Counter Register; 0x0000001A */
volatile MTIM0_MODSTR _MTIM0_MOD;                          /* MTIM Modulo Register; 0x0000001B */
volatile MTIM1_SCSTR _MTIM1_SC;                            /* MTIM Status and Control Register; 0x0000001C */
volatile MTIM1_CLKSTR _MTIM1_CLK;                          /* MTIM Clock Configuration Register; 0x0000001D */
volatile MTIM1_CNTSTR _MTIM1_CNT;                          /* MTIM Counter Register; 0x0000001E */
volatile MTIM1_MODSTR _MTIM1_MOD;                          /* MTIM Modulo Register; 0x0000001F */
volatile FTM0_SCSTR _FTM0_SC;                              /* Status and Control; 0x00000020 */
volatile FTM0_C0SCSTR _FTM0_C0SC;                          /* Channel Status and Control; 0x00000025 */
volatile FTM0_C1SCSTR _FTM0_C1SC;                          /* Channel Status and Control; 0x00000028 */
volatile ACMP_CSSTR _ACMP_CS;                              /* ACMP Control and Status Register; 0x0000002C */
volatile ACMP_C0STR _ACMP_C0;                              /* ACMP Control Register 0; 0x0000002D */
volatile ACMP_C1STR _ACMP_C1;                              /* ACMP Control Register 1; 0x0000002E */
volatile ACMP_C2STR _ACMP_C2;                              /* ACMP Control Register 2; 0x0000002F */
volatile FTM1_SCSTR _FTM1_SC;                              /* Status and Control; 0x00000030 */
volatile FTM1_C0SCSTR _FTM1_C0SC;                          /* Channel Status and Control; 0x00000035 */
volatile FTM1_C1SCSTR _FTM1_C1SC;                          /* Channel Status and Control; 0x00000038 */
volatile IRQ_SCSTR _IRQ_SC;                                /* Interrupt Pin Request Status and Control Register; 0x0000003B */
volatile KBI0_SCSTR _KBI0_SC;                              /* KBI Status and Control Register; 0x0000003C */
volatile KBI1_SCSTR _KBI1_SC;                              /* KBI Status and Control Register; 0x0000003D */
volatile IPC_SCSTR _IPC_SC;                                /* IPC Status and Control Register; 0x0000003E */
volatile IPC_IPMPSSTR _IPC_IPMPS;                          /* Interrupt Priority Mask Pseudo Stack Register; 0x0000003F */
volatile SYS_SRSSTR _SYS_SRS;                              /* System Reset Status Register; 0x00003000 */
volatile SYS_SBDFRSTR _SYS_SBDFR;                          /* System Background Debug Force Reset Register; 0x00003001 */
volatile SYS_SOPT1STR _SYS_SOPT1;                          /* System Options Register 1; 0x00003004 */
volatile SYS_SOPT2STR _SYS_SOPT2;                          /* System Options Register 2; 0x00003005 */
volatile SYS_SOPT3STR _SYS_SOPT3;                          /* System Options Register 3; 0x00003006 */
volatile SYS_SOPT4STR _SYS_SOPT4;                          /* System Options Register 4; 0x00003007 */
volatile SCG_C1STR _SCG_C1;                                /* System Clock Gating Control 1 Register; 0x0000300C */
volatile SCG_C2STR _SCG_C2;                                /* System Clock Gating Control 2 Register; 0x0000300D */
volatile SCG_C3STR _SCG_C3;                                /* System Clock Gating Control 3 Register; 0x0000300E */
volatile SCG_C4STR _SCG_C4;                                /* System Clock Gating Control 4 Register; 0x0000300F */
volatile DBG_CAHSTR _DBG_CAH;                              /* Debug Comparator A High Register; 0x00003010 */
volatile DBG_CALSTR _DBG_CAL;                              /* Debug Comparator A Low Register; 0x00003011 */
volatile DBG_CBHSTR _DBG_CBH;                              /* Debug Comparator B High Register; 0x00003012 */
volatile DBG_CBLSTR _DBG_CBL;                              /* Debug Comparator B Low Register; 0x00003013 */
volatile DBG_CCHSTR _DBG_CCH;                              /* Debug Comparator C High Register; 0x00003014 */
volatile DBG_CCLSTR _DBG_CCL;                              /* Debug Comparator C Low Register; 0x00003015 */
volatile DBG_FHSTR _DBG_FH;                                /* Debug FIFO High Register; 0x00003016 */
volatile DBG_FLSTR _DBG_FL;                                /* Debug FIFO Low Register; 0x00003017 */
volatile DBG_CAXSTR _DBG_CAX;                              /* Debug Comparator A Extension Register; 0x00003018 */
volatile DBG_CBXSTR _DBG_CBX;                              /* Debug Comparator B Extension Register; 0x00003019 */
volatile DBG_CCXSTR _DBG_CCX;                              /* Debug Comparator C Extension Register; 0x0000301A */
volatile DBG_FXSTR _DBG_FX;                                /* Debug FIFO Extended Information Register; 0x0000301B */
volatile DBG_CSTR _DBG_C;                                  /* Debug Control Register; 0x0000301C */
volatile DBG_TSTR _DBG_T;                                  /* Debug Trigger Register; 0x0000301D */
volatile DBG_SSTR _DBG_S;                                  /* Debug Status Register; 0x0000301E */
volatile DBG_CNTSTR _DBG_CNT;                              /* Debug Count Status Register; 0x0000301F */
volatile NVM_FCLKDIVSTR _NVM_FCLKDIV;                      /* Flash Clock Divider Register; 0x00003020 */
volatile NVM_FSECSTR _NVM_FSEC;                            /* Flash Security Register; 0x00003021 */
volatile NVM_FCCOBIXSTR _NVM_FCCOBIX;                      /* Flash CCOB Index Register; 0x00003022 */
volatile NVM_FCNFGSTR _NVM_FCNFG;                          /* Flash Configuration Register; 0x00003024 */
volatile NVM_FERCNFGSTR _NVM_FERCNFG;                      /* Flash Error Configuration Register; 0x00003025 */
volatile NVM_FSTATSTR _NVM_FSTAT;                          /* Flash Status Register; 0x00003026 */
volatile NVM_FERSTATSTR _NVM_FERSTAT;                      /* Flash Error Status Register; 0x00003027 */
volatile NVM_FPROTSTR _NVM_FPROT;                          /* Flash Protection Register; 0x00003028 */
volatile NVM_EEPROTSTR _NVM_EEPROT;                        /* EEPROM Protection Register; 0x00003029 */
volatile NVM_FOPTSTR _NVM_FOPT;                            /* Flash Option Register; 0x0000302C */
volatile WDOG_CS1STR _WDOG_CS1;                            /* Watchdog Control and Status Register 1; 0x00003030 */
volatile WDOG_CS2STR _WDOG_CS2;                            /* Watchdog Control and Status Register 2; 0x00003031 */
volatile ICS_C1STR _ICS_C1;                                /* ICS Control Register 1; 0x00003038 */
volatile ICS_C2STR _ICS_C2;                                /* ICS Control Register 2; 0x00003039 */
volatile ICS_C3STR _ICS_C3;                                /* ICS Control Register 3; 0x0000303A */
volatile ICS_C4STR _ICS_C4;                                /* ICS Control Register 4; 0x0000303B */
volatile ICS_SSTR _ICS_S;                                  /* ICS Status Register; 0x0000303C */
volatile ICS_OSCSCSTR _ICS_OSCSC;                          /* OSC Status and Control Register; 0x0000303E */
volatile PMC_SPMSC1STR _PMC_SPMSC1;                        /* System Power Management Status and Control 1 Register; 0x00003040 */
volatile PMC_SPMSC2STR _PMC_SPMSC2;                        /* System Power Management Status and Control 2 Register; 0x00003041 */
volatile SYS_ILLAHSTR _SYS_ILLAH;                          /* Illegal Address Register: High; 0x0000304A */
volatile SYS_ILLALSTR _SYS_ILLAL;                          /* Illegal Address Register: Low; 0x0000304B */
volatile IPC_ILRS0STR _IPC_ILRS0;                          /* Interrupt Level Setting Registers n; 0x00003050 */
volatile IPC_ILRS1STR _IPC_ILRS1;                          /* Interrupt Level Setting Registers n; 0x00003051 */
volatile IPC_ILRS2STR _IPC_ILRS2;                          /* Interrupt Level Setting Registers n; 0x00003052 */
volatile IPC_ILRS3STR _IPC_ILRS3;                          /* Interrupt Level Setting Registers n; 0x00003053 */
volatile IPC_ILRS4STR _IPC_ILRS4;                          /* Interrupt Level Setting Registers n; 0x00003054 */
volatile IPC_ILRS5STR _IPC_ILRS5;                          /* Interrupt Level Setting Registers n; 0x00003055 */
volatile IPC_ILRS6STR _IPC_ILRS6;                          /* Interrupt Level Setting Registers n; 0x00003056 */
volatile IPC_ILRS7STR _IPC_ILRS7;                          /* Interrupt Level Setting Registers n; 0x00003057 */
volatile IPC_ILRS8STR _IPC_ILRS8;                          /* Interrupt Level Setting Registers n; 0x00003058 */
volatile IPC_ILRS9STR _IPC_ILRS9;                          /* Interrupt Level Setting Registers n; 0x00003059 */
volatile CRC_CTRLSTR _CRC_CTRL;                            /* CRC Control Register; 0x00003068 */
volatile RTC_SC1STR _RTC_SC1;                              /* RTC Status and Control Register 1; 0x0000306A */
volatile RTC_SC2STR _RTC_SC2;                              /* RTC Status and Control Register 2; 0x0000306B */
volatile I2C_A1STR _I2C_A1;                                /* I2C Address Register 1; 0x00003070 */
volatile I2C_FSTR _I2C_F;                                  /* I2C Frequency Divider register; 0x00003071 */
volatile I2C_C1STR _I2C_C1;                                /* I2C Control Register 1; 0x00003072 */
volatile I2C_SSTR _I2C_S;                                  /* I2C Status Register; 0x00003073 */
volatile I2C_DSTR _I2C_D;                                  /* I2C Data I/O register; 0x00003074 */
volatile I2C_C2STR _I2C_C2;                                /* I2C Control Register 2; 0x00003075 */
volatile I2C_FLTSTR _I2C_FLT;                              /* I2C Programmable Input Glitch Filter register; 0x00003076 */
volatile I2C_RASTR _I2C_RA;                                /* I2C Range Address register; 0x00003077 */
volatile I2C_SMBSTR _I2C_SMB;                              /* I2C SMBus Control and Status register; 0x00003078 */
volatile I2C_A2STR _I2C_A2;                                /* I2C Address Register 2; 0x00003079 */
volatile KBI0_PESTR _KBI0_PE;                              /* KBIx Pin Enable Register; 0x0000307C */
volatile KBI0_ESSTR _KBI0_ES;                              /* KBIx Edge Select Register; 0x0000307D */
volatile KBI1_PESTR _KBI1_PE;                              /* KBIx Pin Enable Register; 0x0000307E */
volatile KBI1_ESSTR _KBI1_ES;                              /* KBIx Edge Select Register; 0x0000307F */
volatile SCI0_C1STR _SCI0_C1;                              /* SCI Control Register 1; 0x00003082 */
volatile SCI0_C2STR _SCI0_C2;                              /* SCI Control Register 2; 0x00003083 */
volatile SCI0_S1STR _SCI0_S1;                              /* SCI Status Register 1; 0x00003084 */
volatile SCI0_S2STR _SCI0_S2;                              /* SCI Status Register 2; 0x00003085 */
volatile SCI0_C3STR _SCI0_C3;                              /* SCI Control Register 3; 0x00003086 */
volatile SCI0_DSTR _SCI0_D;                                /* SCI Data Register; 0x00003087 */
volatile SCI1_C1STR _SCI1_C1;                              /* SCI Control Register 1; 0x0000308A */
volatile SCI1_C2STR _SCI1_C2;                              /* SCI Control Register 2; 0x0000308B */
volatile SCI1_S1STR _SCI1_S1;                              /* SCI Status Register 1; 0x0000308C */
volatile SCI1_S2STR _SCI1_S2;                              /* SCI Status Register 2; 0x0000308D */
volatile SCI1_C3STR _SCI1_C3;                              /* SCI Control Register 3; 0x0000308E */
volatile SCI1_DSTR _SCI1_D;                                /* SCI Data Register; 0x0000308F */
volatile SCI2_C1STR _SCI2_C1;                              /* SCI Control Register 1; 0x00003092 */
volatile SCI2_C2STR _SCI2_C2;                              /* SCI Control Register 2; 0x00003093 */
volatile SCI2_S1STR _SCI2_S1;                              /* SCI Status Register 1; 0x00003094 */
volatile SCI2_S2STR _SCI2_S2;                              /* SCI Status Register 2; 0x00003095 */
volatile SCI2_C3STR _SCI2_C3;                              /* SCI Control Register 3; 0x00003096 */
volatile SCI2_DSTR _SCI2_D;                                /* SCI Data Register; 0x00003097 */
volatile SPI0_C1STR _SPI0_C1;                              /* SPI control register 1; 0x00003098 */
volatile SPI0_C2STR _SPI0_C2;                              /* SPI control register 2; 0x00003099 */
volatile SPI0_BRSTR _SPI0_BR;                              /* SPI baud rate register; 0x0000309A */
volatile SPI0_SSTR _SPI0_S;                                /* SPI status register; 0x0000309B */
volatile SPI0_DSTR _SPI0_D;                                /* SPI data register low; 0x0000309D */
volatile SPI0_MSTR _SPI0_M;                                /* SPI match register low; 0x0000309F */
volatile SPI1_C1STR _SPI1_C1;                              /* SPI control register 1; 0x000030A0 */
volatile SPI1_C2STR _SPI1_C2;                              /* SPI control register 2; 0x000030A1 */
volatile SPI1_BRSTR _SPI1_BR;                              /* SPI baud rate register; 0x000030A2 */
volatile SPI1_SSTR _SPI1_S;                                /* SPI status register; 0x000030A3 */
volatile SPI1_C3STR _SPI1_C3;                              /* SPI control register 3; 0x000030A8 */
volatile SPI1_CISTR _SPI1_CI;                              /* SPI clear interrupt register; 0x000030A9 */
volatile ADC_APCTL1STR _ADC_APCTL1;                        /* Pin Control 1 Register; 0x000030AC */
volatile ADC_APCTL2STR _ADC_APCTL2;                        /* Pin Control 2 Register; 0x000030AD */
volatile PORT_HDRVESTR _PORT_HDRVE;                        /* Port High Drive Enable Register; 0x000030AF */
volatile PORT_PTAOESTR _PORT_PTAOE;                        /* Port A Output Enable Register; 0x000030B0 */
volatile PORT_PTBOESTR _PORT_PTBOE;                        /* Port B Output Enable Register; 0x000030B1 */
volatile PORT_PTCOESTR _PORT_PTCOE;                        /* Port C Output Enable Register; 0x000030B2 */
volatile PORT_PTDOESTR _PORT_PTDOE;                        /* Port D Output Enable Register; 0x000030B3 */
volatile PORT_PTEOESTR _PORT_PTEOE;                        /* Port E Output Enable Register; 0x000030B4 */
volatile PORT_PTFOESTR _PORT_PTFOE;                        /* Port F Output Enable Register; 0x000030B5 */
volatile PORT_PTGOESTR _PORT_PTGOE;                        /* Port G Output Enable Register; 0x000030B6 */
volatile PORT_PTHOESTR _PORT_PTHOE;                        /* Port H Output Enable Register; 0x000030B7 */
volatile PORT_PTAIESTR _PORT_PTAIE;                        /* Port A Input Enable Register; 0x000030B8 */
volatile PORT_PTBIESTR _PORT_PTBIE;                        /* Port B Input Enable Register; 0x000030B9 */
volatile PORT_PTCIESTR _PORT_PTCIE;                        /* Port C Input Enable Register; 0x000030BA */
volatile PORT_PTDIESTR _PORT_PTDIE;                        /* Port D Input Enable Register; 0x000030BB */
volatile PORT_PTEIESTR _PORT_PTEIE;                        /* Port E Input Enable Register; 0x000030BC */
volatile PORT_PTFIESTR _PORT_PTFIE;                        /* Port F Input Enable Register; 0x000030BD */
volatile PORT_PTGIESTR _PORT_PTGIE;                        /* Port G Input Enable Register; 0x000030BE */
volatile PORT_PTHIESTR _PORT_PTHIE;                        /* Port H Input Enable Register; 0x000030BF */
volatile FTM2_SCSTR _FTM2_SC;                              /* Status and Control; 0x000030C0 */
volatile FTM2_C0SCSTR _FTM2_C0SC;                          /* Channel Status and Control; 0x000030C5 */
volatile FTM2_C1SCSTR _FTM2_C1SC;                          /* Channel Status and Control; 0x000030C8 */
volatile FTM2_C2SCSTR _FTM2_C2SC;                          /* Channel Status and Control; 0x000030CB */
volatile FTM2_C3SCSTR _FTM2_C3SC;                          /* Channel Status and Control; 0x000030CE */
volatile FTM2_C4SCSTR _FTM2_C4SC;                          /* Channel Status and Control; 0x000030D1 */
volatile FTM2_C5SCSTR _FTM2_C5SC;                          /* Channel Status and Control; 0x000030D4 */
volatile FTM2_STATUSSTR _FTM2_STATUS;                      /* Capture and Compare Status; 0x000030D9 */
volatile FTM2_MODESTR _FTM2_MODE;                          /* Features Mode Selection; 0x000030DA */
volatile FTM2_SYNCSTR _FTM2_SYNC;                          /* Synchronization; 0x000030DB */
volatile FTM2_OUTINITSTR _FTM2_OUTINIT;                    /* Initial State for Channel Output; 0x000030DC */
volatile FTM2_OUTMASKSTR _FTM2_OUTMASK;                    /* Output Mask; 0x000030DD */
volatile FTM2_COMBINE0STR _FTM2_COMBINE0;                  /* Function for Linked Channels; 0x000030DE */
volatile FTM2_COMBINE1STR _FTM2_COMBINE1;                  /* Function for Linked Channels; 0x000030DF */
volatile FTM2_COMBINE2STR _FTM2_COMBINE2;                  /* Function for Linked Channels; 0x000030E0 */
volatile FTM2_DEADTIMESTR _FTM2_DEADTIME;                  /* Deadtime Insertion Control; 0x000030E2 */
volatile FTM2_EXTTRIGSTR _FTM2_EXTTRIG;                    /* External Trigger; 0x000030E3 */
volatile FTM2_POLSTR _FTM2_POL;                            /* Channels Polarity; 0x000030E4 */
volatile FTM2_FMSSTR _FTM2_FMS;                            /* Fault Mode Status; 0x000030E5 */
volatile FTM2_FILTER0STR _FTM2_FILTER0;                    /* Input Capture Filter Control; 0x000030E6 */
volatile FTM2_FILTER1STR _FTM2_FILTER1;                    /* Input Capture Filter Control; 0x000030E7 */
volatile FTM2_FLTFILTERSTR _FTM2_FLTFILTER;                /* Fault Input Filter Control; 0x000030E8 */
volatile FTM2_FLTCTRLSTR _FTM2_FLTCTRL;                    /* Fault Input Control; 0x000030E9 */
volatile PORT_IOFLT0STR _PORT_IOFLT0;                      /* Port Filter Register 0; 0x000030EC */
volatile PORT_IOFLT1STR _PORT_IOFLT1;                      /* Port Filter Register 1; 0x000030ED */
volatile PORT_IOFLT2STR _PORT_IOFLT2;                      /* Port Filter Register 2; 0x000030EE */
volatile PORT_FCLKDIVSTR _PORT_FCLKDIV;                    /* Port Clock Division Register; 0x000030EF */
volatile PORT_PTAPESTR _PORT_PTAPE;                        /* Port A Pullup Enable Register; 0x000030F0 */
volatile PORT_PTBPESTR _PORT_PTBPE;                        /* Port B Pullup Enable Register; 0x000030F1 */
volatile PORT_PTCPESTR _PORT_PTCPE;                        /* Port C Pullup Enable Register; 0x000030F2 */
volatile PORT_PTDPESTR _PORT_PTDPE;                        /* Port D Pullup Enable Register; 0x000030F3 */
volatile PORT_PTEPESTR _PORT_PTEPE;                        /* Port E Pullup Enable Register; 0x000030F4 */
volatile PORT_PTFPESTR _PORT_PTFPE;                        /* Port F Pullup Enable Register; 0x000030F5 */
volatile PORT_PTGPESTR _PORT_PTGPE;                        /* Port G Pullup Enable Register; 0x000030F6 */
volatile PORT_PTHPESTR _PORT_PTHPE;                        /* Port H Pullup Enable Register; 0x000030F7 */
volatile SYS_UUID1STR _SYS_UUID1;                          /* Universally Unique Identifier Register 1; 0x000030F8 */
volatile SYS_UUID2STR _SYS_UUID2;                          /* Universally Unique Identifier Register 2; 0x000030F9 */
volatile SYS_UUID3STR _SYS_UUID3;                          /* Universally Unique Identifier Register 3; 0x000030FA */
volatile SYS_UUID4STR _SYS_UUID4;                          /* Universally Unique Identifier Register 4; 0x000030FB */
volatile SYS_UUID5STR _SYS_UUID5;                          /* Universally Unique Identifier Register 5; 0x000030FC */
volatile SYS_UUID6STR _SYS_UUID6;                          /* Universally Unique Identifier Register 6; 0x000030FD */
volatile SYS_UUID7STR _SYS_UUID7;                          /* Universally Unique Identifier Register 7; 0x000030FE */
volatile SYS_UUID8STR _SYS_UUID8;                          /* Universally Unique Identifier Register 8; 0x000030FF */
/* NV_BACKKEY0 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF70 */
/* Tip for register initialization in the user code:  const byte NV_BACKKEY0_INIT @0x0000FF70 = <NV_BACKKEY0_INITVAL>; */
/* NV_BACKKEY1 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF71 */
/* Tip for register initialization in the user code:  const byte NV_BACKKEY1_INIT @0x0000FF71 = <NV_BACKKEY1_INITVAL>; */
/* NV_BACKKEY2 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF72 */
/* Tip for register initialization in the user code:  const byte NV_BACKKEY2_INIT @0x0000FF72 = <NV_BACKKEY2_INITVAL>; */
/* NV_BACKKEY3 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF73 */
/* Tip for register initialization in the user code:  const byte NV_BACKKEY3_INIT @0x0000FF73 = <NV_BACKKEY3_INITVAL>; */
/* NV_BACKKEY4 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF74 */
/* Tip for register initialization in the user code:  const byte NV_BACKKEY4_INIT @0x0000FF74 = <NV_BACKKEY4_INITVAL>; */
/* NV_BACKKEY5 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF75 */
/* Tip for register initialization in the user code:  const byte NV_BACKKEY5_INIT @0x0000FF75 = <NV_BACKKEY5_INITVAL>; */
/* NV_BACKKEY6 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF76 */
/* Tip for register initialization in the user code:  const byte NV_BACKKEY6_INIT @0x0000FF76 = <NV_BACKKEY6_INITVAL>; */
/* NV_BACKKEY7 - macro for reading non volatile register   Back Door Key Register n; 0x0000FF77 */
/* Tip for register initialization in the user code:  const byte NV_BACKKEY7_INIT @0x0000FF77 = <NV_BACKKEY7_INITVAL>; */
/* NV_FPROT - macro for reading non volatile register      Flash Protection Register; 0x0000FF7C */
/* Tip for register initialization in the user code:  const byte NV_FPROT_INIT @0x0000FF7C = <NV_FPROT_INITVAL>; */
/* NV_EEPROT - macro for reading non volatile register     EEPROM Protection Register; 0x0000FF7D */
/* Tip for register initialization in the user code:  const byte NV_EEPROT_INIT @0x0000FF7D = <NV_EEPROT_INITVAL>; */
/* NV_FOPT - macro for reading non volatile register       Flash Option Register; 0x0000FF7E */
/* Tip for register initialization in the user code:  const byte NV_FOPT_INIT @0x0000FF7E = <NV_FOPT_INITVAL>; */
/* NV_FSEC - macro for reading non volatile register       Flash Security Register; 0x0000FF7F */
/* Tip for register initialization in the user code:  const byte NV_FSEC_INIT @0x0000FF7F = <NV_FSEC_INITVAL>; */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile TSI_CNTSTR _TSI_CNT;                              /* TSI Counter Register; 0x0000000E */
volatile ADC_RSTR _ADC_R;                                  /* Data Result Register; 0x00000014 */
volatile ADC_CVSTR _ADC_CV;                                /* Compare Value Register; 0x00000016 */
volatile FTM0_CNTSTR _FTM0_CNT;                            /* FTM0 Timer Counter Register; 0x00000021 */
volatile FTM0_MODSTR _FTM0_MOD;                            /* FTM0 Timer Counter Modulo Register; 0x00000023 */
volatile FTM0_C0VSTR _FTM0_C0V;                            /* FTM0 Timer Channel 0 Value Register; 0x00000026 */
volatile FTM0_C1VSTR _FTM0_C1V;                            /* FTM0 Timer Channel 1 Value Register; 0x00000029 */
volatile FTM1_CNTSTR _FTM1_CNT;                            /* FTM1 Timer Counter Register; 0x00000031 */
volatile FTM1_MODSTR _FTM1_MOD;                            /* FTM1 Timer Counter Modulo Register; 0x00000033 */
volatile FTM1_C0VSTR _FTM1_C0V;                            /* FTM1 Timer Channel 0 Value Register; 0x00000036 */
volatile FTM1_C1VSTR _FTM1_C1V;                            /* FTM1 Timer Channel 1 Value Register; 0x00000039 */
volatile SYS_SDIDSTR _SYS_SDID;                            /* System Device Identification Register; 0x00003002 */
volatile NVM_FCCOBSTR _NVM_FCCOB;                          /* Flash Common Command Object Register; 0x0000302A */
volatile WDOG_CNTSTR _WDOG_CNT;                            /* Watchdog Counter Register; 0x00003032 */
volatile WDOG_TOVALSTR _WDOG_TOVAL;                        /* Watchdog Timer Register; 0x00003034 */
volatile WDOG_WINSTR _WDOG_WIN;                            /* Watchdog Window Register; 0x00003036 */
volatile CRC_D0D1STR _CRC_D0D1;                            /* CRC_D0D1 register; 0x00003060 */
volatile CRC_D2D3STR _CRC_D2D3;                            /* CRC_D2D3 register; 0x00003062 */
volatile CRC_P0P1STR _CRC_P0P1;                            /* CRC_P0P1 register; 0x00003064 */
volatile CRC_P2P3STR _CRC_P2P3;                            /* CRC_P2P3 register; 0x00003066 */
volatile RTC_MODSTR _RTC_MOD;                              /* RTC Modulo Register; 0x0000306C */
volatile RTC_CNTSTR _RTC_CNT;                              /* RTC Counter Register; 0x0000306E */
volatile I2C_SLTSTR _I2C_SLT;                              /* I2C SCL Low Timeout register; 0x0000307A */
volatile SCI0_BDSTR _SCI0_BD;                              /* SCI0 Baud Rate Register; 0x00003080 */
volatile SCI1_BDSTR _SCI1_BD;                              /* SCI1 Baud Rate Register; 0x00003088 */
volatile SCI2_BDSTR _SCI2_BD;                              /* SCI2 Baud Rate Register; 0x00003090 */
volatile SPI1_D16STR _SPI1_D16;                            /* SPI1 Data Register; 0x000030A4 */
volatile SPI1_MSTR _SPI1_M;                                /* SPI1 Match Register; 0x000030A6 */
volatile FTM2_CNTSTR _FTM2_CNT;                            /* FTM2 Timer Counter Register; 0x000030C1 */
volatile FTM2_MODSTR _FTM2_MOD;                            /* FTM2 Timer Counter Modulo Register; 0x000030C3 */
volatile FTM2_C0VSTR _FTM2_C0V;                            /* FTM2 Timer Channel 0 Value Register; 0x000030C6 */
volatile FTM2_C1VSTR _FTM2_C1V;                            /* FTM2 Timer Channel 1 Value Register; 0x000030C9 */
volatile FTM2_C2VSTR _FTM2_C2V;                            /* FTM2 Timer Channel 2 Value Register; 0x000030CC */
volatile FTM2_C3VSTR _FTM2_C3V;                            /* FTM2 Timer Channel 3 Value Register; 0x000030CF */
volatile FTM2_C4VSTR _FTM2_C4V;                            /* FTM2 Timer Channel 4 Value Register; 0x000030D2 */
volatile FTM2_C5VSTR _FTM2_C5V;                            /* FTM2 Timer Channel 5 Value Register; 0x000030D5 */
volatile FTM2_CNTINSTR _FTM2_CNTIN;                        /* FTM2 Counter Initial Value Registers; 0x000030D7 */

/*lint -restore */

/* EOF */
