#include <stdio.h>

int main(void)
{
	int	x, y;
	int	r = 10;
	int	n = 3;

	for (y = 0; y < r; y++) {
		if ((y % 2) == 0) continue;
		for (x = 0; x < r; x++) {
			if (x > y) break;
			printf("#");
		}
		printf("\n");
	}

	return (0);
}
