#include <stddef.h>

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *d = dest;
    const char *s = source;
    while (num--)
        *d++ = *s++;
    return dest;
}
