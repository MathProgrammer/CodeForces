#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

short check_if_clerk_always_has_change(unsigned int,unsigned int *);
void read_money_with_each_person(unsigned int,unsigned int *);

int main()
{
    short does_clerk_always_have_change;
    unsigned int no_of_people;
    scanf("%u",&no_of_people);

    unsigned int *price_paid_by_people = malloc(no_of_people*sizeof(unsigned int));

    read_money_with_each_person(no_of_people, price_paid_by_people);
    does_clerk_always_have_change = check_if_clerk_always_has_change(no_of_people, price_paid_by_people);

    if(does_clerk_always_have_change)
    {
       printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    free(price_paid_by_people);
    return 0;
}

void read_money_with_each_person(unsigned int no_of_people, unsigned int *price_paid_by_people)
{
    unsigned int i;

    for(i = 0; i < no_of_people; i++)
    {
            scanf("%u",(price_paid_by_people + i));
    }
}

short check_if_clerk_always_has_change(unsigned int no_of_people, unsigned int *price_paid_by_people)
{
    short does_clerk_always_have_change = true;
    int no_of_25_bills = 0, no_of_50_bills = 0, i; //No need of keeping track of 100 because they can't they can't be used for change

    for(i = 0; i < no_of_people; i++)
    {
        if(*(price_paid_by_people + i) == 25)
        {
            no_of_25_bills++;
        }
        else if(*(price_paid_by_people + i) == 50)
        {
            //Check if he has change
            if(no_of_25_bills < 1)
            {
                does_clerk_always_have_change = false;
                break;
            }
            no_of_50_bills++;
            no_of_25_bills --;
        }
        else if(*(price_paid_by_people + i) == 100)
        {
            if((no_of_25_bills >= 1) && (no_of_50_bills >= 1))
            {
                no_of_50_bills--;
                no_of_25_bills --;
            }
            else if(no_of_25_bills >= 3)
            {
                no_of_25_bills = no_of_25_bills - 3;
            }
            else //Change couldn't be paid
            {
                does_clerk_always_have_change = false;
                break;
            }
        }
    }

    return does_clerk_always_have_change;
}
