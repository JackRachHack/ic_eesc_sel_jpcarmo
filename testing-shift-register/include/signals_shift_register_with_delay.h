void signals_shift_register_with_delay() {
  // Apparently, the IC recognizes state in descending edge.

  // Our clock signal "CLK" for the IC, no delays, is  around 42.74kHz.
   
  // There seems to be a faster way to write to a pin using direct register manipulation
  // instead of digitalWrite.

  // The reason why this isnt a for loop is so that we can use the maximum frequency 
  // available.
  // Note that the second Shift_IN signal in every bit isnt necessary if its the same.

  // The first bit to be programmed is bit1, bit0 is the last one. bit7 is external.


  // bit 1
  digitalWrite(SHIFT_IN, bit1);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, bit1); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 2
  digitalWrite(SHIFT_IN, bit2);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, bit2); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 3
  digitalWrite(SHIFT_IN, bit3);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, bit3); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 4
  digitalWrite(SHIFT_IN, bit4);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, bit4); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 5
  digitalWrite(SHIFT_IN, bit5);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, bit5); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 6
  digitalWrite(SHIFT_IN, bit6);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, bit6); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 7
  digitalWrite(SHIFT_IN, bit7);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, bit7); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 0
  digitalWrite(SHIFT_IN, bit0);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, bit0); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);
}