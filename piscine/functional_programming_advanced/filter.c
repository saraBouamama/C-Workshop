#include <stdlib.h>
#include "functional_programming_advanced.h"

size_t filter(int *array, size_t len, int **out_array, bool (*func)(int))
{
    size_t len_out = 0;
    for (size_t i = 0; i < len; i++)
        len_out = func(array[i]) ? 1 + len_out : len_out;

    *out_array = NULL;
    if (!(*out_array = malloc(sizeof(int) * len_out)))
       return 0; 

    size_t j = 0;
    for (size_t i = 0; i < len; i++)
    {
        if (func(array[i]))
            *out_array[j++] = array[i];
    }

    free(out_array);
    return len_out;
}
