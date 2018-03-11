#include <cstdio>

int main()
{
    int rows, columns;
    scanf("%d %d", &rows, &columns);
    char pasture[rows + 5][columns + 5];

    for(int r = 1; r <= rows; r++)
        scanf("%s", pasture[r] + 1);

    int is_possible = true;

    for(int r = 1; r <= rows; r++)
    {
        for(int c = 1; c <= columns; c++)
        {
            if(pasture[r][c] == 'W')
            {
                if(pasture[r + 1][c] == 'S' || pasture[r][c + 1] == 'S' || pasture[r - 1][c] == 'S' || pasture[r][c - 1] == 'S')
                {
                    is_possible = false;
                }
            }
        }
    }

    if(!is_possible)
    {
        printf("No\n");
        return 0;
    }

    printf("Yes\n");
    for(int r = 1; r <= rows; r++)
    {
        for(int c = 1; c <= columns; c++)
        {
            char current_cell = (pasture[r][c] == '.' ? 'D' : pasture[r][c]);

            printf("%c", current_cell);
        }
        printf("\n");
    }

    return 0;
}
