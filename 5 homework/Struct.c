#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char name[10];
    int number;
} phonebook;

int main(void)
{
    int selection;
    bool still_works = true;
    char temp_name[10];
    int temp_number;
    unsigned int i;
    unsigned int flag = 0;

    phonebook record[10];
    strcpy(record[0].name, "Denis");
    record[0].number = 132456;

    strcpy(record[1].name, "Pavel");
    record[1].number = 234567;

    strcpy(record[2].name, "Oleg");
    record[2].number = 345678;

    strcpy(record[3].name, "Alina");
    record[3].number = 456789;

    strcpy(record[4].name, "Svetlana");
    record[4].number = 567890;

    while (still_works)
    {
        printf("1 - show all\n2 - search by name\n3 - remove record\n4 - add record\n5 - exit\n");
        printf("\nselect a comand: ");
        scanf("%d", &selection);
        switch (selection)
        {
        case 1:
            for (i = 0; i < 5; i++)
            {
                printf("\nName - %-11s number - %d\n", record[i].name, record[i].number);
            }
            break;
        case 2:
            printf("\nEnter name: \n");
            scanf("%s", temp_name);
            for (i = 0; i < 5; i++)
            {
                if (strcmp(record[i].name, temp_name) == 0)
                {
                    printf("\nRecord is found: %s - %d\n", record[i].name, record[i].number);
                    flag = 1;
                }
            }
            if (flag != 1)
                printf("\nRecord is not found\n");
            break;
        case 3:
            printf("\nEnter number of record from 1 to 5 to delete: \n");
            scanf("%d", &temp_number);
            printf("\nWill be deleted: %s - %d\n", record[temp_number - 1].name, record[temp_number - 1].number);
            for (i = 0; i < 5; i++)
            {
                record[temp_number - 1].name[i] = '0';
            }
            record[temp_number - 1].number = 0;
            break;
        case 4:
            printf("\nEnter number of record from 1 to 5 to modify: \n");
            scanf("%d", &i);
            printf("\nRecord will be modifed: %s - %d\n", record[i-1].name, record[i-1].number);
            printf("\nEnter new name for record (length 1-10): \n");
            scanf("%s", temp_name);
            printf("\nEnter new phone number (length 6): \n");
            scanf("%d", &temp_number);
            strcpy(record[i-1].name, temp_name);
            record[i-1].number = temp_number;
            printf("\nNew record: %s - %d\n", record[i-1].name, record[i-1].number);
            break;
        case 5:
            still_works = false;
            break;
        default:
            printf("\nThis comand is not found!\n");
            break;
        }
    }
}
