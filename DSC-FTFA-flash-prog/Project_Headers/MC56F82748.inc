;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; File: MC56F82748.inc
;; Purpose: Define the peripheral registers for pure assembly language.
;; This file has been automatically generated from the APIF knowledgebase
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Generic Bit Definitions Used Elsewhere in this File
;;
 define  BIT0                        '$1'
 define  BIT1                        '$2'
 define  BIT2                        '$4'
 define  BIT3                        '$8'
 define  BIT4                        '$10'
 define  BIT5                        '$20'
 define  BIT6                        '$40'
 define  BIT7                        '$80'
 define  BIT8                        '$100'
 define  BIT9                        '$200'
 define  BIT10                       '$400'
 define  BIT11                       '$800'
 define  BIT12                       '$1000'
 define  BIT13                       '$2000'
 define  BIT14                       '$4000'
 define  BIT15                       '$8000'
 define  BIT16                       '$10000'
 define  BIT17                       '$20000'
 define  BIT18                       '$40000'
 define  BIT19                       '$80000'
 define  BIT20                       '$100000'
 define  BIT21                       '$200000'
 define  BIT22                       '$400000'
 define  BIT23                       '$800000'
 define  BIT24                       '$1000000'
 define  BIT25                       '$2000000'
 define  BIT26                       '$4000000'
 define  BIT27                       '$8000000'
 define  BIT28                       '$10000000'
 define  BIT29                       '$20000000'
 define  BIT30                       '$40000000'
 define  BIT31                       '$80000000'

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Peripheral Base Address Defines in Alphabetical Order
;;
 define  ADC                         '$E500'
 define  AOI                         '$E380'
 define  CAN                         '$E700'
 define  CMPA                        '$E020'
 define  CMPB                        '$E028'
 define  CMPC                        '$E030'
 define  CMPD                        '$E038'
 define  COP                         '$E320'
 define  CRC                         '$E1C0'
 define  DACA                        '$E000'
 define  DACB                        '$E010'
 define  DMA                         '$C800'
 define  EWM                         '$E330'
 define  FMC                         '$DE00'
 define  FTFA                        '$1C780'
 define  GPIOA                       '$E200'
 define  GPIOB                       '$E210'
 define  GPIOC                       '$E220'
 define  GPIOD                       '$E230'
 define  GPIOE                       '$E240'
 define  GPIOF                       '$E250'
 define  I2C                         '$E0E0'
 define  INTC                        '$E300'
 define  MCM                         '$18000'
 define  OCCS                        '$E2B0'
 define  PIT0                        '$E100'
 define  PIT1                        '$E110'
 define  PMC                         '$E2A0'
 define  PWMA                        '$E600'
 define  QSCI0                       '$E080'
 define  QSCI1                       '$E090'
 define  QSPI0                       '$E0B0'
 define  QSPI1                       '$E0C0'
 define  SIM                         '$E400'
 define  TMR                         '$E140'
 define  XBARA                       '$E340'
 define  XBARB                       '$E360'

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; The following section defines the IO register locations.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 define  ADC_CTRL1                   '$E500'
 define  ADC_CTRL2                   '$E501'
 define  ADC_ZXCTRL1                 '$E502'
 define  ADC_ZXCTRL2                 '$E503'
 define  ADC_CLIST1                  '$E504'
 define  ADC_CLIST2                  '$E505'
 define  ADC_CLIST3                  '$E506'
 define  ADC_CLIST4                  '$E507'
 define  ADC_SDIS                    '$E508'
 define  ADC_STAT                    '$E509'
 define  ADC_RDY                     '$E50A'
 define  ADC_LOLIMSTAT               '$E50B'
 define  ADC_HILIMSTAT               '$E50C'
 define  ADC_ZXSTAT                  '$E50D'
 define  ADC_RSLT0                   '$E50E'
 define  ADC_RSLT1                   '$E50F'
 define  ADC_RSLT2                   '$E510'
 define  ADC_RSLT3                   '$E511'
 define  ADC_RSLT4                   '$E512'
 define  ADC_RSLT5                   '$E513'
 define  ADC_RSLT6                   '$E514'
 define  ADC_RSLT7                   '$E515'
 define  ADC_RSLT8                   '$E516'
 define  ADC_RSLT9                   '$E517'
 define  ADC_RSLT10                  '$E518'
 define  ADC_RSLT11                  '$E519'
 define  ADC_RSLT12                  '$E51A'
 define  ADC_RSLT13                  '$E51B'
 define  ADC_RSLT14                  '$E51C'
 define  ADC_RSLT15                  '$E51D'
 define  ADC_LOLIM0                  '$E51E'
 define  ADC_LOLIM1                  '$E51F'
 define  ADC_LOLIM2                  '$E520'
 define  ADC_LOLIM3                  '$E521'
 define  ADC_LOLIM4                  '$E522'
 define  ADC_LOLIM5                  '$E523'
 define  ADC_LOLIM6                  '$E524'
 define  ADC_LOLIM7                  '$E525'
 define  ADC_LOLIM8                  '$E526'
 define  ADC_LOLIM9                  '$E527'
 define  ADC_LOLIM10                 '$E528'
 define  ADC_LOLIM11                 '$E529'
 define  ADC_LOLIM12                 '$E52A'
 define  ADC_LOLIM13                 '$E52B'
 define  ADC_LOLIM14                 '$E52C'
 define  ADC_LOLIM15                 '$E52D'
 define  ADC_HILIM0                  '$E52E'
 define  ADC_HILIM1                  '$E52F'
 define  ADC_HILIM2                  '$E530'
 define  ADC_HILIM3                  '$E531'
 define  ADC_HILIM4                  '$E532'
 define  ADC_HILIM5                  '$E533'
 define  ADC_HILIM6                  '$E534'
 define  ADC_HILIM7                  '$E535'
 define  ADC_HILIM8                  '$E536'
 define  ADC_HILIM9                  '$E537'
 define  ADC_HILIM10                 '$E538'
 define  ADC_HILIM11                 '$E539'
 define  ADC_HILIM12                 '$E53A'
 define  ADC_HILIM13                 '$E53B'
 define  ADC_HILIM14                 '$E53C'
 define  ADC_HILIM15                 '$E53D'
 define  ADC_OFFST0                  '$E53E'
 define  ADC_OFFST1                  '$E53F'
 define  ADC_OFFST2                  '$E540'
 define  ADC_OFFST3                  '$E541'
 define  ADC_OFFST4                  '$E542'
 define  ADC_OFFST5                  '$E543'
 define  ADC_OFFST6                  '$E544'
 define  ADC_OFFST7                  '$E545'
 define  ADC_OFFST8                  '$E546'
 define  ADC_OFFST9                  '$E547'
 define  ADC_OFFST10                 '$E548'
 define  ADC_OFFST11                 '$E549'
 define  ADC_OFFST12                 '$E54A'
 define  ADC_OFFST13                 '$E54B'
 define  ADC_OFFST14                 '$E54C'
 define  ADC_OFFST15                 '$E54D'
 define  ADC_PWR                     '$E54E'
 define  ADC_CAL                     '$E54F'
 define  ADC_GC1                     '$E550'
 define  ADC_GC2                     '$E551'
 define  ADC_SCTRL                   '$E552'
 define  ADC_PWR2                    '$E553'
 define  ADC_CTRL3                   '$E554'
 define  ADC_SCHLTEN                 '$E555'
 define  ADC_ZXCTRL3                 '$E558'
 define  ADC_CLIST5                  '$E559'
 define  ADC_SDIS2                   '$E55A'
 define  ADC_RDY2                    '$E55B'
 define  ADC_LOLIMSTAT2              '$E55C'
 define  ADC_HILIMSTAT2              '$E55D'
 define  ADC_ZXSTAT2                 '$E55E'
 define  ADC_RSLT216                 '$E55F'
 define  ADC_RSLT217                 '$E560'
 define  ADC_RSLT218                 '$E561'
 define  ADC_RSLT219                 '$E562'
 define  ADC_LOLIM216                '$E563'
 define  ADC_LOLIM217                '$E564'
 define  ADC_LOLIM218                '$E565'
 define  ADC_LOLIM219                '$E566'
 define  ADC_HILIM216                '$E567'
 define  ADC_HILIM217                '$E568'
 define  ADC_HILIM218                '$E569'
 define  ADC_HILIM219                '$E56A'
 define  ADC_OFFST216                '$E56B'
 define  ADC_OFFST217                '$E56C'
 define  ADC_OFFST218                '$E56D'
 define  ADC_OFFST219                '$E56E'
 define  ADC_GC3                     '$E56F'
 define  ADC_SCTRL2                  '$E570'
 define  ADC_SCHLTEN2                '$E571'
 define  AOI_BFCRT010                '$E380'
 define  AOI_BFCRT230                '$E381'
 define  AOI_BFCRT011                '$E382'
 define  AOI_BFCRT231                '$E383'
 define  AOI_BFCRT012                '$E384'
 define  AOI_BFCRT232                '$E385'
 define  AOI_BFCRT013                '$E386'
 define  AOI_BFCRT233                '$E387'
 define  CAN_CTL0                    '$E700'
 define  CAN_CTL1                    '$E701'
 define  CAN_BTR0                    '$E702'
 define  CAN_BTR1                    '$E703'
 define  CAN_RFLG                    '$E704'
 define  CAN_RIER                    '$E705'
 define  CAN_TFLG                    '$E706'
 define  CAN_TIER                    '$E707'
 define  CAN_TARQ                    '$E708'
 define  CAN_TAAK                    '$E709'
 define  CAN_TBSEL                   '$E70A'
 define  CAN_IDAC                    '$E70B'
 define  CAN_MISC                    '$E70D'
 define  CAN_RXERR                   '$E70E'
 define  CAN_TXERR                   '$E70F'
 define  CAN_IDAR0                   '$E710'
 define  CAN_IDAR1                   '$E711'
 define  CAN_IDAR2                   '$E712'
 define  CAN_IDAR3                   '$E713'
 define  CAN_IDMR0                   '$E714'
 define  CAN_IDMR1                   '$E715'
 define  CAN_IDMR2                   '$E716'
 define  CAN_IDMR3                   '$E717'
 define  CAN_IDAR4                   '$E718'
 define  CAN_IDAR5                   '$E719'
 define  CAN_IDAR6                   '$E71A'
 define  CAN_IDAR7                   '$E71B'
 define  CAN_IDMR4                   '$E71C'
 define  CAN_IDMR5                   '$E71D'
 define  CAN_IDMR6                   '$E71E'
 define  CAN_IDMR7                   '$E71F'
 define  CAN_RXFG_IDR0_EXT           '$E720'
 define  CAN_RXFG_IDR0_STD           '$E720'
 define  CAN_RXFG_IDR1_EXT           '$E721'
 define  CAN_RXFG_IDR1_STD           '$E721'
 define  CAN_RXFG_IDR2_EXT           '$E722'
 define  CAN_RXFG_IDR3_EXT           '$E723'
 define  CAN_RXFG_DSR0               '$E724'
 define  CAN_RXFG_DSR1               '$E725'
 define  CAN_RXFG_DSR2               '$E726'
 define  CAN_RXFG_DSR3               '$E727'
 define  CAN_RXFG_DSR4               '$E728'
 define  CAN_RXFG_DSR5               '$E729'
 define  CAN_RXFG_DSR6               '$E72A'
 define  CAN_RXFG_DSR7               '$E72B'
 define  CAN_RXFG_DLR                '$E72C'
 define  CAN_RXFG_TSRH               '$E72E'
 define  CAN_RXFG_TSRL               '$E72F'
 define  CAN_TXFG_IDR0_EXT           '$E730'
 define  CAN_TXFG_IDR0_STD           '$E730'
 define  CAN_TXFG_IDR1_EXT           '$E731'
 define  CAN_TXFG_IDR1_STD           '$E731'
 define  CAN_TXFG_IDR2_EXT           '$E732'
 define  CAN_TXFG_IDR3_EXT           '$E733'
 define  CAN_TXFG_DSR0               '$E734'
 define  CAN_TXFG_DSR1               '$E735'
 define  CAN_TXFG_DSR2               '$E736'
 define  CAN_TXFG_DSR3               '$E737'
 define  CAN_TXFG_DSR4               '$E738'
 define  CAN_TXFG_DSR5               '$E739'
 define  CAN_TXFG_DSR6               '$E73A'
 define  CAN_TXFG_DSR7               '$E73B'
 define  CAN_TXFG_DLR                '$E73C'
 define  CAN_TXFG_TBPR               '$E73D'
 define  CAN_TXFG_TSRH               '$E73E'
 define  CAN_TXFG_TSRL               '$E73F'
 define  CMPA_CR0                    '$E020'
 define  CMPA_CR1                    '$E021'
 define  CMPA_FPR                    '$E022'
 define  CMPA_SCR                    '$E023'
 define  CMPA_DACCR                  '$E024'
 define  CMPA_MUXCR                  '$E025'
 define  CMPB_CR0                    '$E028'
 define  CMPB_CR1                    '$E029'
 define  CMPB_FPR                    '$E02A'
 define  CMPB_SCR                    '$E02B'
 define  CMPB_DACCR                  '$E02C'
 define  CMPB_MUXCR                  '$E02D'
 define  CMPC_CR0                    '$E030'
 define  CMPC_CR1                    '$E031'
 define  CMPC_FPR                    '$E032'
 define  CMPC_SCR                    '$E033'
 define  CMPC_DACCR                  '$E034'
 define  CMPC_MUXCR                  '$E035'
 define  CMPD_CR0                    '$E038'
 define  CMPD_CR1                    '$E039'
 define  CMPD_FPR                    '$E03A'
 define  CMPD_SCR                    '$E03B'
 define  CMPD_DACCR                  '$E03C'
 define  CMPD_MUXCR                  '$E03D'
 define  COP_CTRL                    '$E320'
 define  COP_TOUT                    '$E321'
 define  COP_CNTR                    '$E322'
 define  COP_INTVAL                  '$E323'
 define  COP_WINDOW                  '$E324'
 define  CRC_CRCH                    '$E1C0'
 define  CRC_CRCL                    '$E1C1'
 define  CRC_TRANSPOSE               '$E1C2'
 define  DACA_CTRL0                  '$E000'
 define  DACA_DATAREG_FMT0           '$E001'
 define  DACA_DATAREG_FMT1           '$E001'
 define  DACA_STEPVAL_FMT0           '$E002'
 define  DACA_STEPVAL_FMT1           '$E002'
 define  DACA_MINVAL_FMT0            '$E003'
 define  DACA_MINVAL_FMT1            '$E003'
 define  DACA_MAXVAL_FMT0            '$E004'
 define  DACA_MAXVAL_FMT1            '$E004'
 define  DACA_STATUS                 '$E005'
 define  DACA_CTRL1                  '$E006'
 define  DACB_CTRL0                  '$E010'
 define  DACB_DATAREG_FMT0           '$E011'
 define  DACB_DATAREG_FMT1           '$E011'
 define  DACB_STEPVAL_FMT0           '$E012'
 define  DACB_STEPVAL_FMT1           '$E012'
 define  DACB_MINVAL_FMT0            '$E013'
 define  DACB_MINVAL_FMT1            '$E013'
 define  DACB_MAXVAL_FMT0            '$E014'
 define  DACB_MAXVAL_FMT1            '$E014'
 define  DACB_STATUS                 '$E015'
 define  DACB_CTRL1                  '$E016'
 define  DMA_REQC                    '$C800'
 define  DMA_SAR0                    '$C880'
 define  DMA_DAR0                    '$C882'
 define  DMA_DSR_BCR0                '$C884'
 define  DMA_DCR0                    '$C886'
 define  DMA_SAR1                    '$C888'
 define  DMA_DAR1                    '$C88A'
 define  DMA_DSR_BCR1                '$C88C'
 define  DMA_DCR1                    '$C88E'
 define  DMA_SAR2                    '$C890'
 define  DMA_DAR2                    '$C892'
 define  DMA_DSR_BCR2                '$C894'
 define  DMA_DCR2                    '$C896'
 define  DMA_SAR3                    '$C898'
 define  DMA_DAR3                    '$C89A'
 define  DMA_DSR_BCR3                '$C89C'
 define  DMA_DCR3                    '$C89E'
 define  EWM_CTRL                    '$E330'
 define  EWM_SERV                    '$E331'
 define  EWM_CMPL                    '$E332'
 define  EWM_CMPH                    '$E333'
 define  EWM_CLKCTRL                 '$E334'
 define  EWM_CLKPRESCALER            '$E335'
 define  FMC_PFAPR                   '$DE00'
 define  FMC_PFB0CR                  '$DE02'
 define  FMC_TAGVDW0S0               '$DE80'
 define  FMC_TAGVDW0S1               '$DE82'
 define  FMC_TAGVDW0S2               '$DE84'
 define  FMC_TAGVDW0S3               '$DE86'
 define  FMC_TAGVDW1S0               '$DE88'
 define  FMC_TAGVDW1S1               '$DE8A'
 define  FMC_TAGVDW1S2               '$DE8C'
 define  FMC_TAGVDW1S3               '$DE8E'
 define  FMC_TAGVDW2S0               '$DE90'
 define  FMC_TAGVDW2S1               '$DE92'
 define  FMC_TAGVDW2S2               '$DE94'
 define  FMC_TAGVDW2S3               '$DE96'
 define  FMC_TAGVDW3S0               '$DE98'
 define  FMC_TAGVDW3S1               '$DE9A'
 define  FMC_TAGVDW3S2               '$DE9C'
 define  FMC_TAGVDW3S3               '$DE9E'
 define  FMC_DATAW0S0                '$DF00'
 define  FMC_DATAW0S1                '$DF02'
 define  FMC_DATAW0S2                '$DF04'
 define  FMC_DATAW0S3                '$DF06'
 define  FMC_DATAW1S0                '$DF08'
 define  FMC_DATAW1S1                '$DF0A'
 define  FMC_DATAW1S2                '$DF0C'
 define  FMC_DATAW1S3                '$DF0E'
 define  FMC_DATAW2S0                '$DF10'
 define  FMC_DATAW2S1                '$DF12'
 define  FMC_DATAW2S2                '$DF14'
 define  FMC_DATAW2S3                '$DF16'
 define  FMC_DATAW3S0                '$DF18'
 define  FMC_DATAW3S1                '$DF1A'
 define  FMC_DATAW3S2                '$DF1C'
 define  FMC_DATAW3S3                '$DF1E'
 define  FTFA_FSTAT                  '$1C780'
 define  FTFA_FCNFG                  '$1C781'
 define  FTFA_FSEC                   '$1C782'
 define  FTFA_FOPT                   '$1C783'
 define  FTFA_FCCOB3                 '$1C784'
 define  FTFA_FCCOB2                 '$1C785'
 define  FTFA_FCCOB1                 '$1C786'
 define  FTFA_FCCOB0                 '$1C787'
 define  FTFA_FCCOB7                 '$1C788'
 define  FTFA_FCCOB6                 '$1C789'
 define  FTFA_FCCOB5                 '$1C78A'
 define  FTFA_FCCOB4                 '$1C78B'
 define  FTFA_FCCOBB                 '$1C78C'
 define  FTFA_FCCOBA                 '$1C78D'
 define  FTFA_FCCOB9                 '$1C78E'
 define  FTFA_FCCOB8                 '$1C78F'
 define  FTFA_FPROT3                 '$1C790'
 define  FTFA_FPROT2                 '$1C791'
 define  FTFA_FPROT1                 '$1C792'
 define  FTFA_FPROT0                 '$1C793'
 define  GPIOA_PUR                   '$E200'
 define  GPIOA_DR                    '$E201'
 define  GPIOA_DDR                   '$E202'
 define  GPIOA_PER                   '$E203'
 define  GPIOA_IAR                   '$E204'
 define  GPIOA_IENR                  '$E205'
 define  GPIOA_IPOLR                 '$E206'
 define  GPIOA_IPR                   '$E207'
 define  GPIOA_IESR                  '$E208'
 define  GPIOA_PPMODE                '$E209'
 define  GPIOA_RAWDATA               '$E20A'
 define  GPIOA_DRIVE                 '$E20B'
 define  GPIOA_PUS                   '$E20C'
 define  GPIOA_SRE                   '$E20D'
 define  GPIOB_PUR                   '$E210'
 define  GPIOB_DR                    '$E211'
 define  GPIOB_DDR                   '$E212'
 define  GPIOB_PER                   '$E213'
 define  GPIOB_IAR                   '$E214'
 define  GPIOB_IENR                  '$E215'
 define  GPIOB_IPOLR                 '$E216'
 define  GPIOB_IPR                   '$E217'
 define  GPIOB_IESR                  '$E218'
 define  GPIOB_PPMODE                '$E219'
 define  GPIOB_RAWDATA               '$E21A'
 define  GPIOB_DRIVE                 '$E21B'
 define  GPIOB_PUS                   '$E21C'
 define  GPIOB_SRE                   '$E21D'
 define  GPIOC_PUR                   '$E220'
 define  GPIOC_DR                    '$E221'
 define  GPIOC_DDR                   '$E222'
 define  GPIOC_PER                   '$E223'
 define  GPIOC_IAR                   '$E224'
 define  GPIOC_IENR                  '$E225'
 define  GPIOC_IPOLR                 '$E226'
 define  GPIOC_IPR                   '$E227'
 define  GPIOC_IESR                  '$E228'
 define  GPIOC_PPMODE                '$E229'
 define  GPIOC_RAWDATA               '$E22A'
 define  GPIOC_DRIVE                 '$E22B'
 define  GPIOC_PUS                   '$E22C'
 define  GPIOC_SRE                   '$E22D'
 define  GPIOD_PUR                   '$E230'
 define  GPIOD_DR                    '$E231'
 define  GPIOD_DDR                   '$E232'
 define  GPIOD_PER                   '$E233'
 define  GPIOD_IAR                   '$E234'
 define  GPIOD_IENR                  '$E235'
 define  GPIOD_IPOLR                 '$E236'
 define  GPIOD_IPR                   '$E237'
 define  GPIOD_IESR                  '$E238'
 define  GPIOD_PPMODE                '$E239'
 define  GPIOD_RAWDATA               '$E23A'
 define  GPIOD_DRIVE                 '$E23B'
 define  GPIOD_PUS                   '$E23C'
 define  GPIOD_SRE                   '$E23D'
 define  GPIOE_PUR                   '$E240'
 define  GPIOE_DR                    '$E241'
 define  GPIOE_DDR                   '$E242'
 define  GPIOE_PER                   '$E243'
 define  GPIOE_IAR                   '$E244'
 define  GPIOE_IENR                  '$E245'
 define  GPIOE_IPOLR                 '$E246'
 define  GPIOE_IPR                   '$E247'
 define  GPIOE_IESR                  '$E248'
 define  GPIOE_PPMODE                '$E249'
 define  GPIOE_RAWDATA               '$E24A'
 define  GPIOE_DRIVE                 '$E24B'
 define  GPIOE_PUS                   '$E24C'
 define  GPIOE_SRE                   '$E24D'
 define  GPIOF_PUR                   '$E250'
 define  GPIOF_DR                    '$E251'
 define  GPIOF_DDR                   '$E252'
 define  GPIOF_PER                   '$E253'
 define  GPIOF_IAR                   '$E254'
 define  GPIOF_IENR                  '$E255'
 define  GPIOF_IPOLR                 '$E256'
 define  GPIOF_IPR                   '$E257'
 define  GPIOF_IESR                  '$E258'
 define  GPIOF_PPMODE                '$E259'
 define  GPIOF_RAWDATA               '$E25A'
 define  GPIOF_DRIVE                 '$E25B'
 define  GPIOF_PUS                   '$E25C'
 define  GPIOF_SRE                   '$E25D'
 define  I2C_A1                      '$E0E0'
 define  I2C_F                       '$E0E1'
 define  I2C_C1                      '$E0E2'
 define  I2C_S                       '$E0E3'
 define  I2C_D                       '$E0E4'
 define  I2C_C2                      '$E0E5'
 define  I2C_FLT                     '$E0E6'
 define  I2C_RA                      '$E0E7'
 define  I2C_SMB                     '$E0E8'
 define  I2C_A2                      '$E0E9'
 define  I2C_SLTH                    '$E0EA'
 define  I2C_SLTL                    '$E0EB'
 define  INTC_IPR0                   '$E300'
 define  INTC_IPR1                   '$E301'
 define  INTC_IPR2                   '$E302'
 define  INTC_IPR3                   '$E303'
 define  INTC_IPR4                   '$E304'
 define  INTC_IPR5                   '$E305'
 define  INTC_IPR6                   '$E306'
 define  INTC_IPR8                   '$E308'
 define  INTC_IPR9                   '$E309'
 define  INTC_IPR10                  '$E30A'
 define  INTC_IPR11                  '$E30B'
 define  INTC_IPR12                  '$E30C'
 define  INTC_VBA                    '$E30D'
 define  INTC_FIM0                   '$E30E'
 define  INTC_FIVAL0                 '$E30F'
 define  INTC_FIVAH0                 '$E310'
 define  INTC_FIM1                   '$E311'
 define  INTC_FIVAL1                 '$E312'
 define  INTC_FIVAH1                 '$E313'
 define  INTC_IRQP0                  '$E314'
 define  INTC_IRQP1                  '$E315'
 define  INTC_IRQP2                  '$E316'
 define  INTC_IRQP3                  '$E317'
 define  INTC_IRQP4                  '$E318'
 define  INTC_IRQP5                  '$E319'
 define  INTC_IRQP6                  '$E31A'
 define  INTC_CTRL                   '$E31B'
 define  MCM_PLASC                   '$18008'
 define  MCM_PLAMC                   '$1800A'
 define  MCM_CPCR                    '$1800C'
 define  MCM_CFADR                   '$18010'
 define  MCM_CFATR                   '$18014'
 define  MCM_CFLOC                   '$18015'
 define  MCM_CFIER                   '$18016'
 define  MCM_CFISR                   '$18017'
 define  MCM_CFDTR                   '$18018'
 define  MCM_RPCR                    '$18020'
 define  MCM_UFLASHBAR               '$18024'
 define  MCM_UPRAMBAR                '$18028'
 define  MCM_SRPOSP                  '$18030'
 define  MCM_SRPIPC                  '$18034'
 define  MCM_SRPMPC                  '$18038'
 define  OCCS_CTRL                   '$E2B0'
 define  OCCS_DIVBY                  '$E2B1'
 define  OCCS_STAT                   '$E2B2'
 define  OCCS_OSCTL1                 '$E2B4'
 define  OCCS_OSCTL2                 '$E2B5'
 define  OCCS_CLKCHKR                '$E2B6'
 define  OCCS_CLKCHKT                '$E2B7'
 define  OCCS_PROT                   '$E2B8'
 define  PIT0_CTRL                   '$E100'
 define  PIT0_MOD                    '$E101'
 define  PIT0_CNTR                   '$E102'
 define  PIT1_CTRL                   '$E110'
 define  PIT1_MOD                    '$E111'
 define  PIT1_CNTR                   '$E112'
 define  PMC_CTRL                    '$E2A0'
 define  PMC_STS                     '$E2A1'
 define  PWMA_SM0CNT                 '$E600'
 define  PWMA_SM0INIT                '$E601'
 define  PWMA_SM0CTRL2               '$E602'
 define  PWMA_SM0CTRL                '$E603'
 define  PWMA_SM0VAL0                '$E605'
 define  PWMA_SM0FRACVAL1            '$E606'
 define  PWMA_SM0VAL1                '$E607'
 define  PWMA_SM0FRACVAL2            '$E608'
 define  PWMA_SM0VAL2                '$E609'
 define  PWMA_SM0FRACVAL3            '$E60A'
 define  PWMA_SM0VAL3                '$E60B'
 define  PWMA_SM0FRACVAL4            '$E60C'
 define  PWMA_SM0VAL4                '$E60D'
 define  PWMA_SM0FRACVAL5            '$E60E'
 define  PWMA_SM0VAL5                '$E60F'
 define  PWMA_SM0FRCTRL              '$E610'
 define  PWMA_SM0OCTRL               '$E611'
 define  PWMA_SM0STS                 '$E612'
 define  PWMA_SM0INTEN               '$E613'
 define  PWMA_SM0DMAEN               '$E614'
 define  PWMA_SM0TCTRL               '$E615'
 define  PWMA_SM0DISMAP0             '$E616'
 define  PWMA_SM0DISMAP1             '$E617'
 define  PWMA_SM0DTCNT0              '$E618'
 define  PWMA_SM0DTCNT1              '$E619'
 define  PWMA_SM0CAPTCTRLA           '$E61A'
 define  PWMA_SM0CAPTCOMPA           '$E61B'
 define  PWMA_SM0CAPTCTRLB           '$E61C'
 define  PWMA_SM0CAPTCOMPB           '$E61D'
 define  PWMA_SM0CAPTCTRLX           '$E61E'
 define  PWMA_SM0CAPTCOMPX           '$E61F'
 define  PWMA_SM0CVAL0               '$E620'
 define  PWMA_SM0CVAL0CYC            '$E621'
 define  PWMA_SM0CVAL1               '$E622'
 define  PWMA_SM0CVAL1CYC            '$E623'
 define  PWMA_SM0CVAL2               '$E624'
 define  PWMA_SM0CVAL2CYC            '$E625'
 define  PWMA_SM0CVAL3               '$E626'
 define  PWMA_SM0CVAL3CYC            '$E627'
 define  PWMA_SM0CVAL4               '$E628'
 define  PWMA_SM0CVAL4CYC            '$E629'
 define  PWMA_SM0CVAL5               '$E62A'
 define  PWMA_SM0CVAL5CYC            '$E62B'
 define  PWMA_SM1CNT                 '$E630'
 define  PWMA_SM1INIT                '$E631'
 define  PWMA_SM1CTRL2               '$E632'
 define  PWMA_SM1CTRL                '$E633'
 define  PWMA_SM1VAL0                '$E635'
 define  PWMA_SM1FRACVAL1            '$E636'
 define  PWMA_SM1VAL1                '$E637'
 define  PWMA_SM1FRACVAL2            '$E638'
 define  PWMA_SM1VAL2                '$E639'
 define  PWMA_SM1FRACVAL3            '$E63A'
 define  PWMA_SM1VAL3                '$E63B'
 define  PWMA_SM1FRACVAL4            '$E63C'
 define  PWMA_SM1VAL4                '$E63D'
 define  PWMA_SM1FRACVAL5            '$E63E'
 define  PWMA_SM1VAL5                '$E63F'
 define  PWMA_SM1FRCTRL              '$E640'
 define  PWMA_SM1OCTRL               '$E641'
 define  PWMA_SM1STS                 '$E642'
 define  PWMA_SM1INTEN               '$E643'
 define  PWMA_SM1DMAEN               '$E644'
 define  PWMA_SM1TCTRL               '$E645'
 define  PWMA_SM1DISMAP0             '$E646'
 define  PWMA_SM1DISMAP1             '$E647'
 define  PWMA_SM1DTCNT0              '$E648'
 define  PWMA_SM1DTCNT1              '$E649'
 define  PWMA_SM1CAPTCTRLA           '$E64A'
 define  PWMA_SM1CAPTCOMPA           '$E64B'
 define  PWMA_SM1CAPTCTRLB           '$E64C'
 define  PWMA_SM1CAPTCOMPB           '$E64D'
 define  PWMA_SM1CAPTCTRLX           '$E64E'
 define  PWMA_SM1CAPTCOMPX           '$E64F'
 define  PWMA_SM1CVAL0               '$E650'
 define  PWMA_SM1CVAL0CYC            '$E651'
 define  PWMA_SM1CVAL1               '$E652'
 define  PWMA_SM1CVAL1CYC            '$E653'
 define  PWMA_SM1CVAL2               '$E654'
 define  PWMA_SM1CVAL2CYC            '$E655'
 define  PWMA_SM1CVAL3               '$E656'
 define  PWMA_SM1CVAL3CYC            '$E657'
 define  PWMA_SM1CVAL4               '$E658'
 define  PWMA_SM1CVAL4CYC            '$E659'
 define  PWMA_SM1CVAL5               '$E65A'
 define  PWMA_SM1CVAL5CYC            '$E65B'
 define  PWMA_SM2CNT                 '$E660'
 define  PWMA_SM2INIT                '$E661'
 define  PWMA_SM2CTRL2               '$E662'
 define  PWMA_SM2CTRL                '$E663'
 define  PWMA_SM2VAL0                '$E665'
 define  PWMA_SM2FRACVAL1            '$E666'
 define  PWMA_SM2VAL1                '$E667'
 define  PWMA_SM2FRACVAL2            '$E668'
 define  PWMA_SM2VAL2                '$E669'
 define  PWMA_SM2FRACVAL3            '$E66A'
 define  PWMA_SM2VAL3                '$E66B'
 define  PWMA_SM2FRACVAL4            '$E66C'
 define  PWMA_SM2VAL4                '$E66D'
 define  PWMA_SM2FRACVAL5            '$E66E'
 define  PWMA_SM2VAL5                '$E66F'
 define  PWMA_SM2FRCTRL              '$E670'
 define  PWMA_SM2OCTRL               '$E671'
 define  PWMA_SM2STS                 '$E672'
 define  PWMA_SM2INTEN               '$E673'
 define  PWMA_SM2DMAEN               '$E674'
 define  PWMA_SM2TCTRL               '$E675'
 define  PWMA_SM2DISMAP0             '$E676'
 define  PWMA_SM2DISMAP1             '$E677'
 define  PWMA_SM2DTCNT0              '$E678'
 define  PWMA_SM2DTCNT1              '$E679'
 define  PWMA_SM2CAPTCTRLA           '$E67A'
 define  PWMA_SM2CAPTCOMPA           '$E67B'
 define  PWMA_SM2CAPTCTRLB           '$E67C'
 define  PWMA_SM2CAPTCOMPB           '$E67D'
 define  PWMA_SM2CAPTCTRLX           '$E67E'
 define  PWMA_SM2CAPTCOMPX           '$E67F'
 define  PWMA_SM2CVAL0               '$E680'
 define  PWMA_SM2CVAL0CYC            '$E681'
 define  PWMA_SM2CVAL1               '$E682'
 define  PWMA_SM2CVAL1CYC            '$E683'
 define  PWMA_SM2CVAL2               '$E684'
 define  PWMA_SM2CVAL2CYC            '$E685'
 define  PWMA_SM2CVAL3               '$E686'
 define  PWMA_SM2CVAL3CYC            '$E687'
 define  PWMA_SM2CVAL4               '$E688'
 define  PWMA_SM2CVAL4CYC            '$E689'
 define  PWMA_SM2CVAL5               '$E68A'
 define  PWMA_SM2CVAL5CYC            '$E68B'
 define  PWMA_SM3CNT                 '$E690'
 define  PWMA_SM3INIT                '$E691'
 define  PWMA_SM3CTRL2               '$E692'
 define  PWMA_SM3CTRL                '$E693'
 define  PWMA_SM3VAL0                '$E695'
 define  PWMA_SM3FRACVAL1            '$E696'
 define  PWMA_SM3VAL1                '$E697'
 define  PWMA_SM3FRACVAL2            '$E698'
 define  PWMA_SM3VAL2                '$E699'
 define  PWMA_SM3FRACVAL3            '$E69A'
 define  PWMA_SM3VAL3                '$E69B'
 define  PWMA_SM3FRACVAL4            '$E69C'
 define  PWMA_SM3VAL4                '$E69D'
 define  PWMA_SM3FRACVAL5            '$E69E'
 define  PWMA_SM3VAL5                '$E69F'
 define  PWMA_SM3FRCTRL              '$E6A0'
 define  PWMA_SM3OCTRL               '$E6A1'
 define  PWMA_SM3STS                 '$E6A2'
 define  PWMA_SM3INTEN               '$E6A3'
 define  PWMA_SM3DMAEN               '$E6A4'
 define  PWMA_SM3TCTRL               '$E6A5'
 define  PWMA_SM3DISMAP0             '$E6A6'
 define  PWMA_SM3DISMAP1             '$E6A7'
 define  PWMA_SM3DTCNT0              '$E6A8'
 define  PWMA_SM3DTCNT1              '$E6A9'
 define  PWMA_SM3CAPTCTRLA           '$E6AA'
 define  PWMA_SM3CAPTCOMPA           '$E6AB'
 define  PWMA_SM3CAPTCTRLB           '$E6AC'
 define  PWMA_SM3CAPTCOMPB           '$E6AD'
 define  PWMA_SM3CAPTCTRLX           '$E6AE'
 define  PWMA_SM3CAPTCOMPX           '$E6AF'
 define  PWMA_SM3CVAL0               '$E6B0'
 define  PWMA_SM3CVAL0CYC            '$E6B1'
 define  PWMA_SM3CVAL1               '$E6B2'
 define  PWMA_SM3CVAL1CYC            '$E6B3'
 define  PWMA_SM3CVAL2               '$E6B4'
 define  PWMA_SM3CVAL2CYC            '$E6B5'
 define  PWMA_SM3CVAL3               '$E6B6'
 define  PWMA_SM3CVAL3CYC            '$E6B7'
 define  PWMA_SM3CVAL4               '$E6B8'
 define  PWMA_SM3CVAL4CYC            '$E6B9'
 define  PWMA_SM3CVAL5               '$E6BA'
 define  PWMA_SM3CVAL5CYC            '$E6BB'
 define  PWMA_OUTEN                  '$E6C0'
 define  PWMA_MASK                   '$E6C1'
 define  PWMA_SWCOUT                 '$E6C2'
 define  PWMA_DTSRCSEL               '$E6C3'
 define  PWMA_MCTRL                  '$E6C4'
 define  PWMA_MCTRL2                 '$E6C5'
 define  PWMA_FCTRL0                 '$E6C6'
 define  PWMA_FSTS0                  '$E6C7'
 define  PWMA_FFILT0                 '$E6C8'
 define  PWMA_FTST0                  '$E6C9'
 define  PWMA_FCTRL1                 '$E6CA'
 define  PWMA_FSTS1                  '$E6CB'
 define  PWMA_FFILT1                 '$E6CC'
 define  PWMA_FTST1                  '$E6CD'
 define  QSCI0_RATE                  '$E080'
 define  QSCI0_CTRL1                 '$E081'
 define  QSCI0_CTRL2                 '$E082'
 define  QSCI0_STAT                  '$E083'
 define  QSCI0_DATA                  '$E084'
 define  QSCI0_CTRL3                 '$E085'
 define  QSCI1_RATE                  '$E090'
 define  QSCI1_CTRL1                 '$E091'
 define  QSCI1_CTRL2                 '$E092'
 define  QSCI1_STAT                  '$E093'
 define  QSCI1_DATA                  '$E094'
 define  QSCI1_CTRL3                 '$E095'
 define  QSPI0_SPSCR                 '$E0B0'
 define  QSPI0_SPDSR                 '$E0B1'
 define  QSPI0_SPDRR                 '$E0B2'
 define  QSPI0_SPDTR                 '$E0B3'
 define  QSPI0_SPFIFO                '$E0B4'
 define  QSPI0_SPWAIT                '$E0B5'
 define  QSPI0_SPCTL2                '$E0B6'
 define  QSPI1_SPSCR                 '$E0C0'
 define  QSPI1_SPDSR                 '$E0C1'
 define  QSPI1_SPDRR                 '$E0C2'
 define  QSPI1_SPDTR                 '$E0C3'
 define  QSPI1_SPFIFO                '$E0C4'
 define  QSPI1_SPWAIT                '$E0C5'
 define  QSPI1_SPCTL2                '$E0C6'
 define  SIM_CTRL                    '$E400'
 define  SIM_RSTAT                   '$E401'
 define  SIM_MSHID                   '$E406'
 define  SIM_LSHID                   '$E407'
 define  SIM_PWR                     '$E408'
 define  SIM_CLKOUT                  '$E40A'
 define  SIM_PCR                     '$E40B'
 define  SIM_PCE0                    '$E40C'
 define  SIM_PCE1                    '$E40D'
 define  SIM_PCE2                    '$E40E'
 define  SIM_PCE3                    '$E40F'
 define  SIM_SD0                     '$E410'
 define  SIM_SD1                     '$E411'
 define  SIM_SD2                     '$E412'
 define  SIM_SD3                     '$E413'
 define  SIM_IOSAHI                  '$E414'
 define  SIM_IOSALO                  '$E415'
 define  SIM_PROT                    '$E416'
 define  SIM_GPSAL                   '$E417'
 define  SIM_GPSBL                   '$E418'
 define  SIM_GPSCL                   '$E419'
 define  SIM_GPSCH                   '$E41A'
 define  SIM_GPSEL                   '$E41C'
 define  SIM_GPSFL                   '$E41E'
 define  SIM_GPSFH                   '$E41F'
 define  SIM_IPSn                    '$E422'
 define  SIM_MISC0                   '$E423'
 define  SIM_PSWR0                   '$E424'
 define  SIM_PSWR1                   '$E425'
 define  SIM_PSWR2                   '$E426'
 define  SIM_PSWR3                   '$E427'
 define  SIM_PWRMODE                 '$E428'
 define  SIM_NVMOPT2H                '$E42C'
 define  SIM_NVMOPT2L                '$E42D'
 define  SIM_SCR0                    '$E445'
 define  SIM_SCR1                    '$E446'
 define  SIM_SCR2                    '$E447'
 define  SIM_SCR3                    '$E448'
 define  SIM_SCR4                    '$E449'
 define  SIM_SCR5                    '$E44A'
 define  SIM_SCR6                    '$E44B'
 define  SIM_SCR7                    '$E44C'
 define  TMR_0_COMP1                 '$E140'
 define  TMR_0_COMP2                 '$E141'
 define  TMR_0_CAPT                  '$E142'
 define  TMR_0_LOAD                  '$E143'
 define  TMR_0_HOLD                  '$E144'
 define  TMR_0_CNTR                  '$E145'
 define  TMR_0_CTRL                  '$E146'
 define  TMR_0_SCTRL                 '$E147'
 define  TMR_0_CMPLD1                '$E148'
 define  TMR_0_CMPLD2                '$E149'
 define  TMR_0_CSCTRL                '$E14A'
 define  TMR_0_FILT                  '$E14B'
 define  TMR_0_DMA                   '$E14C'
 define  TMR_0_ENBL                  '$E14F'
 define  TMR_1_COMP1                 '$E150'
 define  TMR_1_COMP2                 '$E151'
 define  TMR_1_CAPT                  '$E152'
 define  TMR_1_LOAD                  '$E153'
 define  TMR_1_HOLD                  '$E154'
 define  TMR_1_CNTR                  '$E155'
 define  TMR_1_CTRL                  '$E156'
 define  TMR_1_SCTRL                 '$E157'
 define  TMR_1_CMPLD1                '$E158'
 define  TMR_1_CMPLD2                '$E159'
 define  TMR_1_CSCTRL                '$E15A'
 define  TMR_1_FILT                  '$E15B'
 define  TMR_1_DMA                   '$E15C'
 define  TMR_2_COMP1                 '$E160'
 define  TMR_2_COMP2                 '$E161'
 define  TMR_2_CAPT                  '$E162'
 define  TMR_2_LOAD                  '$E163'
 define  TMR_2_HOLD                  '$E164'
 define  TMR_2_CNTR                  '$E165'
 define  TMR_2_CTRL                  '$E166'
 define  TMR_2_SCTRL                 '$E167'
 define  TMR_2_CMPLD1                '$E168'
 define  TMR_2_CMPLD2                '$E169'
 define  TMR_2_CSCTRL                '$E16A'
 define  TMR_2_FILT                  '$E16B'
 define  TMR_2_DMA                   '$E16C'
 define  TMR_3_COMP1                 '$E170'
 define  TMR_3_COMP2                 '$E171'
 define  TMR_3_CAPT                  '$E172'
 define  TMR_3_LOAD                  '$E173'
 define  TMR_3_HOLD                  '$E174'
 define  TMR_3_CNTR                  '$E175'
 define  TMR_3_CTRL                  '$E176'
 define  TMR_3_SCTRL                 '$E177'
 define  TMR_3_CMPLD1                '$E178'
 define  TMR_3_CMPLD2                '$E179'
 define  TMR_3_CSCTRL                '$E17A'
 define  TMR_3_FILT                  '$E17B'
 define  TMR_3_DMA                   '$E17C'
 define  XBARA_SEL0                  '$E340'
 define  XBARA_SEL1                  '$E341'
 define  XBARA_SEL2                  '$E342'
 define  XBARA_SEL3                  '$E343'
 define  XBARA_SEL4                  '$E344'
 define  XBARA_SEL5                  '$E345'
 define  XBARA_SEL6                  '$E346'
 define  XBARA_SEL7                  '$E347'
 define  XBARA_SEL8                  '$E348'
 define  XBARA_SEL9                  '$E349'
 define  XBARA_SEL10                 '$E34A'
 define  XBARA_SEL11                 '$E34B'
 define  XBARA_SEL12                 '$E34C'
 define  XBARA_SEL13                 '$E34D'
 define  XBARA_SEL14                 '$E34E'
 define  XBARA_SEL15                 '$E34F'
 define  XBARA_SEL16                 '$E350'
 define  XBARA_SEL17                 '$E351'
 define  XBARA_SEL18                 '$E352'
 define  XBARA_SEL19                 '$E353'
 define  XBARA_SEL20                 '$E354'
 define  XBARA_CTRL0                 '$E355'
 define  XBARA_CTRL1                 '$E356'
 define  XBARB_SEL0                  '$E360'
 define  XBARB_SEL1                  '$E361'
 define  XBARB_SEL2                  '$E362'
 define  XBARB_SEL3                  '$E363'
 define  XBARB_SEL4                  '$E364'
 define  XBARB_SEL5                  '$E365'
 define  XBARB_SEL6                  '$E366'
 define  XBARB_SEL7                  '$E367'
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; The following section defines the IO register bitfield locations and includes some commentary on the meaning of some settings.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 set     ADC_CTRL1_SMODE             (BIT0|BIT1|BIT2)
;;   ADC Scan Mode Control
;;     0b000 ==> Once (single) sequential
;;     0b001 ==> Once parallel
;;     0b010 ==> Loop sequential
;;     0b011 ==> Loop parallel
;;     0b100 ==> Triggered sequential
;;     0b101 ==> Triggered parallel (default)
;;     0b11x ==> Reserved
 set     ADC_CTRL1_SMODE_0           BIT0
 set     ADC_CTRL1_SMODE_1           BIT1
 set     ADC_CTRL1_SMODE_2           BIT2

 set     ADC_CTRL1_CHNCFG_L          (BIT4|BIT5|BIT6|BIT7)
;;   CHCNF (Channel Configure Low) bits
;;     0bxxx1 ==> Inputs = ANA0-ANA1
;;     0bxxx0 ==> Inputs = ANA0-ANA1
;;     0bxx1x ==> Inputs = ANA2-ANA3
;;     0bxx0x ==> Inputs = ANA2-ANA3
;;     0bx1xx ==> Inputs = ANB0-ANB1
;;     0bx0xx ==> Inputs = ANB0-ANB1
;;     0b1xxx ==> Inputs = ANB2-ANB3
 set     ADC_CTRL1_CHNCFG_L_0        BIT4
 set     ADC_CTRL1_CHNCFG_L_1        BIT5
 set     ADC_CTRL1_CHNCFG_L_2        BIT6
 set     ADC_CTRL1_CHNCFG_L_3        BIT7

 set     ADC_CTRL1_HLMTIE            BIT8
;;   High Limit Interrupt Enable
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     ADC_CTRL1_LLMTIE            BIT9
;;   Low Limit Interrupt Enable
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     ADC_CTRL1_ZCIE              BIT10
;;   Zero Crossing Interrupt Enable
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     ADC_CTRL1_EOSIE0            BIT11
;;   End Of Scan Interrupt Enable
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     ADC_CTRL1_SYNC0             BIT12
;;   SYNC0 Enable
;;     0b0 ==> Scan is initiated by a write to CTRL1[START0] only
;;     0b1 ==> Use a SYNC0 input pulse or CTRL1[START0] to initiate a scan

 set     ADC_CTRL1_START0            BIT13
;;   START0 Conversion
;;     0b0 ==> No action
;;     0b1 ==> Start command is issued

 set     ADC_CTRL1_STOP0             BIT14
;;   Stop
;;     0b0 ==> Normal operation
;;     0b1 ==> Stop mode

 set     ADC_CTRL1_DMAEN0            BIT15
;;   DMA enable
;;     0b0 ==> DMA is not enabled.
;;     0b1 ==> DMA is enabled.

 set     ADC_CTRL2_DIV0              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Clock Divisor Select
 set     ADC_CTRL2_DIV0_0            BIT0
 set     ADC_CTRL2_DIV0_1            BIT1
 set     ADC_CTRL2_DIV0_2            BIT2
 set     ADC_CTRL2_DIV0_3            BIT3
 set     ADC_CTRL2_DIV0_4            BIT4
 set     ADC_CTRL2_DIV0_5            BIT5

 set     ADC_CTRL2_SIMULT            BIT6
;;   Simultaneous mode
;;     0b0 ==> Parallel scans done independently
;;     0b1 ==> Parallel scans done simultaneously (default)

 set     ADC_CTRL2_CHNCFG_H          (BIT7|BIT8|BIT9|BIT10)
;;   CHCNF (Channel Configure High) bits
;;     0bxxx1 ==> Inputs = ANA4-ANA5
;;     0bxxx0 ==> Inputs = ANA4-ANA5
;;     0bxx1x ==> Inputs = ANA6-ANA7
;;     0bxx0x ==> Inputs = ANA6-ANA7
;;     0bx1xx ==> Inputs = ANB4-ANB5
;;     0bx0xx ==> Inputs = ANB4-ANB5
;;     0b1xxx ==> Inputs = ANB6-ANB7
 set     ADC_CTRL2_CHNCFG_H_0        BIT7
 set     ADC_CTRL2_CHNCFG_H_1        BIT8
 set     ADC_CTRL2_CHNCFG_H_2        BIT9
 set     ADC_CTRL2_CHNCFG_H_3        BIT10

 set     ADC_CTRL2_EOSIE1            BIT11
;;   End Of Scan Interrupt Enable
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     ADC_CTRL2_SYNC1             BIT12
;;   SYNC1 Enable
;;     0b0 ==> B converter parallel scan is initiated by a write to CTRL2[START1] bit only
;;     0b1 ==> Use a SYNC1 input pulse or CTRL2[START1] bit to initiate a B converter parallel scan

 set     ADC_CTRL2_START1            BIT13
;;   START1 Conversion
;;     0b0 ==> No action
;;     0b1 ==> Start command is issued

 set     ADC_CTRL2_STOP1             BIT14
;;   Stop
;;     0b0 ==> Normal operation
;;     0b1 ==> Stop mode

 set     ADC_CTRL2_DMAEN1            BIT15
;;   DMA enable
;;     0b0 ==> DMA is not enabled.
;;     0b1 ==> DMA is enabled.

 set     ADC_ZXCTRL1_ZCE0            (BIT0|BIT1)
;;   Zero crossing enable 0
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL1_ZCE0_0          BIT0
 set     ADC_ZXCTRL1_ZCE0_1          BIT1

 set     ADC_ZXCTRL1_ZCE1            (BIT2|BIT3)
;;   Zero crossing enable 1
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL1_ZCE1_0          BIT2
 set     ADC_ZXCTRL1_ZCE1_1          BIT3

 set     ADC_ZXCTRL1_ZCE2            (BIT4|BIT5)
;;   Zero crossing enable 2
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL1_ZCE2_0          BIT4
 set     ADC_ZXCTRL1_ZCE2_1          BIT5

 set     ADC_ZXCTRL1_ZCE3            (BIT6|BIT7)
;;   Zero crossing enable 3
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL1_ZCE3_0          BIT6
 set     ADC_ZXCTRL1_ZCE3_1          BIT7

 set     ADC_ZXCTRL1_ZCE4            (BIT8|BIT9)
;;   Zero crossing enable 4
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL1_ZCE4_0          BIT8
 set     ADC_ZXCTRL1_ZCE4_1          BIT9

 set     ADC_ZXCTRL1_ZCE5            (BIT10|BIT11)
;;   Zero crossing enable 5
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL1_ZCE5_0          BIT10
 set     ADC_ZXCTRL1_ZCE5_1          BIT11

 set     ADC_ZXCTRL1_ZCE6            (BIT12|BIT13)
;;   Zero crossing enable 6
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL1_ZCE6_0          BIT12
 set     ADC_ZXCTRL1_ZCE6_1          BIT13

 set     ADC_ZXCTRL1_ZCE7            (BIT14|BIT15)
;;   Zero crossing enable 7
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL1_ZCE7_0          BIT14
 set     ADC_ZXCTRL1_ZCE7_1          BIT15

 set     ADC_ZXCTRL2_ZCE8            (BIT0|BIT1)
;;   Zero crossing enable 8
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL2_ZCE8_0          BIT0
 set     ADC_ZXCTRL2_ZCE8_1          BIT1

 set     ADC_ZXCTRL2_ZCE9            (BIT2|BIT3)
;;   Zero crossing enable 9
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL2_ZCE9_0          BIT2
 set     ADC_ZXCTRL2_ZCE9_1          BIT3

 set     ADC_ZXCTRL2_ZCE10           (BIT4|BIT5)
;;   Zero crossing enable 10
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL2_ZCE10_0         BIT4
 set     ADC_ZXCTRL2_ZCE10_1         BIT5

 set     ADC_ZXCTRL2_ZCE11           (BIT6|BIT7)
;;   Zero crossing enable 11
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL2_ZCE11_0         BIT6
 set     ADC_ZXCTRL2_ZCE11_1         BIT7

 set     ADC_ZXCTRL2_ZCE12           (BIT8|BIT9)
;;   Zero crossing enable 12
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL2_ZCE12_0         BIT8
 set     ADC_ZXCTRL2_ZCE12_1         BIT9

 set     ADC_ZXCTRL2_ZCE13           (BIT10|BIT11)
;;   Zero crossing enable 13
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL2_ZCE13_0         BIT10
 set     ADC_ZXCTRL2_ZCE13_1         BIT11

 set     ADC_ZXCTRL2_ZCE14           (BIT12|BIT13)
;;   Zero crossing enable 14
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL2_ZCE14_0         BIT12
 set     ADC_ZXCTRL2_ZCE14_1         BIT13

 set     ADC_ZXCTRL2_ZCE15           (BIT14|BIT15)
;;   Zero crossing enable 15
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL2_ZCE15_0         BIT14
 set     ADC_ZXCTRL2_ZCE15_1         BIT15

 set     ADC_CLIST1_SAMPLE0          (BIT0|BIT1|BIT2|BIT3)
;;   Sample Field 0
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST1_SAMPLE0_0        BIT0
 set     ADC_CLIST1_SAMPLE0_1        BIT1
 set     ADC_CLIST1_SAMPLE0_2        BIT2
 set     ADC_CLIST1_SAMPLE0_3        BIT3

 set     ADC_CLIST1_SAMPLE1          (BIT4|BIT5|BIT6|BIT7)
;;   Sample Field 1
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST1_SAMPLE1_0        BIT4
 set     ADC_CLIST1_SAMPLE1_1        BIT5
 set     ADC_CLIST1_SAMPLE1_2        BIT6
 set     ADC_CLIST1_SAMPLE1_3        BIT7

 set     ADC_CLIST1_SAMPLE2          (BIT8|BIT9|BIT10|BIT11)
;;   Sample Field 2
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST1_SAMPLE2_0        BIT8
 set     ADC_CLIST1_SAMPLE2_1        BIT9
 set     ADC_CLIST1_SAMPLE2_2        BIT10
 set     ADC_CLIST1_SAMPLE2_3        BIT11

 set     ADC_CLIST1_SAMPLE3          (BIT12|BIT13|BIT14|BIT15)
;;   Sample Field 3
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST1_SAMPLE3_0        BIT12
 set     ADC_CLIST1_SAMPLE3_1        BIT13
 set     ADC_CLIST1_SAMPLE3_2        BIT14
 set     ADC_CLIST1_SAMPLE3_3        BIT15

 set     ADC_CLIST2_SAMPLE4          (BIT0|BIT1|BIT2|BIT3)
;;   Sample Field 4
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST2_SAMPLE4_0        BIT0
 set     ADC_CLIST2_SAMPLE4_1        BIT1
 set     ADC_CLIST2_SAMPLE4_2        BIT2
 set     ADC_CLIST2_SAMPLE4_3        BIT3

 set     ADC_CLIST2_SAMPLE5          (BIT4|BIT5|BIT6|BIT7)
;;   Sample Field 5
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST2_SAMPLE5_0        BIT4
 set     ADC_CLIST2_SAMPLE5_1        BIT5
 set     ADC_CLIST2_SAMPLE5_2        BIT6
 set     ADC_CLIST2_SAMPLE5_3        BIT7

 set     ADC_CLIST2_SAMPLE6          (BIT8|BIT9|BIT10|BIT11)
;;   Sample Field 6
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST2_SAMPLE6_0        BIT8
 set     ADC_CLIST2_SAMPLE6_1        BIT9
 set     ADC_CLIST2_SAMPLE6_2        BIT10
 set     ADC_CLIST2_SAMPLE6_3        BIT11

 set     ADC_CLIST2_SAMPLE7          (BIT12|BIT13|BIT14|BIT15)
;;   Sample Field 7
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST2_SAMPLE7_0        BIT12
 set     ADC_CLIST2_SAMPLE7_1        BIT13
 set     ADC_CLIST2_SAMPLE7_2        BIT14
 set     ADC_CLIST2_SAMPLE7_3        BIT15

 set     ADC_CLIST3_SAMPLE8          (BIT0|BIT1|BIT2|BIT3)
;;   Sample Field 8
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST3_SAMPLE8_0        BIT0
 set     ADC_CLIST3_SAMPLE8_1        BIT1
 set     ADC_CLIST3_SAMPLE8_2        BIT2
 set     ADC_CLIST3_SAMPLE8_3        BIT3

 set     ADC_CLIST3_SAMPLE9          (BIT4|BIT5|BIT6|BIT7)
;;   Sample Field 9
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST3_SAMPLE9_0        BIT4
 set     ADC_CLIST3_SAMPLE9_1        BIT5
 set     ADC_CLIST3_SAMPLE9_2        BIT6
 set     ADC_CLIST3_SAMPLE9_3        BIT7

 set     ADC_CLIST3_SAMPLE10         (BIT8|BIT9|BIT10|BIT11)
;;   Sample Field 10
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST3_SAMPLE10_0       BIT8
 set     ADC_CLIST3_SAMPLE10_1       BIT9
 set     ADC_CLIST3_SAMPLE10_2       BIT10
 set     ADC_CLIST3_SAMPLE10_3       BIT11

 set     ADC_CLIST3_SAMPLE11         (BIT12|BIT13|BIT14|BIT15)
;;   Sample Field 11
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST3_SAMPLE11_0       BIT12
 set     ADC_CLIST3_SAMPLE11_1       BIT13
 set     ADC_CLIST3_SAMPLE11_2       BIT14
 set     ADC_CLIST3_SAMPLE11_3       BIT15

 set     ADC_CLIST4_SAMPLE12         (BIT0|BIT1|BIT2|BIT3)
;;   Sample Field 12
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST4_SAMPLE12_0       BIT0
 set     ADC_CLIST4_SAMPLE12_1       BIT1
 set     ADC_CLIST4_SAMPLE12_2       BIT2
 set     ADC_CLIST4_SAMPLE12_3       BIT3

 set     ADC_CLIST4_SAMPLE13         (BIT4|BIT5|BIT6|BIT7)
;;   Sample Field 13
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST4_SAMPLE13_0       BIT4
 set     ADC_CLIST4_SAMPLE13_1       BIT5
 set     ADC_CLIST4_SAMPLE13_2       BIT6
 set     ADC_CLIST4_SAMPLE13_3       BIT7

 set     ADC_CLIST4_SAMPLE14         (BIT8|BIT9|BIT10|BIT11)
;;   Sample Field 14
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST4_SAMPLE14_0       BIT8
 set     ADC_CLIST4_SAMPLE14_1       BIT9
 set     ADC_CLIST4_SAMPLE14_2       BIT10
 set     ADC_CLIST4_SAMPLE14_3       BIT11

 set     ADC_CLIST4_SAMPLE15         (BIT12|BIT13|BIT14|BIT15)
;;   Sample Field 15
;;     0b0000 ==> Single Ended: ANA0, Differential: ANA0+, ANA1-
;;     0b0001 ==> Single Ended: ANA1, Differential: ANA0+, ANA1-
;;     0b0010 ==> Single Ended: ANA2, Differential: ANA2+, ANA3-
;;     0b0011 ==> Single Ended: ANA3, Differential: ANA2+, ANA3-
;;     0b0100 ==> Single Ended: ANA4, Differential: ANA4+, ANA5-
;;     0b0101 ==> Single Ended: ANA5, Differential: ANA4+, ANA5-
;;     0b0110 ==> Single Ended: ANA6, Differential: ANA6+, ANA7-
;;     0b0111 ==> Single Ended: ANA7, Differential: ANA6+, ANA7-
;;     0b1000 ==> Single Ended: ANB0, Differential: ANB0+, ANB1-
;;     0b1001 ==> Single Ended: ANB1, Differential: ANB0+, ANB1-
;;     0b1010 ==> Single Ended: ANB2, Differential: ANB2+, ANB3-
;;     0b1011 ==> Single Ended: ANB3, Differential: ANB2+, ANB3-
;;     0b1100 ==> Single Ended: ANB4, Differential: ANB4+, ANB5-
;;     0b1101 ==> Single Ended: ANB5, Differential: ANB4+, ANB5-
;;     0b1110 ==> Single Ended: ANB6, Differential: ANB6+, ANB7-
;;     0b1111 ==> Single Ended: ANB7, Differential: ANB6+, ANB7-
 set     ADC_CLIST4_SAMPLE15_0       BIT12
 set     ADC_CLIST4_SAMPLE15_1       BIT13
 set     ADC_CLIST4_SAMPLE15_2       BIT14
 set     ADC_CLIST4_SAMPLE15_3       BIT15

 set     ADC_SDIS_DS                 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Disable Sample Bits
;;     0b0 ==> Enable CLIST*[SAMPLEx].
;;     0b1 ==> Disable CLIST*[SAMPLEx] and all subsequent samples. Which samples are actually disabled will depend on the conversion mode, sequential/parallel, and the value of CTRL2[SIMULT].
 set     ADC_SDIS_DS_0               BIT0
 set     ADC_SDIS_DS_1               BIT1
 set     ADC_SDIS_DS_2               BIT2
 set     ADC_SDIS_DS_3               BIT3
 set     ADC_SDIS_DS_4               BIT4
 set     ADC_SDIS_DS_5               BIT5
 set     ADC_SDIS_DS_6               BIT6
 set     ADC_SDIS_DS_7               BIT7
 set     ADC_SDIS_DS_8               BIT8
 set     ADC_SDIS_DS_9               BIT9
 set     ADC_SDIS_DS_10              BIT10
 set     ADC_SDIS_DS_11              BIT11
 set     ADC_SDIS_DS_12              BIT12
 set     ADC_SDIS_DS_13              BIT13
 set     ADC_SDIS_DS_14              BIT14
 set     ADC_SDIS_DS_15              BIT15

 set     ADC_STAT_UNDEFINED          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     ADC_STAT_UNDEFINED_0        BIT0
 set     ADC_STAT_UNDEFINED_1        BIT1
 set     ADC_STAT_UNDEFINED_2        BIT2
 set     ADC_STAT_UNDEFINED_3        BIT3
 set     ADC_STAT_UNDEFINED_4        BIT4
 set     ADC_STAT_UNDEFINED_5        BIT5
 set     ADC_STAT_UNDEFINED_6        BIT6
 set     ADC_STAT_UNDEFINED_7        BIT7

 set     ADC_STAT_HLMTI              BIT8
;;   High Limit Interrupt
;;     0b0 ==> No high limit interrupt request
;;     0b1 ==> High limit exceeded, IRQ pending if CTRL1[HLMTIE] is set

 set     ADC_STAT_LLMTI              BIT9
;;   Low Limit Interrupt
;;     0b0 ==> No low limit interrupt request
;;     0b1 ==> Low limit exceeded, IRQ pending if CTRL1[LLMTIE] is set

 set     ADC_STAT_ZCI                BIT10
;;   Zero Crossing Interrupt
;;     0b0 ==> No zero crossing interrupt request
;;     0b1 ==> Zero crossing encountered, IRQ pending if CTRL1[ZCIE] is set

 set     ADC_STAT_EOSI0              BIT11
;;   End of Scan Interrupt
;;     0b0 ==> A scan cycle has not been completed, no end of scan IRQ pending
;;     0b1 ==> A scan cycle has been completed, end of scan IRQ pending

 set     ADC_STAT_EOSI1              BIT12
;;   End of Scan Interrupt
;;     0b0 ==> A scan cycle has not been completed, no end of scan IRQ pending
;;     0b1 ==> A scan cycle has been completed, end of scan IRQ pending

 set     ADC_STAT_CIP1               BIT14
;;   Conversion in Progress
;;     0b0 ==> Idle state
;;     0b1 ==> A scan cycle is in progress. The ADC will ignore all sync pulses or start commands

 set     ADC_STAT_CIP0               BIT15
;;   Conversion in Progress
;;     0b0 ==> Idle state
;;     0b1 ==> A scan cycle is in progress. The ADC will ignore all sync pulses or start commands

 set     ADC_RDY_RDY                 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Ready Sample
;;     0b0 ==> Sample not ready or has been read
;;     0b1 ==> Sample ready to be read
 set     ADC_RDY_RDY_0               BIT0
 set     ADC_RDY_RDY_1               BIT1
 set     ADC_RDY_RDY_2               BIT2
 set     ADC_RDY_RDY_3               BIT3
 set     ADC_RDY_RDY_4               BIT4
 set     ADC_RDY_RDY_5               BIT5
 set     ADC_RDY_RDY_6               BIT6
 set     ADC_RDY_RDY_7               BIT7
 set     ADC_RDY_RDY_8               BIT8
 set     ADC_RDY_RDY_9               BIT9
 set     ADC_RDY_RDY_10              BIT10
 set     ADC_RDY_RDY_11              BIT11
 set     ADC_RDY_RDY_12              BIT12
 set     ADC_RDY_RDY_13              BIT13
 set     ADC_RDY_RDY_14              BIT14
 set     ADC_RDY_RDY_15              BIT15

 set     ADC_LOLIMSTAT_LLS           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Low Limit Status Bits
 set     ADC_LOLIMSTAT_LLS_0         BIT0
 set     ADC_LOLIMSTAT_LLS_1         BIT1
 set     ADC_LOLIMSTAT_LLS_2         BIT2
 set     ADC_LOLIMSTAT_LLS_3         BIT3
 set     ADC_LOLIMSTAT_LLS_4         BIT4
 set     ADC_LOLIMSTAT_LLS_5         BIT5
 set     ADC_LOLIMSTAT_LLS_6         BIT6
 set     ADC_LOLIMSTAT_LLS_7         BIT7
 set     ADC_LOLIMSTAT_LLS_8         BIT8
 set     ADC_LOLIMSTAT_LLS_9         BIT9
 set     ADC_LOLIMSTAT_LLS_10        BIT10
 set     ADC_LOLIMSTAT_LLS_11        BIT11
 set     ADC_LOLIMSTAT_LLS_12        BIT12
 set     ADC_LOLIMSTAT_LLS_13        BIT13
 set     ADC_LOLIMSTAT_LLS_14        BIT14
 set     ADC_LOLIMSTAT_LLS_15        BIT15

 set     ADC_HILIMSTAT_HLS           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   High Limit Status Bits
 set     ADC_HILIMSTAT_HLS_0         BIT0
 set     ADC_HILIMSTAT_HLS_1         BIT1
 set     ADC_HILIMSTAT_HLS_2         BIT2
 set     ADC_HILIMSTAT_HLS_3         BIT3
 set     ADC_HILIMSTAT_HLS_4         BIT4
 set     ADC_HILIMSTAT_HLS_5         BIT5
 set     ADC_HILIMSTAT_HLS_6         BIT6
 set     ADC_HILIMSTAT_HLS_7         BIT7
 set     ADC_HILIMSTAT_HLS_8         BIT8
 set     ADC_HILIMSTAT_HLS_9         BIT9
 set     ADC_HILIMSTAT_HLS_10        BIT10
 set     ADC_HILIMSTAT_HLS_11        BIT11
 set     ADC_HILIMSTAT_HLS_12        BIT12
 set     ADC_HILIMSTAT_HLS_13        BIT13
 set     ADC_HILIMSTAT_HLS_14        BIT14
 set     ADC_HILIMSTAT_HLS_15        BIT15

 set     ADC_ZXSTAT_ZCS              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Zero Crossing Status
;;     0b0 ==> Either: A sign change did not occur in a comparison between the current channelx result and the previous channelx result, or Zero crossing control is disabled for channelx in the zero crossing control register, ZXCTRL
;;     0b1 ==> In a comparison between the current channelx result and the previous channelx result, a sign change condition occurred as defined in the zero crossing control register (ZXCTRL)
 set     ADC_ZXSTAT_ZCS_0            BIT0
 set     ADC_ZXSTAT_ZCS_1            BIT1
 set     ADC_ZXSTAT_ZCS_2            BIT2
 set     ADC_ZXSTAT_ZCS_3            BIT3
 set     ADC_ZXSTAT_ZCS_4            BIT4
 set     ADC_ZXSTAT_ZCS_5            BIT5
 set     ADC_ZXSTAT_ZCS_6            BIT6
 set     ADC_ZXSTAT_ZCS_7            BIT7
 set     ADC_ZXSTAT_ZCS_8            BIT8
 set     ADC_ZXSTAT_ZCS_9            BIT9
 set     ADC_ZXSTAT_ZCS_10           BIT10
 set     ADC_ZXSTAT_ZCS_11           BIT11
 set     ADC_ZXSTAT_ZCS_12           BIT12
 set     ADC_ZXSTAT_ZCS_13           BIT13
 set     ADC_ZXSTAT_ZCS_14           BIT14
 set     ADC_ZXSTAT_ZCS_15           BIT15

 set     ADC_RSLT0_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT0_RSLT_0            BIT3
 set     ADC_RSLT0_RSLT_1            BIT4
 set     ADC_RSLT0_RSLT_2            BIT5
 set     ADC_RSLT0_RSLT_3            BIT6
 set     ADC_RSLT0_RSLT_4            BIT7
 set     ADC_RSLT0_RSLT_5            BIT8
 set     ADC_RSLT0_RSLT_6            BIT9
 set     ADC_RSLT0_RSLT_7            BIT10
 set     ADC_RSLT0_RSLT_8            BIT11
 set     ADC_RSLT0_RSLT_9            BIT12
 set     ADC_RSLT0_RSLT_10           BIT13
 set     ADC_RSLT0_RSLT_11           BIT14

 set     ADC_RSLT0_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT1_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT1_RSLT_0            BIT3
 set     ADC_RSLT1_RSLT_1            BIT4
 set     ADC_RSLT1_RSLT_2            BIT5
 set     ADC_RSLT1_RSLT_3            BIT6
 set     ADC_RSLT1_RSLT_4            BIT7
 set     ADC_RSLT1_RSLT_5            BIT8
 set     ADC_RSLT1_RSLT_6            BIT9
 set     ADC_RSLT1_RSLT_7            BIT10
 set     ADC_RSLT1_RSLT_8            BIT11
 set     ADC_RSLT1_RSLT_9            BIT12
 set     ADC_RSLT1_RSLT_10           BIT13
 set     ADC_RSLT1_RSLT_11           BIT14

 set     ADC_RSLT1_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT2_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT2_RSLT_0            BIT3
 set     ADC_RSLT2_RSLT_1            BIT4
 set     ADC_RSLT2_RSLT_2            BIT5
 set     ADC_RSLT2_RSLT_3            BIT6
 set     ADC_RSLT2_RSLT_4            BIT7
 set     ADC_RSLT2_RSLT_5            BIT8
 set     ADC_RSLT2_RSLT_6            BIT9
 set     ADC_RSLT2_RSLT_7            BIT10
 set     ADC_RSLT2_RSLT_8            BIT11
 set     ADC_RSLT2_RSLT_9            BIT12
 set     ADC_RSLT2_RSLT_10           BIT13
 set     ADC_RSLT2_RSLT_11           BIT14

 set     ADC_RSLT2_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT3_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT3_RSLT_0            BIT3
 set     ADC_RSLT3_RSLT_1            BIT4
 set     ADC_RSLT3_RSLT_2            BIT5
 set     ADC_RSLT3_RSLT_3            BIT6
 set     ADC_RSLT3_RSLT_4            BIT7
 set     ADC_RSLT3_RSLT_5            BIT8
 set     ADC_RSLT3_RSLT_6            BIT9
 set     ADC_RSLT3_RSLT_7            BIT10
 set     ADC_RSLT3_RSLT_8            BIT11
 set     ADC_RSLT3_RSLT_9            BIT12
 set     ADC_RSLT3_RSLT_10           BIT13
 set     ADC_RSLT3_RSLT_11           BIT14

 set     ADC_RSLT3_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT4_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT4_RSLT_0            BIT3
 set     ADC_RSLT4_RSLT_1            BIT4
 set     ADC_RSLT4_RSLT_2            BIT5
 set     ADC_RSLT4_RSLT_3            BIT6
 set     ADC_RSLT4_RSLT_4            BIT7
 set     ADC_RSLT4_RSLT_5            BIT8
 set     ADC_RSLT4_RSLT_6            BIT9
 set     ADC_RSLT4_RSLT_7            BIT10
 set     ADC_RSLT4_RSLT_8            BIT11
 set     ADC_RSLT4_RSLT_9            BIT12
 set     ADC_RSLT4_RSLT_10           BIT13
 set     ADC_RSLT4_RSLT_11           BIT14

 set     ADC_RSLT4_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT5_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT5_RSLT_0            BIT3
 set     ADC_RSLT5_RSLT_1            BIT4
 set     ADC_RSLT5_RSLT_2            BIT5
 set     ADC_RSLT5_RSLT_3            BIT6
 set     ADC_RSLT5_RSLT_4            BIT7
 set     ADC_RSLT5_RSLT_5            BIT8
 set     ADC_RSLT5_RSLT_6            BIT9
 set     ADC_RSLT5_RSLT_7            BIT10
 set     ADC_RSLT5_RSLT_8            BIT11
 set     ADC_RSLT5_RSLT_9            BIT12
 set     ADC_RSLT5_RSLT_10           BIT13
 set     ADC_RSLT5_RSLT_11           BIT14

 set     ADC_RSLT5_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT6_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT6_RSLT_0            BIT3
 set     ADC_RSLT6_RSLT_1            BIT4
 set     ADC_RSLT6_RSLT_2            BIT5
 set     ADC_RSLT6_RSLT_3            BIT6
 set     ADC_RSLT6_RSLT_4            BIT7
 set     ADC_RSLT6_RSLT_5            BIT8
 set     ADC_RSLT6_RSLT_6            BIT9
 set     ADC_RSLT6_RSLT_7            BIT10
 set     ADC_RSLT6_RSLT_8            BIT11
 set     ADC_RSLT6_RSLT_9            BIT12
 set     ADC_RSLT6_RSLT_10           BIT13
 set     ADC_RSLT6_RSLT_11           BIT14

 set     ADC_RSLT6_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT7_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT7_RSLT_0            BIT3
 set     ADC_RSLT7_RSLT_1            BIT4
 set     ADC_RSLT7_RSLT_2            BIT5
 set     ADC_RSLT7_RSLT_3            BIT6
 set     ADC_RSLT7_RSLT_4            BIT7
 set     ADC_RSLT7_RSLT_5            BIT8
 set     ADC_RSLT7_RSLT_6            BIT9
 set     ADC_RSLT7_RSLT_7            BIT10
 set     ADC_RSLT7_RSLT_8            BIT11
 set     ADC_RSLT7_RSLT_9            BIT12
 set     ADC_RSLT7_RSLT_10           BIT13
 set     ADC_RSLT7_RSLT_11           BIT14

 set     ADC_RSLT7_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT8_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT8_RSLT_0            BIT3
 set     ADC_RSLT8_RSLT_1            BIT4
 set     ADC_RSLT8_RSLT_2            BIT5
 set     ADC_RSLT8_RSLT_3            BIT6
 set     ADC_RSLT8_RSLT_4            BIT7
 set     ADC_RSLT8_RSLT_5            BIT8
 set     ADC_RSLT8_RSLT_6            BIT9
 set     ADC_RSLT8_RSLT_7            BIT10
 set     ADC_RSLT8_RSLT_8            BIT11
 set     ADC_RSLT8_RSLT_9            BIT12
 set     ADC_RSLT8_RSLT_10           BIT13
 set     ADC_RSLT8_RSLT_11           BIT14

 set     ADC_RSLT8_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT9_RSLT              (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT9_RSLT_0            BIT3
 set     ADC_RSLT9_RSLT_1            BIT4
 set     ADC_RSLT9_RSLT_2            BIT5
 set     ADC_RSLT9_RSLT_3            BIT6
 set     ADC_RSLT9_RSLT_4            BIT7
 set     ADC_RSLT9_RSLT_5            BIT8
 set     ADC_RSLT9_RSLT_6            BIT9
 set     ADC_RSLT9_RSLT_7            BIT10
 set     ADC_RSLT9_RSLT_8            BIT11
 set     ADC_RSLT9_RSLT_9            BIT12
 set     ADC_RSLT9_RSLT_10           BIT13
 set     ADC_RSLT9_RSLT_11           BIT14

 set     ADC_RSLT9_SEXT              BIT15
;;   Sign Extend

 set     ADC_RSLT10_RSLT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT10_RSLT_0           BIT3
 set     ADC_RSLT10_RSLT_1           BIT4
 set     ADC_RSLT10_RSLT_2           BIT5
 set     ADC_RSLT10_RSLT_3           BIT6
 set     ADC_RSLT10_RSLT_4           BIT7
 set     ADC_RSLT10_RSLT_5           BIT8
 set     ADC_RSLT10_RSLT_6           BIT9
 set     ADC_RSLT10_RSLT_7           BIT10
 set     ADC_RSLT10_RSLT_8           BIT11
 set     ADC_RSLT10_RSLT_9           BIT12
 set     ADC_RSLT10_RSLT_10          BIT13
 set     ADC_RSLT10_RSLT_11          BIT14

 set     ADC_RSLT10_SEXT             BIT15
;;   Sign Extend

 set     ADC_RSLT11_RSLT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT11_RSLT_0           BIT3
 set     ADC_RSLT11_RSLT_1           BIT4
 set     ADC_RSLT11_RSLT_2           BIT5
 set     ADC_RSLT11_RSLT_3           BIT6
 set     ADC_RSLT11_RSLT_4           BIT7
 set     ADC_RSLT11_RSLT_5           BIT8
 set     ADC_RSLT11_RSLT_6           BIT9
 set     ADC_RSLT11_RSLT_7           BIT10
 set     ADC_RSLT11_RSLT_8           BIT11
 set     ADC_RSLT11_RSLT_9           BIT12
 set     ADC_RSLT11_RSLT_10          BIT13
 set     ADC_RSLT11_RSLT_11          BIT14

 set     ADC_RSLT11_SEXT             BIT15
;;   Sign Extend

 set     ADC_RSLT12_RSLT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT12_RSLT_0           BIT3
 set     ADC_RSLT12_RSLT_1           BIT4
 set     ADC_RSLT12_RSLT_2           BIT5
 set     ADC_RSLT12_RSLT_3           BIT6
 set     ADC_RSLT12_RSLT_4           BIT7
 set     ADC_RSLT12_RSLT_5           BIT8
 set     ADC_RSLT12_RSLT_6           BIT9
 set     ADC_RSLT12_RSLT_7           BIT10
 set     ADC_RSLT12_RSLT_8           BIT11
 set     ADC_RSLT12_RSLT_9           BIT12
 set     ADC_RSLT12_RSLT_10          BIT13
 set     ADC_RSLT12_RSLT_11          BIT14

 set     ADC_RSLT12_SEXT             BIT15
;;   Sign Extend

 set     ADC_RSLT13_RSLT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT13_RSLT_0           BIT3
 set     ADC_RSLT13_RSLT_1           BIT4
 set     ADC_RSLT13_RSLT_2           BIT5
 set     ADC_RSLT13_RSLT_3           BIT6
 set     ADC_RSLT13_RSLT_4           BIT7
 set     ADC_RSLT13_RSLT_5           BIT8
 set     ADC_RSLT13_RSLT_6           BIT9
 set     ADC_RSLT13_RSLT_7           BIT10
 set     ADC_RSLT13_RSLT_8           BIT11
 set     ADC_RSLT13_RSLT_9           BIT12
 set     ADC_RSLT13_RSLT_10          BIT13
 set     ADC_RSLT13_RSLT_11          BIT14

 set     ADC_RSLT13_SEXT             BIT15
;;   Sign Extend

 set     ADC_RSLT14_RSLT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT14_RSLT_0           BIT3
 set     ADC_RSLT14_RSLT_1           BIT4
 set     ADC_RSLT14_RSLT_2           BIT5
 set     ADC_RSLT14_RSLT_3           BIT6
 set     ADC_RSLT14_RSLT_4           BIT7
 set     ADC_RSLT14_RSLT_5           BIT8
 set     ADC_RSLT14_RSLT_6           BIT9
 set     ADC_RSLT14_RSLT_7           BIT10
 set     ADC_RSLT14_RSLT_8           BIT11
 set     ADC_RSLT14_RSLT_9           BIT12
 set     ADC_RSLT14_RSLT_10          BIT13
 set     ADC_RSLT14_RSLT_11          BIT14

 set     ADC_RSLT14_SEXT             BIT15
;;   Sign Extend

 set     ADC_RSLT15_RSLT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT15_RSLT_0           BIT3
 set     ADC_RSLT15_RSLT_1           BIT4
 set     ADC_RSLT15_RSLT_2           BIT5
 set     ADC_RSLT15_RSLT_3           BIT6
 set     ADC_RSLT15_RSLT_4           BIT7
 set     ADC_RSLT15_RSLT_5           BIT8
 set     ADC_RSLT15_RSLT_6           BIT9
 set     ADC_RSLT15_RSLT_7           BIT10
 set     ADC_RSLT15_RSLT_8           BIT11
 set     ADC_RSLT15_RSLT_9           BIT12
 set     ADC_RSLT15_RSLT_10          BIT13
 set     ADC_RSLT15_RSLT_11          BIT14

 set     ADC_RSLT15_SEXT             BIT15
;;   Sign Extend

 set     ADC_LOLIM0_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM0_LLMT_0           BIT3
 set     ADC_LOLIM0_LLMT_1           BIT4
 set     ADC_LOLIM0_LLMT_2           BIT5
 set     ADC_LOLIM0_LLMT_3           BIT6
 set     ADC_LOLIM0_LLMT_4           BIT7
 set     ADC_LOLIM0_LLMT_5           BIT8
 set     ADC_LOLIM0_LLMT_6           BIT9
 set     ADC_LOLIM0_LLMT_7           BIT10
 set     ADC_LOLIM0_LLMT_8           BIT11
 set     ADC_LOLIM0_LLMT_9           BIT12
 set     ADC_LOLIM0_LLMT_10          BIT13
 set     ADC_LOLIM0_LLMT_11          BIT14

 set     ADC_LOLIM1_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM1_LLMT_0           BIT3
 set     ADC_LOLIM1_LLMT_1           BIT4
 set     ADC_LOLIM1_LLMT_2           BIT5
 set     ADC_LOLIM1_LLMT_3           BIT6
 set     ADC_LOLIM1_LLMT_4           BIT7
 set     ADC_LOLIM1_LLMT_5           BIT8
 set     ADC_LOLIM1_LLMT_6           BIT9
 set     ADC_LOLIM1_LLMT_7           BIT10
 set     ADC_LOLIM1_LLMT_8           BIT11
 set     ADC_LOLIM1_LLMT_9           BIT12
 set     ADC_LOLIM1_LLMT_10          BIT13
 set     ADC_LOLIM1_LLMT_11          BIT14

 set     ADC_LOLIM2_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM2_LLMT_0           BIT3
 set     ADC_LOLIM2_LLMT_1           BIT4
 set     ADC_LOLIM2_LLMT_2           BIT5
 set     ADC_LOLIM2_LLMT_3           BIT6
 set     ADC_LOLIM2_LLMT_4           BIT7
 set     ADC_LOLIM2_LLMT_5           BIT8
 set     ADC_LOLIM2_LLMT_6           BIT9
 set     ADC_LOLIM2_LLMT_7           BIT10
 set     ADC_LOLIM2_LLMT_8           BIT11
 set     ADC_LOLIM2_LLMT_9           BIT12
 set     ADC_LOLIM2_LLMT_10          BIT13
 set     ADC_LOLIM2_LLMT_11          BIT14

 set     ADC_LOLIM3_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM3_LLMT_0           BIT3
 set     ADC_LOLIM3_LLMT_1           BIT4
 set     ADC_LOLIM3_LLMT_2           BIT5
 set     ADC_LOLIM3_LLMT_3           BIT6
 set     ADC_LOLIM3_LLMT_4           BIT7
 set     ADC_LOLIM3_LLMT_5           BIT8
 set     ADC_LOLIM3_LLMT_6           BIT9
 set     ADC_LOLIM3_LLMT_7           BIT10
 set     ADC_LOLIM3_LLMT_8           BIT11
 set     ADC_LOLIM3_LLMT_9           BIT12
 set     ADC_LOLIM3_LLMT_10          BIT13
 set     ADC_LOLIM3_LLMT_11          BIT14

 set     ADC_LOLIM4_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM4_LLMT_0           BIT3
 set     ADC_LOLIM4_LLMT_1           BIT4
 set     ADC_LOLIM4_LLMT_2           BIT5
 set     ADC_LOLIM4_LLMT_3           BIT6
 set     ADC_LOLIM4_LLMT_4           BIT7
 set     ADC_LOLIM4_LLMT_5           BIT8
 set     ADC_LOLIM4_LLMT_6           BIT9
 set     ADC_LOLIM4_LLMT_7           BIT10
 set     ADC_LOLIM4_LLMT_8           BIT11
 set     ADC_LOLIM4_LLMT_9           BIT12
 set     ADC_LOLIM4_LLMT_10          BIT13
 set     ADC_LOLIM4_LLMT_11          BIT14

 set     ADC_LOLIM5_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM5_LLMT_0           BIT3
 set     ADC_LOLIM5_LLMT_1           BIT4
 set     ADC_LOLIM5_LLMT_2           BIT5
 set     ADC_LOLIM5_LLMT_3           BIT6
 set     ADC_LOLIM5_LLMT_4           BIT7
 set     ADC_LOLIM5_LLMT_5           BIT8
 set     ADC_LOLIM5_LLMT_6           BIT9
 set     ADC_LOLIM5_LLMT_7           BIT10
 set     ADC_LOLIM5_LLMT_8           BIT11
 set     ADC_LOLIM5_LLMT_9           BIT12
 set     ADC_LOLIM5_LLMT_10          BIT13
 set     ADC_LOLIM5_LLMT_11          BIT14

 set     ADC_LOLIM6_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM6_LLMT_0           BIT3
 set     ADC_LOLIM6_LLMT_1           BIT4
 set     ADC_LOLIM6_LLMT_2           BIT5
 set     ADC_LOLIM6_LLMT_3           BIT6
 set     ADC_LOLIM6_LLMT_4           BIT7
 set     ADC_LOLIM6_LLMT_5           BIT8
 set     ADC_LOLIM6_LLMT_6           BIT9
 set     ADC_LOLIM6_LLMT_7           BIT10
 set     ADC_LOLIM6_LLMT_8           BIT11
 set     ADC_LOLIM6_LLMT_9           BIT12
 set     ADC_LOLIM6_LLMT_10          BIT13
 set     ADC_LOLIM6_LLMT_11          BIT14

 set     ADC_LOLIM7_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM7_LLMT_0           BIT3
 set     ADC_LOLIM7_LLMT_1           BIT4
 set     ADC_LOLIM7_LLMT_2           BIT5
 set     ADC_LOLIM7_LLMT_3           BIT6
 set     ADC_LOLIM7_LLMT_4           BIT7
 set     ADC_LOLIM7_LLMT_5           BIT8
 set     ADC_LOLIM7_LLMT_6           BIT9
 set     ADC_LOLIM7_LLMT_7           BIT10
 set     ADC_LOLIM7_LLMT_8           BIT11
 set     ADC_LOLIM7_LLMT_9           BIT12
 set     ADC_LOLIM7_LLMT_10          BIT13
 set     ADC_LOLIM7_LLMT_11          BIT14

 set     ADC_LOLIM8_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM8_LLMT_0           BIT3
 set     ADC_LOLIM8_LLMT_1           BIT4
 set     ADC_LOLIM8_LLMT_2           BIT5
 set     ADC_LOLIM8_LLMT_3           BIT6
 set     ADC_LOLIM8_LLMT_4           BIT7
 set     ADC_LOLIM8_LLMT_5           BIT8
 set     ADC_LOLIM8_LLMT_6           BIT9
 set     ADC_LOLIM8_LLMT_7           BIT10
 set     ADC_LOLIM8_LLMT_8           BIT11
 set     ADC_LOLIM8_LLMT_9           BIT12
 set     ADC_LOLIM8_LLMT_10          BIT13
 set     ADC_LOLIM8_LLMT_11          BIT14

 set     ADC_LOLIM9_LLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM9_LLMT_0           BIT3
 set     ADC_LOLIM9_LLMT_1           BIT4
 set     ADC_LOLIM9_LLMT_2           BIT5
 set     ADC_LOLIM9_LLMT_3           BIT6
 set     ADC_LOLIM9_LLMT_4           BIT7
 set     ADC_LOLIM9_LLMT_5           BIT8
 set     ADC_LOLIM9_LLMT_6           BIT9
 set     ADC_LOLIM9_LLMT_7           BIT10
 set     ADC_LOLIM9_LLMT_8           BIT11
 set     ADC_LOLIM9_LLMT_9           BIT12
 set     ADC_LOLIM9_LLMT_10          BIT13
 set     ADC_LOLIM9_LLMT_11          BIT14

 set     ADC_LOLIM10_LLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM10_LLMT_0          BIT3
 set     ADC_LOLIM10_LLMT_1          BIT4
 set     ADC_LOLIM10_LLMT_2          BIT5
 set     ADC_LOLIM10_LLMT_3          BIT6
 set     ADC_LOLIM10_LLMT_4          BIT7
 set     ADC_LOLIM10_LLMT_5          BIT8
 set     ADC_LOLIM10_LLMT_6          BIT9
 set     ADC_LOLIM10_LLMT_7          BIT10
 set     ADC_LOLIM10_LLMT_8          BIT11
 set     ADC_LOLIM10_LLMT_9          BIT12
 set     ADC_LOLIM10_LLMT_10         BIT13
 set     ADC_LOLIM10_LLMT_11         BIT14

 set     ADC_LOLIM11_LLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM11_LLMT_0          BIT3
 set     ADC_LOLIM11_LLMT_1          BIT4
 set     ADC_LOLIM11_LLMT_2          BIT5
 set     ADC_LOLIM11_LLMT_3          BIT6
 set     ADC_LOLIM11_LLMT_4          BIT7
 set     ADC_LOLIM11_LLMT_5          BIT8
 set     ADC_LOLIM11_LLMT_6          BIT9
 set     ADC_LOLIM11_LLMT_7          BIT10
 set     ADC_LOLIM11_LLMT_8          BIT11
 set     ADC_LOLIM11_LLMT_9          BIT12
 set     ADC_LOLIM11_LLMT_10         BIT13
 set     ADC_LOLIM11_LLMT_11         BIT14

 set     ADC_LOLIM12_LLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM12_LLMT_0          BIT3
 set     ADC_LOLIM12_LLMT_1          BIT4
 set     ADC_LOLIM12_LLMT_2          BIT5
 set     ADC_LOLIM12_LLMT_3          BIT6
 set     ADC_LOLIM12_LLMT_4          BIT7
 set     ADC_LOLIM12_LLMT_5          BIT8
 set     ADC_LOLIM12_LLMT_6          BIT9
 set     ADC_LOLIM12_LLMT_7          BIT10
 set     ADC_LOLIM12_LLMT_8          BIT11
 set     ADC_LOLIM12_LLMT_9          BIT12
 set     ADC_LOLIM12_LLMT_10         BIT13
 set     ADC_LOLIM12_LLMT_11         BIT14

 set     ADC_LOLIM13_LLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM13_LLMT_0          BIT3
 set     ADC_LOLIM13_LLMT_1          BIT4
 set     ADC_LOLIM13_LLMT_2          BIT5
 set     ADC_LOLIM13_LLMT_3          BIT6
 set     ADC_LOLIM13_LLMT_4          BIT7
 set     ADC_LOLIM13_LLMT_5          BIT8
 set     ADC_LOLIM13_LLMT_6          BIT9
 set     ADC_LOLIM13_LLMT_7          BIT10
 set     ADC_LOLIM13_LLMT_8          BIT11
 set     ADC_LOLIM13_LLMT_9          BIT12
 set     ADC_LOLIM13_LLMT_10         BIT13
 set     ADC_LOLIM13_LLMT_11         BIT14

 set     ADC_LOLIM14_LLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM14_LLMT_0          BIT3
 set     ADC_LOLIM14_LLMT_1          BIT4
 set     ADC_LOLIM14_LLMT_2          BIT5
 set     ADC_LOLIM14_LLMT_3          BIT6
 set     ADC_LOLIM14_LLMT_4          BIT7
 set     ADC_LOLIM14_LLMT_5          BIT8
 set     ADC_LOLIM14_LLMT_6          BIT9
 set     ADC_LOLIM14_LLMT_7          BIT10
 set     ADC_LOLIM14_LLMT_8          BIT11
 set     ADC_LOLIM14_LLMT_9          BIT12
 set     ADC_LOLIM14_LLMT_10         BIT13
 set     ADC_LOLIM14_LLMT_11         BIT14

 set     ADC_LOLIM15_LLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM15_LLMT_0          BIT3
 set     ADC_LOLIM15_LLMT_1          BIT4
 set     ADC_LOLIM15_LLMT_2          BIT5
 set     ADC_LOLIM15_LLMT_3          BIT6
 set     ADC_LOLIM15_LLMT_4          BIT7
 set     ADC_LOLIM15_LLMT_5          BIT8
 set     ADC_LOLIM15_LLMT_6          BIT9
 set     ADC_LOLIM15_LLMT_7          BIT10
 set     ADC_LOLIM15_LLMT_8          BIT11
 set     ADC_LOLIM15_LLMT_9          BIT12
 set     ADC_LOLIM15_LLMT_10         BIT13
 set     ADC_LOLIM15_LLMT_11         BIT14

 set     ADC_HILIM0_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM0_HLMT_0           BIT3
 set     ADC_HILIM0_HLMT_1           BIT4
 set     ADC_HILIM0_HLMT_2           BIT5
 set     ADC_HILIM0_HLMT_3           BIT6
 set     ADC_HILIM0_HLMT_4           BIT7
 set     ADC_HILIM0_HLMT_5           BIT8
 set     ADC_HILIM0_HLMT_6           BIT9
 set     ADC_HILIM0_HLMT_7           BIT10
 set     ADC_HILIM0_HLMT_8           BIT11
 set     ADC_HILIM0_HLMT_9           BIT12
 set     ADC_HILIM0_HLMT_10          BIT13
 set     ADC_HILIM0_HLMT_11          BIT14

 set     ADC_HILIM1_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM1_HLMT_0           BIT3
 set     ADC_HILIM1_HLMT_1           BIT4
 set     ADC_HILIM1_HLMT_2           BIT5
 set     ADC_HILIM1_HLMT_3           BIT6
 set     ADC_HILIM1_HLMT_4           BIT7
 set     ADC_HILIM1_HLMT_5           BIT8
 set     ADC_HILIM1_HLMT_6           BIT9
 set     ADC_HILIM1_HLMT_7           BIT10
 set     ADC_HILIM1_HLMT_8           BIT11
 set     ADC_HILIM1_HLMT_9           BIT12
 set     ADC_HILIM1_HLMT_10          BIT13
 set     ADC_HILIM1_HLMT_11          BIT14

 set     ADC_HILIM2_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM2_HLMT_0           BIT3
 set     ADC_HILIM2_HLMT_1           BIT4
 set     ADC_HILIM2_HLMT_2           BIT5
 set     ADC_HILIM2_HLMT_3           BIT6
 set     ADC_HILIM2_HLMT_4           BIT7
 set     ADC_HILIM2_HLMT_5           BIT8
 set     ADC_HILIM2_HLMT_6           BIT9
 set     ADC_HILIM2_HLMT_7           BIT10
 set     ADC_HILIM2_HLMT_8           BIT11
 set     ADC_HILIM2_HLMT_9           BIT12
 set     ADC_HILIM2_HLMT_10          BIT13
 set     ADC_HILIM2_HLMT_11          BIT14

 set     ADC_HILIM3_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM3_HLMT_0           BIT3
 set     ADC_HILIM3_HLMT_1           BIT4
 set     ADC_HILIM3_HLMT_2           BIT5
 set     ADC_HILIM3_HLMT_3           BIT6
 set     ADC_HILIM3_HLMT_4           BIT7
 set     ADC_HILIM3_HLMT_5           BIT8
 set     ADC_HILIM3_HLMT_6           BIT9
 set     ADC_HILIM3_HLMT_7           BIT10
 set     ADC_HILIM3_HLMT_8           BIT11
 set     ADC_HILIM3_HLMT_9           BIT12
 set     ADC_HILIM3_HLMT_10          BIT13
 set     ADC_HILIM3_HLMT_11          BIT14

 set     ADC_HILIM4_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM4_HLMT_0           BIT3
 set     ADC_HILIM4_HLMT_1           BIT4
 set     ADC_HILIM4_HLMT_2           BIT5
 set     ADC_HILIM4_HLMT_3           BIT6
 set     ADC_HILIM4_HLMT_4           BIT7
 set     ADC_HILIM4_HLMT_5           BIT8
 set     ADC_HILIM4_HLMT_6           BIT9
 set     ADC_HILIM4_HLMT_7           BIT10
 set     ADC_HILIM4_HLMT_8           BIT11
 set     ADC_HILIM4_HLMT_9           BIT12
 set     ADC_HILIM4_HLMT_10          BIT13
 set     ADC_HILIM4_HLMT_11          BIT14

 set     ADC_HILIM5_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM5_HLMT_0           BIT3
 set     ADC_HILIM5_HLMT_1           BIT4
 set     ADC_HILIM5_HLMT_2           BIT5
 set     ADC_HILIM5_HLMT_3           BIT6
 set     ADC_HILIM5_HLMT_4           BIT7
 set     ADC_HILIM5_HLMT_5           BIT8
 set     ADC_HILIM5_HLMT_6           BIT9
 set     ADC_HILIM5_HLMT_7           BIT10
 set     ADC_HILIM5_HLMT_8           BIT11
 set     ADC_HILIM5_HLMT_9           BIT12
 set     ADC_HILIM5_HLMT_10          BIT13
 set     ADC_HILIM5_HLMT_11          BIT14

 set     ADC_HILIM6_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM6_HLMT_0           BIT3
 set     ADC_HILIM6_HLMT_1           BIT4
 set     ADC_HILIM6_HLMT_2           BIT5
 set     ADC_HILIM6_HLMT_3           BIT6
 set     ADC_HILIM6_HLMT_4           BIT7
 set     ADC_HILIM6_HLMT_5           BIT8
 set     ADC_HILIM6_HLMT_6           BIT9
 set     ADC_HILIM6_HLMT_7           BIT10
 set     ADC_HILIM6_HLMT_8           BIT11
 set     ADC_HILIM6_HLMT_9           BIT12
 set     ADC_HILIM6_HLMT_10          BIT13
 set     ADC_HILIM6_HLMT_11          BIT14

 set     ADC_HILIM7_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM7_HLMT_0           BIT3
 set     ADC_HILIM7_HLMT_1           BIT4
 set     ADC_HILIM7_HLMT_2           BIT5
 set     ADC_HILIM7_HLMT_3           BIT6
 set     ADC_HILIM7_HLMT_4           BIT7
 set     ADC_HILIM7_HLMT_5           BIT8
 set     ADC_HILIM7_HLMT_6           BIT9
 set     ADC_HILIM7_HLMT_7           BIT10
 set     ADC_HILIM7_HLMT_8           BIT11
 set     ADC_HILIM7_HLMT_9           BIT12
 set     ADC_HILIM7_HLMT_10          BIT13
 set     ADC_HILIM7_HLMT_11          BIT14

 set     ADC_HILIM8_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM8_HLMT_0           BIT3
 set     ADC_HILIM8_HLMT_1           BIT4
 set     ADC_HILIM8_HLMT_2           BIT5
 set     ADC_HILIM8_HLMT_3           BIT6
 set     ADC_HILIM8_HLMT_4           BIT7
 set     ADC_HILIM8_HLMT_5           BIT8
 set     ADC_HILIM8_HLMT_6           BIT9
 set     ADC_HILIM8_HLMT_7           BIT10
 set     ADC_HILIM8_HLMT_8           BIT11
 set     ADC_HILIM8_HLMT_9           BIT12
 set     ADC_HILIM8_HLMT_10          BIT13
 set     ADC_HILIM8_HLMT_11          BIT14

 set     ADC_HILIM9_HLMT             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM9_HLMT_0           BIT3
 set     ADC_HILIM9_HLMT_1           BIT4
 set     ADC_HILIM9_HLMT_2           BIT5
 set     ADC_HILIM9_HLMT_3           BIT6
 set     ADC_HILIM9_HLMT_4           BIT7
 set     ADC_HILIM9_HLMT_5           BIT8
 set     ADC_HILIM9_HLMT_6           BIT9
 set     ADC_HILIM9_HLMT_7           BIT10
 set     ADC_HILIM9_HLMT_8           BIT11
 set     ADC_HILIM9_HLMT_9           BIT12
 set     ADC_HILIM9_HLMT_10          BIT13
 set     ADC_HILIM9_HLMT_11          BIT14

 set     ADC_HILIM10_HLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM10_HLMT_0          BIT3
 set     ADC_HILIM10_HLMT_1          BIT4
 set     ADC_HILIM10_HLMT_2          BIT5
 set     ADC_HILIM10_HLMT_3          BIT6
 set     ADC_HILIM10_HLMT_4          BIT7
 set     ADC_HILIM10_HLMT_5          BIT8
 set     ADC_HILIM10_HLMT_6          BIT9
 set     ADC_HILIM10_HLMT_7          BIT10
 set     ADC_HILIM10_HLMT_8          BIT11
 set     ADC_HILIM10_HLMT_9          BIT12
 set     ADC_HILIM10_HLMT_10         BIT13
 set     ADC_HILIM10_HLMT_11         BIT14

 set     ADC_HILIM11_HLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM11_HLMT_0          BIT3
 set     ADC_HILIM11_HLMT_1          BIT4
 set     ADC_HILIM11_HLMT_2          BIT5
 set     ADC_HILIM11_HLMT_3          BIT6
 set     ADC_HILIM11_HLMT_4          BIT7
 set     ADC_HILIM11_HLMT_5          BIT8
 set     ADC_HILIM11_HLMT_6          BIT9
 set     ADC_HILIM11_HLMT_7          BIT10
 set     ADC_HILIM11_HLMT_8          BIT11
 set     ADC_HILIM11_HLMT_9          BIT12
 set     ADC_HILIM11_HLMT_10         BIT13
 set     ADC_HILIM11_HLMT_11         BIT14

 set     ADC_HILIM12_HLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM12_HLMT_0          BIT3
 set     ADC_HILIM12_HLMT_1          BIT4
 set     ADC_HILIM12_HLMT_2          BIT5
 set     ADC_HILIM12_HLMT_3          BIT6
 set     ADC_HILIM12_HLMT_4          BIT7
 set     ADC_HILIM12_HLMT_5          BIT8
 set     ADC_HILIM12_HLMT_6          BIT9
 set     ADC_HILIM12_HLMT_7          BIT10
 set     ADC_HILIM12_HLMT_8          BIT11
 set     ADC_HILIM12_HLMT_9          BIT12
 set     ADC_HILIM12_HLMT_10         BIT13
 set     ADC_HILIM12_HLMT_11         BIT14

 set     ADC_HILIM13_HLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM13_HLMT_0          BIT3
 set     ADC_HILIM13_HLMT_1          BIT4
 set     ADC_HILIM13_HLMT_2          BIT5
 set     ADC_HILIM13_HLMT_3          BIT6
 set     ADC_HILIM13_HLMT_4          BIT7
 set     ADC_HILIM13_HLMT_5          BIT8
 set     ADC_HILIM13_HLMT_6          BIT9
 set     ADC_HILIM13_HLMT_7          BIT10
 set     ADC_HILIM13_HLMT_8          BIT11
 set     ADC_HILIM13_HLMT_9          BIT12
 set     ADC_HILIM13_HLMT_10         BIT13
 set     ADC_HILIM13_HLMT_11         BIT14

 set     ADC_HILIM14_HLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM14_HLMT_0          BIT3
 set     ADC_HILIM14_HLMT_1          BIT4
 set     ADC_HILIM14_HLMT_2          BIT5
 set     ADC_HILIM14_HLMT_3          BIT6
 set     ADC_HILIM14_HLMT_4          BIT7
 set     ADC_HILIM14_HLMT_5          BIT8
 set     ADC_HILIM14_HLMT_6          BIT9
 set     ADC_HILIM14_HLMT_7          BIT10
 set     ADC_HILIM14_HLMT_8          BIT11
 set     ADC_HILIM14_HLMT_9          BIT12
 set     ADC_HILIM14_HLMT_10         BIT13
 set     ADC_HILIM14_HLMT_11         BIT14

 set     ADC_HILIM15_HLMT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM15_HLMT_0          BIT3
 set     ADC_HILIM15_HLMT_1          BIT4
 set     ADC_HILIM15_HLMT_2          BIT5
 set     ADC_HILIM15_HLMT_3          BIT6
 set     ADC_HILIM15_HLMT_4          BIT7
 set     ADC_HILIM15_HLMT_5          BIT8
 set     ADC_HILIM15_HLMT_6          BIT9
 set     ADC_HILIM15_HLMT_7          BIT10
 set     ADC_HILIM15_HLMT_8          BIT11
 set     ADC_HILIM15_HLMT_9          BIT12
 set     ADC_HILIM15_HLMT_10         BIT13
 set     ADC_HILIM15_HLMT_11         BIT14

 set     ADC_OFFST0_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST0_OFFSET_0         BIT3
 set     ADC_OFFST0_OFFSET_1         BIT4
 set     ADC_OFFST0_OFFSET_2         BIT5
 set     ADC_OFFST0_OFFSET_3         BIT6
 set     ADC_OFFST0_OFFSET_4         BIT7
 set     ADC_OFFST0_OFFSET_5         BIT8
 set     ADC_OFFST0_OFFSET_6         BIT9
 set     ADC_OFFST0_OFFSET_7         BIT10
 set     ADC_OFFST0_OFFSET_8         BIT11
 set     ADC_OFFST0_OFFSET_9         BIT12
 set     ADC_OFFST0_OFFSET_10        BIT13
 set     ADC_OFFST0_OFFSET_11        BIT14

 set     ADC_OFFST1_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST1_OFFSET_0         BIT3
 set     ADC_OFFST1_OFFSET_1         BIT4
 set     ADC_OFFST1_OFFSET_2         BIT5
 set     ADC_OFFST1_OFFSET_3         BIT6
 set     ADC_OFFST1_OFFSET_4         BIT7
 set     ADC_OFFST1_OFFSET_5         BIT8
 set     ADC_OFFST1_OFFSET_6         BIT9
 set     ADC_OFFST1_OFFSET_7         BIT10
 set     ADC_OFFST1_OFFSET_8         BIT11
 set     ADC_OFFST1_OFFSET_9         BIT12
 set     ADC_OFFST1_OFFSET_10        BIT13
 set     ADC_OFFST1_OFFSET_11        BIT14

 set     ADC_OFFST2_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST2_OFFSET_0         BIT3
 set     ADC_OFFST2_OFFSET_1         BIT4
 set     ADC_OFFST2_OFFSET_2         BIT5
 set     ADC_OFFST2_OFFSET_3         BIT6
 set     ADC_OFFST2_OFFSET_4         BIT7
 set     ADC_OFFST2_OFFSET_5         BIT8
 set     ADC_OFFST2_OFFSET_6         BIT9
 set     ADC_OFFST2_OFFSET_7         BIT10
 set     ADC_OFFST2_OFFSET_8         BIT11
 set     ADC_OFFST2_OFFSET_9         BIT12
 set     ADC_OFFST2_OFFSET_10        BIT13
 set     ADC_OFFST2_OFFSET_11        BIT14

 set     ADC_OFFST3_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST3_OFFSET_0         BIT3
 set     ADC_OFFST3_OFFSET_1         BIT4
 set     ADC_OFFST3_OFFSET_2         BIT5
 set     ADC_OFFST3_OFFSET_3         BIT6
 set     ADC_OFFST3_OFFSET_4         BIT7
 set     ADC_OFFST3_OFFSET_5         BIT8
 set     ADC_OFFST3_OFFSET_6         BIT9
 set     ADC_OFFST3_OFFSET_7         BIT10
 set     ADC_OFFST3_OFFSET_8         BIT11
 set     ADC_OFFST3_OFFSET_9         BIT12
 set     ADC_OFFST3_OFFSET_10        BIT13
 set     ADC_OFFST3_OFFSET_11        BIT14

 set     ADC_OFFST4_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST4_OFFSET_0         BIT3
 set     ADC_OFFST4_OFFSET_1         BIT4
 set     ADC_OFFST4_OFFSET_2         BIT5
 set     ADC_OFFST4_OFFSET_3         BIT6
 set     ADC_OFFST4_OFFSET_4         BIT7
 set     ADC_OFFST4_OFFSET_5         BIT8
 set     ADC_OFFST4_OFFSET_6         BIT9
 set     ADC_OFFST4_OFFSET_7         BIT10
 set     ADC_OFFST4_OFFSET_8         BIT11
 set     ADC_OFFST4_OFFSET_9         BIT12
 set     ADC_OFFST4_OFFSET_10        BIT13
 set     ADC_OFFST4_OFFSET_11        BIT14

 set     ADC_OFFST5_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST5_OFFSET_0         BIT3
 set     ADC_OFFST5_OFFSET_1         BIT4
 set     ADC_OFFST5_OFFSET_2         BIT5
 set     ADC_OFFST5_OFFSET_3         BIT6
 set     ADC_OFFST5_OFFSET_4         BIT7
 set     ADC_OFFST5_OFFSET_5         BIT8
 set     ADC_OFFST5_OFFSET_6         BIT9
 set     ADC_OFFST5_OFFSET_7         BIT10
 set     ADC_OFFST5_OFFSET_8         BIT11
 set     ADC_OFFST5_OFFSET_9         BIT12
 set     ADC_OFFST5_OFFSET_10        BIT13
 set     ADC_OFFST5_OFFSET_11        BIT14

 set     ADC_OFFST6_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST6_OFFSET_0         BIT3
 set     ADC_OFFST6_OFFSET_1         BIT4
 set     ADC_OFFST6_OFFSET_2         BIT5
 set     ADC_OFFST6_OFFSET_3         BIT6
 set     ADC_OFFST6_OFFSET_4         BIT7
 set     ADC_OFFST6_OFFSET_5         BIT8
 set     ADC_OFFST6_OFFSET_6         BIT9
 set     ADC_OFFST6_OFFSET_7         BIT10
 set     ADC_OFFST6_OFFSET_8         BIT11
 set     ADC_OFFST6_OFFSET_9         BIT12
 set     ADC_OFFST6_OFFSET_10        BIT13
 set     ADC_OFFST6_OFFSET_11        BIT14

 set     ADC_OFFST7_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST7_OFFSET_0         BIT3
 set     ADC_OFFST7_OFFSET_1         BIT4
 set     ADC_OFFST7_OFFSET_2         BIT5
 set     ADC_OFFST7_OFFSET_3         BIT6
 set     ADC_OFFST7_OFFSET_4         BIT7
 set     ADC_OFFST7_OFFSET_5         BIT8
 set     ADC_OFFST7_OFFSET_6         BIT9
 set     ADC_OFFST7_OFFSET_7         BIT10
 set     ADC_OFFST7_OFFSET_8         BIT11
 set     ADC_OFFST7_OFFSET_9         BIT12
 set     ADC_OFFST7_OFFSET_10        BIT13
 set     ADC_OFFST7_OFFSET_11        BIT14

 set     ADC_OFFST8_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST8_OFFSET_0         BIT3
 set     ADC_OFFST8_OFFSET_1         BIT4
 set     ADC_OFFST8_OFFSET_2         BIT5
 set     ADC_OFFST8_OFFSET_3         BIT6
 set     ADC_OFFST8_OFFSET_4         BIT7
 set     ADC_OFFST8_OFFSET_5         BIT8
 set     ADC_OFFST8_OFFSET_6         BIT9
 set     ADC_OFFST8_OFFSET_7         BIT10
 set     ADC_OFFST8_OFFSET_8         BIT11
 set     ADC_OFFST8_OFFSET_9         BIT12
 set     ADC_OFFST8_OFFSET_10        BIT13
 set     ADC_OFFST8_OFFSET_11        BIT14

 set     ADC_OFFST9_OFFSET           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST9_OFFSET_0         BIT3
 set     ADC_OFFST9_OFFSET_1         BIT4
 set     ADC_OFFST9_OFFSET_2         BIT5
 set     ADC_OFFST9_OFFSET_3         BIT6
 set     ADC_OFFST9_OFFSET_4         BIT7
 set     ADC_OFFST9_OFFSET_5         BIT8
 set     ADC_OFFST9_OFFSET_6         BIT9
 set     ADC_OFFST9_OFFSET_7         BIT10
 set     ADC_OFFST9_OFFSET_8         BIT11
 set     ADC_OFFST9_OFFSET_9         BIT12
 set     ADC_OFFST9_OFFSET_10        BIT13
 set     ADC_OFFST9_OFFSET_11        BIT14

 set     ADC_OFFST10_OFFSET          (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST10_OFFSET_0        BIT3
 set     ADC_OFFST10_OFFSET_1        BIT4
 set     ADC_OFFST10_OFFSET_2        BIT5
 set     ADC_OFFST10_OFFSET_3        BIT6
 set     ADC_OFFST10_OFFSET_4        BIT7
 set     ADC_OFFST10_OFFSET_5        BIT8
 set     ADC_OFFST10_OFFSET_6        BIT9
 set     ADC_OFFST10_OFFSET_7        BIT10
 set     ADC_OFFST10_OFFSET_8        BIT11
 set     ADC_OFFST10_OFFSET_9        BIT12
 set     ADC_OFFST10_OFFSET_10       BIT13
 set     ADC_OFFST10_OFFSET_11       BIT14

 set     ADC_OFFST11_OFFSET          (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST11_OFFSET_0        BIT3
 set     ADC_OFFST11_OFFSET_1        BIT4
 set     ADC_OFFST11_OFFSET_2        BIT5
 set     ADC_OFFST11_OFFSET_3        BIT6
 set     ADC_OFFST11_OFFSET_4        BIT7
 set     ADC_OFFST11_OFFSET_5        BIT8
 set     ADC_OFFST11_OFFSET_6        BIT9
 set     ADC_OFFST11_OFFSET_7        BIT10
 set     ADC_OFFST11_OFFSET_8        BIT11
 set     ADC_OFFST11_OFFSET_9        BIT12
 set     ADC_OFFST11_OFFSET_10       BIT13
 set     ADC_OFFST11_OFFSET_11       BIT14

 set     ADC_OFFST12_OFFSET          (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST12_OFFSET_0        BIT3
 set     ADC_OFFST12_OFFSET_1        BIT4
 set     ADC_OFFST12_OFFSET_2        BIT5
 set     ADC_OFFST12_OFFSET_3        BIT6
 set     ADC_OFFST12_OFFSET_4        BIT7
 set     ADC_OFFST12_OFFSET_5        BIT8
 set     ADC_OFFST12_OFFSET_6        BIT9
 set     ADC_OFFST12_OFFSET_7        BIT10
 set     ADC_OFFST12_OFFSET_8        BIT11
 set     ADC_OFFST12_OFFSET_9        BIT12
 set     ADC_OFFST12_OFFSET_10       BIT13
 set     ADC_OFFST12_OFFSET_11       BIT14

 set     ADC_OFFST13_OFFSET          (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST13_OFFSET_0        BIT3
 set     ADC_OFFST13_OFFSET_1        BIT4
 set     ADC_OFFST13_OFFSET_2        BIT5
 set     ADC_OFFST13_OFFSET_3        BIT6
 set     ADC_OFFST13_OFFSET_4        BIT7
 set     ADC_OFFST13_OFFSET_5        BIT8
 set     ADC_OFFST13_OFFSET_6        BIT9
 set     ADC_OFFST13_OFFSET_7        BIT10
 set     ADC_OFFST13_OFFSET_8        BIT11
 set     ADC_OFFST13_OFFSET_9        BIT12
 set     ADC_OFFST13_OFFSET_10       BIT13
 set     ADC_OFFST13_OFFSET_11       BIT14

 set     ADC_OFFST14_OFFSET          (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST14_OFFSET_0        BIT3
 set     ADC_OFFST14_OFFSET_1        BIT4
 set     ADC_OFFST14_OFFSET_2        BIT5
 set     ADC_OFFST14_OFFSET_3        BIT6
 set     ADC_OFFST14_OFFSET_4        BIT7
 set     ADC_OFFST14_OFFSET_5        BIT8
 set     ADC_OFFST14_OFFSET_6        BIT9
 set     ADC_OFFST14_OFFSET_7        BIT10
 set     ADC_OFFST14_OFFSET_8        BIT11
 set     ADC_OFFST14_OFFSET_9        BIT12
 set     ADC_OFFST14_OFFSET_10       BIT13
 set     ADC_OFFST14_OFFSET_11       BIT14

 set     ADC_OFFST15_OFFSET          (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST15_OFFSET_0        BIT3
 set     ADC_OFFST15_OFFSET_1        BIT4
 set     ADC_OFFST15_OFFSET_2        BIT5
 set     ADC_OFFST15_OFFSET_3        BIT6
 set     ADC_OFFST15_OFFSET_4        BIT7
 set     ADC_OFFST15_OFFSET_5        BIT8
 set     ADC_OFFST15_OFFSET_6        BIT9
 set     ADC_OFFST15_OFFSET_7        BIT10
 set     ADC_OFFST15_OFFSET_8        BIT11
 set     ADC_OFFST15_OFFSET_9        BIT12
 set     ADC_OFFST15_OFFSET_10       BIT13
 set     ADC_OFFST15_OFFSET_11       BIT14

 set     ADC_PWR_PD0                 BIT0
;;   Manual Power Down for Converter A
;;     0b0 ==> Power Up ADC converter A
;;     0b1 ==> Power Down ADC converter A

 set     ADC_PWR_PD1                 BIT1
;;   Manual Power Down for Converter B
;;     0b0 ==> Power Up ADC converter B
;;     0b1 ==> Power Down ADC converter B

 set     ADC_PWR_APD                 BIT3
;;   Auto Powerdown
;;     0b0 ==> Auto Powerdown Mode is not active
;;     0b1 ==> Auto Powerdown Mode is active

 set     ADC_PWR_PUDELAY             (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9)
;;   Power Up Delay
 set     ADC_PWR_PUDELAY_0           BIT4
 set     ADC_PWR_PUDELAY_1           BIT5
 set     ADC_PWR_PUDELAY_2           BIT6
 set     ADC_PWR_PUDELAY_3           BIT7
 set     ADC_PWR_PUDELAY_4           BIT8
 set     ADC_PWR_PUDELAY_5           BIT9

 set     ADC_PWR_PSTS0               BIT10
;;   ADC Converter A Power Status
;;     0b0 ==> ADC Converter A is currently powered up
;;     0b1 ==> ADC Converter A is currently powered down

 set     ADC_PWR_PSTS1               BIT11
;;   ADC Converter B Power Status
;;     0b0 ==> ADC Converter B is currently powered up
;;     0b1 ==> ADC Converter B is currently powered down

 set     ADC_PWR_ASB                 BIT15
;;   Auto Standby
;;     0b0 ==> Auto standby mode disabled
;;     0b1 ==> Auto standby mode enabled

 set     ADC_CAL_SEL_VREFL_A         BIT12
;;   Select V REFLO Source
;;     0b0 ==> Internal VSSA
;;     0b1 ==> ANA3

 set     ADC_CAL_SEL_VREFH_A         BIT13
;;   Select V REFH Source
;;     0b0 ==> Internal VDDA
;;     0b1 ==> ANA2

 set     ADC_CAL_SEL_VREFL_B         BIT14
;;   Select V REFLO Source
;;     0b0 ==> Internal VSSA
;;     0b1 ==> ANB3

 set     ADC_CAL_SEL_VREFH_B         BIT15
;;   Select V REFH Source
;;     0b0 ==> Internal VDDA
;;     0b1 ==> ANB2

 set     ADC_GC1_GAIN0               (BIT0|BIT1)
;;   Gain Control Bit 0
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC1_GAIN0_0             BIT0
 set     ADC_GC1_GAIN0_1             BIT1

 set     ADC_GC1_GAIN1               (BIT2|BIT3)
;;   Gain Control Bit 1
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC1_GAIN1_0             BIT2
 set     ADC_GC1_GAIN1_1             BIT3

 set     ADC_GC1_GAIN2               (BIT4|BIT5)
;;   Gain Control Bit 2
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC1_GAIN2_0             BIT4
 set     ADC_GC1_GAIN2_1             BIT5

 set     ADC_GC1_GAIN3               (BIT6|BIT7)
;;   Gain Control Bit 3
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC1_GAIN3_0             BIT6
 set     ADC_GC1_GAIN3_1             BIT7

 set     ADC_GC1_GAIN4               (BIT8|BIT9)
;;   Gain Control Bit 4
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC1_GAIN4_0             BIT8
 set     ADC_GC1_GAIN4_1             BIT9

 set     ADC_GC1_GAIN5               (BIT10|BIT11)
;;   Gain Control Bit 5
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC1_GAIN5_0             BIT10
 set     ADC_GC1_GAIN5_1             BIT11

 set     ADC_GC1_GAIN6               (BIT12|BIT13)
;;   Gain Control Bit 6
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC1_GAIN6_0             BIT12
 set     ADC_GC1_GAIN6_1             BIT13

 set     ADC_GC1_GAIN7               (BIT14|BIT15)
;;   Gain Control Bit 7
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC1_GAIN7_0             BIT14
 set     ADC_GC1_GAIN7_1             BIT15

 set     ADC_GC2_GAIN8               (BIT0|BIT1)
;;   Gain Control Bit 8
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC2_GAIN8_0             BIT0
 set     ADC_GC2_GAIN8_1             BIT1

 set     ADC_GC2_GAIN9               (BIT2|BIT3)
;;   Gain Control Bit 9
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC2_GAIN9_0             BIT2
 set     ADC_GC2_GAIN9_1             BIT3

 set     ADC_GC2_GAIN10              (BIT4|BIT5)
;;   Gain Control Bit 10
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC2_GAIN10_0            BIT4
 set     ADC_GC2_GAIN10_1            BIT5

 set     ADC_GC2_GAIN11              (BIT6|BIT7)
;;   Gain Control Bit 11
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC2_GAIN11_0            BIT6
 set     ADC_GC2_GAIN11_1            BIT7

 set     ADC_GC2_GAIN12              (BIT8|BIT9)
;;   Gain Control Bit 12
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC2_GAIN12_0            BIT8
 set     ADC_GC2_GAIN12_1            BIT9

 set     ADC_GC2_GAIN13              (BIT10|BIT11)
;;   Gain Control Bit 13
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC2_GAIN13_0            BIT10
 set     ADC_GC2_GAIN13_1            BIT11

 set     ADC_GC2_GAIN14              (BIT12|BIT13)
;;   Gain Control Bit 14
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC2_GAIN14_0            BIT12
 set     ADC_GC2_GAIN14_1            BIT13

 set     ADC_GC2_GAIN15              (BIT14|BIT15)
;;   Gain Control Bit 15
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC2_GAIN15_0            BIT14
 set     ADC_GC2_GAIN15_1            BIT15

 set     ADC_SCTRL_SC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Scan Control Bits
;;     0b0 ==> Perform sample immediately after the completion of the current sample.
;;     0b1 ==> Delay sample until a new sync input occurs.
 set     ADC_SCTRL_SC_0              BIT0
 set     ADC_SCTRL_SC_1              BIT1
 set     ADC_SCTRL_SC_2              BIT2
 set     ADC_SCTRL_SC_3              BIT3
 set     ADC_SCTRL_SC_4              BIT4
 set     ADC_SCTRL_SC_5              BIT5
 set     ADC_SCTRL_SC_6              BIT6
 set     ADC_SCTRL_SC_7              BIT7
 set     ADC_SCTRL_SC_8              BIT8
 set     ADC_SCTRL_SC_9              BIT9
 set     ADC_SCTRL_SC_10             BIT10
 set     ADC_SCTRL_SC_11             BIT11
 set     ADC_SCTRL_SC_12             BIT12
 set     ADC_SCTRL_SC_13             BIT13
 set     ADC_SCTRL_SC_14             BIT14
 set     ADC_SCTRL_SC_15             BIT15

 set     ADC_PWR2_DIV1               (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13)
;;   Clock Divisor Select
 set     ADC_PWR2_DIV1_0             BIT8
 set     ADC_PWR2_DIV1_1             BIT9
 set     ADC_PWR2_DIV1_2             BIT10
 set     ADC_PWR2_DIV1_3             BIT11
 set     ADC_PWR2_DIV1_4             BIT12
 set     ADC_PWR2_DIV1_5             BIT13

 set     ADC_CTRL3_DMASRC            BIT6
;;   DMA Trigger Source
;;     0b0 ==> DMA trigger source is end of scan interrupt
;;     0b1 ==> DMA trigger source is RDY bits

 set     ADC_CTRL3_UPDEN_L           (BIT8|BIT9|BIT10|BIT11)
;;   Unipolar Differential Enable Low bits
;;     0bxxx1 ==> Inputs = ANA0-ANA1
;;     0bxxx0 ==> Inputs = ANA0-ANA1
;;     0bxx1x ==> Inputs = ANA2-ANA3
;;     0bxx0x ==> Inputs = ANA2-ANA3
;;     0bx1xx ==> Inputs = ANB0-ANB1
;;     0bx0xx ==> Inputs = ANB0-ANB1
;;     0b1xxx ==> Inputs = ANB2-ANB3
 set     ADC_CTRL3_UPDEN_L_0         BIT8
 set     ADC_CTRL3_UPDEN_L_1         BIT9
 set     ADC_CTRL3_UPDEN_L_2         BIT10
 set     ADC_CTRL3_UPDEN_L_3         BIT11

 set     ADC_CTRL3_UPDEN_H           (BIT12|BIT13|BIT14|BIT15)
;;   Unipolar Differential Enable High bits
;;     0bxxx1 ==> Inputs = ANA4-ANA5
;;     0bxxx0 ==> Inputs = ANA4-ANA5
;;     0bxx1x ==> Inputs = ANA6-ANA7
;;     0bxx0x ==> Inputs = ANA6-ANA7
;;     0bx1xx ==> Inputs = ANB4-ANB5
;;     0bx0xx ==> Inputs = ANB4-ANB5
;;     0b1xxx ==> Inputs = ANB6-ANB7
 set     ADC_CTRL3_UPDEN_H_0         BIT12
 set     ADC_CTRL3_UPDEN_H_1         BIT13
 set     ADC_CTRL3_UPDEN_H_2         BIT14
 set     ADC_CTRL3_UPDEN_H_3         BIT15

 set     ADC_SCHLTEN_SCHLTEN         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Scan Halted Interrupt Enable
;;     0b0 ==> Scan halted interrupt is not enabled for this sample.
;;     0b1 ==> Scan halted interrupt is enabled for this sample.
 set     ADC_SCHLTEN_SCHLTEN_0       BIT0
 set     ADC_SCHLTEN_SCHLTEN_1       BIT1
 set     ADC_SCHLTEN_SCHLTEN_2       BIT2
 set     ADC_SCHLTEN_SCHLTEN_3       BIT3
 set     ADC_SCHLTEN_SCHLTEN_4       BIT4
 set     ADC_SCHLTEN_SCHLTEN_5       BIT5
 set     ADC_SCHLTEN_SCHLTEN_6       BIT6
 set     ADC_SCHLTEN_SCHLTEN_7       BIT7
 set     ADC_SCHLTEN_SCHLTEN_8       BIT8
 set     ADC_SCHLTEN_SCHLTEN_9       BIT9
 set     ADC_SCHLTEN_SCHLTEN_10      BIT10
 set     ADC_SCHLTEN_SCHLTEN_11      BIT11
 set     ADC_SCHLTEN_SCHLTEN_12      BIT12
 set     ADC_SCHLTEN_SCHLTEN_13      BIT13
 set     ADC_SCHLTEN_SCHLTEN_14      BIT14
 set     ADC_SCHLTEN_SCHLTEN_15      BIT15

 set     ADC_ZXCTRL3_ZCE16           (BIT0|BIT1)
;;   Zero crossing enable 16
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL3_ZCE16_0         BIT0
 set     ADC_ZXCTRL3_ZCE16_1         BIT1

 set     ADC_ZXCTRL3_ZCE17           (BIT2|BIT3)
;;   Zero crossing enable 17
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL3_ZCE17_0         BIT2
 set     ADC_ZXCTRL3_ZCE17_1         BIT3

 set     ADC_ZXCTRL3_ZCE18           (BIT4|BIT5)
;;   Zero crossing enable 18
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL3_ZCE18_0         BIT4
 set     ADC_ZXCTRL3_ZCE18_1         BIT5

 set     ADC_ZXCTRL3_ZCE19           (BIT6|BIT7)
;;   Zero crossing enable 19
;;     0b00 ==> Zero Crossing disabled
;;     0b01 ==> Zero Crossing enabled for positive to negative sign change
;;     0b10 ==> Zero Crossing enabled for negative to positive sign change
;;     0b11 ==> Zero Crossing enabled for any sign change
 set     ADC_ZXCTRL3_ZCE19_0         BIT6
 set     ADC_ZXCTRL3_ZCE19_1         BIT7

 set     ADC_CLIST5_SAMPLE16         (BIT0|BIT1)
;;   Sample Field 16
;;     0b00 ==> Single Ended: ADCA temperature sensor
;;     0b01 ==> Single Ended: ADCA analog input for on-chip generated signals
;;     0b10 ==> Single Ended: ADCB temperature sensor
;;     0b11 ==> Single Ended: ADCB analog input for on-chip generated signals
 set     ADC_CLIST5_SAMPLE16_0       BIT0
 set     ADC_CLIST5_SAMPLE16_1       BIT1

 set     ADC_CLIST5_SAMPLE17         (BIT2|BIT3)
;;   Sample Field 17
;;     0b00 ==> Single Ended: ADCA temperature sensor
;;     0b01 ==> Single Ended: ADCA analog input for on-chip generated signals
;;     0b10 ==> Single Ended: ADCB temperature sensor
;;     0b11 ==> Single Ended: ADCB analog input for on-chip generated signals
 set     ADC_CLIST5_SAMPLE17_0       BIT2
 set     ADC_CLIST5_SAMPLE17_1       BIT3

 set     ADC_CLIST5_SAMPLE18         (BIT4|BIT5)
;;   Sample Field 18
;;     0b00 ==> Single Ended: ADCA temperature sensor
;;     0b01 ==> Single Ended: ADCA analog input for on-chip generated signals
;;     0b10 ==> Single Ended: ADCB temperature sensor
;;     0b11 ==> Single Ended: ADC B analog input for on-chip generated signals
 set     ADC_CLIST5_SAMPLE18_0       BIT4
 set     ADC_CLIST5_SAMPLE18_1       BIT5

 set     ADC_CLIST5_SAMPLE19         (BIT6|BIT7)
;;   Sample Field 19
;;     0b00 ==> Single Ended: ADCA temperature sensor
;;     0b01 ==> Single Ended: ADCA analog input for on-chip generated signals
;;     0b10 ==> Single Ended: ADCB temperature sensor
;;     0b11 ==> Single Ended: ADCB analog input for on-chip generated signals
 set     ADC_CLIST5_SAMPLE19_0       BIT6
 set     ADC_CLIST5_SAMPLE19_1       BIT7

 set     ADC_CLIST5_SEL_TEMP_0       BIT8
;;   Select Temperature Sensor Alternate Source
;;     0b0 ==> Normal Operation (ADCA6)
;;     0b1 ==> ADCA6 input is replaced with ADCA temperature sensor

 set     ADC_CLIST5_SEL_INTERNAL_0   BIT9
;;   Select On-Chip Analog Input Alternate Source
;;     0b0 ==> Normal Operation (ADCA7)
;;     0b1 ==> ADCA7 input is replaced with ADCA on-chip analog input

 set     ADC_CLIST5_SEL_TEMP_1       BIT10
;;   Select Temperature Sensor Alternate Source
;;     0b0 ==> Normal Operation (ADCB6)
;;     0b1 ==> ADCB6 input is replaced with ADCB temperature sensor

 set     ADC_CLIST5_SEL_INTERNAL_1   BIT11
;;   Select On-Chip Analog Input Alternate Source
;;     0b0 ==> Normal operation (ADCB7)
;;     0b1 ==> ADCB7 input is replaced with ADCB on-chip analog input

 set     ADC_SDIS2_DS                (BIT0|BIT1|BIT2|BIT3)
;;   Disable Sample Bits
;;     0b0 ==> Enable CLIST*[SAMPLEx].
;;     0b1 ==> Disable CLIST*[SAMPLEx] and all subsequent samples. Which samples are actually disabled will depend on the conversion mode, sequential/parallel, and the value of CTRL2[SIMULT]. Please note that enabling the four extra sample slots by themselves (ADC_SDIS=FFFF, and samples enabled in ADC_SDIS2 ) is supported only in once sequential mode. Sequential loop, and parallel (both sequential and loop) modes are not supported. It is suggested to poll the ADC_RDY2 register to check for
;;             conversion completion for this case.
 set     ADC_SDIS2_DS_0              BIT0
 set     ADC_SDIS2_DS_1              BIT1
 set     ADC_SDIS2_DS_2              BIT2
 set     ADC_SDIS2_DS_3              BIT3

 set     ADC_RDY2_RDY                (BIT0|BIT1|BIT2|BIT3)
;;   Ready Sample
;;     0b0 ==> Sample not ready or has been read
;;     0b1 ==> Sample ready to be read
 set     ADC_RDY2_RDY_0              BIT0
 set     ADC_RDY2_RDY_1              BIT1
 set     ADC_RDY2_RDY_2              BIT2
 set     ADC_RDY2_RDY_3              BIT3

 set     ADC_LOLIMSTAT2_LLS          (BIT0|BIT1|BIT2|BIT3)
;;   Low Limit Status Bits
 set     ADC_LOLIMSTAT2_LLS_0        BIT0
 set     ADC_LOLIMSTAT2_LLS_1        BIT1
 set     ADC_LOLIMSTAT2_LLS_2        BIT2
 set     ADC_LOLIMSTAT2_LLS_3        BIT3

 set     ADC_HILIMSTAT2_HLS          (BIT0|BIT1|BIT2|BIT3)
;;   High Limit Status Bits
 set     ADC_HILIMSTAT2_HLS_0        BIT0
 set     ADC_HILIMSTAT2_HLS_1        BIT1
 set     ADC_HILIMSTAT2_HLS_2        BIT2
 set     ADC_HILIMSTAT2_HLS_3        BIT3

 set     ADC_ZXSTAT2_ZCS             (BIT0|BIT1|BIT2|BIT3)
;;   Zero Crossing Status
;;     0b0 ==> Either: A sign change did not occur in a comparison between the current channelx result and the previous channelx result, or Zero crossing control is disabled for channelx in the zero crossing control register, ZXCTRL3
;;     0b1 ==> In a comparison between the current channelx result and the previous channelx result, a sign change condition occurred as defined in the zero crossing control register (ZXCTRL3)
 set     ADC_ZXSTAT2_ZCS_0           BIT0
 set     ADC_ZXSTAT2_ZCS_1           BIT1
 set     ADC_ZXSTAT2_ZCS_2           BIT2
 set     ADC_ZXSTAT2_ZCS_3           BIT3

 set     ADC_RSLT216_RSLT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT216_RSLT_0          BIT3
 set     ADC_RSLT216_RSLT_1          BIT4
 set     ADC_RSLT216_RSLT_2          BIT5
 set     ADC_RSLT216_RSLT_3          BIT6
 set     ADC_RSLT216_RSLT_4          BIT7
 set     ADC_RSLT216_RSLT_5          BIT8
 set     ADC_RSLT216_RSLT_6          BIT9
 set     ADC_RSLT216_RSLT_7          BIT10
 set     ADC_RSLT216_RSLT_8          BIT11
 set     ADC_RSLT216_RSLT_9          BIT12
 set     ADC_RSLT216_RSLT_10         BIT13
 set     ADC_RSLT216_RSLT_11         BIT14

 set     ADC_RSLT216_SEXT            BIT15
;;   Sign Extend

 set     ADC_RSLT217_RSLT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT217_RSLT_0          BIT3
 set     ADC_RSLT217_RSLT_1          BIT4
 set     ADC_RSLT217_RSLT_2          BIT5
 set     ADC_RSLT217_RSLT_3          BIT6
 set     ADC_RSLT217_RSLT_4          BIT7
 set     ADC_RSLT217_RSLT_5          BIT8
 set     ADC_RSLT217_RSLT_6          BIT9
 set     ADC_RSLT217_RSLT_7          BIT10
 set     ADC_RSLT217_RSLT_8          BIT11
 set     ADC_RSLT217_RSLT_9          BIT12
 set     ADC_RSLT217_RSLT_10         BIT13
 set     ADC_RSLT217_RSLT_11         BIT14

 set     ADC_RSLT217_SEXT            BIT15
;;   Sign Extend

 set     ADC_RSLT218_RSLT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT218_RSLT_0          BIT3
 set     ADC_RSLT218_RSLT_1          BIT4
 set     ADC_RSLT218_RSLT_2          BIT5
 set     ADC_RSLT218_RSLT_3          BIT6
 set     ADC_RSLT218_RSLT_4          BIT7
 set     ADC_RSLT218_RSLT_5          BIT8
 set     ADC_RSLT218_RSLT_6          BIT9
 set     ADC_RSLT218_RSLT_7          BIT10
 set     ADC_RSLT218_RSLT_8          BIT11
 set     ADC_RSLT218_RSLT_9          BIT12
 set     ADC_RSLT218_RSLT_10         BIT13
 set     ADC_RSLT218_RSLT_11         BIT14

 set     ADC_RSLT218_SEXT            BIT15
;;   Sign Extend

 set     ADC_RSLT219_RSLT            (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Digital Result of the Conversion
 set     ADC_RSLT219_RSLT_0          BIT3
 set     ADC_RSLT219_RSLT_1          BIT4
 set     ADC_RSLT219_RSLT_2          BIT5
 set     ADC_RSLT219_RSLT_3          BIT6
 set     ADC_RSLT219_RSLT_4          BIT7
 set     ADC_RSLT219_RSLT_5          BIT8
 set     ADC_RSLT219_RSLT_6          BIT9
 set     ADC_RSLT219_RSLT_7          BIT10
 set     ADC_RSLT219_RSLT_8          BIT11
 set     ADC_RSLT219_RSLT_9          BIT12
 set     ADC_RSLT219_RSLT_10         BIT13
 set     ADC_RSLT219_RSLT_11         BIT14

 set     ADC_RSLT219_SEXT            BIT15
;;   Sign Extend

 set     ADC_LOLIM216_LLMT           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM216_LLMT_0         BIT3
 set     ADC_LOLIM216_LLMT_1         BIT4
 set     ADC_LOLIM216_LLMT_2         BIT5
 set     ADC_LOLIM216_LLMT_3         BIT6
 set     ADC_LOLIM216_LLMT_4         BIT7
 set     ADC_LOLIM216_LLMT_5         BIT8
 set     ADC_LOLIM216_LLMT_6         BIT9
 set     ADC_LOLIM216_LLMT_7         BIT10
 set     ADC_LOLIM216_LLMT_8         BIT11
 set     ADC_LOLIM216_LLMT_9         BIT12
 set     ADC_LOLIM216_LLMT_10        BIT13
 set     ADC_LOLIM216_LLMT_11        BIT14

 set     ADC_LOLIM217_LLMT           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM217_LLMT_0         BIT3
 set     ADC_LOLIM217_LLMT_1         BIT4
 set     ADC_LOLIM217_LLMT_2         BIT5
 set     ADC_LOLIM217_LLMT_3         BIT6
 set     ADC_LOLIM217_LLMT_4         BIT7
 set     ADC_LOLIM217_LLMT_5         BIT8
 set     ADC_LOLIM217_LLMT_6         BIT9
 set     ADC_LOLIM217_LLMT_7         BIT10
 set     ADC_LOLIM217_LLMT_8         BIT11
 set     ADC_LOLIM217_LLMT_9         BIT12
 set     ADC_LOLIM217_LLMT_10        BIT13
 set     ADC_LOLIM217_LLMT_11        BIT14

 set     ADC_LOLIM218_LLMT           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM218_LLMT_0         BIT3
 set     ADC_LOLIM218_LLMT_1         BIT4
 set     ADC_LOLIM218_LLMT_2         BIT5
 set     ADC_LOLIM218_LLMT_3         BIT6
 set     ADC_LOLIM218_LLMT_4         BIT7
 set     ADC_LOLIM218_LLMT_5         BIT8
 set     ADC_LOLIM218_LLMT_6         BIT9
 set     ADC_LOLIM218_LLMT_7         BIT10
 set     ADC_LOLIM218_LLMT_8         BIT11
 set     ADC_LOLIM218_LLMT_9         BIT12
 set     ADC_LOLIM218_LLMT_10        BIT13
 set     ADC_LOLIM218_LLMT_11        BIT14

 set     ADC_LOLIM219_LLMT           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Low Limit Bits
 set     ADC_LOLIM219_LLMT_0         BIT3
 set     ADC_LOLIM219_LLMT_1         BIT4
 set     ADC_LOLIM219_LLMT_2         BIT5
 set     ADC_LOLIM219_LLMT_3         BIT6
 set     ADC_LOLIM219_LLMT_4         BIT7
 set     ADC_LOLIM219_LLMT_5         BIT8
 set     ADC_LOLIM219_LLMT_6         BIT9
 set     ADC_LOLIM219_LLMT_7         BIT10
 set     ADC_LOLIM219_LLMT_8         BIT11
 set     ADC_LOLIM219_LLMT_9         BIT12
 set     ADC_LOLIM219_LLMT_10        BIT13
 set     ADC_LOLIM219_LLMT_11        BIT14

 set     ADC_HILIM216_HLMT           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM216_HLMT_0         BIT3
 set     ADC_HILIM216_HLMT_1         BIT4
 set     ADC_HILIM216_HLMT_2         BIT5
 set     ADC_HILIM216_HLMT_3         BIT6
 set     ADC_HILIM216_HLMT_4         BIT7
 set     ADC_HILIM216_HLMT_5         BIT8
 set     ADC_HILIM216_HLMT_6         BIT9
 set     ADC_HILIM216_HLMT_7         BIT10
 set     ADC_HILIM216_HLMT_8         BIT11
 set     ADC_HILIM216_HLMT_9         BIT12
 set     ADC_HILIM216_HLMT_10        BIT13
 set     ADC_HILIM216_HLMT_11        BIT14

 set     ADC_HILIM217_HLMT           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM217_HLMT_0         BIT3
 set     ADC_HILIM217_HLMT_1         BIT4
 set     ADC_HILIM217_HLMT_2         BIT5
 set     ADC_HILIM217_HLMT_3         BIT6
 set     ADC_HILIM217_HLMT_4         BIT7
 set     ADC_HILIM217_HLMT_5         BIT8
 set     ADC_HILIM217_HLMT_6         BIT9
 set     ADC_HILIM217_HLMT_7         BIT10
 set     ADC_HILIM217_HLMT_8         BIT11
 set     ADC_HILIM217_HLMT_9         BIT12
 set     ADC_HILIM217_HLMT_10        BIT13
 set     ADC_HILIM217_HLMT_11        BIT14

 set     ADC_HILIM218_HLMT           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM218_HLMT_0         BIT3
 set     ADC_HILIM218_HLMT_1         BIT4
 set     ADC_HILIM218_HLMT_2         BIT5
 set     ADC_HILIM218_HLMT_3         BIT6
 set     ADC_HILIM218_HLMT_4         BIT7
 set     ADC_HILIM218_HLMT_5         BIT8
 set     ADC_HILIM218_HLMT_6         BIT9
 set     ADC_HILIM218_HLMT_7         BIT10
 set     ADC_HILIM218_HLMT_8         BIT11
 set     ADC_HILIM218_HLMT_9         BIT12
 set     ADC_HILIM218_HLMT_10        BIT13
 set     ADC_HILIM218_HLMT_11        BIT14

 set     ADC_HILIM219_HLMT           (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   High Limit Bits
 set     ADC_HILIM219_HLMT_0         BIT3
 set     ADC_HILIM219_HLMT_1         BIT4
 set     ADC_HILIM219_HLMT_2         BIT5
 set     ADC_HILIM219_HLMT_3         BIT6
 set     ADC_HILIM219_HLMT_4         BIT7
 set     ADC_HILIM219_HLMT_5         BIT8
 set     ADC_HILIM219_HLMT_6         BIT9
 set     ADC_HILIM219_HLMT_7         BIT10
 set     ADC_HILIM219_HLMT_8         BIT11
 set     ADC_HILIM219_HLMT_9         BIT12
 set     ADC_HILIM219_HLMT_10        BIT13
 set     ADC_HILIM219_HLMT_11        BIT14

 set     ADC_OFFST216_OFFSET         (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST216_OFFSET_0       BIT3
 set     ADC_OFFST216_OFFSET_1       BIT4
 set     ADC_OFFST216_OFFSET_2       BIT5
 set     ADC_OFFST216_OFFSET_3       BIT6
 set     ADC_OFFST216_OFFSET_4       BIT7
 set     ADC_OFFST216_OFFSET_5       BIT8
 set     ADC_OFFST216_OFFSET_6       BIT9
 set     ADC_OFFST216_OFFSET_7       BIT10
 set     ADC_OFFST216_OFFSET_8       BIT11
 set     ADC_OFFST216_OFFSET_9       BIT12
 set     ADC_OFFST216_OFFSET_10      BIT13
 set     ADC_OFFST216_OFFSET_11      BIT14

 set     ADC_OFFST217_OFFSET         (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST217_OFFSET_0       BIT3
 set     ADC_OFFST217_OFFSET_1       BIT4
 set     ADC_OFFST217_OFFSET_2       BIT5
 set     ADC_OFFST217_OFFSET_3       BIT6
 set     ADC_OFFST217_OFFSET_4       BIT7
 set     ADC_OFFST217_OFFSET_5       BIT8
 set     ADC_OFFST217_OFFSET_6       BIT9
 set     ADC_OFFST217_OFFSET_7       BIT10
 set     ADC_OFFST217_OFFSET_8       BIT11
 set     ADC_OFFST217_OFFSET_9       BIT12
 set     ADC_OFFST217_OFFSET_10      BIT13
 set     ADC_OFFST217_OFFSET_11      BIT14

 set     ADC_OFFST218_OFFSET         (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST218_OFFSET_0       BIT3
 set     ADC_OFFST218_OFFSET_1       BIT4
 set     ADC_OFFST218_OFFSET_2       BIT5
 set     ADC_OFFST218_OFFSET_3       BIT6
 set     ADC_OFFST218_OFFSET_4       BIT7
 set     ADC_OFFST218_OFFSET_5       BIT8
 set     ADC_OFFST218_OFFSET_6       BIT9
 set     ADC_OFFST218_OFFSET_7       BIT10
 set     ADC_OFFST218_OFFSET_8       BIT11
 set     ADC_OFFST218_OFFSET_9       BIT12
 set     ADC_OFFST218_OFFSET_10      BIT13
 set     ADC_OFFST218_OFFSET_11      BIT14

 set     ADC_OFFST219_OFFSET         (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   ADC Offset Bits
 set     ADC_OFFST219_OFFSET_0       BIT3
 set     ADC_OFFST219_OFFSET_1       BIT4
 set     ADC_OFFST219_OFFSET_2       BIT5
 set     ADC_OFFST219_OFFSET_3       BIT6
 set     ADC_OFFST219_OFFSET_4       BIT7
 set     ADC_OFFST219_OFFSET_5       BIT8
 set     ADC_OFFST219_OFFSET_6       BIT9
 set     ADC_OFFST219_OFFSET_7       BIT10
 set     ADC_OFFST219_OFFSET_8       BIT11
 set     ADC_OFFST219_OFFSET_9       BIT12
 set     ADC_OFFST219_OFFSET_10      BIT13
 set     ADC_OFFST219_OFFSET_11      BIT14

 set     ADC_GC3_GAIN16              (BIT0|BIT1)
;;   Gain Control Bit 16
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC3_GAIN16_0            BIT0
 set     ADC_GC3_GAIN16_1            BIT1

 set     ADC_GC3_GAIN17              (BIT2|BIT3)
;;   Gain Control Bit 17
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC3_GAIN17_0            BIT2
 set     ADC_GC3_GAIN17_1            BIT3

 set     ADC_GC3_GAIN18              (BIT4|BIT5)
;;   Gain Control Bit 18
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC3_GAIN18_0            BIT4
 set     ADC_GC3_GAIN18_1            BIT5

 set     ADC_GC3_GAIN19              (BIT6|BIT7)
;;   Gain Control Bit 19
;;     0b00 ==> x1 amplification
;;     0b01 ==> x2 amplification
;;     0b10 ==> x4 amplification
;;     0b11 ==> reserved
 set     ADC_GC3_GAIN19_0            BIT6
 set     ADC_GC3_GAIN19_1            BIT7

 set     ADC_SCTRL2_SC               (BIT0|BIT1|BIT2|BIT3)
;;   Scan Control Bits
;;     0b0 ==> Perform sample immediately after the completion of the current sample.
;;     0b1 ==> Delay sample until a new sync input occurs.
 set     ADC_SCTRL2_SC_0             BIT0
 set     ADC_SCTRL2_SC_1             BIT1
 set     ADC_SCTRL2_SC_2             BIT2
 set     ADC_SCTRL2_SC_3             BIT3

 set     ADC_SCHLTEN2_SCHLTEN        (BIT0|BIT1|BIT2|BIT3)
;;   Scan Halted Interrupt Enable
;;     0b0 ==> Scan halted interrupt is not enabled for this sample.
;;     0b1 ==> Scan halted interrupt is enabled for this sample.
 set     ADC_SCHLTEN2_SCHLTEN_0      BIT0
 set     ADC_SCHLTEN2_SCHLTEN_1      BIT1
 set     ADC_SCHLTEN2_SCHLTEN_2      BIT2
 set     ADC_SCHLTEN2_SCHLTEN_3      BIT3

 set     AOI_BFCRT010_PT1_DC         (BIT0|BIT1)
;;   Product term 1, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT010_PT1_DC_0       BIT0
 set     AOI_BFCRT010_PT1_DC_1       BIT1

 set     AOI_BFCRT010_PT1_CC         (BIT2|BIT3)
;;   Product term 1, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT010_PT1_CC_0       BIT2
 set     AOI_BFCRT010_PT1_CC_1       BIT3

 set     AOI_BFCRT010_PT1_BC         (BIT4|BIT5)
;;   Product term 1, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT010_PT1_BC_0       BIT4
 set     AOI_BFCRT010_PT1_BC_1       BIT5

 set     AOI_BFCRT010_PT1_AC         (BIT6|BIT7)
;;   Product term 1, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT010_PT1_AC_0       BIT6
 set     AOI_BFCRT010_PT1_AC_1       BIT7

 set     AOI_BFCRT010_PT0_DC         (BIT8|BIT9)
;;   Product term 0, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT010_PT0_DC_0       BIT8
 set     AOI_BFCRT010_PT0_DC_1       BIT9

 set     AOI_BFCRT010_PT0_CC         (BIT10|BIT11)
;;   Product term 0, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT010_PT0_CC_0       BIT10
 set     AOI_BFCRT010_PT0_CC_1       BIT11

 set     AOI_BFCRT010_PT0_BC         (BIT12|BIT13)
;;   Product term 0, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT010_PT0_BC_0       BIT12
 set     AOI_BFCRT010_PT0_BC_1       BIT13

 set     AOI_BFCRT010_PT0_AC         (BIT14|BIT15)
;;   Product term 0, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT010_PT0_AC_0       BIT14
 set     AOI_BFCRT010_PT0_AC_1       BIT15

 set     AOI_BFCRT230_PT3_DC         (BIT0|BIT1)
;;   Product term 3, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT230_PT3_DC_0       BIT0
 set     AOI_BFCRT230_PT3_DC_1       BIT1

 set     AOI_BFCRT230_PT3_CC         (BIT2|BIT3)
;;   Product term 3, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT230_PT3_CC_0       BIT2
 set     AOI_BFCRT230_PT3_CC_1       BIT3

 set     AOI_BFCRT230_PT3_BC         (BIT4|BIT5)
;;   Product term 3, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT230_PT3_BC_0       BIT4
 set     AOI_BFCRT230_PT3_BC_1       BIT5

 set     AOI_BFCRT230_PT3_AC         (BIT6|BIT7)
;;   Product term 3, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT230_PT3_AC_0       BIT6
 set     AOI_BFCRT230_PT3_AC_1       BIT7

 set     AOI_BFCRT230_PT2_DC         (BIT8|BIT9)
;;   Product term 2, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT230_PT2_DC_0       BIT8
 set     AOI_BFCRT230_PT2_DC_1       BIT9

 set     AOI_BFCRT230_PT2_CC         (BIT10|BIT11)
;;   Product term 2, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT230_PT2_CC_0       BIT10
 set     AOI_BFCRT230_PT2_CC_1       BIT11

 set     AOI_BFCRT230_PT2_BC         (BIT12|BIT13)
;;   Product term 2, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT230_PT2_BC_0       BIT12
 set     AOI_BFCRT230_PT2_BC_1       BIT13

 set     AOI_BFCRT230_PT2_AC         (BIT14|BIT15)
;;   Product term 2, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT230_PT2_AC_0       BIT14
 set     AOI_BFCRT230_PT2_AC_1       BIT15

 set     AOI_BFCRT011_PT1_DC         (BIT0|BIT1)
;;   Product term 1, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT011_PT1_DC_0       BIT0
 set     AOI_BFCRT011_PT1_DC_1       BIT1

 set     AOI_BFCRT011_PT1_CC         (BIT2|BIT3)
;;   Product term 1, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT011_PT1_CC_0       BIT2
 set     AOI_BFCRT011_PT1_CC_1       BIT3

 set     AOI_BFCRT011_PT1_BC         (BIT4|BIT5)
;;   Product term 1, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT011_PT1_BC_0       BIT4
 set     AOI_BFCRT011_PT1_BC_1       BIT5

 set     AOI_BFCRT011_PT1_AC         (BIT6|BIT7)
;;   Product term 1, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT011_PT1_AC_0       BIT6
 set     AOI_BFCRT011_PT1_AC_1       BIT7

 set     AOI_BFCRT011_PT0_DC         (BIT8|BIT9)
;;   Product term 0, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT011_PT0_DC_0       BIT8
 set     AOI_BFCRT011_PT0_DC_1       BIT9

 set     AOI_BFCRT011_PT0_CC         (BIT10|BIT11)
;;   Product term 0, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT011_PT0_CC_0       BIT10
 set     AOI_BFCRT011_PT0_CC_1       BIT11

 set     AOI_BFCRT011_PT0_BC         (BIT12|BIT13)
;;   Product term 0, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT011_PT0_BC_0       BIT12
 set     AOI_BFCRT011_PT0_BC_1       BIT13

 set     AOI_BFCRT011_PT0_AC         (BIT14|BIT15)
;;   Product term 0, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT011_PT0_AC_0       BIT14
 set     AOI_BFCRT011_PT0_AC_1       BIT15

 set     AOI_BFCRT231_PT3_DC         (BIT0|BIT1)
;;   Product term 3, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT231_PT3_DC_0       BIT0
 set     AOI_BFCRT231_PT3_DC_1       BIT1

 set     AOI_BFCRT231_PT3_CC         (BIT2|BIT3)
;;   Product term 3, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT231_PT3_CC_0       BIT2
 set     AOI_BFCRT231_PT3_CC_1       BIT3

 set     AOI_BFCRT231_PT3_BC         (BIT4|BIT5)
;;   Product term 3, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT231_PT3_BC_0       BIT4
 set     AOI_BFCRT231_PT3_BC_1       BIT5

 set     AOI_BFCRT231_PT3_AC         (BIT6|BIT7)
;;   Product term 3, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT231_PT3_AC_0       BIT6
 set     AOI_BFCRT231_PT3_AC_1       BIT7

 set     AOI_BFCRT231_PT2_DC         (BIT8|BIT9)
;;   Product term 2, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT231_PT2_DC_0       BIT8
 set     AOI_BFCRT231_PT2_DC_1       BIT9

 set     AOI_BFCRT231_PT2_CC         (BIT10|BIT11)
;;   Product term 2, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT231_PT2_CC_0       BIT10
 set     AOI_BFCRT231_PT2_CC_1       BIT11

 set     AOI_BFCRT231_PT2_BC         (BIT12|BIT13)
;;   Product term 2, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT231_PT2_BC_0       BIT12
 set     AOI_BFCRT231_PT2_BC_1       BIT13

 set     AOI_BFCRT231_PT2_AC         (BIT14|BIT15)
;;   Product term 2, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT231_PT2_AC_0       BIT14
 set     AOI_BFCRT231_PT2_AC_1       BIT15

 set     AOI_BFCRT012_PT1_DC         (BIT0|BIT1)
;;   Product term 1, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT012_PT1_DC_0       BIT0
 set     AOI_BFCRT012_PT1_DC_1       BIT1

 set     AOI_BFCRT012_PT1_CC         (BIT2|BIT3)
;;   Product term 1, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT012_PT1_CC_0       BIT2
 set     AOI_BFCRT012_PT1_CC_1       BIT3

 set     AOI_BFCRT012_PT1_BC         (BIT4|BIT5)
;;   Product term 1, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT012_PT1_BC_0       BIT4
 set     AOI_BFCRT012_PT1_BC_1       BIT5

 set     AOI_BFCRT012_PT1_AC         (BIT6|BIT7)
;;   Product term 1, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT012_PT1_AC_0       BIT6
 set     AOI_BFCRT012_PT1_AC_1       BIT7

 set     AOI_BFCRT012_PT0_DC         (BIT8|BIT9)
;;   Product term 0, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT012_PT0_DC_0       BIT8
 set     AOI_BFCRT012_PT0_DC_1       BIT9

 set     AOI_BFCRT012_PT0_CC         (BIT10|BIT11)
;;   Product term 0, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT012_PT0_CC_0       BIT10
 set     AOI_BFCRT012_PT0_CC_1       BIT11

 set     AOI_BFCRT012_PT0_BC         (BIT12|BIT13)
;;   Product term 0, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT012_PT0_BC_0       BIT12
 set     AOI_BFCRT012_PT0_BC_1       BIT13

 set     AOI_BFCRT012_PT0_AC         (BIT14|BIT15)
;;   Product term 0, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT012_PT0_AC_0       BIT14
 set     AOI_BFCRT012_PT0_AC_1       BIT15

 set     AOI_BFCRT232_PT3_DC         (BIT0|BIT1)
;;   Product term 3, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT232_PT3_DC_0       BIT0
 set     AOI_BFCRT232_PT3_DC_1       BIT1

 set     AOI_BFCRT232_PT3_CC         (BIT2|BIT3)
;;   Product term 3, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT232_PT3_CC_0       BIT2
 set     AOI_BFCRT232_PT3_CC_1       BIT3

 set     AOI_BFCRT232_PT3_BC         (BIT4|BIT5)
;;   Product term 3, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT232_PT3_BC_0       BIT4
 set     AOI_BFCRT232_PT3_BC_1       BIT5

 set     AOI_BFCRT232_PT3_AC         (BIT6|BIT7)
;;   Product term 3, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT232_PT3_AC_0       BIT6
 set     AOI_BFCRT232_PT3_AC_1       BIT7

 set     AOI_BFCRT232_PT2_DC         (BIT8|BIT9)
;;   Product term 2, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT232_PT2_DC_0       BIT8
 set     AOI_BFCRT232_PT2_DC_1       BIT9

 set     AOI_BFCRT232_PT2_CC         (BIT10|BIT11)
;;   Product term 2, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT232_PT2_CC_0       BIT10
 set     AOI_BFCRT232_PT2_CC_1       BIT11

 set     AOI_BFCRT232_PT2_BC         (BIT12|BIT13)
;;   Product term 2, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT232_PT2_BC_0       BIT12
 set     AOI_BFCRT232_PT2_BC_1       BIT13

 set     AOI_BFCRT232_PT2_AC         (BIT14|BIT15)
;;   Product term 2, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT232_PT2_AC_0       BIT14
 set     AOI_BFCRT232_PT2_AC_1       BIT15

 set     AOI_BFCRT013_PT1_DC         (BIT0|BIT1)
;;   Product term 1, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT013_PT1_DC_0       BIT0
 set     AOI_BFCRT013_PT1_DC_1       BIT1

 set     AOI_BFCRT013_PT1_CC         (BIT2|BIT3)
;;   Product term 1, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT013_PT1_CC_0       BIT2
 set     AOI_BFCRT013_PT1_CC_1       BIT3

 set     AOI_BFCRT013_PT1_BC         (BIT4|BIT5)
;;   Product term 1, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT013_PT1_BC_0       BIT4
 set     AOI_BFCRT013_PT1_BC_1       BIT5

 set     AOI_BFCRT013_PT1_AC         (BIT6|BIT7)
;;   Product term 1, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT013_PT1_AC_0       BIT6
 set     AOI_BFCRT013_PT1_AC_1       BIT7

 set     AOI_BFCRT013_PT0_DC         (BIT8|BIT9)
;;   Product term 0, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT013_PT0_DC_0       BIT8
 set     AOI_BFCRT013_PT0_DC_1       BIT9

 set     AOI_BFCRT013_PT0_CC         (BIT10|BIT11)
;;   Product term 0, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT013_PT0_CC_0       BIT10
 set     AOI_BFCRT013_PT0_CC_1       BIT11

 set     AOI_BFCRT013_PT0_BC         (BIT12|BIT13)
;;   Product term 0, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT013_PT0_BC_0       BIT12
 set     AOI_BFCRT013_PT0_BC_1       BIT13

 set     AOI_BFCRT013_PT0_AC         (BIT14|BIT15)
;;   Product term 0, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT013_PT0_AC_0       BIT14
 set     AOI_BFCRT013_PT0_AC_1       BIT15

 set     AOI_BFCRT233_PT3_DC         (BIT0|BIT1)
;;   Product term 3, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT233_PT3_DC_0       BIT0
 set     AOI_BFCRT233_PT3_DC_1       BIT1

 set     AOI_BFCRT233_PT3_CC         (BIT2|BIT3)
;;   Product term 3, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT233_PT3_CC_0       BIT2
 set     AOI_BFCRT233_PT3_CC_1       BIT3

 set     AOI_BFCRT233_PT3_BC         (BIT4|BIT5)
;;   Product term 3, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT233_PT3_BC_0       BIT4
 set     AOI_BFCRT233_PT3_BC_1       BIT5

 set     AOI_BFCRT233_PT3_AC         (BIT6|BIT7)
;;   Product term 3, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT233_PT3_AC_0       BIT6
 set     AOI_BFCRT233_PT3_AC_1       BIT7

 set     AOI_BFCRT233_PT2_DC         (BIT8|BIT9)
;;   Product term 2, D input configuration
;;     0b00 ==> Force the D input in this product term to a logical zero
;;     0b01 ==> Pass the D input in this product term
;;     0b10 ==> Complement the D input in this product term
;;     0b11 ==> Force the D input in this product term to a logical one
 set     AOI_BFCRT233_PT2_DC_0       BIT8
 set     AOI_BFCRT233_PT2_DC_1       BIT9

 set     AOI_BFCRT233_PT2_CC         (BIT10|BIT11)
;;   Product term 2, C input configuration
;;     0b00 ==> Force the C input in this product term to a logical zero
;;     0b01 ==> Pass the C input in this product term
;;     0b10 ==> Complement the C input in this product term
;;     0b11 ==> Force the C input in this product term to a logical one
 set     AOI_BFCRT233_PT2_CC_0       BIT10
 set     AOI_BFCRT233_PT2_CC_1       BIT11

 set     AOI_BFCRT233_PT2_BC         (BIT12|BIT13)
;;   Product term 2, B input configuration
;;     0b00 ==> Force the B input in this product term to a logical zero
;;     0b01 ==> Pass the B input in this product term
;;     0b10 ==> Complement the B input in this product term
;;     0b11 ==> Force the B input in this product term to a logical one
 set     AOI_BFCRT233_PT2_BC_0       BIT12
 set     AOI_BFCRT233_PT2_BC_1       BIT13

 set     AOI_BFCRT233_PT2_AC         (BIT14|BIT15)
;;   Product term 2, A input configuration
;;     0b00 ==> Force the A input in this product term to a logical zero
;;     0b01 ==> Pass the A input in this product term
;;     0b10 ==> Complement the A input in this product term
;;     0b11 ==> Force the A input in this product term to a logical one
 set     AOI_BFCRT233_PT2_AC_0       BIT14
 set     AOI_BFCRT233_PT2_AC_1       BIT15

 set     CAN_CTL0_INITRQ             BIT0
;;   Initialization Mode Request
;;     0b0 ==> Normal operation
;;     0b1 ==> MSCAN in initialization mode

 set     CAN_CTL0_SLPRQ              BIT1
;;   Sleep Mode Request
;;     0b0 ==> Running - The MSCAN functions normally
;;     0b1 ==> Sleep mode request - The MSCAN enters sleep mode when CAN bus idle

 set     CAN_CTL0_WUPE               BIT2
;;   Wake-Up Enable
;;     0b0 ==> Wake-up disabled - The MSCAN ignores traffic on CAN
;;     0b1 ==> Wake-up enabled - The MSCAN is able to restart

 set     CAN_CTL0_TIME               BIT3
;;   Timer Enable
;;     0b0 ==> Disable internal MSCAN timer
;;     0b1 ==> Enable internal MSCAN timer

 set     CAN_CTL0_SYNCH              BIT4
;;   Synchronized Status
;;     0b0 ==> MSCAN is not synchronized to the CAN bus
;;     0b1 ==> MSCAN is synchronized to the CAN bus

 set     CAN_CTL0_CSWAI              BIT5
;;   CAN Stops in Wait Mode
;;     0b0 ==> The module is not affected during wait mode
;;     0b1 ==> The module ceases to be clocked during wait mode

 set     CAN_CTL0_RXACT              BIT6
;;   Receiver Active Status
;;     0b0 ==> MSCAN is transmitting or idle
;;     0b1 ==> MSCAN is receiving a message (including when arbitration is lost)

 set     CAN_CTL0_RXFRM              BIT7
;;   Received Frame Flag
;;     0b0 ==> No valid message was received since last clearing this flag
;;     0b1 ==> A valid message was received since last clearing of this flag

 set     CAN_CTL1_INITAK             BIT0
;;   Initialization Mode Acknowledge
;;     0b0 ==> Running - The MSCAN operates normally
;;     0b1 ==> Initialization mode active - The MSCAN has entered initialization mode

 set     CAN_CTL1_SLPAK              BIT1
;;   Sleep Mode Acknowledge
;;     0b0 ==> Running - The MSCAN operates normally
;;     0b1 ==> Sleep mode active - The MSCAN has entered sleep mode

 set     CAN_CTL1_WUPM               BIT2
;;   Wake-Up Mode
;;     0b0 ==> MSCAN wakes up on any dominant level on the CAN bus
;;     0b1 ==> MSCAN wakes up only in case of a dominant pulse on the CAN bus that has a length of T WAKEUP

 set     CAN_CTL1_BORM               BIT3
;;   Bus-Off Recovery Mode
;;     0b0 ==> Automatic bus-off recovery (see Bosch CAN 2.0A/B protocol specification)
;;     0b1 ==> Bus-off recovery upon user request

 set     CAN_CTL1_LISTEN             BIT4
;;   Listen Only Mode
;;     0b0 ==> Normal operation
;;     0b1 ==> Listen only mode activated

 set     CAN_CTL1_LOOPB              BIT5
;;   Loop Back Self Test Mode
;;     0b0 ==> Loopback self test disabled
;;     0b1 ==> Loopback self test enabled

 set     CAN_CTL1_CLKSRC             BIT6
;;   MSCAN Clock Source
;;     0b0 ==> MSCAN clock source is the oscillator clock
;;     0b1 ==> MSCAN clock source is the bus clock

 set     CAN_CTL1_CANE               BIT7
;;   CAN Enable
;;     0b0 ==> MSCAN module is disabled
;;     0b1 ==> MSCAN module is enabled

 set     CAN_BTR0_BRP                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Baud Rate Prescaler
 set     CAN_BTR0_BRP_0              BIT0
 set     CAN_BTR0_BRP_1              BIT1
 set     CAN_BTR0_BRP_2              BIT2
 set     CAN_BTR0_BRP_3              BIT3
 set     CAN_BTR0_BRP_4              BIT4
 set     CAN_BTR0_BRP_5              BIT5

 set     CAN_BTR0_SJW                (BIT6|BIT7)
;;   Synchronization Jump Width
;;     0b00 ==> Synchronization Jump Width 1 Tq Clock Cycle
;;     0b01 ==> Synchronization Jump Width 2 Tq Clock Cycle
;;     0b10 ==> Synchronization Jump Width 3 Tq Clock Cycle
;;     0b11 ==> Synchronization Jump Width 4 Tq Clock Cycle
 set     CAN_BTR0_SJW_0              BIT6
 set     CAN_BTR0_SJW_1              BIT7

 set     CAN_BTR1_TSEG1              (BIT0|BIT1|BIT2|BIT3)
;;   Time Segment 1
;;     0b0000 ==> 1 Tq clock cycles (This setting is not valid)
;;     0b0001 ==> 2 Tq clock cycles (This setting is not valid)
;;     0b0010 ==> 3 Tq clock cycles (This setting is not valid)
;;     0b0011 ==> 4 Tq clock cycles
;;     0b0100 ==> 5 Tq clock cycles
;;     0b0101 ==> 6 Tq clock cycles
;;     0b0110 ==> 7 Tq clock cycles
;;     0b0111 ==> 8 Tq clock cycles
;;     0b1000 ==> 9 Tq clock cycles
;;     0b1001 ==> 10 Tq clock cycles
;;     0b1010 ==> 11 Tq clock cycles
;;     0b1011 ==> 12 Tq clock cycles
;;     0b1100 ==> 13 Tq clock cycles
;;     0b1101 ==> 14 Tq clock cycles
;;     0b1110 ==> 15 Tq clock cycles
;;     0b1111 ==> 16 Tq clock cycles
 set     CAN_BTR1_TSEG1_0            BIT0
 set     CAN_BTR1_TSEG1_1            BIT1
 set     CAN_BTR1_TSEG1_2            BIT2
 set     CAN_BTR1_TSEG1_3            BIT3

 set     CAN_BTR1_TSEG2              (BIT4|BIT5|BIT6)
;;   Time Segment 2
;;     0b000 ==> 1 Tq clock cycle (This setting is not valid)
;;     0b001 ==> 2 Tq clock cycles
;;     0b010 ==> 3 Tq clock cycles
;;     0b011 ==> 4 Tq clock cycles
;;     0b100 ==> 5 Tq clock cycles
;;     0b101 ==> 6 Tq clock cycles
;;     0b110 ==> 7 Tq clock cycles
;;     0b111 ==> 8 Tq clock cycles
 set     CAN_BTR1_TSEG2_0            BIT4
 set     CAN_BTR1_TSEG2_1            BIT5
 set     CAN_BTR1_TSEG2_2            BIT6

 set     CAN_BTR1_SAMP               BIT7
;;   Sampling
;;     0b0 ==> One sample per bit. The resulting bit value is equal to the value of the single bit positioned at the sample point.
;;     0b1 ==> Three samples per bit. In this case, PHASE_SEG1 must be at least 2 time quanta (Tq). The resulting bit value is determined by using majority rule on the three total samples. For higher bit rates, it is recommended that only one sample is taken per bit time (SAMP=0)

 set     CAN_RFLG_RXF                BIT0
;;   Receive Buffer Full Flag
;;     0b0 ==> No new message available within the RxFG
;;     0b1 ==> The receiver FIFO is not empty. A new message is available in the RxFG

 set     CAN_RFLG_OVRIF              BIT1
;;   Overrun Interrupt Flag
;;     0b0 ==> No data overrun condition
;;     0b1 ==> A data overrun detected

 set     CAN_RFLG_TSTAT              (BIT2|BIT3)
;;   Transmitter Status Bits
;;     0b00 ==> TxOK: 0 <= transmit error counter <= 96
;;     0b01 ==> TxWRN: 96 < transmit error counter <= 127
;;     0b10 ==> TxERR: 127 < transmit error counter <= 255
;;     0b11 ==> Bus-Off: transmit error counter > 255
 set     CAN_RFLG_TSTAT_0            BIT2
 set     CAN_RFLG_TSTAT_1            BIT3

 set     CAN_RFLG_RSTAT              (BIT4|BIT5)
;;   Receiver Status Bits
;;     0b00 ==> RxOK: 0 <= receiver error counter <= 96
;;     0b01 ==> RxWRN: 96 < receiver error counter <= 127
;;     0b10 ==> RxERR: 127 < receiver error counter <= 255
;;     0b11 ==> Bus-Off: receiver error counter > 255
 set     CAN_RFLG_RSTAT_0            BIT4
 set     CAN_RFLG_RSTAT_1            BIT5

 set     CAN_RFLG_CSCIF              BIT6
;;   CAN Status Change Interrupt Flag
;;     0b0 ==> No change in CAN bus status occurred since last interrupt
;;     0b1 ==> MSCAN changed current CAN bus status

 set     CAN_RFLG_WUPIF              BIT7
;;   Wake-up Interrupt Flag
;;     0b0 ==> No wakeup activity observed while in sleep mode
;;     0b1 ==> MSCAN detected activity on the CAN bus and requested wakeup

 set     CAN_RIER_RXFIE              BIT0
;;   Receiver Full Interrupt Enable
;;     0b0 ==> No interrupt request is generated from this event.
;;     0b1 ==> A receive buffer full (successful message reception) event causes a receiver interrupt request.

 set     CAN_RIER_OVRIE              BIT1
;;   Overrun Interrupt Enable
;;     0b0 ==> No interrupt request is generated from this event.
;;     0b1 ==> An overrun event causes an error interrupt request.

 set     CAN_RIER_TSTATE             (BIT2|BIT3)
;;   Transmitter Status Change Enable
;;     0b00 ==> Do not generate any CSCIF interrupt caused by transmitter state changes.
;;     0b01 ==> Generate CSCIF interrupt only if the transmitter enters or leaves "bus-off" state. Discard other transmitter state changes for generating CSCIF interrupt.
;;     0b10 ==> Generate CSCIF interrupt only if the transmitter enters or leaves "TxErr" or "bus-off" state. Discard other transmitter state changes for generating CSCIF interrupt.
;;     0b11 ==> Generate CSCIF interrupt on all state changes.
 set     CAN_RIER_TSTATE_0           BIT2
 set     CAN_RIER_TSTATE_1           BIT3

 set     CAN_RIER_RSTATE             (BIT4|BIT5)
;;   Receiver Status Change Enable
;;     0b00 ==> Do not generate any CSCIF interrupt caused by transmitter state changes.
;;     0b01 ==> Generate CSCIF interrupt only if the transmitter enters or leaves "bus-off" state. Discard other transmitter state changes for generating CSCIF interrupt.
;;     0b10 ==> Generate CSCIF interrupt only if the transmitter enters or leaves "TxErr" or "bus-off" state. Discard other transmitter state changes for generating CSCIF interrupt.
;;     0b11 ==> Generate CSCIF interrupt on all state changes.
 set     CAN_RIER_RSTATE_0           BIT4
 set     CAN_RIER_RSTATE_1           BIT5

 set     CAN_RIER_CSCIE              BIT6
;;   CAN Status Change Interrupt Enable
;;     0b0 ==> No interrupt request is generated from this event.
;;     0b1 ==> A CAN status change event causes an error interrupt request.

 set     CAN_RIER_WUPIE              BIT7
;;   Wake-up Interrupt Enable
;;     0b0 ==> No interrupt request is generated from this event.
;;     0b1 ==> A wake-up event causes a Wake-Up interrupt request.

 set     CAN_TFLG_TXE                (BIT0|BIT1|BIT2)
;;   Transmitter Buffer Empty
;;     0b0 ==> The associated message buffer is full (loaded with a message due for transmission)
;;     0b1 ==> The associated message buffer is empty (not scheduled)
 set     CAN_TFLG_TXE_0              BIT0
 set     CAN_TFLG_TXE_1              BIT1
 set     CAN_TFLG_TXE_2              BIT2

 set     CAN_TIER_TXEIE              (BIT0|BIT1|BIT2)
;;   Transmitter Empty Interrupt Enable
;;     0b0 ==> No interrupt request is generated from this event.
;;     0b1 ==> A transmitter empty (transmit buffer available for transmission) event causes a transmitter empty interrupt request.
 set     CAN_TIER_TXEIE_0            BIT0
 set     CAN_TIER_TXEIE_1            BIT1
 set     CAN_TIER_TXEIE_2            BIT2

 set     CAN_TARQ_ABTRQ              (BIT0|BIT1|BIT2)
;;   Abort Request
;;     0b0 ==> No abort request
;;     0b1 ==> Abort request pending
 set     CAN_TARQ_ABTRQ_0            BIT0
 set     CAN_TARQ_ABTRQ_1            BIT1
 set     CAN_TARQ_ABTRQ_2            BIT2

 set     CAN_TAAK_ABTAK              (BIT0|BIT1|BIT2)
;;   Abort Acknowledge
;;     0b0 ==> The message was not aborted.
;;     0b1 ==> The message was aborted.
 set     CAN_TAAK_ABTAK_0            BIT0
 set     CAN_TAAK_ABTAK_1            BIT1
 set     CAN_TAAK_ABTAK_2            BIT2

 set     CAN_TBSEL_TX                (BIT0|BIT1|BIT2)
;;   Transmit Buffer Select
;;     0b0 ==> The associated message buffer is deselected
;;     0b1 ==> The associated message buffer is selected, if lowest numbered bit
 set     CAN_TBSEL_TX_0              BIT0
 set     CAN_TBSEL_TX_1              BIT1
 set     CAN_TBSEL_TX_2              BIT2

 set     CAN_IDAC_IDHIT              (BIT0|BIT1|BIT2)
;;   Identifier Acceptance Hit Indicator
;;     0b000 ==> Filter 0 Hit
;;     0b001 ==> Filter 1 Hit
;;     0b010 ==> Filter 2 Hit
;;     0b011 ==> Filter 3 Hit
;;     0b100 ==> Filter 4 Hit
;;     0b101 ==> Filter 5 Hit
;;     0b110 ==> Filter 6 Hit
;;     0b111 ==> Filter 7 Hit
 set     CAN_IDAC_IDHIT_0            BIT0
 set     CAN_IDAC_IDHIT_1            BIT1
 set     CAN_IDAC_IDHIT_2            BIT2

 set     CAN_IDAC_IDAM               (BIT4|BIT5)
;;   ID Acceptance Mode
;;     0b00 ==> Two 32-Bit Acceptance Filters
;;     0b01 ==> Four 16-Bit Acceptance Filters
;;     0b10 ==> Eight 8-Bit Acceptance Filters
;;     0b11 ==> Filter Closed
 set     CAN_IDAC_IDAM_0             BIT4
 set     CAN_IDAC_IDAM_1             BIT5

 set     CAN_MISC_BOHOLD             BIT0
;;   Bus-off State Hold Until User Request
;;     0b0 ==> Module is not in bus-off state, or recovery has been requested by user in bus-off state
;;     0b1 ==> Module is in bus-off state and holds this state until user requests recovery

 set     CAN_RXERR_RXERR             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   MSCAN Receive Error Counter Bits
 set     CAN_RXERR_RXERR_0           BIT0
 set     CAN_RXERR_RXERR_1           BIT1
 set     CAN_RXERR_RXERR_2           BIT2
 set     CAN_RXERR_RXERR_3           BIT3
 set     CAN_RXERR_RXERR_4           BIT4
 set     CAN_RXERR_RXERR_5           BIT5
 set     CAN_RXERR_RXERR_6           BIT6
 set     CAN_RXERR_RXERR_7           BIT7

 set     CAN_TXERR_TXERR             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   MSCAN Transmit Error Counter Bits
 set     CAN_TXERR_TXERR_0           BIT0
 set     CAN_TXERR_TXERR_1           BIT1
 set     CAN_TXERR_TXERR_2           BIT2
 set     CAN_TXERR_TXERR_3           BIT3
 set     CAN_TXERR_TXERR_4           BIT4
 set     CAN_TXERR_TXERR_5           BIT5
 set     CAN_TXERR_TXERR_6           BIT6
 set     CAN_TXERR_TXERR_7           BIT7

 set     CAN_IDAR0_AC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Code Bits
 set     CAN_IDAR0_AC_0              BIT0
 set     CAN_IDAR0_AC_1              BIT1
 set     CAN_IDAR0_AC_2              BIT2
 set     CAN_IDAR0_AC_3              BIT3
 set     CAN_IDAR0_AC_4              BIT4
 set     CAN_IDAR0_AC_5              BIT5
 set     CAN_IDAR0_AC_6              BIT6
 set     CAN_IDAR0_AC_7              BIT7

 set     CAN_IDAR1_AC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Code Bits
 set     CAN_IDAR1_AC_0              BIT0
 set     CAN_IDAR1_AC_1              BIT1
 set     CAN_IDAR1_AC_2              BIT2
 set     CAN_IDAR1_AC_3              BIT3
 set     CAN_IDAR1_AC_4              BIT4
 set     CAN_IDAR1_AC_5              BIT5
 set     CAN_IDAR1_AC_6              BIT6
 set     CAN_IDAR1_AC_7              BIT7

 set     CAN_IDAR2_AC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Code Bits
 set     CAN_IDAR2_AC_0              BIT0
 set     CAN_IDAR2_AC_1              BIT1
 set     CAN_IDAR2_AC_2              BIT2
 set     CAN_IDAR2_AC_3              BIT3
 set     CAN_IDAR2_AC_4              BIT4
 set     CAN_IDAR2_AC_5              BIT5
 set     CAN_IDAR2_AC_6              BIT6
 set     CAN_IDAR2_AC_7              BIT7

 set     CAN_IDAR3_AC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Code Bits
 set     CAN_IDAR3_AC_0              BIT0
 set     CAN_IDAR3_AC_1              BIT1
 set     CAN_IDAR3_AC_2              BIT2
 set     CAN_IDAR3_AC_3              BIT3
 set     CAN_IDAR3_AC_4              BIT4
 set     CAN_IDAR3_AC_5              BIT5
 set     CAN_IDAR3_AC_6              BIT6
 set     CAN_IDAR3_AC_7              BIT7

 set     CAN_IDMR0_AM                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Mask Bits
;;     0b0 ==> Match corresponding acceptance code register and identifier bits
;;     0b1 ==> Ignore corresponding acceptance code register bit
 set     CAN_IDMR0_AM_0              BIT0
 set     CAN_IDMR0_AM_1              BIT1
 set     CAN_IDMR0_AM_2              BIT2
 set     CAN_IDMR0_AM_3              BIT3
 set     CAN_IDMR0_AM_4              BIT4
 set     CAN_IDMR0_AM_5              BIT5
 set     CAN_IDMR0_AM_6              BIT6
 set     CAN_IDMR0_AM_7              BIT7

 set     CAN_IDMR1_AM                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Mask Bits
;;     0b0 ==> Match corresponding acceptance code register and identifier bits
;;     0b1 ==> Ignore corresponding acceptance code register bit
 set     CAN_IDMR1_AM_0              BIT0
 set     CAN_IDMR1_AM_1              BIT1
 set     CAN_IDMR1_AM_2              BIT2
 set     CAN_IDMR1_AM_3              BIT3
 set     CAN_IDMR1_AM_4              BIT4
 set     CAN_IDMR1_AM_5              BIT5
 set     CAN_IDMR1_AM_6              BIT6
 set     CAN_IDMR1_AM_7              BIT7

 set     CAN_IDMR2_AM                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Mask Bits
;;     0b0 ==> Match corresponding acceptance code register and identifier bits
;;     0b1 ==> Ignore corresponding acceptance code register bit
 set     CAN_IDMR2_AM_0              BIT0
 set     CAN_IDMR2_AM_1              BIT1
 set     CAN_IDMR2_AM_2              BIT2
 set     CAN_IDMR2_AM_3              BIT3
 set     CAN_IDMR2_AM_4              BIT4
 set     CAN_IDMR2_AM_5              BIT5
 set     CAN_IDMR2_AM_6              BIT6
 set     CAN_IDMR2_AM_7              BIT7

 set     CAN_IDMR3_AM                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Mask Bits
;;     0b0 ==> Match corresponding acceptance code register and identifier bits
;;     0b1 ==> Ignore corresponding acceptance code register bit
 set     CAN_IDMR3_AM_0              BIT0
 set     CAN_IDMR3_AM_1              BIT1
 set     CAN_IDMR3_AM_2              BIT2
 set     CAN_IDMR3_AM_3              BIT3
 set     CAN_IDMR3_AM_4              BIT4
 set     CAN_IDMR3_AM_5              BIT5
 set     CAN_IDMR3_AM_6              BIT6
 set     CAN_IDMR3_AM_7              BIT7

 set     CAN_IDAR4_AC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Code Bits
 set     CAN_IDAR4_AC_0              BIT0
 set     CAN_IDAR4_AC_1              BIT1
 set     CAN_IDAR4_AC_2              BIT2
 set     CAN_IDAR4_AC_3              BIT3
 set     CAN_IDAR4_AC_4              BIT4
 set     CAN_IDAR4_AC_5              BIT5
 set     CAN_IDAR4_AC_6              BIT6
 set     CAN_IDAR4_AC_7              BIT7

 set     CAN_IDAR5_AC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Code Bits
 set     CAN_IDAR5_AC_0              BIT0
 set     CAN_IDAR5_AC_1              BIT1
 set     CAN_IDAR5_AC_2              BIT2
 set     CAN_IDAR5_AC_3              BIT3
 set     CAN_IDAR5_AC_4              BIT4
 set     CAN_IDAR5_AC_5              BIT5
 set     CAN_IDAR5_AC_6              BIT6
 set     CAN_IDAR5_AC_7              BIT7

 set     CAN_IDAR6_AC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Code Bits
 set     CAN_IDAR6_AC_0              BIT0
 set     CAN_IDAR6_AC_1              BIT1
 set     CAN_IDAR6_AC_2              BIT2
 set     CAN_IDAR6_AC_3              BIT3
 set     CAN_IDAR6_AC_4              BIT4
 set     CAN_IDAR6_AC_5              BIT5
 set     CAN_IDAR6_AC_6              BIT6
 set     CAN_IDAR6_AC_7              BIT7

 set     CAN_IDAR7_AC                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Code Bits
 set     CAN_IDAR7_AC_0              BIT0
 set     CAN_IDAR7_AC_1              BIT1
 set     CAN_IDAR7_AC_2              BIT2
 set     CAN_IDAR7_AC_3              BIT3
 set     CAN_IDAR7_AC_4              BIT4
 set     CAN_IDAR7_AC_5              BIT5
 set     CAN_IDAR7_AC_6              BIT6
 set     CAN_IDAR7_AC_7              BIT7

 set     CAN_IDMR4_AM                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Mask Bits
;;     0b0 ==> Match corresponding acceptance code register and identifier bits
;;     0b1 ==> Ignore corresponding acceptance code register bit
 set     CAN_IDMR4_AM_0              BIT0
 set     CAN_IDMR4_AM_1              BIT1
 set     CAN_IDMR4_AM_2              BIT2
 set     CAN_IDMR4_AM_3              BIT3
 set     CAN_IDMR4_AM_4              BIT4
 set     CAN_IDMR4_AM_5              BIT5
 set     CAN_IDMR4_AM_6              BIT6
 set     CAN_IDMR4_AM_7              BIT7

 set     CAN_IDMR5_AM                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Mask Bits
;;     0b0 ==> Match corresponding acceptance code register and identifier bits
;;     0b1 ==> Ignore corresponding acceptance code register bit
 set     CAN_IDMR5_AM_0              BIT0
 set     CAN_IDMR5_AM_1              BIT1
 set     CAN_IDMR5_AM_2              BIT2
 set     CAN_IDMR5_AM_3              BIT3
 set     CAN_IDMR5_AM_4              BIT4
 set     CAN_IDMR5_AM_5              BIT5
 set     CAN_IDMR5_AM_6              BIT6
 set     CAN_IDMR5_AM_7              BIT7

 set     CAN_IDMR6_AM                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Mask Bits
;;     0b0 ==> Match corresponding acceptance code register and identifier bits
;;     0b1 ==> Ignore corresponding acceptance code register bit
 set     CAN_IDMR6_AM_0              BIT0
 set     CAN_IDMR6_AM_1              BIT1
 set     CAN_IDMR6_AM_2              BIT2
 set     CAN_IDMR6_AM_3              BIT3
 set     CAN_IDMR6_AM_4              BIT4
 set     CAN_IDMR6_AM_5              BIT5
 set     CAN_IDMR6_AM_6              BIT6
 set     CAN_IDMR6_AM_7              BIT7

 set     CAN_IDMR7_AM                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Acceptance Mask Bits
;;     0b0 ==> Match corresponding acceptance code register and identifier bits
;;     0b1 ==> Ignore corresponding acceptance code register bit
 set     CAN_IDMR7_AM_0              BIT0
 set     CAN_IDMR7_AM_1              BIT1
 set     CAN_IDMR7_AM_2              BIT2
 set     CAN_IDMR7_AM_3              BIT3
 set     CAN_IDMR7_AM_4              BIT4
 set     CAN_IDMR7_AM_5              BIT5
 set     CAN_IDMR7_AM_6              BIT6
 set     CAN_IDMR7_AM_7              BIT7

 set     CAN_RXFG_IDR0_EXT_ID        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Extended Format Identifier
 set     CAN_RXFG_IDR0_EXT_ID_0      BIT0
 set     CAN_RXFG_IDR0_EXT_ID_1      BIT1
 set     CAN_RXFG_IDR0_EXT_ID_2      BIT2
 set     CAN_RXFG_IDR0_EXT_ID_3      BIT3
 set     CAN_RXFG_IDR0_EXT_ID_4      BIT4
 set     CAN_RXFG_IDR0_EXT_ID_5      BIT5
 set     CAN_RXFG_IDR0_EXT_ID_6      BIT6
 set     CAN_RXFG_IDR0_EXT_ID_7      BIT7

 set     CAN_RXFG_IDR0_STD_ID        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Standard Format Identifier
 set     CAN_RXFG_IDR0_STD_ID_0      BIT0
 set     CAN_RXFG_IDR0_STD_ID_1      BIT1
 set     CAN_RXFG_IDR0_STD_ID_2      BIT2
 set     CAN_RXFG_IDR0_STD_ID_3      BIT3
 set     CAN_RXFG_IDR0_STD_ID_4      BIT4
 set     CAN_RXFG_IDR0_STD_ID_5      BIT5
 set     CAN_RXFG_IDR0_STD_ID_6      BIT6
 set     CAN_RXFG_IDR0_STD_ID_7      BIT7

 set     CAN_RXFG_IDR1_EXT_ID_17_15  (BIT0|BIT1|BIT2)
;;   Extended Format Identifier
 set     CAN_RXFG_IDR1_EXT_ID_17_15_0 BIT0
 set     CAN_RXFG_IDR1_EXT_ID_17_15_1 BIT1
 set     CAN_RXFG_IDR1_EXT_ID_17_15_2 BIT2

 set     CAN_RXFG_IDR1_EXT_IDE       BIT3
;;   ID Extended (set to 1)
;;     0b0 ==> Standard format (11 bit)
;;     0b1 ==> Extended format (29 bit)

 set     CAN_RXFG_IDR1_EXT_SRR       BIT4
;;   Substitute Remote Request (set to 1)

 set     CAN_RXFG_IDR1_EXT_ID_20_18  (BIT5|BIT6|BIT7)
;;   Extended Format Identifier
 set     CAN_RXFG_IDR1_EXT_ID_20_18_0 BIT5
 set     CAN_RXFG_IDR1_EXT_ID_20_18_1 BIT6
 set     CAN_RXFG_IDR1_EXT_ID_20_18_2 BIT7

 set     CAN_RXFG_IDR1_STD_Unimplemented (BIT0|BIT1|BIT2)
 set     CAN_RXFG_IDR1_STD_Unimplemented_0 BIT0
 set     CAN_RXFG_IDR1_STD_Unimplemented_1 BIT1
 set     CAN_RXFG_IDR1_STD_Unimplemented_2 BIT2

 set     CAN_RXFG_IDR1_STD_IDE       BIT3
;;   ID Extended (set to 0)
;;     0b0 ==> Standard format (11 bit)
;;     0b1 ==> Extended format (29 bit)

 set     CAN_RXFG_IDR1_STD_RTR       BIT4
;;   Remote Transmission Request
;;     0b0 ==> Data frame
;;     0b1 ==> Remote frame

 set     CAN_RXFG_IDR1_STD_ID        (BIT5|BIT6|BIT7)
;;   Standard Format Identifier
 set     CAN_RXFG_IDR1_STD_ID_0      BIT5
 set     CAN_RXFG_IDR1_STD_ID_1      BIT6
 set     CAN_RXFG_IDR1_STD_ID_2      BIT7

 set     CAN_RXFG_IDR2_EXT_ID        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Extended Format Identifier
 set     CAN_RXFG_IDR2_EXT_ID_0      BIT0
 set     CAN_RXFG_IDR2_EXT_ID_1      BIT1
 set     CAN_RXFG_IDR2_EXT_ID_2      BIT2
 set     CAN_RXFG_IDR2_EXT_ID_3      BIT3
 set     CAN_RXFG_IDR2_EXT_ID_4      BIT4
 set     CAN_RXFG_IDR2_EXT_ID_5      BIT5
 set     CAN_RXFG_IDR2_EXT_ID_6      BIT6
 set     CAN_RXFG_IDR2_EXT_ID_7      BIT7

 set     CAN_RXFG_IDR3_EXT_RTR       BIT0
;;   Remote Transmission Request
;;     0b0 ==> Data frame
;;     0b1 ==> Remote frame

 set     CAN_RXFG_IDR3_EXT_ID        (BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Extended Format Identifier
 set     CAN_RXFG_IDR3_EXT_ID_0      BIT1
 set     CAN_RXFG_IDR3_EXT_ID_1      BIT2
 set     CAN_RXFG_IDR3_EXT_ID_2      BIT3
 set     CAN_RXFG_IDR3_EXT_ID_3      BIT4
 set     CAN_RXFG_IDR3_EXT_ID_4      BIT5
 set     CAN_RXFG_IDR3_EXT_ID_5      BIT6
 set     CAN_RXFG_IDR3_EXT_ID_6      BIT7

 set     CAN_RXFG_DSR0_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_RXFG_DSR0_DB_0          BIT0
 set     CAN_RXFG_DSR0_DB_1          BIT1
 set     CAN_RXFG_DSR0_DB_2          BIT2
 set     CAN_RXFG_DSR0_DB_3          BIT3
 set     CAN_RXFG_DSR0_DB_4          BIT4
 set     CAN_RXFG_DSR0_DB_5          BIT5
 set     CAN_RXFG_DSR0_DB_6          BIT6
 set     CAN_RXFG_DSR0_DB_7          BIT7

 set     CAN_RXFG_DSR1_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_RXFG_DSR1_DB_0          BIT0
 set     CAN_RXFG_DSR1_DB_1          BIT1
 set     CAN_RXFG_DSR1_DB_2          BIT2
 set     CAN_RXFG_DSR1_DB_3          BIT3
 set     CAN_RXFG_DSR1_DB_4          BIT4
 set     CAN_RXFG_DSR1_DB_5          BIT5
 set     CAN_RXFG_DSR1_DB_6          BIT6
 set     CAN_RXFG_DSR1_DB_7          BIT7

 set     CAN_RXFG_DSR2_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_RXFG_DSR2_DB_0          BIT0
 set     CAN_RXFG_DSR2_DB_1          BIT1
 set     CAN_RXFG_DSR2_DB_2          BIT2
 set     CAN_RXFG_DSR2_DB_3          BIT3
 set     CAN_RXFG_DSR2_DB_4          BIT4
 set     CAN_RXFG_DSR2_DB_5          BIT5
 set     CAN_RXFG_DSR2_DB_6          BIT6
 set     CAN_RXFG_DSR2_DB_7          BIT7

 set     CAN_RXFG_DSR3_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_RXFG_DSR3_DB_0          BIT0
 set     CAN_RXFG_DSR3_DB_1          BIT1
 set     CAN_RXFG_DSR3_DB_2          BIT2
 set     CAN_RXFG_DSR3_DB_3          BIT3
 set     CAN_RXFG_DSR3_DB_4          BIT4
 set     CAN_RXFG_DSR3_DB_5          BIT5
 set     CAN_RXFG_DSR3_DB_6          BIT6
 set     CAN_RXFG_DSR3_DB_7          BIT7

 set     CAN_RXFG_DSR4_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_RXFG_DSR4_DB_0          BIT0
 set     CAN_RXFG_DSR4_DB_1          BIT1
 set     CAN_RXFG_DSR4_DB_2          BIT2
 set     CAN_RXFG_DSR4_DB_3          BIT3
 set     CAN_RXFG_DSR4_DB_4          BIT4
 set     CAN_RXFG_DSR4_DB_5          BIT5
 set     CAN_RXFG_DSR4_DB_6          BIT6
 set     CAN_RXFG_DSR4_DB_7          BIT7

 set     CAN_RXFG_DSR5_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_RXFG_DSR5_DB_0          BIT0
 set     CAN_RXFG_DSR5_DB_1          BIT1
 set     CAN_RXFG_DSR5_DB_2          BIT2
 set     CAN_RXFG_DSR5_DB_3          BIT3
 set     CAN_RXFG_DSR5_DB_4          BIT4
 set     CAN_RXFG_DSR5_DB_5          BIT5
 set     CAN_RXFG_DSR5_DB_6          BIT6
 set     CAN_RXFG_DSR5_DB_7          BIT7

 set     CAN_RXFG_DSR6_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_RXFG_DSR6_DB_0          BIT0
 set     CAN_RXFG_DSR6_DB_1          BIT1
 set     CAN_RXFG_DSR6_DB_2          BIT2
 set     CAN_RXFG_DSR6_DB_3          BIT3
 set     CAN_RXFG_DSR6_DB_4          BIT4
 set     CAN_RXFG_DSR6_DB_5          BIT5
 set     CAN_RXFG_DSR6_DB_6          BIT6
 set     CAN_RXFG_DSR6_DB_7          BIT7

 set     CAN_RXFG_DSR7_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_RXFG_DSR7_DB_0          BIT0
 set     CAN_RXFG_DSR7_DB_1          BIT1
 set     CAN_RXFG_DSR7_DB_2          BIT2
 set     CAN_RXFG_DSR7_DB_3          BIT3
 set     CAN_RXFG_DSR7_DB_4          BIT4
 set     CAN_RXFG_DSR7_DB_5          BIT5
 set     CAN_RXFG_DSR7_DB_6          BIT6
 set     CAN_RXFG_DSR7_DB_7          BIT7

 set     CAN_RXFG_DLR_DLC            (BIT0|BIT1|BIT2|BIT3)
;;   Data Length Code
;;     0b0000 ==> Data Byte Count 0
;;     0b0001 ==> Data Byte Count 1
;;     0b0010 ==> Data Byte Count 2
;;     0b0011 ==> Data Byte Count 3
;;     0b0100 ==> Data Byte Count 4
;;     0b0101 ==> Data Byte Count 5
;;     0b0110 ==> Data Byte Count 6
;;     0b0111 ==> Data Byte Count 7
;;     0b1000 ==> Data Byte Count 8
 set     CAN_RXFG_DLR_DLC_0          BIT0
 set     CAN_RXFG_DLR_DLC_1          BIT1
 set     CAN_RXFG_DLR_DLC_2          BIT2
 set     CAN_RXFG_DLR_DLC_3          BIT3

 set     CAN_RXFG_DLR_Unimplemented  (BIT4|BIT5|BIT6|BIT7)
 set     CAN_RXFG_DLR_Unimplemented_0 BIT4
 set     CAN_RXFG_DLR_Unimplemented_1 BIT5
 set     CAN_RXFG_DLR_Unimplemented_2 BIT6
 set     CAN_RXFG_DLR_Unimplemented_3 BIT7

 set     CAN_RXFG_TSRH_TSR           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Time Stamp Register Bits 15-8
 set     CAN_RXFG_TSRH_TSR_0         BIT0
 set     CAN_RXFG_TSRH_TSR_1         BIT1
 set     CAN_RXFG_TSRH_TSR_2         BIT2
 set     CAN_RXFG_TSRH_TSR_3         BIT3
 set     CAN_RXFG_TSRH_TSR_4         BIT4
 set     CAN_RXFG_TSRH_TSR_5         BIT5
 set     CAN_RXFG_TSRH_TSR_6         BIT6
 set     CAN_RXFG_TSRH_TSR_7         BIT7

 set     CAN_RXFG_TSRL_TSR           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Time Stamp Register Bits 7-0
 set     CAN_RXFG_TSRL_TSR_0         BIT0
 set     CAN_RXFG_TSRL_TSR_1         BIT1
 set     CAN_RXFG_TSRL_TSR_2         BIT2
 set     CAN_RXFG_TSRL_TSR_3         BIT3
 set     CAN_RXFG_TSRL_TSR_4         BIT4
 set     CAN_RXFG_TSRL_TSR_5         BIT5
 set     CAN_RXFG_TSRL_TSR_6         BIT6
 set     CAN_RXFG_TSRL_TSR_7         BIT7

 set     CAN_TXFG_IDR0_EXT_ID        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Extended Format Identifier
 set     CAN_TXFG_IDR0_EXT_ID_0      BIT0
 set     CAN_TXFG_IDR0_EXT_ID_1      BIT1
 set     CAN_TXFG_IDR0_EXT_ID_2      BIT2
 set     CAN_TXFG_IDR0_EXT_ID_3      BIT3
 set     CAN_TXFG_IDR0_EXT_ID_4      BIT4
 set     CAN_TXFG_IDR0_EXT_ID_5      BIT5
 set     CAN_TXFG_IDR0_EXT_ID_6      BIT6
 set     CAN_TXFG_IDR0_EXT_ID_7      BIT7

 set     CAN_TXFG_IDR0_STD_ID        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Standard Format Identifier
 set     CAN_TXFG_IDR0_STD_ID_0      BIT0
 set     CAN_TXFG_IDR0_STD_ID_1      BIT1
 set     CAN_TXFG_IDR0_STD_ID_2      BIT2
 set     CAN_TXFG_IDR0_STD_ID_3      BIT3
 set     CAN_TXFG_IDR0_STD_ID_4      BIT4
 set     CAN_TXFG_IDR0_STD_ID_5      BIT5
 set     CAN_TXFG_IDR0_STD_ID_6      BIT6
 set     CAN_TXFG_IDR0_STD_ID_7      BIT7

 set     CAN_TXFG_IDR1_EXT_ID_17_15  (BIT0|BIT1|BIT2)
;;   Extended Format Identifier
 set     CAN_TXFG_IDR1_EXT_ID_17_15_0 BIT0
 set     CAN_TXFG_IDR1_EXT_ID_17_15_1 BIT1
 set     CAN_TXFG_IDR1_EXT_ID_17_15_2 BIT2

 set     CAN_TXFG_IDR1_EXT_IDE       BIT3
;;   ID Extended (set to 1)
;;     0b0 ==> Standard format (11 bit)
;;     0b1 ==> Extended format (29 bit)

 set     CAN_TXFG_IDR1_EXT_SRR       BIT4
;;   Substitute Remote Request (set to 1)

 set     CAN_TXFG_IDR1_EXT_ID_20_18  (BIT5|BIT6|BIT7)
;;   Extended Format Identifier
 set     CAN_TXFG_IDR1_EXT_ID_20_18_0 BIT5
 set     CAN_TXFG_IDR1_EXT_ID_20_18_1 BIT6
 set     CAN_TXFG_IDR1_EXT_ID_20_18_2 BIT7

 set     CAN_TXFG_IDR1_STD_Unimplemented (BIT0|BIT1|BIT2)
 set     CAN_TXFG_IDR1_STD_Unimplemented_0 BIT0
 set     CAN_TXFG_IDR1_STD_Unimplemented_1 BIT1
 set     CAN_TXFG_IDR1_STD_Unimplemented_2 BIT2

 set     CAN_TXFG_IDR1_STD_IDE       BIT3
;;   ID Extended (set to 0)
;;     0b0 ==> Standard format (11 bit)
;;     0b1 ==> Extended format (29 bit)

 set     CAN_TXFG_IDR1_STD_RTR       BIT4
;;   Remote Transmission Request
;;     0b0 ==> Data frame
;;     0b1 ==> Remote frame

 set     CAN_TXFG_IDR1_STD_ID        (BIT5|BIT6|BIT7)
;;   Standard Format Identifier
 set     CAN_TXFG_IDR1_STD_ID_0      BIT5
 set     CAN_TXFG_IDR1_STD_ID_1      BIT6
 set     CAN_TXFG_IDR1_STD_ID_2      BIT7

 set     CAN_TXFG_IDR2_EXT_ID        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Extended Format Identifier
 set     CAN_TXFG_IDR2_EXT_ID_0      BIT0
 set     CAN_TXFG_IDR2_EXT_ID_1      BIT1
 set     CAN_TXFG_IDR2_EXT_ID_2      BIT2
 set     CAN_TXFG_IDR2_EXT_ID_3      BIT3
 set     CAN_TXFG_IDR2_EXT_ID_4      BIT4
 set     CAN_TXFG_IDR2_EXT_ID_5      BIT5
 set     CAN_TXFG_IDR2_EXT_ID_6      BIT6
 set     CAN_TXFG_IDR2_EXT_ID_7      BIT7

 set     CAN_TXFG_IDR3_EXT_RTR       BIT0
;;   Remote Transmission Request
;;     0b0 ==> Data frame
;;     0b1 ==> Remote frame

 set     CAN_TXFG_IDR3_EXT_ID        (BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Extended Format Identifier
 set     CAN_TXFG_IDR3_EXT_ID_0      BIT1
 set     CAN_TXFG_IDR3_EXT_ID_1      BIT2
 set     CAN_TXFG_IDR3_EXT_ID_2      BIT3
 set     CAN_TXFG_IDR3_EXT_ID_3      BIT4
 set     CAN_TXFG_IDR3_EXT_ID_4      BIT5
 set     CAN_TXFG_IDR3_EXT_ID_5      BIT6
 set     CAN_TXFG_IDR3_EXT_ID_6      BIT7

 set     CAN_TXFG_DSR0_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_TXFG_DSR0_DB_0          BIT0
 set     CAN_TXFG_DSR0_DB_1          BIT1
 set     CAN_TXFG_DSR0_DB_2          BIT2
 set     CAN_TXFG_DSR0_DB_3          BIT3
 set     CAN_TXFG_DSR0_DB_4          BIT4
 set     CAN_TXFG_DSR0_DB_5          BIT5
 set     CAN_TXFG_DSR0_DB_6          BIT6
 set     CAN_TXFG_DSR0_DB_7          BIT7

 set     CAN_TXFG_DSR1_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_TXFG_DSR1_DB_0          BIT0
 set     CAN_TXFG_DSR1_DB_1          BIT1
 set     CAN_TXFG_DSR1_DB_2          BIT2
 set     CAN_TXFG_DSR1_DB_3          BIT3
 set     CAN_TXFG_DSR1_DB_4          BIT4
 set     CAN_TXFG_DSR1_DB_5          BIT5
 set     CAN_TXFG_DSR1_DB_6          BIT6
 set     CAN_TXFG_DSR1_DB_7          BIT7

 set     CAN_TXFG_DSR2_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_TXFG_DSR2_DB_0          BIT0
 set     CAN_TXFG_DSR2_DB_1          BIT1
 set     CAN_TXFG_DSR2_DB_2          BIT2
 set     CAN_TXFG_DSR2_DB_3          BIT3
 set     CAN_TXFG_DSR2_DB_4          BIT4
 set     CAN_TXFG_DSR2_DB_5          BIT5
 set     CAN_TXFG_DSR2_DB_6          BIT6
 set     CAN_TXFG_DSR2_DB_7          BIT7

 set     CAN_TXFG_DSR3_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_TXFG_DSR3_DB_0          BIT0
 set     CAN_TXFG_DSR3_DB_1          BIT1
 set     CAN_TXFG_DSR3_DB_2          BIT2
 set     CAN_TXFG_DSR3_DB_3          BIT3
 set     CAN_TXFG_DSR3_DB_4          BIT4
 set     CAN_TXFG_DSR3_DB_5          BIT5
 set     CAN_TXFG_DSR3_DB_6          BIT6
 set     CAN_TXFG_DSR3_DB_7          BIT7

 set     CAN_TXFG_DSR4_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_TXFG_DSR4_DB_0          BIT0
 set     CAN_TXFG_DSR4_DB_1          BIT1
 set     CAN_TXFG_DSR4_DB_2          BIT2
 set     CAN_TXFG_DSR4_DB_3          BIT3
 set     CAN_TXFG_DSR4_DB_4          BIT4
 set     CAN_TXFG_DSR4_DB_5          BIT5
 set     CAN_TXFG_DSR4_DB_6          BIT6
 set     CAN_TXFG_DSR4_DB_7          BIT7

 set     CAN_TXFG_DSR5_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_TXFG_DSR5_DB_0          BIT0
 set     CAN_TXFG_DSR5_DB_1          BIT1
 set     CAN_TXFG_DSR5_DB_2          BIT2
 set     CAN_TXFG_DSR5_DB_3          BIT3
 set     CAN_TXFG_DSR5_DB_4          BIT4
 set     CAN_TXFG_DSR5_DB_5          BIT5
 set     CAN_TXFG_DSR5_DB_6          BIT6
 set     CAN_TXFG_DSR5_DB_7          BIT7

 set     CAN_TXFG_DSR6_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_TXFG_DSR6_DB_0          BIT0
 set     CAN_TXFG_DSR6_DB_1          BIT1
 set     CAN_TXFG_DSR6_DB_2          BIT2
 set     CAN_TXFG_DSR6_DB_3          BIT3
 set     CAN_TXFG_DSR6_DB_4          BIT4
 set     CAN_TXFG_DSR6_DB_5          BIT5
 set     CAN_TXFG_DSR6_DB_6          BIT6
 set     CAN_TXFG_DSR6_DB_7          BIT7

 set     CAN_TXFG_DSR7_DB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data bits 7-0
 set     CAN_TXFG_DSR7_DB_0          BIT0
 set     CAN_TXFG_DSR7_DB_1          BIT1
 set     CAN_TXFG_DSR7_DB_2          BIT2
 set     CAN_TXFG_DSR7_DB_3          BIT3
 set     CAN_TXFG_DSR7_DB_4          BIT4
 set     CAN_TXFG_DSR7_DB_5          BIT5
 set     CAN_TXFG_DSR7_DB_6          BIT6
 set     CAN_TXFG_DSR7_DB_7          BIT7

 set     CAN_TXFG_DLR_DLC            (BIT0|BIT1|BIT2|BIT3)
;;   Data Length Code
;;     0b0000 ==> Data Byte Count 0
;;     0b0001 ==> Data Byte Count 1
;;     0b0010 ==> Data Byte Count 2
;;     0b0011 ==> Data Byte Count 3
;;     0b0100 ==> Data Byte Count 4
;;     0b0101 ==> Data Byte Count 5
;;     0b0110 ==> Data Byte Count 6
;;     0b0111 ==> Data Byte Count 7
;;     0b1000 ==> Data Byte Count 8
 set     CAN_TXFG_DLR_DLC_0          BIT0
 set     CAN_TXFG_DLR_DLC_1          BIT1
 set     CAN_TXFG_DLR_DLC_2          BIT2
 set     CAN_TXFG_DLR_DLC_3          BIT3

 set     CAN_TXFG_DLR_Unimplemented  (BIT4|BIT5|BIT6|BIT7)
 set     CAN_TXFG_DLR_Unimplemented_0 BIT4
 set     CAN_TXFG_DLR_Unimplemented_1 BIT5
 set     CAN_TXFG_DLR_Unimplemented_2 BIT6
 set     CAN_TXFG_DLR_Unimplemented_3 BIT7

 set     CAN_TXFG_TBPR_PRIO          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Priority bits
 set     CAN_TXFG_TBPR_PRIO_0        BIT0
 set     CAN_TXFG_TBPR_PRIO_1        BIT1
 set     CAN_TXFG_TBPR_PRIO_2        BIT2
 set     CAN_TXFG_TBPR_PRIO_3        BIT3
 set     CAN_TXFG_TBPR_PRIO_4        BIT4
 set     CAN_TXFG_TBPR_PRIO_5        BIT5
 set     CAN_TXFG_TBPR_PRIO_6        BIT6
 set     CAN_TXFG_TBPR_PRIO_7        BIT7

 set     CAN_TXFG_TSRH_TSR           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Time Stamp Register Bits 15-8
 set     CAN_TXFG_TSRH_TSR_0         BIT0
 set     CAN_TXFG_TSRH_TSR_1         BIT1
 set     CAN_TXFG_TSRH_TSR_2         BIT2
 set     CAN_TXFG_TSRH_TSR_3         BIT3
 set     CAN_TXFG_TSRH_TSR_4         BIT4
 set     CAN_TXFG_TSRH_TSR_5         BIT5
 set     CAN_TXFG_TSRH_TSR_6         BIT6
 set     CAN_TXFG_TSRH_TSR_7         BIT7

 set     CAN_TXFG_TSRL_TSR           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Time Stamp Register Bits 7-0
 set     CAN_TXFG_TSRL_TSR_0         BIT0
 set     CAN_TXFG_TSRL_TSR_1         BIT1
 set     CAN_TXFG_TSRL_TSR_2         BIT2
 set     CAN_TXFG_TSRL_TSR_3         BIT3
 set     CAN_TXFG_TSRL_TSR_4         BIT4
 set     CAN_TXFG_TSRL_TSR_5         BIT5
 set     CAN_TXFG_TSRL_TSR_6         BIT6
 set     CAN_TXFG_TSRL_TSR_7         BIT7

 set     CMPA_CR0_HYSTCTR            (BIT0|BIT1)
;;   Comparator hard block hysteresis control
;;     0b00 ==> Level 0
;;     0b01 ==> Level 1
;;     0b10 ==> Level 2
;;     0b11 ==> Level 3
 set     CMPA_CR0_HYSTCTR_0          BIT0
 set     CMPA_CR0_HYSTCTR_1          BIT1

 set     CMPA_CR0_FILTER_CNT         (BIT4|BIT5|BIT6)
;;   Filter Sample Count
;;     0b000 ==> Filter is disabled. If SE = 1, then COUT is a logic 0. This is not a legal state, and is not recommended. If SE = 0, COUT = COUTA.
;;     0b001 ==> One sample must agree. The comparator output is simply sampled.
;;     0b010 ==> 2 consecutive samples must agree.
;;     0b011 ==> 3 consecutive samples must agree.
;;     0b100 ==> 4 consecutive samples must agree.
;;     0b101 ==> 5 consecutive samples must agree.
;;     0b110 ==> 6 consecutive samples must agree.
;;     0b111 ==> 7 consecutive samples must agree.
 set     CMPA_CR0_FILTER_CNT_0       BIT4
 set     CMPA_CR0_FILTER_CNT_1       BIT5
 set     CMPA_CR0_FILTER_CNT_2       BIT6

 set     CMPA_CR1_EN                 BIT0
;;   Comparator Module Enable
;;     0b0 ==> Analog Comparator is disabled.
;;     0b1 ==> Analog Comparator is enabled.

 set     CMPA_CR1_OPE                BIT1
;;   Comparator Output Pin Enable
;;     0b0 ==> CMPO is not available on the associated CMPO output pin. If the comparator does not own the pin, this field has no effect.
;;     0b1 ==> CMPO is available on the associated CMPO output pin. The comparator output (CMPO) is driven out on the associated CMPO output pin if the comparator owns the pin. If the comparator does not own the field, this bit has no effect.

 set     CMPA_CR1_COS                BIT2
;;   Comparator Output Select
;;     0b0 ==> Set the filtered comparator output (CMPO) to equal COUT.
;;     0b1 ==> Set the unfiltered comparator output (CMPO) to equal COUTA.

 set     CMPA_CR1_INV                BIT3
;;   Comparator INVERT
;;     0b0 ==> Does not invert the comparator output.
;;     0b1 ==> Inverts the comparator output.

 set     CMPA_CR1_PMODE              BIT4
;;   Power Mode Select
;;     0b0 ==> Low-Speed (LS) Comparison mode selected. In this mode, CMP has slower output propagation delay and lower current consumption.
;;     0b1 ==> High-Speed (HS) Comparison mode selected. In this mode, CMP has faster output propagation delay and higher current consumption.

 set     CMPA_CR1_WE                 BIT6
;;   Windowing Enable
;;     0b0 ==> Windowing mode is not selected.
;;     0b1 ==> Windowing mode is selected.

 set     CMPA_CR1_SE                 BIT7
;;   Sample Enable
;;     0b0 ==> Sampling mode is not selected.
;;     0b1 ==> Sampling mode is selected.

 set     CMPA_FPR_FILT_PER           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Filter Sample Period
 set     CMPA_FPR_FILT_PER_0         BIT0
 set     CMPA_FPR_FILT_PER_1         BIT1
 set     CMPA_FPR_FILT_PER_2         BIT2
 set     CMPA_FPR_FILT_PER_3         BIT3
 set     CMPA_FPR_FILT_PER_4         BIT4
 set     CMPA_FPR_FILT_PER_5         BIT5
 set     CMPA_FPR_FILT_PER_6         BIT6
 set     CMPA_FPR_FILT_PER_7         BIT7

 set     CMPA_SCR_COUT               BIT0
;;   Analog Comparator Output

 set     CMPA_SCR_CFF                BIT1
;;   Analog Comparator Flag Falling
;;     0b0 ==> Falling-edge on COUT has not been detected.
;;     0b1 ==> Falling-edge on COUT has occurred.

 set     CMPA_SCR_CFR                BIT2
;;   Analog Comparator Flag Rising
;;     0b0 ==> Rising-edge on COUT has not been detected.
;;     0b1 ==> Rising-edge on COUT has occurred.

 set     CMPA_SCR_IEF                BIT3
;;   Comparator Interrupt Enable Falling
;;     0b0 ==> Interrupt is disabled.
;;     0b1 ==> Interrupt is enabled.

 set     CMPA_SCR_IER                BIT4
;;   Comparator Interrupt Enable Rising
;;     0b0 ==> Interrupt is disabled.
;;     0b1 ==> Interrupt is enabled.

 set     CMPA_DACCR_VOSEL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   DAC Output Voltage Select
 set     CMPA_DACCR_VOSEL_0          BIT0
 set     CMPA_DACCR_VOSEL_1          BIT1
 set     CMPA_DACCR_VOSEL_2          BIT2
 set     CMPA_DACCR_VOSEL_3          BIT3
 set     CMPA_DACCR_VOSEL_4          BIT4
 set     CMPA_DACCR_VOSEL_5          BIT5

 set     CMPA_DACCR_VRSEL            BIT6
;;   Supply Voltage Reference Source Select
;;     0b0 ==> V is selected as resistor ladder network supply reference V. in1 in
;;     0b1 ==> V is selected as resistor ladder network supply reference V. in2 in

 set     CMPA_DACCR_DACEN            BIT7
;;   DAC Enable
;;     0b0 ==> DAC is disabled.
;;     0b1 ==> DAC is enabled.

 set     CMPA_MUXCR_MSEL             (BIT0|BIT1|BIT2)
;;   Minus Input Mux Control
;;     0b000 ==> IN0
;;     0b001 ==> IN1
;;     0b010 ==> IN2
;;     0b011 ==> IN3
;;     0b100 ==> IN4
;;     0b101 ==> IN5
;;     0b110 ==> IN6
;;     0b111 ==> IN7
 set     CMPA_MUXCR_MSEL_0           BIT0
 set     CMPA_MUXCR_MSEL_1           BIT1
 set     CMPA_MUXCR_MSEL_2           BIT2

 set     CMPA_MUXCR_PSEL             (BIT3|BIT4|BIT5)
;;   Plus Input Mux Control
;;     0b000 ==> IN0
;;     0b001 ==> IN1
;;     0b010 ==> IN2
;;     0b011 ==> IN3
;;     0b100 ==> IN4
;;     0b101 ==> IN5
;;     0b110 ==> IN6
;;     0b111 ==> IN7
 set     CMPA_MUXCR_PSEL_0           BIT3
 set     CMPA_MUXCR_PSEL_1           BIT4
 set     CMPA_MUXCR_PSEL_2           BIT5

 set     CMPB_CR0_HYSTCTR            (BIT0|BIT1)
;;   Comparator hard block hysteresis control
;;     0b00 ==> Level 0
;;     0b01 ==> Level 1
;;     0b10 ==> Level 2
;;     0b11 ==> Level 3
 set     CMPB_CR0_HYSTCTR_0          BIT0
 set     CMPB_CR0_HYSTCTR_1          BIT1

 set     CMPB_CR0_FILTER_CNT         (BIT4|BIT5|BIT6)
;;   Filter Sample Count
;;     0b000 ==> Filter is disabled. If SE = 1, then COUT is a logic 0. This is not a legal state, and is not recommended. If SE = 0, COUT = COUTA.
;;     0b001 ==> One sample must agree. The comparator output is simply sampled.
;;     0b010 ==> 2 consecutive samples must agree.
;;     0b011 ==> 3 consecutive samples must agree.
;;     0b100 ==> 4 consecutive samples must agree.
;;     0b101 ==> 5 consecutive samples must agree.
;;     0b110 ==> 6 consecutive samples must agree.
;;     0b111 ==> 7 consecutive samples must agree.
 set     CMPB_CR0_FILTER_CNT_0       BIT4
 set     CMPB_CR0_FILTER_CNT_1       BIT5
 set     CMPB_CR0_FILTER_CNT_2       BIT6

 set     CMPB_CR1_EN                 BIT0
;;   Comparator Module Enable
;;     0b0 ==> Analog Comparator is disabled.
;;     0b1 ==> Analog Comparator is enabled.

 set     CMPB_CR1_OPE                BIT1
;;   Comparator Output Pin Enable
;;     0b0 ==> CMPO is not available on the associated CMPO output pin. If the comparator does not own the pin, this field has no effect.
;;     0b1 ==> CMPO is available on the associated CMPO output pin. The comparator output (CMPO) is driven out on the associated CMPO output pin if the comparator owns the pin. If the comparator does not own the field, this bit has no effect.

 set     CMPB_CR1_COS                BIT2
;;   Comparator Output Select
;;     0b0 ==> Set the filtered comparator output (CMPO) to equal COUT.
;;     0b1 ==> Set the unfiltered comparator output (CMPO) to equal COUTA.

 set     CMPB_CR1_INV                BIT3
;;   Comparator INVERT
;;     0b0 ==> Does not invert the comparator output.
;;     0b1 ==> Inverts the comparator output.

 set     CMPB_CR1_PMODE              BIT4
;;   Power Mode Select
;;     0b0 ==> Low-Speed (LS) Comparison mode selected. In this mode, CMP has slower output propagation delay and lower current consumption.
;;     0b1 ==> High-Speed (HS) Comparison mode selected. In this mode, CMP has faster output propagation delay and higher current consumption.

 set     CMPB_CR1_WE                 BIT6
;;   Windowing Enable
;;     0b0 ==> Windowing mode is not selected.
;;     0b1 ==> Windowing mode is selected.

 set     CMPB_CR1_SE                 BIT7
;;   Sample Enable
;;     0b0 ==> Sampling mode is not selected.
;;     0b1 ==> Sampling mode is selected.

 set     CMPB_FPR_FILT_PER           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Filter Sample Period
 set     CMPB_FPR_FILT_PER_0         BIT0
 set     CMPB_FPR_FILT_PER_1         BIT1
 set     CMPB_FPR_FILT_PER_2         BIT2
 set     CMPB_FPR_FILT_PER_3         BIT3
 set     CMPB_FPR_FILT_PER_4         BIT4
 set     CMPB_FPR_FILT_PER_5         BIT5
 set     CMPB_FPR_FILT_PER_6         BIT6
 set     CMPB_FPR_FILT_PER_7         BIT7

 set     CMPB_SCR_COUT               BIT0
;;   Analog Comparator Output

 set     CMPB_SCR_CFF                BIT1
;;   Analog Comparator Flag Falling
;;     0b0 ==> Falling-edge on COUT has not been detected.
;;     0b1 ==> Falling-edge on COUT has occurred.

 set     CMPB_SCR_CFR                BIT2
;;   Analog Comparator Flag Rising
;;     0b0 ==> Rising-edge on COUT has not been detected.
;;     0b1 ==> Rising-edge on COUT has occurred.

 set     CMPB_SCR_IEF                BIT3
;;   Comparator Interrupt Enable Falling
;;     0b0 ==> Interrupt is disabled.
;;     0b1 ==> Interrupt is enabled.

 set     CMPB_SCR_IER                BIT4
;;   Comparator Interrupt Enable Rising
;;     0b0 ==> Interrupt is disabled.
;;     0b1 ==> Interrupt is enabled.

 set     CMPB_DACCR_VOSEL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   DAC Output Voltage Select
 set     CMPB_DACCR_VOSEL_0          BIT0
 set     CMPB_DACCR_VOSEL_1          BIT1
 set     CMPB_DACCR_VOSEL_2          BIT2
 set     CMPB_DACCR_VOSEL_3          BIT3
 set     CMPB_DACCR_VOSEL_4          BIT4
 set     CMPB_DACCR_VOSEL_5          BIT5

 set     CMPB_DACCR_VRSEL            BIT6
;;   Supply Voltage Reference Source Select
;;     0b0 ==> V is selected as resistor ladder network supply reference V. in1 in
;;     0b1 ==> V is selected as resistor ladder network supply reference V. in2 in

 set     CMPB_DACCR_DACEN            BIT7
;;   DAC Enable
;;     0b0 ==> DAC is disabled.
;;     0b1 ==> DAC is enabled.

 set     CMPB_MUXCR_MSEL             (BIT0|BIT1|BIT2)
;;   Minus Input Mux Control
;;     0b000 ==> IN0
;;     0b001 ==> IN1
;;     0b010 ==> IN2
;;     0b011 ==> IN3
;;     0b100 ==> IN4
;;     0b101 ==> IN5
;;     0b110 ==> IN6
;;     0b111 ==> IN7
 set     CMPB_MUXCR_MSEL_0           BIT0
 set     CMPB_MUXCR_MSEL_1           BIT1
 set     CMPB_MUXCR_MSEL_2           BIT2

 set     CMPB_MUXCR_PSEL             (BIT3|BIT4|BIT5)
;;   Plus Input Mux Control
;;     0b000 ==> IN0
;;     0b001 ==> IN1
;;     0b010 ==> IN2
;;     0b011 ==> IN3
;;     0b100 ==> IN4
;;     0b101 ==> IN5
;;     0b110 ==> IN6
;;     0b111 ==> IN7
 set     CMPB_MUXCR_PSEL_0           BIT3
 set     CMPB_MUXCR_PSEL_1           BIT4
 set     CMPB_MUXCR_PSEL_2           BIT5

 set     CMPC_CR0_HYSTCTR            (BIT0|BIT1)
;;   Comparator hard block hysteresis control
;;     0b00 ==> Level 0
;;     0b01 ==> Level 1
;;     0b10 ==> Level 2
;;     0b11 ==> Level 3
 set     CMPC_CR0_HYSTCTR_0          BIT0
 set     CMPC_CR0_HYSTCTR_1          BIT1

 set     CMPC_CR0_FILTER_CNT         (BIT4|BIT5|BIT6)
;;   Filter Sample Count
;;     0b000 ==> Filter is disabled. If SE = 1, then COUT is a logic 0. This is not a legal state, and is not recommended. If SE = 0, COUT = COUTA.
;;     0b001 ==> One sample must agree. The comparator output is simply sampled.
;;     0b010 ==> 2 consecutive samples must agree.
;;     0b011 ==> 3 consecutive samples must agree.
;;     0b100 ==> 4 consecutive samples must agree.
;;     0b101 ==> 5 consecutive samples must agree.
;;     0b110 ==> 6 consecutive samples must agree.
;;     0b111 ==> 7 consecutive samples must agree.
 set     CMPC_CR0_FILTER_CNT_0       BIT4
 set     CMPC_CR0_FILTER_CNT_1       BIT5
 set     CMPC_CR0_FILTER_CNT_2       BIT6

 set     CMPC_CR1_EN                 BIT0
;;   Comparator Module Enable
;;     0b0 ==> Analog Comparator is disabled.
;;     0b1 ==> Analog Comparator is enabled.

 set     CMPC_CR1_OPE                BIT1
;;   Comparator Output Pin Enable
;;     0b0 ==> CMPO is not available on the associated CMPO output pin. If the comparator does not own the pin, this field has no effect.
;;     0b1 ==> CMPO is available on the associated CMPO output pin. The comparator output (CMPO) is driven out on the associated CMPO output pin if the comparator owns the pin. If the comparator does not own the field, this bit has no effect.

 set     CMPC_CR1_COS                BIT2
;;   Comparator Output Select
;;     0b0 ==> Set the filtered comparator output (CMPO) to equal COUT.
;;     0b1 ==> Set the unfiltered comparator output (CMPO) to equal COUTA.

 set     CMPC_CR1_INV                BIT3
;;   Comparator INVERT
;;     0b0 ==> Does not invert the comparator output.
;;     0b1 ==> Inverts the comparator output.

 set     CMPC_CR1_PMODE              BIT4
;;   Power Mode Select
;;     0b0 ==> Low-Speed (LS) Comparison mode selected. In this mode, CMP has slower output propagation delay and lower current consumption.
;;     0b1 ==> High-Speed (HS) Comparison mode selected. In this mode, CMP has faster output propagation delay and higher current consumption.

 set     CMPC_CR1_WE                 BIT6
;;   Windowing Enable
;;     0b0 ==> Windowing mode is not selected.
;;     0b1 ==> Windowing mode is selected.

 set     CMPC_CR1_SE                 BIT7
;;   Sample Enable
;;     0b0 ==> Sampling mode is not selected.
;;     0b1 ==> Sampling mode is selected.

 set     CMPC_FPR_FILT_PER           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Filter Sample Period
 set     CMPC_FPR_FILT_PER_0         BIT0
 set     CMPC_FPR_FILT_PER_1         BIT1
 set     CMPC_FPR_FILT_PER_2         BIT2
 set     CMPC_FPR_FILT_PER_3         BIT3
 set     CMPC_FPR_FILT_PER_4         BIT4
 set     CMPC_FPR_FILT_PER_5         BIT5
 set     CMPC_FPR_FILT_PER_6         BIT6
 set     CMPC_FPR_FILT_PER_7         BIT7

 set     CMPC_SCR_COUT               BIT0
;;   Analog Comparator Output

 set     CMPC_SCR_CFF                BIT1
;;   Analog Comparator Flag Falling
;;     0b0 ==> Falling-edge on COUT has not been detected.
;;     0b1 ==> Falling-edge on COUT has occurred.

 set     CMPC_SCR_CFR                BIT2
;;   Analog Comparator Flag Rising
;;     0b0 ==> Rising-edge on COUT has not been detected.
;;     0b1 ==> Rising-edge on COUT has occurred.

 set     CMPC_SCR_IEF                BIT3
;;   Comparator Interrupt Enable Falling
;;     0b0 ==> Interrupt is disabled.
;;     0b1 ==> Interrupt is enabled.

 set     CMPC_SCR_IER                BIT4
;;   Comparator Interrupt Enable Rising
;;     0b0 ==> Interrupt is disabled.
;;     0b1 ==> Interrupt is enabled.

 set     CMPC_DACCR_VOSEL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   DAC Output Voltage Select
 set     CMPC_DACCR_VOSEL_0          BIT0
 set     CMPC_DACCR_VOSEL_1          BIT1
 set     CMPC_DACCR_VOSEL_2          BIT2
 set     CMPC_DACCR_VOSEL_3          BIT3
 set     CMPC_DACCR_VOSEL_4          BIT4
 set     CMPC_DACCR_VOSEL_5          BIT5

 set     CMPC_DACCR_VRSEL            BIT6
;;   Supply Voltage Reference Source Select
;;     0b0 ==> V is selected as resistor ladder network supply reference V. in1 in
;;     0b1 ==> V is selected as resistor ladder network supply reference V. in2 in

 set     CMPC_DACCR_DACEN            BIT7
;;   DAC Enable
;;     0b0 ==> DAC is disabled.
;;     0b1 ==> DAC is enabled.

 set     CMPC_MUXCR_MSEL             (BIT0|BIT1|BIT2)
;;   Minus Input Mux Control
;;     0b000 ==> IN0
;;     0b001 ==> IN1
;;     0b010 ==> IN2
;;     0b011 ==> IN3
;;     0b100 ==> IN4
;;     0b101 ==> IN5
;;     0b110 ==> IN6
;;     0b111 ==> IN7
 set     CMPC_MUXCR_MSEL_0           BIT0
 set     CMPC_MUXCR_MSEL_1           BIT1
 set     CMPC_MUXCR_MSEL_2           BIT2

 set     CMPC_MUXCR_PSEL             (BIT3|BIT4|BIT5)
;;   Plus Input Mux Control
;;     0b000 ==> IN0
;;     0b001 ==> IN1
;;     0b010 ==> IN2
;;     0b011 ==> IN3
;;     0b100 ==> IN4
;;     0b101 ==> IN5
;;     0b110 ==> IN6
;;     0b111 ==> IN7
 set     CMPC_MUXCR_PSEL_0           BIT3
 set     CMPC_MUXCR_PSEL_1           BIT4
 set     CMPC_MUXCR_PSEL_2           BIT5

 set     CMPD_CR0_HYSTCTR            (BIT0|BIT1)
;;   Comparator hard block hysteresis control
;;     0b00 ==> Level 0
;;     0b01 ==> Level 1
;;     0b10 ==> Level 2
;;     0b11 ==> Level 3
 set     CMPD_CR0_HYSTCTR_0          BIT0
 set     CMPD_CR0_HYSTCTR_1          BIT1

 set     CMPD_CR0_FILTER_CNT         (BIT4|BIT5|BIT6)
;;   Filter Sample Count
;;     0b000 ==> Filter is disabled. If SE = 1, then COUT is a logic 0. This is not a legal state, and is not recommended. If SE = 0, COUT = COUTA.
;;     0b001 ==> One sample must agree. The comparator output is simply sampled.
;;     0b010 ==> 2 consecutive samples must agree.
;;     0b011 ==> 3 consecutive samples must agree.
;;     0b100 ==> 4 consecutive samples must agree.
;;     0b101 ==> 5 consecutive samples must agree.
;;     0b110 ==> 6 consecutive samples must agree.
;;     0b111 ==> 7 consecutive samples must agree.
 set     CMPD_CR0_FILTER_CNT_0       BIT4
 set     CMPD_CR0_FILTER_CNT_1       BIT5
 set     CMPD_CR0_FILTER_CNT_2       BIT6

 set     CMPD_CR1_EN                 BIT0
;;   Comparator Module Enable
;;     0b0 ==> Analog Comparator is disabled.
;;     0b1 ==> Analog Comparator is enabled.

 set     CMPD_CR1_OPE                BIT1
;;   Comparator Output Pin Enable
;;     0b0 ==> CMPO is not available on the associated CMPO output pin. If the comparator does not own the pin, this field has no effect.
;;     0b1 ==> CMPO is available on the associated CMPO output pin. The comparator output (CMPO) is driven out on the associated CMPO output pin if the comparator owns the pin. If the comparator does not own the field, this bit has no effect.

 set     CMPD_CR1_COS                BIT2
;;   Comparator Output Select
;;     0b0 ==> Set the filtered comparator output (CMPO) to equal COUT.
;;     0b1 ==> Set the unfiltered comparator output (CMPO) to equal COUTA.

 set     CMPD_CR1_INV                BIT3
;;   Comparator INVERT
;;     0b0 ==> Does not invert the comparator output.
;;     0b1 ==> Inverts the comparator output.

 set     CMPD_CR1_PMODE              BIT4
;;   Power Mode Select
;;     0b0 ==> Low-Speed (LS) Comparison mode selected. In this mode, CMP has slower output propagation delay and lower current consumption.
;;     0b1 ==> High-Speed (HS) Comparison mode selected. In this mode, CMP has faster output propagation delay and higher current consumption.

 set     CMPD_CR1_WE                 BIT6
;;   Windowing Enable
;;     0b0 ==> Windowing mode is not selected.
;;     0b1 ==> Windowing mode is selected.

 set     CMPD_CR1_SE                 BIT7
;;   Sample Enable
;;     0b0 ==> Sampling mode is not selected.
;;     0b1 ==> Sampling mode is selected.

 set     CMPD_FPR_FILT_PER           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Filter Sample Period
 set     CMPD_FPR_FILT_PER_0         BIT0
 set     CMPD_FPR_FILT_PER_1         BIT1
 set     CMPD_FPR_FILT_PER_2         BIT2
 set     CMPD_FPR_FILT_PER_3         BIT3
 set     CMPD_FPR_FILT_PER_4         BIT4
 set     CMPD_FPR_FILT_PER_5         BIT5
 set     CMPD_FPR_FILT_PER_6         BIT6
 set     CMPD_FPR_FILT_PER_7         BIT7

 set     CMPD_SCR_COUT               BIT0
;;   Analog Comparator Output

 set     CMPD_SCR_CFF                BIT1
;;   Analog Comparator Flag Falling
;;     0b0 ==> Falling-edge on COUT has not been detected.
;;     0b1 ==> Falling-edge on COUT has occurred.

 set     CMPD_SCR_CFR                BIT2
;;   Analog Comparator Flag Rising
;;     0b0 ==> Rising-edge on COUT has not been detected.
;;     0b1 ==> Rising-edge on COUT has occurred.

 set     CMPD_SCR_IEF                BIT3
;;   Comparator Interrupt Enable Falling
;;     0b0 ==> Interrupt is disabled.
;;     0b1 ==> Interrupt is enabled.

 set     CMPD_SCR_IER                BIT4
;;   Comparator Interrupt Enable Rising
;;     0b0 ==> Interrupt is disabled.
;;     0b1 ==> Interrupt is enabled.

 set     CMPD_DACCR_VOSEL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   DAC Output Voltage Select
 set     CMPD_DACCR_VOSEL_0          BIT0
 set     CMPD_DACCR_VOSEL_1          BIT1
 set     CMPD_DACCR_VOSEL_2          BIT2
 set     CMPD_DACCR_VOSEL_3          BIT3
 set     CMPD_DACCR_VOSEL_4          BIT4
 set     CMPD_DACCR_VOSEL_5          BIT5

 set     CMPD_DACCR_VRSEL            BIT6
;;   Supply Voltage Reference Source Select
;;     0b0 ==> V is selected as resistor ladder network supply reference V. in1 in
;;     0b1 ==> V is selected as resistor ladder network supply reference V. in2 in

 set     CMPD_DACCR_DACEN            BIT7
;;   DAC Enable
;;     0b0 ==> DAC is disabled.
;;     0b1 ==> DAC is enabled.

 set     CMPD_MUXCR_MSEL             (BIT0|BIT1|BIT2)
;;   Minus Input Mux Control
;;     0b000 ==> IN0
;;     0b001 ==> IN1
;;     0b010 ==> IN2
;;     0b011 ==> IN3
;;     0b100 ==> IN4
;;     0b101 ==> IN5
;;     0b110 ==> IN6
;;     0b111 ==> IN7
 set     CMPD_MUXCR_MSEL_0           BIT0
 set     CMPD_MUXCR_MSEL_1           BIT1
 set     CMPD_MUXCR_MSEL_2           BIT2

 set     CMPD_MUXCR_PSEL             (BIT3|BIT4|BIT5)
;;   Plus Input Mux Control
;;     0b000 ==> IN0
;;     0b001 ==> IN1
;;     0b010 ==> IN2
;;     0b011 ==> IN3
;;     0b100 ==> IN4
;;     0b101 ==> IN5
;;     0b110 ==> IN6
;;     0b111 ==> IN7
 set     CMPD_MUXCR_PSEL_0           BIT3
 set     CMPD_MUXCR_PSEL_1           BIT4
 set     CMPD_MUXCR_PSEL_2           BIT5

 set     COP_CTRL_CWP                BIT0
;;   COP Write Protect
;;     0b0 ==> The CTRL, INTVAL , WINDOW and TOUT registers are readable and writable. (default)
;;     0b1 ==> The CTRL, INTVAL , WINDOW and TOUT registers are read-only.

 set     COP_CTRL_CEN                BIT1
;;   COP Enable
;;     0b0 ==> COP counter is disabled.
;;     0b1 ==> COP counter is enabled. (default)

 set     COP_CTRL_CWEN               BIT2
;;   COP Wait Mode Enable
;;     0b0 ==> COP counter stops in wait mode. (default)
;;     0b1 ==> COP counter runs in wait mode if CEN is set to one.

 set     COP_CTRL_CSEN               BIT3
;;   COP Stop Mode Enable
;;     0b0 ==> COP counter stops in stop mode. (default)
;;     0b1 ==> COP counter runs in stop mode if CEN is set to one.

 set     COP_CTRL_CLOREN             BIT4
;;   COP Loss of Reference Enable
;;     0b0 ==> COP loss of reference counter is disabled. (default)
;;     0b1 ==> COP loss of reference counter is enabled.

 set     COP_CTRL_CLKSEL             (BIT5|BIT6)
;;   Clock Source Select
;;     0b00 ==> Relaxation oscillator output (ROSC) is used to clock the counter (default)
;;     0b01 ==> Crystal oscillator output (COSC) is used to clock the counter
;;     0b10 ==> IP bus clock is used to clock the counter Do not select the IP bus clock to clock the counter if the application requires the COP to wake the device from stop mode.
;;     0b11 ==> Low speed oscillator is used to clock the counter
 set     COP_CTRL_CLKSEL_0           BIT5
 set     COP_CTRL_CLKSEL_1           BIT6

 set     COP_CTRL_INTEN              BIT7
;;   Interrupt Enable
;;     0b0 ==> COP interrupt is disabled. (default)
;;     0b1 ==> COP interrupt is enabled.

 set     COP_CTRL_PSS                (BIT8|BIT9)
;;   Prescaler Select
;;     0b00 ==> No division
;;     0b01 ==> Divide by 16
;;     0b10 ==> Divide by 256
;;     0b11 ==> Divide by 1024
 set     COP_CTRL_PSS_0              BIT8
 set     COP_CTRL_PSS_1              BIT9

 set     COP_TOUT_TIMEOUT            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   COP Timeout Period
 set     COP_TOUT_TIMEOUT_0          BIT0
 set     COP_TOUT_TIMEOUT_1          BIT1
 set     COP_TOUT_TIMEOUT_2          BIT2
 set     COP_TOUT_TIMEOUT_3          BIT3
 set     COP_TOUT_TIMEOUT_4          BIT4
 set     COP_TOUT_TIMEOUT_5          BIT5
 set     COP_TOUT_TIMEOUT_6          BIT6
 set     COP_TOUT_TIMEOUT_7          BIT7
 set     COP_TOUT_TIMEOUT_8          BIT8
 set     COP_TOUT_TIMEOUT_9          BIT9
 set     COP_TOUT_TIMEOUT_10         BIT10
 set     COP_TOUT_TIMEOUT_11         BIT11
 set     COP_TOUT_TIMEOUT_12         BIT12
 set     COP_TOUT_TIMEOUT_13         BIT13
 set     COP_TOUT_TIMEOUT_14         BIT14
 set     COP_TOUT_TIMEOUT_15         BIT15

 set     COP_CNTR_COUNT_SERVICE      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   COP Count/Service
 set     COP_CNTR_COUNT_SERVICE_0    BIT0
 set     COP_CNTR_COUNT_SERVICE_1    BIT1
 set     COP_CNTR_COUNT_SERVICE_2    BIT2
 set     COP_CNTR_COUNT_SERVICE_3    BIT3
 set     COP_CNTR_COUNT_SERVICE_4    BIT4
 set     COP_CNTR_COUNT_SERVICE_5    BIT5
 set     COP_CNTR_COUNT_SERVICE_6    BIT6
 set     COP_CNTR_COUNT_SERVICE_7    BIT7
 set     COP_CNTR_COUNT_SERVICE_8    BIT8
 set     COP_CNTR_COUNT_SERVICE_9    BIT9
 set     COP_CNTR_COUNT_SERVICE_10   BIT10
 set     COP_CNTR_COUNT_SERVICE_11   BIT11
 set     COP_CNTR_COUNT_SERVICE_12   BIT12
 set     COP_CNTR_COUNT_SERVICE_13   BIT13
 set     COP_CNTR_COUNT_SERVICE_14   BIT14
 set     COP_CNTR_COUNT_SERVICE_15   BIT15

 set     COP_INTVAL_INTERRUPT_VALUE  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   COP Interrupt Value
 set     COP_INTVAL_INTERRUPT_VALUE_0 BIT0
 set     COP_INTVAL_INTERRUPT_VALUE_1 BIT1
 set     COP_INTVAL_INTERRUPT_VALUE_2 BIT2
 set     COP_INTVAL_INTERRUPT_VALUE_3 BIT3
 set     COP_INTVAL_INTERRUPT_VALUE_4 BIT4
 set     COP_INTVAL_INTERRUPT_VALUE_5 BIT5
 set     COP_INTVAL_INTERRUPT_VALUE_6 BIT6
 set     COP_INTVAL_INTERRUPT_VALUE_7 BIT7
 set     COP_INTVAL_INTERRUPT_VALUE_8 BIT8
 set     COP_INTVAL_INTERRUPT_VALUE_9 BIT9
 set     COP_INTVAL_INTERRUPT_VALUE_10 BIT10
 set     COP_INTVAL_INTERRUPT_VALUE_11 BIT11
 set     COP_INTVAL_INTERRUPT_VALUE_12 BIT12
 set     COP_INTVAL_INTERRUPT_VALUE_13 BIT13
 set     COP_INTVAL_INTERRUPT_VALUE_14 BIT14
 set     COP_INTVAL_INTERRUPT_VALUE_15 BIT15

 set     COP_WINDOW_WINDOW_VALUE     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   COP Window Timeout Value
 set     COP_WINDOW_WINDOW_VALUE_0   BIT0
 set     COP_WINDOW_WINDOW_VALUE_1   BIT1
 set     COP_WINDOW_WINDOW_VALUE_2   BIT2
 set     COP_WINDOW_WINDOW_VALUE_3   BIT3
 set     COP_WINDOW_WINDOW_VALUE_4   BIT4
 set     COP_WINDOW_WINDOW_VALUE_5   BIT5
 set     COP_WINDOW_WINDOW_VALUE_6   BIT6
 set     COP_WINDOW_WINDOW_VALUE_7   BIT7
 set     COP_WINDOW_WINDOW_VALUE_8   BIT8
 set     COP_WINDOW_WINDOW_VALUE_9   BIT9
 set     COP_WINDOW_WINDOW_VALUE_10  BIT10
 set     COP_WINDOW_WINDOW_VALUE_11  BIT11
 set     COP_WINDOW_WINDOW_VALUE_12  BIT12
 set     COP_WINDOW_WINDOW_VALUE_13  BIT13
 set     COP_WINDOW_WINDOW_VALUE_14  BIT14
 set     COP_WINDOW_WINDOW_VALUE_15  BIT15

 set     CRC_CRCH_CRCH               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     CRC_CRCH_CRCH_0             BIT0
 set     CRC_CRCH_CRCH_1             BIT1
 set     CRC_CRCH_CRCH_2             BIT2
 set     CRC_CRCH_CRCH_3             BIT3
 set     CRC_CRCH_CRCH_4             BIT4
 set     CRC_CRCH_CRCH_5             BIT5
 set     CRC_CRCH_CRCH_6             BIT6
 set     CRC_CRCH_CRCH_7             BIT7

 set     CRC_CRCL_CRCL               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     CRC_CRCL_CRCL_0             BIT0
 set     CRC_CRCL_CRCL_1             BIT1
 set     CRC_CRCL_CRCL_2             BIT2
 set     CRC_CRCL_CRCL_3             BIT3
 set     CRC_CRCL_CRCL_4             BIT4
 set     CRC_CRCL_CRCL_5             BIT5
 set     CRC_CRCL_CRCL_6             BIT6
 set     CRC_CRCL_CRCL_7             BIT7

 set     CRC_TRANSPOSE_TRANSPOSE     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     CRC_TRANSPOSE_TRANSPOSE_0   BIT0
 set     CRC_TRANSPOSE_TRANSPOSE_1   BIT1
 set     CRC_TRANSPOSE_TRANSPOSE_2   BIT2
 set     CRC_TRANSPOSE_TRANSPOSE_3   BIT3
 set     CRC_TRANSPOSE_TRANSPOSE_4   BIT4
 set     CRC_TRANSPOSE_TRANSPOSE_5   BIT5
 set     CRC_TRANSPOSE_TRANSPOSE_6   BIT6
 set     CRC_TRANSPOSE_TRANSPOSE_7   BIT7

 set     DACA_CTRL0_PDN              BIT0
;;   Power Down
;;     0b0 ==> DAC is operational.
;;     0b1 ==> DAC is powered down. (default)

 set     DACA_CTRL0_FORMAT           BIT1
;;   Data Format
;;     0b0 ==> Data words are right justified. (default)
;;     0b1 ==> Data words are left justified.

 set     DACA_CTRL0_SYNC_EN          BIT2
;;   Sync Enable
;;     0b0 ==> Asynchronous mode. Data written to the buffered data register is presented to DAC inputs on the next clock cycle.
;;     0b1 ==> Synchronous mode. Rising edge of SYNC_IN updates data in the buffered data register presented to the DAC input.

 set     DACA_CTRL0_AUTO             BIT3
;;   Automatic Mode
;;     0b0 ==> Normal mode. Automatic waveform generation disabled.
;;     0b1 ==> Automatic waveform generation enabled.

 set     DACA_CTRL0_DOWN             BIT4
;;   Enable Down Counting
;;     0b0 ==> Down counting disabled.
;;     0b1 ==> Down counting enabled.

 set     DACA_CTRL0_UP               BIT5
;;   Enable Up Counting
;;     0b0 ==> Up counting disabled.
;;     0b1 ==> Up counting enabled.

 set     DACA_CTRL0_HSLS             BIT6
;;   High/Low Speed
;;     0b0 ==> High speed mode (default)
;;     0b1 ==> Low speed mode

 set     DACA_CTRL0_DMA_EN           BIT7
;;   Enable DMA Support
;;     0b0 ==> DMA support disabled (default)
;;     0b1 ==> DMA support enabled

 set     DACA_CTRL0_WTMK_LVL         (BIT8|BIT9)
;;   Watermark Level
;;     0b00 ==> Watermark value is 0
;;     0b01 ==> Watermark value is 2 (default)
;;     0b10 ==> Watermark value is 4
;;     0b11 ==> Watermark value is 6
 set     DACA_CTRL0_WTMK_LVL_0       BIT8
 set     DACA_CTRL0_WTMK_LVL_1       BIT9

 set     DACA_CTRL0_FILT_EN          BIT12
;;   Glitch Filter Enable
;;     0b0 ==> Filter disabled.
;;     0b1 ==> Filter enabled.

 set     DACA_DATAREG_FMT0_DATA      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11)
;;   DAC data (right justified)
 set     DACA_DATAREG_FMT0_DATA_0    BIT0
 set     DACA_DATAREG_FMT0_DATA_1    BIT1
 set     DACA_DATAREG_FMT0_DATA_2    BIT2
 set     DACA_DATAREG_FMT0_DATA_3    BIT3
 set     DACA_DATAREG_FMT0_DATA_4    BIT4
 set     DACA_DATAREG_FMT0_DATA_5    BIT5
 set     DACA_DATAREG_FMT0_DATA_6    BIT6
 set     DACA_DATAREG_FMT0_DATA_7    BIT7
 set     DACA_DATAREG_FMT0_DATA_8    BIT8
 set     DACA_DATAREG_FMT0_DATA_9    BIT9
 set     DACA_DATAREG_FMT0_DATA_10   BIT10
 set     DACA_DATAREG_FMT0_DATA_11   BIT11

 set     DACA_DATAREG_FMT1_DATA      (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   DAC data (left justified)
 set     DACA_DATAREG_FMT1_DATA_0    BIT4
 set     DACA_DATAREG_FMT1_DATA_1    BIT5
 set     DACA_DATAREG_FMT1_DATA_2    BIT6
 set     DACA_DATAREG_FMT1_DATA_3    BIT7
 set     DACA_DATAREG_FMT1_DATA_4    BIT8
 set     DACA_DATAREG_FMT1_DATA_5    BIT9
 set     DACA_DATAREG_FMT1_DATA_6    BIT10
 set     DACA_DATAREG_FMT1_DATA_7    BIT11
 set     DACA_DATAREG_FMT1_DATA_8    BIT12
 set     DACA_DATAREG_FMT1_DATA_9    BIT13
 set     DACA_DATAREG_FMT1_DATA_10   BIT14
 set     DACA_DATAREG_FMT1_DATA_11   BIT15

 set     DACA_STEPVAL_FMT0_STEP      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11)
;;   STEP size (right justified)
 set     DACA_STEPVAL_FMT0_STEP_0    BIT0
 set     DACA_STEPVAL_FMT0_STEP_1    BIT1
 set     DACA_STEPVAL_FMT0_STEP_2    BIT2
 set     DACA_STEPVAL_FMT0_STEP_3    BIT3
 set     DACA_STEPVAL_FMT0_STEP_4    BIT4
 set     DACA_STEPVAL_FMT0_STEP_5    BIT5
 set     DACA_STEPVAL_FMT0_STEP_6    BIT6
 set     DACA_STEPVAL_FMT0_STEP_7    BIT7
 set     DACA_STEPVAL_FMT0_STEP_8    BIT8
 set     DACA_STEPVAL_FMT0_STEP_9    BIT9
 set     DACA_STEPVAL_FMT0_STEP_10   BIT10
 set     DACA_STEPVAL_FMT0_STEP_11   BIT11

 set     DACA_STEPVAL_FMT1_STEP      (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   STEP size (left justified)
 set     DACA_STEPVAL_FMT1_STEP_0    BIT4
 set     DACA_STEPVAL_FMT1_STEP_1    BIT5
 set     DACA_STEPVAL_FMT1_STEP_2    BIT6
 set     DACA_STEPVAL_FMT1_STEP_3    BIT7
 set     DACA_STEPVAL_FMT1_STEP_4    BIT8
 set     DACA_STEPVAL_FMT1_STEP_5    BIT9
 set     DACA_STEPVAL_FMT1_STEP_6    BIT10
 set     DACA_STEPVAL_FMT1_STEP_7    BIT11
 set     DACA_STEPVAL_FMT1_STEP_8    BIT12
 set     DACA_STEPVAL_FMT1_STEP_9    BIT13
 set     DACA_STEPVAL_FMT1_STEP_10   BIT14
 set     DACA_STEPVAL_FMT1_STEP_11   BIT15

 set     DACA_MINVAL_FMT0_MINVAL     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11)
;;   Minimum value (right justified)
 set     DACA_MINVAL_FMT0_MINVAL_0   BIT0
 set     DACA_MINVAL_FMT0_MINVAL_1   BIT1
 set     DACA_MINVAL_FMT0_MINVAL_2   BIT2
 set     DACA_MINVAL_FMT0_MINVAL_3   BIT3
 set     DACA_MINVAL_FMT0_MINVAL_4   BIT4
 set     DACA_MINVAL_FMT0_MINVAL_5   BIT5
 set     DACA_MINVAL_FMT0_MINVAL_6   BIT6
 set     DACA_MINVAL_FMT0_MINVAL_7   BIT7
 set     DACA_MINVAL_FMT0_MINVAL_8   BIT8
 set     DACA_MINVAL_FMT0_MINVAL_9   BIT9
 set     DACA_MINVAL_FMT0_MINVAL_10  BIT10
 set     DACA_MINVAL_FMT0_MINVAL_11  BIT11

 set     DACA_MINVAL_FMT1_MINVAL     (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Minimum value (left justified)
 set     DACA_MINVAL_FMT1_MINVAL_0   BIT4
 set     DACA_MINVAL_FMT1_MINVAL_1   BIT5
 set     DACA_MINVAL_FMT1_MINVAL_2   BIT6
 set     DACA_MINVAL_FMT1_MINVAL_3   BIT7
 set     DACA_MINVAL_FMT1_MINVAL_4   BIT8
 set     DACA_MINVAL_FMT1_MINVAL_5   BIT9
 set     DACA_MINVAL_FMT1_MINVAL_6   BIT10
 set     DACA_MINVAL_FMT1_MINVAL_7   BIT11
 set     DACA_MINVAL_FMT1_MINVAL_8   BIT12
 set     DACA_MINVAL_FMT1_MINVAL_9   BIT13
 set     DACA_MINVAL_FMT1_MINVAL_10  BIT14
 set     DACA_MINVAL_FMT1_MINVAL_11  BIT15

 set     DACA_MAXVAL_FMT0_MAXVAL     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11)
;;   Maximum value (right justified)
 set     DACA_MAXVAL_FMT0_MAXVAL_0   BIT0
 set     DACA_MAXVAL_FMT0_MAXVAL_1   BIT1
 set     DACA_MAXVAL_FMT0_MAXVAL_2   BIT2
 set     DACA_MAXVAL_FMT0_MAXVAL_3   BIT3
 set     DACA_MAXVAL_FMT0_MAXVAL_4   BIT4
 set     DACA_MAXVAL_FMT0_MAXVAL_5   BIT5
 set     DACA_MAXVAL_FMT0_MAXVAL_6   BIT6
 set     DACA_MAXVAL_FMT0_MAXVAL_7   BIT7
 set     DACA_MAXVAL_FMT0_MAXVAL_8   BIT8
 set     DACA_MAXVAL_FMT0_MAXVAL_9   BIT9
 set     DACA_MAXVAL_FMT0_MAXVAL_10  BIT10
 set     DACA_MAXVAL_FMT0_MAXVAL_11  BIT11

 set     DACA_MAXVAL_FMT1_MAXVAL     (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Maximum value (left justified)
 set     DACA_MAXVAL_FMT1_MAXVAL_0   BIT4
 set     DACA_MAXVAL_FMT1_MAXVAL_1   BIT5
 set     DACA_MAXVAL_FMT1_MAXVAL_2   BIT6
 set     DACA_MAXVAL_FMT1_MAXVAL_3   BIT7
 set     DACA_MAXVAL_FMT1_MAXVAL_4   BIT8
 set     DACA_MAXVAL_FMT1_MAXVAL_5   BIT9
 set     DACA_MAXVAL_FMT1_MAXVAL_6   BIT10
 set     DACA_MAXVAL_FMT1_MAXVAL_7   BIT11
 set     DACA_MAXVAL_FMT1_MAXVAL_8   BIT12
 set     DACA_MAXVAL_FMT1_MAXVAL_9   BIT13
 set     DACA_MAXVAL_FMT1_MAXVAL_10  BIT14
 set     DACA_MAXVAL_FMT1_MAXVAL_11  BIT15

 set     DACA_STATUS_EMPTY           BIT0
;;   Indicates empty status of FIFO
;;     0b0 ==> FIFO is not empty.
;;     0b1 ==> FIFO is empty (on reset).

 set     DACA_STATUS_FULL            BIT1
;;   Indicates full status of FIFO
;;     0b0 ==> FIFO is not full (on reset).
;;     0b1 ==> FIFO is full.

 set     DACA_CTRL1_FILT_CNT         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Glitch Filter Count
 set     DACA_CTRL1_FILT_CNT_0       BIT0
 set     DACA_CTRL1_FILT_CNT_1       BIT1
 set     DACA_CTRL1_FILT_CNT_2       BIT2
 set     DACA_CTRL1_FILT_CNT_3       BIT3
 set     DACA_CTRL1_FILT_CNT_4       BIT4
 set     DACA_CTRL1_FILT_CNT_5       BIT5

 set     DACB_CTRL0_PDN              BIT0
;;   Power Down
;;     0b0 ==> DAC is operational.
;;     0b1 ==> DAC is powered down. (default)

 set     DACB_CTRL0_FORMAT           BIT1
;;   Data Format
;;     0b0 ==> Data words are right justified. (default)
;;     0b1 ==> Data words are left justified.

 set     DACB_CTRL0_SYNC_EN          BIT2
;;   Sync Enable
;;     0b0 ==> Asynchronous mode. Data written to the buffered data register is presented to DAC inputs on the next clock cycle.
;;     0b1 ==> Synchronous mode. Rising edge of SYNC_IN updates data in the buffered data register presented to the DAC input.

 set     DACB_CTRL0_AUTO             BIT3
;;   Automatic Mode
;;     0b0 ==> Normal mode. Automatic waveform generation disabled.
;;     0b1 ==> Automatic waveform generation enabled.

 set     DACB_CTRL0_DOWN             BIT4
;;   Enable Down Counting
;;     0b0 ==> Down counting disabled.
;;     0b1 ==> Down counting enabled.

 set     DACB_CTRL0_UP               BIT5
;;   Enable Up Counting
;;     0b0 ==> Up counting disabled.
;;     0b1 ==> Up counting enabled.

 set     DACB_CTRL0_HSLS             BIT6
;;   High/Low Speed
;;     0b0 ==> High speed mode (default)
;;     0b1 ==> Low speed mode

 set     DACB_CTRL0_DMA_EN           BIT7
;;   Enable DMA Support
;;     0b0 ==> DMA support disabled (default)
;;     0b1 ==> DMA support enabled

 set     DACB_CTRL0_WTMK_LVL         (BIT8|BIT9)
;;   Watermark Level
;;     0b00 ==> Watermark value is 0
;;     0b01 ==> Watermark value is 2 (default)
;;     0b10 ==> Watermark value is 4
;;     0b11 ==> Watermark value is 6
 set     DACB_CTRL0_WTMK_LVL_0       BIT8
 set     DACB_CTRL0_WTMK_LVL_1       BIT9

 set     DACB_CTRL0_FILT_EN          BIT12
;;   Glitch Filter Enable
;;     0b0 ==> Filter disabled.
;;     0b1 ==> Filter enabled.

 set     DACB_DATAREG_FMT0_DATA      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11)
;;   DAC data (right justified)
 set     DACB_DATAREG_FMT0_DATA_0    BIT0
 set     DACB_DATAREG_FMT0_DATA_1    BIT1
 set     DACB_DATAREG_FMT0_DATA_2    BIT2
 set     DACB_DATAREG_FMT0_DATA_3    BIT3
 set     DACB_DATAREG_FMT0_DATA_4    BIT4
 set     DACB_DATAREG_FMT0_DATA_5    BIT5
 set     DACB_DATAREG_FMT0_DATA_6    BIT6
 set     DACB_DATAREG_FMT0_DATA_7    BIT7
 set     DACB_DATAREG_FMT0_DATA_8    BIT8
 set     DACB_DATAREG_FMT0_DATA_9    BIT9
 set     DACB_DATAREG_FMT0_DATA_10   BIT10
 set     DACB_DATAREG_FMT0_DATA_11   BIT11

 set     DACB_DATAREG_FMT1_DATA      (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   DAC data (left justified)
 set     DACB_DATAREG_FMT1_DATA_0    BIT4
 set     DACB_DATAREG_FMT1_DATA_1    BIT5
 set     DACB_DATAREG_FMT1_DATA_2    BIT6
 set     DACB_DATAREG_FMT1_DATA_3    BIT7
 set     DACB_DATAREG_FMT1_DATA_4    BIT8
 set     DACB_DATAREG_FMT1_DATA_5    BIT9
 set     DACB_DATAREG_FMT1_DATA_6    BIT10
 set     DACB_DATAREG_FMT1_DATA_7    BIT11
 set     DACB_DATAREG_FMT1_DATA_8    BIT12
 set     DACB_DATAREG_FMT1_DATA_9    BIT13
 set     DACB_DATAREG_FMT1_DATA_10   BIT14
 set     DACB_DATAREG_FMT1_DATA_11   BIT15

 set     DACB_STEPVAL_FMT0_STEP      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11)
;;   STEP size (right justified)
 set     DACB_STEPVAL_FMT0_STEP_0    BIT0
 set     DACB_STEPVAL_FMT0_STEP_1    BIT1
 set     DACB_STEPVAL_FMT0_STEP_2    BIT2
 set     DACB_STEPVAL_FMT0_STEP_3    BIT3
 set     DACB_STEPVAL_FMT0_STEP_4    BIT4
 set     DACB_STEPVAL_FMT0_STEP_5    BIT5
 set     DACB_STEPVAL_FMT0_STEP_6    BIT6
 set     DACB_STEPVAL_FMT0_STEP_7    BIT7
 set     DACB_STEPVAL_FMT0_STEP_8    BIT8
 set     DACB_STEPVAL_FMT0_STEP_9    BIT9
 set     DACB_STEPVAL_FMT0_STEP_10   BIT10
 set     DACB_STEPVAL_FMT0_STEP_11   BIT11

 set     DACB_STEPVAL_FMT1_STEP      (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   STEP size (left justified)
 set     DACB_STEPVAL_FMT1_STEP_0    BIT4
 set     DACB_STEPVAL_FMT1_STEP_1    BIT5
 set     DACB_STEPVAL_FMT1_STEP_2    BIT6
 set     DACB_STEPVAL_FMT1_STEP_3    BIT7
 set     DACB_STEPVAL_FMT1_STEP_4    BIT8
 set     DACB_STEPVAL_FMT1_STEP_5    BIT9
 set     DACB_STEPVAL_FMT1_STEP_6    BIT10
 set     DACB_STEPVAL_FMT1_STEP_7    BIT11
 set     DACB_STEPVAL_FMT1_STEP_8    BIT12
 set     DACB_STEPVAL_FMT1_STEP_9    BIT13
 set     DACB_STEPVAL_FMT1_STEP_10   BIT14
 set     DACB_STEPVAL_FMT1_STEP_11   BIT15

 set     DACB_MINVAL_FMT0_MINVAL     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11)
;;   Minimum value (right justified)
 set     DACB_MINVAL_FMT0_MINVAL_0   BIT0
 set     DACB_MINVAL_FMT0_MINVAL_1   BIT1
 set     DACB_MINVAL_FMT0_MINVAL_2   BIT2
 set     DACB_MINVAL_FMT0_MINVAL_3   BIT3
 set     DACB_MINVAL_FMT0_MINVAL_4   BIT4
 set     DACB_MINVAL_FMT0_MINVAL_5   BIT5
 set     DACB_MINVAL_FMT0_MINVAL_6   BIT6
 set     DACB_MINVAL_FMT0_MINVAL_7   BIT7
 set     DACB_MINVAL_FMT0_MINVAL_8   BIT8
 set     DACB_MINVAL_FMT0_MINVAL_9   BIT9
 set     DACB_MINVAL_FMT0_MINVAL_10  BIT10
 set     DACB_MINVAL_FMT0_MINVAL_11  BIT11

 set     DACB_MINVAL_FMT1_MINVAL     (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Minimum value (left justified)
 set     DACB_MINVAL_FMT1_MINVAL_0   BIT4
 set     DACB_MINVAL_FMT1_MINVAL_1   BIT5
 set     DACB_MINVAL_FMT1_MINVAL_2   BIT6
 set     DACB_MINVAL_FMT1_MINVAL_3   BIT7
 set     DACB_MINVAL_FMT1_MINVAL_4   BIT8
 set     DACB_MINVAL_FMT1_MINVAL_5   BIT9
 set     DACB_MINVAL_FMT1_MINVAL_6   BIT10
 set     DACB_MINVAL_FMT1_MINVAL_7   BIT11
 set     DACB_MINVAL_FMT1_MINVAL_8   BIT12
 set     DACB_MINVAL_FMT1_MINVAL_9   BIT13
 set     DACB_MINVAL_FMT1_MINVAL_10  BIT14
 set     DACB_MINVAL_FMT1_MINVAL_11  BIT15

 set     DACB_MAXVAL_FMT0_MAXVAL     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11)
;;   Maximum value (right justified)
 set     DACB_MAXVAL_FMT0_MAXVAL_0   BIT0
 set     DACB_MAXVAL_FMT0_MAXVAL_1   BIT1
 set     DACB_MAXVAL_FMT0_MAXVAL_2   BIT2
 set     DACB_MAXVAL_FMT0_MAXVAL_3   BIT3
 set     DACB_MAXVAL_FMT0_MAXVAL_4   BIT4
 set     DACB_MAXVAL_FMT0_MAXVAL_5   BIT5
 set     DACB_MAXVAL_FMT0_MAXVAL_6   BIT6
 set     DACB_MAXVAL_FMT0_MAXVAL_7   BIT7
 set     DACB_MAXVAL_FMT0_MAXVAL_8   BIT8
 set     DACB_MAXVAL_FMT0_MAXVAL_9   BIT9
 set     DACB_MAXVAL_FMT0_MAXVAL_10  BIT10
 set     DACB_MAXVAL_FMT0_MAXVAL_11  BIT11

 set     DACB_MAXVAL_FMT1_MAXVAL     (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Maximum value (left justified)
 set     DACB_MAXVAL_FMT1_MAXVAL_0   BIT4
 set     DACB_MAXVAL_FMT1_MAXVAL_1   BIT5
 set     DACB_MAXVAL_FMT1_MAXVAL_2   BIT6
 set     DACB_MAXVAL_FMT1_MAXVAL_3   BIT7
 set     DACB_MAXVAL_FMT1_MAXVAL_4   BIT8
 set     DACB_MAXVAL_FMT1_MAXVAL_5   BIT9
 set     DACB_MAXVAL_FMT1_MAXVAL_6   BIT10
 set     DACB_MAXVAL_FMT1_MAXVAL_7   BIT11
 set     DACB_MAXVAL_FMT1_MAXVAL_8   BIT12
 set     DACB_MAXVAL_FMT1_MAXVAL_9   BIT13
 set     DACB_MAXVAL_FMT1_MAXVAL_10  BIT14
 set     DACB_MAXVAL_FMT1_MAXVAL_11  BIT15

 set     DACB_STATUS_EMPTY           BIT0
;;   Indicates empty status of FIFO
;;     0b0 ==> FIFO is not empty.
;;     0b1 ==> FIFO is empty (on reset).

 set     DACB_STATUS_FULL            BIT1
;;   Indicates full status of FIFO
;;     0b0 ==> FIFO is not full (on reset).
;;     0b1 ==> FIFO is full.

 set     DACB_CTRL1_FILT_CNT         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Glitch Filter Count
 set     DACB_CTRL1_FILT_CNT_0       BIT0
 set     DACB_CTRL1_FILT_CNT_1       BIT1
 set     DACB_CTRL1_FILT_CNT_2       BIT2
 set     DACB_CTRL1_FILT_CNT_3       BIT3
 set     DACB_CTRL1_FILT_CNT_4       BIT4
 set     DACB_CTRL1_FILT_CNT_5       BIT5

 set     DMA_REQC_DMAC3              (BIT0|BIT1|BIT2|BIT3)
;;   DMA channel 3
;;     0b0000 ==> Select request 0 as the source
;;     0b0001 ==> Select request 1 as the source
;;     0b0010 ==> Select request 2 as the source
;;     0b0011 ==> Select request 3 as the source
;;     0b0100 ==> Select request 4 as the source
;;     0b0101 ==> Select request 5 as the source
;;     0b0110 ==> Select request 6 as the source
;;     0b0111 ==> Select request 7 as the source
;;     0b1000 ==> Select request 8 as the source
;;     0b1001 ==> Select request 9 as the source
;;     0b1010 ==> Select request 10 as the source
;;     0b1011 ==> Select request 11 as the source
;;     0b1100 ==> Select request 12 as the source
;;     0b1101 ==> Select request 13 as the source
;;     0b1110 ==> Select request 14 as the source
;;     0b1111 ==> Select request 15 as the source
 set     DMA_REQC_DMAC3_0            BIT0
 set     DMA_REQC_DMAC3_1            BIT1
 set     DMA_REQC_DMAC3_2            BIT2
 set     DMA_REQC_DMAC3_3            BIT3

 set     DMA_REQC_CFSM3              BIT7
;;   Clear state machine control 3
;;     0b0 ==> No effect
;;     0b1 ==> Clear state machine for DMA channel 3

 set     DMA_REQC_DMAC2              (BIT8|BIT9|BIT10|BIT11)
;;   DMA channel 2
;;     0b0000 ==> Select request 0 as the source
;;     0b0001 ==> Select request 1 as the source
;;     0b0010 ==> Select request 2 as the source
;;     0b0011 ==> Select request 3 as the source
;;     0b0100 ==> Select request 4 as the source
;;     0b0101 ==> Select request 5 as the source
;;     0b0110 ==> Select request 6 as the source
;;     0b0111 ==> Select request 7 as the source
;;     0b1000 ==> Select request 8 as the source
;;     0b1001 ==> Select request 9 as the source
;;     0b1010 ==> Select request 10 as the source
;;     0b1011 ==> Select request 11 as the source
;;     0b1100 ==> Select request 12 as the source
;;     0b1101 ==> Select request 13 as the source
;;     0b1110 ==> Select request 14 as the source
;;     0b1111 ==> Select request 15 as the source
 set     DMA_REQC_DMAC2_0            BIT8
 set     DMA_REQC_DMAC2_1            BIT9
 set     DMA_REQC_DMAC2_2            BIT10
 set     DMA_REQC_DMAC2_3            BIT11

 set     DMA_REQC_CFSM2              BIT15
;;   Clear state machine control 2
;;     0b0 ==> No effect
;;     0b1 ==> Clear state machine for DMA channel 2

 set     DMA_REQC_DMAC1              (BIT16|BIT17|BIT18|BIT19)
;;   DMA channel 1
;;     0b0000 ==> Select request 0 as the source
;;     0b0001 ==> Select request 1 as the source
;;     0b0010 ==> Select request 2 as the source
;;     0b0011 ==> Select request 3 as the source
;;     0b0100 ==> Select request 4 as the source
;;     0b0101 ==> Select request 5 as the source
;;     0b0110 ==> Select request 6 as the source
;;     0b0111 ==> Select request 7 as the source
;;     0b1000 ==> Select request 8 as the source
;;     0b1001 ==> Select request 9 as the source
;;     0b1010 ==> Select request 10 as the source
;;     0b1011 ==> Select request 11 as the source
;;     0b1100 ==> Select request 12 as the source
;;     0b1101 ==> Select request 13 as the source
;;     0b1110 ==> Select request 14 as the source
;;     0b1111 ==> Select request 15 as the source
 set     DMA_REQC_DMAC1_0            BIT16
 set     DMA_REQC_DMAC1_1            BIT17
 set     DMA_REQC_DMAC1_2            BIT18
 set     DMA_REQC_DMAC1_3            BIT19

 set     DMA_REQC_CFSM1              BIT23
;;   Clear state machine control 1
;;     0b0 ==> No effect
;;     0b1 ==> Clear state machine for DMA channel 1

 set     DMA_REQC_DMAC0              (BIT24|BIT25|BIT26|BIT27)
;;   DMA channel 0
;;     0b0000 ==> Select request 0 as the source
;;     0b0001 ==> Select request 1 as the source
;;     0b0010 ==> Select request 2 as the source
;;     0b0011 ==> Select request 3 as the source
;;     0b0100 ==> Select request 4 as the source
;;     0b0101 ==> Select request 5 as the source
;;     0b0110 ==> Select request 6 as the source
;;     0b0111 ==> Select request 7 as the source
;;     0b1000 ==> Select request 8 as the source
;;     0b1001 ==> Select request 9 as the source
;;     0b1010 ==> Select request 10 as the source
;;     0b1011 ==> Select request 11 as the source
;;     0b1100 ==> Select request 12 as the source
;;     0b1101 ==> Select request 13 as the source
;;     0b1110 ==> Select request 14 as the source
;;     0b1111 ==> Select request 15 as the source
 set     DMA_REQC_DMAC0_0            BIT24
 set     DMA_REQC_DMAC0_1            BIT25
 set     DMA_REQC_DMAC0_2            BIT26
 set     DMA_REQC_DMAC0_3            BIT27

 set     DMA_REQC_CFSM0              BIT31
;;   Clear state machine control 0
;;     0b0 ==> No effect
;;     0b1 ==> Clear state machine for DMA channel 0

 set     DMA_SAR0_SAR                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
 set     DMA_SAR0_SAR_0              BIT0
 set     DMA_SAR0_SAR_1              BIT1
 set     DMA_SAR0_SAR_2              BIT2
 set     DMA_SAR0_SAR_3              BIT3
 set     DMA_SAR0_SAR_4              BIT4
 set     DMA_SAR0_SAR_5              BIT5
 set     DMA_SAR0_SAR_6              BIT6
 set     DMA_SAR0_SAR_7              BIT7
 set     DMA_SAR0_SAR_8              BIT8
 set     DMA_SAR0_SAR_9              BIT9
 set     DMA_SAR0_SAR_10             BIT10
 set     DMA_SAR0_SAR_11             BIT11
 set     DMA_SAR0_SAR_12             BIT12
 set     DMA_SAR0_SAR_13             BIT13
 set     DMA_SAR0_SAR_14             BIT14
 set     DMA_SAR0_SAR_15             BIT15
 set     DMA_SAR0_SAR_16             BIT16
 set     DMA_SAR0_SAR_17             BIT17
 set     DMA_SAR0_SAR_18             BIT18
 set     DMA_SAR0_SAR_19             BIT19
 set     DMA_SAR0_SAR_20             BIT20
 set     DMA_SAR0_SAR_21             BIT21
 set     DMA_SAR0_SAR_22             BIT22
 set     DMA_SAR0_SAR_23             BIT23
 set     DMA_SAR0_SAR_24             BIT24
 set     DMA_SAR0_SAR_25             BIT25
 set     DMA_SAR0_SAR_26             BIT26
 set     DMA_SAR0_SAR_27             BIT27
 set     DMA_SAR0_SAR_28             BIT28
 set     DMA_SAR0_SAR_29             BIT29
 set     DMA_SAR0_SAR_30             BIT30
 set     DMA_SAR0_SAR_31             BIT31

 set     DMA_DAR0_DAR                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
 set     DMA_DAR0_DAR_0              BIT0
 set     DMA_DAR0_DAR_1              BIT1
 set     DMA_DAR0_DAR_2              BIT2
 set     DMA_DAR0_DAR_3              BIT3
 set     DMA_DAR0_DAR_4              BIT4
 set     DMA_DAR0_DAR_5              BIT5
 set     DMA_DAR0_DAR_6              BIT6
 set     DMA_DAR0_DAR_7              BIT7
 set     DMA_DAR0_DAR_8              BIT8
 set     DMA_DAR0_DAR_9              BIT9
 set     DMA_DAR0_DAR_10             BIT10
 set     DMA_DAR0_DAR_11             BIT11
 set     DMA_DAR0_DAR_12             BIT12
 set     DMA_DAR0_DAR_13             BIT13
 set     DMA_DAR0_DAR_14             BIT14
 set     DMA_DAR0_DAR_15             BIT15
 set     DMA_DAR0_DAR_16             BIT16
 set     DMA_DAR0_DAR_17             BIT17
 set     DMA_DAR0_DAR_18             BIT18
 set     DMA_DAR0_DAR_19             BIT19
 set     DMA_DAR0_DAR_20             BIT20
 set     DMA_DAR0_DAR_21             BIT21
 set     DMA_DAR0_DAR_22             BIT22
 set     DMA_DAR0_DAR_23             BIT23
 set     DMA_DAR0_DAR_24             BIT24
 set     DMA_DAR0_DAR_25             BIT25
 set     DMA_DAR0_DAR_26             BIT26
 set     DMA_DAR0_DAR_27             BIT27
 set     DMA_DAR0_DAR_28             BIT28
 set     DMA_DAR0_DAR_29             BIT29
 set     DMA_DAR0_DAR_30             BIT30
 set     DMA_DAR0_DAR_31             BIT31

 set     DMA_DSR_BCR0_BCR            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23)
 set     DMA_DSR_BCR0_BCR_0          BIT0
 set     DMA_DSR_BCR0_BCR_1          BIT1
 set     DMA_DSR_BCR0_BCR_2          BIT2
 set     DMA_DSR_BCR0_BCR_3          BIT3
 set     DMA_DSR_BCR0_BCR_4          BIT4
 set     DMA_DSR_BCR0_BCR_5          BIT5
 set     DMA_DSR_BCR0_BCR_6          BIT6
 set     DMA_DSR_BCR0_BCR_7          BIT7
 set     DMA_DSR_BCR0_BCR_8          BIT8
 set     DMA_DSR_BCR0_BCR_9          BIT9
 set     DMA_DSR_BCR0_BCR_10         BIT10
 set     DMA_DSR_BCR0_BCR_11         BIT11
 set     DMA_DSR_BCR0_BCR_12         BIT12
 set     DMA_DSR_BCR0_BCR_13         BIT13
 set     DMA_DSR_BCR0_BCR_14         BIT14
 set     DMA_DSR_BCR0_BCR_15         BIT15
 set     DMA_DSR_BCR0_BCR_16         BIT16
 set     DMA_DSR_BCR0_BCR_17         BIT17
 set     DMA_DSR_BCR0_BCR_18         BIT18
 set     DMA_DSR_BCR0_BCR_19         BIT19
 set     DMA_DSR_BCR0_BCR_20         BIT20
 set     DMA_DSR_BCR0_BCR_21         BIT21
 set     DMA_DSR_BCR0_BCR_22         BIT22
 set     DMA_DSR_BCR0_BCR_23         BIT23

 set     DMA_DSR_BCR0_DONE           BIT24
;;   Transactions done
;;     0b0 ==> DMA transfer is not yet complete. Writing a 0 has no effect.
;;     0b1 ==> DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an interrupt service routine to clear the DMA interrupt and error bits.

 set     DMA_DSR_BCR0_BSY            BIT25
;;   Busy
;;     0b0 ==> DMA channel is inactive. Cleared when the DMA has finished the last transaction.
;;     0b1 ==> BSY is set the first time the channel is enabled after a transfer is initiated.

 set     DMA_DSR_BCR0_REQ            BIT26
;;   Request
;;     0b0 ==> No request is pending or the channel is currently active. Cleared when the channel is selected.
;;     0b1 ==> The DMA channel has a transfer remaining and the channel is not selected.

 set     DMA_DSR_BCR0_BED            BIT28
;;   Bus error on destination
;;     0b0 ==> No bus error occurred.
;;     0b1 ==> The DMA channel terminated with a bus error during the write portion of a transfer.

 set     DMA_DSR_BCR0_BES            BIT29
;;   Bus error on source
;;     0b0 ==> No bus error occurred.
;;     0b1 ==> The DMA channel terminated with a bus error during the read portion of a transfer.

 set     DMA_DSR_BCR0_CE             BIT30
;;   Configuration error
;;     0b0 ==> No configuration error exists.
;;     0b1 ==> A configuration error has occurred.

 set     DMA_DCR0_LCH2               (BIT0|BIT1)
;;   Link channel 2
;;     0b00 ==> DMA Channel 0
;;     0b01 ==> DMA Channel 1
;;     0b10 ==> DMA Channel 2
;;     0b11 ==> DMA Channel 3
 set     DMA_DCR0_LCH2_0             BIT0
 set     DMA_DCR0_LCH2_1             BIT1

 set     DMA_DCR0_LCH1               (BIT2|BIT3)
;;   Link channel 1
;;     0b00 ==> DMA Channel 0
;;     0b01 ==> DMA Channel 1
;;     0b10 ==> DMA Channel 2
;;     0b11 ==> DMA Channel 3
 set     DMA_DCR0_LCH1_0             BIT2
 set     DMA_DCR0_LCH1_1             BIT3

 set     DMA_DCR0_LINKCC             (BIT4|BIT5)
;;   Link channel control
;;     0b00 ==> No channel-to-channel linking
;;     0b01 ==> Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to zero
;;     0b10 ==> Perform a link to channel LCH1 after each cycle-steal transfer
;;     0b11 ==> Perform a link to channel LCH1 after the BCR decrements to zero
 set     DMA_DCR0_LINKCC_0           BIT4
 set     DMA_DCR0_LINKCC_1           BIT5

 set     DMA_DCR0_D_REQ              BIT7
;;   Disable request
;;     0b0 ==> ERQ bit is not affected.
;;     0b1 ==> ERQ bit is cleared when the BCR is exhausted.

 set     DMA_DCR0_DMOD               (BIT8|BIT9|BIT10|BIT11)
;;   Destination address modulo
;;     0b0000 ==> Buffer disabled
;;     0b0001 ==> Circular buffer size is 16 bytes
;;     0b0010 ==> Circular buffer size is 32 bytes
;;     0b0011 ==> Circular buffer size is 64 bytes
;;     0b0100 ==> Circular buffer size is 128 bytes
;;     0b0101 ==> Circular buffer size is 256 bytes
;;     0b0110 ==> Circular buffer size is 512 bytes
;;     0b0111 ==> Circular buffer size is 1 KB
;;     0b1000 ==> Circular buffer size is 2 KB
;;     0b1001 ==> Circular buffer size is 4 KB
;;     0b1010 ==> Circular buffer size is 8 KB
;;     0b1011 ==> Circular buffer size is 16 KB
;;     0b1100 ==> Circular buffer size is 32 KB
;;     0b1101 ==> Circular buffer size is 64 KB
;;     0b1110 ==> Circular buffer size is 128 KB
;;     0b1111 ==> Circular buffer size is 256 KB
 set     DMA_DCR0_DMOD_0             BIT8
 set     DMA_DCR0_DMOD_1             BIT9
 set     DMA_DCR0_DMOD_2             BIT10
 set     DMA_DCR0_DMOD_3             BIT11

 set     DMA_DCR0_SMOD               (BIT12|BIT13|BIT14|BIT15)
;;   Source address modulo
;;     0b0000 ==> Buffer disabled
;;     0b0001 ==> Circular buffer size is 16 bytes
;;     0b0010 ==> Circular buffer size is 32 bytes
;;     0b0011 ==> Circular buffer size is 64 bytes
;;     0b0100 ==> Circular buffer size is 128 bytes
;;     0b0101 ==> Circular buffer size is 256 bytes
;;     0b0110 ==> Circular buffer size is 512 bytes
;;     0b0111 ==> Circular buffer size is 1 KB
;;     0b1000 ==> Circular buffer size is 2 KB
;;     0b1001 ==> Circular buffer size is 4 KB
;;     0b1010 ==> Circular buffer size is 8 KB
;;     0b1011 ==> Circular buffer size is 16 KB
;;     0b1100 ==> Circular buffer size is 32 KB
;;     0b1101 ==> Circular buffer size is 64 KB
;;     0b1110 ==> Circular buffer size is 128 KB
;;     0b1111 ==> Circular buffer size is 256 KB
 set     DMA_DCR0_SMOD_0             BIT12
 set     DMA_DCR0_SMOD_1             BIT13
 set     DMA_DCR0_SMOD_2             BIT14
 set     DMA_DCR0_SMOD_3             BIT15

 set     DMA_DCR0_START              BIT16
;;   Start transfer
;;     0b0 ==> DMA inactive
;;     0b1 ==> The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after one module clock and always reads as logic 0.

 set     DMA_DCR0_DSIZE              (BIT17|BIT18)
;;   Destination size
;;     0b00 ==> 32-bit
;;     0b01 ==> 8-bit
;;     0b10 ==> 16-bit
;;     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 set     DMA_DCR0_DSIZE_0            BIT17
 set     DMA_DCR0_DSIZE_1            BIT18

 set     DMA_DCR0_DINC               BIT19
;;   Destination increment
;;     0b0 ==> No change to the DAR after a successful transfer.
;;     0b1 ==> The DAR increments by 1, 2, 4 depending upon the size of the transfer.

 set     DMA_DCR0_SSIZE              (BIT20|BIT21)
;;   Source size
;;     0b00 ==> 32-bit
;;     0b01 ==> 8-bit
;;     0b10 ==> 16-bit
;;     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 set     DMA_DCR0_SSIZE_0            BIT20
 set     DMA_DCR0_SSIZE_1            BIT21

 set     DMA_DCR0_SINC               BIT22
;;   Source increment
;;     0b0 ==> No change to SAR after a successful transfer.
;;     0b1 ==> The SAR increments by 1, 2, 4 as determined by the transfer size.

 set     DMA_DCR0_AA                 BIT28
;;   Auto-align
;;     0b0 ==> Auto-align disabled
;;     0b1 ==> If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise, destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.

 set     DMA_DCR0_CS                 BIT29
;;   Cycle steal
;;     0b0 ==> DMA continuously makes read/write transfers until the BCR decrements to 0.
;;     0b1 ==> Forces a single read/write transfer per request.

 set     DMA_DCR0_ERQ                BIT30
;;   Enable peripheral request
;;     0b0 ==> Peripheral request is ignored.
;;     0b1 ==> Enables peripheral request, defined by the appropriate REQC[DMACn] field, to initiate transfer. A software-initiated request (setting the START bit) is always enabled.

 set     DMA_DCR0_EINT               BIT31
;;   Enable interrupt on completion of transfer
;;     0b0 ==> No interrupt is generated.
;;     0b1 ==> Interrupt signal is enabled.

 set     DMA_SAR1_SAR                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
 set     DMA_SAR1_SAR_0              BIT0
 set     DMA_SAR1_SAR_1              BIT1
 set     DMA_SAR1_SAR_2              BIT2
 set     DMA_SAR1_SAR_3              BIT3
 set     DMA_SAR1_SAR_4              BIT4
 set     DMA_SAR1_SAR_5              BIT5
 set     DMA_SAR1_SAR_6              BIT6
 set     DMA_SAR1_SAR_7              BIT7
 set     DMA_SAR1_SAR_8              BIT8
 set     DMA_SAR1_SAR_9              BIT9
 set     DMA_SAR1_SAR_10             BIT10
 set     DMA_SAR1_SAR_11             BIT11
 set     DMA_SAR1_SAR_12             BIT12
 set     DMA_SAR1_SAR_13             BIT13
 set     DMA_SAR1_SAR_14             BIT14
 set     DMA_SAR1_SAR_15             BIT15
 set     DMA_SAR1_SAR_16             BIT16
 set     DMA_SAR1_SAR_17             BIT17
 set     DMA_SAR1_SAR_18             BIT18
 set     DMA_SAR1_SAR_19             BIT19
 set     DMA_SAR1_SAR_20             BIT20
 set     DMA_SAR1_SAR_21             BIT21
 set     DMA_SAR1_SAR_22             BIT22
 set     DMA_SAR1_SAR_23             BIT23
 set     DMA_SAR1_SAR_24             BIT24
 set     DMA_SAR1_SAR_25             BIT25
 set     DMA_SAR1_SAR_26             BIT26
 set     DMA_SAR1_SAR_27             BIT27
 set     DMA_SAR1_SAR_28             BIT28
 set     DMA_SAR1_SAR_29             BIT29
 set     DMA_SAR1_SAR_30             BIT30
 set     DMA_SAR1_SAR_31             BIT31

 set     DMA_DAR1_DAR                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
 set     DMA_DAR1_DAR_0              BIT0
 set     DMA_DAR1_DAR_1              BIT1
 set     DMA_DAR1_DAR_2              BIT2
 set     DMA_DAR1_DAR_3              BIT3
 set     DMA_DAR1_DAR_4              BIT4
 set     DMA_DAR1_DAR_5              BIT5
 set     DMA_DAR1_DAR_6              BIT6
 set     DMA_DAR1_DAR_7              BIT7
 set     DMA_DAR1_DAR_8              BIT8
 set     DMA_DAR1_DAR_9              BIT9
 set     DMA_DAR1_DAR_10             BIT10
 set     DMA_DAR1_DAR_11             BIT11
 set     DMA_DAR1_DAR_12             BIT12
 set     DMA_DAR1_DAR_13             BIT13
 set     DMA_DAR1_DAR_14             BIT14
 set     DMA_DAR1_DAR_15             BIT15
 set     DMA_DAR1_DAR_16             BIT16
 set     DMA_DAR1_DAR_17             BIT17
 set     DMA_DAR1_DAR_18             BIT18
 set     DMA_DAR1_DAR_19             BIT19
 set     DMA_DAR1_DAR_20             BIT20
 set     DMA_DAR1_DAR_21             BIT21
 set     DMA_DAR1_DAR_22             BIT22
 set     DMA_DAR1_DAR_23             BIT23
 set     DMA_DAR1_DAR_24             BIT24
 set     DMA_DAR1_DAR_25             BIT25
 set     DMA_DAR1_DAR_26             BIT26
 set     DMA_DAR1_DAR_27             BIT27
 set     DMA_DAR1_DAR_28             BIT28
 set     DMA_DAR1_DAR_29             BIT29
 set     DMA_DAR1_DAR_30             BIT30
 set     DMA_DAR1_DAR_31             BIT31

 set     DMA_DSR_BCR1_BCR            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23)
 set     DMA_DSR_BCR1_BCR_0          BIT0
 set     DMA_DSR_BCR1_BCR_1          BIT1
 set     DMA_DSR_BCR1_BCR_2          BIT2
 set     DMA_DSR_BCR1_BCR_3          BIT3
 set     DMA_DSR_BCR1_BCR_4          BIT4
 set     DMA_DSR_BCR1_BCR_5          BIT5
 set     DMA_DSR_BCR1_BCR_6          BIT6
 set     DMA_DSR_BCR1_BCR_7          BIT7
 set     DMA_DSR_BCR1_BCR_8          BIT8
 set     DMA_DSR_BCR1_BCR_9          BIT9
 set     DMA_DSR_BCR1_BCR_10         BIT10
 set     DMA_DSR_BCR1_BCR_11         BIT11
 set     DMA_DSR_BCR1_BCR_12         BIT12
 set     DMA_DSR_BCR1_BCR_13         BIT13
 set     DMA_DSR_BCR1_BCR_14         BIT14
 set     DMA_DSR_BCR1_BCR_15         BIT15
 set     DMA_DSR_BCR1_BCR_16         BIT16
 set     DMA_DSR_BCR1_BCR_17         BIT17
 set     DMA_DSR_BCR1_BCR_18         BIT18
 set     DMA_DSR_BCR1_BCR_19         BIT19
 set     DMA_DSR_BCR1_BCR_20         BIT20
 set     DMA_DSR_BCR1_BCR_21         BIT21
 set     DMA_DSR_BCR1_BCR_22         BIT22
 set     DMA_DSR_BCR1_BCR_23         BIT23

 set     DMA_DSR_BCR1_DONE           BIT24
;;   Transactions done
;;     0b0 ==> DMA transfer is not yet complete. Writing a 0 has no effect.
;;     0b1 ==> DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an interrupt service routine to clear the DMA interrupt and error bits.

 set     DMA_DSR_BCR1_BSY            BIT25
;;   Busy
;;     0b0 ==> DMA channel is inactive. Cleared when the DMA has finished the last transaction.
;;     0b1 ==> BSY is set the first time the channel is enabled after a transfer is initiated.

 set     DMA_DSR_BCR1_REQ            BIT26
;;   Request
;;     0b0 ==> No request is pending or the channel is currently active. Cleared when the channel is selected.
;;     0b1 ==> The DMA channel has a transfer remaining and the channel is not selected.

 set     DMA_DSR_BCR1_BED            BIT28
;;   Bus error on destination
;;     0b0 ==> No bus error occurred.
;;     0b1 ==> The DMA channel terminated with a bus error during the write portion of a transfer.

 set     DMA_DSR_BCR1_BES            BIT29
;;   Bus error on source
;;     0b0 ==> No bus error occurred.
;;     0b1 ==> The DMA channel terminated with a bus error during the read portion of a transfer.

 set     DMA_DSR_BCR1_CE             BIT30
;;   Configuration error
;;     0b0 ==> No configuration error exists.
;;     0b1 ==> A configuration error has occurred.

 set     DMA_DCR1_LCH2               (BIT0|BIT1)
;;   Link channel 2
;;     0b00 ==> DMA Channel 0
;;     0b01 ==> DMA Channel 1
;;     0b10 ==> DMA Channel 2
;;     0b11 ==> DMA Channel 3
 set     DMA_DCR1_LCH2_0             BIT0
 set     DMA_DCR1_LCH2_1             BIT1

 set     DMA_DCR1_LCH1               (BIT2|BIT3)
;;   Link channel 1
;;     0b00 ==> DMA Channel 0
;;     0b01 ==> DMA Channel 1
;;     0b10 ==> DMA Channel 2
;;     0b11 ==> DMA Channel 3
 set     DMA_DCR1_LCH1_0             BIT2
 set     DMA_DCR1_LCH1_1             BIT3

 set     DMA_DCR1_LINKCC             (BIT4|BIT5)
;;   Link channel control
;;     0b00 ==> No channel-to-channel linking
;;     0b01 ==> Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to zero
;;     0b10 ==> Perform a link to channel LCH1 after each cycle-steal transfer
;;     0b11 ==> Perform a link to channel LCH1 after the BCR decrements to zero
 set     DMA_DCR1_LINKCC_0           BIT4
 set     DMA_DCR1_LINKCC_1           BIT5

 set     DMA_DCR1_D_REQ              BIT7
;;   Disable request
;;     0b0 ==> ERQ bit is not affected.
;;     0b1 ==> ERQ bit is cleared when the BCR is exhausted.

 set     DMA_DCR1_DMOD               (BIT8|BIT9|BIT10|BIT11)
;;   Destination address modulo
;;     0b0000 ==> Buffer disabled
;;     0b0001 ==> Circular buffer size is 16 bytes
;;     0b0010 ==> Circular buffer size is 32 bytes
;;     0b0011 ==> Circular buffer size is 64 bytes
;;     0b0100 ==> Circular buffer size is 128 bytes
;;     0b0101 ==> Circular buffer size is 256 bytes
;;     0b0110 ==> Circular buffer size is 512 bytes
;;     0b0111 ==> Circular buffer size is 1 KB
;;     0b1000 ==> Circular buffer size is 2 KB
;;     0b1001 ==> Circular buffer size is 4 KB
;;     0b1010 ==> Circular buffer size is 8 KB
;;     0b1011 ==> Circular buffer size is 16 KB
;;     0b1100 ==> Circular buffer size is 32 KB
;;     0b1101 ==> Circular buffer size is 64 KB
;;     0b1110 ==> Circular buffer size is 128 KB
;;     0b1111 ==> Circular buffer size is 256 KB
 set     DMA_DCR1_DMOD_0             BIT8
 set     DMA_DCR1_DMOD_1             BIT9
 set     DMA_DCR1_DMOD_2             BIT10
 set     DMA_DCR1_DMOD_3             BIT11

 set     DMA_DCR1_SMOD               (BIT12|BIT13|BIT14|BIT15)
;;   Source address modulo
;;     0b0000 ==> Buffer disabled
;;     0b0001 ==> Circular buffer size is 16 bytes
;;     0b0010 ==> Circular buffer size is 32 bytes
;;     0b0011 ==> Circular buffer size is 64 bytes
;;     0b0100 ==> Circular buffer size is 128 bytes
;;     0b0101 ==> Circular buffer size is 256 bytes
;;     0b0110 ==> Circular buffer size is 512 bytes
;;     0b0111 ==> Circular buffer size is 1 KB
;;     0b1000 ==> Circular buffer size is 2 KB
;;     0b1001 ==> Circular buffer size is 4 KB
;;     0b1010 ==> Circular buffer size is 8 KB
;;     0b1011 ==> Circular buffer size is 16 KB
;;     0b1100 ==> Circular buffer size is 32 KB
;;     0b1101 ==> Circular buffer size is 64 KB
;;     0b1110 ==> Circular buffer size is 128 KB
;;     0b1111 ==> Circular buffer size is 256 KB
 set     DMA_DCR1_SMOD_0             BIT12
 set     DMA_DCR1_SMOD_1             BIT13
 set     DMA_DCR1_SMOD_2             BIT14
 set     DMA_DCR1_SMOD_3             BIT15

 set     DMA_DCR1_START              BIT16
;;   Start transfer
;;     0b0 ==> DMA inactive
;;     0b1 ==> The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after one module clock and always reads as logic 0.

 set     DMA_DCR1_DSIZE              (BIT17|BIT18)
;;   Destination size
;;     0b00 ==> 32-bit
;;     0b01 ==> 8-bit
;;     0b10 ==> 16-bit
;;     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 set     DMA_DCR1_DSIZE_0            BIT17
 set     DMA_DCR1_DSIZE_1            BIT18

 set     DMA_DCR1_DINC               BIT19
;;   Destination increment
;;     0b0 ==> No change to the DAR after a successful transfer.
;;     0b1 ==> The DAR increments by 1, 2, 4 depending upon the size of the transfer.

 set     DMA_DCR1_SSIZE              (BIT20|BIT21)
;;   Source size
;;     0b00 ==> 32-bit
;;     0b01 ==> 8-bit
;;     0b10 ==> 16-bit
;;     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 set     DMA_DCR1_SSIZE_0            BIT20
 set     DMA_DCR1_SSIZE_1            BIT21

 set     DMA_DCR1_SINC               BIT22
;;   Source increment
;;     0b0 ==> No change to SAR after a successful transfer.
;;     0b1 ==> The SAR increments by 1, 2, 4 as determined by the transfer size.

 set     DMA_DCR1_AA                 BIT28
;;   Auto-align
;;     0b0 ==> Auto-align disabled
;;     0b1 ==> If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise, destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.

 set     DMA_DCR1_CS                 BIT29
;;   Cycle steal
;;     0b0 ==> DMA continuously makes read/write transfers until the BCR decrements to 0.
;;     0b1 ==> Forces a single read/write transfer per request.

 set     DMA_DCR1_ERQ                BIT30
;;   Enable peripheral request
;;     0b0 ==> Peripheral request is ignored.
;;     0b1 ==> Enables peripheral request, defined by the appropriate REQC[DMACn] field, to initiate transfer. A software-initiated request (setting the START bit) is always enabled.

 set     DMA_DCR1_EINT               BIT31
;;   Enable interrupt on completion of transfer
;;     0b0 ==> No interrupt is generated.
;;     0b1 ==> Interrupt signal is enabled.

 set     DMA_SAR2_SAR                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
 set     DMA_SAR2_SAR_0              BIT0
 set     DMA_SAR2_SAR_1              BIT1
 set     DMA_SAR2_SAR_2              BIT2
 set     DMA_SAR2_SAR_3              BIT3
 set     DMA_SAR2_SAR_4              BIT4
 set     DMA_SAR2_SAR_5              BIT5
 set     DMA_SAR2_SAR_6              BIT6
 set     DMA_SAR2_SAR_7              BIT7
 set     DMA_SAR2_SAR_8              BIT8
 set     DMA_SAR2_SAR_9              BIT9
 set     DMA_SAR2_SAR_10             BIT10
 set     DMA_SAR2_SAR_11             BIT11
 set     DMA_SAR2_SAR_12             BIT12
 set     DMA_SAR2_SAR_13             BIT13
 set     DMA_SAR2_SAR_14             BIT14
 set     DMA_SAR2_SAR_15             BIT15
 set     DMA_SAR2_SAR_16             BIT16
 set     DMA_SAR2_SAR_17             BIT17
 set     DMA_SAR2_SAR_18             BIT18
 set     DMA_SAR2_SAR_19             BIT19
 set     DMA_SAR2_SAR_20             BIT20
 set     DMA_SAR2_SAR_21             BIT21
 set     DMA_SAR2_SAR_22             BIT22
 set     DMA_SAR2_SAR_23             BIT23
 set     DMA_SAR2_SAR_24             BIT24
 set     DMA_SAR2_SAR_25             BIT25
 set     DMA_SAR2_SAR_26             BIT26
 set     DMA_SAR2_SAR_27             BIT27
 set     DMA_SAR2_SAR_28             BIT28
 set     DMA_SAR2_SAR_29             BIT29
 set     DMA_SAR2_SAR_30             BIT30
 set     DMA_SAR2_SAR_31             BIT31

 set     DMA_DAR2_DAR                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
 set     DMA_DAR2_DAR_0              BIT0
 set     DMA_DAR2_DAR_1              BIT1
 set     DMA_DAR2_DAR_2              BIT2
 set     DMA_DAR2_DAR_3              BIT3
 set     DMA_DAR2_DAR_4              BIT4
 set     DMA_DAR2_DAR_5              BIT5
 set     DMA_DAR2_DAR_6              BIT6
 set     DMA_DAR2_DAR_7              BIT7
 set     DMA_DAR2_DAR_8              BIT8
 set     DMA_DAR2_DAR_9              BIT9
 set     DMA_DAR2_DAR_10             BIT10
 set     DMA_DAR2_DAR_11             BIT11
 set     DMA_DAR2_DAR_12             BIT12
 set     DMA_DAR2_DAR_13             BIT13
 set     DMA_DAR2_DAR_14             BIT14
 set     DMA_DAR2_DAR_15             BIT15
 set     DMA_DAR2_DAR_16             BIT16
 set     DMA_DAR2_DAR_17             BIT17
 set     DMA_DAR2_DAR_18             BIT18
 set     DMA_DAR2_DAR_19             BIT19
 set     DMA_DAR2_DAR_20             BIT20
 set     DMA_DAR2_DAR_21             BIT21
 set     DMA_DAR2_DAR_22             BIT22
 set     DMA_DAR2_DAR_23             BIT23
 set     DMA_DAR2_DAR_24             BIT24
 set     DMA_DAR2_DAR_25             BIT25
 set     DMA_DAR2_DAR_26             BIT26
 set     DMA_DAR2_DAR_27             BIT27
 set     DMA_DAR2_DAR_28             BIT28
 set     DMA_DAR2_DAR_29             BIT29
 set     DMA_DAR2_DAR_30             BIT30
 set     DMA_DAR2_DAR_31             BIT31

 set     DMA_DSR_BCR2_BCR            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23)
 set     DMA_DSR_BCR2_BCR_0          BIT0
 set     DMA_DSR_BCR2_BCR_1          BIT1
 set     DMA_DSR_BCR2_BCR_2          BIT2
 set     DMA_DSR_BCR2_BCR_3          BIT3
 set     DMA_DSR_BCR2_BCR_4          BIT4
 set     DMA_DSR_BCR2_BCR_5          BIT5
 set     DMA_DSR_BCR2_BCR_6          BIT6
 set     DMA_DSR_BCR2_BCR_7          BIT7
 set     DMA_DSR_BCR2_BCR_8          BIT8
 set     DMA_DSR_BCR2_BCR_9          BIT9
 set     DMA_DSR_BCR2_BCR_10         BIT10
 set     DMA_DSR_BCR2_BCR_11         BIT11
 set     DMA_DSR_BCR2_BCR_12         BIT12
 set     DMA_DSR_BCR2_BCR_13         BIT13
 set     DMA_DSR_BCR2_BCR_14         BIT14
 set     DMA_DSR_BCR2_BCR_15         BIT15
 set     DMA_DSR_BCR2_BCR_16         BIT16
 set     DMA_DSR_BCR2_BCR_17         BIT17
 set     DMA_DSR_BCR2_BCR_18         BIT18
 set     DMA_DSR_BCR2_BCR_19         BIT19
 set     DMA_DSR_BCR2_BCR_20         BIT20
 set     DMA_DSR_BCR2_BCR_21         BIT21
 set     DMA_DSR_BCR2_BCR_22         BIT22
 set     DMA_DSR_BCR2_BCR_23         BIT23

 set     DMA_DSR_BCR2_DONE           BIT24
;;   Transactions done
;;     0b0 ==> DMA transfer is not yet complete. Writing a 0 has no effect.
;;     0b1 ==> DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an interrupt service routine to clear the DMA interrupt and error bits.

 set     DMA_DSR_BCR2_BSY            BIT25
;;   Busy
;;     0b0 ==> DMA channel is inactive. Cleared when the DMA has finished the last transaction.
;;     0b1 ==> BSY is set the first time the channel is enabled after a transfer is initiated.

 set     DMA_DSR_BCR2_REQ            BIT26
;;   Request
;;     0b0 ==> No request is pending or the channel is currently active. Cleared when the channel is selected.
;;     0b1 ==> The DMA channel has a transfer remaining and the channel is not selected.

 set     DMA_DSR_BCR2_BED            BIT28
;;   Bus error on destination
;;     0b0 ==> No bus error occurred.
;;     0b1 ==> The DMA channel terminated with a bus error during the write portion of a transfer.

 set     DMA_DSR_BCR2_BES            BIT29
;;   Bus error on source
;;     0b0 ==> No bus error occurred.
;;     0b1 ==> The DMA channel terminated with a bus error during the read portion of a transfer.

 set     DMA_DSR_BCR2_CE             BIT30
;;   Configuration error
;;     0b0 ==> No configuration error exists.
;;     0b1 ==> A configuration error has occurred.

 set     DMA_DCR2_LCH2               (BIT0|BIT1)
;;   Link channel 2
;;     0b00 ==> DMA Channel 0
;;     0b01 ==> DMA Channel 1
;;     0b10 ==> DMA Channel 2
;;     0b11 ==> DMA Channel 3
 set     DMA_DCR2_LCH2_0             BIT0
 set     DMA_DCR2_LCH2_1             BIT1

 set     DMA_DCR2_LCH1               (BIT2|BIT3)
;;   Link channel 1
;;     0b00 ==> DMA Channel 0
;;     0b01 ==> DMA Channel 1
;;     0b10 ==> DMA Channel 2
;;     0b11 ==> DMA Channel 3
 set     DMA_DCR2_LCH1_0             BIT2
 set     DMA_DCR2_LCH1_1             BIT3

 set     DMA_DCR2_LINKCC             (BIT4|BIT5)
;;   Link channel control
;;     0b00 ==> No channel-to-channel linking
;;     0b01 ==> Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to zero
;;     0b10 ==> Perform a link to channel LCH1 after each cycle-steal transfer
;;     0b11 ==> Perform a link to channel LCH1 after the BCR decrements to zero
 set     DMA_DCR2_LINKCC_0           BIT4
 set     DMA_DCR2_LINKCC_1           BIT5

 set     DMA_DCR2_D_REQ              BIT7
;;   Disable request
;;     0b0 ==> ERQ bit is not affected.
;;     0b1 ==> ERQ bit is cleared when the BCR is exhausted.

 set     DMA_DCR2_DMOD               (BIT8|BIT9|BIT10|BIT11)
;;   Destination address modulo
;;     0b0000 ==> Buffer disabled
;;     0b0001 ==> Circular buffer size is 16 bytes
;;     0b0010 ==> Circular buffer size is 32 bytes
;;     0b0011 ==> Circular buffer size is 64 bytes
;;     0b0100 ==> Circular buffer size is 128 bytes
;;     0b0101 ==> Circular buffer size is 256 bytes
;;     0b0110 ==> Circular buffer size is 512 bytes
;;     0b0111 ==> Circular buffer size is 1 KB
;;     0b1000 ==> Circular buffer size is 2 KB
;;     0b1001 ==> Circular buffer size is 4 KB
;;     0b1010 ==> Circular buffer size is 8 KB
;;     0b1011 ==> Circular buffer size is 16 KB
;;     0b1100 ==> Circular buffer size is 32 KB
;;     0b1101 ==> Circular buffer size is 64 KB
;;     0b1110 ==> Circular buffer size is 128 KB
;;     0b1111 ==> Circular buffer size is 256 KB
 set     DMA_DCR2_DMOD_0             BIT8
 set     DMA_DCR2_DMOD_1             BIT9
 set     DMA_DCR2_DMOD_2             BIT10
 set     DMA_DCR2_DMOD_3             BIT11

 set     DMA_DCR2_SMOD               (BIT12|BIT13|BIT14|BIT15)
;;   Source address modulo
;;     0b0000 ==> Buffer disabled
;;     0b0001 ==> Circular buffer size is 16 bytes
;;     0b0010 ==> Circular buffer size is 32 bytes
;;     0b0011 ==> Circular buffer size is 64 bytes
;;     0b0100 ==> Circular buffer size is 128 bytes
;;     0b0101 ==> Circular buffer size is 256 bytes
;;     0b0110 ==> Circular buffer size is 512 bytes
;;     0b0111 ==> Circular buffer size is 1 KB
;;     0b1000 ==> Circular buffer size is 2 KB
;;     0b1001 ==> Circular buffer size is 4 KB
;;     0b1010 ==> Circular buffer size is 8 KB
;;     0b1011 ==> Circular buffer size is 16 KB
;;     0b1100 ==> Circular buffer size is 32 KB
;;     0b1101 ==> Circular buffer size is 64 KB
;;     0b1110 ==> Circular buffer size is 128 KB
;;     0b1111 ==> Circular buffer size is 256 KB
 set     DMA_DCR2_SMOD_0             BIT12
 set     DMA_DCR2_SMOD_1             BIT13
 set     DMA_DCR2_SMOD_2             BIT14
 set     DMA_DCR2_SMOD_3             BIT15

 set     DMA_DCR2_START              BIT16
;;   Start transfer
;;     0b0 ==> DMA inactive
;;     0b1 ==> The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after one module clock and always reads as logic 0.

 set     DMA_DCR2_DSIZE              (BIT17|BIT18)
;;   Destination size
;;     0b00 ==> 32-bit
;;     0b01 ==> 8-bit
;;     0b10 ==> 16-bit
;;     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 set     DMA_DCR2_DSIZE_0            BIT17
 set     DMA_DCR2_DSIZE_1            BIT18

 set     DMA_DCR2_DINC               BIT19
;;   Destination increment
;;     0b0 ==> No change to the DAR after a successful transfer.
;;     0b1 ==> The DAR increments by 1, 2, 4 depending upon the size of the transfer.

 set     DMA_DCR2_SSIZE              (BIT20|BIT21)
;;   Source size
;;     0b00 ==> 32-bit
;;     0b01 ==> 8-bit
;;     0b10 ==> 16-bit
;;     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 set     DMA_DCR2_SSIZE_0            BIT20
 set     DMA_DCR2_SSIZE_1            BIT21

 set     DMA_DCR2_SINC               BIT22
;;   Source increment
;;     0b0 ==> No change to SAR after a successful transfer.
;;     0b1 ==> The SAR increments by 1, 2, 4 as determined by the transfer size.

 set     DMA_DCR2_AA                 BIT28
;;   Auto-align
;;     0b0 ==> Auto-align disabled
;;     0b1 ==> If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise, destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.

 set     DMA_DCR2_CS                 BIT29
;;   Cycle steal
;;     0b0 ==> DMA continuously makes read/write transfers until the BCR decrements to 0.
;;     0b1 ==> Forces a single read/write transfer per request.

 set     DMA_DCR2_ERQ                BIT30
;;   Enable peripheral request
;;     0b0 ==> Peripheral request is ignored.
;;     0b1 ==> Enables peripheral request, defined by the appropriate REQC[DMACn] field, to initiate transfer. A software-initiated request (setting the START bit) is always enabled.

 set     DMA_DCR2_EINT               BIT31
;;   Enable interrupt on completion of transfer
;;     0b0 ==> No interrupt is generated.
;;     0b1 ==> Interrupt signal is enabled.

 set     DMA_SAR3_SAR                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
 set     DMA_SAR3_SAR_0              BIT0
 set     DMA_SAR3_SAR_1              BIT1
 set     DMA_SAR3_SAR_2              BIT2
 set     DMA_SAR3_SAR_3              BIT3
 set     DMA_SAR3_SAR_4              BIT4
 set     DMA_SAR3_SAR_5              BIT5
 set     DMA_SAR3_SAR_6              BIT6
 set     DMA_SAR3_SAR_7              BIT7
 set     DMA_SAR3_SAR_8              BIT8
 set     DMA_SAR3_SAR_9              BIT9
 set     DMA_SAR3_SAR_10             BIT10
 set     DMA_SAR3_SAR_11             BIT11
 set     DMA_SAR3_SAR_12             BIT12
 set     DMA_SAR3_SAR_13             BIT13
 set     DMA_SAR3_SAR_14             BIT14
 set     DMA_SAR3_SAR_15             BIT15
 set     DMA_SAR3_SAR_16             BIT16
 set     DMA_SAR3_SAR_17             BIT17
 set     DMA_SAR3_SAR_18             BIT18
 set     DMA_SAR3_SAR_19             BIT19
 set     DMA_SAR3_SAR_20             BIT20
 set     DMA_SAR3_SAR_21             BIT21
 set     DMA_SAR3_SAR_22             BIT22
 set     DMA_SAR3_SAR_23             BIT23
 set     DMA_SAR3_SAR_24             BIT24
 set     DMA_SAR3_SAR_25             BIT25
 set     DMA_SAR3_SAR_26             BIT26
 set     DMA_SAR3_SAR_27             BIT27
 set     DMA_SAR3_SAR_28             BIT28
 set     DMA_SAR3_SAR_29             BIT29
 set     DMA_SAR3_SAR_30             BIT30
 set     DMA_SAR3_SAR_31             BIT31

 set     DMA_DAR3_DAR                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
 set     DMA_DAR3_DAR_0              BIT0
 set     DMA_DAR3_DAR_1              BIT1
 set     DMA_DAR3_DAR_2              BIT2
 set     DMA_DAR3_DAR_3              BIT3
 set     DMA_DAR3_DAR_4              BIT4
 set     DMA_DAR3_DAR_5              BIT5
 set     DMA_DAR3_DAR_6              BIT6
 set     DMA_DAR3_DAR_7              BIT7
 set     DMA_DAR3_DAR_8              BIT8
 set     DMA_DAR3_DAR_9              BIT9
 set     DMA_DAR3_DAR_10             BIT10
 set     DMA_DAR3_DAR_11             BIT11
 set     DMA_DAR3_DAR_12             BIT12
 set     DMA_DAR3_DAR_13             BIT13
 set     DMA_DAR3_DAR_14             BIT14
 set     DMA_DAR3_DAR_15             BIT15
 set     DMA_DAR3_DAR_16             BIT16
 set     DMA_DAR3_DAR_17             BIT17
 set     DMA_DAR3_DAR_18             BIT18
 set     DMA_DAR3_DAR_19             BIT19
 set     DMA_DAR3_DAR_20             BIT20
 set     DMA_DAR3_DAR_21             BIT21
 set     DMA_DAR3_DAR_22             BIT22
 set     DMA_DAR3_DAR_23             BIT23
 set     DMA_DAR3_DAR_24             BIT24
 set     DMA_DAR3_DAR_25             BIT25
 set     DMA_DAR3_DAR_26             BIT26
 set     DMA_DAR3_DAR_27             BIT27
 set     DMA_DAR3_DAR_28             BIT28
 set     DMA_DAR3_DAR_29             BIT29
 set     DMA_DAR3_DAR_30             BIT30
 set     DMA_DAR3_DAR_31             BIT31

 set     DMA_DSR_BCR3_BCR            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23)
 set     DMA_DSR_BCR3_BCR_0          BIT0
 set     DMA_DSR_BCR3_BCR_1          BIT1
 set     DMA_DSR_BCR3_BCR_2          BIT2
 set     DMA_DSR_BCR3_BCR_3          BIT3
 set     DMA_DSR_BCR3_BCR_4          BIT4
 set     DMA_DSR_BCR3_BCR_5          BIT5
 set     DMA_DSR_BCR3_BCR_6          BIT6
 set     DMA_DSR_BCR3_BCR_7          BIT7
 set     DMA_DSR_BCR3_BCR_8          BIT8
 set     DMA_DSR_BCR3_BCR_9          BIT9
 set     DMA_DSR_BCR3_BCR_10         BIT10
 set     DMA_DSR_BCR3_BCR_11         BIT11
 set     DMA_DSR_BCR3_BCR_12         BIT12
 set     DMA_DSR_BCR3_BCR_13         BIT13
 set     DMA_DSR_BCR3_BCR_14         BIT14
 set     DMA_DSR_BCR3_BCR_15         BIT15
 set     DMA_DSR_BCR3_BCR_16         BIT16
 set     DMA_DSR_BCR3_BCR_17         BIT17
 set     DMA_DSR_BCR3_BCR_18         BIT18
 set     DMA_DSR_BCR3_BCR_19         BIT19
 set     DMA_DSR_BCR3_BCR_20         BIT20
 set     DMA_DSR_BCR3_BCR_21         BIT21
 set     DMA_DSR_BCR3_BCR_22         BIT22
 set     DMA_DSR_BCR3_BCR_23         BIT23

 set     DMA_DSR_BCR3_DONE           BIT24
;;   Transactions done
;;     0b0 ==> DMA transfer is not yet complete. Writing a 0 has no effect.
;;     0b1 ==> DMA transfer completed. Writing a 1 to this bit clears all DMA status bits and should be used in an interrupt service routine to clear the DMA interrupt and error bits.

 set     DMA_DSR_BCR3_BSY            BIT25
;;   Busy
;;     0b0 ==> DMA channel is inactive. Cleared when the DMA has finished the last transaction.
;;     0b1 ==> BSY is set the first time the channel is enabled after a transfer is initiated.

 set     DMA_DSR_BCR3_REQ            BIT26
;;   Request
;;     0b0 ==> No request is pending or the channel is currently active. Cleared when the channel is selected.
;;     0b1 ==> The DMA channel has a transfer remaining and the channel is not selected.

 set     DMA_DSR_BCR3_BED            BIT28
;;   Bus error on destination
;;     0b0 ==> No bus error occurred.
;;     0b1 ==> The DMA channel terminated with a bus error during the write portion of a transfer.

 set     DMA_DSR_BCR3_BES            BIT29
;;   Bus error on source
;;     0b0 ==> No bus error occurred.
;;     0b1 ==> The DMA channel terminated with a bus error during the read portion of a transfer.

 set     DMA_DSR_BCR3_CE             BIT30
;;   Configuration error
;;     0b0 ==> No configuration error exists.
;;     0b1 ==> A configuration error has occurred.

 set     DMA_DCR3_LCH2               (BIT0|BIT1)
;;   Link channel 2
;;     0b00 ==> DMA Channel 0
;;     0b01 ==> DMA Channel 1
;;     0b10 ==> DMA Channel 2
;;     0b11 ==> DMA Channel 3
 set     DMA_DCR3_LCH2_0             BIT0
 set     DMA_DCR3_LCH2_1             BIT1

 set     DMA_DCR3_LCH1               (BIT2|BIT3)
;;   Link channel 1
;;     0b00 ==> DMA Channel 0
;;     0b01 ==> DMA Channel 1
;;     0b10 ==> DMA Channel 2
;;     0b11 ==> DMA Channel 3
 set     DMA_DCR3_LCH1_0             BIT2
 set     DMA_DCR3_LCH1_1             BIT3

 set     DMA_DCR3_LINKCC             (BIT4|BIT5)
;;   Link channel control
;;     0b00 ==> No channel-to-channel linking
;;     0b01 ==> Perform a link to channel LCH1 after each cycle-steal transfer followed by a link to LCH2 after the BCR decrements to zero
;;     0b10 ==> Perform a link to channel LCH1 after each cycle-steal transfer
;;     0b11 ==> Perform a link to channel LCH1 after the BCR decrements to zero
 set     DMA_DCR3_LINKCC_0           BIT4
 set     DMA_DCR3_LINKCC_1           BIT5

 set     DMA_DCR3_D_REQ              BIT7
;;   Disable request
;;     0b0 ==> ERQ bit is not affected.
;;     0b1 ==> ERQ bit is cleared when the BCR is exhausted.

 set     DMA_DCR3_DMOD               (BIT8|BIT9|BIT10|BIT11)
;;   Destination address modulo
;;     0b0000 ==> Buffer disabled
;;     0b0001 ==> Circular buffer size is 16 bytes
;;     0b0010 ==> Circular buffer size is 32 bytes
;;     0b0011 ==> Circular buffer size is 64 bytes
;;     0b0100 ==> Circular buffer size is 128 bytes
;;     0b0101 ==> Circular buffer size is 256 bytes
;;     0b0110 ==> Circular buffer size is 512 bytes
;;     0b0111 ==> Circular buffer size is 1 KB
;;     0b1000 ==> Circular buffer size is 2 KB
;;     0b1001 ==> Circular buffer size is 4 KB
;;     0b1010 ==> Circular buffer size is 8 KB
;;     0b1011 ==> Circular buffer size is 16 KB
;;     0b1100 ==> Circular buffer size is 32 KB
;;     0b1101 ==> Circular buffer size is 64 KB
;;     0b1110 ==> Circular buffer size is 128 KB
;;     0b1111 ==> Circular buffer size is 256 KB
 set     DMA_DCR3_DMOD_0             BIT8
 set     DMA_DCR3_DMOD_1             BIT9
 set     DMA_DCR3_DMOD_2             BIT10
 set     DMA_DCR3_DMOD_3             BIT11

 set     DMA_DCR3_SMOD               (BIT12|BIT13|BIT14|BIT15)
;;   Source address modulo
;;     0b0000 ==> Buffer disabled
;;     0b0001 ==> Circular buffer size is 16 bytes
;;     0b0010 ==> Circular buffer size is 32 bytes
;;     0b0011 ==> Circular buffer size is 64 bytes
;;     0b0100 ==> Circular buffer size is 128 bytes
;;     0b0101 ==> Circular buffer size is 256 bytes
;;     0b0110 ==> Circular buffer size is 512 bytes
;;     0b0111 ==> Circular buffer size is 1 KB
;;     0b1000 ==> Circular buffer size is 2 KB
;;     0b1001 ==> Circular buffer size is 4 KB
;;     0b1010 ==> Circular buffer size is 8 KB
;;     0b1011 ==> Circular buffer size is 16 KB
;;     0b1100 ==> Circular buffer size is 32 KB
;;     0b1101 ==> Circular buffer size is 64 KB
;;     0b1110 ==> Circular buffer size is 128 KB
;;     0b1111 ==> Circular buffer size is 256 KB
 set     DMA_DCR3_SMOD_0             BIT12
 set     DMA_DCR3_SMOD_1             BIT13
 set     DMA_DCR3_SMOD_2             BIT14
 set     DMA_DCR3_SMOD_3             BIT15

 set     DMA_DCR3_START              BIT16
;;   Start transfer
;;     0b0 ==> DMA inactive
;;     0b1 ==> The DMA begins the transfer in accordance to the values in the TCDn. START is cleared automatically after one module clock and always reads as logic 0.

 set     DMA_DCR3_DSIZE              (BIT17|BIT18)
;;   Destination size
;;     0b00 ==> 32-bit
;;     0b01 ==> 8-bit
;;     0b10 ==> 16-bit
;;     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 set     DMA_DCR3_DSIZE_0            BIT17
 set     DMA_DCR3_DSIZE_1            BIT18

 set     DMA_DCR3_DINC               BIT19
;;   Destination increment
;;     0b0 ==> No change to the DAR after a successful transfer.
;;     0b1 ==> The DAR increments by 1, 2, 4 depending upon the size of the transfer.

 set     DMA_DCR3_SSIZE              (BIT20|BIT21)
;;   Source size
;;     0b00 ==> 32-bit
;;     0b01 ==> 8-bit
;;     0b10 ==> 16-bit
;;     0b11 ==> Reserved (generates a configuration error (DSRn[CE]) if incorrectly specified at time of channel activation)
 set     DMA_DCR3_SSIZE_0            BIT20
 set     DMA_DCR3_SSIZE_1            BIT21

 set     DMA_DCR3_SINC               BIT22
;;   Source increment
;;     0b0 ==> No change to SAR after a successful transfer.
;;     0b1 ==> The SAR increments by 1, 2, 4 as determined by the transfer size.

 set     DMA_DCR3_AA                 BIT28
;;   Auto-align
;;     0b0 ==> Auto-align disabled
;;     0b1 ==> If SSIZE indicates a transfer no smaller than DSIZE, source accesses are auto-aligned; otherwise, destination accesses are auto-aligned. Source alignment takes precedence over destination alignment. If auto-alignment is enabled, the appropriate address register increments, regardless of DINC or SINC.

 set     DMA_DCR3_CS                 BIT29
;;   Cycle steal
;;     0b0 ==> DMA continuously makes read/write transfers until the BCR decrements to 0.
;;     0b1 ==> Forces a single read/write transfer per request.

 set     DMA_DCR3_ERQ                BIT30
;;   Enable peripheral request
;;     0b0 ==> Peripheral request is ignored.
;;     0b1 ==> Enables peripheral request, defined by the appropriate REQC[DMACn] field, to initiate transfer. A software-initiated request (setting the START bit) is always enabled.

 set     DMA_DCR3_EINT               BIT31
;;   Enable interrupt on completion of transfer
;;     0b0 ==> No interrupt is generated.
;;     0b1 ==> Interrupt signal is enabled.

 set     EWM_CTRL_EWMEN              BIT0
;;   EWM enable.

 set     EWM_CTRL_ASSIN              BIT1
;;   EWM_in's Assertion State Select.

 set     EWM_CTRL_INEN               BIT2
;;   Input Enable.

 set     EWM_CTRL_INTEN              BIT3
;;   Interrupt Enable.

 set     EWM_SERV_SERVICE            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     EWM_SERV_SERVICE_0          BIT0
 set     EWM_SERV_SERVICE_1          BIT1
 set     EWM_SERV_SERVICE_2          BIT2
 set     EWM_SERV_SERVICE_3          BIT3
 set     EWM_SERV_SERVICE_4          BIT4
 set     EWM_SERV_SERVICE_5          BIT5
 set     EWM_SERV_SERVICE_6          BIT6
 set     EWM_SERV_SERVICE_7          BIT7

 set     EWM_CMPL_COMPAREL           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     EWM_CMPL_COMPAREL_0         BIT0
 set     EWM_CMPL_COMPAREL_1         BIT1
 set     EWM_CMPL_COMPAREL_2         BIT2
 set     EWM_CMPL_COMPAREL_3         BIT3
 set     EWM_CMPL_COMPAREL_4         BIT4
 set     EWM_CMPL_COMPAREL_5         BIT5
 set     EWM_CMPL_COMPAREL_6         BIT6
 set     EWM_CMPL_COMPAREL_7         BIT7

 set     EWM_CMPH_COMPAREH           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     EWM_CMPH_COMPAREH_0         BIT0
 set     EWM_CMPH_COMPAREH_1         BIT1
 set     EWM_CMPH_COMPAREH_2         BIT2
 set     EWM_CMPH_COMPAREH_3         BIT3
 set     EWM_CMPH_COMPAREH_4         BIT4
 set     EWM_CMPH_COMPAREH_5         BIT5
 set     EWM_CMPH_COMPAREH_6         BIT6
 set     EWM_CMPH_COMPAREH_7         BIT7

 set     EWM_CLKCTRL_CLKSEL          (BIT0|BIT1)
 set     EWM_CLKCTRL_CLKSEL_0        BIT0
 set     EWM_CLKCTRL_CLKSEL_1        BIT1

 set     EWM_CLKPRESCALER_CLK_DIV    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     EWM_CLKPRESCALER_CLK_DIV_0  BIT0
 set     EWM_CLKPRESCALER_CLK_DIV_1  BIT1
 set     EWM_CLKPRESCALER_CLK_DIV_2  BIT2
 set     EWM_CLKPRESCALER_CLK_DIV_3  BIT3
 set     EWM_CLKPRESCALER_CLK_DIV_4  BIT4
 set     EWM_CLKPRESCALER_CLK_DIV_5  BIT5
 set     EWM_CLKPRESCALER_CLK_DIV_6  BIT6
 set     EWM_CLKPRESCALER_CLK_DIV_7  BIT7

 set     FMC_PFAPR_M0AP              (BIT0|BIT1)
;;   Master 0 Access Protection
;;     0b00 ==> No access may be performed by this master
;;     0b01 ==> Only read accesses may be performed by this master
;;     0b10 ==> Reserved
;;     0b11 ==> Reserved
 set     FMC_PFAPR_M0AP_0            BIT0
 set     FMC_PFAPR_M0AP_1            BIT1

 set     FMC_PFAPR_M1AP              (BIT2|BIT3)
;;   Master 1 Access Protection
;;     0b00 ==> No access may be performed by this master
;;     0b01 ==> Only read accesses may be performed by this master
;;     0b10 ==> Reserved
;;     0b11 ==> Reserved
 set     FMC_PFAPR_M1AP_0            BIT2
 set     FMC_PFAPR_M1AP_1            BIT3

 set     FMC_PFAPR_M2AP              (BIT4|BIT5)
;;   Master 2 Access Protection
;;     0b00 ==> No access may be performed by this master
;;     0b01 ==> Only read accesses may be performed by this master
;;     0b10 ==> Reserved
;;     0b11 ==> Reserved
 set     FMC_PFAPR_M2AP_0            BIT4
 set     FMC_PFAPR_M2AP_1            BIT5

 set     FMC_PFAPR_M3AP              (BIT6|BIT7)
;;   Master 3 Access Protection
;;     0b00 ==> No access may be performed by this master
;;     0b01 ==> Only read accesses may be performed by this master
;;     0b10 ==> Reserved
;;     0b11 ==> Reserved
 set     FMC_PFAPR_M3AP_0            BIT6
 set     FMC_PFAPR_M3AP_1            BIT7

 set     FMC_PFAPR_M0PFD             BIT16
;;   Master 0 Prefetch Disable
;;     0b0 ==> Prefetching for this master is enabled.
;;     0b1 ==> Prefetching for this master is disabled.

 set     FMC_PFAPR_M1PFD             BIT17
;;   Master 1 Prefetch Disable
;;     0b0 ==> Prefetching for this master is enabled.
;;     0b1 ==> Prefetching for this master is disabled.

 set     FMC_PFAPR_M2PFD             BIT18
;;   Master 2 Prefetch Disable
;;     0b0 ==> Prefetching for this master is enabled.
;;     0b1 ==> Prefetching for this master is disabled.

 set     FMC_PFAPR_M3PFD             BIT19
;;   Master 3 Prefetch Disable
;;     0b0 ==> Prefetching for this master is enabled.
;;     0b1 ==> Prefetching for this master is disabled.

 set     FMC_PFB0CR_B0SEBE           BIT0
;;   Single Entry Buffer Enable
;;     0b0 ==> Single entry buffer is disabled.
;;     0b1 ==> Single entry buffer is enabled.

 set     FMC_PFB0CR_B0IPE            BIT1
;;   Instruction Prefetch Enable
;;     0b0 ==> Do not prefetch in response to instruction fetches.
;;     0b1 ==> Enable prefetches in response to instruction fetches.

 set     FMC_PFB0CR_B0DPE            BIT2
;;   Data Prefetch Enable
;;     0b0 ==> Do not prefetch in response to data references.
;;     0b1 ==> Enable prefetches in response to data references.

 set     FMC_PFB0CR_B0ICE            BIT3
;;   Instruction Cache Enable
;;     0b0 ==> Do not cache instruction fetches.
;;     0b1 ==> Cache instruction fetches.

 set     FMC_PFB0CR_B0DCE            BIT4
;;   Data Cache Enable
;;     0b0 ==> Do not cache data references.
;;     0b1 ==> Cache data references.

 set     FMC_PFB0CR_CRC              (BIT5|BIT6|BIT7)
;;   Cache Replacement Control
;;     0b000 ==> LRU replacement algorithm per set across all four ways
;;     0b001 ==> Reserved
;;     0b010 ==> Independent LRU with ways [0-1] for ifetches, [2-3] for data
;;     0b011 ==> Independent LRU with ways [0-2] for ifetches, [3] for data
;;     0b1xx ==> Reserved
 set     FMC_PFB0CR_CRC_0            BIT5
 set     FMC_PFB0CR_CRC_1            BIT6
 set     FMC_PFB0CR_CRC_2            BIT7

 set     FMC_PFB0CR_B0MW             (BIT17|BIT18)
;;   Memory Width
;;     0b00 ==> 32 bits
;;     0b01 ==> 64 bits
;;     0b1x ==> Reserved
 set     FMC_PFB0CR_B0MW_0           BIT17
 set     FMC_PFB0CR_B0MW_1           BIT18

 set     FMC_PFB0CR_S_B_INV          BIT19
;;   Invalidate Prefetch Speculation Buffer
;;     0b0 ==> Speculation buffer and single entry buffer are not affected.
;;     0b1 ==> Invalidate (clear) speculation buffer and single entry buffer.

 set     FMC_PFB0CR_CINV_WAY         (BIT20|BIT21|BIT22|BIT23)
;;   Cache Invalidate Way x
;;     0b0 ==> No cache way invalidation for the corresponding cache
;;     0b1 ==> Invalidate cache way for the corresponding cache: clear the tag, data, and vld bits of ways selected
 set     FMC_PFB0CR_CINV_WAY_0       BIT20
 set     FMC_PFB0CR_CINV_WAY_1       BIT21
 set     FMC_PFB0CR_CINV_WAY_2       BIT22
 set     FMC_PFB0CR_CINV_WAY_3       BIT23

 set     FMC_PFB0CR_CLCK_WAY         (BIT24|BIT25|BIT26|BIT27)
;;   Cache Lock Way x
;;     0b0 ==> Cache way is unlocked and may be displaced
;;     0b1 ==> Cache way is locked and its contents are not displaced
 set     FMC_PFB0CR_CLCK_WAY_0       BIT24
 set     FMC_PFB0CR_CLCK_WAY_1       BIT25
 set     FMC_PFB0CR_CLCK_WAY_2       BIT26
 set     FMC_PFB0CR_CLCK_WAY_3       BIT27

 set     FMC_PFB0CR_B0RWSC           (BIT28|BIT29|BIT30|BIT31)
;;   Read Wait State Control
 set     FMC_PFB0CR_B0RWSC_0         BIT28
 set     FMC_PFB0CR_B0RWSC_1         BIT29
 set     FMC_PFB0CR_B0RWSC_2         BIT30
 set     FMC_PFB0CR_B0RWSC_3         BIT31

 set     FMC_TAGVDW0S0_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW0S0_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW0S0_tag_0         BIT4
 set     FMC_TAGVDW0S0_tag_1         BIT5
 set     FMC_TAGVDW0S0_tag_2         BIT6
 set     FMC_TAGVDW0S0_tag_3         BIT7
 set     FMC_TAGVDW0S0_tag_4         BIT8
 set     FMC_TAGVDW0S0_tag_5         BIT9
 set     FMC_TAGVDW0S0_tag_6         BIT10
 set     FMC_TAGVDW0S0_tag_7         BIT11
 set     FMC_TAGVDW0S0_tag_8         BIT12
 set     FMC_TAGVDW0S0_tag_9         BIT13
 set     FMC_TAGVDW0S0_tag_10        BIT14
 set     FMC_TAGVDW0S0_tag_11        BIT15
 set     FMC_TAGVDW0S0_tag_12        BIT16
 set     FMC_TAGVDW0S0_tag_13        BIT17
 set     FMC_TAGVDW0S0_tag_14        BIT18
 set     FMC_TAGVDW0S0_tag_15        BIT19

 set     FMC_TAGVDW0S1_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW0S1_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW0S1_tag_0         BIT4
 set     FMC_TAGVDW0S1_tag_1         BIT5
 set     FMC_TAGVDW0S1_tag_2         BIT6
 set     FMC_TAGVDW0S1_tag_3         BIT7
 set     FMC_TAGVDW0S1_tag_4         BIT8
 set     FMC_TAGVDW0S1_tag_5         BIT9
 set     FMC_TAGVDW0S1_tag_6         BIT10
 set     FMC_TAGVDW0S1_tag_7         BIT11
 set     FMC_TAGVDW0S1_tag_8         BIT12
 set     FMC_TAGVDW0S1_tag_9         BIT13
 set     FMC_TAGVDW0S1_tag_10        BIT14
 set     FMC_TAGVDW0S1_tag_11        BIT15
 set     FMC_TAGVDW0S1_tag_12        BIT16
 set     FMC_TAGVDW0S1_tag_13        BIT17
 set     FMC_TAGVDW0S1_tag_14        BIT18
 set     FMC_TAGVDW0S1_tag_15        BIT19

 set     FMC_TAGVDW0S2_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW0S2_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW0S2_tag_0         BIT4
 set     FMC_TAGVDW0S2_tag_1         BIT5
 set     FMC_TAGVDW0S2_tag_2         BIT6
 set     FMC_TAGVDW0S2_tag_3         BIT7
 set     FMC_TAGVDW0S2_tag_4         BIT8
 set     FMC_TAGVDW0S2_tag_5         BIT9
 set     FMC_TAGVDW0S2_tag_6         BIT10
 set     FMC_TAGVDW0S2_tag_7         BIT11
 set     FMC_TAGVDW0S2_tag_8         BIT12
 set     FMC_TAGVDW0S2_tag_9         BIT13
 set     FMC_TAGVDW0S2_tag_10        BIT14
 set     FMC_TAGVDW0S2_tag_11        BIT15
 set     FMC_TAGVDW0S2_tag_12        BIT16
 set     FMC_TAGVDW0S2_tag_13        BIT17
 set     FMC_TAGVDW0S2_tag_14        BIT18
 set     FMC_TAGVDW0S2_tag_15        BIT19

 set     FMC_TAGVDW0S3_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW0S3_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW0S3_tag_0         BIT4
 set     FMC_TAGVDW0S3_tag_1         BIT5
 set     FMC_TAGVDW0S3_tag_2         BIT6
 set     FMC_TAGVDW0S3_tag_3         BIT7
 set     FMC_TAGVDW0S3_tag_4         BIT8
 set     FMC_TAGVDW0S3_tag_5         BIT9
 set     FMC_TAGVDW0S3_tag_6         BIT10
 set     FMC_TAGVDW0S3_tag_7         BIT11
 set     FMC_TAGVDW0S3_tag_8         BIT12
 set     FMC_TAGVDW0S3_tag_9         BIT13
 set     FMC_TAGVDW0S3_tag_10        BIT14
 set     FMC_TAGVDW0S3_tag_11        BIT15
 set     FMC_TAGVDW0S3_tag_12        BIT16
 set     FMC_TAGVDW0S3_tag_13        BIT17
 set     FMC_TAGVDW0S3_tag_14        BIT18
 set     FMC_TAGVDW0S3_tag_15        BIT19

 set     FMC_TAGVDW1S0_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW1S0_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW1S0_tag_0         BIT4
 set     FMC_TAGVDW1S0_tag_1         BIT5
 set     FMC_TAGVDW1S0_tag_2         BIT6
 set     FMC_TAGVDW1S0_tag_3         BIT7
 set     FMC_TAGVDW1S0_tag_4         BIT8
 set     FMC_TAGVDW1S0_tag_5         BIT9
 set     FMC_TAGVDW1S0_tag_6         BIT10
 set     FMC_TAGVDW1S0_tag_7         BIT11
 set     FMC_TAGVDW1S0_tag_8         BIT12
 set     FMC_TAGVDW1S0_tag_9         BIT13
 set     FMC_TAGVDW1S0_tag_10        BIT14
 set     FMC_TAGVDW1S0_tag_11        BIT15
 set     FMC_TAGVDW1S0_tag_12        BIT16
 set     FMC_TAGVDW1S0_tag_13        BIT17
 set     FMC_TAGVDW1S0_tag_14        BIT18
 set     FMC_TAGVDW1S0_tag_15        BIT19

 set     FMC_TAGVDW1S1_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW1S1_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW1S1_tag_0         BIT4
 set     FMC_TAGVDW1S1_tag_1         BIT5
 set     FMC_TAGVDW1S1_tag_2         BIT6
 set     FMC_TAGVDW1S1_tag_3         BIT7
 set     FMC_TAGVDW1S1_tag_4         BIT8
 set     FMC_TAGVDW1S1_tag_5         BIT9
 set     FMC_TAGVDW1S1_tag_6         BIT10
 set     FMC_TAGVDW1S1_tag_7         BIT11
 set     FMC_TAGVDW1S1_tag_8         BIT12
 set     FMC_TAGVDW1S1_tag_9         BIT13
 set     FMC_TAGVDW1S1_tag_10        BIT14
 set     FMC_TAGVDW1S1_tag_11        BIT15
 set     FMC_TAGVDW1S1_tag_12        BIT16
 set     FMC_TAGVDW1S1_tag_13        BIT17
 set     FMC_TAGVDW1S1_tag_14        BIT18
 set     FMC_TAGVDW1S1_tag_15        BIT19

 set     FMC_TAGVDW1S2_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW1S2_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW1S2_tag_0         BIT4
 set     FMC_TAGVDW1S2_tag_1         BIT5
 set     FMC_TAGVDW1S2_tag_2         BIT6
 set     FMC_TAGVDW1S2_tag_3         BIT7
 set     FMC_TAGVDW1S2_tag_4         BIT8
 set     FMC_TAGVDW1S2_tag_5         BIT9
 set     FMC_TAGVDW1S2_tag_6         BIT10
 set     FMC_TAGVDW1S2_tag_7         BIT11
 set     FMC_TAGVDW1S2_tag_8         BIT12
 set     FMC_TAGVDW1S2_tag_9         BIT13
 set     FMC_TAGVDW1S2_tag_10        BIT14
 set     FMC_TAGVDW1S2_tag_11        BIT15
 set     FMC_TAGVDW1S2_tag_12        BIT16
 set     FMC_TAGVDW1S2_tag_13        BIT17
 set     FMC_TAGVDW1S2_tag_14        BIT18
 set     FMC_TAGVDW1S2_tag_15        BIT19

 set     FMC_TAGVDW1S3_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW1S3_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW1S3_tag_0         BIT4
 set     FMC_TAGVDW1S3_tag_1         BIT5
 set     FMC_TAGVDW1S3_tag_2         BIT6
 set     FMC_TAGVDW1S3_tag_3         BIT7
 set     FMC_TAGVDW1S3_tag_4         BIT8
 set     FMC_TAGVDW1S3_tag_5         BIT9
 set     FMC_TAGVDW1S3_tag_6         BIT10
 set     FMC_TAGVDW1S3_tag_7         BIT11
 set     FMC_TAGVDW1S3_tag_8         BIT12
 set     FMC_TAGVDW1S3_tag_9         BIT13
 set     FMC_TAGVDW1S3_tag_10        BIT14
 set     FMC_TAGVDW1S3_tag_11        BIT15
 set     FMC_TAGVDW1S3_tag_12        BIT16
 set     FMC_TAGVDW1S3_tag_13        BIT17
 set     FMC_TAGVDW1S3_tag_14        BIT18
 set     FMC_TAGVDW1S3_tag_15        BIT19

 set     FMC_TAGVDW2S0_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW2S0_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW2S0_tag_0         BIT4
 set     FMC_TAGVDW2S0_tag_1         BIT5
 set     FMC_TAGVDW2S0_tag_2         BIT6
 set     FMC_TAGVDW2S0_tag_3         BIT7
 set     FMC_TAGVDW2S0_tag_4         BIT8
 set     FMC_TAGVDW2S0_tag_5         BIT9
 set     FMC_TAGVDW2S0_tag_6         BIT10
 set     FMC_TAGVDW2S0_tag_7         BIT11
 set     FMC_TAGVDW2S0_tag_8         BIT12
 set     FMC_TAGVDW2S0_tag_9         BIT13
 set     FMC_TAGVDW2S0_tag_10        BIT14
 set     FMC_TAGVDW2S0_tag_11        BIT15
 set     FMC_TAGVDW2S0_tag_12        BIT16
 set     FMC_TAGVDW2S0_tag_13        BIT17
 set     FMC_TAGVDW2S0_tag_14        BIT18
 set     FMC_TAGVDW2S0_tag_15        BIT19

 set     FMC_TAGVDW2S1_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW2S1_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW2S1_tag_0         BIT4
 set     FMC_TAGVDW2S1_tag_1         BIT5
 set     FMC_TAGVDW2S1_tag_2         BIT6
 set     FMC_TAGVDW2S1_tag_3         BIT7
 set     FMC_TAGVDW2S1_tag_4         BIT8
 set     FMC_TAGVDW2S1_tag_5         BIT9
 set     FMC_TAGVDW2S1_tag_6         BIT10
 set     FMC_TAGVDW2S1_tag_7         BIT11
 set     FMC_TAGVDW2S1_tag_8         BIT12
 set     FMC_TAGVDW2S1_tag_9         BIT13
 set     FMC_TAGVDW2S1_tag_10        BIT14
 set     FMC_TAGVDW2S1_tag_11        BIT15
 set     FMC_TAGVDW2S1_tag_12        BIT16
 set     FMC_TAGVDW2S1_tag_13        BIT17
 set     FMC_TAGVDW2S1_tag_14        BIT18
 set     FMC_TAGVDW2S1_tag_15        BIT19

 set     FMC_TAGVDW2S2_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW2S2_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW2S2_tag_0         BIT4
 set     FMC_TAGVDW2S2_tag_1         BIT5
 set     FMC_TAGVDW2S2_tag_2         BIT6
 set     FMC_TAGVDW2S2_tag_3         BIT7
 set     FMC_TAGVDW2S2_tag_4         BIT8
 set     FMC_TAGVDW2S2_tag_5         BIT9
 set     FMC_TAGVDW2S2_tag_6         BIT10
 set     FMC_TAGVDW2S2_tag_7         BIT11
 set     FMC_TAGVDW2S2_tag_8         BIT12
 set     FMC_TAGVDW2S2_tag_9         BIT13
 set     FMC_TAGVDW2S2_tag_10        BIT14
 set     FMC_TAGVDW2S2_tag_11        BIT15
 set     FMC_TAGVDW2S2_tag_12        BIT16
 set     FMC_TAGVDW2S2_tag_13        BIT17
 set     FMC_TAGVDW2S2_tag_14        BIT18
 set     FMC_TAGVDW2S2_tag_15        BIT19

 set     FMC_TAGVDW2S3_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW2S3_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW2S3_tag_0         BIT4
 set     FMC_TAGVDW2S3_tag_1         BIT5
 set     FMC_TAGVDW2S3_tag_2         BIT6
 set     FMC_TAGVDW2S3_tag_3         BIT7
 set     FMC_TAGVDW2S3_tag_4         BIT8
 set     FMC_TAGVDW2S3_tag_5         BIT9
 set     FMC_TAGVDW2S3_tag_6         BIT10
 set     FMC_TAGVDW2S3_tag_7         BIT11
 set     FMC_TAGVDW2S3_tag_8         BIT12
 set     FMC_TAGVDW2S3_tag_9         BIT13
 set     FMC_TAGVDW2S3_tag_10        BIT14
 set     FMC_TAGVDW2S3_tag_11        BIT15
 set     FMC_TAGVDW2S3_tag_12        BIT16
 set     FMC_TAGVDW2S3_tag_13        BIT17
 set     FMC_TAGVDW2S3_tag_14        BIT18
 set     FMC_TAGVDW2S3_tag_15        BIT19

 set     FMC_TAGVDW3S0_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW3S0_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW3S0_tag_0         BIT4
 set     FMC_TAGVDW3S0_tag_1         BIT5
 set     FMC_TAGVDW3S0_tag_2         BIT6
 set     FMC_TAGVDW3S0_tag_3         BIT7
 set     FMC_TAGVDW3S0_tag_4         BIT8
 set     FMC_TAGVDW3S0_tag_5         BIT9
 set     FMC_TAGVDW3S0_tag_6         BIT10
 set     FMC_TAGVDW3S0_tag_7         BIT11
 set     FMC_TAGVDW3S0_tag_8         BIT12
 set     FMC_TAGVDW3S0_tag_9         BIT13
 set     FMC_TAGVDW3S0_tag_10        BIT14
 set     FMC_TAGVDW3S0_tag_11        BIT15
 set     FMC_TAGVDW3S0_tag_12        BIT16
 set     FMC_TAGVDW3S0_tag_13        BIT17
 set     FMC_TAGVDW3S0_tag_14        BIT18
 set     FMC_TAGVDW3S0_tag_15        BIT19

 set     FMC_TAGVDW3S1_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW3S1_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW3S1_tag_0         BIT4
 set     FMC_TAGVDW3S1_tag_1         BIT5
 set     FMC_TAGVDW3S1_tag_2         BIT6
 set     FMC_TAGVDW3S1_tag_3         BIT7
 set     FMC_TAGVDW3S1_tag_4         BIT8
 set     FMC_TAGVDW3S1_tag_5         BIT9
 set     FMC_TAGVDW3S1_tag_6         BIT10
 set     FMC_TAGVDW3S1_tag_7         BIT11
 set     FMC_TAGVDW3S1_tag_8         BIT12
 set     FMC_TAGVDW3S1_tag_9         BIT13
 set     FMC_TAGVDW3S1_tag_10        BIT14
 set     FMC_TAGVDW3S1_tag_11        BIT15
 set     FMC_TAGVDW3S1_tag_12        BIT16
 set     FMC_TAGVDW3S1_tag_13        BIT17
 set     FMC_TAGVDW3S1_tag_14        BIT18
 set     FMC_TAGVDW3S1_tag_15        BIT19

 set     FMC_TAGVDW3S2_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW3S2_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW3S2_tag_0         BIT4
 set     FMC_TAGVDW3S2_tag_1         BIT5
 set     FMC_TAGVDW3S2_tag_2         BIT6
 set     FMC_TAGVDW3S2_tag_3         BIT7
 set     FMC_TAGVDW3S2_tag_4         BIT8
 set     FMC_TAGVDW3S2_tag_5         BIT9
 set     FMC_TAGVDW3S2_tag_6         BIT10
 set     FMC_TAGVDW3S2_tag_7         BIT11
 set     FMC_TAGVDW3S2_tag_8         BIT12
 set     FMC_TAGVDW3S2_tag_9         BIT13
 set     FMC_TAGVDW3S2_tag_10        BIT14
 set     FMC_TAGVDW3S2_tag_11        BIT15
 set     FMC_TAGVDW3S2_tag_12        BIT16
 set     FMC_TAGVDW3S2_tag_13        BIT17
 set     FMC_TAGVDW3S2_tag_14        BIT18
 set     FMC_TAGVDW3S2_tag_15        BIT19

 set     FMC_TAGVDW3S3_valid         BIT0
;;   1-bit valid for cache entry

 set     FMC_TAGVDW3S3_tag           (BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19)
;;   16-bit tag for cache entry
 set     FMC_TAGVDW3S3_tag_0         BIT4
 set     FMC_TAGVDW3S3_tag_1         BIT5
 set     FMC_TAGVDW3S3_tag_2         BIT6
 set     FMC_TAGVDW3S3_tag_3         BIT7
 set     FMC_TAGVDW3S3_tag_4         BIT8
 set     FMC_TAGVDW3S3_tag_5         BIT9
 set     FMC_TAGVDW3S3_tag_6         BIT10
 set     FMC_TAGVDW3S3_tag_7         BIT11
 set     FMC_TAGVDW3S3_tag_8         BIT12
 set     FMC_TAGVDW3S3_tag_9         BIT13
 set     FMC_TAGVDW3S3_tag_10        BIT14
 set     FMC_TAGVDW3S3_tag_11        BIT15
 set     FMC_TAGVDW3S3_tag_12        BIT16
 set     FMC_TAGVDW3S3_tag_13        BIT17
 set     FMC_TAGVDW3S3_tag_14        BIT18
 set     FMC_TAGVDW3S3_tag_15        BIT19

 set     FMC_DATAW0S0_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW0S0_data_0         BIT0
 set     FMC_DATAW0S0_data_1         BIT1
 set     FMC_DATAW0S0_data_2         BIT2
 set     FMC_DATAW0S0_data_3         BIT3
 set     FMC_DATAW0S0_data_4         BIT4
 set     FMC_DATAW0S0_data_5         BIT5
 set     FMC_DATAW0S0_data_6         BIT6
 set     FMC_DATAW0S0_data_7         BIT7
 set     FMC_DATAW0S0_data_8         BIT8
 set     FMC_DATAW0S0_data_9         BIT9
 set     FMC_DATAW0S0_data_10        BIT10
 set     FMC_DATAW0S0_data_11        BIT11
 set     FMC_DATAW0S0_data_12        BIT12
 set     FMC_DATAW0S0_data_13        BIT13
 set     FMC_DATAW0S0_data_14        BIT14
 set     FMC_DATAW0S0_data_15        BIT15
 set     FMC_DATAW0S0_data_16        BIT16
 set     FMC_DATAW0S0_data_17        BIT17
 set     FMC_DATAW0S0_data_18        BIT18
 set     FMC_DATAW0S0_data_19        BIT19
 set     FMC_DATAW0S0_data_20        BIT20
 set     FMC_DATAW0S0_data_21        BIT21
 set     FMC_DATAW0S0_data_22        BIT22
 set     FMC_DATAW0S0_data_23        BIT23
 set     FMC_DATAW0S0_data_24        BIT24
 set     FMC_DATAW0S0_data_25        BIT25
 set     FMC_DATAW0S0_data_26        BIT26
 set     FMC_DATAW0S0_data_27        BIT27
 set     FMC_DATAW0S0_data_28        BIT28
 set     FMC_DATAW0S0_data_29        BIT29
 set     FMC_DATAW0S0_data_30        BIT30
 set     FMC_DATAW0S0_data_31        BIT31

 set     FMC_DATAW0S1_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW0S1_data_0         BIT0
 set     FMC_DATAW0S1_data_1         BIT1
 set     FMC_DATAW0S1_data_2         BIT2
 set     FMC_DATAW0S1_data_3         BIT3
 set     FMC_DATAW0S1_data_4         BIT4
 set     FMC_DATAW0S1_data_5         BIT5
 set     FMC_DATAW0S1_data_6         BIT6
 set     FMC_DATAW0S1_data_7         BIT7
 set     FMC_DATAW0S1_data_8         BIT8
 set     FMC_DATAW0S1_data_9         BIT9
 set     FMC_DATAW0S1_data_10        BIT10
 set     FMC_DATAW0S1_data_11        BIT11
 set     FMC_DATAW0S1_data_12        BIT12
 set     FMC_DATAW0S1_data_13        BIT13
 set     FMC_DATAW0S1_data_14        BIT14
 set     FMC_DATAW0S1_data_15        BIT15
 set     FMC_DATAW0S1_data_16        BIT16
 set     FMC_DATAW0S1_data_17        BIT17
 set     FMC_DATAW0S1_data_18        BIT18
 set     FMC_DATAW0S1_data_19        BIT19
 set     FMC_DATAW0S1_data_20        BIT20
 set     FMC_DATAW0S1_data_21        BIT21
 set     FMC_DATAW0S1_data_22        BIT22
 set     FMC_DATAW0S1_data_23        BIT23
 set     FMC_DATAW0S1_data_24        BIT24
 set     FMC_DATAW0S1_data_25        BIT25
 set     FMC_DATAW0S1_data_26        BIT26
 set     FMC_DATAW0S1_data_27        BIT27
 set     FMC_DATAW0S1_data_28        BIT28
 set     FMC_DATAW0S1_data_29        BIT29
 set     FMC_DATAW0S1_data_30        BIT30
 set     FMC_DATAW0S1_data_31        BIT31

 set     FMC_DATAW0S2_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW0S2_data_0         BIT0
 set     FMC_DATAW0S2_data_1         BIT1
 set     FMC_DATAW0S2_data_2         BIT2
 set     FMC_DATAW0S2_data_3         BIT3
 set     FMC_DATAW0S2_data_4         BIT4
 set     FMC_DATAW0S2_data_5         BIT5
 set     FMC_DATAW0S2_data_6         BIT6
 set     FMC_DATAW0S2_data_7         BIT7
 set     FMC_DATAW0S2_data_8         BIT8
 set     FMC_DATAW0S2_data_9         BIT9
 set     FMC_DATAW0S2_data_10        BIT10
 set     FMC_DATAW0S2_data_11        BIT11
 set     FMC_DATAW0S2_data_12        BIT12
 set     FMC_DATAW0S2_data_13        BIT13
 set     FMC_DATAW0S2_data_14        BIT14
 set     FMC_DATAW0S2_data_15        BIT15
 set     FMC_DATAW0S2_data_16        BIT16
 set     FMC_DATAW0S2_data_17        BIT17
 set     FMC_DATAW0S2_data_18        BIT18
 set     FMC_DATAW0S2_data_19        BIT19
 set     FMC_DATAW0S2_data_20        BIT20
 set     FMC_DATAW0S2_data_21        BIT21
 set     FMC_DATAW0S2_data_22        BIT22
 set     FMC_DATAW0S2_data_23        BIT23
 set     FMC_DATAW0S2_data_24        BIT24
 set     FMC_DATAW0S2_data_25        BIT25
 set     FMC_DATAW0S2_data_26        BIT26
 set     FMC_DATAW0S2_data_27        BIT27
 set     FMC_DATAW0S2_data_28        BIT28
 set     FMC_DATAW0S2_data_29        BIT29
 set     FMC_DATAW0S2_data_30        BIT30
 set     FMC_DATAW0S2_data_31        BIT31

 set     FMC_DATAW0S3_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW0S3_data_0         BIT0
 set     FMC_DATAW0S3_data_1         BIT1
 set     FMC_DATAW0S3_data_2         BIT2
 set     FMC_DATAW0S3_data_3         BIT3
 set     FMC_DATAW0S3_data_4         BIT4
 set     FMC_DATAW0S3_data_5         BIT5
 set     FMC_DATAW0S3_data_6         BIT6
 set     FMC_DATAW0S3_data_7         BIT7
 set     FMC_DATAW0S3_data_8         BIT8
 set     FMC_DATAW0S3_data_9         BIT9
 set     FMC_DATAW0S3_data_10        BIT10
 set     FMC_DATAW0S3_data_11        BIT11
 set     FMC_DATAW0S3_data_12        BIT12
 set     FMC_DATAW0S3_data_13        BIT13
 set     FMC_DATAW0S3_data_14        BIT14
 set     FMC_DATAW0S3_data_15        BIT15
 set     FMC_DATAW0S3_data_16        BIT16
 set     FMC_DATAW0S3_data_17        BIT17
 set     FMC_DATAW0S3_data_18        BIT18
 set     FMC_DATAW0S3_data_19        BIT19
 set     FMC_DATAW0S3_data_20        BIT20
 set     FMC_DATAW0S3_data_21        BIT21
 set     FMC_DATAW0S3_data_22        BIT22
 set     FMC_DATAW0S3_data_23        BIT23
 set     FMC_DATAW0S3_data_24        BIT24
 set     FMC_DATAW0S3_data_25        BIT25
 set     FMC_DATAW0S3_data_26        BIT26
 set     FMC_DATAW0S3_data_27        BIT27
 set     FMC_DATAW0S3_data_28        BIT28
 set     FMC_DATAW0S3_data_29        BIT29
 set     FMC_DATAW0S3_data_30        BIT30
 set     FMC_DATAW0S3_data_31        BIT31

 set     FMC_DATAW1S0_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW1S0_data_0         BIT0
 set     FMC_DATAW1S0_data_1         BIT1
 set     FMC_DATAW1S0_data_2         BIT2
 set     FMC_DATAW1S0_data_3         BIT3
 set     FMC_DATAW1S0_data_4         BIT4
 set     FMC_DATAW1S0_data_5         BIT5
 set     FMC_DATAW1S0_data_6         BIT6
 set     FMC_DATAW1S0_data_7         BIT7
 set     FMC_DATAW1S0_data_8         BIT8
 set     FMC_DATAW1S0_data_9         BIT9
 set     FMC_DATAW1S0_data_10        BIT10
 set     FMC_DATAW1S0_data_11        BIT11
 set     FMC_DATAW1S0_data_12        BIT12
 set     FMC_DATAW1S0_data_13        BIT13
 set     FMC_DATAW1S0_data_14        BIT14
 set     FMC_DATAW1S0_data_15        BIT15
 set     FMC_DATAW1S0_data_16        BIT16
 set     FMC_DATAW1S0_data_17        BIT17
 set     FMC_DATAW1S0_data_18        BIT18
 set     FMC_DATAW1S0_data_19        BIT19
 set     FMC_DATAW1S0_data_20        BIT20
 set     FMC_DATAW1S0_data_21        BIT21
 set     FMC_DATAW1S0_data_22        BIT22
 set     FMC_DATAW1S0_data_23        BIT23
 set     FMC_DATAW1S0_data_24        BIT24
 set     FMC_DATAW1S0_data_25        BIT25
 set     FMC_DATAW1S0_data_26        BIT26
 set     FMC_DATAW1S0_data_27        BIT27
 set     FMC_DATAW1S0_data_28        BIT28
 set     FMC_DATAW1S0_data_29        BIT29
 set     FMC_DATAW1S0_data_30        BIT30
 set     FMC_DATAW1S0_data_31        BIT31

 set     FMC_DATAW1S1_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW1S1_data_0         BIT0
 set     FMC_DATAW1S1_data_1         BIT1
 set     FMC_DATAW1S1_data_2         BIT2
 set     FMC_DATAW1S1_data_3         BIT3
 set     FMC_DATAW1S1_data_4         BIT4
 set     FMC_DATAW1S1_data_5         BIT5
 set     FMC_DATAW1S1_data_6         BIT6
 set     FMC_DATAW1S1_data_7         BIT7
 set     FMC_DATAW1S1_data_8         BIT8
 set     FMC_DATAW1S1_data_9         BIT9
 set     FMC_DATAW1S1_data_10        BIT10
 set     FMC_DATAW1S1_data_11        BIT11
 set     FMC_DATAW1S1_data_12        BIT12
 set     FMC_DATAW1S1_data_13        BIT13
 set     FMC_DATAW1S1_data_14        BIT14
 set     FMC_DATAW1S1_data_15        BIT15
 set     FMC_DATAW1S1_data_16        BIT16
 set     FMC_DATAW1S1_data_17        BIT17
 set     FMC_DATAW1S1_data_18        BIT18
 set     FMC_DATAW1S1_data_19        BIT19
 set     FMC_DATAW1S1_data_20        BIT20
 set     FMC_DATAW1S1_data_21        BIT21
 set     FMC_DATAW1S1_data_22        BIT22
 set     FMC_DATAW1S1_data_23        BIT23
 set     FMC_DATAW1S1_data_24        BIT24
 set     FMC_DATAW1S1_data_25        BIT25
 set     FMC_DATAW1S1_data_26        BIT26
 set     FMC_DATAW1S1_data_27        BIT27
 set     FMC_DATAW1S1_data_28        BIT28
 set     FMC_DATAW1S1_data_29        BIT29
 set     FMC_DATAW1S1_data_30        BIT30
 set     FMC_DATAW1S1_data_31        BIT31

 set     FMC_DATAW1S2_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW1S2_data_0         BIT0
 set     FMC_DATAW1S2_data_1         BIT1
 set     FMC_DATAW1S2_data_2         BIT2
 set     FMC_DATAW1S2_data_3         BIT3
 set     FMC_DATAW1S2_data_4         BIT4
 set     FMC_DATAW1S2_data_5         BIT5
 set     FMC_DATAW1S2_data_6         BIT6
 set     FMC_DATAW1S2_data_7         BIT7
 set     FMC_DATAW1S2_data_8         BIT8
 set     FMC_DATAW1S2_data_9         BIT9
 set     FMC_DATAW1S2_data_10        BIT10
 set     FMC_DATAW1S2_data_11        BIT11
 set     FMC_DATAW1S2_data_12        BIT12
 set     FMC_DATAW1S2_data_13        BIT13
 set     FMC_DATAW1S2_data_14        BIT14
 set     FMC_DATAW1S2_data_15        BIT15
 set     FMC_DATAW1S2_data_16        BIT16
 set     FMC_DATAW1S2_data_17        BIT17
 set     FMC_DATAW1S2_data_18        BIT18
 set     FMC_DATAW1S2_data_19        BIT19
 set     FMC_DATAW1S2_data_20        BIT20
 set     FMC_DATAW1S2_data_21        BIT21
 set     FMC_DATAW1S2_data_22        BIT22
 set     FMC_DATAW1S2_data_23        BIT23
 set     FMC_DATAW1S2_data_24        BIT24
 set     FMC_DATAW1S2_data_25        BIT25
 set     FMC_DATAW1S2_data_26        BIT26
 set     FMC_DATAW1S2_data_27        BIT27
 set     FMC_DATAW1S2_data_28        BIT28
 set     FMC_DATAW1S2_data_29        BIT29
 set     FMC_DATAW1S2_data_30        BIT30
 set     FMC_DATAW1S2_data_31        BIT31

 set     FMC_DATAW1S3_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW1S3_data_0         BIT0
 set     FMC_DATAW1S3_data_1         BIT1
 set     FMC_DATAW1S3_data_2         BIT2
 set     FMC_DATAW1S3_data_3         BIT3
 set     FMC_DATAW1S3_data_4         BIT4
 set     FMC_DATAW1S3_data_5         BIT5
 set     FMC_DATAW1S3_data_6         BIT6
 set     FMC_DATAW1S3_data_7         BIT7
 set     FMC_DATAW1S3_data_8         BIT8
 set     FMC_DATAW1S3_data_9         BIT9
 set     FMC_DATAW1S3_data_10        BIT10
 set     FMC_DATAW1S3_data_11        BIT11
 set     FMC_DATAW1S3_data_12        BIT12
 set     FMC_DATAW1S3_data_13        BIT13
 set     FMC_DATAW1S3_data_14        BIT14
 set     FMC_DATAW1S3_data_15        BIT15
 set     FMC_DATAW1S3_data_16        BIT16
 set     FMC_DATAW1S3_data_17        BIT17
 set     FMC_DATAW1S3_data_18        BIT18
 set     FMC_DATAW1S3_data_19        BIT19
 set     FMC_DATAW1S3_data_20        BIT20
 set     FMC_DATAW1S3_data_21        BIT21
 set     FMC_DATAW1S3_data_22        BIT22
 set     FMC_DATAW1S3_data_23        BIT23
 set     FMC_DATAW1S3_data_24        BIT24
 set     FMC_DATAW1S3_data_25        BIT25
 set     FMC_DATAW1S3_data_26        BIT26
 set     FMC_DATAW1S3_data_27        BIT27
 set     FMC_DATAW1S3_data_28        BIT28
 set     FMC_DATAW1S3_data_29        BIT29
 set     FMC_DATAW1S3_data_30        BIT30
 set     FMC_DATAW1S3_data_31        BIT31

 set     FMC_DATAW2S0_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW2S0_data_0         BIT0
 set     FMC_DATAW2S0_data_1         BIT1
 set     FMC_DATAW2S0_data_2         BIT2
 set     FMC_DATAW2S0_data_3         BIT3
 set     FMC_DATAW2S0_data_4         BIT4
 set     FMC_DATAW2S0_data_5         BIT5
 set     FMC_DATAW2S0_data_6         BIT6
 set     FMC_DATAW2S0_data_7         BIT7
 set     FMC_DATAW2S0_data_8         BIT8
 set     FMC_DATAW2S0_data_9         BIT9
 set     FMC_DATAW2S0_data_10        BIT10
 set     FMC_DATAW2S0_data_11        BIT11
 set     FMC_DATAW2S0_data_12        BIT12
 set     FMC_DATAW2S0_data_13        BIT13
 set     FMC_DATAW2S0_data_14        BIT14
 set     FMC_DATAW2S0_data_15        BIT15
 set     FMC_DATAW2S0_data_16        BIT16
 set     FMC_DATAW2S0_data_17        BIT17
 set     FMC_DATAW2S0_data_18        BIT18
 set     FMC_DATAW2S0_data_19        BIT19
 set     FMC_DATAW2S0_data_20        BIT20
 set     FMC_DATAW2S0_data_21        BIT21
 set     FMC_DATAW2S0_data_22        BIT22
 set     FMC_DATAW2S0_data_23        BIT23
 set     FMC_DATAW2S0_data_24        BIT24
 set     FMC_DATAW2S0_data_25        BIT25
 set     FMC_DATAW2S0_data_26        BIT26
 set     FMC_DATAW2S0_data_27        BIT27
 set     FMC_DATAW2S0_data_28        BIT28
 set     FMC_DATAW2S0_data_29        BIT29
 set     FMC_DATAW2S0_data_30        BIT30
 set     FMC_DATAW2S0_data_31        BIT31

 set     FMC_DATAW2S1_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW2S1_data_0         BIT0
 set     FMC_DATAW2S1_data_1         BIT1
 set     FMC_DATAW2S1_data_2         BIT2
 set     FMC_DATAW2S1_data_3         BIT3
 set     FMC_DATAW2S1_data_4         BIT4
 set     FMC_DATAW2S1_data_5         BIT5
 set     FMC_DATAW2S1_data_6         BIT6
 set     FMC_DATAW2S1_data_7         BIT7
 set     FMC_DATAW2S1_data_8         BIT8
 set     FMC_DATAW2S1_data_9         BIT9
 set     FMC_DATAW2S1_data_10        BIT10
 set     FMC_DATAW2S1_data_11        BIT11
 set     FMC_DATAW2S1_data_12        BIT12
 set     FMC_DATAW2S1_data_13        BIT13
 set     FMC_DATAW2S1_data_14        BIT14
 set     FMC_DATAW2S1_data_15        BIT15
 set     FMC_DATAW2S1_data_16        BIT16
 set     FMC_DATAW2S1_data_17        BIT17
 set     FMC_DATAW2S1_data_18        BIT18
 set     FMC_DATAW2S1_data_19        BIT19
 set     FMC_DATAW2S1_data_20        BIT20
 set     FMC_DATAW2S1_data_21        BIT21
 set     FMC_DATAW2S1_data_22        BIT22
 set     FMC_DATAW2S1_data_23        BIT23
 set     FMC_DATAW2S1_data_24        BIT24
 set     FMC_DATAW2S1_data_25        BIT25
 set     FMC_DATAW2S1_data_26        BIT26
 set     FMC_DATAW2S1_data_27        BIT27
 set     FMC_DATAW2S1_data_28        BIT28
 set     FMC_DATAW2S1_data_29        BIT29
 set     FMC_DATAW2S1_data_30        BIT30
 set     FMC_DATAW2S1_data_31        BIT31

 set     FMC_DATAW2S2_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW2S2_data_0         BIT0
 set     FMC_DATAW2S2_data_1         BIT1
 set     FMC_DATAW2S2_data_2         BIT2
 set     FMC_DATAW2S2_data_3         BIT3
 set     FMC_DATAW2S2_data_4         BIT4
 set     FMC_DATAW2S2_data_5         BIT5
 set     FMC_DATAW2S2_data_6         BIT6
 set     FMC_DATAW2S2_data_7         BIT7
 set     FMC_DATAW2S2_data_8         BIT8
 set     FMC_DATAW2S2_data_9         BIT9
 set     FMC_DATAW2S2_data_10        BIT10
 set     FMC_DATAW2S2_data_11        BIT11
 set     FMC_DATAW2S2_data_12        BIT12
 set     FMC_DATAW2S2_data_13        BIT13
 set     FMC_DATAW2S2_data_14        BIT14
 set     FMC_DATAW2S2_data_15        BIT15
 set     FMC_DATAW2S2_data_16        BIT16
 set     FMC_DATAW2S2_data_17        BIT17
 set     FMC_DATAW2S2_data_18        BIT18
 set     FMC_DATAW2S2_data_19        BIT19
 set     FMC_DATAW2S2_data_20        BIT20
 set     FMC_DATAW2S2_data_21        BIT21
 set     FMC_DATAW2S2_data_22        BIT22
 set     FMC_DATAW2S2_data_23        BIT23
 set     FMC_DATAW2S2_data_24        BIT24
 set     FMC_DATAW2S2_data_25        BIT25
 set     FMC_DATAW2S2_data_26        BIT26
 set     FMC_DATAW2S2_data_27        BIT27
 set     FMC_DATAW2S2_data_28        BIT28
 set     FMC_DATAW2S2_data_29        BIT29
 set     FMC_DATAW2S2_data_30        BIT30
 set     FMC_DATAW2S2_data_31        BIT31

 set     FMC_DATAW2S3_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW2S3_data_0         BIT0
 set     FMC_DATAW2S3_data_1         BIT1
 set     FMC_DATAW2S3_data_2         BIT2
 set     FMC_DATAW2S3_data_3         BIT3
 set     FMC_DATAW2S3_data_4         BIT4
 set     FMC_DATAW2S3_data_5         BIT5
 set     FMC_DATAW2S3_data_6         BIT6
 set     FMC_DATAW2S3_data_7         BIT7
 set     FMC_DATAW2S3_data_8         BIT8
 set     FMC_DATAW2S3_data_9         BIT9
 set     FMC_DATAW2S3_data_10        BIT10
 set     FMC_DATAW2S3_data_11        BIT11
 set     FMC_DATAW2S3_data_12        BIT12
 set     FMC_DATAW2S3_data_13        BIT13
 set     FMC_DATAW2S3_data_14        BIT14
 set     FMC_DATAW2S3_data_15        BIT15
 set     FMC_DATAW2S3_data_16        BIT16
 set     FMC_DATAW2S3_data_17        BIT17
 set     FMC_DATAW2S3_data_18        BIT18
 set     FMC_DATAW2S3_data_19        BIT19
 set     FMC_DATAW2S3_data_20        BIT20
 set     FMC_DATAW2S3_data_21        BIT21
 set     FMC_DATAW2S3_data_22        BIT22
 set     FMC_DATAW2S3_data_23        BIT23
 set     FMC_DATAW2S3_data_24        BIT24
 set     FMC_DATAW2S3_data_25        BIT25
 set     FMC_DATAW2S3_data_26        BIT26
 set     FMC_DATAW2S3_data_27        BIT27
 set     FMC_DATAW2S3_data_28        BIT28
 set     FMC_DATAW2S3_data_29        BIT29
 set     FMC_DATAW2S3_data_30        BIT30
 set     FMC_DATAW2S3_data_31        BIT31

 set     FMC_DATAW3S0_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW3S0_data_0         BIT0
 set     FMC_DATAW3S0_data_1         BIT1
 set     FMC_DATAW3S0_data_2         BIT2
 set     FMC_DATAW3S0_data_3         BIT3
 set     FMC_DATAW3S0_data_4         BIT4
 set     FMC_DATAW3S0_data_5         BIT5
 set     FMC_DATAW3S0_data_6         BIT6
 set     FMC_DATAW3S0_data_7         BIT7
 set     FMC_DATAW3S0_data_8         BIT8
 set     FMC_DATAW3S0_data_9         BIT9
 set     FMC_DATAW3S0_data_10        BIT10
 set     FMC_DATAW3S0_data_11        BIT11
 set     FMC_DATAW3S0_data_12        BIT12
 set     FMC_DATAW3S0_data_13        BIT13
 set     FMC_DATAW3S0_data_14        BIT14
 set     FMC_DATAW3S0_data_15        BIT15
 set     FMC_DATAW3S0_data_16        BIT16
 set     FMC_DATAW3S0_data_17        BIT17
 set     FMC_DATAW3S0_data_18        BIT18
 set     FMC_DATAW3S0_data_19        BIT19
 set     FMC_DATAW3S0_data_20        BIT20
 set     FMC_DATAW3S0_data_21        BIT21
 set     FMC_DATAW3S0_data_22        BIT22
 set     FMC_DATAW3S0_data_23        BIT23
 set     FMC_DATAW3S0_data_24        BIT24
 set     FMC_DATAW3S0_data_25        BIT25
 set     FMC_DATAW3S0_data_26        BIT26
 set     FMC_DATAW3S0_data_27        BIT27
 set     FMC_DATAW3S0_data_28        BIT28
 set     FMC_DATAW3S0_data_29        BIT29
 set     FMC_DATAW3S0_data_30        BIT30
 set     FMC_DATAW3S0_data_31        BIT31

 set     FMC_DATAW3S1_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW3S1_data_0         BIT0
 set     FMC_DATAW3S1_data_1         BIT1
 set     FMC_DATAW3S1_data_2         BIT2
 set     FMC_DATAW3S1_data_3         BIT3
 set     FMC_DATAW3S1_data_4         BIT4
 set     FMC_DATAW3S1_data_5         BIT5
 set     FMC_DATAW3S1_data_6         BIT6
 set     FMC_DATAW3S1_data_7         BIT7
 set     FMC_DATAW3S1_data_8         BIT8
 set     FMC_DATAW3S1_data_9         BIT9
 set     FMC_DATAW3S1_data_10        BIT10
 set     FMC_DATAW3S1_data_11        BIT11
 set     FMC_DATAW3S1_data_12        BIT12
 set     FMC_DATAW3S1_data_13        BIT13
 set     FMC_DATAW3S1_data_14        BIT14
 set     FMC_DATAW3S1_data_15        BIT15
 set     FMC_DATAW3S1_data_16        BIT16
 set     FMC_DATAW3S1_data_17        BIT17
 set     FMC_DATAW3S1_data_18        BIT18
 set     FMC_DATAW3S1_data_19        BIT19
 set     FMC_DATAW3S1_data_20        BIT20
 set     FMC_DATAW3S1_data_21        BIT21
 set     FMC_DATAW3S1_data_22        BIT22
 set     FMC_DATAW3S1_data_23        BIT23
 set     FMC_DATAW3S1_data_24        BIT24
 set     FMC_DATAW3S1_data_25        BIT25
 set     FMC_DATAW3S1_data_26        BIT26
 set     FMC_DATAW3S1_data_27        BIT27
 set     FMC_DATAW3S1_data_28        BIT28
 set     FMC_DATAW3S1_data_29        BIT29
 set     FMC_DATAW3S1_data_30        BIT30
 set     FMC_DATAW3S1_data_31        BIT31

 set     FMC_DATAW3S2_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW3S2_data_0         BIT0
 set     FMC_DATAW3S2_data_1         BIT1
 set     FMC_DATAW3S2_data_2         BIT2
 set     FMC_DATAW3S2_data_3         BIT3
 set     FMC_DATAW3S2_data_4         BIT4
 set     FMC_DATAW3S2_data_5         BIT5
 set     FMC_DATAW3S2_data_6         BIT6
 set     FMC_DATAW3S2_data_7         BIT7
 set     FMC_DATAW3S2_data_8         BIT8
 set     FMC_DATAW3S2_data_9         BIT9
 set     FMC_DATAW3S2_data_10        BIT10
 set     FMC_DATAW3S2_data_11        BIT11
 set     FMC_DATAW3S2_data_12        BIT12
 set     FMC_DATAW3S2_data_13        BIT13
 set     FMC_DATAW3S2_data_14        BIT14
 set     FMC_DATAW3S2_data_15        BIT15
 set     FMC_DATAW3S2_data_16        BIT16
 set     FMC_DATAW3S2_data_17        BIT17
 set     FMC_DATAW3S2_data_18        BIT18
 set     FMC_DATAW3S2_data_19        BIT19
 set     FMC_DATAW3S2_data_20        BIT20
 set     FMC_DATAW3S2_data_21        BIT21
 set     FMC_DATAW3S2_data_22        BIT22
 set     FMC_DATAW3S2_data_23        BIT23
 set     FMC_DATAW3S2_data_24        BIT24
 set     FMC_DATAW3S2_data_25        BIT25
 set     FMC_DATAW3S2_data_26        BIT26
 set     FMC_DATAW3S2_data_27        BIT27
 set     FMC_DATAW3S2_data_28        BIT28
 set     FMC_DATAW3S2_data_29        BIT29
 set     FMC_DATAW3S2_data_30        BIT30
 set     FMC_DATAW3S2_data_31        BIT31

 set     FMC_DATAW3S3_data           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Bits [31:0] of data entry
 set     FMC_DATAW3S3_data_0         BIT0
 set     FMC_DATAW3S3_data_1         BIT1
 set     FMC_DATAW3S3_data_2         BIT2
 set     FMC_DATAW3S3_data_3         BIT3
 set     FMC_DATAW3S3_data_4         BIT4
 set     FMC_DATAW3S3_data_5         BIT5
 set     FMC_DATAW3S3_data_6         BIT6
 set     FMC_DATAW3S3_data_7         BIT7
 set     FMC_DATAW3S3_data_8         BIT8
 set     FMC_DATAW3S3_data_9         BIT9
 set     FMC_DATAW3S3_data_10        BIT10
 set     FMC_DATAW3S3_data_11        BIT11
 set     FMC_DATAW3S3_data_12        BIT12
 set     FMC_DATAW3S3_data_13        BIT13
 set     FMC_DATAW3S3_data_14        BIT14
 set     FMC_DATAW3S3_data_15        BIT15
 set     FMC_DATAW3S3_data_16        BIT16
 set     FMC_DATAW3S3_data_17        BIT17
 set     FMC_DATAW3S3_data_18        BIT18
 set     FMC_DATAW3S3_data_19        BIT19
 set     FMC_DATAW3S3_data_20        BIT20
 set     FMC_DATAW3S3_data_21        BIT21
 set     FMC_DATAW3S3_data_22        BIT22
 set     FMC_DATAW3S3_data_23        BIT23
 set     FMC_DATAW3S3_data_24        BIT24
 set     FMC_DATAW3S3_data_25        BIT25
 set     FMC_DATAW3S3_data_26        BIT26
 set     FMC_DATAW3S3_data_27        BIT27
 set     FMC_DATAW3S3_data_28        BIT28
 set     FMC_DATAW3S3_data_29        BIT29
 set     FMC_DATAW3S3_data_30        BIT30
 set     FMC_DATAW3S3_data_31        BIT31

 set     FTFA_FSTAT_MGSTAT0          BIT0
;;   Memory Controller Command Completion Status Flag

 set     FTFA_FSTAT_FPVIOL           BIT4
;;   Flash Protection Violation Flag
;;     0b0 ==> No protection violation detected
;;     0b1 ==> Protection violation detected

 set     FTFA_FSTAT_ACCERR           BIT5
;;   Flash Access Error Flag
;;     0b0 ==> No access error detected
;;     0b1 ==> Access error detected

 set     FTFA_FSTAT_RDCOLERR         BIT6
;;   Flash Read Collision Error Flag
;;     0b0 ==> No collision error detected
;;     0b1 ==> Collision error detected

 set     FTFA_FSTAT_CCIF             BIT7
;;   Command Complete Interrupt Flag
;;     0b0 ==> Flash command in progress
;;     0b1 ==> Flash command has completed

 set     FTFA_FCNFG_ERSSUSP          BIT4
;;   Erase Suspend
;;     0b0 ==> No suspend requested
;;     0b1 ==> Suspend the current Erase Flash Sector command execution.

 set     FTFA_FCNFG_ERSAREQ          BIT5
;;   Erase All Request
;;     0b0 ==> No request or request complete
;;     0b1 ==> Request to: run the Erase All Blocks command, verify the erased state, program the security byte in the Flash Configuration Field to the unsecure state, and release MCU security by setting the FSEC[SEC] field to the unsecure state.

 set     FTFA_FCNFG_RDCOLLIE         BIT6
;;   Read Collision Error Interrupt Enable
;;     0b0 ==> Read collision error interrupt disabled
;;     0b1 ==> Read collision error interrupt enabled. An interrupt request is generated whenever a flash memory read collision error is detected (see the description of FSTAT[RDCOLERR]).

 set     FTFA_FCNFG_CCIE             BIT7
;;   Command Complete Interrupt Enable
;;     0b0 ==> Command complete interrupt disabled
;;     0b1 ==> Command complete interrupt enabled. An interrupt request is generated whenever the FSTAT[CCIF] flag is set.

 set     FTFA_FSEC_SEC               (BIT0|BIT1)
;;   Flash Security
;;     0b00 ==> MCU security status is secure
;;     0b01 ==> MCU security status is secure
;;     0b10 ==> MCU security status is unsecure (The standard shipping condition of the flash memory module is unsecure.)
;;     0b11 ==> MCU security status is secure
 set     FTFA_FSEC_SEC_0             BIT0
 set     FTFA_FSEC_SEC_1             BIT1

 set     FTFA_FSEC_FSLACC            (BIT2|BIT3)
;;   Freescale Failure Analysis Access Code
;;     0b00 ==> Freescale factory access granted
;;     0b01 ==> Freescale factory access denied
;;     0b10 ==> Freescale factory access denied
;;     0b11 ==> Freescale factory access granted
 set     FTFA_FSEC_FSLACC_0          BIT2
 set     FTFA_FSEC_FSLACC_1          BIT3

 set     FTFA_FSEC_MEEN              (BIT4|BIT5)
;;   Mass Erase Enable Bits
;;     0b00 ==> Mass erase is enabled
;;     0b01 ==> Mass erase is enabled
;;     0b10 ==> Mass erase is disabled
;;     0b11 ==> Mass erase is enabled
 set     FTFA_FSEC_MEEN_0            BIT4
 set     FTFA_FSEC_MEEN_1            BIT5

 set     FTFA_FSEC_KEYEN             (BIT6|BIT7)
;;   Backdoor Key Security Enable
;;     0b00 ==> Backdoor key access disabled
;;     0b01 ==> Backdoor key access disabled (preferred KEYEN state to disable backdoor key access)
;;     0b10 ==> Backdoor key access enabled
;;     0b11 ==> Backdoor key access disabled
 set     FTFA_FSEC_KEYEN_0           BIT6
 set     FTFA_FSEC_KEYEN_1           BIT7

 set     FTFA_FOPT_OPT               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Nonvolatile Option
 set     FTFA_FOPT_OPT_0             BIT0
 set     FTFA_FOPT_OPT_1             BIT1
 set     FTFA_FOPT_OPT_2             BIT2
 set     FTFA_FOPT_OPT_3             BIT3
 set     FTFA_FOPT_OPT_4             BIT4
 set     FTFA_FOPT_OPT_5             BIT5
 set     FTFA_FOPT_OPT_6             BIT6
 set     FTFA_FOPT_OPT_7             BIT7

 set     FTFA_FCCOB3_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB3_CCOBn_0         BIT0
 set     FTFA_FCCOB3_CCOBn_1         BIT1
 set     FTFA_FCCOB3_CCOBn_2         BIT2
 set     FTFA_FCCOB3_CCOBn_3         BIT3
 set     FTFA_FCCOB3_CCOBn_4         BIT4
 set     FTFA_FCCOB3_CCOBn_5         BIT5
 set     FTFA_FCCOB3_CCOBn_6         BIT6
 set     FTFA_FCCOB3_CCOBn_7         BIT7

 set     FTFA_FCCOB2_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB2_CCOBn_0         BIT0
 set     FTFA_FCCOB2_CCOBn_1         BIT1
 set     FTFA_FCCOB2_CCOBn_2         BIT2
 set     FTFA_FCCOB2_CCOBn_3         BIT3
 set     FTFA_FCCOB2_CCOBn_4         BIT4
 set     FTFA_FCCOB2_CCOBn_5         BIT5
 set     FTFA_FCCOB2_CCOBn_6         BIT6
 set     FTFA_FCCOB2_CCOBn_7         BIT7

 set     FTFA_FCCOB1_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB1_CCOBn_0         BIT0
 set     FTFA_FCCOB1_CCOBn_1         BIT1
 set     FTFA_FCCOB1_CCOBn_2         BIT2
 set     FTFA_FCCOB1_CCOBn_3         BIT3
 set     FTFA_FCCOB1_CCOBn_4         BIT4
 set     FTFA_FCCOB1_CCOBn_5         BIT5
 set     FTFA_FCCOB1_CCOBn_6         BIT6
 set     FTFA_FCCOB1_CCOBn_7         BIT7

 set     FTFA_FCCOB0_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB0_CCOBn_0         BIT0
 set     FTFA_FCCOB0_CCOBn_1         BIT1
 set     FTFA_FCCOB0_CCOBn_2         BIT2
 set     FTFA_FCCOB0_CCOBn_3         BIT3
 set     FTFA_FCCOB0_CCOBn_4         BIT4
 set     FTFA_FCCOB0_CCOBn_5         BIT5
 set     FTFA_FCCOB0_CCOBn_6         BIT6
 set     FTFA_FCCOB0_CCOBn_7         BIT7

 set     FTFA_FCCOB7_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB7_CCOBn_0         BIT0
 set     FTFA_FCCOB7_CCOBn_1         BIT1
 set     FTFA_FCCOB7_CCOBn_2         BIT2
 set     FTFA_FCCOB7_CCOBn_3         BIT3
 set     FTFA_FCCOB7_CCOBn_4         BIT4
 set     FTFA_FCCOB7_CCOBn_5         BIT5
 set     FTFA_FCCOB7_CCOBn_6         BIT6
 set     FTFA_FCCOB7_CCOBn_7         BIT7

 set     FTFA_FCCOB6_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB6_CCOBn_0         BIT0
 set     FTFA_FCCOB6_CCOBn_1         BIT1
 set     FTFA_FCCOB6_CCOBn_2         BIT2
 set     FTFA_FCCOB6_CCOBn_3         BIT3
 set     FTFA_FCCOB6_CCOBn_4         BIT4
 set     FTFA_FCCOB6_CCOBn_5         BIT5
 set     FTFA_FCCOB6_CCOBn_6         BIT6
 set     FTFA_FCCOB6_CCOBn_7         BIT7

 set     FTFA_FCCOB5_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB5_CCOBn_0         BIT0
 set     FTFA_FCCOB5_CCOBn_1         BIT1
 set     FTFA_FCCOB5_CCOBn_2         BIT2
 set     FTFA_FCCOB5_CCOBn_3         BIT3
 set     FTFA_FCCOB5_CCOBn_4         BIT4
 set     FTFA_FCCOB5_CCOBn_5         BIT5
 set     FTFA_FCCOB5_CCOBn_6         BIT6
 set     FTFA_FCCOB5_CCOBn_7         BIT7

 set     FTFA_FCCOB4_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB4_CCOBn_0         BIT0
 set     FTFA_FCCOB4_CCOBn_1         BIT1
 set     FTFA_FCCOB4_CCOBn_2         BIT2
 set     FTFA_FCCOB4_CCOBn_3         BIT3
 set     FTFA_FCCOB4_CCOBn_4         BIT4
 set     FTFA_FCCOB4_CCOBn_5         BIT5
 set     FTFA_FCCOB4_CCOBn_6         BIT6
 set     FTFA_FCCOB4_CCOBn_7         BIT7

 set     FTFA_FCCOBB_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOBB_CCOBn_0         BIT0
 set     FTFA_FCCOBB_CCOBn_1         BIT1
 set     FTFA_FCCOBB_CCOBn_2         BIT2
 set     FTFA_FCCOBB_CCOBn_3         BIT3
 set     FTFA_FCCOBB_CCOBn_4         BIT4
 set     FTFA_FCCOBB_CCOBn_5         BIT5
 set     FTFA_FCCOBB_CCOBn_6         BIT6
 set     FTFA_FCCOBB_CCOBn_7         BIT7

 set     FTFA_FCCOBA_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOBA_CCOBn_0         BIT0
 set     FTFA_FCCOBA_CCOBn_1         BIT1
 set     FTFA_FCCOBA_CCOBn_2         BIT2
 set     FTFA_FCCOBA_CCOBn_3         BIT3
 set     FTFA_FCCOBA_CCOBn_4         BIT4
 set     FTFA_FCCOBA_CCOBn_5         BIT5
 set     FTFA_FCCOBA_CCOBn_6         BIT6
 set     FTFA_FCCOBA_CCOBn_7         BIT7

 set     FTFA_FCCOB9_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB9_CCOBn_0         BIT0
 set     FTFA_FCCOB9_CCOBn_1         BIT1
 set     FTFA_FCCOB9_CCOBn_2         BIT2
 set     FTFA_FCCOB9_CCOBn_3         BIT3
 set     FTFA_FCCOB9_CCOBn_4         BIT4
 set     FTFA_FCCOB9_CCOBn_5         BIT5
 set     FTFA_FCCOB9_CCOBn_6         BIT6
 set     FTFA_FCCOB9_CCOBn_7         BIT7

 set     FTFA_FCCOB8_CCOBn           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     FTFA_FCCOB8_CCOBn_0         BIT0
 set     FTFA_FCCOB8_CCOBn_1         BIT1
 set     FTFA_FCCOB8_CCOBn_2         BIT2
 set     FTFA_FCCOB8_CCOBn_3         BIT3
 set     FTFA_FCCOB8_CCOBn_4         BIT4
 set     FTFA_FCCOB8_CCOBn_5         BIT5
 set     FTFA_FCCOB8_CCOBn_6         BIT6
 set     FTFA_FCCOB8_CCOBn_7         BIT7

 set     FTFA_FPROT3_PROT            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Program Flash Region Protect
;;     0b0 ==> Program flash region is protected.
;;     0b1 ==> Program flash region is not protected
 set     FTFA_FPROT3_PROT_0          BIT0
 set     FTFA_FPROT3_PROT_1          BIT1
 set     FTFA_FPROT3_PROT_2          BIT2
 set     FTFA_FPROT3_PROT_3          BIT3
 set     FTFA_FPROT3_PROT_4          BIT4
 set     FTFA_FPROT3_PROT_5          BIT5
 set     FTFA_FPROT3_PROT_6          BIT6
 set     FTFA_FPROT3_PROT_7          BIT7

 set     FTFA_FPROT2_PROT            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Program Flash Region Protect
;;     0b0 ==> Program flash region is protected.
;;     0b1 ==> Program flash region is not protected
 set     FTFA_FPROT2_PROT_0          BIT0
 set     FTFA_FPROT2_PROT_1          BIT1
 set     FTFA_FPROT2_PROT_2          BIT2
 set     FTFA_FPROT2_PROT_3          BIT3
 set     FTFA_FPROT2_PROT_4          BIT4
 set     FTFA_FPROT2_PROT_5          BIT5
 set     FTFA_FPROT2_PROT_6          BIT6
 set     FTFA_FPROT2_PROT_7          BIT7

 set     FTFA_FPROT1_PROT            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Program Flash Region Protect
;;     0b0 ==> Program flash region is protected.
;;     0b1 ==> Program flash region is not protected
 set     FTFA_FPROT1_PROT_0          BIT0
 set     FTFA_FPROT1_PROT_1          BIT1
 set     FTFA_FPROT1_PROT_2          BIT2
 set     FTFA_FPROT1_PROT_3          BIT3
 set     FTFA_FPROT1_PROT_4          BIT4
 set     FTFA_FPROT1_PROT_5          BIT5
 set     FTFA_FPROT1_PROT_6          BIT6
 set     FTFA_FPROT1_PROT_7          BIT7

 set     FTFA_FPROT0_PROT            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Program Flash Region Protect
;;     0b0 ==> Program flash region is protected.
;;     0b1 ==> Program flash region is not protected
 set     FTFA_FPROT0_PROT_0          BIT0
 set     FTFA_FPROT0_PROT_1          BIT1
 set     FTFA_FPROT0_PROT_2          BIT2
 set     FTFA_FPROT0_PROT_3          BIT3
 set     FTFA_FPROT0_PROT_4          BIT4
 set     FTFA_FPROT0_PROT_5          BIT5
 set     FTFA_FPROT0_PROT_6          BIT6
 set     FTFA_FPROT0_PROT_7          BIT7

 set     GPIOA_PUR_PU                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Enable Bits
;;     0b0 ==> Pull resistor is disabled
;;     0b1 ==> Pull resistor is enabled
 set     GPIOA_PUR_PU_0              BIT0
 set     GPIOA_PUR_PU_1              BIT1
 set     GPIOA_PUR_PU_2              BIT2
 set     GPIOA_PUR_PU_3              BIT3
 set     GPIOA_PUR_PU_4              BIT4
 set     GPIOA_PUR_PU_5              BIT5
 set     GPIOA_PUR_PU_6              BIT6
 set     GPIOA_PUR_PU_7              BIT7
 set     GPIOA_PUR_PU_8              BIT8
 set     GPIOA_PUR_PU_9              BIT9
 set     GPIOA_PUR_PU_10             BIT10
 set     GPIOA_PUR_PU_11             BIT11
 set     GPIOA_PUR_PU_12             BIT12
 set     GPIOA_PUR_PU_13             BIT13
 set     GPIOA_PUR_PU_14             BIT14
 set     GPIOA_PUR_PU_15             BIT15

 set     GPIOA_DR_D                  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Bits
 set     GPIOA_DR_D_0                BIT0
 set     GPIOA_DR_D_1                BIT1
 set     GPIOA_DR_D_2                BIT2
 set     GPIOA_DR_D_3                BIT3
 set     GPIOA_DR_D_4                BIT4
 set     GPIOA_DR_D_5                BIT5
 set     GPIOA_DR_D_6                BIT6
 set     GPIOA_DR_D_7                BIT7
 set     GPIOA_DR_D_8                BIT8
 set     GPIOA_DR_D_9                BIT9
 set     GPIOA_DR_D_10               BIT10
 set     GPIOA_DR_D_11               BIT11
 set     GPIOA_DR_D_12               BIT12
 set     GPIOA_DR_D_13               BIT13
 set     GPIOA_DR_D_14               BIT14
 set     GPIOA_DR_D_15               BIT15

 set     GPIOA_DDR_DD                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Direction Bits
;;     0b0 ==> Pin is an input
;;     0b1 ==> Pin is an output
 set     GPIOA_DDR_DD_0              BIT0
 set     GPIOA_DDR_DD_1              BIT1
 set     GPIOA_DDR_DD_2              BIT2
 set     GPIOA_DDR_DD_3              BIT3
 set     GPIOA_DDR_DD_4              BIT4
 set     GPIOA_DDR_DD_5              BIT5
 set     GPIOA_DDR_DD_6              BIT6
 set     GPIOA_DDR_DD_7              BIT7
 set     GPIOA_DDR_DD_8              BIT8
 set     GPIOA_DDR_DD_9              BIT9
 set     GPIOA_DDR_DD_10             BIT10
 set     GPIOA_DDR_DD_11             BIT11
 set     GPIOA_DDR_DD_12             BIT12
 set     GPIOA_DDR_DD_13             BIT13
 set     GPIOA_DDR_DD_14             BIT14
 set     GPIOA_DDR_DD_15             BIT15

 set     GPIOA_PER_PE                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Peripheral Enable Bits
;;     0b0 ==> Pin is for GPIO (GPIO mode)
;;     0b1 ==> Pin is for peripheral (peripheral mode)
 set     GPIOA_PER_PE_0              BIT0
 set     GPIOA_PER_PE_1              BIT1
 set     GPIOA_PER_PE_2              BIT2
 set     GPIOA_PER_PE_3              BIT3
 set     GPIOA_PER_PE_4              BIT4
 set     GPIOA_PER_PE_5              BIT5
 set     GPIOA_PER_PE_6              BIT6
 set     GPIOA_PER_PE_7              BIT7
 set     GPIOA_PER_PE_8              BIT8
 set     GPIOA_PER_PE_9              BIT9
 set     GPIOA_PER_PE_10             BIT10
 set     GPIOA_PER_PE_11             BIT11
 set     GPIOA_PER_PE_12             BIT12
 set     GPIOA_PER_PE_13             BIT13
 set     GPIOA_PER_PE_14             BIT14
 set     GPIOA_PER_PE_15             BIT15

 set     GPIOA_IAR_IA                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Assert Bits
;;     0b0 ==> Deassert software interrupt
;;     0b1 ==> Assert software interrupt
 set     GPIOA_IAR_IA_0              BIT0
 set     GPIOA_IAR_IA_1              BIT1
 set     GPIOA_IAR_IA_2              BIT2
 set     GPIOA_IAR_IA_3              BIT3
 set     GPIOA_IAR_IA_4              BIT4
 set     GPIOA_IAR_IA_5              BIT5
 set     GPIOA_IAR_IA_6              BIT6
 set     GPIOA_IAR_IA_7              BIT7
 set     GPIOA_IAR_IA_8              BIT8
 set     GPIOA_IAR_IA_9              BIT9
 set     GPIOA_IAR_IA_10             BIT10
 set     GPIOA_IAR_IA_11             BIT11
 set     GPIOA_IAR_IA_12             BIT12
 set     GPIOA_IAR_IA_13             BIT13
 set     GPIOA_IAR_IA_14             BIT14
 set     GPIOA_IAR_IA_15             BIT15

 set     GPIOA_IENR_IEN              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Enable Bits
;;     0b0 ==> External Interrupt is disabled
;;     0b1 ==> External Interrupt is enabled
 set     GPIOA_IENR_IEN_0            BIT0
 set     GPIOA_IENR_IEN_1            BIT1
 set     GPIOA_IENR_IEN_2            BIT2
 set     GPIOA_IENR_IEN_3            BIT3
 set     GPIOA_IENR_IEN_4            BIT4
 set     GPIOA_IENR_IEN_5            BIT5
 set     GPIOA_IENR_IEN_6            BIT6
 set     GPIOA_IENR_IEN_7            BIT7
 set     GPIOA_IENR_IEN_8            BIT8
 set     GPIOA_IENR_IEN_9            BIT9
 set     GPIOA_IENR_IEN_10           BIT10
 set     GPIOA_IENR_IEN_11           BIT11
 set     GPIOA_IENR_IEN_12           BIT12
 set     GPIOA_IENR_IEN_13           BIT13
 set     GPIOA_IENR_IEN_14           BIT14
 set     GPIOA_IENR_IEN_15           BIT15

 set     GPIOA_IPOLR_IPOL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Polarity Bits
;;     0b0 ==> Interrupt occurred on rising edge
;;     0b1 ==> Interrupt occurred on falling edge
 set     GPIOA_IPOLR_IPOL_0          BIT0
 set     GPIOA_IPOLR_IPOL_1          BIT1
 set     GPIOA_IPOLR_IPOL_2          BIT2
 set     GPIOA_IPOLR_IPOL_3          BIT3
 set     GPIOA_IPOLR_IPOL_4          BIT4
 set     GPIOA_IPOLR_IPOL_5          BIT5
 set     GPIOA_IPOLR_IPOL_6          BIT6
 set     GPIOA_IPOLR_IPOL_7          BIT7
 set     GPIOA_IPOLR_IPOL_8          BIT8
 set     GPIOA_IPOLR_IPOL_9          BIT9
 set     GPIOA_IPOLR_IPOL_10         BIT10
 set     GPIOA_IPOLR_IPOL_11         BIT11
 set     GPIOA_IPOLR_IPOL_12         BIT12
 set     GPIOA_IPOLR_IPOL_13         BIT13
 set     GPIOA_IPOLR_IPOL_14         BIT14
 set     GPIOA_IPOLR_IPOL_15         BIT15

 set     GPIOA_IPR_IP                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Pending Bits
;;     0b0 ==> No Interrupt
;;     0b1 ==> Interrupt occurred
 set     GPIOA_IPR_IP_0              BIT0
 set     GPIOA_IPR_IP_1              BIT1
 set     GPIOA_IPR_IP_2              BIT2
 set     GPIOA_IPR_IP_3              BIT3
 set     GPIOA_IPR_IP_4              BIT4
 set     GPIOA_IPR_IP_5              BIT5
 set     GPIOA_IPR_IP_6              BIT6
 set     GPIOA_IPR_IP_7              BIT7
 set     GPIOA_IPR_IP_8              BIT8
 set     GPIOA_IPR_IP_9              BIT9
 set     GPIOA_IPR_IP_10             BIT10
 set     GPIOA_IPR_IP_11             BIT11
 set     GPIOA_IPR_IP_12             BIT12
 set     GPIOA_IPR_IP_13             BIT13
 set     GPIOA_IPR_IP_14             BIT14
 set     GPIOA_IPR_IP_15             BIT15

 set     GPIOA_IESR_IES              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Edge-Sensitive Bits
;;     0b0 ==> No edge detected if read; no effect if writing
;;     0b1 ==> An edge detected if read; clear corresponding Interrupt Pending bit if writing
 set     GPIOA_IESR_IES_0            BIT0
 set     GPIOA_IESR_IES_1            BIT1
 set     GPIOA_IESR_IES_2            BIT2
 set     GPIOA_IESR_IES_3            BIT3
 set     GPIOA_IESR_IES_4            BIT4
 set     GPIOA_IESR_IES_5            BIT5
 set     GPIOA_IESR_IES_6            BIT6
 set     GPIOA_IESR_IES_7            BIT7
 set     GPIOA_IESR_IES_8            BIT8
 set     GPIOA_IESR_IES_9            BIT9
 set     GPIOA_IESR_IES_10           BIT10
 set     GPIOA_IESR_IES_11           BIT11
 set     GPIOA_IESR_IES_12           BIT12
 set     GPIOA_IESR_IES_13           BIT13
 set     GPIOA_IESR_IES_14           BIT14
 set     GPIOA_IESR_IES_15           BIT15

 set     GPIOA_PPMODE_PPMODE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Push-Pull Mode Bits
;;     0b0 ==> Open Drain Mode
;;     0b1 ==> Push-Pull Mode
 set     GPIOA_PPMODE_PPMODE_0       BIT0
 set     GPIOA_PPMODE_PPMODE_1       BIT1
 set     GPIOA_PPMODE_PPMODE_2       BIT2
 set     GPIOA_PPMODE_PPMODE_3       BIT3
 set     GPIOA_PPMODE_PPMODE_4       BIT4
 set     GPIOA_PPMODE_PPMODE_5       BIT5
 set     GPIOA_PPMODE_PPMODE_6       BIT6
 set     GPIOA_PPMODE_PPMODE_7       BIT7
 set     GPIOA_PPMODE_PPMODE_8       BIT8
 set     GPIOA_PPMODE_PPMODE_9       BIT9
 set     GPIOA_PPMODE_PPMODE_10      BIT10
 set     GPIOA_PPMODE_PPMODE_11      BIT11
 set     GPIOA_PPMODE_PPMODE_12      BIT12
 set     GPIOA_PPMODE_PPMODE_13      BIT13
 set     GPIOA_PPMODE_PPMODE_14      BIT14
 set     GPIOA_PPMODE_PPMODE_15      BIT15

 set     GPIOA_RAWDATA_RAW_DATA      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Raw Data Bits
 set     GPIOA_RAWDATA_RAW_DATA_0    BIT0
 set     GPIOA_RAWDATA_RAW_DATA_1    BIT1
 set     GPIOA_RAWDATA_RAW_DATA_2    BIT2
 set     GPIOA_RAWDATA_RAW_DATA_3    BIT3
 set     GPIOA_RAWDATA_RAW_DATA_4    BIT4
 set     GPIOA_RAWDATA_RAW_DATA_5    BIT5
 set     GPIOA_RAWDATA_RAW_DATA_6    BIT6
 set     GPIOA_RAWDATA_RAW_DATA_7    BIT7
 set     GPIOA_RAWDATA_RAW_DATA_8    BIT8
 set     GPIOA_RAWDATA_RAW_DATA_9    BIT9
 set     GPIOA_RAWDATA_RAW_DATA_10   BIT10
 set     GPIOA_RAWDATA_RAW_DATA_11   BIT11
 set     GPIOA_RAWDATA_RAW_DATA_12   BIT12
 set     GPIOA_RAWDATA_RAW_DATA_13   BIT13
 set     GPIOA_RAWDATA_RAW_DATA_14   BIT14
 set     GPIOA_RAWDATA_RAW_DATA_15   BIT15

 set     GPIOA_DRIVE_DRIVE           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Drive Strength Selector Bits
;;     0b0 ==> Low drive strength
;;     0b1 ==> High drive strength
 set     GPIOA_DRIVE_DRIVE_0         BIT0
 set     GPIOA_DRIVE_DRIVE_1         BIT1
 set     GPIOA_DRIVE_DRIVE_2         BIT2
 set     GPIOA_DRIVE_DRIVE_3         BIT3
 set     GPIOA_DRIVE_DRIVE_4         BIT4
 set     GPIOA_DRIVE_DRIVE_5         BIT5
 set     GPIOA_DRIVE_DRIVE_6         BIT6
 set     GPIOA_DRIVE_DRIVE_7         BIT7
 set     GPIOA_DRIVE_DRIVE_8         BIT8
 set     GPIOA_DRIVE_DRIVE_9         BIT9
 set     GPIOA_DRIVE_DRIVE_10        BIT10
 set     GPIOA_DRIVE_DRIVE_11        BIT11
 set     GPIOA_DRIVE_DRIVE_12        BIT12
 set     GPIOA_DRIVE_DRIVE_13        BIT13
 set     GPIOA_DRIVE_DRIVE_14        BIT14
 set     GPIOA_DRIVE_DRIVE_15        BIT15

 set     GPIOA_PUS_PUS               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Type Select Bits
;;     0b0 ==> Pulldown resistor
;;     0b1 ==> Pullup resistor
 set     GPIOA_PUS_PUS_0             BIT0
 set     GPIOA_PUS_PUS_1             BIT1
 set     GPIOA_PUS_PUS_2             BIT2
 set     GPIOA_PUS_PUS_3             BIT3
 set     GPIOA_PUS_PUS_4             BIT4
 set     GPIOA_PUS_PUS_5             BIT5
 set     GPIOA_PUS_PUS_6             BIT6
 set     GPIOA_PUS_PUS_7             BIT7
 set     GPIOA_PUS_PUS_8             BIT8
 set     GPIOA_PUS_PUS_9             BIT9
 set     GPIOA_PUS_PUS_10            BIT10
 set     GPIOA_PUS_PUS_11            BIT11
 set     GPIOA_PUS_PUS_12            BIT12
 set     GPIOA_PUS_PUS_13            BIT13
 set     GPIOA_PUS_PUS_14            BIT14
 set     GPIOA_PUS_PUS_15            BIT15

 set     GPIOA_SRE_SRE               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Slew Rate Enable
;;     0b0 ==> Slew rate is enabled (the turn-on time of the output transistor is faster)
;;     0b1 ==> Slew rate is disabled (the turn-on time of the output transistor is slower)
 set     GPIOA_SRE_SRE_0             BIT0
 set     GPIOA_SRE_SRE_1             BIT1
 set     GPIOA_SRE_SRE_2             BIT2
 set     GPIOA_SRE_SRE_3             BIT3
 set     GPIOA_SRE_SRE_4             BIT4
 set     GPIOA_SRE_SRE_5             BIT5
 set     GPIOA_SRE_SRE_6             BIT6
 set     GPIOA_SRE_SRE_7             BIT7
 set     GPIOA_SRE_SRE_8             BIT8
 set     GPIOA_SRE_SRE_9             BIT9
 set     GPIOA_SRE_SRE_10            BIT10
 set     GPIOA_SRE_SRE_11            BIT11
 set     GPIOA_SRE_SRE_12            BIT12
 set     GPIOA_SRE_SRE_13            BIT13
 set     GPIOA_SRE_SRE_14            BIT14
 set     GPIOA_SRE_SRE_15            BIT15

 set     GPIOB_PUR_PU                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Enable Bits
;;     0b0 ==> Pull resistor is disabled
;;     0b1 ==> Pull resistor is enabled
 set     GPIOB_PUR_PU_0              BIT0
 set     GPIOB_PUR_PU_1              BIT1
 set     GPIOB_PUR_PU_2              BIT2
 set     GPIOB_PUR_PU_3              BIT3
 set     GPIOB_PUR_PU_4              BIT4
 set     GPIOB_PUR_PU_5              BIT5
 set     GPIOB_PUR_PU_6              BIT6
 set     GPIOB_PUR_PU_7              BIT7
 set     GPIOB_PUR_PU_8              BIT8
 set     GPIOB_PUR_PU_9              BIT9
 set     GPIOB_PUR_PU_10             BIT10
 set     GPIOB_PUR_PU_11             BIT11
 set     GPIOB_PUR_PU_12             BIT12
 set     GPIOB_PUR_PU_13             BIT13
 set     GPIOB_PUR_PU_14             BIT14
 set     GPIOB_PUR_PU_15             BIT15

 set     GPIOB_DR_D                  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Bits
 set     GPIOB_DR_D_0                BIT0
 set     GPIOB_DR_D_1                BIT1
 set     GPIOB_DR_D_2                BIT2
 set     GPIOB_DR_D_3                BIT3
 set     GPIOB_DR_D_4                BIT4
 set     GPIOB_DR_D_5                BIT5
 set     GPIOB_DR_D_6                BIT6
 set     GPIOB_DR_D_7                BIT7
 set     GPIOB_DR_D_8                BIT8
 set     GPIOB_DR_D_9                BIT9
 set     GPIOB_DR_D_10               BIT10
 set     GPIOB_DR_D_11               BIT11
 set     GPIOB_DR_D_12               BIT12
 set     GPIOB_DR_D_13               BIT13
 set     GPIOB_DR_D_14               BIT14
 set     GPIOB_DR_D_15               BIT15

 set     GPIOB_DDR_DD                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Direction Bits
;;     0b0 ==> Pin is an input
;;     0b1 ==> Pin is an output
 set     GPIOB_DDR_DD_0              BIT0
 set     GPIOB_DDR_DD_1              BIT1
 set     GPIOB_DDR_DD_2              BIT2
 set     GPIOB_DDR_DD_3              BIT3
 set     GPIOB_DDR_DD_4              BIT4
 set     GPIOB_DDR_DD_5              BIT5
 set     GPIOB_DDR_DD_6              BIT6
 set     GPIOB_DDR_DD_7              BIT7
 set     GPIOB_DDR_DD_8              BIT8
 set     GPIOB_DDR_DD_9              BIT9
 set     GPIOB_DDR_DD_10             BIT10
 set     GPIOB_DDR_DD_11             BIT11
 set     GPIOB_DDR_DD_12             BIT12
 set     GPIOB_DDR_DD_13             BIT13
 set     GPIOB_DDR_DD_14             BIT14
 set     GPIOB_DDR_DD_15             BIT15

 set     GPIOB_PER_PE                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Peripheral Enable Bits
;;     0b0 ==> Pin is for GPIO (GPIO mode)
;;     0b1 ==> Pin is for peripheral (peripheral mode)
 set     GPIOB_PER_PE_0              BIT0
 set     GPIOB_PER_PE_1              BIT1
 set     GPIOB_PER_PE_2              BIT2
 set     GPIOB_PER_PE_3              BIT3
 set     GPIOB_PER_PE_4              BIT4
 set     GPIOB_PER_PE_5              BIT5
 set     GPIOB_PER_PE_6              BIT6
 set     GPIOB_PER_PE_7              BIT7
 set     GPIOB_PER_PE_8              BIT8
 set     GPIOB_PER_PE_9              BIT9
 set     GPIOB_PER_PE_10             BIT10
 set     GPIOB_PER_PE_11             BIT11
 set     GPIOB_PER_PE_12             BIT12
 set     GPIOB_PER_PE_13             BIT13
 set     GPIOB_PER_PE_14             BIT14
 set     GPIOB_PER_PE_15             BIT15

 set     GPIOB_IAR_IA                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Assert Bits
;;     0b0 ==> Deassert software interrupt
;;     0b1 ==> Assert software interrupt
 set     GPIOB_IAR_IA_0              BIT0
 set     GPIOB_IAR_IA_1              BIT1
 set     GPIOB_IAR_IA_2              BIT2
 set     GPIOB_IAR_IA_3              BIT3
 set     GPIOB_IAR_IA_4              BIT4
 set     GPIOB_IAR_IA_5              BIT5
 set     GPIOB_IAR_IA_6              BIT6
 set     GPIOB_IAR_IA_7              BIT7
 set     GPIOB_IAR_IA_8              BIT8
 set     GPIOB_IAR_IA_9              BIT9
 set     GPIOB_IAR_IA_10             BIT10
 set     GPIOB_IAR_IA_11             BIT11
 set     GPIOB_IAR_IA_12             BIT12
 set     GPIOB_IAR_IA_13             BIT13
 set     GPIOB_IAR_IA_14             BIT14
 set     GPIOB_IAR_IA_15             BIT15

 set     GPIOB_IENR_IEN              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Enable Bits
;;     0b0 ==> External Interrupt is disabled
;;     0b1 ==> External Interrupt is enabled
 set     GPIOB_IENR_IEN_0            BIT0
 set     GPIOB_IENR_IEN_1            BIT1
 set     GPIOB_IENR_IEN_2            BIT2
 set     GPIOB_IENR_IEN_3            BIT3
 set     GPIOB_IENR_IEN_4            BIT4
 set     GPIOB_IENR_IEN_5            BIT5
 set     GPIOB_IENR_IEN_6            BIT6
 set     GPIOB_IENR_IEN_7            BIT7
 set     GPIOB_IENR_IEN_8            BIT8
 set     GPIOB_IENR_IEN_9            BIT9
 set     GPIOB_IENR_IEN_10           BIT10
 set     GPIOB_IENR_IEN_11           BIT11
 set     GPIOB_IENR_IEN_12           BIT12
 set     GPIOB_IENR_IEN_13           BIT13
 set     GPIOB_IENR_IEN_14           BIT14
 set     GPIOB_IENR_IEN_15           BIT15

 set     GPIOB_IPOLR_IPOL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Polarity Bits
;;     0b0 ==> Interrupt occurred on rising edge
;;     0b1 ==> Interrupt occurred on falling edge
 set     GPIOB_IPOLR_IPOL_0          BIT0
 set     GPIOB_IPOLR_IPOL_1          BIT1
 set     GPIOB_IPOLR_IPOL_2          BIT2
 set     GPIOB_IPOLR_IPOL_3          BIT3
 set     GPIOB_IPOLR_IPOL_4          BIT4
 set     GPIOB_IPOLR_IPOL_5          BIT5
 set     GPIOB_IPOLR_IPOL_6          BIT6
 set     GPIOB_IPOLR_IPOL_7          BIT7
 set     GPIOB_IPOLR_IPOL_8          BIT8
 set     GPIOB_IPOLR_IPOL_9          BIT9
 set     GPIOB_IPOLR_IPOL_10         BIT10
 set     GPIOB_IPOLR_IPOL_11         BIT11
 set     GPIOB_IPOLR_IPOL_12         BIT12
 set     GPIOB_IPOLR_IPOL_13         BIT13
 set     GPIOB_IPOLR_IPOL_14         BIT14
 set     GPIOB_IPOLR_IPOL_15         BIT15

 set     GPIOB_IPR_IP                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Pending Bits
;;     0b0 ==> No Interrupt
;;     0b1 ==> Interrupt occurred
 set     GPIOB_IPR_IP_0              BIT0
 set     GPIOB_IPR_IP_1              BIT1
 set     GPIOB_IPR_IP_2              BIT2
 set     GPIOB_IPR_IP_3              BIT3
 set     GPIOB_IPR_IP_4              BIT4
 set     GPIOB_IPR_IP_5              BIT5
 set     GPIOB_IPR_IP_6              BIT6
 set     GPIOB_IPR_IP_7              BIT7
 set     GPIOB_IPR_IP_8              BIT8
 set     GPIOB_IPR_IP_9              BIT9
 set     GPIOB_IPR_IP_10             BIT10
 set     GPIOB_IPR_IP_11             BIT11
 set     GPIOB_IPR_IP_12             BIT12
 set     GPIOB_IPR_IP_13             BIT13
 set     GPIOB_IPR_IP_14             BIT14
 set     GPIOB_IPR_IP_15             BIT15

 set     GPIOB_IESR_IES              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Edge-Sensitive Bits
;;     0b0 ==> No edge detected if read; no effect if writing
;;     0b1 ==> An edge detected if read; clear corresponding Interrupt Pending bit if writing
 set     GPIOB_IESR_IES_0            BIT0
 set     GPIOB_IESR_IES_1            BIT1
 set     GPIOB_IESR_IES_2            BIT2
 set     GPIOB_IESR_IES_3            BIT3
 set     GPIOB_IESR_IES_4            BIT4
 set     GPIOB_IESR_IES_5            BIT5
 set     GPIOB_IESR_IES_6            BIT6
 set     GPIOB_IESR_IES_7            BIT7
 set     GPIOB_IESR_IES_8            BIT8
 set     GPIOB_IESR_IES_9            BIT9
 set     GPIOB_IESR_IES_10           BIT10
 set     GPIOB_IESR_IES_11           BIT11
 set     GPIOB_IESR_IES_12           BIT12
 set     GPIOB_IESR_IES_13           BIT13
 set     GPIOB_IESR_IES_14           BIT14
 set     GPIOB_IESR_IES_15           BIT15

 set     GPIOB_PPMODE_PPMODE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Push-Pull Mode Bits
;;     0b0 ==> Open Drain Mode
;;     0b1 ==> Push-Pull Mode
 set     GPIOB_PPMODE_PPMODE_0       BIT0
 set     GPIOB_PPMODE_PPMODE_1       BIT1
 set     GPIOB_PPMODE_PPMODE_2       BIT2
 set     GPIOB_PPMODE_PPMODE_3       BIT3
 set     GPIOB_PPMODE_PPMODE_4       BIT4
 set     GPIOB_PPMODE_PPMODE_5       BIT5
 set     GPIOB_PPMODE_PPMODE_6       BIT6
 set     GPIOB_PPMODE_PPMODE_7       BIT7
 set     GPIOB_PPMODE_PPMODE_8       BIT8
 set     GPIOB_PPMODE_PPMODE_9       BIT9
 set     GPIOB_PPMODE_PPMODE_10      BIT10
 set     GPIOB_PPMODE_PPMODE_11      BIT11
 set     GPIOB_PPMODE_PPMODE_12      BIT12
 set     GPIOB_PPMODE_PPMODE_13      BIT13
 set     GPIOB_PPMODE_PPMODE_14      BIT14
 set     GPIOB_PPMODE_PPMODE_15      BIT15

 set     GPIOB_RAWDATA_RAW_DATA      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Raw Data Bits
 set     GPIOB_RAWDATA_RAW_DATA_0    BIT0
 set     GPIOB_RAWDATA_RAW_DATA_1    BIT1
 set     GPIOB_RAWDATA_RAW_DATA_2    BIT2
 set     GPIOB_RAWDATA_RAW_DATA_3    BIT3
 set     GPIOB_RAWDATA_RAW_DATA_4    BIT4
 set     GPIOB_RAWDATA_RAW_DATA_5    BIT5
 set     GPIOB_RAWDATA_RAW_DATA_6    BIT6
 set     GPIOB_RAWDATA_RAW_DATA_7    BIT7
 set     GPIOB_RAWDATA_RAW_DATA_8    BIT8
 set     GPIOB_RAWDATA_RAW_DATA_9    BIT9
 set     GPIOB_RAWDATA_RAW_DATA_10   BIT10
 set     GPIOB_RAWDATA_RAW_DATA_11   BIT11
 set     GPIOB_RAWDATA_RAW_DATA_12   BIT12
 set     GPIOB_RAWDATA_RAW_DATA_13   BIT13
 set     GPIOB_RAWDATA_RAW_DATA_14   BIT14
 set     GPIOB_RAWDATA_RAW_DATA_15   BIT15

 set     GPIOB_DRIVE_DRIVE           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Drive Strength Selector Bits
;;     0b0 ==> Low drive strength
;;     0b1 ==> High drive strength
 set     GPIOB_DRIVE_DRIVE_0         BIT0
 set     GPIOB_DRIVE_DRIVE_1         BIT1
 set     GPIOB_DRIVE_DRIVE_2         BIT2
 set     GPIOB_DRIVE_DRIVE_3         BIT3
 set     GPIOB_DRIVE_DRIVE_4         BIT4
 set     GPIOB_DRIVE_DRIVE_5         BIT5
 set     GPIOB_DRIVE_DRIVE_6         BIT6
 set     GPIOB_DRIVE_DRIVE_7         BIT7
 set     GPIOB_DRIVE_DRIVE_8         BIT8
 set     GPIOB_DRIVE_DRIVE_9         BIT9
 set     GPIOB_DRIVE_DRIVE_10        BIT10
 set     GPIOB_DRIVE_DRIVE_11        BIT11
 set     GPIOB_DRIVE_DRIVE_12        BIT12
 set     GPIOB_DRIVE_DRIVE_13        BIT13
 set     GPIOB_DRIVE_DRIVE_14        BIT14
 set     GPIOB_DRIVE_DRIVE_15        BIT15

 set     GPIOB_PUS_PUS               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Type Select Bits
;;     0b0 ==> Pulldown resistor
;;     0b1 ==> Pullup resistor
 set     GPIOB_PUS_PUS_0             BIT0
 set     GPIOB_PUS_PUS_1             BIT1
 set     GPIOB_PUS_PUS_2             BIT2
 set     GPIOB_PUS_PUS_3             BIT3
 set     GPIOB_PUS_PUS_4             BIT4
 set     GPIOB_PUS_PUS_5             BIT5
 set     GPIOB_PUS_PUS_6             BIT6
 set     GPIOB_PUS_PUS_7             BIT7
 set     GPIOB_PUS_PUS_8             BIT8
 set     GPIOB_PUS_PUS_9             BIT9
 set     GPIOB_PUS_PUS_10            BIT10
 set     GPIOB_PUS_PUS_11            BIT11
 set     GPIOB_PUS_PUS_12            BIT12
 set     GPIOB_PUS_PUS_13            BIT13
 set     GPIOB_PUS_PUS_14            BIT14
 set     GPIOB_PUS_PUS_15            BIT15

 set     GPIOB_SRE_SRE               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Slew Rate Enable
;;     0b0 ==> Slew rate is enabled (the turn-on time of the output transistor is faster)
;;     0b1 ==> Slew rate is disabled (the turn-on time of the output transistor is slower)
 set     GPIOB_SRE_SRE_0             BIT0
 set     GPIOB_SRE_SRE_1             BIT1
 set     GPIOB_SRE_SRE_2             BIT2
 set     GPIOB_SRE_SRE_3             BIT3
 set     GPIOB_SRE_SRE_4             BIT4
 set     GPIOB_SRE_SRE_5             BIT5
 set     GPIOB_SRE_SRE_6             BIT6
 set     GPIOB_SRE_SRE_7             BIT7
 set     GPIOB_SRE_SRE_8             BIT8
 set     GPIOB_SRE_SRE_9             BIT9
 set     GPIOB_SRE_SRE_10            BIT10
 set     GPIOB_SRE_SRE_11            BIT11
 set     GPIOB_SRE_SRE_12            BIT12
 set     GPIOB_SRE_SRE_13            BIT13
 set     GPIOB_SRE_SRE_14            BIT14
 set     GPIOB_SRE_SRE_15            BIT15

 set     GPIOC_PUR_PU                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Enable Bits
;;     0b0 ==> Pull resistor is disabled
;;     0b1 ==> Pull resistor is enabled
 set     GPIOC_PUR_PU_0              BIT0
 set     GPIOC_PUR_PU_1              BIT1
 set     GPIOC_PUR_PU_2              BIT2
 set     GPIOC_PUR_PU_3              BIT3
 set     GPIOC_PUR_PU_4              BIT4
 set     GPIOC_PUR_PU_5              BIT5
 set     GPIOC_PUR_PU_6              BIT6
 set     GPIOC_PUR_PU_7              BIT7
 set     GPIOC_PUR_PU_8              BIT8
 set     GPIOC_PUR_PU_9              BIT9
 set     GPIOC_PUR_PU_10             BIT10
 set     GPIOC_PUR_PU_11             BIT11
 set     GPIOC_PUR_PU_12             BIT12
 set     GPIOC_PUR_PU_13             BIT13
 set     GPIOC_PUR_PU_14             BIT14
 set     GPIOC_PUR_PU_15             BIT15

 set     GPIOC_DR_D                  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Bits
 set     GPIOC_DR_D_0                BIT0
 set     GPIOC_DR_D_1                BIT1
 set     GPIOC_DR_D_2                BIT2
 set     GPIOC_DR_D_3                BIT3
 set     GPIOC_DR_D_4                BIT4
 set     GPIOC_DR_D_5                BIT5
 set     GPIOC_DR_D_6                BIT6
 set     GPIOC_DR_D_7                BIT7
 set     GPIOC_DR_D_8                BIT8
 set     GPIOC_DR_D_9                BIT9
 set     GPIOC_DR_D_10               BIT10
 set     GPIOC_DR_D_11               BIT11
 set     GPIOC_DR_D_12               BIT12
 set     GPIOC_DR_D_13               BIT13
 set     GPIOC_DR_D_14               BIT14
 set     GPIOC_DR_D_15               BIT15

 set     GPIOC_DDR_DD                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Direction Bits
;;     0b0 ==> Pin is an input
;;     0b1 ==> Pin is an output
 set     GPIOC_DDR_DD_0              BIT0
 set     GPIOC_DDR_DD_1              BIT1
 set     GPIOC_DDR_DD_2              BIT2
 set     GPIOC_DDR_DD_3              BIT3
 set     GPIOC_DDR_DD_4              BIT4
 set     GPIOC_DDR_DD_5              BIT5
 set     GPIOC_DDR_DD_6              BIT6
 set     GPIOC_DDR_DD_7              BIT7
 set     GPIOC_DDR_DD_8              BIT8
 set     GPIOC_DDR_DD_9              BIT9
 set     GPIOC_DDR_DD_10             BIT10
 set     GPIOC_DDR_DD_11             BIT11
 set     GPIOC_DDR_DD_12             BIT12
 set     GPIOC_DDR_DD_13             BIT13
 set     GPIOC_DDR_DD_14             BIT14
 set     GPIOC_DDR_DD_15             BIT15

 set     GPIOC_PER_PE                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Peripheral Enable Bits
;;     0b0 ==> Pin is for GPIO (GPIO mode)
;;     0b1 ==> Pin is for peripheral (peripheral mode)
 set     GPIOC_PER_PE_0              BIT0
 set     GPIOC_PER_PE_1              BIT1
 set     GPIOC_PER_PE_2              BIT2
 set     GPIOC_PER_PE_3              BIT3
 set     GPIOC_PER_PE_4              BIT4
 set     GPIOC_PER_PE_5              BIT5
 set     GPIOC_PER_PE_6              BIT6
 set     GPIOC_PER_PE_7              BIT7
 set     GPIOC_PER_PE_8              BIT8
 set     GPIOC_PER_PE_9              BIT9
 set     GPIOC_PER_PE_10             BIT10
 set     GPIOC_PER_PE_11             BIT11
 set     GPIOC_PER_PE_12             BIT12
 set     GPIOC_PER_PE_13             BIT13
 set     GPIOC_PER_PE_14             BIT14
 set     GPIOC_PER_PE_15             BIT15

 set     GPIOC_IAR_IA                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Assert Bits
;;     0b0 ==> Deassert software interrupt
;;     0b1 ==> Assert software interrupt
 set     GPIOC_IAR_IA_0              BIT0
 set     GPIOC_IAR_IA_1              BIT1
 set     GPIOC_IAR_IA_2              BIT2
 set     GPIOC_IAR_IA_3              BIT3
 set     GPIOC_IAR_IA_4              BIT4
 set     GPIOC_IAR_IA_5              BIT5
 set     GPIOC_IAR_IA_6              BIT6
 set     GPIOC_IAR_IA_7              BIT7
 set     GPIOC_IAR_IA_8              BIT8
 set     GPIOC_IAR_IA_9              BIT9
 set     GPIOC_IAR_IA_10             BIT10
 set     GPIOC_IAR_IA_11             BIT11
 set     GPIOC_IAR_IA_12             BIT12
 set     GPIOC_IAR_IA_13             BIT13
 set     GPIOC_IAR_IA_14             BIT14
 set     GPIOC_IAR_IA_15             BIT15

 set     GPIOC_IENR_IEN              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Enable Bits
;;     0b0 ==> External Interrupt is disabled
;;     0b1 ==> External Interrupt is enabled
 set     GPIOC_IENR_IEN_0            BIT0
 set     GPIOC_IENR_IEN_1            BIT1
 set     GPIOC_IENR_IEN_2            BIT2
 set     GPIOC_IENR_IEN_3            BIT3
 set     GPIOC_IENR_IEN_4            BIT4
 set     GPIOC_IENR_IEN_5            BIT5
 set     GPIOC_IENR_IEN_6            BIT6
 set     GPIOC_IENR_IEN_7            BIT7
 set     GPIOC_IENR_IEN_8            BIT8
 set     GPIOC_IENR_IEN_9            BIT9
 set     GPIOC_IENR_IEN_10           BIT10
 set     GPIOC_IENR_IEN_11           BIT11
 set     GPIOC_IENR_IEN_12           BIT12
 set     GPIOC_IENR_IEN_13           BIT13
 set     GPIOC_IENR_IEN_14           BIT14
 set     GPIOC_IENR_IEN_15           BIT15

 set     GPIOC_IPOLR_IPOL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Polarity Bits
;;     0b0 ==> Interrupt occurred on rising edge
;;     0b1 ==> Interrupt occurred on falling edge
 set     GPIOC_IPOLR_IPOL_0          BIT0
 set     GPIOC_IPOLR_IPOL_1          BIT1
 set     GPIOC_IPOLR_IPOL_2          BIT2
 set     GPIOC_IPOLR_IPOL_3          BIT3
 set     GPIOC_IPOLR_IPOL_4          BIT4
 set     GPIOC_IPOLR_IPOL_5          BIT5
 set     GPIOC_IPOLR_IPOL_6          BIT6
 set     GPIOC_IPOLR_IPOL_7          BIT7
 set     GPIOC_IPOLR_IPOL_8          BIT8
 set     GPIOC_IPOLR_IPOL_9          BIT9
 set     GPIOC_IPOLR_IPOL_10         BIT10
 set     GPIOC_IPOLR_IPOL_11         BIT11
 set     GPIOC_IPOLR_IPOL_12         BIT12
 set     GPIOC_IPOLR_IPOL_13         BIT13
 set     GPIOC_IPOLR_IPOL_14         BIT14
 set     GPIOC_IPOLR_IPOL_15         BIT15

 set     GPIOC_IPR_IP                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Pending Bits
;;     0b0 ==> No Interrupt
;;     0b1 ==> Interrupt occurred
 set     GPIOC_IPR_IP_0              BIT0
 set     GPIOC_IPR_IP_1              BIT1
 set     GPIOC_IPR_IP_2              BIT2
 set     GPIOC_IPR_IP_3              BIT3
 set     GPIOC_IPR_IP_4              BIT4
 set     GPIOC_IPR_IP_5              BIT5
 set     GPIOC_IPR_IP_6              BIT6
 set     GPIOC_IPR_IP_7              BIT7
 set     GPIOC_IPR_IP_8              BIT8
 set     GPIOC_IPR_IP_9              BIT9
 set     GPIOC_IPR_IP_10             BIT10
 set     GPIOC_IPR_IP_11             BIT11
 set     GPIOC_IPR_IP_12             BIT12
 set     GPIOC_IPR_IP_13             BIT13
 set     GPIOC_IPR_IP_14             BIT14
 set     GPIOC_IPR_IP_15             BIT15

 set     GPIOC_IESR_IES              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Edge-Sensitive Bits
;;     0b0 ==> No edge detected if read; no effect if writing
;;     0b1 ==> An edge detected if read; clear corresponding Interrupt Pending bit if writing
 set     GPIOC_IESR_IES_0            BIT0
 set     GPIOC_IESR_IES_1            BIT1
 set     GPIOC_IESR_IES_2            BIT2
 set     GPIOC_IESR_IES_3            BIT3
 set     GPIOC_IESR_IES_4            BIT4
 set     GPIOC_IESR_IES_5            BIT5
 set     GPIOC_IESR_IES_6            BIT6
 set     GPIOC_IESR_IES_7            BIT7
 set     GPIOC_IESR_IES_8            BIT8
 set     GPIOC_IESR_IES_9            BIT9
 set     GPIOC_IESR_IES_10           BIT10
 set     GPIOC_IESR_IES_11           BIT11
 set     GPIOC_IESR_IES_12           BIT12
 set     GPIOC_IESR_IES_13           BIT13
 set     GPIOC_IESR_IES_14           BIT14
 set     GPIOC_IESR_IES_15           BIT15

 set     GPIOC_PPMODE_PPMODE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Push-Pull Mode Bits
;;     0b0 ==> Open Drain Mode
;;     0b1 ==> Push-Pull Mode
 set     GPIOC_PPMODE_PPMODE_0       BIT0
 set     GPIOC_PPMODE_PPMODE_1       BIT1
 set     GPIOC_PPMODE_PPMODE_2       BIT2
 set     GPIOC_PPMODE_PPMODE_3       BIT3
 set     GPIOC_PPMODE_PPMODE_4       BIT4
 set     GPIOC_PPMODE_PPMODE_5       BIT5
 set     GPIOC_PPMODE_PPMODE_6       BIT6
 set     GPIOC_PPMODE_PPMODE_7       BIT7
 set     GPIOC_PPMODE_PPMODE_8       BIT8
 set     GPIOC_PPMODE_PPMODE_9       BIT9
 set     GPIOC_PPMODE_PPMODE_10      BIT10
 set     GPIOC_PPMODE_PPMODE_11      BIT11
 set     GPIOC_PPMODE_PPMODE_12      BIT12
 set     GPIOC_PPMODE_PPMODE_13      BIT13
 set     GPIOC_PPMODE_PPMODE_14      BIT14
 set     GPIOC_PPMODE_PPMODE_15      BIT15

 set     GPIOC_RAWDATA_RAW_DATA      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Raw Data Bits
 set     GPIOC_RAWDATA_RAW_DATA_0    BIT0
 set     GPIOC_RAWDATA_RAW_DATA_1    BIT1
 set     GPIOC_RAWDATA_RAW_DATA_2    BIT2
 set     GPIOC_RAWDATA_RAW_DATA_3    BIT3
 set     GPIOC_RAWDATA_RAW_DATA_4    BIT4
 set     GPIOC_RAWDATA_RAW_DATA_5    BIT5
 set     GPIOC_RAWDATA_RAW_DATA_6    BIT6
 set     GPIOC_RAWDATA_RAW_DATA_7    BIT7
 set     GPIOC_RAWDATA_RAW_DATA_8    BIT8
 set     GPIOC_RAWDATA_RAW_DATA_9    BIT9
 set     GPIOC_RAWDATA_RAW_DATA_10   BIT10
 set     GPIOC_RAWDATA_RAW_DATA_11   BIT11
 set     GPIOC_RAWDATA_RAW_DATA_12   BIT12
 set     GPIOC_RAWDATA_RAW_DATA_13   BIT13
 set     GPIOC_RAWDATA_RAW_DATA_14   BIT14
 set     GPIOC_RAWDATA_RAW_DATA_15   BIT15

 set     GPIOC_DRIVE_DRIVE           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Drive Strength Selector Bits
;;     0b0 ==> Low drive strength
;;     0b1 ==> High drive strength
 set     GPIOC_DRIVE_DRIVE_0         BIT0
 set     GPIOC_DRIVE_DRIVE_1         BIT1
 set     GPIOC_DRIVE_DRIVE_2         BIT2
 set     GPIOC_DRIVE_DRIVE_3         BIT3
 set     GPIOC_DRIVE_DRIVE_4         BIT4
 set     GPIOC_DRIVE_DRIVE_5         BIT5
 set     GPIOC_DRIVE_DRIVE_6         BIT6
 set     GPIOC_DRIVE_DRIVE_7         BIT7
 set     GPIOC_DRIVE_DRIVE_8         BIT8
 set     GPIOC_DRIVE_DRIVE_9         BIT9
 set     GPIOC_DRIVE_DRIVE_10        BIT10
 set     GPIOC_DRIVE_DRIVE_11        BIT11
 set     GPIOC_DRIVE_DRIVE_12        BIT12
 set     GPIOC_DRIVE_DRIVE_13        BIT13
 set     GPIOC_DRIVE_DRIVE_14        BIT14
 set     GPIOC_DRIVE_DRIVE_15        BIT15

 set     GPIOC_PUS_PUS               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Type Select Bits
;;     0b0 ==> Pulldown resistor
;;     0b1 ==> Pullup resistor
 set     GPIOC_PUS_PUS_0             BIT0
 set     GPIOC_PUS_PUS_1             BIT1
 set     GPIOC_PUS_PUS_2             BIT2
 set     GPIOC_PUS_PUS_3             BIT3
 set     GPIOC_PUS_PUS_4             BIT4
 set     GPIOC_PUS_PUS_5             BIT5
 set     GPIOC_PUS_PUS_6             BIT6
 set     GPIOC_PUS_PUS_7             BIT7
 set     GPIOC_PUS_PUS_8             BIT8
 set     GPIOC_PUS_PUS_9             BIT9
 set     GPIOC_PUS_PUS_10            BIT10
 set     GPIOC_PUS_PUS_11            BIT11
 set     GPIOC_PUS_PUS_12            BIT12
 set     GPIOC_PUS_PUS_13            BIT13
 set     GPIOC_PUS_PUS_14            BIT14
 set     GPIOC_PUS_PUS_15            BIT15

 set     GPIOC_SRE_SRE               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Slew Rate Enable
;;     0b0 ==> Slew rate is enabled (the turn-on time of the output transistor is faster)
;;     0b1 ==> Slew rate is disabled (the turn-on time of the output transistor is slower)
 set     GPIOC_SRE_SRE_0             BIT0
 set     GPIOC_SRE_SRE_1             BIT1
 set     GPIOC_SRE_SRE_2             BIT2
 set     GPIOC_SRE_SRE_3             BIT3
 set     GPIOC_SRE_SRE_4             BIT4
 set     GPIOC_SRE_SRE_5             BIT5
 set     GPIOC_SRE_SRE_6             BIT6
 set     GPIOC_SRE_SRE_7             BIT7
 set     GPIOC_SRE_SRE_8             BIT8
 set     GPIOC_SRE_SRE_9             BIT9
 set     GPIOC_SRE_SRE_10            BIT10
 set     GPIOC_SRE_SRE_11            BIT11
 set     GPIOC_SRE_SRE_12            BIT12
 set     GPIOC_SRE_SRE_13            BIT13
 set     GPIOC_SRE_SRE_14            BIT14
 set     GPIOC_SRE_SRE_15            BIT15

 set     GPIOD_PUR_PU                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Enable Bits
;;     0b0 ==> Pull resistor is disabled
;;     0b1 ==> Pull resistor is enabled
 set     GPIOD_PUR_PU_0              BIT0
 set     GPIOD_PUR_PU_1              BIT1
 set     GPIOD_PUR_PU_2              BIT2
 set     GPIOD_PUR_PU_3              BIT3
 set     GPIOD_PUR_PU_4              BIT4
 set     GPIOD_PUR_PU_5              BIT5
 set     GPIOD_PUR_PU_6              BIT6
 set     GPIOD_PUR_PU_7              BIT7
 set     GPIOD_PUR_PU_8              BIT8
 set     GPIOD_PUR_PU_9              BIT9
 set     GPIOD_PUR_PU_10             BIT10
 set     GPIOD_PUR_PU_11             BIT11
 set     GPIOD_PUR_PU_12             BIT12
 set     GPIOD_PUR_PU_13             BIT13
 set     GPIOD_PUR_PU_14             BIT14
 set     GPIOD_PUR_PU_15             BIT15

 set     GPIOD_DR_D                  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Bits
 set     GPIOD_DR_D_0                BIT0
 set     GPIOD_DR_D_1                BIT1
 set     GPIOD_DR_D_2                BIT2
 set     GPIOD_DR_D_3                BIT3
 set     GPIOD_DR_D_4                BIT4
 set     GPIOD_DR_D_5                BIT5
 set     GPIOD_DR_D_6                BIT6
 set     GPIOD_DR_D_7                BIT7
 set     GPIOD_DR_D_8                BIT8
 set     GPIOD_DR_D_9                BIT9
 set     GPIOD_DR_D_10               BIT10
 set     GPIOD_DR_D_11               BIT11
 set     GPIOD_DR_D_12               BIT12
 set     GPIOD_DR_D_13               BIT13
 set     GPIOD_DR_D_14               BIT14
 set     GPIOD_DR_D_15               BIT15

 set     GPIOD_DDR_DD                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Direction Bits
;;     0b0 ==> Pin is an input
;;     0b1 ==> Pin is an output
 set     GPIOD_DDR_DD_0              BIT0
 set     GPIOD_DDR_DD_1              BIT1
 set     GPIOD_DDR_DD_2              BIT2
 set     GPIOD_DDR_DD_3              BIT3
 set     GPIOD_DDR_DD_4              BIT4
 set     GPIOD_DDR_DD_5              BIT5
 set     GPIOD_DDR_DD_6              BIT6
 set     GPIOD_DDR_DD_7              BIT7
 set     GPIOD_DDR_DD_8              BIT8
 set     GPIOD_DDR_DD_9              BIT9
 set     GPIOD_DDR_DD_10             BIT10
 set     GPIOD_DDR_DD_11             BIT11
 set     GPIOD_DDR_DD_12             BIT12
 set     GPIOD_DDR_DD_13             BIT13
 set     GPIOD_DDR_DD_14             BIT14
 set     GPIOD_DDR_DD_15             BIT15

 set     GPIOD_PER_PE                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Peripheral Enable Bits
;;     0b0 ==> Pin is for GPIO (GPIO mode)
;;     0b1 ==> Pin is for peripheral (peripheral mode)
 set     GPIOD_PER_PE_0              BIT0
 set     GPIOD_PER_PE_1              BIT1
 set     GPIOD_PER_PE_2              BIT2
 set     GPIOD_PER_PE_3              BIT3
 set     GPIOD_PER_PE_4              BIT4
 set     GPIOD_PER_PE_5              BIT5
 set     GPIOD_PER_PE_6              BIT6
 set     GPIOD_PER_PE_7              BIT7
 set     GPIOD_PER_PE_8              BIT8
 set     GPIOD_PER_PE_9              BIT9
 set     GPIOD_PER_PE_10             BIT10
 set     GPIOD_PER_PE_11             BIT11
 set     GPIOD_PER_PE_12             BIT12
 set     GPIOD_PER_PE_13             BIT13
 set     GPIOD_PER_PE_14             BIT14
 set     GPIOD_PER_PE_15             BIT15

 set     GPIOD_IAR_IA                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Assert Bits
;;     0b0 ==> Deassert software interrupt
;;     0b1 ==> Assert software interrupt
 set     GPIOD_IAR_IA_0              BIT0
 set     GPIOD_IAR_IA_1              BIT1
 set     GPIOD_IAR_IA_2              BIT2
 set     GPIOD_IAR_IA_3              BIT3
 set     GPIOD_IAR_IA_4              BIT4
 set     GPIOD_IAR_IA_5              BIT5
 set     GPIOD_IAR_IA_6              BIT6
 set     GPIOD_IAR_IA_7              BIT7
 set     GPIOD_IAR_IA_8              BIT8
 set     GPIOD_IAR_IA_9              BIT9
 set     GPIOD_IAR_IA_10             BIT10
 set     GPIOD_IAR_IA_11             BIT11
 set     GPIOD_IAR_IA_12             BIT12
 set     GPIOD_IAR_IA_13             BIT13
 set     GPIOD_IAR_IA_14             BIT14
 set     GPIOD_IAR_IA_15             BIT15

 set     GPIOD_IENR_IEN              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Enable Bits
;;     0b0 ==> External Interrupt is disabled
;;     0b1 ==> External Interrupt is enabled
 set     GPIOD_IENR_IEN_0            BIT0
 set     GPIOD_IENR_IEN_1            BIT1
 set     GPIOD_IENR_IEN_2            BIT2
 set     GPIOD_IENR_IEN_3            BIT3
 set     GPIOD_IENR_IEN_4            BIT4
 set     GPIOD_IENR_IEN_5            BIT5
 set     GPIOD_IENR_IEN_6            BIT6
 set     GPIOD_IENR_IEN_7            BIT7
 set     GPIOD_IENR_IEN_8            BIT8
 set     GPIOD_IENR_IEN_9            BIT9
 set     GPIOD_IENR_IEN_10           BIT10
 set     GPIOD_IENR_IEN_11           BIT11
 set     GPIOD_IENR_IEN_12           BIT12
 set     GPIOD_IENR_IEN_13           BIT13
 set     GPIOD_IENR_IEN_14           BIT14
 set     GPIOD_IENR_IEN_15           BIT15

 set     GPIOD_IPOLR_IPOL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Polarity Bits
;;     0b0 ==> Interrupt occurred on rising edge
;;     0b1 ==> Interrupt occurred on falling edge
 set     GPIOD_IPOLR_IPOL_0          BIT0
 set     GPIOD_IPOLR_IPOL_1          BIT1
 set     GPIOD_IPOLR_IPOL_2          BIT2
 set     GPIOD_IPOLR_IPOL_3          BIT3
 set     GPIOD_IPOLR_IPOL_4          BIT4
 set     GPIOD_IPOLR_IPOL_5          BIT5
 set     GPIOD_IPOLR_IPOL_6          BIT6
 set     GPIOD_IPOLR_IPOL_7          BIT7
 set     GPIOD_IPOLR_IPOL_8          BIT8
 set     GPIOD_IPOLR_IPOL_9          BIT9
 set     GPIOD_IPOLR_IPOL_10         BIT10
 set     GPIOD_IPOLR_IPOL_11         BIT11
 set     GPIOD_IPOLR_IPOL_12         BIT12
 set     GPIOD_IPOLR_IPOL_13         BIT13
 set     GPIOD_IPOLR_IPOL_14         BIT14
 set     GPIOD_IPOLR_IPOL_15         BIT15

 set     GPIOD_IPR_IP                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Pending Bits
;;     0b0 ==> No Interrupt
;;     0b1 ==> Interrupt occurred
 set     GPIOD_IPR_IP_0              BIT0
 set     GPIOD_IPR_IP_1              BIT1
 set     GPIOD_IPR_IP_2              BIT2
 set     GPIOD_IPR_IP_3              BIT3
 set     GPIOD_IPR_IP_4              BIT4
 set     GPIOD_IPR_IP_5              BIT5
 set     GPIOD_IPR_IP_6              BIT6
 set     GPIOD_IPR_IP_7              BIT7
 set     GPIOD_IPR_IP_8              BIT8
 set     GPIOD_IPR_IP_9              BIT9
 set     GPIOD_IPR_IP_10             BIT10
 set     GPIOD_IPR_IP_11             BIT11
 set     GPIOD_IPR_IP_12             BIT12
 set     GPIOD_IPR_IP_13             BIT13
 set     GPIOD_IPR_IP_14             BIT14
 set     GPIOD_IPR_IP_15             BIT15

 set     GPIOD_IESR_IES              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Edge-Sensitive Bits
;;     0b0 ==> No edge detected if read; no effect if writing
;;     0b1 ==> An edge detected if read; clear corresponding Interrupt Pending bit if writing
 set     GPIOD_IESR_IES_0            BIT0
 set     GPIOD_IESR_IES_1            BIT1
 set     GPIOD_IESR_IES_2            BIT2
 set     GPIOD_IESR_IES_3            BIT3
 set     GPIOD_IESR_IES_4            BIT4
 set     GPIOD_IESR_IES_5            BIT5
 set     GPIOD_IESR_IES_6            BIT6
 set     GPIOD_IESR_IES_7            BIT7
 set     GPIOD_IESR_IES_8            BIT8
 set     GPIOD_IESR_IES_9            BIT9
 set     GPIOD_IESR_IES_10           BIT10
 set     GPIOD_IESR_IES_11           BIT11
 set     GPIOD_IESR_IES_12           BIT12
 set     GPIOD_IESR_IES_13           BIT13
 set     GPIOD_IESR_IES_14           BIT14
 set     GPIOD_IESR_IES_15           BIT15

 set     GPIOD_PPMODE_PPMODE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Push-Pull Mode Bits
;;     0b0 ==> Open Drain Mode
;;     0b1 ==> Push-Pull Mode
 set     GPIOD_PPMODE_PPMODE_0       BIT0
 set     GPIOD_PPMODE_PPMODE_1       BIT1
 set     GPIOD_PPMODE_PPMODE_2       BIT2
 set     GPIOD_PPMODE_PPMODE_3       BIT3
 set     GPIOD_PPMODE_PPMODE_4       BIT4
 set     GPIOD_PPMODE_PPMODE_5       BIT5
 set     GPIOD_PPMODE_PPMODE_6       BIT6
 set     GPIOD_PPMODE_PPMODE_7       BIT7
 set     GPIOD_PPMODE_PPMODE_8       BIT8
 set     GPIOD_PPMODE_PPMODE_9       BIT9
 set     GPIOD_PPMODE_PPMODE_10      BIT10
 set     GPIOD_PPMODE_PPMODE_11      BIT11
 set     GPIOD_PPMODE_PPMODE_12      BIT12
 set     GPIOD_PPMODE_PPMODE_13      BIT13
 set     GPIOD_PPMODE_PPMODE_14      BIT14
 set     GPIOD_PPMODE_PPMODE_15      BIT15

 set     GPIOD_RAWDATA_RAW_DATA      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Raw Data Bits
 set     GPIOD_RAWDATA_RAW_DATA_0    BIT0
 set     GPIOD_RAWDATA_RAW_DATA_1    BIT1
 set     GPIOD_RAWDATA_RAW_DATA_2    BIT2
 set     GPIOD_RAWDATA_RAW_DATA_3    BIT3
 set     GPIOD_RAWDATA_RAW_DATA_4    BIT4
 set     GPIOD_RAWDATA_RAW_DATA_5    BIT5
 set     GPIOD_RAWDATA_RAW_DATA_6    BIT6
 set     GPIOD_RAWDATA_RAW_DATA_7    BIT7
 set     GPIOD_RAWDATA_RAW_DATA_8    BIT8
 set     GPIOD_RAWDATA_RAW_DATA_9    BIT9
 set     GPIOD_RAWDATA_RAW_DATA_10   BIT10
 set     GPIOD_RAWDATA_RAW_DATA_11   BIT11
 set     GPIOD_RAWDATA_RAW_DATA_12   BIT12
 set     GPIOD_RAWDATA_RAW_DATA_13   BIT13
 set     GPIOD_RAWDATA_RAW_DATA_14   BIT14
 set     GPIOD_RAWDATA_RAW_DATA_15   BIT15

 set     GPIOD_DRIVE_DRIVE           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Drive Strength Selector Bits
;;     0b0 ==> Low drive strength
;;     0b1 ==> High drive strength
 set     GPIOD_DRIVE_DRIVE_0         BIT0
 set     GPIOD_DRIVE_DRIVE_1         BIT1
 set     GPIOD_DRIVE_DRIVE_2         BIT2
 set     GPIOD_DRIVE_DRIVE_3         BIT3
 set     GPIOD_DRIVE_DRIVE_4         BIT4
 set     GPIOD_DRIVE_DRIVE_5         BIT5
 set     GPIOD_DRIVE_DRIVE_6         BIT6
 set     GPIOD_DRIVE_DRIVE_7         BIT7
 set     GPIOD_DRIVE_DRIVE_8         BIT8
 set     GPIOD_DRIVE_DRIVE_9         BIT9
 set     GPIOD_DRIVE_DRIVE_10        BIT10
 set     GPIOD_DRIVE_DRIVE_11        BIT11
 set     GPIOD_DRIVE_DRIVE_12        BIT12
 set     GPIOD_DRIVE_DRIVE_13        BIT13
 set     GPIOD_DRIVE_DRIVE_14        BIT14
 set     GPIOD_DRIVE_DRIVE_15        BIT15

 set     GPIOD_PUS_PUS               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Type Select Bits
;;     0b0 ==> Pulldown resistor
;;     0b1 ==> Pullup resistor
 set     GPIOD_PUS_PUS_0             BIT0
 set     GPIOD_PUS_PUS_1             BIT1
 set     GPIOD_PUS_PUS_2             BIT2
 set     GPIOD_PUS_PUS_3             BIT3
 set     GPIOD_PUS_PUS_4             BIT4
 set     GPIOD_PUS_PUS_5             BIT5
 set     GPIOD_PUS_PUS_6             BIT6
 set     GPIOD_PUS_PUS_7             BIT7
 set     GPIOD_PUS_PUS_8             BIT8
 set     GPIOD_PUS_PUS_9             BIT9
 set     GPIOD_PUS_PUS_10            BIT10
 set     GPIOD_PUS_PUS_11            BIT11
 set     GPIOD_PUS_PUS_12            BIT12
 set     GPIOD_PUS_PUS_13            BIT13
 set     GPIOD_PUS_PUS_14            BIT14
 set     GPIOD_PUS_PUS_15            BIT15

 set     GPIOD_SRE_SRE               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Slew Rate Enable
;;     0b0 ==> Slew rate is enabled (the turn-on time of the output transistor is faster)
;;     0b1 ==> Slew rate is disabled (the turn-on time of the output transistor is slower)
 set     GPIOD_SRE_SRE_0             BIT0
 set     GPIOD_SRE_SRE_1             BIT1
 set     GPIOD_SRE_SRE_2             BIT2
 set     GPIOD_SRE_SRE_3             BIT3
 set     GPIOD_SRE_SRE_4             BIT4
 set     GPIOD_SRE_SRE_5             BIT5
 set     GPIOD_SRE_SRE_6             BIT6
 set     GPIOD_SRE_SRE_7             BIT7
 set     GPIOD_SRE_SRE_8             BIT8
 set     GPIOD_SRE_SRE_9             BIT9
 set     GPIOD_SRE_SRE_10            BIT10
 set     GPIOD_SRE_SRE_11            BIT11
 set     GPIOD_SRE_SRE_12            BIT12
 set     GPIOD_SRE_SRE_13            BIT13
 set     GPIOD_SRE_SRE_14            BIT14
 set     GPIOD_SRE_SRE_15            BIT15

 set     GPIOE_PUR_PU                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Enable Bits
;;     0b0 ==> Pull resistor is disabled
;;     0b1 ==> Pull resistor is enabled
 set     GPIOE_PUR_PU_0              BIT0
 set     GPIOE_PUR_PU_1              BIT1
 set     GPIOE_PUR_PU_2              BIT2
 set     GPIOE_PUR_PU_3              BIT3
 set     GPIOE_PUR_PU_4              BIT4
 set     GPIOE_PUR_PU_5              BIT5
 set     GPIOE_PUR_PU_6              BIT6
 set     GPIOE_PUR_PU_7              BIT7
 set     GPIOE_PUR_PU_8              BIT8
 set     GPIOE_PUR_PU_9              BIT9
 set     GPIOE_PUR_PU_10             BIT10
 set     GPIOE_PUR_PU_11             BIT11
 set     GPIOE_PUR_PU_12             BIT12
 set     GPIOE_PUR_PU_13             BIT13
 set     GPIOE_PUR_PU_14             BIT14
 set     GPIOE_PUR_PU_15             BIT15

 set     GPIOE_DR_D                  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Bits
 set     GPIOE_DR_D_0                BIT0
 set     GPIOE_DR_D_1                BIT1
 set     GPIOE_DR_D_2                BIT2
 set     GPIOE_DR_D_3                BIT3
 set     GPIOE_DR_D_4                BIT4
 set     GPIOE_DR_D_5                BIT5
 set     GPIOE_DR_D_6                BIT6
 set     GPIOE_DR_D_7                BIT7
 set     GPIOE_DR_D_8                BIT8
 set     GPIOE_DR_D_9                BIT9
 set     GPIOE_DR_D_10               BIT10
 set     GPIOE_DR_D_11               BIT11
 set     GPIOE_DR_D_12               BIT12
 set     GPIOE_DR_D_13               BIT13
 set     GPIOE_DR_D_14               BIT14
 set     GPIOE_DR_D_15               BIT15

 set     GPIOE_DDR_DD                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Direction Bits
;;     0b0 ==> Pin is an input
;;     0b1 ==> Pin is an output
 set     GPIOE_DDR_DD_0              BIT0
 set     GPIOE_DDR_DD_1              BIT1
 set     GPIOE_DDR_DD_2              BIT2
 set     GPIOE_DDR_DD_3              BIT3
 set     GPIOE_DDR_DD_4              BIT4
 set     GPIOE_DDR_DD_5              BIT5
 set     GPIOE_DDR_DD_6              BIT6
 set     GPIOE_DDR_DD_7              BIT7
 set     GPIOE_DDR_DD_8              BIT8
 set     GPIOE_DDR_DD_9              BIT9
 set     GPIOE_DDR_DD_10             BIT10
 set     GPIOE_DDR_DD_11             BIT11
 set     GPIOE_DDR_DD_12             BIT12
 set     GPIOE_DDR_DD_13             BIT13
 set     GPIOE_DDR_DD_14             BIT14
 set     GPIOE_DDR_DD_15             BIT15

 set     GPIOE_PER_PE                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Peripheral Enable Bits
;;     0b0 ==> Pin is for GPIO (GPIO mode)
;;     0b1 ==> Pin is for peripheral (peripheral mode)
 set     GPIOE_PER_PE_0              BIT0
 set     GPIOE_PER_PE_1              BIT1
 set     GPIOE_PER_PE_2              BIT2
 set     GPIOE_PER_PE_3              BIT3
 set     GPIOE_PER_PE_4              BIT4
 set     GPIOE_PER_PE_5              BIT5
 set     GPIOE_PER_PE_6              BIT6
 set     GPIOE_PER_PE_7              BIT7
 set     GPIOE_PER_PE_8              BIT8
 set     GPIOE_PER_PE_9              BIT9
 set     GPIOE_PER_PE_10             BIT10
 set     GPIOE_PER_PE_11             BIT11
 set     GPIOE_PER_PE_12             BIT12
 set     GPIOE_PER_PE_13             BIT13
 set     GPIOE_PER_PE_14             BIT14
 set     GPIOE_PER_PE_15             BIT15

 set     GPIOE_IAR_IA                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Assert Bits
;;     0b0 ==> Deassert software interrupt
;;     0b1 ==> Assert software interrupt
 set     GPIOE_IAR_IA_0              BIT0
 set     GPIOE_IAR_IA_1              BIT1
 set     GPIOE_IAR_IA_2              BIT2
 set     GPIOE_IAR_IA_3              BIT3
 set     GPIOE_IAR_IA_4              BIT4
 set     GPIOE_IAR_IA_5              BIT5
 set     GPIOE_IAR_IA_6              BIT6
 set     GPIOE_IAR_IA_7              BIT7
 set     GPIOE_IAR_IA_8              BIT8
 set     GPIOE_IAR_IA_9              BIT9
 set     GPIOE_IAR_IA_10             BIT10
 set     GPIOE_IAR_IA_11             BIT11
 set     GPIOE_IAR_IA_12             BIT12
 set     GPIOE_IAR_IA_13             BIT13
 set     GPIOE_IAR_IA_14             BIT14
 set     GPIOE_IAR_IA_15             BIT15

 set     GPIOE_IENR_IEN              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Enable Bits
;;     0b0 ==> External Interrupt is disabled
;;     0b1 ==> External Interrupt is enabled
 set     GPIOE_IENR_IEN_0            BIT0
 set     GPIOE_IENR_IEN_1            BIT1
 set     GPIOE_IENR_IEN_2            BIT2
 set     GPIOE_IENR_IEN_3            BIT3
 set     GPIOE_IENR_IEN_4            BIT4
 set     GPIOE_IENR_IEN_5            BIT5
 set     GPIOE_IENR_IEN_6            BIT6
 set     GPIOE_IENR_IEN_7            BIT7
 set     GPIOE_IENR_IEN_8            BIT8
 set     GPIOE_IENR_IEN_9            BIT9
 set     GPIOE_IENR_IEN_10           BIT10
 set     GPIOE_IENR_IEN_11           BIT11
 set     GPIOE_IENR_IEN_12           BIT12
 set     GPIOE_IENR_IEN_13           BIT13
 set     GPIOE_IENR_IEN_14           BIT14
 set     GPIOE_IENR_IEN_15           BIT15

 set     GPIOE_IPOLR_IPOL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Polarity Bits
;;     0b0 ==> Interrupt occurred on rising edge
;;     0b1 ==> Interrupt occurred on falling edge
 set     GPIOE_IPOLR_IPOL_0          BIT0
 set     GPIOE_IPOLR_IPOL_1          BIT1
 set     GPIOE_IPOLR_IPOL_2          BIT2
 set     GPIOE_IPOLR_IPOL_3          BIT3
 set     GPIOE_IPOLR_IPOL_4          BIT4
 set     GPIOE_IPOLR_IPOL_5          BIT5
 set     GPIOE_IPOLR_IPOL_6          BIT6
 set     GPIOE_IPOLR_IPOL_7          BIT7
 set     GPIOE_IPOLR_IPOL_8          BIT8
 set     GPIOE_IPOLR_IPOL_9          BIT9
 set     GPIOE_IPOLR_IPOL_10         BIT10
 set     GPIOE_IPOLR_IPOL_11         BIT11
 set     GPIOE_IPOLR_IPOL_12         BIT12
 set     GPIOE_IPOLR_IPOL_13         BIT13
 set     GPIOE_IPOLR_IPOL_14         BIT14
 set     GPIOE_IPOLR_IPOL_15         BIT15

 set     GPIOE_IPR_IP                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Pending Bits
;;     0b0 ==> No Interrupt
;;     0b1 ==> Interrupt occurred
 set     GPIOE_IPR_IP_0              BIT0
 set     GPIOE_IPR_IP_1              BIT1
 set     GPIOE_IPR_IP_2              BIT2
 set     GPIOE_IPR_IP_3              BIT3
 set     GPIOE_IPR_IP_4              BIT4
 set     GPIOE_IPR_IP_5              BIT5
 set     GPIOE_IPR_IP_6              BIT6
 set     GPIOE_IPR_IP_7              BIT7
 set     GPIOE_IPR_IP_8              BIT8
 set     GPIOE_IPR_IP_9              BIT9
 set     GPIOE_IPR_IP_10             BIT10
 set     GPIOE_IPR_IP_11             BIT11
 set     GPIOE_IPR_IP_12             BIT12
 set     GPIOE_IPR_IP_13             BIT13
 set     GPIOE_IPR_IP_14             BIT14
 set     GPIOE_IPR_IP_15             BIT15

 set     GPIOE_IESR_IES              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Edge-Sensitive Bits
;;     0b0 ==> No edge detected if read; no effect if writing
;;     0b1 ==> An edge detected if read; clear corresponding Interrupt Pending bit if writing
 set     GPIOE_IESR_IES_0            BIT0
 set     GPIOE_IESR_IES_1            BIT1
 set     GPIOE_IESR_IES_2            BIT2
 set     GPIOE_IESR_IES_3            BIT3
 set     GPIOE_IESR_IES_4            BIT4
 set     GPIOE_IESR_IES_5            BIT5
 set     GPIOE_IESR_IES_6            BIT6
 set     GPIOE_IESR_IES_7            BIT7
 set     GPIOE_IESR_IES_8            BIT8
 set     GPIOE_IESR_IES_9            BIT9
 set     GPIOE_IESR_IES_10           BIT10
 set     GPIOE_IESR_IES_11           BIT11
 set     GPIOE_IESR_IES_12           BIT12
 set     GPIOE_IESR_IES_13           BIT13
 set     GPIOE_IESR_IES_14           BIT14
 set     GPIOE_IESR_IES_15           BIT15

 set     GPIOE_PPMODE_PPMODE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Push-Pull Mode Bits
;;     0b0 ==> Open Drain Mode
;;     0b1 ==> Push-Pull Mode
 set     GPIOE_PPMODE_PPMODE_0       BIT0
 set     GPIOE_PPMODE_PPMODE_1       BIT1
 set     GPIOE_PPMODE_PPMODE_2       BIT2
 set     GPIOE_PPMODE_PPMODE_3       BIT3
 set     GPIOE_PPMODE_PPMODE_4       BIT4
 set     GPIOE_PPMODE_PPMODE_5       BIT5
 set     GPIOE_PPMODE_PPMODE_6       BIT6
 set     GPIOE_PPMODE_PPMODE_7       BIT7
 set     GPIOE_PPMODE_PPMODE_8       BIT8
 set     GPIOE_PPMODE_PPMODE_9       BIT9
 set     GPIOE_PPMODE_PPMODE_10      BIT10
 set     GPIOE_PPMODE_PPMODE_11      BIT11
 set     GPIOE_PPMODE_PPMODE_12      BIT12
 set     GPIOE_PPMODE_PPMODE_13      BIT13
 set     GPIOE_PPMODE_PPMODE_14      BIT14
 set     GPIOE_PPMODE_PPMODE_15      BIT15

 set     GPIOE_RAWDATA_RAW_DATA      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Raw Data Bits
 set     GPIOE_RAWDATA_RAW_DATA_0    BIT0
 set     GPIOE_RAWDATA_RAW_DATA_1    BIT1
 set     GPIOE_RAWDATA_RAW_DATA_2    BIT2
 set     GPIOE_RAWDATA_RAW_DATA_3    BIT3
 set     GPIOE_RAWDATA_RAW_DATA_4    BIT4
 set     GPIOE_RAWDATA_RAW_DATA_5    BIT5
 set     GPIOE_RAWDATA_RAW_DATA_6    BIT6
 set     GPIOE_RAWDATA_RAW_DATA_7    BIT7
 set     GPIOE_RAWDATA_RAW_DATA_8    BIT8
 set     GPIOE_RAWDATA_RAW_DATA_9    BIT9
 set     GPIOE_RAWDATA_RAW_DATA_10   BIT10
 set     GPIOE_RAWDATA_RAW_DATA_11   BIT11
 set     GPIOE_RAWDATA_RAW_DATA_12   BIT12
 set     GPIOE_RAWDATA_RAW_DATA_13   BIT13
 set     GPIOE_RAWDATA_RAW_DATA_14   BIT14
 set     GPIOE_RAWDATA_RAW_DATA_15   BIT15

 set     GPIOE_DRIVE_DRIVE           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Drive Strength Selector Bits
;;     0b0 ==> Low drive strength
;;     0b1 ==> High drive strength
 set     GPIOE_DRIVE_DRIVE_0         BIT0
 set     GPIOE_DRIVE_DRIVE_1         BIT1
 set     GPIOE_DRIVE_DRIVE_2         BIT2
 set     GPIOE_DRIVE_DRIVE_3         BIT3
 set     GPIOE_DRIVE_DRIVE_4         BIT4
 set     GPIOE_DRIVE_DRIVE_5         BIT5
 set     GPIOE_DRIVE_DRIVE_6         BIT6
 set     GPIOE_DRIVE_DRIVE_7         BIT7
 set     GPIOE_DRIVE_DRIVE_8         BIT8
 set     GPIOE_DRIVE_DRIVE_9         BIT9
 set     GPIOE_DRIVE_DRIVE_10        BIT10
 set     GPIOE_DRIVE_DRIVE_11        BIT11
 set     GPIOE_DRIVE_DRIVE_12        BIT12
 set     GPIOE_DRIVE_DRIVE_13        BIT13
 set     GPIOE_DRIVE_DRIVE_14        BIT14
 set     GPIOE_DRIVE_DRIVE_15        BIT15

 set     GPIOE_PUS_PUS               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Type Select Bits
;;     0b0 ==> Pulldown resistor
;;     0b1 ==> Pullup resistor
 set     GPIOE_PUS_PUS_0             BIT0
 set     GPIOE_PUS_PUS_1             BIT1
 set     GPIOE_PUS_PUS_2             BIT2
 set     GPIOE_PUS_PUS_3             BIT3
 set     GPIOE_PUS_PUS_4             BIT4
 set     GPIOE_PUS_PUS_5             BIT5
 set     GPIOE_PUS_PUS_6             BIT6
 set     GPIOE_PUS_PUS_7             BIT7
 set     GPIOE_PUS_PUS_8             BIT8
 set     GPIOE_PUS_PUS_9             BIT9
 set     GPIOE_PUS_PUS_10            BIT10
 set     GPIOE_PUS_PUS_11            BIT11
 set     GPIOE_PUS_PUS_12            BIT12
 set     GPIOE_PUS_PUS_13            BIT13
 set     GPIOE_PUS_PUS_14            BIT14
 set     GPIOE_PUS_PUS_15            BIT15

 set     GPIOE_SRE_SRE               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Slew Rate Enable
;;     0b0 ==> Slew rate is enabled (the turn-on time of the output transistor is faster)
;;     0b1 ==> Slew rate is disabled (the turn-on time of the output transistor is slower)
 set     GPIOE_SRE_SRE_0             BIT0
 set     GPIOE_SRE_SRE_1             BIT1
 set     GPIOE_SRE_SRE_2             BIT2
 set     GPIOE_SRE_SRE_3             BIT3
 set     GPIOE_SRE_SRE_4             BIT4
 set     GPIOE_SRE_SRE_5             BIT5
 set     GPIOE_SRE_SRE_6             BIT6
 set     GPIOE_SRE_SRE_7             BIT7
 set     GPIOE_SRE_SRE_8             BIT8
 set     GPIOE_SRE_SRE_9             BIT9
 set     GPIOE_SRE_SRE_10            BIT10
 set     GPIOE_SRE_SRE_11            BIT11
 set     GPIOE_SRE_SRE_12            BIT12
 set     GPIOE_SRE_SRE_13            BIT13
 set     GPIOE_SRE_SRE_14            BIT14
 set     GPIOE_SRE_SRE_15            BIT15

 set     GPIOF_PUR_PU                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Enable Bits
;;     0b0 ==> Pull resistor is disabled
;;     0b1 ==> Pull resistor is enabled
 set     GPIOF_PUR_PU_0              BIT0
 set     GPIOF_PUR_PU_1              BIT1
 set     GPIOF_PUR_PU_2              BIT2
 set     GPIOF_PUR_PU_3              BIT3
 set     GPIOF_PUR_PU_4              BIT4
 set     GPIOF_PUR_PU_5              BIT5
 set     GPIOF_PUR_PU_6              BIT6
 set     GPIOF_PUR_PU_7              BIT7
 set     GPIOF_PUR_PU_8              BIT8
 set     GPIOF_PUR_PU_9              BIT9
 set     GPIOF_PUR_PU_10             BIT10
 set     GPIOF_PUR_PU_11             BIT11
 set     GPIOF_PUR_PU_12             BIT12
 set     GPIOF_PUR_PU_13             BIT13
 set     GPIOF_PUR_PU_14             BIT14
 set     GPIOF_PUR_PU_15             BIT15

 set     GPIOF_DR_D                  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Bits
 set     GPIOF_DR_D_0                BIT0
 set     GPIOF_DR_D_1                BIT1
 set     GPIOF_DR_D_2                BIT2
 set     GPIOF_DR_D_3                BIT3
 set     GPIOF_DR_D_4                BIT4
 set     GPIOF_DR_D_5                BIT5
 set     GPIOF_DR_D_6                BIT6
 set     GPIOF_DR_D_7                BIT7
 set     GPIOF_DR_D_8                BIT8
 set     GPIOF_DR_D_9                BIT9
 set     GPIOF_DR_D_10               BIT10
 set     GPIOF_DR_D_11               BIT11
 set     GPIOF_DR_D_12               BIT12
 set     GPIOF_DR_D_13               BIT13
 set     GPIOF_DR_D_14               BIT14
 set     GPIOF_DR_D_15               BIT15

 set     GPIOF_DDR_DD                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Data Direction Bits
;;     0b0 ==> Pin is an input
;;     0b1 ==> Pin is an output
 set     GPIOF_DDR_DD_0              BIT0
 set     GPIOF_DDR_DD_1              BIT1
 set     GPIOF_DDR_DD_2              BIT2
 set     GPIOF_DDR_DD_3              BIT3
 set     GPIOF_DDR_DD_4              BIT4
 set     GPIOF_DDR_DD_5              BIT5
 set     GPIOF_DDR_DD_6              BIT6
 set     GPIOF_DDR_DD_7              BIT7
 set     GPIOF_DDR_DD_8              BIT8
 set     GPIOF_DDR_DD_9              BIT9
 set     GPIOF_DDR_DD_10             BIT10
 set     GPIOF_DDR_DD_11             BIT11
 set     GPIOF_DDR_DD_12             BIT12
 set     GPIOF_DDR_DD_13             BIT13
 set     GPIOF_DDR_DD_14             BIT14
 set     GPIOF_DDR_DD_15             BIT15

 set     GPIOF_PER_PE                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Peripheral Enable Bits
;;     0b0 ==> Pin is for GPIO (GPIO mode)
;;     0b1 ==> Pin is for peripheral (peripheral mode)
 set     GPIOF_PER_PE_0              BIT0
 set     GPIOF_PER_PE_1              BIT1
 set     GPIOF_PER_PE_2              BIT2
 set     GPIOF_PER_PE_3              BIT3
 set     GPIOF_PER_PE_4              BIT4
 set     GPIOF_PER_PE_5              BIT5
 set     GPIOF_PER_PE_6              BIT6
 set     GPIOF_PER_PE_7              BIT7
 set     GPIOF_PER_PE_8              BIT8
 set     GPIOF_PER_PE_9              BIT9
 set     GPIOF_PER_PE_10             BIT10
 set     GPIOF_PER_PE_11             BIT11
 set     GPIOF_PER_PE_12             BIT12
 set     GPIOF_PER_PE_13             BIT13
 set     GPIOF_PER_PE_14             BIT14
 set     GPIOF_PER_PE_15             BIT15

 set     GPIOF_IAR_IA                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Assert Bits
;;     0b0 ==> Deassert software interrupt
;;     0b1 ==> Assert software interrupt
 set     GPIOF_IAR_IA_0              BIT0
 set     GPIOF_IAR_IA_1              BIT1
 set     GPIOF_IAR_IA_2              BIT2
 set     GPIOF_IAR_IA_3              BIT3
 set     GPIOF_IAR_IA_4              BIT4
 set     GPIOF_IAR_IA_5              BIT5
 set     GPIOF_IAR_IA_6              BIT6
 set     GPIOF_IAR_IA_7              BIT7
 set     GPIOF_IAR_IA_8              BIT8
 set     GPIOF_IAR_IA_9              BIT9
 set     GPIOF_IAR_IA_10             BIT10
 set     GPIOF_IAR_IA_11             BIT11
 set     GPIOF_IAR_IA_12             BIT12
 set     GPIOF_IAR_IA_13             BIT13
 set     GPIOF_IAR_IA_14             BIT14
 set     GPIOF_IAR_IA_15             BIT15

 set     GPIOF_IENR_IEN              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Enable Bits
;;     0b0 ==> External Interrupt is disabled
;;     0b1 ==> External Interrupt is enabled
 set     GPIOF_IENR_IEN_0            BIT0
 set     GPIOF_IENR_IEN_1            BIT1
 set     GPIOF_IENR_IEN_2            BIT2
 set     GPIOF_IENR_IEN_3            BIT3
 set     GPIOF_IENR_IEN_4            BIT4
 set     GPIOF_IENR_IEN_5            BIT5
 set     GPIOF_IENR_IEN_6            BIT6
 set     GPIOF_IENR_IEN_7            BIT7
 set     GPIOF_IENR_IEN_8            BIT8
 set     GPIOF_IENR_IEN_9            BIT9
 set     GPIOF_IENR_IEN_10           BIT10
 set     GPIOF_IENR_IEN_11           BIT11
 set     GPIOF_IENR_IEN_12           BIT12
 set     GPIOF_IENR_IEN_13           BIT13
 set     GPIOF_IENR_IEN_14           BIT14
 set     GPIOF_IENR_IEN_15           BIT15

 set     GPIOF_IPOLR_IPOL            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Polarity Bits
;;     0b0 ==> Interrupt occurred on rising edge
;;     0b1 ==> Interrupt occurred on falling edge
 set     GPIOF_IPOLR_IPOL_0          BIT0
 set     GPIOF_IPOLR_IPOL_1          BIT1
 set     GPIOF_IPOLR_IPOL_2          BIT2
 set     GPIOF_IPOLR_IPOL_3          BIT3
 set     GPIOF_IPOLR_IPOL_4          BIT4
 set     GPIOF_IPOLR_IPOL_5          BIT5
 set     GPIOF_IPOLR_IPOL_6          BIT6
 set     GPIOF_IPOLR_IPOL_7          BIT7
 set     GPIOF_IPOLR_IPOL_8          BIT8
 set     GPIOF_IPOLR_IPOL_9          BIT9
 set     GPIOF_IPOLR_IPOL_10         BIT10
 set     GPIOF_IPOLR_IPOL_11         BIT11
 set     GPIOF_IPOLR_IPOL_12         BIT12
 set     GPIOF_IPOLR_IPOL_13         BIT13
 set     GPIOF_IPOLR_IPOL_14         BIT14
 set     GPIOF_IPOLR_IPOL_15         BIT15

 set     GPIOF_IPR_IP                (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Pending Bits
;;     0b0 ==> No Interrupt
;;     0b1 ==> Interrupt occurred
 set     GPIOF_IPR_IP_0              BIT0
 set     GPIOF_IPR_IP_1              BIT1
 set     GPIOF_IPR_IP_2              BIT2
 set     GPIOF_IPR_IP_3              BIT3
 set     GPIOF_IPR_IP_4              BIT4
 set     GPIOF_IPR_IP_5              BIT5
 set     GPIOF_IPR_IP_6              BIT6
 set     GPIOF_IPR_IP_7              BIT7
 set     GPIOF_IPR_IP_8              BIT8
 set     GPIOF_IPR_IP_9              BIT9
 set     GPIOF_IPR_IP_10             BIT10
 set     GPIOF_IPR_IP_11             BIT11
 set     GPIOF_IPR_IP_12             BIT12
 set     GPIOF_IPR_IP_13             BIT13
 set     GPIOF_IPR_IP_14             BIT14
 set     GPIOF_IPR_IP_15             BIT15

 set     GPIOF_IESR_IES              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Interrupt Edge-Sensitive Bits
;;     0b0 ==> No edge detected if read; no effect if writing
;;     0b1 ==> An edge detected if read; clear corresponding Interrupt Pending bit if writing
 set     GPIOF_IESR_IES_0            BIT0
 set     GPIOF_IESR_IES_1            BIT1
 set     GPIOF_IESR_IES_2            BIT2
 set     GPIOF_IESR_IES_3            BIT3
 set     GPIOF_IESR_IES_4            BIT4
 set     GPIOF_IESR_IES_5            BIT5
 set     GPIOF_IESR_IES_6            BIT6
 set     GPIOF_IESR_IES_7            BIT7
 set     GPIOF_IESR_IES_8            BIT8
 set     GPIOF_IESR_IES_9            BIT9
 set     GPIOF_IESR_IES_10           BIT10
 set     GPIOF_IESR_IES_11           BIT11
 set     GPIOF_IESR_IES_12           BIT12
 set     GPIOF_IESR_IES_13           BIT13
 set     GPIOF_IESR_IES_14           BIT14
 set     GPIOF_IESR_IES_15           BIT15

 set     GPIOF_PPMODE_PPMODE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Push-Pull Mode Bits
;;     0b0 ==> Open Drain Mode
;;     0b1 ==> Push-Pull Mode
 set     GPIOF_PPMODE_PPMODE_0       BIT0
 set     GPIOF_PPMODE_PPMODE_1       BIT1
 set     GPIOF_PPMODE_PPMODE_2       BIT2
 set     GPIOF_PPMODE_PPMODE_3       BIT3
 set     GPIOF_PPMODE_PPMODE_4       BIT4
 set     GPIOF_PPMODE_PPMODE_5       BIT5
 set     GPIOF_PPMODE_PPMODE_6       BIT6
 set     GPIOF_PPMODE_PPMODE_7       BIT7
 set     GPIOF_PPMODE_PPMODE_8       BIT8
 set     GPIOF_PPMODE_PPMODE_9       BIT9
 set     GPIOF_PPMODE_PPMODE_10      BIT10
 set     GPIOF_PPMODE_PPMODE_11      BIT11
 set     GPIOF_PPMODE_PPMODE_12      BIT12
 set     GPIOF_PPMODE_PPMODE_13      BIT13
 set     GPIOF_PPMODE_PPMODE_14      BIT14
 set     GPIOF_PPMODE_PPMODE_15      BIT15

 set     GPIOF_RAWDATA_RAW_DATA      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Raw Data Bits
 set     GPIOF_RAWDATA_RAW_DATA_0    BIT0
 set     GPIOF_RAWDATA_RAW_DATA_1    BIT1
 set     GPIOF_RAWDATA_RAW_DATA_2    BIT2
 set     GPIOF_RAWDATA_RAW_DATA_3    BIT3
 set     GPIOF_RAWDATA_RAW_DATA_4    BIT4
 set     GPIOF_RAWDATA_RAW_DATA_5    BIT5
 set     GPIOF_RAWDATA_RAW_DATA_6    BIT6
 set     GPIOF_RAWDATA_RAW_DATA_7    BIT7
 set     GPIOF_RAWDATA_RAW_DATA_8    BIT8
 set     GPIOF_RAWDATA_RAW_DATA_9    BIT9
 set     GPIOF_RAWDATA_RAW_DATA_10   BIT10
 set     GPIOF_RAWDATA_RAW_DATA_11   BIT11
 set     GPIOF_RAWDATA_RAW_DATA_12   BIT12
 set     GPIOF_RAWDATA_RAW_DATA_13   BIT13
 set     GPIOF_RAWDATA_RAW_DATA_14   BIT14
 set     GPIOF_RAWDATA_RAW_DATA_15   BIT15

 set     GPIOF_DRIVE_DRIVE           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Drive Strength Selector Bits
;;     0b0 ==> Low drive strength
;;     0b1 ==> High drive strength
 set     GPIOF_DRIVE_DRIVE_0         BIT0
 set     GPIOF_DRIVE_DRIVE_1         BIT1
 set     GPIOF_DRIVE_DRIVE_2         BIT2
 set     GPIOF_DRIVE_DRIVE_3         BIT3
 set     GPIOF_DRIVE_DRIVE_4         BIT4
 set     GPIOF_DRIVE_DRIVE_5         BIT5
 set     GPIOF_DRIVE_DRIVE_6         BIT6
 set     GPIOF_DRIVE_DRIVE_7         BIT7
 set     GPIOF_DRIVE_DRIVE_8         BIT8
 set     GPIOF_DRIVE_DRIVE_9         BIT9
 set     GPIOF_DRIVE_DRIVE_10        BIT10
 set     GPIOF_DRIVE_DRIVE_11        BIT11
 set     GPIOF_DRIVE_DRIVE_12        BIT12
 set     GPIOF_DRIVE_DRIVE_13        BIT13
 set     GPIOF_DRIVE_DRIVE_14        BIT14
 set     GPIOF_DRIVE_DRIVE_15        BIT15

 set     GPIOF_PUS_PUS               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pull Resistor Type Select Bits
;;     0b0 ==> Pulldown resistor
;;     0b1 ==> Pullup resistor
 set     GPIOF_PUS_PUS_0             BIT0
 set     GPIOF_PUS_PUS_1             BIT1
 set     GPIOF_PUS_PUS_2             BIT2
 set     GPIOF_PUS_PUS_3             BIT3
 set     GPIOF_PUS_PUS_4             BIT4
 set     GPIOF_PUS_PUS_5             BIT5
 set     GPIOF_PUS_PUS_6             BIT6
 set     GPIOF_PUS_PUS_7             BIT7
 set     GPIOF_PUS_PUS_8             BIT8
 set     GPIOF_PUS_PUS_9             BIT9
 set     GPIOF_PUS_PUS_10            BIT10
 set     GPIOF_PUS_PUS_11            BIT11
 set     GPIOF_PUS_PUS_12            BIT12
 set     GPIOF_PUS_PUS_13            BIT13
 set     GPIOF_PUS_PUS_14            BIT14
 set     GPIOF_PUS_PUS_15            BIT15

 set     GPIOF_SRE_SRE               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Slew Rate Enable
;;     0b0 ==> Slew rate is enabled (the turn-on time of the output transistor is faster)
;;     0b1 ==> Slew rate is disabled (the turn-on time of the output transistor is slower)
 set     GPIOF_SRE_SRE_0             BIT0
 set     GPIOF_SRE_SRE_1             BIT1
 set     GPIOF_SRE_SRE_2             BIT2
 set     GPIOF_SRE_SRE_3             BIT3
 set     GPIOF_SRE_SRE_4             BIT4
 set     GPIOF_SRE_SRE_5             BIT5
 set     GPIOF_SRE_SRE_6             BIT6
 set     GPIOF_SRE_SRE_7             BIT7
 set     GPIOF_SRE_SRE_8             BIT8
 set     GPIOF_SRE_SRE_9             BIT9
 set     GPIOF_SRE_SRE_10            BIT10
 set     GPIOF_SRE_SRE_11            BIT11
 set     GPIOF_SRE_SRE_12            BIT12
 set     GPIOF_SRE_SRE_13            BIT13
 set     GPIOF_SRE_SRE_14            BIT14
 set     GPIOF_SRE_SRE_15            BIT15

 set     I2C_A1_AD                   (BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Address
 set     I2C_A1_AD_0                 BIT1
 set     I2C_A1_AD_1                 BIT2
 set     I2C_A1_AD_2                 BIT3
 set     I2C_A1_AD_3                 BIT4
 set     I2C_A1_AD_4                 BIT5
 set     I2C_A1_AD_5                 BIT6
 set     I2C_A1_AD_6                 BIT7

 set     I2C_F_ICR                   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   ClockRate
 set     I2C_F_ICR_0                 BIT0
 set     I2C_F_ICR_1                 BIT1
 set     I2C_F_ICR_2                 BIT2
 set     I2C_F_ICR_3                 BIT3
 set     I2C_F_ICR_4                 BIT4
 set     I2C_F_ICR_5                 BIT5

 set     I2C_F_MULT                  (BIT6|BIT7)
;;     0b00 ==> mul = 1
;;     0b01 ==> mul = 2
;;     0b10 ==> mul = 4
;;     0b11 ==> Reserved
 set     I2C_F_MULT_0                BIT6
 set     I2C_F_MULT_1                BIT7

 set     I2C_C1_DMAEN                BIT0
;;   DMA Enable
;;     0b0 ==> All DMA signalling disabled.
;;     0b1 ==> DMA transfer is enabled and the following conditions trigger the DMA request: While FACK = 0, a data byte is received, either address or data is transmitted. (ACK/NACK automatic) While FACK = 0, the first byte received matches the A1 register or is general call address. If any address matching occurs, IAAS and TCF are set. If the direction of transfer is known from master to slave, then it is not required to check the SRW. With this assumption, DMA can also be used in this
;;             case. In other cases, if the master reads data from the slave, then it is required to rewrite the C1 register operation. With this assumption, DMA cannot be used. When FACK = 1, an address or a data byte is transmitted.

 set     I2C_C1_WUEN                 BIT1
;;   Wakeup Enable
;;     0b0 ==> Normal operation. No interrupt generated when address matching in low power mode.
;;     0b1 ==> Enables the wakeup function in low power mode.

 set     I2C_C1_RSTA                 BIT2
;;   Repeat START

 set     I2C_C1_TXAK                 BIT3
;;   Transmit Acknowledge Enable
;;     0b0 ==> An acknowledge signal is sent to the bus on the following receiving byte (if FACK is cleared) or the current receiving byte (if FACK is set).
;;     0b1 ==> No acknowledge signal is sent to the bus on the following receiving data byte (if FACK is cleared) or the current receiving data byte (if FACK is set).

 set     I2C_C1_TX                   BIT4
;;   Transmit Mode Select
;;     0b0 ==> Receive
;;     0b1 ==> Transmit

 set     I2C_C1_MST                  BIT5
;;   Master Mode Select
;;     0b0 ==> Slave mode
;;     0b1 ==> Master mode

 set     I2C_C1_IICIE                BIT6
;;   I2C Interrupt Enable
;;     0b0 ==> Disabled
;;     0b1 ==> Enabled

 set     I2C_C1_IICEN                BIT7
;;   I2C Enable
;;     0b0 ==> Disabled
;;     0b1 ==> Enabled

 set     I2C_S_RXAK                  BIT0
;;   Receive Acknowledge
;;     0b0 ==> Acknowledge signal was received after the completion of one byte of data transmission on the bus
;;     0b1 ==> No acknowledge signal detected

 set     I2C_S_IICIF                 BIT1
;;   Interrupt Flag
;;     0b0 ==> No interrupt pending
;;     0b1 ==> Interrupt pending

 set     I2C_S_SRW                   BIT2
;;   Slave Read/Write
;;     0b0 ==> Slave receive, master writing to slave
;;     0b1 ==> Slave transmit, master reading from slave

 set     I2C_S_RAM                   BIT3
;;   Range Address Match
;;     0b0 ==> Not addressed
;;     0b1 ==> Addressed as a slave

 set     I2C_S_ARBL                  BIT4
;;   Arbitration Lost
;;     0b0 ==> Standard bus operation.
;;     0b1 ==> Loss of arbitration.

 set     I2C_S_BUSY                  BIT5
;;   Bus Busy
;;     0b0 ==> Bus is idle
;;     0b1 ==> Bus is busy

 set     I2C_S_IAAS                  BIT6
;;   Addressed As A Slave
;;     0b0 ==> Not addressed
;;     0b1 ==> Addressed as a slave

 set     I2C_S_TCF                   BIT7
;;   Transfer Complete Flag
;;     0b0 ==> Transfer in progress
;;     0b1 ==> Transfer complete

 set     I2C_D_DATA                  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Data
 set     I2C_D_DATA_0                BIT0
 set     I2C_D_DATA_1                BIT1
 set     I2C_D_DATA_2                BIT2
 set     I2C_D_DATA_3                BIT3
 set     I2C_D_DATA_4                BIT4
 set     I2C_D_DATA_5                BIT5
 set     I2C_D_DATA_6                BIT6
 set     I2C_D_DATA_7                BIT7

 set     I2C_C2_AD                   (BIT0|BIT1|BIT2)
;;   Slave Address
 set     I2C_C2_AD_0                 BIT0
 set     I2C_C2_AD_1                 BIT1
 set     I2C_C2_AD_2                 BIT2

 set     I2C_C2_RMEN                 BIT3
;;   Range Address Matching Enable
;;     0b0 ==> Range mode disabled. No address match occurs for an address within the range of values of the A1 and RA registers.
;;     0b1 ==> Range mode enabled. Address matching occurs when a slave receives an address within the range of values of the A1 and RA registers.

 set     I2C_C2_SBRC                 BIT4
;;   Slave Baud Rate Control
;;     0b0 ==> The slave baud rate follows the master baud rate and clock stretching may occur
;;     0b1 ==> Slave baud rate is independent of the master baud rate

 set     I2C_C2_HDRS                 BIT5
;;   High Drive Select
;;     0b0 ==> Normal drive mode
;;     0b1 ==> High drive mode

 set     I2C_C2_ADEXT                BIT6
;;   Address Extension
;;     0b0 ==> 7-bit address scheme
;;     0b1 ==> 10-bit address scheme

 set     I2C_C2_GCAEN                BIT7
;;   General Call Address Enable
;;     0b0 ==> Disabled
;;     0b1 ==> Enabled

 set     I2C_FLT_FLT                 (BIT0|BIT1|BIT2|BIT3)
;;   I2C Programmable Filter Factor
;;     0b0 ==> No filter/bypass
 set     I2C_FLT_FLT_0               BIT0
 set     I2C_FLT_FLT_1               BIT1
 set     I2C_FLT_FLT_2               BIT2
 set     I2C_FLT_FLT_3               BIT3

 set     I2C_FLT_STARTF              BIT4
;;   I2C Bus Start Detect Flag
;;     0b0 ==> No start happens on I2C bus
;;     0b1 ==> Start detected on I2C bus

 set     I2C_FLT_SSIE                BIT5
;;   I2C Bus Stop or Start Interrupt Enable
;;     0b0 ==> Stop or start detection interrupt is disabled
;;     0b1 ==> Stop or start detection interrupt is enabled

 set     I2C_FLT_STOPF               BIT6
;;   I2C Bus Stop Detect Flag
;;     0b0 ==> No stop happens on I2C bus
;;     0b1 ==> Stop detected on I2C bus

 set     I2C_FLT_SHEN                BIT7
;;   Stop Hold Enable
;;     0b0 ==> Stop holdoff is disabled. The MCU's entry to stop mode is not gated.
;;     0b1 ==> Stop holdoff is enabled.

 set     I2C_RA_RAD                  (BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Range Slave Address
 set     I2C_RA_RAD_0                BIT1
 set     I2C_RA_RAD_1                BIT2
 set     I2C_RA_RAD_2                BIT3
 set     I2C_RA_RAD_3                BIT4
 set     I2C_RA_RAD_4                BIT5
 set     I2C_RA_RAD_5                BIT6
 set     I2C_RA_RAD_6                BIT7

 set     I2C_SMB_SHTF2IE             BIT0
;;   SHTF2 Interrupt Enable
;;     0b0 ==> SHTF2 interrupt is disabled
;;     0b1 ==> SHTF2 interrupt is enabled

 set     I2C_SMB_SHTF2               BIT1
;;   SCL High Timeout Flag 2
;;     0b0 ==> No SCL high and SDA low timeout occurs
;;     0b1 ==> SCL high and SDA low timeout occurs

 set     I2C_SMB_SHTF1               BIT2
;;   SCL High Timeout Flag 1
;;     0b0 ==> No SCL high and SDA high timeout occurs
;;     0b1 ==> SCL high and SDA high timeout occurs

 set     I2C_SMB_SLTF                BIT3
;;   SCL Low Timeout Flag
;;     0b0 ==> No low timeout occurs
;;     0b1 ==> Low timeout occurs

 set     I2C_SMB_TCKSEL              BIT4
;;   Timeout Counter Clock Select
;;     0b0 ==> Timeout counter counts at the frequency of the bus clock / 64
;;     0b1 ==> Timeout counter counts at the frequency of the bus clock

 set     I2C_SMB_SIICAEN             BIT5
;;   Second I2C Address Enable
;;     0b0 ==> I2C address register 2 matching is disabled
;;     0b1 ==> I2C address register 2 matching is enabled

 set     I2C_SMB_ALERTEN             BIT6
;;   SMBus Alert Response Address Enable
;;     0b0 ==> SMBus alert response address matching is disabled
;;     0b1 ==> SMBus alert response address matching is enabled

 set     I2C_SMB_FACK                BIT7
;;   Fast NACK/ACK Enable
;;     0b0 ==> An ACK or NACK is sent on the following receiving data byte
;;     0b1 ==> Writing 0 to TXAK after receiving a data byte generates an ACK. Writing 1 to TXAK after receiving a data byte generates a NACK.

 set     I2C_A2_SAD                  (BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   SMBus Address
 set     I2C_A2_SAD_0                BIT1
 set     I2C_A2_SAD_1                BIT2
 set     I2C_A2_SAD_2                BIT3
 set     I2C_A2_SAD_3                BIT4
 set     I2C_A2_SAD_4                BIT5
 set     I2C_A2_SAD_5                BIT6
 set     I2C_A2_SAD_6                BIT7

 set     I2C_SLTH_SSLT               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     I2C_SLTH_SSLT_0             BIT0
 set     I2C_SLTH_SSLT_1             BIT1
 set     I2C_SLTH_SSLT_2             BIT2
 set     I2C_SLTH_SSLT_3             BIT3
 set     I2C_SLTH_SSLT_4             BIT4
 set     I2C_SLTH_SSLT_5             BIT5
 set     I2C_SLTH_SSLT_6             BIT6
 set     I2C_SLTH_SSLT_7             BIT7

 set     I2C_SLTL_SSLT               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
 set     I2C_SLTL_SSLT_0             BIT0
 set     I2C_SLTL_SSLT_1             BIT1
 set     I2C_SLTL_SSLT_2             BIT2
 set     I2C_SLTL_SSLT_3             BIT3
 set     I2C_SLTL_SSLT_4             BIT4
 set     I2C_SLTL_SSLT_5             BIT5
 set     I2C_SLTL_SSLT_6             BIT6
 set     I2C_SLTL_SSLT_7             BIT7

 set     INTC_IPR0_STPCNT            (BIT0|BIT1)
;;   EOnCE Step Counter Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR0_STPCNT_0          BIT0
 set     INTC_IPR0_STPCNT_1          BIT1

 set     INTC_IPR0_BKPT              (BIT2|BIT3)
;;   EOnCE Breakpoint Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR0_BKPT_0            BIT2
 set     INTC_IPR0_BKPT_1            BIT3

 set     INTC_IPR0_TRBUF             (BIT4|BIT5)
;;   EOnCE Trace Buffer Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR0_TRBUF_0           BIT4
 set     INTC_IPR0_TRBUF_1           BIT5

 set     INTC_IPR0_TX_REG            (BIT6|BIT7)
;;   EOnCE Transmit Register Empty Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR0_TX_REG_0          BIT6
 set     INTC_IPR0_TX_REG_1          BIT7

 set     INTC_IPR0_RX_REG            (BIT8|BIT9)
;;   EOnCE Receive Register Full Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR0_RX_REG_0          BIT8
 set     INTC_IPR0_RX_REG_1          BIT9

 set     INTC_IPR0_BUS_ERR           (BIT10|BIT11)
;;   Bus Error Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR0_BUS_ERR_0         BIT10
 set     INTC_IPR0_BUS_ERR_1         BIT11

 set     INTC_IPR1_XBARA             (BIT2|BIT3)
;;   Inter-Peripheral Crossbar Switch A (XBARA) Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR1_XBARA_0           BIT2
 set     INTC_IPR1_XBARA_1           BIT3

 set     INTC_IPR1_LVI1              (BIT4|BIT5)
;;   Low Voltage Detector Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR1_LVI1_0            BIT4
 set     INTC_IPR1_LVI1_1            BIT5

 set     INTC_IPR1_OCCS              (BIT6|BIT7)
;;   PLL Loss of Reference or Change in Lock Status Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 1
;;     0b10 ==> IRQ Priority Level 2
;;     0b11 ==> IRQ Priority Level 3
 set     INTC_IPR1_OCCS_0            BIT6
 set     INTC_IPR1_OCCS_1            BIT7

 set     INTC_IPR2_TMRA_3            (BIT0|BIT1)
;;   Timer A Channel 3 Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR2_TMRA_3_0          BIT0
 set     INTC_IPR2_TMRA_3_1          BIT1

 set     INTC_IPR2_TMRA_2            (BIT2|BIT3)
;;   Timer A Channel 2 Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR2_TMRA_2_0          BIT2
 set     INTC_IPR2_TMRA_2_1          BIT3

 set     INTC_IPR2_TMRA_1            (BIT4|BIT5)
;;   Timer A Channel 1 Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR2_TMRA_1_0          BIT4
 set     INTC_IPR2_TMRA_1_1          BIT5

 set     INTC_IPR2_TMRA_0            (BIT6|BIT7)
;;   Timer A Channel 0 Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR2_TMRA_0_0          BIT6
 set     INTC_IPR2_TMRA_0_1          BIT7

 set     INTC_IPR2_ADC_CC1           (BIT8|BIT9)
;;   ADC_CYC Conversion Complete Interrupt Priority Level (converter B in non-simultaneous parallel scan mode)
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR2_ADC_CC1_0         BIT8
 set     INTC_IPR2_ADC_CC1_1         BIT9

 set     INTC_IPR2_ADC_CC0           (BIT10|BIT11)
;;   ADC_CYC Conversion Complete Interrupt Priority Level (any scan type except converter B in non-simultaneous parallel scan mode)
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR2_ADC_CC0_0         BIT10
 set     INTC_IPR2_ADC_CC0_1         BIT11

 set     INTC_IPR2_ADC_ERR           (BIT12|BIT13)
;;   ADC_CYC Zero Crossing, High Limit, or Low Limit Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR2_ADC_ERR_0         BIT12
 set     INTC_IPR2_ADC_ERR_1         BIT13

 set     INTC_IPR3_DMACH3            (BIT0|BIT1)
;;   DMA Channel 3 Service Request Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR3_DMACH3_0          BIT0
 set     INTC_IPR3_DMACH3_1          BIT1

 set     INTC_IPR3_DMACH2            (BIT2|BIT3)
;;   DMA Channel 2 Service Request Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR3_DMACH2_0          BIT2
 set     INTC_IPR3_DMACH2_1          BIT3

 set     INTC_IPR3_DMACH1            (BIT4|BIT5)
;;   DMA Channel 1 Service Request Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR3_DMACH1_0          BIT4
 set     INTC_IPR3_DMACH1_1          BIT5

 set     INTC_IPR3_DMACH0            (BIT6|BIT7)
;;   DMA Channel 0 Service Request Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR3_DMACH0_0          BIT6
 set     INTC_IPR3_DMACH0_1          BIT7

 set     INTC_IPR3_CAN_ERROR         (BIT12|BIT13)
;;   CAN Error Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR3_CAN_ERROR_0       BIT12
 set     INTC_IPR3_CAN_ERROR_1       BIT13

 set     INTC_IPR3_CAN_TX_WARN       (BIT14|BIT15)
;;   CAN Transmit Warning Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR3_CAN_TX_WARN_0     BIT14
 set     INTC_IPR3_CAN_TX_WARN_1     BIT15

 set     INTC_IPR4_CAN_RX_WARN       (BIT0|BIT1)
;;   CAN Receive Warning Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR4_CAN_RX_WARN_0     BIT0
 set     INTC_IPR4_CAN_RX_WARN_1     BIT1

 set     INTC_IPR4_CAN_WAKEUP        (BIT2|BIT3)
;;   CAN Wakeup Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR4_CAN_WAKEUP_0      BIT2
 set     INTC_IPR4_CAN_WAKEUP_1      BIT3

 set     INTC_IPR4_QSCI1_RERR        (BIT12|BIT13)
;;   QSCI 1 Receiver Error Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR4_QSCI1_RERR_0      BIT12
 set     INTC_IPR4_QSCI1_RERR_1      BIT13

 set     INTC_IPR4_QSCI1_RCV         (BIT14|BIT15)
;;   QSCI 1 Receive Data Register Full Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR4_QSCI1_RCV_0       BIT14
 set     INTC_IPR4_QSCI1_RCV_1       BIT15

 set     INTC_IPR5_QSCI1_TIDLE       (BIT0|BIT1)
;;   QSCI 1 Transmitter Idle Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR5_QSCI1_TIDLE_0     BIT0
 set     INTC_IPR5_QSCI1_TIDLE_1     BIT1

 set     INTC_IPR5_QSCI1_TDRE        (BIT2|BIT3)
;;   QSCI 1 Transmit Data Register Empty Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR5_QSCI1_TDRE_0      BIT2
 set     INTC_IPR5_QSCI1_TDRE_1      BIT3

 set     INTC_IPR5_QSCI0_RERR        (BIT4|BIT5)
;;   QSCI0 Receiver Error Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR5_QSCI0_RERR_0      BIT4
 set     INTC_IPR5_QSCI0_RERR_1      BIT5

 set     INTC_IPR5_QSCI0_RCV         (BIT6|BIT7)
;;   QSCI 0 Receive Data Register Full Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR5_QSCI0_RCV_0       BIT6
 set     INTC_IPR5_QSCI0_RCV_1       BIT7

 set     INTC_IPR5_QSCI0_TIDLE       (BIT8|BIT9)
;;   QSCI 0 Transmitter Idle Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR5_QSCI0_TIDLE_0     BIT8
 set     INTC_IPR5_QSCI0_TIDLE_1     BIT9

 set     INTC_IPR5_QSCI0_TDRE        (BIT10|BIT11)
;;   QSCI 0 Transmit Data Register Empty Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR5_QSCI0_TDRE_0      BIT10
 set     INTC_IPR5_QSCI0_TDRE_1      BIT11

 set     INTC_IPR6_QSPI1_XMIT        (BIT0|BIT1)
;;   QSPI1 Transmitter Empty Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR6_QSPI1_XMIT_0      BIT0
 set     INTC_IPR6_QSPI1_XMIT_1      BIT1

 set     INTC_IPR6_QSPI1_RCV         (BIT2|BIT3)
;;   QSPI1 Receiver Full Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR6_QSPI1_RCV_0       BIT2
 set     INTC_IPR6_QSPI1_RCV_1       BIT3

 set     INTC_IPR6_QSPI0_XMIT        (BIT4|BIT5)
;;   QSPI0 Transmitter Empty Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR6_QSPI0_XMIT_0      BIT4
 set     INTC_IPR6_QSPI0_XMIT_1      BIT5

 set     INTC_IPR6_QSPI0_RCV         (BIT6|BIT7)
;;   QSPI0 Receiver Full Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR6_QSPI0_RCV_0       BIT6
 set     INTC_IPR6_QSPI0_RCV_1       BIT7

 set     INTC_IPR6_IIC0              (BIT10|BIT11)
;;   IIC0 Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR6_IIC0_0            BIT10
 set     INTC_IPR6_IIC0_1            BIT11

 set     INTC_IPR8_PWMA_FAULT        (BIT8|BIT9)
;;   PWMA Fault Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR8_PWMA_FAULT_0      BIT8
 set     INTC_IPR8_PWMA_FAULT_1      BIT9

 set     INTC_IPR8_PWMA_RERR         (BIT10|BIT11)
;;   PWMA Reload Error Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR8_PWMA_RERR_0       BIT10
 set     INTC_IPR8_PWMA_RERR_1       BIT11

 set     INTC_IPR8_PWMA_RELOAD3      (BIT12|BIT13)
;;   PWMA Submodule 3 Reload Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR8_PWMA_RELOAD3_0    BIT12
 set     INTC_IPR8_PWMA_RELOAD3_1    BIT13

 set     INTC_IPR8_PWMA_CAP          (BIT14|BIT15)
;;   PWMA Submodule Capture Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR8_PWMA_CAP_0        BIT14
 set     INTC_IPR8_PWMA_CAP_1        BIT15

 set     INTC_IPR9_PWMA_CMP3         (BIT0|BIT1)
;;   PWMA Submodule 3 Compare Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR9_PWMA_CMP3_0       BIT0
 set     INTC_IPR9_PWMA_CMP3_1       BIT1

 set     INTC_IPR9_PWMA_RELOAD2      (BIT2|BIT3)
;;   PWMA Submodule 2 Reload Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR9_PWMA_RELOAD2_0    BIT2
 set     INTC_IPR9_PWMA_RELOAD2_1    BIT3

 set     INTC_IPR9_PWMA_CMP2         (BIT4|BIT5)
;;   PWMA Submodule 2 Compare Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR9_PWMA_CMP2_0       BIT4
 set     INTC_IPR9_PWMA_CMP2_1       BIT5

 set     INTC_IPR9_PWMA_RELOAD1      (BIT6|BIT7)
;;   PWMA Submodule 1 Reload Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR9_PWMA_RELOAD1_0    BIT6
 set     INTC_IPR9_PWMA_RELOAD1_1    BIT7

 set     INTC_IPR9_PWMA_CMP1         (BIT8|BIT9)
;;   PWMA Submodule 1 Compare Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR9_PWMA_CMP1_0       BIT8
 set     INTC_IPR9_PWMA_CMP1_1       BIT9

 set     INTC_IPR9_PWMA_RELOAD0      (BIT10|BIT11)
;;   PWMA Submodule 0 Reload Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR9_PWMA_RELOAD0_0    BIT10
 set     INTC_IPR9_PWMA_RELOAD0_1    BIT11

 set     INTC_IPR9_PWMA_CMP0         (BIT12|BIT13)
;;   PWMA Submodule 0 Compare Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR9_PWMA_CMP0_0       BIT12
 set     INTC_IPR9_PWMA_CMP0_1       BIT13

 set     INTC_IPR9_FTFA_RDCOL        (BIT14|BIT15)
;;   FTFA Access Error Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR9_FTFA_RDCOL_0      BIT14
 set     INTC_IPR9_FTFA_RDCOL_1      BIT15

 set     INTC_IPR10_FTFA_CC          (BIT0|BIT1)
;;   FTFA Command Complete Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR10_FTFA_CC_0        BIT0
 set     INTC_IPR10_FTFA_CC_1        BIT1

 set     INTC_IPR10_CMPD             (BIT2|BIT3)
;;   Comparator D Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR10_CMPD_0           BIT2
 set     INTC_IPR10_CMPD_1           BIT3

 set     INTC_IPR10_CMPC             (BIT4|BIT5)
;;   Comparator C Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR10_CMPC_0           BIT4
 set     INTC_IPR10_CMPC_1           BIT5

 set     INTC_IPR10_CMPB             (BIT6|BIT7)
;;   Comparator B Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR10_CMPB_0           BIT6
 set     INTC_IPR10_CMPB_1           BIT7

 set     INTC_IPR10_CMPA             (BIT8|BIT9)
;;   Comparator A Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR10_CMPA_0           BIT8
 set     INTC_IPR10_CMPA_1           BIT9

 set     INTC_IPR10_PIT1_ROLLOVR     (BIT10|BIT11)
;;   PIT1 Roll Over Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR10_PIT1_ROLLOVR_0   BIT10
 set     INTC_IPR10_PIT1_ROLLOVR_1   BIT11

 set     INTC_IPR10_PIT0_ROLLOVR     (BIT12|BIT13)
;;   PIT0 Roll Over Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR10_PIT0_ROLLOVR_0   BIT12
 set     INTC_IPR10_PIT0_ROLLOVR_1   BIT13

 set     INTC_IPR11_GPIOF            (BIT10|BIT11)
;;   GPIO F Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR11_GPIOF_0          BIT10
 set     INTC_IPR11_GPIOF_1          BIT11

 set     INTC_IPR11_GPIOE            (BIT12|BIT13)
;;   GPIO E Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR11_GPIOE_0          BIT12
 set     INTC_IPR11_GPIOE_1          BIT13

 set     INTC_IPR11_GPIOD            (BIT14|BIT15)
;;   GPIO D Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR11_GPIOD_0          BIT14
 set     INTC_IPR11_GPIOD_1          BIT15

 set     INTC_IPR12_GPIOC            (BIT0|BIT1)
;;   GPIO C Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR12_GPIOC_0          BIT0
 set     INTC_IPR12_GPIOC_1          BIT1

 set     INTC_IPR12_GPIOB            (BIT2|BIT3)
;;   GPIO B Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR12_GPIOB_0          BIT2
 set     INTC_IPR12_GPIOB_1          BIT3

 set     INTC_IPR12_GPIOA            (BIT4|BIT5)
;;   GPIO A Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR12_GPIOA_0          BIT4
 set     INTC_IPR12_GPIOA_1          BIT5

 set     INTC_IPR12_COP_INT          (BIT6|BIT7)
;;   COP Watchdog Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR12_COP_INT_0        BIT6
 set     INTC_IPR12_COP_INT_1        BIT7

 set     INTC_IPR12_EWM_INT          (BIT8|BIT9)
;;   External Watchdog Monitor Interrupt Priority Level
;;     0b00 ==> IRQ disabled (default)
;;     0b01 ==> IRQ Priority Level 0
;;     0b10 ==> IRQ Priority Level 1
;;     0b11 ==> IRQ Priority Level 2
 set     INTC_IPR12_EWM_INT_0        BIT8
 set     INTC_IPR12_EWM_INT_1        BIT9

 set     INTC_VBA_VECTOR_BASE_ADDRESS (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12)
;;   Interrupt Vector Base Address
 set     INTC_VBA_VECTOR_BASE_ADDRESS_0 BIT0
 set     INTC_VBA_VECTOR_BASE_ADDRESS_1 BIT1
 set     INTC_VBA_VECTOR_BASE_ADDRESS_2 BIT2
 set     INTC_VBA_VECTOR_BASE_ADDRESS_3 BIT3
 set     INTC_VBA_VECTOR_BASE_ADDRESS_4 BIT4
 set     INTC_VBA_VECTOR_BASE_ADDRESS_5 BIT5
 set     INTC_VBA_VECTOR_BASE_ADDRESS_6 BIT6
 set     INTC_VBA_VECTOR_BASE_ADDRESS_7 BIT7
 set     INTC_VBA_VECTOR_BASE_ADDRESS_8 BIT8
 set     INTC_VBA_VECTOR_BASE_ADDRESS_9 BIT9
 set     INTC_VBA_VECTOR_BASE_ADDRESS_10 BIT10
 set     INTC_VBA_VECTOR_BASE_ADDRESS_11 BIT11
 set     INTC_VBA_VECTOR_BASE_ADDRESS_12 BIT12

 set     INTC_FIM0_FAST_INTERRUPT_0  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6)
;;   Fast Interrupt 0 Vector Number
 set     INTC_FIM0_FAST_INTERRUPT_0_0 BIT0
 set     INTC_FIM0_FAST_INTERRUPT_0_1 BIT1
 set     INTC_FIM0_FAST_INTERRUPT_0_2 BIT2
 set     INTC_FIM0_FAST_INTERRUPT_0_3 BIT3
 set     INTC_FIM0_FAST_INTERRUPT_0_4 BIT4
 set     INTC_FIM0_FAST_INTERRUPT_0_5 BIT5
 set     INTC_FIM0_FAST_INTERRUPT_0_6 BIT6

 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_0 BIT0
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_1 BIT1
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_2 BIT2
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_3 BIT3
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_4 BIT4
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_5 BIT5
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_6 BIT6
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_7 BIT7
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_8 BIT8
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_9 BIT9
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_10 BIT10
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_11 BIT11
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_12 BIT12
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_13 BIT13
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_14 BIT14
 set     INTC_FIVAL0_FI_0_VECTOR_ADDRESS_LOW_15 BIT15

 set     INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH (BIT0|BIT1|BIT2|BIT3|BIT4)
;;   Upper 5 bits of vector address for fast interrupt 0
 set     INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_0 BIT0
 set     INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_1 BIT1
 set     INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_2 BIT2
 set     INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_3 BIT3
 set     INTC_FIVAH0_FI_0_VECTOR_ADDRESS_HIGH_4 BIT4

 set     INTC_FIM1_FAST_INTERRUPT_1  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6)
;;   Fast Interrupt 1 Vector Number
 set     INTC_FIM1_FAST_INTERRUPT_1_0 BIT0
 set     INTC_FIM1_FAST_INTERRUPT_1_1 BIT1
 set     INTC_FIM1_FAST_INTERRUPT_1_2 BIT2
 set     INTC_FIM1_FAST_INTERRUPT_1_3 BIT3
 set     INTC_FIM1_FAST_INTERRUPT_1_4 BIT4
 set     INTC_FIM1_FAST_INTERRUPT_1_5 BIT5
 set     INTC_FIM1_FAST_INTERRUPT_1_6 BIT6

 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Lower 16 bits of vector address for fast interrupt 1
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_0 BIT0
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_1 BIT1
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_2 BIT2
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_3 BIT3
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_4 BIT4
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_5 BIT5
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_6 BIT6
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_7 BIT7
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_8 BIT8
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_9 BIT9
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_10 BIT10
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_11 BIT11
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_12 BIT12
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_13 BIT13
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_14 BIT14
 set     INTC_FIVAL1_FI_1_VECTOR_ADDRESS_LOW_15 BIT15

 set     INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_0 BIT0
 set     INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_1 BIT1
 set     INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_2 BIT2
 set     INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_3 BIT3
 set     INTC_FIVAH1_FI_1_VECTOR_ADDRESS_HIGH_4 BIT4

 set     INTC_IRQP0_PENDING          (BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pending IRQs
;;     0b0 ==> IRQ pending for this vector number
;;     0b1 ==> No IRQ pending for this vector number
 set     INTC_IRQP0_PENDING_0        BIT1
 set     INTC_IRQP0_PENDING_1        BIT2
 set     INTC_IRQP0_PENDING_2        BIT3
 set     INTC_IRQP0_PENDING_3        BIT4
 set     INTC_IRQP0_PENDING_4        BIT5
 set     INTC_IRQP0_PENDING_5        BIT6
 set     INTC_IRQP0_PENDING_6        BIT7
 set     INTC_IRQP0_PENDING_7        BIT8
 set     INTC_IRQP0_PENDING_8        BIT9
 set     INTC_IRQP0_PENDING_9        BIT10
 set     INTC_IRQP0_PENDING_10       BIT11
 set     INTC_IRQP0_PENDING_11       BIT12
 set     INTC_IRQP0_PENDING_12       BIT13
 set     INTC_IRQP0_PENDING_13       BIT14
 set     INTC_IRQP0_PENDING_14       BIT15

 set     INTC_IRQP1_PENDING          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pending IRQs
;;     0b0 ==> IRQ pending for this vector number
;;     0b1 ==> No IRQ pending for this vector number
 set     INTC_IRQP1_PENDING_0        BIT0
 set     INTC_IRQP1_PENDING_1        BIT1
 set     INTC_IRQP1_PENDING_2        BIT2
 set     INTC_IRQP1_PENDING_3        BIT3
 set     INTC_IRQP1_PENDING_4        BIT4
 set     INTC_IRQP1_PENDING_5        BIT5
 set     INTC_IRQP1_PENDING_6        BIT6
 set     INTC_IRQP1_PENDING_7        BIT7
 set     INTC_IRQP1_PENDING_8        BIT8
 set     INTC_IRQP1_PENDING_9        BIT9
 set     INTC_IRQP1_PENDING_10       BIT10
 set     INTC_IRQP1_PENDING_11       BIT11
 set     INTC_IRQP1_PENDING_12       BIT12
 set     INTC_IRQP1_PENDING_13       BIT13
 set     INTC_IRQP1_PENDING_14       BIT14
 set     INTC_IRQP1_PENDING_15       BIT15

 set     INTC_IRQP2_PENDING          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pending IRQs
;;     0b0 ==> IRQ pending for this vector number
;;     0b1 ==> No IRQ pending for this vector number
 set     INTC_IRQP2_PENDING_0        BIT0
 set     INTC_IRQP2_PENDING_1        BIT1
 set     INTC_IRQP2_PENDING_2        BIT2
 set     INTC_IRQP2_PENDING_3        BIT3
 set     INTC_IRQP2_PENDING_4        BIT4
 set     INTC_IRQP2_PENDING_5        BIT5
 set     INTC_IRQP2_PENDING_6        BIT6
 set     INTC_IRQP2_PENDING_7        BIT7
 set     INTC_IRQP2_PENDING_8        BIT8
 set     INTC_IRQP2_PENDING_9        BIT9
 set     INTC_IRQP2_PENDING_10       BIT10
 set     INTC_IRQP2_PENDING_11       BIT11
 set     INTC_IRQP2_PENDING_12       BIT12
 set     INTC_IRQP2_PENDING_13       BIT13
 set     INTC_IRQP2_PENDING_14       BIT14
 set     INTC_IRQP2_PENDING_15       BIT15

 set     INTC_IRQP3_PENDING          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pending IRQs
;;     0b0 ==> IRQ pending for this vector number
;;     0b1 ==> No IRQ pending for this vector number
 set     INTC_IRQP3_PENDING_0        BIT0
 set     INTC_IRQP3_PENDING_1        BIT1
 set     INTC_IRQP3_PENDING_2        BIT2
 set     INTC_IRQP3_PENDING_3        BIT3
 set     INTC_IRQP3_PENDING_4        BIT4
 set     INTC_IRQP3_PENDING_5        BIT5
 set     INTC_IRQP3_PENDING_6        BIT6
 set     INTC_IRQP3_PENDING_7        BIT7
 set     INTC_IRQP3_PENDING_8        BIT8
 set     INTC_IRQP3_PENDING_9        BIT9
 set     INTC_IRQP3_PENDING_10       BIT10
 set     INTC_IRQP3_PENDING_11       BIT11
 set     INTC_IRQP3_PENDING_12       BIT12
 set     INTC_IRQP3_PENDING_13       BIT13
 set     INTC_IRQP3_PENDING_14       BIT14
 set     INTC_IRQP3_PENDING_15       BIT15

 set     INTC_IRQP4_PENDING          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pending IRQs
;;     0b0 ==> IRQ pending for this vector number
;;     0b1 ==> No IRQ pending for this vector number
 set     INTC_IRQP4_PENDING_0        BIT0
 set     INTC_IRQP4_PENDING_1        BIT1
 set     INTC_IRQP4_PENDING_2        BIT2
 set     INTC_IRQP4_PENDING_3        BIT3
 set     INTC_IRQP4_PENDING_4        BIT4
 set     INTC_IRQP4_PENDING_5        BIT5
 set     INTC_IRQP4_PENDING_6        BIT6
 set     INTC_IRQP4_PENDING_7        BIT7
 set     INTC_IRQP4_PENDING_8        BIT8
 set     INTC_IRQP4_PENDING_9        BIT9
 set     INTC_IRQP4_PENDING_10       BIT10
 set     INTC_IRQP4_PENDING_11       BIT11
 set     INTC_IRQP4_PENDING_12       BIT12
 set     INTC_IRQP4_PENDING_13       BIT13
 set     INTC_IRQP4_PENDING_14       BIT14
 set     INTC_IRQP4_PENDING_15       BIT15

 set     INTC_IRQP5_PENDING          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Pending IRQs
;;     0b0 ==> IRQ pending for this vector number
;;     0b1 ==> No IRQ pending for this vector number
 set     INTC_IRQP5_PENDING_0        BIT0
 set     INTC_IRQP5_PENDING_1        BIT1
 set     INTC_IRQP5_PENDING_2        BIT2
 set     INTC_IRQP5_PENDING_3        BIT3
 set     INTC_IRQP5_PENDING_4        BIT4
 set     INTC_IRQP5_PENDING_5        BIT5
 set     INTC_IRQP5_PENDING_6        BIT6
 set     INTC_IRQP5_PENDING_7        BIT7
 set     INTC_IRQP5_PENDING_8        BIT8
 set     INTC_IRQP5_PENDING_9        BIT9
 set     INTC_IRQP5_PENDING_10       BIT10
 set     INTC_IRQP5_PENDING_11       BIT11
 set     INTC_IRQP5_PENDING_12       BIT12
 set     INTC_IRQP5_PENDING_13       BIT13
 set     INTC_IRQP5_PENDING_14       BIT14
 set     INTC_IRQP5_PENDING_15       BIT15

 set     INTC_IRQP6_PENDING          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13)
;;   Pending IRQs
;;     0b0 ==> IRQ pending for this vector number
;;     0b1 ==> No IRQ pending for this vector number
 set     INTC_IRQP6_PENDING_0        BIT0
 set     INTC_IRQP6_PENDING_1        BIT1
 set     INTC_IRQP6_PENDING_2        BIT2
 set     INTC_IRQP6_PENDING_3        BIT3
 set     INTC_IRQP6_PENDING_4        BIT4
 set     INTC_IRQP6_PENDING_5        BIT5
 set     INTC_IRQP6_PENDING_6        BIT6
 set     INTC_IRQP6_PENDING_7        BIT7
 set     INTC_IRQP6_PENDING_8        BIT8
 set     INTC_IRQP6_PENDING_9        BIT9
 set     INTC_IRQP6_PENDING_10       BIT10
 set     INTC_IRQP6_PENDING_11       BIT11
 set     INTC_IRQP6_PENDING_12       BIT12
 set     INTC_IRQP6_PENDING_13       BIT13

 set     INTC_CTRL_INT_DIS           BIT5
;;   Interrupt disable
;;     0b0 ==> Normal operation. (default)
;;     0b1 ==> All interrupts disabled.

 set     INTC_CTRL_VAB               (BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12)
;;   Vector number
 set     INTC_CTRL_VAB_0             BIT6
 set     INTC_CTRL_VAB_1             BIT7
 set     INTC_CTRL_VAB_2             BIT8
 set     INTC_CTRL_VAB_3             BIT9
 set     INTC_CTRL_VAB_4             BIT10
 set     INTC_CTRL_VAB_5             BIT11
 set     INTC_CTRL_VAB_6             BIT12

 set     INTC_CTRL_IPIC              (BIT13|BIT14)
;;   Interrupt Priority Level
;;     0b00 ==> Required nested exception priority levels are 0, 1, 2, or 3.
;;     0b01 ==> Required nested exception priority levels are 1, 2, or 3.
;;     0b10 ==> Required nested exception priority levels are 2 or3.
;;     0b11 ==> Required nested exception priority level is 3.
 set     INTC_CTRL_IPIC_0            BIT13
 set     INTC_CTRL_IPIC_1            BIT14

 set     INTC_CTRL_INT               BIT15
;;   Interrupt
;;     0b0 ==> No interrupt is being sent to the core.
;;     0b1 ==> An interrupt is being sent to the core.

 set     MCM_PLASC_ASC               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Each bit in the ASC field indicates if there is a corresponding connection to the AXBS slave input port. For this device, this field always read 0x0F.
;;     0b0 ==> A bus slave connection to AXBS input port n is absent
;;     0b1 ==> A bus slave connection to AXBS input port n is present
 set     MCM_PLASC_ASC_0             BIT0
 set     MCM_PLASC_ASC_1             BIT1
 set     MCM_PLASC_ASC_2             BIT2
 set     MCM_PLASC_ASC_3             BIT3
 set     MCM_PLASC_ASC_4             BIT4
 set     MCM_PLASC_ASC_5             BIT5
 set     MCM_PLASC_ASC_6             BIT6
 set     MCM_PLASC_ASC_7             BIT7

 set     MCM_PLASC_DP64              BIT15
;;   Indicates if the datapath is 32 or 64 bits wide
;;     0b0 ==> Datapath width is 32 bits
;;     0b1 ==> Datapath width is 64 bits

 set     MCM_PLAMC_AMC               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Each bit in the AMC field indicates if there is a corresponding connection to the AXBS master input port. For this device, this field always reads 0x0F.
;;     0b0 ==> A bus master connection to AXBS input port n is absent
;;     0b1 ==> A bus master connection to AXBS input port n is present
 set     MCM_PLAMC_AMC_0             BIT0
 set     MCM_PLAMC_AMC_1             BIT1
 set     MCM_PLAMC_AMC_2             BIT2
 set     MCM_PLAMC_AMC_3             BIT3
 set     MCM_PLAMC_AMC_4             BIT4
 set     MCM_PLAMC_AMC_5             BIT5
 set     MCM_PLAMC_AMC_6             BIT6
 set     MCM_PLAMC_AMC_7             BIT7

 set     MCM_CPCR_INSDIS             BIT16
;;   Disable instructions supported only by DSP56800EX core
;;     0b0 ==> BFSC and 32-bit multiply and MAC instructions enabled
;;     0b1 ==> BFSC and 32-bit multiply and MAC instructions disabled

 set     MCM_CPCR_RCDIS              BIT17
;;   Disable core reverse carry
;;     0b0 ==> Core reverse carry enabled
;;     0b1 ==> Core reverse carry disabled

 set     MCM_CPCR_SRDIS              BIT18
;;   Disable core new shadow region
;;     0b0 ==> Core new shadow region enabled
;;     0b1 ==> Core new shadow region disabled

 set     MCM_CPCR_IBDIS              BIT19
;;   Disable core instruction buffer
;;     0b0 ==> Core longword instruction buffer enabled
;;     0b1 ==> Core longword instruction buffer disabled

 set     MCM_CPCR_FCSDIS             BIT20
;;   Disable Flash Memory Controller stall
;;     0b0 ==> Stall logic is enabled. While a flash memory command is executing, a flash memory access can occur without causing a bus error. The flash memory command completes execution, and then the flash memory access occurs.
;;     0b1 ==> Stall logic is disabled. While a flash memory command is executing, an attempted flash memory access causes a bus error.

 set     MCM_CFADR_ADDR              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Indicates the faulting address of the last core access terminated with an error response.
 set     MCM_CFADR_ADDR_0            BIT0
 set     MCM_CFADR_ADDR_1            BIT1
 set     MCM_CFADR_ADDR_2            BIT2
 set     MCM_CFADR_ADDR_3            BIT3
 set     MCM_CFADR_ADDR_4            BIT4
 set     MCM_CFADR_ADDR_5            BIT5
 set     MCM_CFADR_ADDR_6            BIT6
 set     MCM_CFADR_ADDR_7            BIT7
 set     MCM_CFADR_ADDR_8            BIT8
 set     MCM_CFADR_ADDR_9            BIT9
 set     MCM_CFADR_ADDR_10           BIT10
 set     MCM_CFADR_ADDR_11           BIT11
 set     MCM_CFADR_ADDR_12           BIT12
 set     MCM_CFADR_ADDR_13           BIT13
 set     MCM_CFADR_ADDR_14           BIT14
 set     MCM_CFADR_ADDR_15           BIT15
 set     MCM_CFADR_ADDR_16           BIT16
 set     MCM_CFADR_ADDR_17           BIT17
 set     MCM_CFADR_ADDR_18           BIT18
 set     MCM_CFADR_ADDR_19           BIT19
 set     MCM_CFADR_ADDR_20           BIT20
 set     MCM_CFADR_ADDR_21           BIT21
 set     MCM_CFADR_ADDR_22           BIT22
 set     MCM_CFADR_ADDR_23           BIT23
 set     MCM_CFADR_ADDR_24           BIT24
 set     MCM_CFADR_ADDR_25           BIT25
 set     MCM_CFADR_ADDR_26           BIT26
 set     MCM_CFADR_ADDR_27           BIT27
 set     MCM_CFADR_ADDR_28           BIT28
 set     MCM_CFADR_ADDR_29           BIT29
 set     MCM_CFADR_ADDR_30           BIT30
 set     MCM_CFADR_ADDR_31           BIT31

 set     MCM_CFATR_TYPE              BIT0
;;   Type of last faulted core access
;;     0b0 ==> Instruction
;;     0b1 ==> Data

 set     MCM_CFATR_BUFFER            BIT2
;;   Indicates if last faulted core access was bufferable
;;     0b0 ==> Non-bufferable
;;     0b1 ==> Bufferable

 set     MCM_CFATR_SIZE              (BIT4|BIT5|BIT6)
;;   Size of last faulted core access
;;     0b000 ==> 8-bit
;;     0b001 ==> 16-bit
;;     0b010 ==> 32-bit
 set     MCM_CFATR_SIZE_0            BIT4
 set     MCM_CFATR_SIZE_1            BIT5
 set     MCM_CFATR_SIZE_2            BIT6

 set     MCM_CFATR_DIR               BIT7
;;   Direction of last faulted core access
;;     0b0 ==> Core read access
;;     0b1 ==> Core write access

 set     MCM_CFLOC_LOC               (BIT6|BIT7)
;;   Location of last captured fault
;;     0b00 ==> Error occurred on M0 (instruction bus)
;;     0b01 ==> Error occured on M1 (operand A bus)
;;     0b10 ==> Error occured on M2 (operand B bus)
;;     0b11 ==> Reserved
 set     MCM_CFLOC_LOC_0             BIT6
 set     MCM_CFLOC_LOC_1             BIT7

 set     MCM_CFIER_ECFEI             BIT7
;;   Enable core fault error interrupt
;;     0b0 ==> Do not generate an error interrupt on a faulted system bus cycle
;;     0b1 ==> Generate an error interrupt to the interrupt controller on a faulted system bus cycle

 set     MCM_CFISR_CFEI              BIT7
;;   Core fault error interrupt flag
;;     0b0 ==> No bus error
;;     0b1 ==> A bus error has occurred. The faulting address, attributes (and possibly write data) are captured in the CFADR, CFATR, and CFDTR registers. The error interrupt is enabled only if CFIER[ECFEI] is set.

 set     MCM_CFDTR_DATA              (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23|BIT24|BIT25|BIT26|BIT27|BIT28|BIT29|BIT30|BIT31)
;;   Contains write data associated with the faulting access of the last internal bus write access. The data value is taken directly from the write data bus. Read data is not captured.
 set     MCM_CFDTR_DATA_0            BIT0
 set     MCM_CFDTR_DATA_1            BIT1
 set     MCM_CFDTR_DATA_2            BIT2
 set     MCM_CFDTR_DATA_3            BIT3
 set     MCM_CFDTR_DATA_4            BIT4
 set     MCM_CFDTR_DATA_5            BIT5
 set     MCM_CFDTR_DATA_6            BIT6
 set     MCM_CFDTR_DATA_7            BIT7
 set     MCM_CFDTR_DATA_8            BIT8
 set     MCM_CFDTR_DATA_9            BIT9
 set     MCM_CFDTR_DATA_10           BIT10
 set     MCM_CFDTR_DATA_11           BIT11
 set     MCM_CFDTR_DATA_12           BIT12
 set     MCM_CFDTR_DATA_13           BIT13
 set     MCM_CFDTR_DATA_14           BIT14
 set     MCM_CFDTR_DATA_15           BIT15
 set     MCM_CFDTR_DATA_16           BIT16
 set     MCM_CFDTR_DATA_17           BIT17
 set     MCM_CFDTR_DATA_18           BIT18
 set     MCM_CFDTR_DATA_19           BIT19
 set     MCM_CFDTR_DATA_20           BIT20
 set     MCM_CFDTR_DATA_21           BIT21
 set     MCM_CFDTR_DATA_22           BIT22
 set     MCM_CFDTR_DATA_23           BIT23
 set     MCM_CFDTR_DATA_24           BIT24
 set     MCM_CFDTR_DATA_25           BIT25
 set     MCM_CFDTR_DATA_26           BIT26
 set     MCM_CFDTR_DATA_27           BIT27
 set     MCM_CFDTR_DATA_28           BIT28
 set     MCM_CFDTR_DATA_29           BIT29
 set     MCM_CFDTR_DATA_30           BIT30
 set     MCM_CFDTR_DATA_31           BIT31

 set     MCM_RPCR_RPE                BIT0
;;   Resource Protection Enable
;;     0b0 ==> Resource protection disabled
;;     0b1 ==> Resource protection enabled

 set     MCM_RPCR_RL                 BIT1
;;   Register Lock
;;     0b0 ==> RP register values may be changed
;;     0b1 ==> RP registers are locked and may not be changed until after a system reset

 set     MCM_UFLASHBAR_FBA           (BIT12|BIT13|BIT14|BIT15|BIT16|BIT17)
;;   Flash Base Address for User Region
 set     MCM_UFLASHBAR_FBA_0         BIT12
 set     MCM_UFLASHBAR_FBA_1         BIT13
 set     MCM_UFLASHBAR_FBA_2         BIT14
 set     MCM_UFLASHBAR_FBA_3         BIT15
 set     MCM_UFLASHBAR_FBA_4         BIT16
 set     MCM_UFLASHBAR_FBA_5         BIT17

 set     MCM_UPRAMBAR_RBA            (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14)
;;   Program RAM Base Address for User Region
 set     MCM_UPRAMBAR_RBA_0          BIT8
 set     MCM_UPRAMBAR_RBA_1          BIT9
 set     MCM_UPRAMBAR_RBA_2          BIT10
 set     MCM_UPRAMBAR_RBA_3          BIT11
 set     MCM_UPRAMBAR_RBA_4          BIT12
 set     MCM_UPRAMBAR_RBA_5          BIT13
 set     MCM_UPRAMBAR_RBA_6          BIT14

 set     MCM_SRPOSP_SRPOSP           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20|BIT21|BIT22|BIT23)
;;   Resource protection "other" SP
 set     MCM_SRPOSP_SRPOSP_0         BIT0
 set     MCM_SRPOSP_SRPOSP_1         BIT1
 set     MCM_SRPOSP_SRPOSP_2         BIT2
 set     MCM_SRPOSP_SRPOSP_3         BIT3
 set     MCM_SRPOSP_SRPOSP_4         BIT4
 set     MCM_SRPOSP_SRPOSP_5         BIT5
 set     MCM_SRPOSP_SRPOSP_6         BIT6
 set     MCM_SRPOSP_SRPOSP_7         BIT7
 set     MCM_SRPOSP_SRPOSP_8         BIT8
 set     MCM_SRPOSP_SRPOSP_9         BIT9
 set     MCM_SRPOSP_SRPOSP_10        BIT10
 set     MCM_SRPOSP_SRPOSP_11        BIT11
 set     MCM_SRPOSP_SRPOSP_12        BIT12
 set     MCM_SRPOSP_SRPOSP_13        BIT13
 set     MCM_SRPOSP_SRPOSP_14        BIT14
 set     MCM_SRPOSP_SRPOSP_15        BIT15
 set     MCM_SRPOSP_SRPOSP_16        BIT16
 set     MCM_SRPOSP_SRPOSP_17        BIT17
 set     MCM_SRPOSP_SRPOSP_18        BIT18
 set     MCM_SRPOSP_SRPOSP_19        BIT19
 set     MCM_SRPOSP_SRPOSP_20        BIT20
 set     MCM_SRPOSP_SRPOSP_21        BIT21
 set     MCM_SRPOSP_SRPOSP_22        BIT22
 set     MCM_SRPOSP_SRPOSP_23        BIT23

 set     MCM_SRPIPC_SRPIFPC          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20)
;;   Resource Protection Illegal Faulting PC
 set     MCM_SRPIPC_SRPIFPC_0        BIT0
 set     MCM_SRPIPC_SRPIFPC_1        BIT1
 set     MCM_SRPIPC_SRPIFPC_2        BIT2
 set     MCM_SRPIPC_SRPIFPC_3        BIT3
 set     MCM_SRPIPC_SRPIFPC_4        BIT4
 set     MCM_SRPIPC_SRPIFPC_5        BIT5
 set     MCM_SRPIPC_SRPIFPC_6        BIT6
 set     MCM_SRPIPC_SRPIFPC_7        BIT7
 set     MCM_SRPIPC_SRPIFPC_8        BIT8
 set     MCM_SRPIPC_SRPIFPC_9        BIT9
 set     MCM_SRPIPC_SRPIFPC_10       BIT10
 set     MCM_SRPIPC_SRPIFPC_11       BIT11
 set     MCM_SRPIPC_SRPIFPC_12       BIT12
 set     MCM_SRPIPC_SRPIFPC_13       BIT13
 set     MCM_SRPIPC_SRPIFPC_14       BIT14
 set     MCM_SRPIPC_SRPIFPC_15       BIT15
 set     MCM_SRPIPC_SRPIFPC_16       BIT16
 set     MCM_SRPIPC_SRPIFPC_17       BIT17
 set     MCM_SRPIPC_SRPIFPC_18       BIT18
 set     MCM_SRPIPC_SRPIFPC_19       BIT19
 set     MCM_SRPIPC_SRPIFPC_20       BIT20

 set     MCM_SRPIPC_SRPIFV           BIT31
;;   Resource Protection Illegal Fault Valid

 set     MCM_SRPMPC_SRPMFPC          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15|BIT16|BIT17|BIT18|BIT19|BIT20)
;;   Resource Protection Misaligned Faulting PC
 set     MCM_SRPMPC_SRPMFPC_0        BIT0
 set     MCM_SRPMPC_SRPMFPC_1        BIT1
 set     MCM_SRPMPC_SRPMFPC_2        BIT2
 set     MCM_SRPMPC_SRPMFPC_3        BIT3
 set     MCM_SRPMPC_SRPMFPC_4        BIT4
 set     MCM_SRPMPC_SRPMFPC_5        BIT5
 set     MCM_SRPMPC_SRPMFPC_6        BIT6
 set     MCM_SRPMPC_SRPMFPC_7        BIT7
 set     MCM_SRPMPC_SRPMFPC_8        BIT8
 set     MCM_SRPMPC_SRPMFPC_9        BIT9
 set     MCM_SRPMPC_SRPMFPC_10       BIT10
 set     MCM_SRPMPC_SRPMFPC_11       BIT11
 set     MCM_SRPMPC_SRPMFPC_12       BIT12
 set     MCM_SRPMPC_SRPMFPC_13       BIT13
 set     MCM_SRPMPC_SRPMFPC_14       BIT14
 set     MCM_SRPMPC_SRPMFPC_15       BIT15
 set     MCM_SRPMPC_SRPMFPC_16       BIT16
 set     MCM_SRPMPC_SRPMFPC_17       BIT17
 set     MCM_SRPMPC_SRPMFPC_18       BIT18
 set     MCM_SRPMPC_SRPMFPC_19       BIT19
 set     MCM_SRPMPC_SRPMFPC_20       BIT20

 set     MCM_SRPMPC_SRPMFV           BIT31
;;   Resource Protection Misaligned Fault Valid

 set     OCCS_CTRL_ZSRC              BIT0
;;   CLOCK Source
;;     0b0 ==> MSTR_OSC
;;     0b1 ==> PLL output divided by 2

 set     OCCS_CTRL_PRECS             (BIT2|BIT3)
;;   Prescaler Clock Select
;;     0b00 ==> 8 MHz relaxation oscillator selected (reset value)
;;     0b01 ==> External reference selected
;;     0b10 ==> 200 kHz relaxation oscillator selected
;;     0b11 ==> Reserved
 set     OCCS_CTRL_PRECS_0           BIT2
 set     OCCS_CTRL_PRECS_1           BIT3

 set     OCCS_CTRL_PLLPD             BIT4
;;   PLL Power Down
;;     0b0 ==> PLL enabled
;;     0b1 ==> PLL powered down

 set     OCCS_CTRL_LCKON             BIT7
;;   Lock Detector On
;;     0b0 ==> Lock detector disabled
;;     0b1 ==> Lock detector enabled

 set     OCCS_CTRL_LOCIE             BIT11
;;   Loss of Reference Clock Interrupt Enable
;;     0b0 ==> Interrupt disabled.
;;     0b1 ==> Interrupt enabled.

 set     OCCS_CTRL_PLLIE0            (BIT12|BIT13)
;;   PLL Interrupt Enable 0
;;     0b00 ==> Disable interrupt.
;;     0b01 ==> Enable interrupt on any rising edge of LCK0.
;;     0b10 ==> Enable interrupt on falling edge of LCK0.
;;     0b11 ==> Enable interrupt on any edge change of LCK0.
 set     OCCS_CTRL_PLLIE0_0          BIT12
 set     OCCS_CTRL_PLLIE0_1          BIT13

 set     OCCS_CTRL_PLLIE1            (BIT14|BIT15)
;;   PLL Interrupt Enable 1
;;     0b00 ==> Disable interrupt.
;;     0b01 ==> Enable interrupt on any rising edge of LCK1.
;;     0b10 ==> Enable interrupt on falling edge of LCK1.
;;     0b11 ==> Enable interrupt on any edge change of LCK1.
 set     OCCS_CTRL_PLLIE1_0          BIT14
 set     OCCS_CTRL_PLLIE1_1          BIT15

 set     OCCS_DIVBY_PLLDB            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   PLL Divide By
 set     OCCS_DIVBY_PLLDB_0          BIT0
 set     OCCS_DIVBY_PLLDB_1          BIT1
 set     OCCS_DIVBY_PLLDB_2          BIT2
 set     OCCS_DIVBY_PLLDB_3          BIT3
 set     OCCS_DIVBY_PLLDB_4          BIT4
 set     OCCS_DIVBY_PLLDB_5          BIT5

 set     OCCS_DIVBY_PWM_DIV2         BIT6
;;     0b0 ==> Raw PLL output selected as PWM_2X clock
;;     0b1 ==> PLL DIV2 Clock Selected as PWM 2X clock

 set     OCCS_DIVBY_COD              (BIT8|BIT9|BIT10|BIT11)
;;   Clock Output Divide or Postscaler
;;     0b0000 ==> Divide clock output by 1.
;;     0b0001 ==> Divide clock output by 2.
;;     0b0010 ==> Divide clock output by 4.
;;     0b0011 ==> Divide clock output by 8.
;;     0b0100 ==> Divide clock output by 16.
;;     0b0101 ==> Divide clock output by 32.
;;     0b0110 ==> Divide clock output by 64.
;;     0b0111 ==> Divide clock output by 128.
;;     0b1xxx ==> Divide clock output by 256.
 set     OCCS_DIVBY_COD_0            BIT8
 set     OCCS_DIVBY_COD_1            BIT9
 set     OCCS_DIVBY_COD_2            BIT10
 set     OCCS_DIVBY_COD_3            BIT11

 set     OCCS_DIVBY_LORTP            (BIT12|BIT13|BIT14|BIT15)
;;   Loss of Reference Clock Trip Point
 set     OCCS_DIVBY_LORTP_0          BIT12
 set     OCCS_DIVBY_LORTP_1          BIT13
 set     OCCS_DIVBY_LORTP_2          BIT14
 set     OCCS_DIVBY_LORTP_3          BIT15

 set     OCCS_STAT_ZSRCS             (BIT0|BIT1)
;;   CLOCK Source Status
;;     0b00 ==> MSTR_OSC
;;     0b01 ==> PLL output divided by 2
;;     0b1x ==> Synchronization in progress
 set     OCCS_STAT_ZSRCS_0           BIT0
 set     OCCS_STAT_ZSRCS_1           BIT1

 set     OCCS_STAT_PLLPDN            BIT4
;;   PLL Power Down
;;     0b0 ==> PLL not powered down.
;;     0b1 ==> PLL powered down.

 set     OCCS_STAT_LCK0              BIT5
;;   PLL Lock 0 Status
;;     0b0 ==> PLL is unlocked.
;;     0b1 ==> PLL is locked (coarse).

 set     OCCS_STAT_LCK1              BIT6
;;   PLL Lock 1 Status
;;     0b0 ==> PLL is unlocked.
;;     0b1 ==> PLL is locked (fine).

 set     OCCS_STAT_OSC_OK            BIT7
;;   OSC_OK Indicator from XOSC
;;     0b0 ==> Oscillator clock is still not stable, or XOSC is disabled.
;;     0b1 ==> XOSC OK indicator after crystal oscillator startup.

 set     OCCS_STAT_MON_FAILURE       BIT8
;;   XOSC Clock Monitor Failure Indicator
;;     0b0 ==> No clock failure, or clock monitor is disabled.
;;     0b1 ==> Clock failure detected on XOSC reference clock when clock monitor is enabled.

 set     OCCS_STAT_LOCI              BIT13
;;   Loss of Reference Clock Interrupt
;;     0b0 ==> Oscillator clock normal.
;;     0b1 ==> Loss of oscillator clock detected.

 set     OCCS_STAT_LOLI0             BIT14
;;   PLL Lock or Loss of Lock Interrupt 0
;;     0b0 ==> No lock or loss of lock event has occurred.
;;     0b1 ==> PLL lock status based on PLLIE0.

 set     OCCS_STAT_LOLI1             BIT15
;;   PLL Lock or Loss of Lock Interrupt 1
;;     0b0 ==> No lock or loss of lock event has occurred.
;;     0b1 ==> PLL lock status based on PLLIE1.

 set     OCCS_OSCTL1_FREQ_TRIM8M     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9)
;;   8 MHz Relaxation Oscillator Frequency Trim
 set     OCCS_OSCTL1_FREQ_TRIM8M_0   BIT0
 set     OCCS_OSCTL1_FREQ_TRIM8M_1   BIT1
 set     OCCS_OSCTL1_FREQ_TRIM8M_2   BIT2
 set     OCCS_OSCTL1_FREQ_TRIM8M_3   BIT3
 set     OCCS_OSCTL1_FREQ_TRIM8M_4   BIT4
 set     OCCS_OSCTL1_FREQ_TRIM8M_5   BIT5
 set     OCCS_OSCTL1_FREQ_TRIM8M_6   BIT6
 set     OCCS_OSCTL1_FREQ_TRIM8M_7   BIT7
 set     OCCS_OSCTL1_FREQ_TRIM8M_8   BIT8
 set     OCCS_OSCTL1_FREQ_TRIM8M_9   BIT9

 set     OCCS_OSCTL1_EXT_SEL         BIT10
;;   External Clock In Select
;;     0b0 ==> Use the output of the crystal oscillator as the external clock input.
;;     0b1 ==> Use CLKIN as the external clock input.

 set     OCCS_OSCTL1_CLK_MODE        BIT12
;;   Crystal Oscillator Clock Mode
;;     0b0 ==> Crystal oscillator enabled.
;;     0b1 ==> External clock bypass mode. This enables the crystal oscillator's external clock bypass mode and allows an external clock source on the EXTAL input of the oscillator to propagate directly to the oscillator's clock output.

 set     OCCS_OSCTL1_COHL            BIT13
;;   Crystal Oscillator High/Low Power Level
;;     0b0 ==> High power mode.
;;     0b1 ==> Low power mode.

 set     OCCS_OSCTL1_ROSB            BIT14
;;   8 MHz Relaxation Oscillator Standby
;;     0b0 ==> Normal mode. The relaxation oscillator output frequency is 8 MHz.
;;     0b1 ==> Standby mode. The relaxation oscillator output frequency is reduced to 400 kHz (+/-50%). The PLL should be disabled in this mode and MSTR_OSC should be selected as the output clock.

 set     OCCS_OSCTL1_ROPD            BIT15
;;   8 MHz Relaxation Oscillator Power Down
;;     0b0 ==> Relaxation oscillator enabled.
;;     0b1 ==> Relaxation oscillator powered down.

 set     OCCS_OSCTL2_FREQ_TRIM200K   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8)
;;   200 kHz Internal RC Oscillator Frequency Trim
 set     OCCS_OSCTL2_FREQ_TRIM200K_0 BIT0
 set     OCCS_OSCTL2_FREQ_TRIM200K_1 BIT1
 set     OCCS_OSCTL2_FREQ_TRIM200K_2 BIT2
 set     OCCS_OSCTL2_FREQ_TRIM200K_3 BIT3
 set     OCCS_OSCTL2_FREQ_TRIM200K_4 BIT4
 set     OCCS_OSCTL2_FREQ_TRIM200K_5 BIT5
 set     OCCS_OSCTL2_FREQ_TRIM200K_6 BIT6
 set     OCCS_OSCTL2_FREQ_TRIM200K_7 BIT7
 set     OCCS_OSCTL2_FREQ_TRIM200K_8 BIT8

 set     OCCS_OSCTL2_MON_ENABLE      BIT9
;;   XOSC Clock Monitor Enable Control

 set     OCCS_OSCTL2_TEMP_TRIM8M     (BIT10|BIT11|BIT12|BIT13)
;;   8 MHz Internal Relaxation Oscillator Temperature Trim
 set     OCCS_OSCTL2_TEMP_TRIM8M_0   BIT10
 set     OCCS_OSCTL2_TEMP_TRIM8M_1   BIT11
 set     OCCS_OSCTL2_TEMP_TRIM8M_2   BIT12
 set     OCCS_OSCTL2_TEMP_TRIM8M_3   BIT13

 set     OCCS_OSCTL2_COPD            BIT14
;;   Crystal Oscillator Power Down
;;     0b0 ==> Crystal oscillator enabled.
;;     0b1 ==> Crystal oscillator powered down.

 set     OCCS_OSCTL2_ROPD200K        BIT15
;;   200 kHz RC Oscillator Power Down

 set     OCCS_CLKCHKR_REF_CNT        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6)
;;   Reference Count
 set     OCCS_CLKCHKR_REF_CNT_0      BIT0
 set     OCCS_CLKCHKR_REF_CNT_1      BIT1
 set     OCCS_CLKCHKR_REF_CNT_2      BIT2
 set     OCCS_CLKCHKR_REF_CNT_3      BIT3
 set     OCCS_CLKCHKR_REF_CNT_4      BIT4
 set     OCCS_CLKCHKR_REF_CNT_5      BIT5
 set     OCCS_CLKCHKR_REF_CNT_6      BIT6

 set     OCCS_CLKCHKR_CHK_ENA        BIT15
;;   Check Enable
;;     0b0 ==> Writing a low while the clock checking operation is in progress stops the check in its current state. Reading a low after a check has been started indicates that the check operation is complete and the final values are valid in the REF_CNT and TARGET_CNT fields.
;;     0b1 ==> Writing a one clears the REF_CNT and TARGET_CNT fields and starts the clock checking function. The CLK_ENA bit remains high while the operation is in progress.

 set     OCCS_CLKCHKT_TARGET_CNT     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   CLKCHKT Target Count
 set     OCCS_CLKCHKT_TARGET_CNT_0   BIT0
 set     OCCS_CLKCHKT_TARGET_CNT_1   BIT1
 set     OCCS_CLKCHKT_TARGET_CNT_2   BIT2
 set     OCCS_CLKCHKT_TARGET_CNT_3   BIT3
 set     OCCS_CLKCHKT_TARGET_CNT_4   BIT4
 set     OCCS_CLKCHKT_TARGET_CNT_5   BIT5
 set     OCCS_CLKCHKT_TARGET_CNT_6   BIT6
 set     OCCS_CLKCHKT_TARGET_CNT_7   BIT7
 set     OCCS_CLKCHKT_TARGET_CNT_8   BIT8
 set     OCCS_CLKCHKT_TARGET_CNT_9   BIT9
 set     OCCS_CLKCHKT_TARGET_CNT_10  BIT10

 set     OCCS_PROT_PLLEP             (BIT0|BIT1)
;;   PLL Enable Protection
;;     0b00 ==> Write protection off (default).
;;     0b01 ==> Write protection on.
;;     0b10 ==> Write protection off and locked until chip reset.
;;     0b11 ==> Write protection on and locked until chip reset.
 set     OCCS_PROT_PLLEP_0           BIT0
 set     OCCS_PROT_PLLEP_1           BIT1

 set     OCCS_PROT_OSCEP             (BIT2|BIT3)
;;   Oscillator Enable Protection
;;     0b00 ==> Write protection off (default).
;;     0b01 ==> Write protection on.
;;     0b10 ==> Write protection off and locked until chip reset.
;;     0b11 ==> Write protection on and locked until chip reset.
 set     OCCS_PROT_OSCEP_0           BIT2
 set     OCCS_PROT_OSCEP_1           BIT3

 set     OCCS_PROT_FRQEP             (BIT4|BIT5)
;;   Frequency Enable Protection
;;     0b00 ==> Write protection off (default).
;;     0b01 ==> Write protection on.
;;     0b10 ==> Write protection off and locked until chip reset.
;;     0b11 ==> Write protection on and locked until chip reset.
 set     OCCS_PROT_FRQEP_0           BIT4
 set     OCCS_PROT_FRQEP_1           BIT5

 set     PIT0_CTRL_CNT_EN            BIT0
;;   Count Enable
;;     0b0 ==> PIT counter reset (default).
;;     0b1 ==> PIT counter active.

 set     PIT0_CTRL_PRIE              BIT1
;;   PIT Roll-Over Interrupt Enable.
;;     0b0 ==> PIT roll-over interrupt disabled (default).
;;     0b1 ==> PIT roll-over interrupt enabled.

 set     PIT0_CTRL_PRF               BIT2
;;   PIT Roll-Over Flag.
;;     0b0 ==> PIT counter has not reached the modulo value. (default)
;;     0b1 ==> PIT counter has reached the modulo value.

 set     PIT0_CTRL_PRESCALER         (BIT3|BIT4|BIT5|BIT6)
;;     0b0000 ==> Clock
;;     0b0001 ==> Clock divided by 2
;;     0b0010 ==> Clock divided by 4
;;     0b0011 ==> Clock divided by 8
;;     0b0100 ==> Clock divided by 16
;;     0b0101 ==> Clock divided by 32
;;     0b0110 ==> Clock divided by 64
;;     0b0111 ==> Clock divided by 128
;;     0b1000 ==> Clock divided by 256
;;     0b1001 ==> Clock divided by 512
;;     0b1010 ==> Clock divided by 1024
;;     0b1011 ==> Clock divided by 2048
;;     0b1100 ==> Clock divided by 4096
;;     0b1101 ==> Clock divided by 8192
;;     0b1110 ==> Clock divided by 16384
;;     0b1111 ==> Clock divided by 32768
 set     PIT0_CTRL_PRESCALER_0       BIT3
 set     PIT0_CTRL_PRESCALER_1       BIT4
 set     PIT0_CTRL_PRESCALER_2       BIT5
 set     PIT0_CTRL_PRESCALER_3       BIT6

 set     PIT0_CTRL_CLKSEL            (BIT8|BIT9)
;;     0b00 ==> Selects IPBus clock
;;     0b01 ==> Selects alternate clock 1
;;     0b10 ==> Selects alternate clock 2
;;     0b11 ==> Selects alternate clock 3
 set     PIT0_CTRL_CLKSEL_0          BIT8
 set     PIT0_CTRL_CLKSEL_1          BIT9

 set     PIT0_CTRL_SLAVE             BIT15
;;     0b0 ==> CNT_EN from this PIT is used to control operation (default).
;;     0b1 ==> CNT_EN from master PIT is used to control operation.

 set     PIT0_MOD_MODULO_VALUE       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PIT0_MOD_MODULO_VALUE_0     BIT0
 set     PIT0_MOD_MODULO_VALUE_1     BIT1
 set     PIT0_MOD_MODULO_VALUE_2     BIT2
 set     PIT0_MOD_MODULO_VALUE_3     BIT3
 set     PIT0_MOD_MODULO_VALUE_4     BIT4
 set     PIT0_MOD_MODULO_VALUE_5     BIT5
 set     PIT0_MOD_MODULO_VALUE_6     BIT6
 set     PIT0_MOD_MODULO_VALUE_7     BIT7
 set     PIT0_MOD_MODULO_VALUE_8     BIT8
 set     PIT0_MOD_MODULO_VALUE_9     BIT9
 set     PIT0_MOD_MODULO_VALUE_10    BIT10
 set     PIT0_MOD_MODULO_VALUE_11    BIT11
 set     PIT0_MOD_MODULO_VALUE_12    BIT12
 set     PIT0_MOD_MODULO_VALUE_13    BIT13
 set     PIT0_MOD_MODULO_VALUE_14    BIT14
 set     PIT0_MOD_MODULO_VALUE_15    BIT15

 set     PIT0_CNTR_COUNTER_VALUE     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PIT0_CNTR_COUNTER_VALUE_0   BIT0
 set     PIT0_CNTR_COUNTER_VALUE_1   BIT1
 set     PIT0_CNTR_COUNTER_VALUE_2   BIT2
 set     PIT0_CNTR_COUNTER_VALUE_3   BIT3
 set     PIT0_CNTR_COUNTER_VALUE_4   BIT4
 set     PIT0_CNTR_COUNTER_VALUE_5   BIT5
 set     PIT0_CNTR_COUNTER_VALUE_6   BIT6
 set     PIT0_CNTR_COUNTER_VALUE_7   BIT7
 set     PIT0_CNTR_COUNTER_VALUE_8   BIT8
 set     PIT0_CNTR_COUNTER_VALUE_9   BIT9
 set     PIT0_CNTR_COUNTER_VALUE_10  BIT10
 set     PIT0_CNTR_COUNTER_VALUE_11  BIT11
 set     PIT0_CNTR_COUNTER_VALUE_12  BIT12
 set     PIT0_CNTR_COUNTER_VALUE_13  BIT13
 set     PIT0_CNTR_COUNTER_VALUE_14  BIT14
 set     PIT0_CNTR_COUNTER_VALUE_15  BIT15

 set     PIT1_CTRL_CNT_EN            BIT0
;;   Count Enable
;;     0b0 ==> PIT counter reset (default).
;;     0b1 ==> PIT counter active.

 set     PIT1_CTRL_PRIE              BIT1
;;   PIT Roll-Over Interrupt Enable.
;;     0b0 ==> PIT roll-over interrupt disabled (default).
;;     0b1 ==> PIT roll-over interrupt enabled.

 set     PIT1_CTRL_PRF               BIT2
;;   PIT Roll-Over Flag.
;;     0b0 ==> PIT counter has not reached the modulo value. (default)
;;     0b1 ==> PIT counter has reached the modulo value.

 set     PIT1_CTRL_PRESCALER         (BIT3|BIT4|BIT5|BIT6)
;;     0b0000 ==> Clock
;;     0b0001 ==> Clock divided by 2
;;     0b0010 ==> Clock divided by 4
;;     0b0011 ==> Clock divided by 8
;;     0b0100 ==> Clock divided by 16
;;     0b0101 ==> Clock divided by 32
;;     0b0110 ==> Clock divided by 64
;;     0b0111 ==> Clock divided by 128
;;     0b1000 ==> Clock divided by 256
;;     0b1001 ==> Clock divided by 512
;;     0b1010 ==> Clock divided by 1024
;;     0b1011 ==> Clock divided by 2048
;;     0b1100 ==> Clock divided by 4096
;;     0b1101 ==> Clock divided by 8192
;;     0b1110 ==> Clock divided by 16384
;;     0b1111 ==> Clock divided by 32768
 set     PIT1_CTRL_PRESCALER_0       BIT3
 set     PIT1_CTRL_PRESCALER_1       BIT4
 set     PIT1_CTRL_PRESCALER_2       BIT5
 set     PIT1_CTRL_PRESCALER_3       BIT6

 set     PIT1_CTRL_CLKSEL            (BIT8|BIT9)
;;     0b00 ==> Selects IPBus clock
;;     0b01 ==> Selects alternate clock 1
;;     0b10 ==> Selects alternate clock 2
;;     0b11 ==> Selects alternate clock 3
 set     PIT1_CTRL_CLKSEL_0          BIT8
 set     PIT1_CTRL_CLKSEL_1          BIT9

 set     PIT1_CTRL_SLAVE             BIT15
;;     0b0 ==> CNT_EN from this PIT is used to control operation (default).
;;     0b1 ==> CNT_EN from master PIT is used to control operation.

 set     PIT1_MOD_MODULO_VALUE       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PIT1_MOD_MODULO_VALUE_0     BIT0
 set     PIT1_MOD_MODULO_VALUE_1     BIT1
 set     PIT1_MOD_MODULO_VALUE_2     BIT2
 set     PIT1_MOD_MODULO_VALUE_3     BIT3
 set     PIT1_MOD_MODULO_VALUE_4     BIT4
 set     PIT1_MOD_MODULO_VALUE_5     BIT5
 set     PIT1_MOD_MODULO_VALUE_6     BIT6
 set     PIT1_MOD_MODULO_VALUE_7     BIT7
 set     PIT1_MOD_MODULO_VALUE_8     BIT8
 set     PIT1_MOD_MODULO_VALUE_9     BIT9
 set     PIT1_MOD_MODULO_VALUE_10    BIT10
 set     PIT1_MOD_MODULO_VALUE_11    BIT11
 set     PIT1_MOD_MODULO_VALUE_12    BIT12
 set     PIT1_MOD_MODULO_VALUE_13    BIT13
 set     PIT1_MOD_MODULO_VALUE_14    BIT14
 set     PIT1_MOD_MODULO_VALUE_15    BIT15

 set     PIT1_CNTR_COUNTER_VALUE     (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PIT1_CNTR_COUNTER_VALUE_0   BIT0
 set     PIT1_CNTR_COUNTER_VALUE_1   BIT1
 set     PIT1_CNTR_COUNTER_VALUE_2   BIT2
 set     PIT1_CNTR_COUNTER_VALUE_3   BIT3
 set     PIT1_CNTR_COUNTER_VALUE_4   BIT4
 set     PIT1_CNTR_COUNTER_VALUE_5   BIT5
 set     PIT1_CNTR_COUNTER_VALUE_6   BIT6
 set     PIT1_CNTR_COUNTER_VALUE_7   BIT7
 set     PIT1_CNTR_COUNTER_VALUE_8   BIT8
 set     PIT1_CNTR_COUNTER_VALUE_9   BIT9
 set     PIT1_CNTR_COUNTER_VALUE_10  BIT10
 set     PIT1_CNTR_COUNTER_VALUE_11  BIT11
 set     PIT1_CNTR_COUNTER_VALUE_12  BIT12
 set     PIT1_CNTR_COUNTER_VALUE_13  BIT13
 set     PIT1_CNTR_COUNTER_VALUE_14  BIT14
 set     PIT1_CNTR_COUNTER_VALUE_15  BIT15

 set     PMC_CTRL_LV22IE             BIT0
;;   2.2 V Low Voltage Interrupt Enable
;;     0b0 ==> Disable setting the low voltage interrupt.
;;     0b1 ==> Enable setting the low voltage interrupt.

 set     PMC_CTRL_LV27IE             BIT1
;;   2.7 V Low Voltage Interrupt Enable
;;     0b0 ==> Disable setting the low voltage interrupt.
;;     0b1 ==> Enable setting the low voltage interrupt.

 set     PMC_CTRL_HV22IE             BIT2
;;   2.2 V High Voltage Interrupt Enable
;;     0b0 ==> Disable setting the high voltage interrupt.
;;     0b1 ==> Enable setting the high voltage interrupt.

 set     PMC_CTRL_HV27IE             BIT3
;;   2.7 V High Voltage Interrupt Enable
;;     0b0 ==> Disable setting the high voltage interrupt.
;;     0b1 ==> Enable setting the high voltage interrupt.

 set     PMC_CTRL_VRBEN              BIT7
;;   Voltage Reference Buffer Enable
;;     0b0 ==> Disable voltage reference buffering.
;;     0b1 ==> Enable voltage reference buffering.

 set     PMC_CTRL_TRIM               (BIT12|BIT13|BIT14|BIT15)
;;   Bandgap Trim
 set     PMC_CTRL_TRIM_0             BIT12
 set     PMC_CTRL_TRIM_1             BIT13
 set     PMC_CTRL_TRIM_2             BIT14
 set     PMC_CTRL_TRIM_3             BIT15

 set     PMC_STS_LV22F               BIT0
;;   2.2 V Low Voltage Flag
;;     0b0 ==> 3.3 V supply is not below the 2.2 V threshold.
;;     0b1 ==> 3.3 V supply is below the 2.2 V threshold.

 set     PMC_STS_LV27F               BIT1
;;   2.7 V Low Voltage Flag
;;     0b0 ==> 3.3 V supply is not below the 2.7 V threshold.
;;     0b1 ==> 3.3 V supply is below the 2.7 V threshold.

 set     PMC_STS_SLV22F              BIT2
;;   Sticky 2.2 V Low Voltage Flag
;;     0b0 ==> 3.3 V supply has not dropped below the 2.2 V threshold.
;;     0b1 ==> 3.3 V supply has dropped below the 2.2 V threshold.

 set     PMC_STS_SLV27F              BIT3
;;   Sticky 2.7 V Low Voltage Flag
;;     0b0 ==> 3.3 V supply has not dropped below the 2.7 V threshold.
;;     0b1 ==> 3.3 V supply has dropped below the 2.7 V threshold.

 set     PMC_STS_LVI                 BIT4
;;   Low Voltage Interrupt
;;     0b0 ==> Low voltage interrupt cleared.
;;     0b1 ==> Low voltage interrupt asserted.

 set     PMC_STS_SR27                BIT5
;;   Small Regulator 2.7 V Active Flag
;;     0b0 ==> The small regulator 2.7 V supply is not ready to be used.
;;     0b1 ==> The small regulator 2.7 V supply is ready to be used.

 set     PWMA_SM0CNT_CNT             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Counter Register Bits
 set     PWMA_SM0CNT_CNT_0           BIT0
 set     PWMA_SM0CNT_CNT_1           BIT1
 set     PWMA_SM0CNT_CNT_2           BIT2
 set     PWMA_SM0CNT_CNT_3           BIT3
 set     PWMA_SM0CNT_CNT_4           BIT4
 set     PWMA_SM0CNT_CNT_5           BIT5
 set     PWMA_SM0CNT_CNT_6           BIT6
 set     PWMA_SM0CNT_CNT_7           BIT7
 set     PWMA_SM0CNT_CNT_8           BIT8
 set     PWMA_SM0CNT_CNT_9           BIT9
 set     PWMA_SM0CNT_CNT_10          BIT10
 set     PWMA_SM0CNT_CNT_11          BIT11
 set     PWMA_SM0CNT_CNT_12          BIT12
 set     PWMA_SM0CNT_CNT_13          BIT13
 set     PWMA_SM0CNT_CNT_14          BIT14
 set     PWMA_SM0CNT_CNT_15          BIT15

 set     PWMA_SM0INIT_INIT           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Initial Count Register Bits
 set     PWMA_SM0INIT_INIT_0         BIT0
 set     PWMA_SM0INIT_INIT_1         BIT1
 set     PWMA_SM0INIT_INIT_2         BIT2
 set     PWMA_SM0INIT_INIT_3         BIT3
 set     PWMA_SM0INIT_INIT_4         BIT4
 set     PWMA_SM0INIT_INIT_5         BIT5
 set     PWMA_SM0INIT_INIT_6         BIT6
 set     PWMA_SM0INIT_INIT_7         BIT7
 set     PWMA_SM0INIT_INIT_8         BIT8
 set     PWMA_SM0INIT_INIT_9         BIT9
 set     PWMA_SM0INIT_INIT_10        BIT10
 set     PWMA_SM0INIT_INIT_11        BIT11
 set     PWMA_SM0INIT_INIT_12        BIT12
 set     PWMA_SM0INIT_INIT_13        BIT13
 set     PWMA_SM0INIT_INIT_14        BIT14
 set     PWMA_SM0INIT_INIT_15        BIT15

 set     PWMA_SM0CTRL2_CLK_SEL       (BIT0|BIT1)
;;   Clock Source Select
;;     0b00 ==> The IPBus clock is used as the clock for the local prescaler and counter.
;;     0b01 ==> EXT_CLK is used as the clock for the local prescaler and counter.
;;     0b10 ==> Submodule 0's clock (AUX_CLK) is used as the source clock for the local prescaler and counter. This setting should not be used in submodule 0 as it will force the clock to logic 0.
;;     0b11 ==> reserved
 set     PWMA_SM0CTRL2_CLK_SEL_0     BIT0
 set     PWMA_SM0CTRL2_CLK_SEL_1     BIT1

 set     PWMA_SM0CTRL2_RELOAD_SEL    BIT2
;;   Reload Source Select
;;     0b0 ==> The local RELOAD signal is used to reload registers.
;;     0b1 ==> The master RELOAD signal (from submodule 0) is used to reload registers. This setting should not be used in submodule 0 as it will force the RELOAD signal to logic 0.

 set     PWMA_SM0CTRL2_FORCE_SEL     (BIT3|BIT4|BIT5)
;;   This read/write bit determines the source of the FORCE OUTPUT signal for this submodule.
;;     0b000 ==> The local force signal, CTRL2[FORCE], from this submodule is used to force updates.
;;     0b001 ==> The master force signal from submodule 0 is used to force updates. This setting should not be used in submodule 0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b010 ==> The local reload signal from this submodule is used to force updates without regard to the state of LDOK.
;;     0b011 ==> The master reload signal from submodule0 is used to force updates if LDOK is set. This setting should not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b100 ==> The local sync signal from this submodule is used to force updates.
;;     0b101 ==> The master sync signal from submodule0 is used to force updates. This setting should not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b110 ==> The external force signal, EXT_FORCE, from outside the PWM module causes updates.
;;     0b111 ==> reserved
 set     PWMA_SM0CTRL2_FORCE_SEL_0   BIT3
 set     PWMA_SM0CTRL2_FORCE_SEL_1   BIT4
 set     PWMA_SM0CTRL2_FORCE_SEL_2   BIT5

 set     PWMA_SM0CTRL2_FORCE         BIT6
;;   Force Initialization

 set     PWMA_SM0CTRL2_FRCEN         BIT7
;;   Force Initialization Enable
;;     0b0 ==> Initialization from a FORCE_OUT event is disabled.
;;     0b1 ==> Initialization from a FORCE_OUT event is enabled.

 set     PWMA_SM0CTRL2_INIT_SEL      (BIT8|BIT9)
;;   Initialization Control Select
;;     0b00 ==> Local sync (PWM_X) causes initialization.
;;     0b01 ==> Master reload from submodule 0 causes initialization. This setting should not be used in submodule 0 as it will force the INIT signal to logic 0.
;;     0b10 ==> Master sync from submodule 0 causes initialization. This setting should not be used in submodule 0 as it will force the INIT signal to logic 0.
;;     0b11 ==> EXT_SYNC causes initialization.
 set     PWMA_SM0CTRL2_INIT_SEL_0    BIT8
 set     PWMA_SM0CTRL2_INIT_SEL_1    BIT9

 set     PWMA_SM0CTRL2_PWMX_INIT     BIT10
;;   PWM_X Initial Value

 set     PWMA_SM0CTRL2_PWM45_INIT    BIT11
;;   PWM45 Initial Value

 set     PWMA_SM0CTRL2_PWM23_INIT    BIT12
;;   PWM23 Initial Value

 set     PWMA_SM0CTRL2_INDEP         BIT13
;;   Independent or Complementary Pair Operation
;;     0b0 ==> PWM_A and PWM_B form a complementary PWM pair.
;;     0b1 ==> PWM_A and PWM_B outputs are independent PWMs.

 set     PWMA_SM0CTRL2_WAITEN        BIT14
;;   WAIT Enable

 set     PWMA_SM0CTRL2_DBGEN         BIT15
;;   Debug Enable

 set     PWMA_SM0CTRL_DBLEN          BIT0
;;   Double Switching Enable
;;     0b0 ==> Double switching disabled.
;;     0b1 ==> Double switching enabled.

 set     PWMA_SM0CTRL_DBLX           BIT1
;;   PWMX Double Switching Enable
;;     0b0 ==> PWMX double pulse disabled
;;     0b1 ==> PWMX double pulse enabled

 set     PWMA_SM0CTRL_LDMOD          BIT2
;;   Load Mode Select
;;     0b0 ==> Buffered registers of this submodule are loaded and take effect at the next PWM reload if MCTRL[LDOK] is set.
;;     0b1 ==> Buffered registers of this submodule are loaded and take effect immediately upon MCTRL[LDOK] being set.

 set     PWMA_SM0CTRL_SPLIT          BIT3
;;   Split the DBLPWM signal to PWMA and PWMB
;;     0b0 ==> DBLPWM is not split. PWMA and PWMB each have double pulses.
;;     0b1 ==> DBLPWM is split to PWMA and PWMB.

 set     PWMA_SM0CTRL_PRSC           (BIT4|BIT5|BIT6)
;;   Prescaler
;;     0b000 ==> PWM clock frequency = fclk
;;     0b001 ==> PWM clock frequency = fclk/2
;;     0b010 ==> PWM clock frequency = fclk/4
;;     0b011 ==> PWM clock frequency = fclk/8
;;     0b100 ==> PWM clock frequency = fclk/16
;;     0b101 ==> PWM clock frequency = fclk/32
;;     0b110 ==> PWM clock frequency = fclk/64
;;     0b111 ==> PWM clock frequency = fclk/128
 set     PWMA_SM0CTRL_PRSC_0         BIT4
 set     PWMA_SM0CTRL_PRSC_1         BIT5
 set     PWMA_SM0CTRL_PRSC_2         BIT6

 set     PWMA_SM0CTRL_DT             (BIT8|BIT9)
;;   Deadtime
 set     PWMA_SM0CTRL_DT_0           BIT8
 set     PWMA_SM0CTRL_DT_1           BIT9

 set     PWMA_SM0CTRL_FULL           BIT10
;;   Full Cycle Reload
;;     0b0 ==> Full-cycle reloads disabled.
;;     0b1 ==> Full-cycle reloads enabled.

 set     PWMA_SM0CTRL_HALF           BIT11
;;   Half Cycle Reload
;;     0b0 ==> Half-cycle reloads disabled.
;;     0b1 ==> Half-cycle reloads enabled.

 set     PWMA_SM0CTRL_LDFQ           (BIT12|BIT13|BIT14|BIT15)
;;     0b0000 ==> Every PWM opportunity
;;     0b0001 ==> Every 2 PWM opportunities
;;     0b0010 ==> Every 3 PWM opportunities
;;     0b0011 ==> Every 4 PWM opportunities
;;     0b0100 ==> Every 5 PWM opportunities
;;     0b0101 ==> Every 6 PWM opportunities
;;     0b0110 ==> Every 7 PWM opportunities
;;     0b0111 ==> Every 8 PWM opportunities
;;     0b1000 ==> Every 9 PWM opportunities
;;     0b1001 ==> Every 10 PWM opportunities
;;     0b1010 ==> Every 11 PWM opportunities
;;     0b1011 ==> Every 12 PWM opportunities
;;     0b1100 ==> Every 13 PWM opportunities
;;     0b1101 ==> Every 14 PWM opportunities
;;     0b1110 ==> Every 15 PWM opportunities
;;     0b1111 ==> Every 16 PWM opportunities
 set     PWMA_SM0CTRL_LDFQ_0         BIT12
 set     PWMA_SM0CTRL_LDFQ_1         BIT13
 set     PWMA_SM0CTRL_LDFQ_2         BIT14
 set     PWMA_SM0CTRL_LDFQ_3         BIT15

 set     PWMA_SM0VAL0_VAL0           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 0
 set     PWMA_SM0VAL0_VAL0_0         BIT0
 set     PWMA_SM0VAL0_VAL0_1         BIT1
 set     PWMA_SM0VAL0_VAL0_2         BIT2
 set     PWMA_SM0VAL0_VAL0_3         BIT3
 set     PWMA_SM0VAL0_VAL0_4         BIT4
 set     PWMA_SM0VAL0_VAL0_5         BIT5
 set     PWMA_SM0VAL0_VAL0_6         BIT6
 set     PWMA_SM0VAL0_VAL0_7         BIT7
 set     PWMA_SM0VAL0_VAL0_8         BIT8
 set     PWMA_SM0VAL0_VAL0_9         BIT9
 set     PWMA_SM0VAL0_VAL0_10        BIT10
 set     PWMA_SM0VAL0_VAL0_11        BIT11
 set     PWMA_SM0VAL0_VAL0_12        BIT12
 set     PWMA_SM0VAL0_VAL0_13        BIT13
 set     PWMA_SM0VAL0_VAL0_14        BIT14
 set     PWMA_SM0VAL0_VAL0_15        BIT15

 set     PWMA_SM0FRACVAL1_FRACVAL1   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 1 Register
 set     PWMA_SM0FRACVAL1_FRACVAL1_0 BIT11
 set     PWMA_SM0FRACVAL1_FRACVAL1_1 BIT12
 set     PWMA_SM0FRACVAL1_FRACVAL1_2 BIT13
 set     PWMA_SM0FRACVAL1_FRACVAL1_3 BIT14
 set     PWMA_SM0FRACVAL1_FRACVAL1_4 BIT15

 set     PWMA_SM0VAL1_VAL1           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 1
 set     PWMA_SM0VAL1_VAL1_0         BIT0
 set     PWMA_SM0VAL1_VAL1_1         BIT1
 set     PWMA_SM0VAL1_VAL1_2         BIT2
 set     PWMA_SM0VAL1_VAL1_3         BIT3
 set     PWMA_SM0VAL1_VAL1_4         BIT4
 set     PWMA_SM0VAL1_VAL1_5         BIT5
 set     PWMA_SM0VAL1_VAL1_6         BIT6
 set     PWMA_SM0VAL1_VAL1_7         BIT7
 set     PWMA_SM0VAL1_VAL1_8         BIT8
 set     PWMA_SM0VAL1_VAL1_9         BIT9
 set     PWMA_SM0VAL1_VAL1_10        BIT10
 set     PWMA_SM0VAL1_VAL1_11        BIT11
 set     PWMA_SM0VAL1_VAL1_12        BIT12
 set     PWMA_SM0VAL1_VAL1_13        BIT13
 set     PWMA_SM0VAL1_VAL1_14        BIT14
 set     PWMA_SM0VAL1_VAL1_15        BIT15

 set     PWMA_SM0FRACVAL2_FRACVAL2   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 2
 set     PWMA_SM0FRACVAL2_FRACVAL2_0 BIT11
 set     PWMA_SM0FRACVAL2_FRACVAL2_1 BIT12
 set     PWMA_SM0FRACVAL2_FRACVAL2_2 BIT13
 set     PWMA_SM0FRACVAL2_FRACVAL2_3 BIT14
 set     PWMA_SM0FRACVAL2_FRACVAL2_4 BIT15

 set     PWMA_SM0VAL2_VAL2           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 2
 set     PWMA_SM0VAL2_VAL2_0         BIT0
 set     PWMA_SM0VAL2_VAL2_1         BIT1
 set     PWMA_SM0VAL2_VAL2_2         BIT2
 set     PWMA_SM0VAL2_VAL2_3         BIT3
 set     PWMA_SM0VAL2_VAL2_4         BIT4
 set     PWMA_SM0VAL2_VAL2_5         BIT5
 set     PWMA_SM0VAL2_VAL2_6         BIT6
 set     PWMA_SM0VAL2_VAL2_7         BIT7
 set     PWMA_SM0VAL2_VAL2_8         BIT8
 set     PWMA_SM0VAL2_VAL2_9         BIT9
 set     PWMA_SM0VAL2_VAL2_10        BIT10
 set     PWMA_SM0VAL2_VAL2_11        BIT11
 set     PWMA_SM0VAL2_VAL2_12        BIT12
 set     PWMA_SM0VAL2_VAL2_13        BIT13
 set     PWMA_SM0VAL2_VAL2_14        BIT14
 set     PWMA_SM0VAL2_VAL2_15        BIT15

 set     PWMA_SM0FRACVAL3_FRACVAL3   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 3
 set     PWMA_SM0FRACVAL3_FRACVAL3_0 BIT11
 set     PWMA_SM0FRACVAL3_FRACVAL3_1 BIT12
 set     PWMA_SM0FRACVAL3_FRACVAL3_2 BIT13
 set     PWMA_SM0FRACVAL3_FRACVAL3_3 BIT14
 set     PWMA_SM0FRACVAL3_FRACVAL3_4 BIT15

 set     PWMA_SM0VAL3_VAL3           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 3
 set     PWMA_SM0VAL3_VAL3_0         BIT0
 set     PWMA_SM0VAL3_VAL3_1         BIT1
 set     PWMA_SM0VAL3_VAL3_2         BIT2
 set     PWMA_SM0VAL3_VAL3_3         BIT3
 set     PWMA_SM0VAL3_VAL3_4         BIT4
 set     PWMA_SM0VAL3_VAL3_5         BIT5
 set     PWMA_SM0VAL3_VAL3_6         BIT6
 set     PWMA_SM0VAL3_VAL3_7         BIT7
 set     PWMA_SM0VAL3_VAL3_8         BIT8
 set     PWMA_SM0VAL3_VAL3_9         BIT9
 set     PWMA_SM0VAL3_VAL3_10        BIT10
 set     PWMA_SM0VAL3_VAL3_11        BIT11
 set     PWMA_SM0VAL3_VAL3_12        BIT12
 set     PWMA_SM0VAL3_VAL3_13        BIT13
 set     PWMA_SM0VAL3_VAL3_14        BIT14
 set     PWMA_SM0VAL3_VAL3_15        BIT15

 set     PWMA_SM0FRACVAL4_FRACVAL4   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 4
 set     PWMA_SM0FRACVAL4_FRACVAL4_0 BIT11
 set     PWMA_SM0FRACVAL4_FRACVAL4_1 BIT12
 set     PWMA_SM0FRACVAL4_FRACVAL4_2 BIT13
 set     PWMA_SM0FRACVAL4_FRACVAL4_3 BIT14
 set     PWMA_SM0FRACVAL4_FRACVAL4_4 BIT15

 set     PWMA_SM0VAL4_VAL4           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 4
 set     PWMA_SM0VAL4_VAL4_0         BIT0
 set     PWMA_SM0VAL4_VAL4_1         BIT1
 set     PWMA_SM0VAL4_VAL4_2         BIT2
 set     PWMA_SM0VAL4_VAL4_3         BIT3
 set     PWMA_SM0VAL4_VAL4_4         BIT4
 set     PWMA_SM0VAL4_VAL4_5         BIT5
 set     PWMA_SM0VAL4_VAL4_6         BIT6
 set     PWMA_SM0VAL4_VAL4_7         BIT7
 set     PWMA_SM0VAL4_VAL4_8         BIT8
 set     PWMA_SM0VAL4_VAL4_9         BIT9
 set     PWMA_SM0VAL4_VAL4_10        BIT10
 set     PWMA_SM0VAL4_VAL4_11        BIT11
 set     PWMA_SM0VAL4_VAL4_12        BIT12
 set     PWMA_SM0VAL4_VAL4_13        BIT13
 set     PWMA_SM0VAL4_VAL4_14        BIT14
 set     PWMA_SM0VAL4_VAL4_15        BIT15

 set     PWMA_SM0FRACVAL5_FRACVAL5   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 5
 set     PWMA_SM0FRACVAL5_FRACVAL5_0 BIT11
 set     PWMA_SM0FRACVAL5_FRACVAL5_1 BIT12
 set     PWMA_SM0FRACVAL5_FRACVAL5_2 BIT13
 set     PWMA_SM0FRACVAL5_FRACVAL5_3 BIT14
 set     PWMA_SM0FRACVAL5_FRACVAL5_4 BIT15

 set     PWMA_SM0VAL5_VAL5           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 5
 set     PWMA_SM0VAL5_VAL5_0         BIT0
 set     PWMA_SM0VAL5_VAL5_1         BIT1
 set     PWMA_SM0VAL5_VAL5_2         BIT2
 set     PWMA_SM0VAL5_VAL5_3         BIT3
 set     PWMA_SM0VAL5_VAL5_4         BIT4
 set     PWMA_SM0VAL5_VAL5_5         BIT5
 set     PWMA_SM0VAL5_VAL5_6         BIT6
 set     PWMA_SM0VAL5_VAL5_7         BIT7
 set     PWMA_SM0VAL5_VAL5_8         BIT8
 set     PWMA_SM0VAL5_VAL5_9         BIT9
 set     PWMA_SM0VAL5_VAL5_10        BIT10
 set     PWMA_SM0VAL5_VAL5_11        BIT11
 set     PWMA_SM0VAL5_VAL5_12        BIT12
 set     PWMA_SM0VAL5_VAL5_13        BIT13
 set     PWMA_SM0VAL5_VAL5_14        BIT14
 set     PWMA_SM0VAL5_VAL5_15        BIT15

 set     PWMA_SM0FRCTRL_FRAC1_EN     BIT1
;;   Fractional Cycle PWM Period Enable
;;     0b0 ==> Disable fractional cycle length for the PWM period.
;;     0b1 ==> Enable fractional cycle length for the PWM period.

 set     PWMA_SM0FRCTRL_FRAC23_EN    BIT2
;;   Fractional Cycle Placement Enable fpr PWM_A
;;     0b0 ==> Disable fractional cycle placement for PWM_A.
;;     0b1 ==> Enable fractional cycle placement for PWM_A.

 set     PWMA_SM0FRCTRL_FRAC45_EN    BIT4
;;   Fractional Cycle Placement Enable fpr PWM_B
;;     0b0 ==> Disable fractional cycle placement for PWM_B.
;;     0b1 ==> Enable fractional cycle placement for PWM_B.

 set     PWMA_SM0FRCTRL_FRAC_PU      BIT8
;;   Fractional Delay Circuit Power Up
;;     0b0 ==> Turn off fractional delay logic.
;;     0b1 ==> Power up fractional delay logic.

 set     PWMA_SM0FRCTRL_TEST         BIT15
;;   Test Status Bit

 set     PWMA_SM0OCTRL_PWMXFS        (BIT0|BIT1)
;;   PWM_X Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM0OCTRL_PWMXFS_0      BIT0
 set     PWMA_SM0OCTRL_PWMXFS_1      BIT1

 set     PWMA_SM0OCTRL_PWMBFS        (BIT2|BIT3)
;;   PWM_B Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM0OCTRL_PWMBFS_0      BIT2
 set     PWMA_SM0OCTRL_PWMBFS_1      BIT3

 set     PWMA_SM0OCTRL_PWMAFS        (BIT4|BIT5)
;;   PWM_A Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM0OCTRL_PWMAFS_0      BIT4
 set     PWMA_SM0OCTRL_PWMAFS_1      BIT5

 set     PWMA_SM0OCTRL_POLX          BIT8
;;   PWM_X Output Polarity
;;     0b0 ==> PWM_X output not inverted. A high level on the PWM_X pin represents the "on" or "active" state.
;;     0b1 ==> PWM_X output inverted. A low level on the PWM_X pin represents the "on" or "active" state.

 set     PWMA_SM0OCTRL_POLB          BIT9
;;   PWM_B Output Polarity
;;     0b0 ==> PWM_B output not inverted. A high level on the PWM_B pin represents the "on" or "active" state.
;;     0b1 ==> PWM_B output inverted. A low level on the PWM_B pin represents the "on" or "active" state.

 set     PWMA_SM0OCTRL_POLA          BIT10
;;   PWM_A Output Polarity
;;     0b0 ==> PWM_A output not inverted. A high level on the PWM_A pin represents the "on" or "active" state.
;;     0b1 ==> PWM_A output inverted. A low level on the PWM_A pin represents the "on" or "active" state.

 set     PWMA_SM0OCTRL_PWMX_IN       BIT13
;;   PWM_X Input

 set     PWMA_SM0OCTRL_PWMB_IN       BIT14
;;   PWM_B Input

 set     PWMA_SM0OCTRL_PWMA_IN       BIT15
;;   PWM_A Input

 set     PWMA_SM0STS_CMPF            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Compare Flags
;;     0b0 ==> No compare event has occurred for a particular VALx value.
;;     0b1 ==> A compare event has occurred for a particular VALx value.
 set     PWMA_SM0STS_CMPF_0          BIT0
 set     PWMA_SM0STS_CMPF_1          BIT1
 set     PWMA_SM0STS_CMPF_2          BIT2
 set     PWMA_SM0STS_CMPF_3          BIT3
 set     PWMA_SM0STS_CMPF_4          BIT4
 set     PWMA_SM0STS_CMPF_5          BIT5

 set     PWMA_SM0STS_CFX0            BIT6
;;   Capture Flag X0

 set     PWMA_SM0STS_CFX1            BIT7
;;   Capture Flag X1

 set     PWMA_SM0STS_CFB0            BIT8
;;   Capture Flag B0

 set     PWMA_SM0STS_CFB1            BIT9
;;   Capture Flag B1

 set     PWMA_SM0STS_CFA0            BIT10
;;   Capture Flag A0

 set     PWMA_SM0STS_CFA1            BIT11
;;   Capture Flag A1

 set     PWMA_SM0STS_RF              BIT12
;;   Reload Flag
;;     0b0 ==> No new reload cycle since last STS[RF] clearing
;;     0b1 ==> New reload cycle since last STS[RF] clearing

 set     PWMA_SM0STS_REF             BIT13
;;   Reload Error Flag
;;     0b0 ==> No reload error occurred.
;;     0b1 ==> Reload signal occurred with non-coherent data and MCTRL[LDOK] = 0.

 set     PWMA_SM0STS_RUF             BIT14
;;   Registers Updated Flag
;;     0b0 ==> No register update has occurred since last reload.
;;     0b1 ==> At least one of the double buffered registers has been updated since the last reload.

 set     PWMA_SM0INTEN_CMPIE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Compare Interrupt Enables
;;     0b0 ==> The corresponding STS[CMPF] bit will not cause an interrupt request.
;;     0b1 ==> The corresponding STS[CMPF] bit will cause an interrupt request.
 set     PWMA_SM0INTEN_CMPIE_0       BIT0
 set     PWMA_SM0INTEN_CMPIE_1       BIT1
 set     PWMA_SM0INTEN_CMPIE_2       BIT2
 set     PWMA_SM0INTEN_CMPIE_3       BIT3
 set     PWMA_SM0INTEN_CMPIE_4       BIT4
 set     PWMA_SM0INTEN_CMPIE_5       BIT5

 set     PWMA_SM0INTEN_CX0IE         BIT6
;;   Capture X 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFX0].
;;     0b1 ==> Interrupt request enabled for STS[CFX0].

 set     PWMA_SM0INTEN_CX1IE         BIT7
;;   Capture X 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFX1].
;;     0b1 ==> Interrupt request enabled for STS[CFX1].

 set     PWMA_SM0INTEN_CB0IE         BIT8
;;   Capture B 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFB0].
;;     0b1 ==> Interrupt request enabled for STS[CFB0].

 set     PWMA_SM0INTEN_CB1IE         BIT9
;;   Capture B 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFB1].
;;     0b1 ==> Interrupt request enabled for STS[CFB1].

 set     PWMA_SM0INTEN_CA0IE         BIT10
;;   Capture A 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFA0].
;;     0b1 ==> Interrupt request enabled for STS[CFA0].

 set     PWMA_SM0INTEN_CA1IE         BIT11
;;   Capture A 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFA1].
;;     0b1 ==> Interrupt request enabled for STS[CFA1].

 set     PWMA_SM0INTEN_RIE           BIT12
;;   Reload Interrupt Enable
;;     0b0 ==> STS[RF] CPU interrupt requests disabled
;;     0b1 ==> STS[RF] CPU interrupt requests enabled

 set     PWMA_SM0INTEN_REIE          BIT13
;;   Reload Error Interrupt Enable
;;     0b0 ==> STS[REF] CPU interrupt requests disabled
;;     0b1 ==> STS[REF] CPU interrupt requests enabled

 set     PWMA_SM0DMAEN_CX0DE         BIT0
;;   Capture X0 FIFO DMA Enable

 set     PWMA_SM0DMAEN_CX1DE         BIT1
;;   Capture X1 FIFO DMA Enable

 set     PWMA_SM0DMAEN_CB0DE         BIT2
;;   Capture B0 FIFO DMA Enable

 set     PWMA_SM0DMAEN_CB1DE         BIT3
;;   Capture B1 FIFO DMA Enable

 set     PWMA_SM0DMAEN_CA0DE         BIT4
;;   Capture A0 FIFO DMA Enable

 set     PWMA_SM0DMAEN_CA1DE         BIT5
;;   Capture A1 FIFO DMA Enable

 set     PWMA_SM0DMAEN_CAPTDE        (BIT6|BIT7)
;;   Capture DMA Enable Source Select
;;     0b00 ==> Read DMA requests disabled.
;;     0b01 ==> Exceeding a FIFO watermark sets the DMA read request. This requires at least one of DMAEN[CA1DE], DMAEN[CA0DE], DMAEN[CB1DE], DMAEN[CB0DE], DMAEN[CX1DE], or DMAEN[CX0DE] to also be set in order to determine to which watermark(s) the DMA request is sensitive.
;;     0b10 ==> A local sync (VAL1 matches counter) sets the read DMA request.
;;     0b11 ==> A local reload (STS[RF] being set) sets the read DMA request.
 set     PWMA_SM0DMAEN_CAPTDE_0      BIT6
 set     PWMA_SM0DMAEN_CAPTDE_1      BIT7

 set     PWMA_SM0DMAEN_FAND          BIT8
;;   FIFO Watermark AND Control
;;     0b0 ==> Selected FIFO watermarks are OR'ed together.
;;     0b1 ==> Selected FIFO watermarks are AND'ed together.

 set     PWMA_SM0DMAEN_VALDE         BIT9
;;   Value Registers DMA Enable
;;     0b0 ==> DMA write requests disabled
;;     0b1 ==> DMA write requests for the VALx and FRACVALx registers enabled

 set     PWMA_SM0TCTRL_OUT_TRIG_EN   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Output Trigger Enables
;;     0b0 ==> PWM_OUT_TRIGx will not set when the counter value matches the VALx value.
;;     0b1 ==> PWM_OUT_TRIGx will set when the counter value matches the VALx value.
 set     PWMA_SM0TCTRL_OUT_TRIG_EN_0 BIT0
 set     PWMA_SM0TCTRL_OUT_TRIG_EN_1 BIT1
 set     PWMA_SM0TCTRL_OUT_TRIG_EN_2 BIT2
 set     PWMA_SM0TCTRL_OUT_TRIG_EN_3 BIT3
 set     PWMA_SM0TCTRL_OUT_TRIG_EN_4 BIT4
 set     PWMA_SM0TCTRL_OUT_TRIG_EN_5 BIT5

 set     PWMA_SM0TCTRL_PWBOT1        BIT14
;;   Output Trigger 1 Source Select
;;     0b0 ==> Route the PWM_OUT_TRIG1 signal to PWM_OUT_TRIG1 port.
;;     0b1 ==> Route the PWMB output to the PWM_OUT_TRIG1 port.

 set     PWMA_SM0TCTRL_PWAOT0        BIT15
;;   Output Trigger 0 Source Select
;;     0b0 ==> Route the PWM_OUT_TRIG0 signal to PWM_OUT_TRIG0 port.
;;     0b1 ==> Route the PWMA output to the PWM_OUT_TRIG0 port.

 set     PWMA_SM0DISMAP0_DIS0A       (BIT0|BIT1|BIT2|BIT3)
;;   PWM_A Fault Disable Mask 0
 set     PWMA_SM0DISMAP0_DIS0A_0     BIT0
 set     PWMA_SM0DISMAP0_DIS0A_1     BIT1
 set     PWMA_SM0DISMAP0_DIS0A_2     BIT2
 set     PWMA_SM0DISMAP0_DIS0A_3     BIT3

 set     PWMA_SM0DISMAP0_DIS0B       (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Fault Disable Mask 0
 set     PWMA_SM0DISMAP0_DIS0B_0     BIT4
 set     PWMA_SM0DISMAP0_DIS0B_1     BIT5
 set     PWMA_SM0DISMAP0_DIS0B_2     BIT6
 set     PWMA_SM0DISMAP0_DIS0B_3     BIT7

 set     PWMA_SM0DISMAP0_DIS0X       (BIT8|BIT9|BIT10|BIT11)
;;   PWM_X Fault Disable Mask 0
 set     PWMA_SM0DISMAP0_DIS0X_0     BIT8
 set     PWMA_SM0DISMAP0_DIS0X_1     BIT9
 set     PWMA_SM0DISMAP0_DIS0X_2     BIT10
 set     PWMA_SM0DISMAP0_DIS0X_3     BIT11

 set     PWMA_SM0DISMAP1_DIS1A       (BIT0|BIT1|BIT2|BIT3)
;;   PWM_A Fault Disable Mask 1
 set     PWMA_SM0DISMAP1_DIS1A_0     BIT0
 set     PWMA_SM0DISMAP1_DIS1A_1     BIT1
 set     PWMA_SM0DISMAP1_DIS1A_2     BIT2
 set     PWMA_SM0DISMAP1_DIS1A_3     BIT3

 set     PWMA_SM0DISMAP1_DIS1B       (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Fault Disable Mask 1
 set     PWMA_SM0DISMAP1_DIS1B_0     BIT4
 set     PWMA_SM0DISMAP1_DIS1B_1     BIT5
 set     PWMA_SM0DISMAP1_DIS1B_2     BIT6
 set     PWMA_SM0DISMAP1_DIS1B_3     BIT7

 set     PWMA_SM0DISMAP1_DIS1X       (BIT8|BIT9|BIT10|BIT11)
;;   PWM_X Fault Disable Mask 1
 set     PWMA_SM0DISMAP1_DIS1X_0     BIT8
 set     PWMA_SM0DISMAP1_DIS1X_1     BIT9
 set     PWMA_SM0DISMAP1_DIS1X_2     BIT10
 set     PWMA_SM0DISMAP1_DIS1X_3     BIT11

 set     PWMA_SM0DTCNT0_DTCNT0       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   Deadtime Count Register 0
 set     PWMA_SM0DTCNT0_DTCNT0_0     BIT0
 set     PWMA_SM0DTCNT0_DTCNT0_1     BIT1
 set     PWMA_SM0DTCNT0_DTCNT0_2     BIT2
 set     PWMA_SM0DTCNT0_DTCNT0_3     BIT3
 set     PWMA_SM0DTCNT0_DTCNT0_4     BIT4
 set     PWMA_SM0DTCNT0_DTCNT0_5     BIT5
 set     PWMA_SM0DTCNT0_DTCNT0_6     BIT6
 set     PWMA_SM0DTCNT0_DTCNT0_7     BIT7
 set     PWMA_SM0DTCNT0_DTCNT0_8     BIT8
 set     PWMA_SM0DTCNT0_DTCNT0_9     BIT9
 set     PWMA_SM0DTCNT0_DTCNT0_10    BIT10

 set     PWMA_SM0DTCNT1_DTCNT1       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   Deadtime Count Register 1
 set     PWMA_SM0DTCNT1_DTCNT1_0     BIT0
 set     PWMA_SM0DTCNT1_DTCNT1_1     BIT1
 set     PWMA_SM0DTCNT1_DTCNT1_2     BIT2
 set     PWMA_SM0DTCNT1_DTCNT1_3     BIT3
 set     PWMA_SM0DTCNT1_DTCNT1_4     BIT4
 set     PWMA_SM0DTCNT1_DTCNT1_5     BIT5
 set     PWMA_SM0DTCNT1_DTCNT1_6     BIT6
 set     PWMA_SM0DTCNT1_DTCNT1_7     BIT7
 set     PWMA_SM0DTCNT1_DTCNT1_8     BIT8
 set     PWMA_SM0DTCNT1_DTCNT1_9     BIT9
 set     PWMA_SM0DTCNT1_DTCNT1_10    BIT10

 set     PWMA_SM0CAPTCTRLA_ARMA      BIT0
;;   Arm A
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLA[EDGAx] is enabled.

 set     PWMA_SM0CAPTCTRLA_ONESHOTA  BIT1
;;   One Shot Mode A
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLA[ARMA] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLA[ARMA] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and CAPTCTRLA[ARMA] is cleared. No further captures will be performed until CAPTCTRLA[ARMA] is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled
;;             capture circuit and CAPTCTRLA[ARMA] is then cleared.

 set     PWMA_SM0CAPTCTRLA_EDGA0     (BIT2|BIT3)
;;   Edge A 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM0CAPTCTRLA_EDGA0_0   BIT2
 set     PWMA_SM0CAPTCTRLA_EDGA0_1   BIT3

 set     PWMA_SM0CAPTCTRLA_EDGA1     (BIT4|BIT5)
;;   Edge A 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM0CAPTCTRLA_EDGA1_0   BIT4
 set     PWMA_SM0CAPTCTRLA_EDGA1_1   BIT5

 set     PWMA_SM0CAPTCTRLA_INP_SELA  BIT6
;;   Input Select A
;;     0b0 ==> Raw PWM_A input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLA[EDGA0] and CAPTCTRLA[EDGA1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRA[EDGA0] and/or CAPTCTRLA[EDGA1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM0CAPTCTRLA_EDGCNTA_EN BIT7
;;   Edge Counter A Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM0CAPTCTRLA_CFAWM     (BIT8|BIT9)
;;   Capture A FIFOs Water Mark
 set     PWMA_SM0CAPTCTRLA_CFAWM_0   BIT8
 set     PWMA_SM0CAPTCTRLA_CFAWM_1   BIT9

 set     PWMA_SM0CAPTCTRLA_CA0CNT    (BIT10|BIT11|BIT12)
;;   Capture A0 FIFO Word Count
 set     PWMA_SM0CAPTCTRLA_CA0CNT_0  BIT10
 set     PWMA_SM0CAPTCTRLA_CA0CNT_1  BIT11
 set     PWMA_SM0CAPTCTRLA_CA0CNT_2  BIT12

 set     PWMA_SM0CAPTCTRLA_CA1CNT    (BIT13|BIT14|BIT15)
;;   Capture A1 FIFO Word Count
 set     PWMA_SM0CAPTCTRLA_CA1CNT_0  BIT13
 set     PWMA_SM0CAPTCTRLA_CA1CNT_1  BIT14
 set     PWMA_SM0CAPTCTRLA_CA1CNT_2  BIT15

 set     PWMA_SM0CAPTCOMPA_EDGCMPA   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare A
 set     PWMA_SM0CAPTCOMPA_EDGCMPA_0 BIT0
 set     PWMA_SM0CAPTCOMPA_EDGCMPA_1 BIT1
 set     PWMA_SM0CAPTCOMPA_EDGCMPA_2 BIT2
 set     PWMA_SM0CAPTCOMPA_EDGCMPA_3 BIT3
 set     PWMA_SM0CAPTCOMPA_EDGCMPA_4 BIT4
 set     PWMA_SM0CAPTCOMPA_EDGCMPA_5 BIT5
 set     PWMA_SM0CAPTCOMPA_EDGCMPA_6 BIT6
 set     PWMA_SM0CAPTCOMPA_EDGCMPA_7 BIT7

 set     PWMA_SM0CAPTCOMPA_EDGCNTA   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter A
 set     PWMA_SM0CAPTCOMPA_EDGCNTA_0 BIT8
 set     PWMA_SM0CAPTCOMPA_EDGCNTA_1 BIT9
 set     PWMA_SM0CAPTCOMPA_EDGCNTA_2 BIT10
 set     PWMA_SM0CAPTCOMPA_EDGCNTA_3 BIT11
 set     PWMA_SM0CAPTCOMPA_EDGCNTA_4 BIT12
 set     PWMA_SM0CAPTCOMPA_EDGCNTA_5 BIT13
 set     PWMA_SM0CAPTCOMPA_EDGCNTA_6 BIT14
 set     PWMA_SM0CAPTCOMPA_EDGCNTA_7 BIT15

 set     PWMA_SM0CAPTCTRLB_ARMB      BIT0
;;   Arm B
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLB[EDGBx] is enabled.

 set     PWMA_SM0CAPTCTRLB_ONESHOTB  BIT1
;;   One Shot Mode B
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLB[ARMB] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLB[ARMB] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and CAPTCTRLB[ARMB] is cleared. No further captures will be performed until CAPTCTRLB[ARMB] is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled
;;             capture circuit and CAPTCTRLB[ARMB] is then cleared.

 set     PWMA_SM0CAPTCTRLB_EDGB0     (BIT2|BIT3)
;;   Edge B 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM0CAPTCTRLB_EDGB0_0   BIT2
 set     PWMA_SM0CAPTCTRLB_EDGB0_1   BIT3

 set     PWMA_SM0CAPTCTRLB_EDGB1     (BIT4|BIT5)
;;   Edge B 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM0CAPTCTRLB_EDGB1_0   BIT4
 set     PWMA_SM0CAPTCTRLB_EDGB1_1   BIT5

 set     PWMA_SM0CAPTCTRLB_INP_SELB  BIT6
;;   Input Select B
;;     0b0 ==> Raw PWM_B input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLB[EDGB0] and CAPTCTRLB[EDGB1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRB[EDGB0] and/or CAPTCTRLB[EDGB1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM0CAPTCTRLB_EDGCNTB_EN BIT7
;;   Edge Counter B Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM0CAPTCTRLB_CFBWM     (BIT8|BIT9)
;;   Capture B FIFOs Water Mark
 set     PWMA_SM0CAPTCTRLB_CFBWM_0   BIT8
 set     PWMA_SM0CAPTCTRLB_CFBWM_1   BIT9

 set     PWMA_SM0CAPTCTRLB_CB0CNT    (BIT10|BIT11|BIT12)
;;   Capture B0 FIFO Word Count
 set     PWMA_SM0CAPTCTRLB_CB0CNT_0  BIT10
 set     PWMA_SM0CAPTCTRLB_CB0CNT_1  BIT11
 set     PWMA_SM0CAPTCTRLB_CB0CNT_2  BIT12

 set     PWMA_SM0CAPTCTRLB_CB1CNT    (BIT13|BIT14|BIT15)
;;   Capture B1 FIFO Word Count
 set     PWMA_SM0CAPTCTRLB_CB1CNT_0  BIT13
 set     PWMA_SM0CAPTCTRLB_CB1CNT_1  BIT14
 set     PWMA_SM0CAPTCTRLB_CB1CNT_2  BIT15

 set     PWMA_SM0CAPTCOMPB_EDGCMPB   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare B
 set     PWMA_SM0CAPTCOMPB_EDGCMPB_0 BIT0
 set     PWMA_SM0CAPTCOMPB_EDGCMPB_1 BIT1
 set     PWMA_SM0CAPTCOMPB_EDGCMPB_2 BIT2
 set     PWMA_SM0CAPTCOMPB_EDGCMPB_3 BIT3
 set     PWMA_SM0CAPTCOMPB_EDGCMPB_4 BIT4
 set     PWMA_SM0CAPTCOMPB_EDGCMPB_5 BIT5
 set     PWMA_SM0CAPTCOMPB_EDGCMPB_6 BIT6
 set     PWMA_SM0CAPTCOMPB_EDGCMPB_7 BIT7

 set     PWMA_SM0CAPTCOMPB_EDGCNTB   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter B
 set     PWMA_SM0CAPTCOMPB_EDGCNTB_0 BIT8
 set     PWMA_SM0CAPTCOMPB_EDGCNTB_1 BIT9
 set     PWMA_SM0CAPTCOMPB_EDGCNTB_2 BIT10
 set     PWMA_SM0CAPTCOMPB_EDGCNTB_3 BIT11
 set     PWMA_SM0CAPTCOMPB_EDGCNTB_4 BIT12
 set     PWMA_SM0CAPTCOMPB_EDGCNTB_5 BIT13
 set     PWMA_SM0CAPTCOMPB_EDGCNTB_6 BIT14
 set     PWMA_SM0CAPTCOMPB_EDGCNTB_7 BIT15

 set     PWMA_SM0CAPTCTRLX_ARMX      BIT0
;;   Arm X
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLX[EDGXx] is enabled.

 set     PWMA_SM0CAPTCTRLX_ONESHOTX  BIT1
;;   One Shot Mode Aux
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after the ARMX bit is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after the ARMX bit is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and the ARMX bit is cleared. No further captures will be performed until the ARMX bit is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled capture
;;             circuit and the ARMX bit is then cleared.

 set     PWMA_SM0CAPTCTRLX_EDGX0     (BIT2|BIT3)
;;   Edge X 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM0CAPTCTRLX_EDGX0_0   BIT2
 set     PWMA_SM0CAPTCTRLX_EDGX0_1   BIT3

 set     PWMA_SM0CAPTCTRLX_EDGX1     (BIT4|BIT5)
;;   Edge X 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM0CAPTCTRLX_EDGX1_0   BIT4
 set     PWMA_SM0CAPTCTRLX_EDGX1_1   BIT5

 set     PWMA_SM0CAPTCTRLX_INP_SELX  BIT6
;;   Input Select X
;;     0b0 ==> Raw PWM_X input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLX[EDGX0] and CAPTCTRLX[EDGX1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRX[EDGX0] and/or CAPTCTRLX[EDGX1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM0CAPTCTRLX_EDGCNTX_EN BIT7
;;   Edge Counter X Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM0CAPTCTRLX_CFXWM     (BIT8|BIT9)
;;   Capture X FIFOs Water Mark
 set     PWMA_SM0CAPTCTRLX_CFXWM_0   BIT8
 set     PWMA_SM0CAPTCTRLX_CFXWM_1   BIT9

 set     PWMA_SM0CAPTCTRLX_CX0CNT    (BIT10|BIT11|BIT12)
;;   Capture X0 FIFO Word Count
 set     PWMA_SM0CAPTCTRLX_CX0CNT_0  BIT10
 set     PWMA_SM0CAPTCTRLX_CX0CNT_1  BIT11
 set     PWMA_SM0CAPTCTRLX_CX0CNT_2  BIT12

 set     PWMA_SM0CAPTCTRLX_CX1CNT    (BIT13|BIT14|BIT15)
;;   Capture X1 FIFO Word Count
 set     PWMA_SM0CAPTCTRLX_CX1CNT_0  BIT13
 set     PWMA_SM0CAPTCTRLX_CX1CNT_1  BIT14
 set     PWMA_SM0CAPTCTRLX_CX1CNT_2  BIT15

 set     PWMA_SM0CAPTCOMPX_EDGCMPX   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare X
 set     PWMA_SM0CAPTCOMPX_EDGCMPX_0 BIT0
 set     PWMA_SM0CAPTCOMPX_EDGCMPX_1 BIT1
 set     PWMA_SM0CAPTCOMPX_EDGCMPX_2 BIT2
 set     PWMA_SM0CAPTCOMPX_EDGCMPX_3 BIT3
 set     PWMA_SM0CAPTCOMPX_EDGCMPX_4 BIT4
 set     PWMA_SM0CAPTCOMPX_EDGCMPX_5 BIT5
 set     PWMA_SM0CAPTCOMPX_EDGCMPX_6 BIT6
 set     PWMA_SM0CAPTCOMPX_EDGCMPX_7 BIT7

 set     PWMA_SM0CAPTCOMPX_EDGCNTX   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter X
 set     PWMA_SM0CAPTCOMPX_EDGCNTX_0 BIT8
 set     PWMA_SM0CAPTCOMPX_EDGCNTX_1 BIT9
 set     PWMA_SM0CAPTCOMPX_EDGCNTX_2 BIT10
 set     PWMA_SM0CAPTCOMPX_EDGCNTX_3 BIT11
 set     PWMA_SM0CAPTCOMPX_EDGCNTX_4 BIT12
 set     PWMA_SM0CAPTCOMPX_EDGCNTX_5 BIT13
 set     PWMA_SM0CAPTCOMPX_EDGCNTX_6 BIT14
 set     PWMA_SM0CAPTCOMPX_EDGCNTX_7 BIT15

 set     PWMA_SM0CVAL0_CAPTVAL0      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM0CVAL0_CAPTVAL0_0    BIT0
 set     PWMA_SM0CVAL0_CAPTVAL0_1    BIT1
 set     PWMA_SM0CVAL0_CAPTVAL0_2    BIT2
 set     PWMA_SM0CVAL0_CAPTVAL0_3    BIT3
 set     PWMA_SM0CVAL0_CAPTVAL0_4    BIT4
 set     PWMA_SM0CVAL0_CAPTVAL0_5    BIT5
 set     PWMA_SM0CVAL0_CAPTVAL0_6    BIT6
 set     PWMA_SM0CVAL0_CAPTVAL0_7    BIT7
 set     PWMA_SM0CVAL0_CAPTVAL0_8    BIT8
 set     PWMA_SM0CVAL0_CAPTVAL0_9    BIT9
 set     PWMA_SM0CVAL0_CAPTVAL0_10   BIT10
 set     PWMA_SM0CVAL0_CAPTVAL0_11   BIT11
 set     PWMA_SM0CVAL0_CAPTVAL0_12   BIT12
 set     PWMA_SM0CVAL0_CAPTVAL0_13   BIT13
 set     PWMA_SM0CVAL0_CAPTVAL0_14   BIT14
 set     PWMA_SM0CVAL0_CAPTVAL0_15   BIT15

 set     PWMA_SM0CVAL0CYC_CVAL0CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM0CVAL0CYC_CVAL0CYC_0 BIT0
 set     PWMA_SM0CVAL0CYC_CVAL0CYC_1 BIT1
 set     PWMA_SM0CVAL0CYC_CVAL0CYC_2 BIT2
 set     PWMA_SM0CVAL0CYC_CVAL0CYC_3 BIT3

 set     PWMA_SM0CVAL1_CAPTVAL1      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM0CVAL1_CAPTVAL1_0    BIT0
 set     PWMA_SM0CVAL1_CAPTVAL1_1    BIT1
 set     PWMA_SM0CVAL1_CAPTVAL1_2    BIT2
 set     PWMA_SM0CVAL1_CAPTVAL1_3    BIT3
 set     PWMA_SM0CVAL1_CAPTVAL1_4    BIT4
 set     PWMA_SM0CVAL1_CAPTVAL1_5    BIT5
 set     PWMA_SM0CVAL1_CAPTVAL1_6    BIT6
 set     PWMA_SM0CVAL1_CAPTVAL1_7    BIT7
 set     PWMA_SM0CVAL1_CAPTVAL1_8    BIT8
 set     PWMA_SM0CVAL1_CAPTVAL1_9    BIT9
 set     PWMA_SM0CVAL1_CAPTVAL1_10   BIT10
 set     PWMA_SM0CVAL1_CAPTVAL1_11   BIT11
 set     PWMA_SM0CVAL1_CAPTVAL1_12   BIT12
 set     PWMA_SM0CVAL1_CAPTVAL1_13   BIT13
 set     PWMA_SM0CVAL1_CAPTVAL1_14   BIT14
 set     PWMA_SM0CVAL1_CAPTVAL1_15   BIT15

 set     PWMA_SM0CVAL1CYC_CVAL1CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM0CVAL1CYC_CVAL1CYC_0 BIT0
 set     PWMA_SM0CVAL1CYC_CVAL1CYC_1 BIT1
 set     PWMA_SM0CVAL1CYC_CVAL1CYC_2 BIT2
 set     PWMA_SM0CVAL1CYC_CVAL1CYC_3 BIT3

 set     PWMA_SM0CVAL2_CAPTVAL2      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM0CVAL2_CAPTVAL2_0    BIT0
 set     PWMA_SM0CVAL2_CAPTVAL2_1    BIT1
 set     PWMA_SM0CVAL2_CAPTVAL2_2    BIT2
 set     PWMA_SM0CVAL2_CAPTVAL2_3    BIT3
 set     PWMA_SM0CVAL2_CAPTVAL2_4    BIT4
 set     PWMA_SM0CVAL2_CAPTVAL2_5    BIT5
 set     PWMA_SM0CVAL2_CAPTVAL2_6    BIT6
 set     PWMA_SM0CVAL2_CAPTVAL2_7    BIT7
 set     PWMA_SM0CVAL2_CAPTVAL2_8    BIT8
 set     PWMA_SM0CVAL2_CAPTVAL2_9    BIT9
 set     PWMA_SM0CVAL2_CAPTVAL2_10   BIT10
 set     PWMA_SM0CVAL2_CAPTVAL2_11   BIT11
 set     PWMA_SM0CVAL2_CAPTVAL2_12   BIT12
 set     PWMA_SM0CVAL2_CAPTVAL2_13   BIT13
 set     PWMA_SM0CVAL2_CAPTVAL2_14   BIT14
 set     PWMA_SM0CVAL2_CAPTVAL2_15   BIT15

 set     PWMA_SM0CVAL2CYC_CVAL2CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM0CVAL2CYC_CVAL2CYC_0 BIT0
 set     PWMA_SM0CVAL2CYC_CVAL2CYC_1 BIT1
 set     PWMA_SM0CVAL2CYC_CVAL2CYC_2 BIT2
 set     PWMA_SM0CVAL2CYC_CVAL2CYC_3 BIT3

 set     PWMA_SM0CVAL3_CAPTVAL3      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM0CVAL3_CAPTVAL3_0    BIT0
 set     PWMA_SM0CVAL3_CAPTVAL3_1    BIT1
 set     PWMA_SM0CVAL3_CAPTVAL3_2    BIT2
 set     PWMA_SM0CVAL3_CAPTVAL3_3    BIT3
 set     PWMA_SM0CVAL3_CAPTVAL3_4    BIT4
 set     PWMA_SM0CVAL3_CAPTVAL3_5    BIT5
 set     PWMA_SM0CVAL3_CAPTVAL3_6    BIT6
 set     PWMA_SM0CVAL3_CAPTVAL3_7    BIT7
 set     PWMA_SM0CVAL3_CAPTVAL3_8    BIT8
 set     PWMA_SM0CVAL3_CAPTVAL3_9    BIT9
 set     PWMA_SM0CVAL3_CAPTVAL3_10   BIT10
 set     PWMA_SM0CVAL3_CAPTVAL3_11   BIT11
 set     PWMA_SM0CVAL3_CAPTVAL3_12   BIT12
 set     PWMA_SM0CVAL3_CAPTVAL3_13   BIT13
 set     PWMA_SM0CVAL3_CAPTVAL3_14   BIT14
 set     PWMA_SM0CVAL3_CAPTVAL3_15   BIT15

 set     PWMA_SM0CVAL3CYC_CVAL3CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM0CVAL3CYC_CVAL3CYC_0 BIT0
 set     PWMA_SM0CVAL3CYC_CVAL3CYC_1 BIT1
 set     PWMA_SM0CVAL3CYC_CVAL3CYC_2 BIT2
 set     PWMA_SM0CVAL3CYC_CVAL3CYC_3 BIT3

 set     PWMA_SM0CVAL4_CAPTVAL4      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM0CVAL4_CAPTVAL4_0    BIT0
 set     PWMA_SM0CVAL4_CAPTVAL4_1    BIT1
 set     PWMA_SM0CVAL4_CAPTVAL4_2    BIT2
 set     PWMA_SM0CVAL4_CAPTVAL4_3    BIT3
 set     PWMA_SM0CVAL4_CAPTVAL4_4    BIT4
 set     PWMA_SM0CVAL4_CAPTVAL4_5    BIT5
 set     PWMA_SM0CVAL4_CAPTVAL4_6    BIT6
 set     PWMA_SM0CVAL4_CAPTVAL4_7    BIT7
 set     PWMA_SM0CVAL4_CAPTVAL4_8    BIT8
 set     PWMA_SM0CVAL4_CAPTVAL4_9    BIT9
 set     PWMA_SM0CVAL4_CAPTVAL4_10   BIT10
 set     PWMA_SM0CVAL4_CAPTVAL4_11   BIT11
 set     PWMA_SM0CVAL4_CAPTVAL4_12   BIT12
 set     PWMA_SM0CVAL4_CAPTVAL4_13   BIT13
 set     PWMA_SM0CVAL4_CAPTVAL4_14   BIT14
 set     PWMA_SM0CVAL4_CAPTVAL4_15   BIT15

 set     PWMA_SM0CVAL4CYC_CVAL4CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM0CVAL4CYC_CVAL4CYC_0 BIT0
 set     PWMA_SM0CVAL4CYC_CVAL4CYC_1 BIT1
 set     PWMA_SM0CVAL4CYC_CVAL4CYC_2 BIT2
 set     PWMA_SM0CVAL4CYC_CVAL4CYC_3 BIT3

 set     PWMA_SM0CVAL5_CAPTVAL5      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM0CVAL5_CAPTVAL5_0    BIT0
 set     PWMA_SM0CVAL5_CAPTVAL5_1    BIT1
 set     PWMA_SM0CVAL5_CAPTVAL5_2    BIT2
 set     PWMA_SM0CVAL5_CAPTVAL5_3    BIT3
 set     PWMA_SM0CVAL5_CAPTVAL5_4    BIT4
 set     PWMA_SM0CVAL5_CAPTVAL5_5    BIT5
 set     PWMA_SM0CVAL5_CAPTVAL5_6    BIT6
 set     PWMA_SM0CVAL5_CAPTVAL5_7    BIT7
 set     PWMA_SM0CVAL5_CAPTVAL5_8    BIT8
 set     PWMA_SM0CVAL5_CAPTVAL5_9    BIT9
 set     PWMA_SM0CVAL5_CAPTVAL5_10   BIT10
 set     PWMA_SM0CVAL5_CAPTVAL5_11   BIT11
 set     PWMA_SM0CVAL5_CAPTVAL5_12   BIT12
 set     PWMA_SM0CVAL5_CAPTVAL5_13   BIT13
 set     PWMA_SM0CVAL5_CAPTVAL5_14   BIT14
 set     PWMA_SM0CVAL5_CAPTVAL5_15   BIT15

 set     PWMA_SM0CVAL5CYC_CVAL5CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM0CVAL5CYC_CVAL5CYC_0 BIT0
 set     PWMA_SM0CVAL5CYC_CVAL5CYC_1 BIT1
 set     PWMA_SM0CVAL5CYC_CVAL5CYC_2 BIT2
 set     PWMA_SM0CVAL5CYC_CVAL5CYC_3 BIT3

 set     PWMA_SM1CNT_CNT             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Counter Register Bits
 set     PWMA_SM1CNT_CNT_0           BIT0
 set     PWMA_SM1CNT_CNT_1           BIT1
 set     PWMA_SM1CNT_CNT_2           BIT2
 set     PWMA_SM1CNT_CNT_3           BIT3
 set     PWMA_SM1CNT_CNT_4           BIT4
 set     PWMA_SM1CNT_CNT_5           BIT5
 set     PWMA_SM1CNT_CNT_6           BIT6
 set     PWMA_SM1CNT_CNT_7           BIT7
 set     PWMA_SM1CNT_CNT_8           BIT8
 set     PWMA_SM1CNT_CNT_9           BIT9
 set     PWMA_SM1CNT_CNT_10          BIT10
 set     PWMA_SM1CNT_CNT_11          BIT11
 set     PWMA_SM1CNT_CNT_12          BIT12
 set     PWMA_SM1CNT_CNT_13          BIT13
 set     PWMA_SM1CNT_CNT_14          BIT14
 set     PWMA_SM1CNT_CNT_15          BIT15

 set     PWMA_SM1INIT_INIT           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Initial Count Register Bits
 set     PWMA_SM1INIT_INIT_0         BIT0
 set     PWMA_SM1INIT_INIT_1         BIT1
 set     PWMA_SM1INIT_INIT_2         BIT2
 set     PWMA_SM1INIT_INIT_3         BIT3
 set     PWMA_SM1INIT_INIT_4         BIT4
 set     PWMA_SM1INIT_INIT_5         BIT5
 set     PWMA_SM1INIT_INIT_6         BIT6
 set     PWMA_SM1INIT_INIT_7         BIT7
 set     PWMA_SM1INIT_INIT_8         BIT8
 set     PWMA_SM1INIT_INIT_9         BIT9
 set     PWMA_SM1INIT_INIT_10        BIT10
 set     PWMA_SM1INIT_INIT_11        BIT11
 set     PWMA_SM1INIT_INIT_12        BIT12
 set     PWMA_SM1INIT_INIT_13        BIT13
 set     PWMA_SM1INIT_INIT_14        BIT14
 set     PWMA_SM1INIT_INIT_15        BIT15

 set     PWMA_SM1CTRL2_CLK_SEL       (BIT0|BIT1)
;;   Clock Source Select
;;     0b00 ==> The IPBus clock is used as the clock for the local prescaler and counter.
;;     0b01 ==> EXT_CLK is used as the clock for the local prescaler and counter.
;;     0b10 ==> Submodule 0's clock (AUX_CLK) is used as the source clock for the local prescaler and counter. This setting should not be used in submodule 0 as it will force the clock to logic 0.
;;     0b11 ==> reserved
 set     PWMA_SM1CTRL2_CLK_SEL_0     BIT0
 set     PWMA_SM1CTRL2_CLK_SEL_1     BIT1

 set     PWMA_SM1CTRL2_RELOAD_SEL    BIT2
;;   Reload Source Select
;;     0b0 ==> The local RELOAD signal is used to reload registers.
;;     0b1 ==> The master RELOAD signal (from submodule 0) is used to reload registers. This setting should not be used in submodule 0 as it will force the RELOAD signal to logic 0.

 set     PWMA_SM1CTRL2_FORCE_SEL     (BIT3|BIT4|BIT5)
;;   This read/write bit determines the source of the FORCE OUTPUT signal for this submodule.
;;     0b000 ==> The local force signal, CTRL2[FORCE], from this submodule is used to force updates.
;;     0b001 ==> The master force signal from submodule 0 is used to force updates. This setting should not be used in submodule 0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b010 ==> The local reload signal from this submodule is used to force updates without regard to the state of LDOK.
;;     0b011 ==> The master reload signal from submodule0 is used to force updates if LDOK is set. This setting should not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b100 ==> The local sync signal from this submodule is used to force updates.
;;     0b101 ==> The master sync signal from submodule0 is used to force updates. This setting should not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b110 ==> The external force signal, EXT_FORCE, from outside the PWM module causes updates.
;;     0b111 ==> reserved
 set     PWMA_SM1CTRL2_FORCE_SEL_0   BIT3
 set     PWMA_SM1CTRL2_FORCE_SEL_1   BIT4
 set     PWMA_SM1CTRL2_FORCE_SEL_2   BIT5

 set     PWMA_SM1CTRL2_FORCE         BIT6
;;   Force Initialization

 set     PWMA_SM1CTRL2_FRCEN         BIT7
;;   Force Initialization Enable
;;     0b0 ==> Initialization from a FORCE_OUT event is disabled.
;;     0b1 ==> Initialization from a FORCE_OUT event is enabled.

 set     PWMA_SM1CTRL2_INIT_SEL      (BIT8|BIT9)
;;   Initialization Control Select
;;     0b00 ==> Local sync (PWM_X) causes initialization.
;;     0b01 ==> Master reload from submodule 0 causes initialization. This setting should not be used in submodule 0 as it will force the INIT signal to logic 0.
;;     0b10 ==> Master sync from submodule 0 causes initialization. This setting should not be used in submodule 0 as it will force the INIT signal to logic 0.
;;     0b11 ==> EXT_SYNC causes initialization.
 set     PWMA_SM1CTRL2_INIT_SEL_0    BIT8
 set     PWMA_SM1CTRL2_INIT_SEL_1    BIT9

 set     PWMA_SM1CTRL2_PWMX_INIT     BIT10
;;   PWM_X Initial Value

 set     PWMA_SM1CTRL2_PWM45_INIT    BIT11
;;   PWM45 Initial Value

 set     PWMA_SM1CTRL2_PWM23_INIT    BIT12
;;   PWM23 Initial Value

 set     PWMA_SM1CTRL2_INDEP         BIT13
;;   Independent or Complementary Pair Operation
;;     0b0 ==> PWM_A and PWM_B form a complementary PWM pair.
;;     0b1 ==> PWM_A and PWM_B outputs are independent PWMs.

 set     PWMA_SM1CTRL2_WAITEN        BIT14
;;   WAIT Enable

 set     PWMA_SM1CTRL2_DBGEN         BIT15
;;   Debug Enable

 set     PWMA_SM1CTRL_DBLEN          BIT0
;;   Double Switching Enable
;;     0b0 ==> Double switching disabled.
;;     0b1 ==> Double switching enabled.

 set     PWMA_SM1CTRL_DBLX           BIT1
;;   PWMX Double Switching Enable
;;     0b0 ==> PWMX double pulse disabled
;;     0b1 ==> PWMX double pulse enabled

 set     PWMA_SM1CTRL_LDMOD          BIT2
;;   Load Mode Select
;;     0b0 ==> Buffered registers of this submodule are loaded and take effect at the next PWM reload if MCTRL[LDOK] is set.
;;     0b1 ==> Buffered registers of this submodule are loaded and take effect immediately upon MCTRL[LDOK] being set.

 set     PWMA_SM1CTRL_SPLIT          BIT3
;;   Split the DBLPWM signal to PWMA and PWMB
;;     0b0 ==> DBLPWM is not split. PWMA and PWMB each have double pulses.
;;     0b1 ==> DBLPWM is split to PWMA and PWMB.

 set     PWMA_SM1CTRL_PRSC           (BIT4|BIT5|BIT6)
;;   Prescaler
;;     0b000 ==> PWM clock frequency = fclk
;;     0b001 ==> PWM clock frequency = fclk/2
;;     0b010 ==> PWM clock frequency = fclk/4
;;     0b011 ==> PWM clock frequency = fclk/8
;;     0b100 ==> PWM clock frequency = fclk/16
;;     0b101 ==> PWM clock frequency = fclk/32
;;     0b110 ==> PWM clock frequency = fclk/64
;;     0b111 ==> PWM clock frequency = fclk/128
 set     PWMA_SM1CTRL_PRSC_0         BIT4
 set     PWMA_SM1CTRL_PRSC_1         BIT5
 set     PWMA_SM1CTRL_PRSC_2         BIT6

 set     PWMA_SM1CTRL_DT             (BIT8|BIT9)
;;   Deadtime
 set     PWMA_SM1CTRL_DT_0           BIT8
 set     PWMA_SM1CTRL_DT_1           BIT9

 set     PWMA_SM1CTRL_FULL           BIT10
;;   Full Cycle Reload
;;     0b0 ==> Full-cycle reloads disabled.
;;     0b1 ==> Full-cycle reloads enabled.

 set     PWMA_SM1CTRL_HALF           BIT11
;;   Half Cycle Reload
;;     0b0 ==> Half-cycle reloads disabled.
;;     0b1 ==> Half-cycle reloads enabled.

 set     PWMA_SM1CTRL_LDFQ           (BIT12|BIT13|BIT14|BIT15)
;;     0b0000 ==> Every PWM opportunity
;;     0b0001 ==> Every 2 PWM opportunities
;;     0b0010 ==> Every 3 PWM opportunities
;;     0b0011 ==> Every 4 PWM opportunities
;;     0b0100 ==> Every 5 PWM opportunities
;;     0b0101 ==> Every 6 PWM opportunities
;;     0b0110 ==> Every 7 PWM opportunities
;;     0b0111 ==> Every 8 PWM opportunities
;;     0b1000 ==> Every 9 PWM opportunities
;;     0b1001 ==> Every 10 PWM opportunities
;;     0b1010 ==> Every 11 PWM opportunities
;;     0b1011 ==> Every 12 PWM opportunities
;;     0b1100 ==> Every 13 PWM opportunities
;;     0b1101 ==> Every 14 PWM opportunities
;;     0b1110 ==> Every 15 PWM opportunities
;;     0b1111 ==> Every 16 PWM opportunities
 set     PWMA_SM1CTRL_LDFQ_0         BIT12
 set     PWMA_SM1CTRL_LDFQ_1         BIT13
 set     PWMA_SM1CTRL_LDFQ_2         BIT14
 set     PWMA_SM1CTRL_LDFQ_3         BIT15

 set     PWMA_SM1VAL0_VAL0           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 0
 set     PWMA_SM1VAL0_VAL0_0         BIT0
 set     PWMA_SM1VAL0_VAL0_1         BIT1
 set     PWMA_SM1VAL0_VAL0_2         BIT2
 set     PWMA_SM1VAL0_VAL0_3         BIT3
 set     PWMA_SM1VAL0_VAL0_4         BIT4
 set     PWMA_SM1VAL0_VAL0_5         BIT5
 set     PWMA_SM1VAL0_VAL0_6         BIT6
 set     PWMA_SM1VAL0_VAL0_7         BIT7
 set     PWMA_SM1VAL0_VAL0_8         BIT8
 set     PWMA_SM1VAL0_VAL0_9         BIT9
 set     PWMA_SM1VAL0_VAL0_10        BIT10
 set     PWMA_SM1VAL0_VAL0_11        BIT11
 set     PWMA_SM1VAL0_VAL0_12        BIT12
 set     PWMA_SM1VAL0_VAL0_13        BIT13
 set     PWMA_SM1VAL0_VAL0_14        BIT14
 set     PWMA_SM1VAL0_VAL0_15        BIT15

 set     PWMA_SM1FRACVAL1_FRACVAL1   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 1 Register
 set     PWMA_SM1FRACVAL1_FRACVAL1_0 BIT11
 set     PWMA_SM1FRACVAL1_FRACVAL1_1 BIT12
 set     PWMA_SM1FRACVAL1_FRACVAL1_2 BIT13
 set     PWMA_SM1FRACVAL1_FRACVAL1_3 BIT14
 set     PWMA_SM1FRACVAL1_FRACVAL1_4 BIT15

 set     PWMA_SM1VAL1_VAL1           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 1
 set     PWMA_SM1VAL1_VAL1_0         BIT0
 set     PWMA_SM1VAL1_VAL1_1         BIT1
 set     PWMA_SM1VAL1_VAL1_2         BIT2
 set     PWMA_SM1VAL1_VAL1_3         BIT3
 set     PWMA_SM1VAL1_VAL1_4         BIT4
 set     PWMA_SM1VAL1_VAL1_5         BIT5
 set     PWMA_SM1VAL1_VAL1_6         BIT6
 set     PWMA_SM1VAL1_VAL1_7         BIT7
 set     PWMA_SM1VAL1_VAL1_8         BIT8
 set     PWMA_SM1VAL1_VAL1_9         BIT9
 set     PWMA_SM1VAL1_VAL1_10        BIT10
 set     PWMA_SM1VAL1_VAL1_11        BIT11
 set     PWMA_SM1VAL1_VAL1_12        BIT12
 set     PWMA_SM1VAL1_VAL1_13        BIT13
 set     PWMA_SM1VAL1_VAL1_14        BIT14
 set     PWMA_SM1VAL1_VAL1_15        BIT15

 set     PWMA_SM1FRACVAL2_FRACVAL2   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 2
 set     PWMA_SM1FRACVAL2_FRACVAL2_0 BIT11
 set     PWMA_SM1FRACVAL2_FRACVAL2_1 BIT12
 set     PWMA_SM1FRACVAL2_FRACVAL2_2 BIT13
 set     PWMA_SM1FRACVAL2_FRACVAL2_3 BIT14
 set     PWMA_SM1FRACVAL2_FRACVAL2_4 BIT15

 set     PWMA_SM1VAL2_VAL2           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 2
 set     PWMA_SM1VAL2_VAL2_0         BIT0
 set     PWMA_SM1VAL2_VAL2_1         BIT1
 set     PWMA_SM1VAL2_VAL2_2         BIT2
 set     PWMA_SM1VAL2_VAL2_3         BIT3
 set     PWMA_SM1VAL2_VAL2_4         BIT4
 set     PWMA_SM1VAL2_VAL2_5         BIT5
 set     PWMA_SM1VAL2_VAL2_6         BIT6
 set     PWMA_SM1VAL2_VAL2_7         BIT7
 set     PWMA_SM1VAL2_VAL2_8         BIT8
 set     PWMA_SM1VAL2_VAL2_9         BIT9
 set     PWMA_SM1VAL2_VAL2_10        BIT10
 set     PWMA_SM1VAL2_VAL2_11        BIT11
 set     PWMA_SM1VAL2_VAL2_12        BIT12
 set     PWMA_SM1VAL2_VAL2_13        BIT13
 set     PWMA_SM1VAL2_VAL2_14        BIT14
 set     PWMA_SM1VAL2_VAL2_15        BIT15

 set     PWMA_SM1FRACVAL3_FRACVAL3   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 3
 set     PWMA_SM1FRACVAL3_FRACVAL3_0 BIT11
 set     PWMA_SM1FRACVAL3_FRACVAL3_1 BIT12
 set     PWMA_SM1FRACVAL3_FRACVAL3_2 BIT13
 set     PWMA_SM1FRACVAL3_FRACVAL3_3 BIT14
 set     PWMA_SM1FRACVAL3_FRACVAL3_4 BIT15

 set     PWMA_SM1VAL3_VAL3           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 3
 set     PWMA_SM1VAL3_VAL3_0         BIT0
 set     PWMA_SM1VAL3_VAL3_1         BIT1
 set     PWMA_SM1VAL3_VAL3_2         BIT2
 set     PWMA_SM1VAL3_VAL3_3         BIT3
 set     PWMA_SM1VAL3_VAL3_4         BIT4
 set     PWMA_SM1VAL3_VAL3_5         BIT5
 set     PWMA_SM1VAL3_VAL3_6         BIT6
 set     PWMA_SM1VAL3_VAL3_7         BIT7
 set     PWMA_SM1VAL3_VAL3_8         BIT8
 set     PWMA_SM1VAL3_VAL3_9         BIT9
 set     PWMA_SM1VAL3_VAL3_10        BIT10
 set     PWMA_SM1VAL3_VAL3_11        BIT11
 set     PWMA_SM1VAL3_VAL3_12        BIT12
 set     PWMA_SM1VAL3_VAL3_13        BIT13
 set     PWMA_SM1VAL3_VAL3_14        BIT14
 set     PWMA_SM1VAL3_VAL3_15        BIT15

 set     PWMA_SM1FRACVAL4_FRACVAL4   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 4
 set     PWMA_SM1FRACVAL4_FRACVAL4_0 BIT11
 set     PWMA_SM1FRACVAL4_FRACVAL4_1 BIT12
 set     PWMA_SM1FRACVAL4_FRACVAL4_2 BIT13
 set     PWMA_SM1FRACVAL4_FRACVAL4_3 BIT14
 set     PWMA_SM1FRACVAL4_FRACVAL4_4 BIT15

 set     PWMA_SM1VAL4_VAL4           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 4
 set     PWMA_SM1VAL4_VAL4_0         BIT0
 set     PWMA_SM1VAL4_VAL4_1         BIT1
 set     PWMA_SM1VAL4_VAL4_2         BIT2
 set     PWMA_SM1VAL4_VAL4_3         BIT3
 set     PWMA_SM1VAL4_VAL4_4         BIT4
 set     PWMA_SM1VAL4_VAL4_5         BIT5
 set     PWMA_SM1VAL4_VAL4_6         BIT6
 set     PWMA_SM1VAL4_VAL4_7         BIT7
 set     PWMA_SM1VAL4_VAL4_8         BIT8
 set     PWMA_SM1VAL4_VAL4_9         BIT9
 set     PWMA_SM1VAL4_VAL4_10        BIT10
 set     PWMA_SM1VAL4_VAL4_11        BIT11
 set     PWMA_SM1VAL4_VAL4_12        BIT12
 set     PWMA_SM1VAL4_VAL4_13        BIT13
 set     PWMA_SM1VAL4_VAL4_14        BIT14
 set     PWMA_SM1VAL4_VAL4_15        BIT15

 set     PWMA_SM1FRACVAL5_FRACVAL5   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 5
 set     PWMA_SM1FRACVAL5_FRACVAL5_0 BIT11
 set     PWMA_SM1FRACVAL5_FRACVAL5_1 BIT12
 set     PWMA_SM1FRACVAL5_FRACVAL5_2 BIT13
 set     PWMA_SM1FRACVAL5_FRACVAL5_3 BIT14
 set     PWMA_SM1FRACVAL5_FRACVAL5_4 BIT15

 set     PWMA_SM1VAL5_VAL5           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 5
 set     PWMA_SM1VAL5_VAL5_0         BIT0
 set     PWMA_SM1VAL5_VAL5_1         BIT1
 set     PWMA_SM1VAL5_VAL5_2         BIT2
 set     PWMA_SM1VAL5_VAL5_3         BIT3
 set     PWMA_SM1VAL5_VAL5_4         BIT4
 set     PWMA_SM1VAL5_VAL5_5         BIT5
 set     PWMA_SM1VAL5_VAL5_6         BIT6
 set     PWMA_SM1VAL5_VAL5_7         BIT7
 set     PWMA_SM1VAL5_VAL5_8         BIT8
 set     PWMA_SM1VAL5_VAL5_9         BIT9
 set     PWMA_SM1VAL5_VAL5_10        BIT10
 set     PWMA_SM1VAL5_VAL5_11        BIT11
 set     PWMA_SM1VAL5_VAL5_12        BIT12
 set     PWMA_SM1VAL5_VAL5_13        BIT13
 set     PWMA_SM1VAL5_VAL5_14        BIT14
 set     PWMA_SM1VAL5_VAL5_15        BIT15

 set     PWMA_SM1FRCTRL_FRAC1_EN     BIT1
;;   Fractional Cycle PWM Period Enable
;;     0b0 ==> Disable fractional cycle length for the PWM period.
;;     0b1 ==> Enable fractional cycle length for the PWM period.

 set     PWMA_SM1FRCTRL_FRAC23_EN    BIT2
;;   Fractional Cycle Placement Enable fpr PWM_A
;;     0b0 ==> Disable fractional cycle placement for PWM_A.
;;     0b1 ==> Enable fractional cycle placement for PWM_A.

 set     PWMA_SM1FRCTRL_FRAC45_EN    BIT4
;;   Fractional Cycle Placement Enable fpr PWM_B
;;     0b0 ==> Disable fractional cycle placement for PWM_B.
;;     0b1 ==> Enable fractional cycle placement for PWM_B.

 set     PWMA_SM1FRCTRL_FRAC_PU      BIT8
;;   Fractional Delay Circuit Power Up
;;     0b0 ==> Turn off fractional delay logic.
;;     0b1 ==> Power up fractional delay logic.

 set     PWMA_SM1FRCTRL_TEST         BIT15
;;   Test Status Bit

 set     PWMA_SM1OCTRL_PWMXFS        (BIT0|BIT1)
;;   PWM_X Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM1OCTRL_PWMXFS_0      BIT0
 set     PWMA_SM1OCTRL_PWMXFS_1      BIT1

 set     PWMA_SM1OCTRL_PWMBFS        (BIT2|BIT3)
;;   PWM_B Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM1OCTRL_PWMBFS_0      BIT2
 set     PWMA_SM1OCTRL_PWMBFS_1      BIT3

 set     PWMA_SM1OCTRL_PWMAFS        (BIT4|BIT5)
;;   PWM_A Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM1OCTRL_PWMAFS_0      BIT4
 set     PWMA_SM1OCTRL_PWMAFS_1      BIT5

 set     PWMA_SM1OCTRL_POLX          BIT8
;;   PWM_X Output Polarity
;;     0b0 ==> PWM_X output not inverted. A high level on the PWM_X pin represents the "on" or "active" state.
;;     0b1 ==> PWM_X output inverted. A low level on the PWM_X pin represents the "on" or "active" state.

 set     PWMA_SM1OCTRL_POLB          BIT9
;;   PWM_B Output Polarity
;;     0b0 ==> PWM_B output not inverted. A high level on the PWM_B pin represents the "on" or "active" state.
;;     0b1 ==> PWM_B output inverted. A low level on the PWM_B pin represents the "on" or "active" state.

 set     PWMA_SM1OCTRL_POLA          BIT10
;;   PWM_A Output Polarity
;;     0b0 ==> PWM_A output not inverted. A high level on the PWM_A pin represents the "on" or "active" state.
;;     0b1 ==> PWM_A output inverted. A low level on the PWM_A pin represents the "on" or "active" state.

 set     PWMA_SM1OCTRL_PWMX_IN       BIT13
;;   PWM_X Input

 set     PWMA_SM1OCTRL_PWMB_IN       BIT14
;;   PWM_B Input

 set     PWMA_SM1OCTRL_PWMA_IN       BIT15
;;   PWM_A Input

 set     PWMA_SM1STS_CMPF            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Compare Flags
;;     0b0 ==> No compare event has occurred for a particular VALx value.
;;     0b1 ==> A compare event has occurred for a particular VALx value.
 set     PWMA_SM1STS_CMPF_0          BIT0
 set     PWMA_SM1STS_CMPF_1          BIT1
 set     PWMA_SM1STS_CMPF_2          BIT2
 set     PWMA_SM1STS_CMPF_3          BIT3
 set     PWMA_SM1STS_CMPF_4          BIT4
 set     PWMA_SM1STS_CMPF_5          BIT5

 set     PWMA_SM1STS_CFX0            BIT6
;;   Capture Flag X0

 set     PWMA_SM1STS_CFX1            BIT7
;;   Capture Flag X1

 set     PWMA_SM1STS_CFB0            BIT8
;;   Capture Flag B0

 set     PWMA_SM1STS_CFB1            BIT9
;;   Capture Flag B1

 set     PWMA_SM1STS_CFA0            BIT10
;;   Capture Flag A0

 set     PWMA_SM1STS_CFA1            BIT11
;;   Capture Flag A1

 set     PWMA_SM1STS_RF              BIT12
;;   Reload Flag
;;     0b0 ==> No new reload cycle since last STS[RF] clearing
;;     0b1 ==> New reload cycle since last STS[RF] clearing

 set     PWMA_SM1STS_REF             BIT13
;;   Reload Error Flag
;;     0b0 ==> No reload error occurred.
;;     0b1 ==> Reload signal occurred with non-coherent data and MCTRL[LDOK] = 0.

 set     PWMA_SM1STS_RUF             BIT14
;;   Registers Updated Flag
;;     0b0 ==> No register update has occurred since last reload.
;;     0b1 ==> At least one of the double buffered registers has been updated since the last reload.

 set     PWMA_SM1INTEN_CMPIE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Compare Interrupt Enables
;;     0b0 ==> The corresponding STS[CMPF] bit will not cause an interrupt request.
;;     0b1 ==> The corresponding STS[CMPF] bit will cause an interrupt request.
 set     PWMA_SM1INTEN_CMPIE_0       BIT0
 set     PWMA_SM1INTEN_CMPIE_1       BIT1
 set     PWMA_SM1INTEN_CMPIE_2       BIT2
 set     PWMA_SM1INTEN_CMPIE_3       BIT3
 set     PWMA_SM1INTEN_CMPIE_4       BIT4
 set     PWMA_SM1INTEN_CMPIE_5       BIT5

 set     PWMA_SM1INTEN_CX0IE         BIT6
;;   Capture X 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFX0].
;;     0b1 ==> Interrupt request enabled for STS[CFX0].

 set     PWMA_SM1INTEN_CX1IE         BIT7
;;   Capture X 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFX1].
;;     0b1 ==> Interrupt request enabled for STS[CFX1].

 set     PWMA_SM1INTEN_CB0IE         BIT8
;;   Capture B 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFB0].
;;     0b1 ==> Interrupt request enabled for STS[CFB0].

 set     PWMA_SM1INTEN_CB1IE         BIT9
;;   Capture B 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFB1].
;;     0b1 ==> Interrupt request enabled for STS[CFB1].

 set     PWMA_SM1INTEN_CA0IE         BIT10
;;   Capture A 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFA0].
;;     0b1 ==> Interrupt request enabled for STS[CFA0].

 set     PWMA_SM1INTEN_CA1IE         BIT11
;;   Capture A 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFA1].
;;     0b1 ==> Interrupt request enabled for STS[CFA1].

 set     PWMA_SM1INTEN_RIE           BIT12
;;   Reload Interrupt Enable
;;     0b0 ==> STS[RF] CPU interrupt requests disabled
;;     0b1 ==> STS[RF] CPU interrupt requests enabled

 set     PWMA_SM1INTEN_REIE          BIT13
;;   Reload Error Interrupt Enable
;;     0b0 ==> STS[REF] CPU interrupt requests disabled
;;     0b1 ==> STS[REF] CPU interrupt requests enabled

 set     PWMA_SM1DMAEN_CX0DE         BIT0
;;   Capture X0 FIFO DMA Enable

 set     PWMA_SM1DMAEN_CX1DE         BIT1
;;   Capture X1 FIFO DMA Enable

 set     PWMA_SM1DMAEN_CB0DE         BIT2
;;   Capture B0 FIFO DMA Enable

 set     PWMA_SM1DMAEN_CB1DE         BIT3
;;   Capture B1 FIFO DMA Enable

 set     PWMA_SM1DMAEN_CA0DE         BIT4
;;   Capture A0 FIFO DMA Enable

 set     PWMA_SM1DMAEN_CA1DE         BIT5
;;   Capture A1 FIFO DMA Enable

 set     PWMA_SM1DMAEN_CAPTDE        (BIT6|BIT7)
;;   Capture DMA Enable Source Select
;;     0b00 ==> Read DMA requests disabled.
;;     0b01 ==> Exceeding a FIFO watermark sets the DMA read request. This requires at least one of DMAEN[CA1DE], DMAEN[CA0DE], DMAEN[CB1DE], DMAEN[CB0DE], DMAEN[CX1DE], or DMAEN[CX0DE] to also be set in order to determine to which watermark(s) the DMA request is sensitive.
;;     0b10 ==> A local sync (VAL1 matches counter) sets the read DMA request.
;;     0b11 ==> A local reload (STS[RF] being set) sets the read DMA request.
 set     PWMA_SM1DMAEN_CAPTDE_0      BIT6
 set     PWMA_SM1DMAEN_CAPTDE_1      BIT7

 set     PWMA_SM1DMAEN_FAND          BIT8
;;   FIFO Watermark AND Control
;;     0b0 ==> Selected FIFO watermarks are OR'ed together.
;;     0b1 ==> Selected FIFO watermarks are AND'ed together.

 set     PWMA_SM1DMAEN_VALDE         BIT9
;;   Value Registers DMA Enable
;;     0b0 ==> DMA write requests disabled
;;     0b1 ==> DMA write requests for the VALx and FRACVALx registers enabled

 set     PWMA_SM1TCTRL_OUT_TRIG_EN   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Output Trigger Enables
;;     0b0 ==> PWM_OUT_TRIGx will not set when the counter value matches the VALx value.
;;     0b1 ==> PWM_OUT_TRIGx will set when the counter value matches the VALx value.
 set     PWMA_SM1TCTRL_OUT_TRIG_EN_0 BIT0
 set     PWMA_SM1TCTRL_OUT_TRIG_EN_1 BIT1
 set     PWMA_SM1TCTRL_OUT_TRIG_EN_2 BIT2
 set     PWMA_SM1TCTRL_OUT_TRIG_EN_3 BIT3
 set     PWMA_SM1TCTRL_OUT_TRIG_EN_4 BIT4
 set     PWMA_SM1TCTRL_OUT_TRIG_EN_5 BIT5

 set     PWMA_SM1TCTRL_PWBOT1        BIT14
;;   Output Trigger 1 Source Select
;;     0b0 ==> Route the PWM_OUT_TRIG1 signal to PWM_OUT_TRIG1 port.
;;     0b1 ==> Route the PWMB output to the PWM_OUT_TRIG1 port.

 set     PWMA_SM1TCTRL_PWAOT0        BIT15
;;   Output Trigger 0 Source Select
;;     0b0 ==> Route the PWM_OUT_TRIG0 signal to PWM_OUT_TRIG0 port.
;;     0b1 ==> Route the PWMA output to the PWM_OUT_TRIG0 port.

 set     PWMA_SM1DISMAP0_DIS0A       (BIT0|BIT1|BIT2|BIT3)
;;   PWM_A Fault Disable Mask 0
 set     PWMA_SM1DISMAP0_DIS0A_0     BIT0
 set     PWMA_SM1DISMAP0_DIS0A_1     BIT1
 set     PWMA_SM1DISMAP0_DIS0A_2     BIT2
 set     PWMA_SM1DISMAP0_DIS0A_3     BIT3

 set     PWMA_SM1DISMAP0_DIS0B       (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Fault Disable Mask 0
 set     PWMA_SM1DISMAP0_DIS0B_0     BIT4
 set     PWMA_SM1DISMAP0_DIS0B_1     BIT5
 set     PWMA_SM1DISMAP0_DIS0B_2     BIT6
 set     PWMA_SM1DISMAP0_DIS0B_3     BIT7

 set     PWMA_SM1DISMAP0_DIS0X       (BIT8|BIT9|BIT10|BIT11)
;;   PWM_X Fault Disable Mask 0
 set     PWMA_SM1DISMAP0_DIS0X_0     BIT8
 set     PWMA_SM1DISMAP0_DIS0X_1     BIT9
 set     PWMA_SM1DISMAP0_DIS0X_2     BIT10
 set     PWMA_SM1DISMAP0_DIS0X_3     BIT11

 set     PWMA_SM1DISMAP1_DIS1A       (BIT0|BIT1|BIT2|BIT3)
;;   PWM_A Fault Disable Mask 1
 set     PWMA_SM1DISMAP1_DIS1A_0     BIT0
 set     PWMA_SM1DISMAP1_DIS1A_1     BIT1
 set     PWMA_SM1DISMAP1_DIS1A_2     BIT2
 set     PWMA_SM1DISMAP1_DIS1A_3     BIT3

 set     PWMA_SM1DISMAP1_DIS1B       (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Fault Disable Mask 1
 set     PWMA_SM1DISMAP1_DIS1B_0     BIT4
 set     PWMA_SM1DISMAP1_DIS1B_1     BIT5
 set     PWMA_SM1DISMAP1_DIS1B_2     BIT6
 set     PWMA_SM1DISMAP1_DIS1B_3     BIT7

 set     PWMA_SM1DISMAP1_DIS1X       (BIT8|BIT9|BIT10|BIT11)
;;   PWM_X Fault Disable Mask 1
 set     PWMA_SM1DISMAP1_DIS1X_0     BIT8
 set     PWMA_SM1DISMAP1_DIS1X_1     BIT9
 set     PWMA_SM1DISMAP1_DIS1X_2     BIT10
 set     PWMA_SM1DISMAP1_DIS1X_3     BIT11

 set     PWMA_SM1DTCNT0_DTCNT0       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   Deadtime Count Register 0
 set     PWMA_SM1DTCNT0_DTCNT0_0     BIT0
 set     PWMA_SM1DTCNT0_DTCNT0_1     BIT1
 set     PWMA_SM1DTCNT0_DTCNT0_2     BIT2
 set     PWMA_SM1DTCNT0_DTCNT0_3     BIT3
 set     PWMA_SM1DTCNT0_DTCNT0_4     BIT4
 set     PWMA_SM1DTCNT0_DTCNT0_5     BIT5
 set     PWMA_SM1DTCNT0_DTCNT0_6     BIT6
 set     PWMA_SM1DTCNT0_DTCNT0_7     BIT7
 set     PWMA_SM1DTCNT0_DTCNT0_8     BIT8
 set     PWMA_SM1DTCNT0_DTCNT0_9     BIT9
 set     PWMA_SM1DTCNT0_DTCNT0_10    BIT10

 set     PWMA_SM1DTCNT1_DTCNT1       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   Deadtime Count Register 1
 set     PWMA_SM1DTCNT1_DTCNT1_0     BIT0
 set     PWMA_SM1DTCNT1_DTCNT1_1     BIT1
 set     PWMA_SM1DTCNT1_DTCNT1_2     BIT2
 set     PWMA_SM1DTCNT1_DTCNT1_3     BIT3
 set     PWMA_SM1DTCNT1_DTCNT1_4     BIT4
 set     PWMA_SM1DTCNT1_DTCNT1_5     BIT5
 set     PWMA_SM1DTCNT1_DTCNT1_6     BIT6
 set     PWMA_SM1DTCNT1_DTCNT1_7     BIT7
 set     PWMA_SM1DTCNT1_DTCNT1_8     BIT8
 set     PWMA_SM1DTCNT1_DTCNT1_9     BIT9
 set     PWMA_SM1DTCNT1_DTCNT1_10    BIT10

 set     PWMA_SM1CAPTCTRLA_ARMA      BIT0
;;   Arm A
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLA[EDGAx] is enabled.

 set     PWMA_SM1CAPTCTRLA_ONESHOTA  BIT1
;;   One Shot Mode A
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLA[ARMA] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLA[ARMA] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and CAPTCTRLA[ARMA] is cleared. No further captures will be performed until CAPTCTRLA[ARMA] is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled
;;             capture circuit and CAPTCTRLA[ARMA] is then cleared.

 set     PWMA_SM1CAPTCTRLA_EDGA0     (BIT2|BIT3)
;;   Edge A 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM1CAPTCTRLA_EDGA0_0   BIT2
 set     PWMA_SM1CAPTCTRLA_EDGA0_1   BIT3

 set     PWMA_SM1CAPTCTRLA_EDGA1     (BIT4|BIT5)
;;   Edge A 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM1CAPTCTRLA_EDGA1_0   BIT4
 set     PWMA_SM1CAPTCTRLA_EDGA1_1   BIT5

 set     PWMA_SM1CAPTCTRLA_INP_SELA  BIT6
;;   Input Select A
;;     0b0 ==> Raw PWM_A input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLA[EDGA0] and CAPTCTRLA[EDGA1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRA[EDGA0] and/or CAPTCTRLA[EDGA1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM1CAPTCTRLA_EDGCNTA_EN BIT7
;;   Edge Counter A Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM1CAPTCTRLA_CFAWM     (BIT8|BIT9)
;;   Capture A FIFOs Water Mark
 set     PWMA_SM1CAPTCTRLA_CFAWM_0   BIT8
 set     PWMA_SM1CAPTCTRLA_CFAWM_1   BIT9

 set     PWMA_SM1CAPTCTRLA_CA0CNT    (BIT10|BIT11|BIT12)
;;   Capture A0 FIFO Word Count
 set     PWMA_SM1CAPTCTRLA_CA0CNT_0  BIT10
 set     PWMA_SM1CAPTCTRLA_CA0CNT_1  BIT11
 set     PWMA_SM1CAPTCTRLA_CA0CNT_2  BIT12

 set     PWMA_SM1CAPTCTRLA_CA1CNT    (BIT13|BIT14|BIT15)
;;   Capture A1 FIFO Word Count
 set     PWMA_SM1CAPTCTRLA_CA1CNT_0  BIT13
 set     PWMA_SM1CAPTCTRLA_CA1CNT_1  BIT14
 set     PWMA_SM1CAPTCTRLA_CA1CNT_2  BIT15

 set     PWMA_SM1CAPTCOMPA_EDGCMPA   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare A
 set     PWMA_SM1CAPTCOMPA_EDGCMPA_0 BIT0
 set     PWMA_SM1CAPTCOMPA_EDGCMPA_1 BIT1
 set     PWMA_SM1CAPTCOMPA_EDGCMPA_2 BIT2
 set     PWMA_SM1CAPTCOMPA_EDGCMPA_3 BIT3
 set     PWMA_SM1CAPTCOMPA_EDGCMPA_4 BIT4
 set     PWMA_SM1CAPTCOMPA_EDGCMPA_5 BIT5
 set     PWMA_SM1CAPTCOMPA_EDGCMPA_6 BIT6
 set     PWMA_SM1CAPTCOMPA_EDGCMPA_7 BIT7

 set     PWMA_SM1CAPTCOMPA_EDGCNTA   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter A
 set     PWMA_SM1CAPTCOMPA_EDGCNTA_0 BIT8
 set     PWMA_SM1CAPTCOMPA_EDGCNTA_1 BIT9
 set     PWMA_SM1CAPTCOMPA_EDGCNTA_2 BIT10
 set     PWMA_SM1CAPTCOMPA_EDGCNTA_3 BIT11
 set     PWMA_SM1CAPTCOMPA_EDGCNTA_4 BIT12
 set     PWMA_SM1CAPTCOMPA_EDGCNTA_5 BIT13
 set     PWMA_SM1CAPTCOMPA_EDGCNTA_6 BIT14
 set     PWMA_SM1CAPTCOMPA_EDGCNTA_7 BIT15

 set     PWMA_SM1CAPTCTRLB_ARMB      BIT0
;;   Arm B
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLB[EDGBx] is enabled.

 set     PWMA_SM1CAPTCTRLB_ONESHOTB  BIT1
;;   One Shot Mode B
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLB[ARMB] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLB[ARMB] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and CAPTCTRLB[ARMB] is cleared. No further captures will be performed until CAPTCTRLB[ARMB] is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled
;;             capture circuit and CAPTCTRLB[ARMB] is then cleared.

 set     PWMA_SM1CAPTCTRLB_EDGB0     (BIT2|BIT3)
;;   Edge B 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM1CAPTCTRLB_EDGB0_0   BIT2
 set     PWMA_SM1CAPTCTRLB_EDGB0_1   BIT3

 set     PWMA_SM1CAPTCTRLB_EDGB1     (BIT4|BIT5)
;;   Edge B 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM1CAPTCTRLB_EDGB1_0   BIT4
 set     PWMA_SM1CAPTCTRLB_EDGB1_1   BIT5

 set     PWMA_SM1CAPTCTRLB_INP_SELB  BIT6
;;   Input Select B
;;     0b0 ==> Raw PWM_B input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLB[EDGB0] and CAPTCTRLB[EDGB1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRB[EDGB0] and/or CAPTCTRLB[EDGB1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM1CAPTCTRLB_EDGCNTB_EN BIT7
;;   Edge Counter B Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM1CAPTCTRLB_CFBWM     (BIT8|BIT9)
;;   Capture B FIFOs Water Mark
 set     PWMA_SM1CAPTCTRLB_CFBWM_0   BIT8
 set     PWMA_SM1CAPTCTRLB_CFBWM_1   BIT9

 set     PWMA_SM1CAPTCTRLB_CB0CNT    (BIT10|BIT11|BIT12)
;;   Capture B0 FIFO Word Count
 set     PWMA_SM1CAPTCTRLB_CB0CNT_0  BIT10
 set     PWMA_SM1CAPTCTRLB_CB0CNT_1  BIT11
 set     PWMA_SM1CAPTCTRLB_CB0CNT_2  BIT12

 set     PWMA_SM1CAPTCTRLB_CB1CNT    (BIT13|BIT14|BIT15)
;;   Capture B1 FIFO Word Count
 set     PWMA_SM1CAPTCTRLB_CB1CNT_0  BIT13
 set     PWMA_SM1CAPTCTRLB_CB1CNT_1  BIT14
 set     PWMA_SM1CAPTCTRLB_CB1CNT_2  BIT15

 set     PWMA_SM1CAPTCOMPB_EDGCMPB   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare B
 set     PWMA_SM1CAPTCOMPB_EDGCMPB_0 BIT0
 set     PWMA_SM1CAPTCOMPB_EDGCMPB_1 BIT1
 set     PWMA_SM1CAPTCOMPB_EDGCMPB_2 BIT2
 set     PWMA_SM1CAPTCOMPB_EDGCMPB_3 BIT3
 set     PWMA_SM1CAPTCOMPB_EDGCMPB_4 BIT4
 set     PWMA_SM1CAPTCOMPB_EDGCMPB_5 BIT5
 set     PWMA_SM1CAPTCOMPB_EDGCMPB_6 BIT6
 set     PWMA_SM1CAPTCOMPB_EDGCMPB_7 BIT7

 set     PWMA_SM1CAPTCOMPB_EDGCNTB   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter B
 set     PWMA_SM1CAPTCOMPB_EDGCNTB_0 BIT8
 set     PWMA_SM1CAPTCOMPB_EDGCNTB_1 BIT9
 set     PWMA_SM1CAPTCOMPB_EDGCNTB_2 BIT10
 set     PWMA_SM1CAPTCOMPB_EDGCNTB_3 BIT11
 set     PWMA_SM1CAPTCOMPB_EDGCNTB_4 BIT12
 set     PWMA_SM1CAPTCOMPB_EDGCNTB_5 BIT13
 set     PWMA_SM1CAPTCOMPB_EDGCNTB_6 BIT14
 set     PWMA_SM1CAPTCOMPB_EDGCNTB_7 BIT15

 set     PWMA_SM1CAPTCTRLX_ARMX      BIT0
;;   Arm X
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLX[EDGXx] is enabled.

 set     PWMA_SM1CAPTCTRLX_ONESHOTX  BIT1
;;   One Shot Mode Aux
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after the ARMX bit is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after the ARMX bit is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and the ARMX bit is cleared. No further captures will be performed until the ARMX bit is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled capture
;;             circuit and the ARMX bit is then cleared.

 set     PWMA_SM1CAPTCTRLX_EDGX0     (BIT2|BIT3)
;;   Edge X 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM1CAPTCTRLX_EDGX0_0   BIT2
 set     PWMA_SM1CAPTCTRLX_EDGX0_1   BIT3

 set     PWMA_SM1CAPTCTRLX_EDGX1     (BIT4|BIT5)
;;   Edge X 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM1CAPTCTRLX_EDGX1_0   BIT4
 set     PWMA_SM1CAPTCTRLX_EDGX1_1   BIT5

 set     PWMA_SM1CAPTCTRLX_INP_SELX  BIT6
;;   Input Select X
;;     0b0 ==> Raw PWM_X input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLX[EDGX0] and CAPTCTRLX[EDGX1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRX[EDGX0] and/or CAPTCTRLX[EDGX1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM1CAPTCTRLX_EDGCNTX_EN BIT7
;;   Edge Counter X Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM1CAPTCTRLX_CFXWM     (BIT8|BIT9)
;;   Capture X FIFOs Water Mark
 set     PWMA_SM1CAPTCTRLX_CFXWM_0   BIT8
 set     PWMA_SM1CAPTCTRLX_CFXWM_1   BIT9

 set     PWMA_SM1CAPTCTRLX_CX0CNT    (BIT10|BIT11|BIT12)
;;   Capture X0 FIFO Word Count
 set     PWMA_SM1CAPTCTRLX_CX0CNT_0  BIT10
 set     PWMA_SM1CAPTCTRLX_CX0CNT_1  BIT11
 set     PWMA_SM1CAPTCTRLX_CX0CNT_2  BIT12

 set     PWMA_SM1CAPTCTRLX_CX1CNT    (BIT13|BIT14|BIT15)
;;   Capture X1 FIFO Word Count
 set     PWMA_SM1CAPTCTRLX_CX1CNT_0  BIT13
 set     PWMA_SM1CAPTCTRLX_CX1CNT_1  BIT14
 set     PWMA_SM1CAPTCTRLX_CX1CNT_2  BIT15

 set     PWMA_SM1CAPTCOMPX_EDGCMPX   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare X
 set     PWMA_SM1CAPTCOMPX_EDGCMPX_0 BIT0
 set     PWMA_SM1CAPTCOMPX_EDGCMPX_1 BIT1
 set     PWMA_SM1CAPTCOMPX_EDGCMPX_2 BIT2
 set     PWMA_SM1CAPTCOMPX_EDGCMPX_3 BIT3
 set     PWMA_SM1CAPTCOMPX_EDGCMPX_4 BIT4
 set     PWMA_SM1CAPTCOMPX_EDGCMPX_5 BIT5
 set     PWMA_SM1CAPTCOMPX_EDGCMPX_6 BIT6
 set     PWMA_SM1CAPTCOMPX_EDGCMPX_7 BIT7

 set     PWMA_SM1CAPTCOMPX_EDGCNTX   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter X
 set     PWMA_SM1CAPTCOMPX_EDGCNTX_0 BIT8
 set     PWMA_SM1CAPTCOMPX_EDGCNTX_1 BIT9
 set     PWMA_SM1CAPTCOMPX_EDGCNTX_2 BIT10
 set     PWMA_SM1CAPTCOMPX_EDGCNTX_3 BIT11
 set     PWMA_SM1CAPTCOMPX_EDGCNTX_4 BIT12
 set     PWMA_SM1CAPTCOMPX_EDGCNTX_5 BIT13
 set     PWMA_SM1CAPTCOMPX_EDGCNTX_6 BIT14
 set     PWMA_SM1CAPTCOMPX_EDGCNTX_7 BIT15

 set     PWMA_SM1CVAL0_CAPTVAL0      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM1CVAL0_CAPTVAL0_0    BIT0
 set     PWMA_SM1CVAL0_CAPTVAL0_1    BIT1
 set     PWMA_SM1CVAL0_CAPTVAL0_2    BIT2
 set     PWMA_SM1CVAL0_CAPTVAL0_3    BIT3
 set     PWMA_SM1CVAL0_CAPTVAL0_4    BIT4
 set     PWMA_SM1CVAL0_CAPTVAL0_5    BIT5
 set     PWMA_SM1CVAL0_CAPTVAL0_6    BIT6
 set     PWMA_SM1CVAL0_CAPTVAL0_7    BIT7
 set     PWMA_SM1CVAL0_CAPTVAL0_8    BIT8
 set     PWMA_SM1CVAL0_CAPTVAL0_9    BIT9
 set     PWMA_SM1CVAL0_CAPTVAL0_10   BIT10
 set     PWMA_SM1CVAL0_CAPTVAL0_11   BIT11
 set     PWMA_SM1CVAL0_CAPTVAL0_12   BIT12
 set     PWMA_SM1CVAL0_CAPTVAL0_13   BIT13
 set     PWMA_SM1CVAL0_CAPTVAL0_14   BIT14
 set     PWMA_SM1CVAL0_CAPTVAL0_15   BIT15

 set     PWMA_SM1CVAL0CYC_CVAL0CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM1CVAL0CYC_CVAL0CYC_0 BIT0
 set     PWMA_SM1CVAL0CYC_CVAL0CYC_1 BIT1
 set     PWMA_SM1CVAL0CYC_CVAL0CYC_2 BIT2
 set     PWMA_SM1CVAL0CYC_CVAL0CYC_3 BIT3

 set     PWMA_SM1CVAL1_CAPTVAL1      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM1CVAL1_CAPTVAL1_0    BIT0
 set     PWMA_SM1CVAL1_CAPTVAL1_1    BIT1
 set     PWMA_SM1CVAL1_CAPTVAL1_2    BIT2
 set     PWMA_SM1CVAL1_CAPTVAL1_3    BIT3
 set     PWMA_SM1CVAL1_CAPTVAL1_4    BIT4
 set     PWMA_SM1CVAL1_CAPTVAL1_5    BIT5
 set     PWMA_SM1CVAL1_CAPTVAL1_6    BIT6
 set     PWMA_SM1CVAL1_CAPTVAL1_7    BIT7
 set     PWMA_SM1CVAL1_CAPTVAL1_8    BIT8
 set     PWMA_SM1CVAL1_CAPTVAL1_9    BIT9
 set     PWMA_SM1CVAL1_CAPTVAL1_10   BIT10
 set     PWMA_SM1CVAL1_CAPTVAL1_11   BIT11
 set     PWMA_SM1CVAL1_CAPTVAL1_12   BIT12
 set     PWMA_SM1CVAL1_CAPTVAL1_13   BIT13
 set     PWMA_SM1CVAL1_CAPTVAL1_14   BIT14
 set     PWMA_SM1CVAL1_CAPTVAL1_15   BIT15

 set     PWMA_SM1CVAL1CYC_CVAL1CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM1CVAL1CYC_CVAL1CYC_0 BIT0
 set     PWMA_SM1CVAL1CYC_CVAL1CYC_1 BIT1
 set     PWMA_SM1CVAL1CYC_CVAL1CYC_2 BIT2
 set     PWMA_SM1CVAL1CYC_CVAL1CYC_3 BIT3

 set     PWMA_SM1CVAL2_CAPTVAL2      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM1CVAL2_CAPTVAL2_0    BIT0
 set     PWMA_SM1CVAL2_CAPTVAL2_1    BIT1
 set     PWMA_SM1CVAL2_CAPTVAL2_2    BIT2
 set     PWMA_SM1CVAL2_CAPTVAL2_3    BIT3
 set     PWMA_SM1CVAL2_CAPTVAL2_4    BIT4
 set     PWMA_SM1CVAL2_CAPTVAL2_5    BIT5
 set     PWMA_SM1CVAL2_CAPTVAL2_6    BIT6
 set     PWMA_SM1CVAL2_CAPTVAL2_7    BIT7
 set     PWMA_SM1CVAL2_CAPTVAL2_8    BIT8
 set     PWMA_SM1CVAL2_CAPTVAL2_9    BIT9
 set     PWMA_SM1CVAL2_CAPTVAL2_10   BIT10
 set     PWMA_SM1CVAL2_CAPTVAL2_11   BIT11
 set     PWMA_SM1CVAL2_CAPTVAL2_12   BIT12
 set     PWMA_SM1CVAL2_CAPTVAL2_13   BIT13
 set     PWMA_SM1CVAL2_CAPTVAL2_14   BIT14
 set     PWMA_SM1CVAL2_CAPTVAL2_15   BIT15

 set     PWMA_SM1CVAL2CYC_CVAL2CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM1CVAL2CYC_CVAL2CYC_0 BIT0
 set     PWMA_SM1CVAL2CYC_CVAL2CYC_1 BIT1
 set     PWMA_SM1CVAL2CYC_CVAL2CYC_2 BIT2
 set     PWMA_SM1CVAL2CYC_CVAL2CYC_3 BIT3

 set     PWMA_SM1CVAL3_CAPTVAL3      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM1CVAL3_CAPTVAL3_0    BIT0
 set     PWMA_SM1CVAL3_CAPTVAL3_1    BIT1
 set     PWMA_SM1CVAL3_CAPTVAL3_2    BIT2
 set     PWMA_SM1CVAL3_CAPTVAL3_3    BIT3
 set     PWMA_SM1CVAL3_CAPTVAL3_4    BIT4
 set     PWMA_SM1CVAL3_CAPTVAL3_5    BIT5
 set     PWMA_SM1CVAL3_CAPTVAL3_6    BIT6
 set     PWMA_SM1CVAL3_CAPTVAL3_7    BIT7
 set     PWMA_SM1CVAL3_CAPTVAL3_8    BIT8
 set     PWMA_SM1CVAL3_CAPTVAL3_9    BIT9
 set     PWMA_SM1CVAL3_CAPTVAL3_10   BIT10
 set     PWMA_SM1CVAL3_CAPTVAL3_11   BIT11
 set     PWMA_SM1CVAL3_CAPTVAL3_12   BIT12
 set     PWMA_SM1CVAL3_CAPTVAL3_13   BIT13
 set     PWMA_SM1CVAL3_CAPTVAL3_14   BIT14
 set     PWMA_SM1CVAL3_CAPTVAL3_15   BIT15

 set     PWMA_SM1CVAL3CYC_CVAL3CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM1CVAL3CYC_CVAL3CYC_0 BIT0
 set     PWMA_SM1CVAL3CYC_CVAL3CYC_1 BIT1
 set     PWMA_SM1CVAL3CYC_CVAL3CYC_2 BIT2
 set     PWMA_SM1CVAL3CYC_CVAL3CYC_3 BIT3

 set     PWMA_SM1CVAL4_CAPTVAL4      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM1CVAL4_CAPTVAL4_0    BIT0
 set     PWMA_SM1CVAL4_CAPTVAL4_1    BIT1
 set     PWMA_SM1CVAL4_CAPTVAL4_2    BIT2
 set     PWMA_SM1CVAL4_CAPTVAL4_3    BIT3
 set     PWMA_SM1CVAL4_CAPTVAL4_4    BIT4
 set     PWMA_SM1CVAL4_CAPTVAL4_5    BIT5
 set     PWMA_SM1CVAL4_CAPTVAL4_6    BIT6
 set     PWMA_SM1CVAL4_CAPTVAL4_7    BIT7
 set     PWMA_SM1CVAL4_CAPTVAL4_8    BIT8
 set     PWMA_SM1CVAL4_CAPTVAL4_9    BIT9
 set     PWMA_SM1CVAL4_CAPTVAL4_10   BIT10
 set     PWMA_SM1CVAL4_CAPTVAL4_11   BIT11
 set     PWMA_SM1CVAL4_CAPTVAL4_12   BIT12
 set     PWMA_SM1CVAL4_CAPTVAL4_13   BIT13
 set     PWMA_SM1CVAL4_CAPTVAL4_14   BIT14
 set     PWMA_SM1CVAL4_CAPTVAL4_15   BIT15

 set     PWMA_SM1CVAL4CYC_CVAL4CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM1CVAL4CYC_CVAL4CYC_0 BIT0
 set     PWMA_SM1CVAL4CYC_CVAL4CYC_1 BIT1
 set     PWMA_SM1CVAL4CYC_CVAL4CYC_2 BIT2
 set     PWMA_SM1CVAL4CYC_CVAL4CYC_3 BIT3

 set     PWMA_SM1CVAL5_CAPTVAL5      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM1CVAL5_CAPTVAL5_0    BIT0
 set     PWMA_SM1CVAL5_CAPTVAL5_1    BIT1
 set     PWMA_SM1CVAL5_CAPTVAL5_2    BIT2
 set     PWMA_SM1CVAL5_CAPTVAL5_3    BIT3
 set     PWMA_SM1CVAL5_CAPTVAL5_4    BIT4
 set     PWMA_SM1CVAL5_CAPTVAL5_5    BIT5
 set     PWMA_SM1CVAL5_CAPTVAL5_6    BIT6
 set     PWMA_SM1CVAL5_CAPTVAL5_7    BIT7
 set     PWMA_SM1CVAL5_CAPTVAL5_8    BIT8
 set     PWMA_SM1CVAL5_CAPTVAL5_9    BIT9
 set     PWMA_SM1CVAL5_CAPTVAL5_10   BIT10
 set     PWMA_SM1CVAL5_CAPTVAL5_11   BIT11
 set     PWMA_SM1CVAL5_CAPTVAL5_12   BIT12
 set     PWMA_SM1CVAL5_CAPTVAL5_13   BIT13
 set     PWMA_SM1CVAL5_CAPTVAL5_14   BIT14
 set     PWMA_SM1CVAL5_CAPTVAL5_15   BIT15

 set     PWMA_SM1CVAL5CYC_CVAL5CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM1CVAL5CYC_CVAL5CYC_0 BIT0
 set     PWMA_SM1CVAL5CYC_CVAL5CYC_1 BIT1
 set     PWMA_SM1CVAL5CYC_CVAL5CYC_2 BIT2
 set     PWMA_SM1CVAL5CYC_CVAL5CYC_3 BIT3

 set     PWMA_SM2CNT_CNT             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Counter Register Bits
 set     PWMA_SM2CNT_CNT_0           BIT0
 set     PWMA_SM2CNT_CNT_1           BIT1
 set     PWMA_SM2CNT_CNT_2           BIT2
 set     PWMA_SM2CNT_CNT_3           BIT3
 set     PWMA_SM2CNT_CNT_4           BIT4
 set     PWMA_SM2CNT_CNT_5           BIT5
 set     PWMA_SM2CNT_CNT_6           BIT6
 set     PWMA_SM2CNT_CNT_7           BIT7
 set     PWMA_SM2CNT_CNT_8           BIT8
 set     PWMA_SM2CNT_CNT_9           BIT9
 set     PWMA_SM2CNT_CNT_10          BIT10
 set     PWMA_SM2CNT_CNT_11          BIT11
 set     PWMA_SM2CNT_CNT_12          BIT12
 set     PWMA_SM2CNT_CNT_13          BIT13
 set     PWMA_SM2CNT_CNT_14          BIT14
 set     PWMA_SM2CNT_CNT_15          BIT15

 set     PWMA_SM2INIT_INIT           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Initial Count Register Bits
 set     PWMA_SM2INIT_INIT_0         BIT0
 set     PWMA_SM2INIT_INIT_1         BIT1
 set     PWMA_SM2INIT_INIT_2         BIT2
 set     PWMA_SM2INIT_INIT_3         BIT3
 set     PWMA_SM2INIT_INIT_4         BIT4
 set     PWMA_SM2INIT_INIT_5         BIT5
 set     PWMA_SM2INIT_INIT_6         BIT6
 set     PWMA_SM2INIT_INIT_7         BIT7
 set     PWMA_SM2INIT_INIT_8         BIT8
 set     PWMA_SM2INIT_INIT_9         BIT9
 set     PWMA_SM2INIT_INIT_10        BIT10
 set     PWMA_SM2INIT_INIT_11        BIT11
 set     PWMA_SM2INIT_INIT_12        BIT12
 set     PWMA_SM2INIT_INIT_13        BIT13
 set     PWMA_SM2INIT_INIT_14        BIT14
 set     PWMA_SM2INIT_INIT_15        BIT15

 set     PWMA_SM2CTRL2_CLK_SEL       (BIT0|BIT1)
;;   Clock Source Select
;;     0b00 ==> The IPBus clock is used as the clock for the local prescaler and counter.
;;     0b01 ==> EXT_CLK is used as the clock for the local prescaler and counter.
;;     0b10 ==> Submodule 0's clock (AUX_CLK) is used as the source clock for the local prescaler and counter. This setting should not be used in submodule 0 as it will force the clock to logic 0.
;;     0b11 ==> reserved
 set     PWMA_SM2CTRL2_CLK_SEL_0     BIT0
 set     PWMA_SM2CTRL2_CLK_SEL_1     BIT1

 set     PWMA_SM2CTRL2_RELOAD_SEL    BIT2
;;   Reload Source Select
;;     0b0 ==> The local RELOAD signal is used to reload registers.
;;     0b1 ==> The master RELOAD signal (from submodule 0) is used to reload registers. This setting should not be used in submodule 0 as it will force the RELOAD signal to logic 0.

 set     PWMA_SM2CTRL2_FORCE_SEL     (BIT3|BIT4|BIT5)
;;   This read/write bit determines the source of the FORCE OUTPUT signal for this submodule.
;;     0b000 ==> The local force signal, CTRL2[FORCE], from this submodule is used to force updates.
;;     0b001 ==> The master force signal from submodule 0 is used to force updates. This setting should not be used in submodule 0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b010 ==> The local reload signal from this submodule is used to force updates without regard to the state of LDOK.
;;     0b011 ==> The master reload signal from submodule0 is used to force updates if LDOK is set. This setting should not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b100 ==> The local sync signal from this submodule is used to force updates.
;;     0b101 ==> The master sync signal from submodule0 is used to force updates. This setting should not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b110 ==> The external force signal, EXT_FORCE, from outside the PWM module causes updates.
;;     0b111 ==> reserved
 set     PWMA_SM2CTRL2_FORCE_SEL_0   BIT3
 set     PWMA_SM2CTRL2_FORCE_SEL_1   BIT4
 set     PWMA_SM2CTRL2_FORCE_SEL_2   BIT5

 set     PWMA_SM2CTRL2_FORCE         BIT6
;;   Force Initialization

 set     PWMA_SM2CTRL2_FRCEN         BIT7
;;   Force Initialization Enable
;;     0b0 ==> Initialization from a FORCE_OUT event is disabled.
;;     0b1 ==> Initialization from a FORCE_OUT event is enabled.

 set     PWMA_SM2CTRL2_INIT_SEL      (BIT8|BIT9)
;;   Initialization Control Select
;;     0b00 ==> Local sync (PWM_X) causes initialization.
;;     0b01 ==> Master reload from submodule 0 causes initialization. This setting should not be used in submodule 0 as it will force the INIT signal to logic 0.
;;     0b10 ==> Master sync from submodule 0 causes initialization. This setting should not be used in submodule 0 as it will force the INIT signal to logic 0.
;;     0b11 ==> EXT_SYNC causes initialization.
 set     PWMA_SM2CTRL2_INIT_SEL_0    BIT8
 set     PWMA_SM2CTRL2_INIT_SEL_1    BIT9

 set     PWMA_SM2CTRL2_PWMX_INIT     BIT10
;;   PWM_X Initial Value

 set     PWMA_SM2CTRL2_PWM45_INIT    BIT11
;;   PWM45 Initial Value

 set     PWMA_SM2CTRL2_PWM23_INIT    BIT12
;;   PWM23 Initial Value

 set     PWMA_SM2CTRL2_INDEP         BIT13
;;   Independent or Complementary Pair Operation
;;     0b0 ==> PWM_A and PWM_B form a complementary PWM pair.
;;     0b1 ==> PWM_A and PWM_B outputs are independent PWMs.

 set     PWMA_SM2CTRL2_WAITEN        BIT14
;;   WAIT Enable

 set     PWMA_SM2CTRL2_DBGEN         BIT15
;;   Debug Enable

 set     PWMA_SM2CTRL_DBLEN          BIT0
;;   Double Switching Enable
;;     0b0 ==> Double switching disabled.
;;     0b1 ==> Double switching enabled.

 set     PWMA_SM2CTRL_DBLX           BIT1
;;   PWMX Double Switching Enable
;;     0b0 ==> PWMX double pulse disabled
;;     0b1 ==> PWMX double pulse enabled

 set     PWMA_SM2CTRL_LDMOD          BIT2
;;   Load Mode Select
;;     0b0 ==> Buffered registers of this submodule are loaded and take effect at the next PWM reload if MCTRL[LDOK] is set.
;;     0b1 ==> Buffered registers of this submodule are loaded and take effect immediately upon MCTRL[LDOK] being set.

 set     PWMA_SM2CTRL_SPLIT          BIT3
;;   Split the DBLPWM signal to PWMA and PWMB
;;     0b0 ==> DBLPWM is not split. PWMA and PWMB each have double pulses.
;;     0b1 ==> DBLPWM is split to PWMA and PWMB.

 set     PWMA_SM2CTRL_PRSC           (BIT4|BIT5|BIT6)
;;   Prescaler
;;     0b000 ==> PWM clock frequency = fclk
;;     0b001 ==> PWM clock frequency = fclk/2
;;     0b010 ==> PWM clock frequency = fclk/4
;;     0b011 ==> PWM clock frequency = fclk/8
;;     0b100 ==> PWM clock frequency = fclk/16
;;     0b101 ==> PWM clock frequency = fclk/32
;;     0b110 ==> PWM clock frequency = fclk/64
;;     0b111 ==> PWM clock frequency = fclk/128
 set     PWMA_SM2CTRL_PRSC_0         BIT4
 set     PWMA_SM2CTRL_PRSC_1         BIT5
 set     PWMA_SM2CTRL_PRSC_2         BIT6

 set     PWMA_SM2CTRL_DT             (BIT8|BIT9)
;;   Deadtime
 set     PWMA_SM2CTRL_DT_0           BIT8
 set     PWMA_SM2CTRL_DT_1           BIT9

 set     PWMA_SM2CTRL_FULL           BIT10
;;   Full Cycle Reload
;;     0b0 ==> Full-cycle reloads disabled.
;;     0b1 ==> Full-cycle reloads enabled.

 set     PWMA_SM2CTRL_HALF           BIT11
;;   Half Cycle Reload
;;     0b0 ==> Half-cycle reloads disabled.
;;     0b1 ==> Half-cycle reloads enabled.

 set     PWMA_SM2CTRL_LDFQ           (BIT12|BIT13|BIT14|BIT15)
;;     0b0000 ==> Every PWM opportunity
;;     0b0001 ==> Every 2 PWM opportunities
;;     0b0010 ==> Every 3 PWM opportunities
;;     0b0011 ==> Every 4 PWM opportunities
;;     0b0100 ==> Every 5 PWM opportunities
;;     0b0101 ==> Every 6 PWM opportunities
;;     0b0110 ==> Every 7 PWM opportunities
;;     0b0111 ==> Every 8 PWM opportunities
;;     0b1000 ==> Every 9 PWM opportunities
;;     0b1001 ==> Every 10 PWM opportunities
;;     0b1010 ==> Every 11 PWM opportunities
;;     0b1011 ==> Every 12 PWM opportunities
;;     0b1100 ==> Every 13 PWM opportunities
;;     0b1101 ==> Every 14 PWM opportunities
;;     0b1110 ==> Every 15 PWM opportunities
;;     0b1111 ==> Every 16 PWM opportunities
 set     PWMA_SM2CTRL_LDFQ_0         BIT12
 set     PWMA_SM2CTRL_LDFQ_1         BIT13
 set     PWMA_SM2CTRL_LDFQ_2         BIT14
 set     PWMA_SM2CTRL_LDFQ_3         BIT15

 set     PWMA_SM2VAL0_VAL0           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 0
 set     PWMA_SM2VAL0_VAL0_0         BIT0
 set     PWMA_SM2VAL0_VAL0_1         BIT1
 set     PWMA_SM2VAL0_VAL0_2         BIT2
 set     PWMA_SM2VAL0_VAL0_3         BIT3
 set     PWMA_SM2VAL0_VAL0_4         BIT4
 set     PWMA_SM2VAL0_VAL0_5         BIT5
 set     PWMA_SM2VAL0_VAL0_6         BIT6
 set     PWMA_SM2VAL0_VAL0_7         BIT7
 set     PWMA_SM2VAL0_VAL0_8         BIT8
 set     PWMA_SM2VAL0_VAL0_9         BIT9
 set     PWMA_SM2VAL0_VAL0_10        BIT10
 set     PWMA_SM2VAL0_VAL0_11        BIT11
 set     PWMA_SM2VAL0_VAL0_12        BIT12
 set     PWMA_SM2VAL0_VAL0_13        BIT13
 set     PWMA_SM2VAL0_VAL0_14        BIT14
 set     PWMA_SM2VAL0_VAL0_15        BIT15

 set     PWMA_SM2FRACVAL1_FRACVAL1   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 1 Register
 set     PWMA_SM2FRACVAL1_FRACVAL1_0 BIT11
 set     PWMA_SM2FRACVAL1_FRACVAL1_1 BIT12
 set     PWMA_SM2FRACVAL1_FRACVAL1_2 BIT13
 set     PWMA_SM2FRACVAL1_FRACVAL1_3 BIT14
 set     PWMA_SM2FRACVAL1_FRACVAL1_4 BIT15

 set     PWMA_SM2VAL1_VAL1           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 1
 set     PWMA_SM2VAL1_VAL1_0         BIT0
 set     PWMA_SM2VAL1_VAL1_1         BIT1
 set     PWMA_SM2VAL1_VAL1_2         BIT2
 set     PWMA_SM2VAL1_VAL1_3         BIT3
 set     PWMA_SM2VAL1_VAL1_4         BIT4
 set     PWMA_SM2VAL1_VAL1_5         BIT5
 set     PWMA_SM2VAL1_VAL1_6         BIT6
 set     PWMA_SM2VAL1_VAL1_7         BIT7
 set     PWMA_SM2VAL1_VAL1_8         BIT8
 set     PWMA_SM2VAL1_VAL1_9         BIT9
 set     PWMA_SM2VAL1_VAL1_10        BIT10
 set     PWMA_SM2VAL1_VAL1_11        BIT11
 set     PWMA_SM2VAL1_VAL1_12        BIT12
 set     PWMA_SM2VAL1_VAL1_13        BIT13
 set     PWMA_SM2VAL1_VAL1_14        BIT14
 set     PWMA_SM2VAL1_VAL1_15        BIT15

 set     PWMA_SM2FRACVAL2_FRACVAL2   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 2
 set     PWMA_SM2FRACVAL2_FRACVAL2_0 BIT11
 set     PWMA_SM2FRACVAL2_FRACVAL2_1 BIT12
 set     PWMA_SM2FRACVAL2_FRACVAL2_2 BIT13
 set     PWMA_SM2FRACVAL2_FRACVAL2_3 BIT14
 set     PWMA_SM2FRACVAL2_FRACVAL2_4 BIT15

 set     PWMA_SM2VAL2_VAL2           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 2
 set     PWMA_SM2VAL2_VAL2_0         BIT0
 set     PWMA_SM2VAL2_VAL2_1         BIT1
 set     PWMA_SM2VAL2_VAL2_2         BIT2
 set     PWMA_SM2VAL2_VAL2_3         BIT3
 set     PWMA_SM2VAL2_VAL2_4         BIT4
 set     PWMA_SM2VAL2_VAL2_5         BIT5
 set     PWMA_SM2VAL2_VAL2_6         BIT6
 set     PWMA_SM2VAL2_VAL2_7         BIT7
 set     PWMA_SM2VAL2_VAL2_8         BIT8
 set     PWMA_SM2VAL2_VAL2_9         BIT9
 set     PWMA_SM2VAL2_VAL2_10        BIT10
 set     PWMA_SM2VAL2_VAL2_11        BIT11
 set     PWMA_SM2VAL2_VAL2_12        BIT12
 set     PWMA_SM2VAL2_VAL2_13        BIT13
 set     PWMA_SM2VAL2_VAL2_14        BIT14
 set     PWMA_SM2VAL2_VAL2_15        BIT15

 set     PWMA_SM2FRACVAL3_FRACVAL3   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 3
 set     PWMA_SM2FRACVAL3_FRACVAL3_0 BIT11
 set     PWMA_SM2FRACVAL3_FRACVAL3_1 BIT12
 set     PWMA_SM2FRACVAL3_FRACVAL3_2 BIT13
 set     PWMA_SM2FRACVAL3_FRACVAL3_3 BIT14
 set     PWMA_SM2FRACVAL3_FRACVAL3_4 BIT15

 set     PWMA_SM2VAL3_VAL3           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 3
 set     PWMA_SM2VAL3_VAL3_0         BIT0
 set     PWMA_SM2VAL3_VAL3_1         BIT1
 set     PWMA_SM2VAL3_VAL3_2         BIT2
 set     PWMA_SM2VAL3_VAL3_3         BIT3
 set     PWMA_SM2VAL3_VAL3_4         BIT4
 set     PWMA_SM2VAL3_VAL3_5         BIT5
 set     PWMA_SM2VAL3_VAL3_6         BIT6
 set     PWMA_SM2VAL3_VAL3_7         BIT7
 set     PWMA_SM2VAL3_VAL3_8         BIT8
 set     PWMA_SM2VAL3_VAL3_9         BIT9
 set     PWMA_SM2VAL3_VAL3_10        BIT10
 set     PWMA_SM2VAL3_VAL3_11        BIT11
 set     PWMA_SM2VAL3_VAL3_12        BIT12
 set     PWMA_SM2VAL3_VAL3_13        BIT13
 set     PWMA_SM2VAL3_VAL3_14        BIT14
 set     PWMA_SM2VAL3_VAL3_15        BIT15

 set     PWMA_SM2FRACVAL4_FRACVAL4   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 4
 set     PWMA_SM2FRACVAL4_FRACVAL4_0 BIT11
 set     PWMA_SM2FRACVAL4_FRACVAL4_1 BIT12
 set     PWMA_SM2FRACVAL4_FRACVAL4_2 BIT13
 set     PWMA_SM2FRACVAL4_FRACVAL4_3 BIT14
 set     PWMA_SM2FRACVAL4_FRACVAL4_4 BIT15

 set     PWMA_SM2VAL4_VAL4           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 4
 set     PWMA_SM2VAL4_VAL4_0         BIT0
 set     PWMA_SM2VAL4_VAL4_1         BIT1
 set     PWMA_SM2VAL4_VAL4_2         BIT2
 set     PWMA_SM2VAL4_VAL4_3         BIT3
 set     PWMA_SM2VAL4_VAL4_4         BIT4
 set     PWMA_SM2VAL4_VAL4_5         BIT5
 set     PWMA_SM2VAL4_VAL4_6         BIT6
 set     PWMA_SM2VAL4_VAL4_7         BIT7
 set     PWMA_SM2VAL4_VAL4_8         BIT8
 set     PWMA_SM2VAL4_VAL4_9         BIT9
 set     PWMA_SM2VAL4_VAL4_10        BIT10
 set     PWMA_SM2VAL4_VAL4_11        BIT11
 set     PWMA_SM2VAL4_VAL4_12        BIT12
 set     PWMA_SM2VAL4_VAL4_13        BIT13
 set     PWMA_SM2VAL4_VAL4_14        BIT14
 set     PWMA_SM2VAL4_VAL4_15        BIT15

 set     PWMA_SM2FRACVAL5_FRACVAL5   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 5
 set     PWMA_SM2FRACVAL5_FRACVAL5_0 BIT11
 set     PWMA_SM2FRACVAL5_FRACVAL5_1 BIT12
 set     PWMA_SM2FRACVAL5_FRACVAL5_2 BIT13
 set     PWMA_SM2FRACVAL5_FRACVAL5_3 BIT14
 set     PWMA_SM2FRACVAL5_FRACVAL5_4 BIT15

 set     PWMA_SM2VAL5_VAL5           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 5
 set     PWMA_SM2VAL5_VAL5_0         BIT0
 set     PWMA_SM2VAL5_VAL5_1         BIT1
 set     PWMA_SM2VAL5_VAL5_2         BIT2
 set     PWMA_SM2VAL5_VAL5_3         BIT3
 set     PWMA_SM2VAL5_VAL5_4         BIT4
 set     PWMA_SM2VAL5_VAL5_5         BIT5
 set     PWMA_SM2VAL5_VAL5_6         BIT6
 set     PWMA_SM2VAL5_VAL5_7         BIT7
 set     PWMA_SM2VAL5_VAL5_8         BIT8
 set     PWMA_SM2VAL5_VAL5_9         BIT9
 set     PWMA_SM2VAL5_VAL5_10        BIT10
 set     PWMA_SM2VAL5_VAL5_11        BIT11
 set     PWMA_SM2VAL5_VAL5_12        BIT12
 set     PWMA_SM2VAL5_VAL5_13        BIT13
 set     PWMA_SM2VAL5_VAL5_14        BIT14
 set     PWMA_SM2VAL5_VAL5_15        BIT15

 set     PWMA_SM2FRCTRL_FRAC1_EN     BIT1
;;   Fractional Cycle PWM Period Enable
;;     0b0 ==> Disable fractional cycle length for the PWM period.
;;     0b1 ==> Enable fractional cycle length for the PWM period.

 set     PWMA_SM2FRCTRL_FRAC23_EN    BIT2
;;   Fractional Cycle Placement Enable fpr PWM_A
;;     0b0 ==> Disable fractional cycle placement for PWM_A.
;;     0b1 ==> Enable fractional cycle placement for PWM_A.

 set     PWMA_SM2FRCTRL_FRAC45_EN    BIT4
;;   Fractional Cycle Placement Enable fpr PWM_B
;;     0b0 ==> Disable fractional cycle placement for PWM_B.
;;     0b1 ==> Enable fractional cycle placement for PWM_B.

 set     PWMA_SM2FRCTRL_FRAC_PU      BIT8
;;   Fractional Delay Circuit Power Up
;;     0b0 ==> Turn off fractional delay logic.
;;     0b1 ==> Power up fractional delay logic.

 set     PWMA_SM2FRCTRL_TEST         BIT15
;;   Test Status Bit

 set     PWMA_SM2OCTRL_PWMXFS        (BIT0|BIT1)
;;   PWM_X Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM2OCTRL_PWMXFS_0      BIT0
 set     PWMA_SM2OCTRL_PWMXFS_1      BIT1

 set     PWMA_SM2OCTRL_PWMBFS        (BIT2|BIT3)
;;   PWM_B Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM2OCTRL_PWMBFS_0      BIT2
 set     PWMA_SM2OCTRL_PWMBFS_1      BIT3

 set     PWMA_SM2OCTRL_PWMAFS        (BIT4|BIT5)
;;   PWM_A Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM2OCTRL_PWMAFS_0      BIT4
 set     PWMA_SM2OCTRL_PWMAFS_1      BIT5

 set     PWMA_SM2OCTRL_POLX          BIT8
;;   PWM_X Output Polarity
;;     0b0 ==> PWM_X output not inverted. A high level on the PWM_X pin represents the "on" or "active" state.
;;     0b1 ==> PWM_X output inverted. A low level on the PWM_X pin represents the "on" or "active" state.

 set     PWMA_SM2OCTRL_POLB          BIT9
;;   PWM_B Output Polarity
;;     0b0 ==> PWM_B output not inverted. A high level on the PWM_B pin represents the "on" or "active" state.
;;     0b1 ==> PWM_B output inverted. A low level on the PWM_B pin represents the "on" or "active" state.

 set     PWMA_SM2OCTRL_POLA          BIT10
;;   PWM_A Output Polarity
;;     0b0 ==> PWM_A output not inverted. A high level on the PWM_A pin represents the "on" or "active" state.
;;     0b1 ==> PWM_A output inverted. A low level on the PWM_A pin represents the "on" or "active" state.

 set     PWMA_SM2OCTRL_PWMX_IN       BIT13
;;   PWM_X Input

 set     PWMA_SM2OCTRL_PWMB_IN       BIT14
;;   PWM_B Input

 set     PWMA_SM2OCTRL_PWMA_IN       BIT15
;;   PWM_A Input

 set     PWMA_SM2STS_CMPF            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Compare Flags
;;     0b0 ==> No compare event has occurred for a particular VALx value.
;;     0b1 ==> A compare event has occurred for a particular VALx value.
 set     PWMA_SM2STS_CMPF_0          BIT0
 set     PWMA_SM2STS_CMPF_1          BIT1
 set     PWMA_SM2STS_CMPF_2          BIT2
 set     PWMA_SM2STS_CMPF_3          BIT3
 set     PWMA_SM2STS_CMPF_4          BIT4
 set     PWMA_SM2STS_CMPF_5          BIT5

 set     PWMA_SM2STS_CFX0            BIT6
;;   Capture Flag X0

 set     PWMA_SM2STS_CFX1            BIT7
;;   Capture Flag X1

 set     PWMA_SM2STS_CFB0            BIT8
;;   Capture Flag B0

 set     PWMA_SM2STS_CFB1            BIT9
;;   Capture Flag B1

 set     PWMA_SM2STS_CFA0            BIT10
;;   Capture Flag A0

 set     PWMA_SM2STS_CFA1            BIT11
;;   Capture Flag A1

 set     PWMA_SM2STS_RF              BIT12
;;   Reload Flag
;;     0b0 ==> No new reload cycle since last STS[RF] clearing
;;     0b1 ==> New reload cycle since last STS[RF] clearing

 set     PWMA_SM2STS_REF             BIT13
;;   Reload Error Flag
;;     0b0 ==> No reload error occurred.
;;     0b1 ==> Reload signal occurred with non-coherent data and MCTRL[LDOK] = 0.

 set     PWMA_SM2STS_RUF             BIT14
;;   Registers Updated Flag
;;     0b0 ==> No register update has occurred since last reload.
;;     0b1 ==> At least one of the double buffered registers has been updated since the last reload.

 set     PWMA_SM2INTEN_CMPIE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Compare Interrupt Enables
;;     0b0 ==> The corresponding STS[CMPF] bit will not cause an interrupt request.
;;     0b1 ==> The corresponding STS[CMPF] bit will cause an interrupt request.
 set     PWMA_SM2INTEN_CMPIE_0       BIT0
 set     PWMA_SM2INTEN_CMPIE_1       BIT1
 set     PWMA_SM2INTEN_CMPIE_2       BIT2
 set     PWMA_SM2INTEN_CMPIE_3       BIT3
 set     PWMA_SM2INTEN_CMPIE_4       BIT4
 set     PWMA_SM2INTEN_CMPIE_5       BIT5

 set     PWMA_SM2INTEN_CX0IE         BIT6
;;   Capture X 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFX0].
;;     0b1 ==> Interrupt request enabled for STS[CFX0].

 set     PWMA_SM2INTEN_CX1IE         BIT7
;;   Capture X 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFX1].
;;     0b1 ==> Interrupt request enabled for STS[CFX1].

 set     PWMA_SM2INTEN_CB0IE         BIT8
;;   Capture B 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFB0].
;;     0b1 ==> Interrupt request enabled for STS[CFB0].

 set     PWMA_SM2INTEN_CB1IE         BIT9
;;   Capture B 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFB1].
;;     0b1 ==> Interrupt request enabled for STS[CFB1].

 set     PWMA_SM2INTEN_CA0IE         BIT10
;;   Capture A 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFA0].
;;     0b1 ==> Interrupt request enabled for STS[CFA0].

 set     PWMA_SM2INTEN_CA1IE         BIT11
;;   Capture A 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFA1].
;;     0b1 ==> Interrupt request enabled for STS[CFA1].

 set     PWMA_SM2INTEN_RIE           BIT12
;;   Reload Interrupt Enable
;;     0b0 ==> STS[RF] CPU interrupt requests disabled
;;     0b1 ==> STS[RF] CPU interrupt requests enabled

 set     PWMA_SM2INTEN_REIE          BIT13
;;   Reload Error Interrupt Enable
;;     0b0 ==> STS[REF] CPU interrupt requests disabled
;;     0b1 ==> STS[REF] CPU interrupt requests enabled

 set     PWMA_SM2DMAEN_CX0DE         BIT0
;;   Capture X0 FIFO DMA Enable

 set     PWMA_SM2DMAEN_CX1DE         BIT1
;;   Capture X1 FIFO DMA Enable

 set     PWMA_SM2DMAEN_CB0DE         BIT2
;;   Capture B0 FIFO DMA Enable

 set     PWMA_SM2DMAEN_CB1DE         BIT3
;;   Capture B1 FIFO DMA Enable

 set     PWMA_SM2DMAEN_CA0DE         BIT4
;;   Capture A0 FIFO DMA Enable

 set     PWMA_SM2DMAEN_CA1DE         BIT5
;;   Capture A1 FIFO DMA Enable

 set     PWMA_SM2DMAEN_CAPTDE        (BIT6|BIT7)
;;   Capture DMA Enable Source Select
;;     0b00 ==> Read DMA requests disabled.
;;     0b01 ==> Exceeding a FIFO watermark sets the DMA read request. This requires at least one of DMAEN[CA1DE], DMAEN[CA0DE], DMAEN[CB1DE], DMAEN[CB0DE], DMAEN[CX1DE], or DMAEN[CX0DE] to also be set in order to determine to which watermark(s) the DMA request is sensitive.
;;     0b10 ==> A local sync (VAL1 matches counter) sets the read DMA request.
;;     0b11 ==> A local reload (STS[RF] being set) sets the read DMA request.
 set     PWMA_SM2DMAEN_CAPTDE_0      BIT6
 set     PWMA_SM2DMAEN_CAPTDE_1      BIT7

 set     PWMA_SM2DMAEN_FAND          BIT8
;;   FIFO Watermark AND Control
;;     0b0 ==> Selected FIFO watermarks are OR'ed together.
;;     0b1 ==> Selected FIFO watermarks are AND'ed together.

 set     PWMA_SM2DMAEN_VALDE         BIT9
;;   Value Registers DMA Enable
;;     0b0 ==> DMA write requests disabled
;;     0b1 ==> DMA write requests for the VALx and FRACVALx registers enabled

 set     PWMA_SM2TCTRL_OUT_TRIG_EN   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Output Trigger Enables
;;     0b0 ==> PWM_OUT_TRIGx will not set when the counter value matches the VALx value.
;;     0b1 ==> PWM_OUT_TRIGx will set when the counter value matches the VALx value.
 set     PWMA_SM2TCTRL_OUT_TRIG_EN_0 BIT0
 set     PWMA_SM2TCTRL_OUT_TRIG_EN_1 BIT1
 set     PWMA_SM2TCTRL_OUT_TRIG_EN_2 BIT2
 set     PWMA_SM2TCTRL_OUT_TRIG_EN_3 BIT3
 set     PWMA_SM2TCTRL_OUT_TRIG_EN_4 BIT4
 set     PWMA_SM2TCTRL_OUT_TRIG_EN_5 BIT5

 set     PWMA_SM2TCTRL_PWBOT1        BIT14
;;   Output Trigger 1 Source Select
;;     0b0 ==> Route the PWM_OUT_TRIG1 signal to PWM_OUT_TRIG1 port.
;;     0b1 ==> Route the PWMB output to the PWM_OUT_TRIG1 port.

 set     PWMA_SM2TCTRL_PWAOT0        BIT15
;;   Output Trigger 0 Source Select
;;     0b0 ==> Route the PWM_OUT_TRIG0 signal to PWM_OUT_TRIG0 port.
;;     0b1 ==> Route the PWMA output to the PWM_OUT_TRIG0 port.

 set     PWMA_SM2DISMAP0_DIS0A       (BIT0|BIT1|BIT2|BIT3)
;;   PWM_A Fault Disable Mask 0
 set     PWMA_SM2DISMAP0_DIS0A_0     BIT0
 set     PWMA_SM2DISMAP0_DIS0A_1     BIT1
 set     PWMA_SM2DISMAP0_DIS0A_2     BIT2
 set     PWMA_SM2DISMAP0_DIS0A_3     BIT3

 set     PWMA_SM2DISMAP0_DIS0B       (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Fault Disable Mask 0
 set     PWMA_SM2DISMAP0_DIS0B_0     BIT4
 set     PWMA_SM2DISMAP0_DIS0B_1     BIT5
 set     PWMA_SM2DISMAP0_DIS0B_2     BIT6
 set     PWMA_SM2DISMAP0_DIS0B_3     BIT7

 set     PWMA_SM2DISMAP0_DIS0X       (BIT8|BIT9|BIT10|BIT11)
;;   PWM_X Fault Disable Mask 0
 set     PWMA_SM2DISMAP0_DIS0X_0     BIT8
 set     PWMA_SM2DISMAP0_DIS0X_1     BIT9
 set     PWMA_SM2DISMAP0_DIS0X_2     BIT10
 set     PWMA_SM2DISMAP0_DIS0X_3     BIT11

 set     PWMA_SM2DISMAP1_DIS1A       (BIT0|BIT1|BIT2|BIT3)
;;   PWM_A Fault Disable Mask 1
 set     PWMA_SM2DISMAP1_DIS1A_0     BIT0
 set     PWMA_SM2DISMAP1_DIS1A_1     BIT1
 set     PWMA_SM2DISMAP1_DIS1A_2     BIT2
 set     PWMA_SM2DISMAP1_DIS1A_3     BIT3

 set     PWMA_SM2DISMAP1_DIS1B       (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Fault Disable Mask 1
 set     PWMA_SM2DISMAP1_DIS1B_0     BIT4
 set     PWMA_SM2DISMAP1_DIS1B_1     BIT5
 set     PWMA_SM2DISMAP1_DIS1B_2     BIT6
 set     PWMA_SM2DISMAP1_DIS1B_3     BIT7

 set     PWMA_SM2DISMAP1_DIS1X       (BIT8|BIT9|BIT10|BIT11)
;;   PWM_X Fault Disable Mask 1
 set     PWMA_SM2DISMAP1_DIS1X_0     BIT8
 set     PWMA_SM2DISMAP1_DIS1X_1     BIT9
 set     PWMA_SM2DISMAP1_DIS1X_2     BIT10
 set     PWMA_SM2DISMAP1_DIS1X_3     BIT11

 set     PWMA_SM2DTCNT0_DTCNT0       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   Deadtime Count Register 0
 set     PWMA_SM2DTCNT0_DTCNT0_0     BIT0
 set     PWMA_SM2DTCNT0_DTCNT0_1     BIT1
 set     PWMA_SM2DTCNT0_DTCNT0_2     BIT2
 set     PWMA_SM2DTCNT0_DTCNT0_3     BIT3
 set     PWMA_SM2DTCNT0_DTCNT0_4     BIT4
 set     PWMA_SM2DTCNT0_DTCNT0_5     BIT5
 set     PWMA_SM2DTCNT0_DTCNT0_6     BIT6
 set     PWMA_SM2DTCNT0_DTCNT0_7     BIT7
 set     PWMA_SM2DTCNT0_DTCNT0_8     BIT8
 set     PWMA_SM2DTCNT0_DTCNT0_9     BIT9
 set     PWMA_SM2DTCNT0_DTCNT0_10    BIT10

 set     PWMA_SM2DTCNT1_DTCNT1       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   Deadtime Count Register 1
 set     PWMA_SM2DTCNT1_DTCNT1_0     BIT0
 set     PWMA_SM2DTCNT1_DTCNT1_1     BIT1
 set     PWMA_SM2DTCNT1_DTCNT1_2     BIT2
 set     PWMA_SM2DTCNT1_DTCNT1_3     BIT3
 set     PWMA_SM2DTCNT1_DTCNT1_4     BIT4
 set     PWMA_SM2DTCNT1_DTCNT1_5     BIT5
 set     PWMA_SM2DTCNT1_DTCNT1_6     BIT6
 set     PWMA_SM2DTCNT1_DTCNT1_7     BIT7
 set     PWMA_SM2DTCNT1_DTCNT1_8     BIT8
 set     PWMA_SM2DTCNT1_DTCNT1_9     BIT9
 set     PWMA_SM2DTCNT1_DTCNT1_10    BIT10

 set     PWMA_SM2CAPTCTRLA_ARMA      BIT0
;;   Arm A
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLA[EDGAx] is enabled.

 set     PWMA_SM2CAPTCTRLA_ONESHOTA  BIT1
;;   One Shot Mode A
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLA[ARMA] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLA[ARMA] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and CAPTCTRLA[ARMA] is cleared. No further captures will be performed until CAPTCTRLA[ARMA] is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled
;;             capture circuit and CAPTCTRLA[ARMA] is then cleared.

 set     PWMA_SM2CAPTCTRLA_EDGA0     (BIT2|BIT3)
;;   Edge A 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM2CAPTCTRLA_EDGA0_0   BIT2
 set     PWMA_SM2CAPTCTRLA_EDGA0_1   BIT3

 set     PWMA_SM2CAPTCTRLA_EDGA1     (BIT4|BIT5)
;;   Edge A 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM2CAPTCTRLA_EDGA1_0   BIT4
 set     PWMA_SM2CAPTCTRLA_EDGA1_1   BIT5

 set     PWMA_SM2CAPTCTRLA_INP_SELA  BIT6
;;   Input Select A
;;     0b0 ==> Raw PWM_A input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLA[EDGA0] and CAPTCTRLA[EDGA1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRA[EDGA0] and/or CAPTCTRLA[EDGA1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM2CAPTCTRLA_EDGCNTA_EN BIT7
;;   Edge Counter A Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM2CAPTCTRLA_CFAWM     (BIT8|BIT9)
;;   Capture A FIFOs Water Mark
 set     PWMA_SM2CAPTCTRLA_CFAWM_0   BIT8
 set     PWMA_SM2CAPTCTRLA_CFAWM_1   BIT9

 set     PWMA_SM2CAPTCTRLA_CA0CNT    (BIT10|BIT11|BIT12)
;;   Capture A0 FIFO Word Count
 set     PWMA_SM2CAPTCTRLA_CA0CNT_0  BIT10
 set     PWMA_SM2CAPTCTRLA_CA0CNT_1  BIT11
 set     PWMA_SM2CAPTCTRLA_CA0CNT_2  BIT12

 set     PWMA_SM2CAPTCTRLA_CA1CNT    (BIT13|BIT14|BIT15)
;;   Capture A1 FIFO Word Count
 set     PWMA_SM2CAPTCTRLA_CA1CNT_0  BIT13
 set     PWMA_SM2CAPTCTRLA_CA1CNT_1  BIT14
 set     PWMA_SM2CAPTCTRLA_CA1CNT_2  BIT15

 set     PWMA_SM2CAPTCOMPA_EDGCMPA   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare A
 set     PWMA_SM2CAPTCOMPA_EDGCMPA_0 BIT0
 set     PWMA_SM2CAPTCOMPA_EDGCMPA_1 BIT1
 set     PWMA_SM2CAPTCOMPA_EDGCMPA_2 BIT2
 set     PWMA_SM2CAPTCOMPA_EDGCMPA_3 BIT3
 set     PWMA_SM2CAPTCOMPA_EDGCMPA_4 BIT4
 set     PWMA_SM2CAPTCOMPA_EDGCMPA_5 BIT5
 set     PWMA_SM2CAPTCOMPA_EDGCMPA_6 BIT6
 set     PWMA_SM2CAPTCOMPA_EDGCMPA_7 BIT7

 set     PWMA_SM2CAPTCOMPA_EDGCNTA   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter A
 set     PWMA_SM2CAPTCOMPA_EDGCNTA_0 BIT8
 set     PWMA_SM2CAPTCOMPA_EDGCNTA_1 BIT9
 set     PWMA_SM2CAPTCOMPA_EDGCNTA_2 BIT10
 set     PWMA_SM2CAPTCOMPA_EDGCNTA_3 BIT11
 set     PWMA_SM2CAPTCOMPA_EDGCNTA_4 BIT12
 set     PWMA_SM2CAPTCOMPA_EDGCNTA_5 BIT13
 set     PWMA_SM2CAPTCOMPA_EDGCNTA_6 BIT14
 set     PWMA_SM2CAPTCOMPA_EDGCNTA_7 BIT15

 set     PWMA_SM2CAPTCTRLB_ARMB      BIT0
;;   Arm B
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLB[EDGBx] is enabled.

 set     PWMA_SM2CAPTCTRLB_ONESHOTB  BIT1
;;   One Shot Mode B
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLB[ARMB] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLB[ARMB] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and CAPTCTRLB[ARMB] is cleared. No further captures will be performed until CAPTCTRLB[ARMB] is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled
;;             capture circuit and CAPTCTRLB[ARMB] is then cleared.

 set     PWMA_SM2CAPTCTRLB_EDGB0     (BIT2|BIT3)
;;   Edge B 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM2CAPTCTRLB_EDGB0_0   BIT2
 set     PWMA_SM2CAPTCTRLB_EDGB0_1   BIT3

 set     PWMA_SM2CAPTCTRLB_EDGB1     (BIT4|BIT5)
;;   Edge B 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM2CAPTCTRLB_EDGB1_0   BIT4
 set     PWMA_SM2CAPTCTRLB_EDGB1_1   BIT5

 set     PWMA_SM2CAPTCTRLB_INP_SELB  BIT6
;;   Input Select B
;;     0b0 ==> Raw PWM_B input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLB[EDGB0] and CAPTCTRLB[EDGB1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRB[EDGB0] and/or CAPTCTRLB[EDGB1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM2CAPTCTRLB_EDGCNTB_EN BIT7
;;   Edge Counter B Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM2CAPTCTRLB_CFBWM     (BIT8|BIT9)
;;   Capture B FIFOs Water Mark
 set     PWMA_SM2CAPTCTRLB_CFBWM_0   BIT8
 set     PWMA_SM2CAPTCTRLB_CFBWM_1   BIT9

 set     PWMA_SM2CAPTCTRLB_CB0CNT    (BIT10|BIT11|BIT12)
;;   Capture B0 FIFO Word Count
 set     PWMA_SM2CAPTCTRLB_CB0CNT_0  BIT10
 set     PWMA_SM2CAPTCTRLB_CB0CNT_1  BIT11
 set     PWMA_SM2CAPTCTRLB_CB0CNT_2  BIT12

 set     PWMA_SM2CAPTCTRLB_CB1CNT    (BIT13|BIT14|BIT15)
;;   Capture B1 FIFO Word Count
 set     PWMA_SM2CAPTCTRLB_CB1CNT_0  BIT13
 set     PWMA_SM2CAPTCTRLB_CB1CNT_1  BIT14
 set     PWMA_SM2CAPTCTRLB_CB1CNT_2  BIT15

 set     PWMA_SM2CAPTCOMPB_EDGCMPB   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare B
 set     PWMA_SM2CAPTCOMPB_EDGCMPB_0 BIT0
 set     PWMA_SM2CAPTCOMPB_EDGCMPB_1 BIT1
 set     PWMA_SM2CAPTCOMPB_EDGCMPB_2 BIT2
 set     PWMA_SM2CAPTCOMPB_EDGCMPB_3 BIT3
 set     PWMA_SM2CAPTCOMPB_EDGCMPB_4 BIT4
 set     PWMA_SM2CAPTCOMPB_EDGCMPB_5 BIT5
 set     PWMA_SM2CAPTCOMPB_EDGCMPB_6 BIT6
 set     PWMA_SM2CAPTCOMPB_EDGCMPB_7 BIT7

 set     PWMA_SM2CAPTCOMPB_EDGCNTB   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter B
 set     PWMA_SM2CAPTCOMPB_EDGCNTB_0 BIT8
 set     PWMA_SM2CAPTCOMPB_EDGCNTB_1 BIT9
 set     PWMA_SM2CAPTCOMPB_EDGCNTB_2 BIT10
 set     PWMA_SM2CAPTCOMPB_EDGCNTB_3 BIT11
 set     PWMA_SM2CAPTCOMPB_EDGCNTB_4 BIT12
 set     PWMA_SM2CAPTCOMPB_EDGCNTB_5 BIT13
 set     PWMA_SM2CAPTCOMPB_EDGCNTB_6 BIT14
 set     PWMA_SM2CAPTCOMPB_EDGCNTB_7 BIT15

 set     PWMA_SM2CAPTCTRLX_ARMX      BIT0
;;   Arm X
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLX[EDGXx] is enabled.

 set     PWMA_SM2CAPTCTRLX_ONESHOTX  BIT1
;;   One Shot Mode Aux
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after the ARMX bit is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after the ARMX bit is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and the ARMX bit is cleared. No further captures will be performed until the ARMX bit is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled capture
;;             circuit and the ARMX bit is then cleared.

 set     PWMA_SM2CAPTCTRLX_EDGX0     (BIT2|BIT3)
;;   Edge X 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM2CAPTCTRLX_EDGX0_0   BIT2
 set     PWMA_SM2CAPTCTRLX_EDGX0_1   BIT3

 set     PWMA_SM2CAPTCTRLX_EDGX1     (BIT4|BIT5)
;;   Edge X 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM2CAPTCTRLX_EDGX1_0   BIT4
 set     PWMA_SM2CAPTCTRLX_EDGX1_1   BIT5

 set     PWMA_SM2CAPTCTRLX_INP_SELX  BIT6
;;   Input Select X
;;     0b0 ==> Raw PWM_X input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLX[EDGX0] and CAPTCTRLX[EDGX1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRX[EDGX0] and/or CAPTCTRLX[EDGX1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM2CAPTCTRLX_EDGCNTX_EN BIT7
;;   Edge Counter X Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM2CAPTCTRLX_CFXWM     (BIT8|BIT9)
;;   Capture X FIFOs Water Mark
 set     PWMA_SM2CAPTCTRLX_CFXWM_0   BIT8
 set     PWMA_SM2CAPTCTRLX_CFXWM_1   BIT9

 set     PWMA_SM2CAPTCTRLX_CX0CNT    (BIT10|BIT11|BIT12)
;;   Capture X0 FIFO Word Count
 set     PWMA_SM2CAPTCTRLX_CX0CNT_0  BIT10
 set     PWMA_SM2CAPTCTRLX_CX0CNT_1  BIT11
 set     PWMA_SM2CAPTCTRLX_CX0CNT_2  BIT12

 set     PWMA_SM2CAPTCTRLX_CX1CNT    (BIT13|BIT14|BIT15)
;;   Capture X1 FIFO Word Count
 set     PWMA_SM2CAPTCTRLX_CX1CNT_0  BIT13
 set     PWMA_SM2CAPTCTRLX_CX1CNT_1  BIT14
 set     PWMA_SM2CAPTCTRLX_CX1CNT_2  BIT15

 set     PWMA_SM2CAPTCOMPX_EDGCMPX   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare X
 set     PWMA_SM2CAPTCOMPX_EDGCMPX_0 BIT0
 set     PWMA_SM2CAPTCOMPX_EDGCMPX_1 BIT1
 set     PWMA_SM2CAPTCOMPX_EDGCMPX_2 BIT2
 set     PWMA_SM2CAPTCOMPX_EDGCMPX_3 BIT3
 set     PWMA_SM2CAPTCOMPX_EDGCMPX_4 BIT4
 set     PWMA_SM2CAPTCOMPX_EDGCMPX_5 BIT5
 set     PWMA_SM2CAPTCOMPX_EDGCMPX_6 BIT6
 set     PWMA_SM2CAPTCOMPX_EDGCMPX_7 BIT7

 set     PWMA_SM2CAPTCOMPX_EDGCNTX   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter X
 set     PWMA_SM2CAPTCOMPX_EDGCNTX_0 BIT8
 set     PWMA_SM2CAPTCOMPX_EDGCNTX_1 BIT9
 set     PWMA_SM2CAPTCOMPX_EDGCNTX_2 BIT10
 set     PWMA_SM2CAPTCOMPX_EDGCNTX_3 BIT11
 set     PWMA_SM2CAPTCOMPX_EDGCNTX_4 BIT12
 set     PWMA_SM2CAPTCOMPX_EDGCNTX_5 BIT13
 set     PWMA_SM2CAPTCOMPX_EDGCNTX_6 BIT14
 set     PWMA_SM2CAPTCOMPX_EDGCNTX_7 BIT15

 set     PWMA_SM2CVAL0_CAPTVAL0      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM2CVAL0_CAPTVAL0_0    BIT0
 set     PWMA_SM2CVAL0_CAPTVAL0_1    BIT1
 set     PWMA_SM2CVAL0_CAPTVAL0_2    BIT2
 set     PWMA_SM2CVAL0_CAPTVAL0_3    BIT3
 set     PWMA_SM2CVAL0_CAPTVAL0_4    BIT4
 set     PWMA_SM2CVAL0_CAPTVAL0_5    BIT5
 set     PWMA_SM2CVAL0_CAPTVAL0_6    BIT6
 set     PWMA_SM2CVAL0_CAPTVAL0_7    BIT7
 set     PWMA_SM2CVAL0_CAPTVAL0_8    BIT8
 set     PWMA_SM2CVAL0_CAPTVAL0_9    BIT9
 set     PWMA_SM2CVAL0_CAPTVAL0_10   BIT10
 set     PWMA_SM2CVAL0_CAPTVAL0_11   BIT11
 set     PWMA_SM2CVAL0_CAPTVAL0_12   BIT12
 set     PWMA_SM2CVAL0_CAPTVAL0_13   BIT13
 set     PWMA_SM2CVAL0_CAPTVAL0_14   BIT14
 set     PWMA_SM2CVAL0_CAPTVAL0_15   BIT15

 set     PWMA_SM2CVAL0CYC_CVAL0CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM2CVAL0CYC_CVAL0CYC_0 BIT0
 set     PWMA_SM2CVAL0CYC_CVAL0CYC_1 BIT1
 set     PWMA_SM2CVAL0CYC_CVAL0CYC_2 BIT2
 set     PWMA_SM2CVAL0CYC_CVAL0CYC_3 BIT3

 set     PWMA_SM2CVAL1_CAPTVAL1      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM2CVAL1_CAPTVAL1_0    BIT0
 set     PWMA_SM2CVAL1_CAPTVAL1_1    BIT1
 set     PWMA_SM2CVAL1_CAPTVAL1_2    BIT2
 set     PWMA_SM2CVAL1_CAPTVAL1_3    BIT3
 set     PWMA_SM2CVAL1_CAPTVAL1_4    BIT4
 set     PWMA_SM2CVAL1_CAPTVAL1_5    BIT5
 set     PWMA_SM2CVAL1_CAPTVAL1_6    BIT6
 set     PWMA_SM2CVAL1_CAPTVAL1_7    BIT7
 set     PWMA_SM2CVAL1_CAPTVAL1_8    BIT8
 set     PWMA_SM2CVAL1_CAPTVAL1_9    BIT9
 set     PWMA_SM2CVAL1_CAPTVAL1_10   BIT10
 set     PWMA_SM2CVAL1_CAPTVAL1_11   BIT11
 set     PWMA_SM2CVAL1_CAPTVAL1_12   BIT12
 set     PWMA_SM2CVAL1_CAPTVAL1_13   BIT13
 set     PWMA_SM2CVAL1_CAPTVAL1_14   BIT14
 set     PWMA_SM2CVAL1_CAPTVAL1_15   BIT15

 set     PWMA_SM2CVAL1CYC_CVAL1CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM2CVAL1CYC_CVAL1CYC_0 BIT0
 set     PWMA_SM2CVAL1CYC_CVAL1CYC_1 BIT1
 set     PWMA_SM2CVAL1CYC_CVAL1CYC_2 BIT2
 set     PWMA_SM2CVAL1CYC_CVAL1CYC_3 BIT3

 set     PWMA_SM2CVAL2_CAPTVAL2      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM2CVAL2_CAPTVAL2_0    BIT0
 set     PWMA_SM2CVAL2_CAPTVAL2_1    BIT1
 set     PWMA_SM2CVAL2_CAPTVAL2_2    BIT2
 set     PWMA_SM2CVAL2_CAPTVAL2_3    BIT3
 set     PWMA_SM2CVAL2_CAPTVAL2_4    BIT4
 set     PWMA_SM2CVAL2_CAPTVAL2_5    BIT5
 set     PWMA_SM2CVAL2_CAPTVAL2_6    BIT6
 set     PWMA_SM2CVAL2_CAPTVAL2_7    BIT7
 set     PWMA_SM2CVAL2_CAPTVAL2_8    BIT8
 set     PWMA_SM2CVAL2_CAPTVAL2_9    BIT9
 set     PWMA_SM2CVAL2_CAPTVAL2_10   BIT10
 set     PWMA_SM2CVAL2_CAPTVAL2_11   BIT11
 set     PWMA_SM2CVAL2_CAPTVAL2_12   BIT12
 set     PWMA_SM2CVAL2_CAPTVAL2_13   BIT13
 set     PWMA_SM2CVAL2_CAPTVAL2_14   BIT14
 set     PWMA_SM2CVAL2_CAPTVAL2_15   BIT15

 set     PWMA_SM2CVAL2CYC_CVAL2CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM2CVAL2CYC_CVAL2CYC_0 BIT0
 set     PWMA_SM2CVAL2CYC_CVAL2CYC_1 BIT1
 set     PWMA_SM2CVAL2CYC_CVAL2CYC_2 BIT2
 set     PWMA_SM2CVAL2CYC_CVAL2CYC_3 BIT3

 set     PWMA_SM2CVAL3_CAPTVAL3      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM2CVAL3_CAPTVAL3_0    BIT0
 set     PWMA_SM2CVAL3_CAPTVAL3_1    BIT1
 set     PWMA_SM2CVAL3_CAPTVAL3_2    BIT2
 set     PWMA_SM2CVAL3_CAPTVAL3_3    BIT3
 set     PWMA_SM2CVAL3_CAPTVAL3_4    BIT4
 set     PWMA_SM2CVAL3_CAPTVAL3_5    BIT5
 set     PWMA_SM2CVAL3_CAPTVAL3_6    BIT6
 set     PWMA_SM2CVAL3_CAPTVAL3_7    BIT7
 set     PWMA_SM2CVAL3_CAPTVAL3_8    BIT8
 set     PWMA_SM2CVAL3_CAPTVAL3_9    BIT9
 set     PWMA_SM2CVAL3_CAPTVAL3_10   BIT10
 set     PWMA_SM2CVAL3_CAPTVAL3_11   BIT11
 set     PWMA_SM2CVAL3_CAPTVAL3_12   BIT12
 set     PWMA_SM2CVAL3_CAPTVAL3_13   BIT13
 set     PWMA_SM2CVAL3_CAPTVAL3_14   BIT14
 set     PWMA_SM2CVAL3_CAPTVAL3_15   BIT15

 set     PWMA_SM2CVAL3CYC_CVAL3CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM2CVAL3CYC_CVAL3CYC_0 BIT0
 set     PWMA_SM2CVAL3CYC_CVAL3CYC_1 BIT1
 set     PWMA_SM2CVAL3CYC_CVAL3CYC_2 BIT2
 set     PWMA_SM2CVAL3CYC_CVAL3CYC_3 BIT3

 set     PWMA_SM2CVAL4_CAPTVAL4      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM2CVAL4_CAPTVAL4_0    BIT0
 set     PWMA_SM2CVAL4_CAPTVAL4_1    BIT1
 set     PWMA_SM2CVAL4_CAPTVAL4_2    BIT2
 set     PWMA_SM2CVAL4_CAPTVAL4_3    BIT3
 set     PWMA_SM2CVAL4_CAPTVAL4_4    BIT4
 set     PWMA_SM2CVAL4_CAPTVAL4_5    BIT5
 set     PWMA_SM2CVAL4_CAPTVAL4_6    BIT6
 set     PWMA_SM2CVAL4_CAPTVAL4_7    BIT7
 set     PWMA_SM2CVAL4_CAPTVAL4_8    BIT8
 set     PWMA_SM2CVAL4_CAPTVAL4_9    BIT9
 set     PWMA_SM2CVAL4_CAPTVAL4_10   BIT10
 set     PWMA_SM2CVAL4_CAPTVAL4_11   BIT11
 set     PWMA_SM2CVAL4_CAPTVAL4_12   BIT12
 set     PWMA_SM2CVAL4_CAPTVAL4_13   BIT13
 set     PWMA_SM2CVAL4_CAPTVAL4_14   BIT14
 set     PWMA_SM2CVAL4_CAPTVAL4_15   BIT15

 set     PWMA_SM2CVAL4CYC_CVAL4CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM2CVAL4CYC_CVAL4CYC_0 BIT0
 set     PWMA_SM2CVAL4CYC_CVAL4CYC_1 BIT1
 set     PWMA_SM2CVAL4CYC_CVAL4CYC_2 BIT2
 set     PWMA_SM2CVAL4CYC_CVAL4CYC_3 BIT3

 set     PWMA_SM2CVAL5_CAPTVAL5      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM2CVAL5_CAPTVAL5_0    BIT0
 set     PWMA_SM2CVAL5_CAPTVAL5_1    BIT1
 set     PWMA_SM2CVAL5_CAPTVAL5_2    BIT2
 set     PWMA_SM2CVAL5_CAPTVAL5_3    BIT3
 set     PWMA_SM2CVAL5_CAPTVAL5_4    BIT4
 set     PWMA_SM2CVAL5_CAPTVAL5_5    BIT5
 set     PWMA_SM2CVAL5_CAPTVAL5_6    BIT6
 set     PWMA_SM2CVAL5_CAPTVAL5_7    BIT7
 set     PWMA_SM2CVAL5_CAPTVAL5_8    BIT8
 set     PWMA_SM2CVAL5_CAPTVAL5_9    BIT9
 set     PWMA_SM2CVAL5_CAPTVAL5_10   BIT10
 set     PWMA_SM2CVAL5_CAPTVAL5_11   BIT11
 set     PWMA_SM2CVAL5_CAPTVAL5_12   BIT12
 set     PWMA_SM2CVAL5_CAPTVAL5_13   BIT13
 set     PWMA_SM2CVAL5_CAPTVAL5_14   BIT14
 set     PWMA_SM2CVAL5_CAPTVAL5_15   BIT15

 set     PWMA_SM2CVAL5CYC_CVAL5CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM2CVAL5CYC_CVAL5CYC_0 BIT0
 set     PWMA_SM2CVAL5CYC_CVAL5CYC_1 BIT1
 set     PWMA_SM2CVAL5CYC_CVAL5CYC_2 BIT2
 set     PWMA_SM2CVAL5CYC_CVAL5CYC_3 BIT3

 set     PWMA_SM3CNT_CNT             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Counter Register Bits
 set     PWMA_SM3CNT_CNT_0           BIT0
 set     PWMA_SM3CNT_CNT_1           BIT1
 set     PWMA_SM3CNT_CNT_2           BIT2
 set     PWMA_SM3CNT_CNT_3           BIT3
 set     PWMA_SM3CNT_CNT_4           BIT4
 set     PWMA_SM3CNT_CNT_5           BIT5
 set     PWMA_SM3CNT_CNT_6           BIT6
 set     PWMA_SM3CNT_CNT_7           BIT7
 set     PWMA_SM3CNT_CNT_8           BIT8
 set     PWMA_SM3CNT_CNT_9           BIT9
 set     PWMA_SM3CNT_CNT_10          BIT10
 set     PWMA_SM3CNT_CNT_11          BIT11
 set     PWMA_SM3CNT_CNT_12          BIT12
 set     PWMA_SM3CNT_CNT_13          BIT13
 set     PWMA_SM3CNT_CNT_14          BIT14
 set     PWMA_SM3CNT_CNT_15          BIT15

 set     PWMA_SM3INIT_INIT           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Initial Count Register Bits
 set     PWMA_SM3INIT_INIT_0         BIT0
 set     PWMA_SM3INIT_INIT_1         BIT1
 set     PWMA_SM3INIT_INIT_2         BIT2
 set     PWMA_SM3INIT_INIT_3         BIT3
 set     PWMA_SM3INIT_INIT_4         BIT4
 set     PWMA_SM3INIT_INIT_5         BIT5
 set     PWMA_SM3INIT_INIT_6         BIT6
 set     PWMA_SM3INIT_INIT_7         BIT7
 set     PWMA_SM3INIT_INIT_8         BIT8
 set     PWMA_SM3INIT_INIT_9         BIT9
 set     PWMA_SM3INIT_INIT_10        BIT10
 set     PWMA_SM3INIT_INIT_11        BIT11
 set     PWMA_SM3INIT_INIT_12        BIT12
 set     PWMA_SM3INIT_INIT_13        BIT13
 set     PWMA_SM3INIT_INIT_14        BIT14
 set     PWMA_SM3INIT_INIT_15        BIT15

 set     PWMA_SM3CTRL2_CLK_SEL       (BIT0|BIT1)
;;   Clock Source Select
;;     0b00 ==> The IPBus clock is used as the clock for the local prescaler and counter.
;;     0b01 ==> EXT_CLK is used as the clock for the local prescaler and counter.
;;     0b10 ==> Submodule 0's clock (AUX_CLK) is used as the source clock for the local prescaler and counter. This setting should not be used in submodule 0 as it will force the clock to logic 0.
;;     0b11 ==> reserved
 set     PWMA_SM3CTRL2_CLK_SEL_0     BIT0
 set     PWMA_SM3CTRL2_CLK_SEL_1     BIT1

 set     PWMA_SM3CTRL2_RELOAD_SEL    BIT2
;;   Reload Source Select
;;     0b0 ==> The local RELOAD signal is used to reload registers.
;;     0b1 ==> The master RELOAD signal (from submodule 0) is used to reload registers. This setting should not be used in submodule 0 as it will force the RELOAD signal to logic 0.

 set     PWMA_SM3CTRL2_FORCE_SEL     (BIT3|BIT4|BIT5)
;;   This read/write bit determines the source of the FORCE OUTPUT signal for this submodule.
;;     0b000 ==> The local force signal, CTRL2[FORCE], from this submodule is used to force updates.
;;     0b001 ==> The master force signal from submodule 0 is used to force updates. This setting should not be used in submodule 0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b010 ==> The local reload signal from this submodule is used to force updates without regard to the state of LDOK.
;;     0b011 ==> The master reload signal from submodule0 is used to force updates if LDOK is set. This setting should not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b100 ==> The local sync signal from this submodule is used to force updates.
;;     0b101 ==> The master sync signal from submodule0 is used to force updates. This setting should not be used in submodule0 as it will hold the FORCE OUTPUT signal to logic 0.
;;     0b110 ==> The external force signal, EXT_FORCE, from outside the PWM module causes updates.
;;     0b111 ==> reserved
 set     PWMA_SM3CTRL2_FORCE_SEL_0   BIT3
 set     PWMA_SM3CTRL2_FORCE_SEL_1   BIT4
 set     PWMA_SM3CTRL2_FORCE_SEL_2   BIT5

 set     PWMA_SM3CTRL2_FORCE         BIT6
;;   Force Initialization

 set     PWMA_SM3CTRL2_FRCEN         BIT7
;;   Force Initialization Enable
;;     0b0 ==> Initialization from a FORCE_OUT event is disabled.
;;     0b1 ==> Initialization from a FORCE_OUT event is enabled.

 set     PWMA_SM3CTRL2_INIT_SEL      (BIT8|BIT9)
;;   Initialization Control Select
;;     0b00 ==> Local sync (PWM_X) causes initialization.
;;     0b01 ==> Master reload from submodule 0 causes initialization. This setting should not be used in submodule 0 as it will force the INIT signal to logic 0.
;;     0b10 ==> Master sync from submodule 0 causes initialization. This setting should not be used in submodule 0 as it will force the INIT signal to logic 0.
;;     0b11 ==> EXT_SYNC causes initialization.
 set     PWMA_SM3CTRL2_INIT_SEL_0    BIT8
 set     PWMA_SM3CTRL2_INIT_SEL_1    BIT9

 set     PWMA_SM3CTRL2_PWMX_INIT     BIT10
;;   PWM_X Initial Value

 set     PWMA_SM3CTRL2_PWM45_INIT    BIT11
;;   PWM45 Initial Value

 set     PWMA_SM3CTRL2_PWM23_INIT    BIT12
;;   PWM23 Initial Value

 set     PWMA_SM3CTRL2_INDEP         BIT13
;;   Independent or Complementary Pair Operation
;;     0b0 ==> PWM_A and PWM_B form a complementary PWM pair.
;;     0b1 ==> PWM_A and PWM_B outputs are independent PWMs.

 set     PWMA_SM3CTRL2_WAITEN        BIT14
;;   WAIT Enable

 set     PWMA_SM3CTRL2_DBGEN         BIT15
;;   Debug Enable

 set     PWMA_SM3CTRL_DBLEN          BIT0
;;   Double Switching Enable
;;     0b0 ==> Double switching disabled.
;;     0b1 ==> Double switching enabled.

 set     PWMA_SM3CTRL_DBLX           BIT1
;;   PWMX Double Switching Enable
;;     0b0 ==> PWMX double pulse disabled
;;     0b1 ==> PWMX double pulse enabled

 set     PWMA_SM3CTRL_LDMOD          BIT2
;;   Load Mode Select
;;     0b0 ==> Buffered registers of this submodule are loaded and take effect at the next PWM reload if MCTRL[LDOK] is set.
;;     0b1 ==> Buffered registers of this submodule are loaded and take effect immediately upon MCTRL[LDOK] being set.

 set     PWMA_SM3CTRL_SPLIT          BIT3
;;   Split the DBLPWM signal to PWMA and PWMB
;;     0b0 ==> DBLPWM is not split. PWMA and PWMB each have double pulses.
;;     0b1 ==> DBLPWM is split to PWMA and PWMB.

 set     PWMA_SM3CTRL_PRSC           (BIT4|BIT5|BIT6)
;;   Prescaler
;;     0b000 ==> PWM clock frequency = fclk
;;     0b001 ==> PWM clock frequency = fclk/2
;;     0b010 ==> PWM clock frequency = fclk/4
;;     0b011 ==> PWM clock frequency = fclk/8
;;     0b100 ==> PWM clock frequency = fclk/16
;;     0b101 ==> PWM clock frequency = fclk/32
;;     0b110 ==> PWM clock frequency = fclk/64
;;     0b111 ==> PWM clock frequency = fclk/128
 set     PWMA_SM3CTRL_PRSC_0         BIT4
 set     PWMA_SM3CTRL_PRSC_1         BIT5
 set     PWMA_SM3CTRL_PRSC_2         BIT6

 set     PWMA_SM3CTRL_DT             (BIT8|BIT9)
;;   Deadtime
 set     PWMA_SM3CTRL_DT_0           BIT8
 set     PWMA_SM3CTRL_DT_1           BIT9

 set     PWMA_SM3CTRL_FULL           BIT10
;;   Full Cycle Reload
;;     0b0 ==> Full-cycle reloads disabled.
;;     0b1 ==> Full-cycle reloads enabled.

 set     PWMA_SM3CTRL_HALF           BIT11
;;   Half Cycle Reload
;;     0b0 ==> Half-cycle reloads disabled.
;;     0b1 ==> Half-cycle reloads enabled.

 set     PWMA_SM3CTRL_LDFQ           (BIT12|BIT13|BIT14|BIT15)
;;     0b0000 ==> Every PWM opportunity
;;     0b0001 ==> Every 2 PWM opportunities
;;     0b0010 ==> Every 3 PWM opportunities
;;     0b0011 ==> Every 4 PWM opportunities
;;     0b0100 ==> Every 5 PWM opportunities
;;     0b0101 ==> Every 6 PWM opportunities
;;     0b0110 ==> Every 7 PWM opportunities
;;     0b0111 ==> Every 8 PWM opportunities
;;     0b1000 ==> Every 9 PWM opportunities
;;     0b1001 ==> Every 10 PWM opportunities
;;     0b1010 ==> Every 11 PWM opportunities
;;     0b1011 ==> Every 12 PWM opportunities
;;     0b1100 ==> Every 13 PWM opportunities
;;     0b1101 ==> Every 14 PWM opportunities
;;     0b1110 ==> Every 15 PWM opportunities
;;     0b1111 ==> Every 16 PWM opportunities
 set     PWMA_SM3CTRL_LDFQ_0         BIT12
 set     PWMA_SM3CTRL_LDFQ_1         BIT13
 set     PWMA_SM3CTRL_LDFQ_2         BIT14
 set     PWMA_SM3CTRL_LDFQ_3         BIT15

 set     PWMA_SM3VAL0_VAL0           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 0
 set     PWMA_SM3VAL0_VAL0_0         BIT0
 set     PWMA_SM3VAL0_VAL0_1         BIT1
 set     PWMA_SM3VAL0_VAL0_2         BIT2
 set     PWMA_SM3VAL0_VAL0_3         BIT3
 set     PWMA_SM3VAL0_VAL0_4         BIT4
 set     PWMA_SM3VAL0_VAL0_5         BIT5
 set     PWMA_SM3VAL0_VAL0_6         BIT6
 set     PWMA_SM3VAL0_VAL0_7         BIT7
 set     PWMA_SM3VAL0_VAL0_8         BIT8
 set     PWMA_SM3VAL0_VAL0_9         BIT9
 set     PWMA_SM3VAL0_VAL0_10        BIT10
 set     PWMA_SM3VAL0_VAL0_11        BIT11
 set     PWMA_SM3VAL0_VAL0_12        BIT12
 set     PWMA_SM3VAL0_VAL0_13        BIT13
 set     PWMA_SM3VAL0_VAL0_14        BIT14
 set     PWMA_SM3VAL0_VAL0_15        BIT15

 set     PWMA_SM3FRACVAL1_FRACVAL1   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 1 Register
 set     PWMA_SM3FRACVAL1_FRACVAL1_0 BIT11
 set     PWMA_SM3FRACVAL1_FRACVAL1_1 BIT12
 set     PWMA_SM3FRACVAL1_FRACVAL1_2 BIT13
 set     PWMA_SM3FRACVAL1_FRACVAL1_3 BIT14
 set     PWMA_SM3FRACVAL1_FRACVAL1_4 BIT15

 set     PWMA_SM3VAL1_VAL1           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 1
 set     PWMA_SM3VAL1_VAL1_0         BIT0
 set     PWMA_SM3VAL1_VAL1_1         BIT1
 set     PWMA_SM3VAL1_VAL1_2         BIT2
 set     PWMA_SM3VAL1_VAL1_3         BIT3
 set     PWMA_SM3VAL1_VAL1_4         BIT4
 set     PWMA_SM3VAL1_VAL1_5         BIT5
 set     PWMA_SM3VAL1_VAL1_6         BIT6
 set     PWMA_SM3VAL1_VAL1_7         BIT7
 set     PWMA_SM3VAL1_VAL1_8         BIT8
 set     PWMA_SM3VAL1_VAL1_9         BIT9
 set     PWMA_SM3VAL1_VAL1_10        BIT10
 set     PWMA_SM3VAL1_VAL1_11        BIT11
 set     PWMA_SM3VAL1_VAL1_12        BIT12
 set     PWMA_SM3VAL1_VAL1_13        BIT13
 set     PWMA_SM3VAL1_VAL1_14        BIT14
 set     PWMA_SM3VAL1_VAL1_15        BIT15

 set     PWMA_SM3FRACVAL2_FRACVAL2   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 2
 set     PWMA_SM3FRACVAL2_FRACVAL2_0 BIT11
 set     PWMA_SM3FRACVAL2_FRACVAL2_1 BIT12
 set     PWMA_SM3FRACVAL2_FRACVAL2_2 BIT13
 set     PWMA_SM3FRACVAL2_FRACVAL2_3 BIT14
 set     PWMA_SM3FRACVAL2_FRACVAL2_4 BIT15

 set     PWMA_SM3VAL2_VAL2           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 2
 set     PWMA_SM3VAL2_VAL2_0         BIT0
 set     PWMA_SM3VAL2_VAL2_1         BIT1
 set     PWMA_SM3VAL2_VAL2_2         BIT2
 set     PWMA_SM3VAL2_VAL2_3         BIT3
 set     PWMA_SM3VAL2_VAL2_4         BIT4
 set     PWMA_SM3VAL2_VAL2_5         BIT5
 set     PWMA_SM3VAL2_VAL2_6         BIT6
 set     PWMA_SM3VAL2_VAL2_7         BIT7
 set     PWMA_SM3VAL2_VAL2_8         BIT8
 set     PWMA_SM3VAL2_VAL2_9         BIT9
 set     PWMA_SM3VAL2_VAL2_10        BIT10
 set     PWMA_SM3VAL2_VAL2_11        BIT11
 set     PWMA_SM3VAL2_VAL2_12        BIT12
 set     PWMA_SM3VAL2_VAL2_13        BIT13
 set     PWMA_SM3VAL2_VAL2_14        BIT14
 set     PWMA_SM3VAL2_VAL2_15        BIT15

 set     PWMA_SM3FRACVAL3_FRACVAL3   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 3
 set     PWMA_SM3FRACVAL3_FRACVAL3_0 BIT11
 set     PWMA_SM3FRACVAL3_FRACVAL3_1 BIT12
 set     PWMA_SM3FRACVAL3_FRACVAL3_2 BIT13
 set     PWMA_SM3FRACVAL3_FRACVAL3_3 BIT14
 set     PWMA_SM3FRACVAL3_FRACVAL3_4 BIT15

 set     PWMA_SM3VAL3_VAL3           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 3
 set     PWMA_SM3VAL3_VAL3_0         BIT0
 set     PWMA_SM3VAL3_VAL3_1         BIT1
 set     PWMA_SM3VAL3_VAL3_2         BIT2
 set     PWMA_SM3VAL3_VAL3_3         BIT3
 set     PWMA_SM3VAL3_VAL3_4         BIT4
 set     PWMA_SM3VAL3_VAL3_5         BIT5
 set     PWMA_SM3VAL3_VAL3_6         BIT6
 set     PWMA_SM3VAL3_VAL3_7         BIT7
 set     PWMA_SM3VAL3_VAL3_8         BIT8
 set     PWMA_SM3VAL3_VAL3_9         BIT9
 set     PWMA_SM3VAL3_VAL3_10        BIT10
 set     PWMA_SM3VAL3_VAL3_11        BIT11
 set     PWMA_SM3VAL3_VAL3_12        BIT12
 set     PWMA_SM3VAL3_VAL3_13        BIT13
 set     PWMA_SM3VAL3_VAL3_14        BIT14
 set     PWMA_SM3VAL3_VAL3_15        BIT15

 set     PWMA_SM3FRACVAL4_FRACVAL4   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 4
 set     PWMA_SM3FRACVAL4_FRACVAL4_0 BIT11
 set     PWMA_SM3FRACVAL4_FRACVAL4_1 BIT12
 set     PWMA_SM3FRACVAL4_FRACVAL4_2 BIT13
 set     PWMA_SM3FRACVAL4_FRACVAL4_3 BIT14
 set     PWMA_SM3FRACVAL4_FRACVAL4_4 BIT15

 set     PWMA_SM3VAL4_VAL4           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 4
 set     PWMA_SM3VAL4_VAL4_0         BIT0
 set     PWMA_SM3VAL4_VAL4_1         BIT1
 set     PWMA_SM3VAL4_VAL4_2         BIT2
 set     PWMA_SM3VAL4_VAL4_3         BIT3
 set     PWMA_SM3VAL4_VAL4_4         BIT4
 set     PWMA_SM3VAL4_VAL4_5         BIT5
 set     PWMA_SM3VAL4_VAL4_6         BIT6
 set     PWMA_SM3VAL4_VAL4_7         BIT7
 set     PWMA_SM3VAL4_VAL4_8         BIT8
 set     PWMA_SM3VAL4_VAL4_9         BIT9
 set     PWMA_SM3VAL4_VAL4_10        BIT10
 set     PWMA_SM3VAL4_VAL4_11        BIT11
 set     PWMA_SM3VAL4_VAL4_12        BIT12
 set     PWMA_SM3VAL4_VAL4_13        BIT13
 set     PWMA_SM3VAL4_VAL4_14        BIT14
 set     PWMA_SM3VAL4_VAL4_15        BIT15

 set     PWMA_SM3FRACVAL5_FRACVAL5   (BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Fractional Value 5
 set     PWMA_SM3FRACVAL5_FRACVAL5_0 BIT11
 set     PWMA_SM3FRACVAL5_FRACVAL5_1 BIT12
 set     PWMA_SM3FRACVAL5_FRACVAL5_2 BIT13
 set     PWMA_SM3FRACVAL5_FRACVAL5_3 BIT14
 set     PWMA_SM3FRACVAL5_FRACVAL5_4 BIT15

 set     PWMA_SM3VAL5_VAL5           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Value Register 5
 set     PWMA_SM3VAL5_VAL5_0         BIT0
 set     PWMA_SM3VAL5_VAL5_1         BIT1
 set     PWMA_SM3VAL5_VAL5_2         BIT2
 set     PWMA_SM3VAL5_VAL5_3         BIT3
 set     PWMA_SM3VAL5_VAL5_4         BIT4
 set     PWMA_SM3VAL5_VAL5_5         BIT5
 set     PWMA_SM3VAL5_VAL5_6         BIT6
 set     PWMA_SM3VAL5_VAL5_7         BIT7
 set     PWMA_SM3VAL5_VAL5_8         BIT8
 set     PWMA_SM3VAL5_VAL5_9         BIT9
 set     PWMA_SM3VAL5_VAL5_10        BIT10
 set     PWMA_SM3VAL5_VAL5_11        BIT11
 set     PWMA_SM3VAL5_VAL5_12        BIT12
 set     PWMA_SM3VAL5_VAL5_13        BIT13
 set     PWMA_SM3VAL5_VAL5_14        BIT14
 set     PWMA_SM3VAL5_VAL5_15        BIT15

 set     PWMA_SM3FRCTRL_FRAC1_EN     BIT1
;;   Fractional Cycle PWM Period Enable
;;     0b0 ==> Disable fractional cycle length for the PWM period.
;;     0b1 ==> Enable fractional cycle length for the PWM period.

 set     PWMA_SM3FRCTRL_FRAC23_EN    BIT2
;;   Fractional Cycle Placement Enable fpr PWM_A
;;     0b0 ==> Disable fractional cycle placement for PWM_A.
;;     0b1 ==> Enable fractional cycle placement for PWM_A.

 set     PWMA_SM3FRCTRL_FRAC45_EN    BIT4
;;   Fractional Cycle Placement Enable fpr PWM_B
;;     0b0 ==> Disable fractional cycle placement for PWM_B.
;;     0b1 ==> Enable fractional cycle placement for PWM_B.

 set     PWMA_SM3FRCTRL_FRAC_PU      BIT8
;;   Fractional Delay Circuit Power Up
;;     0b0 ==> Turn off fractional delay logic.
;;     0b1 ==> Power up fractional delay logic.

 set     PWMA_SM3FRCTRL_TEST         BIT15
;;   Test Status Bit

 set     PWMA_SM3OCTRL_PWMXFS        (BIT0|BIT1)
;;   PWM_X Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM3OCTRL_PWMXFS_0      BIT0
 set     PWMA_SM3OCTRL_PWMXFS_1      BIT1

 set     PWMA_SM3OCTRL_PWMBFS        (BIT2|BIT3)
;;   PWM_B Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM3OCTRL_PWMBFS_0      BIT2
 set     PWMA_SM3OCTRL_PWMBFS_1      BIT3

 set     PWMA_SM3OCTRL_PWMAFS        (BIT4|BIT5)
;;   PWM_A Fault State
;;     0b00 ==> Output is forced to logic 0 state prior to consideration of output polarity control.
;;     0b01 ==> Output is forced to logic 1 state prior to consideration of output polarity control.
;;     0b10 ==> Output is tristated.
;;     0b11 ==> Output is tristated.
 set     PWMA_SM3OCTRL_PWMAFS_0      BIT4
 set     PWMA_SM3OCTRL_PWMAFS_1      BIT5

 set     PWMA_SM3OCTRL_POLX          BIT8
;;   PWM_X Output Polarity
;;     0b0 ==> PWM_X output not inverted. A high level on the PWM_X pin represents the "on" or "active" state.
;;     0b1 ==> PWM_X output inverted. A low level on the PWM_X pin represents the "on" or "active" state.

 set     PWMA_SM3OCTRL_POLB          BIT9
;;   PWM_B Output Polarity
;;     0b0 ==> PWM_B output not inverted. A high level on the PWM_B pin represents the "on" or "active" state.
;;     0b1 ==> PWM_B output inverted. A low level on the PWM_B pin represents the "on" or "active" state.

 set     PWMA_SM3OCTRL_POLA          BIT10
;;   PWM_A Output Polarity
;;     0b0 ==> PWM_A output not inverted. A high level on the PWM_A pin represents the "on" or "active" state.
;;     0b1 ==> PWM_A output inverted. A low level on the PWM_A pin represents the "on" or "active" state.

 set     PWMA_SM3OCTRL_PWMX_IN       BIT13
;;   PWM_X Input

 set     PWMA_SM3OCTRL_PWMB_IN       BIT14
;;   PWM_B Input

 set     PWMA_SM3OCTRL_PWMA_IN       BIT15
;;   PWM_A Input

 set     PWMA_SM3STS_CMPF            (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Compare Flags
;;     0b0 ==> No compare event has occurred for a particular VALx value.
;;     0b1 ==> A compare event has occurred for a particular VALx value.
 set     PWMA_SM3STS_CMPF_0          BIT0
 set     PWMA_SM3STS_CMPF_1          BIT1
 set     PWMA_SM3STS_CMPF_2          BIT2
 set     PWMA_SM3STS_CMPF_3          BIT3
 set     PWMA_SM3STS_CMPF_4          BIT4
 set     PWMA_SM3STS_CMPF_5          BIT5

 set     PWMA_SM3STS_CFX0            BIT6
;;   Capture Flag X0

 set     PWMA_SM3STS_CFX1            BIT7
;;   Capture Flag X1

 set     PWMA_SM3STS_CFB0            BIT8
;;   Capture Flag B0

 set     PWMA_SM3STS_CFB1            BIT9
;;   Capture Flag B1

 set     PWMA_SM3STS_CFA0            BIT10
;;   Capture Flag A0

 set     PWMA_SM3STS_CFA1            BIT11
;;   Capture Flag A1

 set     PWMA_SM3STS_RF              BIT12
;;   Reload Flag
;;     0b0 ==> No new reload cycle since last STS[RF] clearing
;;     0b1 ==> New reload cycle since last STS[RF] clearing

 set     PWMA_SM3STS_REF             BIT13
;;   Reload Error Flag
;;     0b0 ==> No reload error occurred.
;;     0b1 ==> Reload signal occurred with non-coherent data and MCTRL[LDOK] = 0.

 set     PWMA_SM3STS_RUF             BIT14
;;   Registers Updated Flag
;;     0b0 ==> No register update has occurred since last reload.
;;     0b1 ==> At least one of the double buffered registers has been updated since the last reload.

 set     PWMA_SM3INTEN_CMPIE         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Compare Interrupt Enables
;;     0b0 ==> The corresponding STS[CMPF] bit will not cause an interrupt request.
;;     0b1 ==> The corresponding STS[CMPF] bit will cause an interrupt request.
 set     PWMA_SM3INTEN_CMPIE_0       BIT0
 set     PWMA_SM3INTEN_CMPIE_1       BIT1
 set     PWMA_SM3INTEN_CMPIE_2       BIT2
 set     PWMA_SM3INTEN_CMPIE_3       BIT3
 set     PWMA_SM3INTEN_CMPIE_4       BIT4
 set     PWMA_SM3INTEN_CMPIE_5       BIT5

 set     PWMA_SM3INTEN_CX0IE         BIT6
;;   Capture X 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFX0].
;;     0b1 ==> Interrupt request enabled for STS[CFX0].

 set     PWMA_SM3INTEN_CX1IE         BIT7
;;   Capture X 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFX1].
;;     0b1 ==> Interrupt request enabled for STS[CFX1].

 set     PWMA_SM3INTEN_CB0IE         BIT8
;;   Capture B 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFB0].
;;     0b1 ==> Interrupt request enabled for STS[CFB0].

 set     PWMA_SM3INTEN_CB1IE         BIT9
;;   Capture B 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFB1].
;;     0b1 ==> Interrupt request enabled for STS[CFB1].

 set     PWMA_SM3INTEN_CA0IE         BIT10
;;   Capture A 0 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFA0].
;;     0b1 ==> Interrupt request enabled for STS[CFA0].

 set     PWMA_SM3INTEN_CA1IE         BIT11
;;   Capture A 1 Interrupt Enable
;;     0b0 ==> Interrupt request disabled for STS[CFA1].
;;     0b1 ==> Interrupt request enabled for STS[CFA1].

 set     PWMA_SM3INTEN_RIE           BIT12
;;   Reload Interrupt Enable
;;     0b0 ==> STS[RF] CPU interrupt requests disabled
;;     0b1 ==> STS[RF] CPU interrupt requests enabled

 set     PWMA_SM3INTEN_REIE          BIT13
;;   Reload Error Interrupt Enable
;;     0b0 ==> STS[REF] CPU interrupt requests disabled
;;     0b1 ==> STS[REF] CPU interrupt requests enabled

 set     PWMA_SM3DMAEN_CX0DE         BIT0
;;   Capture X0 FIFO DMA Enable

 set     PWMA_SM3DMAEN_CX1DE         BIT1
;;   Capture X1 FIFO DMA Enable

 set     PWMA_SM3DMAEN_CB0DE         BIT2
;;   Capture B0 FIFO DMA Enable

 set     PWMA_SM3DMAEN_CB1DE         BIT3
;;   Capture B1 FIFO DMA Enable

 set     PWMA_SM3DMAEN_CA0DE         BIT4
;;   Capture A0 FIFO DMA Enable

 set     PWMA_SM3DMAEN_CA1DE         BIT5
;;   Capture A1 FIFO DMA Enable

 set     PWMA_SM3DMAEN_CAPTDE        (BIT6|BIT7)
;;   Capture DMA Enable Source Select
;;     0b00 ==> Read DMA requests disabled.
;;     0b01 ==> Exceeding a FIFO watermark sets the DMA read request. This requires at least one of DMAEN[CA1DE], DMAEN[CA0DE], DMAEN[CB1DE], DMAEN[CB0DE], DMAEN[CX1DE], or DMAEN[CX0DE] to also be set in order to determine to which watermark(s) the DMA request is sensitive.
;;     0b10 ==> A local sync (VAL1 matches counter) sets the read DMA request.
;;     0b11 ==> A local reload (STS[RF] being set) sets the read DMA request.
 set     PWMA_SM3DMAEN_CAPTDE_0      BIT6
 set     PWMA_SM3DMAEN_CAPTDE_1      BIT7

 set     PWMA_SM3DMAEN_FAND          BIT8
;;   FIFO Watermark AND Control
;;     0b0 ==> Selected FIFO watermarks are OR'ed together.
;;     0b1 ==> Selected FIFO watermarks are AND'ed together.

 set     PWMA_SM3DMAEN_VALDE         BIT9
;;   Value Registers DMA Enable
;;     0b0 ==> DMA write requests disabled
;;     0b1 ==> DMA write requests for the VALx and FRACVALx registers enabled

 set     PWMA_SM3TCTRL_OUT_TRIG_EN   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5)
;;   Output Trigger Enables
;;     0b0 ==> PWM_OUT_TRIGx will not set when the counter value matches the VALx value.
;;     0b1 ==> PWM_OUT_TRIGx will set when the counter value matches the VALx value.
 set     PWMA_SM3TCTRL_OUT_TRIG_EN_0 BIT0
 set     PWMA_SM3TCTRL_OUT_TRIG_EN_1 BIT1
 set     PWMA_SM3TCTRL_OUT_TRIG_EN_2 BIT2
 set     PWMA_SM3TCTRL_OUT_TRIG_EN_3 BIT3
 set     PWMA_SM3TCTRL_OUT_TRIG_EN_4 BIT4
 set     PWMA_SM3TCTRL_OUT_TRIG_EN_5 BIT5

 set     PWMA_SM3TCTRL_PWBOT1        BIT14
;;   Output Trigger 1 Source Select
;;     0b0 ==> Route the PWM_OUT_TRIG1 signal to PWM_OUT_TRIG1 port.
;;     0b1 ==> Route the PWMB output to the PWM_OUT_TRIG1 port.

 set     PWMA_SM3TCTRL_PWAOT0        BIT15
;;   Output Trigger 0 Source Select
;;     0b0 ==> Route the PWM_OUT_TRIG0 signal to PWM_OUT_TRIG0 port.
;;     0b1 ==> Route the PWMA output to the PWM_OUT_TRIG0 port.

 set     PWMA_SM3DISMAP0_DIS0A       (BIT0|BIT1|BIT2|BIT3)
;;   PWM_A Fault Disable Mask 0
 set     PWMA_SM3DISMAP0_DIS0A_0     BIT0
 set     PWMA_SM3DISMAP0_DIS0A_1     BIT1
 set     PWMA_SM3DISMAP0_DIS0A_2     BIT2
 set     PWMA_SM3DISMAP0_DIS0A_3     BIT3

 set     PWMA_SM3DISMAP0_DIS0B       (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Fault Disable Mask 0
 set     PWMA_SM3DISMAP0_DIS0B_0     BIT4
 set     PWMA_SM3DISMAP0_DIS0B_1     BIT5
 set     PWMA_SM3DISMAP0_DIS0B_2     BIT6
 set     PWMA_SM3DISMAP0_DIS0B_3     BIT7

 set     PWMA_SM3DISMAP0_DIS0X       (BIT8|BIT9|BIT10|BIT11)
;;   PWM_X Fault Disable Mask 0
 set     PWMA_SM3DISMAP0_DIS0X_0     BIT8
 set     PWMA_SM3DISMAP0_DIS0X_1     BIT9
 set     PWMA_SM3DISMAP0_DIS0X_2     BIT10
 set     PWMA_SM3DISMAP0_DIS0X_3     BIT11

 set     PWMA_SM3DISMAP1_DIS1A       (BIT0|BIT1|BIT2|BIT3)
;;   PWM_A Fault Disable Mask 1
 set     PWMA_SM3DISMAP1_DIS1A_0     BIT0
 set     PWMA_SM3DISMAP1_DIS1A_1     BIT1
 set     PWMA_SM3DISMAP1_DIS1A_2     BIT2
 set     PWMA_SM3DISMAP1_DIS1A_3     BIT3

 set     PWMA_SM3DISMAP1_DIS1B       (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Fault Disable Mask 1
 set     PWMA_SM3DISMAP1_DIS1B_0     BIT4
 set     PWMA_SM3DISMAP1_DIS1B_1     BIT5
 set     PWMA_SM3DISMAP1_DIS1B_2     BIT6
 set     PWMA_SM3DISMAP1_DIS1B_3     BIT7

 set     PWMA_SM3DISMAP1_DIS1X       (BIT8|BIT9|BIT10|BIT11)
;;   PWM_X Fault Disable Mask 1
 set     PWMA_SM3DISMAP1_DIS1X_0     BIT8
 set     PWMA_SM3DISMAP1_DIS1X_1     BIT9
 set     PWMA_SM3DISMAP1_DIS1X_2     BIT10
 set     PWMA_SM3DISMAP1_DIS1X_3     BIT11

 set     PWMA_SM3DTCNT0_DTCNT0       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   Deadtime Count Register 0
 set     PWMA_SM3DTCNT0_DTCNT0_0     BIT0
 set     PWMA_SM3DTCNT0_DTCNT0_1     BIT1
 set     PWMA_SM3DTCNT0_DTCNT0_2     BIT2
 set     PWMA_SM3DTCNT0_DTCNT0_3     BIT3
 set     PWMA_SM3DTCNT0_DTCNT0_4     BIT4
 set     PWMA_SM3DTCNT0_DTCNT0_5     BIT5
 set     PWMA_SM3DTCNT0_DTCNT0_6     BIT6
 set     PWMA_SM3DTCNT0_DTCNT0_7     BIT7
 set     PWMA_SM3DTCNT0_DTCNT0_8     BIT8
 set     PWMA_SM3DTCNT0_DTCNT0_9     BIT9
 set     PWMA_SM3DTCNT0_DTCNT0_10    BIT10

 set     PWMA_SM3DTCNT1_DTCNT1       (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10)
;;   Deadtime Count Register 1
 set     PWMA_SM3DTCNT1_DTCNT1_0     BIT0
 set     PWMA_SM3DTCNT1_DTCNT1_1     BIT1
 set     PWMA_SM3DTCNT1_DTCNT1_2     BIT2
 set     PWMA_SM3DTCNT1_DTCNT1_3     BIT3
 set     PWMA_SM3DTCNT1_DTCNT1_4     BIT4
 set     PWMA_SM3DTCNT1_DTCNT1_5     BIT5
 set     PWMA_SM3DTCNT1_DTCNT1_6     BIT6
 set     PWMA_SM3DTCNT1_DTCNT1_7     BIT7
 set     PWMA_SM3DTCNT1_DTCNT1_8     BIT8
 set     PWMA_SM3DTCNT1_DTCNT1_9     BIT9
 set     PWMA_SM3DTCNT1_DTCNT1_10    BIT10

 set     PWMA_SM3CAPTCTRLA_ARMA      BIT0
;;   Arm A
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLA[EDGAx] is enabled.

 set     PWMA_SM3CAPTCTRLA_ONESHOTA  BIT1
;;   One Shot Mode A
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLA[ARMA] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLA[ARMA] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and CAPTCTRLA[ARMA] is cleared. No further captures will be performed until CAPTCTRLA[ARMA] is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled
;;             capture circuit and CAPTCTRLA[ARMA] is then cleared.

 set     PWMA_SM3CAPTCTRLA_EDGA0     (BIT2|BIT3)
;;   Edge A 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM3CAPTCTRLA_EDGA0_0   BIT2
 set     PWMA_SM3CAPTCTRLA_EDGA0_1   BIT3

 set     PWMA_SM3CAPTCTRLA_EDGA1     (BIT4|BIT5)
;;   Edge A 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM3CAPTCTRLA_EDGA1_0   BIT4
 set     PWMA_SM3CAPTCTRLA_EDGA1_1   BIT5

 set     PWMA_SM3CAPTCTRLA_INP_SELA  BIT6
;;   Input Select A
;;     0b0 ==> Raw PWM_A input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLA[EDGA0] and CAPTCTRLA[EDGA1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRA[EDGA0] and/or CAPTCTRLA[EDGA1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM3CAPTCTRLA_EDGCNTA_EN BIT7
;;   Edge Counter A Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM3CAPTCTRLA_CFAWM     (BIT8|BIT9)
;;   Capture A FIFOs Water Mark
 set     PWMA_SM3CAPTCTRLA_CFAWM_0   BIT8
 set     PWMA_SM3CAPTCTRLA_CFAWM_1   BIT9

 set     PWMA_SM3CAPTCTRLA_CA0CNT    (BIT10|BIT11|BIT12)
;;   Capture A0 FIFO Word Count
 set     PWMA_SM3CAPTCTRLA_CA0CNT_0  BIT10
 set     PWMA_SM3CAPTCTRLA_CA0CNT_1  BIT11
 set     PWMA_SM3CAPTCTRLA_CA0CNT_2  BIT12

 set     PWMA_SM3CAPTCTRLA_CA1CNT    (BIT13|BIT14|BIT15)
;;   Capture A1 FIFO Word Count
 set     PWMA_SM3CAPTCTRLA_CA1CNT_0  BIT13
 set     PWMA_SM3CAPTCTRLA_CA1CNT_1  BIT14
 set     PWMA_SM3CAPTCTRLA_CA1CNT_2  BIT15

 set     PWMA_SM3CAPTCOMPA_EDGCMPA   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare A
 set     PWMA_SM3CAPTCOMPA_EDGCMPA_0 BIT0
 set     PWMA_SM3CAPTCOMPA_EDGCMPA_1 BIT1
 set     PWMA_SM3CAPTCOMPA_EDGCMPA_2 BIT2
 set     PWMA_SM3CAPTCOMPA_EDGCMPA_3 BIT3
 set     PWMA_SM3CAPTCOMPA_EDGCMPA_4 BIT4
 set     PWMA_SM3CAPTCOMPA_EDGCMPA_5 BIT5
 set     PWMA_SM3CAPTCOMPA_EDGCMPA_6 BIT6
 set     PWMA_SM3CAPTCOMPA_EDGCMPA_7 BIT7

 set     PWMA_SM3CAPTCOMPA_EDGCNTA   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter A
 set     PWMA_SM3CAPTCOMPA_EDGCNTA_0 BIT8
 set     PWMA_SM3CAPTCOMPA_EDGCNTA_1 BIT9
 set     PWMA_SM3CAPTCOMPA_EDGCNTA_2 BIT10
 set     PWMA_SM3CAPTCOMPA_EDGCNTA_3 BIT11
 set     PWMA_SM3CAPTCOMPA_EDGCNTA_4 BIT12
 set     PWMA_SM3CAPTCOMPA_EDGCNTA_5 BIT13
 set     PWMA_SM3CAPTCOMPA_EDGCNTA_6 BIT14
 set     PWMA_SM3CAPTCOMPA_EDGCNTA_7 BIT15

 set     PWMA_SM3CAPTCTRLB_ARMB      BIT0
;;   Arm B
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLB[EDGBx] is enabled.

 set     PWMA_SM3CAPTCTRLB_ONESHOTB  BIT1
;;   One Shot Mode B
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLB[ARMB] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after CAPTCTRLB[ARMB] is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and CAPTCTRLB[ARMB] is cleared. No further captures will be performed until CAPTCTRLB[ARMB] is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled
;;             capture circuit and CAPTCTRLB[ARMB] is then cleared.

 set     PWMA_SM3CAPTCTRLB_EDGB0     (BIT2|BIT3)
;;   Edge B 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM3CAPTCTRLB_EDGB0_0   BIT2
 set     PWMA_SM3CAPTCTRLB_EDGB0_1   BIT3

 set     PWMA_SM3CAPTCTRLB_EDGB1     (BIT4|BIT5)
;;   Edge B 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM3CAPTCTRLB_EDGB1_0   BIT4
 set     PWMA_SM3CAPTCTRLB_EDGB1_1   BIT5

 set     PWMA_SM3CAPTCTRLB_INP_SELB  BIT6
;;   Input Select B
;;     0b0 ==> Raw PWM_B input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLB[EDGB0] and CAPTCTRLB[EDGB1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRB[EDGB0] and/or CAPTCTRLB[EDGB1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM3CAPTCTRLB_EDGCNTB_EN BIT7
;;   Edge Counter B Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM3CAPTCTRLB_CFBWM     (BIT8|BIT9)
;;   Capture B FIFOs Water Mark
 set     PWMA_SM3CAPTCTRLB_CFBWM_0   BIT8
 set     PWMA_SM3CAPTCTRLB_CFBWM_1   BIT9

 set     PWMA_SM3CAPTCTRLB_CB0CNT    (BIT10|BIT11|BIT12)
;;   Capture B0 FIFO Word Count
 set     PWMA_SM3CAPTCTRLB_CB0CNT_0  BIT10
 set     PWMA_SM3CAPTCTRLB_CB0CNT_1  BIT11
 set     PWMA_SM3CAPTCTRLB_CB0CNT_2  BIT12

 set     PWMA_SM3CAPTCTRLB_CB1CNT    (BIT13|BIT14|BIT15)
;;   Capture B1 FIFO Word Count
 set     PWMA_SM3CAPTCTRLB_CB1CNT_0  BIT13
 set     PWMA_SM3CAPTCTRLB_CB1CNT_1  BIT14
 set     PWMA_SM3CAPTCTRLB_CB1CNT_2  BIT15

 set     PWMA_SM3CAPTCOMPB_EDGCMPB   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare B
 set     PWMA_SM3CAPTCOMPB_EDGCMPB_0 BIT0
 set     PWMA_SM3CAPTCOMPB_EDGCMPB_1 BIT1
 set     PWMA_SM3CAPTCOMPB_EDGCMPB_2 BIT2
 set     PWMA_SM3CAPTCOMPB_EDGCMPB_3 BIT3
 set     PWMA_SM3CAPTCOMPB_EDGCMPB_4 BIT4
 set     PWMA_SM3CAPTCOMPB_EDGCMPB_5 BIT5
 set     PWMA_SM3CAPTCOMPB_EDGCMPB_6 BIT6
 set     PWMA_SM3CAPTCOMPB_EDGCMPB_7 BIT7

 set     PWMA_SM3CAPTCOMPB_EDGCNTB   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter B
 set     PWMA_SM3CAPTCOMPB_EDGCNTB_0 BIT8
 set     PWMA_SM3CAPTCOMPB_EDGCNTB_1 BIT9
 set     PWMA_SM3CAPTCOMPB_EDGCNTB_2 BIT10
 set     PWMA_SM3CAPTCOMPB_EDGCNTB_3 BIT11
 set     PWMA_SM3CAPTCOMPB_EDGCNTB_4 BIT12
 set     PWMA_SM3CAPTCOMPB_EDGCNTB_5 BIT13
 set     PWMA_SM3CAPTCOMPB_EDGCNTB_6 BIT14
 set     PWMA_SM3CAPTCOMPB_EDGCNTB_7 BIT15

 set     PWMA_SM3CAPTCTRLX_ARMX      BIT0
;;   Arm X
;;     0b0 ==> Input capture operation is disabled.
;;     0b1 ==> Input capture operation as specified by CAPTCTRLX[EDGXx] is enabled.

 set     PWMA_SM3CAPTCTRLX_ONESHOTX  BIT1
;;   One Shot Mode Aux
;;     0b0 ==> Free running mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after the ARMX bit is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and capture circuit 0 is re-armed. The process continues indefinitely. If only one of the capture circuits is enabled, then captures continue indefinitely on the enabled capture circuit.
;;     0b1 ==> One shot mode is selected. If both capture circuits are enabled, then capture circuit 0 is armed first after the ARMX bit is set. Once a capture occurs, capture circuit 0 is disarmed and capture circuit 1 is armed. After capture circuit 1 performs a capture, it is disarmed and the ARMX bit is cleared. No further captures will be performed until the ARMX bit is set again. If only one of the capture circuits is enabled, then a single capture will occur on the enabled capture
;;             circuit and the ARMX bit is then cleared.

 set     PWMA_SM3CAPTCTRLX_EDGX0     (BIT2|BIT3)
;;   Edge X 0
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM3CAPTCTRLX_EDGX0_0   BIT2
 set     PWMA_SM3CAPTCTRLX_EDGX0_1   BIT3

 set     PWMA_SM3CAPTCTRLX_EDGX1     (BIT4|BIT5)
;;   Edge X 1
;;     0b00 ==> Disabled
;;     0b01 ==> Capture falling edges
;;     0b10 ==> Capture rising edges
;;     0b11 ==> Capture any edge
 set     PWMA_SM3CAPTCTRLX_EDGX1_0   BIT4
 set     PWMA_SM3CAPTCTRLX_EDGX1_1   BIT5

 set     PWMA_SM3CAPTCTRLX_INP_SELX  BIT6
;;   Input Select X
;;     0b0 ==> Raw PWM_X input signal selected as source.
;;     0b1 ==> Output of edge counter/compare selected as source. When this bitfield is set to 1, the internal edge counter is enabled and the rising and/or falling edges specified by the CAPTCTRLX[EDGX0] and CAPTCTRLX[EDGX1] fields are ignored. The software must still place a value other than 00 in either or both of the CAPTCTLRX[EDGX0] and/or CAPTCTRLX[EDGX1] fields in order to enable one or both of the capture registers.

 set     PWMA_SM3CAPTCTRLX_EDGCNTX_EN BIT7
;;   Edge Counter X Enable
;;     0b0 ==> Edge counter disabled and held in reset
;;     0b1 ==> Edge counter enabled

 set     PWMA_SM3CAPTCTRLX_CFXWM     (BIT8|BIT9)
;;   Capture X FIFOs Water Mark
 set     PWMA_SM3CAPTCTRLX_CFXWM_0   BIT8
 set     PWMA_SM3CAPTCTRLX_CFXWM_1   BIT9

 set     PWMA_SM3CAPTCTRLX_CX0CNT    (BIT10|BIT11|BIT12)
;;   Capture X0 FIFO Word Count
 set     PWMA_SM3CAPTCTRLX_CX0CNT_0  BIT10
 set     PWMA_SM3CAPTCTRLX_CX0CNT_1  BIT11
 set     PWMA_SM3CAPTCTRLX_CX0CNT_2  BIT12

 set     PWMA_SM3CAPTCTRLX_CX1CNT    (BIT13|BIT14|BIT15)
;;   Capture X1 FIFO Word Count
 set     PWMA_SM3CAPTCTRLX_CX1CNT_0  BIT13
 set     PWMA_SM3CAPTCTRLX_CX1CNT_1  BIT14
 set     PWMA_SM3CAPTCTRLX_CX1CNT_2  BIT15

 set     PWMA_SM3CAPTCOMPX_EDGCMPX   (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Edge Compare X
 set     PWMA_SM3CAPTCOMPX_EDGCMPX_0 BIT0
 set     PWMA_SM3CAPTCOMPX_EDGCMPX_1 BIT1
 set     PWMA_SM3CAPTCOMPX_EDGCMPX_2 BIT2
 set     PWMA_SM3CAPTCOMPX_EDGCMPX_3 BIT3
 set     PWMA_SM3CAPTCOMPX_EDGCMPX_4 BIT4
 set     PWMA_SM3CAPTCOMPX_EDGCMPX_5 BIT5
 set     PWMA_SM3CAPTCOMPX_EDGCMPX_6 BIT6
 set     PWMA_SM3CAPTCOMPX_EDGCMPX_7 BIT7

 set     PWMA_SM3CAPTCOMPX_EDGCNTX   (BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Edge Counter X
 set     PWMA_SM3CAPTCOMPX_EDGCNTX_0 BIT8
 set     PWMA_SM3CAPTCOMPX_EDGCNTX_1 BIT9
 set     PWMA_SM3CAPTCOMPX_EDGCNTX_2 BIT10
 set     PWMA_SM3CAPTCOMPX_EDGCNTX_3 BIT11
 set     PWMA_SM3CAPTCOMPX_EDGCNTX_4 BIT12
 set     PWMA_SM3CAPTCOMPX_EDGCNTX_5 BIT13
 set     PWMA_SM3CAPTCOMPX_EDGCNTX_6 BIT14
 set     PWMA_SM3CAPTCOMPX_EDGCNTX_7 BIT15

 set     PWMA_SM3CVAL0_CAPTVAL0      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM3CVAL0_CAPTVAL0_0    BIT0
 set     PWMA_SM3CVAL0_CAPTVAL0_1    BIT1
 set     PWMA_SM3CVAL0_CAPTVAL0_2    BIT2
 set     PWMA_SM3CVAL0_CAPTVAL0_3    BIT3
 set     PWMA_SM3CVAL0_CAPTVAL0_4    BIT4
 set     PWMA_SM3CVAL0_CAPTVAL0_5    BIT5
 set     PWMA_SM3CVAL0_CAPTVAL0_6    BIT6
 set     PWMA_SM3CVAL0_CAPTVAL0_7    BIT7
 set     PWMA_SM3CVAL0_CAPTVAL0_8    BIT8
 set     PWMA_SM3CVAL0_CAPTVAL0_9    BIT9
 set     PWMA_SM3CVAL0_CAPTVAL0_10   BIT10
 set     PWMA_SM3CVAL0_CAPTVAL0_11   BIT11
 set     PWMA_SM3CVAL0_CAPTVAL0_12   BIT12
 set     PWMA_SM3CVAL0_CAPTVAL0_13   BIT13
 set     PWMA_SM3CVAL0_CAPTVAL0_14   BIT14
 set     PWMA_SM3CVAL0_CAPTVAL0_15   BIT15

 set     PWMA_SM3CVAL0CYC_CVAL0CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM3CVAL0CYC_CVAL0CYC_0 BIT0
 set     PWMA_SM3CVAL0CYC_CVAL0CYC_1 BIT1
 set     PWMA_SM3CVAL0CYC_CVAL0CYC_2 BIT2
 set     PWMA_SM3CVAL0CYC_CVAL0CYC_3 BIT3

 set     PWMA_SM3CVAL1_CAPTVAL1      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM3CVAL1_CAPTVAL1_0    BIT0
 set     PWMA_SM3CVAL1_CAPTVAL1_1    BIT1
 set     PWMA_SM3CVAL1_CAPTVAL1_2    BIT2
 set     PWMA_SM3CVAL1_CAPTVAL1_3    BIT3
 set     PWMA_SM3CVAL1_CAPTVAL1_4    BIT4
 set     PWMA_SM3CVAL1_CAPTVAL1_5    BIT5
 set     PWMA_SM3CVAL1_CAPTVAL1_6    BIT6
 set     PWMA_SM3CVAL1_CAPTVAL1_7    BIT7
 set     PWMA_SM3CVAL1_CAPTVAL1_8    BIT8
 set     PWMA_SM3CVAL1_CAPTVAL1_9    BIT9
 set     PWMA_SM3CVAL1_CAPTVAL1_10   BIT10
 set     PWMA_SM3CVAL1_CAPTVAL1_11   BIT11
 set     PWMA_SM3CVAL1_CAPTVAL1_12   BIT12
 set     PWMA_SM3CVAL1_CAPTVAL1_13   BIT13
 set     PWMA_SM3CVAL1_CAPTVAL1_14   BIT14
 set     PWMA_SM3CVAL1_CAPTVAL1_15   BIT15

 set     PWMA_SM3CVAL1CYC_CVAL1CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM3CVAL1CYC_CVAL1CYC_0 BIT0
 set     PWMA_SM3CVAL1CYC_CVAL1CYC_1 BIT1
 set     PWMA_SM3CVAL1CYC_CVAL1CYC_2 BIT2
 set     PWMA_SM3CVAL1CYC_CVAL1CYC_3 BIT3

 set     PWMA_SM3CVAL2_CAPTVAL2      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM3CVAL2_CAPTVAL2_0    BIT0
 set     PWMA_SM3CVAL2_CAPTVAL2_1    BIT1
 set     PWMA_SM3CVAL2_CAPTVAL2_2    BIT2
 set     PWMA_SM3CVAL2_CAPTVAL2_3    BIT3
 set     PWMA_SM3CVAL2_CAPTVAL2_4    BIT4
 set     PWMA_SM3CVAL2_CAPTVAL2_5    BIT5
 set     PWMA_SM3CVAL2_CAPTVAL2_6    BIT6
 set     PWMA_SM3CVAL2_CAPTVAL2_7    BIT7
 set     PWMA_SM3CVAL2_CAPTVAL2_8    BIT8
 set     PWMA_SM3CVAL2_CAPTVAL2_9    BIT9
 set     PWMA_SM3CVAL2_CAPTVAL2_10   BIT10
 set     PWMA_SM3CVAL2_CAPTVAL2_11   BIT11
 set     PWMA_SM3CVAL2_CAPTVAL2_12   BIT12
 set     PWMA_SM3CVAL2_CAPTVAL2_13   BIT13
 set     PWMA_SM3CVAL2_CAPTVAL2_14   BIT14
 set     PWMA_SM3CVAL2_CAPTVAL2_15   BIT15

 set     PWMA_SM3CVAL2CYC_CVAL2CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM3CVAL2CYC_CVAL2CYC_0 BIT0
 set     PWMA_SM3CVAL2CYC_CVAL2CYC_1 BIT1
 set     PWMA_SM3CVAL2CYC_CVAL2CYC_2 BIT2
 set     PWMA_SM3CVAL2CYC_CVAL2CYC_3 BIT3

 set     PWMA_SM3CVAL3_CAPTVAL3      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM3CVAL3_CAPTVAL3_0    BIT0
 set     PWMA_SM3CVAL3_CAPTVAL3_1    BIT1
 set     PWMA_SM3CVAL3_CAPTVAL3_2    BIT2
 set     PWMA_SM3CVAL3_CAPTVAL3_3    BIT3
 set     PWMA_SM3CVAL3_CAPTVAL3_4    BIT4
 set     PWMA_SM3CVAL3_CAPTVAL3_5    BIT5
 set     PWMA_SM3CVAL3_CAPTVAL3_6    BIT6
 set     PWMA_SM3CVAL3_CAPTVAL3_7    BIT7
 set     PWMA_SM3CVAL3_CAPTVAL3_8    BIT8
 set     PWMA_SM3CVAL3_CAPTVAL3_9    BIT9
 set     PWMA_SM3CVAL3_CAPTVAL3_10   BIT10
 set     PWMA_SM3CVAL3_CAPTVAL3_11   BIT11
 set     PWMA_SM3CVAL3_CAPTVAL3_12   BIT12
 set     PWMA_SM3CVAL3_CAPTVAL3_13   BIT13
 set     PWMA_SM3CVAL3_CAPTVAL3_14   BIT14
 set     PWMA_SM3CVAL3_CAPTVAL3_15   BIT15

 set     PWMA_SM3CVAL3CYC_CVAL3CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM3CVAL3CYC_CVAL3CYC_0 BIT0
 set     PWMA_SM3CVAL3CYC_CVAL3CYC_1 BIT1
 set     PWMA_SM3CVAL3CYC_CVAL3CYC_2 BIT2
 set     PWMA_SM3CVAL3CYC_CVAL3CYC_3 BIT3

 set     PWMA_SM3CVAL4_CAPTVAL4      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM3CVAL4_CAPTVAL4_0    BIT0
 set     PWMA_SM3CVAL4_CAPTVAL4_1    BIT1
 set     PWMA_SM3CVAL4_CAPTVAL4_2    BIT2
 set     PWMA_SM3CVAL4_CAPTVAL4_3    BIT3
 set     PWMA_SM3CVAL4_CAPTVAL4_4    BIT4
 set     PWMA_SM3CVAL4_CAPTVAL4_5    BIT5
 set     PWMA_SM3CVAL4_CAPTVAL4_6    BIT6
 set     PWMA_SM3CVAL4_CAPTVAL4_7    BIT7
 set     PWMA_SM3CVAL4_CAPTVAL4_8    BIT8
 set     PWMA_SM3CVAL4_CAPTVAL4_9    BIT9
 set     PWMA_SM3CVAL4_CAPTVAL4_10   BIT10
 set     PWMA_SM3CVAL4_CAPTVAL4_11   BIT11
 set     PWMA_SM3CVAL4_CAPTVAL4_12   BIT12
 set     PWMA_SM3CVAL4_CAPTVAL4_13   BIT13
 set     PWMA_SM3CVAL4_CAPTVAL4_14   BIT14
 set     PWMA_SM3CVAL4_CAPTVAL4_15   BIT15

 set     PWMA_SM3CVAL4CYC_CVAL4CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM3CVAL4CYC_CVAL4CYC_0 BIT0
 set     PWMA_SM3CVAL4CYC_CVAL4CYC_1 BIT1
 set     PWMA_SM3CVAL4CYC_CVAL4CYC_2 BIT2
 set     PWMA_SM3CVAL4CYC_CVAL4CYC_3 BIT3

 set     PWMA_SM3CVAL5_CAPTVAL5      (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     PWMA_SM3CVAL5_CAPTVAL5_0    BIT0
 set     PWMA_SM3CVAL5_CAPTVAL5_1    BIT1
 set     PWMA_SM3CVAL5_CAPTVAL5_2    BIT2
 set     PWMA_SM3CVAL5_CAPTVAL5_3    BIT3
 set     PWMA_SM3CVAL5_CAPTVAL5_4    BIT4
 set     PWMA_SM3CVAL5_CAPTVAL5_5    BIT5
 set     PWMA_SM3CVAL5_CAPTVAL5_6    BIT6
 set     PWMA_SM3CVAL5_CAPTVAL5_7    BIT7
 set     PWMA_SM3CVAL5_CAPTVAL5_8    BIT8
 set     PWMA_SM3CVAL5_CAPTVAL5_9    BIT9
 set     PWMA_SM3CVAL5_CAPTVAL5_10   BIT10
 set     PWMA_SM3CVAL5_CAPTVAL5_11   BIT11
 set     PWMA_SM3CVAL5_CAPTVAL5_12   BIT12
 set     PWMA_SM3CVAL5_CAPTVAL5_13   BIT13
 set     PWMA_SM3CVAL5_CAPTVAL5_14   BIT14
 set     PWMA_SM3CVAL5_CAPTVAL5_15   BIT15

 set     PWMA_SM3CVAL5CYC_CVAL5CYC   (BIT0|BIT1|BIT2|BIT3)
 set     PWMA_SM3CVAL5CYC_CVAL5CYC_0 BIT0
 set     PWMA_SM3CVAL5CYC_CVAL5CYC_1 BIT1
 set     PWMA_SM3CVAL5CYC_CVAL5CYC_2 BIT2
 set     PWMA_SM3CVAL5CYC_CVAL5CYC_3 BIT3

 set     PWMA_OUTEN_PWMX_EN          (BIT0|BIT1|BIT2|BIT3)
;;   PWM_X Output Enables
;;     0b0 ==> PWM_X output disabled.
;;     0b1 ==> PWM_X output enabled.
 set     PWMA_OUTEN_PWMX_EN_0        BIT0
 set     PWMA_OUTEN_PWMX_EN_1        BIT1
 set     PWMA_OUTEN_PWMX_EN_2        BIT2
 set     PWMA_OUTEN_PWMX_EN_3        BIT3

 set     PWMA_OUTEN_PWMB_EN          (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Output Enables
;;     0b0 ==> PWM_B output disabled.
;;     0b1 ==> PWM_B output enabled.
 set     PWMA_OUTEN_PWMB_EN_0        BIT4
 set     PWMA_OUTEN_PWMB_EN_1        BIT5
 set     PWMA_OUTEN_PWMB_EN_2        BIT6
 set     PWMA_OUTEN_PWMB_EN_3        BIT7

 set     PWMA_OUTEN_PWMA_EN          (BIT8|BIT9|BIT10|BIT11)
;;   PWM_A Output Enables
;;     0b0 ==> PWM_A output disabled.
;;     0b1 ==> PWM_A output enabled.
 set     PWMA_OUTEN_PWMA_EN_0        BIT8
 set     PWMA_OUTEN_PWMA_EN_1        BIT9
 set     PWMA_OUTEN_PWMA_EN_2        BIT10
 set     PWMA_OUTEN_PWMA_EN_3        BIT11

 set     PWMA_MASK_MASKX             (BIT0|BIT1|BIT2|BIT3)
;;   PWM_X Masks
;;     0b0 ==> PWM_X output normal.
;;     0b1 ==> PWM_X output masked.
 set     PWMA_MASK_MASKX_0           BIT0
 set     PWMA_MASK_MASKX_1           BIT1
 set     PWMA_MASK_MASKX_2           BIT2
 set     PWMA_MASK_MASKX_3           BIT3

 set     PWMA_MASK_MASKB             (BIT4|BIT5|BIT6|BIT7)
;;   PWM_B Masks
;;     0b0 ==> PWM_B output normal.
;;     0b1 ==> PWM_B output masked.
 set     PWMA_MASK_MASKB_0           BIT4
 set     PWMA_MASK_MASKB_1           BIT5
 set     PWMA_MASK_MASKB_2           BIT6
 set     PWMA_MASK_MASKB_3           BIT7

 set     PWMA_MASK_MASKA             (BIT8|BIT9|BIT10|BIT11)
;;   PWM_A Masks
;;     0b0 ==> PWM_A output normal.
;;     0b1 ==> PWM_A output masked.
 set     PWMA_MASK_MASKA_0           BIT8
 set     PWMA_MASK_MASKA_1           BIT9
 set     PWMA_MASK_MASKA_2           BIT10
 set     PWMA_MASK_MASKA_3           BIT11

 set     PWMA_MASK_UPDATE_MASK       (BIT12|BIT13|BIT14|BIT15)
;;   Update Mask Bits Immediately
;;     0b0 ==> Normal operation. MASK* bits within the corresponding submodule are not updated until a FORCE_OUT event occurs within the submodule.
;;     0b1 ==> Immediate operation. MASK* bits within the corresponding submodule are updated on the following clock edge after setting this bit.
 set     PWMA_MASK_UPDATE_MASK_0     BIT12
 set     PWMA_MASK_UPDATE_MASK_1     BIT13
 set     PWMA_MASK_UPDATE_MASK_2     BIT14
 set     PWMA_MASK_UPDATE_MASK_3     BIT15

 set     PWMA_SWCOUT_SM0OUT45        BIT0
;;   Submodule 0 Software Controlled Output 45
;;     0b0 ==> A logic 0 is supplied to the deadtime generator of submodule 0 instead of PWM45.
;;     0b1 ==> A logic 1 is supplied to the deadtime generator of submodule 0 instead of PWM45.

 set     PWMA_SWCOUT_SM0OUT23        BIT1
;;   Submodule 0 Software Controlled Output 23
;;     0b0 ==> A logic 0 is supplied to the deadtime generator of submodule 0 instead of PWM23.
;;     0b1 ==> A logic 1 is supplied to the deadtime generator of submodule 0 instead of PWM23.

 set     PWMA_SWCOUT_SM1OUT45        BIT2
;;   Submodule 1 Software Controlled Output 45
;;     0b0 ==> A logic 0 is supplied to the deadtime generator of submodule 1 instead of PWM45.
;;     0b1 ==> A logic 1 is supplied to the deadtime generator of submodule 1 instead of PWM45.

 set     PWMA_SWCOUT_SM1OUT23        BIT3
;;   Submodule 1 Software Controlled Output 23
;;     0b0 ==> A logic 0 is supplied to the deadtime generator of submodule 1 instead of PWM23.
;;     0b1 ==> A logic 1 is supplied to the deadtime generator of submodule 1 instead of PWM23.

 set     PWMA_SWCOUT_SM2OUT45        BIT4
;;   Submodule 2 Software Controlled Output 45
;;     0b0 ==> A logic 0 is supplied to the deadtime generator of submodule 2 instead of PWM45.
;;     0b1 ==> A logic 1 is supplied to the deadtime generator of submodule 2 instead of PWM45.

 set     PWMA_SWCOUT_SM2OUT23        BIT5
;;   Submodule 2 Software Controlled Output 23
;;     0b0 ==> A logic 0 is supplied to the deadtime generator of submodule 2 instead of PWM23.
;;     0b1 ==> A logic 1 is supplied to the deadtime generator of submodule 2 instead of PWM23.

 set     PWMA_SWCOUT_SM3OUT45        BIT6
;;   Submodule 3 Software Controlled Output 45
;;     0b0 ==> A logic 0 is supplied to the deadtime generator of submodule 3 instead of PWM45.
;;     0b1 ==> A logic 1 is supplied to the deadtime generator of submodule 3 instead of PWM45.

 set     PWMA_SWCOUT_SM3OUT23        BIT7
;;   Submodule 3 Software Controlled Output 23
;;     0b0 ==> A logic 0 is supplied to the deadtime generator of submodule 3 instead of PWM23.
;;     0b1 ==> A logic 1 is supplied to the deadtime generator of submodule 3 instead of PWM23.

 set     PWMA_DTSRCSEL_SM0SEL45      (BIT0|BIT1)
;;   Submodule 0 PWM45 Control Select
;;     0b00 ==> Generated SM0PWM45 signal is used by the deadtime logic.
;;     0b01 ==> Inverted generated SM0PWM45 signal is used by the deadtime logic.
;;     0b10 ==> SWCOUT[SM0OUT45] is used by the deadtime logic.
;;     0b11 ==> PWM0_EXTB signal is used by the deadtime logic.
 set     PWMA_DTSRCSEL_SM0SEL45_0    BIT0
 set     PWMA_DTSRCSEL_SM0SEL45_1    BIT1

 set     PWMA_DTSRCSEL_SM0SEL23      (BIT2|BIT3)
;;   Submodule 0 PWM23 Control Select
;;     0b00 ==> Generated SM0PWM23 signal is used by the deadtime logic.
;;     0b01 ==> Inverted generated SM0PWM23 signal is used by the deadtime logic.
;;     0b10 ==> SWCOUT[SM0OUT23] is used by the deadtime logic.
;;     0b11 ==> PWM0_EXTA signal is used by the deadtime logic.
 set     PWMA_DTSRCSEL_SM0SEL23_0    BIT2
 set     PWMA_DTSRCSEL_SM0SEL23_1    BIT3

 set     PWMA_DTSRCSEL_SM1SEL45      (BIT4|BIT5)
;;   Submodule 1 PWM45 Control Select
;;     0b00 ==> Generated SM1PWM45 signal is used by the deadtime logic.
;;     0b01 ==> Inverted generated SM1PWM45 signal is used by the deadtime logic.
;;     0b10 ==> SWCOUT[SM1OUT45] is used by the deadtime logic.
;;     0b11 ==> PWM1_EXTB signal is used by the deadtime logic.
 set     PWMA_DTSRCSEL_SM1SEL45_0    BIT4
 set     PWMA_DTSRCSEL_SM1SEL45_1    BIT5

 set     PWMA_DTSRCSEL_SM1SEL23      (BIT6|BIT7)
;;   Submodule 1 PWM23 Control Select
;;     0b00 ==> Generated SM1PWM23 signal is used by the deadtime logic.
;;     0b01 ==> Inverted generated SM1PWM23 signal is used by the deadtime logic.
;;     0b10 ==> SWCOUT[SM1OUT23] is used by the deadtime logic.
;;     0b11 ==> PWM1_EXTA signal is used by the deadtime logic.
 set     PWMA_DTSRCSEL_SM1SEL23_0    BIT6
 set     PWMA_DTSRCSEL_SM1SEL23_1    BIT7

 set     PWMA_DTSRCSEL_SM2SEL45      (BIT8|BIT9)
;;   Submodule 2 PWM45 Control Select
;;     0b00 ==> Generated SM2PWM45 signal is used by the deadtime logic.
;;     0b01 ==> Inverted generated SM2PWM45 signal is used by the deadtime logic.
;;     0b10 ==> SWCOUT[SM2OUT45] is used by the deadtime logic.
;;     0b11 ==> PWM2_EXTB signal is used by the deadtime logic.
 set     PWMA_DTSRCSEL_SM2SEL45_0    BIT8
 set     PWMA_DTSRCSEL_SM2SEL45_1    BIT9

 set     PWMA_DTSRCSEL_SM2SEL23      (BIT10|BIT11)
;;   Submodule 2 PWM23 Control Select
;;     0b00 ==> Generated SM2PWM23 signal is used by the deadtime logic.
;;     0b01 ==> Inverted generated SM2PWM23 signal is used by the deadtime logic.
;;     0b10 ==> SWCOUT[SM2OUT23] is used by the deadtime logic.
;;     0b11 ==> PWM2_EXTA signal is used by the deadtime logic.
 set     PWMA_DTSRCSEL_SM2SEL23_0    BIT10
 set     PWMA_DTSRCSEL_SM2SEL23_1    BIT11

 set     PWMA_DTSRCSEL_SM3SEL45      (BIT12|BIT13)
;;   Submodule 3 PWM45 Control Select
;;     0b00 ==> Generated SM3PWM45 signal is used by the deadtime logic.
;;     0b01 ==> Inverted generated SM3PWM45 signal is used by the deadtime logic.
;;     0b10 ==> SWCOUT[SM3OUT45] is used by the deadtime logic.
;;     0b11 ==> PWM3_EXTB signal is used by the deadtime logic.
 set     PWMA_DTSRCSEL_SM3SEL45_0    BIT12
 set     PWMA_DTSRCSEL_SM3SEL45_1    BIT13

 set     PWMA_DTSRCSEL_SM3SEL23      (BIT14|BIT15)
;;   Submodule 3 PWM23 Control Select
;;     0b00 ==> Generated SM3PWM23 signal is used by the deadtime logic.
;;     0b01 ==> Inverted generated SM3PWM23 signal is used by the deadtime logic.
;;     0b10 ==> SWCOUT[SM3OUT23] is used by the deadtime logic.
;;     0b11 ==> PWM3_EXTA signal is used by the deadtime logic.
 set     PWMA_DTSRCSEL_SM3SEL23_0    BIT14
 set     PWMA_DTSRCSEL_SM3SEL23_1    BIT15

 set     PWMA_MCTRL_LDOK             (BIT0|BIT1|BIT2|BIT3)
;;   Load Okay
;;     0b0 ==> Do not load new values.
;;     0b1 ==> Load prescaler, modulus, and PWM values of the corresponding submodule.
 set     PWMA_MCTRL_LDOK_0           BIT0
 set     PWMA_MCTRL_LDOK_1           BIT1
 set     PWMA_MCTRL_LDOK_2           BIT2
 set     PWMA_MCTRL_LDOK_3           BIT3

 set     PWMA_MCTRL_CLDOK            (BIT4|BIT5|BIT6|BIT7)
;;   Clear Load Okay
 set     PWMA_MCTRL_CLDOK_0          BIT4
 set     PWMA_MCTRL_CLDOK_1          BIT5
 set     PWMA_MCTRL_CLDOK_2          BIT6
 set     PWMA_MCTRL_CLDOK_3          BIT7

 set     PWMA_MCTRL_RUN              (BIT8|BIT9|BIT10|BIT11)
;;   Run
;;     0b0 ==> PWM generator is disabled in the corresponding submodule.
;;     0b1 ==> PWM generator is enabled in the corresponding submodule.
 set     PWMA_MCTRL_RUN_0            BIT8
 set     PWMA_MCTRL_RUN_1            BIT9
 set     PWMA_MCTRL_RUN_2            BIT10
 set     PWMA_MCTRL_RUN_3            BIT11

 set     PWMA_MCTRL_IPOL             (BIT12|BIT13|BIT14|BIT15)
;;   Current Polarity
;;     0b0 ==> PWM23 is used to generate complementary PWM pair in the corresponding submodule.
;;     0b1 ==> PWM45 is used to generate complementary PWM pair in the corresponding submodule.
 set     PWMA_MCTRL_IPOL_0           BIT12
 set     PWMA_MCTRL_IPOL_1           BIT13
 set     PWMA_MCTRL_IPOL_2           BIT14
 set     PWMA_MCTRL_IPOL_3           BIT15

 set     PWMA_MCTRL2_MONPLL          (BIT0|BIT1)
;;   Monitor PLL State
;;     0b00 ==> Not locked. Do not monitor PLL operation. Resetting of the fractional delay block in case of PLL losing lock will be controlled by software.
;;     0b01 ==> Not locked. Monitor PLL operation to automatically disable the fractional delay block when the PLL encounters problems.
;;     0b10 ==> Locked. Do not monitor PLL operation. Resetting of the fractional delay block in case of PLL losing lock will be controlled by software. These bits are write protected until the next reset.
;;     0b11 ==> Locked. Monitor PLL operation to automatically disable the fractional delay block when the PLL encounters problems. These bits are write protected until the next reset.
 set     PWMA_MCTRL2_MONPLL_0        BIT0
 set     PWMA_MCTRL2_MONPLL_1        BIT1

 set     PWMA_FCTRL0_FIE             (BIT0|BIT1|BIT2|BIT3)
;;   Fault Interrupt Enables
;;     0b0 ==> FAULTx CPU interrupt requests disabled.
;;     0b1 ==> FAULTx CPU interrupt requests enabled.
 set     PWMA_FCTRL0_FIE_0           BIT0
 set     PWMA_FCTRL0_FIE_1           BIT1
 set     PWMA_FCTRL0_FIE_2           BIT2
 set     PWMA_FCTRL0_FIE_3           BIT3

 set     PWMA_FCTRL0_FSAFE           (BIT4|BIT5|BIT6|BIT7)
;;   Fault Safety Mode
;;     0b0 ==> Normal mode. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear at the start of a half cycle or full cycle depending on the state of FSTS[FFULL] without regard to the state of FSTS[FFPINx]. The PWM outputs disabled by this fault input will not be re-enabled until the actual FAULTx input signal de-asserts since the fault input will combinationally disable the PWM outputs (as programmed in DISMAPn).
;;     0b1 ==> Safe mode. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear and FSTS[FFPINx] is clear at the start of a half cycle or full cycle depending on the state of FSTS[FFULL].
 set     PWMA_FCTRL0_FSAFE_0         BIT4
 set     PWMA_FCTRL0_FSAFE_1         BIT5
 set     PWMA_FCTRL0_FSAFE_2         BIT6
 set     PWMA_FCTRL0_FSAFE_3         BIT7

 set     PWMA_FCTRL0_FAUTO           (BIT8|BIT9|BIT10|BIT11)
;;   Automatic Fault Clearing
;;     0b0 ==> Manual fault clearing. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear at the start of a half cycle or full cycle depending the state of FSTS[FFULL]. This is further controlled by FCTRL[FSAFE].
;;     0b1 ==> Automatic fault clearing. PWM outputs disabled by this fault are enabled when FSTS[FFPINx] is clear at the start of a half cycle or full cycle depending on the state of FSTS[FFULL] without regard to the state of FSTS[FFLAGx].
 set     PWMA_FCTRL0_FAUTO_0         BIT8
 set     PWMA_FCTRL0_FAUTO_1         BIT9
 set     PWMA_FCTRL0_FAUTO_2         BIT10
 set     PWMA_FCTRL0_FAUTO_3         BIT11

 set     PWMA_FCTRL0_FLVL            (BIT12|BIT13|BIT14|BIT15)
;;   Fault Level
;;     0b0 ==> A logic 0 on the fault input indicates a fault condition.
;;     0b1 ==> A logic 1 on the fault input indicates a fault condition.
 set     PWMA_FCTRL0_FLVL_0          BIT12
 set     PWMA_FCTRL0_FLVL_1          BIT13
 set     PWMA_FCTRL0_FLVL_2          BIT14
 set     PWMA_FCTRL0_FLVL_3          BIT15

 set     PWMA_FSTS0_FFLAG            (BIT0|BIT1|BIT2|BIT3)
;;   Fault Flags
;;     0b0 ==> No fault on the FAULTx pin.
;;     0b1 ==> Fault on the FAULTx pin.
 set     PWMA_FSTS0_FFLAG_0          BIT0
 set     PWMA_FSTS0_FFLAG_1          BIT1
 set     PWMA_FSTS0_FFLAG_2          BIT2
 set     PWMA_FSTS0_FFLAG_3          BIT3

 set     PWMA_FSTS0_FFULL            (BIT4|BIT5|BIT6|BIT7)
;;   Full Cycle
;;     0b0 ==> PWM outputs are not re-enabled at the start of a full cycle
;;     0b1 ==> PWM outputs are re-enabled at the start of a full cycle
 set     PWMA_FSTS0_FFULL_0          BIT4
 set     PWMA_FSTS0_FFULL_1          BIT5
 set     PWMA_FSTS0_FFULL_2          BIT6
 set     PWMA_FSTS0_FFULL_3          BIT7

 set     PWMA_FSTS0_FFPIN            (BIT8|BIT9|BIT10|BIT11)
;;   Filtered Fault Pins
 set     PWMA_FSTS0_FFPIN_0          BIT8
 set     PWMA_FSTS0_FFPIN_1          BIT9
 set     PWMA_FSTS0_FFPIN_2          BIT10
 set     PWMA_FSTS0_FFPIN_3          BIT11

 set     PWMA_FSTS0_FHALF            (BIT12|BIT13|BIT14|BIT15)
;;   Half Cycle Fault Recovery
;;     0b0 ==> PWM outputs are not re-enabled at the start of a half cycle.
;;     0b1 ==> PWM outputs are re-enabled at the start of a half cycle (as defined by VAL0).
 set     PWMA_FSTS0_FHALF_0          BIT12
 set     PWMA_FSTS0_FHALF_1          BIT13
 set     PWMA_FSTS0_FHALF_2          BIT14
 set     PWMA_FSTS0_FHALF_3          BIT15

 set     PWMA_FFILT0_FILT_PER        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Fault Filter Period
 set     PWMA_FFILT0_FILT_PER_0      BIT0
 set     PWMA_FFILT0_FILT_PER_1      BIT1
 set     PWMA_FFILT0_FILT_PER_2      BIT2
 set     PWMA_FFILT0_FILT_PER_3      BIT3
 set     PWMA_FFILT0_FILT_PER_4      BIT4
 set     PWMA_FFILT0_FILT_PER_5      BIT5
 set     PWMA_FFILT0_FILT_PER_6      BIT6
 set     PWMA_FFILT0_FILT_PER_7      BIT7

 set     PWMA_FFILT0_FILT_CNT        (BIT8|BIT9|BIT10)
;;   Fault Filter Count
 set     PWMA_FFILT0_FILT_CNT_0      BIT8
 set     PWMA_FFILT0_FILT_CNT_1      BIT9
 set     PWMA_FFILT0_FILT_CNT_2      BIT10

 set     PWMA_FFILT0_GSTR            BIT15
;;   Fault Glitch Stretch Enable
;;     0b0 ==> Fault input glitch stretching is disabled.
;;     0b1 ==> Input fault signals will be stretched to at least 2 IPBus clock cycles.

 set     PWMA_FTST0_FTEST            BIT0
;;   Fault Test
;;     0b0 ==> No fault
;;     0b1 ==> Cause a simulated fault

 set     PWMA_FCTRL1_FIE             (BIT0|BIT1|BIT2|BIT3)
;;   Fault Interrupt Enables
;;     0b0 ==> FAULTx CPU interrupt requests disabled.
;;     0b1 ==> FAULTx CPU interrupt requests enabled.
 set     PWMA_FCTRL1_FIE_0           BIT0
 set     PWMA_FCTRL1_FIE_1           BIT1
 set     PWMA_FCTRL1_FIE_2           BIT2
 set     PWMA_FCTRL1_FIE_3           BIT3

 set     PWMA_FCTRL1_FSAFE           (BIT4|BIT5|BIT6|BIT7)
;;   Fault Safety Mode
;;     0b0 ==> Normal mode. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear at the start of a half cycle or full cycle depending on the state of FSTS[FFULL] without regard to the state of FSTS[FFPINx]. The PWM outputs disabled by this fault input will not be re-enabled until the actual FAULTx input signal de-asserts since the fault input will combinationally disable the PWM outputs (as programmed in DISMAPn).
;;     0b1 ==> Safe mode. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear and FSTS[FFPINx] is clear at the start of a half cycle or full cycle depending on the state of FSTS[FFULL].
 set     PWMA_FCTRL1_FSAFE_0         BIT4
 set     PWMA_FCTRL1_FSAFE_1         BIT5
 set     PWMA_FCTRL1_FSAFE_2         BIT6
 set     PWMA_FCTRL1_FSAFE_3         BIT7

 set     PWMA_FCTRL1_FAUTO           (BIT8|BIT9|BIT10|BIT11)
;;   Automatic Fault Clearing
;;     0b0 ==> Manual fault clearing. PWM outputs disabled by this fault are not enabled until FSTS[FFLAGx] is clear at the start of a half cycle or full cycle depending the state of FSTS[FFULL]. This is further controlled by FCTRL[FSAFE].
;;     0b1 ==> Automatic fault clearing. PWM outputs disabled by this fault are enabled when FSTS[FFPINx] is clear at the start of a half cycle or full cycle depending on the state of FSTS[FFULL] without regard to the state of FSTS[FFLAGx].
 set     PWMA_FCTRL1_FAUTO_0         BIT8
 set     PWMA_FCTRL1_FAUTO_1         BIT9
 set     PWMA_FCTRL1_FAUTO_2         BIT10
 set     PWMA_FCTRL1_FAUTO_3         BIT11

 set     PWMA_FCTRL1_FLVL            (BIT12|BIT13|BIT14|BIT15)
;;   Fault Level
;;     0b0 ==> A logic 0 on the fault input indicates a fault condition.
;;     0b1 ==> A logic 1 on the fault input indicates a fault condition.
 set     PWMA_FCTRL1_FLVL_0          BIT12
 set     PWMA_FCTRL1_FLVL_1          BIT13
 set     PWMA_FCTRL1_FLVL_2          BIT14
 set     PWMA_FCTRL1_FLVL_3          BIT15

 set     PWMA_FSTS1_FFLAG            (BIT0|BIT1|BIT2|BIT3)
;;   Fault Flags
;;     0b0 ==> No fault on the FAULTx pin.
;;     0b1 ==> Fault on the FAULTx pin.
 set     PWMA_FSTS1_FFLAG_0          BIT0
 set     PWMA_FSTS1_FFLAG_1          BIT1
 set     PWMA_FSTS1_FFLAG_2          BIT2
 set     PWMA_FSTS1_FFLAG_3          BIT3

 set     PWMA_FSTS1_FFULL            (BIT4|BIT5|BIT6|BIT7)
;;   Full Cycle
;;     0b0 ==> PWM outputs are not re-enabled at the start of a full cycle
;;     0b1 ==> PWM outputs are re-enabled at the start of a full cycle
 set     PWMA_FSTS1_FFULL_0          BIT4
 set     PWMA_FSTS1_FFULL_1          BIT5
 set     PWMA_FSTS1_FFULL_2          BIT6
 set     PWMA_FSTS1_FFULL_3          BIT7

 set     PWMA_FSTS1_FFPIN            (BIT8|BIT9|BIT10|BIT11)
;;   Filtered Fault Pins
 set     PWMA_FSTS1_FFPIN_0          BIT8
 set     PWMA_FSTS1_FFPIN_1          BIT9
 set     PWMA_FSTS1_FFPIN_2          BIT10
 set     PWMA_FSTS1_FFPIN_3          BIT11

 set     PWMA_FSTS1_FHALF            (BIT12|BIT13|BIT14|BIT15)
;;   Half Cycle Fault Recovery
;;     0b0 ==> PWM outputs are not re-enabled at the start of a half cycle.
;;     0b1 ==> PWM outputs are re-enabled at the start of a half cycle (as defined by VAL0).
 set     PWMA_FSTS1_FHALF_0          BIT12
 set     PWMA_FSTS1_FHALF_1          BIT13
 set     PWMA_FSTS1_FHALF_2          BIT14
 set     PWMA_FSTS1_FHALF_3          BIT15

 set     PWMA_FFILT1_FILT_PER        (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Fault Filter Period
 set     PWMA_FFILT1_FILT_PER_0      BIT0
 set     PWMA_FFILT1_FILT_PER_1      BIT1
 set     PWMA_FFILT1_FILT_PER_2      BIT2
 set     PWMA_FFILT1_FILT_PER_3      BIT3
 set     PWMA_FFILT1_FILT_PER_4      BIT4
 set     PWMA_FFILT1_FILT_PER_5      BIT5
 set     PWMA_FFILT1_FILT_PER_6      BIT6
 set     PWMA_FFILT1_FILT_PER_7      BIT7

 set     PWMA_FFILT1_FILT_CNT        (BIT8|BIT9|BIT10)
;;   Fault Filter Count
 set     PWMA_FFILT1_FILT_CNT_0      BIT8
 set     PWMA_FFILT1_FILT_CNT_1      BIT9
 set     PWMA_FFILT1_FILT_CNT_2      BIT10

 set     PWMA_FFILT1_GSTR            BIT15
;;   Fault Glitch Stretch Enable
;;     0b0 ==> Fault input glitch stretching is disabled.
;;     0b1 ==> Input fault signals will be stretched to at least 2 IPBus clock cycles.

 set     PWMA_FTST1_FTEST            BIT0
;;   Fault Test
;;     0b0 ==> No fault
;;     0b1 ==> Cause a simulated fault

 set     QSCI0_RATE_FRAC_SBR         (BIT0|BIT1|BIT2)
;;   Fractional SCI Baud Rate divider, a value from 0 to 7 that is divided by 8
 set     QSCI0_RATE_FRAC_SBR_0       BIT0
 set     QSCI0_RATE_FRAC_SBR_1       BIT1
 set     QSCI0_RATE_FRAC_SBR_2       BIT2

 set     QSCI0_RATE_SBRL             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Low order bits of SCI Baud Rate divider, which combine with the CTRL3[SBRH] field to form a value from 1 to 65535
 set     QSCI0_RATE_SBRL_0           BIT3
 set     QSCI0_RATE_SBRL_1           BIT4
 set     QSCI0_RATE_SBRL_2           BIT5
 set     QSCI0_RATE_SBRL_3           BIT6
 set     QSCI0_RATE_SBRL_4           BIT7
 set     QSCI0_RATE_SBRL_5           BIT8
 set     QSCI0_RATE_SBRL_6           BIT9
 set     QSCI0_RATE_SBRL_7           BIT10
 set     QSCI0_RATE_SBRL_8           BIT11
 set     QSCI0_RATE_SBRL_9           BIT12
 set     QSCI0_RATE_SBRL_10          BIT13
 set     QSCI0_RATE_SBRL_11          BIT14
 set     QSCI0_RATE_SBRL_12          BIT15

 set     QSCI0_CTRL1_SBK             BIT0
;;   Send Break
;;     0b0 ==> No break characters
;;     0b1 ==> Transmit break characters

 set     QSCI0_CTRL1_RWU             BIT1
;;   Receiver Wake-up
;;     0b0 ==> Normal operation
;;     0b1 ==> Standby state

 set     QSCI0_CTRL1_RE              BIT2
;;   Receiver Enable
;;     0b0 ==> Receiver disabled
;;     0b1 ==> Receiver enabled

 set     QSCI0_CTRL1_TE              BIT3
;;   Transmitter Enable
;;     0b0 ==> Transmitter disabled
;;     0b1 ==> Transmitter enabled

 set     QSCI0_CTRL1_REIE            BIT4
;;   Receive Error Interrupt Enable
;;     0b0 ==> Error interrupt requests disabled
;;     0b1 ==> Error interrupt requests enabled

 set     QSCI0_CTRL1_RFIE            BIT5
;;   Receiver Full Interrupt Enable
;;     0b0 ==> STAT[RDRF] and STAT[OR] interrupt requests disabled
;;     0b1 ==> STAT[RDRF] and STAT[OR] interrupt requests enabled

 set     QSCI0_CTRL1_TIIE            BIT6
;;   Transmitter Idle Interrupt Enable
;;     0b0 ==> STAT[TIDLE] interrupt requests disabled
;;     0b1 ==> STAT[TIDLE] interrupt requests enabled

 set     QSCI0_CTRL1_TEIE            BIT7
;;   Transmitter Empty Interrupt Enable
;;     0b0 ==> STAT[TDRE] interrupt requests disabled
;;     0b1 ==> STAT[TDRE] interrupt requests enabled

 set     QSCI0_CTRL1_PT              BIT8
;;   Parity Type
;;     0b0 ==> Even parity
;;     0b1 ==> Odd parity

 set     QSCI0_CTRL1_PE              BIT9
;;   Parity Enable
;;     0b0 ==> Parity function disabled
;;     0b1 ==> Parity function enabled

 set     QSCI0_CTRL1_POL             BIT10
;;   Polarity
;;     0b0 ==> Don't invert transmit and receive data bits (normal mode)
;;     0b1 ==> Invert transmit and receive data bits (inverted mode)

 set     QSCI0_CTRL1_WAKE            BIT11
;;   Wake-up Condition
;;     0b0 ==> Idle line wake-up
;;     0b1 ==> Address mark wake-up

 set     QSCI0_CTRL1_M               BIT12
;;   Data Format Mode
;;     0b0 ==> One start bit, eight data bits, one stop bit
;;     0b1 ==> One start bit, nine data bits, one stop bit

 set     QSCI0_CTRL1_RSRC            BIT13
;;   Receiver Source
;;     0b0 ==> Receiver input internally connected to transmitter output
;;     0b1 ==> Receiver input connected to TXD pin

 set     QSCI0_CTRL1_SWAI            BIT14
;;   Stop in Wait Mode
;;     0b0 ==> SCI enabled in wait mode
;;     0b1 ==> SCI disabled in wait mode

 set     QSCI0_CTRL1_LOOP            BIT15
;;   Loop Select
;;     0b0 ==> Normal operation, regardless of the value of RSRC
;;     0b1 ==> When RSRC = 0: Loop mode with internal TXD fed back to RXD
;;     0b1 ==> When RSRC = 1: Single-wire mode with TXD output fed back to RXD

 set     QSCI0_CTRL2_RDE             BIT0
;;   Receiver DMA Enable
;;     0b0 ==> Receive DMA disabled
;;     0b1 ==> Receive DMA enabled

 set     QSCI0_CTRL2_TDE             BIT1
;;   Transmitter DMA Enable
;;     0b0 ==> Transmit DMA disabled
;;     0b1 ==> Transmit DMA enabled

 set     QSCI0_CTRL2_LINMODE         BIT3
;;   Enable LIN Slave Mode
;;     0b0 ==> The LIN auto baud feature is disabled and the RATE register maintains whatever value the processor writes to it.
;;     0b1 ==> Enable LIN slave functionality. This includes a search for the break character followed by a sync character (0x55) from the master LIN device. When the break is detected (11 consecutive samples of zero), the subsequent sync character is used to measure the baud rate of the transmitting master, and the RATE register is automatically reloaded with the value needed to "match" that baud rate.

 set     QSCI0_CTRL2_RIEIE           BIT4
;;   Receiver Input Edge Interrupt Enable
;;     0b0 ==> Receiver input edge interrupt request disabled.
;;     0b1 ==> Receiver input edge interrupt request enabled.

 set     QSCI0_CTRL2_FIFO_EN         BIT5
;;   FIFO Enable
;;     0b0 ==> FIFOs are disabled.
;;     0b1 ==> FIFOs are enabled.

 set     QSCI0_CTRL2_RFWM            (BIT6|BIT7)
;;   Receive FIFO Full Water Mark
;;     0b00 ==> RDRF is set when at least 1 word is in the FIFO
;;     0b01 ==> RDRF is set when at least 2 words are in the FIFO
;;     0b10 ==> RDRF is set when at least 3 words are in the FIFO
;;     0b11 ==> RDRF is set when at least 4 words are in the FIFO
 set     QSCI0_CTRL2_RFWM_0          BIT6
 set     QSCI0_CTRL2_RFWM_1          BIT7

 set     QSCI0_CTRL2_RFCNT           (BIT8|BIT9|BIT10)
;;   Receive FIFO Count
;;     0b000 ==> 0 words in RX FIFO
;;     0b001 ==> 1 word in RX FIFO
;;     0b010 ==> 2 words in RX FIFO
;;     0b011 ==> 3 words in RX FIFO
;;     0b100 ==> 4 words in RX FIFO
;;     0b101 ==> Reserved
;;     0b110 ==> Reserved
;;     0b111 ==> Reserved
 set     QSCI0_CTRL2_RFCNT_0         BIT8
 set     QSCI0_CTRL2_RFCNT_1         BIT9
 set     QSCI0_CTRL2_RFCNT_2         BIT10

 set     QSCI0_CTRL2_TFWM            (BIT11|BIT12)
;;   Transmit FIFO Empty Water Mark
;;     0b00 ==> TDRE is set when 0 words are in the FIFO
;;     0b01 ==> TDRE is set when 1 or fewer words are in the FIFO
;;     0b10 ==> TDRE is set when 2 or fewer words are in the FIFO
;;     0b11 ==> TDRE is set when 3 or fewer words are in the FIFO
 set     QSCI0_CTRL2_TFWM_0          BIT11
 set     QSCI0_CTRL2_TFWM_1          BIT12

 set     QSCI0_CTRL2_TFCNT           (BIT13|BIT14|BIT15)
;;   Transmit FIFO Count
;;     0b000 ==> 0 words in Tx FIFO
;;     0b001 ==> 1 word in Tx FIFO
;;     0b010 ==> 2 words in Tx FIFO
;;     0b011 ==> 3 words in Tx FIFO
;;     0b100 ==> 4 words in Tx FIFO
;;     0b101 ==> Reserved
;;     0b110 ==> Reserved
;;     0b111 ==> Reserved
 set     QSCI0_CTRL2_TFCNT_0         BIT13
 set     QSCI0_CTRL2_TFCNT_1         BIT14
 set     QSCI0_CTRL2_TFCNT_2         BIT15

 set     QSCI0_STAT_RAF              BIT0
;;   Receiver Active Flag
;;     0b0 ==> No reception in progress
;;     0b1 ==> Reception in progress

 set     QSCI0_STAT_RDMA             BIT1
;;   Receive DMA Request
;;     0b0 ==> Either CTRL2[RDE] is cleared or CTRL2[RDE] is set and CTRL2[RFCNT] is 0.
;;     0b1 ==> CTRL2[RDE] is set and CTRL2[RFCNT] is currently above 0.

 set     QSCI0_STAT_TDMA             BIT2
;;   Transmit DMA Request
;;     0b0 ==> Either CTRL2[TDE] is cleared or CTRL2[TDE] is set and CTRL2[TFCNT] is at its maximum value.
;;     0b1 ==> CTRL2[TDE] is set and CTRL2[TFCNT] is currently below its maximum value.

 set     QSCI0_STAT_LSE              BIT3
;;   LIN Sync Error
;;     0b0 ==> No error occurred since CTRL2[LINMODE] was enabled or the bit was last cleared
;;     0b1 ==> A sync error prevented loading of the RATE register with a revised value after the break was detected.

 set     QSCI0_STAT_RIEF             BIT4
;;   Receiver Input Edge Flag
;;     0b0 ==> No active edge on the receive pin has occured.
;;     0b1 ==> An active edge on the receive pin has occured.

 set     QSCI0_STAT_PF               BIT8
;;   Parity Error Flag
;;     0b0 ==> No parity error
;;     0b1 ==> Parity error

 set     QSCI0_STAT_FE               BIT9
;;   Framing Error Flag
;;     0b0 ==> No framing error
;;     0b1 ==> Framing error

 set     QSCI0_STAT_NF               BIT10
;;   Noise Flag
;;     0b0 ==> No noise
;;     0b1 ==> Noise

 set     QSCI0_STAT_OR               BIT11
;;   Overrun Flag
;;     0b0 ==> No overrun
;;     0b1 ==> Overrun

 set     QSCI0_STAT_RIDLE            BIT12
;;   Receiver Idle Line Flag
;;     0b0 ==> Receiver input is either active now or has never become active since RIDLE was last cleared
;;     0b1 ==> Receiver input has become idle (after receiving a valid frame)

 set     QSCI0_STAT_RDRF             BIT13
;;   Receive Data Register Full Flag
;;     0b0 ==> RX FIFO word count is at or below watermark
;;     0b1 ==> RX FIFO word count is above watermark

 set     QSCI0_STAT_TIDLE            BIT14
;;   Transmitter Idle Flag
;;     0b0 ==> Transmission in progress
;;     0b1 ==> No transmission in progress

 set     QSCI0_STAT_TDRE             BIT15
;;   Transmit Data Register Empty Flag
;;     0b0 ==> TX FIFO word count is above watermark
;;     0b1 ==> TX FIFO word count is at or below watermark

 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8)
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_0 BIT0
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_1 BIT1
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_2 BIT2
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_3 BIT3
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_4 BIT4
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_5 BIT5
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_6 BIT6
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_7 BIT7
 set     QSCI0_DATA_RECEIVE_TRANSMIT_DATA_8 BIT8

 set     QSCI0_CTRL3_SHEN            BIT0
;;   Stop mode entry hold off
;;     0b0 ==> Stop mode hold off is disabled.
;;     0b1 ==> Stop mode holdoff is enabled.

 set     QSCI0_CTRL3_SBRH            (BIT13|BIT14|BIT15)
;;   High order bits of SCI Baud Rate divider, which combine with the RATE[SBRL] field to form a value from 1 to 65535
 set     QSCI0_CTRL3_SBRH_0          BIT13
 set     QSCI0_CTRL3_SBRH_1          BIT14
 set     QSCI0_CTRL3_SBRH_2          BIT15

 set     QSCI1_RATE_FRAC_SBR         (BIT0|BIT1|BIT2)
;;   Fractional SCI Baud Rate divider, a value from 0 to 7 that is divided by 8
 set     QSCI1_RATE_FRAC_SBR_0       BIT0
 set     QSCI1_RATE_FRAC_SBR_1       BIT1
 set     QSCI1_RATE_FRAC_SBR_2       BIT2

 set     QSCI1_RATE_SBRL             (BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Low order bits of SCI Baud Rate divider, which combine with the CTRL3[SBRH] field to form a value from 1 to 65535
 set     QSCI1_RATE_SBRL_0           BIT3
 set     QSCI1_RATE_SBRL_1           BIT4
 set     QSCI1_RATE_SBRL_2           BIT5
 set     QSCI1_RATE_SBRL_3           BIT6
 set     QSCI1_RATE_SBRL_4           BIT7
 set     QSCI1_RATE_SBRL_5           BIT8
 set     QSCI1_RATE_SBRL_6           BIT9
 set     QSCI1_RATE_SBRL_7           BIT10
 set     QSCI1_RATE_SBRL_8           BIT11
 set     QSCI1_RATE_SBRL_9           BIT12
 set     QSCI1_RATE_SBRL_10          BIT13
 set     QSCI1_RATE_SBRL_11          BIT14
 set     QSCI1_RATE_SBRL_12          BIT15

 set     QSCI1_CTRL1_SBK             BIT0
;;   Send Break
;;     0b0 ==> No break characters
;;     0b1 ==> Transmit break characters

 set     QSCI1_CTRL1_RWU             BIT1
;;   Receiver Wake-up
;;     0b0 ==> Normal operation
;;     0b1 ==> Standby state

 set     QSCI1_CTRL1_RE              BIT2
;;   Receiver Enable
;;     0b0 ==> Receiver disabled
;;     0b1 ==> Receiver enabled

 set     QSCI1_CTRL1_TE              BIT3
;;   Transmitter Enable
;;     0b0 ==> Transmitter disabled
;;     0b1 ==> Transmitter enabled

 set     QSCI1_CTRL1_REIE            BIT4
;;   Receive Error Interrupt Enable
;;     0b0 ==> Error interrupt requests disabled
;;     0b1 ==> Error interrupt requests enabled

 set     QSCI1_CTRL1_RFIE            BIT5
;;   Receiver Full Interrupt Enable
;;     0b0 ==> STAT[RDRF] and STAT[OR] interrupt requests disabled
;;     0b1 ==> STAT[RDRF] and STAT[OR] interrupt requests enabled

 set     QSCI1_CTRL1_TIIE            BIT6
;;   Transmitter Idle Interrupt Enable
;;     0b0 ==> STAT[TIDLE] interrupt requests disabled
;;     0b1 ==> STAT[TIDLE] interrupt requests enabled

 set     QSCI1_CTRL1_TEIE            BIT7
;;   Transmitter Empty Interrupt Enable
;;     0b0 ==> STAT[TDRE] interrupt requests disabled
;;     0b1 ==> STAT[TDRE] interrupt requests enabled

 set     QSCI1_CTRL1_PT              BIT8
;;   Parity Type
;;     0b0 ==> Even parity
;;     0b1 ==> Odd parity

 set     QSCI1_CTRL1_PE              BIT9
;;   Parity Enable
;;     0b0 ==> Parity function disabled
;;     0b1 ==> Parity function enabled

 set     QSCI1_CTRL1_POL             BIT10
;;   Polarity
;;     0b0 ==> Don't invert transmit and receive data bits (normal mode)
;;     0b1 ==> Invert transmit and receive data bits (inverted mode)

 set     QSCI1_CTRL1_WAKE            BIT11
;;   Wake-up Condition
;;     0b0 ==> Idle line wake-up
;;     0b1 ==> Address mark wake-up

 set     QSCI1_CTRL1_M               BIT12
;;   Data Format Mode
;;     0b0 ==> One start bit, eight data bits, one stop bit
;;     0b1 ==> One start bit, nine data bits, one stop bit

 set     QSCI1_CTRL1_RSRC            BIT13
;;   Receiver Source
;;     0b0 ==> Receiver input internally connected to transmitter output
;;     0b1 ==> Receiver input connected to TXD pin

 set     QSCI1_CTRL1_SWAI            BIT14
;;   Stop in Wait Mode
;;     0b0 ==> SCI enabled in wait mode
;;     0b1 ==> SCI disabled in wait mode

 set     QSCI1_CTRL1_LOOP            BIT15
;;   Loop Select
;;     0b0 ==> Normal operation, regardless of the value of RSRC
;;     0b1 ==> When RSRC = 0: Loop mode with internal TXD fed back to RXD
;;     0b1 ==> When RSRC = 1: Single-wire mode with TXD output fed back to RXD

 set     QSCI1_CTRL2_RDE             BIT0
;;   Receiver DMA Enable
;;     0b0 ==> Receive DMA disabled
;;     0b1 ==> Receive DMA enabled

 set     QSCI1_CTRL2_TDE             BIT1
;;   Transmitter DMA Enable
;;     0b0 ==> Transmit DMA disabled
;;     0b1 ==> Transmit DMA enabled

 set     QSCI1_CTRL2_LINMODE         BIT3
;;   Enable LIN Slave Mode
;;     0b0 ==> The LIN auto baud feature is disabled and the RATE register maintains whatever value the processor writes to it.
;;     0b1 ==> Enable LIN slave functionality. This includes a search for the break character followed by a sync character (0x55) from the master LIN device. When the break is detected (11 consecutive samples of zero), the subsequent sync character is used to measure the baud rate of the transmitting master, and the RATE register is automatically reloaded with the value needed to "match" that baud rate.

 set     QSCI1_CTRL2_RIEIE           BIT4
;;   Receiver Input Edge Interrupt Enable
;;     0b0 ==> Receiver input edge interrupt request disabled.
;;     0b1 ==> Receiver input edge interrupt request enabled.

 set     QSCI1_CTRL2_FIFO_EN         BIT5
;;   FIFO Enable
;;     0b0 ==> FIFOs are disabled.
;;     0b1 ==> FIFOs are enabled.

 set     QSCI1_CTRL2_RFWM            (BIT6|BIT7)
;;   Receive FIFO Full Water Mark
;;     0b00 ==> RDRF is set when at least 1 word is in the FIFO
;;     0b01 ==> RDRF is set when at least 2 words are in the FIFO
;;     0b10 ==> RDRF is set when at least 3 words are in the FIFO
;;     0b11 ==> RDRF is set when at least 4 words are in the FIFO
 set     QSCI1_CTRL2_RFWM_0          BIT6
 set     QSCI1_CTRL2_RFWM_1          BIT7

 set     QSCI1_CTRL2_RFCNT           (BIT8|BIT9|BIT10)
;;   Receive FIFO Count
;;     0b000 ==> 0 words in RX FIFO
;;     0b001 ==> 1 word in RX FIFO
;;     0b010 ==> 2 words in RX FIFO
;;     0b011 ==> 3 words in RX FIFO
;;     0b100 ==> 4 words in RX FIFO
;;     0b101 ==> Reserved
;;     0b110 ==> Reserved
;;     0b111 ==> Reserved
 set     QSCI1_CTRL2_RFCNT_0         BIT8
 set     QSCI1_CTRL2_RFCNT_1         BIT9
 set     QSCI1_CTRL2_RFCNT_2         BIT10

 set     QSCI1_CTRL2_TFWM            (BIT11|BIT12)
;;   Transmit FIFO Empty Water Mark
;;     0b00 ==> TDRE is set when 0 words are in the FIFO
;;     0b01 ==> TDRE is set when 1 or fewer words are in the FIFO
;;     0b10 ==> TDRE is set when 2 or fewer words are in the FIFO
;;     0b11 ==> TDRE is set when 3 or fewer words are in the FIFO
 set     QSCI1_CTRL2_TFWM_0          BIT11
 set     QSCI1_CTRL2_TFWM_1          BIT12

 set     QSCI1_CTRL2_TFCNT           (BIT13|BIT14|BIT15)
;;   Transmit FIFO Count
;;     0b000 ==> 0 words in Tx FIFO
;;     0b001 ==> 1 word in Tx FIFO
;;     0b010 ==> 2 words in Tx FIFO
;;     0b011 ==> 3 words in Tx FIFO
;;     0b100 ==> 4 words in Tx FIFO
;;     0b101 ==> Reserved
;;     0b110 ==> Reserved
;;     0b111 ==> Reserved
 set     QSCI1_CTRL2_TFCNT_0         BIT13
 set     QSCI1_CTRL2_TFCNT_1         BIT14
 set     QSCI1_CTRL2_TFCNT_2         BIT15

 set     QSCI1_STAT_RAF              BIT0
;;   Receiver Active Flag
;;     0b0 ==> No reception in progress
;;     0b1 ==> Reception in progress

 set     QSCI1_STAT_RDMA             BIT1
;;   Receive DMA Request
;;     0b0 ==> Either CTRL2[RDE] is cleared or CTRL2[RDE] is set and CTRL2[RFCNT] is 0.
;;     0b1 ==> CTRL2[RDE] is set and CTRL2[RFCNT] is currently above 0.

 set     QSCI1_STAT_TDMA             BIT2
;;   Transmit DMA Request
;;     0b0 ==> Either CTRL2[TDE] is cleared or CTRL2[TDE] is set and CTRL2[TFCNT] is at its maximum value.
;;     0b1 ==> CTRL2[TDE] is set and CTRL2[TFCNT] is currently below its maximum value.

 set     QSCI1_STAT_LSE              BIT3
;;   LIN Sync Error
;;     0b0 ==> No error occurred since CTRL2[LINMODE] was enabled or the bit was last cleared
;;     0b1 ==> A sync error prevented loading of the RATE register with a revised value after the break was detected.

 set     QSCI1_STAT_RIEF             BIT4
;;   Receiver Input Edge Flag
;;     0b0 ==> No active edge on the receive pin has occured.
;;     0b1 ==> An active edge on the receive pin has occured.

 set     QSCI1_STAT_PF               BIT8
;;   Parity Error Flag
;;     0b0 ==> No parity error
;;     0b1 ==> Parity error

 set     QSCI1_STAT_FE               BIT9
;;   Framing Error Flag
;;     0b0 ==> No framing error
;;     0b1 ==> Framing error

 set     QSCI1_STAT_NF               BIT10
;;   Noise Flag
;;     0b0 ==> No noise
;;     0b1 ==> Noise

 set     QSCI1_STAT_OR               BIT11
;;   Overrun Flag
;;     0b0 ==> No overrun
;;     0b1 ==> Overrun

 set     QSCI1_STAT_RIDLE            BIT12
;;   Receiver Idle Line Flag
;;     0b0 ==> Receiver input is either active now or has never become active since RIDLE was last cleared
;;     0b1 ==> Receiver input has become idle (after receiving a valid frame)

 set     QSCI1_STAT_RDRF             BIT13
;;   Receive Data Register Full Flag
;;     0b0 ==> RX FIFO word count is at or below watermark
;;     0b1 ==> RX FIFO word count is above watermark

 set     QSCI1_STAT_TIDLE            BIT14
;;   Transmitter Idle Flag
;;     0b0 ==> Transmission in progress
;;     0b1 ==> No transmission in progress

 set     QSCI1_STAT_TDRE             BIT15
;;   Transmit Data Register Empty Flag
;;     0b0 ==> TX FIFO word count is above watermark
;;     0b1 ==> TX FIFO word count is at or below watermark

 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8)
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_0 BIT0
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_1 BIT1
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_2 BIT2
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_3 BIT3
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_4 BIT4
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_5 BIT5
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_6 BIT6
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_7 BIT7
 set     QSCI1_DATA_RECEIVE_TRANSMIT_DATA_8 BIT8

 set     QSCI1_CTRL3_SHEN            BIT0
;;   Stop mode entry hold off
;;     0b0 ==> Stop mode hold off is disabled.
;;     0b1 ==> Stop mode holdoff is enabled.

 set     QSCI1_CTRL3_SBRH            (BIT13|BIT14|BIT15)
;;   High order bits of SCI Baud Rate divider, which combine with the RATE[SBRL] field to form a value from 1 to 65535
 set     QSCI1_CTRL3_SBRH_0          BIT13
 set     QSCI1_CTRL3_SBRH_1          BIT14
 set     QSCI1_CTRL3_SBRH_2          BIT15

 set     QSPI0_SPSCR_SPTE            BIT0
;;   SPI Transmitter Empty
;;     0b0 ==> Transmit data register or FIFO is not empty. (If using the FIFO, read TFCNT to determine how many words can be written safely.)
;;     0b1 ==> Transmit data register or FIFO is empty.

 set     QSPI0_SPSCR_MODF            BIT1
;;   Mode Fault
;;     0b0 ==> SS_B pin at appropriate logic level
;;     0b1 ==> SS_B pin at inappropriate logic level

 set     QSPI0_SPSCR_OVRF            BIT2
;;   Overflow
;;     0b0 ==> No overflow
;;     0b1 ==> Overflow

 set     QSPI0_SPSCR_SPRF            BIT3
;;   SPI Receiver Full
;;     0b0 ==> Receive data register or FIFO is not full. (If using the FIFO, read RFCNT to determine the number of valid words available.)
;;     0b1 ==> Receive data register or FIFO is full.

 set     QSPI0_SPSCR_SPTIE           BIT4
;;   Transmit Interrupt Enable
;;     0b0 ==> SPTE interrupt requests disabled
;;     0b1 ==> SPTE interrupt requests enabled

 set     QSPI0_SPSCR_SPE             BIT5
;;   SPI Enable
;;     0b0 ==> SPI module disabled
;;     0b1 ==> SPI module enabled

 set     QSPI0_SPSCR_CPHA            BIT6
;;   Clock Phase

 set     QSPI0_SPSCR_CPOL            BIT7
;;   Clock Polarity
;;     0b0 ==> Rising edge of SCLK starts transaction
;;     0b1 ==> Falling edge of SCLK starts transaction

 set     QSPI0_SPSCR_SPMSTR          BIT8
;;   SPI Master
;;     0b0 ==> Slave mode
;;     0b1 ==> Master mode

 set     QSPI0_SPSCR_SPRIE           BIT9
;;   SPI Receiver Interrupt Enable
;;     0b0 ==> SPRF interrupt requests disabled
;;     0b1 ==> SPRF interrupt requests enabled

 set     QSPI0_SPSCR_MODFEN          BIT10
;;   Mode Fault Enable

 set     QSPI0_SPSCR_ERRIE           BIT11
;;   Error Interrupt Enable
;;     0b0 ==> MODF and OVRF cannot generate device interrupt requests
;;     0b1 ==> MODF and OVRF can generate device interrupt requests

 set     QSPI0_SPSCR_DSO             BIT12
;;   Data Shift Order
;;     0b0 ==> MSB transmitted first (MSB -> LSB)
;;     0b1 ==> LSB transmitted first (LSB -> MSB)

 set     QSPI0_SPSCR_SPR             (BIT13|BIT14|BIT15)
;;   SPI Baud Rate Select
;;     0b000 ==> BD = 2 when SPR3 = 0, BD = 512 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b001 ==> BD = 4 when SPR3 = 0, BD = 1024 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b010 ==> BD = 8 when SPR3 = 0, BD = 2048 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b011 ==> BD = 16 when SPR3 = 0, BD = 4096 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b100 ==> BD = 32 when SPR3 = 0, BD = 8192 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b101 ==> BD = 64 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
;;     0b110 ==> BD = 128 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
;;     0b111 ==> BD = 256 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
 set     QSPI0_SPSCR_SPR_0           BIT13
 set     QSPI0_SPSCR_SPR_1           BIT14
 set     QSPI0_SPSCR_SPR_2           BIT15

 set     QSPI0_SPDSR_DS              (BIT0|BIT1|BIT2|BIT3)
;;   Transaction data size
 set     QSPI0_SPDSR_DS_0            BIT0
 set     QSPI0_SPDSR_DS_1            BIT1
 set     QSPI0_SPDSR_DS_2            BIT2
 set     QSPI0_SPDSR_DS_3            BIT3

 set     QSPI0_SPDSR_SPR3            BIT4
;;   SPI Baud Rate Select

 set     QSPI0_SPDSR_SSB_OVER        BIT5
;;   SS_B Override
;;     0b0 ==> SS_B internal module input is selected to be connected to a GPIO pin.
;;     0b1 ==> SS_B internal module input is selected to be equal to SPMSTR.

 set     QSPI0_SPDSR_SSB_STRB        BIT6
;;   SS_B Strobe Mode
;;     0b0 ==> No SS_B pulse between words.
;;     0b1 ==> SS_B output signal is pulsed high between words. This adds 1.5 baud clocks to the total word period. The idle state of SS_B is low unless SSB_AUTO is high and then the idle state is high. Do not use if MODFEN = 1.

 set     QSPI0_SPDSR_SSB_DDR         BIT7
;;   SS_B Data Direction
;;     0b0 ==> SS_B is configured as an input pin. Use this setting in slave mode or in master mode with MODFEN=1.
;;     0b1 ==> SS_B is configured as an output pin. Use this setting in master mode with MODFEN=0.

 set     QSPI0_SPDSR_SSB_AUTO        BIT8
;;   SS_B Automatic Mode
;;     0b0 ==> SS_B output signal is software generated by directly manipulating the various bits in this register or the GPIO registers (compatible with legacy SPI software).
;;     0b1 ==> SS_B output signal is hardware generated to create the initial falling edge and final rising edge. The idle state of the SS_B is high. Do not use if MODFEN = 1.

 set     QSPI0_SPDSR_SSB_ODM         BIT9
;;   SS_B Open Drain Mode
;;     0b0 ==> SS_B is configured for high and low drive. This mode is generally used in single master systems.
;;     0b1 ==> SS_B is configured as an open drain pin (only drives low output level). This mode is useful for multiple master systems.

 set     QSPI0_SPDSR_SSB_DATA        BIT10
;;   SS_B Data
;;     0b0 ==> SS_B pin is driven low if SSB_DDR=1
;;     0b1 ==> SS_B pin is driven high if SSB_DDR=1

 set     QSPI0_SPDSR_SSB_IN          BIT11
;;   SS_B Input

 set     QSPI0_SPDSR_BD2X            BIT12
;;   Baud Divisor Times

 set     QSPI0_SPDSR_RDMAEN          BIT13
;;   Receive DMA Enable

 set     QSPI0_SPDSR_TDMAEN          BIT14
;;   Transmit DMA Enable

 set     QSPI0_SPDSR_WOM             BIT15
;;   Wired-OR Mode
;;     0b0 ==> The SPI pins are configured as push-pull drivers.
;;     0b1 ==> The SPI pins are configured as open-drain drivers with the pull-ups disabled.

 set     QSPI0_SPDRR_R0              BIT0
;;   Receive Data Bit 0

 set     QSPI0_SPDRR_R1              BIT1
;;   Receive Data Bit 1

 set     QSPI0_SPDRR_R2              BIT2
;;   Receive Data Bit 2

 set     QSPI0_SPDRR_R3              BIT3
;;   Receive Data Bit 3

 set     QSPI0_SPDRR_R4              BIT4
;;   Receive Data Bit 4

 set     QSPI0_SPDRR_R5              BIT5
;;   Receive Data Bit 5

 set     QSPI0_SPDRR_R6              BIT6
;;   Receive Data Bit 6

 set     QSPI0_SPDRR_R7              BIT7
;;   Receive Data Bit 7

 set     QSPI0_SPDRR_R8              BIT8
;;   Receive Data Bit 8

 set     QSPI0_SPDRR_R9              BIT9
;;   Receive Data Bit 9

 set     QSPI0_SPDRR_R10             BIT10
;;   Receive Data Bit 10

 set     QSPI0_SPDRR_R11             BIT11
;;   Receive Data Bit 11

 set     QSPI0_SPDRR_R12             BIT12
;;   Receive Data Bit 12

 set     QSPI0_SPDRR_R13             BIT13
;;   Receive Data Bit 13

 set     QSPI0_SPDRR_R14             BIT14
;;   Receive Data Bit 14

 set     QSPI0_SPDRR_R15             BIT15
;;   Receive Data Bit 15

 set     QSPI0_SPDTR_T0              BIT0
;;   Transmit Data Bit 0

 set     QSPI0_SPDTR_T1              BIT1
;;   Transmit Data Bit 1

 set     QSPI0_SPDTR_T2              BIT2
;;   Transmit Data Bit 2

 set     QSPI0_SPDTR_T3              BIT3
;;   Transmit Data Bit 3

 set     QSPI0_SPDTR_T4              BIT4
;;   Transmit Data Bit 4

 set     QSPI0_SPDTR_T5              BIT5
;;   Transmit Data Bit 5

 set     QSPI0_SPDTR_T6              BIT6
;;   Transmit Data Bit 6

 set     QSPI0_SPDTR_T7              BIT7
;;   Transmit Data Bit 7

 set     QSPI0_SPDTR_T8              BIT8
;;   Transmit Data Bit 8

 set     QSPI0_SPDTR_T9              BIT9
;;   Transmit Data Bit 9

 set     QSPI0_SPDTR_T10             BIT10
;;   Transmit Data Bit 10

 set     QSPI0_SPDTR_T11             BIT11
;;   Transmit Data Bit 11

 set     QSPI0_SPDTR_T12             BIT12
;;   Transmit Data Bit 12

 set     QSPI0_SPDTR_T13             BIT13
;;   Transmit Data Bit 13

 set     QSPI0_SPDTR_T14             BIT14
;;   Transmit Data Bit 14

 set     QSPI0_SPDTR_T15             BIT15
;;   Transmit Data Bit 15

 set     QSPI0_SPFIFO_FIFO_ENA       BIT0
;;   FIFO Enable
;;     0b0 ==> FIFOs are disabled and reset.
;;     0b1 ==> FIFOs are enabled. FIFOs retain their status even if SPE is set to 0.

 set     QSPI0_SPFIFO_RFWM           (BIT2|BIT3)
;;   Rx FIFO Watermark
;;     0b00 ==> Receive interrupt active when Rx FIFO has at least one word used
;;     0b01 ==> Receive interrupt active when Rx FIFO has at least two words used
;;     0b10 ==> Receive interrupt active when Rx FIFO has at least three words used
;;     0b11 ==> Receive interrupt active when Rx FIFO is full
 set     QSPI0_SPFIFO_RFWM_0         BIT2
 set     QSPI0_SPFIFO_RFWM_1         BIT3

 set     QSPI0_SPFIFO_TFWM           (BIT5|BIT6)
;;   Tx FIFO Watermark
;;     0b00 ==> Transmit interrupt active when Tx FIFO is empty
;;     0b01 ==> Transmit interrupt active when Tx FIFO has one or fewer words available
;;     0b10 ==> Transmit interrupt active when Tx FIFO has two or fewer words available
;;     0b11 ==> Transmit interrupt active when Tx FIFO has three or fewer words available
 set     QSPI0_SPFIFO_TFWM_0         BIT5
 set     QSPI0_SPFIFO_TFWM_1         BIT6

 set     QSPI0_SPFIFO_RFCNT          (BIT8|BIT9|BIT10)
;;   RX FIFO Level
;;     0b000 ==> Rx FIFO empty
;;     0b001 ==> One word used in Rx FIFO
;;     0b010 ==> Two words used in Rx FIFO
;;     0b011 ==> Three words used in Rx FIFO
;;     0b100 ==> Rx FIFO full (if enabled Receiver Full Interrupt asserted)
 set     QSPI0_SPFIFO_RFCNT_0        BIT8
 set     QSPI0_SPFIFO_RFCNT_1        BIT9
 set     QSPI0_SPFIFO_RFCNT_2        BIT10

 set     QSPI0_SPFIFO_TFCNT          (BIT12|BIT13|BIT14)
;;   TX FIFO Level
;;     0b000 ==> Tx FIFO empty (if enabled Transmit Empty Interrupt asserted)
;;     0b001 ==> One word used in Tx FIFO
;;     0b010 ==> Two words used in Tx FIFO
;;     0b011 ==> Three words used in Tx FIFO
;;     0b100 ==> Tx FIFO full
 set     QSPI0_SPFIFO_TFCNT_0        BIT12
 set     QSPI0_SPFIFO_TFCNT_1        BIT13
 set     QSPI0_SPFIFO_TFCNT_2        BIT14

 set     QSPI0_SPWAIT_WAIT           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12)
;;   Wait Delay
 set     QSPI0_SPWAIT_WAIT_0         BIT0
 set     QSPI0_SPWAIT_WAIT_1         BIT1
 set     QSPI0_SPWAIT_WAIT_2         BIT2
 set     QSPI0_SPWAIT_WAIT_3         BIT3
 set     QSPI0_SPWAIT_WAIT_4         BIT4
 set     QSPI0_SPWAIT_WAIT_5         BIT5
 set     QSPI0_SPWAIT_WAIT_6         BIT6
 set     QSPI0_SPWAIT_WAIT_7         BIT7
 set     QSPI0_SPWAIT_WAIT_8         BIT8
 set     QSPI0_SPWAIT_WAIT_9         BIT9
 set     QSPI0_SPWAIT_WAIT_10        BIT10
 set     QSPI0_SPWAIT_WAIT_11        BIT11
 set     QSPI0_SPWAIT_WAIT_12        BIT12

 set     QSPI0_SPCTL2_SHEN           BIT0
;;   Stop Mode Holdoff Enable
;;     0b0 ==> Disable stop mode holdoff .
;;     0b1 ==> Enable stop mode holdoff while the SPI is transmitting/receiving.

 set     QSPI1_SPSCR_SPTE            BIT0
;;   SPI Transmitter Empty
;;     0b0 ==> Transmit data register or FIFO is not empty. (If using the FIFO, read TFCNT to determine how many words can be written safely.)
;;     0b1 ==> Transmit data register or FIFO is empty.

 set     QSPI1_SPSCR_MODF            BIT1
;;   Mode Fault
;;     0b0 ==> SS_B pin at appropriate logic level
;;     0b1 ==> SS_B pin at inappropriate logic level

 set     QSPI1_SPSCR_OVRF            BIT2
;;   Overflow
;;     0b0 ==> No overflow
;;     0b1 ==> Overflow

 set     QSPI1_SPSCR_SPRF            BIT3
;;   SPI Receiver Full
;;     0b0 ==> Receive data register or FIFO is not full. (If using the FIFO, read RFCNT to determine the number of valid words available.)
;;     0b1 ==> Receive data register or FIFO is full.

 set     QSPI1_SPSCR_SPTIE           BIT4
;;   Transmit Interrupt Enable
;;     0b0 ==> SPTE interrupt requests disabled
;;     0b1 ==> SPTE interrupt requests enabled

 set     QSPI1_SPSCR_SPE             BIT5
;;   SPI Enable
;;     0b0 ==> SPI module disabled
;;     0b1 ==> SPI module enabled

 set     QSPI1_SPSCR_CPHA            BIT6
;;   Clock Phase

 set     QSPI1_SPSCR_CPOL            BIT7
;;   Clock Polarity
;;     0b0 ==> Rising edge of SCLK starts transaction
;;     0b1 ==> Falling edge of SCLK starts transaction

 set     QSPI1_SPSCR_SPMSTR          BIT8
;;   SPI Master
;;     0b0 ==> Slave mode
;;     0b1 ==> Master mode

 set     QSPI1_SPSCR_SPRIE           BIT9
;;   SPI Receiver Interrupt Enable
;;     0b0 ==> SPRF interrupt requests disabled
;;     0b1 ==> SPRF interrupt requests enabled

 set     QSPI1_SPSCR_MODFEN          BIT10
;;   Mode Fault Enable

 set     QSPI1_SPSCR_ERRIE           BIT11
;;   Error Interrupt Enable
;;     0b0 ==> MODF and OVRF cannot generate device interrupt requests
;;     0b1 ==> MODF and OVRF can generate device interrupt requests

 set     QSPI1_SPSCR_DSO             BIT12
;;   Data Shift Order
;;     0b0 ==> MSB transmitted first (MSB -> LSB)
;;     0b1 ==> LSB transmitted first (LSB -> MSB)

 set     QSPI1_SPSCR_SPR             (BIT13|BIT14|BIT15)
;;   SPI Baud Rate Select
;;     0b000 ==> BD = 2 when SPR3 = 0, BD = 512 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b001 ==> BD = 4 when SPR3 = 0, BD = 1024 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b010 ==> BD = 8 when SPR3 = 0, BD = 2048 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b011 ==> BD = 16 when SPR3 = 0, BD = 4096 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b100 ==> BD = 32 when SPR3 = 0, BD = 8192 when SPR3 = 1 (double BD when BD2X = 1)
;;     0b101 ==> BD = 64 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
;;     0b110 ==> BD = 128 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
;;     0b111 ==> BD = 256 when SPR3 = 0 (double BD when BD2X = 1), BD = 16384 when SPR3 = 1 (regardless of BD2X)
 set     QSPI1_SPSCR_SPR_0           BIT13
 set     QSPI1_SPSCR_SPR_1           BIT14
 set     QSPI1_SPSCR_SPR_2           BIT15

 set     QSPI1_SPDSR_DS              (BIT0|BIT1|BIT2|BIT3)
;;   Transaction data size
 set     QSPI1_SPDSR_DS_0            BIT0
 set     QSPI1_SPDSR_DS_1            BIT1
 set     QSPI1_SPDSR_DS_2            BIT2
 set     QSPI1_SPDSR_DS_3            BIT3

 set     QSPI1_SPDSR_SPR3            BIT4
;;   SPI Baud Rate Select

 set     QSPI1_SPDSR_SSB_OVER        BIT5
;;   SS_B Override
;;     0b0 ==> SS_B internal module input is selected to be connected to a GPIO pin.
;;     0b1 ==> SS_B internal module input is selected to be equal to SPMSTR.

 set     QSPI1_SPDSR_SSB_STRB        BIT6
;;   SS_B Strobe Mode
;;     0b0 ==> No SS_B pulse between words.
;;     0b1 ==> SS_B output signal is pulsed high between words. This adds 1.5 baud clocks to the total word period. The idle state of SS_B is low unless SSB_AUTO is high and then the idle state is high. Do not use if MODFEN = 1.

 set     QSPI1_SPDSR_SSB_DDR         BIT7
;;   SS_B Data Direction
;;     0b0 ==> SS_B is configured as an input pin. Use this setting in slave mode or in master mode with MODFEN=1.
;;     0b1 ==> SS_B is configured as an output pin. Use this setting in master mode with MODFEN=0.

 set     QSPI1_SPDSR_SSB_AUTO        BIT8
;;   SS_B Automatic Mode
;;     0b0 ==> SS_B output signal is software generated by directly manipulating the various bits in this register or the GPIO registers (compatible with legacy SPI software).
;;     0b1 ==> SS_B output signal is hardware generated to create the initial falling edge and final rising edge. The idle state of the SS_B is high. Do not use if MODFEN = 1.

 set     QSPI1_SPDSR_SSB_ODM         BIT9
;;   SS_B Open Drain Mode
;;     0b0 ==> SS_B is configured for high and low drive. This mode is generally used in single master systems.
;;     0b1 ==> SS_B is configured as an open drain pin (only drives low output level). This mode is useful for multiple master systems.

 set     QSPI1_SPDSR_SSB_DATA        BIT10
;;   SS_B Data
;;     0b0 ==> SS_B pin is driven low if SSB_DDR=1
;;     0b1 ==> SS_B pin is driven high if SSB_DDR=1

 set     QSPI1_SPDSR_SSB_IN          BIT11
;;   SS_B Input

 set     QSPI1_SPDSR_BD2X            BIT12
;;   Baud Divisor Times

 set     QSPI1_SPDSR_RDMAEN          BIT13
;;   Receive DMA Enable

 set     QSPI1_SPDSR_TDMAEN          BIT14
;;   Transmit DMA Enable

 set     QSPI1_SPDSR_WOM             BIT15
;;   Wired-OR Mode
;;     0b0 ==> The SPI pins are configured as push-pull drivers.
;;     0b1 ==> The SPI pins are configured as open-drain drivers with the pull-ups disabled.

 set     QSPI1_SPDRR_R0              BIT0
;;   Receive Data Bit 0

 set     QSPI1_SPDRR_R1              BIT1
;;   Receive Data Bit 1

 set     QSPI1_SPDRR_R2              BIT2
;;   Receive Data Bit 2

 set     QSPI1_SPDRR_R3              BIT3
;;   Receive Data Bit 3

 set     QSPI1_SPDRR_R4              BIT4
;;   Receive Data Bit 4

 set     QSPI1_SPDRR_R5              BIT5
;;   Receive Data Bit 5

 set     QSPI1_SPDRR_R6              BIT6
;;   Receive Data Bit 6

 set     QSPI1_SPDRR_R7              BIT7
;;   Receive Data Bit 7

 set     QSPI1_SPDRR_R8              BIT8
;;   Receive Data Bit 8

 set     QSPI1_SPDRR_R9              BIT9
;;   Receive Data Bit 9

 set     QSPI1_SPDRR_R10             BIT10
;;   Receive Data Bit 10

 set     QSPI1_SPDRR_R11             BIT11
;;   Receive Data Bit 11

 set     QSPI1_SPDRR_R12             BIT12
;;   Receive Data Bit 12

 set     QSPI1_SPDRR_R13             BIT13
;;   Receive Data Bit 13

 set     QSPI1_SPDRR_R14             BIT14
;;   Receive Data Bit 14

 set     QSPI1_SPDRR_R15             BIT15
;;   Receive Data Bit 15

 set     QSPI1_SPDTR_T0              BIT0
;;   Transmit Data Bit 0

 set     QSPI1_SPDTR_T1              BIT1
;;   Transmit Data Bit 1

 set     QSPI1_SPDTR_T2              BIT2
;;   Transmit Data Bit 2

 set     QSPI1_SPDTR_T3              BIT3
;;   Transmit Data Bit 3

 set     QSPI1_SPDTR_T4              BIT4
;;   Transmit Data Bit 4

 set     QSPI1_SPDTR_T5              BIT5
;;   Transmit Data Bit 5

 set     QSPI1_SPDTR_T6              BIT6
;;   Transmit Data Bit 6

 set     QSPI1_SPDTR_T7              BIT7
;;   Transmit Data Bit 7

 set     QSPI1_SPDTR_T8              BIT8
;;   Transmit Data Bit 8

 set     QSPI1_SPDTR_T9              BIT9
;;   Transmit Data Bit 9

 set     QSPI1_SPDTR_T10             BIT10
;;   Transmit Data Bit 10

 set     QSPI1_SPDTR_T11             BIT11
;;   Transmit Data Bit 11

 set     QSPI1_SPDTR_T12             BIT12
;;   Transmit Data Bit 12

 set     QSPI1_SPDTR_T13             BIT13
;;   Transmit Data Bit 13

 set     QSPI1_SPDTR_T14             BIT14
;;   Transmit Data Bit 14

 set     QSPI1_SPDTR_T15             BIT15
;;   Transmit Data Bit 15

 set     QSPI1_SPFIFO_FIFO_ENA       BIT0
;;   FIFO Enable
;;     0b0 ==> FIFOs are disabled and reset.
;;     0b1 ==> FIFOs are enabled. FIFOs retain their status even if SPE is set to 0.

 set     QSPI1_SPFIFO_RFWM           (BIT2|BIT3)
;;   Rx FIFO Watermark
;;     0b00 ==> Receive interrupt active when Rx FIFO has at least one word used
;;     0b01 ==> Receive interrupt active when Rx FIFO has at least two words used
;;     0b10 ==> Receive interrupt active when Rx FIFO has at least three words used
;;     0b11 ==> Receive interrupt active when Rx FIFO is full
 set     QSPI1_SPFIFO_RFWM_0         BIT2
 set     QSPI1_SPFIFO_RFWM_1         BIT3

 set     QSPI1_SPFIFO_TFWM           (BIT5|BIT6)
;;   Tx FIFO Watermark
;;     0b00 ==> Transmit interrupt active when Tx FIFO is empty
;;     0b01 ==> Transmit interrupt active when Tx FIFO has one or fewer words available
;;     0b10 ==> Transmit interrupt active when Tx FIFO has two or fewer words available
;;     0b11 ==> Transmit interrupt active when Tx FIFO has three or fewer words available
 set     QSPI1_SPFIFO_TFWM_0         BIT5
 set     QSPI1_SPFIFO_TFWM_1         BIT6

 set     QSPI1_SPFIFO_RFCNT          (BIT8|BIT9|BIT10)
;;   RX FIFO Level
;;     0b000 ==> Rx FIFO empty
;;     0b001 ==> One word used in Rx FIFO
;;     0b010 ==> Two words used in Rx FIFO
;;     0b011 ==> Three words used in Rx FIFO
;;     0b100 ==> Rx FIFO full (if enabled Receiver Full Interrupt asserted)
 set     QSPI1_SPFIFO_RFCNT_0        BIT8
 set     QSPI1_SPFIFO_RFCNT_1        BIT9
 set     QSPI1_SPFIFO_RFCNT_2        BIT10

 set     QSPI1_SPFIFO_TFCNT          (BIT12|BIT13|BIT14)
;;   TX FIFO Level
;;     0b000 ==> Tx FIFO empty (if enabled Transmit Empty Interrupt asserted)
;;     0b001 ==> One word used in Tx FIFO
;;     0b010 ==> Two words used in Tx FIFO
;;     0b011 ==> Three words used in Tx FIFO
;;     0b100 ==> Tx FIFO full
 set     QSPI1_SPFIFO_TFCNT_0        BIT12
 set     QSPI1_SPFIFO_TFCNT_1        BIT13
 set     QSPI1_SPFIFO_TFCNT_2        BIT14

 set     QSPI1_SPWAIT_WAIT           (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12)
;;   Wait Delay
 set     QSPI1_SPWAIT_WAIT_0         BIT0
 set     QSPI1_SPWAIT_WAIT_1         BIT1
 set     QSPI1_SPWAIT_WAIT_2         BIT2
 set     QSPI1_SPWAIT_WAIT_3         BIT3
 set     QSPI1_SPWAIT_WAIT_4         BIT4
 set     QSPI1_SPWAIT_WAIT_5         BIT5
 set     QSPI1_SPWAIT_WAIT_6         BIT6
 set     QSPI1_SPWAIT_WAIT_7         BIT7
 set     QSPI1_SPWAIT_WAIT_8         BIT8
 set     QSPI1_SPWAIT_WAIT_9         BIT9
 set     QSPI1_SPWAIT_WAIT_10        BIT10
 set     QSPI1_SPWAIT_WAIT_11        BIT11
 set     QSPI1_SPWAIT_WAIT_12        BIT12

 set     QSPI1_SPCTL2_SHEN           BIT0
;;   Stop Mode Holdoff Enable
;;     0b0 ==> Disable stop mode holdoff .
;;     0b1 ==> Enable stop mode holdoff while the SPI is transmitting/receiving.

 set     SIM_CTRL_WAIT_disable       (BIT0|BIT1)
;;   WAIT Disable
;;     0b00 ==> Wait mode is entered when the DSC core executes a WAIT instruction.
;;     0b01 ==> The DSC core WAIT instruction does not cause entry into wait mode.
;;     0b10 ==> Wait mode is entered when the DSC core executes a WAIT instruction, and the WAIT_disable field is write protected until the next reset.
;;     0b11 ==> The DSC core WAIT instruction does not cause entry into wait mode, and the WAIT_disable field is write protected until the next reset.
 set     SIM_CTRL_WAIT_disable_0     BIT0
 set     SIM_CTRL_WAIT_disable_1     BIT1

 set     SIM_CTRL_STOP_disable       (BIT2|BIT3)
;;   STOP Disable
;;     0b00 ==> Stop mode is entered when the DSC core executes a STOP instruction.
;;     0b01 ==> The DSC core STOP instruction does not cause entry into stop mode.
;;     0b10 ==> Stop mode is entered when the DSC core executes a STOP instruction, and the STOP_disable field is write protected until the next reset.
;;     0b11 ==> The DSC core STOP instruction does not cause entry into stop mode, and the STOP_disable field is write protected until the next reset.
 set     SIM_CTRL_STOP_disable_0     BIT2
 set     SIM_CTRL_STOP_disable_1     BIT3

 set     SIM_CTRL_SWRst              BIT4
;;   SOFTWARE RESET

 set     SIM_CTRL_OnceEbl            BIT5
;;   OnCE Enable
;;     0b0 ==> The OnCE clock to the DSC core is enabled when the core TAP is enabled.
;;     0b1 ==> The OnCE clock to the DSC core is always enabled.

 set     SIM_CTRL_DMAEbl             (BIT6|BIT7|BIT8)
;;   DMA Enable
;;     0b000 ==> DMA module is disabled.
;;     0b001 ==> DMA module is enabled in run mode only.
;;     0b010 ==> DMA module is enabled in run and wait modes only.
;;     0b011 ==> DMA module is enabled in all power modes.
;;     0b100 ==> DMA module is disabled and the DMAEbl field is write protected until the next reset.
;;     0b101 ==> DMA module is enabled in run mode only and the DMAEbl field is write protected until the next reset.
;;     0b110 ==> DMA module is enabled in run and wait modes only and the DMAEbl field is write protected until the next reset.
;;     0b111 ==> DMA module is enabled in all low power modes and the DMAEbl field is write protected until the next reset.
 set     SIM_CTRL_DMAEbl_0           BIT6
 set     SIM_CTRL_DMAEbl_1           BIT7
 set     SIM_CTRL_DMAEbl_2           BIT8

 set     SIM_CTRL_RST_FILT           BIT10
;;   External Reset Padcell Input Filter Enable
;;     0b0 ==> Input filter on external reset disabled
;;     0b1 ==> Input filter on external reset enabled

 set     SIM_RSTAT_POR               BIT2
;;   Power-on Reset

 set     SIM_RSTAT_EXTR              BIT3
;;   External Reset

 set     SIM_RSTAT_COP_LOR           BIT4
;;   COP Loss of Reference Reset

 set     SIM_RSTAT_COP_CPU           BIT5
;;   COP CPU Time-out Reset

 set     SIM_RSTAT_COP_WNDOW         BIT6
;;   COP Window Time-out Reset

 set     SIM_RSTAT_SWR               BIT7
;;   Software Reset Request

 set     SIM_PWR_LRSTDBY             (BIT0|BIT1)
;;   Large Regulator Standby Control
;;     0b00 ==> Large regulator placed in normal mode (default).
;;     0b01 ==> Large regulator placed in standby mode.
;;     0b10 ==> Large regulator placed in normal mode and LRSTDBY is write protected until device reset.
;;     0b11 ==> Large regulator placed in standby mode and LRSTDBY is write protected until device reset.
 set     SIM_PWR_LRSTDBY_0           BIT0
 set     SIM_PWR_LRSTDBY_1           BIT1

 set     SIM_PWR_SR27STDBY           (BIT2|BIT3)
;;   Small Regulator 2.7V Supply Standby Control
;;     0b00 ==> Small regulator 2.7V supply placed in normal mode (default).
;;     0b01 ==> Small regulator 2.7V supply placed in standby mode.
;;     0b10 ==> Small regulator 2.7V supply placed in normal mode and SR27STDBY is write protected until chip reset.
;;     0b11 ==> Small regulator 2.7V supply placed in standby mode and SR27STDBY is write protected until chip reset.
 set     SIM_PWR_SR27STDBY_0         BIT2
 set     SIM_PWR_SR27STDBY_1         BIT3

 set     SIM_PWR_SR27PDN             (BIT4|BIT5)
;;   Small Regulator 2.7V Supply Powerdown Control
;;     0b00 ==> Small regulator placed in normal mode (default).
;;     0b01 ==> Small regulator placed in powerdown mode.
;;     0b10 ==> Small regulator placed in normal mode and SR27PDN is write protected until chip reset.
;;     0b11 ==> Small regulator placed in powerdown mode and SR27PDN is write protected until chip reset.
 set     SIM_PWR_SR27PDN_0           BIT4
 set     SIM_PWR_SR27PDN_1           BIT5

 set     SIM_PWR_SR12STDBY           (BIT6|BIT7)
;;   Small Regulator 1.2V Supply Standby Control
;;     0b00 ==> Small regulator 1.2V supply placed in normal mode (default).
;;     0b01 ==> Small regulator 1.2V supply placed in standby mode.
;;     0b10 ==> Small regulator 1.2V supply placed in normal mode and SR12STDBY is write protected until chip reset.
;;     0b11 ==> Small regulator 1.2V supply placed in standby mode and SR12STDBY is write protected until chip reset.
 set     SIM_PWR_SR12STDBY_0         BIT6
 set     SIM_PWR_SR12STDBY_1         BIT7

 set     SIM_CLKOUT_CLKOSEL0         (BIT0|BIT1|BIT2)
;;   CLKOUT0 Select
;;     0b000 ==> Function = SYS_CLK continuous after reset
;;     0b001 ==> Function = MSTR_2X continuous after reset
;;     0b010 ==> Function = DIV2_BUS_CLK continuous after reset
;;     0b011 ==> Function = MSTR_OSC (master clock) continuous after reset
;;     0b100 ==> Function = ROSC_8M (8 MHz / 400 kHz relaxation oscillator clock )
;;     0b101 ==> Function = ROSC_200K (200 kHz relaxation oscillator clock )
;;     0b110 ==> Reserved. For normal operation, do not write 11x.
;;     0b111 ==> Reserved. For normal operation, do not write 11x.
 set     SIM_CLKOUT_CLKOSEL0_0       BIT0
 set     SIM_CLKOUT_CLKOSEL0_1       BIT1
 set     SIM_CLKOUT_CLKOSEL0_2       BIT2

 set     SIM_CLKOUT_CLKDIS0          BIT5
;;   Disable for CLKOUT0
;;     0b0 ==> CLKOUT0 output is enabled and outputs the signal indicated by CLKOSEL0
;;     0b1 ==> CLKOUT0 is disabled

 set     SIM_CLKOUT_CLKOSEL1         (BIT7|BIT8|BIT9)
;;   CLKOUT1 Select
;;     0b000 ==> Function = SYS_CLK continuous after reset
;;     0b001 ==> Function = MSTR_2X continuous after reset
;;     0b010 ==> Function = DIV2_BUS_CLK continuous after reset
;;     0b011 ==> Function = MSTR_OSC (master clock) continuous after reset
;;     0b100 ==> Function = ROSC_8M (8 MHz / 400 kHz relaxation oscillator clock )
;;     0b101 ==> Function = ROSC_200K (200 kHz relaxation oscillator clock )
;;     0b110 ==> Reserved. For normal operation, do not write 11x.
;;     0b111 ==> Reserved. For normal operation, do not write 11x.
 set     SIM_CLKOUT_CLKOSEL1_0       BIT7
 set     SIM_CLKOUT_CLKOSEL1_1       BIT8
 set     SIM_CLKOUT_CLKOSEL1_2       BIT9

 set     SIM_CLKOUT_CLKDIS1          BIT12
;;   Disable for CLKOUT1
;;     0b0 ==> CLKOUT1 output is enabled and outputs the signal indicated by CLKOSEL1
;;     0b1 ==> CLKOUT1 is disabled

 set     SIM_CLKOUT_CLKODIV          (BIT13|BIT14|BIT15)
;;   CLKOUT divide factor
;;     0b000 ==> Divide by 1
;;     0b001 ==> Divide by 2
;;     0b010 ==> Divide by 4
;;     0b011 ==> Divide by 8
;;     0b100 ==> Divide by 16
;;     0b101 ==> Divide by 32
;;     0b110 ==> Divide by 64
;;     0b111 ==> Divide by 128
 set     SIM_CLKOUT_CLKODIV_0        BIT13
 set     SIM_CLKOUT_CLKODIV_1        BIT14
 set     SIM_CLKOUT_CLKODIV_2        BIT15

 set     SIM_PCR_IIC_FILT            BIT9
;;   IIC_FILT Clock Rate
;;     0b0 ==> IIC FILTER clock rate equals bus clock rate (default).
;;     0b1 ==> IIC FILTER clock rate equals 2X bus clock rate that is, 100MHz

 set     SIM_PCR_PWM                 BIT10
;;   PWM Clock Rate
;;     0b0 ==> PWM clock rate equals bus clock rate (default).
;;     0b1 ==> PWM clock rate equals 2X bus clock rat,ie 100MHz

 set     SIM_PCR_TMR                 BIT11
;;   TMR Clock Rate
;;     0b0 ==> TMR clock rate equals bus clock rate (default).
;;     0b1 ==> TMR clock rate equals 2X bus clock rate that is, 100MHz.

 set     SIM_PCR_SCI1_CR             BIT12
;;   SCI1 Clock Rate
;;     0b0 ==> SCI1 clock rate equals bus clock rate (default)
;;     0b1 ==> SCI1 clock rate equals 2X bus clock rate that is, 100 MHz

 set     SIM_PCR_SCI0_CR             BIT13
;;   SCI0 Clock Rate
;;     0b0 ==> SCI0 clock rate equals bus clock rate (default)
;;     0b1 ==> SCI0 clock rate equals 2X bus clock rate that is, 100MHz

 set     SIM_PCE0_GPIOF              BIT1
;;   GPIOF IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_GPIOE              BIT2
;;   GPIOE IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_GPIOD              BIT3
;;   GPIOD IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_GPIOC              BIT4
;;   GPIOC IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_GPIOB              BIT5
;;   GPIOB IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_GPIOA              BIT6
;;   GPIOA IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_TA3                BIT12
;;   TMRA3 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_TA2                BIT13
;;   TMRA2 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_TA1                BIT14
;;   TMRA1 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE0_TA0                BIT15
;;   TMRA0 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE1_MSCAN              BIT0
;;   MSCAN IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE1_IIC0               BIT6
;;   IIC0 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE1_QSPI1              BIT8
;;   QSPI1 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE1_QSPI0              BIT9
;;   QSPI0 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE1_SCI1               BIT11
;;   SCI1 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE1_SCI0               BIT12
;;   SCI0 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE1_DACA               BIT13
;;   12bit DACA IPBus Clock Enable
;;     0b0 ==> 12bit DACA is not clocked.
;;     0b1 ==> 12bit DACA is clocked.

 set     SIM_PCE1_DACB               BIT14
;;   12bit DACB IPBus Clock Enable
;;     0b0 ==> 12bit DACB is not clocked.
;;     0b1 ==> 12bit DACB is clocked.

 set     SIM_PCE2_PIT1               BIT2
;;   Programmable Interval Timer IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE2_PIT0               BIT3
;;   Programmable Interval Timer IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE2_CRC                BIT5
;;   CRC IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE2_CYCADC             BIT7
;;   Cyclic ADC IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE2_CMPD               BIT9
;;   CMPD IPBus Clock Enable (enables both CMP and 6-bit reference DAC)
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE2_CMPC               BIT10
;;   CMPC IPBus Clock Enable (enables both CMP and 6-bit reference DAC)
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE2_CMPB               BIT11
;;   CMPB IPBus Clock Enable (enables both CMP and 6-bit reference DAC)
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE2_CMPA               BIT12
;;   CMPA IPBus Clock Enable (enables both CMP and 6-bit reference DAC)
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE3_PWMACH3            BIT4
;;   PWMA Channel 3 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE3_PWMACH2            BIT5
;;   PWMA Channel 2 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE3_PWMACH1            BIT6
;;   PWMA Channel 1 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_PCE3_PWMACH0            BIT7
;;   PWMA Channel 0 IPBus Clock Enable
;;     0b0 ==> The peripheral is not clocked.
;;     0b1 ==> The peripheral is clocked.

 set     SIM_SD0_GPIOF               BIT1
;;   GPIOF IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_GPIOE               BIT2
;;   GPIOE IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_GPIOD               BIT3
;;   GPIOD IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_GPIOC               BIT4
;;   GPIOC IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_GPIOB               BIT5
;;   GPIOB IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_GPIOA               BIT6
;;   GPIOA IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_TA3                 BIT12
;;   TMRA3 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_TA2                 BIT13
;;   TMRA2 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_TA1                 BIT14
;;   TMRA1 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD0_TA0                 BIT15
;;   TMRA0 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD1_MSCAN               BIT0
;;   MSCAN IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD1_IIC0                BIT6
;;   IIC0 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode, but the IIC0 module will not enter stop mode.

 set     SIM_SD1_QSPI1               BIT8
;;   QSPI1 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD1_QSPI0               BIT9
;;   QSPI0 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD1_SCI1                BIT11
;;   SCI1 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD1_SCI0                BIT12
;;   SCI0 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD1_DACA                BIT13
;;   DACA IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD1_DACB                BIT14
;;   DACB IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD2_PIT1                BIT2
;;   Programmable Interval Timer IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD2_PIT0                BIT3
;;   Programmable Interval Timer IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD2_CRC                 BIT5
;;   CRC IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD2_CYCADC              BIT7
;;   Cyclic ADC IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD2_CMPD                BIT9
;;   CMPD IPBus STOP Disable (disables both CMP and 6-bit reference DAC)
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD2_CMPC                BIT10
;;   CMPC IPBus STOP Disable (disables both CMP and 6-bit reference DAC)
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD2_CMPB                BIT11
;;   CMPB IPBus STOP Disable (disables both CMP and 6-bit reference DAC)
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD2_CMPA                BIT12
;;   CMPA IPBus STOP Disable (disables both CMP and 6-bit reference DAC)
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD3_PWMACH3             BIT4
;;   PWMA Channel 3 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD3_PWMACH2             BIT5
;;   PWMA Channel 2 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD3_PWMACH1             BIT6
;;   PWMA Channel 1 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_SD3_PWMACH0             BIT7
;;   PWMA Channel 0 IPBus STOP Disable
;;     0b0 ==> The peripheral is not clocked in stop mode.
;;     0b1 ==> The peripheral is clocked in stop mode.

 set     SIM_IOSAHI_ISAL             (BIT0|BIT1)
;;   Bits 23:22 of the address
 set     SIM_IOSAHI_ISAL_0           BIT0
 set     SIM_IOSAHI_ISAL_1           BIT1

 set     SIM_IOSALO_ISAL             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Bits 21:6 of the address
 set     SIM_IOSALO_ISAL_0           BIT0
 set     SIM_IOSALO_ISAL_1           BIT1
 set     SIM_IOSALO_ISAL_2           BIT2
 set     SIM_IOSALO_ISAL_3           BIT3
 set     SIM_IOSALO_ISAL_4           BIT4
 set     SIM_IOSALO_ISAL_5           BIT5
 set     SIM_IOSALO_ISAL_6           BIT6
 set     SIM_IOSALO_ISAL_7           BIT7
 set     SIM_IOSALO_ISAL_8           BIT8
 set     SIM_IOSALO_ISAL_9           BIT9
 set     SIM_IOSALO_ISAL_10          BIT10
 set     SIM_IOSALO_ISAL_11          BIT11
 set     SIM_IOSALO_ISAL_12          BIT12
 set     SIM_IOSALO_ISAL_13          BIT13
 set     SIM_IOSALO_ISAL_14          BIT14
 set     SIM_IOSALO_ISAL_15          BIT15

 set     SIM_PROT_GIPSP              (BIT0|BIT1)
;;   GPIO and Internal Peripheral Select Protection
;;     0b00 ==> Write protection off (default).
;;     0b01 ==> Write protection on.
;;     0b10 ==> Write protection off and locked until chip reset.
;;     0b11 ==> Write protection on and locked until chip reset.
 set     SIM_PROT_GIPSP_0            BIT0
 set     SIM_PROT_GIPSP_1            BIT1

 set     SIM_PROT_PCEP               (BIT2|BIT3)
;;   Peripheral Clock Enable Protection
;;     0b00 ==> Write protection off (default).
;;     0b01 ==> Write protection on.
;;     0b10 ==> Write protection off and locked until chip reset.
;;     0b11 ==> Write protection on and locked until chip reset.
 set     SIM_PROT_PCEP_0             BIT2
 set     SIM_PROT_PCEP_1             BIT3

 set     SIM_PROT_GDP                (BIT4|BIT5)
;;   GPIO Port D Protection
;;     0b00 ==> Write protection off (default).
;;     0b01 ==> Write protection on.
;;     0b10 ==> Write protection off and locked until chip reset.
;;     0b11 ==> Write protection on and locked until chip reset.
 set     SIM_PROT_GDP_0              BIT4
 set     SIM_PROT_GDP_1              BIT5

 set     SIM_PROT_PMODE              (BIT6|BIT7)
;;   Power Mode Control Write Protection
;;     0b00 ==> Write protection off (default).
;;     0b01 ==> Write protection on.
;;     0b10 ==> Write protection off and locked until chip reset.
;;     0b11 ==> Write protection on and locked until chip reset.
 set     SIM_PROT_PMODE_0            BIT6
 set     SIM_PROT_PMODE_1            BIT7

 set     SIM_GPSAL_A0                BIT0
;;   Configure GPIO A0
;;     0b0 ==> Function = ANA0/CMPA3; Peripheral = ADC/CMPA; Direction = AN_IN
;;     0b1 ==> Function = CMPC_O; Peripheral = CMPC; Direction = OUT

 set     SIM_GPSBL_B1                BIT2
;;     0b0 ==> Function = ANB1/CMPB_IN0; Peripheral = ADC/CMPB; Direction = AN_IN
;;     0b1 ==> Function = DACB; Peripheral = DAC; Direction = OUT

 set     SIM_GPSCL_C0                BIT0
;;   Configure GPIO C0
;;     0b0 ==> Function = EXTAL; Peripheral = OSC; Direction = AN_IN
;;     0b1 ==> Function = CLKIN; Peripheral = OCCS; Direction = IN

 set     SIM_GPSCL_C2                (BIT4|BIT5)
;;   Configure GPIO C2
;;     0b00 ==> Function = TXD0; Peripheral = SCI0; Direction = IO
;;     0b01 ==> Function = XBOUT_11; Peripheral = XBARA; Direction = OUT
;;     0b10 ==> Function = XB_IN2; Peripheral = XBAR; Direction = IN
;;     0b11 ==> Function = CLKOUT0; Peripheral = SIM; Direction = OUT
 set     SIM_GPSCL_C2_0              BIT4
 set     SIM_GPSCL_C2_1              BIT5

 set     SIM_GPSCL_C3                (BIT6|BIT7)
;;     0b00 ==> Function = TA0; Peripheral = TMRA; Direction = IO
;;     0b01 ==> Function = CMPA_O; Peripheral = CMPA; Direction = OUT
;;     0b10 ==> Function = RXD0; Peripheral = SCI0; Direction = IN
;;     0b11 ==> Function = CLKIN1; Peripheral = SIM; Direction = IN
 set     SIM_GPSCL_C3_0              BIT6
 set     SIM_GPSCL_C3_1              BIT7

 set     SIM_GPSCL_C4                (BIT8|BIT9)
;;   Configure GPIO C4
;;     0b00 ==> Function = TA1; Peripheral = TMRA; Direction = IO
;;     0b01 ==> Function = CMPB_O; Peripheral = CMPB; Direction = OUT
;;     0b10 ==> Function = XB_IN6; Peripheral = XBAR; Direction = IN
;;     0b11 ==> Function = EWM_OUT_B; Peripheral = EWM; Direction = OUT
 set     SIM_GPSCL_C4_0              BIT8
 set     SIM_GPSCL_C4_1              BIT9

 set     SIM_GPSCL_C5                BIT10
;;   Configure GPIO C5
;;     0b0 ==> Function = DACA; Peripheral = DAC; Direction = AN_OUT
;;     0b1 ==> Function = XB_IN7; Peripheral = XBAR; Direction = IN

 set     SIM_GPSCL_C6                (BIT12|BIT13)
;;   Configure GPIO C6
;;     0b00 ==> Function = TA2; Peripheral = TMRA; Direction = IO
;;     0b01 ==> Function = XB_IN3; Peripheral = XBAR; Direction = IN
;;     0b10 ==> Function = CMPREF; Peripheral = HSCMP A/B/C /D ; Direction = AN_IN
;;     0b11 ==> Function: SS0_B; Periphal: SPI0; Direction: IO
 set     SIM_GPSCL_C6_0              BIT12
 set     SIM_GPSCL_C6_1              BIT13

 set     SIM_GPSCL_C7                (BIT14|BIT15)
;;   Configure GPIO C7
;;     0b00 ==> Function = SS0_B; Peripheral = SPI0; Direction = IO
;;     0b01 ==> Function = TXD0; Peripheral = SCI0; Direction = IO
;;     0b10 ==> Function = XBIN_8; Peripheral = XBARA; Direction = IO
;;     0b11 ==> Reserved
 set     SIM_GPSCL_C7_0              BIT14
 set     SIM_GPSCL_C7_1              BIT15

 set     SIM_GPSCH_C8                (BIT0|BIT1)
;;   Configure GPIO C8
;;     0b00 ==> Function = MISO0; Peripheral = SPI0; Direction = IO
;;     0b01 ==> Function = RXD0; Peripheral = SCI0; Direction = IN
;;     0b10 ==> Function = XB_IN9; Peripheral = XBAR; Direction = IN
;;     0b11 ==> Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
 set     SIM_GPSCH_C8_0              BIT0
 set     SIM_GPSCH_C8_1              BIT1

 set     SIM_GPSCH_C9                (BIT2|BIT3)
;;   Configure GPIO C9
;;     0b00 ==> Function = SCLK0; Peripheral = SPI0; Direction = IO
;;     0b01 ==> Function = XB_IN4; Peripheral = XBAR; Direction = IN
;;     0b10 ==> Function = TXD0; Peripheral = SCI0; Direction = IO
;;     0b11 ==> Function = XB_OUT8; Peripheral = XBAR; Direction = IN
 set     SIM_GPSCH_C9_0              BIT2
 set     SIM_GPSCH_C9_1              BIT3

 set     SIM_GPSCH_C10               (BIT4|BIT5)
;;   Configure GPIO C10
;;     0b00 ==> Function = MOSI0; Peripheral = SPI0; Direction = IO
;;     0b01 ==> Function = XB_IN5; Peripheral = XBAR; Direction = IN
;;     0b10 ==> Function = MISO0; Peripheral = SPI0; Direction = IO
;;     0b11 ==> Function = XB_OUT9; Peripheral = XBAR; Direction = IN
 set     SIM_GPSCH_C10_0             BIT4
 set     SIM_GPSCH_C10_1             BIT5

 set     SIM_GPSCH_C11               (BIT6|BIT7)
;;   Configure GPIO C11
;;     0b00 ==> Function = CANTX; Peripheral = MSCAN; Direction = OD_OUT
;;     0b01 ==> Function = SCL0; Peripheral = IIC0; Direction = OD_IO
;;     0b10 ==> Function = TXD1; Peripheral = SCI1; Direction = IO
;;     0b11 ==> Reserved
 set     SIM_GPSCH_C11_0             BIT6
 set     SIM_GPSCH_C11_1             BIT7

 set     SIM_GPSCH_C12               (BIT8|BIT9)
;;   Configure GPIO C12
;;     0b00 ==> Function = CANRX; Peripheral = MSCAN; Direction = IN
;;     0b01 ==> Function = SDA0; Peripheral = IIC0; Direction = OD_IO
;;     0b10 ==> Function = RXD1; Peripheral = SCI1; Direction = IN
;;     0b11 ==> Reserved
 set     SIM_GPSCH_C12_0             BIT8
 set     SIM_GPSCH_C12_1             BIT9

 set     SIM_GPSCH_C13               (BIT10|BIT11)
;;   Configure GPIO C13
;;     0b00 ==> Function = TA3; Peripheral = TMRA; Direction = IO
;;     0b01 ==> Function = XB_IN6; Peripheral = XBAR; Direction = IN
;;     0b10 ==> Function = EWM_OUT_B; Peripheral = EWM; Direction = OUT
;;     0b11 ==> Reserved
 set     SIM_GPSCH_C13_0             BIT10
 set     SIM_GPSCH_C13_1             BIT11

 set     SIM_GPSCH_C14               (BIT12|BIT13)
;;   Configure GPIO C14
;;     0b00 ==> Function = SDA0; Peripheral = IIC0; Direction = OD_IO
;;     0b01 ==> Function = XB_OUT4; Peripheral = XBAR; Direction = OUT
;;     0b10 ==> Function = PWM_FAULT4; Peripheral = PWM; Direction = OD_IO
;;     0b11 ==> Reserved
 set     SIM_GPSCH_C14_0             BIT12
 set     SIM_GPSCH_C14_1             BIT13

 set     SIM_GPSCH_C15               (BIT14|BIT15)
;;   Configure GPIO C15
;;     0b00 ==> Function = SCL0; Peripheral = IIC0; Direction = OD_IO
;;     0b01 ==> Function = XB_OUT5; Peripheral = XBAR; Direction = OUT
;;     0b10 ==> Function = SCL0; Peripheral = IIC0; Direction = OD_IO
;;     0b11 ==> Reserved
 set     SIM_GPSCH_C15_0             BIT14
 set     SIM_GPSCH_C15_1             BIT15

 set     SIM_GPSEL_E4                BIT8
;;   Configure GPIO E4
;;     0b0 ==> Function = PWMA_2B; Peripheral = PWMA; Direction = IO
;;     0b1 ==> Function = XB_IN2; Peripheral = XBAR; Direction = IN

 set     SIM_GPSEL_E5                BIT10
;;   Configure GPIO E5
;;     0b0 ==> Function = PWMA_2A; Peripheral = PWMA; Direction = IO
;;     0b1 ==> Function = XB_IN3; Peripheral = XBAR; Direction = IN

 set     SIM_GPSEL_E6                BIT12
;;   Configure GPIO E6
;;     0b0 ==> Function = PWMA_3B; Peripheral = PWMA; Direction = IO
;;     0b1 ==> Function = XB_IN4; Peripheral = XBAR; Direction = IN

 set     SIM_GPSEL_E7                BIT14
;;   Configure GPIO E7
;;     0b0 ==> Function = PWMA_3A; Peripheral = PWMA; Direction = IO
;;     0b1 ==> Function = XB_IN5; Peripheral = XBAR; Direction = IN

 set     SIM_GPSFL_F0                (BIT0|BIT1)
;;   Configure GPIO F0
;;     0b00 ==> Function = XB_IN6; Peripheral = XBAR; Direction = IN
;;     0b01 ==> Reserved
;;     0b10 ==> Function = SCLK1; Peripheral = SPI1; Direction = IO
;;     0b11 ==> Reserved
 set     SIM_GPSFL_F0_0              BIT0
 set     SIM_GPSFL_F0_1              BIT1

 set     SIM_GPSFL_F1                (BIT2|BIT3)
;;   Configure GPIO F1
;;     0b00 ==> Function = CLKOUT1; Peripheral = SIM; Direction = OUT
;;     0b01 ==> Function = XB_IN7; Peripheral = XBAR; Direction = IN
;;     0b10 ==> Function = CMPD_O; Peripheral = HSCMPD; Direction = OUT
;;     0b11 ==> Reserved
 set     SIM_GPSFL_F1_0              BIT2
 set     SIM_GPSFL_F1_1              BIT3

 set     SIM_GPSFL_F2                (BIT4|BIT5)
;;   Configure GPIO F2
;;     0b00 ==> Function = SCL0; Peripheral = IIC0; Direction = OD_IO
;;     0b01 ==> Function = XB_OUT6; Peripheral = XBAR; Direction = OUT
;;     0b10 ==> Function = MISO1; Peripheral = SPI1; Direction = IO
;;     0b11 ==> Reserved
 set     SIM_GPSFL_F2_0              BIT4
 set     SIM_GPSFL_F2_1              BIT5

 set     SIM_GPSFL_F3                (BIT6|BIT7)
;;   Configure GPIO F3
;;     0b00 ==> Function = SDA0; Peripheral = IIC0; Direction = OD_IO
;;     0b01 ==> Function = XB_OUT7; Peripheral = XBAR; Direction = OUT
;;     0b10 ==> Function = MOSI1; Peripheral = SPI1; Direction = IO
;;     0b11 ==> Reserved
 set     SIM_GPSFL_F3_0              BIT6
 set     SIM_GPSFL_F3_1              BIT7

 set     SIM_GPSFL_F4                (BIT8|BIT9)
;;   Configure GPIO F4
;;     0b00 ==> Function = TXD1; Peripheral = SCI1; Direction = IO
;;     0b01 ==> Function = XB_OUT8; Peripheral = XBAR; Direction = OUT
;;     0b10 ==> Function = PWMA_0X; Peripheral = PWMA; Direction = IO
;;     0b11 ==> Function = PWMA_FAULT6; Peripheral = PWMA; Direction = OUT
 set     SIM_GPSFL_F4_0              BIT8
 set     SIM_GPSFL_F4_1              BIT9

 set     SIM_GPSFL_F5                (BIT10|BIT11)
;;   Configure GPIO F5
;;     0b00 ==> Function = RXD1; Peripheral = SCI1; Direction = IN
;;     0b01 ==> Function = XB_OUT9; Peripheral = XBAR; Direction = OUT
;;     0b10 ==> Function = PWMA_1x; Peripheral = PWMA; Direction = IN
;;     0b11 ==> Function = PWMA_FAULT7; Peripheral = PWMA; Direction = OUT
 set     SIM_GPSFL_F5_0              BIT10
 set     SIM_GPSFL_F5_1              BIT11

 set     SIM_GPSFL_F6                (BIT12|BIT13)
;;   Configure GPIO F6
;;     0b00 ==> Reserved
;;     0b01 ==> Function = PWMA_3X; Peripheral = PWMA; Direction = IO
;;     0b10 ==> Reserved
;;     0b11 ==> Function = XB_IN2; Peripheral = XBAR; Direction = IN
 set     SIM_GPSFL_F6_0              BIT12
 set     SIM_GPSFL_F6_1              BIT13

 set     SIM_GPSFL_F7                (BIT14|BIT15)
;;   Configure GPIO F7
;;     0b00 ==> Reserved
;;     0b01 ==> Function = CMPC_O; Peripheral = HSCMPC; Direction = OUT
;;     0b10 ==> Function = SS1_B; Peripheral = SPI1; Direction = IO
;;     0b11 ==> Function = XB_IN3; Peripheral = XBAR; Direction = IN
 set     SIM_GPSFL_F7_0              BIT14
 set     SIM_GPSFL_F7_1              BIT15

 set     SIM_GPSFH_F8                (BIT0|BIT1)
;;   Configure GPIO F8
;;     0b00 ==> Function = RXD0; Peripheral = SCI0; Direction = IN
;;     0b01 ==> Function =XB_OUT10; Peripheral = XBARA; Direction = IO
;;     0b10 ==> Function = CMPD_O; Peripheral = HSCMPD; Direction = OUT
;;     0b11 ==> Function = PWMA_2x; Peripheral = PWMA; Direction = IO
 set     SIM_GPSFH_F8_0              BIT0
 set     SIM_GPSFH_F8_1              BIT1

 set     SIM_IPSn_SCI0               BIT0
;;   Select SCI0_RXD source
;;     0b0 ==> Function = GPIOC3 or GPIOC8 or GPIOF8; Peripheral = GPIO; Direction = IN
;;     0b1 ==> Function = XB_OUT38; Peripheral = XBAR; Direction = IN

 set     SIM_IPSn_SCI1               BIT1
;;   Select SCI1_RXD Input
;;     0b0 ==> Function = GPIOC12 or GPIOF5; Peripheral = GPIO; Direction = IN
;;     0b1 ==> Function = XB_OUT39; Peripheral = XBARA; Direction = IN

 set     SIM_IPSn_TA0                BIT8
;;   Select TMRA0 Input
;;     0b0 ==> Function = GPIOC3; Peripheral = GPIOC; Direction = IN
;;     0b1 ==> Function = XB_OUT34; Peripheral = XBAR; Direction = IN

 set     SIM_IPSn_TA1                BIT9
;;   Select TMRA1 Input
;;     0b0 ==> Function = GPIOC4; Peripheral = GPIOC; Direction = IN
;;     0b1 ==> Function = XB_OUT35; Peripheral = XBAR; Direction = IN

 set     SIM_IPSn_TA2                BIT10
;;   Select TMRA2 Input
;;     0b0 ==> Function = GPIOC6; Peripheral = GPIOC; Direction = IN
;;     0b1 ==> Function = XB_OUT36; Peripheral = XBAR; Direction = IN

 set     SIM_IPSn_TA3                BIT11
;;   Select TMRA3 Input
;;     0b0 ==> Function = GPIOC13; Peripheral = GPIOC; Direction = IN
;;     0b1 ==> Function = XB_OUT37; Peripheral = XBAR; Direction = IN

 set     SIM_MISC0_PIT_MSTR          BIT0
;;   Select Master Programmable Interval Timer (PIT)
;;     0b0 ==> PIT0 is master PIT and PIT1 is slave PIT
;;     0b1 ==> PIT1 is master PIT and PIT0 is slave PIT

 set     SIM_MISC0_CLKINSEL          BIT1
;;   CLKIN Select
;;     0b0 ==> CLKIN0 (GPIOC0 alt1) is selected as CLKIN
;;     0b1 ==> CLKIN1 (GPIOC3 alt3) is selected as CLKIN

 set     SIM_MISC0_FAST_MODE         BIT2
;;     0b0 ==> Normal operating mode
;;     0b1 ==> Device boots in fast mode (core:bus :: 2:1) after software reset.

 set     SIM_MISC0_ADC_SCTRL         BIT3
;;     0b0 ==> Normal order
;;     0b1 ==> Enable the re-ordering of ADC scan control bits

 set     SIM_MISC0_MODE_STAT         BIT8
;;     0b0 ==> Device in normal operating mode with core. Bus frequency is 1:1
;;     0b1 ==> Device in fast mode

 set     SIM_PSWR0_GPIO              BIT6
;;   GPIO Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR0_TA                BIT15
;;   TMRA Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR1_MSCAN             BIT0
;;   MSCAN Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR1_IIC0              BIT6
;;   IIC0 Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR1_QSPI1             BIT8
;;   QSPI1 Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR1_QSPI0             BIT9
;;   QSPI0 Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR1_SCI1              BIT11
;;   SCI1 Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR1_SCI0              BIT12
;;   SCI0 Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR1_DACA              BIT13
;;   DACA Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR1_DACB              BIT14
;;   DACB Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR2_PIT1              BIT2
;;   Programmable Interval Timer Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR2_PIT0              BIT3
;;   Programmable Interval Timer Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR2_CRC               BIT5
;;   CRC Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR2_CYCADC            BIT7
;;   Cyclic ADC Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR2_CMP               BIT12
;;   CMP Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR2_EWM               BIT15
;;   EWM Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PSWR3_PWMA              BIT7
;;   PWMA Software Reset
;;     0b0 ==> The corresponding peripheral is not reset.
;;     0b1 ==> The corresponding peripheral is reset.

 set     SIM_PWRMODE_VLPMODE         BIT0
;;   VLPMODE Entry/Exit
;;     0b0 ==> Start exit from VLPMODE
;;     0b1 ==> Start entry to VLPMODE

 set     SIM_PWRMODE_LPMODE          BIT1
;;   LPMODE Entry/Exit
;;     0b0 ==> Start exit from LPMODE
;;     0b1 ==> Start entry to LPMODE

 set     SIM_PWRMODE_VLPMS           BIT8
;;   VLPMODE Status Indicator
;;     0b0 ==> Not in VLPMODE
;;     0b1 ==> In VLPMODE

 set     SIM_PWRMODE_LPMS            BIT9
;;   LPMODE Status Indicator
;;     0b0 ==> Not in LPMODE
;;     0b1 ==> In LPMODE

 set     SIM_NVMOPT2H_ROSC_8M_FTRIM  (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9)
;;   8 MHz Relaxation Oscillator Frequency Trim
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_0 BIT0
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_1 BIT1
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_2 BIT2
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_3 BIT3
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_4 BIT4
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_5 BIT5
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_6 BIT6
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_7 BIT7
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_8 BIT8
 set     SIM_NVMOPT2H_ROSC_8M_FTRIM_9 BIT9

 set     SIM_NVMOPT2H_ROSC_8M_TTRIM  (BIT10|BIT11|BIT12|BIT13)
;;   8 MHz Relaxation Oscillator Temperature Trim
 set     SIM_NVMOPT2H_ROSC_8M_TTRIM_0 BIT10
 set     SIM_NVMOPT2H_ROSC_8M_TTRIM_1 BIT11
 set     SIM_NVMOPT2H_ROSC_8M_TTRIM_2 BIT12
 set     SIM_NVMOPT2H_ROSC_8M_TTRIM_3 BIT13

 set     SIM_NVMOPT2L_ROSC_200K_FTRIM (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8)
;;   200 kHz Relaxation Oscillator Frequency Trim
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_0 BIT0
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_1 BIT1
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_2 BIT2
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_3 BIT3
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_4 BIT4
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_5 BIT5
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_6 BIT6
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_7 BIT7
 set     SIM_NVMOPT2L_ROSC_200K_FTRIM_8 BIT8

 set     SIM_NVMOPT2L_PMC_BGTRIM     (BIT12|BIT13|BIT14|BIT15)
;;   PMC Bandgap Trim
 set     SIM_NVMOPT2L_PMC_BGTRIM_0   BIT12
 set     SIM_NVMOPT2L_PMC_BGTRIM_1   BIT13
 set     SIM_NVMOPT2L_PMC_BGTRIM_2   BIT14
 set     SIM_NVMOPT2L_PMC_BGTRIM_3   BIT15

 set     SIM_SCR0_SCR0               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Software Control Data
 set     SIM_SCR0_SCR0_0             BIT0
 set     SIM_SCR0_SCR0_1             BIT1
 set     SIM_SCR0_SCR0_2             BIT2
 set     SIM_SCR0_SCR0_3             BIT3
 set     SIM_SCR0_SCR0_4             BIT4
 set     SIM_SCR0_SCR0_5             BIT5
 set     SIM_SCR0_SCR0_6             BIT6
 set     SIM_SCR0_SCR0_7             BIT7
 set     SIM_SCR0_SCR0_8             BIT8
 set     SIM_SCR0_SCR0_9             BIT9
 set     SIM_SCR0_SCR0_10            BIT10
 set     SIM_SCR0_SCR0_11            BIT11
 set     SIM_SCR0_SCR0_12            BIT12
 set     SIM_SCR0_SCR0_13            BIT13
 set     SIM_SCR0_SCR0_14            BIT14
 set     SIM_SCR0_SCR0_15            BIT15

 set     SIM_SCR1_SCR1               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Software Control Data
 set     SIM_SCR1_SCR1_0             BIT0
 set     SIM_SCR1_SCR1_1             BIT1
 set     SIM_SCR1_SCR1_2             BIT2
 set     SIM_SCR1_SCR1_3             BIT3
 set     SIM_SCR1_SCR1_4             BIT4
 set     SIM_SCR1_SCR1_5             BIT5
 set     SIM_SCR1_SCR1_6             BIT6
 set     SIM_SCR1_SCR1_7             BIT7
 set     SIM_SCR1_SCR1_8             BIT8
 set     SIM_SCR1_SCR1_9             BIT9
 set     SIM_SCR1_SCR1_10            BIT10
 set     SIM_SCR1_SCR1_11            BIT11
 set     SIM_SCR1_SCR1_12            BIT12
 set     SIM_SCR1_SCR1_13            BIT13
 set     SIM_SCR1_SCR1_14            BIT14
 set     SIM_SCR1_SCR1_15            BIT15

 set     SIM_SCR2_SCR2               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Software Control Data
 set     SIM_SCR2_SCR2_0             BIT0
 set     SIM_SCR2_SCR2_1             BIT1
 set     SIM_SCR2_SCR2_2             BIT2
 set     SIM_SCR2_SCR2_3             BIT3
 set     SIM_SCR2_SCR2_4             BIT4
 set     SIM_SCR2_SCR2_5             BIT5
 set     SIM_SCR2_SCR2_6             BIT6
 set     SIM_SCR2_SCR2_7             BIT7
 set     SIM_SCR2_SCR2_8             BIT8
 set     SIM_SCR2_SCR2_9             BIT9
 set     SIM_SCR2_SCR2_10            BIT10
 set     SIM_SCR2_SCR2_11            BIT11
 set     SIM_SCR2_SCR2_12            BIT12
 set     SIM_SCR2_SCR2_13            BIT13
 set     SIM_SCR2_SCR2_14            BIT14
 set     SIM_SCR2_SCR2_15            BIT15

 set     SIM_SCR3_SCR3               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Software Control Data
 set     SIM_SCR3_SCR3_0             BIT0
 set     SIM_SCR3_SCR3_1             BIT1
 set     SIM_SCR3_SCR3_2             BIT2
 set     SIM_SCR3_SCR3_3             BIT3
 set     SIM_SCR3_SCR3_4             BIT4
 set     SIM_SCR3_SCR3_5             BIT5
 set     SIM_SCR3_SCR3_6             BIT6
 set     SIM_SCR3_SCR3_7             BIT7
 set     SIM_SCR3_SCR3_8             BIT8
 set     SIM_SCR3_SCR3_9             BIT9
 set     SIM_SCR3_SCR3_10            BIT10
 set     SIM_SCR3_SCR3_11            BIT11
 set     SIM_SCR3_SCR3_12            BIT12
 set     SIM_SCR3_SCR3_13            BIT13
 set     SIM_SCR3_SCR3_14            BIT14
 set     SIM_SCR3_SCR3_15            BIT15

 set     SIM_SCR4_SCR4               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Software Control Data
 set     SIM_SCR4_SCR4_0             BIT0
 set     SIM_SCR4_SCR4_1             BIT1
 set     SIM_SCR4_SCR4_2             BIT2
 set     SIM_SCR4_SCR4_3             BIT3
 set     SIM_SCR4_SCR4_4             BIT4
 set     SIM_SCR4_SCR4_5             BIT5
 set     SIM_SCR4_SCR4_6             BIT6
 set     SIM_SCR4_SCR4_7             BIT7
 set     SIM_SCR4_SCR4_8             BIT8
 set     SIM_SCR4_SCR4_9             BIT9
 set     SIM_SCR4_SCR4_10            BIT10
 set     SIM_SCR4_SCR4_11            BIT11
 set     SIM_SCR4_SCR4_12            BIT12
 set     SIM_SCR4_SCR4_13            BIT13
 set     SIM_SCR4_SCR4_14            BIT14
 set     SIM_SCR4_SCR4_15            BIT15

 set     SIM_SCR5_SCR5               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Software Control Data
 set     SIM_SCR5_SCR5_0             BIT0
 set     SIM_SCR5_SCR5_1             BIT1
 set     SIM_SCR5_SCR5_2             BIT2
 set     SIM_SCR5_SCR5_3             BIT3
 set     SIM_SCR5_SCR5_4             BIT4
 set     SIM_SCR5_SCR5_5             BIT5
 set     SIM_SCR5_SCR5_6             BIT6
 set     SIM_SCR5_SCR5_7             BIT7
 set     SIM_SCR5_SCR5_8             BIT8
 set     SIM_SCR5_SCR5_9             BIT9
 set     SIM_SCR5_SCR5_10            BIT10
 set     SIM_SCR5_SCR5_11            BIT11
 set     SIM_SCR5_SCR5_12            BIT12
 set     SIM_SCR5_SCR5_13            BIT13
 set     SIM_SCR5_SCR5_14            BIT14
 set     SIM_SCR5_SCR5_15            BIT15

 set     SIM_SCR6_SCR6               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Software Control Data
 set     SIM_SCR6_SCR6_0             BIT0
 set     SIM_SCR6_SCR6_1             BIT1
 set     SIM_SCR6_SCR6_2             BIT2
 set     SIM_SCR6_SCR6_3             BIT3
 set     SIM_SCR6_SCR6_4             BIT4
 set     SIM_SCR6_SCR6_5             BIT5
 set     SIM_SCR6_SCR6_6             BIT6
 set     SIM_SCR6_SCR6_7             BIT7
 set     SIM_SCR6_SCR6_8             BIT8
 set     SIM_SCR6_SCR6_9             BIT9
 set     SIM_SCR6_SCR6_10            BIT10
 set     SIM_SCR6_SCR6_11            BIT11
 set     SIM_SCR6_SCR6_12            BIT12
 set     SIM_SCR6_SCR6_13            BIT13
 set     SIM_SCR6_SCR6_14            BIT14
 set     SIM_SCR6_SCR6_15            BIT15

 set     SIM_SCR7_SCR7               (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Software Control Data
 set     SIM_SCR7_SCR7_0             BIT0
 set     SIM_SCR7_SCR7_1             BIT1
 set     SIM_SCR7_SCR7_2             BIT2
 set     SIM_SCR7_SCR7_3             BIT3
 set     SIM_SCR7_SCR7_4             BIT4
 set     SIM_SCR7_SCR7_5             BIT5
 set     SIM_SCR7_SCR7_6             BIT6
 set     SIM_SCR7_SCR7_7             BIT7
 set     SIM_SCR7_SCR7_8             BIT8
 set     SIM_SCR7_SCR7_9             BIT9
 set     SIM_SCR7_SCR7_10            BIT10
 set     SIM_SCR7_SCR7_11            BIT11
 set     SIM_SCR7_SCR7_12            BIT12
 set     SIM_SCR7_SCR7_13            BIT13
 set     SIM_SCR7_SCR7_14            BIT14
 set     SIM_SCR7_SCR7_15            BIT15

 set     TMR_0_COMP1_COMPARISON_1    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Comparison Value 1
 set     TMR_0_COMP1_COMPARISON_1_0  BIT0
 set     TMR_0_COMP1_COMPARISON_1_1  BIT1
 set     TMR_0_COMP1_COMPARISON_1_2  BIT2
 set     TMR_0_COMP1_COMPARISON_1_3  BIT3
 set     TMR_0_COMP1_COMPARISON_1_4  BIT4
 set     TMR_0_COMP1_COMPARISON_1_5  BIT5
 set     TMR_0_COMP1_COMPARISON_1_6  BIT6
 set     TMR_0_COMP1_COMPARISON_1_7  BIT7
 set     TMR_0_COMP1_COMPARISON_1_8  BIT8
 set     TMR_0_COMP1_COMPARISON_1_9  BIT9
 set     TMR_0_COMP1_COMPARISON_1_10 BIT10
 set     TMR_0_COMP1_COMPARISON_1_11 BIT11
 set     TMR_0_COMP1_COMPARISON_1_12 BIT12
 set     TMR_0_COMP1_COMPARISON_1_13 BIT13
 set     TMR_0_COMP1_COMPARISON_1_14 BIT14
 set     TMR_0_COMP1_COMPARISON_1_15 BIT15

 set     TMR_0_COMP2_COMPARISON_2    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Comparison Value 2
 set     TMR_0_COMP2_COMPARISON_2_0  BIT0
 set     TMR_0_COMP2_COMPARISON_2_1  BIT1
 set     TMR_0_COMP2_COMPARISON_2_2  BIT2
 set     TMR_0_COMP2_COMPARISON_2_3  BIT3
 set     TMR_0_COMP2_COMPARISON_2_4  BIT4
 set     TMR_0_COMP2_COMPARISON_2_5  BIT5
 set     TMR_0_COMP2_COMPARISON_2_6  BIT6
 set     TMR_0_COMP2_COMPARISON_2_7  BIT7
 set     TMR_0_COMP2_COMPARISON_2_8  BIT8
 set     TMR_0_COMP2_COMPARISON_2_9  BIT9
 set     TMR_0_COMP2_COMPARISON_2_10 BIT10
 set     TMR_0_COMP2_COMPARISON_2_11 BIT11
 set     TMR_0_COMP2_COMPARISON_2_12 BIT12
 set     TMR_0_COMP2_COMPARISON_2_13 BIT13
 set     TMR_0_COMP2_COMPARISON_2_14 BIT14
 set     TMR_0_COMP2_COMPARISON_2_15 BIT15

 set     TMR_0_CAPT_CAPTURE          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Capture Value
 set     TMR_0_CAPT_CAPTURE_0        BIT0
 set     TMR_0_CAPT_CAPTURE_1        BIT1
 set     TMR_0_CAPT_CAPTURE_2        BIT2
 set     TMR_0_CAPT_CAPTURE_3        BIT3
 set     TMR_0_CAPT_CAPTURE_4        BIT4
 set     TMR_0_CAPT_CAPTURE_5        BIT5
 set     TMR_0_CAPT_CAPTURE_6        BIT6
 set     TMR_0_CAPT_CAPTURE_7        BIT7
 set     TMR_0_CAPT_CAPTURE_8        BIT8
 set     TMR_0_CAPT_CAPTURE_9        BIT9
 set     TMR_0_CAPT_CAPTURE_10       BIT10
 set     TMR_0_CAPT_CAPTURE_11       BIT11
 set     TMR_0_CAPT_CAPTURE_12       BIT12
 set     TMR_0_CAPT_CAPTURE_13       BIT13
 set     TMR_0_CAPT_CAPTURE_14       BIT14
 set     TMR_0_CAPT_CAPTURE_15       BIT15

 set     TMR_0_LOAD_LOAD             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Timer Load Register
 set     TMR_0_LOAD_LOAD_0           BIT0
 set     TMR_0_LOAD_LOAD_1           BIT1
 set     TMR_0_LOAD_LOAD_2           BIT2
 set     TMR_0_LOAD_LOAD_3           BIT3
 set     TMR_0_LOAD_LOAD_4           BIT4
 set     TMR_0_LOAD_LOAD_5           BIT5
 set     TMR_0_LOAD_LOAD_6           BIT6
 set     TMR_0_LOAD_LOAD_7           BIT7
 set     TMR_0_LOAD_LOAD_8           BIT8
 set     TMR_0_LOAD_LOAD_9           BIT9
 set     TMR_0_LOAD_LOAD_10          BIT10
 set     TMR_0_LOAD_LOAD_11          BIT11
 set     TMR_0_LOAD_LOAD_12          BIT12
 set     TMR_0_LOAD_LOAD_13          BIT13
 set     TMR_0_LOAD_LOAD_14          BIT14
 set     TMR_0_LOAD_LOAD_15          BIT15

 set     TMR_0_HOLD_HOLD             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_0_HOLD_HOLD_0           BIT0
 set     TMR_0_HOLD_HOLD_1           BIT1
 set     TMR_0_HOLD_HOLD_2           BIT2
 set     TMR_0_HOLD_HOLD_3           BIT3
 set     TMR_0_HOLD_HOLD_4           BIT4
 set     TMR_0_HOLD_HOLD_5           BIT5
 set     TMR_0_HOLD_HOLD_6           BIT6
 set     TMR_0_HOLD_HOLD_7           BIT7
 set     TMR_0_HOLD_HOLD_8           BIT8
 set     TMR_0_HOLD_HOLD_9           BIT9
 set     TMR_0_HOLD_HOLD_10          BIT10
 set     TMR_0_HOLD_HOLD_11          BIT11
 set     TMR_0_HOLD_HOLD_12          BIT12
 set     TMR_0_HOLD_HOLD_13          BIT13
 set     TMR_0_HOLD_HOLD_14          BIT14
 set     TMR_0_HOLD_HOLD_15          BIT15

 set     TMR_0_CNTR_COUNTER          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_0_CNTR_COUNTER_0        BIT0
 set     TMR_0_CNTR_COUNTER_1        BIT1
 set     TMR_0_CNTR_COUNTER_2        BIT2
 set     TMR_0_CNTR_COUNTER_3        BIT3
 set     TMR_0_CNTR_COUNTER_4        BIT4
 set     TMR_0_CNTR_COUNTER_5        BIT5
 set     TMR_0_CNTR_COUNTER_6        BIT6
 set     TMR_0_CNTR_COUNTER_7        BIT7
 set     TMR_0_CNTR_COUNTER_8        BIT8
 set     TMR_0_CNTR_COUNTER_9        BIT9
 set     TMR_0_CNTR_COUNTER_10       BIT10
 set     TMR_0_CNTR_COUNTER_11       BIT11
 set     TMR_0_CNTR_COUNTER_12       BIT12
 set     TMR_0_CNTR_COUNTER_13       BIT13
 set     TMR_0_CNTR_COUNTER_14       BIT14
 set     TMR_0_CNTR_COUNTER_15       BIT15

 set     TMR_0_CTRL_OUTMODE          (BIT0|BIT1|BIT2)
;;   Output Mode
;;     0b000 ==> Asserted while counter is active
;;     0b001 ==> Clear OFLAG output on successful compare
;;     0b010 ==> Set OFLAG output on successful compare
;;     0b011 ==> Toggle OFLAG output on successful compare
;;     0b100 ==> Toggle OFLAG output using alternating compare registers
;;     0b101 ==> Set on compare, cleared on secondary source input edge
;;     0b110 ==> Set on compare, cleared on counter rollover
;;     0b111 ==> Enable gated clock output while counter is active
 set     TMR_0_CTRL_OUTMODE_0        BIT0
 set     TMR_0_CTRL_OUTMODE_1        BIT1
 set     TMR_0_CTRL_OUTMODE_2        BIT2

 set     TMR_0_CTRL_COINIT           BIT3
;;   Co-Channel Initialization
;;     0b0 ==> Co-channel counter/timers cannot force a re-initialization of this counter/timer
;;     0b1 ==> Co-channel counter/timers may force a re-initialization of this counter/timer

 set     TMR_0_CTRL_DIR              BIT4
;;   Count Direction
;;     0b0 ==> Count up.
;;     0b1 ==> Count down.

 set     TMR_0_CTRL_LENGTH           BIT5
;;   Count Length
;;     0b0 ==> Roll over.
;;     0b1 ==> Count until compare, then re-initialize. If counting up, a successful compare occurs when the counter reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When output mode $4 is used, alternating values of COMP1 and COMP2 are used to generate successful comparisons. For example, the counter counts until a COMP1 value is reached, re-initializes, counts until COMP2 value is reached, re-initializes, counts until COMP1 value
;;             is reached, and so on.

 set     TMR_0_CTRL_ONCE             BIT6
;;   Count Once
;;     0b0 ==> Count repeatedly.
;;     0b1 ==> Count until compare and then stop. If counting up, a successful compare occurs when the counter reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When output mode $4 is used, the counter re-initializes after reaching the COMP1 value, continues to count to the COMP2 value, and then stops.

 set     TMR_0_CTRL_SCS              (BIT7|BIT8)
;;   Secondary Count Source
;;     0b00 ==> Counter 0 input pin
;;     0b01 ==> Counter 1 input pin
;;     0b10 ==> Counter 2 input pin
;;     0b11 ==> Counter 3 input pin
 set     TMR_0_CTRL_SCS_0            BIT7
 set     TMR_0_CTRL_SCS_1            BIT8

 set     TMR_0_CTRL_PCS              (BIT9|BIT10|BIT11|BIT12)
;;   Primary Count Source
;;     0b0000 ==> Counter 0 input pin
;;     0b0001 ==> Counter 1 input pin
;;     0b0010 ==> Counter 2 input pin
;;     0b0011 ==> Counter 3 input pin
;;     0b0100 ==> Counter 0 output
;;     0b0101 ==> Counter 1 output
;;     0b0110 ==> Counter 2 output
;;     0b0111 ==> Counter 3 output
;;     0b1000 ==> IP bus clock divide by 1 prescaler
;;     0b1001 ==> IP bus clock divide by 2 prescaler
;;     0b1010 ==> IP bus clock divide by 4 prescaler
;;     0b1011 ==> IP bus clock divide by 8 prescaler
;;     0b1100 ==> IP bus clock divide by 16 prescaler
;;     0b1101 ==> IP bus clock divide by 32 prescaler
;;     0b1110 ==> IP bus clock divide by 64 prescaler
;;     0b1111 ==> IP bus clock divide by 128 prescaler
 set     TMR_0_CTRL_PCS_0            BIT9
 set     TMR_0_CTRL_PCS_1            BIT10
 set     TMR_0_CTRL_PCS_2            BIT11
 set     TMR_0_CTRL_PCS_3            BIT12

 set     TMR_0_CTRL_CM               (BIT13|BIT14|BIT15)
;;   Count Mode
;;     0b000 ==> No operation
;;     0b001 ==> Count rising edges of primary sourceRising edges are counted only when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1. If the primary count source is IP bus clock divide by 1, only rising edges are counted regardless of the value of SCTRL[IPS].
;;     0b010 ==> Count rising and falling edges of primary sourceIP bus clock divide by 1 cannot be used as a primary count source in edge count mode.
;;     0b011 ==> Count rising edges of primary source while secondary input high active
;;     0b100 ==> Quadrature count mode, uses primary and secondary sources
;;     0b101 ==> Count rising edges of primary source; secondary source specifies directionRising edges are counted only when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1.
;;     0b110 ==> Edge of secondary source triggers primary count until compare
;;     0b111 ==> Cascaded counter mode (up/down)The primary count source must be set to one of the counter outputs.
 set     TMR_0_CTRL_CM_0             BIT13
 set     TMR_0_CTRL_CM_1             BIT14
 set     TMR_0_CTRL_CM_2             BIT15

 set     TMR_0_SCTRL_OEN             BIT0
;;   Output Enable
;;     0b0 ==> The external pin is configured as an input.
;;     0b1 ==> The OFLAG output signal is driven on the external pin. Other timer groups using this external pin as their input see the driven value. The polarity of the signal is determined by OPS.

 set     TMR_0_SCTRL_OPS             BIT1
;;   Output Polarity Select
;;     0b0 ==> True polarity.
;;     0b1 ==> Inverted polarity.

 set     TMR_0_SCTRL_FORCE           BIT2
;;   Force OFLAG Output

 set     TMR_0_SCTRL_VAL             BIT3
;;   Forced OFLAG Value

 set     TMR_0_SCTRL_EEOF            BIT4
;;   Enable External OFLAG Force

 set     TMR_0_SCTRL_MSTR            BIT5
;;   Master Mode

 set     TMR_0_SCTRL_CAPTURE_MODE    (BIT6|BIT7)
;;   Input Capture Mode
;;     0b00 ==> Capture function is disabled
;;     0b01 ==> Load capture register on rising edge (when IPS=0) or falling edge (when IPS=1) of input
;;     0b10 ==> Load capture register on falling edge (when IPS=0) or rising edge (when IPS=1) of input
;;     0b11 ==> Load capture register on both edges of input
 set     TMR_0_SCTRL_CAPTURE_MODE_0  BIT6
 set     TMR_0_SCTRL_CAPTURE_MODE_1  BIT7

 set     TMR_0_SCTRL_INPUT           BIT8
;;   External Input Signal

 set     TMR_0_SCTRL_IPS             BIT9
;;   Input Polarity Select

 set     TMR_0_SCTRL_IEFIE           BIT10
;;   Input Edge Flag Interrupt Enable

 set     TMR_0_SCTRL_IEF             BIT11
;;   Input Edge Flag

 set     TMR_0_SCTRL_TOFIE           BIT12
;;   Timer Overflow Flag Interrupt Enable

 set     TMR_0_SCTRL_TOF             BIT13
;;   Timer Overflow Flag

 set     TMR_0_SCTRL_TCFIE           BIT14
;;   Timer Compare Flag Interrupt Enable

 set     TMR_0_SCTRL_TCF             BIT15
;;   Timer Compare Flag

 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_0 BIT0
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_1 BIT1
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_2 BIT2
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_3 BIT3
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_4 BIT4
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_5 BIT5
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_6 BIT6
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_7 BIT7
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_8 BIT8
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_9 BIT9
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_10 BIT10
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_11 BIT11
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_12 BIT12
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_13 BIT13
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_14 BIT14
 set     TMR_0_CMPLD1_COMPARATOR_LOAD_1_15 BIT15

 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_0 BIT0
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_1 BIT1
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_2 BIT2
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_3 BIT3
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_4 BIT4
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_5 BIT5
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_6 BIT6
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_7 BIT7
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_8 BIT8
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_9 BIT9
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_10 BIT10
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_11 BIT11
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_12 BIT12
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_13 BIT13
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_14 BIT14
 set     TMR_0_CMPLD2_COMPARATOR_LOAD_2_15 BIT15

 set     TMR_0_CSCTRL_CL1            (BIT0|BIT1)
;;   Compare Load Control 1
;;     0b00 ==> Never preload
;;     0b01 ==> Load upon successful compare with the value in COMP1
;;     0b10 ==> Load upon successful compare with the value in COMP2
;;     0b11 ==> Reserved
 set     TMR_0_CSCTRL_CL1_0          BIT0
 set     TMR_0_CSCTRL_CL1_1          BIT1

 set     TMR_0_CSCTRL_CL2            (BIT2|BIT3)
;;   Compare Load Control 2
;;     0b00 ==> Never preload
;;     0b01 ==> Load upon successful compare with the value in COMP1
;;     0b10 ==> Load upon successful compare with the value in COMP2
;;     0b11 ==> Reserved
 set     TMR_0_CSCTRL_CL2_0          BIT2
 set     TMR_0_CSCTRL_CL2_1          BIT3

 set     TMR_0_CSCTRL_TCF1           BIT4
;;   Timer Compare 1 Interrupt Flag

 set     TMR_0_CSCTRL_TCF2           BIT5
;;   Timer Compare 2 Interrupt Flag

 set     TMR_0_CSCTRL_TCF1EN         BIT6
;;   Timer Compare 1 Interrupt Enable

 set     TMR_0_CSCTRL_TCF2EN         BIT7
;;   Timer Compare 2 Interrupt Enable

 set     TMR_0_CSCTRL_UP             BIT9
;;   Counting Direction Indicator
;;     0b0 ==> The last count was in the DOWN direction.
;;     0b1 ==> The last count was in the UP direction.

 set     TMR_0_CSCTRL_TCI            BIT10
;;   Triggered Count Initialization Control
;;     0b0 ==> Stop counter upon receiving a second trigger event while still counting from the first trigger event.
;;     0b1 ==> Reload the counter upon receiving a second trigger event while still counting from the first trigger event.

 set     TMR_0_CSCTRL_ROC            BIT11
;;   Reload on Capture
;;     0b0 ==> Do not reload the counter on a capture event.
;;     0b1 ==> Reload the counter on a capture event.

 set     TMR_0_CSCTRL_ALT_LOAD       BIT12
;;   Alternative Load Enable
;;     0b0 ==> Counter can be re-initialized only with the LOAD register.
;;     0b1 ==> Counter can be re-initialized with the LOAD or CMPLD2 registers depending on count direction.

 set     TMR_0_CSCTRL_FAULT          BIT13
;;   Fault Enable
;;     0b0 ==> Fault function disabled.
;;     0b1 ==> Fault function enabled.

 set     TMR_0_CSCTRL_DBG_EN         (BIT14|BIT15)
;;   Debug Actions Enable
;;     0b00 ==> Continue with normal operation during debug mode. (default)
;;     0b01 ==> Halt TMR counter during debug mode.
;;     0b10 ==> Force TMR output to logic 0 (prior to consideration of SCTRL[OPS]).
;;     0b11 ==> Both halt counter and force output to 0 during debug mode.
 set     TMR_0_CSCTRL_DBG_EN_0       BIT14
 set     TMR_0_CSCTRL_DBG_EN_1       BIT15

 set     TMR_0_FILT_FILT_PER         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Input Filter Sample Period
 set     TMR_0_FILT_FILT_PER_0       BIT0
 set     TMR_0_FILT_FILT_PER_1       BIT1
 set     TMR_0_FILT_FILT_PER_2       BIT2
 set     TMR_0_FILT_FILT_PER_3       BIT3
 set     TMR_0_FILT_FILT_PER_4       BIT4
 set     TMR_0_FILT_FILT_PER_5       BIT5
 set     TMR_0_FILT_FILT_PER_6       BIT6
 set     TMR_0_FILT_FILT_PER_7       BIT7

 set     TMR_0_FILT_FILT_CNT         (BIT8|BIT9|BIT10)
;;   Input Filter Sample Count
 set     TMR_0_FILT_FILT_CNT_0       BIT8
 set     TMR_0_FILT_FILT_CNT_1       BIT9
 set     TMR_0_FILT_FILT_CNT_2       BIT10

 set     TMR_0_DMA_IEFDE             BIT0
;;   Input Edge Flag DMA Enable

 set     TMR_0_DMA_CMPLD1DE          BIT1
;;   Comparator Preload Register 1 DMA Enable

 set     TMR_0_DMA_CMPLD2DE          BIT2
;;   Comparator Preload Register 2 DMA Enable

 set     TMR_0_ENBL_ENBL             (BIT0|BIT1|BIT2|BIT3)
;;   Timer Channel Enable
;;     0b0 ==> Timer channel is disabled.
;;     0b1 ==> Timer channel is enabled. (default)
 set     TMR_0_ENBL_ENBL_0           BIT0
 set     TMR_0_ENBL_ENBL_1           BIT1
 set     TMR_0_ENBL_ENBL_2           BIT2
 set     TMR_0_ENBL_ENBL_3           BIT3

 set     TMR_1_COMP1_COMPARISON_1    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Comparison Value 1
 set     TMR_1_COMP1_COMPARISON_1_0  BIT0
 set     TMR_1_COMP1_COMPARISON_1_1  BIT1
 set     TMR_1_COMP1_COMPARISON_1_2  BIT2
 set     TMR_1_COMP1_COMPARISON_1_3  BIT3
 set     TMR_1_COMP1_COMPARISON_1_4  BIT4
 set     TMR_1_COMP1_COMPARISON_1_5  BIT5
 set     TMR_1_COMP1_COMPARISON_1_6  BIT6
 set     TMR_1_COMP1_COMPARISON_1_7  BIT7
 set     TMR_1_COMP1_COMPARISON_1_8  BIT8
 set     TMR_1_COMP1_COMPARISON_1_9  BIT9
 set     TMR_1_COMP1_COMPARISON_1_10 BIT10
 set     TMR_1_COMP1_COMPARISON_1_11 BIT11
 set     TMR_1_COMP1_COMPARISON_1_12 BIT12
 set     TMR_1_COMP1_COMPARISON_1_13 BIT13
 set     TMR_1_COMP1_COMPARISON_1_14 BIT14
 set     TMR_1_COMP1_COMPARISON_1_15 BIT15

 set     TMR_1_COMP2_COMPARISON_2    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Comparison Value 2
 set     TMR_1_COMP2_COMPARISON_2_0  BIT0
 set     TMR_1_COMP2_COMPARISON_2_1  BIT1
 set     TMR_1_COMP2_COMPARISON_2_2  BIT2
 set     TMR_1_COMP2_COMPARISON_2_3  BIT3
 set     TMR_1_COMP2_COMPARISON_2_4  BIT4
 set     TMR_1_COMP2_COMPARISON_2_5  BIT5
 set     TMR_1_COMP2_COMPARISON_2_6  BIT6
 set     TMR_1_COMP2_COMPARISON_2_7  BIT7
 set     TMR_1_COMP2_COMPARISON_2_8  BIT8
 set     TMR_1_COMP2_COMPARISON_2_9  BIT9
 set     TMR_1_COMP2_COMPARISON_2_10 BIT10
 set     TMR_1_COMP2_COMPARISON_2_11 BIT11
 set     TMR_1_COMP2_COMPARISON_2_12 BIT12
 set     TMR_1_COMP2_COMPARISON_2_13 BIT13
 set     TMR_1_COMP2_COMPARISON_2_14 BIT14
 set     TMR_1_COMP2_COMPARISON_2_15 BIT15

 set     TMR_1_CAPT_CAPTURE          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Capture Value
 set     TMR_1_CAPT_CAPTURE_0        BIT0
 set     TMR_1_CAPT_CAPTURE_1        BIT1
 set     TMR_1_CAPT_CAPTURE_2        BIT2
 set     TMR_1_CAPT_CAPTURE_3        BIT3
 set     TMR_1_CAPT_CAPTURE_4        BIT4
 set     TMR_1_CAPT_CAPTURE_5        BIT5
 set     TMR_1_CAPT_CAPTURE_6        BIT6
 set     TMR_1_CAPT_CAPTURE_7        BIT7
 set     TMR_1_CAPT_CAPTURE_8        BIT8
 set     TMR_1_CAPT_CAPTURE_9        BIT9
 set     TMR_1_CAPT_CAPTURE_10       BIT10
 set     TMR_1_CAPT_CAPTURE_11       BIT11
 set     TMR_1_CAPT_CAPTURE_12       BIT12
 set     TMR_1_CAPT_CAPTURE_13       BIT13
 set     TMR_1_CAPT_CAPTURE_14       BIT14
 set     TMR_1_CAPT_CAPTURE_15       BIT15

 set     TMR_1_LOAD_LOAD             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Timer Load Register
 set     TMR_1_LOAD_LOAD_0           BIT0
 set     TMR_1_LOAD_LOAD_1           BIT1
 set     TMR_1_LOAD_LOAD_2           BIT2
 set     TMR_1_LOAD_LOAD_3           BIT3
 set     TMR_1_LOAD_LOAD_4           BIT4
 set     TMR_1_LOAD_LOAD_5           BIT5
 set     TMR_1_LOAD_LOAD_6           BIT6
 set     TMR_1_LOAD_LOAD_7           BIT7
 set     TMR_1_LOAD_LOAD_8           BIT8
 set     TMR_1_LOAD_LOAD_9           BIT9
 set     TMR_1_LOAD_LOAD_10          BIT10
 set     TMR_1_LOAD_LOAD_11          BIT11
 set     TMR_1_LOAD_LOAD_12          BIT12
 set     TMR_1_LOAD_LOAD_13          BIT13
 set     TMR_1_LOAD_LOAD_14          BIT14
 set     TMR_1_LOAD_LOAD_15          BIT15

 set     TMR_1_HOLD_HOLD             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_1_HOLD_HOLD_0           BIT0
 set     TMR_1_HOLD_HOLD_1           BIT1
 set     TMR_1_HOLD_HOLD_2           BIT2
 set     TMR_1_HOLD_HOLD_3           BIT3
 set     TMR_1_HOLD_HOLD_4           BIT4
 set     TMR_1_HOLD_HOLD_5           BIT5
 set     TMR_1_HOLD_HOLD_6           BIT6
 set     TMR_1_HOLD_HOLD_7           BIT7
 set     TMR_1_HOLD_HOLD_8           BIT8
 set     TMR_1_HOLD_HOLD_9           BIT9
 set     TMR_1_HOLD_HOLD_10          BIT10
 set     TMR_1_HOLD_HOLD_11          BIT11
 set     TMR_1_HOLD_HOLD_12          BIT12
 set     TMR_1_HOLD_HOLD_13          BIT13
 set     TMR_1_HOLD_HOLD_14          BIT14
 set     TMR_1_HOLD_HOLD_15          BIT15

 set     TMR_1_CNTR_COUNTER          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_1_CNTR_COUNTER_0        BIT0
 set     TMR_1_CNTR_COUNTER_1        BIT1
 set     TMR_1_CNTR_COUNTER_2        BIT2
 set     TMR_1_CNTR_COUNTER_3        BIT3
 set     TMR_1_CNTR_COUNTER_4        BIT4
 set     TMR_1_CNTR_COUNTER_5        BIT5
 set     TMR_1_CNTR_COUNTER_6        BIT6
 set     TMR_1_CNTR_COUNTER_7        BIT7
 set     TMR_1_CNTR_COUNTER_8        BIT8
 set     TMR_1_CNTR_COUNTER_9        BIT9
 set     TMR_1_CNTR_COUNTER_10       BIT10
 set     TMR_1_CNTR_COUNTER_11       BIT11
 set     TMR_1_CNTR_COUNTER_12       BIT12
 set     TMR_1_CNTR_COUNTER_13       BIT13
 set     TMR_1_CNTR_COUNTER_14       BIT14
 set     TMR_1_CNTR_COUNTER_15       BIT15

 set     TMR_1_CTRL_OUTMODE          (BIT0|BIT1|BIT2)
;;   Output Mode
;;     0b000 ==> Asserted while counter is active
;;     0b001 ==> Clear OFLAG output on successful compare
;;     0b010 ==> Set OFLAG output on successful compare
;;     0b011 ==> Toggle OFLAG output on successful compare
;;     0b100 ==> Toggle OFLAG output using alternating compare registers
;;     0b101 ==> Set on compare, cleared on secondary source input edge
;;     0b110 ==> Set on compare, cleared on counter rollover
;;     0b111 ==> Enable gated clock output while counter is active
 set     TMR_1_CTRL_OUTMODE_0        BIT0
 set     TMR_1_CTRL_OUTMODE_1        BIT1
 set     TMR_1_CTRL_OUTMODE_2        BIT2

 set     TMR_1_CTRL_COINIT           BIT3
;;   Co-Channel Initialization
;;     0b0 ==> Co-channel counter/timers cannot force a re-initialization of this counter/timer
;;     0b1 ==> Co-channel counter/timers may force a re-initialization of this counter/timer

 set     TMR_1_CTRL_DIR              BIT4
;;   Count Direction
;;     0b0 ==> Count up.
;;     0b1 ==> Count down.

 set     TMR_1_CTRL_LENGTH           BIT5
;;   Count Length
;;     0b0 ==> Roll over.
;;     0b1 ==> Count until compare, then re-initialize. If counting up, a successful compare occurs when the counter reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When output mode $4 is used, alternating values of COMP1 and COMP2 are used to generate successful comparisons. For example, the counter counts until a COMP1 value is reached, re-initializes, counts until COMP2 value is reached, re-initializes, counts until COMP1 value
;;             is reached, and so on.

 set     TMR_1_CTRL_ONCE             BIT6
;;   Count Once
;;     0b0 ==> Count repeatedly.
;;     0b1 ==> Count until compare and then stop. If counting up, a successful compare occurs when the counter reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When output mode $4 is used, the counter re-initializes after reaching the COMP1 value, continues to count to the COMP2 value, and then stops.

 set     TMR_1_CTRL_SCS              (BIT7|BIT8)
;;   Secondary Count Source
;;     0b00 ==> Counter 0 input pin
;;     0b01 ==> Counter 1 input pin
;;     0b10 ==> Counter 2 input pin
;;     0b11 ==> Counter 3 input pin
 set     TMR_1_CTRL_SCS_0            BIT7
 set     TMR_1_CTRL_SCS_1            BIT8

 set     TMR_1_CTRL_PCS              (BIT9|BIT10|BIT11|BIT12)
;;   Primary Count Source
;;     0b0000 ==> Counter 0 input pin
;;     0b0001 ==> Counter 1 input pin
;;     0b0010 ==> Counter 2 input pin
;;     0b0011 ==> Counter 3 input pin
;;     0b0100 ==> Counter 0 output
;;     0b0101 ==> Counter 1 output
;;     0b0110 ==> Counter 2 output
;;     0b0111 ==> Counter 3 output
;;     0b1000 ==> IP bus clock divide by 1 prescaler
;;     0b1001 ==> IP bus clock divide by 2 prescaler
;;     0b1010 ==> IP bus clock divide by 4 prescaler
;;     0b1011 ==> IP bus clock divide by 8 prescaler
;;     0b1100 ==> IP bus clock divide by 16 prescaler
;;     0b1101 ==> IP bus clock divide by 32 prescaler
;;     0b1110 ==> IP bus clock divide by 64 prescaler
;;     0b1111 ==> IP bus clock divide by 128 prescaler
 set     TMR_1_CTRL_PCS_0            BIT9
 set     TMR_1_CTRL_PCS_1            BIT10
 set     TMR_1_CTRL_PCS_2            BIT11
 set     TMR_1_CTRL_PCS_3            BIT12

 set     TMR_1_CTRL_CM               (BIT13|BIT14|BIT15)
;;   Count Mode
;;     0b000 ==> No operation
;;     0b001 ==> Count rising edges of primary sourceRising edges are counted only when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1. If the primary count source is IP bus clock divide by 1, only rising edges are counted regardless of the value of SCTRL[IPS].
;;     0b010 ==> Count rising and falling edges of primary sourceIP bus clock divide by 1 cannot be used as a primary count source in edge count mode.
;;     0b011 ==> Count rising edges of primary source while secondary input high active
;;     0b100 ==> Quadrature count mode, uses primary and secondary sources
;;     0b101 ==> Count rising edges of primary source; secondary source specifies directionRising edges are counted only when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1.
;;     0b110 ==> Edge of secondary source triggers primary count until compare
;;     0b111 ==> Cascaded counter mode (up/down)The primary count source must be set to one of the counter outputs.
 set     TMR_1_CTRL_CM_0             BIT13
 set     TMR_1_CTRL_CM_1             BIT14
 set     TMR_1_CTRL_CM_2             BIT15

 set     TMR_1_SCTRL_OEN             BIT0
;;   Output Enable
;;     0b0 ==> The external pin is configured as an input.
;;     0b1 ==> The OFLAG output signal is driven on the external pin. Other timer groups using this external pin as their input see the driven value. The polarity of the signal is determined by OPS.

 set     TMR_1_SCTRL_OPS             BIT1
;;   Output Polarity Select
;;     0b0 ==> True polarity.
;;     0b1 ==> Inverted polarity.

 set     TMR_1_SCTRL_FORCE           BIT2
;;   Force OFLAG Output

 set     TMR_1_SCTRL_VAL             BIT3
;;   Forced OFLAG Value

 set     TMR_1_SCTRL_EEOF            BIT4
;;   Enable External OFLAG Force

 set     TMR_1_SCTRL_MSTR            BIT5
;;   Master Mode

 set     TMR_1_SCTRL_CAPTURE_MODE    (BIT6|BIT7)
;;   Input Capture Mode
;;     0b00 ==> Capture function is disabled
;;     0b01 ==> Load capture register on rising edge (when IPS=0) or falling edge (when IPS=1) of input
;;     0b10 ==> Load capture register on falling edge (when IPS=0) or rising edge (when IPS=1) of input
;;     0b11 ==> Load capture register on both edges of input
 set     TMR_1_SCTRL_CAPTURE_MODE_0  BIT6
 set     TMR_1_SCTRL_CAPTURE_MODE_1  BIT7

 set     TMR_1_SCTRL_INPUT           BIT8
;;   External Input Signal

 set     TMR_1_SCTRL_IPS             BIT9
;;   Input Polarity Select

 set     TMR_1_SCTRL_IEFIE           BIT10
;;   Input Edge Flag Interrupt Enable

 set     TMR_1_SCTRL_IEF             BIT11
;;   Input Edge Flag

 set     TMR_1_SCTRL_TOFIE           BIT12
;;   Timer Overflow Flag Interrupt Enable

 set     TMR_1_SCTRL_TOF             BIT13
;;   Timer Overflow Flag

 set     TMR_1_SCTRL_TCFIE           BIT14
;;   Timer Compare Flag Interrupt Enable

 set     TMR_1_SCTRL_TCF             BIT15
;;   Timer Compare Flag

 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_0 BIT0
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_1 BIT1
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_2 BIT2
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_3 BIT3
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_4 BIT4
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_5 BIT5
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_6 BIT6
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_7 BIT7
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_8 BIT8
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_9 BIT9
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_10 BIT10
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_11 BIT11
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_12 BIT12
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_13 BIT13
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_14 BIT14
 set     TMR_1_CMPLD1_COMPARATOR_LOAD_1_15 BIT15

 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_0 BIT0
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_1 BIT1
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_2 BIT2
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_3 BIT3
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_4 BIT4
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_5 BIT5
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_6 BIT6
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_7 BIT7
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_8 BIT8
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_9 BIT9
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_10 BIT10
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_11 BIT11
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_12 BIT12
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_13 BIT13
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_14 BIT14
 set     TMR_1_CMPLD2_COMPARATOR_LOAD_2_15 BIT15

 set     TMR_1_CSCTRL_CL1            (BIT0|BIT1)
;;   Compare Load Control 1
;;     0b00 ==> Never preload
;;     0b01 ==> Load upon successful compare with the value in COMP1
;;     0b10 ==> Load upon successful compare with the value in COMP2
;;     0b11 ==> Reserved
 set     TMR_1_CSCTRL_CL1_0          BIT0
 set     TMR_1_CSCTRL_CL1_1          BIT1

 set     TMR_1_CSCTRL_CL2            (BIT2|BIT3)
;;   Compare Load Control 2
;;     0b00 ==> Never preload
;;     0b01 ==> Load upon successful compare with the value in COMP1
;;     0b10 ==> Load upon successful compare with the value in COMP2
;;     0b11 ==> Reserved
 set     TMR_1_CSCTRL_CL2_0          BIT2
 set     TMR_1_CSCTRL_CL2_1          BIT3

 set     TMR_1_CSCTRL_TCF1           BIT4
;;   Timer Compare 1 Interrupt Flag

 set     TMR_1_CSCTRL_TCF2           BIT5
;;   Timer Compare 2 Interrupt Flag

 set     TMR_1_CSCTRL_TCF1EN         BIT6
;;   Timer Compare 1 Interrupt Enable

 set     TMR_1_CSCTRL_TCF2EN         BIT7
;;   Timer Compare 2 Interrupt Enable

 set     TMR_1_CSCTRL_UP             BIT9
;;   Counting Direction Indicator
;;     0b0 ==> The last count was in the DOWN direction.
;;     0b1 ==> The last count was in the UP direction.

 set     TMR_1_CSCTRL_TCI            BIT10
;;   Triggered Count Initialization Control
;;     0b0 ==> Stop counter upon receiving a second trigger event while still counting from the first trigger event.
;;     0b1 ==> Reload the counter upon receiving a second trigger event while still counting from the first trigger event.

 set     TMR_1_CSCTRL_ROC            BIT11
;;   Reload on Capture
;;     0b0 ==> Do not reload the counter on a capture event.
;;     0b1 ==> Reload the counter on a capture event.

 set     TMR_1_CSCTRL_ALT_LOAD       BIT12
;;   Alternative Load Enable
;;     0b0 ==> Counter can be re-initialized only with the LOAD register.
;;     0b1 ==> Counter can be re-initialized with the LOAD or CMPLD2 registers depending on count direction.

 set     TMR_1_CSCTRL_FAULT          BIT13
;;   Fault Enable
;;     0b0 ==> Fault function disabled.
;;     0b1 ==> Fault function enabled.

 set     TMR_1_CSCTRL_DBG_EN         (BIT14|BIT15)
;;   Debug Actions Enable
;;     0b00 ==> Continue with normal operation during debug mode. (default)
;;     0b01 ==> Halt TMR counter during debug mode.
;;     0b10 ==> Force TMR output to logic 0 (prior to consideration of SCTRL[OPS]).
;;     0b11 ==> Both halt counter and force output to 0 during debug mode.
 set     TMR_1_CSCTRL_DBG_EN_0       BIT14
 set     TMR_1_CSCTRL_DBG_EN_1       BIT15

 set     TMR_1_FILT_FILT_PER         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Input Filter Sample Period
 set     TMR_1_FILT_FILT_PER_0       BIT0
 set     TMR_1_FILT_FILT_PER_1       BIT1
 set     TMR_1_FILT_FILT_PER_2       BIT2
 set     TMR_1_FILT_FILT_PER_3       BIT3
 set     TMR_1_FILT_FILT_PER_4       BIT4
 set     TMR_1_FILT_FILT_PER_5       BIT5
 set     TMR_1_FILT_FILT_PER_6       BIT6
 set     TMR_1_FILT_FILT_PER_7       BIT7

 set     TMR_1_FILT_FILT_CNT         (BIT8|BIT9|BIT10)
;;   Input Filter Sample Count
 set     TMR_1_FILT_FILT_CNT_0       BIT8
 set     TMR_1_FILT_FILT_CNT_1       BIT9
 set     TMR_1_FILT_FILT_CNT_2       BIT10

 set     TMR_1_DMA_IEFDE             BIT0
;;   Input Edge Flag DMA Enable

 set     TMR_1_DMA_CMPLD1DE          BIT1
;;   Comparator Preload Register 1 DMA Enable

 set     TMR_1_DMA_CMPLD2DE          BIT2
;;   Comparator Preload Register 2 DMA Enable

 set     TMR_2_COMP1_COMPARISON_1    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Comparison Value 1
 set     TMR_2_COMP1_COMPARISON_1_0  BIT0
 set     TMR_2_COMP1_COMPARISON_1_1  BIT1
 set     TMR_2_COMP1_COMPARISON_1_2  BIT2
 set     TMR_2_COMP1_COMPARISON_1_3  BIT3
 set     TMR_2_COMP1_COMPARISON_1_4  BIT4
 set     TMR_2_COMP1_COMPARISON_1_5  BIT5
 set     TMR_2_COMP1_COMPARISON_1_6  BIT6
 set     TMR_2_COMP1_COMPARISON_1_7  BIT7
 set     TMR_2_COMP1_COMPARISON_1_8  BIT8
 set     TMR_2_COMP1_COMPARISON_1_9  BIT9
 set     TMR_2_COMP1_COMPARISON_1_10 BIT10
 set     TMR_2_COMP1_COMPARISON_1_11 BIT11
 set     TMR_2_COMP1_COMPARISON_1_12 BIT12
 set     TMR_2_COMP1_COMPARISON_1_13 BIT13
 set     TMR_2_COMP1_COMPARISON_1_14 BIT14
 set     TMR_2_COMP1_COMPARISON_1_15 BIT15

 set     TMR_2_COMP2_COMPARISON_2    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Comparison Value 2
 set     TMR_2_COMP2_COMPARISON_2_0  BIT0
 set     TMR_2_COMP2_COMPARISON_2_1  BIT1
 set     TMR_2_COMP2_COMPARISON_2_2  BIT2
 set     TMR_2_COMP2_COMPARISON_2_3  BIT3
 set     TMR_2_COMP2_COMPARISON_2_4  BIT4
 set     TMR_2_COMP2_COMPARISON_2_5  BIT5
 set     TMR_2_COMP2_COMPARISON_2_6  BIT6
 set     TMR_2_COMP2_COMPARISON_2_7  BIT7
 set     TMR_2_COMP2_COMPARISON_2_8  BIT8
 set     TMR_2_COMP2_COMPARISON_2_9  BIT9
 set     TMR_2_COMP2_COMPARISON_2_10 BIT10
 set     TMR_2_COMP2_COMPARISON_2_11 BIT11
 set     TMR_2_COMP2_COMPARISON_2_12 BIT12
 set     TMR_2_COMP2_COMPARISON_2_13 BIT13
 set     TMR_2_COMP2_COMPARISON_2_14 BIT14
 set     TMR_2_COMP2_COMPARISON_2_15 BIT15

 set     TMR_2_CAPT_CAPTURE          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Capture Value
 set     TMR_2_CAPT_CAPTURE_0        BIT0
 set     TMR_2_CAPT_CAPTURE_1        BIT1
 set     TMR_2_CAPT_CAPTURE_2        BIT2
 set     TMR_2_CAPT_CAPTURE_3        BIT3
 set     TMR_2_CAPT_CAPTURE_4        BIT4
 set     TMR_2_CAPT_CAPTURE_5        BIT5
 set     TMR_2_CAPT_CAPTURE_6        BIT6
 set     TMR_2_CAPT_CAPTURE_7        BIT7
 set     TMR_2_CAPT_CAPTURE_8        BIT8
 set     TMR_2_CAPT_CAPTURE_9        BIT9
 set     TMR_2_CAPT_CAPTURE_10       BIT10
 set     TMR_2_CAPT_CAPTURE_11       BIT11
 set     TMR_2_CAPT_CAPTURE_12       BIT12
 set     TMR_2_CAPT_CAPTURE_13       BIT13
 set     TMR_2_CAPT_CAPTURE_14       BIT14
 set     TMR_2_CAPT_CAPTURE_15       BIT15

 set     TMR_2_LOAD_LOAD             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Timer Load Register
 set     TMR_2_LOAD_LOAD_0           BIT0
 set     TMR_2_LOAD_LOAD_1           BIT1
 set     TMR_2_LOAD_LOAD_2           BIT2
 set     TMR_2_LOAD_LOAD_3           BIT3
 set     TMR_2_LOAD_LOAD_4           BIT4
 set     TMR_2_LOAD_LOAD_5           BIT5
 set     TMR_2_LOAD_LOAD_6           BIT6
 set     TMR_2_LOAD_LOAD_7           BIT7
 set     TMR_2_LOAD_LOAD_8           BIT8
 set     TMR_2_LOAD_LOAD_9           BIT9
 set     TMR_2_LOAD_LOAD_10          BIT10
 set     TMR_2_LOAD_LOAD_11          BIT11
 set     TMR_2_LOAD_LOAD_12          BIT12
 set     TMR_2_LOAD_LOAD_13          BIT13
 set     TMR_2_LOAD_LOAD_14          BIT14
 set     TMR_2_LOAD_LOAD_15          BIT15

 set     TMR_2_HOLD_HOLD             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_2_HOLD_HOLD_0           BIT0
 set     TMR_2_HOLD_HOLD_1           BIT1
 set     TMR_2_HOLD_HOLD_2           BIT2
 set     TMR_2_HOLD_HOLD_3           BIT3
 set     TMR_2_HOLD_HOLD_4           BIT4
 set     TMR_2_HOLD_HOLD_5           BIT5
 set     TMR_2_HOLD_HOLD_6           BIT6
 set     TMR_2_HOLD_HOLD_7           BIT7
 set     TMR_2_HOLD_HOLD_8           BIT8
 set     TMR_2_HOLD_HOLD_9           BIT9
 set     TMR_2_HOLD_HOLD_10          BIT10
 set     TMR_2_HOLD_HOLD_11          BIT11
 set     TMR_2_HOLD_HOLD_12          BIT12
 set     TMR_2_HOLD_HOLD_13          BIT13
 set     TMR_2_HOLD_HOLD_14          BIT14
 set     TMR_2_HOLD_HOLD_15          BIT15

 set     TMR_2_CNTR_COUNTER          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_2_CNTR_COUNTER_0        BIT0
 set     TMR_2_CNTR_COUNTER_1        BIT1
 set     TMR_2_CNTR_COUNTER_2        BIT2
 set     TMR_2_CNTR_COUNTER_3        BIT3
 set     TMR_2_CNTR_COUNTER_4        BIT4
 set     TMR_2_CNTR_COUNTER_5        BIT5
 set     TMR_2_CNTR_COUNTER_6        BIT6
 set     TMR_2_CNTR_COUNTER_7        BIT7
 set     TMR_2_CNTR_COUNTER_8        BIT8
 set     TMR_2_CNTR_COUNTER_9        BIT9
 set     TMR_2_CNTR_COUNTER_10       BIT10
 set     TMR_2_CNTR_COUNTER_11       BIT11
 set     TMR_2_CNTR_COUNTER_12       BIT12
 set     TMR_2_CNTR_COUNTER_13       BIT13
 set     TMR_2_CNTR_COUNTER_14       BIT14
 set     TMR_2_CNTR_COUNTER_15       BIT15

 set     TMR_2_CTRL_OUTMODE          (BIT0|BIT1|BIT2)
;;   Output Mode
;;     0b000 ==> Asserted while counter is active
;;     0b001 ==> Clear OFLAG output on successful compare
;;     0b010 ==> Set OFLAG output on successful compare
;;     0b011 ==> Toggle OFLAG output on successful compare
;;     0b100 ==> Toggle OFLAG output using alternating compare registers
;;     0b101 ==> Set on compare, cleared on secondary source input edge
;;     0b110 ==> Set on compare, cleared on counter rollover
;;     0b111 ==> Enable gated clock output while counter is active
 set     TMR_2_CTRL_OUTMODE_0        BIT0
 set     TMR_2_CTRL_OUTMODE_1        BIT1
 set     TMR_2_CTRL_OUTMODE_2        BIT2

 set     TMR_2_CTRL_COINIT           BIT3
;;   Co-Channel Initialization
;;     0b0 ==> Co-channel counter/timers cannot force a re-initialization of this counter/timer
;;     0b1 ==> Co-channel counter/timers may force a re-initialization of this counter/timer

 set     TMR_2_CTRL_DIR              BIT4
;;   Count Direction
;;     0b0 ==> Count up.
;;     0b1 ==> Count down.

 set     TMR_2_CTRL_LENGTH           BIT5
;;   Count Length
;;     0b0 ==> Roll over.
;;     0b1 ==> Count until compare, then re-initialize. If counting up, a successful compare occurs when the counter reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When output mode $4 is used, alternating values of COMP1 and COMP2 are used to generate successful comparisons. For example, the counter counts until a COMP1 value is reached, re-initializes, counts until COMP2 value is reached, re-initializes, counts until COMP1 value
;;             is reached, and so on.

 set     TMR_2_CTRL_ONCE             BIT6
;;   Count Once
;;     0b0 ==> Count repeatedly.
;;     0b1 ==> Count until compare and then stop. If counting up, a successful compare occurs when the counter reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When output mode $4 is used, the counter re-initializes after reaching the COMP1 value, continues to count to the COMP2 value, and then stops.

 set     TMR_2_CTRL_SCS              (BIT7|BIT8)
;;   Secondary Count Source
;;     0b00 ==> Counter 0 input pin
;;     0b01 ==> Counter 1 input pin
;;     0b10 ==> Counter 2 input pin
;;     0b11 ==> Counter 3 input pin
 set     TMR_2_CTRL_SCS_0            BIT7
 set     TMR_2_CTRL_SCS_1            BIT8

 set     TMR_2_CTRL_PCS              (BIT9|BIT10|BIT11|BIT12)
;;   Primary Count Source
;;     0b0000 ==> Counter 0 input pin
;;     0b0001 ==> Counter 1 input pin
;;     0b0010 ==> Counter 2 input pin
;;     0b0011 ==> Counter 3 input pin
;;     0b0100 ==> Counter 0 output
;;     0b0101 ==> Counter 1 output
;;     0b0110 ==> Counter 2 output
;;     0b0111 ==> Counter 3 output
;;     0b1000 ==> IP bus clock divide by 1 prescaler
;;     0b1001 ==> IP bus clock divide by 2 prescaler
;;     0b1010 ==> IP bus clock divide by 4 prescaler
;;     0b1011 ==> IP bus clock divide by 8 prescaler
;;     0b1100 ==> IP bus clock divide by 16 prescaler
;;     0b1101 ==> IP bus clock divide by 32 prescaler
;;     0b1110 ==> IP bus clock divide by 64 prescaler
;;     0b1111 ==> IP bus clock divide by 128 prescaler
 set     TMR_2_CTRL_PCS_0            BIT9
 set     TMR_2_CTRL_PCS_1            BIT10
 set     TMR_2_CTRL_PCS_2            BIT11
 set     TMR_2_CTRL_PCS_3            BIT12

 set     TMR_2_CTRL_CM               (BIT13|BIT14|BIT15)
;;   Count Mode
;;     0b000 ==> No operation
;;     0b001 ==> Count rising edges of primary sourceRising edges are counted only when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1. If the primary count source is IP bus clock divide by 1, only rising edges are counted regardless of the value of SCTRL[IPS].
;;     0b010 ==> Count rising and falling edges of primary sourceIP bus clock divide by 1 cannot be used as a primary count source in edge count mode.
;;     0b011 ==> Count rising edges of primary source while secondary input high active
;;     0b100 ==> Quadrature count mode, uses primary and secondary sources
;;     0b101 ==> Count rising edges of primary source; secondary source specifies directionRising edges are counted only when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1.
;;     0b110 ==> Edge of secondary source triggers primary count until compare
;;     0b111 ==> Cascaded counter mode (up/down)The primary count source must be set to one of the counter outputs.
 set     TMR_2_CTRL_CM_0             BIT13
 set     TMR_2_CTRL_CM_1             BIT14
 set     TMR_2_CTRL_CM_2             BIT15

 set     TMR_2_SCTRL_OEN             BIT0
;;   Output Enable
;;     0b0 ==> The external pin is configured as an input.
;;     0b1 ==> The OFLAG output signal is driven on the external pin. Other timer groups using this external pin as their input see the driven value. The polarity of the signal is determined by OPS.

 set     TMR_2_SCTRL_OPS             BIT1
;;   Output Polarity Select
;;     0b0 ==> True polarity.
;;     0b1 ==> Inverted polarity.

 set     TMR_2_SCTRL_FORCE           BIT2
;;   Force OFLAG Output

 set     TMR_2_SCTRL_VAL             BIT3
;;   Forced OFLAG Value

 set     TMR_2_SCTRL_EEOF            BIT4
;;   Enable External OFLAG Force

 set     TMR_2_SCTRL_MSTR            BIT5
;;   Master Mode

 set     TMR_2_SCTRL_CAPTURE_MODE    (BIT6|BIT7)
;;   Input Capture Mode
;;     0b00 ==> Capture function is disabled
;;     0b01 ==> Load capture register on rising edge (when IPS=0) or falling edge (when IPS=1) of input
;;     0b10 ==> Load capture register on falling edge (when IPS=0) or rising edge (when IPS=1) of input
;;     0b11 ==> Load capture register on both edges of input
 set     TMR_2_SCTRL_CAPTURE_MODE_0  BIT6
 set     TMR_2_SCTRL_CAPTURE_MODE_1  BIT7

 set     TMR_2_SCTRL_INPUT           BIT8
;;   External Input Signal

 set     TMR_2_SCTRL_IPS             BIT9
;;   Input Polarity Select

 set     TMR_2_SCTRL_IEFIE           BIT10
;;   Input Edge Flag Interrupt Enable

 set     TMR_2_SCTRL_IEF             BIT11
;;   Input Edge Flag

 set     TMR_2_SCTRL_TOFIE           BIT12
;;   Timer Overflow Flag Interrupt Enable

 set     TMR_2_SCTRL_TOF             BIT13
;;   Timer Overflow Flag

 set     TMR_2_SCTRL_TCFIE           BIT14
;;   Timer Compare Flag Interrupt Enable

 set     TMR_2_SCTRL_TCF             BIT15
;;   Timer Compare Flag

 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_0 BIT0
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_1 BIT1
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_2 BIT2
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_3 BIT3
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_4 BIT4
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_5 BIT5
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_6 BIT6
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_7 BIT7
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_8 BIT8
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_9 BIT9
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_10 BIT10
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_11 BIT11
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_12 BIT12
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_13 BIT13
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_14 BIT14
 set     TMR_2_CMPLD1_COMPARATOR_LOAD_1_15 BIT15

 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_0 BIT0
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_1 BIT1
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_2 BIT2
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_3 BIT3
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_4 BIT4
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_5 BIT5
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_6 BIT6
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_7 BIT7
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_8 BIT8
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_9 BIT9
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_10 BIT10
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_11 BIT11
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_12 BIT12
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_13 BIT13
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_14 BIT14
 set     TMR_2_CMPLD2_COMPARATOR_LOAD_2_15 BIT15

 set     TMR_2_CSCTRL_CL1            (BIT0|BIT1)
;;   Compare Load Control 1
;;     0b00 ==> Never preload
;;     0b01 ==> Load upon successful compare with the value in COMP1
;;     0b10 ==> Load upon successful compare with the value in COMP2
;;     0b11 ==> Reserved
 set     TMR_2_CSCTRL_CL1_0          BIT0
 set     TMR_2_CSCTRL_CL1_1          BIT1

 set     TMR_2_CSCTRL_CL2            (BIT2|BIT3)
;;   Compare Load Control 2
;;     0b00 ==> Never preload
;;     0b01 ==> Load upon successful compare with the value in COMP1
;;     0b10 ==> Load upon successful compare with the value in COMP2
;;     0b11 ==> Reserved
 set     TMR_2_CSCTRL_CL2_0          BIT2
 set     TMR_2_CSCTRL_CL2_1          BIT3

 set     TMR_2_CSCTRL_TCF1           BIT4
;;   Timer Compare 1 Interrupt Flag

 set     TMR_2_CSCTRL_TCF2           BIT5
;;   Timer Compare 2 Interrupt Flag

 set     TMR_2_CSCTRL_TCF1EN         BIT6
;;   Timer Compare 1 Interrupt Enable

 set     TMR_2_CSCTRL_TCF2EN         BIT7
;;   Timer Compare 2 Interrupt Enable

 set     TMR_2_CSCTRL_UP             BIT9
;;   Counting Direction Indicator
;;     0b0 ==> The last count was in the DOWN direction.
;;     0b1 ==> The last count was in the UP direction.

 set     TMR_2_CSCTRL_TCI            BIT10
;;   Triggered Count Initialization Control
;;     0b0 ==> Stop counter upon receiving a second trigger event while still counting from the first trigger event.
;;     0b1 ==> Reload the counter upon receiving a second trigger event while still counting from the first trigger event.

 set     TMR_2_CSCTRL_ROC            BIT11
;;   Reload on Capture
;;     0b0 ==> Do not reload the counter on a capture event.
;;     0b1 ==> Reload the counter on a capture event.

 set     TMR_2_CSCTRL_ALT_LOAD       BIT12
;;   Alternative Load Enable
;;     0b0 ==> Counter can be re-initialized only with the LOAD register.
;;     0b1 ==> Counter can be re-initialized with the LOAD or CMPLD2 registers depending on count direction.

 set     TMR_2_CSCTRL_FAULT          BIT13
;;   Fault Enable
;;     0b0 ==> Fault function disabled.
;;     0b1 ==> Fault function enabled.

 set     TMR_2_CSCTRL_DBG_EN         (BIT14|BIT15)
;;   Debug Actions Enable
;;     0b00 ==> Continue with normal operation during debug mode. (default)
;;     0b01 ==> Halt TMR counter during debug mode.
;;     0b10 ==> Force TMR output to logic 0 (prior to consideration of SCTRL[OPS]).
;;     0b11 ==> Both halt counter and force output to 0 during debug mode.
 set     TMR_2_CSCTRL_DBG_EN_0       BIT14
 set     TMR_2_CSCTRL_DBG_EN_1       BIT15

 set     TMR_2_FILT_FILT_PER         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Input Filter Sample Period
 set     TMR_2_FILT_FILT_PER_0       BIT0
 set     TMR_2_FILT_FILT_PER_1       BIT1
 set     TMR_2_FILT_FILT_PER_2       BIT2
 set     TMR_2_FILT_FILT_PER_3       BIT3
 set     TMR_2_FILT_FILT_PER_4       BIT4
 set     TMR_2_FILT_FILT_PER_5       BIT5
 set     TMR_2_FILT_FILT_PER_6       BIT6
 set     TMR_2_FILT_FILT_PER_7       BIT7

 set     TMR_2_FILT_FILT_CNT         (BIT8|BIT9|BIT10)
;;   Input Filter Sample Count
 set     TMR_2_FILT_FILT_CNT_0       BIT8
 set     TMR_2_FILT_FILT_CNT_1       BIT9
 set     TMR_2_FILT_FILT_CNT_2       BIT10

 set     TMR_2_DMA_IEFDE             BIT0
;;   Input Edge Flag DMA Enable

 set     TMR_2_DMA_CMPLD1DE          BIT1
;;   Comparator Preload Register 1 DMA Enable

 set     TMR_2_DMA_CMPLD2DE          BIT2
;;   Comparator Preload Register 2 DMA Enable

 set     TMR_3_COMP1_COMPARISON_1    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Comparison Value 1
 set     TMR_3_COMP1_COMPARISON_1_0  BIT0
 set     TMR_3_COMP1_COMPARISON_1_1  BIT1
 set     TMR_3_COMP1_COMPARISON_1_2  BIT2
 set     TMR_3_COMP1_COMPARISON_1_3  BIT3
 set     TMR_3_COMP1_COMPARISON_1_4  BIT4
 set     TMR_3_COMP1_COMPARISON_1_5  BIT5
 set     TMR_3_COMP1_COMPARISON_1_6  BIT6
 set     TMR_3_COMP1_COMPARISON_1_7  BIT7
 set     TMR_3_COMP1_COMPARISON_1_8  BIT8
 set     TMR_3_COMP1_COMPARISON_1_9  BIT9
 set     TMR_3_COMP1_COMPARISON_1_10 BIT10
 set     TMR_3_COMP1_COMPARISON_1_11 BIT11
 set     TMR_3_COMP1_COMPARISON_1_12 BIT12
 set     TMR_3_COMP1_COMPARISON_1_13 BIT13
 set     TMR_3_COMP1_COMPARISON_1_14 BIT14
 set     TMR_3_COMP1_COMPARISON_1_15 BIT15

 set     TMR_3_COMP2_COMPARISON_2    (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Comparison Value 2
 set     TMR_3_COMP2_COMPARISON_2_0  BIT0
 set     TMR_3_COMP2_COMPARISON_2_1  BIT1
 set     TMR_3_COMP2_COMPARISON_2_2  BIT2
 set     TMR_3_COMP2_COMPARISON_2_3  BIT3
 set     TMR_3_COMP2_COMPARISON_2_4  BIT4
 set     TMR_3_COMP2_COMPARISON_2_5  BIT5
 set     TMR_3_COMP2_COMPARISON_2_6  BIT6
 set     TMR_3_COMP2_COMPARISON_2_7  BIT7
 set     TMR_3_COMP2_COMPARISON_2_8  BIT8
 set     TMR_3_COMP2_COMPARISON_2_9  BIT9
 set     TMR_3_COMP2_COMPARISON_2_10 BIT10
 set     TMR_3_COMP2_COMPARISON_2_11 BIT11
 set     TMR_3_COMP2_COMPARISON_2_12 BIT12
 set     TMR_3_COMP2_COMPARISON_2_13 BIT13
 set     TMR_3_COMP2_COMPARISON_2_14 BIT14
 set     TMR_3_COMP2_COMPARISON_2_15 BIT15

 set     TMR_3_CAPT_CAPTURE          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Capture Value
 set     TMR_3_CAPT_CAPTURE_0        BIT0
 set     TMR_3_CAPT_CAPTURE_1        BIT1
 set     TMR_3_CAPT_CAPTURE_2        BIT2
 set     TMR_3_CAPT_CAPTURE_3        BIT3
 set     TMR_3_CAPT_CAPTURE_4        BIT4
 set     TMR_3_CAPT_CAPTURE_5        BIT5
 set     TMR_3_CAPT_CAPTURE_6        BIT6
 set     TMR_3_CAPT_CAPTURE_7        BIT7
 set     TMR_3_CAPT_CAPTURE_8        BIT8
 set     TMR_3_CAPT_CAPTURE_9        BIT9
 set     TMR_3_CAPT_CAPTURE_10       BIT10
 set     TMR_3_CAPT_CAPTURE_11       BIT11
 set     TMR_3_CAPT_CAPTURE_12       BIT12
 set     TMR_3_CAPT_CAPTURE_13       BIT13
 set     TMR_3_CAPT_CAPTURE_14       BIT14
 set     TMR_3_CAPT_CAPTURE_15       BIT15

 set     TMR_3_LOAD_LOAD             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
;;   Timer Load Register
 set     TMR_3_LOAD_LOAD_0           BIT0
 set     TMR_3_LOAD_LOAD_1           BIT1
 set     TMR_3_LOAD_LOAD_2           BIT2
 set     TMR_3_LOAD_LOAD_3           BIT3
 set     TMR_3_LOAD_LOAD_4           BIT4
 set     TMR_3_LOAD_LOAD_5           BIT5
 set     TMR_3_LOAD_LOAD_6           BIT6
 set     TMR_3_LOAD_LOAD_7           BIT7
 set     TMR_3_LOAD_LOAD_8           BIT8
 set     TMR_3_LOAD_LOAD_9           BIT9
 set     TMR_3_LOAD_LOAD_10          BIT10
 set     TMR_3_LOAD_LOAD_11          BIT11
 set     TMR_3_LOAD_LOAD_12          BIT12
 set     TMR_3_LOAD_LOAD_13          BIT13
 set     TMR_3_LOAD_LOAD_14          BIT14
 set     TMR_3_LOAD_LOAD_15          BIT15

 set     TMR_3_HOLD_HOLD             (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_3_HOLD_HOLD_0           BIT0
 set     TMR_3_HOLD_HOLD_1           BIT1
 set     TMR_3_HOLD_HOLD_2           BIT2
 set     TMR_3_HOLD_HOLD_3           BIT3
 set     TMR_3_HOLD_HOLD_4           BIT4
 set     TMR_3_HOLD_HOLD_5           BIT5
 set     TMR_3_HOLD_HOLD_6           BIT6
 set     TMR_3_HOLD_HOLD_7           BIT7
 set     TMR_3_HOLD_HOLD_8           BIT8
 set     TMR_3_HOLD_HOLD_9           BIT9
 set     TMR_3_HOLD_HOLD_10          BIT10
 set     TMR_3_HOLD_HOLD_11          BIT11
 set     TMR_3_HOLD_HOLD_12          BIT12
 set     TMR_3_HOLD_HOLD_13          BIT13
 set     TMR_3_HOLD_HOLD_14          BIT14
 set     TMR_3_HOLD_HOLD_15          BIT15

 set     TMR_3_CNTR_COUNTER          (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_3_CNTR_COUNTER_0        BIT0
 set     TMR_3_CNTR_COUNTER_1        BIT1
 set     TMR_3_CNTR_COUNTER_2        BIT2
 set     TMR_3_CNTR_COUNTER_3        BIT3
 set     TMR_3_CNTR_COUNTER_4        BIT4
 set     TMR_3_CNTR_COUNTER_5        BIT5
 set     TMR_3_CNTR_COUNTER_6        BIT6
 set     TMR_3_CNTR_COUNTER_7        BIT7
 set     TMR_3_CNTR_COUNTER_8        BIT8
 set     TMR_3_CNTR_COUNTER_9        BIT9
 set     TMR_3_CNTR_COUNTER_10       BIT10
 set     TMR_3_CNTR_COUNTER_11       BIT11
 set     TMR_3_CNTR_COUNTER_12       BIT12
 set     TMR_3_CNTR_COUNTER_13       BIT13
 set     TMR_3_CNTR_COUNTER_14       BIT14
 set     TMR_3_CNTR_COUNTER_15       BIT15

 set     TMR_3_CTRL_OUTMODE          (BIT0|BIT1|BIT2)
;;   Output Mode
;;     0b000 ==> Asserted while counter is active
;;     0b001 ==> Clear OFLAG output on successful compare
;;     0b010 ==> Set OFLAG output on successful compare
;;     0b011 ==> Toggle OFLAG output on successful compare
;;     0b100 ==> Toggle OFLAG output using alternating compare registers
;;     0b101 ==> Set on compare, cleared on secondary source input edge
;;     0b110 ==> Set on compare, cleared on counter rollover
;;     0b111 ==> Enable gated clock output while counter is active
 set     TMR_3_CTRL_OUTMODE_0        BIT0
 set     TMR_3_CTRL_OUTMODE_1        BIT1
 set     TMR_3_CTRL_OUTMODE_2        BIT2

 set     TMR_3_CTRL_COINIT           BIT3
;;   Co-Channel Initialization
;;     0b0 ==> Co-channel counter/timers cannot force a re-initialization of this counter/timer
;;     0b1 ==> Co-channel counter/timers may force a re-initialization of this counter/timer

 set     TMR_3_CTRL_DIR              BIT4
;;   Count Direction
;;     0b0 ==> Count up.
;;     0b1 ==> Count down.

 set     TMR_3_CTRL_LENGTH           BIT5
;;   Count Length
;;     0b0 ==> Roll over.
;;     0b1 ==> Count until compare, then re-initialize. If counting up, a successful compare occurs when the counter reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When output mode $4 is used, alternating values of COMP1 and COMP2 are used to generate successful comparisons. For example, the counter counts until a COMP1 value is reached, re-initializes, counts until COMP2 value is reached, re-initializes, counts until COMP1 value
;;             is reached, and so on.

 set     TMR_3_CTRL_ONCE             BIT6
;;   Count Once
;;     0b0 ==> Count repeatedly.
;;     0b1 ==> Count until compare and then stop. If counting up, a successful compare occurs when the counter reaches a COMP1 value. If counting down, a successful compare occurs when the counter reaches a COMP2 value. When output mode $4 is used, the counter re-initializes after reaching the COMP1 value, continues to count to the COMP2 value, and then stops.

 set     TMR_3_CTRL_SCS              (BIT7|BIT8)
;;   Secondary Count Source
;;     0b00 ==> Counter 0 input pin
;;     0b01 ==> Counter 1 input pin
;;     0b10 ==> Counter 2 input pin
;;     0b11 ==> Counter 3 input pin
 set     TMR_3_CTRL_SCS_0            BIT7
 set     TMR_3_CTRL_SCS_1            BIT8

 set     TMR_3_CTRL_PCS              (BIT9|BIT10|BIT11|BIT12)
;;   Primary Count Source
;;     0b0000 ==> Counter 0 input pin
;;     0b0001 ==> Counter 1 input pin
;;     0b0010 ==> Counter 2 input pin
;;     0b0011 ==> Counter 3 input pin
;;     0b0100 ==> Counter 0 output
;;     0b0101 ==> Counter 1 output
;;     0b0110 ==> Counter 2 output
;;     0b0111 ==> Counter 3 output
;;     0b1000 ==> IP bus clock divide by 1 prescaler
;;     0b1001 ==> IP bus clock divide by 2 prescaler
;;     0b1010 ==> IP bus clock divide by 4 prescaler
;;     0b1011 ==> IP bus clock divide by 8 prescaler
;;     0b1100 ==> IP bus clock divide by 16 prescaler
;;     0b1101 ==> IP bus clock divide by 32 prescaler
;;     0b1110 ==> IP bus clock divide by 64 prescaler
;;     0b1111 ==> IP bus clock divide by 128 prescaler
 set     TMR_3_CTRL_PCS_0            BIT9
 set     TMR_3_CTRL_PCS_1            BIT10
 set     TMR_3_CTRL_PCS_2            BIT11
 set     TMR_3_CTRL_PCS_3            BIT12

 set     TMR_3_CTRL_CM               (BIT13|BIT14|BIT15)
;;   Count Mode
;;     0b000 ==> No operation
;;     0b001 ==> Count rising edges of primary sourceRising edges are counted only when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1. If the primary count source is IP bus clock divide by 1, only rising edges are counted regardless of the value of SCTRL[IPS].
;;     0b010 ==> Count rising and falling edges of primary sourceIP bus clock divide by 1 cannot be used as a primary count source in edge count mode.
;;     0b011 ==> Count rising edges of primary source while secondary input high active
;;     0b100 ==> Quadrature count mode, uses primary and secondary sources
;;     0b101 ==> Count rising edges of primary source; secondary source specifies directionRising edges are counted only when SCTRL[IPS] = 0. Falling edges are counted when SCTRL[IPS] = 1.
;;     0b110 ==> Edge of secondary source triggers primary count until compare
;;     0b111 ==> Cascaded counter mode (up/down)The primary count source must be set to one of the counter outputs.
 set     TMR_3_CTRL_CM_0             BIT13
 set     TMR_3_CTRL_CM_1             BIT14
 set     TMR_3_CTRL_CM_2             BIT15

 set     TMR_3_SCTRL_OEN             BIT0
;;   Output Enable
;;     0b0 ==> The external pin is configured as an input.
;;     0b1 ==> The OFLAG output signal is driven on the external pin. Other timer groups using this external pin as their input see the driven value. The polarity of the signal is determined by OPS.

 set     TMR_3_SCTRL_OPS             BIT1
;;   Output Polarity Select
;;     0b0 ==> True polarity.
;;     0b1 ==> Inverted polarity.

 set     TMR_3_SCTRL_FORCE           BIT2
;;   Force OFLAG Output

 set     TMR_3_SCTRL_VAL             BIT3
;;   Forced OFLAG Value

 set     TMR_3_SCTRL_EEOF            BIT4
;;   Enable External OFLAG Force

 set     TMR_3_SCTRL_MSTR            BIT5
;;   Master Mode

 set     TMR_3_SCTRL_CAPTURE_MODE    (BIT6|BIT7)
;;   Input Capture Mode
;;     0b00 ==> Capture function is disabled
;;     0b01 ==> Load capture register on rising edge (when IPS=0) or falling edge (when IPS=1) of input
;;     0b10 ==> Load capture register on falling edge (when IPS=0) or rising edge (when IPS=1) of input
;;     0b11 ==> Load capture register on both edges of input
 set     TMR_3_SCTRL_CAPTURE_MODE_0  BIT6
 set     TMR_3_SCTRL_CAPTURE_MODE_1  BIT7

 set     TMR_3_SCTRL_INPUT           BIT8
;;   External Input Signal

 set     TMR_3_SCTRL_IPS             BIT9
;;   Input Polarity Select

 set     TMR_3_SCTRL_IEFIE           BIT10
;;   Input Edge Flag Interrupt Enable

 set     TMR_3_SCTRL_IEF             BIT11
;;   Input Edge Flag

 set     TMR_3_SCTRL_TOFIE           BIT12
;;   Timer Overflow Flag Interrupt Enable

 set     TMR_3_SCTRL_TOF             BIT13
;;   Timer Overflow Flag

 set     TMR_3_SCTRL_TCFIE           BIT14
;;   Timer Compare Flag Interrupt Enable

 set     TMR_3_SCTRL_TCF             BIT15
;;   Timer Compare Flag

 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_0 BIT0
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_1 BIT1
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_2 BIT2
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_3 BIT3
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_4 BIT4
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_5 BIT5
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_6 BIT6
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_7 BIT7
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_8 BIT8
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_9 BIT9
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_10 BIT10
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_11 BIT11
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_12 BIT12
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_13 BIT13
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_14 BIT14
 set     TMR_3_CMPLD1_COMPARATOR_LOAD_1_15 BIT15

 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2 (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7|BIT8|BIT9|BIT10|BIT11|BIT12|BIT13|BIT14|BIT15)
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_0 BIT0
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_1 BIT1
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_2 BIT2
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_3 BIT3
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_4 BIT4
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_5 BIT5
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_6 BIT6
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_7 BIT7
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_8 BIT8
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_9 BIT9
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_10 BIT10
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_11 BIT11
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_12 BIT12
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_13 BIT13
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_14 BIT14
 set     TMR_3_CMPLD2_COMPARATOR_LOAD_2_15 BIT15

 set     TMR_3_CSCTRL_CL1            (BIT0|BIT1)
;;   Compare Load Control 1
;;     0b00 ==> Never preload
;;     0b01 ==> Load upon successful compare with the value in COMP1
;;     0b10 ==> Load upon successful compare with the value in COMP2
;;     0b11 ==> Reserved
 set     TMR_3_CSCTRL_CL1_0          BIT0
 set     TMR_3_CSCTRL_CL1_1          BIT1

 set     TMR_3_CSCTRL_CL2            (BIT2|BIT3)
;;   Compare Load Control 2
;;     0b00 ==> Never preload
;;     0b01 ==> Load upon successful compare with the value in COMP1
;;     0b10 ==> Load upon successful compare with the value in COMP2
;;     0b11 ==> Reserved
 set     TMR_3_CSCTRL_CL2_0          BIT2
 set     TMR_3_CSCTRL_CL2_1          BIT3

 set     TMR_3_CSCTRL_TCF1           BIT4
;;   Timer Compare 1 Interrupt Flag

 set     TMR_3_CSCTRL_TCF2           BIT5
;;   Timer Compare 2 Interrupt Flag

 set     TMR_3_CSCTRL_TCF1EN         BIT6
;;   Timer Compare 1 Interrupt Enable

 set     TMR_3_CSCTRL_TCF2EN         BIT7
;;   Timer Compare 2 Interrupt Enable

 set     TMR_3_CSCTRL_UP             BIT9
;;   Counting Direction Indicator
;;     0b0 ==> The last count was in the DOWN direction.
;;     0b1 ==> The last count was in the UP direction.

 set     TMR_3_CSCTRL_TCI            BIT10
;;   Triggered Count Initialization Control
;;     0b0 ==> Stop counter upon receiving a second trigger event while still counting from the first trigger event.
;;     0b1 ==> Reload the counter upon receiving a second trigger event while still counting from the first trigger event.

 set     TMR_3_CSCTRL_ROC            BIT11
;;   Reload on Capture
;;     0b0 ==> Do not reload the counter on a capture event.
;;     0b1 ==> Reload the counter on a capture event.

 set     TMR_3_CSCTRL_ALT_LOAD       BIT12
;;   Alternative Load Enable
;;     0b0 ==> Counter can be re-initialized only with the LOAD register.
;;     0b1 ==> Counter can be re-initialized with the LOAD or CMPLD2 registers depending on count direction.

 set     TMR_3_CSCTRL_FAULT          BIT13
;;   Fault Enable
;;     0b0 ==> Fault function disabled.
;;     0b1 ==> Fault function enabled.

 set     TMR_3_CSCTRL_DBG_EN         (BIT14|BIT15)
;;   Debug Actions Enable
;;     0b00 ==> Continue with normal operation during debug mode. (default)
;;     0b01 ==> Halt TMR counter during debug mode.
;;     0b10 ==> Force TMR output to logic 0 (prior to consideration of SCTRL[OPS]).
;;     0b11 ==> Both halt counter and force output to 0 during debug mode.
 set     TMR_3_CSCTRL_DBG_EN_0       BIT14
 set     TMR_3_CSCTRL_DBG_EN_1       BIT15

 set     TMR_3_FILT_FILT_PER         (BIT0|BIT1|BIT2|BIT3|BIT4|BIT5|BIT6|BIT7)
;;   Input Filter Sample Period
 set     TMR_3_FILT_FILT_PER_0       BIT0
 set     TMR_3_FILT_FILT_PER_1       BIT1
 set     TMR_3_FILT_FILT_PER_2       BIT2
 set     TMR_3_FILT_FILT_PER_3       BIT3
 set     TMR_3_FILT_FILT_PER_4       BIT4
 set     TMR_3_FILT_FILT_PER_5       BIT5
 set     TMR_3_FILT_FILT_PER_6       BIT6
 set     TMR_3_FILT_FILT_PER_7       BIT7

 set     TMR_3_FILT_FILT_CNT         (BIT8|BIT9|BIT10)
;;   Input Filter Sample Count
 set     TMR_3_FILT_FILT_CNT_0       BIT8
 set     TMR_3_FILT_FILT_CNT_1       BIT9
 set     TMR_3_FILT_FILT_CNT_2       BIT10

 set     TMR_3_DMA_IEFDE             BIT0
;;   Input Edge Flag DMA Enable

 set     TMR_3_DMA_CMPLD1DE          BIT1
;;   Comparator Preload Register 1 DMA Enable

 set     TMR_3_DMA_CMPLD2DE          BIT2
;;   Comparator Preload Register 2 DMA Enable

 set     XBARA_SEL0_SEL0             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL0_SEL0_0           BIT0
 set     XBARA_SEL0_SEL0_1           BIT1
 set     XBARA_SEL0_SEL0_2           BIT2
 set     XBARA_SEL0_SEL0_3           BIT3
 set     XBARA_SEL0_SEL0_4           BIT4

 set     XBARA_SEL0_SEL1             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL0_SEL1_0           BIT8
 set     XBARA_SEL0_SEL1_1           BIT9
 set     XBARA_SEL0_SEL1_2           BIT10
 set     XBARA_SEL0_SEL1_3           BIT11
 set     XBARA_SEL0_SEL1_4           BIT12

 set     XBARA_SEL1_SEL2             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL1_SEL2_0           BIT0
 set     XBARA_SEL1_SEL2_1           BIT1
 set     XBARA_SEL1_SEL2_2           BIT2
 set     XBARA_SEL1_SEL2_3           BIT3
 set     XBARA_SEL1_SEL2_4           BIT4

 set     XBARA_SEL1_SEL3             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL1_SEL3_0           BIT8
 set     XBARA_SEL1_SEL3_1           BIT9
 set     XBARA_SEL1_SEL3_2           BIT10
 set     XBARA_SEL1_SEL3_3           BIT11
 set     XBARA_SEL1_SEL3_4           BIT12

 set     XBARA_SEL2_SEL4             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL2_SEL4_0           BIT0
 set     XBARA_SEL2_SEL4_1           BIT1
 set     XBARA_SEL2_SEL4_2           BIT2
 set     XBARA_SEL2_SEL4_3           BIT3
 set     XBARA_SEL2_SEL4_4           BIT4

 set     XBARA_SEL2_SEL5             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL2_SEL5_0           BIT8
 set     XBARA_SEL2_SEL5_1           BIT9
 set     XBARA_SEL2_SEL5_2           BIT10
 set     XBARA_SEL2_SEL5_3           BIT11
 set     XBARA_SEL2_SEL5_4           BIT12

 set     XBARA_SEL3_SEL6             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL3_SEL6_0           BIT0
 set     XBARA_SEL3_SEL6_1           BIT1
 set     XBARA_SEL3_SEL6_2           BIT2
 set     XBARA_SEL3_SEL6_3           BIT3
 set     XBARA_SEL3_SEL6_4           BIT4

 set     XBARA_SEL3_SEL7             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL3_SEL7_0           BIT8
 set     XBARA_SEL3_SEL7_1           BIT9
 set     XBARA_SEL3_SEL7_2           BIT10
 set     XBARA_SEL3_SEL7_3           BIT11
 set     XBARA_SEL3_SEL7_4           BIT12

 set     XBARA_SEL4_SEL8             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL4_SEL8_0           BIT0
 set     XBARA_SEL4_SEL8_1           BIT1
 set     XBARA_SEL4_SEL8_2           BIT2
 set     XBARA_SEL4_SEL8_3           BIT3
 set     XBARA_SEL4_SEL8_4           BIT4

 set     XBARA_SEL4_SEL9             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL4_SEL9_0           BIT8
 set     XBARA_SEL4_SEL9_1           BIT9
 set     XBARA_SEL4_SEL9_2           BIT10
 set     XBARA_SEL4_SEL9_3           BIT11
 set     XBARA_SEL4_SEL9_4           BIT12

 set     XBARA_SEL5_SEL10            (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL5_SEL10_0          BIT0
 set     XBARA_SEL5_SEL10_1          BIT1
 set     XBARA_SEL5_SEL10_2          BIT2
 set     XBARA_SEL5_SEL10_3          BIT3
 set     XBARA_SEL5_SEL10_4          BIT4

 set     XBARA_SEL5_SEL11            (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL5_SEL11_0          BIT8
 set     XBARA_SEL5_SEL11_1          BIT9
 set     XBARA_SEL5_SEL11_2          BIT10
 set     XBARA_SEL5_SEL11_3          BIT11
 set     XBARA_SEL5_SEL11_4          BIT12

 set     XBARA_SEL6_SEL12            (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL6_SEL12_0          BIT0
 set     XBARA_SEL6_SEL12_1          BIT1
 set     XBARA_SEL6_SEL12_2          BIT2
 set     XBARA_SEL6_SEL12_3          BIT3
 set     XBARA_SEL6_SEL12_4          BIT4

 set     XBARA_SEL6_SEL13            (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL6_SEL13_0          BIT8
 set     XBARA_SEL6_SEL13_1          BIT9
 set     XBARA_SEL6_SEL13_2          BIT10
 set     XBARA_SEL6_SEL13_3          BIT11
 set     XBARA_SEL6_SEL13_4          BIT12

 set     XBARA_SEL7_SEL14            (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL7_SEL14_0          BIT0
 set     XBARA_SEL7_SEL14_1          BIT1
 set     XBARA_SEL7_SEL14_2          BIT2
 set     XBARA_SEL7_SEL14_3          BIT3
 set     XBARA_SEL7_SEL14_4          BIT4

 set     XBARA_SEL7_SEL15            (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL7_SEL15_0          BIT8
 set     XBARA_SEL7_SEL15_1          BIT9
 set     XBARA_SEL7_SEL15_2          BIT10
 set     XBARA_SEL7_SEL15_3          BIT11
 set     XBARA_SEL7_SEL15_4          BIT12

 set     XBARA_SEL8_SEL16            (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL8_SEL16_0          BIT0
 set     XBARA_SEL8_SEL16_1          BIT1
 set     XBARA_SEL8_SEL16_2          BIT2
 set     XBARA_SEL8_SEL16_3          BIT3
 set     XBARA_SEL8_SEL16_4          BIT4

 set     XBARA_SEL8_SEL17            (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL8_SEL17_0          BIT8
 set     XBARA_SEL8_SEL17_1          BIT9
 set     XBARA_SEL8_SEL17_2          BIT10
 set     XBARA_SEL8_SEL17_3          BIT11
 set     XBARA_SEL8_SEL17_4          BIT12

 set     XBARA_SEL9_SEL18            (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL9_SEL18_0          BIT0
 set     XBARA_SEL9_SEL18_1          BIT1
 set     XBARA_SEL9_SEL18_2          BIT2
 set     XBARA_SEL9_SEL18_3          BIT3
 set     XBARA_SEL9_SEL18_4          BIT4

 set     XBARA_SEL9_SEL19            (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL9_SEL19_0          BIT8
 set     XBARA_SEL9_SEL19_1          BIT9
 set     XBARA_SEL9_SEL19_2          BIT10
 set     XBARA_SEL9_SEL19_3          BIT11
 set     XBARA_SEL9_SEL19_4          BIT12

 set     XBARA_SEL10_SEL20           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL10_SEL20_0         BIT0
 set     XBARA_SEL10_SEL20_1         BIT1
 set     XBARA_SEL10_SEL20_2         BIT2
 set     XBARA_SEL10_SEL20_3         BIT3
 set     XBARA_SEL10_SEL20_4         BIT4

 set     XBARA_SEL10_SEL21           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL10_SEL21_0         BIT8
 set     XBARA_SEL10_SEL21_1         BIT9
 set     XBARA_SEL10_SEL21_2         BIT10
 set     XBARA_SEL10_SEL21_3         BIT11
 set     XBARA_SEL10_SEL21_4         BIT12

 set     XBARA_SEL11_SEL22           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL11_SEL22_0         BIT0
 set     XBARA_SEL11_SEL22_1         BIT1
 set     XBARA_SEL11_SEL22_2         BIT2
 set     XBARA_SEL11_SEL22_3         BIT3
 set     XBARA_SEL11_SEL22_4         BIT4

 set     XBARA_SEL11_SEL23           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL11_SEL23_0         BIT8
 set     XBARA_SEL11_SEL23_1         BIT9
 set     XBARA_SEL11_SEL23_2         BIT10
 set     XBARA_SEL11_SEL23_3         BIT11
 set     XBARA_SEL11_SEL23_4         BIT12

 set     XBARA_SEL12_SEL24           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL12_SEL24_0         BIT0
 set     XBARA_SEL12_SEL24_1         BIT1
 set     XBARA_SEL12_SEL24_2         BIT2
 set     XBARA_SEL12_SEL24_3         BIT3
 set     XBARA_SEL12_SEL24_4         BIT4

 set     XBARA_SEL12_SEL25           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL12_SEL25_0         BIT8
 set     XBARA_SEL12_SEL25_1         BIT9
 set     XBARA_SEL12_SEL25_2         BIT10
 set     XBARA_SEL12_SEL25_3         BIT11
 set     XBARA_SEL12_SEL25_4         BIT12

 set     XBARA_SEL13_SEL26           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL13_SEL26_0         BIT0
 set     XBARA_SEL13_SEL26_1         BIT1
 set     XBARA_SEL13_SEL26_2         BIT2
 set     XBARA_SEL13_SEL26_3         BIT3
 set     XBARA_SEL13_SEL26_4         BIT4

 set     XBARA_SEL13_SEL27           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL13_SEL27_0         BIT8
 set     XBARA_SEL13_SEL27_1         BIT9
 set     XBARA_SEL13_SEL27_2         BIT10
 set     XBARA_SEL13_SEL27_3         BIT11
 set     XBARA_SEL13_SEL27_4         BIT12

 set     XBARA_SEL14_SEL28           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL14_SEL28_0         BIT0
 set     XBARA_SEL14_SEL28_1         BIT1
 set     XBARA_SEL14_SEL28_2         BIT2
 set     XBARA_SEL14_SEL28_3         BIT3
 set     XBARA_SEL14_SEL28_4         BIT4

 set     XBARA_SEL14_SEL29           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL14_SEL29_0         BIT8
 set     XBARA_SEL14_SEL29_1         BIT9
 set     XBARA_SEL14_SEL29_2         BIT10
 set     XBARA_SEL14_SEL29_3         BIT11
 set     XBARA_SEL14_SEL29_4         BIT12

 set     XBARA_SEL15_SEL30           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL15_SEL30_0         BIT0
 set     XBARA_SEL15_SEL30_1         BIT1
 set     XBARA_SEL15_SEL30_2         BIT2
 set     XBARA_SEL15_SEL30_3         BIT3
 set     XBARA_SEL15_SEL30_4         BIT4

 set     XBARA_SEL15_SEL31           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL15_SEL31_0         BIT8
 set     XBARA_SEL15_SEL31_1         BIT9
 set     XBARA_SEL15_SEL31_2         BIT10
 set     XBARA_SEL15_SEL31_3         BIT11
 set     XBARA_SEL15_SEL31_4         BIT12

 set     XBARA_SEL16_SEL32           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL16_SEL32_0         BIT0
 set     XBARA_SEL16_SEL32_1         BIT1
 set     XBARA_SEL16_SEL32_2         BIT2
 set     XBARA_SEL16_SEL32_3         BIT3
 set     XBARA_SEL16_SEL32_4         BIT4

 set     XBARA_SEL16_SEL33           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL16_SEL33_0         BIT8
 set     XBARA_SEL16_SEL33_1         BIT9
 set     XBARA_SEL16_SEL33_2         BIT10
 set     XBARA_SEL16_SEL33_3         BIT11
 set     XBARA_SEL16_SEL33_4         BIT12

 set     XBARA_SEL17_SEL34           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL17_SEL34_0         BIT0
 set     XBARA_SEL17_SEL34_1         BIT1
 set     XBARA_SEL17_SEL34_2         BIT2
 set     XBARA_SEL17_SEL34_3         BIT3
 set     XBARA_SEL17_SEL34_4         BIT4

 set     XBARA_SEL17_SEL35           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL17_SEL35_0         BIT8
 set     XBARA_SEL17_SEL35_1         BIT9
 set     XBARA_SEL17_SEL35_2         BIT10
 set     XBARA_SEL17_SEL35_3         BIT11
 set     XBARA_SEL17_SEL35_4         BIT12

 set     XBARA_SEL18_SEL36           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL18_SEL36_0         BIT0
 set     XBARA_SEL18_SEL36_1         BIT1
 set     XBARA_SEL18_SEL36_2         BIT2
 set     XBARA_SEL18_SEL36_3         BIT3
 set     XBARA_SEL18_SEL36_4         BIT4

 set     XBARA_SEL18_SEL37           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL18_SEL37_0         BIT8
 set     XBARA_SEL18_SEL37_1         BIT9
 set     XBARA_SEL18_SEL37_2         BIT10
 set     XBARA_SEL18_SEL37_3         BIT11
 set     XBARA_SEL18_SEL37_4         BIT12

 set     XBARA_SEL19_SEL38           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL19_SEL38_0         BIT0
 set     XBARA_SEL19_SEL38_1         BIT1
 set     XBARA_SEL19_SEL38_2         BIT2
 set     XBARA_SEL19_SEL38_3         BIT3
 set     XBARA_SEL19_SEL38_4         BIT4

 set     XBARA_SEL19_SEL39           (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARA_SEL19_SEL39_0         BIT8
 set     XBARA_SEL19_SEL39_1         BIT9
 set     XBARA_SEL19_SEL39_2         BIT10
 set     XBARA_SEL19_SEL39_3         BIT11
 set     XBARA_SEL19_SEL39_4         BIT12

 set     XBARA_SEL20_SEL40           (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARA_SEL20_SEL40_0         BIT0
 set     XBARA_SEL20_SEL40_1         BIT1
 set     XBARA_SEL20_SEL40_2         BIT2
 set     XBARA_SEL20_SEL40_3         BIT3
 set     XBARA_SEL20_SEL40_4         BIT4

 set     XBARA_CTRL0_DEN0            BIT0
;;   DMA Enable for XBAR_OUT0
;;     0b0 ==> DMA disabled
;;     0b1 ==> DMA enabled

 set     XBARA_CTRL0_IEN0            BIT1
;;   Interrupt Enable for XBAR_OUT0
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     XBARA_CTRL0_EDGE0           (BIT2|BIT3)
;;   Active edge for edge detection on XBAR_OUT0
;;     0b00 ==> STS0 never asserts
;;     0b01 ==> STS0 asserts on rising edges of XBAR_OUT0
;;     0b10 ==> STS0 asserts on falling edges of XBAR_OUT0
;;     0b11 ==> STS0 asserts on rising and falling edges of XBAR_OUT0
 set     XBARA_CTRL0_EDGE0_0         BIT2
 set     XBARA_CTRL0_EDGE0_1         BIT3

 set     XBARA_CTRL0_STS0            BIT4
;;   Edge detection status for XBAR_OUT0
;;     0b0 ==> Active edge not yet detected on XBAR_OUT0
;;     0b1 ==> Active edge detected on XBAR_OUT0

 set     XBARA_CTRL0_DEN1            BIT8
;;   DMA Enable for XBAR_OUT1
;;     0b0 ==> DMA disabled
;;     0b1 ==> DMA enabled

 set     XBARA_CTRL0_IEN1            BIT9
;;   Interrupt Enable for XBAR_OUT1
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     XBARA_CTRL0_EDGE1           (BIT10|BIT11)
;;   Active edge for edge detection on XBAR_OUT1
;;     0b00 ==> STS1 never asserts
;;     0b01 ==> STS1 asserts on rising edges of XBAR_OUT1
;;     0b10 ==> STS1 asserts on falling edges of XBAR_OUT1
;;     0b11 ==> STS1 asserts on rising and falling edges of XBAR_OUT1
 set     XBARA_CTRL0_EDGE1_0         BIT10
 set     XBARA_CTRL0_EDGE1_1         BIT11

 set     XBARA_CTRL0_STS1            BIT12
;;   Edge detection status for XBAR_OUT1
;;     0b0 ==> Active edge not yet detected on XBAR_OUT1
;;     0b1 ==> Active edge detected on XBAR_OUT1

 set     XBARA_CTRL1_DEN2            BIT0
;;   DMA Enable for XBAR_OUT2
;;     0b0 ==> DMA disabled
;;     0b1 ==> DMA enabled

 set     XBARA_CTRL1_IEN2            BIT1
;;   Interrupt Enable for XBAR_OUT2
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     XBARA_CTRL1_EDGE2           (BIT2|BIT3)
;;   Active edge for edge detection on XBAR_OUT2
;;     0b00 ==> STS2 never asserts
;;     0b01 ==> STS2 asserts on rising edges of XBAR_OUT2
;;     0b10 ==> STS2 asserts on falling edges of XBAR_OUT2
;;     0b11 ==> STS2 asserts on rising and falling edges of XBAR_OUT2
 set     XBARA_CTRL1_EDGE2_0         BIT2
 set     XBARA_CTRL1_EDGE2_1         BIT3

 set     XBARA_CTRL1_STS2            BIT4
;;   Edge detection status for XBAR_OUT2
;;     0b0 ==> Active edge not yet detected on XBAR_OUT2
;;     0b1 ==> Active edge detected on XBAR_OUT2

 set     XBARA_CTRL1_DEN3            BIT8
;;   DMA Enable for XBAR_OUT3
;;     0b0 ==> DMA disabled
;;     0b1 ==> DMA enabled

 set     XBARA_CTRL1_IEN3            BIT9
;;   Interrupt Enable for XBAR_OUT3
;;     0b0 ==> Interrupt disabled
;;     0b1 ==> Interrupt enabled

 set     XBARA_CTRL1_EDGE3           (BIT10|BIT11)
;;   Active edge for edge detection on XBAR_OUT3
;;     0b00 ==> STS3 never asserts
;;     0b01 ==> STS3 asserts on rising edges of XBAR_OUT3
;;     0b10 ==> STS3 asserts on falling edges of XBAR_OUT3
;;     0b11 ==> STS3 asserts on rising and falling edges of XBAR_OUT3
 set     XBARA_CTRL1_EDGE3_0         BIT10
 set     XBARA_CTRL1_EDGE3_1         BIT11

 set     XBARA_CTRL1_STS3            BIT12
;;   Edge detection status for XBAR_OUT3
;;     0b0 ==> Active edge not yet detected on XBAR_OUT3
;;     0b1 ==> Active edge detected on XBAR_OUT3

 set     XBARB_SEL0_SEL0             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARB_SEL0_SEL0_0           BIT0
 set     XBARB_SEL0_SEL0_1           BIT1
 set     XBARB_SEL0_SEL0_2           BIT2
 set     XBARB_SEL0_SEL0_3           BIT3
 set     XBARB_SEL0_SEL0_4           BIT4

 set     XBARB_SEL0_SEL1             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARB_SEL0_SEL1_0           BIT8
 set     XBARB_SEL0_SEL1_1           BIT9
 set     XBARB_SEL0_SEL1_2           BIT10
 set     XBARB_SEL0_SEL1_3           BIT11
 set     XBARB_SEL0_SEL1_4           BIT12

 set     XBARB_SEL1_SEL2             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARB_SEL1_SEL2_0           BIT0
 set     XBARB_SEL1_SEL2_1           BIT1
 set     XBARB_SEL1_SEL2_2           BIT2
 set     XBARB_SEL1_SEL2_3           BIT3
 set     XBARB_SEL1_SEL2_4           BIT4

 set     XBARB_SEL1_SEL3             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARB_SEL1_SEL3_0           BIT8
 set     XBARB_SEL1_SEL3_1           BIT9
 set     XBARB_SEL1_SEL3_2           BIT10
 set     XBARB_SEL1_SEL3_3           BIT11
 set     XBARB_SEL1_SEL3_4           BIT12

 set     XBARB_SEL2_SEL4             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARB_SEL2_SEL4_0           BIT0
 set     XBARB_SEL2_SEL4_1           BIT1
 set     XBARB_SEL2_SEL4_2           BIT2
 set     XBARB_SEL2_SEL4_3           BIT3
 set     XBARB_SEL2_SEL4_4           BIT4

 set     XBARB_SEL2_SEL5             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARB_SEL2_SEL5_0           BIT8
 set     XBARB_SEL2_SEL5_1           BIT9
 set     XBARB_SEL2_SEL5_2           BIT10
 set     XBARB_SEL2_SEL5_3           BIT11
 set     XBARB_SEL2_SEL5_4           BIT12

 set     XBARB_SEL3_SEL6             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARB_SEL3_SEL6_0           BIT0
 set     XBARB_SEL3_SEL6_1           BIT1
 set     XBARB_SEL3_SEL6_2           BIT2
 set     XBARB_SEL3_SEL6_3           BIT3
 set     XBARB_SEL3_SEL6_4           BIT4

 set     XBARB_SEL3_SEL7             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARB_SEL3_SEL7_0           BIT8
 set     XBARB_SEL3_SEL7_1           BIT9
 set     XBARB_SEL3_SEL7_2           BIT10
 set     XBARB_SEL3_SEL7_3           BIT11
 set     XBARB_SEL3_SEL7_4           BIT12

 set     XBARB_SEL4_SEL8             (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARB_SEL4_SEL8_0           BIT0
 set     XBARB_SEL4_SEL8_1           BIT1
 set     XBARB_SEL4_SEL8_2           BIT2
 set     XBARB_SEL4_SEL8_3           BIT3
 set     XBARB_SEL4_SEL8_4           BIT4

 set     XBARB_SEL4_SEL9             (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARB_SEL4_SEL9_0           BIT8
 set     XBARB_SEL4_SEL9_1           BIT9
 set     XBARB_SEL4_SEL9_2           BIT10
 set     XBARB_SEL4_SEL9_3           BIT11
 set     XBARB_SEL4_SEL9_4           BIT12

 set     XBARB_SEL5_SEL10            (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARB_SEL5_SEL10_0          BIT0
 set     XBARB_SEL5_SEL10_1          BIT1
 set     XBARB_SEL5_SEL10_2          BIT2
 set     XBARB_SEL5_SEL10_3          BIT3
 set     XBARB_SEL5_SEL10_4          BIT4

 set     XBARB_SEL5_SEL11            (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARB_SEL5_SEL11_0          BIT8
 set     XBARB_SEL5_SEL11_1          BIT9
 set     XBARB_SEL5_SEL11_2          BIT10
 set     XBARB_SEL5_SEL11_3          BIT11
 set     XBARB_SEL5_SEL11_4          BIT12

 set     XBARB_SEL6_SEL12            (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARB_SEL6_SEL12_0          BIT0
 set     XBARB_SEL6_SEL12_1          BIT1
 set     XBARB_SEL6_SEL12_2          BIT2
 set     XBARB_SEL6_SEL12_3          BIT3
 set     XBARB_SEL6_SEL12_4          BIT4

 set     XBARB_SEL6_SEL13            (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARB_SEL6_SEL13_0          BIT8
 set     XBARB_SEL6_SEL13_1          BIT9
 set     XBARB_SEL6_SEL13_2          BIT10
 set     XBARB_SEL6_SEL13_3          BIT11
 set     XBARB_SEL6_SEL13_4          BIT12

 set     XBARB_SEL7_SEL14            (BIT0|BIT1|BIT2|BIT3|BIT4)
 set     XBARB_SEL7_SEL14_0          BIT0
 set     XBARB_SEL7_SEL14_1          BIT1
 set     XBARB_SEL7_SEL14_2          BIT2
 set     XBARB_SEL7_SEL14_3          BIT3
 set     XBARB_SEL7_SEL14_4          BIT4

 set     XBARB_SEL7_SEL15            (BIT8|BIT9|BIT10|BIT11|BIT12)
 set     XBARB_SEL7_SEL15_0          BIT8
 set     XBARB_SEL7_SEL15_1          BIT9
 set     XBARB_SEL7_SEL15_2          BIT10
 set     XBARB_SEL7_SEL15_3          BIT11
 set     XBARB_SEL7_SEL15_4          BIT12


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; Backward compatibility.

;; No backward compatibility issues.
