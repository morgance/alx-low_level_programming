#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void elf_addr(char *dest);
void elf_type(char *dest);
void elf_osabi(char *dest);
void elf_version(char *dest);
void elf_data(char *dest);
void elf_magic(char *dest);
void elf_sys(char *dest);
int elf_checks(char *dest);
int main(int argc, char *argv[]);

/**
 * elf_addr - prints the address
 * @dest: magic
 *
 * Return:nothing
 */
void elf_addr(char *dest)
{
	int i, strt;
	char pro = dest[4] + '0';

	printf("Entry point address: 0x");

	if (pro == '1')
	{
		strt = 26;
		printf("80");
		for (i = strt; i >= 22; i--)
		{
			if (dest[i] == 0)
				printf("%02x", dest[i]);
			else
				printf("%02x", 256 + dest[i]);
		}
		if (dest[7] == 6)
			printf("00");
	}
	else if (pro == '2')
	{
		strt = 26;
		for (i = strt; i > 23; i--)
		{
			if (dest[i] >= 0)
				printf("%02x", dest[i]);
			else
				printf("%02x", 256 + dest[i]);
		}
	}
}
/**
 * elf_type- prints the type
 * @dest:elf magic
 *
 * Return:nothing
 */
void elf_type(char *dest)
{
	char type = dest[16];

	if (dest[5] == 1)
		type = dest[16];
	else
		type = dest[17];

	printf("Type:  ");

	if (type == 0)
		printf("NONE (No file type)\n");
	else if (type == 1)
		printf("REL (relocatable file)\n");
	else if (type == 2)
		printf("EXEC (executable file)\n");
	else if (type == 3)
		printf("DYN (shared object file)\n");
	else if (type == 4)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", type);
}
/**
 * elf_osabi - prints OS/ABI info
 * @dest:elf header
 *
 * Return:nothing
 */
void elf_osabi(char *dest)
{
	char eosabi = dest[7];

	printf(" OS/ABI:      ");
	switch (eosabi)
	{
		case 0:
			printf("UNIX - System V\n");
			break;
		case 2:
			printf("UNIX - NetBSD\n");
			break;
		case 6:
			printf("UNIX - Solaris\n");
			break;
		default:
			printf("<unknown: %x>\n", eosabi);
	}

	printf(" ABI Version:          %d\n", dest[8]);
}
/**
 * elf_version - print the version information of an ELF file
 * @dest:pointer to the elf file
 *
 * Return:nothing
 */
void elf_version(char *dest)
{

	printf(" %-34s %u", "Version:", dest[EI_VERSION]);

	if (dest[EI_VERSION] == EV_CURRENT)
		printf("(Current)");
	else
		printf("\n");
}
/**
 * elf_data - print the data of an elf
 * @dest:array containing the elf class
 *
 * Return:nothing
 */
void elf_data(char *dest)
{
	char data = dest[EI_DATA];

	printf(" Data:          2's compliment");

	switch (data)
	{
	case ELFDATA2LSB:
		printf(", little endian\n");
		break;
	case ELFDATA2MSB:
		printf(", big endian\n");
		break;
	default:
		printf(", unknown byte order\n");
		break;
	}
}
/**
 * elf_magic - print magic of an elf
 * @dest:array containing magic numbers
 *
 * Return:nothing
 */
void elf_magic(char *dest)
{
	int i;

	printf(" Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
		printf(" %02x", (unsigned char)dest[i]);
	printf("\n");
}
/**
 * elf_sys - checks the system version
 * @dest:elf magic header
 *
 * Return:nothing
 */
void elf_sys(char *dest)
{
	char pro = dest[4] + '0';

	if (pro == '0')
	{
		fprintf(stderr, "Error: Not an ELF file\n");
		exit(98);
	}
	printf("ELF Header:\n");
	elf_magic(dest);

	if (pro == '1')
		printf("  Class:                     ELF32\n");
	else if (pro == '2')
		printf("  Class:                     ELF64\n");
	else
	{
		fprintf(stderr, "Error: Invalid ELF class\n");
		exit(98);
	}
	elf_data(dest);
	elf_version(dest);
	elf_osabi(dest);
	elf_type(dest);
	elf_addr(dest);
}
/**
 * elf_checks - checks if its an ELF file
 * @dest:elf magic header
 *
 * Return:1 if successful,otherwise 0
 */
int elf_checks(char *dest)
{
	if (dest[0] != 0x7f || dest[1] != 'E' || dest[2] != 'L' || dest[3] != 'F')
	{
		return (0);
	}
	return (1);
}
/**
 * main - Displays info in the ELF header
 * @argc:number of arguments
 * @argv:pointer to the arguments
 *
 * Return:0
 */
int main(int argc, char *argv[])
{
	int i, pop;
	char dest[27];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}

	i = open(argv[1], O_RDONLY);
	if (i < 0)
	{
		dprintf(STDERR_FILENO, "Error: File can not be opened\n");
		exit(98);
	}

	lseek(i, 0, SEEK_SET);
	pop = read(i, dest, 27);

	if (pop == -1)
	{
		dprintf(STDERR_FILENO, "Error: The file can not be read\n");
		exit(98);
	}

	if (!elf_checks(dest))
	{
		dprintf(STDERR_FILENO, "Error: It is not an ELF\n");
		exit(98);
	}

	elf_sys(dest);
	close(i);

	return (0);
}
