#include <stdio.h>

#define CLASSRANGE 10
#define CLASSCOUNT 11

int main(void) {
  int input;
  int usrCount = 0;
  
  int i;

  int freqClass;
  int freqClasses[CLASSCOUNT] = {};

  printf("Enter scores (0~100 / C-d to exit)\n");

  while (1) {
    if (scanf("%d", &input) == EOF)
      break;
    /* invalid input */
    if (input > 100 || input < 0) {
      printf("Invalid input!  Skipping...\n");
    }

    /* class detect */
    freqClass = input / CLASSRANGE;
    freqClasses[freqClass]++;
  }
  printf("Class : Count\n");
  for (freqClass = 0; freqClass < CLASSCOUNT; freqClass++) {
    printf("%5d : %-5d\n", freqClass*CLASSRANGE, freqClasses[freqClass]);
  }

  return 0;
}
