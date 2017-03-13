#include <stdio.h>
#include <stdlib.h>

#define limit 100000

void sunduram_sieve(unsigned int, short []);
void make_prime_list(unsigned int, short [],short []);
void initial_marking(unsigned int, short [], short);

int main()
{
    unsigned int n, i;
    short is_prime[limit], no_of_colours = 2;

    scanf("%d",&n);

    initial_marking( (n+1), is_prime, 2); //Initialising the array is_prime to 2.
    sunduram_sieve((n+1), is_prime);

    //If there are only 2 or 1 piece, the numbers are 2 and 3. One colour is sufficient to paint them.
    if(n <= 2)
    {
        no_of_colours = 1;
    }

    printf("%hu\n",no_of_colours);
    for(i = 2; i <= n + 1; i++)
    {
        if(is_prime[i] == 1)
        {
            printf("%u ",is_prime[i]); //Primes are painted with one colour - 1
        }
        else
        {
            printf("%u ",is_prime[i]); //Composites are painted with another colour - 2
        }
    }
    return 0;
}

//Initially, everything is marked 1
void initial_marking(unsigned int size, short array[], short initial_value)
{
    unsigned int i;

    for(i = 1; i <= size; i++)
    {
        array[i] = initial_value;
    }
}

//Crossing out numbers of the form i + j + 2ij
void sunduram_sieve(unsigned int target, short is_prime[])
{
    unsigned i, crossed_out_num, cross_limit, increment; //To avoid overflow
    short auxiliary_list[target/2];
    initial_marking(target/2, auxiliary_list, 1);

    /*f(i,j) = i + j + 2ij
    For a given value of i, the minimum is when j = 1. Minimum is f(i,1) = 3i + 1
    f(i, j + 1) = f(i,j) + 2i + 1 so we only need to increase the value of the crossed number by 2i + 1, instead of updating by one.
    i goes from 1 to target/2. But, f(i,j) starts from 3i + 1. If i is greater than target/6, then f(i,j) is out of range.
    So, the minimum
    Maximum occurs when j = i. f(i,j) = 2i(i+1).
    The last number to be crossed out for a given i is either 2i(i + 1) or the last f(i,j) before target/2, whichever comes first.*/

	//All numbers of the form i + j + 2ij need to be marked out

    for(i = 1; i <= target/6; i++)
    {
        increment = 2*i + 1;
        cross_limit = 2*i*(i + 1);

        if(cross_limit > target/2)
        {
            cross_limit = target/2;
        }

        for(crossed_out_num = 3*i + 1;crossed_out_num <= cross_limit ; crossed_out_num += increment)
        {
            auxiliary_list[crossed_out_num] = 0;
        }
    }

    make_prime_list(target, is_prime, auxiliary_list);
}

//Making the list of primes
void make_prime_list(unsigned int target, short is_prime[],short auxiliary_list[])
{
    int i = 0;;

    //We need to put 2 in ourselves because the algorithm 'only' generates all the odd primes
    is_prime[2] = 1;
    for(i = 1; i <= target/2; i++)
    {
        //Checking if the number is not crossed out and adding 2i + 1 to the list if it is unmarked.
        if(auxiliary_list[i] == 1)
        {
            is_prime[2*i + 1] = 1;
        }
    }
}
