#include <Arduino.h>
#include <stdint.h> 
#include "declarations.h" // Declares the 8bits bool vars and a global int var "cell_number" 
// to be used in any logic to select one port at a time with the choosing cell function 

// Digital ports assignments
#define SEL 13
#define RES 11
#define VBIAS 9
#define SHIFT_IN 7
#define CLK 5 

// Functions
#include "signals_shift_register_no_delay.h" // Frequency around 42.74 kHz (maximum)
#include "signals_shift_register_with_delay.h"
#include "choosing_cell_with_register.h"

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

  // ==========THERE ARE TOO MANY LOOPS, IMPLEMENT THE FOLLOWING FUNCTION (available in the gpt history)

  /*
  int getValidIntFromSerial(const char* prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        Serial.println(prompt);
        while (!Serial.available()); // Espera até receber entrada
        value = Serial.parseInt();
        if (value >= minVal && value <= maxVal) {
            return value;
        }
        Serial.println("Valor inválido. Tente novamente.");
    }
}

  */
  // Setting Up the signals
  Serial.println("Do you want set a frequency? If not, the maximum will be used. (1-yes;0-no)");
  while (1){ // Loop to get a valid information from the user
    while(!Serial.available()){
      // Waiting until there is something in the serial conection
    }

    int response = Serial.parseInt();

    if(response == 0 || response == 1) { // If 1 or 0, we get the freq or not and break (IF1_BEGIN)
      
      freq_en = (bool)response;
      if (freq_en) { // If 1, get the value (IF2_BEGIN)
        while(1){ // Loop to get a valid information from the user
          Serial.println("Insert a number from 1 to 42739 to be the frequency");
          while(!Serial.available()){
            // Waiting until there is something in the serial conection
          }
          
          freq = Serial.parseInt(); 

          if (freq > 0 && freq < 42740) break;     
        
          Serial.println("Invalid number");
        }        
      }// (IF2_BEGIN)
      
      // Getting pixel number
      while(1){ // Loop to get a valid information from the user
        Serial.println("Choose the pixel wanted (0-7)(7 is the extern)");
        while(!Serial.available()){
          // Waiting until there is something in the serial conection
        }

        response = Serial.parseInt();

        if (response > -1 && response < 8) {
          cell_number = response;
          break;
        }
        Serial.println("Invalid number");
      } 
      break;
    }// (IF1_END)
    Serial.println("Invalid number");  
  }

  // Function that chooses pixel by shaping the signal
  choosing_cell_with_register(cell_number);

  // Setting needed delay time for the functions
  int DELAY = round((1.0/freq - 0.0000234)*1e6/4); 
  // So, a frequency (freq) is defined. The period is calculated. Since the microcontroler
  // spends 0.000234s with the basic writings instructions, it is taken into account. Then
  // its divided by 4, because the delay is distributed between the 4 writings. Then its 
  // multiplied by 1e6 to be in the form of microseconds for the delayMicroseconds() function.
  // Since the delay function expects an integer, there will be an error in the output frequency
  // due to roundings, mainly with high frequencies that border the limit (42.74kHz).
}

void loop() {
  
  while(1){ 
    // VBIAS was set to 0 in Setup

    // Pixel (cell) was picked in Setup (for this example, bit 4, or pixel 5)

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
