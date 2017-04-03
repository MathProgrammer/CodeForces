#include <stdio.h>
#include <stdlib.h>

void display(unsigned int *, unsigned int);
void sundaram_sieve(unsigned int *, unsigned int, unsigned int *);
void get_question_sequence(unsigned int *, unsigned int *, unsigned int);

int main()
{
    unsigned int number, no_of_questions = 0;
    scanf("%u",&number);

    unsigned int *question_sequence = malloc(number*sizeof(question_sequence));

    get_question_sequence(question_sequence, &no_of_questions, number);
    display(question_sequence, no_of_questions);

    free(question_sequence);
    return 0;
}

void display(unsigned int *question_sequence, unsigned int no_of_questions)
{
    unsigned int i;
    printf("%u\n", no_of_questions);
    for(i = 0; i < no_of_questions; i++)
    {
        printf("%u\t",*(question_sequence + i));
    }
}

/*Question sequence consists of all primes p less than n, raised to every power i, such that p^i <= n*/
void get_question_sequence(unsigned int *question_sequence, unsigned int *no_of_questions, unsigned int number)
{
    unsigned int current_prime, current_prime_power, current_prime_index, primeCount;
    //Looking at the primes mod 6, except 2 and 3, all primes are 6m + 1 or 6m - 1
    unsigned int *primes = malloc((number/3 + 2)*sizeof(unsigned int));

    sundaram_sieve(primes, number, &primeCount); //All primes upto the target number

    for(current_prime_index = 0; current_prime_index < primeCount ; current_prime_index++)
    {
        current_prime = *(primes + current_prime_index); //p = p initially
        current_prime_power = current_prime;
        //printf("Current prime index = %u\tCurrent prime = %u\n",current_prime_index, *(primes + current_prime_index));
        while(current_prime_power <= number)
        {
            *(question_sequence + *no_of_questions) = current_prime_power; //printf("Q%u\t",*(question_sequence + *no_of_questions));
            *(no_of_questions) = *(no_of_questions) + 1;

            current_prime_power *= current_prime; //p^{i+1} = p^i * p
        }
    }
    free(primes);
}

//Crossing out numbers of the form i + j + 2ij
void sundaram_sieve(unsigned int *primes, unsigned int target, unsigned int *primeCount)
{
    unsigned i, crossed_out_num, cross_limit, increment;
    short *auxiliary_list = malloc(target*sizeof(short));

    /*f(i,j) = i + j + 2ij
    For a given value of i, the minimum is when j = 1. Minimum is f(i,1) = 3i + 1
    f(i, j + 1) = f(i,j) + 2i + 1 so we only need to increase the value of the crossed number by 2i + 1, instead of updating by one.
    i goes from 1 to target/2. But, f(i,j) starts from 3i + 1. If i is greater than target/6, then f(i,j) is out of range.
    So, the minimum
    Maximum occurs when j = i. f(i,j) = 2i(i+1).
    The last number to be crossed out for a given i is either 2i(i + 1) or the last f(i,j) before target/2, whichever comes first.*/

	//All numbers of the form i + j + 2ij need to be marked out
    for(i = 0; i < target; i ++)
    {
        *(auxiliary_list + i) = 1;
    }

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
            *(auxiliary_list + crossed_out_num) = 0;
        }
    }

    //We need to put 2 in ourselves because the algorithm 'only' generates all the odd primes
    *primeCount = 0;
    *(primes + *primeCount) = 2;
    *primeCount = *primeCount + 1;

    for(i = 1; i <= target/2; i++)
    {
        //Checking if the number is not crossed out and adding 2i + 1 to the list if it is unmarked.
        if(*(auxiliary_list + i) == 1)
        {
            *(primes + *primeCount) = (2*i + 1); //printf("%u\t", *(primes + *primeCount));
            *primeCount = *primeCount + 1;
        }
    }

    free(auxiliary_list);
}
