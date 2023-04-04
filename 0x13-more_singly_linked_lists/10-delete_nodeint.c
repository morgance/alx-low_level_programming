#include "lists.h"
/**
 * delete_nodeint_at_index - deletes the  node at index of a list
 * @head:head of a list
 * @index:the node that should be deleted
 *
 * Return: 1 if successful and -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *j;
	listint_t *next;

	j = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && j != NULL; i++)
		{
			j = j->next;
		}
	}

	if (j == NULL || (j->next == NULL && index != 0))
	{
		return (-1);
	}

	next = j->next;

	if (index != 0)
	{
		j->next = next->next;
		free(next);
	}
	else
	{
		free(j);
		*head = next;
	}

	return (1);
}
