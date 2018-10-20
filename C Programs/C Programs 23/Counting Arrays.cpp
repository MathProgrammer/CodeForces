#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int MAX_N = 2e6, MOD =1e9 + 7;
vector <long long> factorial(MAX_N + 1), inverse_factorial(MAX_N + 1);
vector <long long> primes;

void sieve()
{
    vector <int> is_prime(MAX_N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= MAX_N; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] <= MAX_N; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

long long power_mod(long long x, long long power)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%MOD;

        x = (x*x)%MOD;
        power = power >> 1;
    }

    return result;
}

void precompute()
{
    factorial[0] = 1;
    for(int i = 1; i <= MAX_N; i++)
        factorial[i] = (i*factorial[i - 1])%MOD;

    inverse_factorial[MAX_N] = power_mod(factorial[MAX_N], MOD - 2);
    for(int i = MAX_N - 1; i >= 0; i--)
        inverse_factorial[i] = ((i + 1)*inverse_factorial[i + 1])%MOD;
}

long long choose(long long n, long long r)
{
    long long numerator = factorial[n];
    long long inverse_denominator = (inverse_factorial[r]*inverse_factorial[n - r])%MOD;

    return (numerator*inverse_denominator)%MOD;
}

void factorise(int n, map <int, int> &exponent)
{
    for(int i = 0; primes[i]*primes[i] <=n; i++)
    {
        while(n%primes[i] == 0)
        {
            exponent[primes[i]]++;

            n /= primes[i];
        }
    }

    if(n > 1)
        exponent[n]++;
}

void solve()
{
    int x, no_of_summands;
    cin >> x >> no_of_summands;

    map <int, int> prime_exponents;
    factorise(x, prime_exponents);

    long long answer = 1;
    for(map <int, int> :: iterator it = prime_exponents.begin(); it != prime_exponents.end(); it++)
    {
        int exponent = it->second;

        answer *= choose(no_of_summands + exponent - 1, no_of_summands - 1);

        answer %= MOD;
    }

    long long ways_to_distribute_signs = power_mod(2, no_of_summands - 1);

    answer = (answer*ways_to_distribute_signs)%MOD;

    cout << answer << "\n";
}

int main()
{
    sieve();
    precompute();

    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}
