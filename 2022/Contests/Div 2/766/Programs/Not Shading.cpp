#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int rows, columns, x, y;
    cin >> rows >> columns >> x >> y;

    vector <string> grid(rows);
    for(int i = 0; i < rows; i++)
    {
        cin >> grid[i];
    }
    x--;
    y--;

    int answer = -1;

    int black_count = 0, black_row_count = 0, black_column_count = 0;
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            if(grid[r][c] == 'B')
            {
                black_count++;

                if(r == x)
                {
                    black_row_count++;
                }

                if(c == y)
                {
                    black_column_count++;
                }
            }
        }
    }

    if(grid[x][y] == 'B')
    {
        answer = 0;
    }
    else if(black_row_count > 0 || black_column_count > 0)
    {
        answer = 1;
    }
    else if(black_count > 0)
    {
        answer = 2;
    }
    else
    {
        answer = -1;
    }

    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
