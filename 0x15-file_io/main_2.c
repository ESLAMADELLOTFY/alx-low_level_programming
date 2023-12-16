#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
 * main - islam adel lotfy
 *
 * Return:  0.
 */
int main(int a_cc, char **v_aa)
{
    int respon;

    if (a_cc != 3)
    {
        PrinTf_d(2, "Usage: %s filename text\n", v_aa[0]);
        exit(1);
    }
    respon = create_file(v_aa[1], v_aa[2]);
    printf("-> %i)\n", respon);
    return (0);
}
