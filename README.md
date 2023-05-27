<details>
  <summary> POINTER </summary>

  A pointer is a variable whose value is the address of another variable, i.e., direct address of the memory location. Like any variable or constant, you must declare a pointer before using it to store any variable address. The general form of a pointer variable declaration is −

  ```C
  type *var-name;
  ```
  ```C
  #include <stdio.h>
  
  int main()
  {
      int n = 10; 
      int *p = &n; // declare p having value = the address of n;
      or
      int *p;
      p = &n;
      return 0;
  }
  ```
  The value of the variable that pointer is pointing equal *p - 
  ```C
  printf("The value of variable that p is pointing = %d", *p);
  ```
  It produces the following result - 
  ```C
  The value of variable that p is pointing = 10
  ```
  
  ### NULL Pointer
  
  The NULL pointer is a constant with a value of zero defined in several standard libraries. Consider the following program −
  
  ```C
  #include <stdio.h>
  
  int main()
  {
      int *ptr = NULL;
      printf("The value of ptr is: %x\n", ptr);
      return 0;
  }
  ```
  When the above code is compiled and executed, it produces the following result - 
  ```C
  The value of ptr is 0
  ```

  ### Pointer Function
  ```C
  #include <stdio.h>
  
  void sum(int a, int b)
  {
    printf("Sum of %d and %d = %d\n, a, b, a + b);
  }
  int main()
  {
    void (*ptr) (int, int) = NULL;
    ptr = &sum;
    ptr(9, 7);
    return 0;
  }
  ```
  
  It produces the result below - 
  ```C
  Sum of 9 and 7 = 16
  ```
  
  ### Void Pointer
  
  A pointer of type void is a general pointer variable, it can take the address of any variable of any data type.

  ### Pointer to Pointer
  
  ```C
#include <stdio.h>
#include <string.h>

int main()
{   
    char *array = "hello"; // save as text area - only read
    char array[] = "hello"; // save as stack area - can write
    char *array2[] = {"Hi", "hello", "wolrd"}; 
    printf("Test: %s\n", *array2);
    return 0;
}
  ```

</details>

 -------------------------------------------------------------
	
	
  <details>
<summary>STRUCT - UNION</summary>
  
# STRUCT AND UNION COMPARISION
  
  | STRUCT | UNION |
  |--------|-------|
  | Size of Struct = sum of all members | Size of Union = the size of the highest one |
  | Can initialize all structure members at a time | Can initialize one union member only at a time |
  | Can access all structure members at a time | Can access one union member at a time |
  
  </details>
	
-------------------------------------------------------------
	
  <details>
<summary> STATIC VARIABLE </summary>
 </details>	
	
	
------------------------------------------------------------------------------------------	
	
	
<details>
<summary> BITS MANIPULATION </summary>
  
# BITWISE OPERATORS 

  1, The & (bitwise AND) - The result of AND is 1 only if both bits are 1. (time)
  
 | A | B | A & B |
  |---|---|:---:|
  |0|0|  0|
  |0|1|  0|
  |1|0|  0|
  |1|1|  1|
  
  2, The | (bitwise OR) - The result of OR is 1 if any of the two bits is 1.
  
 | A | B | A \| B |
  |---|---|:---:|
  |0|0|  0|
  |0|1|  1|
  |1|0|  1|
  |1|1|  1|
  
  3, The ^ (bitwise XOR) - The result of XOR is 1 if the two bits are different.   

 | A | B | A ^ B |
  |---|---|:---:|
  |0|0|  0|
  |0|1|  1|
  |1|0|  1|
  |1|1|  0|
  
  4, The ~ (bitwise NOT) - Takes one number and inverts all bits of it. 
  
   | A | NOT A |
  |--|:---:|
  |0|  1|
  |1|  0|
  
  5, The << (left shift) - Takes two numbers, left shifts the bits of the first operand, and the second operand decides the number of places to shift. (delete the left)

  6, The >> (right shift) - Takes two numbers, right shifts the bits of the first operand, and the second operand decides the number of places to shift. (delete the right) 
  
 </details>

	
-------------------------------------------------------------
	
  <details>
<summary> MACRO - INLINE FUNCTIONS </summary>
 </details>	
	
	
-------------------------------------------------------------
	
<details>
  <summary> MEMORY PARTITIONING </summary>
  
# LAYOUT OF MEMORY 
  
 ![image](https://github.com/liamnguyen2702/Embedded_Class/assets/133777741/8748c934-a799-4e3b-8680-cea8de9b2769)
  
 - Stack (Automatic Variable Storage): Automatic memory allocation, contain function frame during program execution 
 - Heap (Dynamic Memory Allocation): Dynamic memory allocation by malloc/calloc/new
 - Bss (Uninitialized Data Segment): Global & Static variable that uninitialized or initialized to 0
 - Ds (Initialized Data Segment): Global & Static variable that initialized by programers
 - Text (Text Segment): Contain code (Program instruction)

 </details>
	
--------------------------------------------------------------	
	
  <details>
<summary> COMPILER </summary>
 </details>

	
	

