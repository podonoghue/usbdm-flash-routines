#include <cstdint>

extern uint8_t __RAMBAR[];
extern uint8_t __FLASHBAR[];
extern uint8_t _vect[];

#ifndef NULL
#define NULL ((void*)0)
#endif

//#define DEBUG

//! Structure for security info in flash
typedef struct {
   uint8_t   backdoorKey[8];
   uint32_t  fProt;
   uint32_t  fSacc;
   uint32_t  fDacc;
   uint32_t  fSec;
   uint8_t   res[8];
} secStruct_t;

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
//  DO_MASS_ERASE|DO_UNLOCK_FLASH - erase all flash and program default unsecured value
//  DO_ERASE_RANGE|DO_UNLOCK_FLASH - erase security area only and program default unsecured value
//  DO_LOCK_FLASH - program default secured value, assuming security area has been previously erased
//  DO_ERASE_RANGE|DO_LOCK_FLASH - erase security area and program default secured value
//  DO_PROGRAM_RANGE|DO_VERIFY_RANGE program & verify range assuming previously erased
//  DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE do all steps
//
#define DO_INIT_FLASH         (1<<0) // Do initialisation of flash 
#define DO_MASS_ERASE         (1<<1) // Mass erase flash array
#define DO_ERASE_RANGE        (1<<2) // Erase range (including option region)
#define DO_BLANK_CHECK_RANGE  (1<<3) // Blank check region
#define DO_PROGRAM_RANGE      (1<<4) // Program range (including option region)
#define DO_VERIFY_RANGE       (1<<5) // Verify range
#define DO_UNLOCK_FLASH       (1<<6) // Unlock flash with default security options  (+mass erase if needed)
#define DO_LOCK_FLASH         (1<<7) // Lock flash with default security options
#define DO_MISC_OP            (1<<8) // Counting loop to determine clock speed
#define DO_MISC_OFFSET        (4)
#define DO_MISC_MASK          (0x1F<<DO_MISC_OFFSET)           // Bits 8..4 incl.
#define DO_TIMING_LOOP        (DO_MISC_OP|(0<<DO_MISC_OFFSET)) // Do timing loop

// 9 - 15 reserved
// 16-23 target/family specific
// Allows programming/erasing Option region, +DO_INIT_FLASH+DO_PROGRAM_RANGE+DO_ERASE_RANGE
#define DO_MODIFY_OPTION      (1<<16) 
// 24-29 reserved

#define NEED_RESET          (1<<30)
#define IS_COMPLETE         (1<<31)

// Capability masks
#define CAP_MASS_ERASE      (1<<1)
#define CAP_ERASE_RANGE     (1<<2)
#define CAP_BLANK_CHECK     (1<<3)
#define CAP_PROGRAM_RANGE   (1<<4)
#define CAP_VERIFY_RANGE    (1<<5)
#define CAP_UNLOCK_FLASH    (1<<6)
#define CAP_TIMING          (1<<7)
//
#define CAP_ALIGN_MASK      (3<<28)
#define CAP_ALIGN_BYTE      (0<<28)
#define CAP_ALIGN_2BYTE     (1<<28)
#define CAP_ALIGN_4BYTE     (2<<28)
#define CAP_RELOCATABLE     (1<<31)

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
     FLASH_ERR_ILLEGAL_SECURITY  = (12), // Kinetis - Illegal value for security location
     FLASH_ERR_UNKNOWN           = (13) // Unspecified error
} FlashDriverError_t;

// This is the smallest unit of Flash that can be erased
#define FLASH_SECTOR_SIZE  (2*(1<<10)) // 2K block size (used for stride in erase)

typedef void (*EntryPoint_t)(void);

// Describes a block to be programmed & result
typedef struct {
   uint32_t         flags;             // Controls actions of routine
   FlashController *controller;        // Ptr to flash controller
   uint32_t         frequency;         // Target frequency (kHz)
   uint16_t         errorCode;         // Error code from action
   uint16_t         sectorSize;        // Size of flash sectors (minimum erase size)
   uint32_t         address;           // Memory address being accessed
   uint32_t         size;              // Size of memory range being accessed
   const uint32_t  *data;              // Ptr to data to program
} FlashData_t;

// Timing information
typedef struct {
   uint32_t         flags;             // Controls actions of routine
   FlashController *controller;        // Ptr to flash controller
   uint32_t         frequency;         // Target frequency (kHz)
   uint16_t         errorCode;         // Error code from action
   uint16_t         res1;
   uint32_t         timingCount;       // Timing count
   uint32_t         res2; 
} TimingData_t;
#define TIMING_FIELD_OFFSET 16

