#include <stdio.h>
#include <pthread.h>

void *SecondThread(void *value)
{
    // convert void value into a int
    int *num = (int *)value;
    printf("Value: %d\n", *num);
    return NULL;
}

int main()
{
    pthread_t thread;

    int value = 123;
    pthread_create(&thread, NULL, SecondThread, &value);
    pthread_join(thread, NULL);

    return 0;
}
