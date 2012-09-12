#include <cstdint>

extern uint8_t __RAMBAR[];
extern uint8_t __FLASHBAR[];
extern uint8_t _vect[];

#ifndef NULL
#define NULL ((void*)0)
#endif

//#define DEBUG

//==========================================================================================================
// Target defines

#define CLOCK_CALIB (2084616) // 1 second count for a 25MHz Coldfire V2 chip

#define NV_SECURITY_ADDRESS        (0x00000400)
#define NV_SEC_KEYEN               (1<<31)
#define NV_SEC_SECSTAT             (1<<30)
#define NV_SEC_SECURE              (0x4AC8)
#define NV_SEC_UNSECURE            (0xFFFF)
#define NV_SEC_DEFAULT_UNSECURED   (NV_SEC_KEYEN|NV_SEC_UNSECURE)
#define NV_SEC_DEFAULT_SECURED     (NV_SEC_KEYEN|NV_SEC_SECURE)

#pragma pack(1)
typedef struct {
   uint16_t cfmmcr;
   uint8_t  cfmclkd;
   uint8_t  res1;
   uint32_t res2;
   uint32_t cfmsec;
   uint32_t res3;
   uint32_t cfmprot;
   uint32_t cfmsacc;
   uint32_t cfmdacc;
   uint32_t res4;
   uint8_t  cfmustat;
   uint8_t  res5[3];
   uint8_t  cfmcmd;
   uint8_t  res6[3];
   uint32_t res7[8];
   uint8_t  res8[2];
   uint16_t cfmclksel;
} FlashController;
#pragma pack(0)

#define CFMCLKD_DIVLD   (1<<7)
#define CFMCLKD_PRDIV8  (1<<6)
#define CFMCLKD_FDIV    (0x3F)

// Flash commands
#define CFMCMD_BLANK_CHECK          (0x05)
#define CFMCMD_PAGE_ERASE_VERIFY    (0x06)
#define CFMCMD_WORD_PROGRAM         (0x20)
#define CFMCMD_PAGE_ERASE           (0x40)
#define CFMCMD_MASS_ERASE           (0x41)

#define CFMUSTAT_CBEIF  (1<<7)
#define CFMUSTAT_CCIF   (1<<6)
#define CFMUSTAT_PVIOL  (1<<5)
#define CFMUSTAT_ACCERR (1<<4)
#define CFMUSTAT_BLANK  (1<<2)

#define PDDPAR       (*(uint32_t*)(0x00100074+IPSBASE)
#define SYNCR        (*(uint32_t*)(0x00120000+IPSBASE)

// Assume reset/init. value
#define IPSBASE       (0x40000000)
#define FLASHBACKDOOR (IPSBASE+0x04000000)
#define FLASHBASE     (0x00000000)

//==========================================================================================================
// Operation masks
//
//  The following combinations (amongst others) are sensible:
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

#define IS_COMPLETE           (1<<31)
                             
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
                               
#define CAP_RELOCATABLE        (1<<31)

#define ADDRESS_LINEAR (1UL<<31) // Indicate address is linear
#define ADDRESS_EEPROM (1UL<<30) // Indicate address lies within EEPROM

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

// This is the smallest unit of Flash that can be erased
#define FLASH_SECTOR_SIZE  (2*(1<<10)) // 2K block size (used for stride in erase)

typedef void (*EntryPoint_t)(void);
#pragma pack(1)
// Describes a block to be programmed & result
typedef struct {
   uint32_t         flags;             // Controls actions of routine
   uint16_t         errorCode;         // Error code from action
   uint16_t         sectorSize;        // Size of flash sectors (minimum erase size)
   uint32_t         res;
   FlashController *controller;        // Ptr to flash controller
   uint32_t         frequency;         // Target frequency (kHz)
   uint32_t         address;           // Memory address being accessed
   uint32_t         size;              // Size of memory range being accessed
   const uint32_t  *data;              // Ptr to data to program
} FlashData_t;

