#include "holberton.h"

/**
 * Text_file_append - put text at the end of file
 * @Name_of_file: apeend the file in.
 * @ContentTheText: the data to append the your f_ile
 *
 * Return: when successed, return 1. else, return -1.
 */
int Text_file_append(const char *Name_of_file, char *ContentTheText)
{
	ssize_t written_by_who = 0;
	int d_ff;

	if (!Name_of_file)
		return (-1);

	d_ff = open(Name_of_file, O_WRONLY | O_APPEND);

	if (d_ff < 0)
		return (-1);

	if (ContentTheText)
		written_by_who = write(d_ff, ContentTheText, _strlen(ContentTheText));

	close(d_ff);

	if (written_by_who < 0)
		return (-1);
	return (1);
}
