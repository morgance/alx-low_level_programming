#include "main.h"
#include <stdlib.h>
/**
 * array_range - creates an array of integers
 * @min:minimum value
 * @max:maximum value
 *
 * Return:the pointer to the newly created array
 * If min > max, return NULL
 * If malloc fails, return NULL
 */
int *array_range(int min, int max)
{
	int *aj;
	int i;

	if (min > max)
		return (NULL);

	for (i = 0; min <= max; i++, min++)
		aj[i] = min;
	
	return (aj);
}
		
