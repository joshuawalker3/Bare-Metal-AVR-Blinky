//Spec Reg Offset
#define OFFSET 0x20
#define S_REG_OFF(addr) *((volatile unsigned char*)(addr + OFFSET))

// Port B data direction register 0x17
#define DDRB S_REG_OFF(0x17)

// Port B data register 0x18
#define PORTB S_REG_OFF(0x18)

// Output compare Reg A
#define OCR0A S_REG_OFF(0x29)

// Counter Register
#define TCNT0 S_REG_OFF(0x32)

// Bit mask
#define BIT_MASK(shift) (1 << shift)

// Timer control reg A
#define TCCR0A S_REG_OFF(0x2A)

// Timer control reg B
#define TCCR0B S_REG_OFF(0x33)

// Interrupt Register
#define TIMSK S_REG_OFF(0x39)

// Status reg
#define SREG S_REG_OFF(0x3F)

/*
// Handler for interrupts that occur from TIMER0 overflow (enabled by flipping bit 1 in TIMSK)
// __attribute__ just tells GCC compiler that its an interrupt
// __vector_5 came from the vector table. Entry for TIMER0_OVF
void __vector_5(void) __attribute__ ((signal)); 
*/

// Handler for interrupts that occur from Output Compare Interrupt (enabled by flipping bit 4 in TIMSK)
// __attribute__ just tells GCC compiler that its an interrupt
// __vector_10 came from the vector table. Entry for TIMER0_COMPA
void __vector_10(void) __attribute__ ((signal)); 

int main() {
  // Set data direction for Port B bit 0 (PB0 - pin 5)
  DDRB |= BIT_MASK(0); 

  // Start LED in On
  PORTB |= 0x01;

  // 1024 prescaler. 1024 + 1 cycles to increment internal counter by 1.  
  TCCR0B |= 0x05;

  // Enable CTC mode
  TCCR0A |= 0x02;

  // Set Compare Value. This makes it about 2 Hz (I think)
  /*
  * CALCULATION
  * Frequency = 1 MHz
  * Prescaler = 1024 (1025 cycles to increment by 1)
  * OCR0A = 244 (0xF4)
  * Time = OCR0A * Prescaler / Frequency = 0.2501 seconds
  */
  OCR0A |= 0xF4;

  // Enable timer Overflow interrupt
  TIMSK |= BIT_MASK(4);

  // Enable global interrupts
  SREG |= BIT_MASK(7); 
  
  while (1) {}
}

/*
void __vector_5(void) {
  //XOR operation just flips Bit 0, controlling PB0 turning LED on and off
  PORTB ^= BIT_MASK(0);
}
*/

void __vector_10(void) {
  //XOR operation just flips Bit 0, controlling PB0 turning LED on and off
  PORTB ^= BIT_MASK(0);
  //TCNT0 = 0x00; //Have to reset counter since in normal mode
} 
