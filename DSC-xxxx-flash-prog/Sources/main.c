//*******************************************************
// Note all addresses & sizes are in words (16 bits)
//*******************************************************

/*
   This code is used with the following devices:
  
   DSC-56F8006-flash-prog.elf.S
      MC56F8002, MC56F8006

   DSC-56F8014-flash-prog.elf.S
      MC56F8011/13, /MC56F8014
      
   DSC-56F8023-flash-program.elf.S
      MC56F8023/33
      MC56F8025/35
      MC56F8036
      MC56F8027/37
      
   DSC-56F825X-flash-program.elf.S
      MC56F8245/46/47/55/56/57

   DSC-56F8323-flash-prog.elf.S
      MC56F8122/MC56F8322
      MC56F8123/MC56F8323
      MC56F8165/MC56F8365
	   
===============================================================================================================
| History                                                                                                      
---------------------------------------------------------------------------------------------------------------
| 19 Jan 2015 | Added factory clock trim                                                         | V4.10.6.250
===============================================================================================================
*/
typedef signed char int8_t;
typedef short int   int16_t;
typedef long int    int32_t;

typedef unsigned char		 uint8_t;
typedef unsigned short int  uint16_t;
typedef unsigned long int   uint32_t;

#ifndef NULL
#define NULL ((void*)0)
#endif

#define MC56F8006 1
#define MC56F8014 2
#define MC56F8023 3
#define MC56F825X 4 
#define MC56F8323 5

//#define DEBUG

enum AddressModifiers {
   ADDRESS_DATA   = 1UL<<31,  //!< DATA (X:) memory (DSC)
   ADDRESS_LINEAR = 1UL<<31,  //!< Linear address (HCS12)
   ADDRESS_EEPROM = 1UL<<30,  //!< EEPROM
   ADDRESS_A23    = 1UL<<23   //!< A23 bit for Flex/DataFlash on ARM/CFV1+
} ;

//==========================================================================================================
// Target defines
//
#if (TARGET == MC56F8006)   
#define CLOCK_CALIB (444039)               // 1 second count for a 4000 kHz sysclock speed MC568014 chip
#define ISOVERLAYED (CAP_DSC_OVERLAY)
#define  FM_OPT1      (*(uint16_t *) (0xF41B)) // Factory Flash trim
#define  OCCS_OCTRL   (*(uint16_t *) (0xF164)) // IRC Clock trim
#define  COP_CTRL     (*(uint16_t *) (0xF140)) // COP control
#elif (TARGET == MC56F8014)   
#define CLOCK_CALIB (444039)               // 1 second count for a 4000 kHz sysclock speed MC568014 chip
#define ISOVERLAYED (CAP_DSC_OVERLAY)
#define  FM_OPT1      (*(uint16_t *) (0xF41B)) // Factory Flash trim
#define  OCCS_OCTRL   (*(uint16_t *) (0xF0F5)) // IRC Clock trim
#define  COP_CTRL     (*(uint16_t *) (0xF0E0)) // COP control
#elif (TARGET == MC56F8023)   
#define CLOCK_CALIB (444039)               // 1 second count for a 4000 kHz sysclock speed MC568033 chip
#define ISOVERLAYED (CAP_DSC_OVERLAY)
#define  FM_OPT1      (*(uint16_t *) (0xF41B)) // Factory Flash trim
#define  OCCS_OCTRL   (*(uint16_t *) (0xF135)) // IRC Clock trim
#define  COP_CTRL     (*(uint16_t *) (0xF120)) // COP control
#elif (TARGET == MC56F825X)   
#define CLOCK_CALIB (444039)               // 1 second count for a 4000 kHz sysclock speed MC568245 chip
#define ISOVERLAYED (CAP_DSC_OVERLAY)
//#define  FM_OPT1      (*(uint16_t *) (0xF41A)) // Factory Flash trim - automatic trim
//#define  OCCS_OCTRL   (*(uint16_t *) (0xF135)) // IRC Clock trim
#define  COP_CTRL     (*(uint16_t *) (0xF110)) // COP control
#elif (TARGET == MC56F8323)   
#define CLOCK_CALIB (508214)               // 1 second count for a 4000 kHz sysclock speed MC568323 chip
#define ISOVERLAYED (0)
#define  FM_OPT1      (*(uint16_t *) (0xF41B)) // Factory Flash trim
#define  OCCS_OCTRL   (*(uint16_t *) (0xF2D5)) // IRC Clock trim
#define  COP_CTRL     (*(uint16_t *) (0xF2C0)) // COP control
#else
#error "TARGET not defined"
#endif

