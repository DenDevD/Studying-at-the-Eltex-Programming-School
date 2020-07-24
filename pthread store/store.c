#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex[5] = PTHREAD_MUTEX_INITIALIZER;
int store[5];
int i;

void *worker()
{
    int i;
    int delivery = 500;
    while (1)
    {
        i = rand() % 5;
        if (pthread_mutex_trylock(&mutex[i]) == 0)
        {
            store[i] += delivery;
            printf("Worker was delivered %d product to %d store\n", delivery, i);
            pthread_mutex_unlock(&mutex[i]);
        }
        sleep(1);
    }
}

void *buyer()
{
    int i;
    int need = 10000;
    while (need != 0)
    {
        i = rand() % 5;
        if (pthread_mutex_trylock(&mutex[i]) == 0) //Если мьютекс свободен
        {
            if (store[i] != 0 && need > store[i]) // если магазин не пуст и в нём меньше чем требуется
            {
                need -= store[i];
                store[i] = 0;
                printf("I'm in %d store and buy %d product\n", i + 1, store[i]);
                pthread_mutex_unlock(&mutex[i]);
            }
            else if (store[i] != 0 && need <= store[i]) //если магазин не пуст и в нём больше чем требуется
            {
                store[i] -= need;
                need = 0;
                pthread_mutex_unlock(&mutex[i]);
                printf("I'm in %d store and buy my last product\n", i + 1);
            }
            else if (store[i] == 0) //если магазин пуст
            {
                printf("%d store is empty\n", i + 1);
                pthread_mutex_unlock(&mutex[i]);
            }
        }
        else
        {
            printf("%d store is closed\n", i + 1);
        }
        printf("Need = %d\n", need);
        sleep(2);
    }
}

int main(void)
{
    pthread_t buyer_tid[3];
    pthread_t worker_tid;
    pthread_mutex_init(&mutex[i], NULL);
    for (int j = 0; j < 5; j++)
    {
        store[i] = 450 + rand() % 100;
    }
    pthread_create(&worker_tid, NULL, worker, NULL);
    for (int i = 0; i < 3; i++)
    {
        pthread_create(&buyer_tid[i], NULL, buyer, NULL);
    }
    for (int i = 0; i < 3; i++)
    {
        pthread_join(buyer_tid[i], NULL);
    }
    pthread_join(worker_tid, NULL);
    return 0;
}