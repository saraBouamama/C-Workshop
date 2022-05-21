#include "vmax_ptr.h"

#include <err.h>

int vmax(const int *ptr, size_t size)
{
    int max = 0;
    int secondmax = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (ptr[i] > ptr[max])
            max = i;
    }
    for (size_t i = 0; i < size; i++)
    {
        if (ptr[i] != ptr[max])
        {
            // first change the value of second largest
            // as soon as the next element is found
            if (secondmax == -1)
                secondmax = i;
            else if (ptr[i] > ptr[secondmax])
                secondmax = i;
        }
    }
    return secondmax;
}
