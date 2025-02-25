#include <Arduino.h>
#include <stdint.h> 
#include "declarations.h" // Declares global variables to be used in the process

// Digital ports assignments
#define SEL 13
#define RES 11
#define VBIAS 9
#define SHIFT_IN 7
#define CLK 5 

// Functions
#include "signals_shift_register_no_delay.h" // Frequency around 42.74 kHz (maximum)
#include "signals_shift_register_with_delay.h"
#include "other_functions.h"

void setup() {

  Serial.begin(115200);

  // Setting up the digital ports
  pinMode(SEL, OUTPUT);
  pinMode(RES, OUTPUT);
  pinMode(VBIAS, OUTPUT);
  pinMode(SHIFT_IN, OUTPUT);
  pinMode(CLK, OUTPUT);

  // Setup VBIAS, RES and SEL to 0V
  digitalWrite(SEL, 0);
  digitalWrite(RES, 0);
  digitalWrite(VBIAS, 0);

  
  // Getting and setting Up the signals
  Serial.println("Do you want set a frequency? If not, the maximum will be used. (anyInt-yes;0-no)");
  while(!Serial.available()); // Wait to detect something
  freq_en = (bool) Serial.parseInt();
  
  // Get frequency value
  if (freq_en) freq = getValidIntFromSerial("Insert a number from 1 to 42739 to be the frequency", 1, 42739);       
  
  // Get pixel number
  cell_number = getValidIntFromSerial("Choose the pixel wanted (0-7)(7 is the extern)", 0, 7);       
  choosing_cell_with_register(cell_number); // Function that chooses pixel by shaping the signal

  // Setting needed delay time for the functions
  DELAY = (int) round((1.0/freq - 0.0000234)*1e6/4); 
  // Define the delay time based on the frequency wanted
  // Take the time of basic instructions (~23.4µs) into account and devide it in 
  // four equal parts in between the cicle
}

void loop() {  
  while(1){ // While here is redundant and it is part of a test of mine
    // VBIAS was set to 0 in Setup

    // Pixel (cell) was picked in Setup 

    if(freq_en){
      // Sending the signals CLK and Shift_IN, with the frequency determinated by FREQ
      signals_shift_register_with_delay();

      // Activating and deactivating RES 
      digitalWrite(RES, HIGH);
      delayMicroseconds(DELAY*4*3); // "Delay*4" consist in one period
      digitalWrite(RES, LOW);

      // Activating and deactivating SEL enable
      digitalWrite(SEL, HIGH);
      delayMicroseconds(DELAY*4*3);
      digitalWrite(SEL, LOW); 

    } else{
      // Sending the signals CLK and Shift_IN (maximum frequency)
      signals_shift_register_no_delay();

      // Activating and deactivating RES 
      digitalWrite(RES, HIGH);
      delayMicroseconds(24*3); // This is 24 is the period.
      digitalWrite(RES, LOW);

      // Activating and deactivating SEL enable
      digitalWrite(SEL, HIGH);
      delayMicroseconds(24*3);
      digitalWrite(SEL, LOW);
    }
  }
}
