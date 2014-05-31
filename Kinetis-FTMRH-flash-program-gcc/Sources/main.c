//=======================================================================================
// History
//---------------------------------------------------------------------------------------
// 16 Apr 2014 - Added disabling Flash cache
//=======================================================================================


#include <cstdint>

#ifndef NULL
#define NULL ((void*)0)
#endif

//#define DEBUG

//==========================================================================================================
// Target defines

// Vector Table Offset Register
#define SCB_VTOR (*(volatile uint32_t *)0xE000ED08)

#ifdef DEBUG
#define FTMRH_BASE_ADDRESS        ((volatile FlashController *)0x40020000)
#endif


#pragma pack(1)
typedef struct {
   volatile uint8_t fclkdiv;
   volatile uint8_t fsec;
   volatile uint8_t fccobix;
   volatile uint8_t res;
   volatile uint8_t fcnfg;
   volatile uint8_t fercngf;
   volatile uint8_t fstat;
   volatile uint8_t ferstat;
   volatile uint8_t fprot;   //!< Flash protection
   volatile uint8_t eeprot;  //!< EEprom protection
   volatile struct {
         uint8_t  high;
         uint8_t  low;
   } fccob;
   volatile uint8_t  fopt;
} FlashController;

// To minimise code size assume Flash controller at fixed address
//#define FTMRH (*(volatile FlashController *)FTMRH_BASE_ADDRESS) // not much difference!

typedef struct {
   volatile uint8_t cs1;
   volatile uint8_t cs2;
   volatile uint16_t cnt;
   volatile uint16_t toval;
   volatile uint16_t win;
} WatchDog;

#define WDOG (*(volatile WatchDog*) 0x40052000) 

#define WDOG_CS1_EN       (1<<7)
#define WDOG_CS1_INT      (1<<6)
#define WDOG_CS1_UPDATE   (1<<5)
#define WDOG_CS1_DBG      (1<<2)
#define WDOG_CS1_WAIT     (1<<1)
#define WDOG_CS1_STOP     (1<<0)

#define WDOG_CS2_CLK_LPOCLK  (1<<0)

#pragma pack(0)

#define fclkdiv_FDIVLD            (1<<7)
                                 
#define FSTAT_CCIF                (1<<7)  //!< Command complete
#define FSTAT_ACCERR              (1<<5)  //!< Access error
#define FSTAT_FPVIOL              (1<<4)  //!< Protection violation
#define FSTAT_MGBUSY              (1<<3)  //!< Memory controller busy 
#define FSTAT_MGSTAT1             (1<<1)  //!< Command completion status
#define FSTAT_MGSTAT0             (1<<0)  
                                 
#define CFMCLKD_DIVLD             (1<<7)
#define CFMCLKD_PRDIV8            (1<<6)
#define CFMCLKD_FDIV              (0x3F)

// Flash commands
#define FCMD_ERASE_ALL_BLOCKS     (0x08)
#define FCMD_ERASE_FLASH_BLOCK    (0x09)

#define FCMD_PROGRAM_FLASH        (0x06)
#define FCMD_PROGRAM_EEPROM       (0x11)

#define FCMD_ERASE_FLASH_SECTOR   (0x0A)
#define FCMD_ERASE_EEPROM_SECTOR  (0x12)

#define MCM_PLACR  (*(volatile uint32_t*) 0xF000300C) 
#define MCM_PLACR_ESFC  (1<<16)
#define MCM_PLACR_DFCS  (1<<15)
#define MCM_PLACR_EFDS  (1<<14)
#define MCM_PLACR_DFCC  (1<<13)
#define MCM_PLACR_DFCIC (1<<12)
#define MCM_PLACR_DFCDA (1<<11)
#define MCM_PLACR_CFCC  (1<<10)

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
#define CAP_UNLOCK_FLASH       (1<<6)
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
#define FLASH_SECTOR_SIZE  ((1<<10)/2) // 512b block size (used for stride in erase)

