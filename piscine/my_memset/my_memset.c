#include <stddef.h>

void *my_memset(void *s, int c, size_t n)
{
    if (s == NULL || n <= 0)
        return s;
    unsigned char *ptr = s;
    while (*ptr != '\0' && n--)
        *ptr++ = (unsigned char)c;
    return s;
}
