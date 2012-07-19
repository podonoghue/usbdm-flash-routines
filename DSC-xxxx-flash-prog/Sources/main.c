//*******************************************************
// Note all addresses & sizes are in words (16 bits)
//*******************************************************

/*
  This code is used with the following devices:
  
	MC56F8002/MC56F8006
	MC56F8014
	MC56F8245/MC56F8246/MC56F8247/MC56F8255/MC56F8256/MC56F8257

	MC56F8322/MC56F8122
	MC56F8323/MC56F8123
	
	MC56F8365/MC56F8165
*/

typedef signed char int8_t;
typedef short int   int16_t;
typedef long int    int32_t;

typedef unsigned char		uint8_t;
typedef unsigned short int  uint16_t;
typedef unsigned long int   uint32_t;

//#include <stdint.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

#define MC56F8014 1
#define MC56F8323 2
#define MC56F8365 3
#define MC56F8033 4

//#define DEBUG

//==========================================================================================================
// Target defines

#if (TARGET == MC56F8014)   
#define CLOCK_CALIB (444039)               // 1 second count for a 4000 kHz sysclock speed MC568014 chip
#define ISOVERLAYED (CAP_DSC_OVERLAY)
#elif (TARGET == MC56F8033)   
#define CLOCK_CALIB (444039)               // 1 second count for a 4000 kHz sysclock speed MC568014 chip
#define ISOVERLAYED (CAP_DSC_OVERLAY)
#elif (TARGET == MC56F8323)   
#define CLOCK_CALIB (508214)               // 1 second count for a 4000 kHz sysclock speed MC568323 chip
#define ISOVERLAYED (0)
#elif (TARGET == MC56F8365)   
#define CLOCK_CALIB (508214)               // 1 second count for a 4000 kHz sysclock speed MC568365 chip
#define ISOVERLAYED (0)
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
   volatile uint16_t  data;
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
#define DO_MASS_ERASE         (1<<1) // Mass erase flash array
#define DO_ERASE_RANGE        (1<<2) // Erase range (including option region)
#define DO_BLANK_CHECK_RANGE  (1<<3) // Blank check region
#define DO_PROGRAM_RANGE      (1<<4) // Program range (including option region)
#define DO_VERIFY_RANGE       (1<<5) // Verify range
#define DO_UNLOCK_FLASH       (1<<6) // Unlock flash with default security options  (+mass erase if needed)
#define DO_LOCK_FLASH         (1<<7) // Lock flash with default security options
#define DO_TIMING_LOOP        (1<<8) // Do timing loop
// 9 - 14 reserved
#define IS_COMPLETE           (1<<15)

// Capability masks
#define CAP_MASS_ERASE      (1<<1)
#define CAP_ERASE_RANGE     (1<<2)
#define CAP_BLANK_CHECK     (1<<3)
#define CAP_PROGRAM_RANGE   (1<<4)
#define CAP_VERIFY_RANGE    (1<<5)
#define CAP_UNLOCK_FLASH    (1<<6)
#define CAP_TIMING          (1<<7)
#define CAP_DSC_OVERLAY     (1<<8)

//
#define CAP_ALIGN_OFFS      (13)
#define CAP_ALIGN_1         (0<<CAP_ALIGN_OFFS) // No alignment
#define CAP_ALIGN_2         (1<<CAP_ALIGN_OFFS) // Align on even memory address
#define CAP_ALIGN_4         (2<<CAP_ALIGN_OFFS) // Align on quad memory address
#define CAP_ALIGN_8         (3<<CAP_ALIGN_OFFS) // Align on octal memory address

#define CAP_RELOCATABLE     (1<<15)

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
     FLASH_ERR_ILLEGAL_SECURITY  = (12)  // Kinetis - Illegal value for security location
} FlashDriverError_t;

// This is the smallest unit of Flash that can be erased
#define FLASH_SECTOR_SIZE   (256) // block size (words) (used for stride in erase)

typedef void (*EntryPoint_t)(void);

