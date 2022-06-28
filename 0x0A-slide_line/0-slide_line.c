#include "slide_line.h"
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
		slide_line_left();

	if (direction == SLIDE_RIGHT)
		slide_line_right();

	return (1);
}
