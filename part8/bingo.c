#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FLAGCOUNT 15

int lineGen(int LineNum) {
  static int LineArr[5] = {};
  int randNum;
  int min = LineNum*15;
  int dupFlag[FLAGCOUNT] = {};
  int count = 5;

  while (count > 0){
    randNum = rand()%FLAGCOUNT;
    if (dupFlag[randNum] != 0){
      continue;
    } else {
      dupFlag[randNum] = 1;
      LineArr[5 - count] = randNum + min + 1;
      count--;
    }
  }
  return LineArr;

}

int main(void) {
}