// Describes a block to be programmed & result
typedef struct {
   uint16_t         flags;             // Controls actions of routine
   uint16_t         errorCode;         // Error code from action
   FlashController *controller;        // Ptr to flash controller
   uint16_t         frequency;         // Target frequency (kHz)
   uint16_t         sectorSize;        // Size of Flash memory sectors (smallest erasable block)
   uint32_t         address;           // Memory address being accessed
   uint16_t         size;              // Size of memory range being accessed
   uint16_t         pad;
   const uint16_t  *data;              // Ptr to data to program
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
   uint16_t        *loadAddress;       // 0  Address where to load this image
   EntryPoint_t     entry;             // 2  Ptr to entry routine
   uint16_t         capabilities;      // 4  Capabilities of routine
   uint16_t         calibFrequency;    // 5  Frequency used for calibFactor
   uint32_t         calibFactor;       // 6  Calibration factor for speed determination
   FlashData_t     *flashData;         // 8  Ptr to information about operation
} FlashProgramHeader_t;

#define FLASH_DATA_OFFSET 8

extern void asm_entry(void);
extern FlashData_t flashData;

extern uint16_t loadAddress[];

#define CAPABILITIES (CAP_BLANK_CHECK|CAP_ERASE_RANGE|CAP_MASS_ERASE|\
                      CAP_PROGRAM_RANGE|ISOVERLAYED|CAP_VERIFY_RANGE|CAP_ALIGN_1)

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
void  massEraseFlash(void);
void  programRange(void);
void  verifyRange(void);
void  eraseRange(void);
void  blankCheckRange(void);
void  asmTimingLoop(uint32_t *);
void  timingLoop();
void  doTiming();
void  entry(void);
void  testApp(void);

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
static void writePgmSpace(uint32_t address, uint16_t data) {
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
static uint16_t readPgmSpace(uint32_t address) {
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
   controller->clkd = CLK_DIV;
   controller->cr    = 0x00;  // 0 => Program or Boot flash, 1 => Data flash (8323)
   controller->prot  = 0x00;  // Unprotect flash
   controller->protb = 0x00;  // Unprotect boot flash
#endif   

   // Check if clock divider set
   if ((controller->clkd & CFMCLKD_DIVLD) == 0) {
      setErrorCode(FLASH_ERR_CLKDIV);
   }
   // Set flash bank select
   controller->cr = ((flashData->address)>>24)&0x07;
   flashData->flags &= ~DO_INIT_FLASH;
}

//! Erase entire flash array
//!
void massEraseFlash(void) {
   uint16_t         fstat;
   FlashData_t     *flashData = getHeader();
   FlashController *controller = flashData->controller;
   if ((flashData->flags&DO_MASS_ERASE) == 0) {
      return;
   }
   // Clear any existing errors (1 bit at a time)
   controller->ustat   = FSTAT_ACCERR;
   controller->ustat   = FSTAT_PVIOL;
   
   // Write dummy data to Flash
   writePgmSpace(flashData->address, 0xFFFF);

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
   flashData->flags &= ~DO_MASS_ERASE;
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
   data       = flashData->data;
   numWords   = flashData->size;

   // Clear any existing errors (1 bit at a time)
   controller->ustat   = FSTAT_ACCERR;
   controller->ustat   = FSTAT_PVIOL;

   // Program words
   while (numWords-- > 0) {
      // Write data to flash P:address
      writePgmSpace(address, *data);

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
   const uint16_t *data;
   uint16_t        numWords;

   FlashData_t *flashData = getHeader();
   if ((flashData->flags&DO_VERIFY_RANGE) == 0) {
      return;
   }
   address   = (uint32_t)flashData->address;
   data      = flashData->data;
   numWords  = flashData->size;

   // Verify words
   while (numWords-- > 0) {
      if (readPgmSpace(address++) != *data++) {
         //flashData->data      = address-1;               // debug
         //flashData->size      = readPgmSpace(address-1); // debug
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
   endAddress  = address + flashData->size-1; // Inclusive
   sectorSize  = flashData->sectorSize;
   pageMask    = sectorSize-1U;
   
   // Check for empty range before block rounding
   if (flashData->size == 0) {
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
      writePgmSpace(address, 0xFFFF);

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
   uint8_t      memorySpace;
   uint32_t     address;
   uint16_t     numWords;
   FlashData_t *flashData = getHeader();
   if ((flashData->flags&DO_BLANK_CHECK_RANGE) == 0) {
      return;
   }
   memorySpace  = *(uint8_t *)&flashData->address;
   address      = flashData->address;
   numWords     = flashData->size;

   while (numWords>0) {
      if (readPgmSpace(address) != 0xFFFF) {
         //flashData->data      = address-1;               // debug
         //flashData->size      = readPgmSpace(address-1); // debug
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
   initFlash();
   doTiming();
   massEraseFlash();
   eraseRange();
   blankCheckRange();
   programRange();
   verifyRange();

   setErrorCode(FLASH_ERR_OK);
}

#ifndef DEBUG
void testApp(void) {
}
#else
#define TEST 6
#if TEST == 1
// Programming general flash
static const uint16_t buffer[] = {0x0011,0x2233,0x4455,0x6677,0x8899,0xAABB,0xCCDD,0xEEFF,
                                  0x0011,0x2233,0x4455,0x6677,0x8899,0xAABB,0xCCDD,0xEEFF,}; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ (uint16_t *)0x2100,
   /* size       */ sizeof(buffer)/2,
   /* pad        */ 0,
   /* data       */ buffer,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ (uint16_t *)0x2200,
   /* size       */ sizeof(buffer)/2,
   /* pad        */ 0,
   /* data       */ buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ (uint16_t *)0x2300,
   /* size       */ sizeof(buffer)/2,
   /* pad        */ 0,
   /* data       */ buffer,
};
#define DO_D
static const FlashData_t flashdataD = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ (uint16_t *)0x2400,
   /* size       */ sizeof(buffer)/2,
   /* pad        */ 0,
   /* data       */ buffer,
};
#define DO_E
static const FlashData_t flashdataE = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_UNLOCK_FLASH,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 2
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_MASS_ERASE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ (uint16_t *)0x7FF0,
   /* size       */ 0,
   /* pad        */ 0,
   /* data       */ NULL,
};
#define DO_B
static const FlashData_t flashdataB = {
   /* flags      */ DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ (uint16_t *)0x7F00,
   /* size       */ 0,
   /* pad        */ 0,
   /* data       */ NULL,
};
#elif TEST == 3
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE,DO_MASS_ERASE
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ (uint16_t *)0x2400,
   /* size       */ 0x1000,
   /* pad        */ 0,
   /* data       */ NULL,
};
#elif TEST == 4
static const FlashData_t flashdataA = {
   /* flags      */ DO_TIMING_LOOP,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 5
// Set erasing ranges
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0xC000,
   /* size       */ (0xC03e-0xC000)/2,
};
#define DO_B
// Set erasing ranges
static const FlashData_t flashdataB = {
   /* flags      */ DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x83001FF0,
   /* size       */ (0xCC3A-0xC235)/2,
};
#elif TEST == 6
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF}; 
// Mass erase 
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_MASS_ERASE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00003FF0,
   /* size       */ 0,
};
#define DO_B
// Mass erase 
static const FlashData_t flashdataB = {
   /* flags      */ DO_INIT_FLASH|DO_MASS_ERASE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x83001FF0,
   /* size       */ 0,
};
#define DO_C
// Mass erase 
static const FlashData_t flashdataC = {
   /* flags      */ DO_INIT_FLASH|DO_MASS_ERASE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00003FF0,
   /* size       */ 0,
};
#elif TEST == 7
// Checking security region actions
// Program region overlapping security area
static const uint16_t buffer[] = {0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, }; 

static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 4000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ (uint16_t*)0x3FF7,
   /* size       */ sizeof(buffer)/2,
   /* pad        */ 0,
   /* data       */ buffer,
};
#elif TEST == 8
static const FlashData_t flashdataA = {
   /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
   /* errorCode  */ 0xAA55,
   /* controller */ FTSR_BASE,
   /* frequency  */ 8000, /* nominally 8MHz */
   /* sectorSize */ FLASH_SECTOR_SIZE,
   /* address    */ 0x00002100,
   /* size       */ 0x001,
   /* pad        */ 0,
   /* data       */ NULL
};
#endif

//#pragma MESSAGE DISABLE C12056
//! Dummy test program for debugging
//#pragma NO_RETURN
void testApp(void) {
   FlashData_t *flashData = getHeader();

   // Disable COP
   //*(flashProgramHeader.copctlAddress) = 0;
   
   *flashData = flashdataA;
   entry();
#ifdef DO_B
   *flashData = flashdataB;
   entry();
#endif
#ifdef DO_C
   *flashData = flashdataC;
   entry();
#endif
#ifdef DO_D
   *flashData = flashdataD;
   entry();
#endif
#ifdef DO_E
   *flashData = flashdataE;
   entry();
#endif
   asm {
      debughlt
   }
}
#endif
