#include <stdio.h>

int main(void)
{
    int number = 187644256;
    char serial_number;
    char *ptr = &number;

    for(serial_number =1; serial_number <=4; serial_number++)
    {
        printf("%d byte of number = %d\n", serial_number, *ptr);
        ptr++;
    }

}