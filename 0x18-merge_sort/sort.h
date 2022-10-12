#ifndef _H_SORT_
#define _H_SORT_

#include <stddef.h>

void print_array(const int *array, size_t size);
void Output(int *array, int indexA, int indexB);
void Duplicate(int *source, int *destiny, int indexA, int indexB);
void TDMerge(int *source, int *destiny, int indexA, int indexH, int indexB);
void SplitMergeTD(int *source, int *destiny, int indexA, int indexB);
void merge_sort(int *array, size_t size);

#endif
