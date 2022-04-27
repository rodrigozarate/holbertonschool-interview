#ifndef _INS_SLL_
#define _INS_SLL_

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

listint_t *insert_node(listint_t **head, int number);

#endif
