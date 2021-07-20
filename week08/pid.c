#include <stdio.h>
#include <unistd.h>

int main (void) {
    printf ("my PID is %d\n", getpid ());
    printf ("my parent's PID is %d\n", getppid ());
    // an orphan
    // init - pid 1
    return 0;
}
