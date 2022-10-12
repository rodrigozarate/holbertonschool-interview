#include "sort.h"
#include <stdlib.h>
#include <stdio.h>


/**
* Output - Prints output
* @array: int pointer
* @indexA: int
* @indexB: int
*/
void Output(int *array, int indexA, int indexB)
{
	int i;

	if (!array)
		return;

	for (i = indexA; i < indexB; i++)
		if (i < indexB - 1)
			printf("%i, ", array[i]);
		else
			printf("%i\n", array[i]);
}

/**
* Duplicate - duplicate array
* @source: int
* @destiny: int
* @indexA: int
* @indexB: int
*/
void Duplicate(int *source, int *destiny, int indexA, int indexB)
{
	int i;

	if (!source || !destiny)
		return;

	for (i = indexA; i < indexB; i++)
		destiny[i] = source[i];
}

/**
* TDMerge - Join to be happy
* @source: int pointer
* @destiny: int pointer
* @indexA: int alfa
* @indexH: int half
* @indexB: int omega
*/
void TDMerge(int *source, int *destiny, int indexA, int indexH, int indexB)
{
	int i, j, k;

	if (!source || !destiny)
		return;

	i = indexA, j = indexH;

	printf("Merging...\n");
	printf("[left]: ");
	Output(source, indexA, indexH);
	printf("[right]: ");
	Output(source, indexH, indexB);

	for (k = indexA; k < indexB; k++)
	{

		if (i < indexH && (j >= indexB || source[i] <= source[j]))
		{
			destiny[k] = source[i];
			i++;
		}
		else
		{
			destiny[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	Output(destiny, indexA, indexB);
}

/**
* SplitMergeTD - divide and conquer
* @source: int pointer
* @destiny: int pointer
* @indexA: int
* @indexB: int
*/
void SplitMergeTD(int *source, int *destiny, int indexA, int indexB)
{
	int indexH;

	if (!source || !destiny)
		return;

	if (indexB - indexA < 2)
		return;

	indexH = (indexA + indexB) / 2;

	SplitMergeTD(destiny, source, indexA, indexH);
	SplitMergeTD(destiny, source, indexH, indexB);
	TDMerge(source, destiny, indexA, indexH, indexB);
}


/**
* merge_sort - sort integers in array
* @array: int
* @size: size of array
*/
void merge_sort(int *array, size_t size)
{
	int *arr_copy;

	if (!array || size < 2)
		return;

	arr_copy = malloc(sizeof(int) * size);
	if (!arr_copy)
		return;

	Duplicate(array, arr_copy, 0, size);
	SplitMergeTD(array, arr_copy, 0, size);
	Duplicate(arr_copy, array, 0, size);

	free(arr_copy);
}
