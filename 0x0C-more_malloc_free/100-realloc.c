#include "main.h"
#include <stdlib.h>
/**
 * _realloc - reallocates a memory block
 * @ptr:pointer to the memory previously allocated with a call to malloc
 * @old_size:size, in bytes, of the allocated space for ptr
 * @new_size:the new size, in bytes of the new memory block
 *
 * Return:ptr
 * If new_size == old_size do not do anything and return ptr
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		ptr = malloc(new_size);

	if (new_size == old_size)
		return (ptr);

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}