#ifdef DEBUG
#define CLK_DIV     (0x0A)
#define FTSR_BASE   (FlashController *)0x00F400
#endif

#define FREQ_CALIB  (4000)   // Clock calibration frequency (kHz)

#define NV_SECURITY_ADDRESS        (0xFF00)
#define NV_SEC_KEY_MASK            (3<<6)
#define NV_SEC_KEY_ENABLE          (2<<6)
#define NV_SEC_KEY_DISABLE         (1<<6)
#define NV_SEC_SEC_MASK            (3<<0)
#define NV_SEC_SECURE              (1<<0)
#define NV_SEC_UNSECURE            (2<<0)
#define NV_SEC_DEFAULT_UNSECURED   (NV_SEC_KEY_ENABLE|NV_SEC_UNSECURE)
#define NV_SEC_DEFAULT_SECURED     (NV_SEC_KEY_ENABLE|NV_SEC_SECURE)

typedef struct {
   volatile uint16_t  clkd;
   volatile uint16_t  cr;
   volatile uint16_t  pad1;
   volatile uint16_t  sech;
   volatile uint16_t  secl;
   volatile uint16_t  pad2[11];
   volatile uint16_t  prot;
   volatile uint16_t  protb;
   volatile uint16_t  pad3;
   volatile uint16_t  ustat;
   volatile uint16_t  cmd;
   volatile uint16_t  pad4[3];
   volatile uint16_t  dataAddress;
   volatile uint16_t  pad5;
   volatile uint16_t  opt0;
   volatile uint16_t  opt1;
   volatile uint16_t  pad6[2];
   volatile uint16_t  tst_sig;
} FlashController;

#define FSTAT_CBEIF    (1<<7)  //!< Command buffer empty
#define FSTAT_CCIF     (1<<6)  //!< Command complete
#define FSTAT_PVIOL    (1<<5)  //!< Protection violation
#define FSTAT_ACCERR   (1<<4)  //!< Access error
#define FSTAT_BLANK    (1<<2)  //!< Blank check OK

#define CFMCLKD_DIVLD   (1<<7)
#define CFMCLKD_PRDIV8  (1<<6)
#define CFMCLKD_FDIV    (0x3F)

// Flash commands
#define FCMD_PAGE_ERASE_VERIFY    (0x05)
#define FCMD_WORD_PROGRAM         (0x20)
#define FCMD_PAGE_ERASE           (0x40)
#define FCMD_MASS_ERASE           (0x41)

//==========================================================================================================
// Operation masks
//
//  The following combinations (amongst others) are sensible:
//  DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE - erase and check blank a range of memory
//  DO_PROGRAM_RANGE|DO_VERIFY_RANGE program & verify range assuming previously erased
//  DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE do all steps
//
#define DO_INIT_FLASH         (1<<0) // Do initialisation of flash
#define DO_ERASE_BLOCK        (1<<1) // Erase entire flash block e.g. Flash, FlexNVM etc
#define DO_ERASE_RANGE        (1<<2) // Erase range (including option region)
#define DO_BLANK_CHECK_RANGE  (1<<3) // Blank check region
#define DO_PROGRAM_RANGE      (1<<4) // Program range (including option region)
#define DO_VERIFY_RANGE       (1<<5) // Verify range
#define DO_PARTITION_FLEXNVM  (1<<7) // Program FlexNVM DFLASH/EEPROM partitioning
#define DO_TIMING_LOOP        (1<<8) // Counting loop to determine clock speed
// 9 - 14 reserved
#define IS_COMPLETE           (1<<15)

