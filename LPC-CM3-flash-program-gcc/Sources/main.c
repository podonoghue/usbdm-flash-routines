/**
 *  Flash code for Kinetis FTFA memory (Cortex-M4 flash devices)
 *
 *  Summary
 *  MPU       Cortex-M0 (LPC11U14)
 *  LPC_ISP   Controller
 *
 * History
 *--------------------------------------------------------------------------------------------------
 *                                                                                     | V4.12.1.180
 *--------------------------------------------------------------------------------------------------
 */
#include <stdint.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

/** Clock frequency out of reset (Internal RC clock) */
#define RESET_CLOCK_FREQ_kHz (12000000/1000) // kHz

//==================================================================================================
// Target defines

// Vector Table Map Register
#define SYSMEMREMAP           (*(volatile uint32_t *)0x40048000)
#define SYSMEMREMAP_BOOT_ROM  0
#define SYSMEMREMAP_RAM       1
#define SYSMEMREMAP_FLASH     2

// Main clock source select register
#define MAINCLKSEL            (*(volatile uint32_t *)0x40048070)
#define MAINCLKSEL_IRC      0
#define MAINCLKSEL_PLL_IN   1
#define MAINCLKSEL_WDOG     2
#define MAINCLKSEL_PLL_OUT  3

// Main clock source update enable register
#define MAINCLKUEN              (*(volatile uint32_t *)0x40048074)
#define MAINCLKUEN_UPDATE_MASK  0

// Main clock source update enable register
#define SYSAHBCLKDIV          (*(volatile uint32_t *)0x40048078)
#define SYSAHBCLKDIV_DISABLE  0
#define SYSAHBCLKDIV_DIV(x)   ((x)&0xFF)

// CLKOUT clock source select register
#define CLKOUTSEL            (*(volatile uint32_t *)0x400480E0)
#define CLKOUTSEL_IRC        0
#define CLKOUTSEL_SYSOSC     1
#define CLKOUTSEL_WDOG       2
#define CLKOUTSEL_MAIN       3

// CLKOUT clock source update enable register
#define CLKOUTUEN                 (*(volatile uint32_t *)0x400480E4)
#define CLKOUTUEN_UPDATE_MASK     0

// Main clock source update enable register
#define CLKOUTDIV          (*(volatile uint32_t *)0x400480E8)
#define CLKOUTDIV_DISABLE  0
#define CLKOUTDIV_DIV(x)   ((x)&0xFF)

// CLKOUT clock source update enable register
#define SYSAHBCLKCTRL                  (*(volatile uint32_t *)0x40048080)
#define SYSAHBCLKCTRL_IOCON_MASK       (1<<16)

// CLKOUT clock source update enable register
#define SYSAHBCLKCTRL                  (*(volatile uint32_t *)0x40048080)
#define SYSAHBCLKCTRL_IOCON_MASK       (1<<16)

// CLKOUT clock source update enable register
#define IOCON                   ((volatile uint32_t *)0x40044000)
#define IOCON_FUNC(x)           (((x)&0x7)<<0)
#define IOCON_MODE(x)           (((x)&0x3)<<3)
#define PIO0_1                  (IOCON[1])

/*==================================================================================================
 * Operation masks
 *
 *  The following combinations (amongst others) are sensible:
 *  DO_PROGRAM_RANGE|DO_VERIFY_RANGE program & verify range assuming previously erased
 *  DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE do all steps
 */
#define DO_INIT_FLASH             (1<<0) // Do initialisation of flash
#define DO_ERASE_BLOCK            (1<<1) // Erase entire flash block e.g. Flash, FlexNVM etc
#define DO_ERASE_RANGE            (1<<2) // Erase range (including option region)
#define DO_BLANK_CHECK_RANGE      (1<<3) // Blank check region
#define DO_PROGRAM_RANGE          (1<<4) // Program range (including option region)
#define DO_VERIFY_RANGE           (1<<5) // Verify range
#define DO_TIMING_LOOP            (1<<8) // Counting loop to determine clock speed

#define IS_COMPLETE               (1<<31)

