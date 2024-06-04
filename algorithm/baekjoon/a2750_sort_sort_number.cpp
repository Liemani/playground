#define QUICK

#ifdef MIXED003
#include <stdio.h>
#include <queue>
#include <utility>

inline void readNumbers(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    scanf("%d", element);
  }
}

inline void insertionSort(int* array, int count) {
  int* lastElement = (array + count) - 1;

  for (int* lhs = array; lhs != lastElement; ++lhs) {
    int* const rhs = lhs + 1;

    if (*lhs < *rhs) {
      continue;
    }

    int* checker = lhs;
    const int target = *rhs;

    if (target < *array) {
      checker = array - 1;
    }
    else {
      while (*checker > target) {
        --checker;
      }
    }

    for (int* mover = lhs; mover != checker; --mover) {
      *(mover + 1) = *mover;
    }

    *(checker + 1) = target;
  }
}

inline void printArray(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    printf("%d\n", *element);
  }
}

std::queue<std::pair<int*, int> > queue;

inline void swap(int* lhs, int* rhs) {
  int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

// sort 1 ~ 4 element
inline void sortBaseCase(int* array, int count) {
  int* lhs;
  int* rhs;

  switch (count) {
    case 0 :
    case 1 :
      break;
    case 2 :
      lhs = array;
      rhs = array + 1;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }
      break;
    case 3 :
      lhs = array;
      rhs = array + 1;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++rhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++lhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }
      break;
    case 4 :
      lhs = array;
      rhs = array + 1;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++rhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++rhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++lhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      --rhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      lhs += 2;
      if (!(*rhs < *lhs)) {
        swap(lhs, rhs);
      }
      break;
    default :
      printf("[error : sortBaseCase() invalid argument : %d]\n", count);
      break;
  }

  return;
}

/// - Returns : pivot element pointer
inline int* sortCore(int* array, int count) {
  int* const pivotPointer = array + count / 2;
  swap(array, pivotPointer);
  const int pivot = *array;

  int* left = array + 1;
  int* right = array + count - 1;

  while (true) {
    while (*left < pivot) {
      ++left;
    }
    while (*right > pivot) {
      --right;
    }

    if (left > right) {
      break;
    }

    swap(left, right);
  }

  swap(array, right);

  return right;
}

inline void quickSort(int* array, int count) {
  std::pair<int*, int> pair = std::pair<int*, int>(array, count);
  queue.push(pair);

  while (!queue.empty()) {
    const std::pair<int*, int> pair = queue.front();
    queue.pop();

    int* const array = pair.first;
    const int count = pair.second;

    int* const middle = sortCore(array, count);

    int* const leftRange = array;
    const int leftRangeCount = middle - leftRange;
    if (leftRangeCount > 4) {
      std::pair<int*, int> pair = std::pair<int*, int>(leftRange, leftRangeCount);
      queue.push(pair);
    }
    else {
      sortBaseCase(leftRange, leftRangeCount);
    }

    int* const rightRange = middle + 1;
    const int rightRangeCount = count - leftRangeCount - 1;
    if (rightRangeCount > 4) {
      std::pair<int*, int> pair = std::pair<int*, int>(rightRange, rightRangeCount);
      queue.push(pair);
    }
    else {
      sortBaseCase(rightRange, rightRangeCount);
    }
  }
}

inline int calculateMissOrderCount(int* array, int count) {
  int* const last = array + count - 1;
  int missOrderCount = 0;

  for (int* lhs = array; lhs != last; ++lhs) {
    int* const rhs = lhs + 1;

    if (*lhs > *rhs) {
      ++missOrderCount;
    }
  }

  return missOrderCount;
}

inline void sort(int* array, int count) {
  int missOrderCount = calculateMissOrderCount(array, count);

  if (missOrderCount == 0) {
    return;
  }
  else if (missOrderCount > (count * 3 / 4)) {
    for (int i = 0; i < count / 2; ++i) {
      swap(array + i, array + (count - 1 - i));
    }
  }

  missOrderCount = calculateMissOrderCount(array, count);

  if (missOrderCount == 0) {
    return;
  }

  if (missOrderCount < 10) {
    insertionSort(array, count);
  }
  else {
    quickSort(array, count);
  }
}

int main() {
  int* array;
  int numberCount;

  scanf("%d", &numberCount);

  array = new int[numberCount];
  readNumbers(array, numberCount);

  sort(array, numberCount);

  printArray(array, numberCount);

  delete [] array;

  return 0;
}
#endif

#ifdef INSERTION
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void readNumbers(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    cin >> *element;
  }
}

void sort(int* array, int count) {
  int* lastElement = (array + count) - 1;

  for (int* lhs = array; lhs != lastElement; ++lhs) {
    int* const rhs = lhs + 1;

    if (*lhs < *rhs) {
      continue;
    }

    int* checker = lhs;
    const int target = *rhs;

    if (target < *array) {
      checker = array - 1;
    }
    else {
      while (*checker > target) {
        --checker;
      }
    }

    for (int* mover = lhs; mover != checker; --mover) {
      *(mover + 1) = *mover;
    }

    *(checker + 1) = target;
  }
}

void printArray(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    cout << *element << endl;
  }
}

int main() {
  int numberCount;
  int* array;

  cin >> numberCount;

  array = new int[numberCount];
  readNumbers(array, numberCount);

  sort(array, numberCount);
  printArray(array, numberCount);

  delete [] array;

  return 0;
}
#endif

#ifdef QUICK
#include <stdio.h>
#include <queue>
#include <utility>
#include <cassert>

