#include <stdio.h>

char arr[] = "Hello"; // DS partitioning (global array)

char *arr_b = "Hello"; // text partitioning (pointer)

int main()
{
    arr_b[0] = "A";
    
    printf("Test: %s\n", arr); // Display: Hello
    
    printf("Test: %s\n", arr_b); // Error because DS partitioning can not write
  
    return 0;
}
