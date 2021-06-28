#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0,1,2,3,4,5,6,7,8,9};

    i = 0;
    while (i < 5) {
        int x = numbers[i];
        int y = numbers[9 - i];
        numbers[i] = y;
        numbers[9 - i] = x;
        i++;
    }
}
