#include <iostream>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    
    cout << n/2 << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
