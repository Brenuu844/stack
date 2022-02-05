#include "stdbool.h"

typedef struct Stack_ Stack;

Stack* createStack();

bool isEmpty(Stack* stack);

void freeStack(Stack* stack);

void push(Stack* stack, int value);

