#include <stdio.h>

short maximum(short, short);
int main()
{
    short roll_1, roll_2, dot_wins, total_rolls = 6;

    scanf("%hu %hu",&roll_1, &roll_2);
    dot_wins =total_rolls - maximum(roll_1, roll_2) + 1;//+1 because the other two allow Dot to win if she equalises. the maximum is also inclusive of when Dot wins

    //Reducing dot wins and total rolls to it's simplest form. Since we know it's 6, we just check divisibility by 2 and 3 instead of calling a gcd function
    if(dot_wins%3 == 0)
    {
        dot_wins = dot_wins/3;
        total_rolls = total_rolls/3;
    }
    if(dot_wins%2 == 0)
    {
        dot_wins = dot_wins/2;
        total_rolls = total_rolls/2;
    }

    printf("%hu/%hu\n",dot_wins, total_rolls);
    return 0;
}

short maximum(short a, short b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
