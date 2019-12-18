#include <iostream>

using namespace std;

const int MAX_N = 67;
char grid[MAX_N][MAX_N];

int full_row_a(int r, int columns)
{
    for(int c = 0; c < columns; c++)
    {
        if(grid[r][c] != 'A')
        {
            return false;
        }
    }
    
    return true;
}

int full_column_a(int rows, int c)
{
    for(int r = 0; r < rows; r++)
    {
        if(grid[r][c] != 'A')
        {
            return false;
        }
    }
    
    return true;
}

int all_p(int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(grid[i][j] == 'A')
            {
                return false;
            }
        }
    }
    
    return true;
}

int all_a(int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            if(grid[i][j] == 'P')
            {
                return false;
            }
        }
    }
    
    return true;
}

int corner_square(int rows, int columns)
{
    return (grid[0][0] == 'A' || grid[0][columns - 1] == 'A' ||
            grid[rows - 1][0] == 'A' || grid[rows - 1][columns - 1] == 'A');
}

int corner_edge_square(int rows, int columns)
{
    for(int c = 0; c < columns; c++)
    {
        if(grid[0][c] == 'A' || grid[rows - 1][c] == 'A')
        {
            return true;
        }
    }
    
    for(int r = 0; r < rows; r++)
    {
        if(grid[r][0] == 'A' || grid[r][columns - 1] == 'A')
        {
            return true;
        }
    }
    
    return false;
}

int full_corner_edges(int rows, int columns)
{
    if(full_row_a(0, columns) || full_row_a(rows - 1, columns))
    {
        return true;
    }
    
    if(full_column_a(rows, 0) || full_column_a(rows, columns - 1))
    {
        return true;
    }
    
    return false;
}

int any_full_edge(int rows, int columns)
{
    for(int i = 0; i < rows; i++)
    {
        if(full_row_a(i, columns))
        {
            return true;
        }
    }
    
    for(int i = 0; i < columns; i++)
    {
        if(full_column_a(rows, i))
        {
            return true;
        }
    }
    
    return false;
}

void solve()
{
    int rows, columns;
    cin >> rows >> columns;
    
    for(int i = 0; i < rows; i++)
    {
        cin >> grid[i];
    }
    
    if(all_p(rows, columns))
    {
        cout << "MORTAL\n";
        
        return;
    }
    else if(all_a(rows, columns))
    {
        cout << "0\n";
        
        return;
    }
    else if(full_corner_edges(rows, columns))
    {
        cout << "1\n";
        
        return;
    }
    else if(corner_square(rows, columns) || any_full_edge(rows, columns))
    {
        cout << "2\n";
        
        return;
    }
    else if(corner_edge_square(rows, columns))
    {
        cout << "3\n";
        
        return;
    }
    else
    {
        cout << "4\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