// Capability masks
#define CAP_ERASE_BLOCK           (1<<1)
#define CAP_ERASE_RANGE           (1<<2)
#define CAP_BLANK_CHECK_RANGE     (1<<3)
#define CAP_PROGRAM_RANGE         (1<<4)
#define CAP_VERIFY_RANGE          (1<<5)
#define CAP_UNLOCK_FLASH          (1<<6)
#define CAP_PARTITION_FLEXNVM     (1<<7)
#define CAP_TIMING                (1<<8)

#define CAP_DSC_OVERLAY           (1<<11) // Indicates DSC code in pMEM overlays xRAM
#define CAP_DATA_FIXED            (1<<12) // Indicates TargetFlashDataHeader is at fixed address

#define CAP_RELOCATABLE           (1<<31)

#define ADDRESS_LINEAR            (1UL<<31) // Indicate address is linear

/**
 * IAP Error codes
 */
typedef enum {
   /*  0 */ CMD_SUCCESS,                    // Command is executed successfully. Sent by ISP handler only when command given by the host has been completely and successfully executed.
   /*  1 */ INVALID_COMMAND,                // Invalid command.
   /*  2 */ SRC_ADDR_ERROR,                 // Source address is not on word boundary.
   /*  3 */ DST_ADDR_ERROR,                 // Destination address is not on a correct boundary.
   /*  4 */ SRC_ADDR_NOT_MAPPED,            // Source address is not mapped in the memory map. Count value is taken in to consideration where applicable.
   /*  5 */ DST_ADDR_NOT_MAPPED,            // Destination address is not mapped in the memory map. Count value is taken in to consideration where applicable.
   /*  6 */ COUNT_ERROR,                    // Byte count is not multiple of 4 or is not a permitted value.
   /*  7 */ INVALID_SECTOR,                 // Sector number is invalid or end sector number is greater than start sector number.
   /*  8 */ SECTOR_NOT_BLANK,               // Sector is not blank.
   /*  9 */ SECTOR_NOT_PREPARED,            // Command to prepare sector for write operation was not executed.
   /* 10 */ COMPARE_ERROR,                  // Source and destination data not equal.
   /* 11 */ BUSY,                           // Flash programming hardware interface is busy.
   /* 12 */ PARAM_ERROR,                    // Insufficient number of parameters or invalid parameter.
   /* 13 */ ADDR_ERROR,                     // Address is not on word boundary.
   /* 14 */ ADDR_NOT_MAPPED,                // Address is not mapped in the memory map. Count value is taken in to consideration where applicable.
   /* 15 */ CMD_LOCKED,                     // Command is locked.
   /* 16 */ INVALID_CODE,                   // Unlock code is invalid.
   /* 17 */ INVALID_BAUD_RATE,              // Invalid baud rate setting.
   /* 18 */ INVALID_STOP_BIT,               // Invalid stop bit setting.
   /* 19 */ CODE_READ_PROTECTION_ENABLED,   // Code read protection enabled.
   /* 20 */ ERR_TRAP,                       // Trap routine called
   /*    */ CMD_COMPLETE = (CMD_SUCCESS|(1<<16)), // Indicates successful completion
} FlashDriverError_t;

#define ERR_COMPLETE (CMD_SUCCESS|(1<<16))
typedef enum {
   /* 50 */ PREPARE_SECTORS = 50,     // Prepare sector(s) for write operation 50 (decimal) Table 383
   /* 51 */ COPY_RAM_TO_ROM,          // Copy RAM to flash 51 (decimal) Table 384
   /* 52 */ ERASE_SECTORS,            // Erase sector(s) 52 (decimal) Table 385
   /* 53 */ BLANK_CHECK_SEDCTORS,     // Blank check sector(s) 53 (decimal) Table 386
   /* 54 */ READ_PART_ID,             // Read Part ID 54 (decimal) Table 387
   /* 55 */ READ_BOOT_CODE,           // Read Boot code version 55 (decimal) Table 388
   /* 56 */ COMPARE,                  // Compare 56 (decimal) Table 389
   /* 57 */ REINVOKE_ISP,             // Reinvoke ISP 57 (decimal) Table 390
   /* 58 */ READ_UID,                 // Read UID 58 (decimal) Table 391
   /* 59 */ ERASE_PAGE,               // Erase page 59 (decimal) Table 392
   /* 61 */ EEPROM_WRITE = 61,        // EEPROM Write 61(decimal) Table 393
   /* 62 */ EEPROM_READ,              // EEPROM Read 62(decimal) Table 394
} IapCommands;


