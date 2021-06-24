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

/*
How to deal with if-else statements
*/

int main3(void) {
    if (/* condition1 is false */ 1) goto case2;
        /* deal with case1 */
        goto end;
    case2:
    if (/* condition2 is false */ 1) goto case3;
        /* deal with case2 */
        goto end;
    case3:
    
        goto end;
    end:

    return 0;
}
