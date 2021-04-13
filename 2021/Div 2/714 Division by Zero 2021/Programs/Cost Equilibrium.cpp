#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1e9 + 7, MAX_N = 1e5 + 5;
vector <long long> factorial(MAX_N, 0), inverse_factorial(MAX_N, 0);

long long power_mod(long long x, long long power, long long mod)
{
    long long result = 1;

    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%mod;

        x = (x*x)%mod;
        power = power >> 1;
    }

    return result;
}

void precompute()
{
    factorial[0] = 1;
    for(int i = 1; i < MAX_N; i++)
    {
        factorial[i] = (i*factorial[i - 1])%MOD;
    }

    //i*(i - 1)! = i!
    inverse_factorial[MAX_N - 1] = power_mod(factorial[MAX_N - 1], MOD - 2, MOD);
    for(int i = MAX_N - 2; i >= 0; i--)
    {
        inverse_factorial[i] = (i + 1)*inverse_factorial[i + 1];

        inverse_factorial[i] %= MOD;
    }
}

long long multinomial(vector <long long> &frequency)
{
    long long total = 0;
    long long numerator = 0, inverse_denominator = 1;

    for(int i = 0; i < frequency.size(); i++)
    {
        total += frequency[i];

        inverse_denominator *= inverse_factorial[frequency[i]];

        inverse_denominator %= MOD;
    }

    numerator = factorial[total];

    long long answer = (numerator*inverse_denominator)%MOD;

    return answer;
}

long long stars_and_bars(long long stars, long long bars)
{
    long long numerator = factorial[stars + bars - 1];
    long long inverse_denominator = (inverse_factorial[stars]*inverse_factorial[bars - 1])%MOD;

    return (numerator*inverse_denominator)%MOD;
}

int main()
{
    precompute();

    int no_of_elements;
    cin >> no_of_elements;

    map <int, int> frequency;
    long long sum = 0;
    vector <int> A(no_of_elements + 1);
    for(int i = 1; i <= no_of_elements; i++)
    {
        cin >> A[i];

        sum += A[i];

        frequency[A[i]]++;
    }

    if(sum%no_of_elements != 0)
    {
        cout << "0\n";

        return 0;
    }

    int final_value = (sum/no_of_elements);

    vector <long long> F, source_frequency, sink_frequency;

    for(auto it = frequency.begin(); it != frequency.end(); it++)
    {
        if(it->first > final_value)
        {
            source_frequency.push_back(it->second);
        }
        else if(it->first < final_value)
        {
            sink_frequency.push_back(it->second);
        }

        F.push_back(it->second);
    }

    long long answer;
    if(source_frequency.size() == 0 || sink_frequency.size() == 0 ||
       (source_frequency.size() == 1 && source_frequency[0] == 1) || (sink_frequency.size() == 1 && sink_frequency[0] == 1) )
    {
        answer = multinomial(F);

        cout << answer << "\n";

        return 0;
    }

    long long sources = multinomial(source_frequency), sink = multinomial(sink_frequency);
    long long equal_values = frequency[final_value], spaces = no_of_elements - equal_values + 1;

    long long remaining = stars_and_bars(equal_values, spaces);

    answer = (sources*sink)%MOD;
    answer = (answer*remaining)%MOD;
    answer = (answer*2)%MOD;;

    cout << answer << "\n";

    return 0;
}


