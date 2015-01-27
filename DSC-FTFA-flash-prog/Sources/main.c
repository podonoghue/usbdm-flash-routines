
//*******************************************************
// Note all addresses & sizes are in words (16 bits)
//*******************************************************

/*
  FTFA - Used for (MC56F82748 tested):
                 MC56F82723, MC56F82726, MC56F82728, MC56F82733, MC56F82736, MC56F82738, MC56F82743, MC56F82746, MC56F82748
                 MC56F82313, MC56F82716, MC56F82723
  
===============================================================================================================
| History                                                                                                      
---------------------------------------------------------------------------------------------------------------
| 19 Jan 2015 | Created                                                                           | V4.10.6.250
===============================================================================================================
*/

#include <stdint.h>

enum AddressModifiers {
   ADDRESS_DATA   = 1UL<<31,  //!< DATA (X:) memory (DSC)
   ADDRESS_LINEAR = 1UL<<31,  //!< Linear address (HCS12)
   ADDRESS_EEPROM = 1UL<<30,  //!< EEPROM
   ADDRESS_A23    = 1UL<<23   //!< A23 bit for Flex/DataFlash on ARM/CFV1+
} ;

// Target defines
//
#define FTFA 1

#if (TARGET == FTFA)   
#define CLOCK_CALIB (500553)              // 1 second count for a 4000 kHz sysclock speed MC56F82748 chip
#define ISOVERLAYED (CAP_DSC_OVERLAY)
#define COP_CTRL      (*(uint16_t *)0x00E320UL)
#define OCCS_OSCTL1   (*(uint16_t *)0x00E2B4UL)
#define SIM_NVMOPT2H  (*(uint16_t *)0x00E42CUL)
#else
#error "TARGET not defined"
#endif

#define FREQ_CALIB  (4000)   // Clock calibration frequency (kHz)

#define NV_SECURITY_ADDRESS            (0x00000400UL)
#define NV_FSEC_ADDRESS                (NV_SECURITY_ADDRESS+0x0C)
#define FTFA_FSEC_KEY_MASK              0xC0
#define FTFA_FSEC_KEY_ENABLE            0x80
#define FTFA_FSEC_KEY_DISABLE           0xC0
#define FTFA_FSEC_MEEN_MASK             0x30
#define FTFA_FSEC_MEEN_ENABLE           0x30
#define FTFA_FSEC_MEEN_DISABLE          0x20
#define FTFA_FSEC_FSLACC                0x0C
#define FTFA_FSEC_SEC_MASK              0x03
#define FTFA_FSEC_UNSEC                 0x02
#define FTFA_FSEC_SEC                   0x03

#ifndef NULL
#define NULL ((void*)0)
#endif

// Cache control
#define FMC_PFAPR                       (*(volatile uint32_t *)0x00DE00UL)
#define FMC_PFB0CR                      (*(volatile uint32_t *)0x00DE02UL)
#define FMC_PFB1CR                      (*(volatile uint32_t *)0x00DE04UL)

//#pragma pack(1)
typedef struct {
   uint8_t  fstat;
   uint8_t  fcnfg;
   uint8_t  fsec;
   uint8_t  fopt;
   uint32_t fccob3_0;
   uint32_t fccob7_4;
   uint32_t fccobB_8;
   uint32_t fprot3_0;
} FlashController;
//#pragma pack(0)

#define FLASH_CONTROLLER (*(FlashController *)0x0001C780UL)

#define FTFA_FSTAT_CCIF                 0x80
#define FTFA_FSTAT_RDCOLLERR            0x40
#define FTFA_FSTAT_ACCERR               0x20
#define FTFA_FSTAT_FPVIOL               0x10
#define FTFA_FSTAT_MGSTAT0              0x01

#define FTFA_FCNFG_CCIE                 0x80
#define FTFA_FCNFG_RDCOLLIE             0x40
#define FTFA_FCNFG_ERSAREQ              0x20
#define FTFA_FCNFG_ERSSUSP              0x10

#define FOPT_LPBOOTn                    0x01
#define FOPT_EZPORT                     0x02
   
// Flash commands
#define F_RD1SEC                        0x01UL
#define F_PGMCHK                        0x02UL
#define F_RDRSRC                        0x03UL
#define F_PGM4                          0x06UL
#define F_ERSSCR                        0x09UL
#define F_RD1ALL                        0x40UL
#define F_RDONCE                        0x41UL
#define F_PGMONCE                       0x43UL
#define F_ERSALL                        0x44UL
#define F_VFYKEY                        0x45UL

