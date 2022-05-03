#include binary_trees.h
heap_t *heap_insert(heap_t **root, int value)
{
	/* if adress is null make root */
	if (*root == NULL)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	/* check for place to put the node according to MAX heap */
	/* validate if node must be swaped */
	/* validate if node is leaf */
	/* return new node */
}
