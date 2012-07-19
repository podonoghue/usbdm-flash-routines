#include <cstdint>

#ifndef NULL
#define NULL ((void*)0)
#endif

#define DEBUG

//==========================================================================================================
// Target defines

// Vector Table Offset Register
#define SCB_VTOR (*(uint32_t *)0xE000ED08)

// Option Halfwords in Flash
#define RDP   (0x1FFFF800)
#define USER  (0x1FFFF802)
#define Data0 (0x1FFFF804)
#define Data1 (0x1FFFF806)
#define WRP0  (0x1FFFF808)
#define WRP1  (0x1FFFF80A)
#define WRP2  (0x1FFFF80C)
#define WRP3  (0x1FFFF80E)

// RDP unlock key value
#define RDPRT_KEY       (0x00A5)

// USER bit masks
#define nRST_STDBY (1<<2) // 0: Reset when entering Standby, 1: No reset generated.
#define nRST_STOP  (1<<1) // 0: Reset when entering Stop, 1: No reset generated
#define WDG_SW     (1<<0) // 0: Hardware watchdog, 1: Software watchdog

// Flash registers
#define FLASH_ACR       (*(uint32_t *)0x40022000)
#define FLASH_KEYR      (*(uint32_t *)0x40022004)
#define FLASH_OPTKEYR   (*(uint32_t *)0x40022008)
#define FLASH_SR        (*(uint32_t *)0x4002200C)
#define FLASH_CR        (*(uint32_t *)0x40022010)
#define FLASH_AR        (*(uint32_t *)0x40022014)
#define FLASH_OBR       (*(uint32_t *)0x4002201C)
#define FLASH_WRPR      (*(uint32_t *)0x40022020)

#define FLASH_SR_BSY       (1<<0)
#define FLASH_SR_PGERR     (1<<2)
#define FLASH_SR_WRPRTERR  (1<<4)
#define FLASH_SR_EOP       (1<<5)

#define FLASH_CR_PG     (1<<0)
#define FLASH_CR_PER    (1<<1)
#define FLASH_CR_MER    (1<<2)
#define FLASH_CR_OPTPG  (1<<4)
#define FLASH_CR_OPTER  (1<<5)
#define FLASH_CR_STRT   (1<<6)
#define FLASH_CR_LOCK   (1<<7)
#define FLASH_CR_OPTWRE (1<<9)
#define FLASH_CR_ERRIE  (1<<10)
#define FLASH_CR_EOPIE  (1<<12)

#define FLASH_OBR_OPTERR        (1<<0)
#define FLASH_OBR_RDPRT         (1<<1)
#define FLASH_OBR_WDG_SW        (1<<2)
#define FLASH_OBR_nRST_STOP     (1<<3)
#define FLASH_OBR_nRST_STDBY    (1<<4)
#define FLASH_OBR_DATA0_OFF     (10)
#define FLASH_OBR_DATA0_MASK    (0xFF<<FLASH_OBR_DATA0_OFF)
#define FLASH_OBR_DATA1_OFF     (18)
#define FLASH_OBR_DATA1_MASK    (0xFF<<FLASH_OBR_DATA1_OFF)

#define FLASH_KEYR_KEY1 (0x45670123)
#define FLASH_KEYR_KEY2 (0xCDEF89AB)

typedef struct {
   uint8_t res;
} FlashController;

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
     FLASH_ERR_UNKNOWN           = (13), // Unspecified error
} FlashDriverError_t;

// This is the smallest unit of Flash that can be erased
#define FLASH_BLOCK_SIZE  (1*(1<<10)) // 1K block size for small/medium devices
                                      // 2K block size for large devices
