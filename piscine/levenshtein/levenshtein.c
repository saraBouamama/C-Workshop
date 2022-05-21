#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        len += 1;
    }
    return len;
}

int min(int a, int b, int c)
{
    if (a <= b && a <= c)
        return a;
    else if (b <= a && b <= c)
        return b;
    else if (c <= a && c <= b)
        return c;
    else
        return 0;
}

size_t levenshtein(const char *s1, const char *s2)
{
    unsigned int x;
    unsigned int y;
    unsigned int s1len;
    unsigned int s2len;
    s1len = my_strlen(s1);
    s2len = my_strlen(s2);
    unsigned int matrix[s2len + 1][s1len + 1];
    matrix[0][0] = 0;
    for (x = 1; x <= s2len; x++)
        matrix[x][0] = matrix[x - 1][0] + 1;
    for (y = 1; y <= s1len; y++)
        matrix[0][y] = matrix[0][y - 1] + 1;
    for (x = 1; x <= s2len; x++)
        for (y = 1; y <= s1len; y++)
            matrix[x][y] =
                min(matrix[x - 1][y] + 1, matrix[x][y - 1] + 1,
                    matrix[x - 1][y - 1] + (s1[y - 1] == s2[x - 1] ? 0 : 1));

    return (matrix[s2len][s1len]);
}
