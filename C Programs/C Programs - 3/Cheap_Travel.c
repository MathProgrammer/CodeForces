#include <stdio.h>

unsigned int find_minimum_cost(unsigned int, unsigned int,unsigned int,unsigned int);
int main()
{
    unsigned int no_of_rides, price_of_one_ride, special_no_of_rides, price_of_special_rides;
    unsigned int minimum_money_spent;
    scanf("%u %u %u %u", &no_of_rides, &special_no_of_rides, &price_of_one_ride, &price_of_special_rides);

    minimum_money_spent = find_minimum_cost(no_of_rides, special_no_of_rides, price_of_one_ride, price_of_special_rides);

    printf("%u",minimum_money_spent);
    return 0;
}

unsigned int find_minimum_cost(unsigned int no_of_rides, unsigned int special_no_of_rides,unsigned int price_of_one_ride,unsigned int price_of_special_rides)
{
    unsigned int minimum_cost, no_of_special_tickets, no_of_normal_tickets;

    //If it is cheaper to use the special ticket than normal ticket for b rides
    if(price_of_special_rides <= price_of_one_ride*special_no_of_rides)
    {
        no_of_special_tickets = no_of_rides/special_no_of_rides;

        //Checking if it is cheaper to use the special ticket for the remaining rides
        if(price_of_special_rides <= price_of_one_ride*(no_of_rides%special_no_of_rides))
        {
            no_of_special_tickets++;
            no_of_normal_tickets = 0;
        }
        else
        {
            no_of_normal_tickets = no_of_rides%special_no_of_rides;
        }
    }
    else //Otherwise only buy normal tickets
    {
        no_of_special_tickets = 0;
        no_of_normal_tickets = no_of_rides;
    }

    minimum_cost = no_of_special_tickets*price_of_special_rides + no_of_normal_tickets*price_of_one_ride;
    return minimum_cost;
}
