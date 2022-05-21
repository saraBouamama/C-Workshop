#include "functional_programming_advanced.h"
#include <stdio.h>

bool is_even(int x)
{
    return x % 2 == 0 ? true : false;
}

void print_even(int *array, size_t len)
{
    int *out_array = NULL;
    size_t len2 = filter(array, len, &out_array, is_even);

    for (size_t i = 0; i < len2; i++)
        printf("%d", out_array[i]);
    printf("%d\n", out_array[len2 - 1]);
}
