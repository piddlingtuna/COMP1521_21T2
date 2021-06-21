/*
Translate this C program so it uses goto rather than if/else.

Then translate it to MIPS assembler.
*/

// Simple factorial calculator  - without error checking

#include <stdio.h>

int main (void) {
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;
    for (int i = 1; i <= n; i++) {
        fac *= i;
    }

    printf ("n! = %d\n", fac);
    return 0;
}
