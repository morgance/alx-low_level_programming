#include <stdio.h>

/**
 * main - Prints the add of the even-valued
 * fibonacci numbers.
 *
 * Return: Always 0.
 */
int main(void)
{
	long int n1, n2, n3, n4;

	n1 = 1;
	n2 = 2;
	n3 = n4 = 0;
	while (n3 <= 4000000)
	{
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		if ((n1 % 2) == 0)
		{
			n4 += n1;
		}
	}
	printf("%ld\n", n4);
	return (0);
}
