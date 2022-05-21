#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int helper(char *ptr)
{
    int out;
    char *temp1 = NULL;
    char *temp2 = strtok_r(ptr, ",", &temp1);
    out = atoi(temp2);
    while (temp2)
    {
        int temp3 = atoi(temp2);
        if (temp3 > out)
        {
            out = temp3;
        }
        temp2 = strtok_r(NULL, ",", &temp1);
    }

    return out;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 1;
    FILE *file;
    char *line = NULL;
    size_t size = 0;
    ssize_t temp;

    file = fopen(argv[1], "r");
    if (!file)
        return 1;
    for (int count = 1; (temp = getline(&line, &size, file) != -1); count++)
        printf("%d\n", helper(line));
    if (line)
        free(line);
    if (fclose(file) == EOF)
        return 1;
    return 0;
}
