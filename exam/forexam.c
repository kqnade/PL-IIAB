#include <stdio.h>
#include <string.h>

#define BUF_LEN 256

int main(void){
  //cmd buffer
  char buf[BUF_LEN];
  char fmt[16];
  sprintf(fmt, "%%%ds", BUF_LEN - 1);

  while(1){
    printf("Run|> ");
    //exit code
    if (scanf(fmt, buf) == EOF) break;
    else if (strcmp(buf, "exit") == 0) break;

    else {
      printf("Invaild cmd! /> %s\n", buf);
    }
    printf("\n");
    //help command
  }
  printf("exit...\n");
  return 0;
}
