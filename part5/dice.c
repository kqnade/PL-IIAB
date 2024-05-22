#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
  {
	int	x, y;
	int	z;
  srand((unsigned long)time(NULL));

	while (1) {
		x = (rand() % 6) + 1;
		y = (rand() % 6) + 1;
		printf("%d，%d の ", x, y);

    if ((x+y)%2 == 0){
      printf("丁");
    } else {
      printf("半");
    }

		getchar();
	}
	return (0);
}
}
