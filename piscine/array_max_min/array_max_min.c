#include <err.h>
#include <stddef.h>
#include <stdio.h>

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    size_t i = 0;
    *min = tab[0];
    while (i < len)
    {
        if (tab[i] > *max)
        {
            *max = tab[i];
        }
        if (tab[i] < *min)
        {
            *min = tab[i];
        }
        i += 1;
    }
}
