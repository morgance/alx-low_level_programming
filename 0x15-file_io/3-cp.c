#include "main.h"
/**
 * open_files - checks files if they can be opened
 * @file_from: files_from
 * @file_to:file_to
 * @argv:argument
 *
 * Return:nothing
 */
void open_files(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}
/**
 * main - copy files
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return:0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, error;
	ssize_t prim, pro;
	char ptr[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	open_files(file_from, file_to, argv);

	prim = 1024;
	while (prim == 1024)
	{
		prim = read(file_from, ptr, 1024);
		if (prim == -1)
			open_files(-1, 0, argv);
		pro = write(file_to, ptr, prim);
		if (pro == -1)
			open_files(0, -1, argv);
	}

	error = close(file_from);
	if (error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	error = close(file_to);
	if (error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
