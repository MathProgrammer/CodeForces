#include <cstdio>

void solve()
{
    int n;
    scanf("%d", &n);

    long long no_of_ways = 1;

    while(n)
    {
        if(n%2 == 1)
            no_of_ways = no_of_ways << 1;

        n = n >> 1;
    }

    printf("%I64d\n", no_of_ways);
}

int main()
{
    int no_of_test_cases;
    scanf("%d", &no_of_test_cases);

    while(no_of_test_cases--)
        solve();

    return 0;
}
