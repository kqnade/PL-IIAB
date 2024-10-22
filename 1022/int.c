#include <stdio.h>

int main(void){
  int data = 0x1234ABCD;
  unsigned char	*p;

  p = (unsigned char *)&data;

  // 4 byte のまま表示
  printf("%X\n", data);

  // 1 byte ずつ表示
  printf(" %02X", p[0]);	// 先頭のバイト
  printf(" %02X", p[1]);
  printf(" %02X", p[2]);
  printf(" %02X", p[3]);	// 末尾のバイト
  printf("\n");

  return (0);
}