/* Set Power mode values */
enum {
   /* 0 */ PWR_DEFAULT,
   /* 1 */ PWR_CPU_PERFORMANCE,
   /* 2 */ PWR_EFFICIENCY,
   /* 3 */ PWR_LOW_CURRENT,
};

/* Set Power result[0] values */
enum {
   /* 0 */ PWR_CMD_SUCCESS,
   /* 1 */ PWR_INVALID_FREQ,
   /* 2 */ PWR_INVALID_MODE,
};

/* Set PLL mode options */
enum {
   /* 0 */ CPU_FREQ_EQU,
   /* 1 */ CPU_FREQ_LTE,
   /* 2 */ CPU_FREQ_GTE,
   /* 3 */ CPU_FREQ_APPROX,
};

/* Set PLL result[0] options */
enum {
   /* 0 */ PLL_CMD_SUCCESS,
   /* 1 */ PLL_INVALID_FREQ,
   /* 2 */ PLL_INVALID_MODE,
   /* 3 */ PLL_FREQ_NOT_FOUND,
   /* 4 */ PLL_NOT_LOCKED,
};

/** Thumb mode addresses must be odd */
#define THUMB_MODE (1)

/** This is the smallest unit of Flash that can be erased */
#define FLASH_SECTOR_SIZE  (4*(1<<10)) // 4K block size (used for stride in erase)

/** Type for IAP entry point function */
typedef void (*romFunctionPtr_t)(uint32_t *, uint32_t *);

/** IAP entry point */
#define IAP_ENTRY ((romFunctionPtr_t)(0x1FFF1FF0|THUMB_MODE))

/** ROM entry points for clock/power functions */
typedef struct {
   romFunctionPtr_t setPll;
   romFunctionPtr_t setPower;
} RomEntry_t;

typedef uint32_t *RomTable[];

/** Ptr to table of Function table pointers */
#define ROM_DRIVER_TABLE (**(RomTable *)(0x1FFF1FF8))

/** Ptr to table of clock/power functions */
#define POWER_API_FUNCTION_TABLE ((RomEntry_t *)(ROM_DRIVER_TABLE[3]))

/** Type for entry to flash code */
typedef void (*EntryPoint_t)(void);

#pragma pack(push, 2)
/** Describes a block to be programmed & result */
typedef struct {
   uint32_t            flags;       // Controls actions of routine
   romFunctionPtr_t    iapPtr;      // Pointer to IAP entry point
   uint32_t            frequency;   // Target frequency (kHz)
   uint16_t            errorCode;   // Error code from action
   uint16_t            sectorSize;  // Size of flash sectors (minimum erase size)
   uint32_t            address;     // Memory address being accessed
   uint32_t            dataSize;    // Size of memory range being accessed
   uint32_t            dataAddress; // Pointer to data to program
} FlashData_t;

/** Describe the flash programming code */
typedef struct {
   uint32_t           *loadAddress;       // Address where to load this image
   EntryPoint_t        entry;             // Pointer to entry routine
   uint32_t            capabilities;      // Capabilities of routine
   uint32_t            reserved1;
   uint32_t            reserved2;
   FlashData_t        *flashData;         // Pointer to information about operation
} FlashProgramHeader_t;
#pragma pack(pop)

/** Address at which code was located by linker */
extern uint32_t __loadAddress[];

void asm_entry(void);

/**
 * Flash programming command table
 */
volatile const FlashProgramHeader_t gFlashProgramHeader = {
      /* loadAddress  */ __loadAddress,     // load address of image
      /* entry        */ asm_entry,         // entry point for code
      /* capabilities */ CAP_BLANK_CHECK_RANGE|CAP_ERASE_RANGE|CAP_ERASE_BLOCK|CAP_PROGRAM_RANGE|CAP_VERIFY_RANGE|CAP_PARTITION_FLEXNVM,
      /* Reserved1    */ 0,
      /* Reserved2    */ 0,
      /* flashData    */ NULL,
};

/**
 * Set error code to return to BDM & halt if errro set
 */
