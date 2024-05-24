#include <stdio.h>

int main(void) {
  int input, result;

  result = 0;

  printf("Enter Number (over 1) |>");
  if (scanf("%d", &input) == EOF || input <= 0) {
    printf("Invaild input!\n");
    return 1;
  }

  while (input >= 0) {
    result = result + input;
    input = input - 1;
  }

  printf("%d\n", result);
  return 0;
}
