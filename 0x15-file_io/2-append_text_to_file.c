#include "main.h"
/**
 * append_text_to_file - Appends text to the end of a file
 * @filename: A pointer to the name of the file
 * @text_content: The string or text to add to the end of the file
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, writ, size = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		while (text_content[size] != '\0')
			size++;
	}
	fd = open(filename, O_WRONLY | O_APPEND);
	writ = write(fd, text_content, size);
	if (fd == -1 || writ == -1)
		return (-1);
	close(fd);
	return (1);
}