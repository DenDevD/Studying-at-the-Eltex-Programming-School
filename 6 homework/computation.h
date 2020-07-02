#include <stdio.h>

int addition(float a, float b)
{
    printf("Input first number A: \n");
    scanf("%f", &a);
    printf("Input second number B: \n");
    scanf("%f", &b);
    printf("Result = %f\n", a + b);
    return 0;
}

int subtraction(float a, float b)
{
    printf("Input first number A: \n");
    scanf("%f", &a);
    printf("Input second number B: \n");
    scanf("%f", &b);
    printf("Result = %f\n", a - b);
    return 0;
}

int multiplication(float a, float b)
{
    printf("Input first number A: \n");
    scanf("%f", &a);
    printf("Input second number B: \n");
    scanf("%f", &b);
    printf("Result = %f\n", a * b);
    return 0;
}

int division(float a, float b)
{
    printf("Input first number A: \n");
    scanf("%f", &a); 
    printf("Input second number B: \n");
    scanf("%f", &b);
    printf("Result = %f\n", a / b);
    return 0;
}