// Timing information
typedef struct {
   uint32_t         flags;             // Controls actions of routine
   uint16_t         errorCode;         // Error code from action
   uint16_t         res1;
   uint32_t         res2;
   uint32_t         timingCount;       // Timing count
} TimingData_t;
#define TIMING_FIELD_OFFSET 12

//! Describe the flash programming code
typedef struct {
   uint32_t         loadAddress;       // Address where to load this image
   EntryPoint_t     entry;             // Ptr to entry routine
   uint32_t         capabilities;      // Capabilities of routine
   uint16_t         reserved;  
   uint32_t         calibFactor;       // Calibration factor for speed determination
   FlashData_t     *flashData;         // Ptr to information about operation
} FlashProgramHeader_t;

#pragma pack(0)

asm void asm_entry(void);

//! Flash programming command table
//!
const FlashProgramHeader_t gFlashProgramHeader = {
     /* loadAddress  */ 0x20000000,        // load address of image
     /* entry        */ asm_entry,         // entry point for code
     /* capabilities */ CAP_BLANK_CHECK_RANGE|CAP_ERASE_RANGE|CAP_ERASE_BLOCK|CAP_PROGRAM_RANGE|CAP_VERIFY_RANGE|CAP_TIMING,
     /* reserved     */ 0x0,
     /* clockFactor  */ CLOCK_CALIB,       // Clock calibration
     /* flashData    */ NULL
};

void setErrorCode(int errorCode);
void initFlash(FlashData_t *flashData);
void eraseFlashBlock(FlashData_t *flashData);
void programRange(FlashData_t *flashData);
void verifyRange(FlashData_t *flashData);
void eraseRange(FlashData_t *flashData);
void blankCheckRange(FlashData_t *flashData);
void timingLoop(FlashData_t *flashData);
void asmTimingLoop();
void entry(void);
void isr_default(void);
void testApp(void);
asm void asm_testApp(void);

//! Set error code to return to BDM & halt
//!
void setErrorCode(int errorCode) {
   FlashData_t *flashData = gFlashProgramHeader.flashData;
   flashData->errorCode   = (uint16_t)errorCode;
   flashData->flags      |= IS_COMPLETE; 
   asm {
      halt
   }
}

//! Does any initialisation required before accessing the Flash
//!
void initFlash(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint8_t          cfmclkd;
   uint32_t         flashClk;
   uint32_t         frequency; /* kHz */
   
   if ((flashData->flags&DO_INIT_FLASH) == 0) {
      return;
   }
   // Calculate FCDIV value
   frequency  = flashData->frequency>>1;
   if (frequency < 150) {
      setErrorCode(FLASH_ERR_CLKDIV);
   }
   cfmclkd = CFMCLKD_DIVLD;
   if (frequency > 12800) {
      cfmclkd = CFMCLKD_DIVLD|CFMCLKD_PRDIV8;
      frequency = frequency>>3;
   }
   cfmclkd |= (frequency-1)/200;
   flashClk = frequency / ((cfmclkd&CFMCLKD_FDIV)+1);
   //   puts "cfmclkd = $cfmclkd, flashClk = $flashClk"
   if ((flashClk<150)||(flashClk>200)) {
      setErrorCode(FLASH_ERR_CLKDIV);
   }   
   controller->cfmclkd = (uint8_t)cfmclkd;
   
   // Check if clock divider correctly set
   if (controller->cfmclkd != cfmclkd) {
      setErrorCode(FLASH_ERR_CLKDIV);
   }
   controller->cfmprot = 0x00000000; // Unprotect Flash
   controller->cfmsacc = 0x00000000; // Allow user access
   controller->cfmdacc = 0x00000000; // Allow data and instruction access
   controller->cfmmcr  = 0x00000000; // Unlock
   
   flashData->flags &= ~DO_INIT_FLASH;
}

