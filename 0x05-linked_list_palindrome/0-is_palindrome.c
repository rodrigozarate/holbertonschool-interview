#include "lists.h"

/**
 * is_palindrome - determine if given list is palindrome
 * @head: double pointer
 * Return: 1 if is palidrome 0 if not
 */
int is_palindrome(listint_t **head)
{
	int result = 0;
	listint_t *copy_list;
	listint_t *actualnode;

	actualnode = *head;

	copy_list = NULL;
	/* insert nodes in head to produce a reverse list */
	while (actualnode != NULL)
	{
		insert_node_head(&copy_list, actualnode->n);
		actualnode = actualnode->next;
	}
	/* traverse nodes and compare if both values are equal */
	result = compare_lists(*head, copy_list);

	free_listint(copy_list);

	return (result);
}

/**
 * insert_node_head - insert node in head
 * @head: pointer
 * @n: int value
 * Return: new node pointer
 */
listint_t *insert_node_head(listint_t **head, const int n)
{
	listint_t *newnode;
	listint_t *actualnode;

	actualnode = *head;

	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
		return (NULL);

	newnode->n = n;
	newnode->next = NULL;

	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		newnode->next = actualnode;
		*head = newnode;
	}
	return (newnode);
}

/**
 * compare_lists - compare lists
 * @head: pointer
 * @copy_list: pointer
 * Return: 1 if theyre always the same
 */
int compare_lists(listint_t *head, listint_t *copy_list)
{
	listint_t *list1;
	listint_t *list2;
	int f = 1;

	list1 = head;
	list2 = copy_list;

	while (list1)
	{
		if (list1->n == list2->n)
			;
		else
		{
			f = 0;
			return (f);
		}
		list1 = list1->next;
		list2 = list2->next;
	}
	return (f);
}
