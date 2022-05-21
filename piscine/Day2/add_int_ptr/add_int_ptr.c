#include <stddef.h>
int *add_int_ptr(int *a, int *b)
{
    int *c = 0;
    if (a == NULL || b == NULL)
    {
        *c = *a;
    }

    else
    {
        *c = (*a + *b);
    }
    return c;
}
