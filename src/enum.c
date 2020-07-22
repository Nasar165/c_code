#include <stdio.h>

enum months
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC,
};

enum filemode
{
    WRITE = 'w',
    READ = 'r',
    APPEND = 'a'
};

enum boolean
{
    false = 0,
    true

};

int main()
{
    enum months month;
    month = FEB;
    printf("%d\n", month);

    enum boolean expression;
    expression = true;

    printf("boolean expression %d \n", expression);

    if (expression)
        printf("it's true\n");
    else
        printf("it's false\n");

    enum filemode file;
    file = APPEND;
    printf("File mode is set to %c\n", file);

    return 0;
}