#include <assert.h>
#include <err.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int insert_line(const char *file, const char *file_out, const char *content,
                size_t n)
{
    if (!file || !file_out || !content)
        return -1;

    FILE *file_temp = fopen(file, "r");
    FILE *out = fopen(file_out, "w");
    if (!file_temp || !out)
        return -1;

    int read;
    char *line;
    size_t size = 0;
    size_t i = 0;
    int booll = 0;

    for (; (read = getline(&line, &size, file_temp)) != -1; i++)
    {
        if (i == n)
        {
            booll = 1;
            fputs(content, out);
        }
        fputs(line, out);
    }

    if (!booll)
    {
        for (; i != n; i++)
            fputs("\n", out);
        fputs(content, out);
    }

    fclose(out);
    fclose(file_temp);

    int count = 0;
    FILE *temp = fopen(file_out, "r");
    for (; getline(&line, &size, temp) != -1; count++)
        continue;
    fclose(temp);
    free(line);
    return count;
}
