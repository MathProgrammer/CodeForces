#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int find_gcd(int a, int b)
{
    if(a == 0 || b == 0)
        return (a + b);

    if(a == b)
        return a;

    if(a%2 == 0)
        if(b%2 == 0)
            return 2*find_gcd(a >> 1, b >> 1);
        else
            return find_gcd(a >> 1, b);
    else
        if(b%2 == 0)
            return find_gcd(a, b >> 1);
        else
            return find_gcd(min(a, b), (max(a, b) - min(a, b) ) >> 1);
}

int main()
{
    int no_of_numbers, maximum = 0, number, no_of_numbers_at_end, i, no_of_turns, gcd;
    scanf("%d", &no_of_numbers);

    for(i = 1; i <= no_of_numbers; i++)
    {
        scanf("%d", &number);
        maximum = max(maximum, number);
        gcd = (i == 1 ? number : find_gcd(gcd, number) );
    }
    no_of_numbers_at_end = maximum/gcd;
    no_of_turns = no_of_numbers_at_end - no_of_numbers;

    printf(no_of_turns%2 == 1 ? "Alice\n" : "Bob\n");
    return 0;
}
