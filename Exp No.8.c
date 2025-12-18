#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t forks[5];

void* philosopher(void* num) {
    int id = *(int*)num;

    printf("Philosopher %d is thinking...\n", id);
    sem_wait(&forks[id]);
    sem_wait(&forks[(id+1)%5]);

    printf("Philosopher %d is eating...\n", id);
    sleep(1);

    sem_post(&forks[id]);
    sem_post(&forks[(id+1)%5]);

    printf("Philosopher %d finished eating.\n", id);
    return NULL;
}

int main() {
    pthread_t ph[5];
    int ids[5]={0,1,2,3,4};
    int i;

    for (i = 0; i < 5; i++)
        sem_init(&forks[i], 0, 1);

    for (i = 0; i < 5; i++)
        pthread_create(&ph[i], NULL, philosopher, &ids[i]);

    for (i = 0; i < 5; i++)
        pthread_join(ph[i], NULL);

    return 0;
}
