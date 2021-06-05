#include <stdio.h>

typedef unsigned int Word;

Word reverseBits(Word w);

int main(void) {

    Word example1 = 0x01234567;
    printf("Example 1\n");
    printf("w == 0x%x\n", example1);
    printf("reverseBits(w) == 0x%x\n", reverseBits(example1));

    Word example2 = 0xE6A2C480;
    printf("Example 2\n");
    printf("w == 0x%x\n", example2);
    printf("reverseBits(w) == 0x%x\n", reverseBits(example2));

    return 0;
}

Word reverseBits(Word w) {
    Word ret = 0;
    return ret;
}

/*
original = 0b1100
reverse  = 0b0011
*/
