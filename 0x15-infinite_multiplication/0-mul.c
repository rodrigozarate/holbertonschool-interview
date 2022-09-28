#include "holberton.h"
#include <stdlib.h>

/**
 * error - print error and error status
 * @status: error code
 */
void error(int status)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(status);
}

/**
 * makespace - init cero array of t_len size
 * @size: array size
 * Return:pointer
 */
unsigned int *makespace(size_t size)
{
	unsigned int *newarray = NULL;
	size_t i;

	newarray = malloc(sizeof(unsigned int) * size);
	if (!newarray)
		return (NULL);

	for (i = 0; i < size; i++)
		newarray[i] = 0;

	return (newarray);
}

/**
 * valid - check for only numbers in argv
 * @c: char to validate
 * Return: 1 ok or 0 if fail
 */
int valid(char *c)
{
	size_t i;

	for (i = 0; c[i]; i++)
	{
		if (c[i] < '0' || c[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * domult - multiplies two numbers
 * @resp: response array
 * @a_int: operand a
 * @a_len: size of array of operand a
 * @b_int: operand b
 * @b_len: size of array of operand b
 */
void domult(unsigned int *resp, char *a_int, size_t a_len,
			char *b_int, size_t b_len)
{
	int i, j, sum;
	unsigned char d1, d2;

	if (resp == NULL || a_int == NULL || b_int == NULL)
		return;

	for (i = b_len - 1; i >= 0; i--)
	{
		sum = 0;
		d1 = a_int[i] - '0';

		for (j = b_len - 1; j >= 0; j--)
		{
			d2 = b_int[j] - '0';
			sum += resp[i + j + 1] + (d1 * d2);
			resp[i + j + 1] = sum % 10;
			sum /= 10;
		}

		if (sum > 0)
			resp[i + j + 1] += sum;
	}
}

/**
 * main - multiplies two integers
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 98 on error
 */
int main(int argc, char **argv)
{
	size_t i, a_len, b_len, t_len;
	unsigned int *resp = NULL;

	if (argc != 3)
		error(98);

	if (!valid(argv[1] || !valid(argv[2])))
		error(98);

	/* save args into array */
	for (i = 0, a_len = 0; argv[1][i]; i++)
		a_len++;

	for (i = 0, b_len = 0; argv[2][i]; i++)
		b_len++;

	t_len = a_len + b_len;
	resp = makespace(t_len);
	/* multiply each int from a with b arrays */
	domult(resp, argv[1], a_len, argv[2], b_len);

	for (; i < t_len; i++)
		_putchar(resp[i] + '0');
	_putchar('\n');

	free(resp);

	return (0);
}
