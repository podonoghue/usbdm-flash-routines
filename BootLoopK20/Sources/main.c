/*
 * Minimal main-line to stop the target crashing.
 */
#include "derivative.h" /* include peripheral declarations */

int main(void)
{
	for(;;) {	   
	   __asm__("wfi");
	}
	return 0;
}
