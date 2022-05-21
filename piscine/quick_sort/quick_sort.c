#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int min, int max)
{
    int pv = arr[max];
    int i = (min - 1);
    for (int j = min; j <= max - 1; j++)
    {
        if (arr[j] <= pv)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[max]);
    return (i + 1);
}
void help_qs(int arr[], int min, int max)
{
    if (min < max)
    {
        int part = partition(arr, min, max);
        help_qs(arr, min, part - 1);
        help_qs(arr, part + 1, max);
    }
}

void quicksort(int arr[], int len)
{
    help_qs(arr, 0, len - 1);
}