//! Erase entire flash array
//!
void eraseFlashBlock(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint32_t         address    = flashData->address;
   uint8_t          cfmustat;
   
   if ((flashData->flags&DO_ERASE_BLOCK) == 0) {
      return;
   }
   // Clear any existing errors
   controller->cfmustat = CFMUSTAT_ACCERR|CFMUSTAT_PVIOL;

   // Write any data to flash address via backdoor
   *(uint32_t*)(address-FLASHBASE+FLASHBACKDOOR) = 0xFFFFFFFF;
   
   // Set command
   controller->cfmcmd = CFMCMD_MASS_ERASE;

   // Launch command
   controller->cfmustat = CFMUSTAT_CBEIF;
   asm {
      nop // allow CFMUSTAT_CBEIF to clear
      nop
      nop
      nop
   }
   // Wait for command complete
   do {
      cfmustat = controller->cfmustat;
   } while ((cfmustat&(CFMUSTAT_CCIF|CFMUSTAT_ACCERR|CFMUSTAT_PVIOL)) == 0);
   if ((cfmustat & CFMUSTAT_ACCERR ) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
   }
   if ((cfmustat & CFMUSTAT_PVIOL ) != 0) {
      setErrorCode(FLASH_ERR_PROG_FPVIOL);
   }
   flashData->flags &= ~DO_ERASE_BLOCK;
}

