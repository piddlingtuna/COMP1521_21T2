#include <stdio.h>
#include <stdlib.h>

// Write a C programwhich is given one command-line argument, the name of a file, and which reads a line from stdin and appends it to the specified file.

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // TODO

    return 0;
}
