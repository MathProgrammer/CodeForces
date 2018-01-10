#include <cstdio>
#include <cstring>

int main()
{
    int rows, columns;
    scanf("%d %d", &rows, &columns);

    char cell[rows + 1][columns + 2];
    for(int i = 1; i <= rows; i++)
        scanf("%s", cell[i] + 1);

    int horizontal_dominos[rows + 1][columns + 2] = {{0}};
    int vertical_dominos[rows + 1][columns + 2] = {{0}};

    memset(vertical_dominos, 0, sizeof(vertical_dominos));
    memset(horizontal_dominos, 0, sizeof(horizontal_dominos));

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns + 1; j++)
        {
            horizontal_dominos[i][j] = (cell[i][j] == '.' && cell[i][j - 1] == '.');

            horizontal_dominos[i][j] += horizontal_dominos[i - 1][j] + horizontal_dominos[i][j - 1] - horizontal_dominos[i - 1][j - 1];

            vertical_dominos[i][j] = (cell[i][j] == '.' && cell[i - 1][j] == '.');

            vertical_dominos[i][j] += vertical_dominos[i][j - 1] + vertical_dominos[i - 1][j] - vertical_dominos[i - 1][j - 1];
        }
    }

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int row_1, column_1, row_2, column_2;
        scanf("%d %d %d %d", &row_1, &column_1, &row_2, &column_2);

        int total_horizontal = horizontal_dominos[row_2][column_2]
                              - horizontal_dominos[row_2][column_1] - horizontal_dominos[row_1 - 1][column_2]
                              +horizontal_dominos[row_1 - 1][column_1];


        int total_vertical = vertical_dominos[row_2][column_2]
                           - vertical_dominos[row_2][column_1 - 1] - vertical_dominos[row_1][column_2]
                           + vertical_dominos[row_1][column_1 - 1];

        int total_dominos = total_horizontal + total_vertical;

        printf("%d\n", total_dominos);
    }

    return 0;
}
