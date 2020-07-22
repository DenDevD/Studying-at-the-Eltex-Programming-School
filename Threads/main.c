#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
long sum = 0;
void *func(void *param)
{
    long *ptr;
    ptr = (long *)param;
    long tmp;
    pthread_mutex_lock(&mutex);
    for (long j = 0; j < 10000000; j++)
    {
        tmp = *ptr;
        tmp++;
        *ptr = tmp;
    }
    pthread_mutex_unlock(&mutex);
    return 0;
}

int main()
{
    pthread_t thread[500];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 500; i++)
    {
        pthread_create(&thread[i], NULL, func, &sum);
    }
    for (int i = 0; i < 500; i++)
    {
        pthread_join(thread[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    printf("%ld\n", sum);
    return 0;
}
