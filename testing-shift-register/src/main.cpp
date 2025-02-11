#include <Arduino.h>
#include <stdint.h> 
#include "declarations.h"

// Digital ports assignments
#define SHIFT_IN 7
#define CLK 5 

// Defining frequency of the clock in hertz (if its being used)
#define FREQ 10000

const int32_t DELAY = ((1.0/FREQ - 0.0000234)*1e6/4); // Can be manually callibrated
// This int32_t type isn't needed, I am just exercising. If you want, change it to "int"
// and erase "#include <stdint.h>"

// Functions
#include "signals_shift_register_no_delay.h" // Frequency around 42.74 kHz (maximum)
#include "signals_shift_register_with_delay.h"
#include "choosing_cell_with_register.h"

void setup() {

  // Setting up the digital ports
  pinMode(SHIFT_IN, OUTPUT);
  pinMode(CLK, OUTPUT);  

  choosing_cell_with_register(cell_number); // Choose one cell between 1-8
}

void loop() {
  
  while(1){ // This while is redundant, but I want to test
            // if the "void loop" is the couse of a random
            // larger bit in the signal. (aparently it was)

    //signals_shift_register_no_delay();
    signals_shift_register_with_delay();
  }
}