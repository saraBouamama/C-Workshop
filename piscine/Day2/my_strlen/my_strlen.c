size_t mystrlen(const char *s)
{
    size_t sum = 0;
    while (*s != 0)
    {
        sum++;
        s++;
    }
    return sum
}
