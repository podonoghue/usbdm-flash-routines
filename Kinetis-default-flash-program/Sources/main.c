#include <cstdint>

#ifndef NULL
#define NULL ((void*)0)
#endif

//#define DEBUG

//==========================================================================================================
// Target defines

// Vector Table Offset Register
#define SCB_VTOR (*(volatile uint32_t *)0xE000ED08)

#define NV_SECURITY_ADDRESS        (0x00000400)
#define NV_FSEC_ADDRESS            (NV_SECURITY_ADDRESS+0x0C)
#define FTFL_FSEC_KEY_MASK              0xC0
#define FTFL_FSEC_KEY_ENABLE            0x80
#define FTFL_FSEC_KEY_DISABLE           0xC0
#define FTFL_FSEC_MEEN_MASK             0x30
#define FTFL_FSEC_MEEN_ENABLE           0x30
#define FTFL_FSEC_MEEN_DISABLE          0x20
#define FTFL_FSEC_FSLACC                0x0C
#define FTFL_FSEC_SEC_MASK              0x03
#define FTFL_FSEC_UNSEC                 0x02
#define FTFL_FSEC_SEC                   0x03

#ifdef DEBUG
#define FTFL_BASE_ADDRESS               ((volatile FlashController *)0x40020000)
#endif

// Cache control
#define FMC_PFAPR                       (*(volatile uint32_t *)0x4001F000)
#define FMC_PFB0CR                      (*(volatile uint32_t *)0x4001F004)
#define FMC_PFB1CR                      (*(volatile uint32_t *)0x4001F008)

#pragma pack(1)
typedef struct {
   uint8_t  fstat;
   uint8_t  fcnfg;
   uint8_t  fsec;
   uint8_t  fopt;
   uint32_t fccob0_3;
   uint32_t fccob4_7;
   uint32_t fccob8_B;
   uint32_t fprot0_3;
   uint8_t  feprot;
   uint8_t  fdprot;
} FlashController;
#pragma pack(0)

#define FTFL_FSTAT_CCIF                 0x80
#define FTFL_FSTAT_RDCOLLERR            0x40
#define FTFL_FSTAT_ACCERR               0x20
#define FTFL_FSTAT_FPVIOL               0x10
#define FTFL_FSTAT_MGSTAT0              0x01

#define FTFL_FCNFG_CCIE                 0x80
#define FTFL_FCNFG_RDCOLLIE             0x40
#define FTFL_FCNFG_ERSAREQ              0x20
#define FTFL_FCNFG_ERSSUSP              0x10
#define FTFL_FCNFG_SWAP                 0x08
#define FTFL_FCNFG_PFLSH                0x04
#define FTFL_FCNFG_RAMRDY               0x02
#define FTFL_FCNFG_EEERDY               0x01

#define FOPT_LPBOOTn                    0x01
#define FOPT_EZPORT                     0x02
   
// Flash commands
#define F_RD1BLK                        0x00
#define F_RD1SEC                        0x01
#define F_PGMCHK                        0x02
#define F_RDRSRC                        0x03
#define F_PGM4                          0x06
#define F_ERSBLK                        0x08
#define F_ERSSCR                        0x09
#define F_PGMSEC                        0x0B
#define F_RD1ALL                        0x40
#define F_RDONCE                        0x41
#define F_PGMONCE                       0x43
#define F_ERSALL                        0x44
#define F_VFYKEY                        0x45
#define F_PGMPART                       0x80UL
#define F_SETRAM                        0x81

#define F_USER_MARGIN                   0x01 // Use 'user' margin on flash verify
#define F_FACTORY_MARGIN                0x02 // Use 'factory' margin on flash verify

#define CRC_CRC                         (*(volatile uint32_t *)0x40032000)
#define CRC_GPOLY                       (*(volatile uint32_t *)0x40032004)
#define CRC_CTRL                        (*(volatile uint32_t *)0x40032008)
#define CRC_CTRL_WAS                    (1<<25)
#define CRC_CTRL_TCRC                   (1<<24)

/* Address of Watchdog Unlock Register (16 bits) */
#define WDOG_UNLOCK (*(volatile uint16_t *)0x4005200E)

