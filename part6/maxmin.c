#include <stdio.h>

int main(void) {
  int max, min;
  int temp;

  printf("\nCtrl+D to exit from input mode.\n\n");

  printf("Enter point |>");
  if (scanf("%d", &temp) == EOF)
    return 1;
  min = temp;
  max = temp;

  while (1) {
    printf("Enter point |>");
    if (scanf("%d", &temp) == EOF)
      break;
    if (temp > max) {
      max = temp;
    } else if (temp < min) {
      min = temp;
    }
  }

  printf("\nMax: %d\nMin: %d\n", max, min);
  return 0;
}
