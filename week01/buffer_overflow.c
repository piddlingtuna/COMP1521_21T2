/**
 * This program demonstrates a buffer overflow.
 * C does not check the bounds of buffers (i.e. arrays) so will continue to write memory passed the bounds.
 * This lets you overwrite the value of check.
 */
#include <stdio.h>
#include <string.h>

int main(void) {
    char buffer[5];
    char check = 'a';

    printf("Enter a string: \n");
    scanf("%s", buffer);

    if (check == 'b') {
        printf("Hacked!!!\n");
    }

    return 0;
}
