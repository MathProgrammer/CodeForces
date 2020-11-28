#include <iostream>
#include <vector>

using namespace std;

long long power_mod(long long x, long long power, long long mod)
{
    long long result = 1LL;
    
    while(power > 0)
    {
        if(power%2 == 1)
        {
            result = (result*x)%mod;
        }
        
        power = power >> 1;
        x = (x*x)%mod;
    }
    
    return result;
}

long long inverse(long long x, long long mod)
{
    return power_mod(x, mod - 2, mod);
}

long long choose_2(long long n, long long mod)
{
    return ((n*(n + 1))/2)%mod;
}

int main()
{
    string S;
    cin >> S;
    
    const int MOD = 1e9 + 7;
    vector <long long> suffix_cost(S.size() + 5);
    for(int i = S.size() - 1, suffix = 0; i >= 0; i--, suffix++)
    {
        suffix_cost[i] = power_mod(10, suffix, MOD)*(S[i] - '0');
        
        suffix_cost[i] %=  MOD;
        
        suffix_cost[i] *= choose_2(i, MOD);
        
        suffix_cost[i] %= MOD; 
    }
    
    vector <long long> multiplier(S.size() + 5, 0);
    for(int i = 1; i <= S.size(); i++)
    {
        multiplier[i] = (multiplier[i - 1] + (i)*power_mod(10, i - 1, MOD))%MOD;
    }
    
    vector <long long> prefix_cost(S.size() + 1, 0);
    for(int i = 0; i < S.size(); i++)
    {
        prefix_cost[i] = ((multiplier[S.size() - 1 - i])*(S[i] - '0'))%MOD;
        
        //cout << "Prefix Cost " << i << " = " << prefix_cost[i] << "\n";
    }
    
    long long answer = 0;
    for(int i = 0; i < S.size(); i++)
    {
        answer += (prefix_cost[i] + suffix_cost[i])%MOD;
                
        answer %= MOD;
    }

    cout << answer << "\n";
    
    return 0;
}
