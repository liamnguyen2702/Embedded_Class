#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void test()
{
  char arr[3];
  printf("Dia chi arr: %p\n", arr);
} // saved at stack memory (local variables, input parameters,...)

void test2()
{
  char arr* = (char*) malloc (sizeof(char) * 3);
  free(arr);
} // saved at heap memory (dynamic memory, malloc, calloc, realloc)

int main()
{
  test();
  test();
  test2();
  test2();
  return 0;
}
