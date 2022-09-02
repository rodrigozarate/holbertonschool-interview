#include "search_algos.h"
#include <stdio.h>

/**
* recursion - du the job
* @array: array
* @value: needle
* @right: max limit
* @left: min limit
* Return: index
*/
int recursion(int *array, int value, size_ left, size_t right)
{
	size_t mid, i;

	if (!array)
		return (-1);

	mid = (left + right) / 2;
	printf("Searching in array: ");
	for (i = left: i <= right; i++)
	{
		printf("%i%s", array[i], i == right ? "\n" : ", ");
	}

	if (array[left] == value)
		return ((int)left);

	if (array[left] != array[right])
	{
		if (array[mid] < value)
			return (recursion(array, value, mid + 1, right));

		if (array[mid] >= value)
			return (recursion(array, value, left, mid));
	}

	return (-1);
} 

/**
* advanced_binary - search for first match
* @array: pointer
* @size: size of array
* @value: needle
* Return: index
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;

	if (!array)
		return (-1);

	return (recursion(array, value, left, right));
}
