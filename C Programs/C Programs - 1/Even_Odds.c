#include <stdio.h>

int main()
{
    unsigned long long no_of_numbers, position_of_last_odd_number, desired_position, number_at_desired_position;

    scanf("%I64d %I64d",&no_of_numbers, &desired_position);

    //The first ceil(n/2) positions are filled with odd numbers and the remaining spots by even numbers
    if(no_of_numbers%2 == 0)
    {
        position_of_last_odd_number = no_of_numbers >> 1; //n/2
    }
    else
    {
        position_of_last_odd_number = (no_of_numbers >> 1) + 1;//n/2 + 1
    }

    if(desired_position <= position_of_last_odd_number) //kth position has kth odd number = 2k - 1
    {
        number_at_desired_position = 2*desired_position - 1;
    }
    else //kth position has k - ceil(n/2) th even number
    {
        number_at_desired_position = 2*(desired_position - position_of_last_odd_number );
    }
    printf("%I64d\n",number_at_desired_position);
    return 0;
}
