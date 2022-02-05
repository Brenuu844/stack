#include "stack.h"
#include <assert.h>
#include <stdbool.h>

void testCreate()
{
    Stack *stack;

    stack = createStack();

    assert(isEmpty(stack) == true);

    freeStack(stack);
}

void testPush()
{
    Stack *stack;

    stack = createStack();

    push(stack, 10);

    assert(isEmpty(stack) == false);

    freeStack(stack);
}

int main()
{
    testCreate();

    testPush();

    return 0;
}
