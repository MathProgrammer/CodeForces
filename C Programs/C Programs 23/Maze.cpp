#include <cstdio>
#include <cstring>

const int MAX_N = 505;

int visited[MAX_N][MAX_N];
char grid[MAX_N][MAX_N];
int no_of_visits = 0, rows, columns;

void dfs(int r, int c, int target)
{
    if(no_of_visits >= target)
        return;

    visited[r][c] = true;

    no_of_visits++;

    const int NO_OF_NEIGHBOURS = 4;
    int next_x[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1};
    int next_y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};

    for(int i = 0; i < NO_OF_NEIGHBOURS; i++)
    {
        int next_r = r + next_x[i], next_c = c + next_y[i];

        if(0 < next_r && next_r <= rows && 0 < next_c && next_c <= columns &&
           !visited[next_r][next_c] && grid[next_r][next_c] == '.')
        {
            dfs(next_r, next_c, target);
        }
    }
}

int main()
{
    int k;
    scanf("%d %d %d", &rows, &columns, &k);

    for(int i = 1; i <= rows; i++)
        scanf("%s", grid[i] + 1);

    memset(visited, sizeof(visited), false);

    int total_free = 0;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            total_free += (grid[i][j] == '.');
        }
    }

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(grid[i][j] == '.')
            {
                dfs(i, j, total_free - k);

                break;
            }
        }
    }

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            printf("%c", (grid[i][j] == '.' && !visited[i][j]) ? 'X' : grid[i][j]);
        }

        printf("\n");
    }

    return 0;
}
