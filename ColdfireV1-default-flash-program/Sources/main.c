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
#define NV_SECURITY_ADDRESS        (0x00000400)
#define NV_SEC_KEYEN               (1<<31)
#define NV_SEC_SECSTAT             (1<<30)
#define NV_SEC_SECURE              (0x4AC8)
#define NV_SEC_UNSECURE            (0xFFFF)
#define NV_SEC_DEFAULT_UNSECURED   (NV_SEC_KEYEN|NV_SEC_UNSECURE)
#define NV_SEC_DEFAULT_SECURED     (NV_SEC_KEYEN|NV_SEC_SECURE)

#ifdef DEBUG
//#define FTSR_BASE ((FlashController*) 0xFFFF82E0) // CN128
#define FTSR_BASE ((FlashController*) 0x00FF9820)  // AC256
#define SOPT_ADDRESS              ((uint8_t *) 0xFFFF9802)
#else
#define SOPT_ADDRESS              ((uint8_t *) NULL)
#endif


#pragma pack(1)
typedef struct {
   uint8_t fcdiv;
   uint8_t fopt;
   uint8_t res1;
   uint8_t fcnfg;
   uint8_t fprot;
   uint8_t fstat;
   uint8_t fcmd;
} FlashController;
#pragma pack(0)

#define FCDIV_FDIVLD              (1<<7)

#define FSTAT_FCBEF   (1<<7)  //!< Command buffer empty
#define FSTAT_FCCF    (1<<6)  //!< Command complete
#define FSTAT_FPVIOL  (1<<5)  //!< Protection violation
#define FSTAT_FACCERR (1<<4)  //!< Access error
#define FSTAT_FBLANK  (1<<2)  //!< Blank check OK

#define CFMCLKD_DIVLD   (1<<7)
#define CFMCLKD_PRDIV8  (1<<6)
#define CFMCLKD_FDIV    (0x3F)

// Flash commands
#define FCMD_PAGE_ERASE_VERIFY    (0x05)
#define FCMD_WORD_PROGRAM         (0x20)
#define FCMD_BURST_PROGRAM        (0x25)
#define FCMD_PAGE_ERASE           (0x40)
#define FCMD_MASS_ERASE           (0x41)

//==========================================================================================================
// Operation masks
//
//  The following combinations (amongst others) are sensible:
//  DO_PROGRAM_RANGE|DO_VERIFY_RANGE program & verify range assuming previously erased
//  DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE check blank, program & verify range
//  DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE do all steps
//  DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE erase and blank check
//
#define DO_INIT_FLASH         (1<<0) // Do initialisation of flash 
#define DO_ERASE_BLOCK        (1<<1) // Erase entire flash block e.g. Flash, FlexNVM etc
#define DO_ERASE_RANGE        (1<<2) // Erase range (including option region)
#define DO_BLANK_CHECK_RANGE  (1<<3) // Blank check region
#define DO_PROGRAM_RANGE      (1<<4) // Program range (including option region)
#define DO_VERIFY_RANGE       (1<<5) // Verify range
#define DO_TIMING_LOOP        (1<<6) // Do timing loop
#define DO_PARTITION_FLEXNVM  (1<<7) // Program FlexNVM DFLASH/EEPROM partitioning

#define IS_COMPLETE           (1<<31)
                             
// Capability masks          
#define CAP_MASS_ERASE        (1<<1)
#define CAP_ERASE_RANGE       (1<<2)
#define CAP_BLANK_CHECK       (1<<3)
#define CAP_PROGRAM_RANGE     (1<<4)
#define CAP_VERIFY_RANGE      (1<<5)
#define CAP_UNLOCK_FLASH      (1<<6)
#define CAP_TIMING            (1<<7)
//                           
#define CAP_ALIGN_MASK        (3<<28)
#define CAP_ALIGN_BYTE        (0<<28)
#define CAP_ALIGN_2BYTE       (1<<28)
#define CAP_ALIGN_4BYTE       (2<<28)
#define CAP_RELOCATABLE       (1<<31)

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

