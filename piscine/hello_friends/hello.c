#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
        printf("Hello World!\n");
    for (int i = 1; i < argc; i++)
    {
        printf("Hello %s!\n", argv[i]);
    }
    return 0;
}
