#include <cstdio>

int main()
{
    int n, sum_limit;
    long long square_sum_lower_bound;
    scanf("%d %I64d %d", &n, &square_sum_lower_bound, &sum_limit);

    long long largest_element = sum_limit - (n - 1);
    long long max_square_sum = (n - 1) + largest_element*largest_element;

    if(max_square_sum < square_sum_lower_bound || n > sum_limit)
    {
        printf("-1\n");
        return 0;
    }

    for(int i = 1; i <= n; i++)
        printf("%I64d\n", (i == n ? largest_element : 1));

    return 0;
}
