/*
Translate this C program to MIPS assembler.
Store variable x in register $t0 and store variable y in register $t1.
*/

// Print the square of a number

#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);
    y = x * x;
    printf("%d\n", y);
    return 0;
}
