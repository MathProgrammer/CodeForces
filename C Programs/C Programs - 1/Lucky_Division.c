#include <stdio.h>
#include <string.h>

#define true 1
#define false 0
#define base 10

short check_if_num_is_lucky(unsigned int);
short check_if_num_is_almost_lucky(unsigned int);
int main()
{
    unsigned int num;
    short is_almost_lucky;
    char answer[4];

    scanf("%u",&num);
    is_almost_lucky = check_if_num_is_almost_lucky(num);
    if(is_almost_lucky == true)
    {
        strcpy(answer, "YES");
    }
    else
    {
        strcpy(answer, "NO");
    }
    printf("%s\n",answer);
    return 0;
}

short check_if_num_is_lucky(unsigned int num)
{
    short last_digit;

    for( ;num != 0; num = num/base) //Running through all the digits of num, one by one
    {
        last_digit = num%base;
        if((last_digit != 4) && (last_digit != 7))
        {
                return false;
        }
    }
    return true;
}

short check_if_num_is_almost_lucky(unsigned int num)
{
    unsigned int i;

    //Checking if i is a lucky number and if i divides num.
    for(i = 4; (i <= num); i++)
    {
        if(check_if_num_is_lucky(i))
        {
            if(num%i == 0)
            {
                return true;
            }
        }
    }
    return false;
}
