#include <stdio.h>

union _all {
   int ival;
   char cval;
   char sval[4];
   float fval;
   unsigned int uval;
};

int main(void) {

    /*
    If we define a variable union _all var; and assign the following value var.uval = 0x00313233; then what will each of the following printf(3)s produce:

    You can assume that bytes are arranged from right-to-left in increasing address order.

    */

    union _all var;
    var.uval = 0x00313233;

    /*
    Big Endian
    0000 0000 0011 0001 0011 0010 0011 0011

    vs

    Little Endian
    0011 0011 0011 0010 0011 0001 0000 0000
    */

    printf("%x\n", var.uval);
    printf("%d\n", var.ival);
    printf("%c\n", var.cval);
    printf("%s\n", var.sval);
    printf("%f\n", var.fval);
    printf("%e\n", var.fval);

    return 0;

}