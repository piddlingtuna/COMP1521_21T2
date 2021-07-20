#include <err.h>
#include <stdio.h>
#include <unistd.h>

// What are the possible outputs from:

int main (void) {
    int x = 1;
    pid_t pid = fork();
    if (pid < 0) {
        err(1, "fork failed");
    } else if (pid > 0) {
        x++;
        printf("x = %d\n", x);
    } else {
        x--;
        printf("x = %d\n", x);
    }
}

// fork fails
fork failed
// child, parent
x = 0
x = 2
// parent, child
x = 2
x = 0
