#include "slide_line.h"

/**
* slide_line_left - slide and merge to the left
* @line: array
* @size: size of the array
*/
static void slide_line_left(int *line, size_t size)
{
        /* walk array */
        /* move ints to desplace zeros */
        /* if pair of equal ints merge */
        /* displace again and wait */
}

/**
* slide_line_right - slide and merge to the right
* @line: array
* @size: size of the array
*/
slide_line_right(line, size)
{
	/* walk array */
	/* move ints to desplace zeros */
	/* if pair of equal ints merge */
	/* displace again and wait */
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

	if (direction != SLIDE_LEFT || direction != SLIDE_RIGHT)
		return (0);

	if ((int)size == 1)
		return (1);

	if (direction == SLIDE_LEFT)
		slide_line_left(line, size);

	if (direction == SLIDE_RIGHT)
		slide_line_right(line, size);

	return (1);
}
