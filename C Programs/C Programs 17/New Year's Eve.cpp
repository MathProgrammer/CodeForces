#include <cstdio>

int no_of_bits(long long n)
{
    int bit_count = 0;

    while(n)
    {
        n = n >> 1;
        bit_count++;
    }

    return bit_count;
}

int main()
{
    long long n, k;
    scanf("%I64d %I64d", &n, &k);

    long long answer;

    if(k == 1)
    {
        answer = n;
    }
    else
    {
        answer = (1LL << no_of_bits(n) ) - 1;
    }

    printf("%I64d\n", answer);
    return 0;
}
