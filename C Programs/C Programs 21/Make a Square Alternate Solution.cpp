#include <cstdio>

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

int is_subsequence(int sequence, int n)
{
    while(sequence > 0 && n > 0)
    {
        if(n%10 == sequence%10)
        {
            sequence /= 10;

            if(sequence == 0)
                return true;
        }

        n /= 10;
    }

    return false;
}

int main()
{
    int n;
    scanf("%d", &n);

    int digit_count = no_of_digits(n), maximum_digits = 0;

    for(int i = 0; square(i) <= n; i++)
    {
        if(is_subsequence(square(i), n) && no_of_digits(square(i)) > maximum_digits)
        {
            maximum_digits = no_of_digits(square(i));
        }
    }

    int deleted_digits = digit_count - maximum_digits;
    printf(deleted_digits == digit_count ? "-1\n" : "%d\n", deleted_digits);

    return 0;
}

