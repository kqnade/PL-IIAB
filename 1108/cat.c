#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <string.h>

void verbose(FILE * fp) {
  if (fp == NULL) {
    perror("Invalid file pointer");
    return;
  }

  int fd = fileno(fp);
  if (fd == -1) {
    perror("Error getting file descriptor");
    return;
  }

  struct stat file_stat;
  if (fstat(fd, & file_stat) == -1) {
    perror("Error getting file info from fstat");
    return;
  }

  long file_size = file_stat.st_size;

  char time_buffer[100];
  struct tm * tm_info = localtime( & file_stat.st_mtime);
  strftime(time_buffer, sizeof(time_buffer), "%Y-%m-%d %H:%M:%S", tm_info);

  char permissions[10] = "---------";
  if (file_stat.st_mode & S_IRUSR) permissions[0] = 'r';
  if (file_stat.st_mode & S_IWUSR) permissions[1] = 'w';
  if (file_stat.st_mode & S_IXUSR) permissions[2] = 'x';
  if (file_stat.st_mode & S_IRGRP) permissions[3] = 'r';
  if (file_stat.st_mode & S_IWGRP) permissions[4] = 'w';
  if (file_stat.st_mode & S_IXGRP) permissions[5] = 'x';
  if (file_stat.st_mode & S_IROTH) permissions[6] = 'r';
  if (file_stat.st_mode & S_IWOTH) permissions[7] = 'w';
  if (file_stat.st_mode & S_IXOTH) permissions[8] = 'x';

  printf("==> File info <==\n");
  printf("Size: %ld bytes\n", file_size);
  printf("Last modified: %s\n", time_buffer);
  printf("Permissions: %s\n", permissions);
  printf("==> File Body <==\n");
}

void cat(FILE * fp) {
  char c;

  while (1) {
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
  int verbose_flag = 0;

  if (argc < 2) {
    fprintf(stderr, "Usage: %s [-v] <file1> <file2> ...\n", argv[0]);
    return 1;
  }

  if (argc > 2 && strcmp(argv[1], "-v") == 0) {
    verbose_flag = 1;
    argv++;
    argc--;
  }

  for (i = 1; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp == NULL) fatal("fopen()失敗", argv[i]);

    printf("===> %s <===\n", argv[i]);
    if (verbose_flag) {
      verbose(fp);
    }
    cat(fp);
    fclose(fp);
    printf("\n");
  }
  return (EXIT_SUCCESS);
}
