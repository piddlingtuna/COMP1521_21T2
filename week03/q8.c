/*
How large (#bytes) is each of the following C unions? 

You may assume:
sizeof(char) == 1
sizeof(short) == 2
sizeof(int) == 4
*/

union {
    int a;
    int b;
} u1; // max(4, 4) == 4 bytes

union {
    unsigned short a;
    char b;
} u2; // max(2,1) == 2 bytes

union {
    int a;
    char b[12];
} u3; // max(4, 12) == 12 bytes

union {
    double a; // 8 bytes
    char b[14]; // 14 bytes
} u4; // max(8, 14) == 16 bytes
// PADDING - size must be divisible by size of every type.

union {
    unsigned int a;
    int b;
    struct { int x; int y; } c;
} u5; // max(4, 4, 8) == 8 bytes
