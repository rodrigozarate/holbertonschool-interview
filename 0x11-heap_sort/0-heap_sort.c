#include "sort.h"

/**
* indexP - Returns index parent
* @indx: index
* Return: int
*/
int indexP(int indx)
{
	return ((indx - 1) / 2);
}

/**
* indexLChild - Returns index of left child
* @indx: index
* Returns:int
*/
int indexLChild(int indx)
{
	return ((2 * indx) + 1);
}

/**
* doHeap - order array in heap way
* @array: array
* @size: size of array
*/
void doHeap(int *array, size_t size)
{
	int start;
	start = indexP(size - 1);

	while (start >= 0)
	{
		siftDown(array, size, start, size - 1);
		start--;
	}
}

/**
* siftDown - moves values down
* @array: array
* @size: size
* @start: start
* @end: end
*/
void siftDown(int *array, size_t size, int start, int end)
{
	int root, swap, temp, child;
	root = start;

	while (indexLChild(root) <= end)
	{
		child = indexLChild(root);
		swap = root;

		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap != root)
		{
			temp = array[root];
			array[root] = array[swap];
			array[swap] = temp;
			print_array(array, size);
			root = swap;
		}
		else
			return;
	}
}

/**
* heap_sort - sorts an array using heapsort
* @array: array
* @size: size
*/
void heap_sort(int *array, size_t size)
{
	int indexEnd, temp;

	if (!aray || size < 2)
		return;

	doHeap(array, size);

	inexEnd = (int)size - 1;
	while (indexEnd > 0)
	{
		temp = array[indexEnd];
		array[indexEnd] = array[0];
		array[0] = temp;
		print_array(array, size);
		indexEnd--;
		siftDown(array, size, 0, indexEnd);
	}
}
