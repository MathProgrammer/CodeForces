#include <cstdio>
#include <cstring>

const int MAX_BIT = 61, MAX_N = 55;
typedef long long LL;

int no_of_elements, no_of_parts;
LL A[MAX_N], sum[MAX_N];
int possible[MAX_N][MAX_N];

int is_possible(LL goal)
{
    memset(possible, false, sizeof(possible));

    possible[0][0] = true;

    for(int part = 1; part <= no_of_parts; part++)
    {
        for(int right = 1; right <= no_of_elements; right++)
        {
            for(int left = 0; left < right; left++)
            {
                if( possible[left][part - 1] && ( ( (sum[right] - sum[left])&goal ) == goal ) )
                {
                    possible[right][part] = true;
                    break;
                }
            }
        }
    }

    return possible[no_of_elements][no_of_parts];
}

int main()
{
    scanf("%d %d", &no_of_elements, &no_of_parts);

    for(int i = 1; i <= no_of_elements; i++)
        scanf("%I64d", &A[i]);

    sum[0] = 0;
    for(int i = 1; i <= no_of_elements; i++)
        sum[i] = sum[i - 1] + A[i];

    LL answer = 0;

    for(int bit = MAX_BIT; bit >= 0; bit--)
    {
        if(is_possible(answer|(1LL << bit)))
        {
            answer |= (1LL << bit);
        }
    }

    printf("%I64d\n", answer);
    return 0;
}
