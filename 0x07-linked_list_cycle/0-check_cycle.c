#include "lists.h"

/**
 * check_cycle - check if theres a cycle
 * @list: pointer
 * Return: 0 or 1 if cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *by1, *by2;

	if (!list || !(list->next))
		return (0);

	by1 = list;
	by2 = list->next;

	while (by1 && by1->next && by2 && by2->next)
	{
		if (by1 == by2)
		{
			return (1);
		}
		else
		{
			by1 = by1->next;
			by2 = by2->next->next;
		}
	}

	return (0);
}
