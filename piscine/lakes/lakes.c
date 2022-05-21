#include <stdlib.h>

void check(char **map, int **test, int i, int j)
{
    if (map[i][j] == '.' && test[i][j] == 0)
    {
        test[i][j] = 1;
        check(map, test, i + 1, j);
        check(map, test, i - 1, j);
        check(map, test, i, j + 1);
        check(map, test, i, j - 1);
    }
}

int lakes(char **map, int width, int height)
{
    int nblakes = 0;

    int **test = malloc(height * sizeof(int *));
    if (!test)
        return -1;

    for (int index = 0; index < height; index++)
    {
        test[index] = malloc(width * sizeof(int));
        if (!test[index])
            return -1;
        for (int i = 0; i < width; i++)
            test[index][i] = 0;
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            if ((map[row][col] == '.') && (test[row][col] == 0))
            {
                nblakes++;
                check(map, test, row, col);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        free(test[i]);
        test[i] = NULL;
    }
    free(test);
    test = NULL;
    return nblakes;
}
