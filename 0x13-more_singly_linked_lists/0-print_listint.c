#include "lists.h"
/**
 * print_listint - prints all elements on a list
 * @h:head of the list
 *
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t prom = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);

		prom++;

		h = h->next;


	}

	return (prom);
}
