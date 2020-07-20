#include <stdio.h>
#include <stdbool.h>
#include "prototype.h"
#include <dlfcn.h>

int main(int argc, char *argv[])
{
	void *library_handler;
	void *library_handler1;
	void *library_handler2;
	void *library_handler3;
	int a, b;
	char addition[40] = "./plugins/libaddition.so";
	char subtraction[40] = "./plugins/libsubtraction.so";
	char multiplication[40] = "./plugins/libmultiplication.so";
	char division[40] = "./plugins/libdivision.so";
	float a1, b1;
	float (*powerfunc)(float a, float b);
	library_handler = dlopen(addition, RTLD_NOW);
	library_handler1 = dlopen(subtraction, RTLD_NOW);
	library_handler2 = dlopen(multiplication, RTLD_NOW);
	library_handler3 = dlopen(division, RTLD_NOW);
	if (!library_handler && !library_handler1 && !library_handler2 && !library_handler3)
	{
		fprintf(stderr, "dlopen() error: %s\n", dlerror());
	}
	else
	{
		printf("1 - addition\n2 - division\n3 - subtraction\n4 - multiplication");
		char userInput = scanf("%c", &userInput);
		switch (userInput)
		{
		case 1:
			powerfunc = dlsym(library_handler, argv[1]);
			if (argv[1] != NULL)
			{
				printf("%s = %f\n", argv[1], powerfunc(a1, b1));
				dlclose(library_handler);
				break;
			}
		case 2:
			powerfunc = dlsym(library_handler3, argv[1]);
			if (argv[1] != NULL)
			{
				printf("%s = %f\n", argv[1], powerfunc(a1, b1));
				dlclose(library_handler3);
			}
			break;
		case 3:
			powerfunc = dlsym(library_handler1, argv[1]);
			if (argv[1] != NULL)
			{
				printf("%s = %f\n", argv[1], powerfunc(a1, b1));
				dlclose(library_handler1);
			}
			break;
		case 4:
			powerfunc = dlsym(library_handler2, argv[1]);
			if (argv[1] != NULL)
			{
				printf("%s = %f\n", argv[1], powerfunc(a1, b1));
				dlclose(library_handler2);
			}
			break;
		default:
			printf("Error!");
			break;
		}
	}
	return 0;
}