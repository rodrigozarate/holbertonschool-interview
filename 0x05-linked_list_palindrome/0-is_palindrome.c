#include "lists.h"

int is_palindrome(listint_t **head)
{
	/* count nodes to determine odd or even */
	int n = 0;
	n = count_nodes(*head);
	return (n);

	/* insert nodes in head to produce a reverse list */
	/* traverse nodes and compare if both values are equal */
}

int count_nodes(listint_t *head)
{
	unsigned int n = 0;

	while(head)
	{
		head = head->next;
		n++;
	}
	printf("nodes: %d", n);
	return (n);
}
