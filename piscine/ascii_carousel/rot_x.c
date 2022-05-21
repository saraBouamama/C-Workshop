#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

void rot_x(char *s, int x)
{
    if (s == NULL)
        return;
    while (x < 0)
        x += 26;

    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] <= 'z' && s[i] >= 'a')
            s[i] = ((s[i] - 'a' + x) % 26) + 'a';
        else if (s[i] <= 'Z' && s[i] >= 'A')
            s[i] = ((s[i] - 'A' + x) % 26) + 'A';
        i++;
    }
}
