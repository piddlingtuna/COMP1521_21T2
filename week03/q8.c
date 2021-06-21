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
} u1;

union {
    unsigned short a;
    char b;
} u2;

union {
    int a;
    char b[12];
} u3; // max(4, 12) == 12 bytes

union {
    double a;
    char b[14];
} u4;
// PADDING - size must be divisible by size of every type.

union {
    unsigned int a;
    int b;
    struct { int x; int y; } c;
} u5;
