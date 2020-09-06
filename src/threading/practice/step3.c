#include <stdio.h>
#include <pthread.h>
#include <malloc.h>

void *increment()
{
    int *val = (int *)malloc(sizeof(int));
    *val = 5;
    //increment the value
    (*val)++;
    return val;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, increment, NULL);
    // add an empty int pointer
    int *v;
    // parse the memory location of the pointer to the join thread and await result
    // you will need to add (void *) before the memory address for it to convert to the correct value

    pthread_join(thread, (void *)&v);
    printf("%d\n", *v);

    return 0;
}