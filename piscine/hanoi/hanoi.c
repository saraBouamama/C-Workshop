#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stdio.h>

void hanoii(unsigned n, char d, char a, char i)
{
    if (n != 0)
    {
        hanoii(n - 1, d, i, a);
        putchar(d);
        putchar('-');
        putchar('>');
        putchar(a);
        putchar('\n');
        hanoii(n - 1, i, a, d);
    }
}

void hanoi(unsigned n)
{
    if (n < 1)
    {
        return;
    }
    hanoii(n, '1', '3', '2');
}
