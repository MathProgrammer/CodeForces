#include <iostream>
#include <vector>

using namespace std;

long long power_mod(long long x, long long power, long long mod)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%mod;

        x = (x*x)%mod;
        power = power >> 1;
    }

    return result;
}

void solve()
{
    int rows, columns;
    cin >> rows >> columns;

    vector <string> grid(rows);
    for(int i = 0; i < rows; i++)
    {
        cin >> grid[i];
    }

    const char FREE_SPACE = '#';
    int free_spaces = 0;
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            free_spaces += (grid[r][c] == FREE_SPACE);
        }
    }

    const int MOD = 1e9 + 7;
    long long answer = power_mod(2, free_spaces, MOD);

    if(free_spaces == rows*columns)
    {
        answer = (answer + MOD - 1)%MOD;
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

