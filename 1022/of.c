#include <stdio.h>
#include <limits.h>

int main(void){
  int maxInt = INT_MAX;
  printf("Int limit: %d\n", maxInt);
  maxInt += 1;
  printf("Int over limit: %d\n", maxInt);

  char x = 0;
  for(int i = 0; i < 32; i++){
    x += 16;
    printf("%d\n", x);
  }

  return 0;
}
