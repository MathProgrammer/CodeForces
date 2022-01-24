#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7, MAX_N = 1e6 + 5;
long long factorial[MAX_N], inverse_factorial[MAX_N];

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

void precompute()
{
    factorial[0] = 1;
    for(int i = 1; i < MAX_N; i++)
    {
        factorial[i] = (i*factorial[i - 1])%MOD;
    }

    inverse_factorial[MAX_N - 1] = inverse(factorial[MAX_N - 1], MOD);
    for(int i = MAX_N - 2; i >= 0; i--)
    {
        inverse_factorial[i] = ((i + 1)*inverse_factorial[i + 1])%MOD;
    }
}

long long choose(long long n, long long r)
{
    long long numerator = factorial[n];
    long long inverse_denominator = (inverse_factorial[r]*inverse_factorial[n - r])%MOD;

    return (numerator*inverse_denominator)%MOD;
}

void solve()
{
    long long no_of_moves, add_moves, range;
    cin >> no_of_moves >> add_moves >> range;

    const int MOD = 1e9 + 7;
    long long score = 0;

    if(add_moves == no_of_moves)
    {
        cout << (range*add_moves)%MOD << "\n";
        return;
    }

    for(int i = 1; i <= add_moves; i++)
    {
        long long base_case = (i*range)%MOD;

        long long total_moves = no_of_moves - i;
        long long total_free_moves = total_moves - 1;
        long long total_side_moves = add_moves - i;

        base_case *= choose(total_free_moves, total_side_moves);
        base_case %= MOD;
        long long power_2 = power_mod(2, total_moves, MOD);

        //cout << "i = " << i << " Number of paths = C(" << total_free_moves <<"," << total_side_moves << ") = " << choose(total_free_moves, total_side_moves) << " 2^i = " << power_2 << "\n";
        long long contribution = (base_case*inverse(power_2, MOD))%MOD;

        score += contribution;
        score %= MOD;
    }
    cout << score << "\n";
}

int main()
{
    precompute();

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}

