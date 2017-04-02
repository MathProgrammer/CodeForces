#include <stdio.h>
#include <math.h>

int main()
{
    unsigned long long rectangular_length, rectangular_breadth, square_side, answer;
    scanf("%I64u %I64u %I64u",&rectangular_length, &rectangular_breadth, &square_side);

    if(rectangular_length%square_side != 0)
    {
        if(rectangular_breadth%square_side != 0)
        {
            answer = (rectangular_length/square_side + 1)*(rectangular_breadth/square_side + 1);
        }
        else
        {
            answer = (rectangular_length/square_side + 1)*(rectangular_breadth/square_side);
        }
    }
    else
    {
        if(rectangular_breadth%square_side != 0)
        {
            answer = (rectangular_length/square_side)*(rectangular_breadth/square_side + 1);
        }
        else
        {
            answer = (rectangular_length/square_side)*(rectangular_breadth/square_side);
        }
    }
    printf("%I64u\n",answer);
    return 0;
}
