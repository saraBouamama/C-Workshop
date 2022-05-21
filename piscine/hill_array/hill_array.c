#include <stddef.h>

int reorder_hill(int tab[], size_t len)
{
    size_t i = 0;
    while (tab[i] <= tab[i + 1] && i < len - 1)
    {
        i++;
    }
    if (i == len - 1)
        return 1;
    else
    {
        while (tab[i] >= tab[i + 1] && i < len - 1)
        {
            i++;
        }
        if (i == len - 1)
            return 1;
        else
            return 0;
    }
}

int top_of_the_hill(int tab[], size_t len)
{
    int k = reorder_hill(tab, len);
    if (k == 0)
        return -1;
    else
    {
        size_t q = 0;
        while (tab[q] <= tab[q + 1] && q < len - 1)
        {
            q++;
        }
        size_t l = 0;
        int highest_index = tab[q];
        while (tab[q - l] == highest_index && l <= q)
        {
            l++;
        }
        if (l > q)
            return 0;
        else
            return q - l + 1;
    }
}
