#include <stdio.h>

int tong(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main()
{
  tong (7, 8);
  // int a = 7; // 0x01
  // int b = 8; // 0x02
  // int c;
  // inc c = a + b;
  
  tong(9, 12);
  // int a = 7; // 0xc1
  // int b = 12; // 0xc2
  // int c;
  // c = a + b;
  return 0;
}
