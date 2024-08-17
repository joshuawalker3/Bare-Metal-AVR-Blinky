# **AVR Blinky with No Libraries**

## **Overview**
I started this project to begin dipping my toes into bare metal programming and to begin gaining a deeper understanding of programming MCU's. The project simply blinks the LED connected to pin PB0 on the programmer at a frequency of approximately 2 Hz.

## **Equipment**
For this project I used the following:
- [ATTiny 85 MCU](https://components101.com/microcontroller/attiny85-pinout-datasheet)
- [Sparkfun Tiny AVR Programmer](https://www.sparkfun.com/products/11801)

## **Software**
The following software was used to build and flash the program:
- [avrdude](https://github.com/avrdudes/avrdude)
- [GNU Make](https://www.gnu.org/software/make/)

## **Code**
The code is written in C and uses no external libraries. Information about the chip was obtained from the [manual](https://ww1.microchip.com/downloads/en/devicedoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf).
