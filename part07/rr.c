/* Russian Roulette */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int	r;
	int	x;
  srand((unsigned long)time(NULL));

	printf("ロシアンルーレットを始めるよー\n");
	r = rand()%6;

	while (1) {
    /* printf("%d\n", r); */
		printf("弾倉を回す？\n");
		printf("1以上：回して撃つ，0：そのまま撃つ，-1以下：パス > ");
		scanf("%d", &x);

		if (x < 0) continue;
		if (x > 0) r = rand()%6;
		printf("カチッ...\n");
		if (r == 0) break;

		printf("セーフ\n");
		r--;
	}
	printf("バーン...\n");
	printf("終了\n");

	return (0);
}
