#include <stdio.h>

void swap(int arr[], unsigned a, unsigned b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned min = start;
    for (; start < size; ++start)
    {
        if (arr[start] < arr[min])
            min = start;
    }
    return min;
}

void selection_sort(int arr[], unsigned size)
{
    for (unsigned i = 0; i < size; ++i)
    {
        unsigned min = array_min(arr, i, size);
        if (arr[min] < arr[i])
            swap(arr, i, min);
    }
}
