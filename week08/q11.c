#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void handler (int sig) {
    printf("Captured: %d\n", sig);
    exit(0);
}

// pointer to a function

int main (int argc, char *argv[]) {
    struct sigaction act;
    memset(&act, 0, sizeof (act));
    act.sa_handler = &handler; // pointer to a function
    
    sigaction(SIGHUP, &act, NULL);
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGKILL, &act, NULL); // can't override SIGKILL 
    
    printf("pid: %d\n", getpid());
    while (1) {
        sleep (1);
    }
    return 0;
}

/*
What does this program do if it receives

    a. SIGHUP signal
    Gets handled by handler.

    b. SIGINT signal?
    Gets handled by handler.

    c. SIGTSTP signal?
    Stops program.

    d. SIGKILL signal?
    Kills program.

*/