// Capability masks
#define CAP_ERASE_BLOCK        (1<<1)
#define CAP_ERASE_RANGE        (1<<2)
#define CAP_BLANK_CHECK_RANGE  (1<<3)
#define CAP_PROGRAM_RANGE      (1<<4)
#define CAP_VERIFY_RANGE       (1<<5)
#define CAP_PARTITION_FLEXNVM  (1<<7)
#define CAP_TIMING             (1<<8)

#define CAP_DSC_OVERLAY        (1<<11) // Indicates DSC code in pMEM overlays xRAM
#define CAP_DATA_FIXED         (1<<12) // Indicates TargetFlashDataHeader is at fixed address
#define CAP_RELOCATABLE        (1<<15)

// These error numbers are just for debugging
typedef enum {
     FLASH_ERR_OK                = (0),
     FLASH_ERR_LOCKED            = (1),  // Flash is still locked
     FLASH_ERR_ILLEGAL_PARAMS    = (2),  // Parameters illegal
     FLASH_ERR_PROG_FAILED       = (3),  // STM - Programming operation failed - general
     FLASH_ERR_PROG_WPROT        = (4),  // STM - Programming operation failed - write protected
     FLASH_ERR_VERIFY_FAILED     = (5),  // Verify failed
     FLASH_ERR_ERASE_FAILED      = (6),  // Erase or Blank Check failed
     FLASH_ERR_TRAP              = (7),  // Program trapped (illegal instruction/location etc.)
     FLASH_ERR_PROG_ACCERR       = (8),  // Kinetis/CFVx - Programming operation failed - ACCERR
     FLASH_ERR_PROG_FPVIOL       = (9),  // Kinetis/CFVx - Programming operation failed - FPVIOL
     FLASH_ERR_PROG_MGSTAT0      = (10), // Kinetis - Programming operation failed - MGSTAT0
     FLASH_ERR_CLKDIV            = (11), // CFVx - Clock divider not set
     FLASH_ERR_ILLEGAL_SECURITY  = (12), // Kinetis/CFV1+ - Illegal value for security location
     FLASH_ERR_UNKNOWN           = (13)  // Unspecified error
} FlashDriverError_t;

typedef void (*EntryPoint_t)(void);

// Describes a block to be programmed & result
typedef struct {
   uint16_t         flags;             // Controls actions of routine
   uint16_t         errorCode;         // Error code from action
   FlashController *controller;        // Ptr to flash controller
   uint16_t         frequency;         // Target frequency (kHz)
   uint16_t         sectorSize;        // Size of Flash memory sectors (smallest erasable block)
   uint32_t         address;           // Memory address being accessed
   uint16_t         dataSize;          // Size of memory range being accessed
   uint16_t         pad;
   const uint16_t  *dataAddress;       // Ptr to data to program
} FlashData_t;

// Timing information
typedef struct {
   uint16_t         flags;             // Controls actions of routine
   uint16_t         errorCode;         // Error code from action
   FlashController *controller;        // Ptr to flash controller
   uint32_t         timingCount;       // Timing count
} TimingData_t;

//! Describe the flash programming code
typedef struct {
   void           (*loadAddress)();    // 0  Address where to load this image
   EntryPoint_t     entry;             // 2  Ptr to entry routine
   uint16_t         capabilities;      // 4  Capabilities of routine
   uint16_t         calibFrequency;    // 5  Frequency used for calibFactor
   uint32_t         calibFactor;       // 6  Calibration factor for speed determination
   FlashData_t     *flashData;         // 8  Ptr to information about operation
} FlashProgramHeader_t;

#define FLASH_DATA_OFFSET 8

extern void asm_entry(void);
extern FlashData_t flashData;

