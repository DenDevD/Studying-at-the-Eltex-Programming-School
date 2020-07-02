#include <stdbool.h>
#include "computation.h"

int main(void)
{
    bool still_working = true;
    int selection;
    float a = 0;
    float b = 0;

    while (still_working)
    {
        printf("1 - Addition(+)\n2 - Subtraction(-)\n3 - Multiplication(*)\n4 - Division(/)\n5 - Exit\n");
        printf("Choose an operation: ");
        scanf("%d", &selection);

        switch (selection)
        {
        case 1:
            addition(a, b);
            break;
        case 2:
            subtraction(a, b);
            break;
        case 3:
            multiplication(a, b);
            break;
        case 4:
            division(a, b);
            break;
        case 5:
            still_working = false;
            break;
        }
    }

    return 0;
}