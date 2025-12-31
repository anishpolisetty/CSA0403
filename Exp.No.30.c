#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// Thread function
void* myThread(void *arg) {
    printf("Thread running...\n");
    pthread_exit((void*) 0);  // exit thread
}

int main() {
    pthread_t t1, t2;
    void *retval;

    // (i) CREATE threads
    pthread_create(&t1, NULL, myThread, NULL);
    pthread_create(&t2, NULL, myThread, NULL);

    // (ii) JOIN threads
    pthread_join(t1, &retval);
    printf("Thread t1 exited with value %ld\n", (long)retval);

    pthread_join(t2, &retval);
    printf("Thread t2 exited with value %ld\n", (long)retval);

    // (iii) EQUAL threads
    if (pthread_equal(t1, t2))
        printf("Threads t1 and t2 are equal\n");
    else
        printf("Threads t1 and t2 are not equal\n");

    // (iv) EXIT main thread
    printf("Main thread exiting...\n");
    pthread_exit(NULL);

    return 0;
}
