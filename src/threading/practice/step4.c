#include <stdio.h>
#include <pthread.h>

#define BIG 10000000UL

int counter = 0;
//prevent race condition
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *CountToBig()
{
    for (size_t i = 0; i < BIG; i++)
    {
        pthread_mutex_lock(&lock); // locks the value manipulation to thread
        counter++;
        pthread_mutex_unlock(&lock); // unlocks the value manipulation to other threads
    }
    return NULL;
}

// A safe multi threaded test
// Issues app is extremely slow due to the locks and sharing memory location
// this scenario is not ideal when it comes to performance.
int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, CountToBig, NULL);
    CountToBig();
    pthread_join(thread, NULL);
    printf("result: %d\n", counter);
    return 0;
}