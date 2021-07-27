#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

// Write a C program which is given 1+ command-line arguments which are the pathnames of files or directories

// If the file or directory is publically-writeable, it should change it to be not publically-writeable, leaving other permissions unchanged.

// chmod +x - give everyone x or executable permission
// chmod 777
// chmod 664

// octal == 0 - 7
// octal == 3 bits == 2^3 numbers
// rwx
// 111
// 421

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
    // if a system call succeeds, they return 0.
    if (stat(pathname, &s) != 0) {
        perror(pathname);
        exit(1);
    }
    
    mode_t mode = s.st_mode;
    
    /*
    664 == 110110100
    002 == 000000010
      & == 000000000
    */
    
    if(!(mode & S_IWOTH)) {
        // Not publicly writeable.
        printf("%s is not publically writable\n", pathname);
        return;
    }
    
    mode = mode & ~S_IWOTH;
    
    /*
    666 == 110110110
    775 == 111111101
      & == 110110100
    */
      
    if (chmod(pathname, mode) != 0) {
        perror(pathname);
        exit(1);
    }
}
