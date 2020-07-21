#include <stdio.h>
#include <pthread.h>

long sum = 0;
void *func(void *param)
{
    long *ptr;
    ptr = (long *)param;
    long tmp;
    for (long j = 0; j < 10000000; j++)
    {
        tmp = *ptr;
        tmp++;
        *ptr = tmp;
    }
    return 0;
}

int main()
{
    pthread_t thread[500];
    for (int i = 0; i < 500; i++)
    {
        pthread_create(&thread[i], NULL, func, &sum);
    }
    for (int i = 0; i < 500; i++)
    {
        pthread_join(thread[i], NULL);
    }
    printf("%ld\n", sum);
    return 0;
}