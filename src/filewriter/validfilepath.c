#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>

/* 
    A function that removes the filename and validates the directory path 
    before writing a file to the directory.
*/

int DirectoryExists(char *array);

int main()
{
    char filePath[] = "/home/xeroxcore/Downloads/testme";
    if (DirectoryExists(filePath))
        printf("Directory Exists\n");

    return 0;
}

void RemoveFileFromFilePath(char *path)
{
    int i;
    for (i = strlen(path); i > 0; --i)
        if (path[i] == '/')
        {
            path[i + 1] = '\0';
            break;
        }
}

int DirectoryExists(char *path)
{
    RemoveFileFromFilePath(path);
    DIR *directory = opendir(path);

    if (directory)
    {
        closedir(directory);
        return 1;
    }
    else if (ENOENT == errno)
        printf("%s\n", strerror(errno));

    return 0;
}
