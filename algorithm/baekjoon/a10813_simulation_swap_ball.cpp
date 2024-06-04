#include <iostream>

using std::cin;
using std::cout;

template <typename T>
inline void swap(T* left, T* right) {
  T temp = *left;
  *left = *right;
  *right = temp;
}

void simulate(int* basketArray, int basketCount, int repetitionCount) {
  int smallBasketNumber;
  int bigBasketNumber;

  for (int index = 0; index < repetitionCount; ++index) {
    cin >> smallBasketNumber;
    const int smallBasketIndex = smallBasketNumber - 1;

    cin >> bigBasketNumber;
    const int bigBasketIndex = bigBasketNumber - 1;

    int* const smallBasket = basketArray + smallBasketIndex;
    int* const bigBasket = basketArray + bigBasketIndex;
    swap(smallBasket, bigBasket);
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
  int* element = basketArray;
  for (int index = 0; index < basketCount; ++index) {
    *element = (index + 1);
    ++element;
  }

  simulate(basketArray, basketCount, repetitionCount);

  printOutput(basketArray, basketCount);

  delete [] basketArray;

  return 0;
}
