#include <cstdio>

int is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    int prime_in_middle = false;
    for(int i = x + 1; i < y; i++)
    {
        if(is_prime(i))
        {
            prime_in_middle = true;
            break;
        }
    }

    printf(!prime_in_middle && is_prime(y) ? "YES\n" : "NO\n");
    return 0;
}
