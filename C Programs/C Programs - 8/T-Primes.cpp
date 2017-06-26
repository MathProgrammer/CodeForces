#include <cstdio>
#include <vector>
#include <set>

using namespace std;

set <long long> prime_square;

void precompute_prime_squares()
{
    vector <int> is_prime(1000000 + 1, true);

    for(int i = 2; i <= 1e6; i++)
    {
        if(is_prime[i])
        {
            prime_square.insert(i*1LL*i);

            for(int multiple = 2*i; multiple <= 1e6; multiple += i)
                is_prime[multiple] = false;
        }
    }
}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);

    precompute_prime_squares();

    for(int i = 1; i <= no_of_queries; i++)
    {
        long long number;
        scanf("%I64d", &number);

        printf(prime_square.count(number) == 1 ? "YES\n" : "NO\n");
    }
    return 0;
}
