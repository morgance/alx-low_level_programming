#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 *
 * @ht: pointer to the hash table
 * @key: key of the hash table
 * Return: value of the hashtable
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int index;
	hash_node_t *pro;

	if (ht == NULL)
		return (NULL);

	if (key == NULL || *key == '\0')
		return (NULL);

	index = index((unsigned char *)key, ht->size);

	pro = ht->array[index];

	while (pro != NULL)
	{
		if (strcmp(pro->key, key) == 0)
			return (pro->value);
		pro = pro->next;
	}

	return (NULL);
}
