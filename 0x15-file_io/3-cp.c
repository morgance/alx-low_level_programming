#include "main.h"
/**
 * main -copy files
 * @argc:number of arguments
 * @argv:array of arguments
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
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = open(argv[2], 0_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Cant write to %s\n", argv[2]);
		exit(99);
	}
	prim = 1024;
	while (prim == 1024)
	{
		prim = read(file_from, ptr, 1024);
		if (prim == -1)
		{
			 dprintf(STDERR_FILENO, "Error: Cant read from file %s\n", argv[1]);
			 exit(98);
		}
		pro = write(file_to, ptr, prim);
		if (pro == -1)
		{
			dprintf(STDERR_FILENO, "Error: Cant write to %s\n", argv[2]);
			exit(99);
		}
	}
		error = close(file_from);
		if (error == -1)
		{
			dprintf(STDERR_FILENO, "Error: Cant close fd %d\n", file_from);
			exit(100);
		}
		error =  close(file_to);
		if (error == -1)
		{
			dprintf(STDERR_FILENO, "Error: Cant close fd %d\n", file_to);
			exit(100);
		}

		return (0);
}
