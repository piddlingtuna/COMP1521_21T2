#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <ctype.h>

// If a file xyz contains 2500 bytes, and it is scanned using the following code:

// How many calls with be made to the read() function, and what is the value of nb after each call?

#define BUFFER_SIZE 1000
int main(void) {
    int fd;         // open file descriptor
    int nb;         // # bytes read
    int ns = 0;     // # spaces
    char buf[BUFFER_SIZE]; // input buffer
    
    fd = open ("xyz", O_RDONLY);
    assert (fd >= 0);
    while ((nb = read (fd, buf, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < nb; i++) {
            if (isspace (buf[i])) {
                ns++;
            }
        }
    }
    close (fd);
    
    return 0;
}
