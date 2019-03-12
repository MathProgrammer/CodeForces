#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

int main()
{
    int rows, columns;
    cin >> rows >> columns;

    int max_diagonals = rows + columns;
    vector <int> A_diagonals[max_diagonals + 5];
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            int x;
            cin >> x;

            int diagonal_no = i + j;
            A_diagonals[diagonal_no].push_back(x);
        }
    }

    vector <int> B_diagonals[max_diagonals + 5];
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            int x;
            cin >> x;

            int diagonal_no = i + j;
            B_diagonals[diagonal_no].push_back(x);
        }
    }

    int possible = true;
    for(int i = 1; i <= max_diagonals; i++)
    {
        sort(all(A_diagonals[i]));
        sort(all(B_diagonals[i]));

        if(A_diagonals[i] != B_diagonals[i])
        {
            possible = false;
            break;
        }
    }

    cout << (possible ? "Yes\n" : "No\n");
    return 0;
}