//! Describe the flash programming code
typedef struct {
   uint32_t         loadAddress;       // Address where to load this image
   EntryPoint_t     entry;             // Ptr to entry routine
   uint32_t         capabilities;      // Capabilities of routine
   uint32_t         reserved;
   uint8_t         *soptAddress;       // Address of SOPT register
   FlashData_t     *flashData;         // Ptr to information about operation
} FlashProgramHeader_t;
#pragma pack(0)

asm void asm_entry(void);

#pragma define_section flashProgramHeader ".text" far_absolute R

//! Flash programming command table
//!
__declspec(flashProgramHeader) 
const FlashProgramHeader_t gFlashProgramHeader = {
     /* loadAddress  */ 0x00800000,        // load address of image
     /* entry        */ asm_entry,         // entry point for code
     /* capabilities */ CAP_BLANK_CHECK|CAP_ERASE_RANGE|CAP_MASS_ERASE|CAP_PROGRAM_RANGE|CAP_VERIFY_RANGE|CAP_UNLOCK_FLASH|CAP_ALIGN_4BYTE,
     /* reserved     */ 0x0,
     /* soptAddress  */ SOPT_ADDRESS,
     /* flashData    */ NULL,
};

void setErrorCode(int errorCode);
void initFlash(FlashData_t *flashData);
void eraseFlashBlock(FlashData_t *flashData);
void programRange(FlashData_t *flashData);
void verifyRange(FlashData_t *flashData);
void eraseRange(FlashData_t *flashData);
void blankCheckRange(FlashData_t *flashData);
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
   
   if ((flashData->flags&DO_INIT_FLASH) == 0)
      return;

   // Calculate FCDIV value
   frequency  = flashData->frequency;
   if (frequency < 300) {
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
   controller->fcdiv = (uint8_t)cfmclkd;
   
   // Check if clock divider correctly set
   if (controller->fcdiv != cfmclkd)
      setErrorCode(FLASH_ERR_CLKDIV);
   
   controller->fprot = 0xFF;  // Unprotect flash
   
   flashData->flags &= ~DO_INIT_FLASH;
}

