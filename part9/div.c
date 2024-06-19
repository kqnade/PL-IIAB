#include <stdio.h>

int divByMunus(int x, int y){
  int result;
  while(x >= y){
    x = x - y;
    result++;
  }
  return result;
}

int main(void){
  int userInputX, userInputY;
  int ans;
  printf("Enter 2 numbers x/y |>");
  if (scanf("%d %d", &userInputX, &userInputY) == EOF) return 1;

  ans = divByMunus(userInputX, userInputY);
  printf("%d / %d = %d\n", userInputX, userInputY, ans);

  return 0;
}
