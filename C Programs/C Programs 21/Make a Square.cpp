#include <cstdio>

int is_bit_set(int n, int position)
{
    return ( ( (1LL << position)&n ) != 0);
}

int no_of_ones(int n)
{
    int ones = 0;
    while(n)
    {
        if(n&1)
            ones++;

        n >>= 1;
    }

    return ones;
}

int no_of_digits(int n)
{
    int digits = 0;

    while(n)
    {
        n /= 10;
        digits++;
    }

    return digits;
}

long long square(long long n)
{
    return n*n;
}

int is_square(int n)
{
    int left = 0, right = 1e5, mid = (left + right) >> 1;

    while(left <= right)
    {
        mid = (left + right) >> 1;

        if(square(mid) <= n)
        {
            if(square(mid + 1) > n)
            {
                break;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            right = mid - 1;
        }
    }

    return (square(mid) == n);
}

int main()
{
    int n;
    scanf("%d", &n);

    int digit_count = no_of_digits(n), maximum_digits = 0;
    int digit[11];

    for(int i = 0; i < digit_count; i++, n /= 10)
        digit[i] = n%10;

    for(int mask = (1 << digit_count) - 1; mask > 0; mask--)
    {
        int number = 0;

        for(int i = digit_count - 1; i >= 0; i--)
        {
            if(is_bit_set(mask, i))
                number = number*10 + digit[i];
        }

        if(is_square(number) && no_of_digits(number) > maximum_digits)
            maximum_digits = no_of_digits(number);
    }


    int deleted_digits = digit_count - maximum_digits;
    printf(deleted_digits == digit_count ? "-1\n" : "%d\n", deleted_digits);

    return 0;
}
