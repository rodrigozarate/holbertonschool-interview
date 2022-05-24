#include "lists.h"

/**
 * is_palindrome - determine if given list is palindrome
 * @head: double pointer
 * Return: 1 if is palidrome 0 if not
 */
int is_palindrome(listint_t **head)
{
	/* count nodes to determine odd or even */
	int n = 0;
	int result = 0;
	listint_t *copy_list;
	listint_t *actualnode;
	int flag = 0;

	actualnode = *head;
	n = count_nodes(*head);

	if (n % 2 == 0)
		flag = 1;

	copy_list = NULL;

	while (actualnode != NULL)
	{
		printf("la n:%i\n", actualnode->n);
		insert_node_head(&copy_list, actualnode->n);
		actualnode = actualnode->next;
	}

	result = compare_lists(*head, copy_list);

	if (result == 1)
		flag = 1;
	else
		flag = 0;

	printf("Result = %i\n", result);

	printf("flag = %i\n", flag);


	free_listint(copy_list);
	
	return (flag);

	/* insert nodes in head to produce a reverse list */
	/* traverse nodes and compare if both values are equal */
}

/**
 * count_nodes - guess what, this functions count nodes
 * @head: pointer
 * Return: number of nodes
 */
int count_nodes(listint_t *head)
{
	unsigned int n = 0;

	while(head)
	{
		head = head->next;
		n++;
	}
	return (n);
}

/**
 * insert_node_head - insert node in head
 * @head: pointer
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
	printf("here 1 %i\n", n);

	if (*head == NULL)
	{
		printf("on NULL\n");
		*head = newnode;
	}
	else
	{
		printf("on next\n");
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
			printf("same \n");
		else
		{
			printf("NOT \n");
			f = 0;
			return (f);
		}

		printf("ene en head: %i\n", list1->n);
		printf("ene en copy: %i\n", list2->n);
		list1 = list1->next;
		list2 = list2->next;
		printf("----\n");
	}
	return (f);
}