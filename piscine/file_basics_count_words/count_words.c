#include <stdio.h>

int count_words(const char *file_in)
{
    FILE *fp = fopen(file_in, "r");
    if (fp == NULL)
        return -1;
    int number = 0;
    int car = fgetc(fp);
    while ((car = fgetc(fp)) != EOF)
    {
        if (car != ' ' && car != '\n' && car != '\t')
        {
            number = number + 1;
            while ((car != ' ' && car != '\n' && car != '\t') && (car != EOF))
            {
                car = fgetc(fp);
            }
        }
    }
    if (fclose(fp) == EOF)
        return -1;
    return number;
}
