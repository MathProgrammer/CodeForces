#include <iostream>

using namespace std;

void solve()
{
    long long x;
    cin >> x;
    
    cout << "1 " << x - 1 << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
