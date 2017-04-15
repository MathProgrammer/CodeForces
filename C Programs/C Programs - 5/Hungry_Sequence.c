#include <stdio.h>

int main()
{
    int i, no_of_terms;
    scanf("%d",&no_of_terms);

    /*The sequence of consecutive numbers - 2n + 1, 2n + 2, .... , 2n + n - satisfies this property.
    For any number x, it's largest proper divisor is at most x/2. 2*(x/2) = x
    If x had a divisor greater than x/2, than it would have to be multiplied by a number less than 2. But there is only one option - 1,
    The largest proper divisor of any number is this series is smaller than the smallest term of this sequence of consecutive numbers.
    The greatest divisor of 2n + n, is n + n/2, which is less than 2n + 1 for all positive n.
    This means that the divisors of any number from this list are smaller than the smallest number in this sequence.
    So, this is a hungry sequence.
    There is nothing special about the number 2. Any positive integer value m can be multiplied - nm + 1, nm + 2, ... , mn + n to get a Hungry sequence.*/
    for(i = 1; i <= no_of_terms; i++)
    {
        printf("%d ", (2*no_of_terms+ i));
    }
    return 0;
}
