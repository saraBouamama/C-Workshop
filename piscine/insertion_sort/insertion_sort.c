#include <stdio.h>
#include <stdlib.h>

typedef int (*f_cmp)(const void *, const void *);

void swap(void **array, size_t i, size_t j)
{
    void *tmp;
    tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

void insertion_sort(void **array, f_cmp comp)
{
    if (array[0] != NULL)
    {
        for (size_t i = 1; array[i] != NULL; i++)
        {
            for (size_t j = i;
                 (j > 0) && array[j] != NULL && array[j - 1] != NULL; j--)
            {
                if (comp(array[j], array[j - 1]) < 0)
                    swap(array, j, j - 1);
            }
        }
    }
}
