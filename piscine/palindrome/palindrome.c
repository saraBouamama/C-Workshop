#include <errno.h>
#include <stddef.h>

size_t my_strlen(const char *s)
{
    size_t length = 0;
    if (s == NULL)
        return 0;
    while (s[length] != '\0')
        length++;
    return length;
}

int palindrome(const char *s)
{
    size_t len = my_strlen(s);
    if (s == NULL)
        return 0;
    else if (len == 0 || len == 1)
        return 1;
    size_t droite = len - 1;
    size_t gauche = 0;
    int erreur = 0;
    while (erreur == 0 && gauche <= droite)
    {
        if (s[gauche] == s[droite])
        {
            gauche++;
            droite--;
        }
        else if (s[gauche] < '0' || (s[gauche] > '9' && s[gauche] < 'A')
                 || (s[gauche] > 'Z' && s[gauche] < 'a') || s[gauche] > 'z')
            gauche++;
        else if (s[droite] < '0' || (s[droite] > '9' && s[droite] < 'A')
                 || (s[droite] > 'Z' && s[droite] < 'a') || s[droite] > 'z')
            droite--;
        else
            erreur = 1;
    }
    if (erreur == 0)
        return 1;
    return 0;
}
