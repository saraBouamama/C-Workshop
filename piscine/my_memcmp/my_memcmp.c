#include <stddef.h>
int my_memcmp(const void *s1, const void *s2, size_t num)
{
    if (num != 0)
    {
        const unsigned char *p1 = s1, *p2 = s2;
        do
        {
            if (*p1++ != *p2++)
                return (*--p1 - *--p2);
        } while (--num != 0);
    }
    return 0;
}
