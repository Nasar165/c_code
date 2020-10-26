#include <stdio.h>

int main (){
    int c, b;
    b = 6;

    int c = b &= 0b00000100; // checks if the binary 00000>1<00 is activated in b and returns the same value if true and 0 if false 

    printf("b = %d c = %d\n",b, c);

    b = 2;
    c = b |= 0b00000100; // Here we use the or operator and we assigned 0b00000>1<00 (4) to the value of 2 if the binary location is set to 0
    printf("b = %d c = %d\n",b, c);

    return 0;
}