#include "sort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * maxInt - find max int in array
 * @array: array
 * @size: size of array
 * Return: max int
*/
int maxInt(int *array, size_t size)
{
	int max;
	size_t i;

	if (!array)
	{
		fprintf(stderr, "maxInt: array error\n");
		return (0);
	}

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * doBuckets - do the buckets
 * @bucketSize: size of buckets
 * @buckets: double pointer
*/
void doBuckets(int *bucketSize, int **buckets)
{
	int *bucket;
	int i;

	if (!bucketSize || !buckets)
	{
		fprintf(stderr, "doBuckets: error\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < 10; i++)
	{
		bucket = malloc(sizeof(int) * bucketSize[i]);
		if (!bucket)
		{
			fprintf(stderr, "doBuckets: malloc fail\n");
			for (; i > -1; i--)
				free(buckets[i]);
			free(buckets);
			exit(EXIT_FAILURE);
		}
		buckets[i] = bucket;
	}
}

/**
 * mixArray - put all together
 * @array: array
 * @size: size
 * @buckets: double pointer
 * @bucketSize: size needed
*/
void mixArray(int *array, size_t size, int **buckets, int *bucketSize)
{
	int i, j, k;

	for (i = 0, k = 0; i < 10; i++)
	{
		for (j = 0; j < bucketSize[i]; j++, k++)
			array[k] = buckets[i][j];
	}

	print_array(array, size);

	for (i = 0; i < 10; i++)
		free(buckets[i]);
}

/**
* radix_sort - radix sort
* @array: array
* @size: size
*/
void radix_sort(int *array, size_t size)
{
	int **buckets;
	int bucketSize[10], bucketLevel[10];
	int max, intlong, pass, div, digit;
	size_t i;

	if (!array || size < 2)
		return;

	buckets = malloc(sizeof(int *) * 10);
	if (!buckets)
		exit(EXIT_FAILURE);

	max = maxInt(array, size);
	for (intlong = 0; max > 0; intlong++)
		max /= 10;

	for (pass = 0, div = 1; pass < intlong; pass++, div *= 10)
	{
		memset(bucketSize, 0, sizeof(int) * 10);
		memset(bucketLevel, 0, sizeof(int) * 10);

		for (i = 0; i < size; i++)
		{
			digit = (array[i] / div) % 10;
			bucketSize[digit]++;
		}
		doBuckets(bucketSize, buckets);

		for (i = 0; i < size; i++)
		{
			digit = (array[i] / div) % 10;
			buckets[digit][bucketLevel[digit]] = array[i];
			bucketLevel[digit]++;
		}

		mixArray(array, size, buckets, bucketLevel);
	}
	free(buckets);
}
