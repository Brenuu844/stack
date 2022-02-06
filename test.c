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

void testPop()
{
    Stack *stack;

    stack = createStack();

    push(stack, 10);

    pop(stack);

    assert(isEmpty(stack) == true);

    freeStack(stack);
}

void testPopValue()
{
    const int valueTest = 10;

    Stack *stack;

    stack = createStack();

    push(stack, valueTest);

    assert(pop(stack) == valueTest);

    freeStack(stack);
}

void testTop()
{
    Stack *stack;
    const int valueTest = 10;

    stack = createStack();

    push(stack, valueTest);

    top(stack);

    assert(isEmpty(stack) == false);

    freeStack(stack);
}

void testTopValue()
{
    int value;
    const int valueTest = 10;

    Stack *stack;

    stack = createStack();

    push(stack, valueTest);

    value = top(stack);

    assert(value == valueTest);

    freeStack(stack);
}

/*int main()
{
    testCreate();

    testPush();

    testPop();

    testPopValue();

    testTop();

    testTopValue();

    return 0;
}
*/
