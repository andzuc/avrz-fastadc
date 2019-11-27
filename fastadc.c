#include <fastadc.h>

#include <avr/io.h>

int16_t ADCsingleREAD_10bit(void)
{
  int ADCval;

  /* ADMUX = 0;         // use #1 ADC */
  /* ADMUX |= _BV(REFS0) | _BV(REFS1);    // use internal 1.1V Voltage Reference */
  /* ADMUX &= (~_BV(ADLAR));   // clear for 10 bit resolution (default) */
  
  // ADCSRA |= _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0);    // 128 prescale for 8Mhz
  // ADCSRA |= _BV(ADEN);    // Enable the ADC
  
  ADCSRA |= _BV(ADSC);    // Start the ADC conversion

  while(ADCSRA & _BV(ADSC));      // Thanks T, this line waits for the ADC to finish


  ADCval = ADCL;
  ADCval = (ADCH << 8) + ADCval;    // ADCH is read so ADC can be updated again

  return ADCval;
}
