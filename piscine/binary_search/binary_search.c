#include <stddef.h>

int binary_search(const int vec[], size_t size, int elt)
{
    int start = 0;
    int end = size;
    int middle = (end + start) / 2;

    while (start <= end)
    {
        middle = (end + start) / 2;
        if (elt > vec[middle])
            start = middle + 1;
        else if (elt < vec[middle])
            end = middle - 1;
        if (elt == vec[middle])
            return middle;
    }
    return -1;
}
