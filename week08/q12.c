/*
Write a C program, print_diary.c, which prints the contents of the file $HOME/.diary to stdout
The lecture example getstatus.c shows how to get the value of an environment variable.

snprintf is a convenient fucntion for constructing the pathname of the diary file.
*/

// Authored by COMP1521 course staff

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char *home_pathname = getenv("HOME");
    if (home_pathname == NULL) {
        home_pathname = ".";
    }

    char *basename = ".diary";
    int diary_pathname_len = strlen(home_pathname) + strlen(basename) + 2;
    char diary_pathname[diary_pathname_len];
    snprintf(diary_pathname, sizeof diary_pathname, "%s/%s", home_pathname, basename);

    FILE *stream = fopen(diary_pathname, "r");
    if (stream == NULL) {
        perror(diary_pathname);
        return 1;
    }

    int byte;
    while ((byte = fgetc(stream)) != EOF) {
        fputc(byte, stdout);
    }
    fclose(stream);

    return 0;
}
