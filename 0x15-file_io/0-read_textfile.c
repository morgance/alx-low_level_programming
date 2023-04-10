#include "main.h"
/**
 * read_textfile - reads a textfile and prints to the output
 * @filename:file to read and write
 * @letters:number of letters printed
 *
 * Return:number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int i;
	ssize_t prime, pro;
	char *ptr;

	if (!filename)
		return (0);

	i = open(filename, O_RDONLY);

	if (i == -1)
		return (0);


	ptr = malloc(sizeof(char) * (letters));

	if (!ptr)
		return (0);

	prime = read(i, ptr, letters);
	pro = write(STDOUT_FILENO, ptr, prime);

	close(i);

	free(ptr);

	return (pro);
}
