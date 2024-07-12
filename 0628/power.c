#include <stdio.h>

int power(int x, int y) {
  if (y == 0) return 1;
  return (power(x, y - 1)*x);
}

int main() {
  printf("%d\n", power(2, 4));
  return 0;
}
