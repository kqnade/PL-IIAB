#include <stdio.h>

int main(void){
  unsigned char data[4] = {0xCD, 0xAB, 0x34, 0x12};
  unsigned int  *p;

  p = (unsigned int *)&data;

  printf("%08X\n", *p);

  return 0;
}
