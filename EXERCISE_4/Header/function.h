#ifndef FUNCTION_H
#define FUNCTION_H

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

typedef struct {
    char data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initStack(Stack *stack);
int isStackEmpty(Stack *stack);
int isStackFull(Stack *stack);
void push(Stack *stack, char value);
char pop(Stack *stack);
void initQueue(Queue *queue);
int isQueueEmpty(Queue *queue);
int isQueueFull(Queue *queue);
void enqueue(Queue *queue, char value);
char dequeue(Queue *queue);
int getOperatorPriority(char opChar);
char* processExpression(char *expression);
float evaluatePostfix(char *expression);

#endif

