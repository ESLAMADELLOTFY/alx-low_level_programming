#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - check code for islam adel lofy
 *
 * Return: Always 0.
 */
int main(int accc, char **av)
{
    int res;

    if (accc != 3)
    {
        dprintf(2, "Usage: %s filename text\n", av[0]);
        exit(1);
    }
    res = FileCreater(av[1], av[2]);
    printf("-> %i)\n", res);
    return (0);
}
