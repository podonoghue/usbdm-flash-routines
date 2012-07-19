/* Based on CPU DB MCF51AC256A_80, version 3.00.059 (RegistersPrg V2.32) */
/* DataSheet : MCF51AC256RM Rev. 4, 5/2009 */

#include <mcf51ac256a.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
/* NVFTRIM - macro for reading non volatile register       Nonvolatile MCG Fine Trim; 0x000003FE */
/* Tip for register initialization in the user code:  const byte NVFTRIM_INIT @0x000003FE = <NVFTRIM_INITVAL>; */
/* NVMCGTRM - macro for reading non volatile register      Nonvolatile MCG Trim Register; 0x000003FF */
/* Tip for register initialization in the user code:  const byte NVMCGTRM_INIT @0x000003FF = <NVMCGTRM_INITVAL>; */
/* NVBACKKEY0 - macro for reading non volatile register    Backdoor Comparison Key 0; 0x00000400 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x00000400 = <NVBACKKEY0_INITVAL>; */
/* NVBACKKEY1 - macro for reading non volatile register    Backdoor Comparison Key 1; 0x00000401 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x00000401 = <NVBACKKEY1_INITVAL>; */
/* NVBACKKEY2 - macro for reading non volatile register    Backdoor Comparison Key 2; 0x00000402 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x00000402 = <NVBACKKEY2_INITVAL>; */
/* NVBACKKEY3 - macro for reading non volatile register    Backdoor Comparison Key 3; 0x00000403 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x00000403 = <NVBACKKEY3_INITVAL>; */
/* NVBACKKEY4 - macro for reading non volatile register    Backdoor Comparison Key 4; 0x00000404 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x00000404 = <NVBACKKEY4_INITVAL>; */
/* NVBACKKEY5 - macro for reading non volatile register    Backdoor Comparison Key 5; 0x00000405 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x00000405 = <NVBACKKEY5_INITVAL>; */
/* NVBACKKEY6 - macro for reading non volatile register    Backdoor Comparison Key 6; 0x00000406 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x00000406 = <NVBACKKEY6_INITVAL>; */
/* NVBACKKEY7 - macro for reading non volatile register    Backdoor Comparison Key 7; 0x00000407 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x00000407 = <NVBACKKEY7_INITVAL>; */
/* NVPROT - macro for reading non volatile register        Nonvolatile Flash Protection Register; 0x0000040D */
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000040D = <NVPROT_INITVAL>; */
/* NVOPT - macro for reading non volatile register         Nonvolatile Flash Options Register; 0x0000040F */
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000040F = <NVOPT_INITVAL>; */
volatile PTADSTR _PTAD;                                    /* Port A Data Register; 0xFFFF8000 */
volatile PTADDSTR _PTADD;                                  /* Port A Data Direction Register; 0xFFFF8001 */
volatile PTBDSTR _PTBD;                                    /* Port B Data Register; 0xFFFF8002 */
volatile PTBDDSTR _PTBDD;                                  /* Port B Data Direction Register; 0xFFFF8003 */
volatile PTCDSTR _PTCD;                                    /* Port C Data Register; 0xFFFF8004 */
volatile PTCDDSTR _PTCDD;                                  /* Port C Data Direction Register; 0xFFFF8005 */
volatile PTDDSTR _PTDD;                                    /* Port D Data Register; 0xFFFF8006 */
volatile PTDDDSTR _PTDDD;                                  /* Port D Data Direction Register; 0xFFFF8007 */
volatile PTEDSTR _PTED;                                    /* Port E Data Register; 0xFFFF8008 */
volatile PTEDDSTR _PTEDD;                                  /* Port E Data Direction Register; 0xFFFF8009 */
volatile PTFDSTR _PTFD;                                    /* Port F Data Register; 0xFFFF800A */
volatile PTFDDSTR _PTFDD;                                  /* Port F Data Direction Register; 0xFFFF800B */
volatile PTGDSTR _PTGD;                                    /* Port G Data Register; 0xFFFF800C */
volatile PTGDDSTR _PTGDD;                                  /* Port G Data Direction Register; 0xFFFF800D */
volatile PTHDSTR _PTHD;                                    /* Port H Data Register; 0xFFFF800E */
volatile PTHDDSTR _PTHDD;                                  /* Port H Data Direction Register; 0xFFFF800F */
volatile ADCSC1STR _ADCSC1;                                /* Status and Control Register 1; 0xFFFF8010 */
volatile ADCSC2STR _ADCSC2;                                /* Status and Control Register 2; 0xFFFF8011 */
volatile ADCCFGSTR _ADCCFG;                                /* Configuration Register; 0xFFFF8016 */
volatile APCTL1STR _APCTL1;                                /* Pin Control 1 Register; 0xFFFF8017 */
volatile APCTL2STR _APCTL2;                                /* Pin Control 2 Register; 0xFFFF8018 */
volatile APCTL3STR _APCTL3;                                /* Pin Control 3 Register; 0xFFFF8019 */
volatile PTJDSTR _PTJD;                                    /* Port J Data Register; 0xFFFF801A */
volatile PTJDDSTR _PTJDD;                                  /* Port J Data Direction Register; 0xFFFF801B */
volatile IRQSCSTR _IRQSC;                                  /* Interrupt request status and control register; 0xFFFF801C */
volatile KBISCSTR _KBISC;                                  /* KBI Status and Control Register; 0xFFFF801E */
volatile KBIPESTR _KBIPE;                                  /* KBI Pin Enable Register; 0xFFFF801F */
volatile SCI1C1STR _SCI1C1;                                /* SCI1 Control Register 1; 0xFFFF803A */
volatile SCI1C2STR _SCI1C2;                                /* SCI1 Control Register 2; 0xFFFF803B */
volatile SCI1S1STR _SCI1S1;                                /* SCI1 Status Register 1; 0xFFFF803C */
volatile SCI1S2STR _SCI1S2;                                /* SCI1 Status Register 2; 0xFFFF803D */
volatile SCI1C3STR _SCI1C3;                                /* SCI1 Control Register 3; 0xFFFF803E */
volatile SCI1DSTR _SCI1D;                                  /* SCI1 Data Register; 0xFFFF803F */
volatile SCI2C1STR _SCI2C1;                                /* SCI2 Control Register 1; 0xFFFF8042 */
volatile SCI2C2STR _SCI2C2;                                /* SCI2 Control Register 2; 0xFFFF8043 */
volatile SCI2S1STR _SCI2S1;                                /* SCI2 Status Register 1; 0xFFFF8044 */
volatile SCI2S2STR _SCI2S2;                                /* SCI2 Status Register 2; 0xFFFF8045 */
volatile SCI2C3STR _SCI2C3;                                /* SCI2 Control Register 3; 0xFFFF8046 */
volatile SCI2DSTR _SCI2D;                                  /* SCI2 Data Register; 0xFFFF8047 */
volatile MCGC1STR _MCGC1;                                  /* MCG Control Register 1; 0xFFFF8048 */
volatile MCGC2STR _MCGC2;                                  /* MCG Control Register 2; 0xFFFF8049 */
volatile MCGTRMSTR _MCGTRM;                                /* MCG Trim Register; 0xFFFF804A */
volatile MCGSCSTR _MCGSC;                                  /* MCG Status and Control Register; 0xFFFF804B */
volatile MCGC3STR _MCGC3;                                  /* MCG Control Register 3; 0xFFFF804C */
volatile MCGC4STR _MCGC4;                                  /* MCG Control Register 4; 0xFFFF804D */
volatile SPI1C1STR _SPI1C1;                                /* SPI1 Control Register 1; 0xFFFF8050 */
volatile SPI1C2STR _SPI1C2;                                /* SPI1 Control Register 2; 0xFFFF8051 */
volatile SPI1BRSTR _SPI1BR;                                /* SPI1 Baud Rate Register; 0xFFFF8052 */
volatile SPI1SSTR _SPI1S;                                  /* SPI1 Status Register; 0xFFFF8053 */
volatile SPI1DSTR _SPI1D;                                  /* SPI1 Data Register; 0xFFFF8055 */
volatile IICASTR _IICA;                                    /* IIC Address Register; 0xFFFF8058 */
volatile IICFSTR _IICF;                                    /* IIC Frequency Divider Register; 0xFFFF8059 */
volatile IICC1STR _IICC1;                                  /* IIC Control Register 1; 0xFFFF805A */
volatile IICSSTR _IICS;                                    /* IIC Status Register; 0xFFFF805B */
volatile IICDSTR _IICD;                                    /* IIC Data I/O Register; 0xFFFF805C */
volatile IICC2STR _IICC2;                                  /* IIC Control Register 2; 0xFFFF805D */
volatile ACMP1SCSTR _ACMP1SC;                              /* ACMP1 Status and Control Register; 0xFFFF805E */
volatile ACMP2SCSTR _ACMP2SC;                              /* ACMP2 Status and Control Register; 0xFFFF805F */
volatile FTM1SCSTR _FTM1SC;                                /* FTM1 Status and Control Register; 0xFFFF8080 */
volatile FTM1C0SCSTR _FTM1C0SC;                            /* FTM1 Timer Channel 0 Status and Control Register; 0xFFFF8085 */
volatile FTM1C1SCSTR _FTM1C1SC;                            /* FTM1 Timer Channel 1 Status and Control Register; 0xFFFF8088 */
volatile FTM1C2SCSTR _FTM1C2SC;                            /* FTM1 Timer Channel 2 Status and Control Register; 0xFFFF808B */
volatile FTM1C3SCSTR _FTM1C3SC;                            /* FTM1 Timer Channel 3 Status and Control Register; 0xFFFF808E */
volatile FTM1C4SCSTR _FTM1C4SC;                            /* FTM1 Timer Channel 4 Status and Control Register; 0xFFFF8091 */
volatile FTM1C5SCSTR _FTM1C5SC;                            /* FTM1 Timer Channel 5 Status and Control Register; 0xFFFF8094 */
volatile FTM1STATUSSTR _FTM1STATUS;                        /* FTM1 Capture and Compare Status Register; 0xFFFF809F */
volatile FTM1MODESTR _FTM1MODE;                            /* FTM1 Features Mode Selection Register; 0xFFFF80A0 */
volatile FTM1SYNCSTR _FTM1SYNC;                            /* FTM1 Synchronization Register; 0xFFFF80A1 */
volatile FTM1OUTINITSTR _FTM1OUTINIT;                      /* FTM1 Initial State for Channels Output Register; 0xFFFF80A2 */
volatile FTM1OUTMASKSTR _FTM1OUTMASK;                      /* FTM1 Output Mask Register; 0xFFFF80A3 */
volatile FTM1COMBINE0STR _FTM1COMBINE0;                    /* FTM1 Function For Linked Channel 0 Register; 0xFFFF80A4 */
volatile FTM1COMBINE1STR _FTM1COMBINE1;                    /* FTM1 Function For Linked Channel 1 Register; 0xFFFF80A5 */
volatile FTM1COMBINE2STR _FTM1COMBINE2;                    /* FTM1 Function For Linked Channel 2 Register; 0xFFFF80A6 */
volatile FTM1DEADTIMESTR _FTM1DEADTIME;                    /* FTM1 Deadtime Insertion Control Register; 0xFFFF80A8 */
volatile FTM1EXTTRIGSTR _FTM1EXTTRIG;                      /* FTM1 ExternalTrigger Register; 0xFFFF80A9 */
volatile FTM1POLSTR _FTM1POL;                              /* FTM1 Channels Polarity Register; 0xFFFF80AA */
volatile FTM1FMSSTR _FTM1FMS;                              /* FTM1 Fault Mode Status Register; 0xFFFF80AB */
volatile FTM1FILTER0STR _FTM1FILTER0;                      /* FTM1 Input Capture Filter Control Register 0; 0xFFFF80AC */
volatile FTM1FILTER1STR _FTM1FILTER1;                      /* FTM1 Input Capture Filter Control Register 1; 0xFFFF80AD */
volatile FTM1FLTFILTERSTR _FTM1FLTFILTER;                  /* FTM1 Fault Input Filter Control Register; 0xFFFF80AE */
volatile FTM1RFUSTR _FTM1RFU;                              /* FTM1 Register for Future Use; 0xFFFF80AF */
volatile FTM2SCSTR _FTM2SC;                                /* FTM2 Status and Control Register; 0xFFFF80C0 */
volatile FTM2C0SCSTR _FTM2C0SC;                            /* FTM2 Timer Channel 0 Status and Control Register; 0xFFFF80C5 */
volatile FTM2C1SCSTR _FTM2C1SC;                            /* FTM2 Timer Channel 1 Status and Control Register; 0xFFFF80C8 */
volatile FTM2C2SCSTR _FTM2C2SC;                            /* FTM2 Timer Channel 2 Status and Control Register; 0xFFFF80CB */
volatile FTM2C3SCSTR _FTM2C3SC;                            /* FTM2 Timer Channel 3 Status and Control Register; 0xFFFF80CE */
volatile FTM2C4SCSTR _FTM2C4SC;                            /* FTM2 Timer Channel 4 Status and Control Register; 0xFFFF80D1 */
volatile FTM2C5SCSTR _FTM2C5SC;                            /* FTM2 Timer Channel 5 Status and Control Register; 0xFFFF80D4 */
volatile FTM2STATUSSTR _FTM2STATUS;                        /* FTM2 Capture and Compare Status Register; 0xFFFF80DF */
volatile FTM2MODESTR _FTM2MODE;                            /* FTM2 Features Mode Selection Register; 0xFFFF80E0 */
volatile FTM2SYNCSTR _FTM2SYNC;                            /* FTM2 Synchronization Register; 0xFFFF80E1 */
volatile FTM2OUTINITSTR _FTM2OUTINIT;                      /* FTM2 Initial State for Channels Output Register; 0xFFFF80E2 */
volatile FTM2OUTMASKSTR _FTM2OUTMASK;                      /* FTM2 Output Mask Register; 0xFFFF80E3 */
volatile FTM2COMBINE0STR _FTM2COMBINE0;                    /* FTM2 Function For Linked Channel 0 Register; 0xFFFF80E4 */
volatile FTM2COMBINE1STR _FTM2COMBINE1;                    /* FTM2 Function For Linked Channel 1 Register; 0xFFFF80E5 */
volatile FTM2COMBINE2STR _FTM2COMBINE2;                    /* FTM2 Function For Linked Channel 2 Register; 0xFFFF80E6 */
volatile FTM2DEADTIMESTR _FTM2DEADTIME;                    /* FTM2 Deadtime Insertion Control Register; 0xFFFF80E8 */
volatile FTM2POLSTR _FTM2POL;                              /* FTM2 Channels Polarity Register; 0xFFFF80EA */
volatile FTM2FMSSTR _FTM2FMS;                              /* FTM2 Fault Mode Status Register; 0xFFFF80EB */
volatile FTM2FILTER0STR _FTM2FILTER0;                      /* FTM2 Input Capture Filter Control Register 0; 0xFFFF80EC */
volatile FTM2FILTER1STR _FTM2FILTER1;                      /* FTM2 Input Capture Filter Control Register 1; 0xFFFF80ED */
volatile FTM2FLTFILTERSTR _FTM2FLTFILTER;                  /* FTM2 Fault Input Filter Control Register; 0xFFFF80EE */
volatile FTM2RFUSTR _FTM2RFU;                              /* FTM2 Register for Future Use; 0xFFFF80EF */
volatile SRSSTR _SRS;                                      /* System Reset Status Register; 0xFFFF9800 */
volatile SOPTSTR _SOPT;                                    /* System Options Register; 0xFFFF9802 */
volatile SMCLKSTR _SMCLK;                                  /* System MCLK Control Register; 0xFFFF9803 */
volatile SRTISCSTR _SRTISC;                                /* System Real-Time Interrupt Status and Control Register; 0xFFFF9808 */
volatile SPMSC1STR _SPMSC1;                                /* System Power Management Status and Control 1 Register; 0xFFFF9809 */
volatile SPMSC2STR _SPMSC2;                                /* System Power Management Status and Control 2 Register; 0xFFFF980A */
volatile SOPT2STR _SOPT2;                                  /* System Options Register 2; 0xFFFF980C */
volatile SCGC1STR _SCGC1;                                  /* System Clock Gating Control 1 Register; 0xFFFF980D */
volatile SCGC2STR _SCGC2;                                  /* System Clock Gating Control 2 Register; 0xFFFF980E */
volatile FCDIVSTR _FCDIV;                                  /* FLASH Clock Divider Register; 0xFFFF9820 */
volatile FOPTSTR _FOPT;                                    /* Flash Options Register; 0xFFFF9821 */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register; 0xFFFF9823 */
volatile FPROTSTR _FPROT;                                  /* Flash Protection Register; 0xFFFF9824 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0xFFFF9825 */
volatile FCMDSTR _FCMD;                                    /* Flash Command Register; 0xFFFF9826 */
volatile TPM3SCSTR _TPM3SC;                                /* TPM3 Status and Control Register; 0xFFFF9830 */
volatile TPM3C0SCSTR _TPM3C0SC;                            /* TPM3 Timer Channel 0 Status and Control Register; 0xFFFF9835 */
volatile TPM3C1SCSTR _TPM3C1SC;                            /* TPM3 Timer Channel 1 Status and Control Register; 0xFFFF9838 */
volatile PTAPESTR _PTAPE;                                  /* Port A Pull Enable Register; 0xFFFF9840 */
volatile PTASESTR _PTASE;                                  /* Port A Slew Rate Enable Register; 0xFFFF9841 */
volatile PTADSSTR _PTADS;                                  /* Port A Drive Strength Selection Register; 0xFFFF9842 */
volatile PTBPESTR _PTBPE;                                  /* Port B Pull Enable Register; 0xFFFF9844 */
volatile PTBSESTR _PTBSE;                                  /* Port B Slew Rate Enable Register; 0xFFFF9845 */
volatile PTBDSSTR _PTBDS;                                  /* Port B Drive Strength Selection Register; 0xFFFF9846 */
volatile PTCPESTR _PTCPE;                                  /* Port C Pull Enable Register; 0xFFFF9848 */
volatile PTCSESTR _PTCSE;                                  /* Port C Slew Rate Enable Register; 0xFFFF9849 */
volatile PTCDSSTR _PTCDS;                                  /* Port C Drive Strength Selection Register; 0xFFFF984A */
volatile PTDPESTR _PTDPE;                                  /* Port D Pull Enable Register; 0xFFFF984C */
volatile PTDSESTR _PTDSE;                                  /* Port D Slew Rate Enable Register; 0xFFFF984D */
volatile PTDDSSTR _PTDDS;                                  /* Port D Drive Strength Selection Register; 0xFFFF984E */
volatile PTEPESTR _PTEPE;                                  /* Port E Pull Enable Register; 0xFFFF9850 */
volatile PTESESTR _PTESE;                                  /* Port E Slew Rate Enable Register; 0xFFFF9851 */
volatile PTEDSSTR _PTEDS;                                  /* Port E Drive Strength Selection Register; 0xFFFF9852 */
volatile PTFPESTR _PTFPE;                                  /* Port F Pull Enable Register; 0xFFFF9854 */
volatile PTFSESTR _PTFSE;                                  /* Port F Slew Rate Enable Register; 0xFFFF9855 */
volatile PTFDSSTR _PTFDS;                                  /* Port F Drive Strength Selection Register; 0xFFFF9856 */
volatile PTGPESTR _PTGPE;                                  /* Port G Pull Enable Register; 0xFFFF9858 */
volatile PTGSESTR _PTGSE;                                  /* Port G Slew Rate Enable Register; 0xFFFF9859 */
volatile PTGDSSTR _PTGDS;                                  /* Port G Drive Strength Selection Register; 0xFFFF985A */
volatile PTHPESTR _PTHPE;                                  /* Port H Pull Enable Register; 0xFFFF985C */
volatile PTHSESTR _PTHSE;                                  /* Port H Slew Rate Enable Register; 0xFFFF985D */
volatile PTHDSSTR _PTHDS;                                  /* Port H Drive Strength Selection Register; 0xFFFF985E */
volatile PTJPESTR _PTJPE;                                  /* Port J Pull Enable Register; 0xFFFF9860 */
volatile PTJSESTR _PTJSE;                                  /* Port J Slew Rate Enable Register; 0xFFFF9861 */
volatile PTJDSSTR _PTJDS;                                  /* Port J Drive Strength Selection Register; 0xFFFF9862 */
volatile SPI2C1STR _SPI2C1;                                /* SPI2 Control Register 1; 0xFFFF9868 */
volatile SPI2C2STR _SPI2C2;                                /* SPI2 Control Register 2; 0xFFFF9869 */
volatile SPI2BRSTR _SPI2BR;                                /* SPI2 Baud Rate Register; 0xFFFF986A */
volatile SPI2SSTR _SPI2S;                                  /* SPI2 Status Register; 0xFFFF986B */
volatile SPI2C3STR _SPI2C3;                                /* SPI2 Control Register 3; 0xFFFF9870 */
volatile SPI2CISTR _SPI2CI;                                /* SPI2 Clear Interrupt Register; 0xFFFF9871 */
volatile CANCTL0STR _CANCTL0;                              /* MSCAN Control 0 Register; 0xFFFF9880 */
volatile CANCTL1STR _CANCTL1;                              /* MSCAN Control 1 Register; 0xFFFF9881 */
volatile CANBTR0STR _CANBTR0;                              /* MSCAN Bus Timing Register 0; 0xFFFF9882 */
volatile CANBTR1STR _CANBTR1;                              /* MSCAN Bus Timing Register 1; 0xFFFF9883 */
volatile CANRFLGSTR _CANRFLG;                              /* MSCAN Receiver Flag Register; 0xFFFF9884 */
volatile CANRIERSTR _CANRIER;                              /* MSCAN Receiver Interrupt Enable Register; 0xFFFF9885 */
volatile CANTFLGSTR _CANTFLG;                              /* MSCAN Transmitter Flag Register; 0xFFFF9886 */
volatile CANTIERSTR _CANTIER;                              /* MSCAN Transmitter Interrupt Enable Register; 0xFFFF9887 */
volatile CANTARQSTR _CANTARQ;                              /* MSCAN Transmitter Message Abort Request; 0xFFFF9888 */
volatile CANTAAKSTR _CANTAAK;                              /* MSCAN Transmitter Message Abort Acknowledge; 0xFFFF9889 */
volatile CANTBSELSTR _CANTBSEL;                            /* MSCAN Transmit Buffer Selection; 0xFFFF988A */
volatile CANIDACSTR _CANIDAC;                              /* MSCAN Identifier Acceptance Control Register; 0xFFFF988B */
volatile CANMISCSTR _CANMISC;                              /* MSCAN Miscellaneous Register; 0xFFFF988D */
volatile CANRXERRSTR _CANRXERR;                            /* MSCAN Receive Error Counter Register; 0xFFFF988E */
volatile CANTXERRSTR _CANTXERR;                            /* MSCAN Transmit Error Counter Register; 0xFFFF988F */
volatile CANIDAR0STR _CANIDAR0;                            /* MSCAN Identifier Acceptance Register 0; 0xFFFF9890 */
volatile CANIDAR1STR _CANIDAR1;                            /* MSCAN Identifier Acceptance Register 1; 0xFFFF9891 */
volatile CANIDAR2STR _CANIDAR2;                            /* MSCAN Identifier Acceptance Register 2; 0xFFFF9892 */
volatile CANIDAR3STR _CANIDAR3;                            /* MSCAN Identifier Acceptance Register 3; 0xFFFF9893 */
volatile CANIDMR0STR _CANIDMR0;                            /* MSCAN Identifier Mask Register 0; 0xFFFF9894 */
volatile CANIDMR1STR _CANIDMR1;                            /* MSCAN Identifier Mask Register 1; 0xFFFF9895 */
volatile CANIDMR2STR _CANIDMR2;                            /* MSCAN Identifier Mask Register 2; 0xFFFF9896 */
volatile CANIDMR3STR _CANIDMR3;                            /* MSCAN Identifier Mask Register 3; 0xFFFF9897 */
volatile CANIDAR4STR _CANIDAR4;                            /* MSCAN Identifier Acceptance Register 4; 0xFFFF9898 */
volatile CANIDAR5STR _CANIDAR5;                            /* MSCAN Identifier Acceptance Register 5; 0xFFFF9899 */
volatile CANIDAR6STR _CANIDAR6;                            /* MSCAN Identifier Acceptance Register 6; 0xFFFF989A */
volatile CANIDAR7STR _CANIDAR7;                            /* MSCAN Identifier Acceptance Register 7; 0xFFFF989B */
volatile CANIDMR4STR _CANIDMR4;                            /* MSCAN Identifier Mask Register 4; 0xFFFF989C */
volatile CANIDMR5STR _CANIDMR5;                            /* MSCAN Identifier Mask Register 5; 0xFFFF989D */
volatile CANIDMR6STR _CANIDMR6;                            /* MSCAN Identifier Mask Register 6; 0xFFFF989E */
volatile CANIDMR7STR _CANIDMR7;                            /* MSCAN Identifier Mask Register 7; 0xFFFF989F */
volatile CANRDSR0STR _CANRDSR0;                            /* MSCAN Receive Data Segment Register 0; 0xFFFF98A4 */
volatile CANRDSR1STR _CANRDSR1;                            /* MSCAN Receive Data Segment Register 1; 0xFFFF98A5 */
volatile CANRDSR2STR _CANRDSR2;                            /* MSCAN Receive Data Segment Register 2; 0xFFFF98A6 */
volatile CANRDSR3STR _CANRDSR3;                            /* MSCAN Receive Data Segment Register 3; 0xFFFF98A7 */
volatile CANRDSR4STR _CANRDSR4;                            /* MSCAN Receive Data Segment Register 4; 0xFFFF98A8 */
volatile CANRDSR5STR _CANRDSR5;                            /* MSCAN Receive Data Segment Register 5; 0xFFFF98A9 */
volatile CANRDSR6STR _CANRDSR6;                            /* MSCAN Receive Data Segment Register 6; 0xFFFF98AA */
volatile CANRDSR7STR _CANRDSR7;                            /* MSCAN Receive Data Segment Register 7; 0xFFFF98AB */
volatile CANRDLRSTR _CANRDLR;                              /* MSCAN Receive Data Length Register; 0xFFFF98AC */
volatile CANTDSR0STR _CANTDSR0;                            /* MSCAN Transmit Data Segment Register 0; 0xFFFF98B4 */
volatile CANTDSR1STR _CANTDSR1;                            /* MSCAN Transmit Data Segment Register 1; 0xFFFF98B5 */
volatile CANTDSR2STR _CANTDSR2;                            /* MSCAN Transmit Data Segment Register 2; 0xFFFF98B6 */
volatile CANTDSR3STR _CANTDSR3;                            /* MSCAN Transmit Data Segment Register 3; 0xFFFF98B7 */
volatile CANTDSR4STR _CANTDSR4;                            /* MSCAN Transmit Data Segment Register 4; 0xFFFF98B8 */
volatile CANTDSR5STR _CANTDSR5;                            /* MSCAN Transmit Data Segment Register 5; 0xFFFF98B9 */
volatile CANTDSR6STR _CANTDSR6;                            /* MSCAN Transmit Data Segment Register 6; 0xFFFF98BA */
volatile CANTDSR7STR _CANTDSR7;                            /* MSCAN Transmit Data Segment Register 7; 0xFFFF98BB */
volatile CANTDLRSTR _CANTDLR;                              /* MSCAN Transmit Data Length Register; 0xFFFF98BC */
volatile CANTTBPRSTR _CANTTBPR;                            /* MSCAN Transmit Buffer Priority; 0xFFFF98BD */
volatile CRCHSTR _CRCH;                                    /* CRC High Register; 0xFFFF98C0 */
volatile CRCLSTR _CRCL;                                    /* CRC Low Register; 0xFFFF98C1 */
volatile CRCL0STR _CRCL0;                                  /* CRC Low Register 0; 0xFFFF98C4 */
volatile CRCL1STR _CRCL1;                                  /* CRC Low Register 1; 0xFFFF98C5 */
volatile CRCL2STR _CRCL2;                                  /* CRC Low Register 2; 0xFFFF98C6 */
volatile CRCL3STR _CRCL3;                                  /* CRC Low Register 3; 0xFFFF98C7 */
volatile INTC_FRCSTR _INTC_FRC;                            /* INTC Force Interrupt Register; 0xFFFFFFD0 */
volatile INTC_PL6P7STR _INTC_PL6P7;                        /* INTC Programmable Level 6, Priority 7 Register; 0xFFFFFFD8 */
volatile INTC_PL6P6STR _INTC_PL6P6;                        /* INTC Programmable Level 6, Priority 6 Register; 0xFFFFFFD9 */
volatile INTC_WCRSTR _INTC_WCR;                            /* INTC Wake-up Control Register; 0xFFFFFFDB */
volatile INTC_SFRCSTR _INTC_SFRC;                          /* INTC Set Interrupt Force Register; 0xFFFFFFDE */
volatile INTC_CFRCSTR _INTC_CFRC;                          /* INTC Clear Interrupt Force Register; 0xFFFFFFDF */
volatile INTC_SWIACKSTR _INTC_SWIACK;                      /* INTC Software IACK Register; 0xFFFFFFE0 */
volatile INTC_LVL1IACKSTR _INTC_LVL1IACK;                  /* INTC Level 1 IACK Register; 0xFFFFFFE4 */
volatile INTC_LVL2IACKSTR _INTC_LVL2IACK;                  /* INTC Level 2 IACK Register; 0xFFFFFFE8 */
volatile INTC_LVL3IACKSTR _INTC_LVL3IACK;                  /* INTC Level 3 IACK Register; 0xFFFFFFEC */
volatile INTC_LVL4IACKSTR _INTC_LVL4IACK;                  /* INTC Level 4 IACK Register; 0xFFFFFFF0 */
volatile INTC_LVL5IACKSTR _INTC_LVL5IACK;                  /* INTC Level 5 IACK Register; 0xFFFFFFF4 */
volatile INTC_LVL6IACKSTR _INTC_LVL6IACK;                  /* INTC Level 6 IACK Register; 0xFFFFFFF8 */
volatile INTC_LVL7IACKSTR _INTC_LVL7IACK;                  /* INTC Level 7 IACK Register; 0xFFFFFFFC */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile RGPIO_DIRSTR _RGPIO_DIR;                          /* RGPIO Data Direction Register; 0x00C00000 */
volatile RGPIO_DATASTR _RGPIO_DATA;                        /* RGPIO Data Register; 0x00C00002 */
volatile RGPIO_ENBSTR _RGPIO_ENB;                          /* RGPIO Pin Enable Register; 0x00C00004 */
volatile RGPIO_CLRSTR _RGPIO_CLR;                          /* RGPIO Clear Data Register; 0x00C00006 */
volatile RGPIO_SETSTR _RGPIO_SET;                          /* RGPIO Set Data Register; 0x00C0000A */
volatile RGPIO_TOGSTR _RGPIO_TOG;                          /* RGPIO Toggle Data Register; 0x00C0000E */
volatile ADCRSTR _ADCR;                                    /* Data Result Register; 0xFFFF8012 */
volatile ADCCVSTR _ADCCV;                                  /* Compare Value Register; 0xFFFF8014 */
volatile SCI1BDSTR _SCI1BD;                                /* SCI1 Baud Rate Register; 0xFFFF8038 */
volatile SCI2BDSTR _SCI2BD;                                /* SCI2 Baud Rate Register; 0xFFFF8040 */
volatile FTM1CNTSTR _FTM1CNT;                              /* FTM1 Timer Counter Register; 0xFFFF8081 */
volatile FTM1MODSTR _FTM1MOD;                              /* FTM1 Timer Counter Modulo Register; 0xFFFF8083 */
volatile FTM1C0VSTR _FTM1C0V;                              /* FTM1 Timer Channel 0 Value Register; 0xFFFF8086 */
volatile FTM1C1VSTR _FTM1C1V;                              /* FTM1 Timer Channel 1 Value Register; 0xFFFF8089 */
volatile FTM1C2VSTR _FTM1C2V;                              /* FTM1 Timer Channel 2 Value Register; 0xFFFF808C */
volatile FTM1C3VSTR _FTM1C3V;                              /* FTM1 Timer Channel 3 Value Register; 0xFFFF808F */
volatile FTM1C4VSTR _FTM1C4V;                              /* FTM1 Timer Channel 4 Value Register; 0xFFFF8092 */
volatile FTM1C5VSTR _FTM1C5V;                              /* FTM1 Timer Channel 5 Value Register; 0xFFFF8095 */
volatile FTM1CNTINSTR _FTM1CNTIN;                          /* FTM1 Counter Initial Value Registers; 0xFFFF809D */
volatile FTM2CNTSTR _FTM2CNT;                              /* FTM2 Timer Counter Register; 0xFFFF80C1 */
volatile FTM2MODSTR _FTM2MOD;                              /* FTM2 Timer Counter Modulo Register; 0xFFFF80C3 */
volatile FTM2C0VSTR _FTM2C0V;                              /* FTM2 Timer Channel 0 Value Register; 0xFFFF80C6 */
volatile FTM2C1VSTR _FTM2C1V;                              /* FTM2 Timer Channel 1 Value Register; 0xFFFF80C9 */
volatile FTM2C2VSTR _FTM2C2V;                              /* FTM2 Timer Channel 2 Value Register; 0xFFFF80CC */
volatile FTM2C3VSTR _FTM2C3V;                              /* FTM2 Timer Channel 3 Value Register; 0xFFFF80CF */
volatile FTM2C4VSTR _FTM2C4V;                              /* FTM2 Timer Channel 4 Value Register; 0xFFFF80D2 */
volatile FTM2C5VSTR _FTM2C5V;                              /* FTM2 Timer Channel 5 Value Register; 0xFFFF80D5 */
volatile FTM2CNTINSTR _FTM2CNTIN;                          /* FTM2 Counter Initial Value Registers; 0xFFFF80DD */
volatile SDIDSTR _SDID;                                    /* System Device Identification Register; 0xFFFF9806 */
volatile TPM3CNTSTR _TPM3CNT;                              /* TPM3 Timer Counter Register; 0xFFFF9831 */
volatile TPM3MODSTR _TPM3MOD;                              /* TPM3 Timer Counter Modulo Register; 0xFFFF9833 */
volatile TPM3C0VSTR _TPM3C0V;                              /* TPM3 Timer Channel 0 Value Register; 0xFFFF9836 */
volatile TPM3C1VSTR _TPM3C1V;                              /* TPM3 Timer Channel 1 Value Register; 0xFFFF9839 */
volatile SPI2D16STR _SPI2D16;                              /* SPI2 Data Register; 0xFFFF986C */
volatile SPI2MSTR _SPI2M;                                  /* SPI2 Match Register; 0xFFFF986E */
volatile CANRTSRSTR _CANRTSR;                              /* MSCAN Receive Time Stamp Register; 0xFFFF98AE */
volatile CANTTSRSTR _CANTTSR;                              /* MSCAN Transmit Time Stamp Register; 0xFFFF98BE */


/* * * * *  32-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile CANRIDRSTR _CANRIDR;                              /* MSCAN 0 Receive Identifier Register; 0xFFFF98A0 */
volatile CANTIDRSTR _CANTIDR;                              /* MSCAN 0 Transmit Identifier Register; 0xFFFF98B0 */

/*lint -restore */

/* EOF */
