// Global register bits
bool bit0 = false; // 0
bool bit1 = false; // 1
bool bit2 = false; // 2
bool bit3 = false; // 3
bool bit4 = false; // 4
bool bit5 = false; // 5
bool bit6 = false; // 6
bool bit7 = false; // 7

// Global int variable to select cell
int cell_number = 4;

// Global variable to choose frequency
bool freq_en = false;

// ================================================

// Global variable for frequency of the clock in hertz (if its being used) (CANT EXCEED 42740!!!)
int freq = 500;
int DELAY; // To be defined and used in the signals functions
int res_interval = 3*120; // How many microseconds until next reset signal