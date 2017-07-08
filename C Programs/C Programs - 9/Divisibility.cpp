#include <cstdio>

#define abs(x) ( (x) > 0 ? (x) : -(x) )
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int main()
{
    long long k, left, right, no_of_multiples = 0;
    scanf("%I64d %I64d %I64d", &k, &left, &right);

    if(right > 0 && left < 0)
    {
        left = abs(left);

        no_of_multiples = (right)/k + (left)/k + 1; //Add 0 as a multiple as well.
    }
    else
    {
        long long greater_limit = max(abs(right), abs(left));
        long long lower_limit = min(abs(right), abs(left));

        if(lower_limit == 0)
        {
            no_of_multiples = (greater_limit)/k + 1; //Count 0 as well
        }
        else
        {
            no_of_multiples = (greater_limit)/k - (lower_limit - 1)/k;
        }
    }

    printf("%I64d\n", no_of_multiples);
    return 0;
}
