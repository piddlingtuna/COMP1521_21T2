# Give MIPS directives to represent the following variables:

# Assume that we are placing the variables in memory, at an appropriately aligned address, and with a label which is the same as the C variable name.

.data

# char v3 = 'a';
v3:
    .byte 'a'

# double v4;
v4:
    .space 8

# int v5[20];
v5:
    .space 80 # sizeof(int) * 20

# int v6[10][5];
v6:
    .space 200 # sizeof(int) * 10 * 5

# struct { int x; int y; } v7;
v7:
    .space 8

# struct { int x; int y; } v8[4];
v8:
    .space 32 # 8 * 4


# struct { int x; int y; } *v9[4];
# This is an array of pointers of structs.
# Assume pointers are 4 bytes.
v9:
    .space 16 # 4 * 4

# 32-bit computer (32 bits == 4 bytes) implies:
# - size of a register is 32 bits
# - size of memory is 2^32 bytes ~= 4 gigabytes

