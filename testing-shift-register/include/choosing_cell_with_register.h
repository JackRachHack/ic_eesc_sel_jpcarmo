void choosing_cell_with_register(int cell_num) {
    if (cell_num < 1 || cell_num > 8) cell_num = 0; // If outside boundaries, all of them are zero

    bit0 = (cell_num == 1);
    bit1 = (cell_num == 2);
    bit2 = (cell_num == 3);
    bit3 = (cell_num == 4);
    bit4 = (cell_num == 5);
    bit5 = (cell_num == 6);
    bit6 = (cell_num == 7);
    bit7 = (cell_num == 8);
}