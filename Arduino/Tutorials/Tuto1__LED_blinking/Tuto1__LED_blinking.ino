/**
 * \file      Tuto1__LED_blinking.ino
 * \brief     Tutorial -- Arduino basics: LED blinking
 * \details   Learning Arduino basics: LED, digital output (based on Arduino "Blink" example).
 *            The built-in led is used, as well as an LED connected to pin 7 of Arduino UNO.
 * \note      Using 3 LEDs with the proper colours, an interesting exercise would consist in creating a red light.
 * \author    Alexandre QUENON
 * \date      2018-03-08
 * \copyright GNU Public License V3.0
 */



// Constants
const int pin_a = LED_BUILTIN;
const int pin_b = 7;

const unsigned long half_period_blink_a = 1000;
const unsigned long half_period_blink_b = 200;


// Functions prototypes
void blink_led( int pin, unsigned long half_period );


// Arduino main functions
void setup()
{
  pinMode( pin_a, OUTPUT );
  pinMode( pin_b, OUTPUT );
}


void loop()
{
  for( int i = 0; i < 10; ++i)
    blink_led( pin_a, half_period_blink_a );

  for( int i = 0; i < 30; ++i)
    blink_led( pin_b, half_period_blink_b );
}


// Functions implementations
void blink_led( int pin, unsigned long half_period )
{
  digitalWrite( pin, HIGH );
  delay( half_period );
  digitalWrite( pin, LOW );
  delay( half_period );
}
