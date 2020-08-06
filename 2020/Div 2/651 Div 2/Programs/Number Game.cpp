#include <iostream>

using namespace std;

int is_power_of_2(int n)
{
    return ( (n == 1) || (n&(n - 1)) == 0 );
}

int get_prime_divisor_count(int n)
{
    int count = 0;
    
    for(int i = 2; i*i <= n; i++)
    {
        while(n%i == 0)
        {
            n /= i;
            
            count++;
        }
    }
    
    if(n > 1)
    {
        count++;
    }
    
    return count;
}

void solve()
{
    int n;
    cin >> n;
    
    if(n%4 == 0)
    {
        cout << (!is_power_of_2(n) ? "Ashishgup\n" : "FastestFinger\n");
        return;
    }
    
    if(n%2 == 1)
    {
        cout << (n > 1 ? "Ashishgup\n" : "FastestFinger\n");
        
        return;
    }
    
    if(n == 2)
    {
        cout << "Ashishgup\n";
        
        return;
    }
    
    int no_of_odd_divisors = get_prime_divisor_count(n) - 1;
    
    cout << (no_of_odd_divisors > 1 ? "Ashishgup\n" : "FastestFinger\n");
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
