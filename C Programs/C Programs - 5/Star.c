#include <stdio.h>

int main()
{
    unsigned long long n, star_n;
    scanf("%I64u",&n);
    //A star number consists of a central number and 12 copies of the (n-1)th triangular number
    star_n = 6LL*n*(n-1) + 1;
    printf("%I64u",star_n);
    return 0;
}
