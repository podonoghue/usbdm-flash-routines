//!
//! Flash programming code (HCS08-PTxx-flash-program.s19)
//!
//! Families
//!   MC9S08PTxx
//!
//! CPU
//!   CPU08
//!
//! CPU Memory accesses are limited to 64K
//!
//!============================================================================
//!   WARNING  WARNING  WARNING  WARNING  WARNING  WARNING  WARNING   WARNING 
//!  
//! The WDOG address is hard-coded in this routine due to HCS08 CPU limitations
//!
//!============================================================================
//!   WARNING  WARNING  WARNING  WARNING  WARNING  WARNING  WARNING   WARNING 
//!
//! History
//! =======================================================================================================
//! 26 Apr 22 | Changed WDOG to use refresh rather than disable                                 V4.10.6.140
//!  4 Mar 14 | Removed unnecessary alignment check on EEPROM                                   V4.10.6.120
//! =======================================================================================================
#pragma CODE_SEG code

typedef unsigned long  uint32_t;
typedef unsigned int   uint16_t;
typedef unsigned char  uint8_t;

#ifndef NULL
#define NULL ((void*)0)
#endif

#define USE_ASM

//#define DEBUG

//==========================================================================================================
// Target defines

#ifdef DEBUG
#define FLASH_REG_BASE         ((FlashController*) 0x3020)  // For testing
// This is the smallest unit of Flash that can be erased
#define FLASH_SECTOR_SIZE      (1024) // Flash 1024 bytes size (used for stride in erase)
#define EEPROM_SECTOR_SIZE     (256)  // EEprom 256 bytes size (used for stride in erase)
#endif

typedef struct {
   volatile uint8_t fclkdiv;
   volatile uint8_t fsec;
   volatile uint8_t fccobix;
   volatile uint8_t res1;
   volatile uint8_t fcnfg;
   volatile uint8_t res2;
   volatile uint8_t fstat;
   volatile uint8_t res3;
   volatile uint8_t fprot;   //!< Flash protection
   volatile uint8_t res4;
   union {
      volatile uint16_t w;
      volatile uint8_t  b[2];
   } fccob;
   volatile uint8_t  fopt;
} FlashController;

#define FSTAT_OFFSET              6

#define fclkdiv_FDIVLD            (1<<7)
                                 
#define FSTAT_CCIF_OFF            (7)
#define FSTAT_ACCERR_OFF          (5)
#define FSTAT_FPVIOL_OFF          (4)
#define FSTAT_MGBUSY_OFF          (3)
#define FSTAT_MGSTAT1_OFF         (1)
#define FSTAT_MGSTAT0_OFF         (0)

#define FSTAT_CCIF                (1<<FSTAT_CCIF_OFF) 	 //!< Command complete
#define FSTAT_ACCERR              (1<<FSTAT_ACCERR_OFF)  //!< Access error
#define FSTAT_FPVIOL              (1<<FSTAT_FPVIOL_OFF)  //!< Protection violation
#define FSTAT_MGBUSY              (1<<FSTAT_MGBUSY_OFF)  //!< Memory controller busy 
#define FSTAT_MGSTAT1             (1<<FSTAT_MGSTAT1_OFF) //!< Command completion status
#define FSTAT_MGSTAT0             (1<<FSTAT_MGSTAT0_OFF)  

// Flash commands
#define FCMD_ERASE_ALL_BLOCKS     (0x08)
#define FCMD_ERASE_FLASH_BLOCK    (0x09)

#define FCMD_PROGRAM_FLASH        (0x06)

#define FCMD_ERASE_FLASH_SECTOR   (0x0A)

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

#define IS_COMPLETE            (1<<15)
                             
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
                               
#define CAP_RELOCATABLE        (1<<15) // Code is relocatable

//#define ADDRESS_LINEAR (1UL<<31) // Indicate address is linear
//#define ADDRESS_EEPROM (1UL<<30) // Indicate address lies within EEPROM

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

#define FLASH_ERR_PROG_ACCERR_NUM 8
#define FLASH_ERR_PROG_FPVIOL_NUM 9

