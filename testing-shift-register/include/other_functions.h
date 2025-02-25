void choosing_cell_with_register(int cell_num) {
    if (cell_num < 0 || cell_num > 7) cell_num = -1; // If outside boundaries, all of them are zero

    bit1 = (cell_num == 1);
    bit2 = (cell_num == 2);
    bit3 = (cell_num == 3);
    bit4 = (cell_num == 4);
    bit5 = (cell_num == 5);
    bit6 = (cell_num == 6);
    bit7 = (cell_num == 7);
    bit0 = (cell_num == 0);
}

int getValidIntFromSerial(const char* prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        Serial.println(prompt);
        while (!Serial.available()); // Wait to detect something
        value = Serial.parseInt();
        if (value >= minVal && value <= maxVal) {
            return value;
        }
        Serial.println("Invalid value. Try again.");
    }
}