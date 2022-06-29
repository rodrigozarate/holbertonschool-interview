#include <stdio.h>
#include <stddef.h>
#include "slide_line.h"

/**
* slide_line_left - slide to the left
* @line: array
* @size: size of the array
*/
static void slide_line_left(int *line, size_t size)
{
	int i = 0;
	int j = 0;
	int k = 0;

	for (;i < (int)size; i++)
	{
		if (line[i] == 0)
		{
			j++;
		}
		else
		{
			line[k] = line[j];
			if (k != j)
			{
				line[j] = 0;
			}
			j++;
			k++;
		}
	}
}

/**
* merge_line_left - merge to the left
* @line: array
* @size: size of the array
*/
static void merge_line_left(int *line, size_t size)
{
	int i = 0;

	for (;i < (int)size; i++)
	{
		if (i + 1 < (int)size)
		{
			if (line[i] == line[i + 1])
			{
				line[i] = line[i] * 2;
				line[i + 1] = 0;
			}
		}
	}
	slide_line_left(line, size);
}

/**
* slide_line_right - slide and merge to the right
* @line: array
* @size: size of the array
*/
static void slide_line_right(int *line, size_t size)
{
	int i = (int)size - 1;
	int j = (int)size - 1;
	int k = (int)size - 1;

	for (;i >= 0; i--)
	{
		if (line[i] == 0)
		{
			j--;
		}
		else
		{
			line[k] = line[j];
			if (k != j)
                        {
				line[j] = 0;
			}
			j--;
			k--;
		}
	}

}

/**
* merge_line_left - merge to the left
* @line: array
* @size: size of the array
*/
static void merge_line_right(int *line, size_t size)
{
	int i = (int)size - 1;

	for (;i >= 0; i--)
	{
		if (i - 1 >= 0)
		{
			if (line[i] == line[i - 1])
			{
				line[i] = line[i] * 2;
				line[i - 1] = 0;
			}
		}
	}
	slide_line_right(line, size);
}

/**
* slide_line - mock 2048 game behavior
* @line: pointer
* @size: size of the array
* @direction: L = 0 or R = 1
* Return: True or False
*/
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || size == 0)
		return (0);

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	{
		return (0);
	}

	if ((int)size == 1)
		return (1);

	if (direction == SLIDE_LEFT)
	{
		slide_line_left(line, size);
		merge_line_left(line, size);
	}

	if (direction == SLIDE_RIGHT)
	{
		slide_line_right(line, size);
		merge_line_right(line, size);
	}

	return (1);
}
