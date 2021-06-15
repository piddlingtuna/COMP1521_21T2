/*
On a machine with 16-bit ints, the C expression (30000 + 30000) yields a negative result.

Why the negative result? How can you make it produce the correct result?
*/

#include<stdio.h>
#include<stdint.h>

int main(void) {

    // int16_t range: -32768 to 32767

    int16_t fine = 30000;
    printf("%d\n", fine);

    int16_t also_fine = 30000;
    printf("%d\n", also_fine);

    int16_t not_fine = fine + also_fine;
    printf("%d\n", not_fine);

    printf("-----\n");

    // uint16_t range: 0 to 65535

    uint16_t ok = 30000;
    printf("%u\n", ok);

    uint16_t also_ok = 30000;
    printf("%u\n", also_ok);

    uint16_t ok_as_well = ok + also_ok;
    printf("%u\n", ok_as_well);

    // 30000u + 30000u;

    return 0;
}
