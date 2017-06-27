#include <cstdio>
#include <vector>

using namespace std;

vector <int> noldbach_number(1000 + 1, false);
vector <int> primes;

void precompute_noldbach()
{
    vector <int> is_prime(1000 + 1, true);

    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 1000; i++)
    {
        if(is_prime[i])
        {
            for(int multiple = 2*i; multiple <= 1000; multiple += i)
            {
                is_prime[multiple] = false;
            }
            primes.push_back(i);
        }
    }

    for(int i = 0; primes[i] + primes[i + 1] <= 1000 ; i++)
    {
        noldbach_number[primes[i] + primes[i + 1] + 1] = true;
    }

}

int main()
{
    precompute_noldbach();
    int n, k;
    scanf("%d %d", &n, &k);

    int conjecture_count = 0;
    for(int i = 0; primes[i] <= n; i++)
    {
        if(noldbach_number[primes[i]])
            conjecture_count++;
    }

    printf(conjecture_count >= k ? "YES\n" : "NO\n");
    return 0;
}
