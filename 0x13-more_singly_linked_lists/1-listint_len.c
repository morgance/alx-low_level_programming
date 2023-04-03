#include "lists.h"
/**
 * listint_len - returns the number of elements in linked list
 * @h:head of the list
 *
 * Return:number of nodes
 */
size_t listint_len(const listint_t *h)
{
	size_t prim = 0;

	while (h != NULL)
	{
		h = h->next;

		prim++;
	}
	return (prim);
}
