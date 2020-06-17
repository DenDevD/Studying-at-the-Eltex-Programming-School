#include <stdio.h>

int main(void)
{
    unsigned main_number = 0xAABBCCDD;
    unsigned main_number2 = 0xAABBCCDD;
    const unsigned char start_value = 1;
    const unsigned char final_value = 4;
    const int left_byte_shift = 24;
    const int right_byte_shift = 16;

    for (unsigned char serial_number = start_value; serial_number <= final_value; serial_number++)
    {
        int cycle_byte_shift = 8;
        unsigned factor = ((main_number >> cycle_byte_shift * (serial_number - 1)) & 0xFF);
        printf("%d byte of a: %x\n", serial_number, factor);
    }
    main_number2 = main_number2 << left_byte_shift >> right_byte_shift;
    printf("replacement of CC with DD: %x\n", main_number2);
    return 0;
}