void setErrorCode(int errorCode) {
   if (errorCode==CMD_SUCCESS) {
      // Ignore
      return;
   }
   // Set error code and halt
   FlashData_t *flashData = gFlashProgramHeader.flashData;
   flashData->errorCode   = (uint16_t)errorCode;
   flashData->flags      |= IS_COMPLETE;
   for(;;) {
      __asm__("bkpt  0");
   }
}

/**
 * Default unexpected interrupt handler
 */
void isr_default(void) {
   setErrorCode(ERR_TRAP);
}

/**
 * Does any initialisation required before accessing the Flash
 */
void initFlash(FlashData_t *flashData) {
   // Do initialise flash every time

#if defined(DEBUG_BUILD) && 0
   SYSAHBCLKCTRL |= SYSAHBCLKCTRL_IOCON_MASK;
   PIO0_1 = IOCON_FUNC(1)|IOCON_MODE(0);

   CLKOUTDIV = CLKOUTDIV_DIV(1);

   CLKOUTSEL = CLKOUTSEL_MAIN;
   CLKOUTUEN = 0;
   CLKOUTUEN = CLKOUTUEN_UPDATE_MASK;

   MAINCLKSEL   = MAINCLKSEL_IRC;
   MAINCLKUEN   = 0;
   MAINCLKUEN   = MAINCLKUEN_UPDATE_MASK;
   SYSAHBCLKDIV = SYSAHBCLKDIV_DIV(1);

   uint32_t pllParams[5] = {RESET_CLOCK_FREQ_kHz, RESET_CLOCK_FREQ_kHz/2, CPU_FREQ_EQU, 0, 0, };
   POWER_API_FUNCTION_TABLE->setPll(pllParams, pllParams);
   setErrorCode(pllParams[0]);

   uint32_t pwrParams[5] = {RESET_CLOCK_FREQ_kHz/1000, PWR_DEFAULT, RESET_CLOCK_FREQ_kHz/1000, 0, 0, };
   POWER_API_FUNCTION_TABLE->setPower(pwrParams, pwrParams);
   setErrorCode(pwrParams[0]);
#endif

   flashData->flags &= ~DO_INIT_FLASH;
}

/**
 * Prepare sectors before programming
 *
 * @param startSector   Sector number of first sector (inclusive)
 * @param endSector     Sector number of last sector (inclusive)
 */
void prepareSectors(uint32_t startSector, uint32_t endSector) {
   uint32_t params[5] = {PREPARE_SECTORS, startSector, endSector, 0, 0,};
   IAP_ENTRY(params, params);
   setErrorCode(params[0]);
}

/**
 * Erase sectors
 *
 * @param startSector   Sector number of first sector (inclusive)
 * @param endSector     Sector number of last sector (inclusive)
 * @param frequency     Frequency of main clock
 */
void eraseSectors(uint32_t startSector, uint32_t endSector, uint32_t frequency) {
   uint32_t params[5] = {ERASE_SECTORS, startSector, endSector, frequency, 0,};
   IAP_ENTRY(params, params);
   setErrorCode(params[0]);
}

/**
 * Erase sectors
 *
 * @param destination   Sector number of first sector (inclusive)
 * @param source        Sector number of last sector (inclusive)
 * @param frequency     Frequency of main clock
 */
void copyRamtoRom(uint32_t destination, uint32_t source, uint32_t size, uint32_t frequency) {
   uint32_t params[5] = {COPY_RAM_TO_ROM, destination, source, size, frequency,};
   IAP_ENTRY(params, params);
   setErrorCode(params[0]);
}

/**
 * Erase entire flash block
 *
 * @param flashData Pointer to flash programming information
 */
void eraseFlashBlock(FlashData_t *flashData) {
   if ((flashData->flags&DO_ERASE_BLOCK) == 0) {
      return;
   }
   // Not supported
   setErrorCode(INVALID_COMMAND);
}

/**
 * Program a range of flash from buffer
 *
 * @param flashData Pointer to flash programming information
 */
void programRange(FlashData_t *flashData) {
   uint32_t         address    = flashData->address;
   uint32_t         data       = flashData->dataAddress;
   uint32_t         size       = flashData->dataSize;

   if ((flashData->flags&DO_PROGRAM_RANGE) == 0) {
      return;
   }
   while (size>0) {
      // Do in 256 byte blocks
      uint32_t blockSize = size;
      if (blockSize>256) {
         blockSize = 256;
      }
      prepareSectors(address>>12, address>>12);
      copyRamtoRom(address, data, blockSize, RESET_CLOCK_FREQ_kHz);
      data    += blockSize;
      address += blockSize;
      size    -= blockSize;
   }
   flashData->flags &= ~DO_PROGRAM_RANGE;
}

