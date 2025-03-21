#include <Arduino.h>
#include <stdint.h> 
#include "declarations.h" // Declares global variables to be used in the process

//================IMPLEMENT PLEASE A WAY TO HAVE DEFAULT VALUES IF THERE IS NO SERIAL CONECTION


// Testing instructions: 1) connect all the pins needed accoding to schematics in e_mail
//                       2) provide a 1k resistor to use aswell
//                       3) set cell 4 
//                       4) set the physical connections
//                       5) set the oscilloscope to read 'saída' and 'coluna'
//                       6) turn on the circuit 

// Digital ports assignments
#define SEL_en 13
#define RES 11
#define VBIAS 9 
#define SHIFT_IN 7
#define CLK 5 

// Functions
#include "signals_shift_register_no_delay.h" // Frequency around 42.74 kHz (maximum)
#include "signals_shift_register_with_delay.h"
#include "other_functions.h"

void setup() {
  // Setting up the digital ports
  pinMode(SEL_en, OUTPUT);
  pinMode(RES, OUTPUT);
  pinMode(VBIAS, OUTPUT);
  pinMode(SHIFT_IN, OUTPUT);
  pinMode(CLK, OUTPUT);

  // Setup VBIAS, RES and SEL to 0V
  digitalWrite(SEL_en, 0);
  digitalWrite(RES, 0);
  digitalWrite(VBIAS, 0); // Remember that VBIAS is a analog voltage, not digital, so, if 
  // it is ever needed, you must use a resistor in series with a capacitor to make the signal
  // a steady voltage, since it is PWM. 

  Serial.begin(115200);
  
  // Getting and setting Up the signals
  Serial.println("Do you want set a frequency? If not, the maximum will be used. (anyInt-yes;0-no)");
  while(!Serial.available()); // Wait to detect something
  freq_en = (bool) Serial.parseInt();
  
  // Get frequency value
  if (freq_en) freq = getValidIntFromSerial("Insert a number from 1 to 42739 to be the frequency", 1, 42739);       
  
  // Get pixel number
  cell_number = getValidIntFromSerial("Choose the pixel wanted (0-7)(7 is the extern)\nWe are using cell 4, for tests!!", 0, 7);       
  choosing_cell_with_register(cell_number); // Function that chooses pixel by shaping the signal
  Serial.println ("All set!!!\n");

  // Setting needed delay time for the functions
  DELAY = (int) round((1.0/freq - 0.0000234)*1e6/4); 
  // Define the delay time based on the frequency wanted
  // Take the time of basic instructions (~23.4µs) into account and devide it in 
  // four equal parts in between the cicle
  if (DELAY<=0) {
    freq_en = false; // If the delay turns out zero or less, we use the no_delay function
    Serial.println ("The frequency was set up to the maximum, since the number required is beyond the limit.");
  }

  // Selecting the cell already, because it just need to be selected one time, at least for
  // the testing. Hence, it is here in Setup function.
  if(freq_en){
    // Sending the signals CLK and Shift_IN, with the frequency determinated by FREQ
    signals_shift_register_with_delay();
  } else{
    // Sending the signals CLK and Shift_IN (maximum frequency)
    signals_shift_register_no_delay();
  }
}

void loop() {  
  while(1){ // While here is redundant and it is part of a test of mine
    // VBIAS was set to 0 in Setup

    // Pixel (cell) was picked and set in Setup 

    // Activating and deactivating RES 
    digitalWrite(RES, HIGH);
    (freq_en) ? delayMicroseconds(DELAY*4*3) : delayMicroseconds(24*3); // "Delay*4" and 24 consist in one period
    digitalWrite(RES, LOW);

    // Activating and deactivating SEL enable
    digitalWrite(SEL_en, HIGH);
    (freq_en) ? delayMicroseconds(DELAY*4*10) : delayMicroseconds(24*10); // Time to see the signal of 'saida' rising. 
    // You can modify if needed 
    // digitalWrite(SEL_en, LOW); // It doesnt make much of a difference if you LOW this while we are
    // measuring. 
  }
}
