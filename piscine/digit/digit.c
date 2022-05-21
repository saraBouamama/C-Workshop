unsigned int digit(int n, int k)
{
    int mod;
    if (n <= 0 || k <= 0)
    {
        return 0;
    }

    else
    {
        for (int i = 0; i < k; i++)
        {
            mod = n % 10;
            n /= 10;
        }
    }
    return mod;
}
