#include <stdio.h>
#include <pthread.h>
#include <unistd.h> // import sleep function

void *MyTurn(void *arg)
{
    while (1)
    {
        sleep(1);
        printf("my turn!\n");
    }
    return NULL;
}

void YourTurn()
{
    while (1)
    {
        sleep(2);
        printf("Your turn!\n");
    }
}

int main()
{
    pthread_t thread;

    pthread_create(&thread, NULL, MyTurn, NULL);
    YourTurn();
    pthread_join(thread, NULL);
    return 0;
}