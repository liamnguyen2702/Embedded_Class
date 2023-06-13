<details>
  <summary> CLASS - C++ </summary>
	
</details>

-------------------------------------------------------------

<details>
  <summary> MAKEFILE </summary>
	
Makefile - an important tool that automates and simplifies the process of compiling and linking source files in C/C++ programming projects. Makefile saves time, ensures consistency, and eases project management.
	
- Create a 'Makefile' file in the project directory.

- Define variables in Makefile. 

For example:

```C
CC := gcc
CXX := g++
CFLAGS := -Wall -Wextra -std=c11 -IHeader
CXXFLAGS := -Wall -Wextra -std=c++11 -IHeader
TARGET := main

SRC_C := $(wildcard Source/*.c)
SRC_CPP := $(wildcard Source/*.cpp)
```
	
- `CC` and `CXX` are variables that define the C and C++ compilers to be used, respectively. In this case, `gcc` is set as the C compiler, and `g++` is set as the C++ compiler.

- `CFLAGS` and `CXXFLAGS` are variables that specify the compiler flags for C and C++ compilation, respectively. The flags set in these variables include `-Wall` (enable all warnings), `-Wextra` (enable extra warnings), `-std=c11` (for C compilation using the C11 standard), and `-std=c++11` (for C++ compilation using the C++11 standard). Additionally, `-IHeader` adds the `Header` directory to the include path.

- `TARGET` is a variable that specifies the name of the target executable, which in this case is set to `main`.

- `SRC_C` and `SRC_CPP` are variables that use the `wildcard` function to find all `.c` and `.cpp` files, respectively, in the `Source` directory.
```C
.PHONY: all clean run

all: $(TARGET)
```
- `.PHONY` is a special target that declares the following targets as "phony" or not representing actual files. This ensures that these targets are always executed regardless of whether there are files with the same name.

- `all` is a target that depends on the `$(TARGET)` executable.
```C
$(TARGET): $(SRC_C) $(SRC_CPP)
	$(CXX) $(CXXFLAGS) $^ -o $@
```
- `$(TARGET)` is the target executable. It depends on the `$(SRC_C)` and `$(SRC_CPP)` files.

- The line starting with `$(CXX)` is the command to build the target. It uses the C++ compiler (`g++`) and applies the `CXXFLAGS` (compiler flags) defined earlier. `$^` is an automatic variable that represents all the prerequisites (source files), and `$@` represents the target (the `$(TARGET)` executable). This line compiles and links all the source files into the `$(TARGET)` executable.
	
```C
run: $(TARGET)
	./$(TARGET)
```
- `run` is a target that depends on the `$(TARGET)` executable.

- The line `./$(TARGET)` is the command to run the target executable.
```C
	clean:
	$(RM) $(TARGET)
```
- `clean` is a target used for cleaning the project.

- The line `$(RM)` `$(TARGET)` uses the `$(RM)` variable, which represents the remove command, to delete the `$(TARGET)` executable.

In summary, this Makefile is designed to compile and build a C and C++ project. The `all` target is the default target and is responsible for building the `$(TARGET)` executable. The `run` target allows you to execute the `$(TARGET)` executable. The `clean` target removes the `$(TARGET)` executable.
	
</details>

 -------------------------------------------------------------

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
  <summary> EXTERN </summary>
		
- To access a global variable in 2 different files
- Suppose there is a global file in file test.c, it can be used in file main.c
```C
	extern int count;
```
- Being use in a large project while unknow where the library to include -> using extern.
- "Extern" is a variable and being located in 2 different files.
- In addition, "extern" can be using for function.
```C
	extern void dem(); // add function dem () from other file
```
- Can not "extern" a global static variable
- Otherwise: "Extern" still allow a function when having a global static variable in. 
	
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
<summary> STATIC VARIABLES </summary>
	  
## Local Static Variable

- The local static variables is initialized once and lasts the entire all the program.
```C
	void excample()
	  {
	  	static int a = 15;
	  	printf ("a = %d\n", a);
	  	a++;
	  }
	  
	  int main()
	  {
	  	example(); // 15
	  
	  	example(); // 16
	  	
	  	example(); // 17
	  
	  	return 0;
	  }
	  	
```
	  
## Global Static Variable
- The global static variables are only valid in the file those variables are created
- Using by all of functions in initial file
- Can not called from the other files.
	  
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
	  
## Macro
	  
- Take place in preprocessing 
- Macro is actually replacing the definition in main 
```C
	  #define MAX 10;
```
- For example: 
```C	
	  #define SUM(a, b) a + b
	  #define CREATE_FUNC (func_name, content)	\
	  void func_name()				\
	  	{					\	
	  		printf("%s\n", content);	\
	  	}
```
- Using operator "\" when having to enter in macro.
- Disadvantage: the size of the compiled file will be larger because of calling multiple times.
- Advantage: Decrease the time of program.
	  
