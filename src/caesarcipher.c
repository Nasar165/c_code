#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum
{
    false = 0,
    true,

} boolean;

void keyIsValidShift(boolean *validKey, char *argv[])
{
    for (int i = 0; i < strlen(argv[1]); i++)
        if (isdigit(argv[1][i]))
            *validKey = true;
        else
        {
            *validKey = false;
            printf("Enter a valid Caesar Key\n");
        }
}

void cipherPlainText(int *key)
{
    char input[500];
    printf("plaintext: ");
    fgets(input, sizeof(input), stdin);
    for (int i = 0; i < strlen(input); i++)
        if (isupper(input[i]))
            input[i] = ((input[i] - 65 + *key) % 26) + 65;
        else if (islower(input[i]))
            input[i] = ((input[i] - 97 + *key) % 26) + 97;

    printf("Chiphertext: %s \n", input);
}

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        int key = atoi(argv[1]);
        boolean validKey = false;
        keyIsValidShift(&validKey, argv);

        if (validKey)
            cipherPlainText(&key);

        return 0;
    }
    else
    {
        printf("No Arguments\n");
        return 1;
    }
}