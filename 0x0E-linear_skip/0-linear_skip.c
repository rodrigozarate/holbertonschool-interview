#include "search.h"

/**
* print_check - prints check round
* @index: index
* @value: int value
*/
void print_check(size_t index, int value)
{
	printf("Value checked at index [%lu] = [%i]\n",
		index, value);
}

/**
* print_found - prints indexes range
* @indexa: size_t index a
* @indexb: size_t index b
*/
void print_found(size_t indexa, size_t indexb)
{
	printf("Value found between indexes [%lu] and [%lu]\n",
		indexa, indexb);
}

/**
* linear_skip - skip search over ordered linked list
* @list: pointer
* @value: int to search for
* Return: pointer to first match or NULL
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *head = NULL, *prev = NULL;

	if (list == NULL)
		return (NULL);

	head = list;

	while (head && head->express && head->express->n < value)
	{
		print_check(head->express->index, head->express->n);
		head = head->express;
	}
	prev = head;

	while (prev && prev->next != prev->express)
		prev = prev->next;

	if (head->express)
	{
		print_check(head->express->index, head->express->n);
		print_found(head->index, head->express->index);
	}
	else
		print_found(head->index, prev->index);

	while (head != prev && head->n < value)
	{
		print_check(head->index, head->n);
		head = head->next;
	}
	print_check(head->index, head->n);

	if (head == prev)
		return (NULL);
	return (head);
}
