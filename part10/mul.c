#include <stdio.h>

int mul(int x, int y) {
  if (y == 0) return 0;
  return (mul(x, y-1)+x);
}

int main() {
  printf("%d\n", mul(10, 10));
  return 0;
}
