#include <stdio.h>

const unsigned char N = 5;
unsigned char a = 1;

int main(void)
{
    unsigned char array[N][N];
    for (unsigned char i = 0; i < N; i++)
    {
        array[0][i] = a;
        a++;
    }
    for (unsigned char j = 1; j < N; j++)
    {
        array[j][N-1] = a;
        a++;
    }
   for(unsigned char i = N-2; i>=0; i--)
    {
        array[N-1][i] = a;
        a++;
    }
    //TODO
    for (unsigned char i = 0; i < N; i++)
    {
        for (unsigned char j = 0; j < N; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}
