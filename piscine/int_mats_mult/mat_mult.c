#include <stddef.h>

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    for (size_t i = 0; i < *(matrices_size); i = i + 1)
    {
        for (size_t j = 0; j < *(matrices_size + 2); j = j + 1)
        {
            int value = 0;
            for (size_t p = 0; p < *(matrices_size + 1); p = p + 1)
            {
                value += mat1[i][p] * mat2[p][j];
            }
            out[i][j] = value;
        }
    }
}
