#include <cstdio>
#include <vector>

using namespace std;

vector <int> no_of_almost_primes_till(3000 + 1, 0);

void precompute_primes()
{
    vector <int> no_of_prime_factors(3000 + 1, 0);

    for(int i = 2; i <= 3000; i++)
    {
        if(no_of_prime_factors[i] == 0)
        {
            for(int multiple = i; multiple <= 3000; multiple += i)
            {
                no_of_prime_factors[multiple]++;
            }
        }
    }

    for(int i = 1; i <= 3000; i++)
    {
        no_of_almost_primes_till[i] = no_of_almost_primes_till[i - 1] + (no_of_prime_factors[i] == 2);
    }
}

int main()
{
    precompute_primes();

    int n;
    scanf("%d", &n);
    printf("%d\n", no_of_almost_primes_till[n]);

    return 0;
}