/* Address of Watchdog Status and Control Register High (16 bits) */
#define WDOG_STCTRLH (*(volatile uint16_t *)0x40052000)

/* Unlocking Watchdog sequence words*/
#define WDOG_UNLOCK_SEQ_1   (0xC520)
#define WDOG_UNLOCK_SEQ_2   (0xD928)

/* Word to be written in in STCTRLH after unlocking sequence in order to disable the Watchdog */
#define WDOG_DISABLED_CTRL  0x0012

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
#define FLASH_SECTOR_SIZE  (1*(1<<10)) // 1K block size (used for stride in erase)

typedef void (*EntryPoint_t)(void);
#pragma pack(2)
// Describes a block to be programmed & result
typedef struct {
   uint32_t         flags;             // Controls actions of routine
   volatile FlashController *controller;        // Pointer to flash controller
   uint32_t         frequency;         // Target frequency (kHz)
   uint16_t         errorCode;         // Error code from action
   uint16_t         sectorSize;        // Size of flash sectors (minimum erase size)
   uint32_t         address;           // Memory address being accessed
   uint32_t         dataSize;          // Size of memory range being accessed
   const uint32_t  *dataAddress;       // Pointer to data to program
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

asm void asm_entry(void);

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

void setErrorCode(int errorCode);
void initFlash(FlashData_t *flashData);
void eraseFlashBlock(FlashData_t *flashData);
void programRange(FlashData_t *flashData);
void verifyRange(FlashData_t *flashData);
void eraseRange(FlashData_t *flashData);
void blankCheckRange(FlashData_t *flashData);
void programPartition(FlashData_t *flashData);
void entry(void);
void isr_default(void);
void testApp(void);
asm void asm_testApp(void);
int executeCommand(volatile FlashController *controller);

//! Set error code to return to BDM & halt
//!
void setErrorCode(int errorCode) {
   FlashData_t *flashData = gFlashProgramHeader.flashData;
   flashData->errorCode   = (uint16_t)errorCode;
   flashData->flags      |= IS_COMPLETE; 
   asm {
      bkpt  0
   }
}

//! Does any initialisation required before accessing the Flash
//!
void initFlash(FlashData_t *flashData) {
   // Do init flash every time
   volatile FlashController *controller = flashData->controller;
   
   // Unprotect flash
   controller->fprot0_3 = 0xFFFFFFFF;
   controller->fdprot   = 0xFF;
   
   // Disable flash caching
   FMC_PFB0CR  = 0x00000000;
   FMC_PFB1CR  = 0x00000000;

   flashData->flags &= ~DO_INIT_FLASH;
}

int executeCommand(volatile FlashController *controller) {
   // Clear any existing errors
   controller->fstat = FTFL_FSTAT_ACCERR|FTFL_FSTAT_FPVIOL;

   // Start command
   controller->fstat = FTFL_FSTAT_CCIF;

   // Wait for command complete
   while ((controller->fstat & FTFL_FSTAT_CCIF) == 0) {
   }
   // Convert error codes
   if ((controller->fstat & FTFL_FSTAT_FPVIOL ) != 0) {
      return FLASH_ERR_PROG_FPVIOL;
   }
   if ((controller->fstat & FTFL_FSTAT_ACCERR ) != 0) {
      return FLASH_ERR_PROG_ACCERR;
   }
   if ((controller->fstat & FTFL_FSTAT_MGSTAT0 ) != 0) {
      return FLASH_ERR_PROG_MGSTAT0;
   }
   return FLASH_ERR_OK;
}

//! Erase entire flash block
//!
void eraseFlashBlock(FlashData_t *flashData) {
   volatile FlashController *controller = flashData->controller;
   uint32_t         address    = flashData->address;
   int rc;

   if ((flashData->flags&DO_ERASE_BLOCK) == 0) {
      return;
   }
   controller->fccob0_3 = (F_ERSBLK << 24) | address;
   rc = executeCommand(controller);
   if (rc != FLASH_ERR_OK) {
      setErrorCode(rc);
   }
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
   uint32_t         numWords   = flashData->dataSize>>2;
   int              rc         = FLASH_ERR_OK;
   
   if ((flashData->flags&DO_PROGRAM_RANGE) == 0) {
      return;
   }
   if ((address & 0x03) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   // Program words
   while (numWords-- > 0) {
      if (address == (NV_FSEC_ADDRESS&~3)) {
         // Check for permanent secure value
         if ((*data & (FTFL_FSEC_MEEN_MASK)) == (FTFL_FSEC_MEEN_DISABLE)) {
            setErrorCode(FLASH_ERR_ILLEGAL_SECURITY);
         }
      }
      controller->fccob0_3 = (F_PGM4 << 24) | address;
      controller->fccob4_7 = *data;
      rc = executeCommand(controller);
      if (rc != FLASH_ERR_OK) {
         setErrorCode(rc);
      }
      address += 4;
      flashData->frequency = address;
      data++;
   }
   flashData->flags &= ~DO_PROGRAM_RANGE;
}

//! Verify a range of flash against buffer
//!
void verifyRange(FlashData_t *flashData) {
   volatile FlashController *controller   = flashData->controller;
   uint32_t        address       = flashData->address;
   const uint32_t *data          = flashData->dataAddress;
   uint32_t        numLongwords  = flashData->dataSize>>2;
   
   if ((flashData->flags&DO_VERIFY_RANGE) == 0) {
      return;
   }
   if ((address & 0x03) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
//   // Initialise CRC
//   CRC_CTRL  = CRC_CTRL_TCRC;
//   CRC_GPOLY = 0x13451234;
//   CRC_CTRL  = CRC_CTRL_TCRC|CRC_CTRL_WAS;
//   CRC_CRC   = 0xFFFFFFFF;
//   CRC_CTRL  = CRC_CTRL_TCRC;
   
   // Verify words
   while (numLongwords-- > 0) {
      int rc;
      controller->fccob0_3 = (F_PGMCHK << 24) | address;
      controller->fccob4_7 = (F_USER_MARGIN<<24) | 0;
      controller->fccob8_B = *data;
//      CRC_CRC       = *data;
      rc = executeCommand(controller);
      if (rc != FLASH_ERR_OK) {
         if (rc == FLASH_ERR_PROG_MGSTAT0) {
            rc = FLASH_ERR_VERIFY_FAILED;
         }
         setErrorCode(rc);         
      }
      address += 4;
      data++;
   }
   flashData->flags &= ~DO_VERIFY_RANGE;
}

//! Erase a range of flash
//!
void eraseRange(FlashData_t *flashData) {
   volatile FlashController *controller = flashData->controller;
   uint32_t address     = flashData->address;
   uint32_t endAddress  = address + flashData->dataSize - 1; // Inclusive
   uint32_t pageMask    = flashData->sectorSize-1U;
   int      rc;
   
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
   
   // Erase each block/page
   while (address <= endAddress) {
      controller->fccob0_3 = (F_ERSSCR << 24) | address;
      rc = executeCommand(controller);
      if (rc != FLASH_ERR_OK) {
         if (rc == FLASH_ERR_PROG_MGSTAT0) {
            rc = FLASH_ERR_ERASE_FAILED;
         }
         setErrorCode(rc);         
      }
      // Advance to start of next block
      address += flashData->sectorSize;
   }
   flashData->flags &= ~DO_ERASE_RANGE;
}

#if 1
//! Check that a range of flash is blank (=0xFFFF)
//!
void blankCheckRange(FlashData_t *flashData) {
#define  itemSize 4
   uint32_t *address  = (uint32_t *)(flashData->address);
   uint32_t numItems  = (flashData->dataSize+itemSize-1)/itemSize;
   
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
#else
//! Check that a range of flash is blank (=0xFFFF)
//!
void blankCheckRange(FlashData_t *flashData) {
   static const uint32_t  elementSize = 8; // Size of element verified
   volatile FlashController       *controller  = flashData->controller;
   uint32_t               address     = flashData->address;
   uint32_t               numElements = (flashData->dataSize+elementSize-1)/elementSize;

   if ((flashData->flags&DO_BLANK_CHECK_RANGE) == 0) {
      return;
   }
   if ((address & (elementSize-1)) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   while (numElements>0) {
      int rc;
      uint16_t num = 0x8000;
      if (num>numElements) {
         num = numElements;
      }
      controller->fccob0_3 = (F_RD1SEC << 24) | address;
      controller->fccob4_7 = (num <<16) | (F_USER_MARGIN<<8) | 0;
      rc = executeCommand(controller);
      if (rc != FLASH_ERR_OK) {
         if (rc == FLASH_ERR_PROG_MGSTAT0) {
            rc = FLASH_ERR_ERASE_FAILED;
         }
//         flashData->frequency = controller->fccob0_3; // debug
//         flashData->address   = controller->fccob4_7;
         setErrorCode(rc);         
      }
      numElements -= num;
      address     += elementSize*num;
   }
   flashData->flags &= ~DO_BLANK_CHECK_RANGE;
}
#endif
//! Partition FlexNVM/EEPROM 
//!
void programPartition(FlashData_t *flashData) {
   int rc;
   volatile FlashController *controller = flashData->controller;
   if ((flashData->flags&DO_PARTITION_FLEXNVM) == 0) {
      return;
   }
   controller->fccob0_3 = (F_PGMPART << 24)|0;
   controller->fccob4_7 = flashData->frequency;
   rc = executeCommand(controller);
   if (rc != FLASH_ERR_OK) {
      setErrorCode(rc);         
   }
   flashData->flags &= ~DO_PARTITION_FLEXNVM;
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
   // Disable watchdog
   WDOG_UNLOCK  = WDOG_UNLOCK_SEQ_1;
   WDOG_UNLOCK  = WDOG_UNLOCK_SEQ_2;
   WDOG_STCTRLH = WDOG_DISABLED_CTRL;
#endif
   
   // Handle on programming data
   flashData = gFlashProgramHeader.flashData;

   // Indicate not complete
   flashData->flags &= ~IS_COMPLETE;
   
   // No errors so far
   flashData->errorCode = FLASH_ERR_OK;
   
   if (flashData->controller == NULL) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   // Clear invalid/unused address bits
   // A23 is used for Flash block number
   flashData->address &= 0x008FFFFFUL;
   
   initFlash(flashData);
   eraseFlashBlock(flashData);
   programPartition(flashData) ;
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
asm void asm_entry(void) {
#ifndef DEBUG
   // Setup the stack before we attempt anything else
   lda   r0,__stacktop
   mov   sp,r0
   bl    entry
   bkpt  0
#else
   lda   r0,entry
   bx    r0
   rts
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
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTFL_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000040,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTFL_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x000000440,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTFL_BASE_ADDRESS,
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
   /* controller */ FTFL_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000C40,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_E
static const FlashData_t flashdataE = {
   /* flags      */ DO_INIT_FLASH|DO_UNLOCK_FLASH,
   /* controller */ FTFL_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
};
#elif TEST == 2
// Unlock flash
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_UNLOCK_FLASH|DO_VERIFY_RANGE,
   /* controller */ FTFL_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 3
// Lock Flash 
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_LOCK_FLASH|DO_VERIFY_RANGE,
   /* controller */ FTFL_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 4
// Not used
static const FlashData_t flashdataA = {
   /* flags      */ DO_TIMING_LOOP,
   /* controller */ FTFL_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 5
// Set erasing ranges
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* controller */ FTFL_BASE_ADDRESS,
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
   /* controller */ FTFL_BASE_ADDRESS,
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
   /* controller */ FTFL_BASE_ADDRESS,
   /* frequency  */ 0,
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTFL_BASE_ADDRESS,
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
   /* controller */ FTFL_BASE_ADDRESS,
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
   /* controller */ FTFL_BASE_ADDRESS,
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
//                                 (FTFL_FSEC_KEY_ENABLE|FTFL_FSEC_MEEN_DISABLE|FTFL_FSEC_FSLACC|FTFL_FSEC_UNSEC),0xFF,0xFF,0xFF,}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTFL_BASE_ADDRESS,
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
   WDOG_UNLOCK  = WDOG_UNLOCK_SEQ_1;
   WDOG_UNLOCK  = WDOG_UNLOCK_SEQ_2;
   WDOG_STCTRLH = WDOG_DISABLED_CTRL;
      
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
asm void asm_testApp(void) {
   // Setup the stack before we attempt anything else
   lda   r0,__stacktop
   mov   sp,r0
   bl    testApp
}
#endif
