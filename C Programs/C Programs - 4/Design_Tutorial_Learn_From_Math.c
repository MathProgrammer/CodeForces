#include <stdio.h>

void get_composite_summands(unsigned long, unsigned long *, unsigned long *);
int main()
{
    unsigned long number, composite_summand_1, composite_summand_2;
    scanf("%lu",&number);

    get_composite_summands(number, &composite_summand_1, &composite_summand_2); //Pass by Reference
    printf("%lu %lu\n", composite_summand_1, composite_summand_2);
    return 0;
}

void get_composite_summands(unsigned long number, unsigned long *composite_summand_1, unsigned long *composite_summand_2)
{
    if(number%2 == 0)
    {
        //2n = n + n, If n is an even number, we are done
        if(number%4 == 0)
        {
            *composite_summand_1 = number/2;
            *composite_summand_2 = number/2;
            return;
        }
        else //2n = n - 1 + n + 1, here (n-1) and (n+1) are even numbers because n is odd
        {
            *composite_summand_1 = number/2 - 1;
            *composite_summand_2 = number/2 + 1;
            return;
        }
    }
    else
    {
        //n = 9 + (n -9). 9 is composite and (n-9) is even. Since, n >= 12, n-9 >=4 when n is odd in the given range. We will always get an even number
        *composite_summand_1 = 9;
        *composite_summand_2 = number - 9;
        return;
    }
}
