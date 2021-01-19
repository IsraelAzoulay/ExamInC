/************************************************************************
*	Description: Implementation of linked list.
*************************************************************************/

#include <assert.h>  /*assert*/
#include <stdlib.h>  /*malloc, free*/
#include <string.h>   /*memcpy */
#include "list.h"    /* slist header */

/******************************************************************************/
/*                              Typedefs                                      */
/******************************************************************************/



struct list
{
	struct node* head;
	struct node* tail;
};

struct node
{
	void* data;
	node_t* next;
};



/******************************************************************************/
/*                      constractor / destractor                              */
/******************************************************************************/

static node_t* NodeCreate(void* data, node_t* next)
{
	node_t* node = malloc(sizeof(node_t));
	if (NULL != node)
	{
		node->data = data;
		node->next = next;
	}

	return node;
}

list_t* CreateList(void)
{
	list_t* list = malloc(sizeof(list_t));
	if (NULL == list)
	{
		return NULL;
	}

	list->tail = NodeCreate(NULL, NULL);
	if (NULL == list->tail)
	{
		free(list); list = NULL;
		return NULL;
	}

	list->head = NodeCreate(NULL, list->tail);
	if (NULL == list->head)
	{
		free(list->tail); list->tail = NULL;
		free(list);  list = NULL;
		return NULL;
	}


	return list;
}

void DeleteList(list_t* lst)
{
	node_t* iter = lst->head;
	node_t* next_iter = NULL;

	assert(NULL != lst);

	do
	{
		next_iter = iter->next;
		iter->data = NULL;
		free(iter);
		iter = next_iter;

	} while (iter != lst->tail);

	/* Destroy dummy node and release its memory */
	free(iter);

	free(lst);
}

/******************************************************************************/
/*                        Public functions Implementation                     */
/******************************************************************************/

void* PopBackList(list_t* lst)
{
	node_t* iter = lst->head;
	node_t* iter_temp = NULL;

	assert(lst);

	if (iter->next == lst->tail)
	{
		iter->data = NULL;
		return;
	}

	while (iter->next != lst->tail)
	{
		iter_temp = iter;
		iter = iter->next;
	}

	iter_temp->next = lst->tail;
	free(iter);
	iter = NULL;

	return iter_temp->data;
}



node_t* PushBackList(list_t* lst, const void* data)
{
	node_t* new_iter, * t;
	assert(lst);
	/*if the list is empty*/
	if (SLLIsEmpty(lst))
	{
		lst->head->data = (void*)data;
		return lst->head;
	}

	new_iter = malloc(sizeof(node_t));
	if (NULL == new_iter)
	{
		return NULL;
	}

	new_iter->data = lst->tail->data;
	new_iter->next = lst->tail->next;
	lst->tail->data = (void*)data;
	lst->tail->next = new_iter;
	t = lst->tail;
	lst->tail = new_iter;

	return t;
}


int IsEmptyList(const list_t* lst)
{
	if (NULL == lst->head->data)
	{
		return 1;
	}

	return 0;
}
size_t SizeList(const list_t* lst)
{
	size_t count = 0;
	node_t* iter = NULL;

	assert(lst);

	if (IsEmptyList(lst))
	{
		return count;
	}

	iter = lst->head;
	while (iter->next != lst->tail)
	{
		++count;
		iter = iter->next;
	}
	++count;
	return count;
}

void ForEach(list_t* lst, void (*action)(int data))
{
node_t* iter = lst->head;

assert(lst);

while (iter != lst->tail)     /*didnt reach the end*/
{
	action(iter->data);

		iter = iter->next;
}
}

/*************************************************************************/






















