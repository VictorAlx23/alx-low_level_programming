#include "main.h"
#include <stdio.h>
#include <stdlib.h>
char *create_buffers(char *files);
void close_files(int fd);
/**
 * create_buffers - Allocates 1024 bytes to the buffer
 * @files: The name of the file buffer its storing characters for
 * Return: A pointer to the newly-allocated buffer
 */
char *create_buffers(char *files)
{
	char *buff;
	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", files);
		exit(99);
	}
	return (buff);
}
/**
 * close_files - Closes file descriptor
 * @fd: The file descriptor to be closed
 */
void close_files(int fd)
{
	int cl;
	cl = close(fd);

	if (cl == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - Copies the contents of a file to another file
 * @argc: The number of arguments suppplied to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on success
 *
 * Description: if the argument count is incorrect - exit code 97.
 *	if file_from does not exist or cannot be read - exit code 98.
 *	if file_to cannot be created or written to - exit code 99.
 *	if file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, re, wr;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buff = create_buffers(argv[2]);
	from = open(argv[1], O_RDONLY);
	re = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || re == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read to %s\n", argv[1]);
			free(buff);
			exit(98);
		}
		wr = write(to, buff, re);
		if (to == -1 || wr == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}
		re = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (re > 0);
	free(buff);
	close_files(from);
	close_files(to);
	return (0);
}
