#include <stdio.h>
#include <dirent.h>

void ListDirectory(char *path);

int main()
{
    ListDirectory("/home/");
    return 0;
}

void ListDirectory(char *path)
{
    DIR *dir = opendir(path);
    struct dirent *ep;
    while ((ep = readdir(dir)) != NULL)
    {
        printf("%s\n", ep->d_name);
    }
    closedir(dir);
}