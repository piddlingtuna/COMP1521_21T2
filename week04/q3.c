/*
Translate this C program so it uses goto rather than if/else.

Then translate it to MIPS assembler.
*/

// Print the square of a number

#include <stdio.h>

int main(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 46340) {
        printf("square too big for 32 bits\n");
    } else {
        y = x * x;
        printf("%d\n", y);
    }
    
    return 0;
}

/*
Consider this alternate version of the above program, use its approach to produce simpler MIPS assembler.
*/

#include <stdio.h>

int main2(void) {
    int x, y;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x <= 46340) goto square;
        printf("square too big for 32 bits\n");
        goto end;
    square:
        y = x * x;
        printf("%d\n", y);
    end:

    return 0;
}
