#include <stdio.h>    /* printf, size_t */
#include "stack.h"    /* bit_array_t and all its functions */

/******************** Functions Declarations ********************/

void TestStackCreateDestroy(void);
void TestStackPush(void);
void TestStackPop(void);
void TestStackSize(void);

/******************** main function ********************/

int main(void)
{

    TestStackCreateDestroy();
    TestStackPush();
    TestStackPop();
    TestStackSize();

    return 0;
}

/******************** Functions Implementations ********************/

void TestStackCreateDestroy(void)
{
    size_t element_size = 8;
    stack_t* stack = StackCreate();

    printf("Stack was created without crashing!\n");

    StackDelete(stack);

    printf("Stack was destroyed without crashing!\n");

    printf("\n");
}

void TestStackPush(void)
{
    long num = 15;
    static int status[5];
    static int status_expected[5] = { 0, 0, 0, 1, 1 };
    int i = 0;
    int success = 1;

    stack_t* stack = StackCreate();

    printf("Attempting to push 5 times to a stack with a capacitiy of 3,\n"
        "expected statuses are: 0, 0, 0, 1, 1.\n");

    for (i = 0; i < 5; ++i)
    {
        status[i] = StackPush(stack, &num);
        if (status[i] != status_expected[i])
        {
            success = 0;
        }
    }

    if (success)
    {
        printf("StackPush test was success!\n");
    }
    else
    {
        printf("StackPush test has failed! --- --- --- --- ---\n");
        for (i = 0; i < 5; ++i)
        {
            printf("     StackPush finished with status %d\n", status[i]);
        }
    }
    printf("\n");

    StackDestroy(stack);
}

void TestStackPop(void)
{
    long num = 15;
    static int status[5];
    static int status_expected[5] = { 0, 0, 0, 1, 1 };
    int i = 0;
    int success = 1;

    stack_t* stack = StackCreate();

    StackPush(stack, &num);
    StackPush(stack, &num);
    StackPush(stack, &num);

    printf("Attempting to pop 5 times to a full stack with a capacitiy of 3,\n"
        "expected statuses are: 0, 0, 0, 1, 1.\n");

    for (i = 0; i < 5; ++i)
    {
        status[i] = StackPop(stack);
        if (status[i] != status_expected[i])
        {
            success = 0;
        }
    }

    if (success)
    {
        printf("StackPop test was success!\n");
    }
    else
    {
        printf("StackPop test has failed! --- --- --- --- ---\n");
        for (i = 0; i < 5; ++i)
        {
            printf("     StackPop finished with status %d\n", status[i]);
        }
    }
    printf("\n");

    StackDestroy(stack);
}




void TestStackSize(void)
{
    long num = 15;
    size_t sizes[5];
    size_t sizes_expected[5] = { 3, 2, 1, 0, 0 };
    int success = 1;
    int i = 0;

    stack_t* stack = StackCreate();

    StackPush(stack, &num);
    StackPush(stack, &num);
    StackPush(stack, &num);

    printf("Stack of size 3, each time we get the size then we Pop,\n"
        "expected sizes are: 3, 2, 1, 0, 0.\n");

    for (i = 0; i < 5; ++i)
    {
        sizes[i] = StackSize(stack);
        StackPop(stack);

        if (sizes[i] != sizes_expected[i])
        {
            success = 0;
        }
    }

    if (success)
    {
        printf("StackSize test was success!\n");
    }
    else
    {
        printf("StackSize test has failed! --- --- --- --- ---\n");
        for (i = 0; i < 5; ++i)
        {
            printf("     StackSize = %lu\n", sizes[i]);
        }
    }

    printf("\n");

    StackDestroy(stack);
}