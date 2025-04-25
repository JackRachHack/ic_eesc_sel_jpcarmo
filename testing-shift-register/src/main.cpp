#include <Arduino.h>
#include <stdint.h> 
#include "declarations.h" // Declares global variables to be used in the process

//================FASTER SPEED SUGGESTION (not necessary anymore): IMPLEMENT DIRECT REGISTER MANIPULATION INSTEAD OF DIGITAL WRITE

// Next step: try putting the setting function back in setup

// Testing instructions: 1) connect all the pins needed accoding to schematics in e_mail
//                       2) provide a 1k resistor to use aswell
//                       3) set cell 4 
//                       4) set the physical connections
//                       5) set the oscilloscope to read 'saída' and 'coluna'
//                       6) turn on the circuit 

// Digital ports assignments
#define SEL_en 12
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
  pinMode(13, OUTPUT);
  pinMode(SEL_en, OUTPUT);
  pinMode(RES, OUTPUT);
  pinMode(VBIAS, OUTPUT);
  pinMode(SHIFT_IN, OUTPUT);
  pinMode(CLK, OUTPUT);

  // Setting up VBIAS, RES and SEL
  digitalWrite(SEL_en, HIGH);
  digitalWrite(RES, 0);
  digitalWrite(VBIAS, 0); // Remember that VBIAS is a analog voltage, not digital, so, if 
  // it is ever needed, you must use a resistor in series with a capacitor to make the signal
  // a steady voltage, since the analogWrite output is PWM. 

  Serial.begin(115200);
  
  //==== Getting and setting Up the signals
  
  // Setting a timer, used to go forward with default values if there is no serial conection
  int count = 10;
  int count_c = count;
  Serial.println("Do you want set a frequency? \nIf not, the maximum will be used. (anyInt-yes;0-no). \n\nIf there is no answer in 10 seconds, the test will proceed with default values: maximum frequency, cell 4 and reset interval = 120us.");
  
  unsigned long currentMillis = millis();
  unsigned long previousMillis = currentMillis;
  unsigned long midMillis = currentMillis;
  bool inverter = true;

  while(true){ // Wait to detect something or passing the time limit
    currentMillis = millis();
    digitalWrite(13, inverter);

    if ((currentMillis - midMillis) > 500){
      midMillis = currentMillis;
      inverter = !inverter;
      if(inverter) {
        count_c = count_c - 1;
        Serial.println(count_c);
      }
    }

    if (Serial.available() > 0 || (currentMillis - previousMillis) > count * 1000) {
      inverter = true;
      if (!Serial.available()) inverter = false; // Just reusing this variable in case there is a time out
      break;
    }     
  }; 
  freq_en = (bool) Serial.parseInt();
  
  // Get frequency value
  if (freq_en) freq = getValidIntFromSerial("Insert a number from 1 to 42739 to be the frequency", 1, 42739);       
  
  // Get pixel number and reset interval (microseconds)
  if (inverter) cell_number = getValidIntFromSerial("Choose the pixel wanted (0-7)(7 is the extern)\nWe are using cell 4, for tests!!", 0, 7);       
  if (inverter) res_interval = getValidIntFromSerial("How many microseconds the time between resets must have?\n120us is the default.", 0, 2147483646);
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

  // Selecting the cell here because it just need to be selected one time, at least for
  // the testing.
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
    delayMicroseconds(24*3);
    digitalWrite(RES, LOW);
    delayMicroseconds(res_interval); 
  }
}
