#include <iostream>

using namespace std;

const int MAX_N = 1e5 + 5, MOD = 1e9 + 7;
long long factorial[MAX_N + 5], inverse_factorial[MAX_N + 5];

long long power(long long x, long long p)
{
    long long result = 1;
    
    while(p)
    {
        if(p%2 == 1)
            result = (result*x)%MOD;
        
        x = (x*x)%MOD;
        p /= 2;
    }
    
    return result;
}

void precompute()
{
    factorial[0] = 1;
    for(int i = 1; i <= MAX_N; i++)
    {
        factorial[i] = (i*factorial[i - 1])%MOD;
    }
    
    inverse_factorial[MAX_N] = power(factorial[MAX_N], MOD - 2);
    for(int i = MAX_N - 1; i >= 0; i--)
    {
        //i*(i - 1)! = i! => (i - 1)!^ = i!^ i
        inverse_factorial[i] = ((i + 1)*inverse_factorial[i + 1])%MOD;
    }
}

long long combinations(long long n, long long k)
{
    if(n < k)
    {
        return 0;
    }
    
    long long numerator = factorial[n];
    long long denominator_inverse = (inverse_factorial[k]*inverse_factorial[n - k])%MOD;
    
    //cout << "C(" << n << "," << k << ") = " << (numerator*denominator_inverse)%MOD << endl;
    return (numerator*denominator_inverse)%MOD;
}

//Number of strings of length N consisting of numbers in [L, R]
long long count(long long left, long long right, long long length)
{
    //Either first or last element is fixed
    long long stars = length - 1;
    long long bars = right - left;
    
    return combinations(stars + bars, stars);
}

int main()
{
    precompute();
    
    int n, length;
    cin >> n >> length;
    
    long long answer = 0;
    for(int a_ending = 1; a_ending <= n; a_ending++)
    {
        for(int b_ending = a_ending; b_ending <= n; b_ending++)
        {
            answer += (count(1, a_ending, length)*count(b_ending, n, length))%MOD;
            
            answer %= MOD;
        }
    }
    
    cout << answer << "\n";
    return 0;
}
