#include <stdio.h>
#include <string.h>

int error(char message[])
{
    printf("%s\n", message);
    return 1;
}

int isArgument(char argument[])
{
    if (argument[0] == '-')
        return 1;
    return 0;
}

void runArgument(char argument[], char value[], int key)
{
    if (strcmp(argument, "-pn") == 0)
        printf("Adding new Package %s\n", value);
    else
        printf("Could not find a matching argument\n");
}

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        printf("Argument Length: %d\n", argc);
        char *input[] = {argv[0]};
        for (int i = 1; i < argc; i += 2)
        {
            if (isArgument(argv[i]))
            {
                *input = argv[i];
                printf("%s\n", *input);
                runArgument(*input, argv[i + 1], i);
            }
            else
            {
                return error("An invalid argument was detected");
                break;
            }
        }
        return 1;
    }
    else
        return error("Error: Arguments missing");
}