#include <stdio.h>
void test()
{
  static int a = 10;
  printf("a = %d\n", a);
  a++;
}

int main()
{
  test(); // 10
  
  test(); // 11
  
  test(); // 12

  return 0;
}

