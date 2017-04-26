#include <stdio.h>
#include <stdlib.h>

#define min(a,b) (a < b ? a : b)
#define INFINITY 1e9 + 1

int read_and_find_minimum(int *, int);
long long find_no_of_days_equalise_shares(int *, int, int, int);

int main()
{
    int no_of_shares, decreasing_amount, minimum_share;
    long long no_of_days;
    scanf("%d %d", &no_of_shares, &decreasing_amount);
    int *share = malloc(no_of_shares*sizeof(int));

    minimum_share = read_and_find_minimum(share, no_of_shares);
    no_of_days = find_no_of_days_equalise_shares(share, no_of_shares, decreasing_amount, minimum_share);

    printf("%I64d\n",no_of_days);
    free(share);
    return 0;
}

long long find_no_of_days_equalise_shares(int *share, int no_of_shares,int decreasing_amount,int minimum_share)
{
    int i;
    long long no_of_days = 0;

    for(i = 0; i < no_of_shares; i++)
    {
        if( ( *(share + i) - minimum_share) % decreasing_amount != 0)
        {
            no_of_days = -1;
            break;
        }
        else
        {
            no_of_days = no_of_days + (( *(share + i) - minimum_share) / decreasing_amount);
        }
    }
    return no_of_days;
}

int read_and_find_minimum(int *share, int no_of_shares)
{
    int i, minimum = INFINITY;

    for(i = 0; i < no_of_shares; i++)
    {
        scanf("%d",(share + i));
        minimum = min(minimum, *(share + i));
    }
    return minimum;
}
