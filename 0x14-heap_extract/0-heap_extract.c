#include "binary_trees.h"
/* malloc free */
#include <stdlib.h>


/**
 * BTQP - adds member to rear
 * @queue: pointer to head
 * @node: pointer to a node
 * Return: pointer
 */
bt_node_queue_t *BTQP(bt_node_queue_t **queue, binary_tree_t *node)
{
	bt_node_queue_t *temp, *new = NULL;

	if (!queue || !node)
		return (NULL);

	new = malloc(sizeof(bt_node_queue_t));
	if (!new)
		return (NULL);
	new->node = node;
	new->next = NULL;

	if (!*queue)
		*queue = new;
	else
	{
		temp = *queue;
		while (temp && temp->next)
			temp = temp->next;
		temp->next = new;
	}

	return (new);
}


/**
 * BTQA - deletes first member
 * @queue: pointer to head
 */
void BTQA(bt_node_queue_t **queue)
{
	bt_node_queue_t *temp;

	if (!queue || !*queue)
		return;

	temp = *queue;
	*queue = (*queue)->next;
	free(temp);
}


/**
 * lILO - lilo
 * @root: pointer to root
 * Return: pointer to the last node
 */
heap_t *lILO(heap_t *root)
{
	heap_t *last = NULL;
	bt_node_queue_t *queue = NULL;

	if (!root)
		return (NULL);

	queue = BTQP(&queue, root);
	if (!queue)
		return (NULL);

	while (queue)
	{
		if ((queue->node->left &&
		     !BTQP(&queue, queue->node->left)) ||
		    (queue->node->right &&
		     !BTQP(&queue, queue->node->right)))
		{
			while (queue)
				BTQA(&queue);
			return (NULL);
		}

		if (!queue->next)
		{
			if (queue->node->left)
				last = queue->node->left;
			else
				last = queue->node;
		}

		BTQA(&queue);
	}

	return (last);
}


/**
 * maxHeapSiftDown - Reconstruct
 * @root: pointer to root
 */
void maxHSD(heap_t *root)
{
	heap_t *temp = NULL, *next = NULL;
	int swap;

	temp = root;
	while (temp && temp->left)
	{
		/* defaults to sifting down if parent == max child */
		/* and to left if left == right */
		if (!temp->right ||
		    temp->left->n - temp->right->n >= 0)
		{
			if (temp->n - temp->left->n <= 0)
				next = temp->left;
			else
				break;
		}
		else if (temp->n - temp->right->n <= 0)
			next = temp->right;
		else
			break;

		if (next)
		{
			swap = temp->n;
			temp->n = next->n;
			next->n = swap;
		}

		temp = next;
	}
}


/**
 * heap_extract - extacts the integer value at the root
 * @root: double pointer to root node
 * Return: extracted integer
 */
int heap_extract(heap_t **root)
{
	heap_t *last = NULL;
	int extract;

	if (root == NULL || *root == NULL)
		return (0);

	last = lILO(*root);
	if (!last)
		return (0);

	extract = (*root)->n;
	(*root)->n = last->n;

	maxHSD(*root);

	if (last->parent)
	{
		if (last->parent->left == last)
			last->parent->left = NULL;
		else if (last->parent->right == last)
			last->parent->right = NULL;
	}

	if (last == *root)
		*root = NULL;
	free(last);

	return (extract);
}
