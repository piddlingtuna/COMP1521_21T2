#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void handler (int sig) {
    printf("Quitting...\n");
    exit(0);
}

int main (int argc, char *argv[]) {
    struct sigaction act;
    memset(&act, 0, sizeof (act));
    act.sa_handler = &handler;
    sigaction(SIGHUP, &act, NULL);
    sigaction(SIGINT, &act, NULL);
    sigaction(SIGKILL, &act, NULL);
    while (1) {
        sleep (5);
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
