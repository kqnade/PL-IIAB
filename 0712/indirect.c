#include <stdio.h>

int main(void)
{
	int	x = 1;
	int	y = 2;
	int	*p;		// 変数p はポインタだよ

	// データの確認
	printf("&x = %p, x = %d\n", &x, x);	// x のアドレスと値を確認
	printf("&y = %p, y = %d\n", &y, y);	// y のアドレスと値を確認
	printf("\n");

	// x の間接参照
	p = &x;		// ポインタp に変数x を参照させたよ
	printf("p = %p, *p = %d\n", p, *p);	// 参照先の x のアドレスと値になるよ
	*p = 128;				// 間接参照で x に128が代入されるよ
	printf("p = %p, *p = %d\n", p, *p);	// 参照先の x のアドレスと値になるよ

	// データの確認
	printf("&x = %p, x = %d\n", &x, x);	// x のアドレスと値を確認
	printf("&y = %p, y = %d\n", &y, y);	// y のアドレスと値を確認
	printf("\n");

	// y の間接参照
	p = &y;		// ポインタp に変数y を参照させたよ
	printf("p = %p, *p = %d\n", p, *p);	// 参照先の y のアドレスと値になるよ
	*p = 256;				// 間接参照で y に256が代入されるよ．
	printf("p = %p, *p = %d\n", p, *p);	// 参照先の y のアドレスと値になるよ

	// データの確認
	printf("&x = %p, x = %d\n", &x, x);	// x のアドレスと値を確認
	printf("&y = %p, y = %d\n", &y, y);	// y のアドレスと値を確認
	printf("\n");

	return (0);
}

