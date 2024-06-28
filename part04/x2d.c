#include <stdio.h>

int main(void){
  int usr_input = 0;
 
  while(1){
    printf("Enter Hex(16) number |>");
    if (scanf("%x", &usr_input) == EOF){
      printf("Invalid Input\n");
      break;
    }
    printf("Output Dex(10) number |>%d\n", usr_input);
  }

  printf("Exit\n");
  return (0);
}
