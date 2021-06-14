/*
Draw diagrams to show the difference between the following two data structures:
*/

struct {
	int a; // 4 bytes
	double b; // 8 bytes
} x1;

union {
	int a; // 4 bytes
	double b; // 8 bytes
} x2;


/*
If x1 was located at &x1 == 0x1000 and x2 was located at &x2 == 0x2000, what would be the values of:

&x1 == TODO


&x1.a == TODO


&x1.b == TODO


&x2 == TODO


&x2.a == TODO


&x2.b == TODO

*/
