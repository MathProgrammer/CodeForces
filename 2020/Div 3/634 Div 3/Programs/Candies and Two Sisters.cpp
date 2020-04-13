#include <iostream>

using namespace std;

void solve()
{
    long long n;
    cin >> n;
    
    long long no_of_ways = (n/2) - (n%2 == 0 ? 1 : 0);
    cout << no_of_ways << "\n";
}

int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