extern void loadAddress();

#define CAPABILITIES (CAP_BLANK_CHECK_RANGE|CAP_ERASE_RANGE|CAP_ERASE_BLOCK|\
                      CAP_PROGRAM_RANGE|ISOVERLAYED|CAP_VERIFY_RANGE)

//! Flash programming command table
//!
const FlashProgramHeader_t flashProgramHeader = {
     /* loadAddress    */ loadAddress,                     // load address of image
     /* entry          */ asm_entry,                       // entry point for code
     /* capabilities   */ CAPABILITIES,
     /* calibFrequency */ FREQ_CALIB,
     /* clockFactor    */ CLOCK_CALIB,
     /* flashData      */ &flashData,
};

void  setErrorCode(uint16_t errorCode);
void  initFlash(void);
void  eraseFlashBlock(void);
void  programRange(void);
void  verifyRange(void);
void  eraseRange(void);
void  blankCheckRange(void);
void  asmTimingLoop(uint32_t *);
void  timingLoop();
void  doTiming();
void  entry(void);
void  testApp(void);

//! Get address of Header Block
//!
//! @return        (R2) - Address of header
//!
asm
static FlashData_t *getHeader(void) {
   move.l #>>flashProgramHeader,R0
   adda   #FLASH_DATA_OFFSET,R0  
   move.w P:(R0)+,A1
   move.w A1,A0
   move.w P:(R0)+,A1
   move.l A10,R2
   rts
}

//! @param address (A10[31])    - MemorySpace (0=>P, 1=>X)
//!                (A10[23:0])  - Address       
//!
//! @param data    (Y0)         - Data value to write
//!
asm
static void writeMemorySpace(uint32_t address, uint16_t data) {
   move.l      A10,R0
   bfclr       #0x8000,A1
   bcc         pMem
dMem:
   move.w      Y0,X:(R0)+  
   rts       
pMem:
   move.w      Y0,P:(R0)+  
   rts       
}

//! @param address (A10[31])    - MemorySpace (0=>P, 1=>X)
//!                (A10[23:0])  - Address       
//!
//! @return        (Y0)         - Data value read
//!
asm
static uint16_t readMemorySpace(uint32_t address) {
   move.l      A10,R0
   bfclr       #0x8000,A1
   bcc         pMem
dMem:
   move.w      X:(R0)+,Y0        
   rts
pMem:
   move.w      P:(R0)+,Y0        
   rts
}

//! Set error code & halt
//!
void setErrorCode(uint16_t errorCode) {
   FlashData_t *flashData = getHeader();
   flashData->errorCode   = errorCode;
   
   // Indicate completed
   flashData->flags |= IS_COMPLETE; 
   asm {
        debughlt
   }
}
  
//! Does any initialisation required before accessing the Flash
//!
void initFlash(void) {
   FlashData_t     *flashData = getHeader();
   FlashController *controller = flashData->controller;
   if ((flashData->flags&DO_INIT_FLASH) == 0) {
      return;
   }
#ifdef DEBUG
   controller->clkd  = CLK_DIV;
   controller->cr    = 0x00;  // 0 => Program or Boot flash, 1 => Data flash (8323)
   controller->prot  = 0x00;  // Unprotect flash
   controller->protb = 0x00;  // Unprotect boot flash
#endif   
   // Check if clock divider set
   if ((controller->clkd & CFMCLKD_DIVLD) == 0) {
      setErrorCode(FLASH_ERR_CLKDIV);
   }
   controller->cr = 0x00;
#if (TARGET == MC56F8323)   
   // Set flash bank select if DATA space
   if (flashData->address&ADDRESS_DATA) {
      controller->cr = 0x01;
   }
#endif
   flashData->flags &= ~DO_INIT_FLASH;
}

