#include <cstdio>

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);

    const int LIMIT = 43;
    int divisible_by_lcm = true;

    if(k < LIMIT)
    {
        for(int i = 1; i <= k; i++)
        {
            if( (n + 1)%i != 0)
            {
                divisible_by_lcm = false;
                break;
            }
        }
    }

    printf(k < LIMIT && divisible_by_lcm ? "Yes\n" : "No\n");
    return 0;
}
