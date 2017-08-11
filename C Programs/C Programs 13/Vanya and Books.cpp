#include <cstdio>

int main()
{
    int no_of_pages;
    scanf("%d", &no_of_pages);

    long long no_of_digits_used = 0;
    long long power_of_10 = 1;

    while(power_of_10 <= no_of_pages)
    {
        no_of_digits_used += no_of_pages - (power_of_10 - 1);
        power_of_10 *= 10;
    }

    printf("%I64d\n", no_of_digits_used);
    return 0;
}
