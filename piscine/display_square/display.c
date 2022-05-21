#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void display_square(int width)
{
    if (width <= 0)
        return;
    if (width % 2 != 0)
    {
        width++;
    }
    int w = width;
    int n = (width + 1) / 2;
    if (n <= 0)
    {
        return;
    }
    if (n % 2 != 0)
        n++;
    while (w > 0)
    {
        putchar('*');
        w--;
    }
    putchar('\n');
    for (int i = 2; i < n; i++)
    {
        putchar('*');
        for (int j = 2; j < width; j++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }
    w = width;
    while (w > 0)
    {
        putchar('*');
        w--;
    }
    putchar('\n');
}
