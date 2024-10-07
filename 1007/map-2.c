#include <stdio.h>

#define N 3

int main(){
  char a[N];
  int b[N];
  double c[N];
  int i;

  for (i =0; i < N; i++){
    printf("%p : a[%d]\n", &a[i], i);
    printf("%p : b[%d]\n", &b[i], i);
    printf("%p : c[%d]\n", &c[i], i);
  }

  printf("%p : i\n", &i);

  return 0;
}
