#include <stdio.h>

int main(void) {
    int i;
    int numbers[10] = {0};

    i = 0;
    while (i < 10) {
        scanf("%d", &numbers[i]);
        i++;
    }
}
