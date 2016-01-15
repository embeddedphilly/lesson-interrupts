#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
int core(void);