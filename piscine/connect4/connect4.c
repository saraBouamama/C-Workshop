#include <stddef.h>

int connect4(char *game[], size_t columns, size_t lines)
{
    for (int c = 0; c <= columns; c++)
    {
        for (int l = 0; l <= lines; l++)
        {
            if (game[c][l] == game[c + 1][l] && game[c + 1][l] == game[c + 2][l]
                && game[c + 2][l] == game[c + 3][l]
                && game[c + 3][l] == game[c + 4][l])
            {
                if (game[c][l] == 'X')
                    return 1;
                else if (game[c][l] == 'O')
                    return 2;
            }
            if (game[c][l] == game[c - 1][l + 1] && game[c - 1][l + 1] == game[c - 2][l + 2] && game[c - 2][l + 2] == game[c - 3][l + 3] &&
