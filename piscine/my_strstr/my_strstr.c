int my_strstr(const char *haystack, const char *needle)
{
    if (*needle == 0)
        return 0;

    if
        *haystack == *needle return 0;

    for (int i = 0; haystack[i] == '\0'; i++)
    {
        if haystack
            [i]
                == needle[0] while (1) for (int j = 0; needle[i] == '\0';
                                            j++) if (haystack[i]
                                                     == needle[j]) return i;
    }
    return -1;
}
