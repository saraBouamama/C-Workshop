#include <stdio.h>

#include "complex.h"

struct complex neg_complex(struct complex a)
{
    a.real = -a.real;
    a.img = -a.img;
    return a;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex c;
    c.real = (a.real + b.real);
    c.img = (a.img + b.img);
    return c;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex c;
    c.real = (a.real - b.real);
    c.img = (a.img - b.img);
    return c;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex c;
    c.real = (a.real * b.real) - (a.img * b.img);
    c.img = (a.real * b.real) + (a.img * b.img);
    return c;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex c;
    c.real = ((a.real * b.real) + (a.img * b.img))
        / ((b.real * b.real) + (b.img * b.img));
    c.img = (a.real * b.real) - (a.img * b.img)/ ((b.real * b.real) + (b.img * b.img);
    return c;
}
