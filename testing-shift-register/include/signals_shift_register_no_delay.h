void signals_shift_register_no_delay() {
  // Apparently, the IC recognizes state in descending edge.

  // Our clock signal, no delays, is  around 42.74kHz.
   
  // There seems to be a faster way to write to a pin using direct register manipulation
  // instead of digitalWrite.

  // The reason why this isnt a for loop is to use the maximum frequency available.
  // Note that the second Shift_IN signal isnt necessary if its the same

  // The first bit to be programmed is bit1, bit0 is the last one. bit7 is external.

  // bit 1
  digitalWrite(SHIFT_IN, bit1);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, bit1); // Value stored
  digitalWrite(CLK, LOW);

  // bit 2
  digitalWrite(SHIFT_IN, bit2);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, bit2); // Value stored
  digitalWrite(CLK, LOW);

  // bit 3
  digitalWrite(SHIFT_IN, bit3);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, bit3); // Value stored
  digitalWrite(CLK, LOW);

  // bit 4
  digitalWrite(SHIFT_IN, bit4);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, bit4); // Value stored
  digitalWrite(CLK, LOW);

  // bit 5
  digitalWrite(SHIFT_IN, bit5);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, bit5); // Value stored
  digitalWrite(CLK, LOW);

  // bit 6
  digitalWrite(SHIFT_IN, bit6);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, bit6); // Value stored
  digitalWrite(CLK, LOW);

  // bit 7
  digitalWrite(SHIFT_IN, bit7);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, bit7); // Value stored
  digitalWrite(CLK, LOW);

  // bit 0
  digitalWrite(SHIFT_IN, bit0);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, bit0); // Value stored
  digitalWrite(CLK, LOW);
}