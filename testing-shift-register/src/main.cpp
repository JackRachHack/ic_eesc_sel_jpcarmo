#include <Arduino.h>

// Digital ports assignments
#define SHIFT_IN 7
#define CLK 5 

// Defining frequency of the clock in the function with delay
#define DELAY 19    // The value must be in microseconds and an integer
                    // To know the number, do the following calculation
                    // with the frequency you want: (1/f - 0.0000234)/4

#include "signals_shift_register_no_delay.h" // Frequency around 42.74 kHz (maximum)
#include "signals_shift_register_with_delay.h"

void setup() {

  // Setting up the digital ports
  pinMode(SHIFT_IN, OUTPUT);
  pinMode(CLK, OUTPUT);  
}

void loop() {
  
  while(1){ // This while is redundant, but I want to test
            // if the "void loop" is the couse of a random
            // larger bit in the signal.
    //signals_shift_register_no_delay();
    signals_shift_register_with_delay();
  }
}