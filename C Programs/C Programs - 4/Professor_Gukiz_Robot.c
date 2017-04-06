#include <stdio.h>
#include <stdlib.h>

long find_minimum_moves(long, long, long, long);
long maximum(long, long);

int main()
{
    long start_x, start_y, final_x, final_y, minimum_moves;
    scanf("%ld %ld %ld %ld",&start_x, &start_y, &final_x, &final_y);
    minimum_moves = find_minimum_moves(start_x, start_y, final_x, final_y);
    printf("%ld\n",minimum_moves);
    return 0;
}

long find_minimum_moves(long start_x, long start_y, long final_x, long final_y)
{
    long minimum_moves;

    /*First take as many diagonal steps as possible. This is min{|x-x1|, |y - y1|}
    Then take the required number of line moves. This is max{|x-x1|, |y - y1|} - min{|x-x1|, |y - y1|}
    The total sum is max{|x-x1|, |y - y1|}*/
    minimum_moves = maximum(abs(start_x-final_x),abs(start_y-final_y));

    return minimum_moves;
}

long maximum(long a, long b)
{
    if(a > b)
        return a;
    else
        return b;
}
