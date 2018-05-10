#include <cstdio>
#include <vector>

using namespace std;

void sieve(vector <int> &is_prime, int LIMIT)
{
    is_prime[0] = is_prime[1] = false;
    for(long long i = 2; i*i <= LIMIT; i++)
    {
        if(is_prime[i])
        {
            for(long long multiple = i*i; multiple <= LIMIT; multiple += i)
            {
                is_prime[multiple] = false;
            }
        }
    }
}

int all_prime_factors_available(int n, vector <int> &used)
{
    for(int p = 2; p*p <= n; p++)
    {
        while(n%p == 0)
        {
            if(used[p] == true) return false;

            n /= p;
        }
    }

    if(n > 1 && used[n]) return false;

    return true;
}

void mark_prime_factors(int n, vector <int> &used)
{
    for(int p = 2; p*p <= n; p++)
    {
        while(n%p == 0)
        {
            used[p] = true;

            n /= p;
        }
    }

    if(n > 1)
        used[n] = true;
}

int main()
{
    const int LIMIT = 2e6;
    vector <int> is_prime(LIMIT, true);
    sieve(is_prime, LIMIT);

    int no_of_elements;
    scanf("%d", &no_of_elements);

    vector <int> original(no_of_elements);
    for(int i = 0; i < no_of_elements; i++) scanf("%d", &original[i]);

    vector <int> solution;

    vector <int> used(LIMIT, false);
    for(int i = 0; i < no_of_elements; i++)
    {
        if(all_prime_factors_available(original[i], used))
        {
            solution.push_back(original[i]);

            mark_prime_factors(original[i], used);
        }
        else
        {
            int x = original[i] + 1;
            while(!all_prime_factors_available(x, used))
                x++;

            mark_prime_factors(x, used);

            solution.push_back(x);
            break;
        }
    }

    for(int i = 2; i < LIMIT && solution.size() < no_of_elements; i++)
    {   //printf("i = %d, u %d, p %d\n", i, used[i], is_prime[i]);
        if(!used[i] && is_prime[i])
            solution.push_back(i);
    }

    for(int i = 0; i < no_of_elements; i++) printf("%d ", solution[i]);
    return 0;
}
