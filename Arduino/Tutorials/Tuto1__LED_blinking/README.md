# Tutorial 1: LED blinking



## Aims

The aims of this tutorial are:
* start learning to code the Arduino UNO microcontroller with Arduino "language"
* discover the hardware which can be connected to the microcontroller
* use some "rules" for *good programming practice*



## Tools

The current tutorial has been done under the Arduino IDE environment.



## Arduino language bases


### Basic Arduino functions

Two very important **functions**:
1. `void setup()`, which is run only once at start-up or reset;
2. `void loop()`, which is run forever after setup.


### Controlling digital I/Os

The easiest way to start coding with Arduino consists in controlling digital I/Os.
It is easy for several reasons:
* digital I/Os can only output a bit ('0' or a '1'),
* a bit can be used to switch on and off an LED.

To do so, two steps are necessary:
1. set the pin in used up,
2. write the desired bit value on the pin.

Setting the pin up is achieved with the `pinMode()` function.
It is typically done in the `setup()` function.

Writing a bit value to a pin is done with `digitalWrite()` function.
Constants LOW and HIGH, which are defined in the "Arduino.h" header, can be used to pass the value.
LOW means a '0', HIGH means a '1'.


### Good practice

#### Declaring pins with *const* global variables

Functions as `digitalWrite()` and `pinMode()` wait for an integer argument to pass the target pin.
One simple way to do it is to directly write the pin number as an argument.
For instance,

	digitalWrite( 7, HIGH );

allows to write a '1' on pin 7.

The problem with hard-writing the pin number is that it creates a maintenance nightmare.
Indeed, imagine you need to change the pin in use for any reason.
Then, you must find each function call which uses the pin in order to change it.
It is long and horrible.

To avoid such a problem, declare a constant global variable, i.e., outside the `setup` and `loop` functions.
Hence,

	const int pin_led = 7;
	
	void setup()
	{
		pinMode(pin_led, OUTPUT);
		// any other instruction
	}
	
	void loop()
	{
		// ...
		digitalWrite(pin_led, HIGH);
		// ...
	}

#### Using global variables of correct type

Use `unsigned long` for argument of `delay()` function.