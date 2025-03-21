void signals_shift_register_with_delay() {
  // Apparently, the IC recognizes state in ascending edge.

  // Our clock signal "CLK" for the IC, no delays, is  around 42.74kHz.
   
  // There seems to be a faster way to write to a pin using direct register manipulation
  // instead of digitalWrite.

  // The reason why this isnt a for loop is to use the maximum frequency available (dont know if it matters, but...)

  // Aparently, the sequency to be programmed is 7->0 !!!!!!!!!! (bit 7 is external)

  // bit 7
digitalWrite(SHIFT_IN, bit7);
delayMicroseconds(DELAY);
digitalWrite(CLK, LOW);
delayMicroseconds(DELAY);
digitalWrite(SHIFT_IN, bit7); // Value stored
delayMicroseconds(DELAY);
digitalWrite(CLK, HIGH);
delayMicroseconds(DELAY);

// bit 6
digitalWrite(SHIFT_IN, bit6);
delayMicroseconds(DELAY);
digitalWrite(CLK, LOW);
delayMicroseconds(DELAY);
digitalWrite(SHIFT_IN, bit6); // Value stored
delayMicroseconds(DELAY);
digitalWrite(CLK, HIGH);
delayMicroseconds(DELAY);

// bit 5
digitalWrite(SHIFT_IN, bit5);
delayMicroseconds(DELAY);
digitalWrite(CLK, LOW);
delayMicroseconds(DELAY);
digitalWrite(SHIFT_IN, bit5); // Value stored
delayMicroseconds(DELAY);
digitalWrite(CLK, HIGH);
delayMicroseconds(DELAY);

// bit 4
digitalWrite(SHIFT_IN, bit4);
delayMicroseconds(DELAY);
digitalWrite(CLK, LOW);
delayMicroseconds(DELAY);
digitalWrite(SHIFT_IN, bit4); // Value stored
delayMicroseconds(DELAY);
digitalWrite(CLK, HIGH);
delayMicroseconds(DELAY);

// bit 3
digitalWrite(SHIFT_IN, bit3);
delayMicroseconds(DELAY);
digitalWrite(CLK, LOW);
delayMicroseconds(DELAY);
digitalWrite(SHIFT_IN, bit3); // Value stored
delayMicroseconds(DELAY);
digitalWrite(CLK, HIGH);
delayMicroseconds(DELAY);

// bit 2
digitalWrite(SHIFT_IN, bit2);
delayMicroseconds(DELAY);
digitalWrite(CLK, LOW);
delayMicroseconds(DELAY);
digitalWrite(SHIFT_IN, bit2); // Value stored
delayMicroseconds(DELAY);
digitalWrite(CLK, HIGH);
delayMicroseconds(DELAY);

// bit 1
digitalWrite(SHIFT_IN, bit1);
delayMicroseconds(DELAY);
digitalWrite(CLK, LOW);
delayMicroseconds(DELAY);
digitalWrite(SHIFT_IN, bit1); // Value stored
delayMicroseconds(DELAY);
digitalWrite(CLK, HIGH);
delayMicroseconds(DELAY);

  // Cemetery (wrong order and wrong sensitive edge(descending))
  // // bit 1
  // digitalWrite(SHIFT_IN, bit1);
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, HIGH);
  // delayMicroseconds(DELAY);
  // digitalWrite(SHIFT_IN, bit1); // Value stored
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, LOW);
  // delayMicroseconds(DELAY);

  // // bit 2
  // digitalWrite(SHIFT_IN, bit2);
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, HIGH);
  // delayMicroseconds(DELAY);
  // digitalWrite(SHIFT_IN, bit2); // Value stored
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, LOW);
  // delayMicroseconds(DELAY);

  // // bit 3
  // digitalWrite(SHIFT_IN, bit3);
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, HIGH);
  // delayMicroseconds(DELAY);
  // digitalWrite(SHIFT_IN, bit3); // Value stored
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, LOW);
  // delayMicroseconds(DELAY);

  // // bit 4
  // digitalWrite(SHIFT_IN, bit4);
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, HIGH);
  // delayMicroseconds(DELAY);
  // digitalWrite(SHIFT_IN, bit4); // Value stored
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, LOW);
  // delayMicroseconds(DELAY);

  // // bit 5
  // digitalWrite(SHIFT_IN, bit5);
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, HIGH);
  // delayMicroseconds(DELAY);
  // digitalWrite(SHIFT_IN, bit5); // Value stored
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, LOW);
  // delayMicroseconds(DELAY);

  // // bit 6
  // digitalWrite(SHIFT_IN, bit6);
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, HIGH);
  // delayMicroseconds(DELAY);
  // digitalWrite(SHIFT_IN, bit6); // Value stored
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, LOW);
  // delayMicroseconds(DELAY);

  // // bit 7
  // digitalWrite(SHIFT_IN, bit7);
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, HIGH);
  // delayMicroseconds(DELAY);
  // digitalWrite(SHIFT_IN, bit7); // Value stored
  // delayMicroseconds(DELAY);
  // digitalWrite(CLK, LOW);
  // delayMicroseconds(DELAY);
}