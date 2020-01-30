#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long x, long long y)
{
    if(min(x, y) == 0)
    {
        return max(x, y);
    }
    
    return gcd(max(x, y)%min(x, y), min(x, y));
}

long long totient(long long n)
{
    long long totient = 1;
    
    for(long long i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            while(n%i == 0)
            {
                n /= i;
                totient *= i;
            }
            
            totient /= i;
            totient *= (i - 1);
        }
    }
    
    if(n > 1)
    {
        totient *= 1*(n - 1);
    }
    
    return totient;
}

void solve()
{
    long long a, m;
    cin >> a >> m;
    
    long long g = gcd(a, m);
    
    long long answer = totient(m/g);
    
    cout << answer << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
