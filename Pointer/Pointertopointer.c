#include <stdio.h>
#include <string.h>

int main()
{
  char *array = "hello";
  
  char array1[] = "hello";
  
  char *array2[] = {"Hi", "Hello", "World"};
  
  printf("Test: %s\n", *array2);
  
  return 0;
}
