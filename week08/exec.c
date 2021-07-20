#include <stdio.h>
#include <unistd.h>

int main (void) {
    if (fork () != 0) {
        // We are parent
        printf ("Parent PID is %d\n", getpid ());
        sleep(1);
    } else {
        printf ("Child PID is %d\n", getpid ());
        char *args[2], *envs[1];
        args[0] = "./pid";
        args[1] = NULL;
        envs[0] = NULL;
        execve (args[0], args, envs);
        // only reach here if exec fails
        perror ("Exec failed");
    }
    return 0;
}
