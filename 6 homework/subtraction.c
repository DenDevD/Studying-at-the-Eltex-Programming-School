#include <stdio.h>

float subtraction(float a, float b)
{
    printf("Input first number A: \n");
    scanf("%f", &a);
    printf("Input second number B: \n");
    scanf("%f", &b);
    printf("Result = %f\n", a - b);
    return 0;
}