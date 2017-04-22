#include <stdio.h>
#include <stdlib.h>
#define NOT_POSSIBLE -10
int find_coefficient_of_income(int,int ,short);
int power(int, int);

int main()
{
    int money_at_beginning, money_at_end, coefficient_of_income_growth;
    short no_of_years;
    scanf("%d %d %hu",&money_at_beginning, &money_at_end, &no_of_years);
    coefficient_of_income_growth = find_coefficient_of_income(money_at_beginning, money_at_end, no_of_years);
    if(coefficient_of_income_growth == NOT_POSSIBLE)
    {
        printf("No solution\n");
    }
    else
    {
        printf("%d\n",coefficient_of_income_growth);
    }
    return 0;
}

int find_coefficient_of_income(int money_at_beginning,int money_at_end, short no_of_years)
{
    int assumed_coefficient, expected_answer ;

    if(money_at_beginning == 0)//No solution then
    {
        /*If both a = b= 0, then any value of x satisfies the equation
         If a is 0 and b is non zero, there is no solution*/
        assumed_coefficient = (money_at_end == 0 ? 1 : NOT_POSSIBLE);

        return assumed_coefficient;
    }
    else
    {
        if(abs(money_at_end)% abs(money_at_beginning) != 0)
        {
            return NOT_POSSIBLE;
        }
        expected_answer =   money_at_end/money_at_beginning; //X^n = b/a
    }

    if(expected_answer > 0)
    {
        for(assumed_coefficient = 0; power(assumed_coefficient, no_of_years) < expected_answer; assumed_coefficient++);
    }
    else
    {
        for(assumed_coefficient = 0; power(assumed_coefficient, no_of_years) > expected_answer; assumed_coefficient--);
    }
    //printf("%d\t%d\t=%d\n",assumed_coefficient,power(assumed_coefficient, 1),expected_answer);
    if(power(assumed_coefficient, no_of_years) != expected_answer)
    {
        assumed_coefficient = NOT_POSSIBLE;
    }

    return assumed_coefficient;
}

int power(int x,int n)
{
    return (n == 0 ? 1 : x*power(x, n-1));
}
