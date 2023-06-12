#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../Header/function.h"

void initStack(Stack *stack) {
    stack->top = -1;
}

int isStackEmpty(Stack *stack) {
    return (stack->top == -1);
}

int isStackFull(Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

void push(Stack *stack, char value) {
    if (isStackFull(stack)) {
        printf("Stack is full, cannot push element.\n");
        return;
    }
    stack->data[++(stack->top)] = value;
}

char pop(Stack *stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty, cannot pop element.\n");
        return '\0';
    }
    return stack->data[(stack->top)--];
}

void initQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isQueueEmpty(Queue *queue) {
    return (queue->front == -1);
}

int isQueueFull(Queue *queue) {
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(Queue *queue, char value) {
    if (isQueueFull(queue)) {
        printf("Queue is full, cannot enqueue element.\n");
        return;
    }
    if (isQueueEmpty(queue))
        queue->front = queue->rear = 0;
    else
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
}

char dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("Queue is empty, cannot dequeue element.\n");
        return '\0';
    }
    char value = queue->data[queue->front];
    if (queue->front == queue->rear)
        queue->front = queue->rear = -1;
    else
        queue->front = (queue->front + 1) % MAX_SIZE;
    return value;
}

int getOperatorPriority(char opChar) {
    if (opChar == '(' || opChar == ')') {
        return 1;
    } else if (opChar == '*' || opChar == '/') {
        return 2;
    } else if (opChar == '+' || opChar == '-') {
        return 3;
    }
    return -1;
}

char* processExpression(char *expression) {
    int length = strlen(expression);
    Stack stack;
    Queue queue;
    initStack(&stack);
    initQueue(&queue);

    int i;
    for (i = 0; i < length; i++) {
        char currentChar = expression[i];
        if (isdigit(currentChar)) {
            enqueue(&queue, currentChar);
        } else if (currentChar == '(') {
            push(&stack, currentChar);
        } else if (currentChar == ')') {
            while (!isStackEmpty(&stack)) {
                char topChar = pop(&stack);
                if (topChar == '(') {
                    break;
                }
                enqueue(&queue, topChar);
            }
        } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            int currentPriority = getOperatorPriority(currentChar);
            while (!isStackEmpty(&stack)) {
                char topChar = stack.data[stack.top];
                int topPriority = getOperatorPriority(topChar);
                if (topChar == '(' || currentPriority < topPriority) {
                    break;
                }
                enqueue(&queue, pop(&stack));
            }
            push(&stack, currentChar);
        }
    }

    while (!isStackEmpty(&stack)) {
        enqueue(&queue, pop(&stack));
    }

    char* out = (char*)calloc(length + 1, sizeof(char));
    int idx = 0;
    while (!isQueueEmpty(&queue)) {
        out[idx++] = dequeue(&queue);
        out = (char*)realloc(out, (idx + 1) * sizeof(char));
    }
    return out;
}

float evaluatePostfix(char *expression) {
    Stack stack;
    initStack(&stack);

    int i;
    float op1, op2, result;

    for (i = 0; expression[i] != '\0'; i++) {
        if (isdigit(expression[i])) {
            push(&stack, (float)(expression[i] - '0'));
        } else if (expression[i] != ' ') {
            if (isStackEmpty(&stack)) {
                printf("Invalid postfix expression\n");
                exit(EXIT_FAILURE);
            }

            op2 = pop(&stack);

            if (isStackEmpty(&stack)) {
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

    if (isStackEmpty(&stack) || stack.top > 0) {
        printf("Invalid postfix expression\n");
        exit(EXIT_FAILURE);
    }

    return pop(&stack);
}