typedef void (*EntryPoint_t)(void);

// Describes a block to be programmed & result
typedef struct {
   uint16_t           errorCode;    //  0: Error code from action
   uint16_t           flags;        //  2: Controls actions of routine
   FlashController   *controller;   //  4: Ptr to flash controller
   uint16_t           unused;       //  6: Address of Watchdog
   uint16_t           frequency;    //  8: Target frequency (kHz)
   uint16_t           sectorSize;   // 10: Size of Flash memory sectors (smallest erasable block)
   uint32_t           address;      // 12: Linear memory address being accessed
   uint16_t           size;         // 16: Size of memory range being accessed
   const uint16_t    *data;         // 18: Ptr to data to program
} FlashData_t;                      

#define ERROR_CODE_OFFSET   0
#define FLAGS_OFFSET        2
#define CONTROLLER_OFFSET   4
 
//! Describe the flash programming code
//!
typedef struct {
   uint16_t         loadAddress;    //  0: Address where to load this image
   EntryPoint_t     entry;          //  2: Ptr to entry routine
   uint16_t         capabilities;   //  4: Capabilities of routine
   uint32_t         calibFactor;    //  8: Calibration factor for speed determination
   FlashData_t     *flashData;      // 12: Ptr to information about operation
} FlashProgramHeader_t;

//! Some stack space
#define STACK_SIZE 27
volatile uint8_t stackSpace[STACK_SIZE];

// Describes a block to be programmed & result
FlashData_t gFlashData;
                              
void asm_entry(void);
const FlashProgramHeader_t gFlashProgramHeader;

// Used by programmer to locate flashProgramHeader 
const FlashProgramHeader_t *const headerPtr = &gFlashProgramHeader;

//! Flash programming information table
//!
const FlashProgramHeader_t gFlashProgramHeader = {
     /* loadAddress   */  (uint16_t)&headerPtr,  // load address of image
     /* entry         */  asm_entry,             // entry point for code
     /* capabilities  */  CAP_BLANK_CHECK_RANGE|CAP_ERASE_RANGE|CAP_ERASE_BLOCK|
                          CAP_PROGRAM_RANGE|CAP_VERIFY_RANGE|
                          CAP_DATA_FIXED,
     /* clockFactor   */  0,
     /* flashData     */  &gFlashData,
};

#pragma CODE_SEG code
void  setErrorCode(uint8_t errorCode);
void  initFlash(void);
void  massEraseFlash(void);
void  programRange(void);
void  verifyRange(void);
void  eraseRange(void);
void  blankCheckRange(void);
void  entry(void);
void  testApp(void);

//! Set error code to return to BDM
//!
//! @note Doesn't return
//!
#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN
void setErrorCode(uint8_t errorCode) {
   (void)errorCode;
   // ENTRY : A = errorCode
   asm {
      ldhx  #@gFlashData
      clr   ERROR_CODE_OFFSET,x
      sta   ERROR_CODE_OFFSET+1,x
      lda   FLAGS_OFFSET,x
      ora   #((IS_COMPLETE>>8)&0xFF)
      sta   FLAGS_OFFSET,x
      bgnd
   }
}

////! Refresh watchdog
////!
//#pragma NO_ENTRY
//#pragma NO_EXIT
//#pragma NO_RETURN
//void refreshWatchdog(void) {
//#define WATCHDOG_COUNT $3032
//   asm {
//      pshx
//      ldhx  #$A602
//      sthx  WATCHDOG_COUNT
//      
//      ldhx  #$B480
//      sthx  WATCHDOG_COUNT
//      pulx
//      rts
//   }
//}

//! Does any initialisation required before accessing the Flash
//!
void initFlash(void) {
   FlashController *controller;
   if ((gFlashData.flags&DO_INIT_FLASH) == 0) {
      return;
   }
   controller = gFlashData.controller;

#ifdef DEBUG
   controller->fclkdiv = 0x0F;
#endif

   controller->fprot  = 0xFF;  // Unprotect Flash
        
   gFlashData.flags  &= ~DO_INIT_FLASH;
}

