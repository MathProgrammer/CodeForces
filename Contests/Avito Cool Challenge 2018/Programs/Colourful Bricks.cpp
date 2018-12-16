#include <cstdio>
#include <vector>

using namespace std;

long long power_mod(long long base, long long power, long long mod)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*base)%mod;

        base = (base*base)%mod;
        power = power >> 1;
    }

    return result;
}

long long inverse(long long n, long long mod)
{
    return power_mod(n, mod - 2, mod);
}

long long choose(long long n, long long r, long long mod)
{
    vector <long long> factorial(n + 1);
    factorial[0] = 1;
    for(int i = 1; i <= n; i++)
        factorial[i] = (i*factorial[i - 1])%mod;

    vector <long long> inverse_factorial(n + 1); // i*(i - 1)! = i! => i^(-1) (i - 1)!^(-1) = i!^(-1)
    inverse_factorial[n] = inverse(factorial[n], mod);
    for(int i = n - 1; i >= 0; i--)
        inverse_factorial[i] = ((i + 1)*inverse_factorial[i + 1])%mod;

    long long numerator = factorial[n];
    long long denominator_inverse = (inverse_factorial[r]*inverse_factorial[n - r])%mod;

    return (numerator*denominator_inverse)%mod;
}

int main()
{
    int no_of_bricks, no_of_colours, no_of_divisions;
    scanf("%d %d %d", &no_of_bricks, &no_of_colours, &no_of_divisions);

    int no_of_groups = no_of_divisions + 1;

    const int MOD = 998244353;
    long long group_size_count = choose(no_of_bricks - 1, no_of_divisions, MOD);
    long long colour_distribution_count = (no_of_colours* power_mod(no_of_colours - 1,no_of_groups - 1, MOD))%MOD;

    long long answer = (group_size_count*colour_distribution_count)%MOD;

    printf("%I64d\n", answer);
    return 0;
}
