#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int tmp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = tmp;
    return vec;
}

struct int_vector int_vector_insert_sort(struct int_vector vec)
{
    for (size_t i = 0; i < vec.size; i++)
    {
        size_t j = i;
        while (vec.data[j - 1] > vec.data[j] && j >= 1)
        {
            vec = swap(vec, j - 1, j);
            j--;
        }
    }
    return vec;
}
