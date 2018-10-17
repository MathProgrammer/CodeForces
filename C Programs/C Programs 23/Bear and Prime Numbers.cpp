#include <cstdio>
#include <vector>

using namespace std;

void precompute(vector <int> &is_prime, int N)
{
    is_prime[0] = is_prime[1] = false;
    vector <int> primes;

    for(int i = 2; i <= N; i++)
    {
        if(is_prime[i])
            primes.push_back(i);

        for(int j = 0; j < primes.size() && i*primes[j] <= N; j++)
        {
            is_prime[i*primes[j]] = false;

            if(i%primes[j] == 0) break;
        }
    }
}

int main()
{
    int no_of_elements;
    scanf("%d", &no_of_elements);

    const int MAX_N = 1e7;
    vector <int> frequency(MAX_N + 1, 0);
    while(no_of_elements--)
    {
        int element;
        scanf("%d", &element);
        frequency[element]++;
    }

    vector <int> is_prime(MAX_N + 1, true);
    precompute(is_prime, MAX_N);

    vector <int> no_of_multiples(MAX_N + 1, 0);
    for(int i = 1; i <= MAX_N; i++)
    {
        if(!is_prime[i]) continue;

        for(int multiple = i; multiple <= MAX_N; multiple += i)
        {
            no_of_multiples[i] += frequency[multiple];
        }
    }

    vector <int> answer(MAX_N + 1, 0);
    for(int i = 1; i <= MAX_N; i++)
        answer[i] = answer[i - 1] + no_of_multiples[i];

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
    {
        int left, right;
        scanf("%d %d", &left, &right);

        right = min(right, MAX_N);
        left = min(left, MAX_N);

        printf("%d\n", answer[right] - answer[left - 1]);
    }

    return 0;
}
