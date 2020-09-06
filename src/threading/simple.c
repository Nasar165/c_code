#include <stdio.h>
#include <pthread.h>

// To compile this code add -lpthread to gcc ot include threading libary
// Sample gcc simple.c -lpthread
void *entry_point()
{
    printf("hello from the second tread\n");
    return NULL;
}

int main()
{
    pthread_t thread;
    printf("hello from the first tread\n");

    pthread_create(&thread, NULL, entry_point, NULL);
    //Wait until thread is done executing code before exiting main thread;
    pthread_join(thread, NULL);
    return 0;
}