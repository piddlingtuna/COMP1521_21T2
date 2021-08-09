// read 32-byte hexadecimal numbers from a file
// and print low (least significant) byte
// as a signed decimal number (-128..127)

#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }
    
    FILE *stream = fopen(argv[1], "r");
    if (stream == NULL) {
        perror(argv[1]);
        return 1;
    }

    int32_t number;
    while (fscanf(stream, "%x", &number) == 1) {

        // convert low byte to a signed number
        // simple assignment to a int8_t variable works on most platforms
        // but is not defined by the C standard

        int32_t low_byte = number & 0xff;
        if (low_byte & 1 << 7) {
            low_byte = -(1 << 8) + low_byte;
        }

        printf("%d\n", low_byte);
    }
    fclose(stream);

    return 0;
}
