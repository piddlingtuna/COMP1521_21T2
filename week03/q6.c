#include <stdio.h>
#include <stdint.h>

uint32_t six_last_bits(uint32_t bits);
uint32_t six_middle_bits(uint32_t bits);

int main(void) {

    uint32_t bits = 0x0f0f0f0f;

    uint32_t last = six_last_bits(bits);
    uint32_t middle = six_middle_bits(bits);

    printf("bits:   0x%x\n", bits);
    printf("last: %d\n", middle);
    printf("middle: %d\n", middle);

    return 0;
}

uint32_t six_last_bits(uint32_t bits) {
    return bits;
}

uint32_t six_middle_bits(uint32_t bits) {
    return bits;
}

/*
last_bits == 0b 0000 1111 0000 1111 0000 1111 0000 1111
                                                ^^^ ^^^


middle_bits == 0b 0000 1111 0000 1111 0000 1111 0000 1111
                                  ^^^ ^^^

*/
