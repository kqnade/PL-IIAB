#include <stdio.h>

int main(void) {
  unsigned int value;

  printf("16進数 (under 8 digits) > ");
  scanf("%X", &value);

  unsigned char *p;

  p = (unsigned char *)&value;
  
  printf(" %02X %02X %02X %02X\n", p[3], p[2], p[1], p[0]);
    
  return 0;
}

