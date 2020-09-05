#include <stdio.h>
#include <errno.h>
#include <string.h>

int FileExists(char filePath[]);

int main()
{
    FileExists("/home/xeroxcore/Downloads/linkedin.png");
    return 0;
}

int FileExists(char filePath[])
{
    FILE *file = fopen(filePath, "r");

    if (file)
    {
        fclose(file);
        printf("File exists\n");
        return 1;
    }
    else if (ENOENT == errno)
        printf("File does not exists %s\n", strerror(errno));

    return 0;
}