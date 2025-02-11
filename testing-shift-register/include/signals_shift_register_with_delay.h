void signals_shift_register_with_delay() {

  // Entering "11001100" in the shift register

  // Apparently, the IC recognizes state in descending edge.

  // Our clock signal, no delays, is  around 42.74kHz.
  // 
  // Funny observation: there is one random semi-cycle that is larger (80%) than the
  // others. Its value can be 0 or 1 and it seems to apper once every (at least) 43 
  // cyles. It may be due to Arduino operation or something like that and shouldnt
  // be a problem, at least at first sight.


  // digitalWrite(CLK, LOW);

  // bit 0
  digitalWrite(SHIFT_IN, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, HIGH); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 1
  digitalWrite(SHIFT_IN, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, HIGH); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 2
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 3
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 4
  digitalWrite(SHIFT_IN, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, HIGH); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 5
  digitalWrite(SHIFT_IN, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, HIGH); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 6
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 7
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 8 (all zeros above here)
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 9
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 10
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 11
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 12
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 13
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 14
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);

  // bit 15
  digitalWrite(SHIFT_IN, LOW);
  delayMicroseconds(DELAY);
  digitalWrite(CLK, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  delayMicroseconds(DELAY);
  digitalWrite(CLK, LOW);
  delayMicroseconds(DELAY);
}