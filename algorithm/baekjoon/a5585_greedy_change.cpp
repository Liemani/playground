#include <iostream>

using std::cin;
using std::cout;

const int pay = 1000;
int changeType[] = { 500, 100, 50, 10, 5, 1 };

int calculateChangeCount(int change) {
  int changeCount = 0;
  int changeTypeIndex = 0;
  while (change != 0) {
    changeCount += change / changeType[changeTypeIndex];
    change %= changeType[changeTypeIndex];
    ++changeTypeIndex;
  }

  return changeCount;
}

int main(void) {
  int cost;
  int change;
  int changeCount;

  cin >> cost;
  change = pay - cost;

  changeCount = calculateChangeCount(change);
  cout << changeCount;

  return 0;
}
