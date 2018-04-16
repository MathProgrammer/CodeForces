#include <cstdio>

long long all_ones(int n)
{
    return (1LL << (n + 1)) - 1;
}

int main()
{
    long long left, right;
    scanf("%I64d %I64d", &left, &right);

    if(left == right)
    {
        printf("0\n");
        return 0;
    }

    int largest_unequal_bit_position;

    for(int i = 0; left > 0 || right > 0; i++)
    {
        if(left%2 != right%2)
            largest_unequal_bit_position = i;

        left >>= 1;
        right >>= 1;
    }

    long long answer = all_ones(largest_unequal_bit_position); //This gives a number consisting of n 1's in binary
    printf("%I64d\n", answer);

    return 0;
}
