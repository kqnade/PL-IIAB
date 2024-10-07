#include <stdio.h>

void func(void)
{
	int	a[65536];	// ローカルな配列
		// メモリ使用量：65536*4 byte
		// = 256*256*4 B = 256*1024 B = 256 KB

	printf("%p\n", a);	// 先頭アドレス
	func();	// 終了条件なしで再帰（無限再帰）
		// ...本来なら終了条件が必要
}

int main(void)
{
	func();
	return (0);
}
