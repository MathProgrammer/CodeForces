#include <stdio.h>

unsigned long long count_pairs_multiple_5(unsigned long long, unsigned long long);
int main()
{
    unsigned long long m, n, answer;
    scanf("%I64u %I64u",&m, &n);
    answer = count_pairs_multiple_5(m,n);
    printf("%I64u\n",answer);
    return 0;
}

unsigned long long count_pairs_multiple_5(unsigned long long m, unsigned long long n)
{
    short i;
    unsigned long long answer = 0, current_mod_x, current_mod_y;

    answer = (n/5)*(m/5);//doing the case of i = 0 (mod 5) separately because (m - (5 - i)) will actually lose 1 possible value of y.
    for(i = 1; i <5; i++)
    {
        current_mod_x = n/5;
        current_mod_y = m/5;
        if(n%5 >= i)
        {
            current_mod_x++;
        }
        if(m%5 >= 5 - i)
        {
            current_mod_y++;
        }
        answer = answer + current_mod_x*current_mod_y;
    }
    return answer;
}
