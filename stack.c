#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node_
{
    int data;
    struct node_ *next;
}Node;

struct Stack_
{
    Node *first;
};

Stack* createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->first = NULL;
    return stack;
}

bool isEmpty(Stack* stack)
{
    return stack->first == NULL ? true : false;
}

void freeStack(Stack* stack)
{
    Node *currentNode;
    while (!isEmpty(stack))
    {
        currentNode = stack->first;
        stack->first = currentNode->next;
        free(currentNode);
    }

    free(stack);
}

void push(Stack* stack, int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = stack->first;
    stack->first = node;
    node->data = value;
}
