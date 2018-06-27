#include <cstdio>

typedef long long LL;

LL power_mod(LL x, LL power, LL MOD)
{
    LL result = 1;

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
    long long initial, months;
    scanf("%I64d %I64d", &initial, &months);

    if(initial == 0)
    {
        printf("0\n");
        return 0;
    }

    const int MOD = 1e9 + 7;
    initial %= MOD;

    long long answer = (initial*power_mod(2, months + 1, MOD))%MOD - power_mod(2, months, MOD) + 1;
    answer = (answer + MOD)%MOD;


    printf("%I64d\n", answer);
    return 0;
}
