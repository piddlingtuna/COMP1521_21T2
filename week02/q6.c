#include <stdio.h>
#include <stdint.h>

typedef uint32_t Word; // 32 bits

Word reverse_bits(Word w);

int main(void) {

    Word example1 = 0x01234567;
    printf("Example 1\n");
    printf("w == 0x%x\n", example1);
    printf("reverse_bits(w) == 0x%x\n", reverse_bits(example1));

    Word example2 = 0xE6A2C480;
    printf("Example 2\n");
    printf("w == 0x%x\n", example2);
    printf("reverse_bits(w) == 0x%x\n", reverse_bits(example2));

    return 0;
}

/*
original = 0b 0000 0001 0010 0011 0100 0101 0110 0111
reverse  = 0b 1110 0110 1010 0010 1100 0100 1000 0000
*/

Word reverse_bits(Word w) {
    Word reversed_bits = 0;
    for (Word bit = 0; bit < 32; bit++) {
        // 1u means 1 as an unsigned integer literal
        Word check_mask = 1u << (31 - bit);
        if (w & check_mask) {
            Word reversed_mask = 1u << bit;
            reversed_bits = reversed_bits | reversed_mask;
        }
    }
    return reversed_bits;
}
