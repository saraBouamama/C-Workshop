#include "bsearch.h"

int *binary_search(int *begin, int *end, int elt)
{
    int *middle;
    while (begin < end)
    {
        middle = (end - begin) / 2 + begin;
        if (elt > *middle)
            begin = middle + 1;
        else if (elt < *middle)
            end = middle - 1;
        else if (elt == *middle)
            return middle;
    }
    return middle;
}