typedef void (*EntryPoint_t)(void);
#pragma pack(2)
// Describes a block to be programmed & result
typedef struct {
   uint32_t                  flags;             // Controls actions of routine
   volatile FlashController *controller;        // Pointer to flash controller
   uint32_t                  frequency;         // Target frequency (kHz)
   uint16_t                  errorCode;         // Error code from action
   uint16_t                  sectorSize;        // Size of flash sectors (minimum erase size)
   uint32_t                  address;           // Memory address being accessed
   uint32_t                  dataSize;          // Size of memory range being accessed
   const uint32_t           *dataAddress;       // Pointer to data to program
} FlashData_t;

//! Describe the flash programming code
typedef struct {
   uint32_t        *loadAddress;       // Address where to load this image
   EntryPoint_t     entry;             // Pointer to entry routine
   uint32_t         capabilities;      // Capabilities of routine
   uint32_t         reserved1;
   uint32_t         reserved2;
   FlashData_t     *flashData;         // Pointer to information about operation
} FlashProgramHeader_t;

#pragma pack(0)

extern uint32_t __loadAddress[];

void asm_entry(void);

//! Flash programming command table
//!
volatile const FlashProgramHeader_t gFlashProgramHeader = {
     /* loadAddress  */ __loadAddress,     // load address of image
     /* entry        */ asm_entry,         // entry point for code
     /* capabilities */ CAP_BLANK_CHECK_RANGE|CAP_ERASE_RANGE|CAP_ERASE_BLOCK|CAP_PROGRAM_RANGE|CAP_VERIFY_RANGE|CAP_PARTITION_FLEXNVM,
     /* Reserved1    */ 0,
     /* Reserved2    */ 0,
     /* flashData    */ NULL,
};

void setErrorCode(int errorCode) __attribute__ ((noreturn));
void initFlash(FlashData_t *flashData);
void eraseFlashBlock(FlashData_t *flashData);
void programRange(FlashData_t *flashData);
void verifyRange(FlashData_t *flashData);
void eraseRange(FlashData_t *flashData);
void blankCheckRange(FlashData_t *flashData);
void entry(void);
void isr_default(void);
void testApp(void);
void asm_testApp(void);
void executeCommand(volatile FlashController *controller);

//! Set error code to return to BDM & halt
//!
void setErrorCode(int errorCode) {
   FlashData_t *flashData = gFlashProgramHeader.flashData;
   flashData->errorCode   = (uint16_t)errorCode;
   flashData->flags      |= IS_COMPLETE; 
   for(;;) {
	   asm("bkpt  0");
   }
}

//! Does any initialisation required before accessing the Flash
//!
void initFlash(FlashData_t *flashData) {
   volatile FlashController *controller = flashData->controller;;
   if ((flashData->flags&DO_INIT_FLASH) == 0) {
      return;
   }
   controller->fclkdiv = 0x0F;  // Approximate divider for 16MHz clock out of reset
   controller->fprot   = 0xFF;  // Unprotect Flash
   controller->eeprot  = 0xFF;  // Unprotect EEprom

   MCM_PLACR = (MCM_PLACR_DFCS|MCM_PLACR_DFCC|MCM_PLACR_DFCIC|MCM_PLACR_DFCDA|MCM_PLACR_CFCC);
   
   flashData->flags &= ~DO_INIT_FLASH;
}

//! Launch & wait for Flash command to complete
//!
void executeCommand(volatile FlashController *controller) {
   volatile uint8_t *pFstat;
   uint8_t           fstat;
   
   pFstat = &controller->fstat;
   
   // Launch command
   *pFstat = FSTAT_CCIF;

   // Wait for command complete
   do {
      fstat = *pFstat;
   } while ((fstat&(FSTAT_CCIF|FSTAT_ACCERR|FSTAT_FPVIOL)) == 0);
   if ((fstat & FSTAT_ACCERR) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
   }
   if ((fstat & FSTAT_FPVIOL) != 0) {
      setErrorCode(FLASH_ERR_PROG_FPVIOL);
   }
}

