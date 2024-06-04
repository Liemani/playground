#include <stdio.h>

const int smallBagWeight = 3;
const int bigBagWeight = 5;

int main(void) {
  int targetWeight;
  int bigBagFullCount;
  int remainingSugarAfterDistributingIntoBigBag;
  int smallBagFullCount;
  int remainingSugarAfterDistributingIntoSmallBag;
  int optimizedBagCount;

  scanf("%d", &targetWeight);

  bigBagFullCount = targetWeight / bigBagWeight;
  remainingSugarAfterDistributingIntoBigBag = targetWeight % bigBagWeight;
  smallBagFullCount = remainingSugarAfterDistributingIntoBigBag / smallBagWeight;
  remainingSugarAfterDistributingIntoSmallBag = remainingSugarAfterDistributingIntoBigBag % smallBagWeight;
  bigBagFullCount -= remainingSugarAfterDistributingIntoSmallBag;
  if (bigBagFullCount < 0) {
    printf("-1");
    return 0;
  }
  smallBagFullCount += (remainingSugarAfterDistributingIntoSmallBag + bigBagWeight * remainingSugarAfterDistributingIntoSmallBag) / smallBagWeight;
  optimizedBagCount = bigBagFullCount + smallBagFullCount;

  printf("%d", optimizedBagCount);

  return 0;
}