typedef void (*EntryPoint_t)(void);
#pragma pack(2)
// Describes a block to be programmed & result
typedef struct {
   uint32_t         flags;             // Controls actions of routine
   FlashController *controller;        // Ptr to flash controller
   uint32_t         frequency;         // Target frequency (kHz)
   uint16_t         errorCode;         // Error code from action
   uint16_t         res1;
   uint32_t         address;           // Memory address being accessed
   uint32_t         size;              // Size of memory range being accessed
   const uint16_t   *data;              // Ptr to data to program
} FlashData_t;

//! Describe the flash programming code
typedef struct {
   uint32_t         loadAddress;       // Address where to load this image
   EntryPoint_t     entry;             // Ptr to entry routine
   uint32_t         capabilities;      // Capabilities of routine
// uint8_t          reserved[32];      // Reserved for target specific use, values may be copied from XML
   uint16_t         blockSize;         // Size of Flash memory blocks
   uint8_t          reserved2[30];     // Reserved for future programmer use 
   FlashData_t     *flashData;         // Ptr to information about operation
   uint16_t         unsecure[8];       // Flash data for unsecure
   uint16_t         secure[8];         // Flash data for secure
} FlashProgramHeader_t;
#pragma pack(0)

asm void asm_entry(void);

//! Flash programming command table
//!
const FlashProgramHeader_t flashProgramHeader = {
     /* loadAddress  */ 0x20000000,        // load address of image
     /* entry        */ asm_entry,         // entry point for code
     /* capabilities */ CAP_BLANK_CHECK|CAP_ERASE_RANGE|CAP_MASS_ERASE|CAP_PROGRAM_RANGE|CAP_VERIFY_RANGE|CAP_UNLOCK_FLASH|CAP_ALIGN_2BYTE,
     /* blockSize    */ FLASH_BLOCK_SIZE,  // flash blockSize
     /* reserved     */ {0x0},
     /* flashData    */ NULL,
// Reserved for target specific use, values may be copied from XML
// STM32F100xx - option default values
//    RDP        USER                         DATA0 DATA1 WRP0  WRP1  WRP2  WRP3
     {RDPRT_KEY, nRST_STDBY|nRST_STOP|WDG_SW, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }, // Unprotect value
     {0,         nRST_STDBY|nRST_STOP|WDG_SW, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF }, // Protect values
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
   // Do init flash every time
   
   if ((FLASH_CR&FLASH_CR_LOCK)!=0) {
      // Not unlocked - try to unlock
      FLASH_KEYR = FLASH_KEYR_KEY1;   
      FLASH_KEYR = FLASH_KEYR_KEY2;
   }
   if ((FLASH_CR&FLASH_CR_LOCK)!=0)
      return setErrorCode(FLASH_ERR_LOCKED);
   
   flashData->flags &= ~DO_INIT_FLASH;
   return FLASH_ERR_OK;
}

//! Does any initialisation required before accessing the option Flash
//!
int initOptionFlash(FlashData_t *flashData) {
   if ((flashData->flags&DO_MODIFY_OPTION) == 0)
      return setErrorCode(FLASH_ERR_OK);
   
   if ((FLASH_CR&FLASH_CR_OPTWRE)==0) {
      // Not unlocked - try to unlock
      FLASH_OPTKEYR = FLASH_KEYR_KEY1;   
      FLASH_OPTKEYR = FLASH_KEYR_KEY2;
   }
   if ((FLASH_CR&FLASH_CR_OPTWRE)==0)
      return setErrorCode(FLASH_ERR_LOCKED);

   return FLASH_ERR_OK;
}

//! Erase entire flash array
//!
int massEraseFlash(FlashData_t *flashData) {
   if ((flashData->flags&DO_MASS_ERASE) == 0)
      return FLASH_ERR_OK;
   
   FLASH_CR = FLASH_CR_MER;
   FLASH_CR = FLASH_CR_MER|FLASH_CR_STRT;
   while ((FLASH_SR & FLASH_SR_BSY) != 0) {
   }
   FLASH_CR = 0;
   if ((FLASH_SR & FLASH_SR_PGERR) != 0) {
      return setErrorCode(FLASH_ERR_PROG_FAILED);
   }
   if ((FLASH_SR & FLASH_SR_WRPRTERR) != 0) {
      return setErrorCode(FLASH_ERR_PROG_WPROT);
   }
   flashData->flags &= ~DO_MASS_ERASE;
   return FLASH_ERR_OK;
}

