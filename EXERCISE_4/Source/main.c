#include <stdio.h>
#include <stdlib.h>
#include "function.h"

int main() {
    char expression[MAX_SIZE];

    printf("Enter an infix expression: ");
    fgets(expression, sizeof(expression), stdin);

    float result = evaluatePostfix(processExpression(expression));

    printf("The result is: %f\n", result);

    return 0;
}