#ifdef USE_ASM
//! Launch & wait for Flash command to complete
//!
#pragma NO_ENTRY
#pragma NO_EXIT
#pragma NO_RETURN
void doFlashCommand(void) {
   asm {
      // HX=FlashController
      ldhx  gFlashData:CONTROLLER_OFFSET
      
      // Launch command
      lda   #FSTAT_CCIF
      sta   FSTAT_OFFSET,x
      
      // Wait for command complete
   loop:

      // HX=FlashController
      ldhx  gFlashData:CONTROLLER_OFFSET
      lda   FSTAT_OFFSET,x
      and   #FSTAT_CCIF|FSTAT_ACCERR|FSTAT_FPVIOL
      beq   loop
      
      // Check for errors
      bit   FSTAT_ACCERR_OFF
      beq   next1
      lda   #FLASH_ERR_PROG_ACCERR_NUM
      jmp   setErrorCode
      
   next1:
      bit   FSTAT_FPVIOL_OFF
      beq   next2
      lda   #FLASH_ERR_PROG_FPVIOL_NUM
      jmp   setErrorCode
      
      // All done
   next2:
      rts
   }
}
#else
//! Launch & wait for Flash command to complete
//!
void doFlashCommand(void) {
   uint8_t           fstat;
      
   // Launch command
   gFlashData.controller->fstat = FSTAT_CCIF;

   // Wait for command complete
   do {
      fstat = gFlashData.controller->fstat;
   } while ((fstat&(FSTAT_CCIF|FSTAT_ACCERR|FSTAT_FPVIOL)) == 0);
   if ((fstat & FSTAT_ACCERR) != 0) {
      setErrorCode(FLASH_ERR_PROG_ACCERR);
   }
   if ((fstat & FSTAT_FPVIOL) != 0) {
      setErrorCode(FLASH_ERR_PROG_FPVIOL);
   }
}
#endif

//! Erase an entire flash array
//!
void massEraseFlash(void) {
   FlashController *controller;
   uint16_t         addressH;
   if ((gFlashData.flags&DO_ERASE_BLOCK) == 0) {
      return;
   }
   controller = gFlashData.controller;
   addressH   = (uint16_t)(gFlashData.address>>16);

   // Clear any existing errors
   controller->fstat   = FSTAT_ACCERR|FSTAT_FPVIOL;
   
   // Write command & address with EEPROM modifier flag
   controller->fccobix = 0; controller->fccob.b[0] = FCMD_ERASE_FLASH_BLOCK; 
                            controller->fccob.b[1] = ((uint8_t)addressH);
   controller->fccobix = 1; controller->fccob.w    = (uint16_t)gFlashData.address;

   doFlashCommand();

   gFlashData.flags &= ~DO_ERASE_BLOCK;
}

