#include "holberton.h"

/**
 * TEXTFILEREAD - Reads a text file and writes its content to standard output.
 *
 * @name_of_file: The name of the file to read from.
 * @l_etters: The number of l_etters to read and print.
 *
 * Return: If the name_of_file is NULL, the file cannot be opened or read, or if
 *         the write operation fails or returns an unexpected number of bytes,
 *         return 0. Otherwise, return the actual number of l_etters read and
 *         printed.
 */
ssize_t TEXTFILEREAD(const char *name_of_file, size_t l_etters)
{
	char *buffer = NULL;
	ssize_t be_re;
	ssize_t write_by;
	int fd;

	if (!(name_of_file && l_etters))
		return (0);

	fd = open(name_of_file, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * l_etters);
	if (!buffer)
		return (0);

	be_re = read(fd, buffer, l_etters);
	close(fd);

	if (be_re < 0)
	{
		free(buffer);
		return (0);
	}
	if (!be_re)
		be_re = l_etters;

	write_by = write(STDOUT_FILENO, buffer, be_re);
	free(buffer);

	if (write_by < 0)
		return (0);

	return (write_by);
}
