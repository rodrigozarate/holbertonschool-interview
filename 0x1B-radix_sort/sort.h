#ifndef _RADIX_SORT_
#define _RADIX_SORT_

#include <stddef.h>

void print_array(const int *array, size_t size);
int maxInt(int *array, size_t size);
void doBuckets(int *bucketSize, int **buckets);
void mixArray(int *array, size_t size, int **buckets, int *bucketSize);
void radix_sort(int *array, size_t size);

#endif /* _RADIX_SORT_ */
