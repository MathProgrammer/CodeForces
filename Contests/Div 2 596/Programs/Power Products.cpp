#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

const int N = 1e5 + 5;
const long long oo = 1e10;
vector <long long> primes;

void sieve()
{
    vector <int> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < N; i++)
    {
        if(is_prime[i])
        {
            primes.push_back(i);
        }

        for(int j = 0; j < primes.size() && i*primes[j] < N; j++)
        {
            is_prime[i*primes[j]] = false;

            if(primes[j]%i == 0)
            {
                break;
            }
        }
    }
}

void get_factors(vector <pair <int, int> > &F, long long &n)
{
    for(int i = 0; n > 1 && i < primes.size(); i++)
    {
        if(n%primes[i] != 0)
        {
            continue;
        }

        int exponent = 0;

        while(n%primes[i] == 0)
        {
            n /= primes[i];

            exponent++;
        }

        F.push_back(make_pair(primes[i], exponent));
    }

    if(n > 1)
    {
        F.push_back(make_pair(n, 1));

        n /= n;
    }
}

long long get_complement(long long n, long long power)
{
    long long complement = 1;

    for(int i = 0; n > 1 && i < primes.size(); i++)
    {
        if(primes[i]*primes[i] > n)
        {
            break;
        }

        if(n%primes[i] != 0)
        {
            continue;
        }

        int exponent = 0;

        while(n%primes[i] == 0)
        {
            n /= primes[i];

            exponent++;
        }

        while(exponent%power != 0)
        {
            exponent++;

            if(complement > oo/primes[i])
            {
                complement = -1;

                return -1;
            }
            else
            {
                complement *= primes[i];
            }
        }
    }

    if(n == 1)
    {
        return complement;
    }

    int exponent = 1;

    while(exponent%power != 0)
    {
        exponent++;

        if(complement > oo/n)
        {
            complement = -1;

            return -1;
        }
        else
        {
            complement *= n;
        }
    }

    return complement;
}

int main()
{
    sieve();

    int no_of_elements, power;
    scanf("%d %d", &no_of_elements, &power);

    vector <long long> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        scanf("%I64d", &A[i]);

        vector <pair <int, int> > factors;

        get_factors(factors, A[i]);

        for(int f = 0; f < factors.size(); f++)
        {
            int p = factors[f].first;
            int exponent = (factors[f].second)%power;

            for(int e = 1; e <= exponent; e++)
            {
                A[i] *= p;
            }
        }
    }

    long long answer = 0;
    map <long long, int> frequency;
    for(int i = 1; i <= no_of_elements; i++)
    {
        long long complement = get_complement(A[i], power);

        answer += frequency[complement];

        frequency[A[i]]++;
    }

    printf("%I64d\n", answer);
    return 0;
}
