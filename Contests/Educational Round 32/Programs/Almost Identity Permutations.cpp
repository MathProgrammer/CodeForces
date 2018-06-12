#include <cstdio>

long long choose(int n, int r)
{
    if(r == 0 || r == n)
        return 1;
    if(r == 1 || r == n - 1)
        return n;

    return choose(n - 1, r) + choose(n - 1, r - 1);
}

long long derangements(int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    return (n - 1)*(derangements(n - 1) + derangements(n - 2));
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);

    long long answer = 0;
    for(int i = 0; i <= k; i++)
    {
        answer += choose(n, i)*derangements(i);
    }

    printf("%I64d\n", answer);
    return 0;
}
