/**
 * This program demonstrates the use of a static variable 'count'.
 * The 'count' variable behaves like a global variable except it is only visible from inside the scope of the 'magic' function.
 * The value of 'count' persists across function calls.
 */
#include<stdio.h>

int magic() {
    static int count = 0;
    count++;
    return count;
}

int main() {
    printf("%d\n", magic());
    printf("%d\n", magic());
    printf("%d\n", magic());
    return 0;
}
