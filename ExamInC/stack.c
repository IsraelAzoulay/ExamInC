//Name: Israel Azoulay, ID: 316564202.

#include <string.h>   /*strcpy*/
#include <assert.h>  /*assert*/
#include <stdlib.h>  /*malloc, free*/
#include"list.h"
#include "stack.h"    /* stack header */

struct stack
{
    list_t* list;
};

static void Print(int data);
/*****************************************************************************/
stack_t* CreateStack(void)
{
    stack_t* s = malloc(sizeof(*s));
    if (NULL != s)
    {
        s->list = CreateList();
        if (NULL == s->list)
        {
            free(s);
            return NULL;
        }
    }
    return s;
}

void DeleteStack(stack_t* stack)
{
    DeleteList(stack->list);
    free(stack);
}

void* StackPop(stack_t* stack)
{
    assert(stack);

    return PopBackList(stack->list);
}

int StackPush(stack_t* stack, void* item)
{
    assert(stack);

    if (NULL != PushBackList(stack->list, item))
    {
        return 0;
    }
    return 1;
}

size_t StackSize(const stack_t* stack)
{
    assert(stack);

    return SizeList(stack->list);
}

int StackGetLastError(stack_t*);


void StackPrint(stack_t* stack)
{
    ForEach(stack ->list, &Print);
}

static void Print(int data)
{
    printf("%d, ", data);
}
















