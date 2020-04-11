#include <iostream>
#include <map>

using namespace std;

#define PHI(x) 500000002

long long power_mod(long long x, long long power, long long mod)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%mod;

        x = (x*x)%mod;
        power = power >> 1;
    }

    return result;
}

long long ceil(long long n, long long x)
{
    long long quotient = n/x;
    long long remainder = n%x;

    return (quotient + (remainder > 0));
}

int main()
{
    const int MOD = 1e9 + 7;
    long long product = 1LL;

    int no_of_primes;
    cin >>  no_of_primes;

    map <int, long long> exponent;

    for(int i = 1; i <= no_of_primes; i++)
    {
        int prime_i;
        scanf("%d", &prime_i);

        exponent[prime_i]++;
    }

    long long no_of_divisors = 1;
    for(map <int, long long> :: iterator it = exponent.begin(); it != exponent.end(); it++)
    {
        int p = it->first;
        long long exp = it->second;

        long long divisor_product_here = power_mod(p, (exp*(exp + 1))/2, MOD);
        product = power_mod(product, exp + 1, MOD)*power_mod(divisor_product_here, no_of_divisors, MOD);
        product %= MOD;
        
        no_of_divisors *= (exp + 1);
        no_of_divisors %= (MOD - 1);
    }

    cout << product << "\n";
    return 0;
}
