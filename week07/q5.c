// sum 4 numbers using function calls

#include <stdio.h>

int sum4(int a, int b, int c, int d);
int sum2(int x, int y);

int main(void) {
    int z = sum4(11, 13, 17, 19);
    printf("%d\n", z);
    return 0;
}

int sum4(int a, int b, int c, int d) {
    int e = sum2(a, b);
    int f = sum2(c, d);
    return sum2(e, f);
}

int sum2(int x, int y) {
    return x + y;
}
