#include <stdio.h>

#define true 1
#define false 0

short check_if_pineapple_barks(unsigned long,unsigned long,unsigned long);

int main()
{
    short does_pineapple_bark;
    unsigned long first_bark_time, barking_interval, desired_time;

    scanf("%lu %lu %lu",&first_bark_time, &barking_interval, &desired_time);
    does_pineapple_bark = check_if_pineapple_barks(first_bark_time, barking_interval, desired_time);

    if(does_pineapple_bark)
    {
       printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

short check_if_pineapple_barks(unsigned long first_bark_time,unsigned long barking_interval,unsigned long desired_time)
{
    /*First bark time = t, barking interval = s, desired time = x
    If x = t + ms or x = t + ms + 1, then it is a YES, it barks
    If x = t + ms, then x - t is a multiple of s.
    If x = t + ms + 1, then x - t = ms + 1, (x - t) has to leave a remainder of 1 with s.
    However, it doesn't bark at time t + 1
    If x < t, then no other checks are necessary. The pineapple doesn't bark. Avoid subtraction in that case because these are unsigned numbers.*/
    if(desired_time < first_bark_time)
    {
        return false;
    }
    if( (desired_time - first_bark_time) < barking_interval ) //This block ensures t+1 doesn't get counted as a barking time.
    {
        if(desired_time == first_bark_time)//If x-t <s, then it is a barking interval only if x = t + 0s. Not x = t + 0s +1
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    if( ( (desired_time - first_bark_time)%barking_interval == 0) || ( (desired_time - first_bark_time)%barking_interval == 1) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
