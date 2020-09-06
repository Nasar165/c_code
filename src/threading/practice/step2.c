#include <stdio.h>
#include <pthread.h>

void *increment(void *arg)
{
    int *val = (int *)arg;
    //increment the value
    (*val)++;
}

int main()
{
    pthread_t thread;
    int v = 0;
    pthread_create(&thread, NULL, increment, &v);
    pthread_join(thread, NULL);
    printf("%d\n", v);

    return 0;
}