#define F_USER_MARGIN                   0x01UL // Use 'user' margin on flash verify
#define F_FACTORY_MARGIN                0x02UL // Use 'factory' margin on flash verify

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
void executeCommand(volatile FlashController *controller);
uint32_t fixAddress(uint32_t address);

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
   controller->fprot3_0 = 0xFFFFFFFFUL;  // Unprotect PFLASH
   
   // Disable flash caching
   FMC_PFB0CR  = 0x00000000;
   FMC_PFB1CR  = 0x00000000;

   flashData->flags &= ~DO_INIT_FLASH;
}

//! Launch & wait for Flash command to complete
//!
void executeCommand(volatile FlashController *controller) {
   // Clear any existing errors
   controller->fstat = FTFA_FSTAT_ACCERR|FTFA_FSTAT_FPVIOL;

   // Launch command
   controller->fstat = FTFA_FSTAT_CCIF;

   // Wait for command complete
   while ((controller->fstat & FTFA_FSTAT_CCIF) == 0) {
   }
   // Handle any errors
   if ((controller->fstat & FTFA_FSTAT_FPVIOL ) != 0) {
      setErrorCode(FLASH_ERR_PROG_FPVIOL);
   }
   if ((controller->fstat & FTFA_FSTAT_ACCERR ) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
   }
   if ((controller->fstat & FTFA_FSTAT_MGSTAT0 ) != 0) {
      setErrorCode(FLASH_ERR_PROG_MGSTAT0);
   }
}

/*
 * Converts Global WORD address to adjusted BYTE address required by flash operations
 * 
 * A[31] indicates X space
 * 
 */
uint32_t fixAddress(uint32_t address) {
   // Validate & convert to byte address
   if (address<=0x00007FFF) {
      // P:ROM region
      return address<<1;   
   }
   else if ((address>=0x80004000) && (address<=0x8000BFFF)) { 
      // X:ROM region - Map to PROM
      return ((address-0x80004000)<<1);   
   }
   // Not valid programmable memory
   setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
}

//! Erase entire flash block
//!
void eraseFlashBlock(void) {
   uint32_t         address;
   FlashData_t     *flashData = getHeader();
   FlashController *controller = flashData->controller;
   if ((flashData->flags&DO_ERASE_BLOCK) == 0) {
      return;
   }
   // Convert to byte address
   address        = fixAddress(flashData->address);

   if ((address & 0x03) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   // Erase block
   flashData->controller->fccob3_0 = (F_ERSALL << 24) | address;
   executeCommand(flashData->controller);
   flashData->flags &= ~DO_ERASE_BLOCK;
}

//! Program a range of flash from buffer
//!
void programRange(void) {
   uint32_t         address;
   const uint32_t  *dataAddress;
   uint16_t         numLongwords;
   
   FlashData_t     *flashData  = getHeader();
   if ((flashData->flags&DO_PROGRAM_RANGE) == 0) {
      return;
   }
   address        = fixAddress(flashData->address);
   dataAddress    = (uint32_t *)flashData->dataAddress;
   numLongwords   = flashData->dataSize>>1;
   
   if ((address & 0x03) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   // Program words
   while (numLongwords-- > 0) {
      if (address == (NV_FSEC_ADDRESS&~3)) {
         // Check for permanent secure value
         if ((*dataAddress & (FTFA_FSEC_MEEN_MASK)) == (FTFA_FSEC_MEEN_DISABLE)) {
            setErrorCode(FLASH_ERR_ILLEGAL_SECURITY);
         }
      }
      flashData->controller->fccob3_0 = (F_PGM4 << 24) | address;
      flashData->controller->fccob7_4 = *dataAddress++;
      executeCommand(flashData->controller);
      address += 4;
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
   uint32_t  sectorSize;
   uint32_t  pageMask;
   
   FlashData_t     *flashData  = getHeader();
   FlashController *controller = flashData->controller;
   if ((flashData->flags&DO_ERASE_RANGE) == 0) {
      return;
   }
   // Convert addresses to bytes
   address     = fixAddress(flashData->address);
   endAddress  = address + (flashData->dataSize<<1)-1; // Inclusive
   sectorSize  = flashData->sectorSize<<1;
   pageMask    = sectorSize-1U;
   
   // Check for empty range before block rounding
   if (flashData->dataSize == 0) {
      return;
   }
   // Round start address to start of block (inclusive)
   address &= ~pageMask;
   
   // Round end address to end of block (inclusive)
   endAddress |= pageMask;
   
   // Erase each sector
   while (address <= endAddress) {
      flashData->controller->fccob3_0 = (F_ERSSCR << 24) | address;
      executeCommand(flashData->controller);
      // Advance to start of next sector
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
#ifdef OCCS_OSCTL1
   // Trim oscillator
   // Note: Some chips have incorrect trim values
   OCCS_OSCTL1   = (OCCS_OSCTL1&~0x3FFFF)|(SIM_NVMOPT2H&0x3FFF);
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

