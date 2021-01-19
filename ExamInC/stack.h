/******************************************************************************
 * Definition of a stack data structure,
 * and declarations of the functions that serve as its interface.
 ******************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <stddef.h>   /* size_t */

 /******************************************************************************/
 /***                               Typedefs                                 ***/
 /******************************************************************************/

typedef struct stack stack_t;

/******************************************************************************/
/***                      Public functions declarations                     ***/
/******************************************************************************/

/*
 * Create an empty stack
 * If it fails (memory allocation failure), it will return NULL.
 */
stack_t* CreateStack(void);


/*
 * Free the memory allocated to the stack,
 * and turn the stack to NULL.
 * If stack is NULL, behaviour is undefined.
 */
void DeleteStack(stack_t* stack);

/*
 * Remove the top element from the stack.
 * If the remove was successful, return 0,
 * if the stack was empty, return anything but 0.
 * If stack is NULL, behaviour is undefined.
 */
void* StackPop(stack_t* stack);


/*
 * Push the given item on top of the stack.
 * Upon success, return 0, otherwise (memory allocation failes) return anything but 0.
 * If stack or item are NULL, behaviour is undefined.
 */
int StackPush(stack_t* stack, void* item);

/*
 * Return the current size of the stack, i.e. the index of its 'top'.
 * If the stack is empty, it will return 0.
 * If stack is NULL, behaviour is undefined.
 */
size_t StackSize(const stack_t* stack);

/*
 * Returns 1 if the stack is empty, and 0 otherwise.
 * If stack is NULL, behaviour is undefined.
 */
int StackGetLastError(stack_t*);

/*
 * prints the items in the stack.
 * Returns non.
 */
void StackPrint(stack_t* stack);


#endif   /* __STACK_H_*/
