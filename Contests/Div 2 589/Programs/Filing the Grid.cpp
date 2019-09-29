#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

LL power_mod(LL n, LL power, LL mod)
{
    LL result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*n)%mod;

        n = (n*n)%mod;
        power = power >> 1;
    }

    return result;
}

int main()
{
    int rows, columns;
    cin >> rows >> columns;

    vector <int> blocked_cells_row(rows + 3, 0);
    for(int i = 1; i <= rows; i++)
        cin >> blocked_cells_row[i];

    vector <int> blocked_cells_column(columns + 3, 0);
    for(int i = 1; i <= columns; i++)
        cin >> blocked_cells_column[i];

    for(int i = 1; i <= rows; i++)
    {
        int first_empty_column = blocked_cells_row[i] + 1;

        if(blocked_cells_column[first_empty_column] >= i)
        {
            cout << "0\n";

            return 0;
        }
    }

    for(int j = 1; j <= columns; j++)
    {
        int first_empty_row = blocked_cells_column[j] + 1;

        if(blocked_cells_row[first_empty_row] >= j)
        {
            cout << "0\n";

            return 0;
        }
    }

    LL free_cells = 0;
    for(int i = 1; i <= rows; i++)
    {
        for(int j = 1; j <= columns; j++)
        {
            if(i <= blocked_cells_column[j] + 1 || j <= blocked_cells_row[i] + 1)
            {
                continue;
            }
            else
            {
                free_cells++;
            }
        }
    }

    const LL MOD = 1e9 + 7;
    LL answer = power_mod(2, free_cells, MOD);
    cout << answer << "\n";

    return 0;
}
