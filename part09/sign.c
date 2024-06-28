#include <stdio.h>

int sign(int x){
  if (x == 0) return 0;
  else if (x > 0) return 1;
  else return -1;
}

int main(void){
  int userInput;
  int result;
  
  while(1){
    printf("Enter number |>");
    if (scanf("%d", &userInput) == EOF) break;
    result = sign(userInput);
    printf("%d\n", result);
  }
  printf("Invaild Input!\n");

  return 0;
}
