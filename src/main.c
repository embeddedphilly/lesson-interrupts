#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

int core(void);
void setupLED(void);
void setupSwitch(void);
void setLED(int state);

volatile int flag = 0;

#ifdef __AVR__
int main(void)
{
  core();
}
#endif

void setupLED()
{
  // Configure Port F, Pin 0 to Output
  DDRF |= (1 << 0);
  // Set Port F, Pin 0 to HIGH
  PORTF |= (1 << 0);
}

void setupSwitch()
{
  // Configure Port D, Pin 2 to Input
  DDRD &= ~(1 << 2);
  // Set Port D, Pin 2 to use a Pull-up resistor
  PORTD |= (1 << 2);

  // Clear interrupt enable
  EIMSK &= ~(1 << 2);
  // Set interrupt sense type to trigger on any logic change
  EICRA |= (1 << 4);
  EICRA &= ~(1 << 5);
  // enable interrupt
  EIMSK |= (1 << 2);
}

void setLED(int state)
{
  // state 1 means "ON"
  // state 0 means "OFF"
  if (state == 1)
  {
    PORTF |= (1 << 0);
  }
  else
  {
    PORTF &= ~(1 << 0);
  }
}

int core(void)
{
  CPU_PRESCALE(0x01);
  setupLED();
  setupSwitch();
  sei();

  // starts "on"
  int state = 1;

  while (1)
  {
    // do whatever

    if (flag == 1)
    {
      cli();
      // Read state of pin
      state = (PIND >> 2) & 1;
      // set the LED state
      setLED(state);
      // reset flag
      flag = 0;
      sei();
    }
  }
}

ISR(INT2_vect)
{
  flag = 1;
}

