#include "my_itoa_base.h"

#include <stdio.h>
#define MAX_BUFF 1024

int my_strlen(const char *s)
{
    int i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int i = 0;
    int tmp = n;
    char buff[MAX_BUFF] = { '\0' };
    int len_base = my_strlen(base);

    int start = 0;
    if (n < 0)
    {
        s[start] = '-';
        start++;
        tmp *= -1;
    }

    while (tmp > 0)
    {
        buff[i] = base[tmp % len_base];
        tmp /= len_base;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        s[start] = buff[j];
        start++;
    }
    s[start] = '\0';
    return s;
}