//! Program a range of flash from buffer
//!
int programRange(FlashData_t *flashData) {
   uint32_t address      = flashData->address;
   const uint16_t *data  = flashData->data;
   uint16_t numHalfWords = flashData->size/2;
   
   if ((flashData->flags&DO_PROGRAM_RANGE) == 0)
      return FLASH_ERR_OK;
   
   if ((address & 0x01) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

   // Set program mode option/normal bytes
   if (flashData->flags&DO_MODIFY_OPTION)
      FLASH_CR = FLASH_CR_OPTPG|FLASH_CR_OPTWRE;
   else
      FLASH_CR = FLASH_CR_PG;
   while (numHalfWords-- > 0) {
      *(uint16_t *)address = *data;
      while ((FLASH_SR & FLASH_SR_BSY) != 0) {
      }
      if ((FLASH_SR & FLASH_SR_PGERR) != 0) {
         FLASH_CR = 0;
         return setErrorCode(FLASH_ERR_PROG_FAILED);
      }
      if ((FLASH_SR & FLASH_SR_WRPRTERR) != 0) {
         FLASH_CR = 0;
         return setErrorCode(FLASH_ERR_PROG_WPROT);
      }
      // Only try verify if not options 
      if (((flashData->flags&DO_MODIFY_OPTION) == 0) &&
          (*(uint16_t *)address != *data)) {
         FLASH_CR = 0;
         return setErrorCode(FLASH_ERR_VERIFY_FAILED);
      }
      address += 2;
      data++;
   }
   FLASH_CR = 0;   
   flashData->flags &= ~DO_PROGRAM_RANGE;
   return FLASH_ERR_OK;
}

//! Verify a range of flash against buffer
//!
int verifyRange(FlashData_t *flashData) {
   uint32_t address      = flashData->address;
   const uint16_t *data  = flashData->data;
   uint16_t numHalfWords = flashData->size/2;
   
   if ((flashData->flags&DO_VERIFY_RANGE) == 0)
      return FLASH_ERR_OK;

   if ((address & 0x01) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

   // Verify words
   while (numHalfWords-- > 0) {
      if (*(uint16_t *)address != *data)
         return setErrorCode(FLASH_ERR_VERIFY_FAILED);
      address += 2;
      data++;
   }
   flashData->flags &= ~DO_VERIFY_RANGE;
   return FLASH_ERR_OK;
}

//! Erase a range of flash
//!
int eraseRange(FlashData_t *flashData) {
   uint32_t address            = flashData->address;
   uint32_t endAddress         = address + flashData->size; // Exclusive
   uint32_t pageMask           = flashProgramHeader.blockSize-1U;
   
   if ((flashData->flags&DO_ERASE_RANGE) == 0)
      return FLASH_ERR_OK;

   // Round range to page boundaries
   address    &= ~pageMask;
   endAddress |= pageMask;
   
   // Set program mode option/normal bytes
   if (flashData->flags&DO_MODIFY_OPTION)
      FLASH_CR = FLASH_CR_OPTER|FLASH_CR_OPTWRE;
   else
      FLASH_CR = FLASH_CR_PER;
   // Erase each block/page
   while (address < endAddress) {
      // Set page erase mode
      FLASH_AR = address;
      if (flashData->flags&DO_MODIFY_OPTION)
         FLASH_CR = FLASH_CR_OPTER|FLASH_CR_OPTWRE|FLASH_CR_STRT;
      else
         FLASH_CR = FLASH_CR_PER|FLASH_CR_STRT;
      while ((FLASH_SR & FLASH_SR_BSY) != 0) {
      }
      if ((FLASH_SR & FLASH_SR_PGERR) != 0) {
         FLASH_CR = 0;
         return setErrorCode(FLASH_ERR_PROG_FAILED);
      }
      if ((FLASH_SR & FLASH_SR_WRPRTERR) != 0) {
         FLASH_CR = 0;
         return setErrorCode(FLASH_ERR_PROG_WPROT);
      }
      address += flashProgramHeader.blockSize;
   }
   FLASH_CR = 0;   
   flashData->flags &= ~DO_ERASE_RANGE;
   return FLASH_ERR_OK;
}

//! Check that a range of flash is blank (=0xFFFF)
//!
int blankCheckRange(FlashData_t *flashData) {
   uint32_t address      = flashData->address;
   uint16_t numHalfWords = (flashData->size+1)/2;

   if ((flashData->flags&DO_BLANK_CHECK_RANGE) == 0)
      return FLASH_ERR_OK;
   
   if ((address & 0x01) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

   while (numHalfWords>0) {
      if ((*(uint16_t *) address) != 0xFFFF)
         return setErrorCode(FLASH_ERR_ERASE_FAILED);
      numHalfWords--;
      address += 2;
   }
   flashData->flags &= ~DO_BLANK_CHECK_RANGE;
   return FLASH_ERR_OK;
}

//! Unlock the flash by programming the Option Flash
//! region to a default value (all flash unprotected)
//!
int unlockFlash(FlashData_t *flashData) {
   if ((flashData->flags&DO_UNLOCK_FLASH) == 0)
      return FLASH_ERR_OK;

   // Unlock can only be combined with Mass Erase
   if ((flashData->flags&(DO_ERASE_RANGE|DO_PROGRAM_RANGE)) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

   // Simply modify the settings for later operations
   // The required option flash values are part of the flashData
   // so they can be modified.
   // Always erase security area as has no collateral damage
   flashData->address = RDP;
   flashData->data    = flashProgramHeader.unsecure;
   flashData->size    = sizeof(flashProgramHeader.unsecure);
   flashData->flags  |= DO_ERASE_RANGE|DO_PROGRAM_RANGE|DO_MODIFY_OPTION;
   flashData->flags  &= ~DO_UNLOCK_FLASH;

   return FLASH_ERR_OK;
}

//! Lock the flash by programming the Option Flash
//! region to a default secured value (all flash protected)
//!
int lockFlash(FlashData_t *flashData) {
   if ((flashData->flags&DO_LOCK_FLASH) == 0)
      return FLASH_ERR_OK;

   // Unlock can only be combined with Mass Erase
   if ((flashData->flags&(DO_ERASE_RANGE|DO_PROGRAM_RANGE)) != 0)
      return setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);

   // Simply modify the settings for later operations
   // The required option flash values are part of the flashCommandTable
   // so they can be modified.
   // Always erase security area as has no collateral damage
   flashData->address = RDP;
   flashData->data    = flashProgramHeader.secure;
   flashData->size    = sizeof(flashProgramHeader.secure);
   flashData->flags  |= DO_ERASE_RANGE|DO_PROGRAM_RANGE|DO_MODIFY_OPTION;
   flashData->flags  &= ~DO_LOCK_FLASH;

   return FLASH_ERR_OK;
}

//! Do miscellaneous operations
//!
int doMiscOperations(FlashData_t *flashData) {
   int rc;
   if ((flashData->flags&DO_MISC_OP) == 0)
      return FLASH_ERR_OK;

   switch ((flashData->flags&DO_MISC_MASK)) {
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
extern uint32_t __stacktop[];

//! Main C entry point
//! 
//! Assumes ramBuffer is set up beforehand
//!
void entry(void) {
   FlashData_t *flashData;  // Handle on programming data
   
   // Set the interrupt vector table position
   SCB_VTOR = (uint32_t)__vector_table;
   
   // Handle on programming data
   flashData = flashProgramHeader.flashData;

   // Indicate not complete
   flashData->flags &= ~IS_COMPLETE;
   
   // No errors so far
   clearErrorCode();

#ifndef DEBUG
   // Execute in order with early abort
   // Each routine returns FLASH_ERR_OK (0) on success
   !initFlash(flashData)          &&
   !doMiscOperations(flashData)   &&
   !unlockFlash(flashData)        &&
   !lockFlash(flashData)          &&
   !massEraseFlash(flashData)     &&
   !initOptionFlash(flashData)    &&
   !eraseRange(flashData)         &&
   !blankCheckRange(flashData)    &&
   !initOptionFlash(flashData)    &&
   !programRange(flashData)       &&
   !verifyRange(flashData)        ;
#else
   // Easier to debug
   initFlash(flashData);
   doMiscOperations(flashData);
   unlockFlash(flashData);
   lockFlash(flashData);
   massEraseFlash(flashData);
   initOptionFlash(flashData);
   eraseRange(flashData);
   blankCheckRange(flashData);
   initOptionFlash(flashData);
   programRange(flashData);
   verifyRange(flashData);
#endif
   // Indicate completed
   flashData->flags |= IS_COMPLETE; 
}

//! Low level entry point
//! 
asm void asm_entry(void) {
   // Setup the stack before we attempt anything else
   lda   r0,__stacktop
   mov   sp,r0
   bl    entry
   bkpt  0
}

//! Default unexpected interrupt handler
//!
void isr_default(void) {
   setErrorCode(FLASH_ERR_TRAP);
   flashProgramHeader.flashData->flags |= IS_COMPLETE; 
   for(;;) {}
}

#ifndef DEBUG
void asm_testApp(void) {
}
#else
#define TEST 2
#if TEST == 1
// Programming general flash
static const uint16_t buffer[] = {0xEE11,0xDD22,0xCC33,0xBB44,0x4455,0x3366,0x2277}; 
static const FlashData_t flashdata = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ (0x00000000),
   /* frequency  */ 0,  /* not used */
   /* errorCode  */ 0xAA55,
   /* res        */ 0,
   /* address    */ 0x08000000,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t*)buffer,
};
#elif TEST == 2
// Mass erase + Unlock flash
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_UNLOCK_FLASH|DO_MASS_ERASE,
   /* controller */ (0x00000000),
   /* frequency  */ 0,  /* not used */
   /* errorCode  */ 0xAA55,
   /* res        */ 0,
};
#elif TEST == 3
// Lock Flash 
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_LOCK_FLASH,
   /* controller */ (0x00000000),
   /* frequency  */ 0,  /* not used */
   /* errorCode  */ 0xAA55,
   /* res        */ 0,
};
#elif TEST == 4
// Programming values to Option region
//                                        RDP       USER                        DATA0 DATA1 WRP0  WRP1  WRP2  WRP3
static const uint16_t optionValues[] = {RDPRT_KEY, nRST_STDBY|nRST_STOP|WDG_SW, 0,    0,    0xFF, 0xFF, 0xFF, 0xFF }; 
static const FlashData_t flashdata = {
   /* flags     */ DO_INIT_FLASH|DO_MODIFY_OPTION|DO_MASS_ERASE|DO_ERASE_RANGE|DO_PROGRAM_RANGE,
   /* controller */ (0x00000000),
   /* frequency  */ 0,  /* not used */
   /* errorCode  */ 0xAA55,
   /* res        */ 0,
   /* address   */ RDP,
   /* size      */ sizeof(optionValues),
   /* data      */ (uint32_t *)optionValues,
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
	for(;;) {	   
	}
}
asm void asm_testApp(void) {
   // Setup the stack before we attempt anything else
   lda   r0,__stacktop
   mov   sp,r0
   bl    testApp
}
#endif
