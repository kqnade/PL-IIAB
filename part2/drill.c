// 必要なライブラリを取得
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// メイン関数
 int main(void){
  // 変数の宣言
  // ランダムな数を保存する変数
  int x;
  int multibled;
  int y; 
   int answer;
  // ユーザーが入力した数を保存する変数
  int userInput;
  // 乱数の種を設定
  srand((unsigned)time(NULL));

  while (1)
  {
    // 1から100までの乱数を生成
    x = rand() % 100 + 1;
    // 1から9までの乱数を生成
    y = rand() % 9 + 1;
    // x * y を計算
    multibled = x * y;

    // 問題を表示
    printf("問題: %d/%d は?\n", multibled, y);
    // ユーザーが入力した数を受け取る
    scanf("%d", &userInput);
    // 正解かどうかを判定
    if (userInput == x)
    {
      printf("正解です\n");
    }
    else
    {
      printf("不正解です\n");
    }
  }
  return (0);
}
