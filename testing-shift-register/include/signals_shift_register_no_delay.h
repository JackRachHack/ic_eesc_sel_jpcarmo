void signals_shift_register_no_delay() {

  // Entering "11001100" in the shift register

  // Since the shift register in the IC is 8bit, we will need
  // 16 pulses of clock to both enter a 8bit value in SHIFT_IN
  // and read a 8bit value in the SHIFT_OUT. Update: in our IC
  // there is no SHIFT_OUT, so we will do a "blind" test.

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
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, HIGH); // Value stored
  digitalWrite(CLK, LOW);

  // bit 1
  digitalWrite(SHIFT_IN, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, HIGH); // Value stored
  digitalWrite(CLK, LOW);

  // bit 2
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 3
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 4
  digitalWrite(SHIFT_IN, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, HIGH); // Value stored
  digitalWrite(CLK, LOW);

  // bit 5
  digitalWrite(SHIFT_IN, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, HIGH); // Value stored
  digitalWrite(CLK, LOW);

  // bit 6
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 7
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 8 (all zeros above here)
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 9
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 10
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 11
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 12
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 13
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 14
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);

  // bit 15
  digitalWrite(SHIFT_IN, LOW);
  digitalWrite(CLK, HIGH);
  digitalWrite(SHIFT_IN, LOW); // Value stored
  digitalWrite(CLK, LOW);
}