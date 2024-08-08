#include <cstdio>
#include <signal.h>
#include <unistd.h>
#include <map>

const char* signalNames[] = {
  "NSIG",
  "SIGHUP",
  "SIGINT",
  "SIGQUIT",
  "SIGILL",
  "SIGTRAP",
  "SIGABRT",
  "SIGEMT",
  "SIGFPE",
  "SIGKILL",
  "SIGBUS",
  "SIGSEGV",
  "SIGSYS",
  "SIGPIPE",
  "SIGALRM",
  "SIGTERM",
  "SIGURG",
  "SIGSTOP",
  "SIGTSTP",
  "SIGCONT",
  "SIGCHLD",
  "SIGTTIN",
  "SIGTTOU",
  "SIGIO",
  "SIGXCPU",
  "SIGXFSZ",
  "SIGVTALRM",
  "SIGPROF",
  "SIGWINCH",
  "SIGINFO",
  "SIGUSR1",
  "SIGUSR2",
};

void signalHandler (int signalIndex) {
  printf("[%d] %s\n", signalIndex, signalNames[signalIndex]);
}

int main() {
  for (int i = 0; i < 32; ++i) {
    signal(i, signalHandler);
  }

  sleep(100);

  return 0;
}
