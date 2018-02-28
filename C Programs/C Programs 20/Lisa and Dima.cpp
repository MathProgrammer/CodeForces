#include <cstdio>
#include <vector>

using namespace std;

int is_prime(int n)
{
    for(int i = 2; i*i <= n; i++)
        if(n%i == 0)
            return false;

    return true;
}

void sieve(vector <int> &is_prime)
{
    int N = is_prime.size();
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i*i <= N; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = i*i; multiple <= N; multiple += i)
            {
                is_prime[multiple] = false;
            }
        }
    }
}

void break_into_sum_of_primes(int N, int &prime_1, int &prime_2)
{
    vector <int> is_prime(N + 1, true);
    sieve(is_prime);

    for(int i = 2; i <= N; i++)
    {
        if(is_prime[i] && is_prime[N - i])
        {
            prime_1 = i;
            prime_2 = N - i;
            return;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    if(is_prime(n))
    {
        printf("1\n%d\n", n);
        return 0;
    }

    if(is_prime(n - 2))
    {
        printf("2\n%d %d", 2, n - 2);
        return 0;
    }

    int prime_1, prime_2, prime_3;

    for(int i = n - 4; ; i--)
    {
        if(is_prime(i))
        {
            prime_3 = i;
            break;
        }
    }

    break_into_sum_of_primes(n - prime_3, prime_1, prime_2);
    printf("3\n%d %d %d\n", prime_1, prime_2, prime_3);

    return 0;
}
