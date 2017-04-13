/*
 * File: exceptions.h
 * Purpose: Generic exception handling for ColdFire processors
 *
 * Notes:
 */

#ifndef _MCF_EXCEPTIONS_H
#define _MCF_EXCEPTIONS_H

#ifdef __cplusplus
extern "C" {
#endif

/***********************************************************************/
/*
 *    Dummy routine for initializing hardware.  For user's custom systems, you
 *    can create your own routine of the same name that will perform HW
 *    initialization.  The linker will do the right thing to ignore this
 *    definition and use the version in your file.
 *
 */

void __initialize_hardware(void);

/***********************************************************************/
/*
 * This is the handler for all exceptions which are not common to all 
 * ColdFire Chips.  
 *
 * Called by mcf_exception_handler
 * 
 */
void derivative_interrupt(unsigned long vector);

/***********************************************************************/
/*
 * This is the exception handler for all  exceptions common to all 
 * chips ColdFire.  Most exceptions do nothing, but some of the more 
 * important ones are handled to some extent.
 *
 * Called by asm_exception_handler 
 */
void mcf_exception_handler(void *framepointer);


/***********************************************************************/
/*
 * This is the assembly exception handler defined in the vector table.  
 * This function is in assembler so that the frame pointer can be read  
 * from the stack.
 * Note that the way to give the stack frame as argument to the c handler
 * depends on the used ABI (Register, Compact or Standard).
 *
 */
asm __declspec(register_abi) void asm_exception_handler(void);

/***********************************************************************/
/*
* printf() TRAP #14 handler
 *
 */
#if CONSOLE_IO_SUPPORT == 1
asm __declspec(register_abi) void TrapHandler_printf(void);
#endif

#ifdef __cplusplus
}
#endif

#endif   /* _MCF_EXCEPTIONS_H */

