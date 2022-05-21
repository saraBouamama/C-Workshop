int int_sqrt2(int n)
{
    int res;
    if (n < 0)
        return -1;
    for (int i = 1; i * i <= n; i++)
    {
        if (i * i == n)
            res = i;
    }
    return res;
}
