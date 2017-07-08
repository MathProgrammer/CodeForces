#include <cstdio>

#define min(a, b) (a < b ? a : b)
#define min_3(a, b, c) min(a, min(b, c))

int main()
{
    int no_of_books, price_1, price_2, price_3;
    scanf("%d %d %d %d", &no_of_books, &price_1, &price_2, &price_3);

    long long minimum_amount = 0;

    switch(no_of_books%4)
    {
        case 1: minimum_amount = min_3(price_1*3LL, price_1 + price_2, price_3);
                break;

        case 2: minimum_amount = min_3(price_1*2LL, price_2, price_3*2LL);
                break;

        case 3: minimum_amount = min_3(price_1, price_2 + price_3, price_3*3LL);
    }

    printf("%I64d\n", minimum_amount);
    return 0;
}
