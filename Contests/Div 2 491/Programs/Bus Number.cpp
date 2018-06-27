#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

vector <int> original_frequency(10, 0);
vector <long long> factorial(20, 1);
set <string> processed;

int is_bit_set(int n, int position)
{
    return ( (n&(1LL << position)) != 0);
}

void precompute()
{
    factorial[0] = 1;

    for(int i = 1; i < 20; i++)
        factorial[i] = i*factorial[i - 1];
}

void get(string S, vector <int> &frequency)
{
    for(int i = 0; i < S.size(); i++)
    {
        frequency[S[i] - '0']++;
    }
}

long long get_count(vector <int> &frequency)
{
    int sum = 0;
    long long denominator = 1;

    for(int i = 0; i < 10; i++)
    {
        sum += frequency[i];
        denominator *= factorial[frequency[i]];
    }

    long long numerator = factorial[sum];

    return (numerator/denominator);
}

long long solve(string S)
{
    vector <int> frequency(10, 0);
    get(S, frequency);

    //Not a good string.
    for(int i = 0; i < 10; i++)
        if(original_frequency[i] > 0 && frequency[i] == 0)
            return 0;

    string sorted_S;
    for(int i = 0; i < 10; i++)
        for(int j = 1; j <= frequency[i]; j++)
            sorted_S += (char)(i + '0');

    if(processed.count(sorted_S) == 1)//Already counted
        return 0;

    processed.insert(sorted_S);


    long long no_of_permutations = get_count(frequency);

    long long leading_zero_permutations = 0;

    if(frequency[0] > 0)
    {
        frequency[0]--;
        leading_zero_permutations = get_count(frequency);
    }

    return (no_of_permutations - leading_zero_permutations);
}

int main()
{
    precompute();

    string n;
    cin >> n;

    get(n, original_frequency);

    long long answer = 0;

    for(int mask = 0; mask < (1LL << n.size()); mask++)
    {
        string subset_n;

        for(int i = 0; i < n.size(); i++)
        {
            if(is_bit_set(mask, i))
            {
                subset_n += n[i];
            }
        }

        answer += solve(subset_n);
    }

    cout << answer;
    return 0;
}
