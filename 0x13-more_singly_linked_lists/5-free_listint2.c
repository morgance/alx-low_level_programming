#include "lists.h"
/**
 * free_listint2 - frees a list
 * @head:head of a list
 *
 * Return:nothing
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;
	listint_t *prim;

	if (head != NULL)
	{
		prim = *head;

		while ((temp = prim) != NULL)
		{
			prim = prim->next;

			free(temp);
		}
		*head = NULL;
	}
}
