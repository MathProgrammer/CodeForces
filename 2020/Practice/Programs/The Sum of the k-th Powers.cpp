#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long power_mod(long long x, long long power)
{
    long long result = 1;
    
    while(power)
    {
        if(power%2 == 1)
            result = (result*x)%MOD;
        
        x = (x*x)%MOD;
        power = power >> 1;
    }
    
    return result;
}

long long inverse(long long x)
{
    return power_mod(x, MOD - 2);
}

int main()
{
    long long n, power;
    cin >> n >> power;
    
    //f(i) = 1^k + 2^k + ... + i^k
    vector <long long> value(power + 3, 0);
    for(int i = 1; i <= power + 2; i++)
    {
        value[i] = (value[i - 1] + power_mod(i, power))%MOD;
    }
    
    if(n <= power + 2)
    {
        cout << value[n] << "\n";
        return 0;
    }
    
    long long numerator = 1, denominator = 1;
    long long largest = (1 - 2 + MOD)%MOD, smallest = (1 - (power + 2) + MOD)%MOD;
    for(int i = 2; i <= power + 2; i++)
    {
        numerator = (numerator*(n - i))%MOD; 
        
        denominator = (denominator*(1 - i + MOD))%MOD;
    }
    
    long long answer = value[1]*numerator;
    answer = (answer*inverse(denominator))%MOD;
    
    for(int i = 2; i <= power + 2; i++)
    {
        numerator = (numerator*inverse(n - i))%MOD;
        numerator = (numerator*(n - (i - 1)))%MOD;
        
        largest = (largest + 1)%MOD;
        if(largest == 0)
        {
            largest = (largest + 1)%MOD;
        }
        
        if(smallest == 0)
        {
            smallest = (smallest + 1)%MOD;
        }
        
        denominator = (denominator*inverse(smallest))%MOD;
        denominator = (denominator*(largest))%MOD;// cout << "Remove small = " << smallest << " largest = " << largest << " D = " << denominator << "\n";
        
       smallest = (smallest + 1)%MOD;
        
       
                       
        long long current_term = (numerator*inverse(denominator))%MOD;
        current_term = (value[i]*current_term)%MOD;
        
        answer = (answer + current_term)%MOD;
    }
    
    cout << answer << "\n";
    
    return 0;
}
