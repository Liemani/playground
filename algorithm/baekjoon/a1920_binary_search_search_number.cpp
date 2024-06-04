#include <stdio.h>
#include <algorithm>
#include <cassert>

inline int* readArray(int count) {
  int* array = new int[count];

  int* const endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    scanf("%d", element);
  }

  return array;
}

inline void printNotContains() {
  printf("0\n");
}

inline void printContains() {
  printf("1\n");
}

inline void baseCase(int* array, int count, int target) {
  switch (count) {
    case 0 :
      break;

    case 1 :
      if (target == *array) {
        printContains();
        return;
      }
      break;

    case 2 :
      if (target == *array || target == *++array) {
        printContains();
        return;
      }
      break;

    default :
      assert(count <= 2);
  }

  printNotContains();
}

inline void binarySearch(int* array, int count, int target) {
  while (true) {
    if (count <= 2) {
      baseCase(array, count, target);
      return;
    }

    const int middleIndex = count / 2;
    const int middleNumber = array[middleIndex];
    if (target == middleNumber) {
      printContains();
      return;
    }

    if (target < middleNumber) {
      count = middleIndex;
    }
    else {
      const int leftAndMiddleCount = middleIndex + 1;
      array += leftAndMiddleCount;
      count -= leftAndMiddleCount;
    }
  }
}

inline void solution(int* array, int count) {
  int searchCount;

  scanf("%d", &searchCount);

  for (int i = 0; i < searchCount; ++i) {
    int target;
    scanf("%d", &target);
    binarySearch(array, count, target);
  }
}

// main()
int main() {
  int numberCount;

  scanf("%d", &numberCount);
  int* array = readArray(numberCount);
  std::sort(array, array + numberCount);

  solution(array, numberCount);

  delete [] array;

  return 0;
}
