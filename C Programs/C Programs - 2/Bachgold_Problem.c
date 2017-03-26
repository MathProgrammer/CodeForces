#include <stdio.h>
#include <stdlib.h>

void get_prime_series_sum_to_n(short *, unsigned int);
void fill_with_2(short *, short, unsigned int);
void display_prime_series_that_sums_to_n(short *, unsigned int);

int main()
{
    unsigned int num, no_of_terms;

    scanf("%u",&num);
    //If n is even, there are n/2 terms. If n is odd, there are (n-3)/2 + 1 = (n/2 - 1) + 1
    no_of_terms = num >> 1;
    short *prime_series_sum_n = malloc(no_of_terms*sizeof(short));

    get_prime_series_sum_to_n(prime_series_sum_n, num);

    printf("%u\n", no_of_terms);
    display_prime_series_that_sums_to_n(prime_series_sum_n, no_of_terms);

    free(prime_series_sum_n);
    return 0;
}

void get_prime_series_sum_to_n(short *prime_series_sum_n, unsigned int n)
{
    if(n%2 == 0)
    {
         //If a number is even, then the maximum number of prime terms that sum to it is n = 2 + 2 + 2 + ...
        fill_with_2(prime_series_sum_n,0, n >> 1);
    }
    else
    {
        //If a number is odd, then the maximum number of prime terms that sum to it is n = 3 + 2 + 2 + 2 + ...
        *(prime_series_sum_n) = 3;
        fill_with_2(prime_series_sum_n,1, (n - 3)>>1 );
    }
}

void display_prime_series_that_sums_to_n(short *prime_series_sum_n, unsigned int no_of_terms)
{
    unsigned int i;

    for(i = 0; i < no_of_terms; i++)
    {
        printf("%hu\t",*(prime_series_sum_n + i));
    }
}

void fill_with_2(short *prime_series_sum_n, short start, unsigned int no_of_terms)
{
    unsigned int i = start;

    for(i = start; i < no_of_terms + start; i++)
    {
        *(prime_series_sum_n + i) = 2;
    }
}
