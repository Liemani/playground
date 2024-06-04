#include <stdio.h>
#include <cstring>

inline void solution(int number) {
  int* array = new int[number + 1];

  std::memset(array, 0, sizeof(int) * number);

  for (int i = 2; i < number + 1; ++i) {
    int minimum = array[i - 1];
    if (i % 3 == 0 && array[i / 3] < minimum)
      minimum = array[i / 3];
    if (i % 2 == 0 && array[i / 2] < minimum)
      minimum = array[i / 2];
    array[i] = minimum + 1;
  }

  printf("%d", array[number]);

  while (number > 1) {
    int minimum = array[number - 1];
    int minimumNumber = number - 1;

    printf("\n[");
    if (number % 3 == 0) {
      printf("%d : %d, ", number / 3, array[number / 3]);
      if (array[number / 3] < minimum) {
        minimumNumber = number / 3;
        minimum = array[number / 3];
      }
    }
    if (number % 2 == 0) {
      printf("%d : %d, ", number / 2, array[number / 2]);
      if (array[number / 2] < minimum) {
        minimumNumber = number / 2;
        minimum = array[number / 2];
      }
    }
    printf("%d : %d]", number - 1, array[number - 1]);
    number = minimumNumber;
  }
}

int main() {
  int number;

  scanf("%d", &number);

  solution(number);

  return 0;
}
