#include "main.h"
/**
 * set_bit - sets the value of bit to 1 at a given index
 * @n:this is the bit
 * @index:where the bit is taken
 *
 * Return:1 if it works or -1 if unsuccesful
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i;

	if (index > 63)
		return (-1);

	i = 1 << index;
	*n = (*n | i);

	return (1);
}
