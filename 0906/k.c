#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUF_LEN 256

int sum(char *file){
  FILE *fp = NULL;
  int fileTotal = 0;
  int x;

  fp = fopen(file, "r");
  if (fp == NULL) {
    perror("cannot open the file!");
    return 1;
  }

  while (fscanf(fp, "%d", &x) != EOF) {
    fileTotal += x;
  } 
  printf("sum: %d\n", fileTotal);
  if (fp != NULL) fclose(fp);
  return fileTotal;
}

int save(int total, char *file){
  if (access(file, F_OK) == 0) {
    printf("saving...\n");
    FILE *fp = NULL;
    fp = fopen(file, "w");
    if (fp == NULL) {
      printf("We can't  open the save file!\nPlease check perm!");
      return 1;
    }
    fprintf(fp, "%d\n", total);
    fclose(fp);
    return 0;
  } else {
    printf("We couldn't find the sabe file...\n");
    return 1;
  }
}

int main(){
  int total = 0;
  char cmd[BUF_LEN];
  char fmt[16];
  sprintf(fmt, "%%%ds", BUF_LEN-1);
  char arg[BUF_LEN];

  while(1){
    /* runner test */
    printf("run |> ");
    if (scanf(fmt, cmd) == EOF) break;

    /* parse cmd */
    /* exit command */
    if (strcmp(cmd, "exit") == 0) break;
    else if (strcmp(cmd, "sum") == 0) {
      scanf(fmt, arg);
      total += sum(arg);
    }
    else if (strcmp(cmd, "show") == 0) {
      printf("sum: %d\n", total);
    }
    else if (strcmp(cmd, "save") == 0){
      scanf(fmt, arg);
      if (save(total, arg) != 0) {
        printf("We couldn't save total data!\n");
      } else {
        printf("save he total data to %s!\n", arg);
      }
    }

    else {
      printf("ERROR: invaild command \\> %s\n", cmd);
    }
    printf("\n");
  }
  printf("exit...\n\n");
  return 0;
}
