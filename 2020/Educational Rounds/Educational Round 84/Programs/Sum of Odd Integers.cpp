#include <iostream>
 
using namespace std;
 
void solve()
{
    long long n, no_of_summands;
    cin >> n >> no_of_summands;
    
    //k(k + 1)/2
    long long min_sum = (no_of_summands/2)*(2*no_of_summands - 1 + 1) + (no_of_summands%2)*no_of_summands;
    //cout << "S = " << min_sum << "\n";
    cout << (min_sum <= n && min_sum%2 == n%2 ? "YES\n" : "NO\n");
}
 
int main()
{
    int no_of_test_cases;
    cin >> no_of_test_cases;
    
    while(no_of_test_cases--)
        solve();
    
    return 0;
}
