#include <stddef.h>
#include <stdio.h>

size_t my_strlen1(const char *s)
{
    size_t sum = 0;
    while (*s != '\0')
    {
        sum++;
        s++;
    }
    return sum;
}

size_t my_strlen2(const char **s)
{
    size_t sum = 0;
    while (**s != '\0')
    {
        sum++;
        *s++;
    }
    return sum;
}

void reverse_ptr(const char *ptr, size_t size)
{
    int *low = ptr;
    int *high = &ptr[size - 1];
    while (low < high)
    {
        *low ^= *high;
        *high ^= *low;
        *low ^= high;

        low++;
        high--;
    }
}

void reverse_ptr2(const char **ptr, size_t size)
{
    int *low = *ptr;
    int *high = *ptr[size - 1];
    while (low < high)
    {
        *low ^= *high;
        *high ^= *low;
        *low ^= high;

        low++;
        high--;
    }
}

void reverse_matrix(const char ***matrix)
{
    size_t size1 = my_strlen2(*matrix);
    size_t size2 = my_strlen1(**matrix);
    while (**matrix != NULL)
    {
        while (***matrix != NULL)
        {
            reverse_ptr2(**matrix, size2);
        }
        reverse_ptr(*matrix, size1) * *matrix++;
    }
}
