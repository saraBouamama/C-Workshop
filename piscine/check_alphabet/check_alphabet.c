#include <stddef.h>

int check_alphabet(const char *str, const char *alphabet)
{
    if (!alphabet || alphabet[0] == '\0')
        return 1;
    else
    {
        size_t i = 0;
        int erreur = 0;
        while (alphabet[i] != '\0' && erreur == 0)
        {
            size_t j = 0;
            while (str[j] != '\0' && str[j] != alphabet[i])
                j++;
            if (str[j] == '\0')
                erreur++;
            i++;
        }
        if (erreur != 0)
            return 0;
        return 1;
    }
}
