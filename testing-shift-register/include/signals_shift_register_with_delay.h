void signals_shift_register_with_delay() {
  // Apparently, the IC recognizes state in ascending edge.

  // Our clock signal "CLK" for the IC, no delays, is  around 42.74kHz.
   
  // There seems to be a faster way to write to a pin using direct register manipulation
  // instead of digitalWrite.

  // The reason why this isnt a for loop is to use the maximum frequency available (dont know if it matters, but...)

  // Aparently, the sequency to be programmed is 7->0 !!!!!!!!!! (bit 7 is external)

  if (DELAY < 16000){
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
  } else {
    DELAY = DELAY / 1000;
    // bit 7
    digitalWrite(SHIFT_IN, bit7);
    delay(DELAY);
    digitalWrite(CLK, LOW);
    delay(DELAY);
    digitalWrite(SHIFT_IN, bit7); // Value stored
    delay(DELAY);
    digitalWrite(CLK, HIGH);
    delay(DELAY);

    // bit 6
    digitalWrite(SHIFT_IN, bit6);
    delay(DELAY);
    digitalWrite(CLK, LOW);
    delay(DELAY);
    digitalWrite(SHIFT_IN, bit6); // Value stored
    delay(DELAY);
    digitalWrite(CLK, HIGH);
    delay(DELAY);

    // bit 5
    digitalWrite(SHIFT_IN, bit5);
    delay(DELAY);
    digitalWrite(CLK, LOW);
    delay(DELAY);
    digitalWrite(SHIFT_IN, bit5); // Value stored
    delay(DELAY);
    digitalWrite(CLK, HIGH);
    delay(DELAY);

    // bit 4
    digitalWrite(SHIFT_IN, bit4);
    delay(DELAY);
    digitalWrite(CLK, LOW);
    delay(DELAY);
    digitalWrite(SHIFT_IN, bit4); // Value stored
    delay(DELAY);
    digitalWrite(CLK, HIGH);
    delay(DELAY);

    // bit 3
    digitalWrite(SHIFT_IN, bit3);
    delay(DELAY);
    digitalWrite(CLK, LOW);
    delay(DELAY);
    digitalWrite(SHIFT_IN, bit3); // Value stored
    delay(DELAY);
    digitalWrite(CLK, HIGH);
    delay(DELAY);

    // bit 2
    digitalWrite(SHIFT_IN, bit2);
    delay(DELAY);
    digitalWrite(CLK, LOW);
    delay(DELAY);
    digitalWrite(SHIFT_IN, bit2); // Value stored
    delay(DELAY);
    digitalWrite(CLK, HIGH);
    delay(DELAY);

    // bit 1
    digitalWrite(SHIFT_IN, bit1);
    delay(DELAY);
    digitalWrite(CLK, LOW);
    delay(DELAY);
    digitalWrite(SHIFT_IN, bit1); // Value stored
    delay(DELAY);
    digitalWrite(CLK, HIGH);
    delay(DELAY);
  }
}