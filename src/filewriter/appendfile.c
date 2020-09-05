#include <stdio.h>

void appendText(char *filePath, char *text);

int main()
{
    appendText("/home/xeroxcore/test", "hello world\n");
    return 0;
}

void appendText(char *filePath, char *text)
{
    FILE *file = fopen(filePath, "a");
    fputs(text, file);
}