//! Erase entire flash block
//!
void eraseFlashBlock(FlashData_t *flashData) {
   volatile FlashController *controller = flashData->controller;
   uint32_t                  address    = flashData->address;
   
   if ((flashData->flags&DO_ERASE_BLOCK) == 0) {
      return;
   }
   // Clear any existing errors
   controller->fstat   = FSTAT_ACCERR|FSTAT_FPVIOL;
   
   if ((address & ADDRESS_EEPROM) != 0) {
      // Global address [23] selects between flash (0) or EEPROM (1) block.
      address |= (1<<23); 
   }
   // Write command & address
   controller->fccobix = 0; controller->fccob.high = FCMD_ERASE_FLASH_BLOCK; 
                            controller->fccob.low  = ((uint8_t)(address>>16));
   controller->fccobix = 1; controller->fccob.high =  (uint8_t)(address>>8);
                            controller->fccob.low  =  (uint8_t)(address);
   executeCommand(controller);
   flashData->flags &= ~DO_ERASE_BLOCK;
}

//! Program a range of flash from buffer
//!
//! Returns an error if the security location is to be programmed
//! to permanently lock the device
//!
void programRange(FlashData_t *flashData) {
   volatile FlashController *controller = flashData->controller;
   uint32_t         address    = flashData->address;
   const uint32_t  *data       = flashData->dataAddress;
   
   if ((flashData->flags&DO_PROGRAM_RANGE) == 0) {
      return;
   }
   // Programs phrases
   
   // Clear any existing errors
   controller->fstat   = FSTAT_ACCERR|FSTAT_FPVIOL;

   if ((address & ADDRESS_EEPROM) == 0) {
      uint16_t numPhrases = flashData->dataSize/4;
      // Program 1 to 2 Flash phrases (1 phrase = 4 bytes)
      while (numPhrases-- > 0) {
         uint32_t dataValue;
         // Write command
         controller->fccobix = 0; controller->fccob.high = FCMD_PROGRAM_FLASH; 
                                  controller->fccob.low  = (uint8_t)(address>>16);
         controller->fccobix = 1; controller->fccob.high = (uint8_t)(address>>8);
                                  controller->fccob.low  = (uint8_t)(address);
         // 1st phrase
         dataValue = *data++; 
         controller->fccobix = 2; controller->fccob.high    = (uint8_t)(dataValue>>8);
                                  controller->fccob.low     = (uint8_t)(dataValue);
         controller->fccobix = 3; controller->fccob.high    = (uint8_t)(dataValue>>24);
                                  controller->fccob.low     = (uint8_t)(dataValue>>16);
         if (numPhrases > 0) {
            // 2nd phrase
            dataValue = *data++; 
            controller->fccobix = 4; controller->fccob.high    = (uint8_t)(dataValue>>8);
                                     controller->fccob.low     = (uint8_t)(dataValue);
            controller->fccobix = 5; controller->fccob.high    = (uint8_t)(dataValue>>24);
                                     controller->fccob.low     = (uint8_t)(dataValue>>16);
            numPhrases--;
           }
         executeCommand(controller);
         address += 8;
      }
   }
   else {
      uint16_t numBytes = flashData->dataSize;
      // Program 1 to 4 EEPROM bytes
      while (numBytes-- > 0) {
         uint32_t dataValue = *data++;
         // Write command
         controller->fccobix = 0; controller->fccob.high = FCMD_PROGRAM_EEPROM; 
                                  controller->fccob.low  = (uint8_t)(address>>16);
		   controller->fccobix = 1; controller->fccob.high = (uint8_t)(address>>8);
		                            controller->fccob.low  = (uint8_t)(address);
         controller->fccobix = 2; controller->fccob.low  = (uint8_t)(dataValue);
         if (numBytes > 0) {
            numBytes--;
            controller->fccobix = 3; controller->fccob.low  = (uint8_t)(dataValue>>8);
            if (numBytes > 0) {
               numBytes--;
               controller->fccobix = 4; controller->fccob.low  = (uint8_t)(dataValue>>16);
               if (numBytes > 0) {
                  numBytes--;
                  controller->fccobix = 5; controller->fccob.low  = (uint8_t)(dataValue>>24);
               }
            }
         }
         executeCommand(controller);
         address += 4;
      }
   }
   flashData->flags &= ~DO_PROGRAM_RANGE;
}

