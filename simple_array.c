#include <stdio.h>

const unsigned char N = 3;

int main(void)
{
    unsigned char array[N][N];
    for (unsigned char i = 0; i < N; i++)
    {
        for (unsigned char j = 0; j < N; j++)
        {
            array[i][j] = (N * i) + j + 1;
            printf("%d", array[i][j]);
        }
        printf("\n");
    }
    return 0;
}