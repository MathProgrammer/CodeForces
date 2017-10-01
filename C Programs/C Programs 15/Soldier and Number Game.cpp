#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &no_of_prime_divisors_till, int LIMIT)
{
    vector <int> largest_prime_factor(LIMIT, 0);
    vector <int> no_of_prime_divisors(LIMIT, 0);

    for(int i = 2; i < LIMIT; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(int multiple = i; multiple < LIMIT; multiple += i)
                largest_prime_factor[multiple] = i;
        }

        int p = largest_prime_factor[i];
        no_of_prime_divisors[i] = 1 + no_of_prime_divisors[i/p];

        no_of_prime_divisors_till[i] += no_of_prime_divisors[i] + no_of_prime_divisors_till[i - 1];
    }
}

int main()
{
    const int LIMIT = 5e6 + 1;
    vector <int> no_of_prime_divisors_till(LIMIT, 0);
    precompute(no_of_prime_divisors_till, LIMIT);

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int left, right;
        scanf("%d %d", &right, &left);

        printf("%d\n", no_of_prime_divisors_till[right] - no_of_prime_divisors_till[left]);
    }
    return 0;
}
