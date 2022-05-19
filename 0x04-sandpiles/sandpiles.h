#ifndef _SANDPILES_
#define _SANDPILES_

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void own_print_grid(int grid[3][3]);
void reduce(int grid[3][3]);
void distribute(int grid[3][3], int i, int j);
int validate(int grid[3][3]);

#endif /* _SANDPILES_ */
