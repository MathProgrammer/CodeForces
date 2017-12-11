#include <cstdio>
#include <vector>

using namespace std;

int reverse(int n)
{
    int rev = 0;
    while(n)
    {
        rev = rev*10 + n%10;
        n /= 10;
    }
    return rev;
}

int is_palindrome(int n)
{
    return (n == reverse(n));
}

void precompute(vector <int> &no_of_primes_till, vector <int> &no_of_palindromes_till, int LIMIT)
{
    vector <int> is_prime(LIMIT + 1, true);
    is_prime[0] = is_prime[1] = false;

    vector <int> primes;
    for(int i = 2; i <= LIMIT; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] < LIMIT; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }

    for(int i = 1; i <= LIMIT; i++)
        no_of_primes_till[i] = no_of_primes_till[i - 1] + is_prime[i];

    for(int i = 1; i <= LIMIT; i++)
        no_of_palindromes_till[i] = no_of_palindromes_till[i - 1] + is_palindrome(i);
}

int main()
{
    const int LIMIT = 2e6;
    vector <int> no_of_primes_till(LIMIT + 1, 0);
    vector <int> no_of_palindromes_till(LIMIT + 1, 0);
    precompute(no_of_primes_till, no_of_palindromes_till, LIMIT);

    int p, q;
    scanf("%d %d", &p, &q);

    for(int n = LIMIT; n >= 1; n--)
    {
        if(q*no_of_primes_till[n] <= p*no_of_palindromes_till[n])
        {
            printf("%d\n", n);
            break;
        }
    }

    return 0;
}
