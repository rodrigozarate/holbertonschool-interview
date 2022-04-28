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
	listint_t *nodeprev;

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
		if (number > nodeposition->n)
		{
			nodeprev = nodeposition;
			nodeposition = nodeposition->next;
		}
		else
		{
			newnode->next = nodeposition;
			nodeprev->next = newnode;
			return (newnode);
		}
	}
	return (newnode);
}
