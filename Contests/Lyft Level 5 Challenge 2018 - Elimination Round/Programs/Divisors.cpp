#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b)
{
    if(min(a, b) == 0)
        return max(a, b);
    else
        return gcd(min(a, b), max(a, b)%min(a, b));
}

void precompute(vector <int> &primes, int LIMIT)
{
    vector <int> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i < LIMIT; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

int main()
{
    const int LIMIT = 2e6;
    vector <int> primes;
    precompute(primes, LIMIT);

    int no_of_numbers;
    scanf("%d", &no_of_numbers);

    vector <long long> A(no_of_numbers + 1);
    for(int i = 1; i <= no_of_numbers; i++)
        scanf("%I64d", &A[i]);

    vector <int> factorised(no_of_numbers + 1, false);

    const int MOD = 998244353;
    long long no_of_divisors = 1;
    map <long long, int> prime_exponent;
    for(int i = 1; i <= no_of_numbers; i++)
    {
        if(factorised[i]) continue;

        long long root = (long long) sqrt(A[i]);

        if(root*root == A[i]) //Perfect square. Either 3 or 5 factors
        {
            long long fourth_root = (long long) sqrt(root);

            if(fourth_root*fourth_root == root) //A[i] = p^4
            {
                prime_exponent[fourth_root] += 4;
            }
            else
            {
                prime_exponent[root] += 2; //A[i] = p^2
            }

            factorised[i] = true;
        }
        else //A[i] has 4 factors. A[i] = pq or A[i] = p^3
        {
            long long factor_1 = 0, factor_2 = 0;

            for(int p = 0; p < primes.size(); p++)
            {
                if(A[i]%primes[p] == 0)
                {
                    factor_1 = primes[p];

                    if(factor_1*factor_1*factor_1 == A[i]) // A[i] = p^3
                    {
                        prime_exponent[factor_1] += 3;
                    }
                    else
                    {
                        prime_exponent[factor_1]++;
                        prime_exponent[A[i]/factor_1]++;
                    }

                    factorised[i] = true;
                    break;
                }
            }

            if(!factorised[i])
            {
                for(int j = 1; j <= no_of_numbers; j++)
                {
                    if(gcd(A[j], A[i]) > 1 && gcd(A[i], A[j]) < A[i])
                    {
                        factor_1 = gcd(A[i], A[j]);
                        factor_2 = A[i]/factor_1;

                        prime_exponent[factor_1]++;
                        prime_exponent[factor_2]++;

                        factorised[i] = true;
                        break;
                    }
                }
            }

            int frequency = 0;
            if(!factorised[i])
            {
                for(int j = 1; j <= no_of_numbers; j++)
                {
                    if(A[i] == A[j])
                    {
                        frequency++;

                        factorised[j] = true;
                    }
                }
            }

            if(factor_1 == 0 && factor_2 == 0) //Two new factors
                no_of_divisors = (no_of_divisors*(frequency + 1)*(frequency + 1))%MOD;
        }
    }


    for(map <long long, int> :: iterator it = prime_exponent.begin(); it != prime_exponent.end(); it++)
    {
        int divisors_here = it->second + 1;

        no_of_divisors = (no_of_divisors*divisors_here)%MOD;
    }

    printf("%I64d\n", no_of_divisors);
    return 0;
}