//! Program a range of flash/EEprom from buffer
//!
void programRange(void) {
   FlashController *controller;
   uint16_t         addressH;
   uint16_t         addressL;
   const uint16_t  *data;
   
   if ((gFlashData.flags&DO_PROGRAM_RANGE) == 0) {
      return;
   }
   controller = gFlashData.controller;
   addressH   = (uint16_t)(gFlashData.address>>16);
   addressL   = (uint16_t)gFlashData.address;
   data       = gFlashData.data;

   // Clear any existing errors
   controller->fstat   = FSTAT_ACCERR|FSTAT_FPVIOL;

//   if (((uint8_t)(addressH>>8) & (ADDRESS_EEPROM>>24)) == 0)
   {
      uint16_t numPhrases = gFlashData.size/4;
      // Flash requires a multiple of longwords (4-byte)
      if ((addressL & 0x3) != 0) {
         setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
      }
      if ((gFlashData.size & 0x3) != 0) {
         setErrorCode(FLASH_ERR_ILLEGAL_PARAMS);
      }
      // Program 1 to 2 Flash phrases (2 words)
      while (numPhrases-- > 0) {
         // Write command
         controller->fccobix = 0; controller->fccob.b[0] = FCMD_PROGRAM_FLASH; 
                                  controller->fccob.b[1] = (uint8_t)addressH;
         controller->fccobix = 1; controller->fccob.w    = addressL;
         // 1st word
         controller->fccobix = 2; controller->fccob.w    = *data++;
         controller->fccobix = 3; controller->fccob.w    = *data++;
         if (numPhrases > 0) {
            // 2nd word
            numPhrases--;
            controller->fccobix = 4; controller->fccob.w    = *data++;
            controller->fccobix = 5; controller->fccob.w    = *data++;
         }
         doFlashCommand();
         addressL += 8;
      }
   }
//   else {
//      uint16_t numBytes = gFlashData.size;
//      // Program 1 to 4 EEPROM bytes
//      while (numBytes-- > 0) {
//         // Write command
//         controller->fccobix = 0; controller->fccob.b[0] = FCMD_PROGRAM_EEPROM; 
//                                  controller->fccob.b[1] = (uint8_t)addressH;
//         controller->fccobix = 1; controller->fccob.w    = addressL;
//         // 1st byte
//         controller->fccobix = 2; controller->fccob.b[1] = (uint8_t)((*data)>>8);
//         if (numBytes > 0) {
//            numBytes--;
//            // 2nd byte
//            controller->fccobix = 3; controller->fccob.b[1] = (uint8_t)(*data++);
//            if (numBytes > 0) {
//               numBytes--;
//               // 3rd byte
//               controller->fccobix = 4; controller->fccob.b[1] = (uint8_t)((*data)>>8);
//               if (numBytes > 0) {
//                  numBytes--;
//                  // 4th byte
//                  controller->fccobix = 5; controller->fccob.b[1] = (uint8_t)(*data++);
//               }
//            }
//         }
//         doFlashCommand();
//         addressL += 4;
//      }
//   }
   gFlashData.flags &= ~DO_PROGRAM_RANGE;
}

//! Verify a range of flash against buffer
//!
void verifyRange(void) {
   const uint8_t  *address;
   const uint8_t  *data;
   uint16_t        numBytes;

   if ((gFlashData.flags&DO_VERIFY_RANGE) == 0) {
      return;
   }
   address   = (const uint8_t *)gFlashData.address;
   data      = (const uint8_t *)gFlashData.data;
   numBytes  = gFlashData.size;

   // Verify bytes
   while (numBytes-- > 0) {
//      refreshWatchdog();
      if (*address++ != *data++) {
         setErrorCode(FLASH_ERR_VERIFY_FAILED);
      }
   }
   gFlashData.flags &= ~DO_VERIFY_RANGE;
}

//! Erase a range of flash
//!
void eraseRange(void) {
   FlashController *controller;
   uint16_t         addressH;
   uint16_t         addressL;
   uint16_t         endAddressL;
   uint16_t         sectorSize;
   uint16_t         pageMask;
   uint8_t          eraseCommand;
   
   if ((gFlashData.flags&DO_ERASE_RANGE) == 0) {
      return;
   }
   controller  = gFlashData.controller;
   addressH    = (gFlashData.address>>16);
   addressL    = gFlashData.address&0xFFFF;
   endAddressL = addressL + (gFlashData.size-1); // Inclusive
   sectorSize  = gFlashData.sectorSize;
   pageMask    = ~(sectorSize-1U);
   
   // Check for empty range
   if (gFlashData.size == 0) {
      gFlashData.flags &= ~DO_ERASE_RANGE;
      return;
   }
   // Round start address to start of block (inclusive)
   addressL &= pageMask;
   
   // Round end address to end of block (exclusive)
   endAddressL += sectorSize;
   endAddressL &= pageMask;

//   if (((uint8_t)(addressH>>8) & (ADDRESS_EEPROM>>24)) != 0) {
//      eraseCommand = FCMD_ERASE_EEPROM_SECTOR;
//   }
//   else {
      eraseCommand = FCMD_ERASE_FLASH_SECTOR;
//   }
   // Clear any existing errors
   controller->fstat   = FSTAT_ACCERR|FSTAT_FPVIOL;

   // Erase each sector
   while (addressL != endAddressL) {
      // Write command
      controller->fccobix = 0; controller->fccob.b[0] = eraseCommand; 
                               controller->fccob.b[1] = addressH&0xFF;
      controller->fccobix = 1; controller->fccob.w    = addressL;
      doFlashCommand();
      // Advance to start of next sector
      addressL += sectorSize;
   }
   gFlashData.flags &= ~DO_ERASE_RANGE;
}

