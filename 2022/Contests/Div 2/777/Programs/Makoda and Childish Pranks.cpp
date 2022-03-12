#include <iostream>
#include <vector>

using namespace std;

const int NO_OF_NEIGHBOURS = 4;
const char BLACK = '1', WHITE = '0';
int X[NO_OF_NEIGHBOURS] = {-1, 0, 0, 1}, Y[NO_OF_NEIGHBOURS] = {0, 1, -1, 0};

struct rectangle
{
    int x1, y1, x2, y2;

    rectangle(int X1, int Y1, int X2, int Y2)
    {
        x1 = X1 + 1;
        y1 = Y1 + 1;
        x2 = X2 + 1;
        y2 = Y2 + 1;
    }
};

void solve()
{
    int no_of_rows, no_of_columns;
    cin >> no_of_rows >> no_of_columns;

    vector <string> grid(no_of_rows);
    for(int i = 0; i < no_of_rows; i++)
    {
        cin >> grid[i];
    }

    if(grid[0][0] == BLACK)
    {
        cout << "-1\n";
        return;
    }

    vector <rectangle> moves;
    for(int i = no_of_rows - 1; i >= 0; i--)
    {
        for(int j = no_of_columns - 1; j >= 0; j--)
        {
            if(grid[i][j] == BLACK)
            {
                if(j > 0)
                {
                    moves.push_back(rectangle(i, j - 1, i, j));
                }
                else if(i > 0)
                {
                    moves.push_back(rectangle(i - 1, j, i, j));
                }
            }
        }
    }

    cout << moves.size() << "\n";
    for(rectangle current_rectangle : moves)
    {
        cout << current_rectangle.x1 << " " << current_rectangle.y1 << " " << current_rectangle.x2 << " " << current_rectangle.y2 << "\n";
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





