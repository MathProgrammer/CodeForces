#include <cstdio>

int is_prime(long long n)
{
    if(n == 1) return false;

    for(long long i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

void solve()
{
    long long a, b;
    scanf("%I64d %I64d", &a, &b);
    printf(a - b == 1 && is_prime(a + b) ? "YES\n" : "NO\n");
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