//! Verify a range of flash against buffer
//!
void verifyRange(FlashData_t *flashData) {
   uint8_t       *address   = (uint8_t *)flashData->address;
   const uint8_t *data      = (uint8_t *)flashData->dataAddress;
   uint32_t       numBytes  = flashData->dataSize;
   
   if ((flashData->flags&DO_VERIFY_RANGE) == 0) {
      return;
   }
   // Verify bytes
   while (numBytes-- > 0) {
      if (*address++ != *data++) {
         setErrorCode(FLASH_ERR_VERIFY_FAILED);
      }
   flashData->flags &= ~DO_VERIFY_RANGE;
   }
}

//! Erase a range of flash
//!
void eraseRange(FlashData_t *flashData) {
   volatile FlashController *controller = flashData->controller;
   uint32_t address     = flashData->address;
   uint32_t endAddress  = address + flashData->dataSize - 1; // Inclusive
   uint32_t pageMask    = flashData->sectorSize-1U;
   uint8_t  eraseCommand;
   
   if ((flashData->flags&DO_ERASE_RANGE) == 0) {
      return;
   }
   // Check for empty range before block rounding
   if (flashData->dataSize == 0) {
      return;
   }
   // Round start address to start of block (inclusive)
   address &= ~pageMask;
   
   // Round end address to end of block (inclusive)
   endAddress |= pageMask;
   
   if ((address & ADDRESS_EEPROM) != 0) {
      eraseCommand = FCMD_ERASE_EEPROM_SECTOR;
   }
   else {
      eraseCommand = FCMD_ERASE_FLASH_SECTOR;
   }
   // Clear any existing errors
   controller->fstat   = FSTAT_ACCERR|FSTAT_FPVIOL;

   // Erase each sector
   while (address <= endAddress) {
      // Write command
      controller->fccobix = 0; controller->fccob.high = eraseCommand; 
                               controller->fccob.low  = (uint8_t)(address>>16);
      controller->fccobix = 1; controller->fccob.high = (uint8_t)(address>>8);
                               controller->fccob.low  = (uint8_t)(address);
      executeCommand(controller);
      // Advance to start of next sector
      address += flashData->sectorSize;
   }
   flashData->flags &= ~DO_ERASE_RANGE;
}

//! Check that a range of flash is blank (=0xFFFF)
//!
void blankCheckRange(FlashData_t *flashData) {
   const int  itemSize  = 4;
   uint32_t  *address   = (uint32_t *)(flashData->address);
   uint32_t   numItems  = (flashData->dataSize+itemSize-1)/itemSize;
   
   if ((flashData->flags&DO_BLANK_CHECK_RANGE) == 0) {
      return;
   }
//   if (((int)address & (itemSize-1)) != 0) {
//      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
//   }
   while (numItems>0) {
      if (*address != 0xFFFFFFFFUL) {
         setErrorCode(FLASH_ERR_ERASE_FAILED);
      }
      numItems--;
      address++;
   }
   flashData->flags &= ~DO_BLANK_CHECK_RANGE;
}

//! Minimal vector table
extern uint32_t __vector_table[];

//! Some stack space
extern uint32_t __stacktop[];

