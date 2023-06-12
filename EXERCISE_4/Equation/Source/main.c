#include <stdio.h>
#include <string.h>
#include "function.h"

int main()
{
    char arr[100];

    printf("Enter your equation: ");
    fgets(arr, sizeof(arr), stdin);

    check(arr);

    return 0;
}
