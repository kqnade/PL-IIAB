#include <stdio.h>
#include <math.h>

void plot(int y){
  int i;
  for (i = 0; i < y; i++){
    printf(" ");
  }
  printf("*\n");
}

int main(void){
  double x;
  int y;
  for(x = 0; x < 3.142*2; x = x + 0.1){
    y = roundf(10*cos(x));
    plot(y+10);
  }
  return 0;
}
