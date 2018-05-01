#include <cstdio>

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);

    const int LIMIT = 43;
    int divisible_by_lcm_1_till_k = true;

    if(k < LIMIT)
    {
        for(int i = 1; i <= k; i++)
        {
            if( (n + 1)%i != 0)
            {
                divisible_by_lcm_1_till_k = false;
                break;
            }
        }
    }

    printf(k < LIMIT && divisible_by_lcm_1_till_k ? "Yes\n" : "No\n");
    return 0;
}
