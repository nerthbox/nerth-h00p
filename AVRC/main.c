#include <avr/io.h>
#include <util/delay.h>

//define pins
#define PIN_LED1 PB0
#define PIN_LED2 PB1
//define delay time
#define DELAY_MS 250

//write high
#define D_HIGH(prt, pn) prt |= (1<<pn)
//write low
#define D_LOW(prt, pn) prt &= ~(1<<pn)

//long delay, 8 bit timer protect, max 10
void long_delay_ms(uint16_t ms){
  for(ms /= 10; ms > 0; ms--)_delay_ms(10) ;
}

int main(void){
  DDRB |= (1 << PIN_LED1) | (1 << PIN_LED2);

  D_LOW(PORTB, PIN_LED1);
  D_LOW(PORTB, PIN_LED2);

  uint8_t toggle = 0;
  for(;;){
    D_HIGH(PORTB, (toggle == 0 ? PIN_LED1 : PIN_LED2));
    D_LOW(PORTB,  (toggle == 0 ? PIN_LED2 : PIN_LED1));

    toggle = !toggle;

    long_delay_ms(DELAY_MS);
}
  return 0;
}
