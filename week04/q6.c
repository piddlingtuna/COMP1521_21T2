/*
Translate this C program so it uses goto rather than if/else.

Then translate it to MIPS assembler.
*/

// Print a triangle

#include <stdio.h>

int main (void) {
    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }
        printf("\n");
    };
    return 0;
}
