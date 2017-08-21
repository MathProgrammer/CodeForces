#include <cstdio>
#define NO_OF_ROWS 10
#define NO_OF_COLUMNS 10

bool horizontal_win(char grid[][NO_OF_COLUMNS + 2], int i, int j)
{
    int no_of_crosses = 0, no_of_dots = 0;

    for(int counter = 0; counter < 5 && i + counter < NO_OF_ROWS; counter++)
    {
        no_of_crosses += (grid[i + counter][j] == 'X');
        no_of_dots += (grid[i + counter][j] == '.');
    }

    return (no_of_crosses == 4 && no_of_dots == 1 ? true : false);
}

bool vertical_win(char grid[][NO_OF_COLUMNS + 2], int i, int j)
{
    int no_of_crosses = 0, no_of_dots = 0;

    for(int counter = 0; counter < 5 && j + counter < NO_OF_COLUMNS; counter++)
    {
        no_of_crosses += (grid[i][j + counter] == 'X');
        no_of_dots += (grid[i][j + counter] == '.');
    }

    return (no_of_crosses == 4 && no_of_dots == 1 ? true : false);
}

bool diagonal_win(char grid[][NO_OF_COLUMNS + 2], int i, int j)
{
    int no_of_crosses = 0, no_of_dots = 0;

    for(int counter = 0; counter < 5 && i + counter < NO_OF_ROWS && j + counter < NO_OF_COLUMNS; counter++)
    {
        no_of_crosses += (grid[i + counter][j + counter] == 'X');
        no_of_dots += (grid[i + counter][j + counter] == '.');
    }

    return (no_of_crosses == 4 && no_of_dots == 1 ? true : false);
}

bool anti_diagonal_win(char grid[][NO_OF_COLUMNS + 2], int i, int j)
{
    int no_of_crosses = 0, no_of_dots = 0;

    for(int counter = 0; counter < 5 && i + counter <= NO_OF_ROWS && j - counter >= 0; counter++)
    {
        no_of_crosses += (grid[i + counter][j - counter] == 'X');
        no_of_dots += (grid[i + counter][j - counter] == '.');
    }

    return (no_of_crosses == 4 && no_of_dots == 1 ? true : false);
}

int main()
{
    bool win_possible = false;
    char grid[NO_OF_ROWS][NO_OF_COLUMNS + 2];

    for(int i = 0; i < NO_OF_ROWS; i++)
        scanf("%s", grid[i]);

    for(int i = 0; i < NO_OF_ROWS; i++)
    {
        for(int j = 0; j < NO_OF_COLUMNS; j++)
        {
            if(horizontal_win(grid, i, j) || vertical_win(grid, i, j) || diagonal_win(grid, i, j) || anti_diagonal_win(grid, i, j))
            {
                win_possible = true;
                break;
            }
        }
    }

    printf(win_possible ? "YES\n" : "NO\n");
    return 0;
}