/*
 * Verify a range of flash against buffer
 *
 * @param flashData Pointer to flash programming information
 */
void verifyRange(FlashData_t *flashData) {
   uint32_t       *address    = (uint32_t *)flashData->address;
   uint32_t       *endAddress = (uint32_t *)(flashData->address+flashData->dataSize);
   const uint32_t *data       = (uint32_t *)flashData->dataAddress;

   if ((flashData->flags&DO_VERIFY_RANGE) == 0) {
      return;
   }
   // Verify bytes
   while (address<endAddress) {
      if (*address++ != *data++) {
         // Record failure address
         setErrorCode(COMPARE_ERROR);
      }
   }
   flashData->flags &= ~DO_VERIFY_RANGE;
}

/**
 * Erase a range of flash
 *
 * @param flashData Pointer to flash programming information
 */
void eraseRange(FlashData_t *flashData) {
   uint32_t   startSector  = (flashData->address)>>12;
   uint32_t   endSector    = (flashData->address + flashData->dataSize-1)>>12; // inclusive

   if ((flashData->flags&DO_ERASE_RANGE) == 0) {
      return;
   }
   // Check for empty range
   if (flashData->dataSize == 0) {
      return;
   }

   prepareSectors(startSector, endSector);

   eraseSectors(startSector, endSector, RESET_CLOCK_FREQ_kHz);

   flashData->flags &= ~DO_ERASE_RANGE;
}

/**
 * Check that a range of flash is blank (=0xFFFF)
 *
 * @param flashData Pointer to flash programming information
 */
void blankCheckRange(FlashData_t *flashData) {
   uint32_t   address     = flashData->address;
   uint32_t   endAddress  = address + flashData->dataSize;

   if ((flashData->flags&DO_BLANK_CHECK_RANGE) == 0) {
      return;
   }
   while (address < endAddress) {
      if (*(uint32_t *)address != 0xFFFFFFFFUL) {
         setErrorCode(SECTOR_NOT_BLANK);
      }
      address += 4;
   }
   flashData->flags &= ~DO_BLANK_CHECK_RANGE;
}

/** Some stack space */
extern uint32_t __stacktop[];

/**
 * Main C entry point
 *
 * Assumes ramBuffer is set up beforehand
 */
void entry(void) {

   // Disable interrupts
   __asm__ volatile ("cpsid i" : : : "memory");

   // Make Flash visible @0x0000 for programming
   SYSMEMREMAP = SYSMEMREMAP_FLASH;

   // Handle on programming data
   FlashData_t *flashData = gFlashProgramHeader.flashData;

   initFlash(flashData);
   eraseFlashBlock(flashData);
   eraseRange(flashData);
   blankCheckRange(flashData);
   programRange(flashData);
   verifyRange(flashData);

#ifndef DEBUG_BUILD
   // Indicate completed & stop
   setErrorCode(CMD_COMPLETE);
#endif
}

/**
 * Low level entry point
 */
__attribute__((naked))
void asm_entry(void) {
#ifndef DEBUG_BUILD
   // Setup the stack before we attempt anything else
   __asm__ (
         "mov   r0,%[stacktop]\n\t"
         "mov   sp,r0\n\t"
         "b     entry\n\t"
         "bkpt  0\n\t"::[stacktop] "r" (__stacktop));
#else
   __asm__ (
         "b     entry\n\t");
#endif
}

#ifndef DEBUG_BUILD
void asm_testApp(void) {
   for(;;) {
      __asm__("nop");
   }
}
#else

#define TEST 1
#if TEST == 1
// Programming general flash
static const uint8_t buffer[256] = {
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xCC,0xDD,0xEE,0xFF,
};

