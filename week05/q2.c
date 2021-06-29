#include <stdio.h>

int main(void) {
	int i = 0;

	// while loop running at least once
	do {
		i++;

		printf("%d", i);
		printf("\n");
	} while (i < 10);

	return 0;
}
