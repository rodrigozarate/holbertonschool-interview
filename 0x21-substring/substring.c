#include "substring.h"

/**
 * find_substring - finds a substring from array words in a string
 * @s: string -> array
 * @words: array
 * @nb_words: size
 * @n: pointer
 * Return: int
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int len, len_word, x;
	int j, i = 0;
	int *strings, *memw;

	if (!s)
		return (NULL);

	*n = 0;
	len = strlen(s);
	len_word = strlen(words[0]);

*memw = malloc(nb_words * sizeof(int));
	strings = malloc(len * sizeof(int));

	while (i <= (len - nb_words * len_word))
	{
		for (j = 0; j < nb_words; j++)
			memw[j] = 0;
		for (j = 0; j < nb_words; j++)
		{
			for (x = 0; x < nb_words; x++)
			{
				if (memw[x] == 0 && strncmp(s + i + j *
					len_word, words[x], len_word) == 0)
				{
					memw[x] = 1;
					break;
				}
			}
			if (x == nb_words)
				break;
		}
		if (j == nb_words)
			strings[(*n)++] = i;
		i++;
	}
	free(memw);
	return (strings);
}