//! Program a range of flash from buffer
//!
void programRange(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint32_t         address    = flashData->address;
   const uint32_t  *data       = flashData->data;
   uint32_t         numWords   = flashData->size/4;
   uint8_t          cfmustat;
   
   if ((flashData->flags&DO_PROGRAM_RANGE) == 0) {
      return;
   }
   if ((address & 0x03) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   // Clear any existing errors
   controller->cfmustat = CFMUSTAT_ACCERR|CFMUSTAT_PVIOL;

   // Program words
   while (numWords-- > 0) {
      // Write data to flash address via backdoor
      *(uint32_t*)(address-FLASHBASE+FLASHBACKDOOR) = *data;

      // Set command
      controller->cfmcmd = CFMCMD_WORD_PROGRAM;

      // Launch command
      controller->cfmustat = CFMUSTAT_CBEIF;
      asm {
         nop // allow CFMUSTAT_CBEIF to clear
         nop
         nop
         nop
      }
      // Wait for buffer empty
      do {
         cfmustat = controller->cfmustat;
      } while ((cfmustat&(CFMUSTAT_CBEIF|CFMUSTAT_ACCERR|CFMUSTAT_PVIOL)) == 0);
      if ((cfmustat & CFMUSTAT_ACCERR) != 0) {
         setErrorCode(FLASH_ERR_PROG_ACCERR);
      }
      if ((cfmustat & CFMUSTAT_PVIOL) != 0) {
         setErrorCode(FLASH_ERR_PROG_FPVIOL);
      }
      address += 4;
      data++;
   }
   // Wait for last command complete
   do {
      cfmustat = controller->cfmustat;
   } while ((cfmustat&(CFMUSTAT_CCIF|CFMUSTAT_ACCERR|CFMUSTAT_PVIOL)) == 0);
   if ((cfmustat & CFMUSTAT_ACCERR) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
   }
   if ((cfmustat & CFMUSTAT_PVIOL) != 0) {
      setErrorCode(FLASH_ERR_PROG_FPVIOL);
   }
   flashData->flags &= ~DO_PROGRAM_RANGE;
}

//! Verify a range of flash against buffer
//!
void verifyRange(FlashData_t *flashData) {
   uint32_t       *address   = (uint32_t *)flashData->address;
   const uint32_t *data      = flashData->data;
   uint32_t        numWords  = flashData->size/4;
   
   if ((flashData->flags&DO_VERIFY_RANGE) == 0) {
      return;
   }
   if (((uint32_t)address & 0x03) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   // Verify words
   while (numWords-- > 0) {
      if (*address++ != *data++)
         setErrorCode(FLASH_ERR_VERIFY_FAILED);
   }
   flashData->flags &= ~DO_VERIFY_RANGE;
}

//! Erase a range of flash
//!
void eraseRange(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint32_t address     = flashData->address;
   uint32_t endAddress  = address + flashData->size - 1; // Inclusive
   uint32_t pageMask    = flashData->sectorSize-1U;
   uint8_t  cfmustat;
   
   if ((flashData->flags&DO_ERASE_RANGE) == 0) {
      return;
   }
   // Check for empty range before block rounding
   if (flashData->size == 0) {
      return;
   }
   // Validate sector size
   if (flashData->sectorSize == 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   // Round start address to start of block (inclusive)
      address &= ~pageMask;
   // Round end address to end of block (inclusive)
      endAddress |= pageMask;
   
   // Clear any existing errors
   controller->cfmustat = CFMUSTAT_ACCERR|CFMUSTAT_PVIOL|CFMUSTAT_BLANK;

   // Erase each block/page
   while (address <= endAddress) {
      // Write dummy data to flash address via backdoor
      *(uint32_t*)(address-FLASHBASE+FLASHBACKDOOR) = 0xFFFFFFFF;
      
      // Set command
      controller->cfmcmd = CFMCMD_PAGE_ERASE;

      // Launch command
      controller->cfmustat = CFMUSTAT_CBEIF;
      asm {
         nop // allow CFMUSTAT_CBEIF to clear
         nop
         nop
         nop
      }
      // Wait for buffer empty
      do {
         cfmustat = controller->cfmustat;
      } while ((cfmustat&(CFMUSTAT_CCIF|CFMUSTAT_ACCERR|CFMUSTAT_PVIOL)) == 0);
      if ((cfmustat & CFMUSTAT_ACCERR) != 0) {
         setErrorCode(FLASH_ERR_PROG_ACCERR);
      }
      if ((cfmustat & CFMUSTAT_PVIOL) != 0) {
         setErrorCode(FLASH_ERR_PROG_FPVIOL);
      }
      // Advance to start of next block
      address += flashData->sectorSize;
   }
   flashData->flags &= ~DO_ERASE_RANGE;
}

//! Check that a range of flash is blank (=0xFFFF)
//!
void blankCheckRange(FlashData_t *flashData) {
   uint32_t address  = flashData->address;
   uint32_t numWords = (flashData->size+3)/4;

   if ((flashData->flags&DO_BLANK_CHECK_RANGE) == 0) {
      return;
   }
   if ((address & 0x03) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   while (numWords>0) {
      if (*(uint32_t*)address != 0xFFFFFFFF) {
         setErrorCode(FLASH_ERR_ERASE_FAILED);
      }
      numWords--;
      address += 4;
   }
   flashData->flags &= ~DO_BLANK_CHECK_RANGE;
}

//! Execute endless counting loop for target speed calibration
//!
//!  Any changes require CLOCK_CALIB to be altered
//!
__declspec(register_abi)
asm void asmTimingLoop() {
      move.l  gFlashProgramHeader.flashData,a0
      add.l   #TIMING_FIELD_OFFSET,a0
      moveq.l #0,d0
   loop:
      addq.l  #1,d0
      move.l  d0,(a0)
      bra.s   loop
}

//! Execute endless counting loop for target speed calibration
//!
void timingLoop(FlashData_t *flashData) {
   if ((flashData->flags&DO_TIMING_LOOP) == 0) {
      return;
   }
   asmTimingLoop();
}

//! Minimal vector table
extern uint32_t __vector_table[];

//! Some stack space
#pragma define_section stack ".stack" far_abs R
static __declspec(stack) uint16_t stackSpace[100];
extern uint32_t _stacktop[];

//! Main C entry point
//! 
//! Assumes ramBuffer is set up beforehand
//!
void entry(void) {
   FlashData_t *flashData;  // Handle on programming data

   // Handle on programming data
   flashData = gFlashProgramHeader.flashData;

   // Indicate not complete
   flashData->flags &= ~IS_COMPLETE;
   
   // No errors so far
   flashData->errorCode = FLASH_ERR_OK;
   
   timingLoop(flashData);

   if (flashData->controller == NULL) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   initFlash(flashData);
   eraseFlashBlock(flashData);
   eraseRange(flashData);
   blankCheckRange(flashData);
   programRange(flashData);
   verifyRange(flashData);
   
   // Indicate completed
   setErrorCode(FLASH_ERR_OK);
}

//! Default unexpected interrupt handler
//!
void isr_default(void) {
   setErrorCode(FLASH_ERR_TRAP);
}

//! Low level entry point
//! 
__declspec(register_abi)
asm void asm_entry(void) {

   // Disable interrupts
   move.w   #0x2700,sr
   
#ifndef DEBUG
   // Setup the stack before we attempt anything else
   move.l   #_stacktop,d0
   move.l   d0,sp
   clr.l    -(sp)
   move.l   #0,a6
#endif
   
   // Initialise Vector Base Reg
   move.l   #_vect,d0
   movec    d0,VBR

   // Initialise RAM base register
   move.l   #__RAMBAR + 0x21,d0
   movec    d0,RAMBAR;

   // Initialise Flash base register 
   move.l   #__FLASHBAR + 0x21,d0
   movec    d0,FLASHBAR;

   jmp     entry
}

#ifndef DEBUG
__declspec(register_abi)
void asm_testApp(void) {
}
#else
#define TEST 7
#if TEST == 1
// Programming general flash
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ (FlashController*)(0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000800,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#elif TEST == 2
// Mass erase + Unlock flash
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_UNLOCK_FLASH|DO_ERASE_BLOCK,
   /* controller */ (FlashController*)(0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 3
// Lock Flash 
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_LOCK_FLASH,
   /* controller */ (FlashController*)(0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 4
// Lock Flash 
static const FlashData_t flashdataA = {
   /* flags      */ DO_TIMING_LOOP,
   /* controller */ (FlashController*)(0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 5
// Set erasing ranges
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* controller */ (0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000000,
   /* size       */ 0x416,
};
#define DO_B
// Set erasing ranges
static const FlashData_t flashdataB = {
   /* flags      */ DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* controller */ (FlashController*)(0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000500,
   /* size       */ 0x0C3A-0x0500,
};
#elif TEST == 6
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF}; 
// Mass erase + Unlock flash
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_UNLOCK_FLASH|DO_ERASE_BLOCK,
   /* controller */ (FlashController *)(0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000000,
   /* size       */ 0,
   /* data       */ 0,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ (FlashController *)(0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000800,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ (FlashController *)(0x001D0000+IPSBASE),
   /* frequency  */ 25000, /* nominally 25MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000900,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#elif TEST == 7
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF}; 
// Mass erase + Unlock flash
static const FlashData_t flashdataA = {
   /* flags      */ DO_TIMING_LOOP,
   /* controller */ NULL,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* res        */ 0,
   /* address    */ 0,
   /* size       */ 0,
   /* data       */ 0,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#endif

//! Dummy test program for debugging
void testApp(void) {
   FlashProgramHeader_t *fph = (FlashProgramHeader_t*) &gFlashProgramHeader;
   
   fph->flashData = (FlashData_t *)&flashdataA;
   fph->entry();
#ifdef DO_B
   fph->flashData = (FlashData_t *)&flashdataB;
   fph->entry();
#endif
#ifdef DO_C
   fph->flashData = (FlashData_t *)&flashdataC;
   fph->entry();
#endif
#ifdef DO_D
   fph->flashData = (FlashData_t *)&flashdataD;
   fph->entry();
#endif
#ifdef DO_E
   fph->flashData = (FlashData_t *)&flashdataE;
   fph->entry();
#endif
   asm {
      halt
   }
}

//!
//!
__declspec(register_abi)
asm void asm_testApp(void) {
   // Disable interrupts
   move.w        #0x2700,sr
   
   // Setup the stack before we attempt anything else
   move.l   #_stacktop,d0
   move.l   d0,sp
   clr.l    -(sp)
   move.l   #0,a6
   
   // Initialise Vector Base Reg
   move.l   #_vect,d0
   movec    d0,VBR

   // Initialise RAMBAR
   move.l   #__RAMBAR + 0x21,d0
   movec    d0,RAMBAR;

   // Initialise ROMBAR/FLASHBAR
   move.l   #__FLASHBAR + 0x61,d0
   movec    d0,FLASHBAR;

   jmp     testApp
}
#endif
