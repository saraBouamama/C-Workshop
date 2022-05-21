#include <stddef.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    unsigned char res = value;
    while (roll)
    {
        res = res << 1 | res >> 7;
        roll--;
    }
    return res;
}
