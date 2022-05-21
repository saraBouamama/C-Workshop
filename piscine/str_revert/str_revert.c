#include <stddef.h>

int my_strlen(char str[])
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i)
        count++;
    return count;
}

void str_revert(char str[])
{
    int len = my_strlen(str);
    for (int i = 0; i < len; i++)
    {
        int tmp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = tmp;
    }
}
