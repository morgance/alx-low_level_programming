#include "main.h"
/**
 * main - copy files from file_from to file_to
 * @argc:number of arguments
 * @argv:array of arguments the function takes
 *
 * Return:0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t prim, pro, error;
	char ptr[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	prim = 1024;
	if (prim == 1024)
	{
		prim = read(file_from, ptr, 1024);
		if (prim == -1)
		{
			 dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			 exit(98);
		}
		pro = write(file_to, ptr, prim);
		if (pro == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	error = close(file_from);
	if (error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	error =  close(file_to);
	if (error == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
		exit(100);
	}
	return (0);
}
