#include "functional_programming_advanced.h"

static int foldl(int *array, size_t len, int (*func)(int, int))
{
    int current = 0;
    for (size_t i = 0; i < len; i++)
        current = func(current, array[i]);

    return current;
}

static int max_of_two(int a, int b)
{
    return a > b ? a : b;
}

int max(int *array, size_t len)
{
    return foldl(array, len, max_of_two);
}
