#include <unistd.h>

/**
 * pUTch - i wNT TO WRITE CC
 * @c: printThe character/
 *
 * Return: whenn success 1.
 * at Error, -1 is returned.
 */
int pUTch(char c)
{
       return (write(1, &c, 1));
}
