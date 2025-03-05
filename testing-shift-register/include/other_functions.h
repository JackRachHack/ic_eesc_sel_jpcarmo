void choosing_cell_with_register(int cell_num) {
    bit1 = (cell_num == 1);
    bit2 = (cell_num == 2);
    bit3 = (cell_num == 3);
    bit4 = (cell_num == 4);
    bit5 = (cell_num == 5);
    bit6 = (cell_num == 6);
    bit7 = (cell_num == 7);
    bit0 = (cell_num == 0);
}

int getValidIntFromSerial(const char* prompt, int minVal, long int maxVal) {
    int value;
    String input;  // Stores user input as a string

    while (true) {
        Serial.println(prompt);
        input = "";  // Clear previous input

        // Wait until the user starts typing
        while (!Serial.available());

        // Read the entire input until Enter ('\n') is pressed
        while (true) {
            if (Serial.available()) {
                char c = Serial.read();
                if (c == '\n') break;  // Stop reading when Enter is detected
                Serial.print(c);  // Echo the character back to the terminal
                input += c;  // Append the character to the input string
            }
        }
        Serial.println();  // Move to a new line after input is entered

        Serial.print("You entered: ");
        Serial.println(input);

        value = input.toInt();  // Convert input string to integer

        // Validate the entered value
        if (value >= minVal && value <= maxVal) {
            return value;
        }
        Serial.println("Invalid value. Try again.");
    }
}