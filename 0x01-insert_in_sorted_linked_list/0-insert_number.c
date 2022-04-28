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
	listint_t *newnode, *nodeposition = *head;

	newnode = malloc(sizeof(*newnode));
	if (newnode == NULL)
		return (NULL);
	newnode->n = number;

	if (*head == NULL || (*head)->n > number)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	for (; nodeposition != NULL ; nodeposition = nodeposition->next)
	{
		if (nodeposition->next == NULL || nodeposition->next->n > number)
		{
			newnode->next = nodeposition->next;
			nodeposition->next = newnode;
			break;
		}
	}
	return (newnode);
}
