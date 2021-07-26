#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Write a C program which is given 1+ command-line arguments which are the pathnames of files or directories

// If the file or directory is publically-writeable, it should change it to be not publically-writeable, leaving other permissions unchanged.

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}

// chmod a file if publically-writeable
void chmod_if_needed(char *pathname) {
    struct stat s;
    if (stat(pathname, &s) != 0) {
        perror(pathname);
        exit(1);
    }
    
    // TODO
}
