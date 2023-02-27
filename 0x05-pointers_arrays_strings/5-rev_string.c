#include "main.h"

/**
  * rev_string - Reverses a string
  * @s: The string to be modified
  *
  * Return: void
  */
void rev_string(char *s)
{
	char *a, *b, c;
	int i, count;
	int length = 0;

	for (i = 0; s(i); i++)
	{
		length++;
	}
	count = length;

	a = s;
	b = s;

	for (i = 0; i < count - 1; i++)
	{
		b++;
	}

	for (i = 0; i < count / 2; i++)
	{
		c = *a;
		*a = c;

		a++;
		b--;
	}
}
