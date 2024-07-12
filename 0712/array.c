#include <stdio.h>

#define ARRAY_SIZE 5

/* print all elements of array */
void print(int *p, int n){
  for (int i = 0; i < n; i++){
    printf("%d ", p[i]);
  }
  printf("\n");
}

void reset(int *p, int n, int v){
  for (int i = 0; i < n; i++){
    p[i] = v;
  }
}

int check(int *p, int n, int *np, int *nm){
  int zero_count = 0;
  *np = 0;
  *nm = 0;

  for (int i = 0; i < n; i++){
    if (p[i] > 0) (*np)++;
    else if (p[i] < 0) (*nm)++;
    else zero_count++;
  }
  return zero_count;
}

void input(int *p, int n){
  for (int i = 0; i < n; i++){
    scanf("%d", &p[i]);
  }
}

void copy(int *p, int *q, int n){
  for (int i = 0; i < n; i++){
    q[i] = p[i];
  }
}

int main(void)
{
	int     a[ARRAY_SIZE];
	int     b[ARRAY_SIZE];
	int	np, nm, nz;

	print(a, ARRAY_SIZE);		// ゴミが表示される

	nz = check(a, ARRAY_SIZE, &np, &nm);	// 符号をカウント
	printf("ゼロ｜正｜負：%d｜%d｜%d 個\n", nz, np, nm);

	reset(a, ARRAY_SIZE, 7);	// a の全要素を 7 にする
	print(a, ARRAY_SIZE);		// 7 7 7 ... が表示される

	nz = check(a, ARRAY_SIZE, &np, &nm);	// 符号をカウント
	printf("ゼロ｜正｜負：%d｜%d｜%d 個\n", nz, np, nm);

	input(a, ARRAY_SIZE);		// てきとーなデータを a にキーボード入力すると...
	print(a, ARRAY_SIZE);		// そいつらが表示される

	copy(a, b, ARRAY_SIZE);	// a の全要素を b にコピーする
	print(b, ARRAY_SIZE);		// b として，a と同じ内容が表示される

	return (0);
}
