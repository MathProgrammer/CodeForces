#include <stdio.h>

int main()
{
    unsigned long long n, answer;
    scanf("%I64u",&n);

    //Each layer adds 6 new hexagons.Including itself, 1 + 6( 1 + 2 + ... + n) = 1 + 6n(n+1)/2
    answer = 1LL + 3LL*n*(n+1);
    printf("%I64u\n",answer);
    return 0;
}
