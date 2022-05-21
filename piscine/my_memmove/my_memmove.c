#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    size_t i;
    const unsigned char *src2 = src;
    unsigned char *dest2 = dest;
    if (dest2 < src2)
    {
        for (i = 0; i < n; i++)
            dest2[i] = src2[i];
    }
    else if (dest2 > src2)
    {
        for (i = n; i > 0; i--)
            dest2[i - 1] = src2[i - 1];
    }
    return dest;
}