std::queue<std::pair<int*, int> > queue;

inline void readNumbers(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    scanf("%d", element);
  }
}

inline void swap(int* lhs, int* rhs) {
  int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

// sort 1 ~ 4 element
inline void sortBaseCase(int* array, int count) {
  int* lhs;
  int* rhs;

  switch (count) {
    case 0 :
    case 1 :
      break;
    case 2 :
      lhs = array;
      rhs = array + 1;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }
      break;
    case 3 :
      lhs = array;
      rhs = array + 1;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++rhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++lhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }
      break;
    case 4 :
      lhs = array;
      rhs = array + 1;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++rhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++rhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      ++lhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      --rhs;
      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
      }

      lhs += 2;
      if (!(*rhs < *lhs)) {
        swap(lhs, rhs);
      }
      break;
    default :
      assert(count <= 4);
      break;
  }

  return;
}

/// - Returns : pivot element pointer
inline int* sortCore(int* array, int count) {
  int* const pivotPointer = array + count / 2;
  swap(array, pivotPointer);
  const int pivot = *array;

  int* left = array + 1;
  int* right = array + count - 1;

  while (true) {
    while (*left < pivot) {
      ++left;
    }
    while (*right > pivot) {
      --right;
    }

    if (left > right) {
      break;
    }

    swap(left, right);
  }

  swap(array, right);

  return right;
}

inline void sort(int* array, int count) {
  std::pair<int*, int> pair = std::pair<int*, int>(array, count);
  queue.push(pair);

  while (!queue.empty()) {
    const std::pair<int*, int> pair = queue.front();
    queue.pop();

    int* const array = pair.first;
    const int count = pair.second;

    int* const middle = sortCore(array, count);

    int* const leftRange = array;
    const int leftRangeCount = middle - leftRange;
    if (leftRangeCount > 4) {
      std::pair<int*, int> pair = std::pair<int*, int>(leftRange, leftRangeCount);
      queue.push(pair);
    }
    else {
      sortBaseCase(leftRange, leftRangeCount);
    }

    int* const rightRange = middle + 1;
    const int rightRangeCount = count - leftRangeCount - 1;
    if (rightRangeCount > 4) {
      std::pair<int*, int> pair = std::pair<int*, int>(rightRange, rightRangeCount);
      queue.push(pair);
    }
    else {
      sortBaseCase(rightRange, rightRangeCount);
    }
  }
}

inline void printArray(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    printf("%d\n", *element);
  }
}

int main() {
  int* array;
  int numberCount;

  scanf("%d", &numberCount);

  array = new int[numberCount];
  readNumbers(array, numberCount);

  sort(array, numberCount);

  printArray(array, numberCount);

  delete [] array;

  return 0;
}
#endif

#ifdef BUBBLE
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void readNumbers(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    cin >> *element;
  }
}

void swap(int* lhs, int* rhs) {
  int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

void sort(int* array, int count) {
  int* lastElement = (array + count) - 1;
  bool isSorted = false;

  while (!isSorted) {
    int* lhs = array;
    isSorted = true;

    while (lhs != lastElement) {
      int* const rhs = lhs + 1;

      if (!(*lhs < *rhs)) {
        swap(lhs, rhs);
        isSorted = false;
      }

      ++lhs;
    }

    --lastElement;
  }
}

void printArray(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    cout << *element << endl;
  }
}

int main() {
  int numberCount;
  int* array;

  cin >> numberCount;

  array = new int[numberCount];
  readNumbers(array, numberCount);

  sort(array, numberCount);
  printArray(array, numberCount);

  delete [] array;

  return 0;
}
#endif

#ifdef SELECTION2
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void readNumbers(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    cin >> *element;
  }
}

void swap(int* lhs, int* rhs) {
  int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

void sort(int* array, int count) {
  int* lastElement = (array + count) - 1;
  int* endElement = array + count;
  int* smallest;

  for (int* lhs = array; lhs != lastElement; ++lhs) {
    smallest = lhs;

    for (int* rhs = lhs + 1; rhs != endElement; ++rhs) {
      if (*smallest > *rhs) {
        smallest = rhs;
      }
    }

    if (lhs != smallest) {
      swap(lhs, smallest);
    }
  }
}

void printArray(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    cout << *element << endl;
  }
}

int main() {
  int numberCount;
  int* array;

  cin >> numberCount;

  array = new int[numberCount];
  readNumbers(array, numberCount);

  sort(array, numberCount);
  printArray(array, numberCount);

  delete [] array;

  return 0;
}
#endif

#ifdef SELECTION
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void readNumbers(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    cin >> *element;
  }
}

void swap(int* lhs, int* rhs) {
  int temp = *lhs;
  *lhs = *rhs;
  *rhs = temp;
}

void sort(int* array, int count) {
  int* lastElement = (array + count) - 1;
  int* endElement = array + count;
  for (int* lhs = array; lhs != lastElement; ++lhs) {
    for (int* rhs = lhs + 1; rhs != endElement; ++rhs) {
      if (*lhs > *rhs) {
        swap(lhs, rhs);
      }
    }
  }
}

void printArray(int* array, int count) {
  int* endElement = array + count;
  for (int* element = array; element != endElement; ++element) {
    cout << *element << endl;
  }
}

int main() {
  int numberCount;
  int* array;

  cin >> numberCount;

  array = new int[numberCount];
  readNumbers(array, numberCount);

  sort(array, numberCount);
  printArray(array, numberCount);

  delete [] array;

  return 0;
}
#endif