//! Erase entire flash block
//!
void eraseFlashBlock(void) {
   uint16_t         fstat;
   FlashData_t     *flashData = getHeader();
   FlashController *controller = flashData->controller;
   if ((flashData->flags&DO_ERASE_BLOCK) == 0) {
      return;
   }
   // Clear any existing errors (1 bit at a time)
   controller->ustat   = FSTAT_ACCERR;
   controller->ustat   = FSTAT_PVIOL;
   
   // Write dummy data to Flash
   writeMemorySpace(flashData->address, 0xFFFF);

   // Set command
   controller->cmd = FCMD_MASS_ERASE;

   // Launch command
   controller->ustat = FSTAT_CBEIF;
   asm {
      nop // allow FSTAT_CCIF to clear
      nop
      nop
      nop
   }
   // Wait for command complete
   do {
      fstat = controller->ustat;
   } while ((fstat&(FSTAT_CCIF|FSTAT_ACCERR|FSTAT_PVIOL)) == 0);
   if ((fstat & FSTAT_ACCERR ) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
   }
   if ((fstat & FSTAT_PVIOL ) != 0) {
      setErrorCode(FLASH_ERR_PROG_FPVIOL);
   }
   flashData->flags &= ~DO_ERASE_BLOCK;
}

//! Program a range of flash from buffer
//!
void programRange(void) {
   uint32_t         address;
   const uint16_t  *data;
   uint16_t         numWords;
   uint16_t         fstat;
   
   FlashData_t *flashData = getHeader();
   FlashController *controller = flashData->controller;
   if ((flashData->flags&DO_PROGRAM_RANGE) == 0) {
      return;
   }
   address    = flashData->address;
   data       = flashData->dataAddress;
   numWords   = flashData->dataSize;

   // Clear any existing errors (1 bit at a time)
   controller->ustat   = FSTAT_ACCERR;
   controller->ustat   = FSTAT_PVIOL;

   // Program words
   while (numWords-- > 0) {
      // Write data to flash P:address
      writeMemorySpace(address, *data);

      // Set command
      controller->cmd = FCMD_WORD_PROGRAM;

      // Launch command
      controller->ustat = FSTAT_CBEIF;
      asm {
         nop // allow FSTAT_CBEIF to clear
         nop
         nop
         nop
      }
      // Wait for buffer empty or error
      do {
         fstat = controller->ustat;
      } while ((fstat&(FSTAT_CBEIF|FSTAT_ACCERR|FSTAT_PVIOL)) == 0);
      if ((fstat & FSTAT_ACCERR) != 0)
         setErrorCode(FLASH_ERR_PROG_ACCERR);
      if ((fstat & FSTAT_PVIOL) != 0)
         setErrorCode(FLASH_ERR_PROG_FPVIOL);
      address++;
      data++;
   }
   // Wait for last command complete
   do {
      fstat = controller->ustat;
   } while ((fstat&(FSTAT_CCIF|FSTAT_ACCERR|FSTAT_PVIOL)) == 0);
   if ((fstat & FSTAT_ACCERR) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
   }
   if ((fstat & FSTAT_PVIOL) != 0) {
      setErrorCode(FLASH_ERR_PROG_FPVIOL);
   }
   flashData->flags &= ~DO_PROGRAM_RANGE;
}

//! Verify a range of flash against buffer
//!
void verifyRange(void) {
   uint32_t        address;
   const uint16_t *dataAddress;
   uint16_t        numWords;

   FlashData_t *flashData = getHeader();
   if ((flashData->flags&DO_VERIFY_RANGE) == 0) {
      return;
   }
   address      = (uint32_t)flashData->address;
   dataAddress  = flashData->dataAddress;
   numWords     = flashData->dataSize;

   // Verify words
   while (numWords-- > 0) {
      if (readMemorySpace(address++) != *dataAddress++) {
         setErrorCode(FLASH_ERR_VERIFY_FAILED);
      }
   }
   flashData->flags &= ~DO_VERIFY_RANGE;
}

