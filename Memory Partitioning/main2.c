#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int main()
{
    uint8_t *ptr = (uint8_t *) malloc(sizeof(uint16_t) * 5); //general method
      for (int i = 0; i < 5; i++)
      {
          arr[i] = i;
      }
  
      for (int i = 0; i < 5; i++)
      {
        printf("i = %d\n", arr[i]);
      }
      
      arr = (uint8_t *)realloc(arr, sizeof(uint8_t) * 3);
    return 0;
}
