#include <cstdio>
#include <vector>
#include <math.h>

using namespace std;

vector <int> is_prime(1000000 + 1, true);

void precompute_prime_squares()
{
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; i <= 1e6; i++)
        if(is_prime[i])
            for(int multiple = 2*i; multiple <= 1e6; multiple += i)
                is_prime[multiple] = false;

}

int main()
{
    int no_of_queries;
    scanf("%d", &no_of_queries);

    precompute_prime_squares();

    for(int i = 1; i <= no_of_queries; i++)
    {
        long long number, root;
        scanf("%I64d", &number);

        root = (int) sqrt(number);

        printf(root*root == number && is_prime[root] ? "YES\n" : "NO\n");
    }
    return 0;
}
