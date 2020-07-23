#include <stdio.h>
#include <string.h>

int error(char message[])
{
    printf("%s\n", message);
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        printf("Argument Length: %d\n", argc);
        char *input[] = {argv[0]};
        for (int i = 1; i < argc; i += 2)
        {
            *input = argv[i];
            printf("%s\n", *input);
        }

        return 1;
    }
    else
        return error("Error: Arguments missing");
}