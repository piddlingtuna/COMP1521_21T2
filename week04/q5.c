/*
Translate this C program so it uses goto rather than if/else.

Then translate it to MIPS assembler.
*/

#include <stdio.h>

int main(void) {
    for (int x = 24; x < 42; x += 3) {
        printf("%d\n",x);
    }
}

/*
Consider this alternate version of the above program, use its approach to produce simpler MIPS assembler.
*/

#include <stdio.h>

int main2(void) {
    int x = 24;

    loop:
    if (x >= 42) goto end;

        printf("%d", x);
        printf("%c", '\n');

        x += 3;

        goto loop;
    end:

    return 0;
}
