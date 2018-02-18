#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &primes, int LIMIT)
{
    vector <int> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= LIMIT; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] <= LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

int nearest_power_of_2_greater_than(int n)
{
    int power = 1;

    while(power <= n)
        power = power << 1;

    return power;
}

int is_bit_set(int n, int position)
{
    return ( (n & (1 << position)) != 0);
}

int main()
{
    const int LIMIT = 300;
    vector <int> primes;
    precompute(primes, LIMIT);

    int n;
    scanf("%d", &n);

    if(n == 2)
    {
        printf("-1\n");
        return 0;
    }

    int N = nearest_power_of_2_greater_than(n);
    vector <long long> A(N + 5, 1);

    int first_free_prime = 0;

    for(int bit = 0; (1 << bit) < N; bit++)
    {
        int set_bit_prime = primes[first_free_prime++];
        int unset_bit_prime = primes[first_free_prime++];

        for(int i = 1; i <= N; i++)
        {
            if(is_bit_set(i, bit))
                A[i] *= set_bit_prime;
            else
                A[i] *= unset_bit_prime;
        }
    }

    for(int i = 1; 2*i <= N; i++, first_free_prime++)
    {
        A[i]   *= primes[first_free_prime];
        A[(N - 1)^i] *= primes[first_free_prime];
    }

    for(int i = 1; i <= n; i++)
        printf("%I64d\n", A[i]);

    return 0;
}
