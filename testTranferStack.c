#include "stack.h"
#include <string.h>
#include <assert.h>

int stackLen(Stack *stackSrc, Stack *stackAux)
{
    int rc = 0;
    while(!isEmpty(stackSrc))
    {
        push(stackAux, pop(stackSrc));
    }

    while(!isEmpty(stackAux))
    {
        push(stackSrc, pop(stackAux));
        rc++;
    }

    return rc;
}

void reverseStack(Stack *stackSrc, Stack *stackAux)
{
    int dataAux;
    int stackSize = stackLen(stackSrc, stackAux);
    int count = 0;
    int i;

    while (count < stackSize)
    {
        dataAux = pop(stackSrc);

        for (i = 0; i < stackSize - count - 1; i++)
        {
            push(stackAux, pop(stackSrc));
        }

        push(stackSrc, dataAux);

        while (!isEmpty(stackAux))
        {
            push(stackSrc, pop(stackAux));
        }
        count++;
    }
}

void transferStack (Stack *stackSrc, Stack *stackDest)
{
    reverseStack(stackSrc, stackDest);

    while(!isEmpty(stackSrc))
    {
        push(stackDest, pop(stackSrc));
    }
}

void populationStack(Stack *stack, const int *values, size_t valuesLen)
{
    int i;

    for(i = 0; i < valuesLen; i++)
    {
        push(stack, values[i]);
    }
}

void testTransferStack()
{
    int i;
    Stack *stackSrc;
    Stack *stackDest;
    const int values[] = {1, 2, 3, 4, 5};
    size_t valuesLen = sizeof(values) / sizeof(values[0]);

    stackSrc = createStack();
    stackDest = createStack();

    populationStack(stackSrc, values, valuesLen);

    transferStack(stackSrc, stackDest);

    for (i = (int)valuesLen - 1; i >= 0; i--)
    {
        assert(values[i] == pop(stackDest));
    }
}

void testTransferStackLen()
{
    Stack *stackSrc;
    Stack *stackDest;
    const int values[] = {1, 2, 3, 4, 5};
    size_t valuesLen = sizeof(values) / sizeof(values[0]);

    stackSrc = createStack();
    stackDest = createStack();

    populationStack(stackSrc, values, valuesLen);

    transferStack(stackSrc, stackDest);

    assert(stackLen(stackDest, stackSrc) == valuesLen);
}

void testStackLen()
{
    Stack *stackSrc;
    Stack *stackDest;
    const int values[] = {1, 2, 3, 4, 5};
    size_t valuesLen = sizeof(values) / sizeof(values[0]);
    int stackSize;

    stackSrc = createStack();
    stackDest = createStack();

    populationStack(stackSrc, values, valuesLen);

    stackSize = stackLen(stackSrc, stackDest);

    assert(stackSize == valuesLen);
}

void testStackLenEqual()
{
    int i;
    Stack *stackSrc;
    Stack *stackDest;
    const int values[] = {1, 2, 3, 4, 5};
    size_t valuesLen = sizeof(values) / sizeof(values[0]);
    int stackSize;

    stackSrc = createStack();
    stackDest = createStack();

    populationStack(stackSrc, values, valuesLen);

    stackSize = stackLen(stackSrc, stackDest);

    for (i = valuesLen - 1; i >= 0; i--)
    {
        assert(values[i] == pop(stackSrc));
    }
}

void testStackLenSrc()
{
    Stack *stackSrc;
    Stack *stackAux;
    const int values[] = {1, 2, 3, 4, 5};
    size_t valuesLen = sizeof(values) / sizeof(values[0]);

    stackSrc = createStack();
    stackAux = createStack();

    populationStack(stackSrc, values, valuesLen);

    stackLen(stackSrc, stackAux);

    assert(!isEmpty(stackSrc));
}

void testStackLenAux()
{
    Stack *stackSrc;
    Stack *stackAux;
    const int values[] = {1, 2, 3, 4, 5};
    size_t valuesLen = sizeof(values) / sizeof(values[0]);

    stackSrc = createStack();
    stackAux = createStack();

    populationStack(stackSrc, values, valuesLen);

    stackLen(stackSrc, stackAux);

    assert(isEmpty(stackAux));
}

int main()
{
    testTransferStackLen();
    testTransferStack();

    testStackLen();
    testStackLenEqual();
    testStackLenSrc();
    testStackLenAux();

    return 0;
}
