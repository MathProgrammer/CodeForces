#include <iostream>
 
using namespace std;
 
void solve()
{
    long long x, y;
    cin >> x >> y;
 
    long long difference = x - y;
    cout << (difference == 1 ? "NO\n" : "YES\n");
}
 
int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
 
    while(no_of_test_cases--)
        solve();
 
    return 0;
}