/* Erase all flash */
static const FlashData_t flashdataA = {
      /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
      /* address    */ 0x00000400,
      /* size       */ 0x100,
      /* data       */ 0,
};
/* Program range */
#define DO_B
static const FlashData_t flashdataB = {
      /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
      /* address    */ 0x00000000,
      /* size       */ 0xA00,
      /* data       */ (uint32_t)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
      /* flags      */ DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
      /* address    */ 0x00000000,
      /* size       */ sizeof(buffer),
      /* data       */ (uint32_t)buffer,
};
//#define DO_D
//static const FlashData_t flashdataD = {
//      /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
//      /* controller */ IAP_ENTRY,
//      /* frequency  */ RESET_CLOCK_FREQ_kHz,
//      /* errorCode  */ 0xAA55,
//      /* sectorSize */ FLASH_SECTOR_SIZE,
//      /* address    */ 0x00000000,
//      /* size       */ sizeof(buffer),
//      /* data       */ (uint32_t)buffer,
//};
//#define DO_E
//static const FlashData_t flashdataE = {
//      /* flags      */ DO_INIT_FLASH,
//      /* controller */ IAP_ENTRY,
//      /* frequency  */ RESET_CLOCK_FREQ_kHz,
//      /* errorCode  */ 0xAA55,
//      /* sectorSize */ FLASH_SECTOR_SIZE,
//      /* address    */ 0x00000C40,
//      /* size       */ sizeof(buffer),
//      /* data       */ (uint32_t)buffer,
//};
#elif TEST == 2
// Unlock flash
static const FlashData_t flashdataA = {
      /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_UNLOCK_FLASH|DO_VERIFY_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 3
// Lock Flash
static const FlashData_t flashdataA = {
      /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_LOCK_FLASH|DO_VERIFY_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 4
// Not used
static const FlashData_t flashdataA = {
      /* flags      */ DO_TIMING_LOOP,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
};
#elif TEST == 5
// Set erasing ranges
static const FlashData_t flashdataA = {
      /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
      /* address    */ 0x00000045,
      /* size       */ 0x312-0x45,
};
#define DO_B
// Set erasing ranges
static const FlashData_t flashdataB = {
      /* flags      */ DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
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
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
};
#define DO_B
static const FlashData_t flashdataB = {
      /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
      /* address    */ 0x00000800,
      /* size       */ sizeof(buffer),
      /* data       */ (uint32_t)buffer,
};
#define DO_C
static const FlashData_t flashdataC = {
      /* flags      */ DO_INIT_FLASH|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
      /* address    */ 0x00000900,
      /* size       */ sizeof(buffer),
      /* data       */ (uint32_t)buffer,
};
#elif TEST == 7
// Checking security region actions
// Program region overlapping security area
static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF,
      0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,0xFF,0xFF,0xFF,0xFF};

static const FlashData_t flashdataA = {
      /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
      /* address    */ 0x000003F0,
      /* size       */ sizeof(buffer),
      /* data       */ (uint32_t)buffer,
};
#elif TEST == 8
// Checking security anti-lockup
//static const uint8_t buffer[] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xAA,0xBB,
//                                 (FTFA_FSEC_KEY_ENABLE|FTFA_FSEC_MEEN_DISABLE|FTFA_FSEC_FSLACC|FTFA_FSEC_UNSEC),0xFF,0xFF,0xFF,};

static const FlashData_t flashdataA = {
      /* flags      */ DO_INIT_FLASH|DO_ERASE_RANGE|DO_BLANK_CHECK_RANGE|DO_PROGRAM_RANGE|DO_VERIFY_RANGE,
      /* controller */ IAP_ENTRY,
      /* frequency  */ RESET_CLOCK_FREQ_kHz,
      /* errorCode  */ 0xAA55,
      /* sectorSize */ FLASH_SECTOR_SIZE,
      /* address    */ 0x00000400,
      /* size       */ sizeof(buffer),
      /* data       */ (uint32_t)buffer,
};
#endif

//! Dummy test program for debugging
void testApp(void) {
   FlashProgramHeader_t *fph = (FlashProgramHeader_t*) &gFlashProgramHeader;

   // Relocate the interrupt vector table to RAM
   SYSMEMREMAP = SYSMEMREMAP_FLASH;

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
extern void asm_testApp(void) {
   __asm__ (
         // Setup the stack before we attempt anything else
         "mov   r0,%[stacktop]\n\t"
         "mov   sp,r0\n\t"
         // execute testApp
         "bl    testApp\n\t"
         //
         "bkpt  0\n\t"::[stacktop] "r" (__stacktop));
}
#endif
