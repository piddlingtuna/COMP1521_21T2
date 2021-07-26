#include <stdio.h>
#include <unistd.h>

// What are the possible outputs from the execution of this code?
// Assume fork succeeds
int main (void) {
    printf("Hello\n"); // Only 1 process running
    if (fork() != 0) // 2 different processes running, both printing to same terminal
        // Does the OS run the child or parent first? Order is unpredictable.
        printf("Gan bei\n");
        // OS can switch to the child here
    else
        printf("Prost\n");
        // OS can switch to the parent here
    printf ("Goodbye\n");
}

/*
Hello\n
// Child runs first
Prost\n
Goodbye\n
// Then parent runs
Gan bei\n
Goodbye\n

Hello\n
// Parent runs first
Gan bei\n
Goodbye\n
// Then child runs
Prost\n
Goodbye\n

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
*/
