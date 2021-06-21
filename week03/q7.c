/*
Draw diagrams to show the difference between the following two data structures:
*/

struct {
	int a; // 4 bytes
	double b; // 8 bytes
} x1;

/*
--------------------
| int a | double b |
--------------------
*/

union {
	int a; // 4 bytes
	double b; // 8 bytes
} x2;

/*
---------------------
| int a or double b |
---------------------
*/

/*
If x1 was located at &x1 == 0x1000 and x2 was located at &x2 == 0x2000, what would be the values of:

&x1 == 0x1000


&x1.a == 0x1000


&x1.b == 0x1004


&x2 == 0x2000


&x2.a == 0x2000


&x2.b == 0x2000

*/
