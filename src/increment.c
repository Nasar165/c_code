#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int i, j = 0;
    char hello[] = {"hello"};
    char world[25];
    for (i = 0; i < strlen(hello); i++)
    {
        if (hello[i] == 'l')
            world[j++] = hello[i];

        world[2] = '\0';
    }

    printf("%s\n", world);
    return 0;
}