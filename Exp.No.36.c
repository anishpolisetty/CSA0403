#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5
int buffer[SIZE], in=0,out=0;
sem_t empty, full, mutex;

void* producer(void* arg){
    for(int i=1;i<=10;i++){
        sem_wait(&empty); sem_wait(&mutex);
        buffer[in]=i; in=(in+1)%SIZE;
        printf("Produced %d\n", i);
        sem_post(&mutex); sem_post(&full);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg){
    for(int i=1;i<=10;i++){
        sem_wait(&full); sem_wait(&mutex);
        int item = buffer[out]; out=(out+1)%SIZE;
        printf("Consumed %d\n", item);
        sem_post(&mutex); sem_post(&empty);
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t p,c;
    sem_init(&empty,0,SIZE); sem_init(&full,0,0); sem_init(&mutex,0,1);
    pthread_create(&p,NULL,producer,NULL); pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL); pthread_join(c,NULL);
    return 0;
}
