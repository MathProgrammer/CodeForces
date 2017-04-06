#include <stdio.h>
#include <stdlib.h>

long maximum(long, long);

int main()
{
    long start_x, start_y, final_x, final_y, minimum_moves;
    scanf("%ld %ld %ld %ld",&start_x, &start_y, &final_x, &final_y);
    
    /*First take as many diagonal steps as possible. This is min{|x-x1|, |y - y1|}
    Then take the required number of line moves. This is max{|x-x1|, |y - y1|} - min{|x-x1|, |y - y1|}
    The total sum is max{|x-x1|, |y - y1|}*/
    minimum_moves = maximum(abs(start_x-final_x),abs(start_y-final_y));
    
    printf("%ld\n",minimum_moves);
    return 0;
}

long maximum(long a, long b)
{
    if(a > b)
        return a;
    else
        return b;
}
