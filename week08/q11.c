#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void handler (int sig) {
    printf("Quitting...\n");
    printf("%d\n", sig);
    exit(0);
}

// pointer to a function

int main (int argc, char *argv[]) {
    struct sigaction act;
    memset(&act, 0, sizeof (act));
    printf("pid: %d\n", getpid());
    act.sa_handler = &handler;
    sigaction(SIGHUP, &act, NULL);
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGKILL, &act, NULL); // can't override overkill 
    while (1) {
        sleep (15);
    }
    return 0;
}

/*
What does this program do if it receives

    a. SIGHUP signal

    b. SIGINT signal?

    c. SIGTSTP signal?

    d. SIGKILL signal?

*/
