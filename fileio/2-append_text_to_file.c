#include "main.h"
/**
 * append_text_to_file - appends text at the end of file
 * @filename:name of the file
 * @text_content:string to write on file
 *
 * Return:1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int i, j, m;

	if (!filename)
		return (-1);

	i = open(filename, O_WRONLY | O_APPEND);

	if (i == -1)
		return (-1);

	if (text_content)
	{
		for (j = 0; text_content[j]; j++)
			;

		m = write(i, text_content, j);

		if (m == -1)
			return (-1);
	}
	close(i);
	return (1);
}
