#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    long long n;
    cin >> n;
    
    long long final_n = n;
    pair <int, long long> best_prime;
    
    vector <pair <int, long long> > prime_exponents;
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
            
            prime_exponents.push_back(make_pair(exponent, i));
            
            best_prime = max(best_prime, prime_exponents.back());
        }
    }
    
    if(n > 1)
    {
        prime_exponents.push_back(make_pair(1, n));
        
        best_prime = max(best_prime, prime_exponents.back());
    }
    
    cout << best_prime.first << "\n";
    for(int i = 1; i < best_prime.first; i++)
    {
        cout << best_prime.second << " ";
        
        final_n /= best_prime.second;
    }
    
    cout << final_n << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
        
    return 0;
}
