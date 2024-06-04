#include <cstdio>
#include <queue>

inline bool simulateDepth(std::queue<int>& top, std::queue<int>& down, int depth) {
  while (!top.empty()) {
    int parent = top.front();
    top.pop();

    if (parent % 3 == 0) {
      if (parent == 3)
        return true;
      down.push(parent / 3);
      if (parent % 2 != 0)
        down.push(parent - 1);
    }
    else {
      down.push(parent - 1);
    }

    if (parent % 2 == 0) {
      if (parent == 2)
        return true;
      down.push(parent / 2);
    }
  }

  return false;
}


inline void solution(int number) {
  if (number == 1) {
    printf("0");
    return;
  }

  std::queue<int> queue1 = std::queue<int>();
  std::queue<int> queue2 = std::queue<int>();

  queue1.push(number);

  int depth = 0;
  while (true) {
    const bool isEnd1 = simulateDepth(queue1, queue2, depth);
    if (isEnd1)
      break;
    ++depth;

    const bool isEnd2 = simulateDepth(queue2, queue1, depth);
    if (isEnd2)
      break;
    ++depth;
  }

  printf("%d", depth + 1);
}

int main() {
  int number;

  scanf("%d", &number);

  solution(number);

  return 0;
}
