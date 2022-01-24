#include <iostream>
#include <vector>

using namespace std;

long long power_mod(long long x, long long power, long long m)
{
    long long result = 1;

    while(power > 0)
    {
        if(power%2 == 1)
            result = (result*x)%m;

        x = (x*x)%m;
        power = power >> 1;
    }

    return result;
}

long long inverse(long long x, long long m)
{
    return power_mod(x, m - 2, m);
}

void solve()
{
    long long no_of_moves, add_moves, range;
    cin >> no_of_moves >> add_moves >> range;

    const int MOD = 1e9 + 7;
    vector <vector <long long> > score(no_of_moves + 1, vector <long long> (add_moves + 1, 0));
    for(int i = 0; i <= no_of_moves; i++)
    {
        for(int j = 0; j <= add_moves; j++)
        {
            if(i == 0 || j == 0)
            {
                score[i][j] = 0;
                continue;
            }
            if(j == i)
            {
                score[i][j] = (range*j)%MOD;
                continue;
            }

            score[i][j] = (score[i - 1][j - 1] + score[i - 1][j])%MOD;
            score[i][j] *= inverse(2, MOD);
            score[i][j] %= MOD; //cout << "F(" << i << "," << j << ") = " << score[i][j] << "\n";
        }
    }

    cout << score[no_of_moves][add_moves] << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

