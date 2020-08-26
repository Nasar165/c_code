#include <stdio.h>
#include <stdlib.h>

void SortArray(int array[], int length)
{
    int loops = 0;
    for (int i = 0; i < length - 1; i++)
    {
        loops++;
        for (int j = 0; j < length - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            loops++;
        }
    }
    printf("\nloops %d\n", loops);
}

int main()
{
    int number[] = {
        100,
        3,
        5,
        1,
        100,
        3,
        5,
        1,
        100,
        3,
        5,
        1,
        100,
        3,
        5,
        1,
        100,
        3,
        5,
        1,
        100,
        3,
        5,
        1,
        100,
        3,
        5,
        1,
        100,
        3,
        5,
        1,
    };

    unsigned int length = (int)(sizeof(number) / sizeof(number[0]));
    printf("Array Length %d\n", length);
    printf("unsorted array\n");
    for (int i = 0; i < length; i++)
        printf("%d\t", number[i]);
    printf("\n");
    SortArray(number, length);
    printf("sorted array\n");
    for (int i = 0; i < length; i++)
        printf("%d\t", number[i]);
    printf("\n");
    return 0;
}
