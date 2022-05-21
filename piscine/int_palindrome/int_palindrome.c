int int_palindrome_help(int n)
{
    int r;
    int sum = 0;
    while (n != 0)
    {
        r = n % 10;
        sum = (sum * 10) + r;
        n = n / 10;
    }
    return sum;
}

int int_palindrome(int n)
{
    if (n == int_palindrome_help(n))
        return 1;
    return 0;
}
