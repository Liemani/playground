#include <stdio.h>
#include <stdlib.h>

void add_arrays(const float* inA,
    const float* inB,
    float* result,
    int length)
{
  for (int index = 0; index < length; ++index)
  {
    result[index] = inA[index] + inB[index];
  }
}

void printFloatArray(const float* inFloatArray,
    int length)
{
  const float* inEnd = inFloatArray + length;

  printf("[ ");
  for (const float* inFloat = inFloatArray; inFloat != inEnd; ++inFloat)
  {
    printf("%.2f, ", *inFloat);
  }
  printf("]");
}

#define ARRAY_LENGTH 20

void initArrayWithScale(float* outFloatArray,
    int length,
    int scale)
{
  float* outFloat = outFloatArray;

  for (int index = 0; index < length; ++index)
  {
    *outFloat = scale * index;
    ++outFloat;
  }
}

int main(int argc, char* argv[])
{
  float arrayA[ARRAY_LENGTH];
  float arrayB[ARRAY_LENGTH];
  float* resultArray = malloc(sizeof(float) * ARRAY_LENGTH);

  initArrayWithScale(arrayA, ARRAY_LENGTH, 2);
  initArrayWithScale(arrayB, ARRAY_LENGTH, 3);

  add_arrays(arrayA, arrayB, resultArray, ARRAY_LENGTH);

  printFloatArray(arrayA, ARRAY_LENGTH);
  printFloatArray(arrayB, ARRAY_LENGTH);
  printFloatArray(resultArray, ARRAY_LENGTH);

  return 0;
}
