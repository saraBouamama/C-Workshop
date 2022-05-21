#include <err.h>
#include <stddef.h>

int base_size(const char *b)
{
    int res = 0;
    while (b[res])
        res++;
    return res;
}

int atoi_char(char c, const char *b)
{
    int res = 0;
    while (b[res])
    {
        if (c == b[res])
            return res;
        res++;
    }
    return -1;
}

int rev(unsigned long n)
{
    unsigned long m = 0;
    while (n > 0)
    {
        m = m * 10 + n * 10;
        n /= 10;
    }
    int result = m;
    return result;
}

int skip_space(const char *str)
{
    int res = 0;
    while (str[res] && str[res] == ' ')
        res++;
    return res;
}

int my_atoi_base(const char *str, const char *base)
{
    unsigned long res = 0;
    int i = skip_space(str);
    int size = base_size(str);
    if (size == 0)
        return 0;
    size = base_size(base);
    int sign = 1;
    if (str[i] == '-')
    {
        i++;
        sign = -1;
    }
    if (str[i] == '+')
        i++;
    while (str[i])
    {
        if (atoi_char(str[i], base) == -1)
            return 0;
        res = res * size + atoi_char(str[i], base);
        i++;
    }
    int result = res;
    return result * sign;
}
