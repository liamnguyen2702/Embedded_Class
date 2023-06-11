#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    float data[MAX_SIZE];
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return (stack->top == -1);
}

int isFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack *stack, float item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = item;
}

float pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

float evaluatePostfix(char *expression) {
    Stack stack;
    initialize(&stack);

    int i;
    float op1, op2, result;

    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, (float)(expression[i] - '0'));
        } else if (expression[i] != ' ') {
            if (isEmpty(&stack)) {
                printf("Invalid postfix expression\n");
                exit(EXIT_FAILURE);
            }

            op2 = pop(&stack);

            if (isEmpty(&stack)) {
                printf("Invalid postfix expression\n");
                exit(EXIT_FAILURE);
            }

            op1 = pop(&stack);

            switch (expression[i]) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(EXIT_FAILURE);
            }

            push(&stack, result);
        }
    }

    if (isEmpty(&stack) || stack.top > 0) {
        printf("Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }

    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter postfix expression: ");
    scanf("%[^\n]s", expression);

    float result = evaluatePostfix(expression);
    printf("Result: %.2f\n", result);

    return 0;
}
