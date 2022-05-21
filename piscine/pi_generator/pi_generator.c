double pi_generator(int precision)
{
    double pi = 1;
    for (double i = precision; i > 0; i--)
    {
        pi = 1 + (i / (i * 2 + 1) * pi);
    }
    return 2 * pi;
}
