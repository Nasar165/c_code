#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int main()
{
    char line[MAXLINE + 1];

    printf("Concatinated string\n");
    printf("hello,"
           "world\n");

    char word[] = "hello world";
    int length = strlen(word);
    printf("Character length: %d", length);

    int i = 0;
    while (word[i] != '\0')
    {
        printf("c: %c \t", word[i], i);
        i++;
    }

    return 0;
}