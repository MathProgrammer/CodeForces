#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const unsigned long long MAX_P = 55, oo = LLONG_MAX;
unsigned long long max_good = 0;
vector <unsigned long long> powers;

void precompute()
{
    powers.push_back(1);

    unsigned long long n = 1;
    while(n <= oo/3)
    {
        n = n*3ULL;

        powers.push_back(n);
    }
}

void display(unsigned long long n)
{
    long long temp_n = n;
    vector <int> exponent(powers.size(), 0);
    for(int i = powers.size() - 1; i >= 0; i--)
    {
        while(temp_n >= powers[i])
        {
            temp_n -= powers[i];

            exponent[i]++;
        }
    }

    for(int i = powers.size() - 1; i >= 0; i--)
    {
        cout << exponent[i];
    }

    cout << "\n";
}

void solve()
{
    unsigned long long n;
    cin >> n;

    unsigned long long temp_n = n;
    vector <int> exponent(powers.size() + 5, 0);
    for(int i = powers.size() - 1; i >= 0; i--)
    {
        while(temp_n >= powers[i])
        {
            temp_n -= powers[i];

            exponent[i]++;
        }
    }

    int left_most_2 = powers.size();
    for(int i = powers.size() - 1; i >= 0; i--)
    {
        if(exponent[i] == 2)
        {
            left_most_2 = i;

            break;
        }
    }

    if(left_most_2 == powers.size())
    {
        cout << n << "\n";

        return;
    }

    int next_zero = left_most_2;
    for(int i = left_most_2; i < powers.size(); i++)
    {
        if(exponent[i] == 0)
        {
            next_zero = i;

            break;
        }
    }

    vector <int> answer_exponent(powers.size() + 5, 0);
    for(int i = powers.size() - 1; i > next_zero; i--)
        answer_exponent[i] = exponent[i];

    answer_exponent[next_zero] = 1;
    for(int i = next_zero - 1; i >= 0; i--)
    {
        answer_exponent[i] = 0;
    }

    unsigned long long answer = 0;
    for(int i = 0; i < powers.size(); i++)
    {
        answer += answer_exponent[i]*powers[i];
    }

    cout << answer << "\n";
}

int main()
{
    precompute();

    int no_of_queries;
    cin >> no_of_queries;

    while(no_of_queries--)
        solve();

    return 0;
}

