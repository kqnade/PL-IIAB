#include <stdio.h>

int main(void){
  int usr_input = 0;
 
  while(1) {
    printf("Enter Dex(10) number |>");
    if (scanf("%d", &usr_input) == EOF) {
      printf("Invalid Input\n");
      break;
    }
    printf("Output Hex(16) number |>%x\n", usr_input);
  }
  printf("Exit.\n");
  return (0);
}
