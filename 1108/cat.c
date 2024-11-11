#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cat(FILE * fp, int line_num) {
  char c;
  int line_count = 1;

  if (line_num == 1) printf("%4d\t", line_count++);
  while (1) {
    if (line_num == 1 && c == '\n') printf("%4d\t", line_count++);
    if (fscanf(fp, "%c", & c) == EOF) return;
    printf("%c", c);
  }
}

void fatal(char * msg, char * op) {
  fprintf(stderr, "%s：%s\n", msg, op);
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
  FILE * fp;
  int i;
  int number_flag = 0;

  for (i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-n") == 0){
      number_flag = 1;
      break;
    }
  }

  if (argc == 1){
    fp = stdin;

    if (fp == NULL) fatal("fopen()失敗", argv[i]);

    printf("===> stdin <===\n");
    cat(fp, number_flag);
    printf("\n");

    return (EXIT_SUCCESS);
  }

  for (i = 1; i < argc; i++) {

    if (strcmp(argv[i], "-n") == 0) {
      continue;
    }
    if (strcmp(argv[i], "-") == 0) {
      fp = stdin;
      printf("===> stdin <===\n");

    } else {
      fp = fopen(argv[i], "r");
      if (fp == NULL) fatal("fopen()失敗", argv[i]);
      printf("===> %s <===\n", argv[i]);
    }

    cat(fp, number_flag);
    fclose(fp);
    printf("\n");
  }
  return (EXIT_SUCCESS);
}
