#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    if(n <= 30)
    {
        cout << "NO\n";
        
        return;
    }
    
    cout << "YES\n";
    switch(n)
    {
        case 36 :
        case 40 :
        case 44 : cout << "6 10 15 " << n - 31 << "\n";
            return;
            
        default : cout << "6 10 14 " << n - 30 << "\n";
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
