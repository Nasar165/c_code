#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int DirectoryExists(char path[]);

int main()
{
    DirectoryExists("/home/xeroxcore/Downloads");
    return 0;
}

int DirectoryExists(char path[])
{
    DIR *dir = opendir(path);

    if (dir)
    {
        printf("Directory exists\n");
        closedir(dir);
        return 1;
    }
    else if (ENOENT == errno)
    {
        printf("%s\n", strerror(errno));
    }
    else
    {
        printf("Something went wrong\n");
    }

    return 0;
}