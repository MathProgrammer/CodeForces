#include <stdio.h>

#define min(a, b) (a < b ? a : b)
#define min_of_3(a,b,c) min(a, min(b,c))

int main()
{
    unsigned int no_of_2, no_of_3, no_of_5, no_of_6, no_of_256, no_of_32, sum = 0;
    scanf("%u %u %u %u",&no_of_2, &no_of_3, &no_of_5, &no_of_6);

    no_of_256 = min_of_3(no_of_2, no_of_5, no_of_6); //Make as many 256s as possible
    no_of_32 = min(no_of_2 - no_of_256, no_of_3); //Some of the 2s have been used in 256s.

    sum = 256*no_of_256 + 32*no_of_32;
    printf("%u\n",sum);
    return 0;
}
