#include "int_vector_bubble_sort.h"
#include <err.h>
#include <stddef.h>
#include <assert.h>

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    size_t i = 0;
    size_t j = 1;
    while (j < vec.size)
    {
        if (vec.data[j] < vec.data[i])
        {
            int vect = vec.data[j];
            vec.data[j] = vec.data[i];
            vec.data[i] = vect;
            i = 0;
            j = 1;
        }
        else
        {
            ++i;
            ++j;
        }
    }
    return vec;
}
