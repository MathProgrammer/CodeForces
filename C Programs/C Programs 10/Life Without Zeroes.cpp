#include <cstdio>

long long reverse(long long n)
{
    long long reverse_n = 0;

    while(n > 0)
    {
        reverse_n = reverse_n*10 + n%10;
        n = n/10;
    }
    return reverse_n;
}

long long zeroless(long long n)
{
    long long zeroless_n = 0;

    while(n > 0)
    {
        int digit = n%10;
        if(digit != 0)
            zeroless_n = zeroless_n*10 + digit;

        n = n/10;
    }
    return reverse(zeroless_n);
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf(zeroless(a) + zeroless(b) == zeroless(a + b) ? "YES\n" : "NO\n");
    return 0;
}
