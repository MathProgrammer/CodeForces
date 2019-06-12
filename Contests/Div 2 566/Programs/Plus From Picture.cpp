#include <cstdio>
#include <cstring>

const int MAX_N = 505;
const char STAR = '*', EMPTY = '.';
char grid[MAX_N][MAX_N];
int up[MAX_N][MAX_N], down[MAX_N][MAX_N], left[MAX_N][MAX_N], right[MAX_N][MAX_N];

int main()
{
    int height, width;
    scanf("%d %d", &height, &width);

    for(int i = 1; i <= height; i++)
    {
        scanf("%s", grid[i] + 1);
    }

    memset(up, 0, sizeof(up));
    memset(left, 0, sizeof(left));
    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            up[i][j] = (grid[i][j] == STAR ? 1 + up[i - 1][j] : 0);
            left[i][j] = (grid[i][j] == STAR ? 1 + left[i][j - 1] : 0);
        }
    }

    memset(down, 0, sizeof(down));
    memset(right, 0, sizeof(right));
    for(int i = height; i >= 1; i--)
    {
        for(int j = width; j >= 1; j--)
        {
            down[i][j] = (grid[i][j] == STAR ? 1 + down[i + 1][j] : 0);
            right[i][j] = (grid[i][j] == STAR ? 1 + right[i][j + 1] : 0);
        }
    }

    int no_of_plus_centers = 0, center_i = 0, center_j = 0;
    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            if(down[i][j] >= 2 && right[i][j] >= 2 && up[i][j] >= 2 && left[i][j] >= 2)
            {
                no_of_plus_centers++;

                center_i = i, center_j = j;
            }
        }
    }

    int possible = true;

    if(no_of_plus_centers != 1)
    {
        possible = false;
    }

    for(int i = 1; i <= height; i++)
    {
        for(int j = 1; j <= width; j++)
        {
            if(grid[i][j] == EMPTY) continue;

            if(i != center_i && j != center_j)
            {
                possible = false;
            }

            if(i < center_i && i + up[center_i][center_j]  - 1 < center_i)
            {
                possible = false;
            }
            if(center_i < i && center_i + down[center_i][center_j] - 1 < i)
            {
                possible = false;
            }
            if(j < center_j && j + left[center_i][center_j] - 1 < center_j)
            {
                possible = false;
            }
            if(center_j < j && center_j + right[center_i][center_j] - 1 < j)
            {
                possible = false;
            }
        }
    }

    printf("%s", (possible ? "YES\n" : "NO\n"));
    return 0;
}
