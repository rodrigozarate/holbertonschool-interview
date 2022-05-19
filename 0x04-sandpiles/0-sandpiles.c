/*
* Author: Rodrigo Zarate
* Date: may 17 2022
*/

#include "sandpiles.h"

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
	printf("gato\n");
	flag = validate(grid1);
	printf("fin gato\n");

	while (flag)
	{
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
		printf(" resta \n");
		printf("grid1:\n");
		own_print_grid(grid1);
		printf("grid2:\n");
		own_print_grid(grid2);
		printf(" resta \n");

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid2[i][j] == 1)
				{
					if (i - 1 >= 0)
					{
						printf("bottom -");
						grid1[i - 1][j]++;
					}

					if (j - 1 >= 0)
					{
						printf("right -");
						grid1[i][j - 1]++;
					}
					if (i + 1 < 3)
					{
						printf("up -");
						grid1[i + 1][j]++;
					}

					if (j + 1 < 3)
					{
						printf("left -");
						grid1[i][j + 1]++;
					}
				}
			}
		}
		printf(" suma \n");
		printf("grid1 ---\n");
		own_print_grid(grid1);
		printf("grid2 ---\n");
		own_print_grid(grid2);
		printf(" suma \n");

		flag = validate(grid1);
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
	printf("--------------------------------\n");
	own_print_grid(grid);
	printf("--------------------------------\n");
	return (flag);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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
