char *my_strcpy(char *dest, const char *source)
{
    char *beginning = dest;
    while (*source != '\0')
    {
        *dest = *source;
        dest++;
        source++;
    }
    *dest = '\0';
    return beginning;
}
