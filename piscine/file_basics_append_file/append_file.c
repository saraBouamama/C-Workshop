#include <stdio.h>

int append_file(const char *file_in, const char *content)
{
    FILE *file = fopen(file_in, "a");
    if (file == NULL)
    {
        return -1;
    }
    if (fprintf(file, "%s", content) < 0)
        return -1;
    if (fclose(file) == EOF)
        return -1;
    return 0;
}
