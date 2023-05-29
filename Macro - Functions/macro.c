#include <stdio.h>

#define MAX 10

#define SUM(a, b) a + b 

#define Create_func(function_name, contents)  \
    void function_name()                      \
    {                                         \
      printf("%s\n", contents);               \ 
    }

Create_func(test, "This is test");

Create_func(abc, "This is abd function");

int main()
{
  printf("MAX: %d\n", MAX);
  
  int a = MAX + 5;
  
  printf("Tong a va b: %d\n", SUM (5, 8));
  
  printf("Tong a va b: %d\n", SUM (12, 20));
  
  test(); // This is test
  
  abc(); // This is abd function
  
  return 0;
}  
