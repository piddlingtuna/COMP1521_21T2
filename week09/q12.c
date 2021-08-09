#include <stdio.h>
#include <stdlib.h>

// Write a C program which is given one command-line argument, the name of a file, and which reads a line from stdin and appends it to the specified file.

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    FILE *stream = fopen(argv[1], "a");
    // stream is like a file you can write/read to.
    // - stdin - reads from your terminal
    // - stdout - prints to your terminal
    // - stderr - prints to your terminal
    
    if (stream == NULL) {
        perror(argv[1]);
        return 1; // same as exit(1) because you're in main
    }
    
    int c; // EOF - on *most* systems is -1
    int cont = 1;
    while (cont && (c = fgetc(stdin)) != EOF) {
        // when you assign a variable, you return it.
        fputc(c, stream);
        if (c == '\n') {
            cont = 0;
        }
    }
    
    fclose(stream); // good practice
    return 0;
}
