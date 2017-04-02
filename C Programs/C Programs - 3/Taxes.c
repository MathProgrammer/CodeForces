#include <stdio.h>

#define true 1
#define false 0

short is_prime(unsigned long);
short find_minimum_tax(unsigned long);

int main()
{
    short minimum_taxes;
    unsigned long total_taxes;
    scanf("%lu",&total_taxes);
    minimum_taxes = find_minimum_tax(total_taxes);
    printf("%hu\n",minimum_taxes);
    return 0;
}

//Happens in O(root(n)) time
short is_prime(unsigned long n)
{
    short prime = true;
    unsigned long i;

    for(i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            prime = false;
            break;
        }
    }
    return prime;
}

/*If the number is prime, then only 1 has to be paid. That is the minimum possible.
The next minimum is 2.
Since the Goldbach conjecture has been verified upto the limit, we can use it. Any even number is the sum of two primes.
We don't need to actually find the pair of primes, we just know it exists.
If a number is odd and composite , n = (n-2) + 2, is the only way it can be written as the sum of two primes. 2 is the only even prime number.
The sum of two odd numbers is another odd number. So, an even number has to be involved. If (n-2) is prime, then the minimum tax = 1+1 = 2

n = n-3 + 3, and then n-3 is an even number and has minimum return 2. 3 is prime. 2+1 = 3. This is the maximum possible tax that will ever be given
following the scheme.

Note - Although logically the first thing to do is check if a number is prime and return 1 if it is and then go for the other test,
I have included it second because checking parity of number is a very quick and easy process Even numbers don't need to be subjected to primality tests.*/
short find_minimum_tax(unsigned long tax)
{
    //According to Goldbach conjecture, every even number can be written as the sum of two odd primes, It has been numerically verified upto the limit given
    if( (tax%2 == 0) && (tax != 2) )
    {
        return 2;
    }
    else if(is_prime(tax))
    {
        return 1;
    }
    else
    {
        //If n-2 is prime, then n = (n - 2) + 2 is the sum of two primes. This is the only way since one summand has to be even to get an odd number
        if(is_prime(tax - 2))
        {
            return 2;
        }
        else //Then, n = (n-3) + 3. n-3 is an even number and can be written as the sum of two odd primes
        {
            return 3;
        }
    }
}
