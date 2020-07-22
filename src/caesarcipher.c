#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
    false = 0,
    true,

} boolean;

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        boolean validKey = false;
        int i;
        for (i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]))
            {
                validKey = true;
            }
            else
            {
                printf("Enter Caesar Key\n");
                return 1;
            }
        }

        if (validKey)
        {
            char input[500];
            printf("plaintext: ");
            fgets(input, sizeof(input), stdin);

            for (i = 0; i < strlen(input); i++)
            {
                if (isupper(input[i]))
                    input[i] = ((input[i] - 65 + key) % 26) + 65;
                else if (islower(input[i]))
                    input[i] = ((input[i] - 97 + key) % 26) + 97;
            }
            printf("Chiphertext: %s \n", input);
        }
        return 0;
    }
    else
    {
        printf("No Arguments\n");
        return 1;
    }
}