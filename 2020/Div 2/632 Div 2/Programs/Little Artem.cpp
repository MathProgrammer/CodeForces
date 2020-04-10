#include <iostream>

using namespace std;

const int MAX_N = 105;
char grid[MAX_N][MAX_N];

void solve()
{
    int rows, columns;
    cin >> rows >> columns;
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            switch((i + j)%2)
            {
                case 0 : grid[i][j] = 'B'; break;
                case 1 : grid[i][j] = 'W'; break;
            }
        }
    }
    
    grid[rows][columns] = 'B';
    
    if(rows%2 == 0 && columns%2 == 0)
    {
        grid[rows][1] = 'B';
    }
    
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cout << grid[i][j];
        }
        
        cout << "\n";
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while (no_of_test_cases--)
        solve();
    
    return 0;
}