//! Describe the flash programming code
typedef struct {
   uint32_t         loadAddress;       // Address where to load this image
   EntryPoint_t     entry;             // Ptr to entry routine
   uint32_t         capabilities;      // Capabilities of routine
// uint8_t          reserved[32];      // Reserved for target specific use, values may be copied from XML
   uint16_t         reserved1;
   uint16_t         reserved2;
   uint32_t         clockFactor;       // Clock calibration factor
   uint8_t          reserved3[24];     // Reserved for future programmer use 
   FlashData_t     *flashData;         // Ptr to information about operation
   secStruct_t      secure;            // Flash data for secure
} FlashProgramHeader_t;

__declspec(register_abi)
asm void asm_entry(void);

//! Flash programming command table
//!
const FlashProgramHeader_t flashProgramHeader = {
     /* loadAddress  */ 0x20000000,        // load address of image
     /* entry        */ asm_entry,         // entry point for code
     /* capabilities */ CAP_BLANK_CHECK|CAP_ERASE_RANGE|CAP_MASS_ERASE|CAP_PROGRAM_RANGE|CAP_VERIFY_RANGE|CAP_UNLOCK_FLASH|CAP_TIMING|CAP_ALIGN_4BYTE,
     /* reserved     */ 0x0,
     /* reserved     */ 0x0,
     /* clockFactor  */ CLOCK_CALIB,       // Clock calibration
     /* reserved     */ {0x0},
     /* flashData    */ NULL,
     /* secure       */ {{0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08},0xFFFFFFFF,0xFFFFFFFF,0xFFFFFFFF,NV_SEC_DEFAULT_SECURED},
};

int setErrorCode(int errorCode);
void clearErrorCode(void);
int initFlash(FlashData_t *flashData);
int massEraseFlash(FlashData_t *flashData);
int programRange(FlashData_t *flashData);
int verifyRange(FlashData_t *flashData);
int eraseRange(FlashData_t *flashData);
int blankCheckRange(FlashData_t *flashData);
int unlockFlash(FlashData_t *);
int lockFlash(FlashData_t *flashData);
asm void asmTimingLoop(void);
int timingLoop();
int doMiscOperations(FlashData_t *flashData);
void entry(void);
void isr_default(void);
void testApp(void);
asm void asm_testApp(void);

//! Set error code to return to BDM
//!
int setErrorCode(int errorCode) {
   FlashData_t *flashData = flashProgramHeader.flashData;
   if (flashData->errorCode == FLASH_ERR_OK) {
      flashData->errorCode = (uint16_t)errorCode;
   }
   return flashData->errorCode;
}

//! Set error code to OK
//!
void clearErrorCode(void) {
   flashProgramHeader.flashData->errorCode = FLASH_ERR_OK;
}

//! Does any initialisation required before accessing the Flash
//!
int initFlash(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint8_t          cfmclkd;
   uint32_t         flashClk;
   uint32_t         frequency; /* kHz */
   
   if ((flashData->flags&DO_INIT_FLASH) == 0)
      return FLASH_ERR_OK;

   // Calculate FCDIV value
   frequency  = flashData->frequency>>1;
   if (frequency < 150) {
      return setErrorCode(FLASH_ERR_CLKDIV);
   }
   cfmclkd = CFMCLKD_DIVLD;
   if (frequency > 12800) {
      cfmclkd = CFMCLKD_DIVLD|CFMCLKD_PRDIV8;
      frequency = frequency>>3;
   }
   cfmclkd |= (frequency-1)/200;
   flashClk = frequency / ((cfmclkd&CFMCLKD_FDIV)+1);
   if ((flashClk<150)||(flashClk>200)) {
      return setErrorCode(FLASH_ERR_CLKDIV);
      }   
   controller->cfmclkd = (uint8_t)cfmclkd;
   
   // Check if clock divider correctly set
   if (controller->cfmclkd != cfmclkd)
      return setErrorCode(FLASH_ERR_CLKDIV);
   
   controller->cfmprot = 0x00000000; // Unprotect Flash
   controller->cfmsacc = 0x00000000; // Allow user access
   controller->cfmdacc = 0x00000000; // Allow data and instruction access
   controller->cfmmcr  = 0x00000000; // Unlock
   
   flashData->flags &= ~DO_INIT_FLASH;
   return FLASH_ERR_OK;
}

