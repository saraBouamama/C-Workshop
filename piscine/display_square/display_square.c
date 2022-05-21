#include <stddef.h>
#include <stdio.h>
void display_square_deluxe(int width)
{
    for (int i = 0; i < (width / 2) - 1; i++)
    {
        putchar('*');
        for (int j = 1; j < width - 1; j++)
            putchar(' ');
        putchar('*');
        putchar('\n');
    }
}

void display_trait(int width)
{
    int l = 0;
    while (l <= width)
    {
        putchar('*');
        l++;
    }
    putchar('\n');
}

void display_square(int width)
{
    if (width <= 0)
        return;
    if (width == 1)
    {
        putchar('*');
        putchar('\n');
        return;
    }

    if (width % 2 == 0)
    {
        width += 1;
        display_trait(width - 1);
        display_square_deluxe(width);
        display_trait(width - 1);
    }

    else if (width % 2 != 0)
    {
        display_trait(width - 1);
        display_square_deluxe(width);
        display_trait(width - 1);
    }
}
