#include <cstdio>

int main()
{
    int socks, new_sock_day;
    scanf("%d %d", &socks, &new_sock_day);

    int no_of_days = 0;

    while(socks > 0)
    {
        no_of_days++;

        if(no_of_days%new_sock_day == 0)
            socks++;

        socks--;
    }

    printf("%d\n", no_of_days);
    return 0;
}
