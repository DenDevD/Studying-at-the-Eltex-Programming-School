#include <stdio.h>
#include <stdbool.h>
#include "prototype.h"
#include <dlfcn.h>

int main(int argc, char *argv[])
{
	// void *dlopen(const char *filename, int flag);
	void *library_handler;
	int a, b;
	float a1, b1;
	float (*powerfunc)(float a, float b);
	library_handler = dlopen("libcalc.so", RTLD_NOW);
	if (!library_handler)
	{
		fprintf(stderr, "dlopen() error: %s\n", dlerror());
	}
	else
	{
		powerfunc = dlsym(library_handler, argv[1]);
		// a = 5;
		// b = 1;
		if(argv[1] != NULL)
		{
		printf("Input first number A: \n");
		scanf("%f", &a1);
		printf("Input second number B: \n");
		scanf("%f", &b1);
		printf("%s = %f\n", argv[1], powerfunc(a1, b1));
		dlclose(library_handler);
		return 0;
		}
		else
		{
			printf("Error!");
		}
		
	}
}