#include <stdio.h>
int my_stmrcp(const char *s1, const char *s2)
{
    int prob = 0;
    while (*s1 != '\0' && *s2 != '\0')
    {
        if (*s1 != *s2)
        {
            prob = 1;
        }
        s1++;
        s2++;
    }
    if (prob == 0)
    {
        return 0;
    }
    else
        return 1;
}
