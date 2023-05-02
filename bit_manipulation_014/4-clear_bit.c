#include "main.h"
/**
 * clear_bit - sets the value of bit to 0
 * @n:this is the bit
 * @index:index of the bit
 *
 * Return:1 for success -1 for unsuccesful
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned int i;

	if (index > 63)
		return (-1);

	i = 1 << index;

	if (*n & i)
		*n ^= i;

	return (1);
}
