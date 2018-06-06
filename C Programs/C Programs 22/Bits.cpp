#include <cstdio>

long long all_ones(int n)
{
    return (1LL << n) - 1;
}

int is_set(long long n, int bit)
{
    return ((n & (1LL << bit)) != 0);
}

int no_of_bits(long long n)
{
    int answer = 0;

    while(n)
    {
        n >>= 1;
        answer++;
    }

    return answer;
}

void solve()
{
    long long left, right;
    scanf("%I64d %I64d", &left, &right);

    long long answer = 0;

    if(all_ones(no_of_bits(right)) == right)
    {
        answer = right;
    }
    else if(no_of_bits(left) != no_of_bits(right))
    {
        answer = all_ones(no_of_bits(right) - 1);
    }
    else if(no_of_bits(left) == no_of_bits(right))
    {
        for(int bit = 63; bit >= 0; bit--)
        {
            if(is_set(left, bit) && is_set(right, bit))
            {
                answer |= (1LL << bit);
            }
            else if(!is_set(left, bit) && is_set(right, bit)) //If L[i] = 0, and R[i] = 1
            {
                answer |= all_ones(bit); //Setting the current bit to 0, and then padding with 1s till the end.

                if((answer|(1LL << bit)) <= right) //Checking if the current bit can also be 1
                    answer |= (1LL << bit);
            }
        }
    }

    printf("%I64d\n", answer);
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
        solve();

    return 0;
}
