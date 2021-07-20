#include <stdio.h>
#include <unistd.h>

// What are the possible outputs from the execution of this code?
// Assume fork succeeds
int main (void) {
    printf("Hello\n");
    if (fork() != 0) - 2 different programs both printing to same terminal
        printf("Gan bei\n");
    else
        printf("Prost\n");
    printf ("Goodbye\n");
}

Hello\n
// child runs first
Prost\n
Goodbye\n
// then parent runs
Gan bei\n
Goodbye\n

Hello\n
Gan bei\n
Goodbye\n
Prost\n
Goodbye\n


int main (void) {
    printf("Hello\n"); - just one process
    PC - program counter - instruction you are actually executing 
    if (fork() != 0) - 2 different programs both printing to same terminal
        // does the OS run the child or parent first?
        printf("Gan bei\n");
        // OS can switch to the child
    else
        printf("Prost\n");
        // OS can switch to the parent
    printf ("Goodbye\n");
}

// fork - order is unpredictable

Hello\n
Gan bei\n
Prost\n
Goodbye\n
Goodbye\n

Hello\n
Prost\n
Gan bei\n
Goodbye\n
Goodbye\n
