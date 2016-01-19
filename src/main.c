#include <stdlib.h>
#include <avr/interrupt.h>
#include <avr/io.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))

int core(void);
void setupLED(void);
void setupSwitch(void);
void setLED(int status);

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

  // TODO: Clear interrupt enable

  // TODO: Set interrupt sense type to trigger on any logic change

  // TODO: enable interrupt

}

void setLED(int status)
{
  // status 1 means "ON"
  // status 0 means "OFF"
  if (status == 1)
  {
    // TODO: set F0 to HIGH
  }
  else
  {
    // TODO: set F0 to LOW
  }
}

int core(void)
{
  CPU_PRESCALE(0x01);
  setupLED();
  setupSwitch();
  // TODO: enable global interrupts

  // TODO: create a status variable

  while (1)
  {
    // Do regular processing (nothing in this lesson)

    if (flag == 1)
    {
      // TODO:
      // 1) disable interrupts
      // 2) Read switch value
      // 3) Set LED to HIGH or LOW
      // 4) re-enable interrupts
    }
  }
}

// TODO: Write interrupt service routine for INT2
