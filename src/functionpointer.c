#include <stdio.h>

void sayHello(char name[])
{
    printf("Hello %s", name);
}

void sayGoodbye(char name[])
{
    printf("Goodbye %s", name);
}

int main()
{
    printf("Simple function pointer\n");
    void (*p_sayHello)(char[]) = &sayHello;
    (p_sayHello)("Nasar\n");

    printf("Function pointer array\n");
    void (*p_array[])(char[]) = {&sayHello, &sayGoodbye};

    for (int i = 0; i < 2; i++)
    {
        (*p_array[i])("Nasar\n");
    }

    printf("Change function pointer array\n");
    p_array[0] = &sayGoodbye;

    for (int i = 0; i < 2; i++)
    {
        (*p_array[i])("Nasar\n");
    }
    return 0;
}