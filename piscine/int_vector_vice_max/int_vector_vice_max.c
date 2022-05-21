#include "int_vector_vice_max.h"

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int min = vec.data[1];
    for (size_t i = 0; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            min = max;
            max = vec.data[i];
        }
        else if (vec.data[i] > min && vec.data[i] < max)
            min = vec.data[i];
    }
    return min;
}
