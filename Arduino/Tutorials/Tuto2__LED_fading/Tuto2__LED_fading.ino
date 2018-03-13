/**
 * \file      Tuto2__LED_fading.ino
 * \brief     Tutorial -- Arduino basics: LED fading
 * \details   Learning Arduino basics: LED, analogue output (based on Arduino "Fade" and "Fading" examples).
 *            An LED connected to pin A3 of Arduino UNO.
 * \author    Alexandre QUENON
 * \date      2018-03-13
 * \copyright GNU Public License V3.0
 */


// Libraries
#include <Arduino.h>


// Global variables
const int pin_pwm = 3;
const unsigned long delay_fade = 100;

const bool auto_fade = false;


// Functions protoypes
void inc_led_bright( int pin, int bright_amount = 5, unsigned long inc_timing_ms = 50 );
void dec_led_bright( int pin, int bright_amount = 5, unsigned long dec_timing_ms = 50 );


// Arduino main functions
void setup()
{
  pinMode( pin_pwm, OUTPUT );
}

void loop()
{
  if( auto_fade )
  {
    inc_led_bright( pin_pwm );
    dec_led_bright( pin_pwm, 20, 200 );
  }
  else
  {
    auto sensed_dig_val = static_cast<int>( analogRead( A3 ) / 4 );
    analogWrite( pin_pwm, sensed_dig_val );
  }
}


// Functions implementation
void inc_led_bright( int pin, int bright_amount, unsigned long inc_timing_ms )
{
  for( auto brightness = 0; brightness <= 255; brightness += bright_amount )
  {
    analogWrite( pin, brightness );
    delay( inc_timing_ms );
  }
}
void dec_led_bright( int pin, int bright_amount, unsigned long dec_timing_ms )
{
  for( auto brightness = 255; brightness >= 0; brightness -= bright_amount )
  {
    analogWrite( pin, brightness );
    delay( dec_timing_ms );
  }
}

