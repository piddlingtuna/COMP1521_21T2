// For each of the following struct definitions, what are the likely offset values for each field, and the total size of the struct.

// Both the offsets and sizes should be in units of number of bytes.

struct _coord {
    double x;
    double y;
};
// sizeof (struct _coord) == 8 + 8 == 16 bytes
// offset of _coord.x == 0 bytes
// offset of _coord.y == 8 bytes


struct _node {
    int value;
    struct _node *next; // sizeof (pointer is 8 bytes)
};

// sizeof (struct _node) == 4 + 8 == 12 bytes
// offset of _coord.value == 0 bytes
// offset of _coord.next == 4 bytes


struct _enrolment {
    int stu_id;         // e.g. 5012345
    char course[9];     // e.g. "COMP1521"
    char term[5];       // e.g. "17s2"
    char grade[3];      // e.g. "HD"
    double mark;        // e.g. 87.3
};

// Memory must be stored at an address divisible by its size.
// int must be at an address divisible by 4 since its size is 4.
// double must be at an address divisible by 8 since its size is 8.

// Padding is added to ensure memory is aligned (to the next address that is divisible).
// Padding wastes bytes.

// sizeof (struct _enrolment) == 4 + 9 + 5 + 3 + 8 != 32 bytes
// offset of _enrolment.std_id == 0 bytes
// offset of _enrolment.course == 4 bytes
// offset of _enrolment.term == 13 bytes
// offset of _enrolment.grade == 18 bytes
// offset of _enrolment.mark == 24 bytes
// sizeof of _enrolment.mark == 8 bytes
