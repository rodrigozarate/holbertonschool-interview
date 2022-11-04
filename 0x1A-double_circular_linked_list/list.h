#ifndef H_LIST_H
#define H_LIST_H

/**
 * struct List - doubly linked list
 * @str: string - (malloc'ed string)
 * @prev: pointer to the previous node
 * @next: pointer to the next node
 *
 * Description: doubly linked list node structure
 * for Holberton project
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* H_LIST_H */
