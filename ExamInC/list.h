#ifndef LIST_H
#define LIST_H
/*******************************************************************************
 *
 * Definition of  Linked List ADT & its interface operations declarations
 *
/***                               Includes                                 ***/

#include <stddef.h>   /* size_t                                               */

/***                               Typedefs                                 ***/

typedef struct list list_t;
typedef struct node node_t;

/***                      Public functions declarations                     ***/
/*
 * Create an empty linked list structure.
 * @return If memory allocation fails the function will return NULL.
 */
list_t* CreateList(void);

/*
 * Destroy a given linked list (frees memory of all the elements
 *       inside the list and the memory for the list itself).
 * @return non
 */
void DeleteList(list_t* lst);


/*
 * This function is used for inserting a value as the last value (element).
 * @Returns end -iter on failure or iterator for the new element on success.
 * Time complexity: O(1).
 */
node_t* PushBackList(list_t* lst, const void* data);

/*
 * This function is used for removing last element from the list (not the end -iter).
 * @return the data from the last
 * Pop on empty list will cause undefined behaviour
 * Time complexity: O(n).
 */
void* PopBackList(list_t* lst);


/*
 * This function Checks if a given list is empty or not.
 * Returns 1 on empty list & 0 on non empty list.
 * Time complexity: O(1).
 */
int IsEmptyList(const list_t* lst);


/*
 * The function receives a sllist and a range starting from start and ending
 * ending with end (inclusive), and action function which will be activated on
 * each element of the sllist in the range. If the action function encounters an
 * error while dealing with some element, it will return an error, in that case
 * ForEach will stop iteration and return the same error. if from > to behaviour
 * is undefined. 0 is used for success return status and shouldn't be used
 * for any error code.
 * Time complexity: O(n).
 */
void ForEach(list_t* lst, void (*action)(void* data));

/* @returns number of elements in the list
* Time complexity: O(n).
*/
size_t SizeList(const list_t* lst);


#endif   /* __LIST_H_ */


















