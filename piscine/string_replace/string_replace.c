#include <stddef.h>
#include <stdlib.h>

size_t my_strlen(const char *str)
{
    if (!str)
        return 0;
    size_t count = 0;
    while (str[count] != '\0')
        count++;
    return count;
}

char *path(size_t *s1, char *s2, const char *pattern)
{
    size_t i = 0;
    while (pattern[i] != '\0')
    {
        s2[*s1] = pattern[i];
        *s1 += 1;
        i++;
    }
    return s2;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    size_t len_str = my_strlen(str);
    char *s = calloc(len_str * 10, sizeof(char));
    if (!s || !str)
    {
        free(s);
        return NULL;
    }
    size_t j = 0;
    size_t i = 0;
    if (pattern == NULL)
    {
        while (str[j] != '\0')
        {
            if (str[j] != c)
            {
                s[i] = str[j];
                i++;
            }
            j++;
        }
    }
    else
    {
        while (str[j] != '\0')
        {
            if (str[j] == c)
                s = path(&i, s, pattern);
            else
            {
                s[i] = str[j];
                i++;
            }
            j++;
        }
    }
    return s;
}
