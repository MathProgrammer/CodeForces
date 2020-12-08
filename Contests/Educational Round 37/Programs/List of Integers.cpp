#include <cstdio>
#include <vector>

using namespace std;

const int MAX_N = 1e6 + 15;

vector <int> inclusion_exclusion_factors[MAX_N];

void sieve()
{
    for(int i = 1; i < MAX_N; i++)
        inclusion_exclusion_factors[i].push_back(1);

    for(int i = 2; i < MAX_N; i++)
    {
        if(inclusion_exclusion_factors[i].size() > 1) //Not prime
            continue;

        for(int multiple = i; multiple < MAX_N; multiple += i)
        {
            int original_size = inclusion_exclusion_factors[multiple].size();

            for(int j = 0; j < original_size; j++)
            {
                int new_factor = (-1)*inclusion_exclusion_factors[multiple][j]*i;

                inclusion_exclusion_factors[multiple].push_back(new_factor);
            }
        }
    }
}

int no_of_coprime_integers_till(int n, int limit)
{
    int answer = 0;

    for(int i = 0; i < inclusion_exclusion_factors[n].size(); i++)
    {
        answer += limit/inclusion_exclusion_factors[n][i];
    }

    return answer;
}

void solve()
{
    int n, x, target;
    scanf("%d %d %d", &x, &n, &target);

    target += no_of_coprime_integers_till(n, x);

    int left = 1, right = 1e9, answer;

    while(left <= right) //f(n, L) < target and f(n, R) >= target
    {
        int mid = (left + right) >> 1;

        if(no_of_coprime_integers_till(n, mid) < target)
        {
            if(no_of_coprime_integers_till(n, mid + 1) == target)
            {
                answer = mid + 1;
                break;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if(no_of_coprime_integers_till(n, mid) >= target)
        {
            right = mid;
        }
    }

    printf("%d\n", answer);
}

int main()
{
    sieve();

    int no_of_queries;
    scanf("%d", &no_of_queries);

    while(no_of_queries--)
        solve();

    return 0;
}
