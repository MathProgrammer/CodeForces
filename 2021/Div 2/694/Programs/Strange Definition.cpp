#include <iostream>
#include <vector>
#include <map>
#include  <algorithm>

using namespace std;

const int MAX_N = 1e6 + 5;
vector  <int> primes;
vector <int> value(MAX_N, 1);

void sieve(int n)
{
    vector <int> largest_prime_factor(MAX_N, 0);

    for(long long i = 2; i < MAX_N; i++)
    {
        if(largest_prime_factor[i] == 0)
        {
            for(long long multiple = i; multiple < MAX_N; multiple += i)
            {
                largest_prime_factor[multiple] = i;
            }
        }
    }

    for(int i = 2; i < MAX_N; i++)
    {
        int current = i, exponent = 0;

        while(current%largest_prime_factor[i] == 0)
        {
            current /= largest_prime_factor[i];

            exponent++;
        }

        value[i] = value[current];

        if(exponent%2 == 1)
        {
            value[i] *= largest_prime_factor[i];
        }
    }
}

void solve()
{
    int no_of_elements;
    cin >> no_of_elements;

    map <int, int> frequency;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        A[i] = value[A[i]];

        frequency[A[i]]++;
    }

    int even_frequency = 0, max_frequency = frequency[1];
    for(map <int, int> :: iterator it = frequency.begin(); it != frequency.end(); it++)
    {
        if(it->first == 1)
        {
            continue;
        }

        if(it->second%2 == 0)
        {
            even_frequency += it->second;
        }

        max_frequency = max(max_frequency, it->second);
    }

    int initial_answer = max_frequency;
    int final_answer = max(max_frequency, frequency[1] + even_frequency);

    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
    {
        long long time;
        cin >> time;

        int answer = (time == 0 ? initial_answer : final_answer);
        cout << answer << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(MAX_N);

    int no_of_test_cases;
    cin >> no_of_test_cases;

    while(no_of_test_cases--)
        solve();

    return 0;
}
