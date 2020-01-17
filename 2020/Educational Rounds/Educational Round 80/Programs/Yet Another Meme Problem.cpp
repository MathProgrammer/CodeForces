#include <iostream>

using namespace std;

int digit_count(int n)
{
    int count = 0;
    
    while(n)
    {
        n /= 10;
        
        count++;
    }
    
    return count;
}

void solve()
{
    int a, b;
    cin >> a >> b;

    //a.b + a + b = 10a + b => a.b = 9a => a.b = 9a => b = 9
    //a.b + a + b = 100a + b => a.b = 99a => b = 99
    
    long long no_of_pairs = 0;
    
    for(long long i = 10; i - 1 <= b; i *= 10)
    {
        no_of_pairs += a;
    }
    
    cout << no_of_pairs << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
