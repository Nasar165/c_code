#include <stdio.h>

extern void PrintMessage(char *message[]);

void printMessage(char *message[])
{
    printf("%s\n", message);
}
