#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pine(unsigned int top)
{
    if (top <= 2)
        return 1;
    unsigned int vo = top - 1;
    unsigned int po = 1;
    for (unsigned int i = 1; i <= top; i++)
    {
        for (unsigned int y = 0; y != vo; y++)
            putchar(32);
        for (unsigned int y = 0; y != po; y++)
            putchar(42);
        vo--;
        po += 2;
        putchar(10);
    }
    unsigned int rope = 1;
    while (rope <= top / 2)
    {
        for (unsigned int y = 0; y != top - 1; y++)
            putchar(32);
        putchar(42);
        rope++;
        putchar(10);
    }
    return 0;
}
