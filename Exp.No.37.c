#include <stdio.h>
#include <pthread.h>

void* func(void* arg){ printf("Thread running\n"); pthread_exit((void*)0); return NULL; }

int main(){
    pthread_t t;
    pthread_create(&t,NULL,func,NULL);
    if(pthread_equal(pthread_self(), t)) printf("Same thread\n"); else printf("Different thread\n");
    pthread_join(t,NULL);
    printf("Main exiting\n");
    return 0;
}
