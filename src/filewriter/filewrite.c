#include <stdio.h>
#include <errno.h>
#include <string.h>

void WriteToFile(char filePath[], char text[]);

int main()
{
    WriteToFile("/home/xeroxcore/test", "hello world\n");
    return 0;
}

int FilePathIsValid(char path[])
{
    int result = 0;
    FILE *file = fopen(path, "r");

    if (file)
    {
        fclose(file);
        result = 1;
    }
    return result;
}

void WriteToFile(char filePath[], char text[])
{
    if (FilePathIsValid(filePath))
    {
        FILE *file = fopen(filePath, "w");
        fprintf(file, text);
        fputs(text, file);
        fclose(file);
    }
    else
    {
        printf("Invalid filepath\n");
    }
}
