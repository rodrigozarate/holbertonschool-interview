/**
 * is_palindrome - check for palindromation
 * @n: int
 * Return: 0 or 1
 */

int is_palindrome(unsigned long n)
{
	unsigned long le;
	unsigned long patras = 0;
	unsigned long pata;
	int gato = 0;

	le = n;
	while (le != 0)
	{
		pata = le % 10;
		patras = patras * 10 + pata;
		le /= 10;
	}
	if (patras == n)
	{
		gato = 1;
	}
	return (gato);
}
