// when fclose, fd also closed
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd = open("output.txt", O_WRONLY/* | O_CREAT*/);
  char* message = "fd write test\n";
  write(fd, message, strlen(message));

  FILE* stream = fdopen(fd, "w");
  fprintf(stderr, "stream : %p\n", stream);
  fprintf(stream, "stream fdopen test\n");

  fclose(stream);
  write(fd, message, strlen(message));

  return 0;
}
