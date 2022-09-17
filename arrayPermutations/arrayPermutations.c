#include <stdio.h>
#include <stdlib.h>

// "Given an array of distinct integers, return all the possible
// permutations. You can return the answer in any order."

// Usage: ./arrayPermutations 1 2 3 ...

void nextNumberCombination(int arr[], int length, int index);
void swapIndices(int arr[], int index1, int index2);
void printArray(int arr[], int length);

int main(int argc, char *argv[])
{
  int *nums;

  nums = malloc(argc * sizeof(int));

  for (int i = 1; i < argc; i++)
  {
    nums[i - 1] = atoi(argv[i]);
  }

  nextNumberCombination(nums, argc - 1, 0);
  return 0;
}

void swapIndices(int arr[], int index1, int index2)
{
  int intToSwap = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = intToSwap;
}

void printArray(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%i", arr[i]);

    if (i < length - 1)
    {
      printf(", ");
    }
  }
  printf("\n");
}

// Walk down, fill up array, print when at the end
void nextNumberCombination(int arr[], int length, int index)
{
  for (int i = index; i < length; i++)
  {
    swapIndices(arr, index, i);
    nextNumberCombination(arr, length, index + 1);
    swapIndices(arr, index, i);
  }

  if (index == length - 1)
  {
    printArray(arr, length);
  }
}
