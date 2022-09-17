#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Write a function that tests whether three lengths could form a triangle

bool isValidTriangle(int a, int b, int c);

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    printf("Usage: ./isValidTriangle a b c");
    return -1;
  }

  if (isValidTriangle(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])))
  {
    printf("Valid");
  }
  else
  {
    printf("Invalid");
  }
}

bool isValidTriangle(int a, int b, int c)
{
  int longest = a;
  if (b > longest)
    longest = b;
  if (c > longest)
    longest = c;

  return a + b + c > longest * 2;
}
