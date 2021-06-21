/*
Translate this C program so it uses goto rather than if/else.

Then translate it to MIPS assembler.
*/
#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > 100 && x < 1000) {
        printf("medium\n");
    } else {
        printf("small/big\n");
    }
    
    return 0;
}

/*
Consider this alternate version of the above program, use its approach to produce simpler MIPS assembler.
*/

#include <stdio.h>

int main2(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    char *message = "small/big\n";
    if (x > 100 && x < 1000) {
        message = "medium";
    }

    printf("%s", message);

    return 0;
}
