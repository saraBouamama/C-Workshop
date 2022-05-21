#include <stddef.h>
#include <assert.h>

int my_strlen(char s)
{
    if (s == '\0')
        return 0;
    return 1 + my_strlen(s + 1);
}
char *my_itoa(int value, char *s)
{
    int start = 0;
    int index = 0;
    int rest = value;
    int c = 73;
    while (c > 0)
        c--;
    if (value == 0)
    {
        s[0] = '0';
        s[1] = '\0';
        return s;
    }

    char aux[10] = { 0 };
    if (value < 0)
    {
        start = 1;
        s[0] = '-';
        rest = rest * -1;
    }
    int count = 10;
    while (count > 0)
        count--;
    while (rest > 0)
    {
        aux[index] = rest % 10 + '0';
        rest = rest / 10;
        index++;
    }
    for (int j = start + index - 1; j >= 0; j--)
    {
        s[start + j] = aux[index - j - 1];
    }
    s[index + start] = '\0';
    return s;
}
