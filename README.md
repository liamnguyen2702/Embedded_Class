<details>
  <summary>
    MEMORY LAYOUT
  </summary>
  
# LAYOUT OF MEMORY 
  
 ![image](https://github.com/liamnguyen2702/Embedded_Class/assets/133777741/8748c934-a799-4e3b-8680-cea8de9b2769)
  
 - Text (Text Segment):
 - Ds (Initialized Data Segment):
 - Bss (Uninitialized Data Segment):
 - Heap (Dynamic Memory Allocation):
 - Stack (Automatic Variable Storage): 

 </details>





<details>
<summary> 
  BITWISE OPERATORS
  </summary>
  
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
  
  <details>
<summary>STRUCT AND UNION COMPARISION</summary>
  
# STRUCT AND UNION COMPARISION
  
  | STRUCT | UNION |
  |--------|-------|
  | Size of Struct = sum of all members | Size of Union = the size of the highest one |
  | Can initialize all structure members at a time | Can initialize one union member only at a time |
  | Can access all structure members at a time | Can access one union member at a time |
  
  </details>
