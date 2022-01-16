#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int rows, columns;
    cin >> rows >> columns;

    vector <int> distances;
    int row_distance = 0, column_distance = 0;
    for(int r = 1; r <= rows; r++)
    {
        for(int c = 1; c <= columns; c++)
        {
            row_distance = max(rows - r, r - 1);
            column_distance = max(columns - c, c - 1);
            distances.push_back(row_distance + column_distance);
        }

    }

    sort(distances.begin(), distances.end());

    for(int d : distances)
    {
        cout << d << " ";
    }
    cout << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

