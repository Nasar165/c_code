#include <stdio.h>

int main()
{
    int value = 23;

    int *pValue = &value;

    printf("Name \t value \t pointer \n");

    printf("%s \t %d \t %p \n", "value", value, &value);
    printf("%s \t %d \t %p \n", "pvalue", *pValue, pValue);

    *pValue = 41;
    printf("Name \t value \t pointer \n");
    printf("%s \t %d \t %p \n", "pvalue", *pValue, pValue);
    return 0;
}