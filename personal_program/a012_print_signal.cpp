#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

void printSignal(int signal)
{
  printf("signal index : %d\n", signal);
}

int main(int argc, char* argv[])
{
  struct sigaction sa;

  sa.sa_handler = printSignal;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  for (int i = 1; i < 32; ++i)
  {
    if (i == 9 || i == 17)
    {
      continue;
    }

    if (sigaction(i, &sa, NULL) == -1)
    {
      printf("[%2d] ", i);
      perror("error");
      return -1;
    }
  }

  while (1)
  {
    char ch;

    read(0, &ch, 1);

    if (ch == 'q')
    {
      break;
    }
  }

  return 0;
}
