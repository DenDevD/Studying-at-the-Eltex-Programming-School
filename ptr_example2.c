#include <stdio.h>

int main(void)
{
    char a = 'A';
    char b = 'B';
    char *ptr1 = &a;
    char **ptr2 = &ptr1;

    **ptr2 = b;

    printf("%c\n", *ptr1);
}