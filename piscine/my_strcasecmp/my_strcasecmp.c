#include <stdio.h>

int low(int cha)
{
    if (cha >= 'A' && cha <= 'Z')
        return ('a' + cha - 'A');
    return cha;
}

int my_strcasecmp(const char *s1, const char *s2)
{
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;
    int res;
    if (p1 == p2)
        return 0;
    while ((res = low(*p1) - low(*p2++)) == 0)
    {
        if (*p1++ == '\0')
            break;
    }
    return res;
}
