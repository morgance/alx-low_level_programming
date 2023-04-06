#include "main.h"

/**
 * binary_to_uint - converts binary number to unsigned int
 * @b:pointing to a string of 0 and 1 chars
 *
 * Return:The converted number or 0 if theres one or more chars in a sring of b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i;
	int prim, rim;

	if (b == NULL)
		return (NULL);

	i = 0;

	for (prime = 0; b[prime] != '\0'; prime++)
		;

	for (prime--, rim = 1; prime >= 0; prime--, rim *=2)
	{
		if (b[prim] != '0' && b[prim] != '1')
		{
			return (0)
		}

		if (b[prim] & 1)
		{
			i += rim;
		}
	}
	
	return (i);
}
