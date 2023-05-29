#include <stdio.h>

void tong(int a, int b)
{
  printf("Tong %d va %d = %d\n", a, b, a + b);
}

int tich(int a, int b)
{
  return a * b;
}

void hieu(int a, int b)
{
  return a - b;
}

void thuong(int a, int b)
{
  printf("Thuong %d va %d: %d\n", a, b, (float) a / b);
}

// void tinh_toan(int a, int b, void (*ptr)(int, int))
// {
//   printf("Chuong trinh toan\n");
//   ptr(a, b);
// }


int main()
{
  void (*ptr)(int, int) = NULL;
  
  ptr = &tong;
  
  ptr(10, 8);
 
  int (*ptr_tich)(int, int) = &tich;
  
  printf("Tich a va b: %d\n", ptr_tich(6, 7));
  
  void (*phep_toan)(int, int) = NULL;
  
  phep_toan = &tong; 
  
  phep_toan(7, 9);
  
//   tinh_toan(8, 9, thuong);
  
  return 0; 
}
