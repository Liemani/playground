#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

#define INPUT_FILE_NAME "input.txt"
#define messege

int main() {
  char ch;
  ssize_t readReturn;

  int input = open(INPUT_FILE_NAME, O_RDONLY);
  int dupInput = dup(input);

  readReturn = read(input, &ch, 1);
  printf("read return : %zd\n", readReturn);
  putchar(ch);
  printf("\n");

  readReturn = read(dupInput, &ch, 1);
  printf("read return : %zd\n", readReturn);
  putchar(ch);
  printf("\n");

  close(input);

  readReturn = read(dupInput, &ch, 1);
  printf("read return : %zd\n", readReturn);
  putchar(ch);
  printf("\n");

  close(dupInput);

  return 0;
}
