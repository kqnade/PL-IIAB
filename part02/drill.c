#include <stdio.h>
#include <stdlib.h>	// rand() を使うために必要

int main(void)
{
	int	x, y, z;	// 問題の数値 z = x/y;
	int	a;		// ユーザが入力する答案の数値
	int correctAnswers = 0;  // 正答数
	int incorrectAnswers = 0;  // 誤答数

	printf("💩計算ドリル\n");	// タイトルを表示

	while (1) {
		x = rand()%100 + 1;	// 1〜100の乱数を設定
		y = rand()%10 + 1;	// 1〜10の乱数を設定
		z = x * y;  // 正解を計算
		printf("♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪♪\n");
		printf("%d 個の💩をもらいました．\n", z);
		printf("%d 人で山分けしましょう．\n", y);
		printf("一人分は何個ですか？ > ");

		if (scanf("%d", &a) == EOF) break;  // 答案を入力


		if (a == x) {
			printf("◯\n");
			correctAnswers++;  // 正答数を増やす
		} else {
			printf("☓ ：正解は %d です．\n", z);
			incorrectAnswers++;  // 誤答数を増やす
		}

		// 成績の表示
		printf("【成績】\n");
		printf("正答数：%d\n", correctAnswers);
		printf("誤答数：%d\n", incorrectAnswers);
		printf("正答率：%.2f%%\n", (float)correctAnswers / (correctAnswers + incorrectAnswers) * 100);

	}

	printf("\nおしまい．\n");
  printf("\n最終成績\n");
  printf(" %d 問中、%d問正解\n", correctAnswers + incorrectAnswers, correctAnswers);
	printf(" 正答率：%.2f%%\n", (float)correctAnswers / (correctAnswers + incorrectAnswers) * 100);
	return (0);
}
