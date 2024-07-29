#include <cstdio>
#include <queue>

int main() {
  std::queue<int> queue;

  for (int i = 0; i < 10; ++i) {
    queue.push(i);
  }

  queue.data();

  return 0;
}
