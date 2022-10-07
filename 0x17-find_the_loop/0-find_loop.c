#include "lists.h"


/**
 * find_listint_loop - finds the loop
 * @head: pointer
 * Return: pointer to node if loop of NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *hare;

	if (!head || !head->next)
		return (NULL);

	hare = tortoise = head;
	while (hare && hare->next)
	{
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = head;
			while (tortoise != hare)
			{
				tortoise = tortoise->next;
				hare = hare->next;
			}

			return (hare);
		}
	}

	return (NULL);
}
