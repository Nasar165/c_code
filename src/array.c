#include <stdio.h>
#include <string.h>

int main()
{
    int array[] = {1, 42, 33, 18};
    int *parray;
    parray = array;
    int i;
    for (i = -1; i < 3; i++)
        printf("%d \n", parray[*parray + i]);
    return 0;
}