#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DUPLICATE_FLAG 15

int main(){
  srand((unsigned long)time(NULL));
  int dupFlag[DUPLICATE_FLAG] = {};
  int count = 5;
  int temp;

  while(count > 0){
    temp = rand()%15;
    if (dupFlag[temp] == 1) continue;
    dupFlag[temp] = 1;
    count--;
  }

  printf("B\n");
  for(count=0; count<=16; count++){
    if (dupFlag[count] == 1) {
      printf("%d\n", count + 1);
    }
  }

  return 0;
}
