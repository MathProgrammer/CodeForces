#include <stdio.h>

int main()
{
    unsigned long length_of_stick, no_of_rectangular_cuts;

    scanf("%lu",&length_of_stick);

    /*If x is not an even number, then the number of rectangles is 0.
    Let x, be an even number. We must find the number of unordered pairs (a, b) such that (a + b) = x/2, where a is not equal to b.
    It is sufficient to count the number of times we can find (a + b) = x/2. We just replicate the same division on the other other x/2 stick.
    This is the number of integers upto (x/2)/2 = x/4 [ (1, x/2-1), (2, x/2 - 2) .... (x/4 - 1, x/4 + 1), (x/4, x/4)]
    If x is a multiple of 4, then the last pair is (x/4, x/4) which has to be discounted.
    Otherwise, it is (x/4 - 1, x/4 + 1)*/
    if(length_of_stick%2 == 1)
    {
        no_of_rectangular_cuts = 0;
    }
    else
    {
        if(length_of_stick%4 == 0)
        {
            no_of_rectangular_cuts = length_of_stick/4 - 1;
        }
        else
        {
            no_of_rectangular_cuts = length_of_stick/4;
        }
    }

    printf("%lu\n",no_of_rectangular_cuts);
    return 0;
}
