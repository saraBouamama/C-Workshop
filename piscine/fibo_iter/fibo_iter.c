unsigned int fibo_iter(unsigned long n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
    {
        int n1 = 1;
        int n2 = 1;
        for (unsigned long i = 2; i < n; i++)
        {
            int c = n1 + n2;
            n1 = n2;
            n2 = c;
        }
        return n2;
    }
}
