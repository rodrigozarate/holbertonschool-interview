#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
int indexP(int indx);
int indexLChild(int indx);
void doHeap(int *array, size_t size);
void siftDown(int *array, size_t size, int start, int end);
void heap_sort(int *array, size_t size);

#endif /* SORT_H */
