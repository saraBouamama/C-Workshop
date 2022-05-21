#include <stddef.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init)
{
    int zero = 0;
    if ((size == 0) || (__builtin_mul_overflow(size, sizeof(int), &zero)))
        return NULL;
    int *res = malloc(size * sizeof(int));
    if (!res)
        return NULL;
    for (size_t i = 0; i < size; i++)
        res[i] = init;
    return res;
}
