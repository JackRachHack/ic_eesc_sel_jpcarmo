void signals_shift_register_no_delay() {
  // Apparently, the IC recognizes state in ascending edge.

  // Our clock signal, no delays, is  around 42.74kHz.
   
  // There seems to be a faster way to write to a pin using direct register manipulation
  // instead of digitalWrite.

  // The reason why this isnt a for loop is to use the maximum frequency available (dont know if it matters, but...)

  // Aparently, the sequency to be programmed is 7->0 !!!!!!!!!! (bit 7 is external)

  // bit 7
  digitalWrite(SHIFT_IN, bit7);
  digitalWrite(CLK, LOW);
  digitalWrite(SHIFT_IN, bit7); // Value stored
  digitalWrite(CLK, HIGH);

  // bit 6
  digitalWrite(SHIFT_IN, bit6);
  digitalWrite(CLK, LOW);
  digitalWrite(SHIFT_IN, bit6); // Value stored
  digitalWrite(CLK, HIGH);

  // bit 5
  digitalWrite(SHIFT_IN, bit5);
  digitalWrite(CLK, LOW);
  digitalWrite(SHIFT_IN, bit5); // Value stored
  digitalWrite(CLK, HIGH);

  // bit 4
  digitalWrite(SHIFT_IN, bit4);
  digitalWrite(CLK, LOW);
  digitalWrite(SHIFT_IN, bit4); // Value stored
  digitalWrite(CLK, HIGH);

  // bit 3
  digitalWrite(SHIFT_IN, bit3);
  digitalWrite(CLK, LOW);
  digitalWrite(SHIFT_IN, bit3); // Value stored
  digitalWrite(CLK, HIGH);

  // bit 2
  digitalWrite(SHIFT_IN, bit2);
  digitalWrite(CLK, LOW);
  digitalWrite(SHIFT_IN, bit2); // Value stored
  digitalWrite(CLK, HIGH);

  // bit 1
  digitalWrite(SHIFT_IN, bit1);
  digitalWrite(CLK, LOW);
  digitalWrite(SHIFT_IN, bit1); // Value stored
  digitalWrite(CLK, HIGH);

  // bit 0
  digitalWrite(SHIFT_IN, bit0);
  digitalWrite(CLK, LOW);
  digitalWrite(SHIFT_IN, bit0); // Value stored
  digitalWrite(CLK, HIGH);
}