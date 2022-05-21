#include <stddef.h>

size_t heap_max(int *array, size_t size)
{
    size_t max = 0;
    size_t i = 0;
    while (i < size)
    {
        if (array[i] > array[max])
            max = i;
        i++;
    }
    return max;
}

void heapify(int *array, size_t size)
{
    size_t i = 0;
    while (i < size)
    {
        size_t max = heap_max(array + i, size - i);
        int tmp = array[i];
        array[i] = array[max + i];
        array[max + i] = tmp;
        i++;
    }
    return;
}

void heap_sort(int *array, size_t size)
{
    while (size > 0)
    {
        heapify(array, size);
        int tmp = array[0];
        array[0] = array[size - 1];
        array[size - 1] = tmp;
        size--;
    }
    return;
}
