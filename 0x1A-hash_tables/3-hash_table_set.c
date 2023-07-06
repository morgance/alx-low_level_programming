#include "hash_tables.h"

/**
 * hash_table_set - adds element to hash table
 * @ht: hash table
 * @key: key of hash table
 * @value: value
 * Return: 1 if successful  0 if fail
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node, *tmp;
	unsigned long int index;

	if (ht == NULL || key == NULL || strlen(key) == 0)
	return (0);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];

	while (tmp != NULL)
	{
	if (strcmp(key, tmp->key) == 0)
	{
	free(tmp->value);
	tmp->value = strdup(value);
	return (1);
	}
	tmp = tmp->next;
	}

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	return (0);

	node->key = strdup(key);
	node->value = strdup(value);
	node->next = ht->array[index];
	ht->array[index] = node;

	return (1);
}
