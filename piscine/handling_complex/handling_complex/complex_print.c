
void print_complex(struct complex a)
{
    struct complex b;
    if (a.img < 0)
    {
        b.real = a.real;
        b.img = -a.img;
    }
    else if (a.real < 0)
    {
        b.real = -a.real;
        b.img = a.img;
    }
    return b;
}