//! Erase a range of flash
//!
void eraseRange(void) {
   uint32_t  address;
   uint32_t  endAddress;
   uint16_t  sectorSize;
   uint32_t  pageMask;
   uint16_t  fstat;
   
   FlashData_t     *flashData  = getHeader();
   FlashController *controller = flashData->controller;
   if ((flashData->flags&DO_ERASE_RANGE) == 0) {
      return;
   }
   address     = flashData->address;
   endAddress  = address + flashData->dataSize-1; // Inclusive
   sectorSize  = flashData->sectorSize;
   pageMask    = sectorSize-1U;
   
   // Check for empty range before block rounding
   if (flashData->dataSize == 0) {
      return;
   }
   // Round start address to start of block (inclusive)
   address &= ~pageMask;
   
   // Round end address to end of block (exclusive)
   endAddress += sectorSize;
   endAddress &= ~pageMask;
   
   // Clear any existing errors (1 bit at a time)
   controller->ustat   = FSTAT_ACCERR;
   controller->ustat   = FSTAT_PVIOL;

   // Erase each sector
   while (address != endAddress) {
      // Write dummy data to flash address
      writeMemorySpace(address, 0xFFFF);

      // Set command
      controller->cmd = FCMD_PAGE_ERASE;

      // Launch command
      controller->ustat = FSTAT_CBEIF;
      asm {
         nop // allow FSTAT_CCIF to set
         nop
         nop
         nop
      }
      // Wait for buffer empty
      do {
         fstat = controller->ustat;
      } while ((fstat&(FSTAT_CCIF|FSTAT_ACCERR|FSTAT_PVIOL)) == 0);
      if ((fstat & FSTAT_ACCERR) != 0) {
         setErrorCode(FLASH_ERR_PROG_ACCERR);
      }
      if ((fstat & FSTAT_PVIOL) != 0) {
         setErrorCode(FLASH_ERR_PROG_FPVIOL);
      }
      // Advance to start of next block
      address += sectorSize;
   }
   flashData->flags &= ~DO_ERASE_RANGE;
}

//! Check that a range of flash is blank (=0xFFFF)
//!
void blankCheckRange() {
   uint32_t     address;
   uint16_t     numWords;
   FlashData_t *flashData = getHeader();
   if ((flashData->flags&DO_BLANK_CHECK_RANGE) == 0) {
      return;
   }
   address      = flashData->address;
   numWords     = flashData->dataSize;

   while (numWords>0) {
      if (readMemorySpace(address) != 0xFFFF) {
         setErrorCode(FLASH_ERR_ERASE_FAILED);
      }
      numWords--;
      address++;
   }
   flashData->flags &= ~DO_BLANK_CHECK_RANGE;
}

asm
void asmTimingLoop(uint32_t *timingLocation) {
     // R2 = timingLocation
      move.l #0,Y
   loop:
      add.l  #1,Y
      move.l Y,X:(R2)
      bra loop
}

//!  Assembly counting loop
//!
void doTiming(void) {
   TimingData_t *flashData = (TimingData_t *)getHeader();
   if ((flashData->flags&DO_TIMING_LOOP) == 0) {
      return;
   }
   asmTimingLoop(&flashData->timingCount);
}

//! Main C entry point
//!
void entry(void) {
   FlashData_t *flashData = getHeader();

   // No errors so far - set error code to OK
   flashData->errorCode = FLASH_ERR_OK;
   
   // Indicate not complete
   flashData->flags &= ~IS_COMPLETE;
   
   if (flashData->controller == NULL) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   
#ifdef COP_CTRL
   //Disable COP
   COP_CTRL = 0x0000;
#endif
#ifdef OCCS_OCTRL
   // Trim oscillator
   // Note: Some chips have incorrect trim values
   OCCS_OCTRL  = (OCCS_OCTRL&~0x3FF) | (FM_OPT1&0x3FF);
#endif
   
   initFlash();
   doTiming();
   eraseFlashBlock();
   eraseRange();
   blankCheckRange();
   programRange();
   verifyRange();

   setErrorCode(FLASH_ERR_OK);
}

