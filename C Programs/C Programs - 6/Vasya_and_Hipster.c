#include <stdio.h>

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)
int main()
{
    int red_socks, blue_socks, no_of_days_different_socks, no_of_days_same_socks;
    scanf("%d %d", &red_socks, &blue_socks);

    no_of_days_different_socks = min(red_socks, blue_socks);
    no_of_days_same_socks = (max(red_socks, blue_socks) - min(red_socks, blue_socks))/ 2;
    printf("%d %d\n",no_of_days_different_socks, no_of_days_same_socks);
    return 0;
}
