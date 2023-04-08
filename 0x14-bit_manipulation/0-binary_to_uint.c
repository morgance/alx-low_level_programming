#include "main.h"

/**
 * binary_to_uint - converts binary number to unsigned int
 * @b:pointing to a string of 0 and 1 chars
 *
 * Return:The converted number or 0
 * if theres one or more chars in a sring of b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i;
	int prim, rim;

	if (!b)
		return (0);


	i = 0;
	for (prim = 0; b[prim] != '\0'; prim++)
		;

	for (prim--, rim = 1; prim >= 0; prim--, rim *= 2)
	{
		if (b[prim] != '0' && b[prim] != '1')
		{
			return (0);
		}

		if (b[prim] & 1)
		{
			i += rim;
		}
	}
	return (i);
}
