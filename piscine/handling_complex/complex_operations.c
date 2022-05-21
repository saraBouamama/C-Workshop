#include "complex.h"

struct complex neg_complex(struct complex a)
{
    a.real = a.real * -1;
    a.img = a.img * -1;
    return a;
}

struct complex add_complex(struct complex a, struct complex b)
{
    struct complex sum;
    sum.real = a.real + b.real;
    sum.img = a.img + b.img;
    return sum;
}

struct complex sub_complex(struct complex a, struct complex b)
{
    struct complex sub;
    sub.real = a.real - b.real;
    sub.img = a.img - b.img;
    return sub;
}

struct complex mul_complex(struct complex a, struct complex b)
{
    struct complex mul;
    mul.real = a.real * b.real - a.img * b.img;
    mul.img = a.real * b.img + a.img * b.real;
    return mul;
}

struct complex div_complex(struct complex a, struct complex b)
{
    struct complex c;
    float deno = (b.real * b.real + b.img * b.img);
    c.real = (a.real * b.real + a.img * b.img) / deno;
    c.img = (a.img * b.real - a.real * b.img) / deno;
    return c;
}
