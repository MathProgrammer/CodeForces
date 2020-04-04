#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353, MAX_N = 5e5 + 5;
vector <long long> factorials(MAX_N + 1, 0), inverse_factorials(MAX_N + 1, 0);

long long power(long long x, long long p)
{
    long long answer = 1;
    
    while(p)
    {
        if(p%2 == 1)
        {
            answer = (answer*x)%MOD;
        }
        
        x = (x*x)%MOD;
        p = p/2;
    }
    
    return answer;
}

long long inverse(long long n)
{
    return power(n, MOD - 2);
}

void precompute_factorials()
{
    factorials[0] = 1;
    for(int i = 1; i < MAX_N; i++)
    {
        factorials[i] = (factorials[i - 1]*i)%MOD;
    }
    
    //i*(i - 1)! = i!
    inverse_factorials[MAX_N - 1] = inverse(factorials[MAX_N - 1]);
    for(int i = MAX_N - 2; i >= 0; i--)
    {
        inverse_factorials[i] = ((i + 1)*inverse_factorials[i + 1])%MOD;
    }
}

long long choose(long long n, long long r)
{
    long long numerator = factorials[n];
    long long inverse_denominator = (inverse_factorials[r]*inverse_factorials[n - r])%MOD;
    
    return (numerator*inverse_denominator)%MOD;
}

int main()
{
    precompute_factorials();
    
    long long no_of_elements, m;
    cin >> no_of_elements >> m;
    
    if(no_of_elements == 2)
    {
        cout << "0\n";
        
        return 0;
    }
    
    long long answer = (choose(m, no_of_elements - 1)*(no_of_elements - 2))%MOD;
    answer *= power(2, no_of_elements - 3);
    answer %= MOD;
    
    cout << answer << "\n";
    return 0;
}
