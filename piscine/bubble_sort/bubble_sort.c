#include <stdio.h>

void bubble_sort(int array[], size_t size)
{
    if (size == 0)
        return;
    size_t cursor = 1;
    while (cursor != size)
    {
        cursor = 1;
        size_t i = 0;
        while (i < size - 1)
        {
            if (array[i] > array[i + 1])
            {
                int swap = array[i];
                array[i] = array[i + 1];
                array[i + 1] = swap;
                cursor = 1;
            }
            else
                cursor++;
            i++;
        }
    }
}
