#include "regex.h"
#include <stdio.h>


/**
 * regexPiece - test regex pieces
 * @str: string
 * @pattern: string pattern
 * @str_end: pointer
 * @pttrn_end: pointer
 * Return: 1 or 0 if error
 */
int regexPiece(char const *str, char const *pattern,
				const char **str_end, const char **pttrn_end)
{
	const char *pttrn_start;
	int match = 0;

	if (!str || !pattern)
	{
		fprintf(stderr, "regexPiece: NULL parameter(s)\n");
		return (0);
	}

	while (*str)
	{
		while (*str && *str != *pattern)
			str++;

		pttrn_start = pattern;

		while (*str == *pattern && *pattern != '.' &&
		       *pattern != '*' && *pattern != '\0' &&
		       *(pattern + 1) != '*')
		{
			str++;
			pattern++;
		}

		if (*pattern == '.' || *pattern == '*' ||
		    *pattern == '\0' || *(pattern + 1) == '*')
		{
			*pttrn_end = pattern;
			*str_end = str;
			match = 1;
		}

		pattern = pttrn_start;
	}

	return (match);
}


/**
 * regex_match - match regex against str
 * @str: string
 * @pattern: pattern
 * Return: 1 or 0 if error
 */
int regex_match(char const *str, char const *pattern)
{
	char repeat;
	const char *str_end = NULL, *pttrn_end = NULL;

	if (!str || !pattern)
	{
		fprintf(stderr, "regex_match: NULL parameter(s)\n");
		return (0);
	}

	while (*pattern)
	{
		if (*(pattern + 1) == '*')
		{
			if (*pattern == '.')
			{
				pattern += 2;
				if (regexPiece(str, pattern, &str_end, &pttrn_end))
				{
					str = str_end;
					pattern = pttrn_end;
				}
			}
			else
			{
				repeat = *pattern;
				pattern += 2;
				while (*str == repeat)
					str++;
			}
		}
		else if (*pattern == '.' || *pattern == *str)
		{
			pattern++;
			str++;
		}
		else
			break;
	}
	return (!(*str) && !(*pattern));
}
