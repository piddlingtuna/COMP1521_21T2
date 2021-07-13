// For each of the following struct definitions, what are the likely offset values for each field, and the total size of the struct:

// Both the offsets and sizes should be in units of number of bytes.

struct _coord {
    double x;
    double y;
};
// sizeof (struct _coord) == 8 + 8 == 16
// offset of _coord.x == 0 bytes
// offset of _coord.y == 8 bytes


typedef struct _node Node;
struct _node {
    int value;
    Node *next; // sizeof (pointer is 8 bytes)
};

// sizeof (struct _node) == 12
// offset of _coord.value == 0 bytes
// offset of _coord.next == 4 bytes


struct _enrolment {
    int stu_id;         // e.g. 5012345
    char course[9]:     // e.g. "COMP1521"
    char term[5];       // e.g. "17s2"
    char grade[3];      // e.g. "HD"
    double mark;        // e.g. 87.3
};

// stu_id to be at an address divisible by 4 (sizeof(int))

// padding
// memory unaligned
.align 2

// sizeof (struct _enrolment) == 4 + 9 + 5 + 3 + 8 // wrong, actually 32 bytes
// offset of _enrolment.std_id == 0 bytes
// offset of _enrolment.course == 4 bytes
// offset of _enrolment.term == 13 bytes
// offset of _enrolment.grade == 18 bytes
// offset of _enrolment.mark == 24 bytes
// sizeof of _enrolment.mark == 8 bytes

struct _queue {
    int nitems;     // # items currently in queue
    int head;       // index of oldest item added
    int tail;       // index of most recent item added
    int maxitems;   // size of array
    Item *items;    // malloc'd array of Items
};
