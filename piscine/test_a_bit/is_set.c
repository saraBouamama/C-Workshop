#include <stddef.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned short max = 1 << (n - 1);
    unsigned short resultat = value | max;
    return (resultat == value);
}
