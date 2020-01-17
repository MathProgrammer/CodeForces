#include <iostream>

using namespace std;

int ceil(int n, int d)
{
    return (n/d + (n%d != 0));
}

void solve()
{
    int n, d;
    cin >> n >> d;
    
    if(d <= n)
    {
        cout << "YES\n";
        
        return;
    }
    
    const int N = 2e6;
    for(int x = 1; x <= min(n, N); x++)
    {
        int optimised_d = ceil(d, x + 1);
        //cout << "d = " << optimised_d << " x = " << x << "\n";
        
        if(optimised_d + x <= n)
        {
            cout << "YES\n";
            return;
        }
    }
    
    cout << "NO\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
