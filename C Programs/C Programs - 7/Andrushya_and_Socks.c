#include <stdio.h>

#define max(a, b) (a > b ? a : b)
#define MAX_SIZE 100000 + 1

int no_of_socks[MAX_SIZE] = {0};
int main()
{
    int current_sock_type, i, no_of_sock_types, no_of_socks_on_table = 0, max_no_of_socks_on_table = 0;
    scanf("%d", &no_of_sock_types);

    for(i = 1; i < 2*no_of_sock_types; i++)
    {
        scanf("%d", &current_sock_type);
        no_of_socks[current_sock_type]++;

        if(no_of_socks[current_sock_type] == 1)
            no_of_socks_on_table++;
        else if(no_of_socks[current_sock_type] == 2)
            no_of_socks_on_table--;

        max_no_of_socks_on_table = max(max_no_of_socks_on_table, no_of_socks_on_table);
    }

    printf("%d\n",max_no_of_socks_on_table);
    return 0;
}
