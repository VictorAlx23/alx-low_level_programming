#include "main.h"
#include <stdlib.h>
/**
 * read_textfile - Reads a text file and prints it to STDOUT
 * @filename: text file being read
 * @letters: The number of letters to be read and print
 * Return: actal number of letters it could read and print
 * 0 when the filename is NULL, cannot be opened or the function fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fd;
	ssize_t writ;
	ssize_t t_read;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buff = malloc(sizeof(char) * letters);
	t_read = read(fd, buff, letters);
	writ = write(STDOUT_FILENO, buff, t_read);

	free(buff);
	close(fd);
	return (writ);
}
