#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    vector <string> grid(no_of_elements);
    for(int i = 0; i < no_of_elements; i++)
    {
        cin >> grid[i];
    }

    int r_1 = -1, c_1 = -1, r_2 = -1, c_2 = -1;
    for(int i = 0; i < no_of_elements; i++)
    {
        for(int j = 0; j < no_of_elements; j++)
        {
            if(grid[i][j] == '*')
            {
                if(r_1 == -1)
                {
                    r_1 = i; c_1 = j;
                }
                else
                {
                    r_2 = i; c_2 = j;
                }
            }
        }
    }

    grid[r_1][c_2] = grid[r_2][c_1] = '*';

    if(r_1 == r_2)
    {
        int r = (r_1 == 0 ? 1 : 0);
        grid[r][c_1] = grid[r][c_2] = '*';
    }
    else if(c_1 == c_2)
    {
        int c = (c_1 == 0 ? 1 : 0);
        grid[r_1][c] = grid[r_2][c] = '*';
    }

    for(int i = 0; i < no_of_elements; i++)
    {
        cout << grid[i] << "\n";
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

