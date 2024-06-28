#include <stdio.h>

int collatz(int x, int count) {
  /* Debugger */
  /* printf("%d\n", x); */
  if (x==1 && count != 0) return count;
  else if (x%2 == 0) return collatz(x/2, count+1);
  return collatz(3*x+1, count+1);
}

int main() {
  printf("%d\n", collatz(65536, 0));
}
