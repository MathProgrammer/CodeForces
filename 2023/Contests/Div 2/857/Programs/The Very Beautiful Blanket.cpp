#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve()
{
    int rows, columns;
    cin >> rows >> columns;

    vector <vector <long long> > M(rows + 1, vector <long long> (columns + 1));
    for(int i = 1, cell_no = 0; i <= rows; i++)
    {
        M[i][1] = cell_no++;
        M[i][2] = cell_no++;
    }

    for(int i = 1; i <= rows; i++)
    {
        for(int j = 3; j <= columns; j++)
        {
            long long offset = (j << 9);
            int reference_column = (j%2 == 1 ? 1 : 2);

            M[i][j] = M[i][reference_column]^offset;
            M[i][j] = M[i][reference_column]^offset;
        }
    }

    cout << rows*columns << "\n";
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            cout << M[i][j] << " ";
        }

        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}


