#ifndef _BTH_AVL_
#define _BTH_AVL_

#include <stddef.h>

/**
* struct binary_tree_s - Binary tree node
*
* @n: Integer stored in the node
* @parent: Pointer to the parent node
* @left: Pointer to the left child node
* @right: Pointer to the right child node
*/
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

typedef struct binary_tree_s avl_t;

binary_tree_t *create_node(binary_tree_t *parent, int value);
avl_t *avl_helper(int *array, int lindex, int rindex, avl_t *parent);
avl_t *sorted_array_to_avl(int *array, size_t size);

#endif /* _BTH_AVL_ */
