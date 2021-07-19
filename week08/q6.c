#include <stdio.h>
#include <unistd.h>

// What are the possible outputs from the execution of this code?

int main (void) {
    printf("Hello\n");
    if (fork () != 0)
        printf("Gan bei\n");
    else
        printf("Prost\n");
    printf ("Goodbye\n");
}
