/*
* Author: Rodrigo Zarate
* Date: may 17 2022
*/

#include "sandpiles.h"

/**
 * sandpiles_sum - sum sandpiles
 * @grid1: stable grid
 * @grid2: sum grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int flag = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	flag = validate(grid1);

	while (flag)
	{
		reduce(grid1, grid2);
		distribute(grid1, grid2);
		flag = validate(grid1);
	}
}

/**
 * reduce - reduce grid
 * @grid1: grid stable
 * @grid2: control
 */
void reduce(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] >= 4)
			{
				grid1[i][j] = grid1[i][j] - 4;
				grid2[i][j] = 1;
			}
			else
			{
				grid2[i][j] = 0;
			}
		}
	}
}

/**
 * distribute - distribute grid
 * @grid1: grid stable
 * @grid2: control
 */
void distribute(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] == 1)
			{
				if (i - 1 >= 0)
				{
					grid1[i - 1][j]++;
				}
				if (j - 1 >= 0)
				{
					grid1[i][j - 1]++;
				}
				if (i + 1 < 3)
				{
					grid1[i + 1][j]++;
				}
				if (j + 1 < 3)
				{
					grid1[i][j + 1]++;
				}
			}
		}
	}
}

/**
 * validate - validate extra grains
 * @grid: the grid
 * Return: 1 if true or 0 if false
 */
int validate(int grid[3][3])
{
	int i, j;
	int flag = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				flag = 1;
			}
		}
	}
	if (flag)
	{
		own_print_grid(grid);
	}
	return (flag);
}

/**
 * own_print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
void own_print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
