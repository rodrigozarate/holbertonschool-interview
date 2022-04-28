#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - insert a new node
 * @head: double pointer
 * @n: int of the list
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
			return(NULL);
	newnode->n = number;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
		printf("here i m \n");
	}
	while (nodeposition->next != NULL)
	{
		printf("pre got n: %d \n", nodeposition->n);
		
		/* walk nodes until next is mayor */
		if (number > nodeposition->n)
		{
			printf("mayor n: %d \n", nodeposition->n);
			nodeprev = nodeposition;
			nodeposition = nodeposition->next;
			printf("post mayor n: %d \n", nodeposition->n);	
		}
		else
		{
			/* disconect nodes */
			newnode->next = nodeposition;
			/* connect next to freed node in chain */
			nodeprev->next = newnode;
			return(newnode);
		}
		/* connect new node to prev */
		printf("got n: %d \n", nodeposition->n);
		
	}
	return(newnode);
}
