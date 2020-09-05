#include <stdio.h>

void readFile(char *filePath);

int main()
{
    char array[1000];
    readFile("/home/xeroxcore/test");
    return 0;
}

void readFile(char *filePath)
{
    FILE *file = fopen(filePath, "r");
    if (file)
    {
        int ch;
        while ((ch = fgetc(file)) != EOF)
        {
            printf("%c", ch);
            /* code */
        }
        fclose(file);
    }
}