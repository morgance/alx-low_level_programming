#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a
 * dlistint_t linked list
 *
 * @head: head of the list
 * @index: index of the new node
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *pro;
	dlistint_t *prim;
	unsigned int i;

	pro = *head;

	if (pro != NULL)
		while (pro->prev != NULL)
			pro = pro->prev;

	i = 0;

	while (pro != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = pro->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				prim->next = pro->next;

				if (pro->next != NULL)
					pro->next->prev = prim;
			}

			free(pro);
			return (1);
		}
		prim = pro;
		pro = pro->next;
		i++;
	}

	return (-1);
}
