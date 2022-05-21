#include <err.h>
#include <stdio.h>
int count(const char *file_1)
{
    int res = 0;
    char c;
    FILE *fp = fopen(file_1, "r");
    if (fp == NULL)
        errx(-1, "error opening the file");
    for (c = getc(fp); c != EOF; c = getc(fp))
        if (c == '\n')
            res++;
    fclose(fp);
    return res;
}

int merge_files(const char *file_1, const char *file_2)
{
    char buffer[256];

    FILE *fd1 = fopen(file_1, "a");
    FILE *fd2 = fopen(file_2, "r");
    if (fd1 == NULL || fd2 == NULL)
    {
        errx(-1, "error opening the file");
    }
    while (fgets(buffer, sizeof(buffer), fd2))
    {
        fprintf(fd1, "%s", buffer);
    }
    return count(file_1);
}
