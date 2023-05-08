#include "main.h"
/**
 * create_file - Creates a file
 * @filename: A pointer to the name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure and if the filename is NULL
 */
int create_file(const char *filename, char *text_content)
{
	int fd, writ, size = 0;

	if (filename == NULL)
		return (-1);
	if (text_content)
	{
		while (text_content[size])
			size++;
	}
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	writ = write(fd, text_content, size);
	if (fd == -1 || writ == -1)
		return (-1);
	close(fd);
	return (1);
}