//! Erase entire flash array
//!
int massEraseFlash(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint32_t         address    = flashData->address;
   uint8_t          cfmustat;
   
   if ((flashData->flags&DO_MASS_ERASE) == 0)
      return FLASH_ERR_OK;

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
   if ((cfmustat & CFMUSTAT_ACCERR ) != 0)
      return setErrorCode(FLASH_ERR_PROG_ACCERR);
   if ((cfmustat & CFMUSTAT_PVIOL ) != 0)
      return setErrorCode(FLASH_ERR_PROG_FPVIOL);

   flashData->flags &= ~DO_MASS_ERASE;
   return FLASH_ERR_OK;
}

//! Program a range of flash from buffer
//!
int programRange(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint32_t         address    = flashData->address;
   const uint32_t  *data       = flashData->data;
   uint32_t         numWords   = flashData->size/4;
   uint8_t          cfmustat;
   
   if ((flashData->flags&DO_PROGRAM_RANGE) == 0)
      return FLASH_ERR_OK;
   
   if ((address & 0x03) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

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
      if ((cfmustat & CFMUSTAT_ACCERR) != 0)
         return setErrorCode(FLASH_ERR_PROG_ACCERR);
      if ((cfmustat & CFMUSTAT_PVIOL) != 0)
         return setErrorCode(FLASH_ERR_PROG_FPVIOL);
      address += 4;
      data++;
   }
   // Wait for last command complete
   do {
      cfmustat = controller->cfmustat;
   } while ((cfmustat&(CFMUSTAT_CCIF|CFMUSTAT_ACCERR|CFMUSTAT_PVIOL)) == 0);
   if ((cfmustat & CFMUSTAT_ACCERR) != 0)
      return setErrorCode(FLASH_ERR_PROG_ACCERR);
   if ((cfmustat & CFMUSTAT_PVIOL) != 0)
      return setErrorCode(FLASH_ERR_PROG_FPVIOL);

   flashData->flags &= ~DO_PROGRAM_RANGE;
   return FLASH_ERR_OK;
}

