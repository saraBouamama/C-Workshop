#include "int_vector_print.h"

#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    for (size_t j = 0; j < vec.size - 1; j++)
    {
        printf("%d ", vec.data[j]);
    }
    printf("%d", vec.data[vec.size - 1]);
    printf("\n");
}
