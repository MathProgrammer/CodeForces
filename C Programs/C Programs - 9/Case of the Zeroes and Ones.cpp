#include <cstdio>

#define MAX_LENGTH 200000 + 1
#define min(a, b) (a < b ? a : b)

int main()
{
    char sequence[MAX_LENGTH];
    int length, no_of_zeroes = 0, no_of_ones = 0;
    scanf("%d %s", &length, sequence);

    for(int i = 0; i < length; i++)
    {
        no_of_zeroes += (sequence[i] == '0');
        no_of_ones += (sequence[i] == '1');
    }

    int no_of_survivors = length - 2*min(no_of_ones, no_of_zeroes);

    printf("%d\n", no_of_survivors);
    return 0;
}
