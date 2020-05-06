#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353, MAX_N = 1e6 + 5;

vector <long long> primes, factorial(MAX_N), inverse_factorial(MAX_N);

long long gcd(long long x, long long y)
{
    if(min(x, y) == 0)
    {
        return max(x, y);
    }
    
    return gcd(max(x, y)%min(x, y), min(x, y));
}

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

void factorise(long long d)
{
    for(long long i = 2; i*i <= d; i++)
    {
        if(d%i == 0)
        {
            primes.push_back(i);
            
            while(d%i == 0)
            {
                d /= i;
            }
        }
    }
    
    if(d > 1)
    {
        primes.push_back(d);
    }
}

void precompute_factorial()
{
    factorial[0] = 1;
    for(int i = 1; i < MAX_N; i++)
    {
        factorial[i] = (i*factorial[i - 1])%MOD;
    }
    
    //i*(i - 1)! = i! => (i - 1)!^ = i!^i
    inverse_factorial[MAX_N - 1] = power_mod(factorial[MAX_N - 1], MOD - 2);
    for(int i = MAX_N - 2; i >= 0; i--)
    {
        inverse_factorial[i] = ((i + 1)*inverse_factorial[i + 1])%MOD;
    }
}

//Here y is a divisor of x, by convention
long long get_count(long long x, long long y)
{
    if(x%y != 0)
    {
        return -1;
    }
    
    vector <int> path;
    
    for(int i = 0; i < primes.size(); i++)
    {
        int x_exponent = 0, y_exponent = 0;
        
        if(x%primes[i] != 0)
        {
            continue;
        }
        
        while(y%primes[i] == 0)
        {
            y /= primes[i];
            
            y_exponent++;
        }
        
        while(x%primes[i] == 0)
        {
            x /= primes[i];
            
            x_exponent++;
        }
        
        path.push_back(x_exponent - y_exponent);
    }
    
    int total_steps = 0;
    for(int i = 0; i < path.size(); i++)
    {
        total_steps += path[i];
    }
   
    long long answer = factorial[total_steps];
    for(int i = 0; i < path.size(); i++)
    {   
        answer = (answer*inverse_factorial[path[i]])%MOD;
    }
    
    return answer;
}

int main()
{
    precompute_factorial();
    
    long long d;
    int no_of_queries;
    cin >> d >> no_of_queries;
    
    factorise(d);
    
    while(no_of_queries--)
    {
        long long x, y;
        cin >> x >> y;
        
        long long path_1 = get_count(x, gcd(x, y));
        long long path_2 = get_count(y, gcd(x, y));
        
        long long answer = (path_1*path_2)%MOD;
        
        cout << answer << "\n";
    }
    
    return 0;
}