## Function

- When the function is called, the compiler stores the poiter address at that location. The pointer will continue to jump into the function and execute the entire function. After the funtion ends, the pointer will return the address before jumping into the function and continuing the program.
- Programing running time is slow, while the code is more concise. 
- For instance:
```C
	  void SUM(int a, int b)
	  {
	  	printf("%d", a + b);
	  }
```
	  	
## Inline function
	  
- A funtion declared with the inline keywork and processed by the compiler. At the place where the inline function appears, the compiler will replace the inline function with the code of the compiled function (the code has been converted to assembly code).
- Inline makes the code longer but takes less time to run than the function.
	  
```C
	#include <stdio.h>

	inline void test ()
	{
	} // 0xc4  0x05

	int main()
	{
  		test (); // 0xc4 0x05
  
  		test (); // 0xc4 0x05
  
  	return 0;
	}	  
```
	  

 </details>	
	
	
-------------------------------------------------------------
	
<details>
  <summary> MEMORY PARTITIONING </summary>
  
# LAYOUT OF MEMORY 
  
 ![image](https://github.com/liamnguyen2702/Embedded_Class/assets/133777741/8748c934-a799-4e3b-8680-cea8de9b2769)
  
 - Stack (Automatic Variable Storage): Automatic memory allocation, contain function frame during program execution 
	- Access is Read and Write
	- Using to allocate to local variables, input parameters of functions
	- Released at the end of the code block or function
 - Heap (Dynamic Memory Allocation): Dynamic memory allocation by malloc/calloc/new
	- Access is Read and Write
	- Using to allocate dynamic memory such as Malloc, Calloc,...
	- Released at the free function is called
 - Bss (Uninitialized Data Segment):
	- Access is Read and Write
	- Contains global or static variables with a zero (0) initialized or un initialized
	- Released at the end of the program
 - Ds (Initialized Data Segment): 
	- Access is Read and Write
	- Contains a global or static variables with a non-zero initialized value
	- Released at the end of the program
 - Text (Text Segment):
	- Contain code (Program instruction)
	- Read only access and it contains instructions to execute, so avoid modifying instruction.
	- Contains declaration of constants in the program (.rodata)

# Heap and Stack ?
	
- Heap and Stack memory are essentially the same memory that is creaated and stored in RAM when the program is executed.
	
- Stack memory is used to store local variables in functions, parameters passed in,...Access to this memory very fast and is executed when the program is compliled.
	
- Heap memory is used to store memory for pointer variables dynamically allocated by functions malloc - calloc - realloc (in C)
	
- Area size:
	- Stack: The size of the Stack memory is fixed, depending on the operating system, for instance, Windows operating system is 1MB, Linux operating is 8MB (note that the number may differ depending on your operating system architecture).
	- Heap: The size of the Heap memory is not fixed, it can be increased or decreased to meet the data storage needs of the program.
- Characteristics of the memory area:
	- Stack: Stack memory is managed by the operating system, the data stored in the Stack will automatically be destroyed when the function completes its work.
	- Heap: The Heap is managed by the programmer (in C or C++), the data in the Heap will not be destroyed when the function is done, that means you have to manually destroy the memory are with the free statement (in C), and delete or delete[] (in C++), otherwise a memory leak will occur. 
	
Note: automatic memory cleanup depends on the intermediate compiler
	
- An error occurred in the memory area:
	- Stack: Because the memory of the Stack is fixed, if your program uses too much memory beyond the storage capacity of the Stack, Stack overflow will inevitably occur such as: initialize too many local variables, infinitely recursive function,...
	- Example of Stack overflow with infinite recursion: 
```C
	int foo (int x)
	{
		printf("De quy khong gioi han\n");
		return foo(x);
	}
```

- Heap: 
	- If continously allocating memory without freeing it, you will get a Heap overflow error.
	- If initializing a memory area that is too large that the Heap connot be stored once, the Heap initialization error will fail.
	- Example case initialization of Heap memory is too large:
	
```C
	int *A = (int*) malloc (12983781273981273981273891273891273);
```
	
	
 </details>
	
--------------------------------------------------------------	
	
  <details>
<summary> COMPILER </summary>

![Compilation-Process-in-C](https://github.com/liamnguyen2702/Embedded_Class/assets/133777741/a6f67411-9f60-4150-873d-a59f51fca37d)
	  
It is the process of converting high-level programing language such as C, C++, and Python into languages that computers can understand and execute. In short, "Compiler" will turn .c files into hex files to load into MCUs.
	  
The compilation process is divided into 4 main stages:
- Pre-processcor: Get source code & delete comments, process preprocessor commands	  
- Translate high-level programing languages (H-LPL) to Assembly
- Translate Assembly into machine language: Translate Assembly code to code 0 1 and generate .0 file
- Linking stage: Link the object files and library files together and create the executable file
	
	  
 </details>

	


	

