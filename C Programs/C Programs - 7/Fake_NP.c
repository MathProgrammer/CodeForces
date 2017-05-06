#include <stdio.h>

int main()
{
    unsigned int left_limit, right_limit;
    scanf("%u %u",&left_limit, &right_limit);

    printf(left_limit != right_limit ? "2\n" : "%u\n",left_limit);
    return 0;
}
