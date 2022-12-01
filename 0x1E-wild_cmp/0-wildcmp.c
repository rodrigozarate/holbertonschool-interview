#include "holberton.h"
#include <stdbool.h>
#include <stdio.h>


/**
 * rec_helper - recursive helper
 * @base: current position
 * @pattern: current postion in pattern string
 * @indx: count reference
 * Return: 1 if ok, else 0
 */
int rec_helper(char *base, char *pattern, int *indx)
{
	if (!base || !pattern || !indx)
		return (0);

	(*indx)++;

	if (*base == *pattern)
	{
		if (*(pattern + 1) == '\0' || *(pattern + 1) == '*')
			return (1);

		return  (rec_helper(base + 1, pattern + 1, indx));
	}

	return (0);
}


/**
 * wildcmp_helper - recursive helper to wildcmp
 * @base: current position
 * @pattern: current postion in pattern
 * @wildcard: flag for '*'
 * Return: 1 if ok, else 0
 */
int wildcmp_helper(char *base, char *pattern, bool wildcard)
{
	int offset = 0;

	if (!base || !pattern)
		return (0);

	if (*pattern == '*')
		return (wildcmp_helper(base, pattern + 1, true));

	if (*pattern == '?')
	{
		if (*base == '\0')
			return (0);

		return (wildcmp_helper(base + 1, pattern + 1, false));
	}

	if (wildcard)
	{
		if (*base == '\0')
			return (*pattern == '\0');

		if (*base == *pattern && rec_helper(base, pattern, &offset))
			return (wildcmp_helper(base + offset,
					 pattern + offset, false));

		return (wildcmp_helper(base + 1, pattern, true));
	}

	if (*base == *pattern)
	{
		if (*base == '\0')
			return (1);

		return (wildcmp_helper(base + 1, pattern + 1, false));
	}

	return (0);
}


/**
 * wildcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 1 if OK, else 0
 */
int wildcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
	{
		fprintf(stderr, "wildcmp: NULL parameter(s)\n");
		return (0);
	}

	return (_wildcmp(s1, s2, false));
}
