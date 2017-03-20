#include <stdio.h>

unsigned int gcd(unsigned int,unsigned int);
int main()
{
    unsigned int lahub_bricks, floyd_bricks;
    unsigned long lahub_lucky_number, floyd_lucky_number, lcm, answer;

    scanf("%u %u %lu %lu",&lahub_bricks, &floyd_bricks, &lahub_lucky_number, &floyd_lucky_number);

    lcm = (lahub_bricks*floyd_bricks)/gcd(lahub_bricks,floyd_bricks);
    answer = floyd_lucky_number/lcm - (lahub_lucky_number-1)/lcm;

    printf("%lu\n",answer);
    return 0;
}

/*We use bitwise operations instead of multiply and divide simply because it is faster at the hardware level.*/
unsigned int gcd(unsigned int u,unsigned int v)
{
    //Base Cases
    if(u == v)
    {
        return u; //Both are GCD
    }
    if(u == 0)
    {
        return v;
    }
    if(v == 0)
    {
        return u;
    }

    //If both are even, their GCD will also have a factor of 2 in it
    if(~u & 1) //If it is even, the last bit will be 0. Taking complement will make it 1. AND it with 1 and you get 1 if is even and 0 otherwise
    {
        if(v & 1)//v is odd. Removing the factor of 2 from u
        {
            return gcd(u >> 1, v);
        }
        else //Checking if both u and v are even gcd(u,v) = 2*gcd(u/2,v/2)
        {
            return 2*gcd(u >> 1 , v >> 1);//Dividing u and v by 2
        }
    }

    if(~v & 1) //u is odd and v is even
    {
        return gcd(u,v>>1);
    }

    //Both are odd. gcd(u,v) = ( (u-v)/2, v) This is just one step ahead of the Euclidean algorithm
    //Any number that divides both u and v must also divide their difference. Here, the difference is even so we just remove
    //the fact of 2
    //Determining the larger number
    if(u > v)
    {
        return gcd( (u - v) >> 1, v);
    }
    else
    {
        return gcd( (v - u) >> 1, u);
    }
}
