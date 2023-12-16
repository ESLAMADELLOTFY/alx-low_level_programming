#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define BUFSIZE 1024



/**
 * _read - an ksdd sdds sldksdsdos sisisi
 * @Name_file: oiwe ww  rr w qd 
 * @feed_back:jsa skdkn a;ks  aud
 * @buffera: poqw qe q f e s csxhjy j uf
 * @Co_nt: av sx sfsfdfgfds fcsxc 
 *
 * Return: num byte youn ara read
 */
ssize_t _read(const char *Name_file, int feed_back, char *buffera, size_t Co_nt)
{
	ssize_t pread = read(feed_back, buffera, Co_nt);

	if (pread > -1)
		return (pread);
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", Name_file);
	return (-1);
}

/**
 * _close - islam adel lotfy hefni 
 * @feed_back: the file descriptor to close
 *
 * Return: 0 upon success, -1 upon failure
 */
int _close(int feed_back)
{
	if (!close(feed_back))
		return (0);
	dprintf(STDERR_FILENO, "Error: Can't close feed_back %d\n", feed_back);
	return (-1);

}

/**
 * _write - kjbkjbk khhk hgkg ure
 * @Name_file: m,n  kfx dxkv dvjd dsk
 * @feed_back: ksd fdsfsd fsd gfsd 
 * @buffera: asdsalda  dakldad adn
 * @Co_nt:xjczf xdsasfseterydt yrt yrt
 *
 * Return: The number of bytes written, or -1 upon failure
 */
ssize_t _write(const char *Name_file, int feed_back, const char *buffera, size_t Co_nt)
{
	ssize_t bytes_written = write(feed_back, buffera, Co_nt);

	if (bytes_written > -1)
		return (bytes_written);
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", Name_file);
	return (-1);
}

/**
 * main - saod askmd ksadfas osad 
 * @ar_gc: count of argu
 * @ar_gv: the argument values
 *
 * Return: Always 1
 */
int main(int ar_gc, const char *ar_gv[])
{
	int fd_in, fd_out;
	ssize_t pread;
	char buffer[BUFSIZE];

	if (ar_gc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_in = open(ar_gv[1], O_RDONLY);
	if (fd_in < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", ar_gv[1]);
		exit(98);
	}
	fd_out = open(ar_gv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_out < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", ar_gv[2]);
		close(fd_in);
		exit(99);
	}
	while ((pread = _read(ar_gv[1], fd_in, buffer, BUFSIZE)))
	{
		if (pread < 0)
		{
			_close(fd_in);
			_close(fd_out);
			exit(98);
		}
		if (pwrite (ar_gv[2], fd_out, buffer, pread) < 0)
		{
			_close(fd_in);
			_close(fd_out);
			exit(99);
		}
	}
	if ((_close(fd_in) | _close(fd_out)) < 0)
		exit(100);
	return (0);
}

