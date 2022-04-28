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
	int flag = 0;

	newnode = malloc(sizeof(listint_t));
		if (newnode == NULL)
			return (NULL);
	newnode->n = number;

	if (*head == NULL || (*head)->n > number)
	{
		newnode->next = *head;
		*head = newnode;
		return (newnode);
	}
	while (nodeposition->next != NULL)
	{
		if (nodeposition->next->n > number)
		{
			newnode->next = nodeposition->next;
			nodeposition->next = newnode;
			return (newnode);
			flag = 1;
		}
		nodeposition = nodeposition->next;
	}
	if (flag == 0)
	{
		newnode->next = nodeposition->next;
		nodeposition->next = newnode;
		return (newnode);
	}
	return (newnode);
}
