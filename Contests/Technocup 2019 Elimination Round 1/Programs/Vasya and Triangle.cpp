#include <cstdio>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
typedef long long LL;

LL gcd(LL a, LL b)
{
    if(a == 0 || b == 0)
        return (a + b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

int main()
{
    LL x_limit, y_limit, k;
    scanf("%I64d %I64d %I64d", &x_limit, &y_limit, &k);

    //2*Area = (2mn)/k ... K should divide 2mn
    LL g = gcd(x_limit, k);
    LL x = x_limit/g;
    k /= g;

    g = gcd(y_limit, k);
    LL y = y_limit/g;
    k /= g;

    if(k == 1)
    {
        if(2*x <= x_limit)
            x = 2*x;
        else
            y = 2*y;
    }

    if(k <= 2)
    {
        printf("YES\n");
        printf("0 0\n%I64d 0\n0 %I64d\n", x, y);
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
