#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

short  check_if_possible(long,long,unsigned long);
int main()
{
    short is_possible;
    long x_coordinate, y_coordinate;
    unsigned long distance_travelled;

    scanf("%ld %ld %lu",&x_coordinate, &y_coordinate, &distance_travelled);

    is_possible = check_if_possible(x_coordinate, y_coordinate, distance_travelled);

    if(is_possible)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

/*1. In a given move, either x or y changes by 1. To go from (0,0) to (a,b) it will take a minimum of (|a|+|b|) moves.
2. From a point (x,y), it is possible to return to (x,y) in an even number of moves only.
	If an odd number of moves have been made, it means that one of the coordinates has been changed more times than the other. So, it isn't possible to return to (x,y).
	A simple example is (x,y) - (x+1, y) - (x,y) and variations of this. It is possible to return only after an even number of moves.*/

short  check_if_possible(long x_coordinate,long y_coordinate,unsigned long distance_travelled)
{
    unsigned long minimum_distance_required = abs(x_coordinate) + abs(y_coordinate);

    if(distance_travelled < minimum_distance_required)//If the distance_travelled is less than the number of moves, then it is not possible
    {
        return false;
    }
    /*the same point can be returned to only in an even number of moves. In an odd number of moves, one coordinate gets changed more times than the other.
    So, it isn't possible*/
    else if((distance_travelled - minimum_distance_required)%2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