//! Check that a range of flash is blank (=0xFFFF)
//!
void blankCheckRange() {
   uint8_t   *address;
   uint16_t   numBytes;

   if ((gFlashData.flags&DO_BLANK_CHECK_RANGE) == 0) {
      return;
   }
   address  = (uint8_t *)gFlashData.address;
   numBytes = gFlashData.size;
   
   while (numBytes>0) {
//      refreshWatchdog();
      if (*address++ != (uint8_t)-1) {
         setErrorCode(FLASH_ERR_ERASE_FAILED);
      }
      numBytes--;
   }
   gFlashData.flags &= ~DO_BLANK_CHECK_RANGE;
}

//! Main C entry point
//!
void entry(void) {
   initFlash();
   massEraseFlash();
   eraseRange();
   blankCheckRange();
   programRange();
   verifyRange();

   setErrorCode(FLASH_ERR_OK);
}

//! Low level entry point
//! 
#pragma NO_ENTRY
#pragma NO_EXIT
void asm_entry(void) {
   asm {
      // Disable interrupts
      sei
      
      // Setup the stack
      ldhx   #@stackSpace:STACK_SIZE-1
      txs
      jmp   entry
   }
}

#ifdef DEBUG
#define TEST 1
#if TEST == 1
// Unpaged Flash address
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF,
                                 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FLASH_REG_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x0000C000,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t *)buffer,
};
#elif TEST == 2
// Paged Flash address
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF,
                                 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FLASH_REG_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* sectorSize */ EEPROM_SECTOR_SIZE,
   /* address    */ 0xF88000,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t *)buffer,
};
#elif TEST == 3
// Paged EEPROM (or DFlash) address
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF,
                                 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FLASH_REG_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* sectorSize */ EEPROM_SECTOR_SIZE,
   /* address    */ 0xFC0800,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t *)buffer,
};
#elif TEST == 4
// Fixed EEPROM (or DFlash) address
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF,
                                 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FLASH_REG_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* sectorSize */ EEPROM_SECTOR_SIZE,
   /* address    */ 0x000C00,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t *)buffer,
};
#elif TEST == 5
// Programming general flash
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
                                 0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF}; 
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FLASH_REG_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0xC000,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t *)buffer,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FLASH_REG_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0xC200,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t *)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FLASH_REG_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0xC440,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t *)buffer,
};
#define DO_D
static const FlashData_t flashdataD = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FLASH_REG_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0xFF00,
   /* size       */ sizeof(buffer),
   /* data       */ (uint16_t *)buffer,
};
#endif

#pragma NO_RETURN
//! Dummy test program for debugging
void testApp(void) {
   FlashProgramHeader_t *fph = (FlashProgramHeader_t*) &gFlashProgramHeader;
   
   // Disable COP
   *(gFlashProgramHeader.copctlAddress) = 0;
   
   fph->flashData = (FlashData_t *)&flashdataA;
   asm_entry();
#ifdef DO_B
   fph->flashData = (FlashData_t *)&flashdataB;
   asm_entry();
#endif
#ifdef DO_C
   fph->flashData = (FlashData_t *)&flashdataC;
   asm_entry();
#endif
#ifdef DO_D
   fph->flashData = (FlashData_t *)&flashdataD;
   asm_entry();
#endif
#ifdef DO_E
   fph->flashData = (FlashData_t *)&flashdataE;
   asm_entry();
#endif
   asm {
      bgnd
   }
}
#endif
