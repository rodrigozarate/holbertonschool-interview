#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a new node
 * @head: double pointer
 * @number: int of the list
 * Return: pointer of newnode or NULL if fail
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *newnode;
	listint_t *nodeposition;
	int flag = 0;

	nodeposition = *head;

	newnode = malloc(sizeof(listint_t));
		if (newnode == NULL)
			return (NULL);
	newnode->n = number;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		return (newnode);
	}
	while (nodeposition->next != NULL)
	{
		if (number > nodeposition->next->n)
		{
			nodeposition = nodeposition->next;
			flag = 1;
		}
		else
		{
			newnode->next = nodeposition->next;
			nodeposition->next = newnode;
			return (newnode);
		}
	}
	if (flag == 0)
	{
		newnode->next = nodeposition->next;
		nodeposition->next = newnode;
		return (newnode);
	}
	return (newnode);
}
