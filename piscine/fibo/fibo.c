#include <stdio.h>
unsigned long fibonacci(unsigned long n)
{
    int U_n = 0;

    if (n == 0)
    {
        U_n = 0;
    }
    else if (n == 1)
    {
        U_n = 1;
    }
    else
    {
        U_n = (fibonacci(n - 1) + fibonacci(n - 2));
    }
    return U_n;
}
