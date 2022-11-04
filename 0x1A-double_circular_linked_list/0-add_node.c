#include "list.h"
#include <stdlib.h>
#include <string.h>


/**
 * add_node_end - adds node to the end of a doubly circular linked list
 * @list: pointer to List
 * @str: string
 * Return: pointer to new node, or NULL
 */
List *add_node_end(List **list, char *str)
{
	List *new, *head, *tail;
	char *str_cpy = NULL;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));
	str_cpy = strdup(str);
	if (!new || !str_cpy)
		return (NULL);
	new->str = str_cpy;
	new->next = new;
	new->prev = new;
	head = *list;

	if (head)
	{
		if (!head->prev && !head->next)
		{
			head->prev = head->next = new;
			new->prev = new->next = head;
		}
		else
		{
			tail = head->prev;
			tail->next = new;
			new->next = head;
			head->prev = new;
			new->prev = tail;
		}
	}
	else
		*list = new;

	return (new);
}

/**
 * add_node_begin - adds node to the start of a doubly circular linked list
 *
 * @list: double pointer list
 * @str: string
 * Return: pointer to new node, or NULL
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *head, *tail;
	char *str_cpy = NULL;

	if (!list)
		return (NULL);

	new = malloc(sizeof(List));
	str_cpy = strdup(str);
	if (!new || !str_cpy)
		return (NULL);
	new->str = str_cpy;
	new->next = new;
	new->prev = new;
	head = *list;

	if (head)
	{
		if (!head->prev && !head->next)
		{
			head->prev = head->next = new;
			new->prev = new->next = head;
		}
		else
		{
			tail = head->prev;
			tail->next = new;
			new->next = head;
			head->prev = new;
			new->prev = tail;
		}
	}

	*list = new;
	return (new);
}
