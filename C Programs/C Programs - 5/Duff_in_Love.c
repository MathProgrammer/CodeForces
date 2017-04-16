#include <stdio.h>
unsigned long long find_product_all_prime_factors(unsigned long long);
int main()
{
    unsigned long long n, largest_lovely_number;
    scanf("%I64u",&n);
    largest_lovely_number = find_product_all_prime_factors(n);
    printf("%I64u\n",largest_lovely_number);
    return 0;
}

unsigned long long find_product_all_prime_factors(unsigned long long n)
{
    unsigned long long prime_product = 1, reduced_n = n, i;

    //n = p1^{a1} p2^{a2} ... pk^ {ak}.
    //Answer is product of n's prime factors a = p_1 p_2 ... p_k
    //This number is squarefree. And since all numbers from 1 till n are divisible by some combination of these numbers,
    //the largest squarefree number <= p_1 p_2 ... p_k. since no p^2 divides it.
    for(i = 2; i*i <= n; i++)
    {
        if(reduced_n%i == 0)
        {
            prime_product = prime_product*i;

            //Reducing n from p1^{a1} p2^{a2} ... .pn^ {an} to p2^{a2} ... .pn^ {an}
            //So that none of the multiples of i divide reduced_n. This ensures only prime factors are multiplies in product.
            while(reduced_n%i == 0)
            {
                reduced_n = reduced_n/i;
            }
        }
    }

    //N has been reduced to either 1 or a single number greater than root(n) since the composite factors of n are cancelled out, this number must be prime.
    prime_product = prime_product*reduced_n;

    return prime_product;
}
