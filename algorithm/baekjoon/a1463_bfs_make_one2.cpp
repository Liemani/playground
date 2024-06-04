#include <cstdio>
#include <algorithm>

int baseCase[] = { 0, 0, 1, 1 };

int minimumInstruction(int number) {
  if (number <= 3) {
    return baseCase[number];
  }

  const int count1 = minimumInstruction(number / 3) + number % 3 + 1;
  const int count2 = minimumInstruction(number / 2) + number % 2 + 1;

  return std::min(count1, count2);
}

inline void solution(int number) {
  const int count = minimumInstruction(number);

  printf("%d", count);
}

int main() {
  int number;

  scanf("%d", &number);

  solution(number);

  return 0;
}
