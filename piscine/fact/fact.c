unsigned long fact(unsigned n)
{
    int res;
    if (n != 0)
    {
        res = n * fact(n - 1);
    }
    else
    {
        res = 1;
    }
    return res;
}
