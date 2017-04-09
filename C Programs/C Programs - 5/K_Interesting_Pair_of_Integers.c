#include <stdio.h>

#define RANGE 10000

void build_population_count(unsigned int[]);
void read_and_find_frequency(int[], unsigned int);
unsigned long long count_k_interesting_pairs(int[],int, unsigned int[]);

int main()
{
    int count[RANGE + 1] = {0}, k;
    unsigned int population_count[2*RANGE], no_of_elements;
    unsigned long long no_of_k_interesting_pairs;

    scanf("%u %d", &no_of_elements, &k);

    build_population_count(population_count);
    read_and_find_frequency(count, no_of_elements);
    no_of_k_interesting_pairs = count_k_interesting_pairs(count, k, population_count);
    printf("%I64u\n",no_of_k_interesting_pairs);
    return 0;
}

//Builds a vector PC - Population Count, where PC[x] has the number of 1s in the binary representation of x
void build_population_count(unsigned int population_count[])
{
    unsigned int i;
    population_count[0] = 0;

    /*Let us suppose there is a binary number x - 10001, then we can XOR with 01110 to get 11111.
    We can XOR to numbers to get a number greater than either of the numbers. What is the greatest number we can get ?
    If x and y are binary numbers, and x > y, and the first 1 in the binary form of x is at position p (from the right),
    the greatest value of x XOR y is a number with all 1s from position p.
    So, x XOR y is always less than a 1 at position (p+1) and all 0s afterwards. So, 2*x is a loose upper bound.
    That is why we build a population count table till 2* RANGE instead of just RANGE*/

    for(i = 1; i <= 2*RANGE; i++)
    {
        /*for even x, f(x) = f(x/2) ,the string is left shifted once
          for odd x, f(x) = f(x/2) + 1 , x/2 is left shifted and then 1 is added
          We can write this elegantly in one case. */

        population_count[i] = population_count[i >> 1] + (i % 2);
    }
}

unsigned long long count_k_interesting_pairs(int count[],int k, unsigned int population_count[])
{
    unsigned int i, j;
    unsigned long long k_interesting_count = 0;

    if(k == 0) //k = 0 is a special case. Then if the count of x is n, no of pairs is nC2.
    {
        for(i = 0; i <= RANGE; i++)
        {
            if(count[i] > 0)
            {
                k_interesting_count += (long long)count[i]*(count[i] - 1)/2; //Preventing overflow by typecasting
            }
        }
    }
    else
    {
        for(i = 0; i <= RANGE; i++)
        {
            for(j = i + 1; j <= RANGE; j++)
            {
                if( (count[j] > 0) && (population_count[i^j] == k) )
                {
                    //Explicit typecasting done to prevent overflow
                    k_interesting_count += (long long) count[i]*count[j];//i occurs count[i] times and j count[j]. No of pairs (i,j) s their product
                }
            }
        }
    }

    return k_interesting_count;
}

void read_and_find_frequency(int count[], unsigned int no_of_elements)
{
    unsigned int num, i;

    for(i = 0; i < no_of_elements; i++)
    {
        scanf("%u", &num);
        count[num]++;
    }
}
