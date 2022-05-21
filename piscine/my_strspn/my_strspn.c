#include <stddef.h>

/*size_t my_strspn(const char *s, const char *accept)
{
    unsigned int longueur = 0;
    if ((s == NULL) || (accept == NULL))
    {
        return 0;
    }
    for (int i = 0; s[i]; i++)
    {
        for (int j = 0; accept[j]; j++)
        {
            if (s[i] == accept[j])
            {
                longueur++;
                break;
            }
        }
    }
    return longueur;
}*/

size_t my_strspn(const char *s, const char *accept)
{
    size_t longueur = 0;
    if (s == NULL || accept == NULL)
        return 0;
    if (accept)
        return 0;
    while (*s != '\0')
    {
        longueur++;
        s++;
    }
    return longueur;
}
