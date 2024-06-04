#include <iostream>

using std::cin;
using std::cout;

class List {
public :
private :
  int value;
  List* next;
};

void simulate(int* basketArray, int basketCount, int repetitionCount) {
  int lowerBasketNumber;
  int upperBasketNumber;
  int ballNumber;

  for (int index = 0; index < repetitionCount; ++index) {
    cin >> lowerBasketNumber;
    const int lowerBasketIndex = lowerBasketNumber - 1;

    cin >> upperBasketNumber;
    const int upperBasketIndex = upperBasketNumber - 1;

    cin >> ballNumber;

    int* first = basketArray + lowerBasketIndex;
    int* last = basketArray + (upperBasketIndex + 1);
    fill(first, last, ballNumber);
  }
}

void printOutput(int* array, int size) {
  int* element;

  element = array;

  cout << *element++;
  for (int index = 1; index < size; ++index) {
    cout << ' ';
    cout << *element++;
  }
}

int main(void) {
  int basketCount;
  int repetitionCount;

  cin >> basketCount;
  cin >> repetitionCount;

  int* basketArray = new int[basketCount];

  simulate(basketArray, basketCount, repetitionCount);

  printOutput(basketArray, basketCount);

  delete [] basketArray;

  return 0;
}
