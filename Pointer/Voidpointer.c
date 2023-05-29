#include <stdio.h>

int main()
{
  int i = 10;
  
  double d = 15.6;
  
  char c = 'B';
  
  int *ptr = &d; // Error different type
  
  void *ptr = &i; // it's ok
  
  printf("i = %d\n", *ptr); // can not take the value from the pointer void
  /* so have to set up the type for variable
  ex: */
  printf("i = %d\n", *(int *) ptr);
  
  ptr = &d;               printf("i = %f\n", *(double*) ptr);
  
  ptr = & c;              printf("i = %c\n", *(char*) ptr);
  
  ptr = &tong;            ((void (*) (int, int)) ptr) (9, 16);
  
  return 0;
}
