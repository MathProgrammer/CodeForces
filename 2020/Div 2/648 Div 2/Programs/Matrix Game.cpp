#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int rows, columns;
    cin >> rows >> columns;
    
    vector <int> claimed_row(rows + 1, false), claimed_column(columns + 1, false);
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            int cell;
            cin >> cell;
            
            if(cell != 0)
            {
                claimed_row[i] = true;
                claimed_column[j] = true;
            }
        }
    }
    
    int row_moves = 0;
    for(int i = 1; i <= rows; i++)
    {
        row_moves += (!claimed_row[i]);
    }
    
    int column_moves = 0;
    for(int j = 1; j <= columns; j++)
    {
        column_moves += (!claimed_column[j]);
    }
    
    int moves = min(row_moves, column_moves);
    cout << (moves%2 == 0 ? "Vivek\n" : "Ashish\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
