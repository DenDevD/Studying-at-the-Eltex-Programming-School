#include <stdio.h>

const unsigned char N = 5;
unsigned char number = 21;

int main(void)
{
    unsigned char matrix[N][N];
    for (unsigned char i = 0; i < N; i++)
    {
        for (unsigned char j = 0; j < N; j++)
        {
            if ((i+j)>(N-2))
            {
                matrix[i][j] = 1;
            }
            else
            {
                matrix[i][j] = 0;
            }
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}