//! Verify a range of flash against buffer
//!
int verifyRange(FlashData_t *flashData) {
   uint32_t       *address   = (uint32_t *)flashData->address;
   const uint32_t *data      = flashData->data;
   uint32_t        numWords  = flashData->size/4;
   
   if ((flashData->flags&DO_VERIFY_RANGE) == 0)
      return FLASH_ERR_OK;

   if (((uint32_t)address & 0x03) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

   // Verify words
   while (numWords-- > 0) {
      if (*address++ != *data++)
         return setErrorCode(FLASH_ERR_VERIFY_FAILED);
   }
   flashData->flags &= ~DO_VERIFY_RANGE;
   return FLASH_ERR_OK;
}

//! Erase a range of flash
//!
int eraseRange(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint32_t address     = flashData->address;
   uint32_t endAddress  = address + flashData->size - 1; // Inclusive
   uint32_t pageMask    = flashData->sectorSize-1U;
   uint8_t  cfmustat;
   
   if ((flashData->flags&DO_ERASE_RANGE) == 0)
      return FLASH_ERR_OK;
   
   // Check for empty range before block rounding
   if (flashData->size == 0)
      return FLASH_ERR_OK;

   // Validate sector size
   if (flashData->sectorSize == 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

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
      if ((cfmustat & CFMUSTAT_ACCERR) != 0)
         return setErrorCode(FLASH_ERR_PROG_ACCERR);
      if ((cfmustat & CFMUSTAT_PVIOL) != 0)
         return setErrorCode(FLASH_ERR_PROG_FPVIOL);
      // Advance to start of next block
      address += flashData->sectorSize;
   }
   flashData->flags &= ~DO_ERASE_RANGE;
   return FLASH_ERR_OK;
}

//! Check that a range of flash is blank (=0xFFFF)
//!
int blankCheckRange(FlashData_t *flashData) {
   uint32_t address  = flashData->address;
   uint32_t numWords = (flashData->size+3)/4;

   if ((flashData->flags&DO_BLANK_CHECK_RANGE) == 0)
      return FLASH_ERR_OK;
   
   if ((address & 0x03) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

   while (numWords>0) {
      if (*(uint32_t*)address != 0xFFFFFFFF)
         return setErrorCode(FLASH_ERR_ERASE_FAILED);
      numWords--;
      address += 4;
   }
   flashData->flags &= ~DO_BLANK_CHECK_RANGE;
   return FLASH_ERR_OK;
}

//! Unlock the flash by programming the Option Flash
//! region to a default value (all flash unprotected)
//!
//! Note: The page should be erased either beforehand or
//! by combining with the DO_ERASE_RANGE option. 
//! (There may be collateral damage to the rest of the page!)
//!
int unlockFlash(FlashData_t *flashData) {
   if ((flashData->flags&DO_UNLOCK_FLASH) == 0)
      return FLASH_ERR_OK;

   if ((flashData->flags&(DO_PROGRAM_RANGE|DO_LOCK_FLASH|DO_MISC_OP)) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   
   // Not supported - 
   // It is not possible to (safely) program unsecured value - requires erase
   // with collateral damage
   flashData->flags  &= ~(DO_UNLOCK_FLASH|DO_ERASE_RANGE);
   return FLASH_ERR_OK;
}

//! Lock the flash by programming the Option Flash
//! region to a default secured value (all flash protected)
//!
//! Note: The page should be erased either beforehand or
//! by combining with the DO_ERASE_RANGE option. 
//! (There may be collateral damage to the rest of the page!)
//!
int lockFlash(FlashData_t *flashData) {
   if ((flashData->flags&DO_LOCK_FLASH) == 0)
      return FLASH_ERR_OK;

   if ((flashData->flags&(DO_PROGRAM_RANGE|DO_UNLOCK_FLASH|DO_MISC_OP)) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   
   // Programming values to Security region
   flashData->address = NV_SECURITY_ADDRESS;
   flashData->data    = (uint32_t *)&flashProgramHeader.secure;
   flashData->size    = sizeof(flashProgramHeader.secure);
   flashData->flags  |= DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE;
   flashData->flags  &= ~DO_LOCK_FLASH;

   return FLASH_ERR_OK;
}

//!  Assembly counting loop
//!  Any changes require CLOCK_CALIB to be altered
//!
__declspec(register_abi)
asm void asmTimingLoop(void) {
      move.l  flashProgramHeader.flashData,a0
      add.l   #TIMING_FIELD_OFFSET,a0
      moveq.l #0,d0
   loop:
      addq.l  #1,d0
      move.l  d0,(a0)
      bra.s   loop
}

//! Execute endless counting loop for target speed calibration
//!
int timingLoop() {
   asmTimingLoop();
   return FLASH_ERR_OK;
}

//! Do miscellaneous operations
//!
int doMiscOperations(FlashData_t *flashData) {
   int rc;
   if ((flashData->flags&DO_MISC_OP) == 0)
      return FLASH_ERR_OK;

   switch ((flashData->flags&DO_MISC_MASK)) {
      case DO_TIMING_LOOP :    
         rc = timingLoop();
         break;
      default: 
         rc = FLASH_ERR_ILLEGAL_PARAMS;
         break;
   }
   if (rc != FLASH_ERR_OK)
      return setErrorCode(rc);
   
   flashData->flags &= ~DO_MISC_MASK;
   return FLASH_ERR_OK;
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
   flashData = flashProgramHeader.flashData;

   // Indicate not complete
   flashData->flags &= ~IS_COMPLETE;
   
   // No errors so far
   clearErrorCode();
   
   if (flashData->controller == NULL) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
      // Indicate completed
      flashData->flags |= IS_COMPLETE; 
      return;
   }

#ifndef DEBUG
   // Execute in order with early abort
   // Each routine returns FLASH_ERR_OK (0) on success
   !initFlash(flashData)          &&
   !doMiscOperations(flashData)   &&
   !unlockFlash(flashData)        &&
   !lockFlash(flashData)          &&
   !massEraseFlash(flashData)     &&
   !eraseRange(flashData)         &&
   !blankCheckRange(flashData)    &&
   !programRange(flashData)       &&
   !verifyRange(flashData)        ;
#else
   // Easier to debug
   initFlash(flashData);
   doMiscOperations(flashData);
   unlockFlash(flashData);
   lockFlash(flashData);
   massEraseFlash(flashData);
   eraseRange(flashData);
   blankCheckRange(flashData);
   programRange(flashData);
   verifyRange(flashData);
#endif
   // Indicate completed
   flashData->flags |= IS_COMPLETE; 
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

   jsr     entry
#ifndef DEBUG
   halt
#else
   rts
#endif
}

//! Default unexpected interrupt handler
//!
void isr_default(void) {
   setErrorCode(FLASH_ERR_TRAP);
   flashProgramHeader.flashData->flags |= IS_COMPLETE; 
   asm {
      halt
   }
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
   /* flags      */ DO_INIT_FLASH|DO_UNLOCK_FLASH|DO_MASS_ERASE,
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
   /* flags      */ DO_INIT_FLASH|DO_UNLOCK_FLASH|DO_MASS_ERASE,
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
   FlashProgramHeader_t *fph = (FlashProgramHeader_t*) &flashProgramHeader;
   
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
