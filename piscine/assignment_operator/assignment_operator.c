#include <stddef.h>
#include <stdio.h>

void plus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
        return;
    *a = (*a + *b);
}

void minus_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
        return;
    *a = (*a - *b);
}

void mult_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
        return;
    *a = ((*a) * (*b));
}
void div_equal(int *a, int *b)
{
    if (a == NULL || b == NULL || *b == 0)
        return;
    *a = (*a) / (*b);
}
