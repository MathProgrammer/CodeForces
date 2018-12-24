#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

typedef long long LL;

LL gcd(LL x, LL y)
{
    if(x == 0 || y == 0)
        return (x + y);
    else
        return gcd(min(x, y), max(x, y)%min(x, y));
}

void solve()
{
    LL numerator, denominator, base;
    scanf("%I64d %I64d %I64d", &numerator, &denominator, &base);

    LL gcd_fraction = gcd(numerator, denominator);
    numerator /= gcd_fraction;
    denominator /= gcd_fraction;

    base = gcd(base, denominator);

    while(base > 1)
    {
        while(denominator%base == 0) denominator /= base;

        base = gcd(base, denominator);
    }

    printf(denominator == 1 ? "Finite\n" : "Infinite\n");
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
        solve();

    return 0;
}
