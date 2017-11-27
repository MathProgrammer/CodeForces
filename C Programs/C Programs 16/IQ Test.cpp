#include <cstdio>

int possible_to_make_square(char square[][5], int x, int y)
{
    int black = (square[x][y] == '#') + (square[x - 1][y] == '#') + (square[x - 1][y - 1] == '#') + (square[x][y - 1] == '#');
    int white = (square[x][y] == '.') + (square[x - 1][y] == '.') + (square[x - 1][y - 1] == '.') + (square[x][y - 1] == '.');

    return (black >= 3 || white >= 3);
}

int main()
{
    const int N = 4;
    char square[N + 1][N + 1];

    for(int i = 0; i < N; i++)
        scanf("%s", square[i]);

    int is_possible = false;

    for(int i = 1; i < 4; i++)
    {
        for(int j = 1; j < 4; j++)
        {
            if(possible_to_make_square(square, i, j))
                is_possible = true;
        }
    }

    printf(is_possible ? "YES\n" : "NO\n");
    return 0;
}
