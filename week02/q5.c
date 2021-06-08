//
// Sample solution for COMP1521 lab exercises
//
// Convert a 16-bit signed integer to a string of binary digits

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BITS 16

char *sixteen_out(int16_t value);

/*
Discuss the starting code for sixteen_out, one of this week's lab exercises.
In particular, what does this code (from the provided main) do?
*/

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        /*
        strtol converts a string to an integer (of type long).
        
        The third parameter value indicates what radix or numeric base to use; e.g., 10 for decimal.
        A value of 0 means values starting with 0x are interpreted as hexadeximal, values starting with 0 are interpreted as octal, and otherwise decimal.
        
        Unlike atoi, strtol allows for error checking.
        strtol's second argument, if it is not NULL, allows for error checking.
        It is set to point to the first character that couldn't be understood.
        */
        long l = strtol(argv[arg], NULL, 10);
        // This assert errors the program if `l` is not in the range of type int16_t.
        assert(l >= INT16_MIN && l <= INT16_MAX);
        int16_t value = l;

        char *bits = sixteen_out(value);
        printf("%s\n", bits);

        // Free the memory malloced in sixteen_out.
        free(bits);
    }

    return 0;
}

// given a signed 16 bit integer
// return a null-terminated string of 16 binary digits ('1' and '0')
// storage for string is allocated using malloc
char *sixteen_out(int16_t value) {

    // PUT YOUR CODE HERE
    return NULL;
}
