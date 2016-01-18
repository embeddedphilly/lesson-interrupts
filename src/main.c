#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

int core(void);

volatile int flag = 0,
             switchState = 0;

#ifdef __AVR__
int main(void)
{
  core();
}
#endif

void setLED(int state)
{

}

int core(void)
{
  CPU_PRESCALE(0x01);
  sei();

  int state = 0;

  while (1)
  {
    // do whatever
    if (flag == 1)
    {
      state = switchState;
      setLED(state);
    }
  }
}

ISR(INT2_vect)
{

}