//! Main C entry point
//! 
//! Assumes ramBuffer is set up beforehand
//!
void entry(void) {
   FlashData_t *flashData;  // Handle on programming data

   // Set the interrupt vector table position
   SCB_VTOR = (uint32_t)__vector_table;
   
#ifndef DEBUG
   /* Disable the Watchdog */

   WDOG.cnt    = 0x20C5;                  // Write the 1st unlock word
   WDOG.cnt    = 0x28D9;                  // Write the 2nd unlock word
   WDOG.toval  = 0x28D9;                  // Setting timeout value
   WDOG.cs2    = WDOG_CS2_CLK_LPOCLK;     // Setting 1-kHz clock source
   WDOG.cs1    = WDOG_CS1_UPDATE;         // Disable watch-dog
#endif
   
   // Handle on programming data
   flashData = gFlashProgramHeader.flashData;

   // Indicate not complete
   flashData->flags &= ~IS_COMPLETE;
   
   // No errors so far
   flashData->errorCode = FLASH_ERR_OK;
   
   // Clear invalid/unused address bits
   // A23 is used for Flash block number
   flashData->address &= 0x008FFFFFUL;
   
   initFlash(flashData);
   eraseFlashBlock(flashData);
   eraseRange(flashData);
   blankCheckRange(flashData);
   programRange(flashData);
   verifyRange(flashData);
   
#ifndef DEBUG
   // Indicate completed & stop
   setErrorCode(FLASH_ERR_OK);
#endif
}

//! Default unexpected interrupt handler
//!
void isr_default(void) {
   setErrorCode(FLASH_ERR_TRAP);
}

//! Low level entry point
//! 
__attribute__((naked))
void asm_entry(void) {
#ifndef DEBUG
   // Setup the stack before we attempt anything else
   asm (
   "mov   r0,%[stacktop]\n\t"
   "mov   sp,r0\n\t"
   "b     entry\n\t"
   "bkpt  0\n\t"::[stacktop] "r" (__stacktop));
#else
   asm (
   "b     entry\n\t");
#endif
}

#ifndef DEBUG
void asm_testApp(void) {
}
#else
#define TEST 1
#if TEST == 1
// Programming general flash
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
                                 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000040,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x000000040,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000840,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_D
static const FlashData_t flashdataD = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000C40,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_E
static const FlashData_t flashdataE = {
   /* flags      */ DO_INIT_FLASH,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
};
#elif TEST == 2
// Unlock flash
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_UNLOCK_FLASH|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 3
// Lock Flash 
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_LOCK_FLASH|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 4
// Not used
static const FlashData_t flashdataA = {
   /* flags      */ DO_TIMING_LOOP,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 5
// Set erasing ranges
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000045,
   /* size       */ 0x312-0x45,
};
#define DO_B
// Set erasing ranges
static const FlashData_t flashdataB = {
   /* flags      */ DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00001235,
   /* size       */ 0x1C3A-0x1235,
};
#elif TEST == 6
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF}; 
// Mass erase + Unlock flash
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_UNLOCK_FLASH|DO_ERASE_BLOCK,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000800,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000900,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#elif TEST == 7
// Checking security region actions
// Program region overlapping security area
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF,
                                 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x000003F0,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#elif TEST == 8
// Checking security anti-lockup
//static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,
//                                 (FTFA_FSEC_KEY_ENABLE|FTFA_FSEC_MEEN_DISABLE|FTFA_FSEC_FSLACC|FTFA_FSEC_UNSEC),0xFF,0xFF,0xFF,}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTMRH_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000400,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#endif

//! Dummy test program for debugging
void testApp(void) {
	FlashProgramHeader_t *fph = (FlashProgramHeader_t*) &gFlashProgramHeader;

   // Set the interrupt vector table position
   SCB_VTOR = (uint32_t)__vector_table;
   
   // Disable watchdog
   SIM_COPC = COP_DISABLE;
      
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
}

//!
//!
__attribute__((naked))
void asm_testApp(void) {
   asm (
   // Setup the stack before we attempt anything else
   "mov   r0,%[stacktop]\n\t"
   "mov   sp,r0\n\t"
   // execute testApp	   
   "bl    testApp\n\t"
   // 
   "bkpt  0\n\t"::[stacktop] "r" (__stacktop));
}
#endif
