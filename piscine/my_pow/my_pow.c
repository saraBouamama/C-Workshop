#include <assert.h>

int my_pow(int a, int b)
{
    int resultat;
    if (b == 0)
        return 1;
    resultat = my_pow(a, b / 2);
    if (b % 2)
        return a * resultat * resultat;
    else
        return resultat * resultat;
}
