#include <stdio.h>

int is_digit(const char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}

int num(const char c)
{
    return c - '0';
}

int my_atoi(const char *str)
{
    int cursor = 0;
    int res = 0;
    int sign = 1;
    if (str[0] == '-')
    {
        sign = -1;
        cursor = 1;
    }
    else if (str[0] == '+')
    {
        sign = 1;
        cursor = 1;
    }
    while (str[cursor])
    {
        if (str[cursor] == ' ')
            cursor++;
        else
        {
            if (is_digit(str[cursor]) == 1)
                res = res * 10 + num(str[cursor]);
            else
            {
                return 0;
            }
            cursor++;
        }
    }
    return res * sign;
}
