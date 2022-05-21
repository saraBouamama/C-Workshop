#include <stddef.h>
void plus_equal(int *a, int *b)
{
    *a = (*a + *b);
}

void minus_equal(int *a, int *b)
{
    *a = (*a - *b);
}

void mult_equal(int *a, int *b)
{
    *a = ((*a) * (*b));
}

int div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
    {
        return 0;
    }

    else
    {
        *a = (*a) / (*b);
        return *a;
    }
}
