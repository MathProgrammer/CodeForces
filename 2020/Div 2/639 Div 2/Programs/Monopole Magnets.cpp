#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int MAX_N = 1005, NO_OF_NEIGHOURS = 4;
const char BLACK = '#', WHITE = '.';
char grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int next_r[NO_OF_NEIGHOURS] = {-1, 0, 0, 1};
int next_c[NO_OF_NEIGHOURS] = {0, 1, -1, 0};
int rows, columns;

int inside_grid(int x, int y)
{
    return (1 <= x && x <= rows && 1 <= y && y <= columns);
}

void dfs(int x, int y)
{
    visited[x][y] = true;
    
    for(int n = 0; n < NO_OF_NEIGHOURS; n++)
    {
        int next_x = x + next_r[n];
        int next_y = y + next_c[n];
        
        if(inside_grid(next_x, next_y) && grid[next_x][next_y] == BLACK && !visited[next_x][next_y])
        {
            dfs(next_x, next_y);
        }
    }
}

int main()
{
    scanf("%d %d", &rows, &columns);
    
    for(int i = 1; i <= rows; i++)
    {
        scanf("%s", grid[i] + 1);
    }
    
    vector <int> row_frequency(rows + 1);
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(grid[i][j] == BLACK)
            {
                row_frequency[i]++;
            }
        }
    }
    
    vector <int> column_frequency(columns + 1);
    for(int j = 1; j <= columns; j++)
    {
        for(int i = 1; i <= rows; i++)
        {
            if(grid[i][j] == BLACK)
            {
                column_frequency[j]++;
            }
        }
    }
    
    int possible = true, all_white_row = false, all_white_column = false;
    for(int i = 1; i <= rows; i++)
    {
        int black_cells = 0;
        
        for(int j = 1; j <= columns; j++)
        {
            if(grid[i][j] == BLACK)
            {
                black_cells++;
                
                if(j + 1 <= columns && grid[i][j + 1] == WHITE && black_cells != row_frequency[i])
                {
                    possible = false;
                    break;
                }
            }
        }
        
        if(row_frequency[i] == 0)
        {
            all_white_row = true;
        }
    }
    
    for(int j = 1; j <= columns; j++)
    {
        int black_cells = 0;
        
        for(int i = 1; i <= rows; i++)
        {
            if(grid[i][j] == BLACK)
            {
                black_cells++;
                
                if(i + 1 <= rows && grid[i + 1][j] == WHITE && black_cells != column_frequency[j])
                {
                    possible = false;
                    break;
                }
            }
        }
        
        if(column_frequency[j] == 0)
        {
            all_white_column = true;
        }
    }
    
    if( (all_white_row && !all_white_column) || (!all_white_row && all_white_column) )
    {
        possible = false;
    }
    
    if(!possible)
    {
        cout << "-1\n";
        
        return 0;
    }
    
    int no_of_components = 0;
    memset(visited, false, sizeof(visited));
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(grid[i][j] == BLACK && !visited[i][j])
            {
                dfs(i, j);
                no_of_components++;
            }
        }
    }
    
    cout << no_of_components << "\n";
    return 0;
}
