#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }

    char a = argv[2][0];
    for (char i = '0'; i < a; i++)
    {
        puts(argv[1]);
    }
    return 0;
}
