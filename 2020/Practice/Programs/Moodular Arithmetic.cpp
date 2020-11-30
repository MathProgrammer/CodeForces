#include <iostream>

using namespace std;

long long power_mod(long long x, long long power, long long m)
{
    long long result = 1;
    
    while(power > 0)
    {
        if(power%2 == 1)
            result = (result*x)%m;
        
        x = (x*x)%m;
        power = power >> 1;
    }
    
    return result;
}

int order(int k, int m)
{
    int answer = m - 1;
    
    for(int i = 1; i*i <= m - 1; i++)
    {
        if((m - 1)%i == 0)
        {
            if(power_mod(k, i, m) == 1)
            {
                answer = min(answer, i);
            }
            else if(power_mod(k, (m - 1)/i, m) == 1)
            {
                answer = min(answer, (m - 1)/i);
            }
        }
    }
    
    return answer;
}

int main()
{
    int p, k;
    cin >> p >> k;
    
    const int MOD = 1e9 + 7;
    if(k == 0)
    {
        cout << power_mod(p, p  - 1, MOD) << "\n";
        return 0;
    }
    if(k == 1)
    {
        cout << power_mod(p, p, MOD) << "\n";
        return 0;
    }
    
    cout << power_mod(p, (p - 1)/order(k, p), MOD) << "\n";
    return 0;
}

