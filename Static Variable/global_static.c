#include <stdio.h>

int count = 16;

void dem()
{
  printf("count: %d\n", count);
  count++;
}

int main()
{
  dem();
  return 0;
}
