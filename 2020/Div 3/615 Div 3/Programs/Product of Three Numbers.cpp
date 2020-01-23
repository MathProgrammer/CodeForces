#include <iostream>
#include <vector>
#include <algorithm>

#define all(v) (v).begin(), (v).end()
using namespace std;

void factorise(int n, vector <int> &P, vector <int> &E)
{
    for(long long i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            int exponent = 0;
            
            while(n%i == 0)
            {
                n /= i;
                exponent++;
            }
            
            P.push_back(i);
            E.push_back(exponent);
        }
    }
    
    if(n > 1)
    {
        P.push_back(n);
        E.push_back(1);
    }
}

void solve()
{
    int n;
    cin >> n;
    
    vector <int> primes;
    vector <int> exponents;
    factorise(n, primes, exponents);
    
    if(primes.size() >= 3)
    {
        cout << "YES\n";
        cout << primes[0] << " " << primes[1] << " " << n/(primes[0]*primes[1]) << "\n";
                                                           
        return;
    }
    
    if(primes.size() == 1)
    {
        if(exponents[0] < 6)
        {
            cout << "NO\n";
            return;
        }
        
        long long f1 = primes[0], f2 = primes[0]*primes[0];
        
        cout << "YES\n";
        cout << f1 << " " << f2 << " " << n/(f1*f2) << "\n";
        
        return;
    }
    
    if(primes.size() == 2)
    {
        if(min(exponents[0], exponents[1]) == 1 && max(exponents[0], exponents[1]) <= 2)
        {
            cout << "NO\n";
            
            return;
        }
        
        cout << "YES\n";
        cout << primes[0] << " " << primes[1] << " " << n/(primes[0]*primes[1]) << "\n";
        return;
    }
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