//! Erase entire flash array
//!
void eraseFlashBlock(FlashData_t *flashData) {
   FlashController *controller = flashData->controller;
   uint32_t         address    = flashData->address;
   uint8_t          fstat;

   if ((flashData->flags&DO_ERASE_BLOCK) == 0) {
      return;
   }
   // Clear any existing errors
   controller->fstat = FSTAT_FACCERR|FSTAT_FPVIOL;

   // Write any data to flash address
   *(uint32_t*)(address) = 0xFFFFFFFF;
   
   // Set command
   controller->fcmd = FCMD_MASS_ERASE;

   // Launch command
   controller->fstat = FSTAT_FCBEF;
   asm {
      nop // allow FSTAT_FCBEF to clear
      nop
      nop
      nop
   }
   // Wait for command complete
   do {
      fstat = controller->fstat;
   } while ((fstat&(FSTAT_FCCF|FSTAT_FACCERR|FSTAT_FPVIOL)) == 0);
   if ((fstat & FSTAT_FACCERR ) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
      }
   if ((fstat & FSTAT_FPVIOL ) != 0) {
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
   uint8_t          fstat;
   
   if ((flashData->flags&DO_PROGRAM_RANGE) == 0) {
      return;
   }
   if ((address & 0x03) != 0) {
      setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
   }
   // Clear any existing errors
   controller->fstat = FSTAT_FACCERR|FSTAT_FPVIOL;

   // Program words
   while (numWords-- > 0) {
      // Write data to flash address
      *(uint32_t*)(address) = *data;

      // Set command
      controller->fcmd = FCMD_WORD_PROGRAM;

      // Launch command
      controller->fstat = FSTAT_FCBEF;
      asm {
         nop // allow FSTAT_CBEIF to clear
         nop
         nop
         nop
      }
      // Wait for buffer empty
      do {
         fstat = controller->fstat;
      } while ((fstat&(FSTAT_FCBEF|FSTAT_FACCERR|FSTAT_FPVIOL)) == 0);
      if ((fstat & FSTAT_FACCERR) != 0) {
         setErrorCode(FLASH_ERR_PROG_ACCERR);
      }
      if ((fstat & FSTAT_FPVIOL) != 0) {
         setErrorCode(FLASH_ERR_PROG_FPVIOL);
      }
      address += 4;
      data++;
   }
   // Wait for last command complete
   do {
      fstat = controller->fstat;
   } while ((fstat&(FSTAT_FCCF|FSTAT_FACCERR|FSTAT_FPVIOL)) == 0);
   if ((fstat & FSTAT_FACCERR) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
   }
   if ((fstat & FSTAT_FPVIOL) != 0) {
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
   uint8_t  fstat;
   
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
   controller->fstat = FSTAT_FACCERR|FSTAT_FPVIOL|FSTAT_FBLANK;

   // Erase each block/page
   while (address <= endAddress) {
      // Write dummy data to flash address
      *(uint32_t*)(address) = 0xFFFFFFFF;
      
      // Set command
      controller->fcmd = FCMD_PAGE_ERASE;

      // Launch command
      controller->fstat = FSTAT_FCBEF;
      asm {
         nop // allow FSTAT_CBEIF to clear
         nop
         nop
         nop
      }
      // Wait for buffer empty
      do {
         fstat = controller->fstat;
      } while ((fstat&(FSTAT_FCCF|FSTAT_FACCERR|FSTAT_FPVIOL)) == 0);
      if ((fstat & FSTAT_FACCERR) != 0) {
         setErrorCode(FLASH_ERR_PROG_ACCERR);
      }
      if ((fstat & FSTAT_FPVIOL) != 0) {
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
      if (*(uint16_t*)address != 0xFFFF) {
         setErrorCode(FLASH_ERR_ERASE_FAILED);
      }
      numWords--;
      address += 2;
   }
   flashData->flags &= ~DO_BLANK_CHECK_RANGE;
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

   // Disable COP
   *gFlashProgramHeader.soptAddress = 0x03;
   
   // Handle on programming data
   flashData = gFlashProgramHeader.flashData;

   // Indicate not complete
   flashData->flags &= ~IS_COMPLETE;
   
   // No errors so far
   flashData->errorCode = FLASH_ERR_OK;
   
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

   jmp     entry
}

#ifndef DEBUG
__declspec(register_abi)
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
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000040,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x000000440,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000840,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_D
static const FlashData_t flashdataD = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000C40,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_E
static const FlashData_t flashdataE = {
   /* flags      */ DO_INIT_FLASH|DO_UNLOCK_FLASH,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
};
#elif TEST == 2
// Unlock flash
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_UNLOCK_FLASH|DO_VERIFY_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 3
// Lock Flash 
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_LOCK_FLASH|DO_VERIFY_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 4
// Not used
static const FlashData_t flashdataA = {
   /* flags      */ DO_TIMING_LOOP,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 5
// Set erasing ranges
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000045,
   /* size       */ 0x312-0x45,
};
#define DO_B
// Set erasing ranges
static const FlashData_t flashdataB = {
   /* flags      */ DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
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
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00000800,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
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
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* errorCode  */ 0xAA55,
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x000003F0,
   /* size       */ sizeof(buffer),
   /* data       */ (uint32_t *)buffer,
};
#elif TEST == 8
// Checking security anti-lockup
//static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,
//                                 (FTFL_FSEC_KEY_ENABLE|FTFL_FSEC_MEEN_DISABLE|FTFL_FSEC_FSLACC|FTFL_FSEC_UNSEC)}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
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
   
   // Disable COP
   *gFlashProgramHeader.soptAddress = 0;
   
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

   jmp     testApp
}
#endif
