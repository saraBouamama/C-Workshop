#include <stdlib.h>

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *fin;
    if (str == NULL)
        str = *saveptr;
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    str += my_strspn(str, delim);
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    fin = str + my_strcspn(str, delim);
    if (*fin == '\0')
    {
        *saveptr = fin;
        return str;
    }

    *fin = '\0';
    *saveptr = fin + 1;
    return str;
}
