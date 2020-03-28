#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    if(n == 1)
    {
        cout << "-1\n";
        
        return;
    }
    
    for(int i = 1; i <= n - 1; i++)
    {
        cout << "5";
    }
    
    cout << "4\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
