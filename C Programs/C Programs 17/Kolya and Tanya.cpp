#include <cstdio>

long long power_mod(long long x, int power, int MOD)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%MOD;

        x = (x*x)%MOD;
        power = power >> 1;
    }

    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    const int MOD = 1e9 + 7;
    long long no_of_ways = power_mod(27, n, MOD) + (MOD - power_mod(7, n, MOD));

    no_of_ways %= MOD;

    printf("%I64d\n", no_of_ways);
    return 0;
}
