#include <stdio.h>

const unsigned char N = 5;

int main(void)
{
    unsigned char array[N];
    for (unsigned char i = 0; i < N; i++)
    {
        array[i] = N - i;
        printf("%d", array[i]);
    }
    printf("\n");
    return 0;
}